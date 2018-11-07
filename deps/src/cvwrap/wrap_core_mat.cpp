#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_core_mat_module(Module &mod) {
  mod.set_const("ACCESS_READ", (int)cv::ACCESS_READ);
  mod.set_const("ACCESS_WRITE", (int)cv::ACCESS_WRITE);
  mod.set_const("ACCESS_RW", (int)cv::ACCESS_RW);
  mod.set_const("ACCESS_MASK", (int)cv::ACCESS_MASK);
  mod.set_const("ACCESS_FAST", (int)cv::ACCESS_FAST);
  mod.method("noArray", []() { return cv::noArray(); });
  mod.add_bits<cv::UMatUsageFlags>("UMatUsageFlags");
  mod.set_const("USAGE_DEFAULT", cv::UMatUsageFlags::USAGE_DEFAULT);
  mod.set_const("USAGE_ALLOCATE_HOST_MEMORY",
                cv::UMatUsageFlags::USAGE_ALLOCATE_HOST_MEMORY);
  mod.set_const("USAGE_ALLOCATE_DEVICE_MEMORY",
                cv::UMatUsageFlags::USAGE_ALLOCATE_DEVICE_MEMORY);
  mod.set_const("USAGE_ALLOCATE_SHARED_MEMORY",
                cv::UMatUsageFlags::USAGE_ALLOCATE_SHARED_MEMORY);
  mod.set_const("__UMAT_USAGE_FLAGS_32BIT",
                cv::UMatUsageFlags::__UMAT_USAGE_FLAGS_32BIT);
  mod.add_type<cv::MatAllocator>("MatAllocator");
  mod.add_type<Parametric<TypeVar<1>>>("MatCommaInitializer_")
      .apply<cv::MatCommaInitializer_<int>, cv::MatCommaInitializer_<uchar>,
             cv::MatCommaInitializer_<short>, cv::MatCommaInitializer_<ushort>,
             cv::MatCommaInitializer_<float>, cv::MatCommaInitializer_<double>>(
          [](auto wrapped) {
            typedef typename decltype(wrapped)::type WrappedT;
            typedef typename get_template_type<WrappedT>::type ValueT;
            wrapped.template constructor<Mat_<ValueT> *>();
          });
  mod.add_type<cv::UMatData>("UMatData")
      .constructor<const cv::MatAllocator *>()
      .method(
          "prevAllocator",
          [](const cv::UMatData &instance) { return instance.prevAllocator; })
      .method(
          "currAllocator",
          [](const cv::UMatData &instance) { return instance.currAllocator; })
      .method("urefcount",
              [](const cv::UMatData &instance) { return instance.urefcount; })
      .method("refcount",
              [](const cv::UMatData &instance) { return instance.refcount; })
      .method("data",
              [](const cv::UMatData &instance) { return instance.data; })
      .method("origdata",
              [](const cv::UMatData &instance) { return instance.origdata; })
      .method("size",
              [](const cv::UMatData &instance) { return instance.size; })
      .method("flags",
              [](const cv::UMatData &instance) { return instance.flags; })
      .method("handle",
              [](const cv::UMatData &instance) { return instance.handle; })
      .method("userdata",
              [](const cv::UMatData &instance) { return instance.userdata; })
      .method(
          "allocatorFlags_",
          [](const cv::UMatData &instance) { return instance.allocatorFlags_; })
      .method("mapcount",
              [](const cv::UMatData &instance) { return instance.mapcount; })
      .method("originalUMatData", [](const cv::UMatData &instance) {
        return instance.originalUMatData;
      });
  mod.add_type<cv::MatSize>("MatSize").constructor<int *>().method(
      "p", [](const cv::MatSize &instance) { return instance.p; });
  mod.add_type<cv::MatStep>("MatStep")
      .constructor<size_t>()
      .method("p", [](const cv::MatStep &instance) { return instance.p; })
      .method("buf", [](const cv::MatStep &instance) { return instance.buf; });
  mod.add_type<Parametric<TypeVar<1>>>("Mat_")
      .apply<cv::Mat_<int>, cv::Mat_<uchar>, cv::Mat_<short>, cv::Mat_<ushort>,
             cv::Mat_<float>, cv::Mat_<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<int, int>()
            .template constructor<int, int, const ValueT &>()
            .template constructor<cv::Size>()
            .template constructor<cv::Size, const ValueT &>()
            .template constructor<int, const int *>()
            .template constructor<int, const int *, const ValueT &>()
            .template constructor<const cv::Mat &>()
            .template constructor<const Mat_<ValueT> &>()
            .template constructor<int, int, ValueT *, size_t>()
            .template constructor<int, const int *, ValueT *, const size_t *>()
            .template constructor<const Mat_<ValueT> &, const cv::Range &,
                                  const cv::Range &>()
            .template constructor<const Mat_<ValueT> &, const cv::Rect &>()
            .template constructor<const Mat_<ValueT> &, const cv::Range *>()
            .template constructor<const Mat_<ValueT> &, const int &>()
            .template constructor<const cv::MatExpr &>()
            .template constructor<const int &, bool>()
            .template constructor<
                const Point_<typename DataType<ValueT>::channel_type> &, bool>()
            .template constructor<
                const Point3_<typename DataType<ValueT>::channel_type> &,
                bool>()
            .template constructor<const MatCommaInitializer_<ValueT> &>()
            .template constructor<std::initializer_list<ValueT>>()
            .template constructor<const std::initializer_list<int>,
                                  const std::initializer_list<ValueT>>();
      });
  mod.add_type<cv::UMat>("UMat")
      .constructor<cv::UMatUsageFlags>()
      .constructor<int, int, int, cv::UMatUsageFlags>()
      .constructor<cv::Size, int, cv::UMatUsageFlags>()
      .constructor<int, int, int, const cv::Scalar &, cv::UMatUsageFlags>()
      .constructor<cv::Size, int, const cv::Scalar &, cv::UMatUsageFlags>()
      .constructor<int, const int *, int, cv::UMatUsageFlags>()
      .constructor<int, const int *, int, const cv::Scalar &,
                   cv::UMatUsageFlags>()
      .constructor<const cv::UMat &>()
      .constructor<const cv::UMat &, const cv::Range &, const cv::Range &>()
      .constructor<const cv::UMat &, const cv::Rect &>()
      .constructor<const cv::UMat &, const cv::Range *>()
      //.constructor<const cv::UMat &, const int &>()
      .method("flags", [](const cv::UMat &instance) { return instance.flags; })
      .method("dims", [](const cv::UMat &instance) { return instance.dims; })
      .method("rows", [](const cv::UMat &instance) { return instance.rows; })
      .method("cols", [](const cv::UMat &instance) { return instance.cols; })
      .method("allocator",
              [](const cv::UMat &instance) { return instance.allocator; })
      .method("usageFlags",
              [](const cv::UMat &instance) { return instance.usageFlags; })
      .method("u", [](const cv::UMat &instance) { return instance.u; })
      .method("offset",
              [](const cv::UMat &instance) { return instance.offset; })
      .method("size", [](const cv::UMat &instance) { return instance.size; })
      .method("step", [](const cv::UMat &instance) { return instance.step; });
  mod.add_type<cv::SparseMat>("SparseMat")
      .constructor<int, const int *, int>()
      .constructor<const cv::SparseMat &>()
      .constructor<const cv::Mat &>()
      .method("flags",
              [](const cv::SparseMat &instance) { return instance.flags; })
      .method("hdr",
              [](const cv::SparseMat &instance) { return instance.hdr; });
  mod.add_type<Parametric<TypeVar<1>>>("SparseMat_")
      .apply<cv::SparseMat_<int>, cv::SparseMat_<uchar>, cv::SparseMat_<short>,
             cv::SparseMat_<ushort>, cv::SparseMat_<float>,
             cv::SparseMat_<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<int, const int *>()
            .template constructor<const cv::SparseMat &>()
            .template constructor<const SparseMat_<ValueT> &>()
            .template constructor<const cv::Mat &>();
      });
  mod.add_type<cv::SparseMatConstIterator>("SparseMatConstIterator")
      .constructor<const cv::SparseMatConstIterator &>()
      .method(
          "m",
          [](const cv::SparseMatConstIterator &instance) { return instance.m; })
      .method("hashidx",
              [](const cv::SparseMatConstIterator &instance) {
                return instance.hashidx;
              })
      .method("ptr", [](const cv::SparseMatConstIterator &instance) {
        return instance.ptr;
      });
  mod.add_type<cv::SparseMatIterator>("SparseMatIterator")
      .constructor<const cv::SparseMatIterator &>();
  mod.add_type<Parametric<TypeVar<1>>>("SparseMatConstIterator_")
      .apply<cv::SparseMatConstIterator_<int>,
             cv::SparseMatConstIterator_<uchar>,
             cv::SparseMatConstIterator_<short>,
             cv::SparseMatConstIterator_<ushort>,
             cv::SparseMatConstIterator_<float>,
             cv::SparseMatConstIterator_<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<const SparseMat_<ValueT> *>()
            .template constructor<const SparseMatConstIterator_<ValueT> &>();
      });
  mod.add_type<Parametric<TypeVar<1>>>("SparseMatIterator_")
      .apply<cv::SparseMatIterator_<int>, cv::SparseMatIterator_<uchar>,
             cv::SparseMatIterator_<short>, cv::SparseMatIterator_<ushort>,
             cv::SparseMatIterator_<float>, cv::SparseMatIterator_<double>>(
          [](auto wrapped) {
            typedef typename decltype(wrapped)::type WrappedT;
            typedef typename get_template_type<WrappedT>::type ValueT;
            wrapped.template constructor<SparseMat_<ValueT> *>()
                .template constructor<const SparseMatIterator_<ValueT> &>();
          });
  mod.add_type<cv::MatOp>("MatOp");
  mod.add_type<cv::MatExpr>("MatExpr")
      .constructor<const cv::Mat &>()
      .constructor<const cv::MatOp *, int, const cv::Mat &, const cv::Mat &,
                   const cv::Mat &, double, double, const cv::Scalar &>()
      .method("op", [](const cv::MatExpr &instance) { return instance.op; })
      .method("flags",
              [](const cv::MatExpr &instance) { return instance.flags; })
      .method("a", [](const cv::MatExpr &instance) { return instance.a; })
      .method("b", [](const cv::MatExpr &instance) { return instance.b; })
      .method("c", [](const cv::MatExpr &instance) { return instance.c; })
      .method("alpha",
              [](const cv::MatExpr &instance) { return instance.alpha; })
      .method("beta", [](const cv::MatExpr &instance) { return instance.beta; })
      .method("s", [](const cv::MatExpr &instance) { return instance.s; });
  mod.method("operator+", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator+(a, b);
  });
  mod.method("operator+", [](const cv::Mat &a, const cv::Scalar &s) {
    return cv::operator+(a, s);
  });
  mod.method("operator+", [](const cv::Scalar &s, const cv::Mat &a) {
    return cv::operator+(s, a);
  });
  mod.method("operator+", [](const cv::MatExpr &e, const cv::Mat &m) {
    return cv::operator+(e, m);
  });
  mod.method("operator+", [](const cv::Mat &m, const cv::MatExpr &e) {
    return cv::operator+(m, e);
  });
  mod.method("operator+", [](const cv::MatExpr &e, const cv::Scalar &s) {
    return cv::operator+(e, s);
  });
  mod.method("operator+", [](const cv::Scalar &s, const cv::MatExpr &e) {
    return cv::operator+(s, e);
  });
  mod.method("operator+", [](const cv::MatExpr &e1, const cv::MatExpr &e2) {
    return cv::operator+(e1, e2);
  });
  mod.method("operator-", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator-(a, b);
  });
  mod.method("operator-", [](const cv::Mat &a, const cv::Scalar &s) {
    return cv::operator-(a, s);
  });
  mod.method("operator-", [](const cv::Scalar &s, const cv::Mat &a) {
    return cv::operator-(s, a);
  });
  mod.method("operator-", [](const cv::MatExpr &e, const cv::Mat &m) {
    return cv::operator-(e, m);
  });
  mod.method("operator-", [](const cv::Mat &m, const cv::MatExpr &e) {
    return cv::operator-(m, e);
  });
  mod.method("operator-", [](const cv::MatExpr &e, const cv::Scalar &s) {
    return cv::operator-(e, s);
  });
  mod.method("operator-", [](const cv::Scalar &s, const cv::MatExpr &e) {
    return cv::operator-(s, e);
  });
  mod.method("operator-", [](const cv::MatExpr &e1, const cv::MatExpr &e2) {
    return cv::operator-(e1, e2);
  });
  mod.method("operator-", [](const cv::Mat &m) { return cv::operator-(m); });
  mod.method("operator-",
             [](const cv::MatExpr &e) { return cv::operator-(e); });
  mod.method("operator*", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator*(a, b);
  });
  mod.method("operator*",
             [](const cv::Mat &a, double s) { return cv::operator*(a, s); });
  mod.method("operator*",
             [](double s, const cv::Mat &a) { return cv::operator*(s, a); });
  mod.method("operator*", [](const cv::MatExpr &e, const cv::Mat &m) {
    return cv::operator*(e, m);
  });
  mod.method("operator*", [](const cv::Mat &m, const cv::MatExpr &e) {
    return cv::operator*(m, e);
  });
  mod.method("operator*", [](const cv::MatExpr &e, double s) {
    return cv::operator*(e, s);
  });
  mod.method("operator*", [](double s, const cv::MatExpr &e) {
    return cv::operator*(s, e);
  });
  mod.method("operator*", [](const cv::MatExpr &e1, const cv::MatExpr &e2) {
    return cv::operator*(e1, e2);
  });
  mod.method("operator/", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator/(a, b);
  });
  mod.method("operator/",
             [](const cv::Mat &a, double s) { return cv::operator/(a, s); });
  mod.method("operator/",
             [](double s, const cv::Mat &a) { return cv::operator/(s, a); });
  mod.method("operator/", [](const cv::MatExpr &e, const cv::Mat &m) {
    return cv::operator/(e, m);
  });
  mod.method("operator/", [](const cv::Mat &m, const cv::MatExpr &e) {
    return cv::operator/(m, e);
  });
  mod.method("operator/", [](const cv::MatExpr &e, double s) {
    return cv::operator/(e, s);
  });
  mod.method("operator/", [](double s, const cv::MatExpr &e) {
    return cv::operator/(s, e);
  });
  mod.method("operator/", [](const cv::MatExpr &e1, const cv::MatExpr &e2) {
    return cv::operator/(e1, e2);
  });
  mod.method("operator<", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator<(a, b);
  });
  mod.method("operator<",
             [](const cv::Mat &a, double s) { return cv::operator<(a, s); });
  mod.method("operator<",
             [](double s, const cv::Mat &a) { return cv::operator<(s, a); });
  mod.method("operator<=", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator<=(a, b);
  });
  mod.method("operator<=",
             [](const cv::Mat &a, double s) { return cv::operator<=(a, s); });
  mod.method("operator<=",
             [](double s, const cv::Mat &a) { return cv::operator<=(s, a); });
  mod.method("operator==", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator==(a, b);
  });
  mod.method("operator==",
             [](const cv::Mat &a, double s) { return cv::operator==(a, s); });
  mod.method("operator==",
             [](double s, const cv::Mat &a) { return cv::operator==(s, a); });
  mod.method("operator!=", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator!=(a, b);
  });
  mod.method("operator!=",
             [](const cv::Mat &a, double s) { return cv::operator!=(a, s); });
  mod.method("operator!=",
             [](double s, const cv::Mat &a) { return cv::operator!=(s, a); });
  mod.method("operator>=", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator>=(a, b);
  });
  mod.method("operator>=",
             [](const cv::Mat &a, double s) { return cv::operator>=(a, s); });
  mod.method("operator>=",
             [](double s, const cv::Mat &a) { return cv::operator>=(s, a); });
  mod.method("operator>", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator>(a, b);
  });
  mod.method("operator>",
             [](const cv::Mat &a, double s) { return cv::operator>(a, s); });
  mod.method("operator>",
             [](double s, const cv::Mat &a) { return cv::operator>(s, a); });
  mod.method("operator&", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator&(a, b);
  });
  mod.method("operator&", [](const cv::Mat &a, const cv::Scalar &s) {
    return cv::operator&(a, s);
  });
  mod.method("operator&", [](const cv::Scalar &s, const cv::Mat &a) {
    return cv::operator&(s, a);
  });
  mod.method("operator|", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator|(a, b);
  });
  mod.method("operator|", [](const cv::Mat &a, const cv::Scalar &s) {
    return cv::operator|(a, s);
  });
  mod.method("operator|", [](const cv::Scalar &s, const cv::Mat &a) {
    return cv::operator|(s, a);
  });
  mod.method("operator^", [](const cv::Mat &a, const cv::Mat &b) {
    return cv::operator^(a, b);
  });
  mod.method("operator^", [](const cv::Mat &a, const cv::Scalar &s) {
    return cv::operator^(a, s);
  });
  mod.method("operator^", [](const cv::Scalar &s, const cv::Mat &a) {
    return cv::operator^(s, a);
  });
  mod.method("operator~", [](const cv::Mat &m) { return cv::operator~(m); });
  mod.method("min",
             [](const cv::Mat &a, const cv::Mat &b) { return cv::min(a, b); });
  mod.method("min", [](const cv::Mat &a, double s) { return cv::min(a, s); });
  mod.method("min", [](double s, const cv::Mat &a) { return cv::min(s, a); });
  mod.method("max",
             [](const cv::Mat &a, const cv::Mat &b) { return cv::max(a, b); });
  mod.method("max", [](const cv::Mat &a, double s) { return cv::max(a, s); });
  mod.method("max", [](double s, const cv::Mat &a) { return cv::max(s, a); });
  mod.method("abs", [](const cv::Mat &m) { return cv::abs(m); });
  mod.method("abs", [](const cv::MatExpr &e) { return cv::abs(e); });
}
