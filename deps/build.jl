using BinDeps
using CxxWrap


@BinDeps.setup


opencv = library_dependency("opencv",aliases=["libopencv_core"])

provides(AptGet,"opencv", opencv, os=:Linux)
provides(Pacman,"opencv", opencv, os=:Linux)
provides(Yum, "opencv", opencv, os=:Linux)
provides(BSDPkg, "opencv", opencv, os=:FreeBSD)

if Sys.iswindows()
  using WinRPM
  provides(WinRPM.RPM, "opencv", opencv, os=:Windows)
end
# #if Sys.isapple()
# #  using Homebrew
# #  provides(Homebrew.HB, "opencv", opencv, os=:Darwin)
# #end
# using CMakeWrapper
# provides(Sources, URI("https://github.com/opencv/opencv/archive/3.4.3.zip"),opencv)
# provides(BuildProcess, CMakeProcess(), opencv)

@BinDeps.install

jlcxx_cmake_dir   = joinpath(dirname(pathof(CxxWrap)), "..", "deps",   "usr", "lib", "cmake", "JlCxx")
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
	`cmake -DJlCxx_DIR=$jlcxx_cmake_dir -DJulia_EXECUTABLE=$(Sys.BINDIR)/julia $cvwrap_srcdir`
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
