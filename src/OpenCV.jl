module OpenCV
using CxxWrap
include("../deps/deps.jl")
import Base: error
@wrapmodule(cvwrap)
function __init__()

    @initcxx
end
end
