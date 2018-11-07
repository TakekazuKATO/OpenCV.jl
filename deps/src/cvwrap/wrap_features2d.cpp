#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_features2d_module(Module &mod) {
  mod.add_type<cv::KeyPointsFilter>("KeyPointsFilter")
      .method("runByImageBorder",
              [](cv::KeyPointsFilter &instance,
                 const std::vector<cv::KeyPoint> &keypoints, cv::Size imageSize,
                 int borderSize) {
                return instance.runByImageBorder(const_off(keypoints),
                                                 imageSize, borderSize);
              })
      .method("runByKeypointSize",
              [](cv::KeyPointsFilter &instance,
                 const std::vector<cv::KeyPoint> &keypoints, float minSize) {
                return instance.runByKeypointSize(const_off(keypoints),
                                                  minSize);
              })
      .method("runByKeypointSize",
              [](cv::KeyPointsFilter &instance,
                 const std::vector<cv::KeyPoint> &keypoints, float minSize,
                 float maxSize) {
                return instance.runByKeypointSize(const_off(keypoints), minSize,
                                                  maxSize);
              })
      .method(
          "runByPixelsMask",
          [](cv::KeyPointsFilter &instance,
             const std::vector<cv::KeyPoint> &keypoints, const cv::Mat &mask) {
            return instance.runByPixelsMask(const_off(keypoints), mask);
          })
      .method("removeDuplicated",
              [](cv::KeyPointsFilter &instance,
                 const std::vector<cv::KeyPoint> &keypoints) {
                return instance.removeDuplicated(const_off(keypoints));
              })
      .method("removeDuplicatedSorted",
              [](cv::KeyPointsFilter &instance,
                 const std::vector<cv::KeyPoint> &keypoints) {
                return instance.removeDuplicatedSorted(const_off(keypoints));
              })
      .method("retainBest",
              [](cv::KeyPointsFilter &instance,
                 const std::vector<cv::KeyPoint> &keypoints, int npoints) {
                return instance.retainBest(const_off(keypoints), npoints);
              });
  mod.add_type<cv::Feature2D>("Feature2D")
      .method(
          "detect",
          [](cv::Feature2D &instance, const cv::Mat &image,
             const std::vector<cv::KeyPoint> &keypoints, const cv::Mat &mask) {
            return instance.detect(cv::InputArray(image), const_off(keypoints),
                                   cv::InputArray(mask));
          })
      .method("detect",
              [](cv::Feature2D &instance, const std::vector<cv::Mat> &images,
                 const std::vector<std::vector<cv::KeyPoint>> &keypoints,
                 const std::vector<cv::Mat> &masks) {
                return instance.detect(cv::InputArrayOfArrays(images),
                                       const_off(keypoints),
                                       cv::InputArrayOfArrays(masks));
              })
      .method("compute",
              [](cv::Feature2D &instance, const cv::Mat &image,
                 const std::vector<cv::KeyPoint> &keypoints,
                 const cv::Mat &descriptors) {
                return instance.compute(cv::InputArray(image),
                                        const_off(keypoints),
                                        cv::OutputArray(descriptors));
              })
      .method("compute",
              [](cv::Feature2D &instance, const std::vector<cv::Mat> &images,
                 const std::vector<std::vector<cv::KeyPoint>> &keypoints,
                 const std::vector<cv::Mat> &descriptors) {
                return instance.compute(cv::InputArrayOfArrays(images),
                                        const_off(keypoints),
                                        cv::OutputArrayOfArrays(descriptors));
              })
      .method(
          "detectAndCompute",
          [](cv::Feature2D &instance, const cv::Mat &image, const cv::Mat &mask,
             const std::vector<cv::KeyPoint> &keypoints,
             const cv::Mat &descriptors) {
            return instance.detectAndCompute(
                cv::InputArray(image), cv::InputArray(mask),
                const_off(keypoints), cv::OutputArray(descriptors));
          })
      .method(
          "detectAndCompute",
          [](cv::Feature2D &instance, const cv::Mat &image, const cv::Mat &mask,
             const std::vector<cv::KeyPoint> &keypoints,
             const cv::Mat &descriptors, bool useProvidedKeypoints) {
            return instance.detectAndCompute(
                cv::InputArray(image), cv::InputArray(mask),
                const_off(keypoints), cv::OutputArray(descriptors),
                useProvidedKeypoints);
          })
      .method("descriptorSize",
              [](const cv::Feature2D &instance) {
                return instance.descriptorSize();
              })
      .method("descriptorType",
              [](const cv::Feature2D &instance) {
                return instance.descriptorType();
              })
      .method(
          "defaultNorm",
          [](const cv::Feature2D &instance) { return instance.defaultNorm(); })
      .method("write",
              [](const cv::Feature2D &instance, const cv::String &fileName) {
                return instance.write(fileName);
              })
      .method("read",
              [](cv::Feature2D &instance, const cv::String &fileName) {
                return instance.read(fileName);
              })
      .method("write",
              [](const cv::Feature2D &instance, cv::FileStorage &_argument0) {
                return instance.write(_argument0);
              })
      .method("read",
              [](cv::Feature2D &instance, const cv::FileNode &_argument1) {
                return instance.read(_argument1);
              })
      .method("empty",
              [](const cv::Feature2D &instance) { return instance.empty(); })
      .method("getDefaultName",
              [](const cv::Feature2D &instance) {
                return instance.getDefaultName();
              })
      .method("write",
              [](cv::Feature2D &instance, const cv::Ptr<cv::FileStorage> &fs) {
                return instance.write(fs);
              })
      .method("write",
              [](cv::Feature2D &instance, const cv::Ptr<cv::FileStorage> &fs,
                 const cv::String &name) { return instance.write(fs, name); });
  mod.add_type<cv::BRISK>("BRISK")
      .method("create", [](cv::BRISK &instance) { return instance.create(); })
      .method("create", [](cv::BRISK &instance,
                           int thresh) { return instance.create(thresh); })
      .method("create",
              [](cv::BRISK &instance, int thresh, int octaves) {
                return instance.create(thresh, octaves);
              })
      .method(
          "create",
          [](cv::BRISK &instance, int thresh, int octaves, float patternScale) {
            return instance.create(thresh, octaves, patternScale);
          })
      .method("create",
              [](cv::BRISK &instance, const std::vector<float> &radiusList,
                 const std::vector<int> &numberList) {
                return instance.create(radiusList, numberList);
              })
      .method("create",
              [](cv::BRISK &instance, const std::vector<float> &radiusList,
                 const std::vector<int> &numberList, float dMax) {
                return instance.create(radiusList, numberList, dMax);
              })
      .method("create",
              [](cv::BRISK &instance, const std::vector<float> &radiusList,
                 const std::vector<int> &numberList, float dMax, float dMin) {
                return instance.create(radiusList, numberList, dMax, dMin);
              })
      .method("create",
              [](cv::BRISK &instance, const std::vector<float> &radiusList,
                 const std::vector<int> &numberList, float dMax, float dMin,
                 const std::vector<int> &indexChange) {
                return instance.create(radiusList, numberList, dMax, dMin,
                                       indexChange);
              })
      .method("create",
              [](cv::BRISK &instance, int thresh, int octaves,
                 const std::vector<float> &radiusList,
                 const std::vector<int> &numberList) {
                return instance.create(thresh, octaves, radiusList, numberList);
              })
      .method("create",
              [](cv::BRISK &instance, int thresh, int octaves,
                 const std::vector<float> &radiusList,
                 const std::vector<int> &numberList, float dMax) {
                return instance.create(thresh, octaves, radiusList, numberList,
                                       dMax);
              })
      .method("create",
              [](cv::BRISK &instance, int thresh, int octaves,
                 const std::vector<float> &radiusList,
                 const std::vector<int> &numberList, float dMax, float dMin) {
                return instance.create(thresh, octaves, radiusList, numberList,
                                       dMax, dMin);
              })
      .method("create",
              [](cv::BRISK &instance, int thresh, int octaves,
                 const std::vector<float> &radiusList,
                 const std::vector<int> &numberList, float dMax, float dMin,
                 const std::vector<int> &indexChange) {
                return instance.create(thresh, octaves, radiusList, numberList,
                                       dMax, dMin, indexChange);
              })
      .method("getDefaultName", [](const cv::BRISK &instance) {
        return instance.getDefaultName();
      });
  mod.add_type<cv::ORB>("ORB")
      .method("create", [](cv::ORB &instance) { return instance.create(); })
      .method("create",
              [](cv::ORB &instance, int nfeatures) {
                return instance.create(nfeatures);
              })
      .method("create",
              [](cv::ORB &instance, int nfeatures, float scaleFactor) {
                return instance.create(nfeatures, scaleFactor);
              })
      .method(
          "create",
          [](cv::ORB &instance, int nfeatures, float scaleFactor, int nlevels) {
            return instance.create(nfeatures, scaleFactor, nlevels);
          })
      .method("create",
              [](cv::ORB &instance, int nfeatures, float scaleFactor,
                 int nlevels, int edgeThreshold) {
                return instance.create(nfeatures, scaleFactor, nlevels,
                                       edgeThreshold);
              })
      .method("create",
              [](cv::ORB &instance, int nfeatures, float scaleFactor,
                 int nlevels, int edgeThreshold, int firstLevel) {
                return instance.create(nfeatures, scaleFactor, nlevels,
                                       edgeThreshold, firstLevel);
              })
      .method("create",
              [](cv::ORB &instance, int nfeatures, float scaleFactor,
                 int nlevels, int edgeThreshold, int firstLevel, int WTA_K) {
                return instance.create(nfeatures, scaleFactor, nlevels,
                                       edgeThreshold, firstLevel, WTA_K);
              })
      .method(
          "create",
          [](cv::ORB &instance, int nfeatures, float scaleFactor, int nlevels,
             int edgeThreshold, int firstLevel, int WTA_K, int scoreType) {
            return instance.create(nfeatures, scaleFactor, nlevels,
                                   edgeThreshold, firstLevel, WTA_K, scoreType);
          })
      .method("create",
              [](cv::ORB &instance, int nfeatures, float scaleFactor,
                 int nlevels, int edgeThreshold, int firstLevel, int WTA_K,
                 int scoreType, int patchSize) {
                return instance.create(nfeatures, scaleFactor, nlevels,
                                       edgeThreshold, firstLevel, WTA_K,
                                       scoreType, patchSize);
              })
      .method("create",
              [](cv::ORB &instance, int nfeatures, float scaleFactor,
                 int nlevels, int edgeThreshold, int firstLevel, int WTA_K,
                 int scoreType, int patchSize, int fastThreshold) {
                return instance.create(nfeatures, scaleFactor, nlevels,
                                       edgeThreshold, firstLevel, WTA_K,
                                       scoreType, patchSize, fastThreshold);
              })
      .method("setMaxFeatures",
              [](cv::ORB &instance, int maxFeatures) {
                return instance.setMaxFeatures(maxFeatures);
              })
      .method("getMaxFeatures",
              [](const cv::ORB &instance) { return instance.getMaxFeatures(); })
      .method("setScaleFactor",
              [](cv::ORB &instance, double scaleFactor) {
                return instance.setScaleFactor(scaleFactor);
              })
      .method("getScaleFactor",
              [](const cv::ORB &instance) { return instance.getScaleFactor(); })
      .method("setNLevels",
              [](cv::ORB &instance, int nlevels) {
                return instance.setNLevels(nlevels);
              })
      .method("getNLevels",
              [](const cv::ORB &instance) { return instance.getNLevels(); })
      .method("setEdgeThreshold",
              [](cv::ORB &instance, int edgeThreshold) {
                return instance.setEdgeThreshold(edgeThreshold);
              })
      .method(
          "getEdgeThreshold",
          [](const cv::ORB &instance) { return instance.getEdgeThreshold(); })
      .method("setFirstLevel",
              [](cv::ORB &instance, int firstLevel) {
                return instance.setFirstLevel(firstLevel);
              })
      .method("getFirstLevel",
              [](const cv::ORB &instance) { return instance.getFirstLevel(); })
      .method("setWTA_K", [](cv::ORB &instance,
                             int wta_k) { return instance.setWTA_K(wta_k); })
      .method("getWTA_K",
              [](const cv::ORB &instance) { return instance.getWTA_K(); })
      .method("setScoreType",
              [](cv::ORB &instance, int scoreType) {
                return instance.setScoreType(scoreType);
              })
      .method("getScoreType",
              [](const cv::ORB &instance) { return instance.getScoreType(); })
      .method("setPatchSize",
              [](cv::ORB &instance, int patchSize) {
                return instance.setPatchSize(patchSize);
              })
      .method("getPatchSize",
              [](const cv::ORB &instance) { return instance.getPatchSize(); })
      .method("setFastThreshold",
              [](cv::ORB &instance, int fastThreshold) {
                return instance.setFastThreshold(fastThreshold);
              })
      .method(
          "getFastThreshold",
          [](const cv::ORB &instance) { return instance.getFastThreshold(); })
      .method("getDefaultName", [](const cv::ORB &instance) {
        return instance.getDefaultName();
      });
  mod.add_type<cv::MSER>("MSER")
      .method("create", [](cv::MSER &instance) { return instance.create(); })
      .method("create", [](cv::MSER &instance,
                           int _delta) { return instance.create(_delta); })
      .method("create",
              [](cv::MSER &instance, int _delta, int _min_area) {
                return instance.create(_delta, _min_area);
              })
      .method("create",
              [](cv::MSER &instance, int _delta, int _min_area, int _max_area) {
                return instance.create(_delta, _min_area, _max_area);
              })
      .method("create",
              [](cv::MSER &instance, int _delta, int _min_area, int _max_area,
                 double _max_variation) {
                return instance.create(_delta, _min_area, _max_area,
                                       _max_variation);
              })
      .method("create",
              [](cv::MSER &instance, int _delta, int _min_area, int _max_area,
                 double _max_variation, double _min_diversity) {
                return instance.create(_delta, _min_area, _max_area,
                                       _max_variation, _min_diversity);
              })
      .method(
          "create",
          [](cv::MSER &instance, int _delta, int _min_area, int _max_area,
             double _max_variation, double _min_diversity, int _max_evolution) {
            return instance.create(_delta, _min_area, _max_area, _max_variation,
                                   _min_diversity, _max_evolution);
          })
      .method("create",
              [](cv::MSER &instance, int _delta, int _min_area, int _max_area,
                 double _max_variation, double _min_diversity,
                 int _max_evolution, double _area_threshold) {
                return instance.create(_delta, _min_area, _max_area,
                                       _max_variation, _min_diversity,
                                       _max_evolution, _area_threshold);
              })
      .method(
          "create",
          [](cv::MSER &instance, int _delta, int _min_area, int _max_area,
             double _max_variation, double _min_diversity, int _max_evolution,
             double _area_threshold, double _min_margin) {
            return instance.create(_delta, _min_area, _max_area, _max_variation,
                                   _min_diversity, _max_evolution,
                                   _area_threshold, _min_margin);
          })
      .method(
          "create",
          [](cv::MSER &instance, int _delta, int _min_area, int _max_area,
             double _max_variation, double _min_diversity, int _max_evolution,
             double _area_threshold, double _min_margin, int _edge_blur_size) {
            return instance.create(
                _delta, _min_area, _max_area, _max_variation, _min_diversity,
                _max_evolution, _area_threshold, _min_margin, _edge_blur_size);
          })
      .method("detectRegions",
              [](cv::MSER &instance, const cv::Mat &image,
                 const std::vector<std::vector<cv::Point>> &msers,
                 const std::vector<cv::Rect> &bboxes) {
                return instance.detectRegions(
                    cv::InputArray(image), const_off(msers), const_off(bboxes));
              })
      .method("setDelta", [](cv::MSER &instance,
                             int delta) { return instance.setDelta(delta); })
      .method("getDelta",
              [](const cv::MSER &instance) { return instance.getDelta(); })
      .method("setMinArea",
              [](cv::MSER &instance, int minArea) {
                return instance.setMinArea(minArea);
              })
      .method("getMinArea",
              [](const cv::MSER &instance) { return instance.getMinArea(); })
      .method("setMaxArea",
              [](cv::MSER &instance, int maxArea) {
                return instance.setMaxArea(maxArea);
              })
      .method("getMaxArea",
              [](const cv::MSER &instance) { return instance.getMaxArea(); })
      .method("setPass2Only", [](cv::MSER &instance,
                                 bool f) { return instance.setPass2Only(f); })
      .method("getPass2Only",
              [](const cv::MSER &instance) { return instance.getPass2Only(); })
      .method("getDefaultName", [](const cv::MSER &instance) {
        return instance.getDefaultName();
      });
  mod.method(
      "FAST", [](const cv::Mat &image,
                 const std::vector<cv::KeyPoint> &keypoints, int threshold) {
        return cv::FAST(cv::InputArray(image), const_off(keypoints), threshold);
      });
  mod.method("FAST", [](const cv::Mat &image,
                        const std::vector<cv::KeyPoint> &keypoints,
                        int threshold, bool nonmaxSuppression) {
    return cv::FAST(cv::InputArray(image), const_off(keypoints), threshold,
                    nonmaxSuppression);
  });
  mod.method("FAST", [](const cv::Mat &image,
                        const std::vector<cv::KeyPoint> &keypoints,
                        int threshold, bool nonmaxSuppression, int type) {
    return cv::FAST(cv::InputArray(image), const_off(keypoints), threshold,
                    nonmaxSuppression, type);
  });
  mod.add_type<cv::FastFeatureDetector>("FastFeatureDetector")
      .method(
          "create",
          [](cv::FastFeatureDetector &instance) { return instance.create(); })
      .method("create",
              [](cv::FastFeatureDetector &instance, int threshold) {
                return instance.create(threshold);
              })
      .method("create",
              [](cv::FastFeatureDetector &instance, int threshold,
                 bool nonmaxSuppression) {
                return instance.create(threshold, nonmaxSuppression);
              })
      .method("create",
              [](cv::FastFeatureDetector &instance, int threshold,
                 bool nonmaxSuppression, int type) {
                return instance.create(threshold, nonmaxSuppression, type);
              })
      .method("setThreshold",
              [](cv::FastFeatureDetector &instance, int threshold) {
                return instance.setThreshold(threshold);
              })
      .method("getThreshold",
              [](const cv::FastFeatureDetector &instance) {
                return instance.getThreshold();
              })
      .method("setNonmaxSuppression",
              [](cv::FastFeatureDetector &instance, bool f) {
                return instance.setNonmaxSuppression(f);
              })
      .method("getNonmaxSuppression",
              [](const cv::FastFeatureDetector &instance) {
                return instance.getNonmaxSuppression();
              })
      .method("setType", [](cv::FastFeatureDetector &instance,
                            int type) { return instance.setType(type); })
      .method("getType",
              [](const cv::FastFeatureDetector &instance) {
                return instance.getType();
              })
      .method("getDefaultName", [](const cv::FastFeatureDetector &instance) {
        return instance.getDefaultName();
      });
  mod.method("AGAST", [](const cv::Mat &image,
                         const std::vector<cv::KeyPoint> &keypoints,
                         int threshold) {
    return cv::AGAST(cv::InputArray(image), const_off(keypoints), threshold);
  });
  mod.method("AGAST", [](const cv::Mat &image,
                         const std::vector<cv::KeyPoint> &keypoints,
                         int threshold, bool nonmaxSuppression) {
    return cv::AGAST(cv::InputArray(image), const_off(keypoints), threshold,
                     nonmaxSuppression);
  });
  mod.method("AGAST", [](const cv::Mat &image,
                         const std::vector<cv::KeyPoint> &keypoints,
                         int threshold, bool nonmaxSuppression, int type) {
    return cv::AGAST(cv::InputArray(image), const_off(keypoints), threshold,
                     nonmaxSuppression, type);
  });
  mod.add_type<cv::AgastFeatureDetector>("AgastFeatureDetector")
      .method(
          "create",
          [](cv::AgastFeatureDetector &instance) { return instance.create(); })
      .method("create",
              [](cv::AgastFeatureDetector &instance, int threshold) {
                return instance.create(threshold);
              })
      .method("create",
              [](cv::AgastFeatureDetector &instance, int threshold,
                 bool nonmaxSuppression) {
                return instance.create(threshold, nonmaxSuppression);
              })
      .method("create",
              [](cv::AgastFeatureDetector &instance, int threshold,
                 bool nonmaxSuppression, int type) {
                return instance.create(threshold, nonmaxSuppression, type);
              })
      .method("setThreshold",
              [](cv::AgastFeatureDetector &instance, int threshold) {
                return instance.setThreshold(threshold);
              })
      .method("getThreshold",
              [](const cv::AgastFeatureDetector &instance) {
                return instance.getThreshold();
              })
      .method("setNonmaxSuppression",
              [](cv::AgastFeatureDetector &instance, bool f) {
                return instance.setNonmaxSuppression(f);
              })
      .method("getNonmaxSuppression",
              [](const cv::AgastFeatureDetector &instance) {
                return instance.getNonmaxSuppression();
              })
      .method("setType", [](cv::AgastFeatureDetector &instance,
                            int type) { return instance.setType(type); })
      .method("getType",
              [](const cv::AgastFeatureDetector &instance) {
                return instance.getType();
              })
      .method("getDefaultName", [](const cv::AgastFeatureDetector &instance) {
        return instance.getDefaultName();
      });
  mod.add_type<cv::GFTTDetector>("GFTTDetector")
      .method("create",
              [](cv::GFTTDetector &instance) { return instance.create(); })
      .method("create",
              [](cv::GFTTDetector &instance, int maxCorners) {
                return instance.create(maxCorners);
              })
      .method(
          "create",
          [](cv::GFTTDetector &instance, int maxCorners, double qualityLevel) {
            return instance.create(maxCorners, qualityLevel);
          })
      .method("create",
              [](cv::GFTTDetector &instance, int maxCorners,
                 double qualityLevel, double minDistance) {
                return instance.create(maxCorners, qualityLevel, minDistance);
              })
      .method("create",
              [](cv::GFTTDetector &instance, int maxCorners,
                 double qualityLevel, double minDistance, int blockSize) {
                return instance.create(maxCorners, qualityLevel, minDistance,
                                       blockSize);
              })
      .method(
          "create",
          [](cv::GFTTDetector &instance, int maxCorners, double qualityLevel,
             double minDistance, int blockSize, bool useHarrisDetector) {
            return instance.create(maxCorners, qualityLevel, minDistance,
                                   blockSize, useHarrisDetector);
          })
      .method("create",
              [](cv::GFTTDetector &instance, int maxCorners,
                 double qualityLevel, double minDistance, int blockSize,
                 bool useHarrisDetector, double k) {
                return instance.create(maxCorners, qualityLevel, minDistance,
                                       blockSize, useHarrisDetector, k);
              })
      .method(
          "create",
          [](cv::GFTTDetector &instance, int maxCorners, double qualityLevel,
             double minDistance, int blockSize, int gradiantSize) {
            return instance.create(maxCorners, qualityLevel, minDistance,
                                   blockSize, gradiantSize);
          })
      .method("create",
              [](cv::GFTTDetector &instance, int maxCorners,
                 double qualityLevel, double minDistance, int blockSize,
                 int gradiantSize, bool useHarrisDetector) {
                return instance.create(maxCorners, qualityLevel, minDistance,
                                       blockSize, gradiantSize,
                                       useHarrisDetector);
              })
      .method("create",
              [](cv::GFTTDetector &instance, int maxCorners,
                 double qualityLevel, double minDistance, int blockSize,
                 int gradiantSize, bool useHarrisDetector, double k) {
                return instance.create(maxCorners, qualityLevel, minDistance,
                                       blockSize, gradiantSize,
                                       useHarrisDetector, k);
              })
      .method("setMaxFeatures",
              [](cv::GFTTDetector &instance, int maxFeatures) {
                return instance.setMaxFeatures(maxFeatures);
              })
      .method("getMaxFeatures",
              [](const cv::GFTTDetector &instance) {
                return instance.getMaxFeatures();
              })
      .method("setQualityLevel",
              [](cv::GFTTDetector &instance, double qlevel) {
                return instance.setQualityLevel(qlevel);
              })
      .method("getQualityLevel",
              [](const cv::GFTTDetector &instance) {
                return instance.getQualityLevel();
              })
      .method("setMinDistance",
              [](cv::GFTTDetector &instance, double minDistance) {
                return instance.setMinDistance(minDistance);
              })
      .method("getMinDistance",
              [](const cv::GFTTDetector &instance) {
                return instance.getMinDistance();
              })
      .method("setBlockSize",
              [](cv::GFTTDetector &instance, int blockSize) {
                return instance.setBlockSize(blockSize);
              })
      .method("getBlockSize",
              [](const cv::GFTTDetector &instance) {
                return instance.getBlockSize();
              })
      .method("setHarrisDetector",
              [](cv::GFTTDetector &instance, bool val) {
                return instance.setHarrisDetector(val);
              })
      .method("getHarrisDetector",
              [](const cv::GFTTDetector &instance) {
                return instance.getHarrisDetector();
              })
      .method("setK", [](cv::GFTTDetector &instance,
                         double k) { return instance.setK(k); })
      .method("getK",
              [](const cv::GFTTDetector &instance) { return instance.getK(); })
      .method("getDefaultName", [](const cv::GFTTDetector &instance) {
        return instance.getDefaultName();
      });
  mod.add_type<cv::SimpleBlobDetector>("SimpleBlobDetector")
      .method(
          "create",
          [](cv::SimpleBlobDetector &instance) { return instance.create(); })
      .method("create",
              [](cv::SimpleBlobDetector &instance,
                 const cv::SimpleBlobDetector::Params &parameters) {
                return instance.create(parameters);
              })
      .method("getDefaultName", [](const cv::SimpleBlobDetector &instance) {
        return instance.getDefaultName();
      });
  mod.add_type<cv::KAZE>("KAZE")
      .method("create", [](cv::KAZE &instance) { return instance.create(); })
      .method("create", [](cv::KAZE &instance,
                           bool extended) { return instance.create(extended); })
      .method("create",
              [](cv::KAZE &instance, bool extended, bool upright) {
                return instance.create(extended, upright);
              })
      .method(
          "create",
          [](cv::KAZE &instance, bool extended, bool upright, float threshold) {
            return instance.create(extended, upright, threshold);
          })
      .method("create",
              [](cv::KAZE &instance, bool extended, bool upright,
                 float threshold, int nOctaves) {
                return instance.create(extended, upright, threshold, nOctaves);
              })
      .method("create",
              [](cv::KAZE &instance, bool extended, bool upright,
                 float threshold, int nOctaves, int nOctaveLayers) {
                return instance.create(extended, upright, threshold, nOctaves,
                                       nOctaveLayers);
              })
      .method(
          "create",
          [](cv::KAZE &instance, bool extended, bool upright, float threshold,
             int nOctaves, int nOctaveLayers, int diffusivity) {
            return instance.create(extended, upright, threshold, nOctaves,
                                   nOctaveLayers, diffusivity);
          })
      .method("setExtended",
              [](cv::KAZE &instance, bool extended) {
                return instance.setExtended(extended);
              })
      .method("getExtended",
              [](const cv::KAZE &instance) { return instance.getExtended(); })
      .method("setUpright",
              [](cv::KAZE &instance, bool upright) {
                return instance.setUpright(upright);
              })
      .method("getUpright",
              [](const cv::KAZE &instance) { return instance.getUpright(); })
      .method("setThreshold",
              [](cv::KAZE &instance, double threshold) {
                return instance.setThreshold(threshold);
              })
      .method("getThreshold",
              [](const cv::KAZE &instance) { return instance.getThreshold(); })
      .method("setNOctaves",
              [](cv::KAZE &instance, int octaves) {
                return instance.setNOctaves(octaves);
              })
      .method("getNOctaves",
              [](const cv::KAZE &instance) { return instance.getNOctaves(); })
      .method("setNOctaveLayers",
              [](cv::KAZE &instance, int octaveLayers) {
                return instance.setNOctaveLayers(octaveLayers);
              })
      .method(
          "getNOctaveLayers",
          [](const cv::KAZE &instance) { return instance.getNOctaveLayers(); })
      .method("setDiffusivity",
              [](cv::KAZE &instance, int diff) {
                return instance.setDiffusivity(diff);
              })
      .method(
          "getDiffusivity",
          [](const cv::KAZE &instance) { return instance.getDiffusivity(); })
      .method("getDefaultName", [](const cv::KAZE &instance) {
        return instance.getDefaultName();
      });
  mod.add_type<cv::AKAZE>("AKAZE")
      .method("create", [](cv::AKAZE &instance) { return instance.create(); })
      .method("create",
              [](cv::AKAZE &instance, int descriptor_type) {
                return instance.create(descriptor_type);
              })
      .method(
          "create",
          [](cv::AKAZE &instance, int descriptor_type, int descriptor_size) {
            return instance.create(descriptor_type, descriptor_size);
          })
      .method("create",
              [](cv::AKAZE &instance, int descriptor_type, int descriptor_size,
                 int descriptor_channels) {
                return instance.create(descriptor_type, descriptor_size,
                                       descriptor_channels);
              })
      .method("create",
              [](cv::AKAZE &instance, int descriptor_type, int descriptor_size,
                 int descriptor_channels, float threshold) {
                return instance.create(descriptor_type, descriptor_size,
                                       descriptor_channels, threshold);
              })
      .method("create",
              [](cv::AKAZE &instance, int descriptor_type, int descriptor_size,
                 int descriptor_channels, float threshold, int nOctaves) {
                return instance.create(descriptor_type, descriptor_size,
                                       descriptor_channels, threshold,
                                       nOctaves);
              })
      .method("create",
              [](cv::AKAZE &instance, int descriptor_type, int descriptor_size,
                 int descriptor_channels, float threshold, int nOctaves,
                 int nOctaveLayers) {
                return instance.create(descriptor_type, descriptor_size,
                                       descriptor_channels, threshold, nOctaves,
                                       nOctaveLayers);
              })
      .method("create",
              [](cv::AKAZE &instance, int descriptor_type, int descriptor_size,
                 int descriptor_channels, float threshold, int nOctaves,
                 int nOctaveLayers, int diffusivity) {
                return instance.create(descriptor_type, descriptor_size,
                                       descriptor_channels, threshold, nOctaves,
                                       nOctaveLayers, diffusivity);
              })
      .method("setDescriptorType",
              [](cv::AKAZE &instance, int dtype) {
                return instance.setDescriptorType(dtype);
              })
      .method("getDescriptorType",
              [](const cv::AKAZE &instance) {
                return instance.getDescriptorType();
              })
      .method("setDescriptorSize",
              [](cv::AKAZE &instance, int dsize) {
                return instance.setDescriptorSize(dsize);
              })
      .method("getDescriptorSize",
              [](const cv::AKAZE &instance) {
                return instance.getDescriptorSize();
              })
      .method("setDescriptorChannels",
              [](cv::AKAZE &instance, int dch) {
                return instance.setDescriptorChannels(dch);
              })
      .method("getDescriptorChannels",
              [](const cv::AKAZE &instance) {
                return instance.getDescriptorChannels();
              })
      .method("setThreshold",
              [](cv::AKAZE &instance, double threshold) {
                return instance.setThreshold(threshold);
              })
      .method("getThreshold",
              [](const cv::AKAZE &instance) { return instance.getThreshold(); })
      .method("setNOctaves",
              [](cv::AKAZE &instance, int octaves) {
                return instance.setNOctaves(octaves);
              })
      .method("getNOctaves",
              [](const cv::AKAZE &instance) { return instance.getNOctaves(); })
      .method("setNOctaveLayers",
              [](cv::AKAZE &instance, int octaveLayers) {
                return instance.setNOctaveLayers(octaveLayers);
              })
      .method(
          "getNOctaveLayers",
          [](const cv::AKAZE &instance) { return instance.getNOctaveLayers(); })
      .method("setDiffusivity",
              [](cv::AKAZE &instance, int diff) {
                return instance.setDiffusivity(diff);
              })
      .method(
          "getDiffusivity",
          [](const cv::AKAZE &instance) { return instance.getDiffusivity(); })
      .method("getDefaultName", [](const cv::AKAZE &instance) {
        return instance.getDefaultName();
      });
  mod.add_type<Parametric<TypeVar<1>>>("Accumulator")
      .apply<cv::Accumulator<int>, cv::Accumulator<int64_t>,
             cv::Accumulator<uchar>, cv::Accumulator<short>,
             cv::Accumulator<ushort>, cv::Accumulator<float>,
             cv::Accumulator<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped;
      });
  mod.add_type<Parametric<TypeVar<1>>>("SL2")
      .apply<cv::SL2<int>, cv::SL2<int64_t>, cv::SL2<uchar>, cv::SL2<short>,
             cv::SL2<ushort>, cv::SL2<float>, cv::SL2<double>>(
          [](auto wrapped) {
            typedef typename decltype(wrapped)::type WrappedT;
            typedef typename get_template_type<WrappedT>::type ValueT;
            wrapped.method(
                [](WrappedT &instance, const ValueT *a, const ValueT *b,
                   int size) { return instance.operator()(a, b, size); });
          });
  mod.add_type<Parametric<TypeVar<1>>>("L2")
      .apply<cv::L2<int>, cv::L2<int64_t>, cv::L2<uchar>, cv::L2<short>,
             cv::L2<ushort>, cv::L2<float>, cv::L2<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.method(
            [](WrappedT &instance, const ValueT *a, const ValueT *b, int size) {
              return instance.operator()(a, b, size);
            });
      });
  mod.add_type<Parametric<TypeVar<1>>>("L1")
      .apply<cv::L1<int>, cv::L1<int64_t>, cv::L1<uchar>, cv::L1<short>,
             cv::L1<ushort>, cv::L1<float>, cv::L1<double>>([](auto wrapped) {
        typedef typename decltype(wrapped)::type WrappedT;
        typedef typename get_template_type<WrappedT>::type ValueT;
        wrapped.method(
            [](WrappedT &instance, const ValueT *a, const ValueT *b, int size) {
              return instance.operator()(a, b, size);
            });
      });
  mod.add_type<cv::DescriptorMatcher>("DescriptorMatcher")
      .method("add",
              [](cv::DescriptorMatcher &instance,
                 const std::vector<cv::Mat> &descriptors) {
                return instance.add(cv::InputArrayOfArrays(descriptors));
              })
      .method("getTrainDescriptors",
              [](const cv::DescriptorMatcher &instance) {
                return instance.getTrainDescriptors();
              })
      .method("clear",
              [](cv::DescriptorMatcher &instance) { return instance.clear(); })
      .method("empty",
              [](const cv::DescriptorMatcher &instance) {
                return instance.empty();
              })
      .method("isMaskSupported",
              [](const cv::DescriptorMatcher &instance) {
                return instance.isMaskSupported();
              })
      .method("train",
              [](cv::DescriptorMatcher &instance) { return instance.train(); })
      .method(
          "match",
          [](const cv::DescriptorMatcher &instance,
             const cv::Mat &queryDescriptors, const cv::Mat &trainDescriptors,
             const std::vector<cv::DMatch> &matches, const cv::Mat &mask) {
            return instance.match(cv::InputArray(queryDescriptors),
                                  cv::InputArray(trainDescriptors),
                                  const_off(matches), cv::InputArray(mask));
          })
      .method(
          "knnMatch",
          [](const cv::DescriptorMatcher &instance,
             const cv::Mat &queryDescriptors, const cv::Mat &trainDescriptors,
             const std::vector<std::vector<cv::DMatch>> &matches, int k,
             const cv::Mat &mask) {
            return instance.knnMatch(cv::InputArray(queryDescriptors),
                                     cv::InputArray(trainDescriptors),
                                     const_off(matches), k,
                                     cv::InputArray(mask));
          })
      .method(
          "knnMatch",
          [](const cv::DescriptorMatcher &instance,
             const cv::Mat &queryDescriptors, const cv::Mat &trainDescriptors,
             const std::vector<std::vector<cv::DMatch>> &matches, int k,
             const cv::Mat &mask, bool compactResult) {
            return instance.knnMatch(cv::InputArray(queryDescriptors),
                                     cv::InputArray(trainDescriptors),
                                     const_off(matches), k,
                                     cv::InputArray(mask), compactResult);
          })
      .method(
          "radiusMatch",
          [](const cv::DescriptorMatcher &instance,
             const cv::Mat &queryDescriptors, const cv::Mat &trainDescriptors,
             const std::vector<std::vector<cv::DMatch>> &matches,
             float maxDistance, const cv::Mat &mask) {
            return instance.radiusMatch(cv::InputArray(queryDescriptors),
                                        cv::InputArray(trainDescriptors),
                                        const_off(matches), maxDistance,
                                        cv::InputArray(mask));
          })
      .method(
          "radiusMatch",
          [](const cv::DescriptorMatcher &instance,
             const cv::Mat &queryDescriptors, const cv::Mat &trainDescriptors,
             const std::vector<std::vector<cv::DMatch>> &matches,
             float maxDistance, const cv::Mat &mask, bool compactResult) {
            return instance.radiusMatch(cv::InputArray(queryDescriptors),
                                        cv::InputArray(trainDescriptors),
                                        const_off(matches), maxDistance,
                                        cv::InputArray(mask), compactResult);
          })
      .method(
          "match",
          [](cv::DescriptorMatcher &instance, const cv::Mat &queryDescriptors,
             const std::vector<cv::DMatch> &matches,
             const std::vector<cv::Mat> &masks) {
            return instance.match(cv::InputArray(queryDescriptors),
                                  const_off(matches),
                                  cv::InputArrayOfArrays(masks));
          })
      .method(
          "knnMatch",
          [](cv::DescriptorMatcher &instance, const cv::Mat &queryDescriptors,
             const std::vector<std::vector<cv::DMatch>> &matches, int k,
             const std::vector<cv::Mat> &masks) {
            return instance.knnMatch(cv::InputArray(queryDescriptors),
                                     const_off(matches), k,
                                     cv::InputArrayOfArrays(masks));
          })
      .method(
          "knnMatch",
          [](cv::DescriptorMatcher &instance, const cv::Mat &queryDescriptors,
             const std::vector<std::vector<cv::DMatch>> &matches, int k,
             const std::vector<cv::Mat> &masks, bool compactResult) {
            return instance.knnMatch(
                cv::InputArray(queryDescriptors), const_off(matches), k,
                cv::InputArrayOfArrays(masks), compactResult);
          })
      .method(
          "radiusMatch",
          [](cv::DescriptorMatcher &instance, const cv::Mat &queryDescriptors,
             const std::vector<std::vector<cv::DMatch>> &matches,
             float maxDistance, const std::vector<cv::Mat> &masks) {
            return instance.radiusMatch(cv::InputArray(queryDescriptors),
                                        const_off(matches), maxDistance,
                                        cv::InputArrayOfArrays(masks));
          })
      .method(
          "radiusMatch",
          [](cv::DescriptorMatcher &instance, const cv::Mat &queryDescriptors,
             const std::vector<std::vector<cv::DMatch>> &matches,
             float maxDistance, const std::vector<cv::Mat> &masks,
             bool compactResult) {
            return instance.radiusMatch(
                cv::InputArray(queryDescriptors), const_off(matches),
                maxDistance, cv::InputArrayOfArrays(masks), compactResult);
          })
      .method("write",
              [](cv::DescriptorMatcher &instance, const cv::String &fileName) {
                return instance.write(fileName);
              })
      .method("read",
              [](cv::DescriptorMatcher &instance, const cv::String &fileName) {
                return instance.read(fileName);
              })
      .method(
          "read",
          [](cv::DescriptorMatcher &instance, const cv::FileNode &_argument2) {
            return instance.read(_argument2);
          })
      .method("write",
              [](const cv::DescriptorMatcher &instance,
                 cv::FileStorage &_argument3) {
                return instance.write(_argument3);
              })
      .method("clone",
              [](const cv::DescriptorMatcher &instance) {
                return instance.clone();
              })
      .method("clone",
              [](const cv::DescriptorMatcher &instance, bool emptyTrainData) {
                return instance.clone(emptyTrainData);
              })
      .method("create",
              [](cv::DescriptorMatcher &instance,
                 const cv::String &descriptorMatcherType) {
                return instance.create(descriptorMatcherType);
              })
      .method("create",
              [](cv::DescriptorMatcher &instance, int matcherType) {
                return instance.create(matcherType);
              })
      .method(
          "write",
          [](cv::DescriptorMatcher &instance,
             const cv::Ptr<cv::FileStorage> &fs) { return instance.write(fs); })
      .method("write",
              [](cv::DescriptorMatcher &instance,
                 const cv::Ptr<cv::FileStorage> &fs,
                 const cv::String &name) { return instance.write(fs, name); });
  mod.add_type<cv::BFMatcher>("BFMatcher")
      .constructor<int, bool>()
      .method("isMaskSupported",
              [](const cv::BFMatcher &instance) {
                return instance.isMaskSupported();
              })
      .method("create",
              [](cv::BFMatcher &instance) { return instance.create(); })
      .method("create", [](cv::BFMatcher &instance,
                           int normType) { return instance.create(normType); })
      .method("create",
              [](cv::BFMatcher &instance, int normType, bool crossCheck) {
                return instance.create(normType, crossCheck);
              })
      .method("clone",
              [](const cv::BFMatcher &instance) { return instance.clone(); })
      .method("clone", [](const cv::BFMatcher &instance, bool emptyTrainData) {
        return instance.clone(emptyTrainData);
      });
  mod.add_type<cv::FlannBasedMatcher>("FlannBasedMatcher")
      .constructor<const Ptr<flann::IndexParams> &,
                   const Ptr<flann::SearchParams> &>()
      .method("add",
              [](cv::FlannBasedMatcher &instance,
                 const std::vector<cv::Mat> &descriptors) {
                return instance.add(cv::InputArrayOfArrays(descriptors));
              })
      .method("clear",
              [](cv::FlannBasedMatcher &instance) { return instance.clear(); })
      .method(
          "read",
          [](cv::FlannBasedMatcher &instance, const cv::FileNode &_argument4) {
            return instance.read(_argument4);
          })
      .method("write",
              [](const cv::FlannBasedMatcher &instance,
                 cv::FileStorage &_argument5) {
                return instance.write(_argument5);
              })
      .method("train",
              [](cv::FlannBasedMatcher &instance) { return instance.train(); })
      .method("isMaskSupported",
              [](const cv::FlannBasedMatcher &instance) {
                return instance.isMaskSupported();
              })
      .method("create",
              [](cv::FlannBasedMatcher &instance) { return instance.create(); })
      .method("clone",
              [](const cv::FlannBasedMatcher &instance) {
                return instance.clone();
              })
      .method("clone",
              [](const cv::FlannBasedMatcher &instance, bool emptyTrainData) {
                return instance.clone(emptyTrainData);
              });
  mod.add_type<cv::DrawMatchesFlags>("DrawMatchesFlags");
  mod.method("drawKeypoints", [](const cv::Mat &image,
                                 const std::vector<cv::KeyPoint> &keypoints,
                                 const cv::Mat &outImage) {
    return cv::drawKeypoints(cv::InputArray(image), keypoints,
                             cv::InputOutputArray(outImage));
  });
  mod.method(
      "drawKeypoints",
      [](const cv::Mat &image, const std::vector<cv::KeyPoint> &keypoints,
         const cv::Mat &outImage, const cv::Scalar &color) {
        return cv::drawKeypoints(cv::InputArray(image), keypoints,
                                 cv::InputOutputArray(outImage), color);
      });
  mod.method(
      "drawKeypoints",
      [](const cv::Mat &image, const std::vector<cv::KeyPoint> &keypoints,
         const cv::Mat &outImage, const cv::Scalar &color, int flags) {
        return cv::drawKeypoints(cv::InputArray(image), keypoints,
                                 cv::InputOutputArray(outImage), color, flags);
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<cv::DMatch> &matches1to2, const cv::Mat &outImg) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg));
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<cv::DMatch> &matches1to2, const cv::Mat &outImg,
         const cv::Scalar &matchColor) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg), matchColor);
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<cv::DMatch> &matches1to2, const cv::Mat &outImg,
         const cv::Scalar &matchColor, const cv::Scalar &singlePointColor) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg), matchColor,
                               singlePointColor);
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<cv::DMatch> &matches1to2, const cv::Mat &outImg,
         const cv::Scalar &matchColor, const cv::Scalar &singlePointColor,
         const std::vector<char> &matchesMask) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg), matchColor,
                               singlePointColor, matchesMask);
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<cv::DMatch> &matches1to2, const cv::Mat &outImg,
         const cv::Scalar &matchColor, const cv::Scalar &singlePointColor,
         const std::vector<char> &matchesMask, int flags) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg), matchColor,
                               singlePointColor, matchesMask, flags);
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<std::vector<cv::DMatch>> &matches1to2,
         const cv::Mat &outImg) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg));
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<std::vector<cv::DMatch>> &matches1to2,
         const cv::Mat &outImg, const cv::Scalar &matchColor) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg), matchColor);
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<std::vector<cv::DMatch>> &matches1to2,
         const cv::Mat &outImg, const cv::Scalar &matchColor,
         const cv::Scalar &singlePointColor) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg), matchColor,
                               singlePointColor);
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<std::vector<cv::DMatch>> &matches1to2,
         const cv::Mat &outImg, const cv::Scalar &matchColor,
         const cv::Scalar &singlePointColor,
         const std::vector<std::vector<char>> &matchesMask) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg), matchColor,
                               singlePointColor, matchesMask);
      });
  mod.method(
      "drawMatches",
      [](const cv::Mat &img1, const std::vector<cv::KeyPoint> &keypoints1,
         const cv::Mat &img2, const std::vector<cv::KeyPoint> &keypoints2,
         const std::vector<std::vector<cv::DMatch>> &matches1to2,
         const cv::Mat &outImg, const cv::Scalar &matchColor,
         const cv::Scalar &singlePointColor,
         const std::vector<std::vector<char>> &matchesMask, int flags) {
        return cv::drawMatches(cv::InputArray(img1), keypoints1,
                               cv::InputArray(img2), keypoints2, matches1to2,
                               cv::InputOutputArray(outImg), matchColor,
                               singlePointColor, matchesMask, flags);
      });
  /*mod.method("evaluateFeatureDetector", [](const cv::Mat &img1,const cv::Mat
  &img2,const cv::Mat &H1to2,std::vector<cv::KeyPoint >
  *keypoints1,std::vector<cv::KeyPoint > *keypoints2,float &repeatability,int
  &correspCount) { return cv::evaluateFeatureDetector(
  img1,img2,H1to2,keypoints1,keypoints2,repeatability,correspCount );
  });
  mod.method("evaluateFeatureDetector", [](const cv::Mat &img1,const cv::Mat
  &img2,const cv::Mat &H1to2,std::vector<cv::KeyPoint >
  *keypoints1,std::vector<cv::KeyPoint > *keypoints2,float &repeatability,int
  &correspCount,const cv::Ptr<cv::FeatureDetector > &fdetector) { return
  cv::evaluateFeatureDetector(
  img1,img2,H1to2,keypoints1,keypoints2,repeatability,correspCount,fdetector );
  });*/
  mod.method("computeRecallPrecisionCurve",
             [](const std::vector<std::vector<cv::DMatch>> &matches1to2,
                const std::vector<std::vector<uchar>> &correctMatches1to2Mask,
                const std::vector<cv::Point2f> &recallPrecisionCurve) {
               return cv::computeRecallPrecisionCurve(
                   matches1to2, correctMatches1to2Mask,
                   const_off(recallPrecisionCurve));
             });
  mod.method("getRecall",
             [](const std::vector<cv::Point2f> &recallPrecisionCurve,
                float l_precision) {
               return cv::getRecall(recallPrecisionCurve, l_precision);
             });
  mod.method("getNearestPoint",
             [](const std::vector<cv::Point2f> &recallPrecisionCurve,
                float l_precision) {
               return cv::getNearestPoint(recallPrecisionCurve, l_precision);
             });
  mod.add_type<cv::BOWTrainer>("BOWTrainer")
      .method("add",
              [](cv::BOWTrainer &instance, const cv::Mat &descriptors) {
                return instance.add(descriptors);
              })
      .method("getDescriptors",
              [](const cv::BOWTrainer &instance) {
                return instance.getDescriptors();
              })
      .method("descriptorsCount",
              [](const cv::BOWTrainer &instance) {
                return instance.descriptorsCount();
              })
      .method("clear",
              [](cv::BOWTrainer &instance) { return instance.clear(); })
      .method("cluster",
              [](const cv::BOWTrainer &instance) { return instance.cluster(); })
      .method("cluster",
              [](const cv::BOWTrainer &instance, const cv::Mat &descriptors) {
                return instance.cluster(descriptors);
              });
  mod.add_type<cv::BOWKMeansTrainer>("BOWKMeansTrainer")
      .constructor<int, const cv::TermCriteria &, int, int>()
      .method("cluster",
              [](const cv::BOWKMeansTrainer &instance) {
                return instance.cluster();
              })
      .method("cluster", [](const cv::BOWKMeansTrainer &instance,
                            const cv::Mat &descriptors) {
        return instance.cluster(descriptors);
      });
  mod.add_type<cv::BOWImgDescriptorExtractor>("BOWImgDescriptorExtractor")
      .constructor<const Ptr<cv::DescriptorExtractor> &,
                   const Ptr<cv::DescriptorMatcher> &>()
      .constructor<const Ptr<cv::DescriptorMatcher> &>()
      .method("setVocabulary",
              [](cv::BOWImgDescriptorExtractor &instance,
                 const cv::Mat &vocabulary) {
                return instance.setVocabulary(vocabulary);
              })
      .method("getVocabulary",
              [](const cv::BOWImgDescriptorExtractor &instance) {
                return instance.getVocabulary();
              })
      .method("compute",
              [](cv::BOWImgDescriptorExtractor &instance, const cv::Mat &image,
                 const std::vector<cv::KeyPoint> &keypoints,
                 const cv::Mat &imgDescriptor) {
                return instance.compute(cv::InputArray(image),
                                        const_off(keypoints),
                                        cv::OutputArray(imgDescriptor));
              })
      /*.method("compute",
              [](cv::BOWImgDescriptorExtractor &instance, const cv::Mat &image,
                 const std::vector<cv::KeyPoint> &keypoints,
                 const cv::Mat &imgDescriptor,
                 std::vector<std::vector<int>> *pointIdxsOfClusters) {
                return instance.compute(
                    cv::InputArray(image), const_off(keypoints),
                    cv::OutputArray(imgDescriptor), pointIdxsOfClusters);
              })*/
      .method(
          "compute",
          [](cv::BOWImgDescriptorExtractor &instance,
             const cv::Mat &keypointDescriptors, const cv::Mat &imgDescriptor) {
            return instance.compute(cv::InputArray(keypointDescriptors),
                                    cv::OutputArray(imgDescriptor));
          })
      /*.method(
          "compute",
          [](cv::BOWImgDescriptorExtractor &instance,
             const cv::Mat &keypointDescriptors, const cv::Mat &imgDescriptor,
             std::vector<std::vector<int>> *pointIdxsOfClusters) {
            return instance.compute(cv::InputArray(keypointDescriptors),
                                    cv::OutputArray(imgDescriptor),
                                    pointIdxsOfClusters);
          })*/
      .method("descriptorSize",
              [](const cv::BOWImgDescriptorExtractor &instance) {
                return instance.descriptorSize();
              })
      .method("descriptorType",
              [](const cv::BOWImgDescriptorExtractor &instance) {
                return instance.descriptorType();
              });
}
