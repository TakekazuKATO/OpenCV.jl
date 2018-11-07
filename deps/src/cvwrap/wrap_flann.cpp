#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_flann_module(Module &mod) {
  mod.add_bits<cvflann::flann_algorithm_t>("flann_algorithm_t");
  mod.set_const("FLANN_INDEX_LINEAR",
                cvflann::flann_algorithm_t::FLANN_INDEX_LINEAR);
  mod.set_const("FLANN_INDEX_KDTREE",
                cvflann::flann_algorithm_t::FLANN_INDEX_KDTREE);
  mod.set_const("FLANN_INDEX_KMEANS",
                cvflann::flann_algorithm_t::FLANN_INDEX_KMEANS);
  mod.set_const("FLANN_INDEX_COMPOSITE",
                cvflann::flann_algorithm_t::FLANN_INDEX_COMPOSITE);
  mod.set_const("FLANN_INDEX_KDTREE_SINGLE",
                cvflann::flann_algorithm_t::FLANN_INDEX_KDTREE_SINGLE);
  mod.set_const("FLANN_INDEX_HIERARCHICAL",
                cvflann::flann_algorithm_t::FLANN_INDEX_HIERARCHICAL);
  mod.set_const("FLANN_INDEX_LSH", cvflann::flann_algorithm_t::FLANN_INDEX_LSH);
  mod.set_const("FLANN_INDEX_SAVED",
                cvflann::flann_algorithm_t::FLANN_INDEX_SAVED);
  mod.set_const("FLANN_INDEX_AUTOTUNED",
                cvflann::flann_algorithm_t::FLANN_INDEX_AUTOTUNED);
  mod.set_const("LINEAR", cvflann::flann_algorithm_t::LINEAR);
  mod.set_const("KDTREE", cvflann::flann_algorithm_t::KDTREE);
  mod.set_const("KMEANS", cvflann::flann_algorithm_t::KMEANS);
  mod.set_const("COMPOSITE", cvflann::flann_algorithm_t::COMPOSITE);
  mod.set_const("KDTREE_SINGLE", cvflann::flann_algorithm_t::KDTREE_SINGLE);
  mod.set_const("SAVED", cvflann::flann_algorithm_t::SAVED);
  mod.set_const("AUTOTUNED", cvflann::flann_algorithm_t::AUTOTUNED);
  mod.add_bits<cvflann::flann_centers_init_t>("flann_centers_init_t");
  mod.set_const("FLANN_CENTERS_RANDOM",
                cvflann::flann_centers_init_t::FLANN_CENTERS_RANDOM);
  mod.set_const("FLANN_CENTERS_GONZALES",
                cvflann::flann_centers_init_t::FLANN_CENTERS_GONZALES);
  mod.set_const("FLANN_CENTERS_KMEANSPP",
                cvflann::flann_centers_init_t::FLANN_CENTERS_KMEANSPP);
  mod.set_const("FLANN_CENTERS_GROUPWISE",
                cvflann::flann_centers_init_t::FLANN_CENTERS_GROUPWISE);
  mod.set_const("CENTERS_RANDOM",
                cvflann::flann_centers_init_t::CENTERS_RANDOM);
  mod.set_const("CENTERS_GONZALES",
                cvflann::flann_centers_init_t::CENTERS_GONZALES);
  mod.set_const("CENTERS_KMEANSPP",
                cvflann::flann_centers_init_t::CENTERS_KMEANSPP);
  mod.add_bits<cvflann::flann_log_level_t>("flann_log_level_t");
  mod.set_const("FLANN_LOG_NONE", cvflann::flann_log_level_t::FLANN_LOG_NONE);
  mod.set_const("FLANN_LOG_FATAL", cvflann::flann_log_level_t::FLANN_LOG_FATAL);
  mod.set_const("FLANN_LOG_ERROR", cvflann::flann_log_level_t::FLANN_LOG_ERROR);
  mod.set_const("FLANN_LOG_WARN", cvflann::flann_log_level_t::FLANN_LOG_WARN);
  mod.set_const("FLANN_LOG_INFO", cvflann::flann_log_level_t::FLANN_LOG_INFO);
  mod.add_bits<cvflann::flann_distance_t>("flann_distance_t");
  mod.set_const("FLANN_DIST_EUCLIDEAN",
                cvflann::flann_distance_t::FLANN_DIST_EUCLIDEAN);
  mod.set_const("FLANN_DIST_L2", cvflann::flann_distance_t::FLANN_DIST_L2);
  mod.set_const("FLANN_DIST_MANHATTAN",
                cvflann::flann_distance_t::FLANN_DIST_MANHATTAN);
  mod.set_const("FLANN_DIST_L1", cvflann::flann_distance_t::FLANN_DIST_L1);
  mod.set_const("FLANN_DIST_MINKOWSKI",
                cvflann::flann_distance_t::FLANN_DIST_MINKOWSKI);
  mod.set_const("FLANN_DIST_MAX", cvflann::flann_distance_t::FLANN_DIST_MAX);
  mod.set_const("FLANN_DIST_HIST_INTERSECT",
                cvflann::flann_distance_t::FLANN_DIST_HIST_INTERSECT);
  mod.set_const("FLANN_DIST_HELLINGER",
                cvflann::flann_distance_t::FLANN_DIST_HELLINGER);
  mod.set_const("FLANN_DIST_CHI_SQUARE",
                cvflann::flann_distance_t::FLANN_DIST_CHI_SQUARE);
  mod.set_const("FLANN_DIST_CS", cvflann::flann_distance_t::FLANN_DIST_CS);
  mod.set_const("FLANN_DIST_KULLBACK_LEIBLER",
                cvflann::flann_distance_t::FLANN_DIST_KULLBACK_LEIBLER);
  mod.set_const("FLANN_DIST_KL", cvflann::flann_distance_t::FLANN_DIST_KL);
  mod.set_const("FLANN_DIST_HAMMING",
                cvflann::flann_distance_t::FLANN_DIST_HAMMING);
  mod.set_const("EUCLIDEAN", cvflann::flann_distance_t::EUCLIDEAN);
  mod.set_const("MANHATTAN", cvflann::flann_distance_t::MANHATTAN);
  mod.set_const("MINKOWSKI", cvflann::flann_distance_t::MINKOWSKI);
  mod.set_const("MAX_DIST", cvflann::flann_distance_t::MAX_DIST);
  mod.set_const("HIST_INTERSECT", cvflann::flann_distance_t::HIST_INTERSECT);
  mod.set_const("HELLINGER", cvflann::flann_distance_t::HELLINGER);
  mod.set_const("CS", cvflann::flann_distance_t::CS);
  mod.set_const("KL", cvflann::flann_distance_t::KL);
  mod.set_const("KULLBACK_LEIBLER",
                cvflann::flann_distance_t::KULLBACK_LEIBLER);
  mod.add_bits<cvflann::flann_datatype_t>("flann_datatype_t");
  mod.set_const("FLANN_INT8", cvflann::flann_datatype_t::FLANN_INT8);
  mod.set_const("FLANN_INT16", cvflann::flann_datatype_t::FLANN_INT16);
  mod.set_const("FLANN_INT32", cvflann::flann_datatype_t::FLANN_INT32);
  mod.set_const("FLANN_INT64", cvflann::flann_datatype_t::FLANN_INT64);
  mod.set_const("FLANN_UINT8", cvflann::flann_datatype_t::FLANN_UINT8);
  mod.set_const("FLANN_UINT16", cvflann::flann_datatype_t::FLANN_UINT16);
  mod.set_const("FLANN_UINT32", cvflann::flann_datatype_t::FLANN_UINT32);
  mod.set_const("FLANN_UINT64", cvflann::flann_datatype_t::FLANN_UINT64);
  mod.set_const("FLANN_FLOAT32", cvflann::flann_datatype_t::FLANN_FLOAT32);
  mod.set_const("FLANN_FLOAT64", cvflann::flann_datatype_t::FLANN_FLOAT64);
  mod.set_const("FLANN_CHECKS_UNLIMITED", (int)cvflann::FLANN_CHECKS_UNLIMITED);
  mod.set_const("FLANN_CHECKS_AUTOTUNED", (int)cvflann::FLANN_CHECKS_AUTOTUNED);
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
                 std::vector<cv::String> &names, std::vector<int> &types,
                 std::vector<cv::String> &strValues,
                 std::vector<double> &numValues) {
                return instance.getAll(names, types, strValues, numValues);
              })
      .method("params", [](const cv::flann::IndexParams &instance) {
        return instance.params;
      });
  mod.add_type<cv::flann::KDTreeIndexParams>("KDTreeIndexParams")
      .constructor<int>();
  mod.add_type<cv::flann::LinearIndexParams>("LinearIndexParams");
  mod.add_type<cv::flann::CompositeIndexParams>("CompositeIndexParams")
      .constructor<int, int, int, cvflann::flann_centers_init_t, float>();
  mod.add_type<cv::flann::AutotunedIndexParams>("AutotunedIndexParams")
      .constructor<float, float, float, float>();
  mod.add_type<cv::flann::HierarchicalClusteringIndexParams>(
         "HierarchicalClusteringIndexParams")
      .constructor<int, cvflann::flann_centers_init_t, int, int>();
  mod.add_type<cv::flann::KMeansIndexParams>("KMeansIndexParams")
      .constructor<int, int, cvflann::flann_centers_init_t, float>();
  mod.add_type<cv::flann::LshIndexParams>("LshIndexParams")
      .constructor<int, int, int>();
  mod.add_type<cv::flann::SavedIndexParams>("SavedIndexParams")
      .constructor<const cv::String &>();
  mod.add_type<cv::flann::SearchParams>("SearchParams")
      .constructor<int, float, bool>();
  mod.add_type<cv::flann::Index>("Index")
      .constructor<cv::InputArray, const cv::flann::IndexParams &,
                   cvflann::flann_distance_t>()
      .method("build",
              [](cv::flann::Index &instance, const cv::Mat &features,
                 const cv::flann::IndexParams &params) {
                return instance.build(cv::InputArray(features), params);
              })
      .method("build",
              [](cv::flann::Index &instance, const cv::Mat &features,
                 const cv::flann::IndexParams &params,
                 cvflann::flann_distance_t distType) {
                return instance.build(cv::InputArray(features), params,
                                      distType);
              })
      .method("knnSearch",
              [](cv::flann::Index &instance, const cv::Mat &query,
                 const cv::Mat &indices, const cv::Mat &dists, int knn) {
                return instance.knnSearch(cv::InputArray(query),
                                          cv::OutputArray(indices),
                                          cv::OutputArray(dists), knn);
              })
      .method("knnSearch",
              [](cv::flann::Index &instance, const cv::Mat &query,
                 const cv::Mat &indices, const cv::Mat &dists, int knn,
                 const cv::flann::SearchParams &params) {
                return instance.knnSearch(cv::InputArray(query),
                                          cv::OutputArray(indices),
                                          cv::OutputArray(dists), knn, params);
              })
      .method("radiusSearch",
              [](cv::flann::Index &instance, const cv::Mat &query,
                 const cv::Mat &indices, const cv::Mat &dists, double radius,
                 int maxResults) {
                return instance.radiusSearch(
                    cv::InputArray(query), cv::OutputArray(indices),
                    cv::OutputArray(dists), radius, maxResults);
              })
      .method("radiusSearch",
              [](cv::flann::Index &instance, const cv::Mat &query,
                 const cv::Mat &indices, const cv::Mat &dists, double radius,
                 int maxResults, const cv::flann::SearchParams &params) {
                return instance.radiusSearch(
                    cv::InputArray(query), cv::OutputArray(indices),
                    cv::OutputArray(dists), radius, maxResults, params);
              })
      .method("save",
              [](const cv::flann::Index &instance, const cv::String &filename) {
                return instance.save(filename);
              })
      .method("load",
              [](cv::flann::Index &instance, const cv::Mat &features,
                 const cv::String &filename) {
                return instance.load(cv::InputArray(features), filename);
              })
      .method("release",
              [](cv::flann::Index &instance) { return instance.release(); })
      .method("getDistance",
              [](const cv::flann::Index &instance) {
                return instance.getDistance();
              })
      .method("getAlgorithm", [](const cv::flann::Index &instance) {
        return instance.getAlgorithm();
      });
  mod.add_type<cvflann::FLANNException>("FLANNException")
      .constructor<const char *>()
      .constructor<const cv::String &>();
  mod.add_type<Parametric<TypeVar<1>>>("Matrix")
      .apply<cvflann::Matrix<int>, cvflann::Matrix<int64_t>,
             cvflann::Matrix<uchar>, cvflann::Matrix<short>,
             cvflann::Matrix<ushort>, cvflann::Matrix<float>,
             cvflann::Matrix<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("rows",
                    [](const WrappedT &instance) { return instance.rows; })
            .method("cols",
                    [](const WrappedT &instance) { return instance.cols; })
            .method("stride",
                    [](const WrappedT &instance) { return instance.stride; })
            .method("data",
                    [](const WrappedT &instance) { return instance.data; })
            .template constructor<ValueT *, size_t, size_t, size_t>()
            .method("free", [](WrappedT &instance) { return instance.free(); })
            .method("operator[]", [](const WrappedT &instance, size_t index) {
              return instance.operator[](index);
            });
      });
  mod.add_type<cvflann::UntypedMatrix>("UntypedMatrix")
      .method(
          "rows",
          [](const cvflann::UntypedMatrix &instance) { return instance.rows; })
      .method(
          "cols",
          [](const cvflann::UntypedMatrix &instance) { return instance.cols; })
      .method(
          "data",
          [](const cvflann::UntypedMatrix &instance) { return instance.data; })
      .method(
          "type",
          [](const cvflann::UntypedMatrix &instance) { return instance.type; })
      .constructor<void *, long, long>();
  mod.add_type<cvflann::anyimpl::base_any_policy>("base_any_policy")
      .method("static_delete",
              [](cvflann::anyimpl::base_any_policy &instance, void **x) {
                return instance.static_delete(x);
              })
      .method("copy_from_value",
              [](cvflann::anyimpl::base_any_policy &instance, const void *src,
                 void **dest) { return instance.copy_from_value(src, dest); })
      .method("clone",
              [](cvflann::anyimpl::base_any_policy &instance, void *const *src,
                 void **dest) { return instance.clone(src, dest); })
      .method("move",
              [](cvflann::anyimpl::base_any_policy &instance, void *const *src,
                 void **dest) { return instance.move(src, dest); })
      .method("get_value", [](cvflann::anyimpl::base_any_policy &instance,
                              void **src) { return instance.get_value(src); })
      .method("get_value", [](cvflann::anyimpl::base_any_policy &instance,
                              void **src) { return instance.get_value(src); })
      .method("get_size",
              [](cvflann::anyimpl::base_any_policy &instance) {
                return instance.get_size();
              })
      //.method("type",
      //        [](cvflann::anyimpl::base_any_policy &instance) {
      //          return instance.type();
      //        })
      .method("print",
              [](cvflann::anyimpl::base_any_policy &instance, std::ostream &out,
                 void *const *src) { return instance.print(out, src); });
  mod.add_type<Parametric<TypeVar<1>>>("typed_base_any_policy")
      .apply<cvflann::anyimpl::typed_base_any_policy<int>,
             cvflann::anyimpl::typed_base_any_policy<int64_t>,
             cvflann::anyimpl::typed_base_any_policy<uchar>,
             cvflann::anyimpl::typed_base_any_policy<short>,
             cvflann::anyimpl::typed_base_any_policy<ushort>,
             cvflann::anyimpl::typed_base_any_policy<float>,
             cvflann::anyimpl::typed_base_any_policy<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("get_size",
                    [](WrappedT &instance) { return instance.get_size(); })
            .method("type", [](WrappedT &instance) { return instance.type(); });
      });
  mod.add_type<Parametric<TypeVar<1>>>("small_any_policy")
      .apply<cvflann::anyimpl::small_any_policy<int>,
             cvflann::anyimpl::small_any_policy<int64_t>,
             cvflann::anyimpl::small_any_policy<uchar>,
             cvflann::anyimpl::small_any_policy<short>,
             cvflann::anyimpl::small_any_policy<ushort>,
             cvflann::anyimpl::small_any_policy<float>,
             cvflann::anyimpl::small_any_policy<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("static_delete",
                    [](WrappedT &instance, void **) {
                      return instance.static_delete();
                    })
            .method("copy_from_value",
                    [](WrappedT &instance, void const *src, void **dest) {
                      return instance.copy_from_value(src, dest);
                    })
            .method("clone",
                    [](WrappedT &instance, void *src, void **dest) {
                      return instance.clone(src, dest);
                    })
            .method("move",
                    [](WrappedT &instance, void *src, void **dest) {
                      return instance.move(src, dest);
                    })
            .method("get_value",
                    [](WrappedT &instance, void **src) {
                      return instance.get_value(src);
                    })
            .method("get_value",
                    [](WrappedT &instance, void *src) {
                      return instance.get_value(src);
                    })
            .method("print",
                    [](WrappedT &instance, std::ostream &out, void *src) {
                      return instance.print(out, src);
                    });
      });
  mod.add_type<Parametric<TypeVar<1>>>("big_any_policy")
      .apply<cvflann::anyimpl::big_any_policy<int>,
             cvflann::anyimpl::big_any_policy<int64_t>,
             cvflann::anyimpl::big_any_policy<uchar>,
             cvflann::anyimpl::big_any_policy<short>,
             cvflann::anyimpl::big_any_policy<ushort>,
             cvflann::anyimpl::big_any_policy<float>,
             cvflann::anyimpl::big_any_policy<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("static_delete",
                    [](WrappedT &instance, void **x) {
                      return instance.static_delete(x);
                    })
            .method("copy_from_value",
                    [](WrappedT &instance, void const *src, void **dest) {
                      return instance.copy_from_value(src, dest);
                    })
            .method("clone",
                    [](WrappedT &instance, void *src, void **dest) {
                      return instance.clone(src, dest);
                    })
            .method("move",
                    [](WrappedT &instance, void *src, void **dest) {
                      return instance.move(src, dest);
                    })
            .method("get_value",
                    [](WrappedT &instance, void **src) {
                      return instance.get_value(src);
                    })
            .method("get_value",
                    [](WrappedT &instance, void *src) {
                      return instance.get_value(src);
                    })
            .method("print",
                    [](WrappedT &instance, std::ostream &out, void *src) {
                      return instance.print(out, src);
                    });
      });
  mod.add_type<Parametric<TypeVar<1>>>("choose_policy")
      .apply<cvflann::anyimpl::choose_policy<int>,
             cvflann::anyimpl::choose_policy<int64_t>,
             cvflann::anyimpl::choose_policy<uchar>,
             cvflann::anyimpl::choose_policy<short>,
             cvflann::anyimpl::choose_policy<ushort>,
             cvflann::anyimpl::choose_policy<float>,
             cvflann::anyimpl::choose_policy<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  /*mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");
  mod.add_type<cvflann::anyimpl::choose_policy>("choose_policy");*/
  mod.add_type<Parametric<TypeVar<1>>>("SinglePolicy")
      .apply<cvflann::anyimpl::SinglePolicy<int>,
             cvflann::anyimpl::SinglePolicy<int64_t>,
             cvflann::anyimpl::SinglePolicy<uchar>,
             cvflann::anyimpl::SinglePolicy<short>,
             cvflann::anyimpl::SinglePolicy<ushort>,
             cvflann::anyimpl::SinglePolicy<float>,
             cvflann::anyimpl::SinglePolicy<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<const WrappedT &>()
            .method("operator=",
                    [](WrappedT &instance, const WrappedT &other) {
                      return instance.operator=(other);
                    })
            .method("get_policy",
                    [](WrappedT &instance) { return instance.get_policy(); });
      });
  mod.add_type<cvflann::any>("any")
      .constructor<const char *>()
      .constructor<const cvflann::any &>()
      .method("assign",
              [](cvflann::any &instance, const cvflann::any &x) {
                return instance.assign(x);
              })
      .method("operator=",
              [](cvflann::any &instance, const cvflann::any &x) {
                return instance.operator=(x);
              })
      .method("operator=", [](cvflann::any &instance,
                              const char *x) { return instance.operator=(x); })
      .method("swap", [](cvflann::any &instance,
                         cvflann::any &x) { return instance.swap(x); })
      .method("empty", [](cvflann::any &instance) { return instance.empty(); })
      .method("reset", [](cvflann::any &instance) { return instance.reset(); })
      .method("compatible", [](cvflann::any &instance, const cvflann::any &x) {
        return instance.compatible(x);
      });
  //.method("type", [](cvflann::any &instance) { return instance.type(); });
  mod.add_type<cvflann::SearchParams>("SearchParams")
      .constructor<int, float, bool>();
  /*
mod.add_type<Parametric<TypeVar<1>>>("BranchStruct")
  .apply<cvflann::BranchStruct<int>, cvflann::BranchStruct<int64_t>,
         cvflann::BranchStruct<uchar>, cvflann::BranchStruct<short>,
         cvflann::BranchStruct<ushort>, cvflann::BranchStruct<float>,
         cvflann::BranchStruct<double>>([](auto wrapped) {
    typedef typename decltype(wrapped)::type WrappedT;
    typedef typename get_template_type<WrappedT>::type ValueT;
    wrapped
        .method("node",
                [](const WrappedT &instance) { return instance.node; })
        .method("mindist",
                [](const WrappedT &instance) { return instance.mindist; })
        .template constructor<const T &, ValueT>()
        .method("operator<", [](const WrappedT &instance,
                                const cv::BranchStruct<cv::T> &rhs) {
          return instance.operator<(rhs);
        });
  });*/
  mod.add_type<Parametric<TypeVar<1>>>("ResultSet")
      .apply<cvflann::ResultSet<int>, cvflann::ResultSet<int64_t>,
             cvflann::ResultSet<uchar>, cvflann::ResultSet<short>,
             cvflann::ResultSet<ushort>, cvflann::ResultSet<float>,
             cvflann::ResultSet<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("full",
                    [](const WrappedT &instance) { return instance.full(); })
            .method("addPoint",
                    [](WrappedT &instance, ValueT dist, int index) {
                      return instance.addPoint(dist, index);
                    })
            .method("worstDist", [](const WrappedT &instance) {
              return instance.worstDist();
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("KNNSimpleResultSet")
      .apply<cvflann::KNNSimpleResultSet<int>,
             cvflann::KNNSimpleResultSet<int64_t>,
             cvflann::KNNSimpleResultSet<uchar>,
             cvflann::KNNSimpleResultSet<short>,
             cvflann::KNNSimpleResultSet<ushort>,
             cvflann::KNNSimpleResultSet<float>,
             cvflann::KNNSimpleResultSet<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("indices",
                    [](const WrappedT &instance) { return instance.indices; })
            .method("dists",
                    [](const WrappedT &instance) { return instance.dists; })
            .method("capacity",
                    [](const WrappedT &instance) { return instance.capacity; })
            .method("count",
                    [](const WrappedT &instance) { return instance.count; })
            .method("worst_distance_",
                    [](const WrappedT &instance) {
                      return instance.worst_distance_;
                    })
            .template constructor<int>()
            .method("init",
                    [](WrappedT &instance, int *indices_, ValueT *dists_) {
                      return instance.init(indices_, dists_);
                    })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("full",
                    [](const WrappedT &instance) { return instance.full(); })
            .method("addPoint",
                    [](WrappedT &instance, ValueT dist, int index) {
                      return instance.addPoint(dist, index);
                    })
            .method("worstDist", [](const WrappedT &instance) {
              return instance.worstDist();
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("KNNResultSet")
      .apply<cvflann::KNNResultSet<int>, cvflann::KNNResultSet<int64_t>,
             cvflann::KNNResultSet<uchar>, cvflann::KNNResultSet<short>,
             cvflann::KNNResultSet<ushort>, cvflann::KNNResultSet<float>,
             cvflann::KNNResultSet<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("indices",
                    [](const WrappedT &instance) { return instance.indices; })
            .method("dists",
                    [](const WrappedT &instance) { return instance.dists; })
            .method("capacity",
                    [](const WrappedT &instance) { return instance.capacity; })
            .method("count",
                    [](const WrappedT &instance) { return instance.count; })
            .method("worst_distance_",
                    [](const WrappedT &instance) {
                      return instance.worst_distance_;
                    })
            .template constructor<int>()
            .method("init",
                    [](WrappedT &instance, int *indices_, ValueT *dists_) {
                      return instance.init(indices_, dists_);
                    })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("full",
                    [](const WrappedT &instance) { return instance.full(); })
            .method("addPoint",
                    [](WrappedT &instance, ValueT dist, int index) {
                      return instance.addPoint(dist, index);
                    })
            .method("worstDist", [](const WrappedT &instance) {
              return instance.worstDist();
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("RadiusResultSet")
      .apply<cvflann::RadiusResultSet<int>, cvflann::RadiusResultSet<int64_t>,
             cvflann::RadiusResultSet<uchar>, cvflann::RadiusResultSet<short>,
             cvflann::RadiusResultSet<ushort>, cvflann::RadiusResultSet<float>,
             cvflann::RadiusResultSet<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("radius",
                    [](const WrappedT &instance) { return instance.radius; })
            .method("indices",
                    [](const WrappedT &instance) { return instance.indices; })
            .method("dists",
                    [](const WrappedT &instance) { return instance.dists; })
            .method("capacity",
                    [](const WrappedT &instance) { return instance.capacity; })
            .method("count",
                    [](const WrappedT &instance) { return instance.count; })
            .template constructor<ValueT, int *, ValueT *, int>()
            .method("init", [](WrappedT &instance) { return instance.init(); })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("full",
                    [](const WrappedT &instance) { return instance.full(); })
            .method("addPoint",
                    [](WrappedT &instance, ValueT dist, int index) {
                      return instance.addPoint(dist, index);
                    })
            .method("worstDist", [](const WrappedT &instance) {
              return instance.worstDist();
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("UniqueResultSet")
      .apply<cvflann::UniqueResultSet<int>, cvflann::UniqueResultSet<int64_t>,
             cvflann::UniqueResultSet<uchar>, cvflann::UniqueResultSet<short>,
             cvflann::UniqueResultSet<ushort>, cvflann::UniqueResultSet<float>,
             cvflann::UniqueResultSet<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("full",
                    [](const WrappedT &instance) { return instance.full(); })
            .method("clear",
                    [](WrappedT &instance) { return instance.clear(); })
            .method("copy",
                    [](WrappedT &instance, int *indices, ValueT *dist) {
                      return instance.copy(indices, dist);
                    })
            .method("copy",
                    [](WrappedT &instance, int *indices, ValueT *dist,
                       int n_neighbors) {
                      return instance.copy(indices, dist, n_neighbors);
                    })
            .method("sortAndCopy",
                    [](WrappedT &instance, int *indices, ValueT *dist) {
                      return instance.sortAndCopy(indices, dist);
                    })
            .method("sortAndCopy",
                    [](WrappedT &instance, int *indices, ValueT *dist,
                       int n_neighbors) {
                      return instance.sortAndCopy(indices, dist, n_neighbors);
                    })
            .method("size", [](WrappedT &instance) { return instance.size(); })
            .method("worstDist", [](const WrappedT &instance) {
              return instance.worstDist();
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("KNNUniqueResultSet")
      .apply<cvflann::KNNUniqueResultSet<int>,
             cvflann::KNNUniqueResultSet<int64_t>,
             cvflann::KNNUniqueResultSet<uchar>,
             cvflann::KNNUniqueResultSet<short>,
             cvflann::KNNUniqueResultSet<ushort>,
             cvflann::KNNUniqueResultSet<float>,
             cvflann::KNNUniqueResultSet<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<unsigned int>()
            .method("addPoint",
                    [](WrappedT &instance, ValueT dist, int index) {
                      return instance.addPoint(dist, index);
                    })
            .method("clear",
                    [](WrappedT &instance) { return instance.clear(); });
      });
  mod.add_type<Parametric<TypeVar<1>>>("RadiusUniqueResultSet")
      .apply<cvflann::RadiusUniqueResultSet<int>,
             cvflann::RadiusUniqueResultSet<int64_t>,
             cvflann::RadiusUniqueResultSet<uchar>,
             cvflann::RadiusUniqueResultSet<short>,
             cvflann::RadiusUniqueResultSet<ushort>,
             cvflann::RadiusUniqueResultSet<float>,
             cvflann::RadiusUniqueResultSet<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<ValueT>()
            .method("addPoint",
                    [](WrappedT &instance, ValueT dist, int index) {
                      return instance.addPoint(dist, index);
                    })
            .method("clear",
                    [](WrappedT &instance) { return instance.clear(); })
            .method("full",
                    [](const WrappedT &instance) { return instance.full(); })
            .method("worstDist", [](const WrappedT &instance) {
              return instance.worstDist();
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("KNNRadiusUniqueResultSet")
      .apply<cvflann::KNNRadiusUniqueResultSet<int>,
             cvflann::KNNRadiusUniqueResultSet<int64_t>,
             cvflann::KNNRadiusUniqueResultSet<uchar>,
             cvflann::KNNRadiusUniqueResultSet<short>,
             cvflann::KNNRadiusUniqueResultSet<ushort>,
             cvflann::KNNRadiusUniqueResultSet<float>,
             cvflann::KNNRadiusUniqueResultSet<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<unsigned int, ValueT>().method(
            "clear", [](WrappedT &instance) { return instance.clear(); });
      });
  /*
mod.add_type<Parametric<TypeVar<1>>>("NNIndex")
  .apply<cvflann::NNIndex<L2_Simple<double>>, cvflann::NNIndex<L2<double>>,
         cvflann::NNIndex<L1<double>>,
cvflann::NNIndex<MinkowskiDistance<double>>, cvflann::NNIndex<MaxDistance>,
cvflann::NNIndex<HammingLUT>,
         cvflann::NNIndex<Hamming>,cvflann::NNIndex<Hamming2>

         >([](auto wrapped) {
    typedef typename decltype(wrapped)::type WrappedT;
    typedef typename get_template_type<WrappedT>::type ValueT;
    wrapped
        .method("buildIndex",
                [](WrappedT &instance) { return instance.buildIndex(); })
        .method("knnSearch",
                [](WrappedT &instance,
                   const cv::Matrix<cv::ElementType> &queries,
                   cv::Matrix<int> &indices, cv::Matrix<ValueT> &dists,
                   int knn, const cv::flann::SearchParams &params) {
                  return instance.knnSearch(queries, indices, dists, knn,
                                            params);
                })
        .method(
            "radiusSearch",
            [](WrappedT &instance, const cv::Matrix<cv::ElementType> &query,
               cv::Matrix<int> &indices, cv::Matrix<ValueT> &dists,
               float radius, const cv::flann::SearchParams &params) {
              return instance.radiusSearch(query, indices, dists, radius,
                                           params);
            })
        .method("saveIndex",
                [](WrappedT &instance, cv::FILE *stream) {
                  return instance.saveIndex(stream);
                })
        .method("loadIndex",
                [](WrappedT &instance, cv::FILE *stream) {
                  return instance.loadIndex(stream);
                })
        .method("size",
                [](const WrappedT &instance) { return instance.size(); })
        .method("veclen",
                [](const WrappedT &instance) { return instance.veclen(); })
        .method(
            "usedMemory",
            [](const WrappedT &instance) { return instance.usedMemory(); })
        .method("getType",
                [](const WrappedT &instance) { return instance.getType(); })
        .method("getParameters",
                [](const WrappedT &instance) {
                  return instance.getParameters();
                })
        .method(
            "findNeighbors",
            [](WrappedT &instance, cv::ResultSet<cv::DistanceType> &result,
               const cv::ElementType *vec,
               const cv::flann::SearchParams &searchParams) {
              return instance.findNeighbors(result, vec, searchParams);
            });
  });*/
  /*
  mod.add_type<Parametric<TypeVar<1>>>("Datatype")
      .apply<cvflann::Datatype<int>, cvflann::Datatype<int64_t>,
             cvflann::Datatype<uchar>, cvflann::Datatype<short>,
             cvflann::Datatype<ushort>, cvflann::Datatype<float>,
             cvflann::Datatype<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<cvflann::Datatype>("Datatype")
      .method("type",
              [](cvflann::Datatype &instance) { return instance.type(); });
  mod.add_type<cvflann::Datatype>("Datatype")
      .method("type",
              [](cvflann::Datatype &instance) { return instance.type(); });
  mod.add_type<cvflann::Datatype>("Datatype")
      .method("type",
              [](cvflann::Datatype &instance) { return instance.type(); });
  mod.add_type<cvflann::Datatype>("Datatype")
      .method("type",
              [](cvflann::Datatype &instance) { return instance.type(); });
  mod.add_type<cvflann::Datatype>("Datatype")
      .method("type",
              [](cvflann::Datatype &instance) { return instance.type(); });
  mod.add_type<cvflann::Datatype>("Datatype")
      .method("type",
              [](cvflann::Datatype &instance) { return instance.type(); });
  mod.add_type<cvflann::Datatype>("Datatype")
      .method("type",
              [](cvflann::Datatype &instance) { return instance.type(); });
  mod.add_type<cvflann::Datatype>("Datatype")
      .method("type",
              [](cvflann::Datatype &instance) { return instance.type(); });
  mod.add_type<cvflann::IndexHeader>("IndexHeader")
      .method("signature",
              [](const cvflann::IndexHeader &instance) {
                return instance.signature;
              })
      .method(
          "version",
          [](const cvflann::IndexHeader &instance) { return instance.version; })
      .method("data_type",
              [](const cvflann::IndexHeader &instance) {
                return instance.data_type;
              })
      .method("index_type",
              [](const cvflann::IndexHeader &instance) {
                return instance.index_type;
              })
      .method(
          "rows",
          [](const cvflann::IndexHeader &instance) { return instance.rows; })
      .method("cols", [](const cvflann::IndexHeader &instance) {
        return instance.cols;
      });
      */
  mod.add_type<Parametric<TypeVar<1>>>("Accumulator")
      .apply<cvflann::Accumulator<int>, cvflann::Accumulator<int64_t>,
             cvflann::Accumulator<uchar>, cvflann::Accumulator<short>,
             cvflann::Accumulator<ushort>, cvflann::Accumulator<float>,
             cvflann::Accumulator<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  // mod.add_type<cvflann::Accumulator>("Accumulator");
  // mod.add_type<cvflann::Accumulator>("Accumulator");
  // mod.add_type<cvflann::Accumulator>("Accumulator");
  // mod.add_type<cvflann::Accumulator>("Accumulator");
  // mod.add_type<cvflann::Accumulator>("Accumulator");
  // mod.add_type<cvflann::Accumulator>("Accumulator");
  mod.add_type<Parametric<TypeVar<1>>>("L2_Simple")
      .apply<cvflann::L2_Simple<int>, cvflann::L2_Simple<int64_t>,
             cvflann::L2_Simple<uchar>, cvflann::L2_Simple<short>,
             cvflann::L2_Simple<ushort>, cvflann::L2_Simple<float>,
             cvflann::L2_Simple<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("L2")
      .apply<cvflann::L2<int>, cvflann::L2<int64_t>, cvflann::L2<uchar>,
             cvflann::L2<short>, cvflann::L2<ushort>, cvflann::L2<float>,
             cvflann::L2<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("L1")
      .apply<cvflann::L1<int>, cvflann::L1<int64_t>, cvflann::L1<uchar>,
             cvflann::L1<short>, cvflann::L1<ushort>, cvflann::L1<float>,
             cvflann::L1<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("MinkowskiDistance")
      .apply<
          cvflann::MinkowskiDistance<int>, cvflann::MinkowskiDistance<int64_t>,
          cvflann::MinkowskiDistance<uchar>, cvflann::MinkowskiDistance<short>,
          cvflann::MinkowskiDistance<ushort>, cvflann::MinkowskiDistance<float>,
          cvflann::MinkowskiDistance<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("order",
                    [](const WrappedT &instance) { return instance.order; })
            .template constructor<int>();
      });
  mod.add_type<Parametric<TypeVar<1>>>("MaxDistance")
      .apply<cvflann::MaxDistance<int>, cvflann::MaxDistance<int64_t>,
             cvflann::MaxDistance<uchar>, cvflann::MaxDistance<short>,
             cvflann::MaxDistance<ushort>, cvflann::MaxDistance<float>,
             cvflann::MaxDistance<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<cvflann::HammingLUT>("HammingLUT")
      .method([](cvflann::HammingLUT &instance, const unsigned char *a,
                 const unsigned char *b,
                 size_t size) { return instance.operator()(a, b, size); });
  mod.add_type<Parametric<TypeVar<1>>>("Hamming")
      .apply<cvflann::Hamming<int>, cvflann::Hamming<int64_t>,
             cvflann::Hamming<uchar>, cvflann::Hamming<short>,
             cvflann::Hamming<ushort>, cvflann::Hamming<float>,
             cvflann::Hamming<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("Hamming2")
      .apply<cvflann::Hamming2<int>, cvflann::Hamming2<int64_t>,
             cvflann::Hamming2<uchar>, cvflann::Hamming2<short>,
             cvflann::Hamming2<ushort>, cvflann::Hamming2<float>,
             cvflann::Hamming2<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("popcnt32",
                    [](WrappedT &instance, cv::uint32_t n) {
                      return instance.popcnt32(n);
                    })
            .method("popcnt64", [](WrappedT &instance, cv::uint64_t n) {
              return instance.popcnt64(n);
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("HistIntersectionDistance")
      .apply<cvflann::HistIntersectionDistance<int>,
             cvflann::HistIntersectionDistance<int64_t>,
             cvflann::HistIntersectionDistance<uchar>,
             cvflann::HistIntersectionDistance<short>,
             cvflann::HistIntersectionDistance<ushort>,
             cvflann::HistIntersectionDistance<float>,
             cvflann::HistIntersectionDistance<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("HellingerDistance")
      .apply<
          cvflann::HellingerDistance<int>, cvflann::HellingerDistance<int64_t>,
          cvflann::HellingerDistance<uchar>, cvflann::HellingerDistance<short>,
          cvflann::HellingerDistance<ushort>, cvflann::HellingerDistance<float>,
          cvflann::HellingerDistance<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("ChiSquareDistance")
      .apply<
          cvflann::ChiSquareDistance<int>, cvflann::ChiSquareDistance<int64_t>,
          cvflann::ChiSquareDistance<uchar>, cvflann::ChiSquareDistance<short>,
          cvflann::ChiSquareDistance<ushort>, cvflann::ChiSquareDistance<float>,
          cvflann::ChiSquareDistance<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("KL_Divergence")
      .apply<cvflann::KL_Divergence<int>, cvflann::KL_Divergence<int64_t>,
             cvflann::KL_Divergence<uchar>, cvflann::KL_Divergence<short>,
             cvflann::KL_Divergence<ushort>, cvflann::KL_Divergence<float>,
             cvflann::KL_Divergence<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("ZeroIterator")
      .apply<cvflann::ZeroIterator<int>, cvflann::ZeroIterator<int64_t>,
             cvflann::ZeroIterator<uchar>, cvflann::ZeroIterator<short>,
             cvflann::ZeroIterator<ushort>, cvflann::ZeroIterator<float>,
             cvflann::ZeroIterator<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("operator*",
                    [](WrappedT &instance) { return instance.operator*(); })
            .method("operator[]", [](WrappedT &instance,
                                     int) { return instance.operator[](); })
            .method("operator++",
                    [](WrappedT &instance) { return instance.operator++(); })
            .method("operator++", [](WrappedT &instance,
                                     int) { return instance.operator++(); })
            .method("operator+=", [](WrappedT &instance, int) {
              return instance.operator+=();
            });
      });
  /*
mod.add_type<Parametric<TypeVar<1>>>("squareDistance")
  .apply<cvflann::squareDistance<int, int>,
         cvflann::squareDistance<uint64_t, uint64_t>,
         cvflann::squareDistance<int, uchar>,
         cvflann::squareDistance<int, short>,
         cvflann::squareDistance<int, ushort>,
         cvflann::squareDistance<float, float>,
         cvflann::squareDistance<double, double>>([](auto wrapped) {
    typedef typename decltype(wrapped)::type WrappedT;
    typedef typename get_template_type<WrappedT>::type ValueT;
    wrapped.method([](WrappedT &instance, cv::ResultType dist) {
      return instance.operator()(dist);
    });
  });*/
  /*
  mod.add_type<Parametric<TypeVar<1>>>("simpleDistance")
      .apply<cvflann::simpleDistance<int>, cvflann::simpleDistance<int64_t>,
             cvflann::simpleDistance<uchar>, cvflann::simpleDistance<short>,
             cvflann::simpleDistance<ushort>, cvflann::simpleDistance<float>,
             cvflann::simpleDistance<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.method([](WrappedT &instance, cv::ResultType dist) {
          return instance.operator()(dist);
        });
      });*/
  mod.add_type<cvflann::DynamicBitset>("DynamicBitset")
      .constructor<size_t>()
      .method("clear",
              [](cvflann::DynamicBitset &instance) { return instance.clear(); })
      .method("empty",
              [](cvflann::DynamicBitset &instance) { return instance.empty(); })
      .method("reset",
              [](cvflann::DynamicBitset &instance) { return instance.reset(); })
      .method("reset", [](cvflann::DynamicBitset &instance,
                          size_t index) { return instance.reset(index); })
      .method("reset_block",
              [](cvflann::DynamicBitset &instance, size_t index) {
                return instance.reset_block(index);
              })
      .method("resize", [](cvflann::DynamicBitset &instance,
                           size_t sz) { return instance.resize(sz); })
      .method("set", [](cvflann::DynamicBitset &instance,
                        size_t index) { return instance.set(index); })
      .method("size",
              [](const cvflann::DynamicBitset &instance) {
                return instance.size();
              })
      .method("test", [](cvflann::DynamicBitset &instance, size_t index) {
        return instance.test(index);
      });
  mod.add_type<Parametric<TypeVar<1>>>("Heap")
      .apply<cvflann::Heap<int>, cvflann::Heap<int64_t>, cvflann::Heap<uchar>,
             cvflann::Heap<short>, cvflann::Heap<ushort>, cvflann::Heap<float>,
             cvflann::Heap<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method("heap",
                    [](const WrappedT &instance) { return instance.heap; })
            .method("length",
                    [](const WrappedT &instance) { return instance.length; })
            .method("count",
                    [](const WrappedT &instance) { return instance.count; })
            .template constructor<int>()
            .method("size", [](WrappedT &instance) { return instance.size(); })
            .method("empty",
                    [](WrappedT &instance) { return instance.empty(); })
            .method("clear",
                    [](WrappedT &instance) { return instance.clear(); })
            .method("insert",
                    [](WrappedT &instance, ValueT value) {
                      return instance.insert(value);
                    })
            .method("popMin", [](WrappedT &instance, ValueT &value) {
              return instance.popMin(value);
            });
      });
  mod.add_type<cvflann::PooledAllocator>("PooledAllocator")
      /*.method("remaining",
              [](const cvflann::PooledAllocator &instance) {
                return instance.remaining;
              })
      .method("base",
              [](const cvflann::PooledAllocator &instance) {
                return instance.base;
              })
      .method(
          "loc",
          [](const cvflann::PooledAllocator &instance) { return instance.loc; })
      .method("blocksize",
              [](const cvflann::PooledAllocator &instance) {
                return instance.blocksize;
              })*/
      .method("usedMemory",
              [](const cvflann::PooledAllocator &instance) {
                return instance.usedMemory;
              })
      .method("wastedMemory",
              [](const cvflann::PooledAllocator &instance) {
                return instance.wastedMemory;
              })
      .constructor<int>()
      .method("allocateMemory",
              [](cvflann::PooledAllocator &instance, int size) {
                return instance.allocateMemory(size);
              });
  mod.add_type<cvflann::UniqueRandom>("UniqueRandom")
      /*.method(
          "vals_",
          [](const cvflann::UniqueRandom &instance) { return instance.vals_; })
      .method(
          "size_",
          [](const cvflann::UniqueRandom &instance) { return instance.size_; })
      .method("counter_",
              [](const cvflann::UniqueRandom &instance) {
                return instance.counter_;
              })*/
      .constructor<int>()
      .method("init", [](cvflann::UniqueRandom &instance,
                         int n) { return instance.init(n); })
      .method("next",
              [](cvflann::UniqueRandom &instance) { return instance.next(); });
  mod.add_type<cvflann::KDTreeIndexParams>("KDTreeIndexParams")
      .constructor<int>();
  /*mod.add_type<Parametric<TypeVar<1>>>("KDTreeIndex")
      .apply<cvflann::KDTreeIndex<int>, cvflann::KDTreeIndex<int64_t>,
             cvflann::KDTreeIndex<uchar>, cvflann::KDTreeIndex<short>,
             cvflann::KDTreeIndex<ushort>, cvflann::KDTreeIndex<float>,
             cvflann::KDTreeIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<
                const Matrix<typename WrappedT::ElementType> &,
                const cv::flann::IndexParams &, ValueT>()
            .template constructor<const KDTreeIndex<ValueT> &>()
            .method("operator=",
                    [](WrappedT &instance, const cv::KDTreeIndex &) {
                      return instance.operator=();
                    })
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("getType",
                    [](const WrappedT &instance) { return instance.getType(); })
            .method("saveIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.saveIndex(stream);
                    })
            .method("loadIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.loadIndex(stream);
                    })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("veclen",
                    [](const WrappedT &instance) { return instance.veclen(); })
            .method("usedMemory",
                    [](WrappedT &instance) { return instance.usedMemory(); })
            .method(
                "findNeighbors",
                [](WrappedT &instance, cv::ResultSet<cv::DistanceType> &result,
                   const cv::ElementType *vec,
                   const cv::flann::SearchParams &searchParams) {
                  return instance.findNeighbors(result, vec, searchParams);
                })
            .method("getParameters", [](const WrappedT &instance) {
              return instance.getParameters();
            });
      });*/
  mod.add_type<cvflann::KDTreeSingleIndexParams>("KDTreeSingleIndexParams")
      .constructor<int, bool, int>();
  /*mod.add_type<Parametric<TypeVar<1>>>("KDTreeSingleIndex")
      .apply<
          cvflann::KDTreeSingleIndex<int>, cvflann::KDTreeSingleIndex<int64_t>,
          cvflann::KDTreeSingleIndex<uchar>, cvflann::KDTreeSingleIndex<short>,
          cvflann::KDTreeSingleIndex<ushort>, cvflann::KDTreeSingleIndex<float>,
          cvflann::KDTreeSingleIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<
                const Matrix<typename WrappedT::ElementType> &,
                const cv::flann::IndexParams &, ValueT>()
            .template constructor<const KDTreeSingleIndex<ValueT> &>()
            .method("operator=",
                    [](WrappedT &instance, const cv::KDTreeSingleIndex &) {
                      return instance.operator=();
                    })
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("getType",
                    [](const WrappedT &instance) { return instance.getType(); })
            .method("saveIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.saveIndex(stream);
                    })
            .method("loadIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.loadIndex(stream);
                    })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("veclen",
                    [](const WrappedT &instance) { return instance.veclen(); })
            .method("usedMemory",
                    [](WrappedT &instance) { return instance.usedMemory(); })
            .method("knnSearch",
                    [](WrappedT &instance,
                       const cv::Matrix<cv::ElementType> &queries,
                       cv::Matrix<int> &indices,
                       cv::Matrix<cv::DistanceType> &dists, int knn,
                       const cv::flann::SearchParams &params) {
                      return instance.knnSearch(queries, indices, dists, knn,
                                                params);
                    })
            .method("getParameters",
                    [](const WrappedT &instance) {
                      return instance.getParameters();
                    })
            .method(
                "findNeighbors",
                [](WrappedT &instance, cv::ResultSet<cv::DistanceType> &result,
                   const cv::ElementType *vec,
                   const cv::flann::SearchParams &searchParams) {
                  return instance.findNeighbors(result, vec, searchParams);
                });
      });*/
  mod.add_type<cvflann::Logger>("Logger")
      /*.method("instance",
              [](cvflann::Logger &instance) { return instance.instance(); })
      .method("_setDestination",
              [](cvflann::Logger &instance, const char *name) {
                return instance._setDestination(name);
              })
      .method("_log",
              [](cvflann::Logger &instance, int level, const char *fmt,
                 cv::va_list arglist) {
                return instance._log(level, fmt, arglist);
              })*/
      .method("setLevel", [](cvflann::Logger &instance,
                             int level) { return instance.setLevel(level); })
      .method("setDestination",
              [](cvflann::Logger &instance, const char *name) {
                return instance.setDestination(name);
              })
      .method("log", [](cvflann::Logger &instance, int level,
                        const char *fmt) { return instance.log(level, fmt); })
      //.method("fatal",
      //        [](cvflann::Logger &instance) { return instance.fatal(); })
      .method("fatal", [](cvflann::Logger &instance,
                          const char *fmt) { return instance.fatal(fmt); })
      //.method("error",
      //        [](cvflann::Logger &instance) { return instance.error(); })
      .method("error", [](cvflann::Logger &instance,
                          const char *fmt) { return instance.error(fmt); })
      //.method("warn", [](cvflann::Logger &instance) { return instance.warn();
      //})
      .method("warn", [](cvflann::Logger &instance,
                         const char *fmt) { return instance.warn(fmt); })
      //.method("info", [](cvflann::Logger &instance) { return instance.info();
      //})
      .method("info", [](cvflann::Logger &instance, const char *fmt) {
        return instance.info(fmt);
      });
  mod.add_type<cvflann::KMeansIndexParams>("KMeansIndexParams")
      .constructor<int, int, cvflann::flann_centers_init_t, float>();
  mod.add_type<Parametric<TypeVar<1>>>("KMeansIndex")
      .apply<cvflann::KMeansIndex<int>, cvflann::KMeansIndex<int64_t>,
             cvflann::KMeansIndex<uchar>, cvflann::KMeansIndex<short>,
             cvflann::KMeansIndex<ushort>, cvflann::KMeansIndex<float>,
             cvflann::KMeansIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .method(
                "chooseCenters",
                [](const WrappedT &instance) { return instance.chooseCenters; })
            .method("chooseCentersRandom",
                    [](WrappedT &instance, int k, int *indices,
                       int indices_length, int *centers, int &centers_length) {
                      return instance.chooseCentersRandom(
                          k, indices, indices_length, centers, centers_length);
                    })
            .method("chooseCentersGonzales",
                    [](WrappedT &instance, int k, int *indices,
                       int indices_length, int *centers, int &centers_length) {
                      return instance.chooseCentersGonzales(
                          k, indices, indices_length, centers, centers_length);
                    })
            .method("chooseCentersKMeanspp",
                    [](WrappedT &instance, int k, int *indices,
                       int indices_length, int *centers, int &centers_length) {
                      return instance.chooseCentersKMeanspp(
                          k, indices, indices_length, centers, centers_length);
                    })
            .method("getType",
                    [](const WrappedT &instance) { return instance.getType(); })
            .template constructor<
                const cvflann::Matrix<typename WrappedT::ElementType> &,
                const cv::flann::IndexParams &, ValueT>()
            .template constructor<const WrappedT &>()
            .method("operator=",
                    [](WrappedT &instance, const WrappedT &other) {
                      return instance.operator=(other);
                    })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("veclen",
                    [](const WrappedT &instance) { return instance.veclen(); })
            .method("set_cb_index",
                    [](WrappedT &instance, float index) {
                      return instance.set_cb_index(index);
                    })
            .method(
                "usedMemory",
                [](const WrappedT &instance) { return instance.usedMemory(); })
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("saveIndex",
                    [](WrappedT &instance, FILE *stream) {
                      return instance.saveIndex(stream);
                    })
            .method("loadIndex",
                    [](WrappedT &instance, FILE *stream) {
                      return instance.loadIndex(stream);
                    })
            .method("findNeighbors",
                    [](WrappedT &instance, cv::ResultSet<ValueT> &result,
                       const cv::ElementType *vec,
                       const cv::flann::SearchParams &searchParams) {
                      return instance.findNeighbors(result, vec, searchParams);
                    })
            .method(
                "getClusterCenters",
                [](WrappedT &instance, cv::Matrix<cv::DistanceType> &centers) {
                  return instance.getClusterCenters(centers);
                })
            .method("getParameters", [](const WrappedT &instance) {
              return instance.getParameters();
            });
      });
  mod.add_type<cvflann::CompositeIndexParams>("CompositeIndexParams")
      .constructor<int, int, int, cvflann::flann_centers_init_t, float>();
  mod.add_type<Parametric<TypeVar<1>>>("CompositeIndex")
      .apply<cvflann::CompositeIndex<int>, cvflann::CompositeIndex<int64_t>,
             cvflann::CompositeIndex<uchar>, cvflann::CompositeIndex<short>,
             cvflann::CompositeIndex<ushort>, cvflann::CompositeIndex<float>,
             cvflann::CompositeIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<
                const cvflann::Matrix<typename WrappedT::ElementType> &,
                const cv::flann::IndexParams &, ValueT>()
            .template constructor<const cvflann::CompositeIndex<ValueT> &>()
            .method("operator=",
                    [](WrappedT &instance, const cvflann::CompositeIndex &) {
                      return instance.operator=();
                    })
            .method("getType",
                    [](const WrappedT &instance) { return instance.getType(); })
            .method("size", [](WrappedT &instance) { return instance.size(); })
            .method("veclen",
                    [](WrappedT &instance) { return instance.veclen(); })
            .method("usedMemory",
                    [](WrappedT &instance) { return instance.usedMemory(); })
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("saveIndex",
                    [](WrappedT &instance, FILE *stream) {
                      return instance.saveIndex(stream);
                    })
            .method("loadIndex",
                    [](WrappedT &instance, FILE *stream) {
                      return instance.loadIndex(stream);
                    })
            .method("getParameters",
                    [](const WrappedT &instance) {
                      return instance.getParameters();
                    })
            .method("findNeighbors",
                    [](WrappedT &instance, cv::ResultSet<ValueT> &result,
                       const cv::ElementType *vec,
                       const cv::flann::SearchParams &searchParams) {
                      return instance.findNeighbors(result, vec, searchParams);
                    });
      });
  mod.add_type<cvflann::LinearIndexParams>("LinearIndexParams");
  mod.add_type<Parametric<TypeVar<1>>>("LinearIndex")
      .apply<cvflann::LinearIndex<int>, cvflann::LinearIndex<int64_t>,
             cvflann::LinearIndex<uchar>, cvflann::LinearIndex<short>,
             cvflann::LinearIndex<ushort>, cvflann::LinearIndex<float>,
             cvflann::LinearIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<
                const Matrix<typename WrappedT::ElementType> &,
                const cv::flann::IndexParams &, ValueT>()
            .template constructor<const LinearIndex<ValueT> &>()
            .method("operator=",
                    [](WrappedT &instance, const cv::LinearIndex &) {
                      return instance.operator=();
                    })
            .method("getType",
                    [](const WrappedT &instance) { return instance.getType(); })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("veclen",
                    [](const WrappedT &instance) { return instance.veclen(); })
            .method(
                "usedMemory",
                [](const WrappedT &instance) { return instance.usedMemory(); })
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("saveIndex",
                    [](WrappedT &instance) { return instance.saveIndex(); })
            .method("loadIndex",
                    [](WrappedT &instance) { return instance.loadIndex(); })
            .method("findNeighbors",
                    [](WrappedT &instance,
                       cv::ResultSet<cv::DistanceType> &resultSet,
                       const cv::ElementType *vec,
                       const cv::flann::SearchParams &) {
                      return instance.findNeighbors(resultSet, vec, );
                    })
            .method("getParameters", [](const WrappedT &instance) {
              return instance.getParameters();
            });
      });
  mod.add_type<cvflann::HierarchicalClusteringIndexParams>(
         "HierarchicalClusteringIndexParams")
      .constructor<int, cvflann::flann_centers_init_t, int, int>();
  mod.add_type<Parametric<TypeVar<1>>>("HierarchicalClusteringIndex")
      .apply<cvflann::HierarchicalClusteringIndex<int>,
             cvflann::HierarchicalClusteringIndex<int64_t>,
             cvflann::HierarchicalClusteringIndex<uchar>,
             cvflann::HierarchicalClusteringIndex<short>,
             cvflann::HierarchicalClusteringIndex<ushort>,
             cvflann::HierarchicalClusteringIndex<float>,
             cvflann::HierarchicalClusteringIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<
                const Matrix<typename WrappedT::ElementType> &,
                const cv::flann::IndexParams &, ValueT>()
            .template constructor<const HierarchicalClusteringIndex<ValueT> &>()
            .method("operator=",
                    [](WrappedT &instance,
                       const cv::HierarchicalClusteringIndex &) {
                      return instance.operator=();
                    })
            .method("free_elements",
                    [](WrappedT &instance) { return instance.free_elements(); })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("veclen",
                    [](const WrappedT &instance) { return instance.veclen(); })
            .method(
                "usedMemory",
                [](const WrappedT &instance) { return instance.usedMemory(); })
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("getType",
                    [](const WrappedT &instance) { return instance.getType(); })
            .method("saveIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.saveIndex(stream);
                    })
            .method("loadIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.loadIndex(stream);
                    })
            .method(
                "findNeighbors",
                [](WrappedT &instance, cv::ResultSet<cv::DistanceType> &result,
                   const cv::ElementType *vec,
                   const cv::flann::SearchParams &searchParams) {
                  return instance.findNeighbors(result, vec, searchParams);
                })
            .method("getParameters", [](const WrappedT &instance) {
              return instance.getParameters();
            });
      });
  mod.add_type<cvflann::lsh::LshStats>("LshStats")
      .method("bucket_sizes_",
              [](const cvflann::lsh::LshStats &instance) {
                return instance.bucket_sizes_;
              })
      .method("n_buckets_",
              [](const cvflann::lsh::LshStats &instance) {
                return instance.n_buckets_;
              })
      .method("bucket_size_mean_",
              [](const cvflann::lsh::LshStats &instance) {
                return instance.bucket_size_mean_;
              })
      .method("bucket_size_median_",
              [](const cvflann::lsh::LshStats &instance) {
                return instance.bucket_size_median_;
              })
      .method("bucket_size_min_",
              [](const cvflann::lsh::LshStats &instance) {
                return instance.bucket_size_min_;
              })
      .method("bucket_size_max_",
              [](const cvflann::lsh::LshStats &instance) {
                return instance.bucket_size_max_;
              })
      .method("bucket_size_std_dev",
              [](const cvflann::lsh::LshStats &instance) {
                return instance.bucket_size_std_dev;
              })
      .method("size_histogram_", [](const cvflann::lsh::LshStats &instance) {
        return instance.size_histogram_;
      });
  mod.add_type<Parametric<TypeVar<1>>>("LshTable")
      .apply<cvflann::lsh::LshTable<int>, cvflann::lsh::LshTable<int64_t>,
             cvflann::lsh::LshTable<uchar>, cvflann::lsh::LshTable<short>,
             cvflann::lsh::LshTable<ushort>, cvflann::lsh::LshTable<float>,
             cvflann::lsh::LshTable<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<unsigned int, unsigned int>()
            .method("add",
                    [](WrappedT &instance, unsigned value,
                       const cv::ElementType *feature) {
                      return instance.add(value, feature);
                    })
            .method(
                "add",
                [](WrappedT &instance, cv::Matrix<cv::ElementType> dataset) {
                  return instance.add(dataset);
                })
            .method("getBucketFromKey",
                    [](WrappedT &instance, cv::BucketKey key) {
                      return instance.getBucketFromKey(key);
                    })
            .method("getKey",
                    [](WrappedT &instance, const cv::ElementType *) {
                      return instance.getKey();
                    })
            .method("getStats", [](const WrappedT &instance) {
              return instance.getStats();
            });
      });
  mod.add_type<cvflann::LshIndexParams>("LshIndexParams")
      .constructor<unsigned int, unsigned int, unsigned int>();
  mod.add_type<Parametric<TypeVar<1>>>("LshIndex")
      .apply<cvflann::LshIndex<int>, cvflann::LshIndex<int64_t>,
             cvflann::LshIndex<uchar>, cvflann::LshIndex<short>,
             cvflann::LshIndex<ushort>, cvflann::LshIndex<float>,
             cvflann::LshIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<
                const Matrix<typename WrappedT::ElementType> &,
                const cv::flann::IndexParams &, ValueT>()
            .template constructor<const LshIndex<ValueT> &>()
            .method("operator=",
                    [](WrappedT &instance, const cv::LshIndex &) {
                      return instance.operator=();
                    })
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("getType",
                    [](const WrappedT &instance) { return instance.getType(); })
            .method("saveIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.saveIndex(stream);
                    })
            .method("loadIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.loadIndex(stream);
                    })
            .method("size",
                    [](const WrappedT &instance) { return instance.size(); })
            .method("veclen",
                    [](const WrappedT &instance) { return instance.veclen(); })
            .method("usedMemory",
                    [](WrappedT &instance) { return instance.usedMemory(); })
            .method("getParameters",
                    [](const WrappedT &instance) {
                      return instance.getParameters();
                    })
            .method("knnSearch",
                    [](WrappedT &instance,
                       const cv::Matrix<cv::ElementType> &queries,
                       cv::Matrix<int> &indices,
                       cv::Matrix<cv::DistanceType> &dists, int knn,
                       const cv::flann::SearchParams &params) {
                      return instance.knnSearch(queries, indices, dists, knn,
                                                params);
                    })
            .method("findNeighbors", [](WrappedT &instance,
                                        cv::ResultSet<cv::DistanceType> &result,
                                        const cv::ElementType *vec,
                                        const cv::flann::SearchParams &) {
              return instance.findNeighbors(result, vec, );
            });
      });
  mod.add_type<cvflann::StartStopTimer>("StartStopTimer")
      .method("startTime",
              [](const cvflann::StartStopTimer &instance) {
                return instance.startTime;
              })
      .method("value",
              [](const cvflann::StartStopTimer &instance) {
                return instance.value;
              })
      .method(
          "start",
          [](cvflann::StartStopTimer &instance) { return instance.start(); })
      .method("stop",
              [](cvflann::StartStopTimer &instance) { return instance.stop(); })
      .method("reset", [](cvflann::StartStopTimer &instance) {
        return instance.reset();
      });
  mod.add_type<cvflann::AutotunedIndexParams>("AutotunedIndexParams")
      .constructor<float, float, float, float>();
  mod.add_type<Parametric<TypeVar<1>>>("AutotunedIndex")
      .apply<cvflann::AutotunedIndex<int>, cvflann::AutotunedIndex<int64_t>,
             cvflann::AutotunedIndex<uchar>, cvflann::AutotunedIndex<short>,
             cvflann::AutotunedIndex<ushort>, cvflann::AutotunedIndex<float>,
             cvflann::AutotunedIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<
                const Matrix<typename WrappedT::ElementType> &,
                const cv::flann::IndexParams &, ValueT>()
            .template constructor<const AutotunedIndex<ValueT> &>()
            .method("operator=",
                    [](WrappedT &instance, const cv::AutotunedIndex &) {
                      return instance.operator=();
                    })
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("saveIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.saveIndex(stream);
                    })
            .method("loadIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.loadIndex(stream);
                    })
            .method(
                "findNeighbors",
                [](WrappedT &instance, cv::ResultSet<cv::DistanceType> &result,
                   const cv::ElementType *vec,
                   const cv::flann::SearchParams &searchParams) {
                  return instance.findNeighbors(result, vec, searchParams);
                })
            .method("getParameters",
                    [](WrappedT &instance) { return instance.getParameters(); })
            .method("getSearchParameters",
                    [](const WrappedT &instance) {
                      return instance.getSearchParameters();
                    })
            .method(
                "getSpeedup",
                [](const WrappedT &instance) { return instance.getSpeedup(); })
            .method("size", [](WrappedT &instance) { return instance.size(); })
            .method("veclen",
                    [](WrappedT &instance) { return instance.veclen(); })
            .method("usedMemory",
                    [](WrappedT &instance) { return instance.usedMemory(); })
            .method("getType", [](const WrappedT &instance) {
              return instance.getType();
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("index_creator")
      .apply<cvflann::index_creator<int>, cvflann::index_creator<int64_t>,
             cvflann::index_creator<uchar>, cvflann::index_creator<short>,
             cvflann::index_creator<ushort>, cvflann::index_creator<float>,
             cvflann::index_creator<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.method("create", [](WrappedT &instance,
                                    const cv::Matrix<typename> &dataset,
                                    const cv::flann::IndexParams &params,
                                    const cv::Distance &distance) {
          return instance.create(dataset, params, distance);
        });
      });
  mod.add_type<cvflann::SavedIndexParams>("SavedIndexParams")
      .constructor<cv::String>();
  mod.add_type<Parametric<TypeVar<1>>>("Index")
      .apply<cvflann::Index<int>, cvflann::Index<int64_t>,
             cvflann::Index<uchar>, cvflann::Index<short>,
             cvflann::Index<ushort>, cvflann::Index<float>,
             cvflann::Index<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<
                const Matrix<typename WrappedT::ElementType> &,
                const typename WrappedTParams &, ValueT>()
            .method("buildIndex",
                    [](WrappedT &instance) { return instance.buildIndex(); })
            .method("save",
                    [](WrappedT &instance, cv::String filename) {
                      return instance.save(filename);
                    })
            .method("saveIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.saveIndex(stream);
                    })
            .method("loadIndex",
                    [](WrappedT &instance, cv::FILE *stream) {
                      return instance.loadIndex(stream);
                    })
            .method("veclen",
                    [](WrappedT &instance) { return instance.veclen(); })
            .method("size", [](WrappedT &instance) { return instance.size(); })
            .method("getType",
                    [](WrappedT &instance) { return instance.getType(); })
            .method("usedMemory",
                    [](WrappedT &instance) { return instance.usedMemory(); })
            .method("getParameters",
                    [](WrappedT &instance) { return instance.getParameters(); })
            .method("knnSearch",
                    [](WrappedT &instance,
                       const cv::Matrix<cv::ElementType> &queries,
                       cv::Matrix<int> &indices,
                       cv::Matrix<cv::DistanceType> &dists, int knn,
                       const cv::flann::SearchParams &params) {
                      return instance.knnSearch(queries, indices, dists, knn,
                                                params);
                    })
            .method(
                "radiusSearch",
                [](WrappedT &instance, const cv::Matrix<cv::ElementType> &query,
                   cv::Matrix<int> &indices,
                   cv::Matrix<cv::DistanceType> &dists, float radius,
                   const cv::flann::SearchParams &params) {
                  return instance.radiusSearch(query, indices, dists, radius,
                                               params);
                })
            .method(
                "findNeighbors",
                [](WrappedT &instance, cv::ResultSet<cv::DistanceType> &result,
                   const cv::ElementType *vec,
                   const cv::flann::SearchParams &searchParams) {
                  return instance.findNeighbors(result, vec, searchParams);
                })
            .method("getIndex",
                    [](WrappedT &instance) { return instance.getIndex(); })
            .method("getIndexParameters", [](WrappedT &instance) {
              return instance.getIndexParameters();
            });
      });
  mod.method("flann_distance_type",
             []() { return cvflann::flann_distance_type(); });
  mod.method("set_distance_type",
             [](cv::flann_distance_t distance_type, int order) {
               return cvflann::set_distance_type(distance_type, order);
             });
  mod.add_type<Parametric<TypeVar<1>>>("CvType")
      .apply<cv::flann::CvType<int>, cv::flann::CvType<int64_t>,
             cv::flann::CvType<uchar>, cv::flann::CvType<short>,
             cv::flann::CvType<ushort>, cv::flann::CvType<float>,
             cv::flann::CvType<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<cv::flann::CvType>("CvType").method(
      "type", [](cv::flann::CvType &instance) { return instance.type(); });
  mod.add_type<cv::flann::CvType>("CvType").method(
      "type", [](cv::flann::CvType &instance) { return instance.type(); });
  mod.add_type<cv::flann::CvType>("CvType").method(
      "type", [](cv::flann::CvType &instance) { return instance.type(); });
  mod.add_type<cv::flann::CvType>("CvType").method(
      "type", [](cv::flann::CvType &instance) { return instance.type(); });
  mod.add_type<cv::flann::CvType>("CvType").method(
      "type", [](cv::flann::CvType &instance) { return instance.type(); });
  mod.add_type<cv::flann::CvType>("CvType").method(
      "type", [](cv::flann::CvType &instance) { return instance.type(); });
  mod.add_type<cv::flann::CvType>("CvType").method(
      "type", [](cv::flann::CvType &instance) { return instance.type(); });
  mod.add_type<Parametric<TypeVar<1>>>("GenericIndex")
      .apply<cv::flann::GenericIndex<int>, cv::flann::GenericIndex<int64_t>,
             cv::flann::GenericIndex<uchar>, cv::flann::GenericIndex<short>,
             cv::flann::GenericIndex<ushort>, cv::flann::GenericIndex<float>,
             cv::flann::GenericIndex<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<const cv::Mat &,
                                  const ::cv::flann::IndexParams &, ValueT>()
            .method("knnSearch",
                    [](WrappedT &instance,
                       const std::vector<cv::ElementType> &query,
                       std::vector<int> &indices,
                       std::vector<cv::DistanceType> &dists, int knn,
                       const ::cvflann::SearchParams &params) {
                      return instance.knnSearch(query, indices, dists, knn,
                                                params);
                    })
            .method("radiusSearch",
                    [](WrappedT &instance,
                       const std::vector<cv::ElementType> &query,
                       std::vector<int> &indices,
                       std::vector<cv::DistanceType> &dists,
                       cv::DistanceType radius,
                       const ::cvflann::SearchParams &params) {
                      return instance.radiusSearch(query, indices, dists,
                                                   radius, params);
                    })
            .method("save",
                    [](WrappedT &instance, cv::String filename) {
                      return instance.save(filename);
                    })
            .method("veclen",
                    [](WrappedT &instance) { return instance.veclen(); })
            .method("size", [](WrappedT &instance) { return instance.size(); })
            .method("getParameters",
                    [](WrappedT &instance) { return instance.getParameters(); })
            .method("getIndexParameters", [](WrappedT &instance) {
              return instance.getIndexParameters();
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("Index_")
      .apply<cv::flann::Index_<int>, cv::flann::Index_<int64_t>,
             cv::flann::Index_<uchar>, cv::flann::Index_<short>,
             cv::flann::Index_<ushort>, cv::flann::Index_<float>,
             cv::flann::Index_<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped
            .template constructor<const cv::Mat &,
                                  const ::cv::flann::IndexParams &>()
            .method("knnSearch",
                    [](WrappedT &instance,
                       const std::vector<cv::ElementType> &query,
                       std::vector<int> &indices,
                       std::vector<cv::DistanceType> &dists, int knn,
                       const ::cvflann::SearchParams &searchParams) {
                      return instance.knnSearch(query, indices, dists, knn,
                                                searchParams);
                    })
            .method("radiusSearch",
                    [](WrappedT &instance,
                       const std::vector<cv::ElementType> &query,
                       std::vector<int> &indices,
                       std::vector<cv::DistanceType> &dists,
                       cv::DistanceType radius,
                       const ::cvflann::SearchParams &searchParams) {
                      return instance.radiusSearch(query, indices, dists,
                                                   radius, searchParams);
                    })
            .method("save",
                    [](WrappedT &instance, cv::String filename) {
                      return instance.save(filename);
                    })
            .method("veclen",
                    [](WrappedT &instance) { return instance.veclen(); })
            .method("size", [](WrappedT &instance) { return instance.size(); })
            .method("getParameters",
                    [](WrappedT &instance) { return instance.getParameters(); })
            .method("getIndexParameters", [](WrappedT &instance) {
              return instance.getIndexParameters();
            });
      });
}
