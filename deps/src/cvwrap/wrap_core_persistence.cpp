#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_core_persistence_module(Module &mod) {
  mod.add_type<cv::FileStorage>("FileStorage")
      .constructor<const cv::String &, int, const cv::String &>()
      //.constructor<CvFileStorage *, bool>()
      //.method("fs", [](const cv::FileStorage &instance) { return instance.fs;
      //})
      .method("elname",
              [](const cv::FileStorage &instance) { return instance.elname; })
      .method("structs",
              [](const cv::FileStorage &instance) { return instance.structs; })
      .method("state",
              [](const cv::FileStorage &instance) { return instance.state; });
  mod.add_type<cv::FileNode>("FileNode")
      //.constructor<const CvFileStorage *, const CvFileNode *>()
      .constructor<const cv::FileNode &>()
      //.method("fs", [](const cv::FileNode &instance) { return instance.fs; })
      .method("node",
              [](const cv::FileNode &instance) { return instance.node; });
  mod.add_type<cv::FileNodeIterator>("FileNodeIterator")
      //.constructor<const CvFileStorage *, const CvFileNode *, size_t>()
      .constructor<const cv::FileNodeIterator &>()
      //.method("fs",
      //        [](const cv::FileNodeIterator &instance) { return instance.fs;
      //        })
      .method("container",
              [](const cv::FileNodeIterator &instance) {
                return instance.container;
              })
      .method(
          "reader",
          [](const cv::FileNodeIterator &instance) { return instance.reader; })
      .method("remaining", [](const cv::FileNodeIterator &instance) {
        return instance.remaining;
      });
  mod.method("write", [](cv::FileStorage &fs, const cv::String &name,
                         int value) { return cv::write(fs, name, value); });
  mod.method("write", [](cv::FileStorage &fs, const cv::String &name,
                         float value) { return cv::write(fs, name, value); });
  mod.method("write", [](cv::FileStorage &fs, const cv::String &name,
                         double value) { return cv::write(fs, name, value); });
  mod.method("write", [](cv::FileStorage &fs, const cv::String &name,
                         const cv::String &value) {
    return cv::write(fs, name, value);
  });
  mod.method("write",
             [](cv::FileStorage &fs, const cv::String &name,
                const cv::Mat &value) { return cv::write(fs, name, value); });
  mod.method("write", [](cv::FileStorage &fs, const cv::String &name,
                         const cv::SparseMat &value) {
    return cv::write(fs, name, value);
  });
  mod.method("write", [](cv::FileStorage &fs, const cv::String &name,
                         const std::vector<cv::KeyPoint> &value) {
    return cv::write(fs, name, value);
  });
  mod.method("write", [](cv::FileStorage &fs, const cv::String &name,
                         const std::vector<cv::DMatch> &value) {
    return cv::write(fs, name, value);
  });
  mod.method("writeScalar", [](cv::FileStorage &fs, int value) {
    return cv::writeScalar(fs, value);
  });
  mod.method("writeScalar", [](cv::FileStorage &fs, float value) {
    return cv::writeScalar(fs, value);
  });
  mod.method("writeScalar", [](cv::FileStorage &fs, double value) {
    return cv::writeScalar(fs, value);
  });
  mod.method("writeScalar", [](cv::FileStorage &fs, const cv::String &value) {
    return cv::writeScalar(fs, value);
  });
  mod.method("read",
             [](const cv::FileNode &node, int &value, int default_value) {
               return cv::read(node, value, default_value);
             });
  mod.method("read",
             [](const cv::FileNode &node, float &value, float default_value) {
               return cv::read(node, value, default_value);
             });
  mod.method("read",
             [](const cv::FileNode &node, double &value, double default_value) {
               return cv::read(node, value, default_value);
             });
  // mod.method("read", [](const cv::FileNode &node, cv::String &value,
  //                      const cv::String &default_value) {
  //  return cv::read(node, value, default_value);
  //});
  // mod.method("read", [](const cv::FileNode &node, std::string &value,
  //                        const std::string &default_value) {
  //  return cv::read(node, value, default_value);
  //});
  mod.method("read", [](const cv::FileNode &node, cv::SparseMat &mat) {
    return cv::read(node, mat);
  });
  mod.method("read", [](const cv::FileNode &node, cv::SparseMat &mat,
                        const cv::SparseMat &default_mat) {
    return cv::read(node, mat, default_mat);
  });
  mod.method("read", [](const cv::FileNode &node,
                        const std::vector<cv::KeyPoint> &keypoints) {
    return cv::read(node, const_off(keypoints));
  });
  mod.method("read", [](const cv::FileNode &node,
                        const std::vector<cv::DMatch> &matches) {
    return cv::read(node, const_off(matches));
  });
  /*mod.method("read", [](const cv::FileNode &node, cv::KeyPoint &value,
                        const cv::KeyPoint &default_value) {
    return cv::read(node, value, default_value);
  });*/
  mod.method("read", [](const cv::FileNode &node, cv::DMatch &value,
                        const cv::DMatch &default_value) {
    return cv::read(node, value, default_value);
  });
  mod.method("operator<<", [](cv::FileStorage &fs, const cv::String &str) {
    return cv::operator<<(fs, str);
  });
  mod.add_type<cv::internal::WriteStructContext>("WriteStructContext")
      .constructor<cv::FileStorage &, const cv::String &, int,
                   const cv::String &>();
  /*mod.method(
      "cvStartWriteRawData_Base64",
      [](::CvFileStorage *fs, const char *name, int len, const char *dt) {
        return cv::cvStartWriteRawData_Base64(fs, name, len, dt);
      });
  mod.method("cvWriteRawData_Base64",
             [](::CvFileStorage *fs, const void *_data, int len) {
               return cv::cvWriteRawData_Base64(fs, _data, len);
             });
  mod.method("cvEndWriteRawData_Base64", [](::CvFileStorage *fs) {
    return cv::cvEndWriteRawData_Base64(fs);
  });
  mod.method("cvWriteMat_Base64",
             [](::CvFileStorage *fs, const char *name, const ::CvMat *mat) {
               return cv::cvWriteMat_Base64(fs, name, mat);
             });
  mod.method("cvWriteMatND_Base64",
             [](::CvFileStorage *fs, const char *name, const ::CvMatND *mat) {
               return cv::cvWriteMatND_Base64(fs, name, mat);
             });
             */
}
