# OpenCV.jl

This is OpenCV wrapper for julia via C++ Interface by using CxxWrap.jl.
The OpenCV image Matrix (cv::Mat) is automatically convert from/to julia Array.
Most C++ classes, methods, enums and functions are generated from opencv2/opencv.hpp(and included headers) by Clang.jl.
