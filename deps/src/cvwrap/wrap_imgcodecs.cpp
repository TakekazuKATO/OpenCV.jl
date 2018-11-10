#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_imgcodecs_module(Module& mod) {
  mod.add_bits<cv::ImreadModes>("ImreadModes");
  mod.set_const("IMREAD_UNCHANGED", cv::ImreadModes::IMREAD_UNCHANGED);
  mod.set_const("IMREAD_GRAYSCALE", cv::ImreadModes::IMREAD_GRAYSCALE);
  mod.set_const("IMREAD_COLOR", cv::ImreadModes::IMREAD_COLOR);
  mod.set_const("IMREAD_ANYDEPTH", cv::ImreadModes::IMREAD_ANYDEPTH);
  mod.set_const("IMREAD_ANYCOLOR", cv::ImreadModes::IMREAD_ANYCOLOR);
  mod.set_const("IMREAD_LOAD_GDAL", cv::ImreadModes::IMREAD_LOAD_GDAL);
  mod.set_const("IMREAD_REDUCED_GRAYSCALE_2",
                cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_2);
  mod.set_const("IMREAD_REDUCED_COLOR_2",
                cv::ImreadModes::IMREAD_REDUCED_COLOR_2);
  mod.set_const("IMREAD_REDUCED_GRAYSCALE_4",
                cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_4);
  mod.set_const("IMREAD_REDUCED_COLOR_4",
                cv::ImreadModes::IMREAD_REDUCED_COLOR_4);
  mod.set_const("IMREAD_REDUCED_GRAYSCALE_8",
                cv::ImreadModes::IMREAD_REDUCED_GRAYSCALE_8);
  mod.set_const("IMREAD_REDUCED_COLOR_8",
                cv::ImreadModes::IMREAD_REDUCED_COLOR_8);
  mod.set_const("IMREAD_IGNORE_ORIENTATION",
                cv::ImreadModes::IMREAD_IGNORE_ORIENTATION);
  mod.add_bits<cv::ImwriteFlags>("ImwriteFlags");
  mod.set_const("IMWRITE_JPEG_QUALITY", cv::ImwriteFlags::IMWRITE_JPEG_QUALITY);
  mod.set_const("IMWRITE_JPEG_PROGRESSIVE",
                cv::ImwriteFlags::IMWRITE_JPEG_PROGRESSIVE);
  mod.set_const("IMWRITE_JPEG_OPTIMIZE",
                cv::ImwriteFlags::IMWRITE_JPEG_OPTIMIZE);
  mod.set_const("IMWRITE_JPEG_RST_INTERVAL",
                cv::ImwriteFlags::IMWRITE_JPEG_RST_INTERVAL);
  mod.set_const("IMWRITE_JPEG_LUMA_QUALITY",
                cv::ImwriteFlags::IMWRITE_JPEG_LUMA_QUALITY);
  mod.set_const("IMWRITE_JPEG_CHROMA_QUALITY",
                cv::ImwriteFlags::IMWRITE_JPEG_CHROMA_QUALITY);
  mod.set_const("IMWRITE_PNG_COMPRESSION",
                cv::ImwriteFlags::IMWRITE_PNG_COMPRESSION);
  mod.set_const("IMWRITE_PNG_STRATEGY", cv::ImwriteFlags::IMWRITE_PNG_STRATEGY);
  mod.set_const("IMWRITE_PNG_BILEVEL", cv::ImwriteFlags::IMWRITE_PNG_BILEVEL);
  mod.set_const("IMWRITE_PXM_BINARY", cv::ImwriteFlags::IMWRITE_PXM_BINARY);
  mod.set_const("IMWRITE_EXR_TYPE", cv::ImwriteFlags::IMWRITE_EXR_TYPE);
  mod.set_const("IMWRITE_WEBP_QUALITY", cv::ImwriteFlags::IMWRITE_WEBP_QUALITY);
  mod.set_const("IMWRITE_PAM_TUPLETYPE",
                cv::ImwriteFlags::IMWRITE_PAM_TUPLETYPE);
  // mod.set_const("IMWRITE_TIFF_RESUNIT",
  // cv::ImwriteFlags::IMWRITE_TIFF_RESUNIT);
  // mod.set_const("IMWRITE_TIFF_XDPI", cv::ImwriteFlags::IMWRITE_TIFF_XDPI);
  // mod.set_const("IMWRITE_TIFF_YDPI", cv::ImwriteFlags::IMWRITE_TIFF_YDPI);
  /*mod.add_bits<cv::ImwriteEXRTypeFlags>("ImwriteEXRTypeFlags");
  mod.set_const("IMWRITE_EXR_TYPE_HALF",
                cv::ImwriteEXRTypeFlags::IMWRITE_EXR_TYPE_HALF);
  mod.set_const("IMWRITE_EXR_TYPE_FLOAT",
                cv::ImwriteEXRTypeFlags::IMWRITE_EXR_TYPE_FLOAT);*/
  mod.add_bits<cv::ImwritePNGFlags>("ImwritePNGFlags");
  mod.set_const("IMWRITE_PNG_STRATEGY_DEFAULT",
                cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_DEFAULT);
  mod.set_const("IMWRITE_PNG_STRATEGY_FILTERED",
                cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_FILTERED);
  mod.set_const("IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY",
                cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY);
  mod.set_const("IMWRITE_PNG_STRATEGY_RLE",
                cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_RLE);
  mod.set_const("IMWRITE_PNG_STRATEGY_FIXED",
                cv::ImwritePNGFlags::IMWRITE_PNG_STRATEGY_FIXED);
  mod.add_bits<cv::ImwritePAMFlags>("ImwritePAMFlags");
  mod.set_const("IMWRITE_PAM_FORMAT_NULL",
                cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_NULL);
  mod.set_const("IMWRITE_PAM_FORMAT_BLACKANDWHITE",
                cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_BLACKANDWHITE);
  mod.set_const("IMWRITE_PAM_FORMAT_GRAYSCALE",
                cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_GRAYSCALE);
  mod.set_const("IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA",
                cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_GRAYSCALE_ALPHA);
  mod.set_const("IMWRITE_PAM_FORMAT_RGB",
                cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_RGB);
  mod.set_const("IMWRITE_PAM_FORMAT_RGB_ALPHA",
                cv::ImwritePAMFlags::IMWRITE_PAM_FORMAT_RGB_ALPHA);
  mod.method("imread",
             [](const cv::String& filename) { return cv::imread(filename); });
  mod.method("imread", [](const cv::String& filename, int flags) {
    return cv::imread(filename, flags);
  });
  mod.method("imread", [](const cv::String& filename, cv::ImreadModes flags) {
    return cv::imread(filename, flags);
  });

  mod.method("imwrite", [](const cv::String& filename, const cv::Mat& img) {
    return cv::imwrite(filename, cv::InputArray(img));
  });
  mod.method("imwrite", [](const cv::String& filename, const cv::Mat& img,
                           const std::vector<int>& params) {
    return cv::imwrite(filename, cv::InputArray(img), params);
  });
  mod.method("imdecode", [](const cv::Mat& buf, int flags) {
    return cv::imdecode(cv::InputArray(buf), flags);
  });
  mod.method("imencode", [](const cv::String& ext, const cv::Mat& img,
                            const std::vector<uchar>& buf) {
    return cv::imencode(ext, cv::InputArray(img), const_off(buf));
  });
  mod.method("imencode", [](const cv::String& ext, const cv::Mat& img,
                            const std::vector<uchar>& buf,
                            const std::vector<int>& params) {
    return cv::imencode(ext, cv::InputArray(img), const_off(buf), params);
  });
}
