#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_core_types_module(Module& mod) {
  mod.add_type<Parametric<TypeVar<1>>>("Point_")
.apply<cv::Point_<int>,cv::Point_<int64_t>,cv::Point_<uchar>,cv::Point_<short>,cv::Point_<ushort>,cv::Point_<float>,cv::Point_<double>>([](auto wrapped) {
  typedef typename decltype(wrapped)::type WrappedT;
  typedef typename get_template_type<WrappedT>::type ValueT;
  wrapped
    .template constructor<ValueT, ValueT>()
    .template constructor<const Point_<ValueT> &>()
    .template constructor<const Size_<ValueT> &>()
    .template constructor<const Vec<ValueT, 2> &>()
    .method("x",[](const WrappedT &instance){return instance.x;})
    .method("y",[](const WrappedT &instance){return instance.y;});
});
  mod.add_type<Parametric<TypeVar<1>>>("Point3_")
.apply<cv::Point3_<int>,cv::Point3_<int64_t>,cv::Point3_<uchar>,cv::Point3_<short>,cv::Point3_<ushort>,cv::Point3_<float>,cv::Point3_<double>>([](auto wrapped) {
  typedef typename decltype(wrapped)::type WrappedT;
  typedef typename get_template_type<WrappedT>::type ValueT;
  wrapped
    .template constructor<ValueT, ValueT, ValueT>()
    .template constructor<const Point3_<ValueT> &>()
    .template constructor<const Point_<ValueT> &>()
    .template constructor<const Vec<ValueT, 3> &>()
    .method("x",[](const WrappedT &instance){return instance.x;})
    .method("y",[](const WrappedT &instance){return instance.y;})
    .method("z",[](const WrappedT &instance){return instance.z;});
});
  mod.add_type<Parametric<TypeVar<1>>>("Size_")
.apply<cv::Size_<int>,cv::Size_<int64_t>,cv::Size_<uchar>,cv::Size_<short>,cv::Size_<ushort>,cv::Size_<float>,cv::Size_<double>>([](auto wrapped) {
  typedef typename decltype(wrapped)::type WrappedT;
  typedef typename get_template_type<WrappedT>::type ValueT;
  wrapped
    .template constructor<ValueT, ValueT>()
    .template constructor<const Size_<ValueT> &>()
    .template constructor<const Point_<ValueT> &>()
    .method("width",[](const WrappedT &instance){return instance.width;})
    .method("height",[](const WrappedT &instance){return instance.height;});
});
  mod.add_type<Parametric<TypeVar<1>>>("Rect_")
.apply<cv::Rect_<int>,cv::Rect_<int64_t>,cv::Rect_<uchar>,cv::Rect_<short>,cv::Rect_<ushort>,cv::Rect_<float>,cv::Rect_<double>>([](auto wrapped) {
  typedef typename decltype(wrapped)::type WrappedT;
  typedef typename get_template_type<WrappedT>::type ValueT;
  wrapped
    .template constructor<ValueT, ValueT, ValueT, ValueT>()
    .template constructor<const Rect_<ValueT> &>()
    .template constructor<const Point_<ValueT> &, const Size_<ValueT> &>()
    .template constructor<const Point_<ValueT> &, const Point_<ValueT> &>()
    .method("x",[](const WrappedT &instance){return instance.x;})
    .method("y",[](const WrappedT &instance){return instance.y;})
    .method("width",[](const WrappedT &instance){return instance.width;})
    .method("height",[](const WrappedT &instance){return instance.height;});
});
  mod.add_type<cv::RotatedRect>("RotatedRect")
    .constructor<const cv::Point2f &, const cv::Size2f &, float>()
    .constructor<const cv::Point2f &, const cv::Point2f &, const cv::Point2f &>()
    .method("center",[](const cv::RotatedRect &instance){return instance.center;})
    .method("size",[](const cv::RotatedRect &instance){return instance.size;})
    .method("angle",[](const cv::RotatedRect &instance){return instance.angle;});
  mod.add_type<cv::Range>("Range")
    .constructor<int, int>()
    .method("start",[](const cv::Range &instance){return instance.start;})
    .method("end",[](const cv::Range &instance){return instance.end;});
  mod.add_type<Parametric<TypeVar<1>>>("Scalar_")
.apply<cv::Scalar_<int>,cv::Scalar_<int64_t>,cv::Scalar_<uchar>,cv::Scalar_<short>,cv::Scalar_<ushort>,cv::Scalar_<float>,cv::Scalar_<double>>([](auto wrapped) {
  typedef typename decltype(wrapped)::type WrappedT;
  typedef typename get_template_type<WrappedT>::type ValueT;
  wrapped
    .template constructor<ValueT, ValueT, ValueT, ValueT>()
    .template constructor<ValueT>();
});
  mod.add_type<cv::KeyPoint>("KeyPoint")
    .constructor<cv::Point2f, float, float, float, int, int>()
    .constructor<float, float, float, float, float, int, int>()
    .method("pt",[](const cv::KeyPoint &instance){return instance.pt;})
    .method("size",[](const cv::KeyPoint &instance){return instance.size;})
    .method("angle",[](const cv::KeyPoint &instance){return instance.angle;})
    .method("response",[](const cv::KeyPoint &instance){return instance.response;})
    .method("octave",[](const cv::KeyPoint &instance){return instance.octave;})
    .method("class_id",[](const cv::KeyPoint &instance){return instance.class_id;});
  mod.add_type<cv::DMatch>("DMatch")
    .constructor<int, int, float>()
    .constructor<int, int, int, float>()
    .method("queryIdx",[](const cv::DMatch &instance){return instance.queryIdx;})
    .method("trainIdx",[](const cv::DMatch &instance){return instance.trainIdx;})
    .method("imgIdx",[](const cv::DMatch &instance){return instance.imgIdx;})
    .method("distance",[](const cv::DMatch &instance){return instance.distance;});
  mod.add_type<cv::TermCriteria>("TermCriteria")
    .constructor<int, int, double>()
    .method("type",[](const cv::TermCriteria &instance){return instance.type;})
    .method("maxCount",[](const cv::TermCriteria &instance){return instance.maxCount;})
    .method("epsilon",[](const cv::TermCriteria &instance){return instance.epsilon;});
  mod.add_type<cv::Moments>("Moments")
    .constructor<double, double, double, double, double, double, double, double, double, double>()
    .method("m00",[](const cv::Moments &instance){return instance.m00;})
    .method("m10",[](const cv::Moments &instance){return instance.m10;})
    .method("m01",[](const cv::Moments &instance){return instance.m01;})
    .method("m20",[](const cv::Moments &instance){return instance.m20;})
    .method("m11",[](const cv::Moments &instance){return instance.m11;})
    .method("m02",[](const cv::Moments &instance){return instance.m02;})
    .method("m30",[](const cv::Moments &instance){return instance.m30;})
    .method("m21",[](const cv::Moments &instance){return instance.m21;})
    .method("m12",[](const cv::Moments &instance){return instance.m12;})
    .method("m03",[](const cv::Moments &instance){return instance.m03;})
    .method("mu20",[](const cv::Moments &instance){return instance.mu20;})
    .method("mu11",[](const cv::Moments &instance){return instance.mu11;})
    .method("mu02",[](const cv::Moments &instance){return instance.mu02;})
    .method("mu30",[](const cv::Moments &instance){return instance.mu30;})
    .method("mu21",[](const cv::Moments &instance){return instance.mu21;})
    .method("mu12",[](const cv::Moments &instance){return instance.mu12;})
    .method("mu03",[](const cv::Moments &instance){return instance.mu03;})
    .method("nu20",[](const cv::Moments &instance){return instance.nu20;})
    .method("nu11",[](const cv::Moments &instance){return instance.nu11;})
    .method("nu02",[](const cv::Moments &instance){return instance.nu02;})
    .method("nu30",[](const cv::Moments &instance){return instance.nu30;})
    .method("nu21",[](const cv::Moments &instance){return instance.nu21;})
    .method("nu12",[](const cv::Moments &instance){return instance.nu12;})
    .method("nu03",[](const cv::Moments &instance){return instance.nu03;});
}
