using BinDeps
using CxxWrap


@BinDeps.setup
jlcxx_dir = joinpath(dirname(CxxWrap.jlcxx_path), "cmake", "JlCxx")
cvwrap = library_dependency("cvwrap", aliases=["libcvwrap"])

prefix=joinpath(BinDeps.depsdir(cvwrap),"usr")
cvwrap_srcdir = joinpath(BinDeps.depsdir(cvwrap),"src","cvwrap")
cvwrap_builddir = joinpath(BinDeps.depsdir(cvwrap),"builds","cvwrap")
lib_prefix = @static Sys.iswindows() ? "" : "lib"
lib_suffix = @static Sys.iswindows() ? "dll" : (@static Sys.isapple() ? "dylib" : "so")

makeopts = ["--", "-j", "$(Sys.CPU_THREADS+2)"]
genopt = "Unix Makefiles"
build_type = get(ENV, "CXXWRAP_BUILD_TYPE", "Release")

cv_steps = @build_steps begin
	`cmake $cvwrap_srcdir`
	`cmake --build . --config $build_type --target install $makeopts`
end

# If built, always run cmake, in case the code changed
if isdir(cvwrap_builddir)
  BinDeps.run(@build_steps begin
    ChangeDirectory(cvwrap_builddir)
    cv_steps
  end)
end

provides(BuildProcess,
  (@build_steps begin
    CreateDirectory(cvwrap_builddir)
    @build_steps begin
      ChangeDirectory(cvwrap_builddir)
      FileRule(joinpath(prefix,"lib", "$(lib_prefix)cvwrap.$lib_suffix"),cv_steps)
    end
  end),cvwrap)

deps = [cvwrap]

@BinDeps.install Dict(:cvwrap=>:cvwrap)
