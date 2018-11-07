using Clang
const CLCXXAccessSpecifier=cindex.CXXAccessSpecifiers
function parseEnum(cur::cindex.CLCursor,ns::Array)
    filename = cindex.cu_file(cur)
    classname = cindex.spelling(cur)
    fullname = join([ns;classname],"::")
    if classname == ""
        prefix = "(int)$(join(ns,"::"))::"
    else
        prefix = "$(fullname)::"
        println("  mod.add_bits<$(fullname)>(\"$(classname)\");")
    end
    for c in cindex.children(cur)
        if cindex.typeof(c) == cindex.EnumConstantDecl
            cname = cindex.name(c)
            cfullname = prefix*cname
            println("  mod.set_const(\"$(cname)\",$(cfullname));")
        end
    end
end
classes=[]
function parseClass(cur::cindex.CLCursor,ns::Array)
    #attrs = cindex.search(cur, c->typeof(c) == cindex.AnnotateAttr && cindex.spelling(c) == "CV_EXPORTS")
    #if isempty(attrs)
    #    return
    #end
    filename = cindex.cu_file(cur)
    classname = cindex.spelling(cur)
    fullname = "$(join(ns,"::"))::$(classname)"
    if findfirst(a->a==fullname,classes) != nothing
        return
    end
    push!(classes,fullname)
    children = cindex.search(cur,c->typeof(c) != cindex.AnnotateAttr)
    if isempty(children)
        return
    end
    tflag = false
    accflag=false
    if cindex.typeof(cur) == cindex.StructDecl
        accflag=true
    end

    if cindex.typeof(cur) == cindex.ClassTemplate
        print("""  mod.add_type<Parametric<TypeVar<1>>>(\"$(classname)\")
                        .apply<$(fullname)<int>,$(fullname)<int64_t>,$(fullname)<uchar>,$(fullname)<short>,$(fullname)<ushort>,$(fullname)<float>,$(fullname)<double>>([](auto wrapped) {
                          typedef typename decltype(wrapped)::type WrappedT;
                          typedef typename get_template_type<WrappedT>::type ValueT;
                          wrapped""")
        tflag = true
    else
        print("  mod.add_type<$(join(ns,"::"))::$(classname)>(\"$(classname)\")")
    end
    temptype = ""
    for c in children
        if cindex.typeof(c) == cindex.CXXAccessSpecifier
            tokens=(cindex.tokenize(c))
            spec = tokens[1]
            if spec.text == "public" 
                accflag=true
            else
               accflag = false
            end
        end
        if !accflag 
            continue
        end
        myclass ="$(join(ns,"::"))::$(classname)"
        omyclass = myclass
        if tflag
            myclass = "WrappedT"
        end
        if cindex.typeof(c) == cindex.Constructor
            m = match(r"\(.*\)",cindex.name(c))
            ps = m.match[2:end-1]
            if temptype != ""
                ps = replace(ps,"$(temptype)"=>"ValueT")
                ps = replace(ps,omyclass=>"typename WrappedT")
            end
            if !isempty(ps) && !contains(ps,"Mat *") && !contains(ps,"&&")
                print("\n    .")
                if tflag
                    print("template ")
                end
                print("constructor<$(ps)>()")
            end
        elseif cindex.typeof(c) == cindex.CXXMethod
            tokens=collect(cindex.tokenize(c))
            cflag=false
            m = findlast(t->cindex.typeof(t)==cindex.Punctuation && t.text == ")",tokens)
            if m!=nothing && m<length(tokens) && tokens[m+1].text == "const"
                cflag = true
            end
            parseFunction(c,ns,myclass,temptype,cflag)
        elseif cindex.typeof(c) == cindex.FieldDecl
            fname = cindex.name(c)
            print("\n    .method(\"$(fname)\",[](const $(myclass) &instance){return instance.$(fname);})")
        elseif cindex.typeof(c) == cindex.TemplateTypeParameter
            temptype = cindex.spelling(c)
        end
    end
    println(";")
    if tflag
        println("});")
    end
end
global arg_count=0
function parseArg(tokens,pnameflag=true)
    if isempty(tokens)
        return ()
    end
    typename = []
    modifier = ""
    reference = ""
    fundamental = false
    tempparam = ()
    paramname = ""
    has_default = false
    state = :init
    idx = 0
    while idx < length(tokens)
        idx = idx + 1
        tok = tokens[idx]
        if state == :init # modifier or fundamental
            if cindex.typeof(tok) == cindex.Keyword && (tok.text == "const" || tok.text == "virtual")
                modifier = modifier*tok.text
                continue
            elseif cindex.typeof(tok) == cindex.Keyword || tok.text == "uchar" || tok.text == "size_t" || tok.text == "ptrdiff_t" || (length(tok.text)>1 && tok.text[1:2]=="Cv")
                fundamental = true
                push!(typename,tok.text)
                state = :reference
                continue
            else 
                state = :typename
            end
        end
        if state == :typename # typename
            if isempty(typename) && cindex.typeof(tok) == cindex.Punctuation && tok.text == "::"
                push!(typename,"")
                continue
            end
            if cindex.typeof(tok) == cindex.Identifier
                push!(typename,tok.text)
                state = :namespace
                continue
            else
                state = :reference
            end
        end
        if state == :namespace # namespace separator
            if cindex.typeof(tok) == cindex.Punctuation && tok.text == "::"
                state = :typename
                continue;
            else
                state = :reference
            end
        end
        if state == :reference # reference
            if cindex.typeof(tok) == cindex.Punctuation && tok.text != "<"
                reference = reference*tok.text
                #state = :paramname
                continue
            elseif cindex.typeof(tok) == cindex.Punctuation && tok.text == "<"
                etemp=findlast(t->t.text == ">",tokens[idx:end])
                if etemp == nothing
                    idx = length(tokens)
                else
                    tempparam=parseArg(tokens[idx+1:idx+etemp-2],false)
                    idx = idx + etemp -1
                end
                continue
            else
                state = :paramname
            end
        end
        if state == :paramname # for param
            if cindex.typeof(tok) == cindex.Identifier
                paramname = tok.text
                state = :default_param
                continue
            end
        end
        if state == :default_param # default parameter
            if cindex.typeof(tok) == cindex.Punctuation && tok.text == "="
                has_default = true
                break
            elseif cindex.typeof(tok) == cindex.Punctuation && tok.text == "["
                state = :array
                continue
            end
        end
        if state == :array
            if cindex.typeof(tok) == cindex.Punctuation && tok.text == "]"
                reference = "*"
                state = :default_param
                continue
            end
        end
    end
    if pnameflag && paramname==""
        paramname = "_argument$(arg_count)"
        global arg_count += 1
    end
    param2=paramname
    (fundamental,modifier,typename,tempparam,reference,paramname,has_default,param2)
end
function makeArgString(arg,argcomp=true)
    tn = join(arg[3],"::")
    if arg[2] != ""
        tn = arg[2]*" "*tn
    end
    if arg[4] != ()
        tn = tn * "<" * makeArgString(arg[4],false) * ">"
    end
    tn*" "*arg[5]*arg[6]
end
function parseFunction(cur::cindex.CLCursor,ns::Array,instance::String="",temptype="",constflag=false)
    attrs = cindex.search(cur, c->typeof(c) == cindex.AnnotateAttr && cindex.spelling(c) == "CV_EXPORTS")
    if isempty(instance) && isempty(attrs)
        return
    end
    filename = cindex.cu_file(cur)
    funcname = cindex.spelling(cur)
    args = cindex.function_args(cur)
    targs = map(args) do arg
        tokens = cindex.tokenize(arg)
        parg = parseArg(collect(tokens))
        c = cindex.children(arg)
        (fundamental,modifier,typename,tempparam,reference,paramname,has_default,param2)=parg
        if length(c)>0 && cindex.typeof(c[1]) == cindex.TypeRef
            typename=cindex.spelling(c[1])
            typename = replace(typename,"class "=>"")
            typename = replace(typename,"struct "=>"")
            typename=split(typename,"::")
        end
        if ~fundamental
            if typename[1] != "" && typename[1] != "std" && typename[1] != "cv"
                    pushfirst!(typename,"cv")
            end
            tn = join(typename,"::")
            if typename[end] == "InputArray" || typename[end] == "OutputArray" || typename[end] == "InputOutputArray"
                modifier="const"
                typename[end] = "Mat"
                reference = "&"
                param2="$(tn)($(paramname))"
            elseif typename[end] == "InputArrayOfArrays" || typename[end] == "OutputArrayOfArrays" || typename[end] == "InputOutputArrayOfArrays"
                modifier="const"
                typename = ["std","vector"]
                tempparam = (false,"",["cv","Mat"],(),"","",false,"")
                reference = "&"
                param2="$(tn)($(paramname))"
            elseif modifier == "" && reference == "&" && tn == "std::vector"
                modifier="const"
                param2="const_off($(paramname))"
            end
        end
        (fundamental,modifier,typename,tempparam,reference,paramname,has_default,param2)
    end
    targs = filter(a->!isempty(a),targs)
    vargs = map(makeArgString,targs)
    if temptype != ""
        vargs = map(a->replace(a,"cv::$(temptype)"=>"ValueT"),vargs)
    end
    params = map(a->a[8],targs)
    dindex=findfirst(map(a->a[7],targs))
    if dindex==nothing
        dindex=length(targs)
    else
        dindex=dindex-1
    end
    for i in dindex:length(targs)
        
        if isempty(vargs[1:i]) || findfirst(a->ismatch(r"^ *(Mat &|Mat \*|cv::Mat &|cv::Mat \*|const Mat \*|const cv::Mat \*|const  *std::vector<cv::Mat> &|std::vector<cv::Mat> &)",a),vargs[1:i])==nothing 
            if isempty(instance)
                println("  mod.method(\"$(funcname)\", []($(join(vargs[1:i],','))) {")
                println("    return $(join(ns,"::"))::$(funcname)( $(join(params[1:i],',') ) );")
                println("  });")
            else
                print("\n")
                print("    .method(")
                if funcname == "operator=="
                    print("\"isequal\",")
                elseif funcname != "operator()"
                    print("\"$(funcname)\",")
                end
                print("[](")
                if constflag
                    st_instance="const $(instance) &instance"
                else
                    st_instance="$(instance) &instance"
                end
                
                args2=vargs[1:i]
                if typeof(args2)==Array{Union{},1}
                    args2=[st_instance]
                else
                    pushfirst!(args2,st_instance)
                end
                print("$(join(args2,','))) {")
                print("    return instance.$(funcname)( $(join(params[1:i],',') ) ); })")
            end
        end
    end
end
function rsearch(cur::cindex.CLCursor,ns::Array=[],target_file="",excludes=[])
    for c in cindex.children(cur)
        if typeof(c) == cindex.Namespace
            rsearch(c,cat(ns,[cindex.spelling(c)],dims=1),target_file,excludes)
        elseif contains(cindex.cu_file(cur),target_file) && findfirst(e->cindex.spelling(c)==e,excludes)==nothing
            if typeof(c) == cindex.FunctionDecl
                parseFunction(c,ns)
            elseif typeof(c) == cindex.ClassDecl || typeof(c) == cindex.StructDecl || typeof(c) == cindex.ClassTemplate
                parseClass(c,ns)
            elseif typeof(c) == cindex.EnumDecl 
                parseEnum(c,ns)
            end
        end
    end
end

function main()
    target_file = ARGS[1]
    excludes = ARGS[2:end]
    mname=replace(target_file,"/"=>"_")
    mname=replace(mname,".hpp"=>"")
    mname=replace(mname,".h"=>"")
    if length(target_file)>1 && target_file[1] != '/'
        target_file = "/"*target_file
    end

    cur=cindex.parse_header("/usr/local/include/opencv2/opencv.hpp",args=["-D","CV_EXPORTS=__attribute__((annotate(\"CV_EXPORTS\")))"])
    #cur=cindex.parse_header("/usr/local/include/opencv2/dnn/all_layers.hpp",args=["-D","CV_EXPORTS=__attribute__((annotate(\"CV_EXPORTS\")))"])
    #cur=cindex.parse_header("test.cpp")
    print("""
    #include <opencv2/opencv.hpp>
    #include "jlcxx/jlcxx.hpp"
    #include "modules.hpp"
    using namespace jlcxx;
    using namespace cv;
    JLCXX_MODULE
    define_$(mname)_module(Module& mod) {
    """)
    rsearch(cur,[],target_file,excludes)
    println("}")
end

main()
