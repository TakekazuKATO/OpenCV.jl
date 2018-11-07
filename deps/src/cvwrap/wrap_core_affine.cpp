#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_core_affine_module(Module &mod) {
  mod.add_type<Parametric<TypeVar<1>>>("Affine3")
      .apply<cv::Affine3<float>, cv::Affine3<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.template constructor<const typename WrappedT::Mat4 &>()
            .template constructor<const typename WrappedT::Mat3 &,
                                  const typename WrappedT::Vec3 &>()
            .template constructor<const typename WrappedT::Vec3 &,
                                  const typename WrappedT::Vec3 &>()
            .template constructor<const cv::Mat &,
                                  const typename WrappedT::Vec3 &>()
            .template constructor<const typename WrappedT::float_type *>()
            .method("Identity",
                    [](WrappedT &instance) { return instance.Identity(); })
            .method("rotation",
                    [](WrappedT &instance, const typename WrappedT::Mat3 &R) {
                      return instance.rotation(R);
                    })
            .method(
                "rotation",
                [](WrappedT &instance, const typename WrappedT::Vec3 &rvec) {
                  return instance.rotation(rvec);
                })
            .method("rotation",
                    [](WrappedT &instance, const cv::Mat &data) {
                      return instance.rotation(data);
                    })
            .method("linear",
                    [](WrappedT &instance, const typename WrappedT::Mat3 &L) {
                      return instance.linear(L);
                    })
            .method("translation",
                    [](WrappedT &instance, const typename WrappedT::Vec3 &t) {
                      return instance.translation(t);
                    })
            .method(
                "rotation",
                [](const WrappedT &instance) { return instance.rotation(); })
            .method("linear",
                    [](const WrappedT &instance) { return instance.linear(); })
            .method(
                "translation",
                [](const WrappedT &instance) { return instance.translation(); })
            .method("rvec",
                    [](const WrappedT &instance) { return instance.rvec(); })
            .method("inv",
                    [](const WrappedT &instance) { return instance.inv(); })
            .method("inv", [](const WrappedT &instance,
                              int method) { return instance.inv(method); })
            .method(
                "rotate",
                [](const WrappedT &instance, const typename WrappedT::Mat3 &R) {
                  return instance.rotate(R);
                })
            .method("rotate",
                    [](const WrappedT &instance,
                       const typename WrappedT::Vec3 &rvec) {
                      return instance.rotate(rvec);
                    })
            .method(
                "translate",
                [](const WrappedT &instance, const typename WrappedT::Vec3 &t) {
                  return instance.translate(t);
                })
            .method("concatenate",
                    [](const WrappedT &instance, const WrappedT &affine) {
                      return instance.concatenate(affine);
                    })
            .method("matrix",
                    [](const WrappedT &instance) { return instance.matrix; });
      });
}
