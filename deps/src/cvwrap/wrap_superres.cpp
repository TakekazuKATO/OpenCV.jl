#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_superres_module(Module& mod) {
  mod.add_type<cv::superres::FrameSource>("FrameSource");
  mod.method("createFrameSource_Empty", []() {
    return cv::superres::createFrameSource_Empty(  );
  });
  mod.method("createFrameSource_Video", [](const cv::String & fileName) {
    return cv::superres::createFrameSource_Video( fileName );
  });
  mod.method("createFrameSource_Video_CUDA", [](const cv::String & fileName) {
    return cv::superres::createFrameSource_Video_CUDA( fileName );
  });
  mod.method("createFrameSource_Camera", []() {
    return cv::superres::createFrameSource_Camera(  );
  });
  mod.method("createFrameSource_Camera", [](int  deviceId) {
    return cv::superres::createFrameSource_Camera( deviceId );
  });
  mod.add_type<cv::superres::SuperResolution>("SuperResolution");
  mod.method("createSuperResolution_BTVL1", []() {
    return cv::superres::createSuperResolution_BTVL1(  );
  });
  mod.method("createSuperResolution_BTVL1_CUDA", []() {
    return cv::superres::createSuperResolution_BTVL1_CUDA(  );
  });
}
