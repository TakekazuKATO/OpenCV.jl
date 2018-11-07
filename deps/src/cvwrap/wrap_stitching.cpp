#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_stitching_module(Module& mod) {
  mod.add_type<cv::Stitcher>("Stitcher");
  mod.method("createStitcher", []() {
    return cv::createStitcher(  );
  });
  mod.method("createStitcher", [](bool  try_use_gpu) {
    return cv::createStitcher( try_use_gpu );
  });
  mod.method("createStitcherScans", []() {
    return cv::createStitcherScans(  );
  });
  mod.method("createStitcherScans", [](bool  try_use_gpu) {
    return cv::createStitcherScans( try_use_gpu );
  });
}
