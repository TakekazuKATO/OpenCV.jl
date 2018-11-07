#include "modules.hpp"
#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
extern "C" {
extern void define_core_types_module(jlcxx::Module &);
extern void define_core_affine_module(jlcxx::Module &);
extern void define_core_mat_module(jlcxx::Module &);
extern void define_core_module(jlcxx::Module &);
extern void define_core_persistence_module(jlcxx::Module &);
extern void define_imgproc_module(jlcxx::Module &);
extern void define_imgcodecs_module(jlcxx::Module &);
extern void define_videoio_module(jlcxx::Module &);
extern void define_video_tracking_module(jlcxx::Module &);
extern void define_video_background_segm_module(jlcxx::Module &);
extern void define_calib3d_module(jlcxx::Module &);
// extern void define_flann_module(jlcxx::Module &);
extern void define_features2d_module(jlcxx::Module &);
extern void define_objdetect_module(jlcxx::Module &);
extern void define_dnn_all_layers_module(jlcxx::Module &);
extern void define_dnn_module(jlcxx::Module &);
extern void define_ml_module(jlcxx::Module &);
extern void define_photo_module(jlcxx::Module &);
extern void define_stitching_module(jlcxx::Module &);
extern void define_superres_module(jlcxx::Module &);
}
JLCXX_MODULE
define_julia_module(jlcxx::Module &mod) {
  mod.add_type<::IplROI>("IplROI");
  mod.add_type<::CvSet>("CvSet");
  mod.add_type<::CvTypeInfo>("CvTypeInfo");
  mod.add_type<::CvMat>("CvMat");
  mod.add_type<::CvTermCriteria>("CvTermCriteria");
  mod.add_type<cv::_InputArray>("InputArray");
  mod.add_type<cv::_OutputArray>("OutputArray");
  mod.add_type<cv::_InputOutputArray>("InputOutputArray");
  mod.add_type<cv::SparseMat::Hdr>("SparseMatHdr");
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("initializer_list")
      .apply<std::initializer_list<unsigned char>, std::initializer_list<int>,
             std::initializer_list<short>,
             std::initializer_list<unsigned short>, std::initializer_list<char>,
             std::initializer_list<int64>, std::initializer_list<float>,
             std::initializer_list<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
      });
  mod.add_type<CvFileNode>("CvFileNode");
  mod.add_type<cv::DetectionBasedTracker::IDetector>("IDetector");
  mod.add_type<cv::DetectionBasedTracker::Parameters>("Parameters");
  define_core_types_module(mod);
  define_core_affine_module(mod);
  define_core_mat_module(mod);
  define_core_module(mod);
  define_core_persistence_module(mod);
  define_imgproc_module(mod);
  define_imgcodecs_module(mod);
  define_videoio_module(mod);
  define_video_tracking_module(mod);
  define_video_background_segm_module(mod);
  define_calib3d_module(mod);
  // define_flann_module(mod);

  mod.add_type<cv::flann::IndexParams>("IndexParams")
      .method("getString",
              [](const cv::flann::IndexParams &instance,
                 const cv::String &key) { return instance.getString(key); })
      .method("getString",
              [](const cv::flann::IndexParams &instance, const cv::String &key,
                 const cv::String &defaultVal) {
                return instance.getString(key, defaultVal);
              })
      .method("getInt",
              [](const cv::flann::IndexParams &instance,
                 const cv::String &key) { return instance.getInt(key); })
      .method("getInt",
              [](const cv::flann::IndexParams &instance, const cv::String &key,
                 int defaultVal) { return instance.getInt(key, defaultVal); })
      .method("getDouble",
              [](const cv::flann::IndexParams &instance,
                 const cv::String &key) { return instance.getDouble(key); })
      .method(
          "getDouble",
          [](const cv::flann::IndexParams &instance, const cv::String &key,
             double defaultVal) { return instance.getDouble(key, defaultVal); })
      .method("setString",
              [](cv::flann::IndexParams &instance, const cv::String &key,
                 const cv::String &value) {
                return instance.setString(key, value);
              })
      .method("setInt",
              [](cv::flann::IndexParams &instance, const cv::String &key,
                 int value) { return instance.setInt(key, value); })
      .method("setDouble",
              [](cv::flann::IndexParams &instance, const cv::String &key,
                 double value) { return instance.setDouble(key, value); })
      .method("setFloat",
              [](cv::flann::IndexParams &instance, const cv::String &key,
                 float value) { return instance.setFloat(key, value); })
      .method("setBool",
              [](cv::flann::IndexParams &instance, const cv::String &key,
                 bool value) { return instance.setBool(key, value); })
      .method("setAlgorithm",
              [](cv::flann::IndexParams &instance, int value) {
                return instance.setAlgorithm(value);
              })
      .method("getAll",
              [](const cv::flann::IndexParams &instance,
                 const std::vector<cv::String> &names,
                 const std::vector<int> &types,
                 const std::vector<cv::String> &strValues,
                 const std::vector<double> &numValues) {
                return instance.getAll(
                    jlcxx::const_off(names), jlcxx::const_off(types),
                    jlcxx::const_off(strValues), jlcxx::const_off(numValues));
              })
      .method("params", [](const cv::flann::IndexParams &instance) {
        return instance.params;
      });
  mod.add_type<cv::flann::SearchParams>("SearchParams")
      .constructor<int, float, bool>();
  mod.add_type<cv::SimpleBlobDetector::Params>("SimpleBlobDetectorParams");

  define_features2d_module(mod);

  mod.add_type<cv::BaseCascadeClassifier::MaskGenerator>(
         "BaseCascadeClassifierMaskGenerator")
      .method("generateMask",
              &cv::BaseCascadeClassifier::MaskGenerator::generateMask)
      .method("initializeMask",
              &cv::BaseCascadeClassifier::MaskGenerator::initializeMask);
  mod.add_type<cv::DetectionBasedTracker::ExtObject>(
      "DetectionBasedTrackerExtObject");
  define_objdetect_module(mod);
  define_dnn_module(mod);
  define_dnn_all_layers_module(mod);
  define_ml_module(mod);
  define_photo_module(mod);
  define_stitching_module(mod);
  define_superres_module(mod);
  mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>, jlcxx::TypeVar<2>>>("Pair")
      .apply<std::pair<cv::Rect_<int>, int>>([&mod](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename WrappedT::first_type ValueT1;
        typedef typename WrappedT::second_type ValueT2;
        wrapped.template constructor<const ValueT1 &, const ValueT2 &>();
      });
  /*
mod.add_type<jlcxx::Parametric<jlcxx::TypeVar<1>>>("Vector")
  .apply<std::vector<int>, std::vector<std::vector<int>>, std::vector<char>,
         std::vector<unsigned char>,
         std::vector<std::vector<unsigned char>>, std::vector<float>,
         std::vector<double>, std::vector<cv::Point_<int>>,
         std::vector<cv::Point_<float>>, std::vector<cv::Point_<double>>,
         std::vector<std::vector<cv::Point_<int>>>, std::vector<cv::Rect>,
         std::vector<cv::Mat>, std::vector<cv::KeyPoint>,
         std::vector<cv::DMatch>, std::vector<std::vector<cv::DMatch>>,
         std::vector<cv::String>, std::vector<cv::DetectionROI>,
         std::vector<std::pair<cv::Rect_<int>, int>>,
         std::vector<cv::DetectionBasedTracker::ExtObject>>(
      [&mod](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename WrappedT::value_type ValueT;
        wrapped.template constructor<size_t>();
        wrapped.template constructor<size_t, ValueT>();
        mod.method("Vector", [](jlcxx::ArrayRef<ValueT> arr) {
          return std::vector<ValueT>((ValueT *)arr.data(),
                                     (ValueT *)arr.data() + arr.size());
        });
        wrapped.method("getindex", [](const std::vector<ValueT> v,
                                      int64_t i) { return v[i]; });
      });*/
}
