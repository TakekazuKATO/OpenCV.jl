project(OPENCV)

cmake_minimum_required(VERSION 3.1)
include(CheckCXXCompilerFlag)
set(CMAKE_INSTALL_PATH "${CMAKE_INSTALL_PREFIX}/lib")
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang" OR CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR CMAKE_CXX_COMPILER_ID MATCHES "Intel")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -DNDEBUG")
    CHECK_CXX_COMPILER_FLAG("-std=c++14" HAS_CPP14_FLAG)

    if (HAS_CPP14_FLAG)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
    else()
        message(FATAL_ERROR "Unsupported compiler -- xtensor requires C++14 support!")
    endif()
endif()

add_definitions(-DJULIA_ENABLE_THREADING)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})

find_package(JlCxx REQUIRED)
find_package(OpenCV REQUIRED)

add_library(cvwrap SHARED
    modules.cpp
    wrap_core_types.cpp
    wrap_core_affine.cpp
    wrap_core_mat.cpp
    wrap_core.cpp
    wrap_core_persistence.cpp
    wrap_imgproc.cpp
    wrap_imgcodecs.cpp
    wrap_videoio.cpp
    wrap_video_tracking.cpp
    wrap_video_background_segm.cpp
    wrap_calib3d.cpp
    wrap_features2d.cpp
    wrap_objdetect.cpp
    wrap_dnn_all_layers.cpp
    wrap_dnn.cpp
    wrap_ml.cpp
    wrap_photo.cpp
    wrap_stitching.cpp
    wrap_superres.cpp)

target_link_libraries(cvwrap ${OpenCV_LIBS} JlCxx::cxxwrap_julia)

include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

install(TARGETS
  cvwrap
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
