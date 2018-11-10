#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_imgproc_module(Module &mod) {
  mod.add_bits<cv::MorphTypes>("MorphTypes");
  mod.set_const("MORPH_ERODE", cv::MorphTypes::MORPH_ERODE);
  mod.set_const("MORPH_DILATE", cv::MorphTypes::MORPH_DILATE);
  mod.set_const("MORPH_OPEN", cv::MorphTypes::MORPH_OPEN);
  mod.set_const("MORPH_CLOSE", cv::MorphTypes::MORPH_CLOSE);
  mod.set_const("MORPH_GRADIENT", cv::MorphTypes::MORPH_GRADIENT);
  mod.set_const("MORPH_TOPHAT", cv::MorphTypes::MORPH_TOPHAT);
  mod.set_const("MORPH_BLACKHAT", cv::MorphTypes::MORPH_BLACKHAT);
  mod.set_const("MORPH_HITMISS", cv::MorphTypes::MORPH_HITMISS);
  mod.add_bits<cv::MorphShapes>("MorphShapes");
  mod.set_const("MORPH_RECT", cv::MorphShapes::MORPH_RECT);
  mod.set_const("MORPH_CROSS", cv::MorphShapes::MORPH_CROSS);
  mod.set_const("MORPH_ELLIPSE", cv::MorphShapes::MORPH_ELLIPSE);
  mod.add_bits<cv::InterpolationFlags>("InterpolationFlags");
  mod.set_const("INTER_NEAREST", cv::InterpolationFlags::INTER_NEAREST);
  mod.set_const("INTER_LINEAR", cv::InterpolationFlags::INTER_LINEAR);
  mod.set_const("INTER_CUBIC", cv::InterpolationFlags::INTER_CUBIC);
  mod.set_const("INTER_AREA", cv::InterpolationFlags::INTER_AREA);
  mod.set_const("INTER_LANCZOS4", cv::InterpolationFlags::INTER_LANCZOS4);
  // mod.set_const("INTER_LINEAR_EXACT",
  //              cv::InterpolationFlags::INTER_LINEAR_EXACT);
  mod.set_const("INTER_MAX", cv::InterpolationFlags::INTER_MAX);
  mod.set_const("WARP_FILL_OUTLIERS",
                cv::InterpolationFlags::WARP_FILL_OUTLIERS);
  mod.set_const("WARP_INVERSE_MAP", cv::InterpolationFlags::WARP_INVERSE_MAP);
  mod.add_bits<cv::InterpolationMasks>("InterpolationMasks");
  mod.set_const("INTER_BITS", cv::InterpolationMasks::INTER_BITS);
  mod.set_const("INTER_BITS2", cv::InterpolationMasks::INTER_BITS2);
  mod.set_const("INTER_TAB_SIZE", cv::InterpolationMasks::INTER_TAB_SIZE);
  mod.set_const("INTER_TAB_SIZE2", cv::InterpolationMasks::INTER_TAB_SIZE2);
  mod.add_bits<cv::DistanceTypes>("DistanceTypes");
  mod.set_const("DIST_USER", cv::DistanceTypes::DIST_USER);
  mod.set_const("DIST_L1", cv::DistanceTypes::DIST_L1);
  mod.set_const("DIST_L2", cv::DistanceTypes::DIST_L2);
  mod.set_const("DIST_C", cv::DistanceTypes::DIST_C);
  mod.set_const("DIST_L12", cv::DistanceTypes::DIST_L12);
  mod.set_const("DIST_FAIR", cv::DistanceTypes::DIST_FAIR);
  mod.set_const("DIST_WELSCH", cv::DistanceTypes::DIST_WELSCH);
  mod.set_const("DIST_HUBER", cv::DistanceTypes::DIST_HUBER);
  mod.add_bits<cv::DistanceTransformMasks>("DistanceTransformMasks");
  mod.set_const("DIST_MASK_3", cv::DistanceTransformMasks::DIST_MASK_3);
  mod.set_const("DIST_MASK_5", cv::DistanceTransformMasks::DIST_MASK_5);
  mod.set_const("DIST_MASK_PRECISE",
                cv::DistanceTransformMasks::DIST_MASK_PRECISE);
  mod.add_bits<cv::ThresholdTypes>("ThresholdTypes");
  mod.set_const("THRESH_BINARY", cv::ThresholdTypes::THRESH_BINARY);
  mod.set_const("THRESH_BINARY_INV", cv::ThresholdTypes::THRESH_BINARY_INV);
  mod.set_const("THRESH_TRUNC", cv::ThresholdTypes::THRESH_TRUNC);
  mod.set_const("THRESH_TOZERO", cv::ThresholdTypes::THRESH_TOZERO);
  mod.set_const("THRESH_TOZERO_INV", cv::ThresholdTypes::THRESH_TOZERO_INV);
  mod.set_const("THRESH_MASK", cv::ThresholdTypes::THRESH_MASK);
  mod.set_const("THRESH_OTSU", cv::ThresholdTypes::THRESH_OTSU);
  mod.set_const("THRESH_TRIANGLE", cv::ThresholdTypes::THRESH_TRIANGLE);
  mod.add_bits<cv::AdaptiveThresholdTypes>("AdaptiveThresholdTypes");
  mod.set_const("ADAPTIVE_THRESH_MEAN_C",
                cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_MEAN_C);
  mod.set_const("ADAPTIVE_THRESH_GAUSSIAN_C",
                cv::AdaptiveThresholdTypes::ADAPTIVE_THRESH_GAUSSIAN_C);
  mod.add_bits<cv::UndistortTypes>("UndistortTypes");
  mod.set_const("PROJ_SPHERICAL_ORTHO",
                cv::UndistortTypes::PROJ_SPHERICAL_ORTHO);
  mod.set_const("PROJ_SPHERICAL_EQRECT",
                cv::UndistortTypes::PROJ_SPHERICAL_EQRECT);
  mod.add_bits<cv::GrabCutClasses>("GrabCutClasses");
  mod.set_const("GC_BGD", cv::GrabCutClasses::GC_BGD);
  mod.set_const("GC_FGD", cv::GrabCutClasses::GC_FGD);
  mod.set_const("GC_PR_BGD", cv::GrabCutClasses::GC_PR_BGD);
  mod.set_const("GC_PR_FGD", cv::GrabCutClasses::GC_PR_FGD);
  mod.add_bits<cv::GrabCutModes>("GrabCutModes");
  mod.set_const("GC_INIT_WITH_RECT", cv::GrabCutModes::GC_INIT_WITH_RECT);
  mod.set_const("GC_INIT_WITH_MASK", cv::GrabCutModes::GC_INIT_WITH_MASK);
  mod.set_const("GC_EVAL", cv::GrabCutModes::GC_EVAL);
  // mod.set_const("GC_EVAL_FREEZE_MODEL",
  // cv::GrabCutModes::GC_EVAL_FREEZE_MODEL);
  mod.add_bits<cv::DistanceTransformLabelTypes>("DistanceTransformLabelTypes");
  mod.set_const("DIST_LABEL_CCOMP",
                cv::DistanceTransformLabelTypes::DIST_LABEL_CCOMP);
  mod.set_const("DIST_LABEL_PIXEL",
                cv::DistanceTransformLabelTypes::DIST_LABEL_PIXEL);
  mod.add_bits<cv::FloodFillFlags>("FloodFillFlags");
  mod.set_const("FLOODFILL_FIXED_RANGE",
                cv::FloodFillFlags::FLOODFILL_FIXED_RANGE);
  mod.set_const("FLOODFILL_MASK_ONLY", cv::FloodFillFlags::FLOODFILL_MASK_ONLY);
  mod.add_bits<cv::ConnectedComponentsTypes>("ConnectedComponentsTypes");
  mod.set_const("CC_STAT_LEFT", cv::ConnectedComponentsTypes::CC_STAT_LEFT);
  mod.set_const("CC_STAT_TOP", cv::ConnectedComponentsTypes::CC_STAT_TOP);
  mod.set_const("CC_STAT_WIDTH", cv::ConnectedComponentsTypes::CC_STAT_WIDTH);
  mod.set_const("CC_STAT_HEIGHT", cv::ConnectedComponentsTypes::CC_STAT_HEIGHT);
  mod.set_const("CC_STAT_AREA", cv::ConnectedComponentsTypes::CC_STAT_AREA);
  mod.set_const("CC_STAT_MAX", cv::ConnectedComponentsTypes::CC_STAT_MAX);
  mod.add_bits<cv::ConnectedComponentsAlgorithmsTypes>(
      "ConnectedComponentsAlgorithmsTypes");
  mod.set_const("CCL_WU", cv::ConnectedComponentsAlgorithmsTypes::CCL_WU);
  mod.set_const("CCL_DEFAULT",
                cv::ConnectedComponentsAlgorithmsTypes::CCL_DEFAULT);
  mod.set_const("CCL_GRANA", cv::ConnectedComponentsAlgorithmsTypes::CCL_GRANA);
  mod.add_bits<cv::RetrievalModes>("RetrievalModes");
  mod.set_const("RETR_EXTERNAL", cv::RetrievalModes::RETR_EXTERNAL);
  mod.set_const("RETR_LIST", cv::RetrievalModes::RETR_LIST);
  mod.set_const("RETR_CCOMP", cv::RetrievalModes::RETR_CCOMP);
  mod.set_const("RETR_TREE", cv::RetrievalModes::RETR_TREE);
  mod.set_const("RETR_FLOODFILL", cv::RetrievalModes::RETR_FLOODFILL);
  mod.add_bits<cv::ContourApproximationModes>("ContourApproximationModes");
  mod.set_const("CHAIN_APPROX_NONE",
                cv::ContourApproximationModes::CHAIN_APPROX_NONE);
  mod.set_const("CHAIN_APPROX_SIMPLE",
                cv::ContourApproximationModes::CHAIN_APPROX_SIMPLE);
  mod.set_const("CHAIN_APPROX_TC89_L1",
                cv::ContourApproximationModes::CHAIN_APPROX_TC89_L1);
  mod.set_const("CHAIN_APPROX_TC89_KCOS",
                cv::ContourApproximationModes::CHAIN_APPROX_TC89_KCOS);
  /*mod.add_bits<cv::ShapeMatchModes>("ShapeMatchModes");
  mod.set_const("CONTOURS_MATCH_I1", cv::ShapeMatchModes::CONTOURS_MATCH_I1);
  mod.set_const("CONTOURS_MATCH_I2", cv::ShapeMatchModes::CONTOURS_MATCH_I2);
  mod.set_const("CONTOURS_MATCH_I3", cv::ShapeMatchModes::CONTOURS_MATCH_I3);*/
  mod.add_bits<cv::HoughModes>("HoughModes");
  mod.set_const("HOUGH_STANDARD", cv::HoughModes::HOUGH_STANDARD);
  mod.set_const("HOUGH_PROBABILISTIC", cv::HoughModes::HOUGH_PROBABILISTIC);
  mod.set_const("HOUGH_MULTI_SCALE", cv::HoughModes::HOUGH_MULTI_SCALE);
  mod.set_const("HOUGH_GRADIENT", cv::HoughModes::HOUGH_GRADIENT);
  mod.add_bits<cv::LineSegmentDetectorModes>("LineSegmentDetectorModes");
  mod.set_const("LSD_REFINE_NONE",
                cv::LineSegmentDetectorModes::LSD_REFINE_NONE);
  mod.set_const("LSD_REFINE_STD", cv::LineSegmentDetectorModes::LSD_REFINE_STD);
  mod.set_const("LSD_REFINE_ADV", cv::LineSegmentDetectorModes::LSD_REFINE_ADV);
  mod.add_bits<cv::HistCompMethods>("HistCompMethods");
  mod.set_const("HISTCMP_CORREL", cv::HistCompMethods::HISTCMP_CORREL);
  mod.set_const("HISTCMP_CHISQR", cv::HistCompMethods::HISTCMP_CHISQR);
  mod.set_const("HISTCMP_INTERSECT", cv::HistCompMethods::HISTCMP_INTERSECT);
  mod.set_const("HISTCMP_BHATTACHARYYA",
                cv::HistCompMethods::HISTCMP_BHATTACHARYYA);
  mod.set_const("HISTCMP_HELLINGER", cv::HistCompMethods::HISTCMP_HELLINGER);
  mod.set_const("HISTCMP_CHISQR_ALT", cv::HistCompMethods::HISTCMP_CHISQR_ALT);
  mod.set_const("HISTCMP_KL_DIV", cv::HistCompMethods::HISTCMP_KL_DIV);
  mod.add_bits<cv::ColorConversionCodes>("ColorConversionCodes");
  mod.set_const("COLOR_BGR2BGRA", cv::ColorConversionCodes::COLOR_BGR2BGRA);
  mod.set_const("COLOR_RGB2RGBA", cv::ColorConversionCodes::COLOR_RGB2RGBA);
  mod.set_const("COLOR_BGRA2BGR", cv::ColorConversionCodes::COLOR_BGRA2BGR);
  mod.set_const("COLOR_RGBA2RGB", cv::ColorConversionCodes::COLOR_RGBA2RGB);
  mod.set_const("COLOR_BGR2RGBA", cv::ColorConversionCodes::COLOR_BGR2RGBA);
  mod.set_const("COLOR_RGB2BGRA", cv::ColorConversionCodes::COLOR_RGB2BGRA);
  mod.set_const("COLOR_RGBA2BGR", cv::ColorConversionCodes::COLOR_RGBA2BGR);
  mod.set_const("COLOR_BGRA2RGB", cv::ColorConversionCodes::COLOR_BGRA2RGB);
  mod.set_const("COLOR_BGR2RGB", cv::ColorConversionCodes::COLOR_BGR2RGB);
  mod.set_const("COLOR_RGB2BGR", cv::ColorConversionCodes::COLOR_RGB2BGR);
  mod.set_const("COLOR_BGRA2RGBA", cv::ColorConversionCodes::COLOR_BGRA2RGBA);
  mod.set_const("COLOR_RGBA2BGRA", cv::ColorConversionCodes::COLOR_RGBA2BGRA);
  mod.set_const("COLOR_BGR2GRAY", cv::ColorConversionCodes::COLOR_BGR2GRAY);
  mod.set_const("COLOR_RGB2GRAY", cv::ColorConversionCodes::COLOR_RGB2GRAY);
  mod.set_const("COLOR_GRAY2BGR", cv::ColorConversionCodes::COLOR_GRAY2BGR);
  mod.set_const("COLOR_GRAY2RGB", cv::ColorConversionCodes::COLOR_GRAY2RGB);
  mod.set_const("COLOR_GRAY2BGRA", cv::ColorConversionCodes::COLOR_GRAY2BGRA);
  mod.set_const("COLOR_GRAY2RGBA", cv::ColorConversionCodes::COLOR_GRAY2RGBA);
  mod.set_const("COLOR_BGRA2GRAY", cv::ColorConversionCodes::COLOR_BGRA2GRAY);
  mod.set_const("COLOR_RGBA2GRAY", cv::ColorConversionCodes::COLOR_RGBA2GRAY);
  mod.set_const("COLOR_BGR2BGR565", cv::ColorConversionCodes::COLOR_BGR2BGR565);
  mod.set_const("COLOR_RGB2BGR565", cv::ColorConversionCodes::COLOR_RGB2BGR565);
  mod.set_const("COLOR_BGR5652BGR", cv::ColorConversionCodes::COLOR_BGR5652BGR);
  mod.set_const("COLOR_BGR5652RGB", cv::ColorConversionCodes::COLOR_BGR5652RGB);
  mod.set_const("COLOR_BGRA2BGR565",
                cv::ColorConversionCodes::COLOR_BGRA2BGR565);
  mod.set_const("COLOR_RGBA2BGR565",
                cv::ColorConversionCodes::COLOR_RGBA2BGR565);
  mod.set_const("COLOR_BGR5652BGRA",
                cv::ColorConversionCodes::COLOR_BGR5652BGRA);
  mod.set_const("COLOR_BGR5652RGBA",
                cv::ColorConversionCodes::COLOR_BGR5652RGBA);
  mod.set_const("COLOR_GRAY2BGR565",
                cv::ColorConversionCodes::COLOR_GRAY2BGR565);
  mod.set_const("COLOR_BGR5652GRAY",
                cv::ColorConversionCodes::COLOR_BGR5652GRAY);
  mod.set_const("COLOR_BGR2BGR555", cv::ColorConversionCodes::COLOR_BGR2BGR555);
  mod.set_const("COLOR_RGB2BGR555", cv::ColorConversionCodes::COLOR_RGB2BGR555);
  mod.set_const("COLOR_BGR5552BGR", cv::ColorConversionCodes::COLOR_BGR5552BGR);
  mod.set_const("COLOR_BGR5552RGB", cv::ColorConversionCodes::COLOR_BGR5552RGB);
  mod.set_const("COLOR_BGRA2BGR555",
                cv::ColorConversionCodes::COLOR_BGRA2BGR555);
  mod.set_const("COLOR_RGBA2BGR555",
                cv::ColorConversionCodes::COLOR_RGBA2BGR555);
  mod.set_const("COLOR_BGR5552BGRA",
                cv::ColorConversionCodes::COLOR_BGR5552BGRA);
  mod.set_const("COLOR_BGR5552RGBA",
                cv::ColorConversionCodes::COLOR_BGR5552RGBA);
  mod.set_const("COLOR_GRAY2BGR555",
                cv::ColorConversionCodes::COLOR_GRAY2BGR555);
  mod.set_const("COLOR_BGR5552GRAY",
                cv::ColorConversionCodes::COLOR_BGR5552GRAY);
  mod.set_const("COLOR_BGR2XYZ", cv::ColorConversionCodes::COLOR_BGR2XYZ);
  mod.set_const("COLOR_RGB2XYZ", cv::ColorConversionCodes::COLOR_RGB2XYZ);
  mod.set_const("COLOR_XYZ2BGR", cv::ColorConversionCodes::COLOR_XYZ2BGR);
  mod.set_const("COLOR_XYZ2RGB", cv::ColorConversionCodes::COLOR_XYZ2RGB);
  mod.set_const("COLOR_BGR2YCrCb", cv::ColorConversionCodes::COLOR_BGR2YCrCb);
  mod.set_const("COLOR_RGB2YCrCb", cv::ColorConversionCodes::COLOR_RGB2YCrCb);
  mod.set_const("COLOR_YCrCb2BGR", cv::ColorConversionCodes::COLOR_YCrCb2BGR);
  mod.set_const("COLOR_YCrCb2RGB", cv::ColorConversionCodes::COLOR_YCrCb2RGB);
  mod.set_const("COLOR_BGR2HSV", cv::ColorConversionCodes::COLOR_BGR2HSV);
  mod.set_const("COLOR_RGB2HSV", cv::ColorConversionCodes::COLOR_RGB2HSV);
  mod.set_const("COLOR_BGR2Lab", cv::ColorConversionCodes::COLOR_BGR2Lab);
  mod.set_const("COLOR_RGB2Lab", cv::ColorConversionCodes::COLOR_RGB2Lab);
  mod.set_const("COLOR_BGR2Luv", cv::ColorConversionCodes::COLOR_BGR2Luv);
  mod.set_const("COLOR_RGB2Luv", cv::ColorConversionCodes::COLOR_RGB2Luv);
  mod.set_const("COLOR_BGR2HLS", cv::ColorConversionCodes::COLOR_BGR2HLS);
  mod.set_const("COLOR_RGB2HLS", cv::ColorConversionCodes::COLOR_RGB2HLS);
  mod.set_const("COLOR_HSV2BGR", cv::ColorConversionCodes::COLOR_HSV2BGR);
  mod.set_const("COLOR_HSV2RGB", cv::ColorConversionCodes::COLOR_HSV2RGB);
  mod.set_const("COLOR_Lab2BGR", cv::ColorConversionCodes::COLOR_Lab2BGR);
  mod.set_const("COLOR_Lab2RGB", cv::ColorConversionCodes::COLOR_Lab2RGB);
  mod.set_const("COLOR_Luv2BGR", cv::ColorConversionCodes::COLOR_Luv2BGR);
  mod.set_const("COLOR_Luv2RGB", cv::ColorConversionCodes::COLOR_Luv2RGB);
  mod.set_const("COLOR_HLS2BGR", cv::ColorConversionCodes::COLOR_HLS2BGR);
  mod.set_const("COLOR_HLS2RGB", cv::ColorConversionCodes::COLOR_HLS2RGB);
  mod.set_const("COLOR_BGR2HSV_FULL",
                cv::ColorConversionCodes::COLOR_BGR2HSV_FULL);
  mod.set_const("COLOR_RGB2HSV_FULL",
                cv::ColorConversionCodes::COLOR_RGB2HSV_FULL);
  mod.set_const("COLOR_BGR2HLS_FULL",
                cv::ColorConversionCodes::COLOR_BGR2HLS_FULL);
  mod.set_const("COLOR_RGB2HLS_FULL",
                cv::ColorConversionCodes::COLOR_RGB2HLS_FULL);
  mod.set_const("COLOR_HSV2BGR_FULL",
                cv::ColorConversionCodes::COLOR_HSV2BGR_FULL);
  mod.set_const("COLOR_HSV2RGB_FULL",
                cv::ColorConversionCodes::COLOR_HSV2RGB_FULL);
  mod.set_const("COLOR_HLS2BGR_FULL",
                cv::ColorConversionCodes::COLOR_HLS2BGR_FULL);
  mod.set_const("COLOR_HLS2RGB_FULL",
                cv::ColorConversionCodes::COLOR_HLS2RGB_FULL);
  mod.set_const("COLOR_LBGR2Lab", cv::ColorConversionCodes::COLOR_LBGR2Lab);
  mod.set_const("COLOR_LRGB2Lab", cv::ColorConversionCodes::COLOR_LRGB2Lab);
  mod.set_const("COLOR_LBGR2Luv", cv::ColorConversionCodes::COLOR_LBGR2Luv);
  mod.set_const("COLOR_LRGB2Luv", cv::ColorConversionCodes::COLOR_LRGB2Luv);
  mod.set_const("COLOR_Lab2LBGR", cv::ColorConversionCodes::COLOR_Lab2LBGR);
  mod.set_const("COLOR_Lab2LRGB", cv::ColorConversionCodes::COLOR_Lab2LRGB);
  mod.set_const("COLOR_Luv2LBGR", cv::ColorConversionCodes::COLOR_Luv2LBGR);
  mod.set_const("COLOR_Luv2LRGB", cv::ColorConversionCodes::COLOR_Luv2LRGB);
  mod.set_const("COLOR_BGR2YUV", cv::ColorConversionCodes::COLOR_BGR2YUV);
  mod.set_const("COLOR_RGB2YUV", cv::ColorConversionCodes::COLOR_RGB2YUV);
  mod.set_const("COLOR_YUV2BGR", cv::ColorConversionCodes::COLOR_YUV2BGR);
  mod.set_const("COLOR_YUV2RGB", cv::ColorConversionCodes::COLOR_YUV2RGB);
  mod.set_const("COLOR_YUV2RGB_NV12",
                cv::ColorConversionCodes::COLOR_YUV2RGB_NV12);
  mod.set_const("COLOR_YUV2BGR_NV12",
                cv::ColorConversionCodes::COLOR_YUV2BGR_NV12);
  mod.set_const("COLOR_YUV2RGB_NV21",
                cv::ColorConversionCodes::COLOR_YUV2RGB_NV21);
  mod.set_const("COLOR_YUV2BGR_NV21",
                cv::ColorConversionCodes::COLOR_YUV2BGR_NV21);
  mod.set_const("COLOR_YUV420sp2RGB",
                cv::ColorConversionCodes::COLOR_YUV420sp2RGB);
  mod.set_const("COLOR_YUV420sp2BGR",
                cv::ColorConversionCodes::COLOR_YUV420sp2BGR);
  mod.set_const("COLOR_YUV2RGBA_NV12",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_NV12);
  mod.set_const("COLOR_YUV2BGRA_NV12",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_NV12);
  mod.set_const("COLOR_YUV2RGBA_NV21",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_NV21);
  mod.set_const("COLOR_YUV2BGRA_NV21",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_NV21);
  mod.set_const("COLOR_YUV420sp2RGBA",
                cv::ColorConversionCodes::COLOR_YUV420sp2RGBA);
  mod.set_const("COLOR_YUV420sp2BGRA",
                cv::ColorConversionCodes::COLOR_YUV420sp2BGRA);
  mod.set_const("COLOR_YUV2RGB_YV12",
                cv::ColorConversionCodes::COLOR_YUV2RGB_YV12);
  mod.set_const("COLOR_YUV2BGR_YV12",
                cv::ColorConversionCodes::COLOR_YUV2BGR_YV12);
  mod.set_const("COLOR_YUV2RGB_IYUV",
                cv::ColorConversionCodes::COLOR_YUV2RGB_IYUV);
  mod.set_const("COLOR_YUV2BGR_IYUV",
                cv::ColorConversionCodes::COLOR_YUV2BGR_IYUV);
  mod.set_const("COLOR_YUV2RGB_I420",
                cv::ColorConversionCodes::COLOR_YUV2RGB_I420);
  mod.set_const("COLOR_YUV2BGR_I420",
                cv::ColorConversionCodes::COLOR_YUV2BGR_I420);
  mod.set_const("COLOR_YUV420p2RGB",
                cv::ColorConversionCodes::COLOR_YUV420p2RGB);
  mod.set_const("COLOR_YUV420p2BGR",
                cv::ColorConversionCodes::COLOR_YUV420p2BGR);
  mod.set_const("COLOR_YUV2RGBA_YV12",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_YV12);
  mod.set_const("COLOR_YUV2BGRA_YV12",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_YV12);
  mod.set_const("COLOR_YUV2RGBA_IYUV",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_IYUV);
  mod.set_const("COLOR_YUV2BGRA_IYUV",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_IYUV);
  mod.set_const("COLOR_YUV2RGBA_I420",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_I420);
  mod.set_const("COLOR_YUV2BGRA_I420",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_I420);
  mod.set_const("COLOR_YUV420p2RGBA",
                cv::ColorConversionCodes::COLOR_YUV420p2RGBA);
  mod.set_const("COLOR_YUV420p2BGRA",
                cv::ColorConversionCodes::COLOR_YUV420p2BGRA);
  mod.set_const("COLOR_YUV2GRAY_420",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_420);
  mod.set_const("COLOR_YUV2GRAY_NV21",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_NV21);
  mod.set_const("COLOR_YUV2GRAY_NV12",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_NV12);
  mod.set_const("COLOR_YUV2GRAY_YV12",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_YV12);
  mod.set_const("COLOR_YUV2GRAY_IYUV",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_IYUV);
  mod.set_const("COLOR_YUV2GRAY_I420",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_I420);
  mod.set_const("COLOR_YUV420sp2GRAY",
                cv::ColorConversionCodes::COLOR_YUV420sp2GRAY);
  mod.set_const("COLOR_YUV420p2GRAY",
                cv::ColorConversionCodes::COLOR_YUV420p2GRAY);
  mod.set_const("COLOR_YUV2RGB_UYVY",
                cv::ColorConversionCodes::COLOR_YUV2RGB_UYVY);
  mod.set_const("COLOR_YUV2BGR_UYVY",
                cv::ColorConversionCodes::COLOR_YUV2BGR_UYVY);
  mod.set_const("COLOR_YUV2RGB_Y422",
                cv::ColorConversionCodes::COLOR_YUV2RGB_Y422);
  mod.set_const("COLOR_YUV2BGR_Y422",
                cv::ColorConversionCodes::COLOR_YUV2BGR_Y422);
  mod.set_const("COLOR_YUV2RGB_UYNV",
                cv::ColorConversionCodes::COLOR_YUV2RGB_UYNV);
  mod.set_const("COLOR_YUV2BGR_UYNV",
                cv::ColorConversionCodes::COLOR_YUV2BGR_UYNV);
  mod.set_const("COLOR_YUV2RGBA_UYVY",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_UYVY);
  mod.set_const("COLOR_YUV2BGRA_UYVY",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_UYVY);
  mod.set_const("COLOR_YUV2RGBA_Y422",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_Y422);
  mod.set_const("COLOR_YUV2BGRA_Y422",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_Y422);
  mod.set_const("COLOR_YUV2RGBA_UYNV",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_UYNV);
  mod.set_const("COLOR_YUV2BGRA_UYNV",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_UYNV);
  mod.set_const("COLOR_YUV2RGB_YUY2",
                cv::ColorConversionCodes::COLOR_YUV2RGB_YUY2);
  mod.set_const("COLOR_YUV2BGR_YUY2",
                cv::ColorConversionCodes::COLOR_YUV2BGR_YUY2);
  mod.set_const("COLOR_YUV2RGB_YVYU",
                cv::ColorConversionCodes::COLOR_YUV2RGB_YVYU);
  mod.set_const("COLOR_YUV2BGR_YVYU",
                cv::ColorConversionCodes::COLOR_YUV2BGR_YVYU);
  mod.set_const("COLOR_YUV2RGB_YUYV",
                cv::ColorConversionCodes::COLOR_YUV2RGB_YUYV);
  mod.set_const("COLOR_YUV2BGR_YUYV",
                cv::ColorConversionCodes::COLOR_YUV2BGR_YUYV);
  mod.set_const("COLOR_YUV2RGB_YUNV",
                cv::ColorConversionCodes::COLOR_YUV2RGB_YUNV);
  mod.set_const("COLOR_YUV2BGR_YUNV",
                cv::ColorConversionCodes::COLOR_YUV2BGR_YUNV);
  mod.set_const("COLOR_YUV2RGBA_YUY2",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_YUY2);
  mod.set_const("COLOR_YUV2BGRA_YUY2",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_YUY2);
  mod.set_const("COLOR_YUV2RGBA_YVYU",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_YVYU);
  mod.set_const("COLOR_YUV2BGRA_YVYU",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_YVYU);
  mod.set_const("COLOR_YUV2RGBA_YUYV",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_YUYV);
  mod.set_const("COLOR_YUV2BGRA_YUYV",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_YUYV);
  mod.set_const("COLOR_YUV2RGBA_YUNV",
                cv::ColorConversionCodes::COLOR_YUV2RGBA_YUNV);
  mod.set_const("COLOR_YUV2BGRA_YUNV",
                cv::ColorConversionCodes::COLOR_YUV2BGRA_YUNV);
  mod.set_const("COLOR_YUV2GRAY_UYVY",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_UYVY);
  mod.set_const("COLOR_YUV2GRAY_YUY2",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_YUY2);
  mod.set_const("COLOR_YUV2GRAY_Y422",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_Y422);
  mod.set_const("COLOR_YUV2GRAY_UYNV",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_UYNV);
  mod.set_const("COLOR_YUV2GRAY_YVYU",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_YVYU);
  mod.set_const("COLOR_YUV2GRAY_YUYV",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_YUYV);
  mod.set_const("COLOR_YUV2GRAY_YUNV",
                cv::ColorConversionCodes::COLOR_YUV2GRAY_YUNV);
  mod.set_const("COLOR_RGBA2mRGBA", cv::ColorConversionCodes::COLOR_RGBA2mRGBA);
  mod.set_const("COLOR_mRGBA2RGBA", cv::ColorConversionCodes::COLOR_mRGBA2RGBA);
  mod.set_const("COLOR_RGB2YUV_I420",
                cv::ColorConversionCodes::COLOR_RGB2YUV_I420);
  mod.set_const("COLOR_BGR2YUV_I420",
                cv::ColorConversionCodes::COLOR_BGR2YUV_I420);
  mod.set_const("COLOR_RGB2YUV_IYUV",
                cv::ColorConversionCodes::COLOR_RGB2YUV_IYUV);
  mod.set_const("COLOR_BGR2YUV_IYUV",
                cv::ColorConversionCodes::COLOR_BGR2YUV_IYUV);
  mod.set_const("COLOR_RGBA2YUV_I420",
                cv::ColorConversionCodes::COLOR_RGBA2YUV_I420);
  mod.set_const("COLOR_BGRA2YUV_I420",
                cv::ColorConversionCodes::COLOR_BGRA2YUV_I420);
  mod.set_const("COLOR_RGBA2YUV_IYUV",
                cv::ColorConversionCodes::COLOR_RGBA2YUV_IYUV);
  mod.set_const("COLOR_BGRA2YUV_IYUV",
                cv::ColorConversionCodes::COLOR_BGRA2YUV_IYUV);
  mod.set_const("COLOR_RGB2YUV_YV12",
                cv::ColorConversionCodes::COLOR_RGB2YUV_YV12);
  mod.set_const("COLOR_BGR2YUV_YV12",
                cv::ColorConversionCodes::COLOR_BGR2YUV_YV12);
  mod.set_const("COLOR_RGBA2YUV_YV12",
                cv::ColorConversionCodes::COLOR_RGBA2YUV_YV12);
  mod.set_const("COLOR_BGRA2YUV_YV12",
                cv::ColorConversionCodes::COLOR_BGRA2YUV_YV12);
  mod.set_const("COLOR_BayerBG2BGR",
                cv::ColorConversionCodes::COLOR_BayerBG2BGR);
  mod.set_const("COLOR_BayerGB2BGR",
                cv::ColorConversionCodes::COLOR_BayerGB2BGR);
  mod.set_const("COLOR_BayerRG2BGR",
                cv::ColorConversionCodes::COLOR_BayerRG2BGR);
  mod.set_const("COLOR_BayerGR2BGR",
                cv::ColorConversionCodes::COLOR_BayerGR2BGR);
  mod.set_const("COLOR_BayerBG2RGB",
                cv::ColorConversionCodes::COLOR_BayerBG2RGB);
  mod.set_const("COLOR_BayerGB2RGB",
                cv::ColorConversionCodes::COLOR_BayerGB2RGB);
  mod.set_const("COLOR_BayerRG2RGB",
                cv::ColorConversionCodes::COLOR_BayerRG2RGB);
  mod.set_const("COLOR_BayerGR2RGB",
                cv::ColorConversionCodes::COLOR_BayerGR2RGB);
  mod.set_const("COLOR_BayerBG2GRAY",
                cv::ColorConversionCodes::COLOR_BayerBG2GRAY);
  mod.set_const("COLOR_BayerGB2GRAY",
                cv::ColorConversionCodes::COLOR_BayerGB2GRAY);
  mod.set_const("COLOR_BayerRG2GRAY",
                cv::ColorConversionCodes::COLOR_BayerRG2GRAY);
  mod.set_const("COLOR_BayerGR2GRAY",
                cv::ColorConversionCodes::COLOR_BayerGR2GRAY);
  mod.set_const("COLOR_BayerBG2BGR_VNG",
                cv::ColorConversionCodes::COLOR_BayerBG2BGR_VNG);
  mod.set_const("COLOR_BayerGB2BGR_VNG",
                cv::ColorConversionCodes::COLOR_BayerGB2BGR_VNG);
  mod.set_const("COLOR_BayerRG2BGR_VNG",
                cv::ColorConversionCodes::COLOR_BayerRG2BGR_VNG);
  mod.set_const("COLOR_BayerGR2BGR_VNG",
                cv::ColorConversionCodes::COLOR_BayerGR2BGR_VNG);
  mod.set_const("COLOR_BayerBG2RGB_VNG",
                cv::ColorConversionCodes::COLOR_BayerBG2RGB_VNG);
  mod.set_const("COLOR_BayerGB2RGB_VNG",
                cv::ColorConversionCodes::COLOR_BayerGB2RGB_VNG);
  mod.set_const("COLOR_BayerRG2RGB_VNG",
                cv::ColorConversionCodes::COLOR_BayerRG2RGB_VNG);
  mod.set_const("COLOR_BayerGR2RGB_VNG",
                cv::ColorConversionCodes::COLOR_BayerGR2RGB_VNG);
  mod.set_const("COLOR_BayerBG2BGR_EA",
                cv::ColorConversionCodes::COLOR_BayerBG2BGR_EA);
  mod.set_const("COLOR_BayerGB2BGR_EA",
                cv::ColorConversionCodes::COLOR_BayerGB2BGR_EA);
  mod.set_const("COLOR_BayerRG2BGR_EA",
                cv::ColorConversionCodes::COLOR_BayerRG2BGR_EA);
  mod.set_const("COLOR_BayerGR2BGR_EA",
                cv::ColorConversionCodes::COLOR_BayerGR2BGR_EA);
  mod.set_const("COLOR_BayerBG2RGB_EA",
                cv::ColorConversionCodes::COLOR_BayerBG2RGB_EA);
  mod.set_const("COLOR_BayerGB2RGB_EA",
                cv::ColorConversionCodes::COLOR_BayerGB2RGB_EA);
  mod.set_const("COLOR_BayerRG2RGB_EA",
                cv::ColorConversionCodes::COLOR_BayerRG2RGB_EA);
  mod.set_const("COLOR_BayerGR2RGB_EA",
                cv::ColorConversionCodes::COLOR_BayerGR2RGB_EA);
  /* mod.set_const("COLOR_BayerBG2BGRA",
   cv::ColorConversionCodes::COLOR_BayerBG2BGRA);
  mod.set_const("COLOR_BayerGB2BGRA",
                cv::ColorConversionCodes::COLOR_BayerGB2BGRA);
  mod.set_const("COLOR_BayerRG2BGRA",
                cv::ColorConversionCodes::COLOR_BayerRG2BGRA);
  mod.set_const("COLOR_BayerGR2BGRA",
                cv::ColorConversionCodes::COLOR_BayerGR2BGRA);
  mod.set_const("COLOR_BayerBG2RGBA",
                cv::ColorConversionCodes::COLOR_BayerBG2RGBA);
  mod.set_const("COLOR_BayerGB2RGBA",
                cv::ColorConversionCodes::COLOR_BayerGB2RGBA);
  mod.set_const("COLOR_BayerRG2RGBA",
                cv::ColorConversionCodes::COLOR_BayerRG2RGBA);
  mod.set_const("COLOR_BayerGR2RGBA",
                cv::ColorConversionCodes::COLOR_BayerGR2RGBA);*/
  mod.set_const("COLOR_COLORCVT_MAX",
                cv::ColorConversionCodes::COLOR_COLORCVT_MAX);
  mod.add_bits<cv::RectanglesIntersectTypes>("RectanglesIntersectTypes");
  mod.set_const("INTERSECT_NONE", cv::RectanglesIntersectTypes::INTERSECT_NONE);
  mod.set_const("INTERSECT_PARTIAL",
                cv::RectanglesIntersectTypes::INTERSECT_PARTIAL);
  mod.set_const("INTERSECT_FULL", cv::RectanglesIntersectTypes::INTERSECT_FULL);
  mod.add_type<cv::GeneralizedHough>("GeneralizedHough")
      .method("setTemplate",
              [](cv::GeneralizedHough &instance, const cv::Mat &templ) {
                return instance.setTemplate(cv::InputArray(templ));
              })
      .method("setTemplate",
              [](cv::GeneralizedHough &instance, const cv::Mat &templ,
                 cv::Point templCenter) {
                return instance.setTemplate(cv::InputArray(templ), templCenter);
              })
      .method("setTemplate",
              [](cv::GeneralizedHough &instance, const cv::Mat &edges,
                 const cv::Mat &dx, const cv::Mat &dy) {
                return instance.setTemplate(cv::InputArray(edges),
                                            cv::InputArray(dx),
                                            cv::InputArray(dy));
              })
      .method("setTemplate",
              [](cv::GeneralizedHough &instance, const cv::Mat &edges,
                 const cv::Mat &dx, const cv::Mat &dy, cv::Point templCenter) {
                return instance.setTemplate(cv::InputArray(edges),
                                            cv::InputArray(dx),
                                            cv::InputArray(dy), templCenter);
              })
      .method("detect",
              [](cv::GeneralizedHough &instance, const cv::Mat &image,
                 const cv::Mat &positions, const cv::Mat &votes) {
                return instance.detect(cv::InputArray(image),
                                       cv::OutputArray(positions),
                                       cv::OutputArray(votes));
              })
      .method("detect",
              [](cv::GeneralizedHough &instance, const cv::Mat &edges,
                 const cv::Mat &dx, const cv::Mat &dy, const cv::Mat &positions,
                 const cv::Mat &votes) {
                return instance.detect(cv::InputArray(edges),
                                       cv::InputArray(dx), cv::InputArray(dy),
                                       cv::OutputArray(positions),
                                       cv::OutputArray(votes));
              })
      .method("setCannyLowThresh",
              [](cv::GeneralizedHough &instance, int cannyLowThresh) {
                return instance.setCannyLowThresh(cannyLowThresh);
              })
      .method("getCannyLowThresh",
              [](const cv::GeneralizedHough &instance) {
                return instance.getCannyLowThresh();
              })
      .method("setCannyHighThresh",
              [](cv::GeneralizedHough &instance, int cannyHighThresh) {
                return instance.setCannyHighThresh(cannyHighThresh);
              })
      .method("getCannyHighThresh",
              [](const cv::GeneralizedHough &instance) {
                return instance.getCannyHighThresh();
              })
      .method("setMinDist",
              [](cv::GeneralizedHough &instance, double minDist) {
                return instance.setMinDist(minDist);
              })
      .method("getMinDist",
              [](const cv::GeneralizedHough &instance) {
                return instance.getMinDist();
              })
      .method("setDp", [](cv::GeneralizedHough &instance,
                          double dp) { return instance.setDp(dp); })
      .method(
          "getDp",
          [](const cv::GeneralizedHough &instance) { return instance.getDp(); })
      .method("setMaxBufferSize",
              [](cv::GeneralizedHough &instance, int maxBufferSize) {
                return instance.setMaxBufferSize(maxBufferSize);
              })
      .method("getMaxBufferSize", [](const cv::GeneralizedHough &instance) {
        return instance.getMaxBufferSize();
      });
  mod.add_type<cv::GeneralizedHoughBallard>("GeneralizedHoughBallard")
      .method("setLevels",
              [](cv::GeneralizedHoughBallard &instance, int levels) {
                return instance.setLevels(levels);
              })
      .method("getLevels",
              [](const cv::GeneralizedHoughBallard &instance) {
                return instance.getLevels();
              })
      .method("setVotesThreshold",
              [](cv::GeneralizedHoughBallard &instance, int votesThreshold) {
                return instance.setVotesThreshold(votesThreshold);
              })
      .method("getVotesThreshold",
              [](const cv::GeneralizedHoughBallard &instance) {
                return instance.getVotesThreshold();
              });
  mod.add_type<cv::GeneralizedHoughGuil>("GeneralizedHoughGuil")
      .method("setXi", [](cv::GeneralizedHoughGuil &instance,
                          double xi) { return instance.setXi(xi); })
      .method("getXi",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getXi();
              })
      .method("setLevels",
              [](cv::GeneralizedHoughGuil &instance, int levels) {
                return instance.setLevels(levels);
              })
      .method("getLevels",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getLevels();
              })
      .method("setAngleEpsilon",
              [](cv::GeneralizedHoughGuil &instance, double angleEpsilon) {
                return instance.setAngleEpsilon(angleEpsilon);
              })
      .method("getAngleEpsilon",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getAngleEpsilon();
              })
      .method("setMinAngle",
              [](cv::GeneralizedHoughGuil &instance, double minAngle) {
                return instance.setMinAngle(minAngle);
              })
      .method("getMinAngle",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getMinAngle();
              })
      .method("setMaxAngle",
              [](cv::GeneralizedHoughGuil &instance, double maxAngle) {
                return instance.setMaxAngle(maxAngle);
              })
      .method("getMaxAngle",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getMaxAngle();
              })
      .method("setAngleStep",
              [](cv::GeneralizedHoughGuil &instance, double angleStep) {
                return instance.setAngleStep(angleStep);
              })
      .method("getAngleStep",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getAngleStep();
              })
      .method("setAngleThresh",
              [](cv::GeneralizedHoughGuil &instance, int angleThresh) {
                return instance.setAngleThresh(angleThresh);
              })
      .method("getAngleThresh",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getAngleThresh();
              })
      .method("setMinScale",
              [](cv::GeneralizedHoughGuil &instance, double minScale) {
                return instance.setMinScale(minScale);
              })
      .method("getMinScale",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getMinScale();
              })
      .method("setMaxScale",
              [](cv::GeneralizedHoughGuil &instance, double maxScale) {
                return instance.setMaxScale(maxScale);
              })
      .method("getMaxScale",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getMaxScale();
              })
      .method("setScaleStep",
              [](cv::GeneralizedHoughGuil &instance, double scaleStep) {
                return instance.setScaleStep(scaleStep);
              })
      .method("getScaleStep",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getScaleStep();
              })
      .method("setScaleThresh",
              [](cv::GeneralizedHoughGuil &instance, int scaleThresh) {
                return instance.setScaleThresh(scaleThresh);
              })
      .method("getScaleThresh",
              [](const cv::GeneralizedHoughGuil &instance) {
                return instance.getScaleThresh();
              })
      .method("setPosThresh",
              [](cv::GeneralizedHoughGuil &instance, int posThresh) {
                return instance.setPosThresh(posThresh);
              })
      .method("getPosThresh", [](const cv::GeneralizedHoughGuil &instance) {
        return instance.getPosThresh();
      });
  mod.add_type<cv::CLAHE>("CLAHE")
      .method("apply",
              [](cv::CLAHE &instance, const cv::Mat &src, const cv::Mat &dst) {
                return instance.apply(cv::InputArray(src),
                                      cv::OutputArray(dst));
              })
      .method("setClipLimit",
              [](cv::CLAHE &instance, double clipLimit) {
                return instance.setClipLimit(clipLimit);
              })
      .method("getClipLimit",
              [](const cv::CLAHE &instance) { return instance.getClipLimit(); })
      .method("setTilesGridSize",
              [](cv::CLAHE &instance, cv::Size tileGridSize) {
                return instance.setTilesGridSize(tileGridSize);
              })
      .method(
          "getTilesGridSize",
          [](const cv::CLAHE &instance) { return instance.getTilesGridSize(); })
      .method("collectGarbage",
              [](cv::CLAHE &instance) { return instance.collectGarbage(); });
  mod.add_type<cv::Subdiv2D>("Subdiv2D")
      .constructor<cv::Rect>()
      .method("initDelaunay",
              [](cv::Subdiv2D &instance, cv::Rect rect) {
                return instance.initDelaunay(rect);
              })
      .method("insert", [](cv::Subdiv2D &instance,
                           cv::Point2f pt) { return instance.insert(pt); })
      .method("insert",
              [](cv::Subdiv2D &instance, const std::vector<Point2f> &ptvec) {
                return instance.insert(ptvec);
              })
      .method("locate",
              [](cv::Subdiv2D &instance, cv::Point2f pt, int &edge,
                 int &vertex) { return instance.locate(pt, edge, vertex); })
      .method("findNearest",
              [](cv::Subdiv2D &instance, cv::Point2f pt) {
                return instance.findNearest(pt);
              })
      .method(
          "findNearest",
          [](cv::Subdiv2D &instance, cv::Point2f pt, cv::Point2f *nearestPt) {
            return instance.findNearest(pt, nearestPt);
          })
      .method(
          "getEdgeList",
          [](const cv::Subdiv2D &instance, const std::vector<Vec4f> &edgeList) {
            return instance.getEdgeList(const_off(edgeList));
          })
      .method("getLeadingEdgeList",
              [](const cv::Subdiv2D &instance,
                 const std::vector<int> &leadingEdgeList) {
                return instance.getLeadingEdgeList(const_off(leadingEdgeList));
              })
      .method("getTriangleList",
              [](const cv::Subdiv2D &instance,
                 const std::vector<Vec6f> &triangleList) {
                return instance.getTriangleList(const_off(triangleList));
              })
      .method("getVoronoiFacetList",
              [](cv::Subdiv2D &instance, const std::vector<int> &idx,
                 const std::vector<std::vector<Point2f> > &facetList,
                 const std::vector<Point2f> &facetCenters) {
                return instance.getVoronoiFacetList(idx, const_off(facetList),
                                                    const_off(facetCenters));
              })
      .method("getVertex",
              [](const cv::Subdiv2D &instance, int vertex) {
                return instance.getVertex(vertex);
              })
      .method("getVertex",
              [](const cv::Subdiv2D &instance, int vertex, int *firstEdge) {
                return instance.getVertex(vertex, firstEdge);
              })
      .method("getEdge",
              [](const cv::Subdiv2D &instance, int edge, int nextEdgeType) {
                return instance.getEdge(edge, nextEdgeType);
              })
      .method("nextEdge", [](const cv::Subdiv2D &instance,
                             int edge) { return instance.nextEdge(edge); })
      .method("rotateEdge",
              [](const cv::Subdiv2D &instance, int edge, int rotate) {
                return instance.rotateEdge(edge, rotate);
              })
      .method("symEdge", [](const cv::Subdiv2D &instance,
                            int edge) { return instance.symEdge(edge); })
      .method("edgeOrg", [](const cv::Subdiv2D &instance,
                            int edge) { return instance.edgeOrg(edge); })
      .method("edgeOrg",
              [](const cv::Subdiv2D &instance, int edge, cv::Point2f *orgpt) {
                return instance.edgeOrg(edge, orgpt);
              })
      .method("edgeDst", [](const cv::Subdiv2D &instance,
                            int edge) { return instance.edgeDst(edge); })
      .method("edgeDst",
              [](const cv::Subdiv2D &instance, int edge, cv::Point2f *dstpt) {
                return instance.edgeDst(edge, dstpt);
              });
  mod.add_type<cv::LineSegmentDetector>("LineSegmentDetector")
      .method("detect",
              [](cv::LineSegmentDetector &instance, const cv::Mat &_image,
                 const cv::Mat &_lines, const cv::Mat &width,
                 const cv::Mat &prec, const cv::Mat &nfa) {
                return instance.detect(
                    cv::InputArray(_image), cv::OutputArray(_lines),
                    cv::OutputArray(width), cv::OutputArray(prec),
                    cv::OutputArray(nfa));
              })
      .method("drawSegments",
              [](cv::LineSegmentDetector &instance, const cv::Mat &_image,
                 const cv::Mat &lines) {
                return instance.drawSegments(cv::InputOutputArray(_image),
                                             cv::InputArray(lines));
              })
      .method("compareSegments",
              [](cv::LineSegmentDetector &instance, const cv::Size &size,
                 const cv::Mat &lines1, const cv::Mat &lines2) {
                return instance.compareSegments(size, cv::InputArray(lines1),
                                                cv::InputArray(lines2));
              })
      .method("compareSegments",
              [](cv::LineSegmentDetector &instance, const cv::Size &size,
                 const cv::Mat &lines1, const cv::Mat &lines2,
                 const cv::Mat &_image) {
                return instance.compareSegments(size, cv::InputArray(lines1),
                                                cv::InputArray(lines2),
                                                cv::InputOutputArray(_image));
              });
  mod.method("createLineSegmentDetector",
             []() { return cv::createLineSegmentDetector(); });
  mod.method("createLineSegmentDetector", [](int _refine) {
    return cv::createLineSegmentDetector(_refine);
  });
  mod.method("createLineSegmentDetector", [](int _refine, double _scale) {
    return cv::createLineSegmentDetector(_refine, _scale);
  });
  mod.method("createLineSegmentDetector", [](int _refine, double _scale,
                                             double _sigma_scale) {
    return cv::createLineSegmentDetector(_refine, _scale, _sigma_scale);
  });
  mod.method("createLineSegmentDetector", [](int _refine, double _scale,
                                             double _sigma_scale,
                                             double _quant) {
    return cv::createLineSegmentDetector(_refine, _scale, _sigma_scale, _quant);
  });
  mod.method("createLineSegmentDetector",
             [](int _refine, double _scale, double _sigma_scale, double _quant,
                double _ang_th) {
               return cv::createLineSegmentDetector(
                   _refine, _scale, _sigma_scale, _quant, _ang_th);
             });
  mod.method("createLineSegmentDetector",
             [](int _refine, double _scale, double _sigma_scale, double _quant,
                double _ang_th, double _log_eps) {
               return cv::createLineSegmentDetector(
                   _refine, _scale, _sigma_scale, _quant, _ang_th, _log_eps);
             });
  mod.method("createLineSegmentDetector",
             [](int _refine, double _scale, double _sigma_scale, double _quant,
                double _ang_th, double _log_eps, double _density_th) {
               return cv::createLineSegmentDetector(
                   _refine, _scale, _sigma_scale, _quant, _ang_th, _log_eps,
                   _density_th);
             });
  mod.method(
      "createLineSegmentDetector",
      [](int _refine, double _scale, double _sigma_scale, double _quant,
         double _ang_th, double _log_eps, double _density_th, int _n_bins) {
        return cv::createLineSegmentDetector(_refine, _scale, _sigma_scale,
                                             _quant, _ang_th, _log_eps,
                                             _density_th, _n_bins);
      });
  mod.method("getGaussianKernel", [](int ksize, double sigma) {
    return cv::getGaussianKernel(ksize, sigma);
  });
  mod.method("getGaussianKernel", [](int ksize, double sigma, int ktype) {
    return cv::getGaussianKernel(ksize, sigma, ktype);
  });
  mod.method("getDerivKernels", [](const cv::Mat &kx, const cv::Mat &ky, int dx,
                                   int dy, int ksize) {
    return cv::getDerivKernels(cv::OutputArray(kx), cv::OutputArray(ky), dx, dy,
                               ksize);
  });
  mod.method("getDerivKernels", [](const cv::Mat &kx, const cv::Mat &ky, int dx,
                                   int dy, int ksize, bool normalize) {
    return cv::getDerivKernels(cv::OutputArray(kx), cv::OutputArray(ky), dx, dy,
                               ksize, normalize);
  });
  mod.method(
      "getDerivKernels", [](const cv::Mat &kx, const cv::Mat &ky, int dx,
                            int dy, int ksize, bool normalize, int ktype) {
        return cv::getDerivKernels(cv::OutputArray(kx), cv::OutputArray(ky), dx,
                                   dy, ksize, normalize, ktype);
      });
  mod.method("getGaborKernel", [](cv::Size ksize, double sigma, double theta,
                                  double lambd, double gamma) {
    return cv::getGaborKernel(ksize, sigma, theta, lambd, gamma);
  });
  mod.method("getGaborKernel", [](cv::Size ksize, double sigma, double theta,
                                  double lambd, double gamma, double psi) {
    return cv::getGaborKernel(ksize, sigma, theta, lambd, gamma, psi);
  });
  mod.method("getGaborKernel", [](cv::Size ksize, double sigma, double theta,
                                  double lambd, double gamma, double psi,
                                  int ktype) {
    return cv::getGaborKernel(ksize, sigma, theta, lambd, gamma, psi, ktype);
  });
  mod.method("getStructuringElement", [](int shape, cv::Size ksize) {
    return cv::getStructuringElement(shape, ksize);
  });
  mod.method("getStructuringElement",
             [](int shape, cv::Size ksize, cv::Point anchor) {
               return cv::getStructuringElement(shape, ksize, anchor);
             });
  mod.method(
      "medianBlur", [](const cv::Mat &src, const cv::Mat &dst, int ksize) {
        return cv::medianBlur(cv::InputArray(src), cv::OutputArray(dst), ksize);
      });
  mod.method("GaussianBlur", [](const cv::Mat &src, const cv::Mat &dst,
                                cv::Size ksize, double sigmaX) {
    return cv::GaussianBlur(cv::InputArray(src), cv::OutputArray(dst), ksize,
                            sigmaX);
  });
  mod.method("GaussianBlur", [](const cv::Mat &src, const cv::Mat &dst,
                                cv::Size ksize, double sigmaX, double sigmaY) {
    return cv::GaussianBlur(cv::InputArray(src), cv::OutputArray(dst), ksize,
                            sigmaX, sigmaY);
  });
  mod.method(
      "GaussianBlur", [](const cv::Mat &src, const cv::Mat &dst, cv::Size ksize,
                         double sigmaX, double sigmaY, int borderType) {
        return cv::GaussianBlur(cv::InputArray(src), cv::OutputArray(dst),
                                ksize, sigmaX, sigmaY, borderType);
      });
  mod.method(
      "bilateralFilter", [](const cv::Mat &src, const cv::Mat &dst, int d,
                            double sigmaColor, double sigmaSpace) {
        return cv::bilateralFilter(cv::InputArray(src), cv::OutputArray(dst), d,
                                   sigmaColor, sigmaSpace);
      });
  mod.method("bilateralFilter", [](const cv::Mat &src, const cv::Mat &dst,
                                   int d, double sigmaColor, double sigmaSpace,
                                   int borderType) {
    return cv::bilateralFilter(cv::InputArray(src), cv::OutputArray(dst), d,
                               sigmaColor, sigmaSpace, borderType);
  });
  mod.method("boxFilter", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                             cv::Size ksize) {
    return cv::boxFilter(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                         ksize);
  });
  mod.method("boxFilter", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                             cv::Size ksize, cv::Point anchor) {
    return cv::boxFilter(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                         ksize, anchor);
  });
  mod.method("boxFilter", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                             cv::Size ksize, cv::Point anchor, bool normalize) {
    return cv::boxFilter(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                         ksize, anchor, normalize);
  });
  mod.method("boxFilter", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                             cv::Size ksize, cv::Point anchor, bool normalize,
                             int borderType) {
    return cv::boxFilter(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                         ksize, anchor, normalize, borderType);
  });
  mod.method("sqrBoxFilter", [](const cv::Mat &_src, const cv::Mat &_dst,
                                int ddepth, cv::Size ksize) {
    return cv::sqrBoxFilter(cv::InputArray(_src), cv::OutputArray(_dst), ddepth,
                            ksize);
  });
  mod.method("sqrBoxFilter", [](const cv::Mat &_src, const cv::Mat &_dst,
                                int ddepth, cv::Size ksize, cv::Point anchor) {
    return cv::sqrBoxFilter(cv::InputArray(_src), cv::OutputArray(_dst), ddepth,
                            ksize, anchor);
  });
  mod.method(
      "sqrBoxFilter", [](const cv::Mat &_src, const cv::Mat &_dst, int ddepth,
                         cv::Size ksize, cv::Point anchor, bool normalize) {
        return cv::sqrBoxFilter(cv::InputArray(_src), cv::OutputArray(_dst),
                                ddepth, ksize, anchor, normalize);
      });
  mod.method("sqrBoxFilter", [](const cv::Mat &_src, const cv::Mat &_dst,
                                int ddepth, cv::Size ksize, cv::Point anchor,
                                bool normalize, int borderType) {
    return cv::sqrBoxFilter(cv::InputArray(_src), cv::OutputArray(_dst), ddepth,
                            ksize, anchor, normalize, borderType);
  });
  mod.method(
      "blur", [](const cv::Mat &src, const cv::Mat &dst, cv::Size ksize) {
        return cv::blur(cv::InputArray(src), cv::OutputArray(dst), ksize);
      });
  mod.method("blur", [](const cv::Mat &src, const cv::Mat &dst, cv::Size ksize,
                        cv::Point anchor) {
    return cv::blur(cv::InputArray(src), cv::OutputArray(dst), ksize, anchor);
  });
  mod.method("blur", [](const cv::Mat &src, const cv::Mat &dst, cv::Size ksize,
                        cv::Point anchor, int borderType) {
    return cv::blur(cv::InputArray(src), cv::OutputArray(dst), ksize, anchor,
                    borderType);
  });
  mod.method("filter2D", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                            const cv::Mat &kernel) {
    return cv::filter2D(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                        cv::InputArray(kernel));
  });
  mod.method("filter2D", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                            const cv::Mat &kernel, cv::Point anchor) {
    return cv::filter2D(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                        cv::InputArray(kernel), anchor);
  });
  mod.method(
      "filter2D", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                     const cv::Mat &kernel, cv::Point anchor, double delta) {
        return cv::filter2D(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                            cv::InputArray(kernel), anchor, delta);
      });
  mod.method("filter2D", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                            const cv::Mat &kernel, cv::Point anchor,
                            double delta, int borderType) {
    return cv::filter2D(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                        cv::InputArray(kernel), anchor, delta, borderType);
  });
  mod.method("sepFilter2D", [](const cv::Mat &src, const cv::Mat &dst,
                               int ddepth, const cv::Mat &kernelX,
                               const cv::Mat &kernelY) {
    return cv::sepFilter2D(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                           cv::InputArray(kernelX), cv::InputArray(kernelY));
  });
  mod.method("sepFilter2D", [](const cv::Mat &src, const cv::Mat &dst,
                               int ddepth, const cv::Mat &kernelX,
                               const cv::Mat &kernelY, cv::Point anchor) {
    return cv::sepFilter2D(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                           cv::InputArray(kernelX), cv::InputArray(kernelY),
                           anchor);
  });
  mod.method("sepFilter2D",
             [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                const cv::Mat &kernelX, const cv::Mat &kernelY,
                cv::Point anchor, double delta) {
               return cv::sepFilter2D(cv::InputArray(src), cv::OutputArray(dst),
                                      ddepth, cv::InputArray(kernelX),
                                      cv::InputArray(kernelY), anchor, delta);
             });
  mod.method("sepFilter2D", [](const cv::Mat &src, const cv::Mat &dst,
                               int ddepth, const cv::Mat &kernelX,
                               const cv::Mat &kernelY, cv::Point anchor,
                               double delta, int borderType) {
    return cv::sepFilter2D(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                           cv::InputArray(kernelX), cv::InputArray(kernelY),
                           anchor, delta, borderType);
  });
  mod.method("Sobel", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                         int dx, int dy) {
    return cv::Sobel(cv::InputArray(src), cv::OutputArray(dst), ddepth, dx, dy);
  });
  mod.method("Sobel", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                         int dx, int dy, int ksize) {
    return cv::Sobel(cv::InputArray(src), cv::OutputArray(dst), ddepth, dx, dy,
                     ksize);
  });
  mod.method("Sobel", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                         int dx, int dy, int ksize, double scale) {
    return cv::Sobel(cv::InputArray(src), cv::OutputArray(dst), ddepth, dx, dy,
                     ksize, scale);
  });
  mod.method("Sobel",
             [](const cv::Mat &src, const cv::Mat &dst, int ddepth, int dx,
                int dy, int ksize, double scale, double delta) {
               return cv::Sobel(cv::InputArray(src), cv::OutputArray(dst),
                                ddepth, dx, dy, ksize, scale, delta);
             });
  mod.method("Sobel", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                         int dx, int dy, int ksize, double scale, double delta,
                         int borderType) {
    return cv::Sobel(cv::InputArray(src), cv::OutputArray(dst), ddepth, dx, dy,
                     ksize, scale, delta, borderType);
  });
  mod.method("spatialGradient", [](const cv::Mat &src, const cv::Mat &dx,
                                   const cv::Mat &dy) {
    return cv::spatialGradient(cv::InputArray(src), cv::OutputArray(dx),
                               cv::OutputArray(dy));
  });
  mod.method("spatialGradient", [](const cv::Mat &src, const cv::Mat &dx,
                                   const cv::Mat &dy, int ksize) {
    return cv::spatialGradient(cv::InputArray(src), cv::OutputArray(dx),
                               cv::OutputArray(dy), ksize);
  });
  mod.method(
      "spatialGradient", [](const cv::Mat &src, const cv::Mat &dx,
                            const cv::Mat &dy, int ksize, int borderType) {
        return cv::spatialGradient(cv::InputArray(src), cv::OutputArray(dx),
                                   cv::OutputArray(dy), ksize, borderType);
      });
  mod.method("Scharr", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                          int dx, int dy) {
    return cv::Scharr(cv::InputArray(src), cv::OutputArray(dst), ddepth, dx,
                      dy);
  });
  mod.method("Scharr", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                          int dx, int dy, double scale) {
    return cv::Scharr(cv::InputArray(src), cv::OutputArray(dst), ddepth, dx, dy,
                      scale);
  });
  mod.method("Scharr", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                          int dx, int dy, double scale, double delta) {
    return cv::Scharr(cv::InputArray(src), cv::OutputArray(dst), ddepth, dx, dy,
                      scale, delta);
  });
  mod.method("Scharr",
             [](const cv::Mat &src, const cv::Mat &dst, int ddepth, int dx,
                int dy, double scale, double delta, int borderType) {
               return cv::Scharr(cv::InputArray(src), cv::OutputArray(dst),
                                 ddepth, dx, dy, scale, delta, borderType);
             });
  mod.method(
      "Laplacian", [](const cv::Mat &src, const cv::Mat &dst, int ddepth) {
        return cv::Laplacian(cv::InputArray(src), cv::OutputArray(dst), ddepth);
      });
  mod.method("Laplacian",
             [](const cv::Mat &src, const cv::Mat &dst, int ddepth, int ksize) {
               return cv::Laplacian(cv::InputArray(src), cv::OutputArray(dst),
                                    ddepth, ksize);
             });
  mod.method("Laplacian", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                             int ksize, double scale) {
    return cv::Laplacian(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                         ksize, scale);
  });
  mod.method("Laplacian", [](const cv::Mat &src, const cv::Mat &dst, int ddepth,
                             int ksize, double scale, double delta) {
    return cv::Laplacian(cv::InputArray(src), cv::OutputArray(dst), ddepth,
                         ksize, scale, delta);
  });
  mod.method("Laplacian",
             [](const cv::Mat &src, const cv::Mat &dst, int ddepth, int ksize,
                double scale, double delta, int borderType) {
               return cv::Laplacian(cv::InputArray(src), cv::OutputArray(dst),
                                    ddepth, ksize, scale, delta, borderType);
             });
  mod.method("Canny", [](const cv::Mat &image, const cv::Mat &edges,
                         double threshold1, double threshold2) {
    return cv::Canny(cv::InputArray(image), cv::OutputArray(edges), threshold1,
                     threshold2);
  });
  mod.method("Canny",
             [](const cv::Mat &image, const cv::Mat &edges, double threshold1,
                double threshold2, int apertureSize) {
               return cv::Canny(cv::InputArray(image), cv::OutputArray(edges),
                                threshold1, threshold2, apertureSize);
             });
  mod.method(
      "Canny", [](const cv::Mat &image, const cv::Mat &edges, double threshold1,
                  double threshold2, int apertureSize, bool L2gradient) {
        return cv::Canny(cv::InputArray(image), cv::OutputArray(edges),
                         threshold1, threshold2, apertureSize, L2gradient);
      });
  mod.method("Canny",
             [](const cv::Mat &dx, const cv::Mat &dy, const cv::Mat &edges,
                double threshold1, double threshold2) {
               return cv::Canny(cv::InputArray(dx), cv::InputArray(dy),
                                cv::OutputArray(edges), threshold1, threshold2);
             });
  mod.method("Canny",
             [](const cv::Mat &dx, const cv::Mat &dy, const cv::Mat &edges,
                double threshold1, double threshold2, bool L2gradient) {
               return cv::Canny(cv::InputArray(dx), cv::InputArray(dy),
                                cv::OutputArray(edges), threshold1, threshold2,
                                L2gradient);
             });
  mod.method("cornerMinEigenVal",
             [](const cv::Mat &src, const cv::Mat &dst, int blockSize) {
               return cv::cornerMinEigenVal(cv::InputArray(src),
                                            cv::OutputArray(dst), blockSize);
             });
  mod.method("cornerMinEigenVal", [](const cv::Mat &src, const cv::Mat &dst,
                                     int blockSize, int ksize) {
    return cv::cornerMinEigenVal(cv::InputArray(src), cv::OutputArray(dst),
                                 blockSize, ksize);
  });
  mod.method("cornerMinEigenVal", [](const cv::Mat &src, const cv::Mat &dst,
                                     int blockSize, int ksize, int borderType) {
    return cv::cornerMinEigenVal(cv::InputArray(src), cv::OutputArray(dst),
                                 blockSize, ksize, borderType);
  });
  mod.method("cornerHarris", [](const cv::Mat &src, const cv::Mat &dst,
                                int blockSize, int ksize, double k) {
    return cv::cornerHarris(cv::InputArray(src), cv::OutputArray(dst),
                            blockSize, ksize, k);
  });
  mod.method(
      "cornerHarris", [](const cv::Mat &src, const cv::Mat &dst, int blockSize,
                         int ksize, double k, int borderType) {
        return cv::cornerHarris(cv::InputArray(src), cv::OutputArray(dst),
                                blockSize, ksize, k, borderType);
      });
  mod.method(
      "cornerEigenValsAndVecs",
      [](const cv::Mat &src, const cv::Mat &dst, int blockSize, int ksize) {
        return cv::cornerEigenValsAndVecs(
            cv::InputArray(src), cv::OutputArray(dst), blockSize, ksize);
      });
  mod.method("cornerEigenValsAndVecs", [](const cv::Mat &src,
                                          const cv::Mat &dst, int blockSize,
                                          int ksize, int borderType) {
    return cv::cornerEigenValsAndVecs(cv::InputArray(src), cv::OutputArray(dst),
                                      blockSize, ksize, borderType);
  });
  mod.method("preCornerDetect",
             [](const cv::Mat &src, const cv::Mat &dst, int ksize) {
               return cv::preCornerDetect(cv::InputArray(src),
                                          cv::OutputArray(dst), ksize);
             });
  mod.method("preCornerDetect", [](const cv::Mat &src, const cv::Mat &dst,
                                   int ksize, int borderType) {
    return cv::preCornerDetect(cv::InputArray(src), cv::OutputArray(dst), ksize,
                               borderType);
  });
  mod.method("cornerSubPix",
             [](const cv::Mat &image, const cv::Mat &corners, cv::Size winSize,
                cv::Size zeroZone, cv::TermCriteria criteria) {
               return cv::cornerSubPix(cv::InputArray(image),
                                       cv::InputOutputArray(corners), winSize,
                                       zeroZone, criteria);
             });
  mod.method("goodFeaturesToTrack",
             [](const cv::Mat &image, const cv::Mat &corners, int maxCorners,
                double qualityLevel, double minDistance, const cv::Mat &mask) {
               return cv::goodFeaturesToTrack(
                   cv::InputArray(image), cv::OutputArray(corners), maxCorners,
                   qualityLevel, minDistance, cv::InputArray(mask));
             });
  mod.method("goodFeaturesToTrack",
             [](const cv::Mat &image, const cv::Mat &corners, int maxCorners,
                double qualityLevel, double minDistance, const cv::Mat &mask,
                int blockSize) {
               return cv::goodFeaturesToTrack(
                   cv::InputArray(image), cv::OutputArray(corners), maxCorners,
                   qualityLevel, minDistance, cv::InputArray(mask), blockSize);
             });
  mod.method("goodFeaturesToTrack",
             [](const cv::Mat &image, const cv::Mat &corners, int maxCorners,
                double qualityLevel, double minDistance, const cv::Mat &mask,
                int blockSize, bool useHarrisDetector) {
               return cv::goodFeaturesToTrack(
                   cv::InputArray(image), cv::OutputArray(corners), maxCorners,
                   qualityLevel, minDistance, cv::InputArray(mask), blockSize,
                   useHarrisDetector);
             });
  mod.method("goodFeaturesToTrack",
             [](const cv::Mat &image, const cv::Mat &corners, int maxCorners,
                double qualityLevel, double minDistance, const cv::Mat &mask,
                int blockSize, bool useHarrisDetector, double k) {
               return cv::goodFeaturesToTrack(
                   cv::InputArray(image), cv::OutputArray(corners), maxCorners,
                   qualityLevel, minDistance, cv::InputArray(mask), blockSize,
                   useHarrisDetector, k);
             });
  mod.method("goodFeaturesToTrack",
             [](const cv::Mat &image, const cv::Mat &corners, int maxCorners,
                double qualityLevel, double minDistance, const cv::Mat &mask,
                int blockSize, int gradientSize) {
               return cv::goodFeaturesToTrack(
                   cv::InputArray(image), cv::OutputArray(corners), maxCorners,
                   qualityLevel, minDistance, cv::InputArray(mask), blockSize,
                   gradientSize);
             });
  mod.method("goodFeaturesToTrack",
             [](const cv::Mat &image, const cv::Mat &corners, int maxCorners,
                double qualityLevel, double minDistance, const cv::Mat &mask,
                int blockSize, int gradientSize, bool useHarrisDetector) {
               return cv::goodFeaturesToTrack(
                   cv::InputArray(image), cv::OutputArray(corners), maxCorners,
                   qualityLevel, minDistance, cv::InputArray(mask), blockSize,
                   gradientSize, useHarrisDetector);
             });
  mod.method(
      "goodFeaturesToTrack",
      [](const cv::Mat &image, const cv::Mat &corners, int maxCorners,
         double qualityLevel, double minDistance, const cv::Mat &mask,
         int blockSize, int gradientSize, bool useHarrisDetector, double k) {
        return cv::goodFeaturesToTrack(
            cv::InputArray(image), cv::OutputArray(corners), maxCorners,
            qualityLevel, minDistance, cv::InputArray(mask), blockSize,
            gradientSize, useHarrisDetector, k);
      });
  mod.method("HoughLines", [](const cv::Mat &image, const cv::Mat &lines,
                              double rho, double theta, int threshold) {
    return cv::HoughLines(cv::InputArray(image), cv::OutputArray(lines), rho,
                          theta, threshold);
  });
  mod.method(
      "HoughLines", [](const cv::Mat &image, const cv::Mat &lines, double rho,
                       double theta, int threshold, double srn) {
        return cv::HoughLines(cv::InputArray(image), cv::OutputArray(lines),
                              rho, theta, threshold, srn);
      });
  mod.method(
      "HoughLines", [](const cv::Mat &image, const cv::Mat &lines, double rho,
                       double theta, int threshold, double srn, double stn) {
        return cv::HoughLines(cv::InputArray(image), cv::OutputArray(lines),
                              rho, theta, threshold, srn, stn);
      });
  mod.method("HoughLines", [](const cv::Mat &image, const cv::Mat &lines,
                              double rho, double theta, int threshold,
                              double srn, double stn, double min_theta) {
    return cv::HoughLines(cv::InputArray(image), cv::OutputArray(lines), rho,
                          theta, threshold, srn, stn, min_theta);
  });
  mod.method("HoughLines", [](const cv::Mat &image, const cv::Mat &lines,
                              double rho, double theta, int threshold,
                              double srn, double stn, double min_theta,
                              double max_theta) {
    return cv::HoughLines(cv::InputArray(image), cv::OutputArray(lines), rho,
                          theta, threshold, srn, stn, min_theta, max_theta);
  });
  mod.method("HoughLinesP", [](const cv::Mat &image, const cv::Mat &lines,
                               double rho, double theta, int threshold) {
    return cv::HoughLinesP(cv::InputArray(image), cv::OutputArray(lines), rho,
                           theta, threshold);
  });
  mod.method(
      "HoughLinesP", [](const cv::Mat &image, const cv::Mat &lines, double rho,
                        double theta, int threshold, double minLineLength) {
        return cv::HoughLinesP(cv::InputArray(image), cv::OutputArray(lines),
                               rho, theta, threshold, minLineLength);
      });
  mod.method("HoughLinesP", [](const cv::Mat &image, const cv::Mat &lines,
                               double rho, double theta, int threshold,
                               double minLineLength, double maxLineGap) {
    return cv::HoughLinesP(cv::InputArray(image), cv::OutputArray(lines), rho,
                           theta, threshold, minLineLength, maxLineGap);
  });
  mod.method("HoughLinesPointSet",
             [](const cv::Mat &_point, const cv::Mat &_lines, int lines_max,
                int threshold, double min_rho, double max_rho, double rho_step,
                double min_theta, double max_theta, double theta_step) {
               return cv::HoughLinesPointSet(
                   cv::InputArray(_point), cv::OutputArray(_lines), lines_max,
                   threshold, min_rho, max_rho, rho_step, min_theta, max_theta,
                   theta_step);
             });
  mod.method("HoughCircles", [](const cv::Mat &image, const cv::Mat &circles,
                                int method, double dp, double minDist) {
    return cv::HoughCircles(cv::InputArray(image), cv::OutputArray(circles),
                            method, dp, minDist);
  });
  mod.method(
      "HoughCircles", [](const cv::Mat &image, const cv::Mat &circles,
                         int method, double dp, double minDist, double param1) {
        return cv::HoughCircles(cv::InputArray(image), cv::OutputArray(circles),
                                method, dp, minDist, param1);
      });
  mod.method("HoughCircles", [](const cv::Mat &image, const cv::Mat &circles,
                                int method, double dp, double minDist,
                                double param1, double param2) {
    return cv::HoughCircles(cv::InputArray(image), cv::OutputArray(circles),
                            method, dp, minDist, param1, param2);
  });
  mod.method("HoughCircles", [](const cv::Mat &image, const cv::Mat &circles,
                                int method, double dp, double minDist,
                                double param1, double param2, int minRadius) {
    return cv::HoughCircles(cv::InputArray(image), cv::OutputArray(circles),
                            method, dp, minDist, param1, param2, minRadius);
  });
  mod.method(
      "HoughCircles", [](const cv::Mat &image, const cv::Mat &circles,
                         int method, double dp, double minDist, double param1,
                         double param2, int minRadius, int maxRadius) {
        return cv::HoughCircles(cv::InputArray(image), cv::OutputArray(circles),
                                method, dp, minDist, param1, param2, minRadius,
                                maxRadius);
      });
  mod.method("erode",
             [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &kernel) {
               return cv::erode(cv::InputArray(src), cv::OutputArray(dst),
                                cv::InputArray(kernel));
             });
  mod.method("erode", [](const cv::Mat &src, const cv::Mat &dst,
                         const cv::Mat &kernel, cv::Point anchor) {
    return cv::erode(cv::InputArray(src), cv::OutputArray(dst),
                     cv::InputArray(kernel), anchor);
  });
  mod.method("erode",
             [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &kernel,
                cv::Point anchor, int iterations) {
               return cv::erode(cv::InputArray(src), cv::OutputArray(dst),
                                cv::InputArray(kernel), anchor, iterations);
             });
  mod.method("erode", [](const cv::Mat &src, const cv::Mat &dst,
                         const cv::Mat &kernel, cv::Point anchor,
                         int iterations, int borderType) {
    return cv::erode(cv::InputArray(src), cv::OutputArray(dst),
                     cv::InputArray(kernel), anchor, iterations, borderType);
  });
  mod.method("erode",
             [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &kernel,
                cv::Point anchor, int iterations, int borderType,
                const cv::Scalar &borderValue) {
               return cv::erode(cv::InputArray(src), cv::OutputArray(dst),
                                cv::InputArray(kernel), anchor, iterations,
                                borderType, borderValue);
             });
  mod.method("dilate",
             [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &kernel) {
               return cv::dilate(cv::InputArray(src), cv::OutputArray(dst),
                                 cv::InputArray(kernel));
             });
  mod.method("dilate", [](const cv::Mat &src, const cv::Mat &dst,
                          const cv::Mat &kernel, cv::Point anchor) {
    return cv::dilate(cv::InputArray(src), cv::OutputArray(dst),
                      cv::InputArray(kernel), anchor);
  });
  mod.method("dilate",
             [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &kernel,
                cv::Point anchor, int iterations) {
               return cv::dilate(cv::InputArray(src), cv::OutputArray(dst),
                                 cv::InputArray(kernel), anchor, iterations);
             });
  mod.method("dilate", [](const cv::Mat &src, const cv::Mat &dst,
                          const cv::Mat &kernel, cv::Point anchor,
                          int iterations, int borderType) {
    return cv::dilate(cv::InputArray(src), cv::OutputArray(dst),
                      cv::InputArray(kernel), anchor, iterations, borderType);
  });
  mod.method("dilate",
             [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &kernel,
                cv::Point anchor, int iterations, int borderType,
                const cv::Scalar &borderValue) {
               return cv::dilate(cv::InputArray(src), cv::OutputArray(dst),
                                 cv::InputArray(kernel), anchor, iterations,
                                 borderType, borderValue);
             });
  mod.method("morphologyEx", [](const cv::Mat &src, const cv::Mat &dst, int op,
                                const cv::Mat &kernel) {
    return cv::morphologyEx(cv::InputArray(src), cv::OutputArray(dst), op,
                            cv::InputArray(kernel));
  });
  mod.method("morphologyEx", [](const cv::Mat &src, const cv::Mat &dst, int op,
                                const cv::Mat &kernel, cv::Point anchor) {
    return cv::morphologyEx(cv::InputArray(src), cv::OutputArray(dst), op,
                            cv::InputArray(kernel), anchor);
  });
  mod.method("morphologyEx", [](const cv::Mat &src, const cv::Mat &dst, int op,
                                const cv::Mat &kernel, cv::Point anchor,
                                int iterations) {
    return cv::morphologyEx(cv::InputArray(src), cv::OutputArray(dst), op,
                            cv::InputArray(kernel), anchor, iterations);
  });
  mod.method("morphologyEx", [](const cv::Mat &src, const cv::Mat &dst, int op,
                                const cv::Mat &kernel, cv::Point anchor,
                                int iterations, int borderType) {
    return cv::morphologyEx(cv::InputArray(src), cv::OutputArray(dst), op,
                            cv::InputArray(kernel), anchor, iterations,
                            borderType);
  });
  mod.method("morphologyEx", [](const cv::Mat &src, const cv::Mat &dst, int op,
                                const cv::Mat &kernel, cv::Point anchor,
                                int iterations, int borderType,
                                const cv::Scalar &borderValue) {
    return cv::morphologyEx(cv::InputArray(src), cv::OutputArray(dst), op,
                            cv::InputArray(kernel), anchor, iterations,
                            borderType, borderValue);
  });
  mod.method(
      "resize", [](const cv::Mat &src, const cv::Mat &dst, cv::Size dsize) {
        return cv::resize(cv::InputArray(src), cv::OutputArray(dst), dsize);
      });
  mod.method("resize", [](const cv::Mat &src, const cv::Mat &dst,
                          cv::Size dsize, double fx) {
    return cv::resize(cv::InputArray(src), cv::OutputArray(dst), dsize, fx);
  });
  mod.method("resize", [](const cv::Mat &src, const cv::Mat &dst,
                          cv::Size dsize, double fx, double fy) {
    return cv::resize(cv::InputArray(src), cv::OutputArray(dst), dsize, fx, fy);
  });
  mod.method("resize",
             [](const cv::Mat &src, const cv::Mat &dst, cv::Size dsize,
                double fx, double fy, int interpolation) {
               return cv::resize(cv::InputArray(src), cv::OutputArray(dst),
                                 dsize, fx, fy, interpolation);
             });
  mod.method("warpAffine", [](const cv::Mat &src, const cv::Mat &dst,
                              const cv::Mat &M, cv::Size dsize) {
    return cv::warpAffine(cv::InputArray(src), cv::OutputArray(dst),
                          cv::InputArray(M), dsize);
  });
  mod.method("warpAffine", [](const cv::Mat &src, const cv::Mat &dst,
                              const cv::Mat &M, cv::Size dsize, int flags) {
    return cv::warpAffine(cv::InputArray(src), cv::OutputArray(dst),
                          cv::InputArray(M), dsize, flags);
  });
  mod.method(
      "warpAffine", [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &M,
                       cv::Size dsize, int flags, int borderMode) {
        return cv::warpAffine(cv::InputArray(src), cv::OutputArray(dst),
                              cv::InputArray(M), dsize, flags, borderMode);
      });
  mod.method("warpAffine", [](const cv::Mat &src, const cv::Mat &dst,
                              const cv::Mat &M, cv::Size dsize, int flags,
                              int borderMode, const cv::Scalar &borderValue) {
    return cv::warpAffine(cv::InputArray(src), cv::OutputArray(dst),
                          cv::InputArray(M), dsize, flags, borderMode,
                          borderValue);
  });
  mod.method("warpPerspective", [](const cv::Mat &src, const cv::Mat &dst,
                                   const cv::Mat &M, cv::Size dsize) {
    return cv::warpPerspective(cv::InputArray(src), cv::OutputArray(dst),
                               cv::InputArray(M), dsize);
  });
  mod.method(
      "warpPerspective", [](const cv::Mat &src, const cv::Mat &dst,
                            const cv::Mat &M, cv::Size dsize, int flags) {
        return cv::warpPerspective(cv::InputArray(src), cv::OutputArray(dst),
                                   cv::InputArray(M), dsize, flags);
      });
  mod.method("warpPerspective", [](const cv::Mat &src, const cv::Mat &dst,
                                   const cv::Mat &M, cv::Size dsize, int flags,
                                   int borderMode) {
    return cv::warpPerspective(cv::InputArray(src), cv::OutputArray(dst),
                               cv::InputArray(M), dsize, flags, borderMode);
  });
  mod.method(
      "warpPerspective", [](const cv::Mat &src, const cv::Mat &dst,
                            const cv::Mat &M, cv::Size dsize, int flags,
                            int borderMode, const cv::Scalar &borderValue) {
        return cv::warpPerspective(cv::InputArray(src), cv::OutputArray(dst),
                                   cv::InputArray(M), dsize, flags, borderMode,
                                   borderValue);
      });
  mod.method("remap", [](const cv::Mat &src, const cv::Mat &dst,
                         const cv::Mat &map1, const cv::Mat &map2,
                         int interpolation) {
    return cv::remap(cv::InputArray(src), cv::OutputArray(dst),
                     cv::InputArray(map1), cv::InputArray(map2), interpolation);
  });
  mod.method("remap",
             [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &map1,
                const cv::Mat &map2, int interpolation, int borderMode) {
               return cv::remap(cv::InputArray(src), cv::OutputArray(dst),
                                cv::InputArray(map1), cv::InputArray(map2),
                                interpolation, borderMode);
             });
  mod.method("remap",
             [](const cv::Mat &src, const cv::Mat &dst, const cv::Mat &map1,
                const cv::Mat &map2, int interpolation, int borderMode,
                const cv::Scalar &borderValue) {
               return cv::remap(cv::InputArray(src), cv::OutputArray(dst),
                                cv::InputArray(map1), cv::InputArray(map2),
                                interpolation, borderMode, borderValue);
             });
  mod.method("convertMaps", [](const cv::Mat &map1, const cv::Mat &map2,
                               const cv::Mat &dstmap1, const cv::Mat &dstmap2,
                               int dstmap1type) {
    return cv::convertMaps(cv::InputArray(map1), cv::InputArray(map2),
                           cv::OutputArray(dstmap1), cv::OutputArray(dstmap2),
                           dstmap1type);
  });
  mod.method("convertMaps", [](const cv::Mat &map1, const cv::Mat &map2,
                               const cv::Mat &dstmap1, const cv::Mat &dstmap2,
                               int dstmap1type, bool nninterpolation) {
    return cv::convertMaps(cv::InputArray(map1), cv::InputArray(map2),
                           cv::OutputArray(dstmap1), cv::OutputArray(dstmap2),
                           dstmap1type, nninterpolation);
  });
  mod.method("getRotationMatrix2D",
             [](cv::Point2f center, double angle, double scale) {
               return cv::getRotationMatrix2D(center, angle, scale);
             });
  mod.method("getPerspectiveTransform",
             [](const cv::Point2f *src, const cv::Point2f *dst) {
               return cv::getPerspectiveTransform(src, dst);
             });
  mod.method("getAffineTransform",
             [](const cv::Point2f *src, const cv::Point2f *dst) {
               return cv::getAffineTransform(src, dst);
             });
  mod.method("invertAffineTransform", [](const cv::Mat &M, const cv::Mat &iM) {
    return cv::invertAffineTransform(cv::InputArray(M), cv::OutputArray(iM));
  });
  mod.method("getPerspectiveTransform",
             [](const cv::Mat &src, const cv::Mat &dst) {
               return cv::getPerspectiveTransform(cv::InputArray(src),
                                                  cv::InputArray(dst));
             });
  mod.method("getAffineTransform", [](const cv::Mat &src, const cv::Mat &dst) {
    return cv::getAffineTransform(cv::InputArray(src), cv::InputArray(dst));
  });
  mod.method("getRectSubPix", [](const cv::Mat &image, cv::Size patchSize,
                                 cv::Point2f center, const cv::Mat &patch) {
    return cv::getRectSubPix(cv::InputArray(image), patchSize, center,
                             cv::OutputArray(patch));
  });
  mod.method("getRectSubPix", [](const cv::Mat &image, cv::Size patchSize,
                                 cv::Point2f center, const cv::Mat &patch,
                                 int patchType) {
    return cv::getRectSubPix(cv::InputArray(image), patchSize, center,
                             cv::OutputArray(patch), patchType);
  });
  mod.method("logPolar", [](const cv::Mat &src, const cv::Mat &dst,
                            cv::Point2f center, double M, int flags) {
    return cv::logPolar(cv::InputArray(src), cv::OutputArray(dst), center, M,
                        flags);
  });
  mod.method("linearPolar",
             [](const cv::Mat &src, const cv::Mat &dst, cv::Point2f center,
                double maxRadius, int flags) {
               return cv::linearPolar(cv::InputArray(src), cv::OutputArray(dst),
                                      center, maxRadius, flags);
             });
  /*mod.method("warpPolar",
             [](const cv::Mat &src, const cv::Mat &dst, cv::Size dsize,
                cv::Point2f center, double maxRadius, int flags) {
               return cv::warpPolar(cv::InputArray(src), cv::OutputArray(dst),
                                    dsize, center, maxRadius, flags);
             });*/
  mod.method("integral", [](const cv::Mat &src, const cv::Mat &sum) {
    return cv::integral(cv::InputArray(src), cv::OutputArray(sum));
  });
  mod.method(
      "integral", [](const cv::Mat &src, const cv::Mat &sum, int sdepth) {
        return cv::integral(cv::InputArray(src), cv::OutputArray(sum), sdepth);
      });
  mod.method("integral",
             [](const cv::Mat &src, const cv::Mat &sum, const cv::Mat &sqsum) {
               return cv::integral(cv::InputArray(src), cv::OutputArray(sum),
                                   cv::OutputArray(sqsum));
             });
  mod.method("integral", [](const cv::Mat &src, const cv::Mat &sum,
                            const cv::Mat &sqsum, int sdepth) {
    return cv::integral(cv::InputArray(src), cv::OutputArray(sum),
                        cv::OutputArray(sqsum), sdepth);
  });
  mod.method("integral", [](const cv::Mat &src, const cv::Mat &sum,
                            const cv::Mat &sqsum, int sdepth, int sqdepth) {
    return cv::integral(cv::InputArray(src), cv::OutputArray(sum),
                        cv::OutputArray(sqsum), sdepth, sqdepth);
  });
  mod.method("integral", [](const cv::Mat &src, const cv::Mat &sum,
                            const cv::Mat &sqsum, const cv::Mat &tilted) {
    return cv::integral(cv::InputArray(src), cv::OutputArray(sum),
                        cv::OutputArray(sqsum), cv::OutputArray(tilted));
  });
  mod.method("integral",
             [](const cv::Mat &src, const cv::Mat &sum, const cv::Mat &sqsum,
                const cv::Mat &tilted, int sdepth) {
               return cv::integral(cv::InputArray(src), cv::OutputArray(sum),
                                   cv::OutputArray(sqsum),
                                   cv::OutputArray(tilted), sdepth);
             });
  mod.method("integral",
             [](const cv::Mat &src, const cv::Mat &sum, const cv::Mat &sqsum,
                const cv::Mat &tilted, int sdepth, int sqdepth) {
               return cv::integral(cv::InputArray(src), cv::OutputArray(sum),
                                   cv::OutputArray(sqsum),
                                   cv::OutputArray(tilted), sdepth, sqdepth);
             });
  mod.method("accumulate", [](const cv::Mat &src, const cv::Mat &dst,
                              const cv::Mat &mask) {
    return cv::accumulate(cv::InputArray(src), cv::InputOutputArray(dst),
                          cv::InputArray(mask));
  });
  mod.method("accumulateSquare", [](const cv::Mat &src, const cv::Mat &dst,
                                    const cv::Mat &mask) {
    return cv::accumulateSquare(cv::InputArray(src), cv::InputOutputArray(dst),
                                cv::InputArray(mask));
  });
  mod.method("accumulateProduct", [](const cv::Mat &src1, const cv::Mat &src2,
                                     const cv::Mat &dst, const cv::Mat &mask) {
    return cv::accumulateProduct(cv::InputArray(src1), cv::InputArray(src2),
                                 cv::InputOutputArray(dst),
                                 cv::InputArray(mask));
  });
  mod.method("accumulateWeighted", [](const cv::Mat &src, const cv::Mat &dst,
                                      double alpha, const cv::Mat &mask) {
    return cv::accumulateWeighted(cv::InputArray(src),
                                  cv::InputOutputArray(dst), alpha,
                                  cv::InputArray(mask));
  });
  mod.method("phaseCorrelate", [](const cv::Mat &src1, const cv::Mat &src2,
                                  const cv::Mat &window) {
    return cv::phaseCorrelate(cv::InputArray(src1), cv::InputArray(src2),
                              cv::InputArray(window));
  });
  mod.method("phaseCorrelate", [](const cv::Mat &src1, const cv::Mat &src2,
                                  const cv::Mat &window, double *response) {
    return cv::phaseCorrelate(cv::InputArray(src1), cv::InputArray(src2),
                              cv::InputArray(window), response);
  });
  mod.method("createHanningWindow", [](const cv::Mat &dst, cv::Size winSize,
                                       int type) {
    return cv::createHanningWindow(cv::OutputArray(dst), winSize, type);
  });
  mod.method("threshold", [](const cv::Mat &src, const cv::Mat &dst,
                             double thresh, double maxval, int type) {
    return cv::threshold(cv::InputArray(src), cv::OutputArray(dst), thresh,
                         maxval, type);
  });
  mod.method(
      "adaptiveThreshold",
      [](const cv::Mat &src, const cv::Mat &dst, double maxValue,
         int adaptiveMethod, int thresholdType, int blockSize, double C) {
        return cv::adaptiveThreshold(cv::InputArray(src), cv::OutputArray(dst),
                                     maxValue, adaptiveMethod, thresholdType,
                                     blockSize, C);
      });
  mod.method("pyrDown", [](const cv::Mat &src, const cv::Mat &dst) {
    return cv::pyrDown(cv::InputArray(src), cv::OutputArray(dst));
  });
  mod.method("pyrDown", [](const cv::Mat &src, const cv::Mat &dst,
                           const cv::Size &dstsize) {
    return cv::pyrDown(cv::InputArray(src), cv::OutputArray(dst), dstsize);
  });
  mod.method("pyrDown", [](const cv::Mat &src, const cv::Mat &dst,
                           const cv::Size &dstsize, int borderType) {
    return cv::pyrDown(cv::InputArray(src), cv::OutputArray(dst), dstsize,
                       borderType);
  });
  mod.method("pyrUp", [](const cv::Mat &src, const cv::Mat &dst) {
    return cv::pyrUp(cv::InputArray(src), cv::OutputArray(dst));
  });
  mod.method("pyrUp", [](const cv::Mat &src, const cv::Mat &dst,
                         const cv::Size &dstsize) {
    return cv::pyrUp(cv::InputArray(src), cv::OutputArray(dst), dstsize);
  });
  mod.method("pyrUp", [](const cv::Mat &src, const cv::Mat &dst,
                         const cv::Size &dstsize, int borderType) {
    return cv::pyrUp(cv::InputArray(src), cv::OutputArray(dst), dstsize,
                     borderType);
  });
  mod.method("buildPyramid", [](const cv::Mat &src,
                                const std::vector<cv::Mat> &dst, int maxlevel) {
    return cv::buildPyramid(cv::InputArray(src), cv::OutputArrayOfArrays(dst),
                            maxlevel);
  });
  mod.method("buildPyramid", [](const cv::Mat &src,
                                const std::vector<cv::Mat> &dst, int maxlevel,
                                int borderType) {
    return cv::buildPyramid(cv::InputArray(src), cv::OutputArrayOfArrays(dst),
                            maxlevel, borderType);
  });
  mod.method("undistort", [](const cv::Mat &src, const cv::Mat &dst,
                             const cv::Mat &cameraMatrix,
                             const cv::Mat &distCoeffs,
                             const cv::Mat &newCameraMatrix) {
    return cv::undistort(
        cv::InputArray(src), cv::OutputArray(dst), cv::InputArray(cameraMatrix),
        cv::InputArray(distCoeffs), cv::InputArray(newCameraMatrix));
  });
  mod.method("initUndistortRectifyMap",
             [](const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                const cv::Mat &R, const cv::Mat &newCameraMatrix, cv::Size size,
                int m1type, const cv::Mat &map1, const cv::Mat &map2) {
               return cv::initUndistortRectifyMap(
                   cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
                   cv::InputArray(R), cv::InputArray(newCameraMatrix), size,
                   m1type, cv::OutputArray(map1), cv::OutputArray(map2));
             });
  mod.method("initWideAngleProjMap",
             [](const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                cv::Size imageSize, int destImageWidth, int m1type,
                const cv::Mat &map1, const cv::Mat &map2) {
               return cv::initWideAngleProjMap(
                   cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
                   imageSize, destImageWidth, m1type, cv::OutputArray(map1),
                   cv::OutputArray(map2));
             });
  mod.method("initWideAngleProjMap",
             [](const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                cv::Size imageSize, int destImageWidth, int m1type,
                const cv::Mat &map1, const cv::Mat &map2, int projType) {
               return cv::initWideAngleProjMap(
                   cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
                   imageSize, destImageWidth, m1type, cv::OutputArray(map1),
                   cv::OutputArray(map2), projType);
             });
  mod.method(
      "initWideAngleProjMap",
      [](const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
         cv::Size imageSize, int destImageWidth, int m1type,
         const cv::Mat &map1, const cv::Mat &map2, int projType, double alpha) {
        return cv::initWideAngleProjMap(
            cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs), imageSize,
            destImageWidth, m1type, cv::OutputArray(map1),
            cv::OutputArray(map2), projType, alpha);
      });
  mod.method("getDefaultNewCameraMatrix", [](const cv::Mat &cameraMatrix) {
    return cv::getDefaultNewCameraMatrix(cv::InputArray(cameraMatrix));
  });
  mod.method("getDefaultNewCameraMatrix", [](const cv::Mat &cameraMatrix,
                                             cv::Size imgsize) {
    return cv::getDefaultNewCameraMatrix(cv::InputArray(cameraMatrix), imgsize);
  });
  mod.method("getDefaultNewCameraMatrix",
             [](const cv::Mat &cameraMatrix, cv::Size imgsize,
                bool centerPrincipalPoint) {
               return cv::getDefaultNewCameraMatrix(
                   cv::InputArray(cameraMatrix), imgsize, centerPrincipalPoint);
             });
  mod.method("undistortPoints", [](const cv::Mat &src, const cv::Mat &dst,
                                   const cv::Mat &cameraMatrix,
                                   const cv::Mat &distCoeffs, const cv::Mat &R,
                                   const cv::Mat &P) {
    return cv::undistortPoints(
        cv::InputArray(src), cv::OutputArray(dst), cv::InputArray(cameraMatrix),
        cv::InputArray(distCoeffs), cv::InputArray(R), cv::InputArray(P));
  });
  mod.method("undistortPoints",
             [](const cv::Mat &src, const cv::Mat &dst,
                const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                const cv::Mat &R, const cv::Mat &P, cv::TermCriteria criteria) {
               return cv::undistortPoints(
                   cv::InputArray(src), cv::OutputArray(dst),
                   cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
                   cv::InputArray(R), cv::InputArray(P), criteria);
             });
  mod.method(
      "calcHist",
      [](const std::vector<cv::Mat> &images, const std::vector<int> &channels,
         const cv::Mat &mask, const cv::Mat &hist,
         const std::vector<int> &histSize, const std::vector<float> &ranges) {
        return cv::calcHist(cv::InputArrayOfArrays(images), channels,
                            cv::InputArray(mask), cv::OutputArray(hist),
                            histSize, ranges);
      });
  mod.method("calcHist",
             [](const std::vector<cv::Mat> &images,
                const std::vector<int> &channels, const cv::Mat &mask,
                const cv::Mat &hist, const std::vector<int> &histSize,
                const std::vector<float> &ranges, bool accumulate) {
               return cv::calcHist(cv::InputArrayOfArrays(images), channels,
                                   cv::InputArray(mask), cv::OutputArray(hist),
                                   histSize, ranges, accumulate);
             });
  mod.method(
      "calcBackProject",
      [](const std::vector<cv::Mat> &images, const std::vector<int> &channels,
         const cv::Mat &hist, const cv::Mat &dst,
         const std::vector<float> &ranges, double scale) {
        return cv::calcBackProject(cv::InputArrayOfArrays(images), channels,
                                   cv::InputArray(hist), cv::OutputArray(dst),
                                   ranges, scale);
      });
  mod.method(
      "compareHist", [](const cv::Mat &H1, const cv::Mat &H2, int method) {
        return cv::compareHist(cv::InputArray(H1), cv::InputArray(H2), method);
      });
  mod.method("compareHist",
             [](const cv::SparseMat &H1, const cv::SparseMat &H2, int method) {
               return cv::compareHist(H1, H2, method);
             });
  mod.method("equalizeHist", [](const cv::Mat &src, const cv::Mat &dst) {
    return cv::equalizeHist(cv::InputArray(src), cv::OutputArray(dst));
  });
  mod.method("EMD", [](const cv::Mat &signature1, const cv::Mat &signature2,
                       int distType, const cv::Mat &cost, float *lowerBound,
                       const cv::Mat &flow) {
    return cv::EMD(cv::InputArray(signature1), cv::InputArray(signature2),
                   distType, cv::InputArray(cost), lowerBound,
                   cv::OutputArray(flow));
  });
  mod.method("wrapperEMD",
             [](const cv::Mat &signature1, const cv::Mat &signature2,
                int distType, const cv::Mat &cost) {
               return cv::wrapperEMD(cv::InputArray(signature1),
                                     cv::InputArray(signature2), distType,
                                     cv::InputArray(cost));
             });
  mod.method("wrapperEMD",
             [](const cv::Mat &signature1, const cv::Mat &signature2,
                int distType, const cv::Mat &cost, cv::Ptr<float> lowerBound) {
               return cv::wrapperEMD(cv::InputArray(signature1),
                                     cv::InputArray(signature2), distType,
                                     cv::InputArray(cost), lowerBound);
             });
  mod.method(
      "wrapperEMD",
      [](const cv::Mat &signature1, const cv::Mat &signature2, int distType,
         const cv::Mat &cost, cv::Ptr<float> lowerBound, const cv::Mat &flow) {
        return cv::wrapperEMD(
            cv::InputArray(signature1), cv::InputArray(signature2), distType,
            cv::InputArray(cost), lowerBound, cv::OutputArray(flow));
      });
  mod.method("watershed", [](const cv::Mat &image, const cv::Mat &markers) {
    return cv::watershed(cv::InputArray(image), cv::InputOutputArray(markers));
  });
  mod.method("pyrMeanShiftFiltering",
             [](const cv::Mat &src, const cv::Mat &dst, double sp, double sr) {
               return cv::pyrMeanShiftFiltering(cv::InputArray(src),
                                                cv::OutputArray(dst), sp, sr);
             });
  mod.method("pyrMeanShiftFiltering", [](const cv::Mat &src, const cv::Mat &dst,
                                         double sp, double sr, int maxLevel) {
    return cv::pyrMeanShiftFiltering(cv::InputArray(src), cv::OutputArray(dst),
                                     sp, sr, maxLevel);
  });
  mod.method("pyrMeanShiftFiltering", [](const cv::Mat &src, const cv::Mat &dst,
                                         double sp, double sr, int maxLevel,
                                         cv::TermCriteria termcrit) {
    return cv::pyrMeanShiftFiltering(cv::InputArray(src), cv::OutputArray(dst),
                                     sp, sr, maxLevel, termcrit);
  });
  mod.method("grabCut", [](const cv::Mat &img, const cv::Mat &mask,
                           cv::Rect rect, const cv::Mat &bgdModel,
                           const cv::Mat &fgdModel, int iterCount) {
    return cv::grabCut(cv::InputArray(img), cv::InputOutputArray(mask), rect,
                       cv::InputOutputArray(bgdModel),
                       cv::InputOutputArray(fgdModel), iterCount);
  });
  mod.method("grabCut", [](const cv::Mat &img, const cv::Mat &mask,
                           cv::Rect rect, const cv::Mat &bgdModel,
                           const cv::Mat &fgdModel, int iterCount, int mode) {
    return cv::grabCut(cv::InputArray(img), cv::InputOutputArray(mask), rect,
                       cv::InputOutputArray(bgdModel),
                       cv::InputOutputArray(fgdModel), iterCount, mode);
  });
  mod.method("distanceTransform", [](const cv::Mat &src, const cv::Mat &dst,
                                     const cv::Mat &labels, int distanceType,
                                     int maskSize) {
    return cv::distanceTransform(cv::InputArray(src), cv::OutputArray(dst),
                                 cv::OutputArray(labels), distanceType,
                                 maskSize);
  });
  mod.method("distanceTransform", [](const cv::Mat &src, const cv::Mat &dst,
                                     const cv::Mat &labels, int distanceType,
                                     int maskSize, int labelType) {
    return cv::distanceTransform(cv::InputArray(src), cv::OutputArray(dst),
                                 cv::OutputArray(labels), distanceType,
                                 maskSize, labelType);
  });
  mod.method("distanceTransform", [](const cv::Mat &src, const cv::Mat &dst,
                                     int distanceType, int maskSize) {
    return cv::distanceTransform(cv::InputArray(src), cv::OutputArray(dst),
                                 distanceType, maskSize);
  });
  mod.method(
      "distanceTransform", [](const cv::Mat &src, const cv::Mat &dst,
                              int distanceType, int maskSize, int dstType) {
        return cv::distanceTransform(cv::InputArray(src), cv::OutputArray(dst),
                                     distanceType, maskSize, dstType);
      });
  mod.method("floodFill", [](const cv::Mat &image, cv::Point seedPoint,
                             cv::Scalar newVal) {
    return cv::floodFill(cv::InputOutputArray(image), seedPoint, newVal);
  });
  mod.method("floodFill", [](const cv::Mat &image, cv::Point seedPoint,
                             cv::Scalar newVal, cv::Rect *rect) {
    return cv::floodFill(cv::InputOutputArray(image), seedPoint, newVal, rect);
  });
  mod.method("floodFill",
             [](const cv::Mat &image, cv::Point seedPoint, cv::Scalar newVal,
                cv::Rect *rect, cv::Scalar loDiff) {
               return cv::floodFill(cv::InputOutputArray(image), seedPoint,
                                    newVal, rect, loDiff);
             });
  mod.method("floodFill",
             [](const cv::Mat &image, cv::Point seedPoint, cv::Scalar newVal,
                cv::Rect *rect, cv::Scalar loDiff, cv::Scalar upDiff) {
               return cv::floodFill(cv::InputOutputArray(image), seedPoint,
                                    newVal, rect, loDiff, upDiff);
             });
  mod.method("floodFill", [](const cv::Mat &image, cv::Point seedPoint,
                             cv::Scalar newVal, cv::Rect *rect,
                             cv::Scalar loDiff, cv::Scalar upDiff, int flags) {
    return cv::floodFill(cv::InputOutputArray(image), seedPoint, newVal, rect,
                         loDiff, upDiff, flags);
  });
  mod.method("floodFill", [](const cv::Mat &image, const cv::Mat &mask,
                             cv::Point seedPoint, cv::Scalar newVal) {
    return cv::floodFill(cv::InputOutputArray(image),
                         cv::InputOutputArray(mask), seedPoint, newVal);
  });
  mod.method("floodFill", [](const cv::Mat &image, const cv::Mat &mask,
                             cv::Point seedPoint, cv::Scalar newVal,
                             cv::Rect *rect) {
    return cv::floodFill(cv::InputOutputArray(image),
                         cv::InputOutputArray(mask), seedPoint, newVal, rect);
  });
  mod.method("floodFill",
             [](const cv::Mat &image, const cv::Mat &mask, cv::Point seedPoint,
                cv::Scalar newVal, cv::Rect *rect, cv::Scalar loDiff) {
               return cv::floodFill(cv::InputOutputArray(image),
                                    cv::InputOutputArray(mask), seedPoint,
                                    newVal, rect, loDiff);
             });
  mod.method("floodFill",
             [](const cv::Mat &image, const cv::Mat &mask, cv::Point seedPoint,
                cv::Scalar newVal, cv::Rect *rect, cv::Scalar loDiff,
                cv::Scalar upDiff) {
               return cv::floodFill(cv::InputOutputArray(image),
                                    cv::InputOutputArray(mask), seedPoint,
                                    newVal, rect, loDiff, upDiff);
             });
  mod.method("floodFill",
             [](const cv::Mat &image, const cv::Mat &mask, cv::Point seedPoint,
                cv::Scalar newVal, cv::Rect *rect, cv::Scalar loDiff,
                cv::Scalar upDiff, int flags) {
               return cv::floodFill(cv::InputOutputArray(image),
                                    cv::InputOutputArray(mask), seedPoint,
                                    newVal, rect, loDiff, upDiff, flags);
             });
  mod.method("cvtColor", [](const cv::Mat &src, const cv::Mat &dst, int code) {
    return cv::cvtColor(cv::InputArray(src), cv::OutputArray(dst), code);
  });
  mod.method("cvtColor", [](const cv::Mat &src, const cv::Mat &dst, int code,
                            int dstCn) {
    return cv::cvtColor(cv::InputArray(src), cv::OutputArray(dst), code, dstCn);
  });
  mod.method("cvtColorTwoPlane", [](const cv::Mat &src1, const cv::Mat &src2,
                                    const cv::Mat &dst, int code) {
    return cv::cvtColorTwoPlane(cv::InputArray(src1), cv::InputArray(src2),
                                cv::OutputArray(dst), code);
  });
  mod.method("demosaicing", [](const cv::Mat &_src, const cv::Mat &_dst,
                               int code) {
    return cv::demosaicing(cv::InputArray(_src), cv::OutputArray(_dst), code);
  });
  mod.method("demosaicing",
             [](const cv::Mat &_src, const cv::Mat &_dst, int code, int dcn) {
               return cv::demosaicing(cv::InputArray(_src),
                                      cv::OutputArray(_dst), code, dcn);
             });
  mod.method("moments", [](const cv::Mat &array) {
    return cv::moments(cv::InputArray(array));
  });
  mod.method("moments", [](const cv::Mat &array, bool binaryImage) {
    return cv::moments(cv::InputArray(array), binaryImage);
  });
  mod.method("HuMoments", [](const cv::Moments &moments, double *hu) {
    return cv::HuMoments(moments, hu);
  });
  mod.method("HuMoments", [](const cv::Moments &m, const cv::Mat &hu) {
    return cv::HuMoments(m, cv::OutputArray(hu));
  });
  mod.add_bits<cv::TemplateMatchModes>("TemplateMatchModes");
  mod.set_const("TM_SQDIFF", cv::TemplateMatchModes::TM_SQDIFF);
  mod.set_const("TM_SQDIFF_NORMED", cv::TemplateMatchModes::TM_SQDIFF_NORMED);
  mod.set_const("TM_CCORR", cv::TemplateMatchModes::TM_CCORR);
  mod.set_const("TM_CCORR_NORMED", cv::TemplateMatchModes::TM_CCORR_NORMED);
  mod.set_const("TM_CCOEFF", cv::TemplateMatchModes::TM_CCOEFF);
  mod.set_const("TM_CCOEFF_NORMED", cv::TemplateMatchModes::TM_CCOEFF_NORMED);
  mod.method("matchTemplate", [](const cv::Mat &image, const cv::Mat &templ,
                                 const cv::Mat &result, int method,
                                 const cv::Mat &mask) {
    return cv::matchTemplate(cv::InputArray(image), cv::InputArray(templ),
                             cv::OutputArray(result), method,
                             cv::InputArray(mask));
  });
  mod.method("connectedComponents",
             [](const cv::Mat &image, const cv::Mat &labels, int connectivity,
                int ltype, int ccltype) {
               return cv::connectedComponents(cv::InputArray(image),
                                              cv::OutputArray(labels),
                                              connectivity, ltype, ccltype);
             });
  mod.method("connectedComponents",
             [](const cv::Mat &image, const cv::Mat &labels) {
               return cv::connectedComponents(cv::InputArray(image),
                                              cv::OutputArray(labels));
             });
  mod.method("connectedComponents",
             [](const cv::Mat &image, const cv::Mat &labels, int connectivity) {
               return cv::connectedComponents(cv::InputArray(image),
                                              cv::OutputArray(labels),
                                              connectivity);
             });
  mod.method("connectedComponents", [](const cv::Mat &image,
                                       const cv::Mat &labels, int connectivity,
                                       int ltype) {
    return cv::connectedComponents(
        cv::InputArray(image), cv::OutputArray(labels), connectivity, ltype);
  });
  mod.method(
      "connectedComponentsWithStats",
      [](const cv::Mat &image, const cv::Mat &labels, const cv::Mat &stats,
         const cv::Mat &centroids, int connectivity, int ltype, int ccltype) {
        return cv::connectedComponentsWithStats(
            cv::InputArray(image), cv::OutputArray(labels),
            cv::OutputArray(stats), cv::OutputArray(centroids), connectivity,
            ltype, ccltype);
      });
  mod.method("connectedComponentsWithStats",
             [](const cv::Mat &image, const cv::Mat &labels,
                const cv::Mat &stats, const cv::Mat &centroids) {
               return cv::connectedComponentsWithStats(
                   cv::InputArray(image), cv::OutputArray(labels),
                   cv::OutputArray(stats), cv::OutputArray(centroids));
             });
  mod.method(
      "connectedComponentsWithStats",
      [](const cv::Mat &image, const cv::Mat &labels, const cv::Mat &stats,
         const cv::Mat &centroids, int connectivity) {
        return cv::connectedComponentsWithStats(
            cv::InputArray(image), cv::OutputArray(labels),
            cv::OutputArray(stats), cv::OutputArray(centroids), connectivity);
      });
  mod.method(
      "connectedComponentsWithStats",
      [](const cv::Mat &image, const cv::Mat &labels, const cv::Mat &stats,
         const cv::Mat &centroids, int connectivity, int ltype) {
        return cv::connectedComponentsWithStats(
            cv::InputArray(image), cv::OutputArray(labels),
            cv::OutputArray(stats), cv::OutputArray(centroids), connectivity,
            ltype);
      });
  mod.method("findContours",
             [](const cv::Mat &image, const std::vector<cv::Mat> &contours,
                const cv::Mat &hierarchy, int mode, int method) {
               return cv::findContours(cv::InputOutputArray(image),
                                       cv::OutputArrayOfArrays(contours),
                                       cv::OutputArray(hierarchy), mode,
                                       method);
             });
  mod.method("findContours", [](const cv::Mat &image,
                                const std::vector<cv::Mat> &contours,
                                const cv::Mat &hierarchy, int mode, int method,
                                cv::Point offset) {
    return cv::findContours(cv::InputOutputArray(image),
                            cv::OutputArrayOfArrays(contours),
                            cv::OutputArray(hierarchy), mode, method, offset);
  });
  mod.method("findContours", [](const cv::Mat &image,
                                const std::vector<cv::Mat> &contours, int mode,
                                int method) {
    return cv::findContours(cv::InputOutputArray(image),
                            cv::OutputArrayOfArrays(contours), mode, method);
  });
  mod.method("findContours",
             [](const cv::Mat &image, const std::vector<cv::Mat> &contours,
                int mode, int method, cv::Point offset) {
               return cv::findContours(cv::InputOutputArray(image),
                                       cv::OutputArrayOfArrays(contours), mode,
                                       method, offset);
             });
  mod.method(
      "approxPolyDP", [](const cv::Mat &curve, const cv::Mat &approxCurve,
                         double epsilon, bool closed) {
        return cv::approxPolyDP(cv::InputArray(curve),
                                cv::OutputArray(approxCurve), epsilon, closed);
      });
  mod.method("arcLength", [](const cv::Mat &curve, bool closed) {
    return cv::arcLength(cv::InputArray(curve), closed);
  });
  mod.method("boundingRect", [](const cv::Mat &points) {
    return cv::boundingRect(cv::InputArray(points));
  });
  mod.method("contourArea", [](const cv::Mat &contour) {
    return cv::contourArea(cv::InputArray(contour));
  });
  mod.method("contourArea", [](const cv::Mat &contour, bool oriented) {
    return cv::contourArea(cv::InputArray(contour), oriented);
  });
  mod.method("minAreaRect", [](const cv::Mat &points) {
    return cv::minAreaRect(cv::InputArray(points));
  });
  mod.method("boxPoints", [](cv::RotatedRect box, const cv::Mat &points) {
    return cv::boxPoints(box, cv::OutputArray(points));
  });
  mod.method("minEnclosingCircle", [](const cv::Mat &points,
                                      cv::Point2f &center, float &radius) {
    return cv::minEnclosingCircle(cv::InputArray(points), center, radius);
  });
  mod.method("minEnclosingTriangle",
             [](const cv::Mat &points, const cv::Mat &triangle) {
               return cv::minEnclosingTriangle(cv::InputArray(points),
                                               cv::OutputArray(triangle));
             });
  mod.method("matchShapes", [](const cv::Mat &contour1, const cv::Mat &contour2,
                               int method, double parameter) {
    return cv::matchShapes(cv::InputArray(contour1), cv::InputArray(contour2),
                           method, parameter);
  });
  mod.method("convexHull", [](const cv::Mat &points, const cv::Mat &hull) {
    return cv::convexHull(cv::InputArray(points), cv::OutputArray(hull));
  });
  mod.method("convexHull",
             [](const cv::Mat &points, const cv::Mat &hull, bool clockwise) {
               return cv::convexHull(cv::InputArray(points),
                                     cv::OutputArray(hull), clockwise);
             });
  mod.method("convexHull", [](const cv::Mat &points, const cv::Mat &hull,
                              bool clockwise, bool returnPoints) {
    return cv::convexHull(cv::InputArray(points), cv::OutputArray(hull),
                          clockwise, returnPoints);
  });
  mod.method("convexityDefects",
             [](const cv::Mat &contour, const cv::Mat &convexhull,
                const cv::Mat &convexityDefects) {
               return cv::convexityDefects(cv::InputArray(contour),
                                           cv::InputArray(convexhull),
                                           cv::OutputArray(convexityDefects));
             });
  mod.method("isContourConvex", [](const cv::Mat &contour) {
    return cv::isContourConvex(cv::InputArray(contour));
  });
  mod.method("intersectConvexConvex", [](const cv::Mat &_p1, const cv::Mat &_p2,
                                         const cv::Mat &_p12) {
    return cv::intersectConvexConvex(cv::InputArray(_p1), cv::InputArray(_p2),
                                     cv::OutputArray(_p12));
  });
  mod.method("intersectConvexConvex", [](const cv::Mat &_p1, const cv::Mat &_p2,
                                         const cv::Mat &_p12,
                                         bool handleNested) {
    return cv::intersectConvexConvex(cv::InputArray(_p1), cv::InputArray(_p2),
                                     cv::OutputArray(_p12), handleNested);
  });
  mod.method("fitEllipse", [](const cv::Mat &points) {
    return cv::fitEllipse(cv::InputArray(points));
  });
  mod.method("fitEllipseAMS", [](const cv::Mat &points) {
    return cv::fitEllipseAMS(cv::InputArray(points));
  });
  mod.method("fitEllipseDirect", [](const cv::Mat &points) {
    return cv::fitEllipseDirect(cv::InputArray(points));
  });
  mod.method("fitLine",
             [](const cv::Mat &points, const cv::Mat &line, int distType,
                double param, double reps, double aeps) {
               return cv::fitLine(cv::InputArray(points), cv::OutputArray(line),
                                  distType, param, reps, aeps);
             });
  mod.method("pointPolygonTest", [](const cv::Mat &contour, cv::Point2f pt,
                                    bool measureDist) {
    return cv::pointPolygonTest(cv::InputArray(contour), pt, measureDist);
  });
  mod.method("rotatedRectangleIntersection",
             [](const cv::RotatedRect &rect1, const cv::RotatedRect &rect2,
                const cv::Mat &intersectingRegion) {
               return cv::rotatedRectangleIntersection(
                   rect1, rect2, cv::OutputArray(intersectingRegion));
             });
  mod.method("createCLAHE", []() { return cv::createCLAHE(); });
  mod.method("createCLAHE",
             [](double clipLimit) { return cv::createCLAHE(clipLimit); });
  mod.method("createCLAHE", [](double clipLimit, cv::Size tileGridSize) {
    return cv::createCLAHE(clipLimit, tileGridSize);
  });
  mod.method("createGeneralizedHoughBallard",
             []() { return cv::createGeneralizedHoughBallard(); });
  mod.method("createGeneralizedHoughGuil",
             []() { return cv::createGeneralizedHoughGuil(); });
  mod.method("blendLinear", [](const cv::Mat &src1, const cv::Mat &src2,
                               const cv::Mat &weights1, const cv::Mat &weights2,
                               const cv::Mat &dst) {
    return cv::blendLinear(cv::InputArray(src1), cv::InputArray(src2),
                           cv::InputArray(weights1), cv::InputArray(weights2),
                           cv::OutputArray(dst));
  });
  mod.add_bits<cv::ColormapTypes>("ColormapTypes");
  mod.set_const("COLORMAP_AUTUMN", cv::ColormapTypes::COLORMAP_AUTUMN);
  mod.set_const("COLORMAP_BONE", cv::ColormapTypes::COLORMAP_BONE);
  mod.set_const("COLORMAP_JET", cv::ColormapTypes::COLORMAP_JET);
  mod.set_const("COLORMAP_WINTER", cv::ColormapTypes::COLORMAP_WINTER);
  mod.set_const("COLORMAP_RAINBOW", cv::ColormapTypes::COLORMAP_RAINBOW);
  mod.set_const("COLORMAP_OCEAN", cv::ColormapTypes::COLORMAP_OCEAN);
  mod.set_const("COLORMAP_SUMMER", cv::ColormapTypes::COLORMAP_SUMMER);
  mod.set_const("COLORMAP_SPRING", cv::ColormapTypes::COLORMAP_SPRING);
  mod.set_const("COLORMAP_COOL", cv::ColormapTypes::COLORMAP_COOL);
  mod.set_const("COLORMAP_HSV", cv::ColormapTypes::COLORMAP_HSV);
  mod.set_const("COLORMAP_PINK", cv::ColormapTypes::COLORMAP_PINK);
  mod.set_const("COLORMAP_HOT", cv::ColormapTypes::COLORMAP_HOT);
  mod.set_const("COLORMAP_PARULA", cv::ColormapTypes::COLORMAP_PARULA);
  mod.method("applyColorMap",
             [](const cv::Mat &src, const cv::Mat &dst, int colormap) {
               return cv::applyColorMap(cv::InputArray(src),
                                        cv::OutputArray(dst), colormap);
             });
  mod.method("applyColorMap", [](const cv::Mat &src, const cv::Mat &dst,
                                 const cv::Mat &userColor) {
    return cv::applyColorMap(cv::InputArray(src), cv::OutputArray(dst),
                             cv::InputArray(userColor));
  });
  mod.method("line", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                        const cv::Scalar &color) {
    return cv::line(cv::InputOutputArray(img), pt1, pt2, color);
  });
  mod.method("line", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                        const cv::Scalar &color, int thickness) {
    return cv::line(cv::InputOutputArray(img), pt1, pt2, color, thickness);
  });
  mod.method("line", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                        const cv::Scalar &color, int thickness, int lineType) {
    return cv::line(cv::InputOutputArray(img), pt1, pt2, color, thickness,
                    lineType);
  });
  mod.method("line", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                        const cv::Scalar &color, int thickness, int lineType,
                        int shift) {
    return cv::line(cv::InputOutputArray(img), pt1, pt2, color, thickness,
                    lineType, shift);
  });
  mod.method("arrowedLine", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                               const cv::Scalar &color) {
    return cv::arrowedLine(cv::InputOutputArray(img), pt1, pt2, color);
  });
  mod.method("arrowedLine", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                               const cv::Scalar &color, int thickness) {
    return cv::arrowedLine(cv::InputOutputArray(img), pt1, pt2, color,
                           thickness);
  });
  mod.method("arrowedLine",
             [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                const cv::Scalar &color, int thickness, int line_type) {
               return cv::arrowedLine(cv::InputOutputArray(img), pt1, pt2,
                                      color, thickness, line_type);
             });
  mod.method("arrowedLine", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                               const cv::Scalar &color, int thickness,
                               int line_type, int shift) {
    return cv::arrowedLine(cv::InputOutputArray(img), pt1, pt2, color,
                           thickness, line_type, shift);
  });
  mod.method("arrowedLine", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                               const cv::Scalar &color, int thickness,
                               int line_type, int shift, double tipLength) {
    return cv::arrowedLine(cv::InputOutputArray(img), pt1, pt2, color,
                           thickness, line_type, shift, tipLength);
  });
  mod.method("rectangle", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                             const cv::Scalar &color) {
    return cv::rectangle(cv::InputOutputArray(img), pt1, pt2, color);
  });
  mod.method("rectangle", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                             const cv::Scalar &color, int thickness) {
    return cv::rectangle(cv::InputOutputArray(img), pt1, pt2, color, thickness);
  });
  mod.method("rectangle",
             [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                const cv::Scalar &color, int thickness, int lineType) {
               return cv::rectangle(cv::InputOutputArray(img), pt1, pt2, color,
                                    thickness, lineType);
             });
  mod.method("rectangle", [](const cv::Mat &img, cv::Point pt1, cv::Point pt2,
                             const cv::Scalar &color, int thickness,
                             int lineType, int shift) {
    return cv::rectangle(cv::InputOutputArray(img), pt1, pt2, color, thickness,
                         lineType, shift);
  });
  mod.method("circle", [](const cv::Mat &img, cv::Point center, int radius,
                          const cv::Scalar &color) {
    return cv::circle(cv::InputOutputArray(img), center, radius, color);
  });
  mod.method("circle", [](const cv::Mat &img, cv::Point center, int radius,
                          const cv::Scalar &color, int thickness) {
    return cv::circle(cv::InputOutputArray(img), center, radius, color,
                      thickness);
  });
  mod.method("circle",
             [](const cv::Mat &img, cv::Point center, int radius,
                const cv::Scalar &color, int thickness, int lineType) {
               return cv::circle(cv::InputOutputArray(img), center, radius,
                                 color, thickness, lineType);
             });
  mod.method("circle", [](const cv::Mat &img, cv::Point center, int radius,
                          const cv::Scalar &color, int thickness, int lineType,
                          int shift) {
    return cv::circle(cv::InputOutputArray(img), center, radius, color,
                      thickness, lineType, shift);
  });
  mod.method("ellipse", [](const cv::Mat &img, cv::Point center, cv::Size axes,
                           double angle, double startAngle, double endAngle,
                           const cv::Scalar &color) {
    return cv::ellipse(cv::InputOutputArray(img), center, axes, angle,
                       startAngle, endAngle, color);
  });
  mod.method("ellipse", [](const cv::Mat &img, cv::Point center, cv::Size axes,
                           double angle, double startAngle, double endAngle,
                           const cv::Scalar &color, int thickness) {
    return cv::ellipse(cv::InputOutputArray(img), center, axes, angle,
                       startAngle, endAngle, color, thickness);
  });
  mod.method(
      "ellipse", [](const cv::Mat &img, cv::Point center, cv::Size axes,
                    double angle, double startAngle, double endAngle,
                    const cv::Scalar &color, int thickness, int lineType) {
        return cv::ellipse(cv::InputOutputArray(img), center, axes, angle,
                           startAngle, endAngle, color, thickness, lineType);
      });
  mod.method("ellipse", [](const cv::Mat &img, cv::Point center, cv::Size axes,
                           double angle, double startAngle, double endAngle,
                           const cv::Scalar &color, int thickness, int lineType,
                           int shift) {
    return cv::ellipse(cv::InputOutputArray(img), center, axes, angle,
                       startAngle, endAngle, color, thickness, lineType, shift);
  });
  mod.method("ellipse", [](const cv::Mat &img, const cv::RotatedRect &box,
                           const cv::Scalar &color) {
    return cv::ellipse(cv::InputOutputArray(img), box, color);
  });
  mod.method("ellipse", [](const cv::Mat &img, const cv::RotatedRect &box,
                           const cv::Scalar &color, int thickness) {
    return cv::ellipse(cv::InputOutputArray(img), box, color, thickness);
  });
  mod.method("ellipse",
             [](const cv::Mat &img, const cv::RotatedRect &box,
                const cv::Scalar &color, int thickness, int lineType) {
               return cv::ellipse(cv::InputOutputArray(img), box, color,
                                  thickness, lineType);
             });
  mod.add_bits<cv::MarkerTypes>("MarkerTypes");
  mod.set_const("MARKER_CROSS", cv::MarkerTypes::MARKER_CROSS);
  mod.set_const("MARKER_TILTED_CROSS", cv::MarkerTypes::MARKER_TILTED_CROSS);
  mod.set_const("MARKER_STAR", cv::MarkerTypes::MARKER_STAR);
  mod.set_const("MARKER_DIAMOND", cv::MarkerTypes::MARKER_DIAMOND);
  mod.set_const("MARKER_SQUARE", cv::MarkerTypes::MARKER_SQUARE);
  mod.set_const("MARKER_TRIANGLE_UP", cv::MarkerTypes::MARKER_TRIANGLE_UP);
  mod.set_const("MARKER_TRIANGLE_DOWN", cv::MarkerTypes::MARKER_TRIANGLE_DOWN);
  mod.method("fillConvexPoly", [](const cv::Mat &img, const cv::Mat &points,
                                  const cv::Scalar &color) {
    return cv::fillConvexPoly(cv::InputOutputArray(img), cv::InputArray(points),
                              color);
  });
  mod.method("fillConvexPoly", [](const cv::Mat &img, const cv::Mat &points,
                                  const cv::Scalar &color, int lineType) {
    return cv::fillConvexPoly(cv::InputOutputArray(img), cv::InputArray(points),
                              color, lineType);
  });
  mod.method("fillConvexPoly", [](const cv::Mat &img, const cv::Mat &points,
                                  const cv::Scalar &color, int lineType,
                                  int shift) {
    return cv::fillConvexPoly(cv::InputOutputArray(img), cv::InputArray(points),
                              color, lineType, shift);
  });
  mod.method("fillPoly", [](const cv::Mat &img, const std::vector<cv::Mat> &pts,
                            const cv::Scalar &color) {
    return cv::fillPoly(cv::InputOutputArray(img), cv::InputArrayOfArrays(pts),
                        color);
  });
  mod.method("fillPoly", [](const cv::Mat &img, const std::vector<cv::Mat> &pts,
                            const cv::Scalar &color, int lineType) {
    return cv::fillPoly(cv::InputOutputArray(img), cv::InputArrayOfArrays(pts),
                        color, lineType);
  });
  mod.method("fillPoly", [](const cv::Mat &img, const std::vector<cv::Mat> &pts,
                            const cv::Scalar &color, int lineType, int shift) {
    return cv::fillPoly(cv::InputOutputArray(img), cv::InputArrayOfArrays(pts),
                        color, lineType, shift);
  });
  mod.method("fillPoly", [](const cv::Mat &img, const std::vector<cv::Mat> &pts,
                            const cv::Scalar &color, int lineType, int shift,
                            cv::Point offset) {
    return cv::fillPoly(cv::InputOutputArray(img), cv::InputArrayOfArrays(pts),
                        color, lineType, shift, offset);
  });
  mod.method(
      "polylines", [](const cv::Mat &img, const std::vector<cv::Mat> &pts,
                      bool isClosed, const cv::Scalar &color) {
        return cv::polylines(cv::InputOutputArray(img),
                             cv::InputArrayOfArrays(pts), isClosed, color);
      });
  mod.method("polylines", [](const cv::Mat &img,
                             const std::vector<cv::Mat> &pts, bool isClosed,
                             const cv::Scalar &color, int thickness) {
    return cv::polylines(cv::InputOutputArray(img), cv::InputArrayOfArrays(pts),
                         isClosed, color, thickness);
  });
  mod.method("polylines", [](const cv::Mat &img,
                             const std::vector<cv::Mat> &pts, bool isClosed,
                             const cv::Scalar &color, int thickness,
                             int lineType) {
    return cv::polylines(cv::InputOutputArray(img), cv::InputArrayOfArrays(pts),
                         isClosed, color, thickness, lineType);
  });
  mod.method("polylines", [](const cv::Mat &img,
                             const std::vector<cv::Mat> &pts, bool isClosed,
                             const cv::Scalar &color, int thickness,
                             int lineType, int shift) {
    return cv::polylines(cv::InputOutputArray(img), cv::InputArrayOfArrays(pts),
                         isClosed, color, thickness, lineType, shift);
  });
  mod.method("drawContours",
             [](const cv::Mat &image, const std::vector<cv::Mat> &contours,
                int contourIdx, const cv::Scalar &color) {
               return cv::drawContours(cv::InputOutputArray(image),
                                       cv::InputArrayOfArrays(contours),
                                       contourIdx, color);
             });
  mod.method("drawContours",
             [](const cv::Mat &image, const std::vector<cv::Mat> &contours,
                int contourIdx, const cv::Scalar &color, int thickness) {
               return cv::drawContours(cv::InputOutputArray(image),
                                       cv::InputArrayOfArrays(contours),
                                       contourIdx, color, thickness);
             });
  mod.method(
      "drawContours",
      [](const cv::Mat &image, const std::vector<cv::Mat> &contours,
         int contourIdx, const cv::Scalar &color, int thickness, int lineType) {
        return cv::drawContours(cv::InputOutputArray(image),
                                cv::InputArrayOfArrays(contours), contourIdx,
                                color, thickness, lineType);
      });
  mod.method("drawContours",
             [](const cv::Mat &image, const std::vector<cv::Mat> &contours,
                int contourIdx, const cv::Scalar &color, int thickness,
                int lineType, const cv::Mat &hierarchy) {
               return cv::drawContours(cv::InputOutputArray(image),
                                       cv::InputArrayOfArrays(contours),
                                       contourIdx, color, thickness, lineType,
                                       cv::InputArray(hierarchy));
             });
  mod.method("drawContours",
             [](const cv::Mat &image, const std::vector<cv::Mat> &contours,
                int contourIdx, const cv::Scalar &color, int thickness,
                int lineType, const cv::Mat &hierarchy, int maxLevel) {
               return cv::drawContours(cv::InputOutputArray(image),
                                       cv::InputArrayOfArrays(contours),
                                       contourIdx, color, thickness, lineType,
                                       cv::InputArray(hierarchy), maxLevel);
             });
  mod.method(
      "drawContours",
      [](const cv::Mat &image, const std::vector<cv::Mat> &contours,
         int contourIdx, const cv::Scalar &color, int thickness, int lineType,
         const cv::Mat &hierarchy, int maxLevel, cv::Point offset) {
        return cv::drawContours(cv::InputOutputArray(image),
                                cv::InputArrayOfArrays(contours), contourIdx,
                                color, thickness, lineType,
                                cv::InputArray(hierarchy), maxLevel, offset);
      });
  mod.method("clipLine", [](cv::Size imgSize, cv::Point &pt1, cv::Point &pt2) {
    return cv::clipLine(imgSize, pt1, pt2);
  });
  mod.method("clipLine",
             [](cv::Size2l imgSize, cv::Point2l &pt1, cv::Point2l &pt2) {
               return cv::clipLine(imgSize, pt1, pt2);
             });
  mod.method("clipLine", [](cv::Rect imgRect, cv::Point &pt1, cv::Point &pt2) {
    return cv::clipLine(imgRect, pt1, pt2);
  });
  mod.method("ellipse2Poly",
             [](cv::Point center, cv::Size axes, int angle, int arcStart,
                int arcEnd, int delta, const std::vector<Point> &pts) {
               return cv::ellipse2Poly(center, axes, angle, arcStart, arcEnd,
                                       delta, const_off(pts));
             });
  mod.method("ellipse2Poly",
             [](cv::Point2d center, cv::Size2d axes, int angle, int arcStart,
                int arcEnd, int delta, const std::vector<Point2d> &pts) {
               return cv::ellipse2Poly(center, axes, angle, arcStart, arcEnd,
                                       delta, const_off(pts));
             });
  mod.method("putText",
             [](const cv::Mat &img, const cv::String &text, cv::Point org,
                int fontFace, double fontScale, cv::Scalar color) {
               return cv::putText(cv::InputOutputArray(img), text, org,
                                  fontFace, fontScale, color);
             });
  mod.method("putText", [](const cv::Mat &img, const cv::String &text,
                           cv::Point org, int fontFace, double fontScale,
                           cv::Scalar color, int thickness) {
    return cv::putText(cv::InputOutputArray(img), text, org, fontFace,
                       fontScale, color, thickness);
  });
  mod.method("putText", [](const cv::Mat &img, const cv::String &text,
                           cv::Point org, int fontFace, double fontScale,
                           cv::Scalar color, int thickness, int lineType) {
    return cv::putText(cv::InputOutputArray(img), text, org, fontFace,
                       fontScale, color, thickness, lineType);
  });
  mod.method("putText", [](const cv::Mat &img, const cv::String &text,
                           cv::Point org, int fontFace, double fontScale,
                           cv::Scalar color, int thickness, int lineType,
                           bool bottomLeftOrigin) {
    return cv::putText(cv::InputOutputArray(img), text, org, fontFace,
                       fontScale, color, thickness, lineType, bottomLeftOrigin);
  });
  mod.method("getTextSize", [](const cv::String &text, int fontFace,
                               double fontScale, int thickness, int *baseLine) {
    return cv::getTextSize(text, fontFace, fontScale, thickness, baseLine);
  });
  mod.method("getFontScaleFromHeight",
             [](const int fontFace, const int pixelHeight) {
               return cv::getFontScaleFromHeight(fontFace, pixelHeight);
             });
  mod.method(
      "getFontScaleFromHeight",
      [](const int fontFace, const int pixelHeight, const int thickness) {
        return cv::getFontScaleFromHeight(fontFace, pixelHeight, thickness);
      });
  mod.add_type<cv::LineIterator>("LineIterator")
      .constructor<const cv::Mat &, cv::Point, cv::Point, int, bool>()
      .method("operator*",
              [](cv::LineIterator &instance) { return instance.operator*(); })
      .method("operator++",
              [](cv::LineIterator &instance) { return instance.operator++(); })
      .method("operator++",
              [](cv::LineIterator &instance, int _argument0) {
                return instance.operator++(_argument0);
              })
      .method("pos",
              [](const cv::LineIterator &instance) { return instance.pos(); })
      .method("ptr",
              [](const cv::LineIterator &instance) { return instance.ptr; })
      .method("ptr0",
              [](const cv::LineIterator &instance) { return instance.ptr0; })
      .method("step",
              [](const cv::LineIterator &instance) { return instance.step; })
      .method(
          "elemSize",
          [](const cv::LineIterator &instance) { return instance.elemSize; })
      .method("err",
              [](const cv::LineIterator &instance) { return instance.err; })
      .method("count",
              [](const cv::LineIterator &instance) { return instance.count; })
      .method(
          "minusDelta",
          [](const cv::LineIterator &instance) { return instance.minusDelta; })
      .method(
          "plusDelta",
          [](const cv::LineIterator &instance) { return instance.plusDelta; })
      .method(
          "minusStep",
          [](const cv::LineIterator &instance) { return instance.minusStep; })
      .method("plusStep", [](const cv::LineIterator &instance) {
        return instance.plusStep;
      });
}
