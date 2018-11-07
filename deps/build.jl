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
#=
deps = [
    opencv_aruco = library_dependency("libopencv_aruco")
    opencv_bgsegm = library_dependency("libopencv_bgsegm")
    opencv_bioinspired = library_dependency("libopencv_bioinspired")
    opencv_calib3d = library_dependency("libopencv_calib3d")
    opencv_ccalib = library_dependency("libopencv_ccalib")
    opencv_core = library_dependency("libopencv_core")
    opencv_datasets = library_dependency("libopencv_datasets")
    opencv_dnn = library_dependency("libopencv_dnn")
    opencv_dnn_objdetect = library_dependency("libopencv_dnn_objdetect")
    opencv_dpm = library_dependency("libopencv_dpm")
    opencv_face = library_dependency("libopencv_face")
    opencv_features2d = library_dependency("libopencv_features2d")
    opencv_flann = library_dependency("libopencv_flann")
    opencv_fuzzy = library_dependency("libopencv_fuzzy")
    opencv_hfs = library_dependency("libopencv_hfs")
    opencv_highgui = library_dependency("libopencv_highgui")
    opencv_img_hash = library_dependency("libopencv_img_hash")
    opencv_imgcodecs = library_dependency("libopencv_imgcodecs")
    opencv_imgproc = library_dependency("libopencv_imgproc")
    opencv_line_descriptor = library_dependency("libopencv_line_descriptor")
    opencv_ml = library_dependency("libopencv_ml")
    opencv_objdetect = library_dependency("libopencv_objdetect")
    opencv_optflow = library_dependency("libopencv_optflow")
    opencv_phase_unwrapping = library_dependency("libopencv_phase_unwrapping")
    opencv_photo = library_dependency("libopencv_photo")
    opencv_plot = library_dependency("libopencv_plot")
    opencv_reg = library_dependency("libopencv_reg")
    opencv_rgbd = library_dependency("libopencv_rgbd")
    opencv_saliency = library_dependency("libopencv_saliency")
    opencv_shape = library_dependency("libopencv_shape")
    opencv_stereo = library_dependency("libopencv_stereo")
    opencv_stitching = library_dependency("libopencv_stitching")
    opencv_structured_light = library_dependency("libopencv_structured_light")
    opencv_superres = library_dependency("libopencv_superres")
    opencv_surface_matching = library_dependency("libopencv_surface_matching")
    opencv_tracking = library_dependency("libopencv_tracking")
    opencv_video = library_dependency("libopencv_video")
    opencv_videoio = library_dependency("libopencv_videoio")
    opencv_videostab = library_dependency("libopencv_videostab")
    opencv_xfeatures2d = library_dependency("libopencv_xfeatures2d")
    opencv_ximgproc = library_dependency("libopencv_ximgproc")
    opencv_xobjdetect = library_dependency("libopencv_xobjdetect")
    opencv_xphoto = library_dependency("libopencv_xphoto")
]

using Homebrew
provides(Homebrew.HB,"opencv", opencv_core)

@BinDeps.install Dict(
    :libopencv_aruco => :libopencv_aruco,
    :libopencv_bgsegm => :libopencv_bgsegm,
    :libopencv_bioinspired => :libopencv_bioinspired,
    :libopencv_calib3d => :libopencv_calib3d,
    :libopencv_ccalib => :libopencv_ccalib,
    :libopencv_core => :libopencv_core,
    :libopencv_datasets => :libopencv_datasets,
    :libopencv_dnn => :libopencv_dnn,
    :libopencv_dnn_objdetect => :libopencv_dnn_objdetect,
    :libopencv_dpm => :libopencv_dpm,
    :libopencv_face => :libopencv_face,
    :libopencv_features2d => :libopencv_features2d,
    :libopencv_flann => :libopencv_flann,
    :libopencv_fuzzy => :libopencv_fuzzy,
    :libopencv_hfs => :libopencv_hfs,
    :libopencv_highgui => :libopencv_highgui,
    :libopencv_img_hash => :libopencv_img_hash,
    :libopencv_imgcodecs => :libopencv_imgcodecs,
    :libopencv_imgproc => :libopencv_imgproc,
    :libopencv_line_descriptor => :libopencv_line_descriptor,
    :libopencv_ml => :libopencv_ml,
    :libopencv_objdetect => :libopencv_objdetect,
    :libopencv_optflow => :libopencv_optflow,
    :libopencv_phase_unwrapping => :libopencv_phase_unwrapping,
    :libopencv_photo => :libopencv_photo,
    :libopencv_plot => :libopencv_plot,
    :libopencv_reg => :libopencv_reg,
    :libopencv_rgbd => :libopencv_rgbd,
    :libopencv_saliency => :libopencv_saliency,
    :libopencv_shape => :libopencv_shape,
    :libopencv_stereo => :libopencv_stereo,
    :libopencv_stitching => :libopencv_stitching,
    :libopencv_structured_light => :libopencv_structured_light,
    :libopencv_superres => :libopencv_superres,
    :libopencv_surface_matching => :libopencv_surface_matching,
    :libopencv_tracking => :libopencv_tracking,
    :libopencv_video => :libopencv_video,
    :libopencv_videoio => :libopencv_videoio,
    :libopencv_videostab => :libopencv_videostab,
    :libopencv_xfeatures2d => :libopencv_xfeatures2d,
    :libopencv_ximgproc => :libopencv_ximgproc,
    :libopencv_xobjdetect => :libopencv_xobjdetect,
    :libopencv_xphoto => :libopencv_xphoto
)
=#
