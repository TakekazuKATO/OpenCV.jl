#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_objdetect_module(Module &mod) {
  mod.add_type<cv::SimilarRects>("SimilarRects")
      .constructor<double>()
      .method([](cv::SimilarRects &instance, const cv::Rect &r1,
                 const cv::Rect &r2) { return instance.operator()(r1, r2); })
      .method("eps",
              [](const cv::SimilarRects &instance) { return instance.eps; });
  mod.method("groupRectangles",
             [](const std::vector<cv::Rect> &rectList, int groupThreshold) {
               return cv::groupRectangles(const_off(rectList), groupThreshold);
             });
  mod.method("groupRectangles", [](const std::vector<cv::Rect> &rectList,
                                   int groupThreshold, double eps) {
    return cv::groupRectangles(const_off(rectList), groupThreshold, eps);
  });
  mod.method("groupRectangles",
             [](const std::vector<cv::Rect> &rectList,
                const std::vector<int> &weights, int groupThreshold) {
               return cv::groupRectangles(const_off(rectList),
                                          const_off(weights), groupThreshold);
             });
  mod.method("groupRectangles", [](const std::vector<cv::Rect> &rectList,
                                   const std::vector<int> &weights,
                                   int groupThreshold, double eps) {
    return cv::groupRectangles(const_off(rectList), const_off(weights),
                               groupThreshold, eps);
  });
  /*mod.method(
      "groupRectangles",
      [](const std::vector<cv::Rect> &rectList, int groupThreshold, double eps,
         std::vector<int> *weights, std::vector<double> *levelWeights) {
        return cv::groupRectangles(const_off(rectList), groupThreshold, eps,
                                   weights, levelWeights);
      });*/
  mod.method("groupRectangles", [](const std::vector<cv::Rect> &rectList,
                                   const std::vector<int> &rejectLevels,
                                   const std::vector<double> &levelWeights,
                                   int groupThreshold) {
    return cv::groupRectangles(const_off(rectList), const_off(rejectLevels),
                               const_off(levelWeights), groupThreshold);
  });
  mod.method("groupRectangles", [](const std::vector<cv::Rect> &rectList,
                                   const std::vector<int> &rejectLevels,
                                   const std::vector<double> &levelWeights,
                                   int groupThreshold, double eps) {
    return cv::groupRectangles(const_off(rectList), const_off(rejectLevels),
                               const_off(levelWeights), groupThreshold, eps);
  });
  mod.method("groupRectangles_meanshift",
             [](const std::vector<cv::Rect> &rectList,
                const std::vector<double> &foundWeights,
                const std::vector<double> &foundScales) {
               return cv::groupRectangles_meanshift(const_off(rectList),
                                                    const_off(foundWeights),
                                                    const_off(foundScales));
             });
  mod.method(
      "groupRectangles_meanshift",
      [](const std::vector<cv::Rect> &rectList,
         const std::vector<double> &foundWeights,
         const std::vector<double> &foundScales, double detectThreshold) {
        return cv::groupRectangles_meanshift(
            const_off(rectList), const_off(foundWeights),
            const_off(foundScales), detectThreshold);
      });
  mod.method("groupRectangles_meanshift",
             [](const std::vector<cv::Rect> &rectList,
                const std::vector<double> &foundWeights,
                const std::vector<double> &foundScales, double detectThreshold,
                cv::Size winDetSize) {
               return cv::groupRectangles_meanshift(
                   const_off(rectList), const_off(foundWeights),
                   const_off(foundScales), detectThreshold, winDetSize);
             });
  mod.set_const("CASCADE_DO_CANNY_PRUNING", (int)cv::CASCADE_DO_CANNY_PRUNING);
  mod.set_const("CASCADE_SCALE_IMAGE", (int)cv::CASCADE_SCALE_IMAGE);
  mod.set_const("CASCADE_FIND_BIGGEST_OBJECT",
                (int)cv::CASCADE_FIND_BIGGEST_OBJECT);
  mod.set_const("CASCADE_DO_ROUGH_SEARCH", (int)cv::CASCADE_DO_ROUGH_SEARCH);
  mod.add_type<cv::BaseCascadeClassifier>("BaseCascadeClassifier")
      .method("empty",
              [](const cv::BaseCascadeClassifier &instance) {
                return instance.empty();
              })
      .method(
          "load",
          [](cv::BaseCascadeClassifier &instance, const cv::String &filename) {
            return instance.load(filename);
          })
      .method(
          "detectMultiScale",
          [](cv::BaseCascadeClassifier &instance, const cv::Mat &image,
             const std::vector<cv::Rect> &objects, double scaleFactor,
             int minNeighbors, int flags, cv::Size minSize, cv::Size maxSize) {
            return instance.detectMultiScale(
                cv::InputArray(image), const_off(objects), scaleFactor,
                minNeighbors, flags, minSize, maxSize);
          })
      .method(
          "detectMultiScale",
          [](cv::BaseCascadeClassifier &instance, const cv::Mat &image,
             const std::vector<cv::Rect> &objects,
             const std::vector<int> &numDetections, double scaleFactor,
             int minNeighbors, int flags, cv::Size minSize, cv::Size maxSize) {
            return instance.detectMultiScale(
                cv::InputArray(image), const_off(objects),
                const_off(numDetections), scaleFactor, minNeighbors, flags,
                minSize, maxSize);
          })
      .method("detectMultiScale",
              [](cv::BaseCascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &rejectLevels,
                 const std::vector<double> &levelWeights, double scaleFactor,
                 int minNeighbors, int flags, cv::Size minSize,
                 cv::Size maxSize, bool outputRejectLevels) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(rejectLevels), const_off(levelWeights),
                    scaleFactor, minNeighbors, flags, minSize, maxSize,
                    outputRejectLevels);
              })
      .method("isOldFormatCascade",
              [](const cv::BaseCascadeClassifier &instance) {
                return instance.isOldFormatCascade();
              })
      .method("getOriginalWindowSize",
              [](const cv::BaseCascadeClassifier &instance) {
                return instance.getOriginalWindowSize();
              })
      .method("getFeatureType",
              [](const cv::BaseCascadeClassifier &instance) {
                return instance.getFeatureType();
              })
      .method("getOldCascade",
              [](cv::BaseCascadeClassifier &instance) {
                return instance.getOldCascade();
              })
      .method("setMaskGenerator",
              [](cv::BaseCascadeClassifier &instance,
                 const cv::Ptr<cv::BaseCascadeClassifier::MaskGenerator>
                     &maskGenerator) {
                return instance.setMaskGenerator(maskGenerator);
              })
      .method("getMaskGenerator", [](cv::BaseCascadeClassifier &instance) {
        return instance.getMaskGenerator();
      });
  mod.add_type<cv::CascadeClassifier>("CascadeClassifier")
      .constructor<const cv::String &>()
      .method("empty",
              [](const cv::CascadeClassifier &instance) {
                return instance.empty();
              })
      .method("load",
              [](cv::CascadeClassifier &instance, const cv::String &filename) {
                return instance.load(filename);
              })
      .method("read",
              [](cv::CascadeClassifier &instance, const cv::FileNode &node) {
                return instance.read(node);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects) {
                return instance.detectMultiScale(cv::InputArray(image),
                                                 const_off(objects));
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects, double scaleFactor) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects), scaleFactor);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects, double scaleFactor,
                 int minNeighbors) {
                return instance.detectMultiScale(cv::InputArray(image),
                                                 const_off(objects),
                                                 scaleFactor, minNeighbors);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects, double scaleFactor,
                 int minNeighbors, int flags) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects), scaleFactor,
                    minNeighbors, flags);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects, double scaleFactor,
                 int minNeighbors, int flags, cv::Size minSize) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects), scaleFactor,
                    minNeighbors, flags, minSize);
              })
      .method(
          "detectMultiScale",
          [](cv::CascadeClassifier &instance, const cv::Mat &image,
             const std::vector<cv::Rect> &objects, double scaleFactor,
             int minNeighbors, int flags, cv::Size minSize, cv::Size maxSize) {
            return instance.detectMultiScale(
                cv::InputArray(image), const_off(objects), scaleFactor,
                minNeighbors, flags, minSize, maxSize);
          })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &numDetections) {
                return instance.detectMultiScale(cv::InputArray(image),
                                                 const_off(objects),
                                                 const_off(numDetections));
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &numDetections, double scaleFactor) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(numDetections), scaleFactor);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &numDetections, double scaleFactor,
                 int minNeighbors) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(numDetections), scaleFactor, minNeighbors);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &numDetections, double scaleFactor,
                 int minNeighbors, int flags) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(numDetections), scaleFactor, minNeighbors, flags);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &numDetections, double scaleFactor,
                 int minNeighbors, int flags, cv::Size minSize) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(numDetections), scaleFactor, minNeighbors, flags,
                    minSize);
              })
      .method(
          "detectMultiScale",
          [](cv::CascadeClassifier &instance, const cv::Mat &image,
             const std::vector<cv::Rect> &objects,
             const std::vector<int> &numDetections, double scaleFactor,
             int minNeighbors, int flags, cv::Size minSize, cv::Size maxSize) {
            return instance.detectMultiScale(
                cv::InputArray(image), const_off(objects),
                const_off(numDetections), scaleFactor, minNeighbors, flags,
                minSize, maxSize);
          })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &rejectLevels,
                 const std::vector<double> &levelWeights) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(rejectLevels), const_off(levelWeights));
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &rejectLevels,
                 const std::vector<double> &levelWeights, double scaleFactor) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(rejectLevels), const_off(levelWeights),
                    scaleFactor);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &rejectLevels,
                 const std::vector<double> &levelWeights, double scaleFactor,
                 int minNeighbors) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(rejectLevels), const_off(levelWeights),
                    scaleFactor, minNeighbors);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &rejectLevels,
                 const std::vector<double> &levelWeights, double scaleFactor,
                 int minNeighbors, int flags) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(rejectLevels), const_off(levelWeights),
                    scaleFactor, minNeighbors, flags);
              })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &rejectLevels,
                 const std::vector<double> &levelWeights, double scaleFactor,
                 int minNeighbors, int flags, cv::Size minSize) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(rejectLevels), const_off(levelWeights),
                    scaleFactor, minNeighbors, flags, minSize);
              })
      .method(
          "detectMultiScale",
          [](cv::CascadeClassifier &instance, const cv::Mat &image,
             const std::vector<cv::Rect> &objects,
             const std::vector<int> &rejectLevels,
             const std::vector<double> &levelWeights, double scaleFactor,
             int minNeighbors, int flags, cv::Size minSize, cv::Size maxSize) {
            return instance.detectMultiScale(
                cv::InputArray(image), const_off(objects),
                const_off(rejectLevels), const_off(levelWeights), scaleFactor,
                minNeighbors, flags, minSize, maxSize);
          })
      .method("detectMultiScale",
              [](cv::CascadeClassifier &instance, const cv::Mat &image,
                 const std::vector<cv::Rect> &objects,
                 const std::vector<int> &rejectLevels,
                 const std::vector<double> &levelWeights, double scaleFactor,
                 int minNeighbors, int flags, cv::Size minSize,
                 cv::Size maxSize, bool outputRejectLevels) {
                return instance.detectMultiScale(
                    cv::InputArray(image), const_off(objects),
                    const_off(rejectLevels), const_off(levelWeights),
                    scaleFactor, minNeighbors, flags, minSize, maxSize,
                    outputRejectLevels);
              })
      .method("isOldFormatCascade",
              [](const cv::CascadeClassifier &instance) {
                return instance.isOldFormatCascade();
              })
      .method("getOriginalWindowSize",
              [](const cv::CascadeClassifier &instance) {
                return instance.getOriginalWindowSize();
              })
      .method("getFeatureType",
              [](const cv::CascadeClassifier &instance) {
                return instance.getFeatureType();
              })
      .method("getOldCascade",
              [](cv::CascadeClassifier &instance) {
                return instance.getOldCascade();
              })
      .method("convert",
              [](cv::CascadeClassifier &instance, const cv::String &oldcascade,
                 const cv::String &newcascade) {
                return instance.convert(oldcascade, newcascade);
              })
      .method("setMaskGenerator",
              [](cv::CascadeClassifier &instance,
                 const cv::Ptr<cv::BaseCascadeClassifier::MaskGenerator>
                     &maskGenerator) {
                return instance.setMaskGenerator(maskGenerator);
              })
      .method("getMaskGenerator",
              [](cv::CascadeClassifier &instance) {
                return instance.getMaskGenerator();
              })
      .method("cc", [](const cv::CascadeClassifier &instance) {
        return instance.cc;
      });
  mod.method("createFaceDetectionMaskGenerator",
             []() { return cv::createFaceDetectionMaskGenerator(); });
  mod.add_type<cv::DetectionROI>("DetectionROI")
      .method("scale",
              [](const cv::DetectionROI &instance) { return instance.scale; })
      .method(
          "locations",
          [](const cv::DetectionROI &instance) { return instance.locations; })
      .method("confidences", [](const cv::DetectionROI &instance) {
        return instance.confidences;
      });
  mod.add_type<cv::HOGDescriptor>("HOGDescriptor")
      .constructor<cv::Size, cv::Size, cv::Size, cv::Size, int, int, double,
                   int, double, bool, int, bool>()
      .constructor<const cv::String &>()
      .constructor<const cv::HOGDescriptor &>()
      .method("getDescriptorSize",
              [](const cv::HOGDescriptor &instance) {
                return instance.getDescriptorSize();
              })
      .method("checkDetectorSize",
              [](const cv::HOGDescriptor &instance) {
                return instance.checkDetectorSize();
              })
      .method("getWinSigma",
              [](const cv::HOGDescriptor &instance) {
                return instance.getWinSigma();
              })
      .method("setSVMDetector",
              [](cv::HOGDescriptor &instance, const cv::Mat &_svmdetector) {
                return instance.setSVMDetector(cv::InputArray(_svmdetector));
              })
      .method("read", [](cv::HOGDescriptor &instance,
                         cv::FileNode &fn) { return instance.read(fn); })
      .method(
          "write",
          [](const cv::HOGDescriptor &instance, cv::FileStorage &fs,
             const cv::String &objname) { return instance.write(fs, objname); })
      .method("load",
              [](cv::HOGDescriptor &instance, const cv::String &filename) {
                return instance.load(filename);
              })
      .method("load",
              [](cv::HOGDescriptor &instance, const cv::String &filename,
                 const cv::String &objname) {
                return instance.load(filename, objname);
              })
      .method(
          "save",
          [](const cv::HOGDescriptor &instance, const cv::String &filename) {
            return instance.save(filename);
          })
      .method("save",
              [](const cv::HOGDescriptor &instance, const cv::String &filename,
                 const cv::String &objname) {
                return instance.save(filename, objname);
              })
      .method("copyTo", [](const cv::HOGDescriptor &instance,
                           cv::HOGDescriptor &c) { return instance.copyTo(c); })
      .method("compute",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<float> &descriptors) {
                return instance.compute(cv::InputArray(img),
                                        const_off(descriptors));
              })
      .method("compute",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<float> &descriptors, cv::Size winStride) {
                return instance.compute(cv::InputArray(img),
                                        const_off(descriptors), winStride);
              })
      .method("compute",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<float> &descriptors, cv::Size winStride,
                 cv::Size padding) {
                return instance.compute(cv::InputArray(img),
                                        const_off(descriptors), winStride,
                                        padding);
              })
      .method("compute",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<float> &descriptors, cv::Size winStride,
                 cv::Size padding, const std::vector<cv::Point> &locations) {
                return instance.compute(cv::InputArray(img),
                                        const_off(descriptors), winStride,
                                        padding, locations);
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &weights) {
                return instance.detect(img, const_off(foundLocations),
                                       const_off(weights));
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &weights, double hitThreshold) {
                return instance.detect(img, const_off(foundLocations),
                                       const_off(weights), hitThreshold);
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &weights, double hitThreshold,
                 cv::Size winStride) {
                return instance.detect(img, const_off(foundLocations),
                                       const_off(weights), hitThreshold,
                                       winStride);
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &weights, double hitThreshold,
                 cv::Size winStride, cv::Size padding) {
                return instance.detect(img, const_off(foundLocations),
                                       const_off(weights), hitThreshold,
                                       winStride, padding);
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &weights, double hitThreshold,
                 cv::Size winStride, cv::Size padding,
                 const std::vector<cv::Point> &searchLocations) {
                return instance.detect(img, const_off(foundLocations),
                                       const_off(weights), hitThreshold,
                                       winStride, padding, searchLocations);
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations) {
                return instance.detect(img, const_off(foundLocations));
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 double hitThreshold) {
                return instance.detect(img, const_off(foundLocations),
                                       hitThreshold);
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 double hitThreshold, cv::Size winStride) {
                return instance.detect(img, const_off(foundLocations),
                                       hitThreshold, winStride);
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 double hitThreshold, cv::Size winStride, cv::Size padding) {
                return instance.detect(img, const_off(foundLocations),
                                       hitThreshold, winStride, padding);
              })
      .method("detect",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &foundLocations,
                 double hitThreshold, cv::Size winStride, cv::Size padding,
                 const std::vector<cv::Point> &searchLocations) {
                return instance.detect(img, const_off(foundLocations),
                                       hitThreshold, winStride, padding,
                                       searchLocations);
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<double> &foundWeights) {
                return instance.detectMultiScale(cv::InputArray(img),
                                                 const_off(foundLocations),
                                                 const_off(foundWeights));
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<double> &foundWeights, double hitThreshold) {
                return instance.detectMultiScale(
                    cv::InputArray(img), const_off(foundLocations),
                    const_off(foundWeights), hitThreshold);
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<double> &foundWeights, double hitThreshold,
                 cv::Size winStride) {
                return instance.detectMultiScale(
                    cv::InputArray(img), const_off(foundLocations),
                    const_off(foundWeights), hitThreshold, winStride);
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<double> &foundWeights, double hitThreshold,
                 cv::Size winStride, cv::Size padding) {
                return instance.detectMultiScale(
                    cv::InputArray(img), const_off(foundLocations),
                    const_off(foundWeights), hitThreshold, winStride, padding);
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<double> &foundWeights, double hitThreshold,
                 cv::Size winStride, cv::Size padding, double scale) {
                return instance.detectMultiScale(
                    cv::InputArray(img), const_off(foundLocations),
                    const_off(foundWeights), hitThreshold, winStride, padding,
                    scale);
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<double> &foundWeights, double hitThreshold,
                 cv::Size winStride, cv::Size padding, double scale,
                 double finalThreshold) {
                return instance.detectMultiScale(
                    cv::InputArray(img), const_off(foundLocations),
                    const_off(foundWeights), hitThreshold, winStride, padding,
                    scale, finalThreshold);
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<double> &foundWeights, double hitThreshold,
                 cv::Size winStride, cv::Size padding, double scale,
                 double finalThreshold, bool useMeanshiftGrouping) {
                return instance.detectMultiScale(
                    cv::InputArray(img), const_off(foundLocations),
                    const_off(foundWeights), hitThreshold, winStride, padding,
                    scale, finalThreshold, useMeanshiftGrouping);
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations) {
                return instance.detectMultiScale(cv::InputArray(img),
                                                 const_off(foundLocations));
              })
      .method(
          "detectMultiScale",
          [](const cv::HOGDescriptor &instance, const cv::Mat &img,
             const std::vector<cv::Rect> &foundLocations, double hitThreshold) {
            return instance.detectMultiScale(
                cv::InputArray(img), const_off(foundLocations), hitThreshold);
          })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 double hitThreshold, cv::Size winStride) {
                return instance.detectMultiScale(cv::InputArray(img),
                                                 const_off(foundLocations),
                                                 hitThreshold, winStride);
              })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 double hitThreshold, cv::Size winStride, cv::Size padding) {
                return instance.detectMultiScale(
                    cv::InputArray(img), const_off(foundLocations),
                    hitThreshold, winStride, padding);
              })
      .method(
          "detectMultiScale",
          [](const cv::HOGDescriptor &instance, const cv::Mat &img,
             const std::vector<cv::Rect> &foundLocations, double hitThreshold,
             cv::Size winStride, cv::Size padding, double scale) {
            return instance.detectMultiScale(
                cv::InputArray(img), const_off(foundLocations), hitThreshold,
                winStride, padding, scale);
          })
      .method("detectMultiScale",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 double hitThreshold, cv::Size winStride, cv::Size padding,
                 double scale, double finalThreshold) {
                return instance.detectMultiScale(
                    cv::InputArray(img), const_off(foundLocations),
                    hitThreshold, winStride, padding, scale, finalThreshold);
              })
      .method(
          "detectMultiScale",
          [](const cv::HOGDescriptor &instance, const cv::Mat &img,
             const std::vector<cv::Rect> &foundLocations, double hitThreshold,
             cv::Size winStride, cv::Size padding, double scale,
             double finalThreshold, bool useMeanshiftGrouping) {
            return instance.detectMultiScale(
                cv::InputArray(img), const_off(foundLocations), hitThreshold,
                winStride, padding, scale, finalThreshold,
                useMeanshiftGrouping);
          })
      .method("getDefaultPeopleDetector",
              [](cv::HOGDescriptor &instance) {
                return instance.getDefaultPeopleDetector();
              })
      .method("getDaimlerPeopleDetector",
              [](cv::HOGDescriptor &instance) {
                return instance.getDaimlerPeopleDetector();
              })
      .method(
          "winSize",
          [](const cv::HOGDescriptor &instance) { return instance.winSize; })
      .method(
          "blockSize",
          [](const cv::HOGDescriptor &instance) { return instance.blockSize; })
      .method("blockStride",
              [](const cv::HOGDescriptor &instance) {
                return instance.blockStride;
              })
      .method(
          "cellSize",
          [](const cv::HOGDescriptor &instance) { return instance.cellSize; })
      .method("nbins",
              [](const cv::HOGDescriptor &instance) { return instance.nbins; })
      .method("derivAperture",
              [](const cv::HOGDescriptor &instance) {
                return instance.derivAperture;
              })
      .method(
          "winSigma",
          [](const cv::HOGDescriptor &instance) { return instance.winSigma; })
      .method("histogramNormType",
              [](const cv::HOGDescriptor &instance) {
                return instance.histogramNormType;
              })
      .method("L2HysThreshold",
              [](const cv::HOGDescriptor &instance) {
                return instance.L2HysThreshold;
              })
      .method("gammaCorrection",
              [](const cv::HOGDescriptor &instance) {
                return instance.gammaCorrection;
              })
      .method("svmDetector",
              [](const cv::HOGDescriptor &instance) {
                return instance.svmDetector;
              })
      .method("oclSvmDetector",
              [](const cv::HOGDescriptor &instance) {
                return instance.oclSvmDetector;
              })
      .method(
          "free_coef",
          [](const cv::HOGDescriptor &instance) { return instance.free_coef; })
      .method(
          "nlevels",
          [](const cv::HOGDescriptor &instance) { return instance.nlevels; })
      .method("signedGradient",
              [](const cv::HOGDescriptor &instance) {
                return instance.signedGradient;
              })
      .method("detectROI",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &locations,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &confidences) {
                return instance.detectROI(img, locations,
                                          const_off(foundLocations),
                                          const_off(confidences));
              })
      .method("detectROI",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &locations,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &confidences, double hitThreshold) {
                return instance.detectROI(img, locations,
                                          const_off(foundLocations),
                                          const_off(confidences), hitThreshold);
              })
      .method("detectROI",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &locations,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &confidences, double hitThreshold,
                 cv::Size winStride) {
                return instance.detectROI(
                    img, locations, const_off(foundLocations),
                    const_off(confidences), hitThreshold, winStride);
              })
      .method("detectROI",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Point> &locations,
                 const std::vector<cv::Point> &foundLocations,
                 const std::vector<double> &confidences, double hitThreshold,
                 cv::Size winStride, cv::Size padding) {
                return instance.detectROI(
                    img, locations, const_off(foundLocations),
                    const_off(confidences), hitThreshold, winStride, padding);
              })
      .method("detectMultiScaleROI",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<cv::DetectionROI> &locations) {
                return instance.detectMultiScaleROI(
                    img, const_off(foundLocations), const_off(locations));
              })
      .method("detectMultiScaleROI",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<cv::DetectionROI> &locations,
                 double hitThreshold) {
                return instance.detectMultiScaleROI(
                    img, const_off(foundLocations), const_off(locations),
                    hitThreshold);
              })
      .method("detectMultiScaleROI",
              [](const cv::HOGDescriptor &instance, const cv::Mat &img,
                 const std::vector<cv::Rect> &foundLocations,
                 const std::vector<cv::DetectionROI> &locations,
                 double hitThreshold, int groupThreshold) {
                return instance.detectMultiScaleROI(
                    img, const_off(foundLocations), const_off(locations),
                    hitThreshold, groupThreshold);
              })
      .method("readALTModel",
              [](cv::HOGDescriptor &instance, cv::String modelfile) {
                return instance.readALTModel(modelfile);
              })
      .method("groupRectangles", [](const cv::HOGDescriptor &instance,
                                    const std::vector<cv::Rect> &rectList,
                                    const std::vector<double> &weights,
                                    int groupThreshold, double eps) {
        return instance.groupRectangles(const_off(rectList), const_off(weights),
                                        groupThreshold, eps);
      });
  mod.method("detectQRCode",
             [](const cv::Mat &in, const std::vector<cv::Point> &points) {
               return cv::detectQRCode(cv::InputArray(in), const_off(points));
             });
  mod.method(
      "detectQRCode", [](const cv::Mat &in,
                         const std::vector<cv::Point> &points, double eps_x) {
        return cv::detectQRCode(cv::InputArray(in), const_off(points), eps_x);
      });
  mod.method("detectQRCode",
             [](const cv::Mat &in, const std::vector<cv::Point> &points,
                double eps_x, double eps_y) {
               return cv::detectQRCode(cv::InputArray(in), const_off(points),
                                       eps_x, eps_y);
             });
  mod.add_type<cv::DetectionBasedTracker>("DetectionBasedTracker")
      .constructor<cv::Ptr<cv::DetectionBasedTracker::IDetector>,
                   cv::Ptr<cv::DetectionBasedTracker::IDetector>,
                   const cv::DetectionBasedTracker::Parameters &>()
      .method(
          "run",
          [](cv::DetectionBasedTracker &instance) { return instance.run(); })
      .method(
          "stop",
          [](cv::DetectionBasedTracker &instance) { return instance.stop(); })
      .method("resetTracking",
              [](cv::DetectionBasedTracker &instance) {
                return instance.resetTracking();
              })
      .method(
          "process",
          [](cv::DetectionBasedTracker &instance, const cv::Mat &imageGray) {
            return instance.process(imageGray);
          })
      .method("setParameters",
              [](cv::DetectionBasedTracker &instance,
                 const cv::DetectionBasedTracker::Parameters &params) {
                return instance.setParameters(params);
              })
      .method("getParameters",
              [](const cv::DetectionBasedTracker &instance) {
                return instance.getParameters();
              })
      .method("getObjects",
              [](const cv::DetectionBasedTracker &instance,
                 const std::vector<cv::Rect> &result) {
                return instance.getObjects(const_off(result));
              })
      .method("getObjects",
              [](const cv::DetectionBasedTracker &instance,
                 const std::vector<cv::DetectionBasedTracker::Object> &result) {
                return instance.getObjects(const_off(result));
              })
      .method(
          "getObjects",
          [](const cv::DetectionBasedTracker &instance,
             const std::vector<cv::DetectionBasedTracker::ExtObject> &result) {
            return instance.getObjects(const_off(result));
          })
      .method("addObject", [](cv::DetectionBasedTracker &instance,
                              const cv::Rect &location) {
        return instance.addObject(location);
      });
}
