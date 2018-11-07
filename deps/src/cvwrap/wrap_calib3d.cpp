#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_calib3d_module(Module &mod) {
  mod.set_const("LMEDS", (int)cv::LMEDS);
  mod.set_const("RANSAC", (int)cv::RANSAC);
  mod.set_const("RHO", (int)cv::RHO);
  mod.set_const("SOLVEPNP_ITERATIVE", (int)cv::SOLVEPNP_ITERATIVE);
  mod.set_const("SOLVEPNP_EPNP", (int)cv::SOLVEPNP_EPNP);
  mod.set_const("SOLVEPNP_P3P", (int)cv::SOLVEPNP_P3P);
  mod.set_const("SOLVEPNP_DLS", (int)cv::SOLVEPNP_DLS);
  mod.set_const("SOLVEPNP_UPNP", (int)cv::SOLVEPNP_UPNP);
  mod.set_const("SOLVEPNP_AP3P", (int)cv::SOLVEPNP_AP3P);
  mod.set_const("SOLVEPNP_MAX_COUNT", (int)cv::SOLVEPNP_MAX_COUNT);
  mod.set_const("CALIB_CB_ADAPTIVE_THRESH", (int)cv::CALIB_CB_ADAPTIVE_THRESH);
  mod.set_const("CALIB_CB_NORMALIZE_IMAGE", (int)cv::CALIB_CB_NORMALIZE_IMAGE);
  mod.set_const("CALIB_CB_FILTER_QUADS", (int)cv::CALIB_CB_FILTER_QUADS);
  mod.set_const("CALIB_CB_FAST_CHECK", (int)cv::CALIB_CB_FAST_CHECK);
  mod.set_const("CALIB_CB_SYMMETRIC_GRID", (int)cv::CALIB_CB_SYMMETRIC_GRID);
  mod.set_const("CALIB_CB_ASYMMETRIC_GRID", (int)cv::CALIB_CB_ASYMMETRIC_GRID);
  mod.set_const("CALIB_CB_CLUSTERING", (int)cv::CALIB_CB_CLUSTERING);
  mod.set_const("CALIB_USE_INTRINSIC_GUESS",
                (int)cv::CALIB_USE_INTRINSIC_GUESS);
  mod.set_const("CALIB_FIX_ASPECT_RATIO", (int)cv::CALIB_FIX_ASPECT_RATIO);
  mod.set_const("CALIB_FIX_PRINCIPAL_POINT",
                (int)cv::CALIB_FIX_PRINCIPAL_POINT);
  mod.set_const("CALIB_ZERO_TANGENT_DIST", (int)cv::CALIB_ZERO_TANGENT_DIST);
  mod.set_const("CALIB_FIX_FOCAL_LENGTH", (int)cv::CALIB_FIX_FOCAL_LENGTH);
  mod.set_const("CALIB_FIX_K1", (int)cv::CALIB_FIX_K1);
  mod.set_const("CALIB_FIX_K2", (int)cv::CALIB_FIX_K2);
  mod.set_const("CALIB_FIX_K3", (int)cv::CALIB_FIX_K3);
  mod.set_const("CALIB_FIX_K4", (int)cv::CALIB_FIX_K4);
  mod.set_const("CALIB_FIX_K5", (int)cv::CALIB_FIX_K5);
  mod.set_const("CALIB_FIX_K6", (int)cv::CALIB_FIX_K6);
  mod.set_const("CALIB_RATIONAL_MODEL", (int)cv::CALIB_RATIONAL_MODEL);
  mod.set_const("CALIB_THIN_PRISM_MODEL", (int)cv::CALIB_THIN_PRISM_MODEL);
  mod.set_const("CALIB_FIX_S1_S2_S3_S4", (int)cv::CALIB_FIX_S1_S2_S3_S4);
  mod.set_const("CALIB_TILTED_MODEL", (int)cv::CALIB_TILTED_MODEL);
  mod.set_const("CALIB_FIX_TAUX_TAUY", (int)cv::CALIB_FIX_TAUX_TAUY);
  mod.set_const("CALIB_USE_QR", (int)cv::CALIB_USE_QR);
  mod.set_const("CALIB_FIX_TANGENT_DIST", (int)cv::CALIB_FIX_TANGENT_DIST);
  mod.set_const("CALIB_FIX_INTRINSIC", (int)cv::CALIB_FIX_INTRINSIC);
  mod.set_const("CALIB_SAME_FOCAL_LENGTH", (int)cv::CALIB_SAME_FOCAL_LENGTH);
  mod.set_const("CALIB_ZERO_DISPARITY", (int)cv::CALIB_ZERO_DISPARITY);
  mod.set_const("CALIB_USE_LU", (int)cv::CALIB_USE_LU);
  mod.set_const("CALIB_USE_EXTRINSIC_GUESS",
                (int)cv::CALIB_USE_EXTRINSIC_GUESS);
  mod.set_const("FM_7POINT", (int)cv::FM_7POINT);
  mod.set_const("FM_8POINT", (int)cv::FM_8POINT);
  mod.set_const("FM_LMEDS", (int)cv::FM_LMEDS);
  mod.set_const("FM_RANSAC", (int)cv::FM_RANSAC);
  mod.method("Rodrigues", [](const cv::Mat &src, const cv::Mat &dst,
                             const cv::Mat &jacobian) {
    return cv::Rodrigues(cv::InputArray(src), cv::OutputArray(dst),
                         cv::OutputArray(jacobian));
  });
  mod.method("findHomography",
             [](const cv::Mat &srcPoints, const cv::Mat &dstPoints, int method,
                double ransacReprojThreshold, const cv::Mat &mask) {
               return cv::findHomography(
                   cv::InputArray(srcPoints), cv::InputArray(dstPoints), method,
                   ransacReprojThreshold, cv::OutputArray(mask));
             });
  mod.method("findHomography",
             [](const cv::Mat &srcPoints, const cv::Mat &dstPoints, int method,
                double ransacReprojThreshold, const cv::Mat &mask,
                const int maxIters) {
               return cv::findHomography(
                   cv::InputArray(srcPoints), cv::InputArray(dstPoints), method,
                   ransacReprojThreshold, cv::OutputArray(mask), maxIters);
             });
  mod.method("findHomography",
             [](const cv::Mat &srcPoints, const cv::Mat &dstPoints, int method,
                double ransacReprojThreshold, const cv::Mat &mask,
                const int maxIters, const double confidence) {
               return cv::findHomography(
                   cv::InputArray(srcPoints), cv::InputArray(dstPoints), method,
                   ransacReprojThreshold, cv::OutputArray(mask), maxIters,
                   confidence);
             });
  mod.method("findHomography", [](const cv::Mat &srcPoints,
                                  const cv::Mat &dstPoints,
                                  const cv::Mat &mask) {
    return cv::findHomography(cv::InputArray(srcPoints),
                              cv::InputArray(dstPoints), cv::OutputArray(mask));
  });
  mod.method("findHomography",
             [](const cv::Mat &srcPoints, const cv::Mat &dstPoints,
                const cv::Mat &mask, int method) {
               return cv::findHomography(cv::InputArray(srcPoints),
                                         cv::InputArray(dstPoints),
                                         cv::OutputArray(mask), method);
             });
  mod.method("findHomography", [](const cv::Mat &srcPoints,
                                  const cv::Mat &dstPoints, const cv::Mat &mask,
                                  int method, double ransacReprojThreshold) {
    return cv::findHomography(cv::InputArray(srcPoints),
                              cv::InputArray(dstPoints), cv::OutputArray(mask),
                              method, ransacReprojThreshold);
  });
  mod.method("RQDecomp3x3", [](const cv::Mat &src, const cv::Mat &mtxR,
                               const cv::Mat &mtxQ, const cv::Mat &Qx,
                               const cv::Mat &Qy, const cv::Mat &Qz) {
    return cv::RQDecomp3x3(cv::InputArray(src), cv::OutputArray(mtxR),
                           cv::OutputArray(mtxQ), cv::OutputArray(Qx),
                           cv::OutputArray(Qy), cv::OutputArray(Qz));
  });
  mod.method("decomposeProjectionMatrix",
             [](const cv::Mat &projMatrix, const cv::Mat &cameraMatrix,
                const cv::Mat &rotMatrix, const cv::Mat &transVect,
                const cv::Mat &rotMatrixX, const cv::Mat &rotMatrixY,
                const cv::Mat &rotMatrixZ, const cv::Mat &eulerAngles) {
               return cv::decomposeProjectionMatrix(
                   cv::InputArray(projMatrix), cv::OutputArray(cameraMatrix),
                   cv::OutputArray(rotMatrix), cv::OutputArray(transVect),
                   cv::OutputArray(rotMatrixX), cv::OutputArray(rotMatrixY),
                   cv::OutputArray(rotMatrixZ), cv::OutputArray(eulerAngles));
             });
  mod.method("matMulDeriv", [](const cv::Mat &A, const cv::Mat &B,
                               const cv::Mat &dABdA, const cv::Mat &dABdB) {
    return cv::matMulDeriv(cv::InputArray(A), cv::InputArray(B),
                           cv::OutputArray(dABdA), cv::OutputArray(dABdB));
  });
  mod.method(
      "composeRT",
      [](const cv::Mat &rvec1, const cv::Mat &tvec1, const cv::Mat &rvec2,
         const cv::Mat &tvec2, const cv::Mat &rvec3, const cv::Mat &tvec3,
         const cv::Mat &dr3dr1, const cv::Mat &dr3dt1, const cv::Mat &dr3dr2,
         const cv::Mat &dr3dt2, const cv::Mat &dt3dr1, const cv::Mat &dt3dt1,
         const cv::Mat &dt3dr2, const cv::Mat &dt3dt2) {
        return cv::composeRT(cv::InputArray(rvec1), cv::InputArray(tvec1),
                             cv::InputArray(rvec2), cv::InputArray(tvec2),
                             cv::OutputArray(rvec3), cv::OutputArray(tvec3),
                             cv::OutputArray(dr3dr1), cv::OutputArray(dr3dt1),
                             cv::OutputArray(dr3dr2), cv::OutputArray(dr3dt2),
                             cv::OutputArray(dt3dr1), cv::OutputArray(dt3dt1),
                             cv::OutputArray(dt3dr2), cv::OutputArray(dt3dt2));
      });
  mod.method(
      "projectPoints",
      [](const cv::Mat &objectPoints, const cv::Mat &rvec, const cv::Mat &tvec,
         const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
         const cv::Mat &imagePoints, const cv::Mat &jacobian) {
        return cv::projectPoints(
            cv::InputArray(objectPoints), cv::InputArray(rvec),
            cv::InputArray(tvec), cv::InputArray(cameraMatrix),
            cv::InputArray(distCoeffs), cv::OutputArray(imagePoints),
            cv::OutputArray(jacobian));
      });
  mod.method("projectPoints",
             [](const cv::Mat &objectPoints, const cv::Mat &rvec,
                const cv::Mat &tvec, const cv::Mat &cameraMatrix,
                const cv::Mat &distCoeffs, const cv::Mat &imagePoints,
                const cv::Mat &jacobian, double aspectRatio) {
               return cv::projectPoints(
                   cv::InputArray(objectPoints), cv::InputArray(rvec),
                   cv::InputArray(tvec), cv::InputArray(cameraMatrix),
                   cv::InputArray(distCoeffs), cv::OutputArray(imagePoints),
                   cv::OutputArray(jacobian), aspectRatio);
             });
  mod.method("solvePnP",
             [](const cv::Mat &objectPoints, const cv::Mat &imagePoints,
                const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                const cv::Mat &rvec, const cv::Mat &tvec) {
               return cv::solvePnP(
                   cv::InputArray(objectPoints), cv::InputArray(imagePoints),
                   cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
                   cv::OutputArray(rvec), cv::OutputArray(tvec));
             });
  mod.method(
      "solvePnP",
      [](const cv::Mat &objectPoints, const cv::Mat &imagePoints,
         const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
         const cv::Mat &rvec, const cv::Mat &tvec, bool useExtrinsicGuess) {
        return cv::solvePnP(
            cv::InputArray(objectPoints), cv::InputArray(imagePoints),
            cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
            cv::OutputArray(rvec), cv::OutputArray(tvec), useExtrinsicGuess);
      });
  mod.method(
      "solvePnP", [](const cv::Mat &objectPoints, const cv::Mat &imagePoints,
                     const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                     const cv::Mat &rvec, const cv::Mat &tvec,
                     bool useExtrinsicGuess, int flags) {
        return cv::solvePnP(cv::InputArray(objectPoints),
                            cv::InputArray(imagePoints),
                            cv::InputArray(cameraMatrix),
                            cv::InputArray(distCoeffs), cv::OutputArray(rvec),
                            cv::OutputArray(tvec), useExtrinsicGuess, flags);
      });
  mod.method(
      "solvePnPRansac",
      [](const cv::Mat &objectPoints, const cv::Mat &imagePoints,
         const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
         const cv::Mat &rvec, const cv::Mat &tvec, bool useExtrinsicGuess,
         int iterationsCount, float reprojectionError, double confidence,
         const cv::Mat &inliers) {
        return cv::solvePnPRansac(
            cv::InputArray(objectPoints), cv::InputArray(imagePoints),
            cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
            cv::OutputArray(rvec), cv::OutputArray(tvec), useExtrinsicGuess,
            iterationsCount, reprojectionError, confidence,
            cv::OutputArray(inliers));
      });
  mod.method(
      "solvePnPRansac",
      [](const cv::Mat &objectPoints, const cv::Mat &imagePoints,
         const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
         const cv::Mat &rvec, const cv::Mat &tvec, bool useExtrinsicGuess,
         int iterationsCount, float reprojectionError, double confidence,
         const cv::Mat &inliers, int flags) {
        return cv::solvePnPRansac(
            cv::InputArray(objectPoints), cv::InputArray(imagePoints),
            cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
            cv::OutputArray(rvec), cv::OutputArray(tvec), useExtrinsicGuess,
            iterationsCount, reprojectionError, confidence,
            cv::OutputArray(inliers), flags);
      });
  mod.method(
      "findChessboardCorners",
      [](const cv::Mat &image, cv::Size patternSize, const cv::Mat &corners) {
        return cv::findChessboardCorners(cv::InputArray(image), patternSize,
                                         cv::OutputArray(corners));
      });
  mod.method(
      "findChessboardCorners", [](const cv::Mat &image, cv::Size patternSize,
                                  const cv::Mat &corners, int flags) {
        return cv::findChessboardCorners(cv::InputArray(image), patternSize,
                                         cv::OutputArray(corners), flags);
      });
  mod.method(
      "find4QuadCornerSubpix",
      [](const cv::Mat &img, const cv::Mat &corners, cv::Size region_size) {
        return cv::find4QuadCornerSubpix(
            cv::InputArray(img), cv::InputOutputArray(corners), region_size);
      });
  mod.method("drawChessboardCorners",
             [](const cv::Mat &image, cv::Size patternSize,
                const cv::Mat &corners, bool patternWasFound) {
               return cv::drawChessboardCorners(
                   cv::InputOutputArray(image), patternSize,
                   cv::InputArray(corners), patternWasFound);
             });
  mod.add_type<cv::CirclesGridFinderParameters>("CirclesGridFinderParameters")
      .method("densityNeighborhoodSize",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.densityNeighborhoodSize;
              })
      .method("minDensity",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.minDensity;
              })
      .method("kmeansAttempts",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.kmeansAttempts;
              })
      .method("minDistanceToAddKeypoint",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.minDistanceToAddKeypoint;
              })
      .method("keypointScale",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.keypointScale;
              })
      .method("minGraphConfidence",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.minGraphConfidence;
              })
      .method("vertexGain",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.vertexGain;
              })
      .method("vertexPenalty",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.vertexPenalty;
              })
      .method("existingVertexGain",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.existingVertexGain;
              })
      .method("edgeGain",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.edgeGain;
              })
      .method("edgePenalty",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.edgePenalty;
              })
      .method("convexHullFactor",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.convexHullFactor;
              })
      .method("minRNGEdgeSwitchDist",
              [](const cv::CirclesGridFinderParameters &instance) {
                return instance.minRNGEdgeSwitchDist;
              });
  //.method("gridType",[](const cv::CirclesGridFinderParameters
  //&instance){return instance.gridType;});
  mod.add_type<cv::CirclesGridFinderParameters2>("CirclesGridFinderParameters2")
      .method("squareSize",
              [](const cv::CirclesGridFinderParameters2 &instance) {
                return instance.squareSize;
              })
      .method("maxRectifiedDistance",
              [](const cv::CirclesGridFinderParameters2 &instance) {
                return instance.maxRectifiedDistance;
              });
  mod.method(
      "findCirclesGrid",
      [](const cv::Mat &image, cv::Size patternSize, const cv::Mat &centers,
         int flags, const cv::Ptr<cv::FeatureDetector> &blobDetector,
         cv::CirclesGridFinderParameters parameters) {
        return cv::findCirclesGrid(cv::InputArray(image), patternSize,
                                   cv::OutputArray(centers), flags,
                                   blobDetector, parameters);
      });
  mod.method(
      "findCirclesGrid2",
      [](const cv::Mat &image, cv::Size patternSize, const cv::Mat &centers,
         int flags, const cv::Ptr<cv::FeatureDetector> &blobDetector,
         cv::CirclesGridFinderParameters2 parameters) {
        return cv::findCirclesGrid2(cv::InputArray(image), patternSize,
                                    cv::OutputArray(centers), flags,
                                    blobDetector, parameters);
      });
  mod.method("findCirclesGrid", [](const cv::Mat &image, cv::Size patternSize,
                                   const cv::Mat &centers) {
    return cv::findCirclesGrid(cv::InputArray(image), patternSize,
                               cv::OutputArray(centers));
  });
  mod.method("findCirclesGrid", [](const cv::Mat &image, cv::Size patternSize,
                                   const cv::Mat &centers, int flags) {
    return cv::findCirclesGrid(cv::InputArray(image), patternSize,
                               cv::OutputArray(centers), flags);
  });
  mod.method(
      "findCirclesGrid",
      [](const cv::Mat &image, cv::Size patternSize, const cv::Mat &centers,
         int flags, const cv::Ptr<cv::FeatureDetector> &blobDetector) {
        return cv::findCirclesGrid(cv::InputArray(image), patternSize,
                                   cv::OutputArray(centers), flags,
                                   blobDetector);
      });
  mod.method(
      "calibrationMatrixValues",
      [](const cv::Mat &cameraMatrix, cv::Size imageSize, double apertureWidth,
         double apertureHeight, double &fovx, double &fovy, double &focalLength,
         cv::Point2d &principalPoint, double &aspectRatio) {
        return cv::calibrationMatrixValues(
            cv::InputArray(cameraMatrix), imageSize, apertureWidth,
            apertureHeight, fovx, fovy, focalLength, principalPoint,
            aspectRatio);
      });
  mod.method("stereoRectify",
             [](const cv::Mat &cameraMatrix1, const cv::Mat &distCoeffs1,
                const cv::Mat &cameraMatrix2, const cv::Mat &distCoeffs2,
                cv::Size imageSize, const cv::Mat &R, const cv::Mat &T,
                const cv::Mat &R1, const cv::Mat &R2, const cv::Mat &P1,
                const cv::Mat &P2, const cv::Mat &Q) {
               return cv::stereoRectify(
                   cv::InputArray(cameraMatrix1), cv::InputArray(distCoeffs1),
                   cv::InputArray(cameraMatrix2), cv::InputArray(distCoeffs2),
                   imageSize, cv::InputArray(R), cv::InputArray(T),
                   cv::OutputArray(R1), cv::OutputArray(R2),
                   cv::OutputArray(P1), cv::OutputArray(P2),
                   cv::OutputArray(Q));
             });
  mod.method("stereoRectify",
             [](const cv::Mat &cameraMatrix1, const cv::Mat &distCoeffs1,
                const cv::Mat &cameraMatrix2, const cv::Mat &distCoeffs2,
                cv::Size imageSize, const cv::Mat &R, const cv::Mat &T,
                const cv::Mat &R1, const cv::Mat &R2, const cv::Mat &P1,
                const cv::Mat &P2, const cv::Mat &Q, int flags) {
               return cv::stereoRectify(
                   cv::InputArray(cameraMatrix1), cv::InputArray(distCoeffs1),
                   cv::InputArray(cameraMatrix2), cv::InputArray(distCoeffs2),
                   imageSize, cv::InputArray(R), cv::InputArray(T),
                   cv::OutputArray(R1), cv::OutputArray(R2),
                   cv::OutputArray(P1), cv::OutputArray(P2), cv::OutputArray(Q),
                   flags);
             });
  mod.method("stereoRectify",
             [](const cv::Mat &cameraMatrix1, const cv::Mat &distCoeffs1,
                const cv::Mat &cameraMatrix2, const cv::Mat &distCoeffs2,
                cv::Size imageSize, const cv::Mat &R, const cv::Mat &T,
                const cv::Mat &R1, const cv::Mat &R2, const cv::Mat &P1,
                const cv::Mat &P2, const cv::Mat &Q, int flags, double alpha) {
               return cv::stereoRectify(
                   cv::InputArray(cameraMatrix1), cv::InputArray(distCoeffs1),
                   cv::InputArray(cameraMatrix2), cv::InputArray(distCoeffs2),
                   imageSize, cv::InputArray(R), cv::InputArray(T),
                   cv::OutputArray(R1), cv::OutputArray(R2),
                   cv::OutputArray(P1), cv::OutputArray(P2), cv::OutputArray(Q),
                   flags, alpha);
             });
  mod.method("stereoRectify",
             [](const cv::Mat &cameraMatrix1, const cv::Mat &distCoeffs1,
                const cv::Mat &cameraMatrix2, const cv::Mat &distCoeffs2,
                cv::Size imageSize, const cv::Mat &R, const cv::Mat &T,
                const cv::Mat &R1, const cv::Mat &R2, const cv::Mat &P1,
                const cv::Mat &P2, const cv::Mat &Q, int flags, double alpha,
                cv::Size newImageSize) {
               return cv::stereoRectify(
                   cv::InputArray(cameraMatrix1), cv::InputArray(distCoeffs1),
                   cv::InputArray(cameraMatrix2), cv::InputArray(distCoeffs2),
                   imageSize, cv::InputArray(R), cv::InputArray(T),
                   cv::OutputArray(R1), cv::OutputArray(R2),
                   cv::OutputArray(P1), cv::OutputArray(P2), cv::OutputArray(Q),
                   flags, alpha, newImageSize);
             });
  mod.method("stereoRectify",
             [](const cv::Mat &cameraMatrix1, const cv::Mat &distCoeffs1,
                const cv::Mat &cameraMatrix2, const cv::Mat &distCoeffs2,
                cv::Size imageSize, const cv::Mat &R, const cv::Mat &T,
                const cv::Mat &R1, const cv::Mat &R2, const cv::Mat &P1,
                const cv::Mat &P2, const cv::Mat &Q, int flags, double alpha,
                cv::Size newImageSize, cv::Rect *validPixROI1) {
               return cv::stereoRectify(
                   cv::InputArray(cameraMatrix1), cv::InputArray(distCoeffs1),
                   cv::InputArray(cameraMatrix2), cv::InputArray(distCoeffs2),
                   imageSize, cv::InputArray(R), cv::InputArray(T),
                   cv::OutputArray(R1), cv::OutputArray(R2),
                   cv::OutputArray(P1), cv::OutputArray(P2), cv::OutputArray(Q),
                   flags, alpha, newImageSize, validPixROI1);
             });
  mod.method("stereoRectify",
             [](const cv::Mat &cameraMatrix1, const cv::Mat &distCoeffs1,
                const cv::Mat &cameraMatrix2, const cv::Mat &distCoeffs2,
                cv::Size imageSize, const cv::Mat &R, const cv::Mat &T,
                const cv::Mat &R1, const cv::Mat &R2, const cv::Mat &P1,
                const cv::Mat &P2, const cv::Mat &Q, int flags, double alpha,
                cv::Size newImageSize, cv::Rect *validPixROI1,
                cv::Rect *validPixROI2) {
               return cv::stereoRectify(
                   cv::InputArray(cameraMatrix1), cv::InputArray(distCoeffs1),
                   cv::InputArray(cameraMatrix2), cv::InputArray(distCoeffs2),
                   imageSize, cv::InputArray(R), cv::InputArray(T),
                   cv::OutputArray(R1), cv::OutputArray(R2),
                   cv::OutputArray(P1), cv::OutputArray(P2), cv::OutputArray(Q),
                   flags, alpha, newImageSize, validPixROI1, validPixROI2);
             });
  mod.method(
      "stereoRectifyUncalibrated",
      [](const cv::Mat &points1, const cv::Mat &points2, const cv::Mat &F,
         cv::Size imgSize, const cv::Mat &H1, const cv::Mat &H2) {
        return cv::stereoRectifyUncalibrated(
            cv::InputArray(points1), cv::InputArray(points2), cv::InputArray(F),
            imgSize, cv::OutputArray(H1), cv::OutputArray(H2));
      });
  mod.method("stereoRectifyUncalibrated",
             [](const cv::Mat &points1, const cv::Mat &points2,
                const cv::Mat &F, cv::Size imgSize, const cv::Mat &H1,
                const cv::Mat &H2, double threshold) {
               return cv::stereoRectifyUncalibrated(
                   cv::InputArray(points1), cv::InputArray(points2),
                   cv::InputArray(F), imgSize, cv::OutputArray(H1),
                   cv::OutputArray(H2), threshold);
             });
  mod.method("getOptimalNewCameraMatrix", [](const cv::Mat &cameraMatrix,
                                             const cv::Mat &distCoeffs,
                                             cv::Size imageSize, double alpha) {
    return cv::getOptimalNewCameraMatrix(cv::InputArray(cameraMatrix),
                                         cv::InputArray(distCoeffs), imageSize,
                                         alpha);
  });
  mod.method("getOptimalNewCameraMatrix",
             [](const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                cv::Size imageSize, double alpha, cv::Size newImgSize) {
               return cv::getOptimalNewCameraMatrix(
                   cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
                   imageSize, alpha, newImgSize);
             });
  mod.method("getOptimalNewCameraMatrix",
             [](const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                cv::Size imageSize, double alpha, cv::Size newImgSize,
                cv::Rect *validPixROI) {
               return cv::getOptimalNewCameraMatrix(
                   cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
                   imageSize, alpha, newImgSize, validPixROI);
             });
  mod.method("getOptimalNewCameraMatrix",
             [](const cv::Mat &cameraMatrix, const cv::Mat &distCoeffs,
                cv::Size imageSize, double alpha, cv::Size newImgSize,
                cv::Rect *validPixROI, bool centerPrincipalPoint) {
               return cv::getOptimalNewCameraMatrix(
                   cv::InputArray(cameraMatrix), cv::InputArray(distCoeffs),
                   imageSize, alpha, newImgSize, validPixROI,
                   centerPrincipalPoint);
             });
  mod.method("convertPointsToHomogeneous",
             [](const cv::Mat &src, const cv::Mat &dst) {
               return cv::convertPointsToHomogeneous(cv::InputArray(src),
                                                     cv::OutputArray(dst));
             });
  mod.method("convertPointsFromHomogeneous",
             [](const cv::Mat &src, const cv::Mat &dst) {
               return cv::convertPointsFromHomogeneous(cv::InputArray(src),
                                                       cv::OutputArray(dst));
             });
  mod.method("convertPointsHomogeneous",
             [](const cv::Mat &src, const cv::Mat &dst) {
               return cv::convertPointsHomogeneous(cv::InputArray(src),
                                                   cv::OutputArray(dst));
             });
  mod.method(
      "findFundamentalMat",
      [](const cv::Mat &points1, const cv::Mat &points2, int method,
         double ransacReprojThreshold, double confidence, const cv::Mat &mask) {
        return cv::findFundamentalMat(
            cv::InputArray(points1), cv::InputArray(points2), method,
            ransacReprojThreshold, confidence, cv::OutputArray(mask));
      });
  mod.method(
      "findFundamentalMat",
      [](const cv::Mat &points1, const cv::Mat &points2, const cv::Mat &mask) {
        return cv::findFundamentalMat(cv::InputArray(points1),
                                      cv::InputArray(points2),
                                      cv::OutputArray(mask));
      });
  mod.method("findFundamentalMat",
             [](const cv::Mat &points1, const cv::Mat &points2,
                const cv::Mat &mask, int method) {
               return cv::findFundamentalMat(cv::InputArray(points1),
                                             cv::InputArray(points2),
                                             cv::OutputArray(mask), method);
             });
  mod.method("findFundamentalMat",
             [](const cv::Mat &points1, const cv::Mat &points2,
                const cv::Mat &mask, int method, double ransacReprojThreshold) {
               return cv::findFundamentalMat(
                   cv::InputArray(points1), cv::InputArray(points2),
                   cv::OutputArray(mask), method, ransacReprojThreshold);
             });
  mod.method(
      "findFundamentalMat",
      [](const cv::Mat &points1, const cv::Mat &points2, const cv::Mat &mask,
         int method, double ransacReprojThreshold, double confidence) {
        return cv::findFundamentalMat(
            cv::InputArray(points1), cv::InputArray(points2),
            cv::OutputArray(mask), method, ransacReprojThreshold, confidence);
      });
  mod.method("findEssentialMat",
             [](const cv::Mat &points1, const cv::Mat &points2,
                const cv::Mat &cameraMatrix, int method, double prob,
                double threshold, const cv::Mat &mask) {
               return cv::findEssentialMat(
                   cv::InputArray(points1), cv::InputArray(points2),
                   cv::InputArray(cameraMatrix), method, prob, threshold,
                   cv::OutputArray(mask));
             });
  mod.method("findEssentialMat",
             [](const cv::Mat &points1, const cv::Mat &points2) {
               return cv::findEssentialMat(cv::InputArray(points1),
                                           cv::InputArray(points2));
             });
  mod.method("findEssentialMat",
             [](const cv::Mat &points1, const cv::Mat &points2, double focal) {
               return cv::findEssentialMat(cv::InputArray(points1),
                                           cv::InputArray(points2), focal);
             });
  mod.method("findEssentialMat",
             [](const cv::Mat &points1, const cv::Mat &points2, double focal,
                cv::Point2d pp) {
               return cv::findEssentialMat(cv::InputArray(points1),
                                           cv::InputArray(points2), focal, pp);
             });
  mod.method(
      "findEssentialMat", [](const cv::Mat &points1, const cv::Mat &points2,
                             double focal, cv::Point2d pp, int method) {
        return cv::findEssentialMat(cv::InputArray(points1),
                                    cv::InputArray(points2), focal, pp, method);
      });
  mod.method("findEssentialMat",
             [](const cv::Mat &points1, const cv::Mat &points2, double focal,
                cv::Point2d pp, int method, double prob) {
               return cv::findEssentialMat(cv::InputArray(points1),
                                           cv::InputArray(points2), focal, pp,
                                           method, prob);
             });
  mod.method("findEssentialMat",
             [](const cv::Mat &points1, const cv::Mat &points2, double focal,
                cv::Point2d pp, int method, double prob, double threshold) {
               return cv::findEssentialMat(cv::InputArray(points1),
                                           cv::InputArray(points2), focal, pp,
                                           method, prob, threshold);
             });
  mod.method("findEssentialMat", [](const cv::Mat &points1,
                                    const cv::Mat &points2, double focal,
                                    cv::Point2d pp, int method, double prob,
                                    double threshold, const cv::Mat &mask) {
    return cv::findEssentialMat(cv::InputArray(points1),
                                cv::InputArray(points2), focal, pp, method,
                                prob, threshold, cv::OutputArray(mask));
  });
  mod.method("decomposeEssentialMat", [](const cv::Mat &E, const cv::Mat &R1,
                                         const cv::Mat &R2, const cv::Mat &t) {
    return cv::decomposeEssentialMat(cv::InputArray(E), cv::OutputArray(R1),
                                     cv::OutputArray(R2), cv::OutputArray(t));
  });
  mod.method("recoverPose", [](const cv::Mat &E, const cv::Mat &points1,
                               const cv::Mat &points2,
                               const cv::Mat &cameraMatrix, const cv::Mat &R,
                               const cv::Mat &t) {
    return cv::recoverPose(
        cv::InputArray(E), cv::InputArray(points1), cv::InputArray(points2),
        cv::InputArray(cameraMatrix), cv::OutputArray(R), cv::OutputArray(t));
  });
  mod.method("recoverPose", [](const cv::Mat &E, const cv::Mat &points1,
                               const cv::Mat &points2,
                               const cv::Mat &cameraMatrix, const cv::Mat &R,
                               const cv::Mat &t, const cv::Mat &mask) {
    return cv::recoverPose(cv::InputArray(E), cv::InputArray(points1),
                           cv::InputArray(points2),
                           cv::InputArray(cameraMatrix), cv::OutputArray(R),
                           cv::OutputArray(t), cv::InputOutputArray(mask));
  });
  mod.method("recoverPose", [](const cv::Mat &E, const cv::Mat &points1,
                               const cv::Mat &points2, const cv::Mat &R,
                               const cv::Mat &t) {
    return cv::recoverPose(cv::InputArray(E), cv::InputArray(points1),
                           cv::InputArray(points2), cv::OutputArray(R),
                           cv::OutputArray(t));
  });
  mod.method("recoverPose", [](const cv::Mat &E, const cv::Mat &points1,
                               const cv::Mat &points2, const cv::Mat &R,
                               const cv::Mat &t, double focal) {
    return cv::recoverPose(cv::InputArray(E), cv::InputArray(points1),
                           cv::InputArray(points2), cv::OutputArray(R),
                           cv::OutputArray(t), focal);
  });
  mod.method("recoverPose", [](const cv::Mat &E, const cv::Mat &points1,
                               const cv::Mat &points2, const cv::Mat &R,
                               const cv::Mat &t, double focal, cv::Point2d pp) {
    return cv::recoverPose(cv::InputArray(E), cv::InputArray(points1),
                           cv::InputArray(points2), cv::OutputArray(R),
                           cv::OutputArray(t), focal, pp);
  });
  mod.method("recoverPose", [](const cv::Mat &E, const cv::Mat &points1,
                               const cv::Mat &points2, const cv::Mat &R,
                               const cv::Mat &t, double focal, cv::Point2d pp,
                               const cv::Mat &mask) {
    return cv::recoverPose(cv::InputArray(E), cv::InputArray(points1),
                           cv::InputArray(points2), cv::OutputArray(R),
                           cv::OutputArray(t), focal, pp,
                           cv::InputOutputArray(mask));
  });
  mod.method("recoverPose",
             [](const cv::Mat &E, const cv::Mat &points1,
                const cv::Mat &points2, const cv::Mat &cameraMatrix,
                const cv::Mat &R, const cv::Mat &t, double distanceThresh,
                const cv::Mat &mask, const cv::Mat &triangulatedPoints) {
               return cv::recoverPose(
                   cv::InputArray(E), cv::InputArray(points1),
                   cv::InputArray(points2), cv::InputArray(cameraMatrix),
                   cv::OutputArray(R), cv::OutputArray(t), distanceThresh,
                   cv::InputOutputArray(mask),
                   cv::OutputArray(triangulatedPoints));
             });
  mod.method(
      "computeCorrespondEpilines", [](const cv::Mat &points, int whichImage,
                                      const cv::Mat &F, const cv::Mat &lines) {
        return cv::computeCorrespondEpilines(cv::InputArray(points), whichImage,
                                             cv::InputArray(F),
                                             cv::OutputArray(lines));
      });
  mod.method("triangulatePoints",
             [](const cv::Mat &projMatr1, const cv::Mat &projMatr2,
                const cv::Mat &projPoints1, const cv::Mat &projPoints2,
                const cv::Mat &points4D) {
               return cv::triangulatePoints(
                   cv::InputArray(projMatr1), cv::InputArray(projMatr2),
                   cv::InputArray(projPoints1), cv::InputArray(projPoints2),
                   cv::OutputArray(points4D));
             });
  mod.method(
      "correctMatches",
      [](const cv::Mat &F, const cv::Mat &points1, const cv::Mat &points2,
         const cv::Mat &newPoints1, const cv::Mat &newPoints2) {
        return cv::correctMatches(
            cv::InputArray(F), cv::InputArray(points1), cv::InputArray(points2),
            cv::OutputArray(newPoints1), cv::OutputArray(newPoints2));
      });
  mod.method("filterSpeckles", [](const cv::Mat &img, double newVal,
                                  int maxSpeckleSize, double maxDiff) {
    return cv::filterSpeckles(cv::InputOutputArray(img), newVal, maxSpeckleSize,
                              maxDiff);
  });
  mod.method("filterSpeckles", [](const cv::Mat &img, double newVal,
                                  int maxSpeckleSize, double maxDiff,
                                  const cv::Mat &buf) {
    return cv::filterSpeckles(cv::InputOutputArray(img), newVal, maxSpeckleSize,
                              maxDiff, cv::InputOutputArray(buf));
  });
  mod.method(
      "getValidDisparityROI", [](cv::Rect roi1, cv::Rect roi2, int minDisparity,
                                 int numberOfDisparities, int SADWindowSize) {
        return cv::getValidDisparityROI(roi1, roi2, minDisparity,
                                        numberOfDisparities, SADWindowSize);
      });
  mod.method("validateDisparity",
             [](const cv::Mat &disparity, const cv::Mat &cost, int minDisparity,
                int numberOfDisparities) {
               return cv::validateDisparity(cv::InputOutputArray(disparity),
                                            cv::InputArray(cost), minDisparity,
                                            numberOfDisparities);
             });
  mod.method("validateDisparity",
             [](const cv::Mat &disparity, const cv::Mat &cost, int minDisparity,
                int numberOfDisparities, int disp12MaxDisp) {
               return cv::validateDisparity(cv::InputOutputArray(disparity),
                                            cv::InputArray(cost), minDisparity,
                                            numberOfDisparities, disp12MaxDisp);
             });
  mod.method("reprojectImageTo3D", [](const cv::Mat &disparity,
                                      const cv::Mat &_3dImage,
                                      const cv::Mat &Q) {
    return cv::reprojectImageTo3D(cv::InputArray(disparity),
                                  cv::OutputArray(_3dImage), cv::InputArray(Q));
  });
  mod.method("reprojectImageTo3D", [](const cv::Mat &disparity,
                                      const cv::Mat &_3dImage, const cv::Mat &Q,
                                      bool handleMissingValues) {
    return cv::reprojectImageTo3D(cv::InputArray(disparity),
                                  cv::OutputArray(_3dImage), cv::InputArray(Q),
                                  handleMissingValues);
  });
  mod.method("reprojectImageTo3D", [](const cv::Mat &disparity,
                                      const cv::Mat &_3dImage, const cv::Mat &Q,
                                      bool handleMissingValues, int ddepth) {
    return cv::reprojectImageTo3D(cv::InputArray(disparity),
                                  cv::OutputArray(_3dImage), cv::InputArray(Q),
                                  handleMissingValues, ddepth);
  });
  mod.method("sampsonDistance",
             [](const cv::Mat &pt1, const cv::Mat &pt2, const cv::Mat &F) {
               return cv::sampsonDistance(
                   cv::InputArray(pt1), cv::InputArray(pt2), cv::InputArray(F));
             });
  mod.method("estimateAffine3D", [](const cv::Mat &src, const cv::Mat &dst,
                                    const cv::Mat &out,
                                    const cv::Mat &inliers) {
    return cv::estimateAffine3D(cv::InputArray(src), cv::InputArray(dst),
                                cv::OutputArray(out), cv::OutputArray(inliers));
  });
  mod.method("estimateAffine3D", [](const cv::Mat &src, const cv::Mat &dst,
                                    const cv::Mat &out, const cv::Mat &inliers,
                                    double ransacThreshold) {
    return cv::estimateAffine3D(cv::InputArray(src), cv::InputArray(dst),
                                cv::OutputArray(out), cv::OutputArray(inliers),
                                ransacThreshold);
  });
  mod.method("estimateAffine3D", [](const cv::Mat &src, const cv::Mat &dst,
                                    const cv::Mat &out, const cv::Mat &inliers,
                                    double ransacThreshold, double confidence) {
    return cv::estimateAffine3D(cv::InputArray(src), cv::InputArray(dst),
                                cv::OutputArray(out), cv::OutputArray(inliers),
                                ransacThreshold, confidence);
  });
  mod.method("estimateAffine2D", [](const cv::Mat &from, const cv::Mat &to,
                                    const cv::Mat &inliers) {
    return cv::estimateAffine2D(cv::InputArray(from), cv::InputArray(to),
                                cv::OutputArray(inliers));
  });
  mod.method("estimateAffine2D", [](const cv::Mat &from, const cv::Mat &to,
                                    const cv::Mat &inliers, int method) {
    return cv::estimateAffine2D(cv::InputArray(from), cv::InputArray(to),
                                cv::OutputArray(inliers), method);
  });
  mod.method("estimateAffine2D", [](const cv::Mat &from, const cv::Mat &to,
                                    const cv::Mat &inliers, int method,
                                    double ransacReprojThreshold) {
    return cv::estimateAffine2D(cv::InputArray(from), cv::InputArray(to),
                                cv::OutputArray(inliers), method,
                                ransacReprojThreshold);
  });
  mod.method("estimateAffine2D",
             [](const cv::Mat &from, const cv::Mat &to, const cv::Mat &inliers,
                int method, double ransacReprojThreshold, size_t maxIters) {
               return cv::estimateAffine2D(cv::InputArray(from),
                                           cv::InputArray(to),
                                           cv::OutputArray(inliers), method,
                                           ransacReprojThreshold, maxIters);
             });
  mod.method("estimateAffine2D", [](const cv::Mat &from, const cv::Mat &to,
                                    const cv::Mat &inliers, int method,
                                    double ransacReprojThreshold,
                                    size_t maxIters, double confidence) {
    return cv::estimateAffine2D(cv::InputArray(from), cv::InputArray(to),
                                cv::OutputArray(inliers), method,
                                ransacReprojThreshold, maxIters, confidence);
  });
  mod.method("estimateAffine2D",
             [](const cv::Mat &from, const cv::Mat &to, const cv::Mat &inliers,
                int method, double ransacReprojThreshold, size_t maxIters,
                double confidence, size_t refineIters) {
               return cv::estimateAffine2D(
                   cv::InputArray(from), cv::InputArray(to),
                   cv::OutputArray(inliers), method, ransacReprojThreshold,
                   maxIters, confidence, refineIters);
             });
  mod.method(
      "estimateAffinePartial2D",
      [](const cv::Mat &from, const cv::Mat &to, const cv::Mat &inliers) {
        return cv::estimateAffinePartial2D(
            cv::InputArray(from), cv::InputArray(to), cv::OutputArray(inliers));
      });
  mod.method("estimateAffinePartial2D", [](const cv::Mat &from,
                                           const cv::Mat &to,
                                           const cv::Mat &inliers, int method) {
    return cv::estimateAffinePartial2D(cv::InputArray(from), cv::InputArray(to),
                                       cv::OutputArray(inliers), method);
  });
  mod.method("estimateAffinePartial2D",
             [](const cv::Mat &from, const cv::Mat &to, const cv::Mat &inliers,
                int method, double ransacReprojThreshold) {
               return cv::estimateAffinePartial2D(
                   cv::InputArray(from), cv::InputArray(to),
                   cv::OutputArray(inliers), method, ransacReprojThreshold);
             });
  mod.method("estimateAffinePartial2D",
             [](const cv::Mat &from, const cv::Mat &to, const cv::Mat &inliers,
                int method, double ransacReprojThreshold, size_t maxIters) {
               return cv::estimateAffinePartial2D(
                   cv::InputArray(from), cv::InputArray(to),
                   cv::OutputArray(inliers), method, ransacReprojThreshold,
                   maxIters);
             });
  mod.method("estimateAffinePartial2D",
             [](const cv::Mat &from, const cv::Mat &to, const cv::Mat &inliers,
                int method, double ransacReprojThreshold, size_t maxIters,
                double confidence) {
               return cv::estimateAffinePartial2D(
                   cv::InputArray(from), cv::InputArray(to),
                   cv::OutputArray(inliers), method, ransacReprojThreshold,
                   maxIters, confidence);
             });
  mod.method("estimateAffinePartial2D",
             [](const cv::Mat &from, const cv::Mat &to, const cv::Mat &inliers,
                int method, double ransacReprojThreshold, size_t maxIters,
                double confidence, size_t refineIters) {
               return cv::estimateAffinePartial2D(
                   cv::InputArray(from), cv::InputArray(to),
                   cv::OutputArray(inliers), method, ransacReprojThreshold,
                   maxIters, confidence, refineIters);
             });
  mod.add_type<cv::StereoMatcher>("StereoMatcher")
      .method("compute",
              [](cv::StereoMatcher &instance, const cv::Mat &left,
                 const cv::Mat &right, const cv::Mat &disparity) {
                return instance.compute(cv::InputArray(left),
                                        cv::InputArray(right),
                                        cv::OutputArray(disparity));
              })
      .method("getMinDisparity",
              [](const cv::StereoMatcher &instance) {
                return instance.getMinDisparity();
              })
      .method("setMinDisparity",
              [](cv::StereoMatcher &instance, int minDisparity) {
                return instance.setMinDisparity(minDisparity);
              })
      .method("getNumDisparities",
              [](const cv::StereoMatcher &instance) {
                return instance.getNumDisparities();
              })
      .method("setNumDisparities",
              [](cv::StereoMatcher &instance, int numDisparities) {
                return instance.setNumDisparities(numDisparities);
              })
      .method("getBlockSize",
              [](const cv::StereoMatcher &instance) {
                return instance.getBlockSize();
              })
      .method("setBlockSize",
              [](cv::StereoMatcher &instance, int blockSize) {
                return instance.setBlockSize(blockSize);
              })
      .method("getSpeckleWindowSize",
              [](const cv::StereoMatcher &instance) {
                return instance.getSpeckleWindowSize();
              })
      .method("setSpeckleWindowSize",
              [](cv::StereoMatcher &instance, int speckleWindowSize) {
                return instance.setSpeckleWindowSize(speckleWindowSize);
              })
      .method("getSpeckleRange",
              [](const cv::StereoMatcher &instance) {
                return instance.getSpeckleRange();
              })
      .method("setSpeckleRange",
              [](cv::StereoMatcher &instance, int speckleRange) {
                return instance.setSpeckleRange(speckleRange);
              })
      .method("getDisp12MaxDiff",
              [](const cv::StereoMatcher &instance) {
                return instance.getDisp12MaxDiff();
              })
      .method("setDisp12MaxDiff",
              [](cv::StereoMatcher &instance, int disp12MaxDiff) {
                return instance.setDisp12MaxDiff(disp12MaxDiff);
              });
  mod.add_type<cv::StereoBM>("StereoBM")
      .method("getPreFilterType",
              [](const cv::StereoBM &instance) {
                return instance.getPreFilterType();
              })
      .method("setPreFilterType",
              [](cv::StereoBM &instance, int preFilterType) {
                return instance.setPreFilterType(preFilterType);
              })
      .method("getPreFilterSize",
              [](const cv::StereoBM &instance) {
                return instance.getPreFilterSize();
              })
      .method("setPreFilterSize",
              [](cv::StereoBM &instance, int preFilterSize) {
                return instance.setPreFilterSize(preFilterSize);
              })
      .method("getPreFilterCap",
              [](const cv::StereoBM &instance) {
                return instance.getPreFilterCap();
              })
      .method("setPreFilterCap",
              [](cv::StereoBM &instance, int preFilterCap) {
                return instance.setPreFilterCap(preFilterCap);
              })
      .method("getTextureThreshold",
              [](const cv::StereoBM &instance) {
                return instance.getTextureThreshold();
              })
      .method("setTextureThreshold",
              [](cv::StereoBM &instance, int textureThreshold) {
                return instance.setTextureThreshold(textureThreshold);
              })
      .method("getUniquenessRatio",
              [](const cv::StereoBM &instance) {
                return instance.getUniquenessRatio();
              })
      .method("setUniquenessRatio",
              [](cv::StereoBM &instance, int uniquenessRatio) {
                return instance.setUniquenessRatio(uniquenessRatio);
              })
      .method("getSmallerBlockSize",
              [](const cv::StereoBM &instance) {
                return instance.getSmallerBlockSize();
              })
      .method("setSmallerBlockSize",
              [](cv::StereoBM &instance, int blockSize) {
                return instance.setSmallerBlockSize(blockSize);
              })
      .method("getROI1",
              [](const cv::StereoBM &instance) { return instance.getROI1(); })
      .method("setROI1", [](cv::StereoBM &instance,
                            cv::Rect roi1) { return instance.setROI1(roi1); })
      .method("getROI2",
              [](const cv::StereoBM &instance) { return instance.getROI2(); })
      .method("setROI2", [](cv::StereoBM &instance,
                            cv::Rect roi2) { return instance.setROI2(roi2); })
      .method("create",
              [](cv::StereoBM &instance) { return instance.create(); })
      .method("create",
              [](cv::StereoBM &instance, int numDisparities) {
                return instance.create(numDisparities);
              })
      .method("create",
              [](cv::StereoBM &instance, int numDisparities, int blockSize) {
                return instance.create(numDisparities, blockSize);
              });
  mod.add_type<cv::StereoSGBM>("StereoSGBM")
      .method("getPreFilterCap",
              [](const cv::StereoSGBM &instance) {
                return instance.getPreFilterCap();
              })
      .method("setPreFilterCap",
              [](cv::StereoSGBM &instance, int preFilterCap) {
                return instance.setPreFilterCap(preFilterCap);
              })
      .method("getUniquenessRatio",
              [](const cv::StereoSGBM &instance) {
                return instance.getUniquenessRatio();
              })
      .method("setUniquenessRatio",
              [](cv::StereoSGBM &instance, int uniquenessRatio) {
                return instance.setUniquenessRatio(uniquenessRatio);
              })
      .method("getP1",
              [](const cv::StereoSGBM &instance) { return instance.getP1(); })
      .method("setP1", [](cv::StereoSGBM &instance,
                          int P1) { return instance.setP1(P1); })
      .method("getP2",
              [](const cv::StereoSGBM &instance) { return instance.getP2(); })
      .method("setP2", [](cv::StereoSGBM &instance,
                          int P2) { return instance.setP2(P2); })
      .method("getMode",
              [](const cv::StereoSGBM &instance) { return instance.getMode(); })
      .method("setMode", [](cv::StereoSGBM &instance,
                            int mode) { return instance.setMode(mode); })
      .method("create",
              [](cv::StereoSGBM &instance) { return instance.create(); })
      .method("create",
              [](cv::StereoSGBM &instance, int minDisparity) {
                return instance.create(minDisparity);
              })
      .method(
          "create",
          [](cv::StereoSGBM &instance, int minDisparity, int numDisparities) {
            return instance.create(minDisparity, numDisparities);
          })
      .method("create",
              [](cv::StereoSGBM &instance, int minDisparity, int numDisparities,
                 int blockSize) {
                return instance.create(minDisparity, numDisparities, blockSize);
              })
      .method("create",
              [](cv::StereoSGBM &instance, int minDisparity, int numDisparities,
                 int blockSize, int P1) {
                return instance.create(minDisparity, numDisparities, blockSize,
                                       P1);
              })
      .method("create",
              [](cv::StereoSGBM &instance, int minDisparity, int numDisparities,
                 int blockSize, int P1, int P2) {
                return instance.create(minDisparity, numDisparities, blockSize,
                                       P1, P2);
              })
      .method("create",
              [](cv::StereoSGBM &instance, int minDisparity, int numDisparities,
                 int blockSize, int P1, int P2, int disp12MaxDiff) {
                return instance.create(minDisparity, numDisparities, blockSize,
                                       P1, P2, disp12MaxDiff);
              })
      .method("create",
              [](cv::StereoSGBM &instance, int minDisparity, int numDisparities,
                 int blockSize, int P1, int P2, int disp12MaxDiff,
                 int preFilterCap) {
                return instance.create(minDisparity, numDisparities, blockSize,
                                       P1, P2, disp12MaxDiff, preFilterCap);
              })
      .method("create",
              [](cv::StereoSGBM &instance, int minDisparity, int numDisparities,
                 int blockSize, int P1, int P2, int disp12MaxDiff,
                 int preFilterCap, int uniquenessRatio) {
                return instance.create(minDisparity, numDisparities, blockSize,
                                       P1, P2, disp12MaxDiff, preFilterCap,
                                       uniquenessRatio);
              })
      .method("create",
              [](cv::StereoSGBM &instance, int minDisparity, int numDisparities,
                 int blockSize, int P1, int P2, int disp12MaxDiff,
                 int preFilterCap, int uniquenessRatio, int speckleWindowSize) {
                return instance.create(minDisparity, numDisparities, blockSize,
                                       P1, P2, disp12MaxDiff, preFilterCap,
                                       uniquenessRatio, speckleWindowSize);
              })
      .method(
          "create",
          [](cv::StereoSGBM &instance, int minDisparity, int numDisparities,
             int blockSize, int P1, int P2, int disp12MaxDiff, int preFilterCap,
             int uniquenessRatio, int speckleWindowSize, int speckleRange) {
            return instance.create(
                minDisparity, numDisparities, blockSize, P1, P2, disp12MaxDiff,
                preFilterCap, uniquenessRatio, speckleWindowSize, speckleRange);
          })
      .method("create", [](cv::StereoSGBM &instance, int minDisparity,
                           int numDisparities, int blockSize, int P1, int P2,
                           int disp12MaxDiff, int preFilterCap,
                           int uniquenessRatio, int speckleWindowSize,
                           int speckleRange, int mode) {
        return instance.create(minDisparity, numDisparities, blockSize, P1, P2,
                               disp12MaxDiff, preFilterCap, uniquenessRatio,
                               speckleWindowSize, speckleRange, mode);
      });
  mod.set_const("FISHEYE_CALIB_USE_INTRINSIC_GUESS",
                (int)cv::fisheye::CALIB_USE_INTRINSIC_GUESS);
  mod.set_const("FISHEYE_CALIB_RECOMPUTE_EXTRINSIC",
                (int)cv::fisheye::CALIB_RECOMPUTE_EXTRINSIC);
  mod.set_const("FISHEYE_CALIB_CHECK_COND", (int)cv::fisheye::CALIB_CHECK_COND);
  mod.set_const("FISHEYE_CALIB_FIX_SKEW", (int)cv::fisheye::CALIB_FIX_SKEW);
  mod.set_const("FISHEYE_CALIB_FIX_K1", (int)cv::fisheye::CALIB_FIX_K1);
  mod.set_const("FISHEYE_CALIB_FIX_K2", (int)cv::fisheye::CALIB_FIX_K2);
  mod.set_const("FISHEYE_CALIB_FIX_K3", (int)cv::fisheye::CALIB_FIX_K3);
  mod.set_const("FISHEYE_CALIB_FIX_K4", (int)cv::fisheye::CALIB_FIX_K4);
  mod.set_const("FISHEYE_CALIB_FIX_INTRINSIC",
                (int)cv::fisheye::CALIB_FIX_INTRINSIC);
  mod.set_const("FISHEYE_CALIB_FIX_PRINCIPAL_POINT",
                (int)cv::fisheye::CALIB_FIX_PRINCIPAL_POINT);
  mod.method("projectPoints",
             [](const cv::Mat &objectPoints, const cv::Mat &imagePoints,
                const cv::Affine3d &affine, const cv::Mat &K, const cv::Mat &D,
                double alpha, const cv::Mat &jacobian) {
               return cv::fisheye::projectPoints(
                   cv::InputArray(objectPoints), cv::OutputArray(imagePoints),
                   affine, cv::InputArray(K), cv::InputArray(D), alpha,
                   cv::OutputArray(jacobian));
             });
  mod.method("projectPoints",
             [](const cv::Mat &objectPoints, const cv::Mat &imagePoints,
                const cv::Mat &rvec, const cv::Mat &tvec, const cv::Mat &K,
                const cv::Mat &D, double alpha, const cv::Mat &jacobian) {
               return cv::fisheye::projectPoints(
                   cv::InputArray(objectPoints), cv::OutputArray(imagePoints),
                   cv::InputArray(rvec), cv::InputArray(tvec),
                   cv::InputArray(K), cv::InputArray(D), alpha,
                   cv::OutputArray(jacobian));
             });
  mod.method(
      "distortPoints", [](const cv::Mat &undistorted, const cv::Mat &distorted,
                          const cv::Mat &K, const cv::Mat &D) {
        return cv::fisheye::distortPoints(cv::InputArray(undistorted),
                                          cv::OutputArray(distorted),
                                          cv::InputArray(K), cv::InputArray(D));
      });
  mod.method("distortPoints",
             [](const cv::Mat &undistorted, const cv::Mat &distorted,
                const cv::Mat &K, const cv::Mat &D, double alpha) {
               return cv::fisheye::distortPoints(
                   cv::InputArray(undistorted), cv::OutputArray(distorted),
                   cv::InputArray(K), cv::InputArray(D), alpha);
             });
  mod.method("undistortPoints", [](const cv::Mat &distorted,
                                   const cv::Mat &undistorted, const cv::Mat &K,
                                   const cv::Mat &D, const cv::Mat &R,
                                   const cv::Mat &P) {
    return cv::fisheye::undistortPoints(cv::InputArray(distorted),
                                        cv::OutputArray(undistorted),
                                        cv::InputArray(K), cv::InputArray(D),
                                        cv::InputArray(R), cv::InputArray(P));
  });
  mod.method("initUndistortRectifyMap",
             [](const cv::Mat &K, const cv::Mat &D, const cv::Mat &R,
                const cv::Mat &P, const cv::Size &size, int m1type,
                const cv::Mat &map1, const cv::Mat &map2) {
               return cv::fisheye::initUndistortRectifyMap(
                   cv::InputArray(K), cv::InputArray(D), cv::InputArray(R),
                   cv::InputArray(P), size, m1type, cv::OutputArray(map1),
                   cv::OutputArray(map2));
             });
  mod.method("undistortImage",
             [](const cv::Mat &distorted, const cv::Mat &undistorted,
                const cv::Mat &K, const cv::Mat &D, const cv::Mat &Knew) {
               return cv::fisheye::undistortImage(
                   cv::InputArray(distorted), cv::OutputArray(undistorted),
                   cv::InputArray(K), cv::InputArray(D), cv::InputArray(Knew));
             });
  mod.method("undistortImage", [](const cv::Mat &distorted,
                                  const cv::Mat &undistorted, const cv::Mat &K,
                                  const cv::Mat &D, const cv::Mat &Knew,
                                  const cv::Size &new_size) {
    return cv::fisheye::undistortImage(
        cv::InputArray(distorted), cv::OutputArray(undistorted),
        cv::InputArray(K), cv::InputArray(D), cv::InputArray(Knew), new_size);
  });
  mod.method("estimateNewCameraMatrixForUndistortRectify",
             [](const cv::Mat &K, const cv::Mat &D, const cv::Size &image_size,
                const cv::Mat &R, const cv::Mat &P) {
               return cv::fisheye::estimateNewCameraMatrixForUndistortRectify(
                   cv::InputArray(K), cv::InputArray(D), image_size,
                   cv::InputArray(R), cv::OutputArray(P));
             });
  mod.method("estimateNewCameraMatrixForUndistortRectify",
             [](const cv::Mat &K, const cv::Mat &D, const cv::Size &image_size,
                const cv::Mat &R, const cv::Mat &P, double balance) {
               return cv::fisheye::estimateNewCameraMatrixForUndistortRectify(
                   cv::InputArray(K), cv::InputArray(D), image_size,
                   cv::InputArray(R), cv::OutputArray(P), balance);
             });
  mod.method("estimateNewCameraMatrixForUndistortRectify",
             [](const cv::Mat &K, const cv::Mat &D, const cv::Size &image_size,
                const cv::Mat &R, const cv::Mat &P, double balance,
                const cv::Size &new_size) {
               return cv::fisheye::estimateNewCameraMatrixForUndistortRectify(
                   cv::InputArray(K), cv::InputArray(D), image_size,
                   cv::InputArray(R), cv::OutputArray(P), balance, new_size);
             });
  mod.method("estimateNewCameraMatrixForUndistortRectify",
             [](const cv::Mat &K, const cv::Mat &D, const cv::Size &image_size,
                const cv::Mat &R, const cv::Mat &P, double balance,
                const cv::Size &new_size, double fov_scale) {
               return cv::fisheye::estimateNewCameraMatrixForUndistortRectify(
                   cv::InputArray(K), cv::InputArray(D), image_size,
                   cv::InputArray(R), cv::OutputArray(P), balance, new_size,
                   fov_scale);
             });
  mod.method(
      "stereoRectify",
      [](const cv::Mat &K1, const cv::Mat &D1, const cv::Mat &K2,
         const cv::Mat &D2, const cv::Size &imageSize, const cv::Mat &R,
         const cv::Mat &tvec, const cv::Mat &R1, const cv::Mat &R2,
         const cv::Mat &P1, const cv::Mat &P2, const cv::Mat &Q, int flags) {
        return cv::fisheye::stereoRectify(
            cv::InputArray(K1), cv::InputArray(D1), cv::InputArray(K2),
            cv::InputArray(D2), imageSize, cv::InputArray(R),
            cv::InputArray(tvec), cv::OutputArray(R1), cv::OutputArray(R2),
            cv::OutputArray(P1), cv::OutputArray(P2), cv::OutputArray(Q),
            flags);
      });
  mod.method("stereoRectify", [](const cv::Mat &K1, const cv::Mat &D1,
                                 const cv::Mat &K2, const cv::Mat &D2,
                                 const cv::Size &imageSize, const cv::Mat &R,
                                 const cv::Mat &tvec, const cv::Mat &R1,
                                 const cv::Mat &R2, const cv::Mat &P1,
                                 const cv::Mat &P2, const cv::Mat &Q, int flags,
                                 const cv::Size &newImageSize) {
    return cv::fisheye::stereoRectify(
        cv::InputArray(K1), cv::InputArray(D1), cv::InputArray(K2),
        cv::InputArray(D2), imageSize, cv::InputArray(R), cv::InputArray(tvec),
        cv::OutputArray(R1), cv::OutputArray(R2), cv::OutputArray(P1),
        cv::OutputArray(P2), cv::OutputArray(Q), flags, newImageSize);
  });
  mod.method("stereoRectify", [](const cv::Mat &K1, const cv::Mat &D1,
                                 const cv::Mat &K2, const cv::Mat &D2,
                                 const cv::Size &imageSize, const cv::Mat &R,
                                 const cv::Mat &tvec, const cv::Mat &R1,
                                 const cv::Mat &R2, const cv::Mat &P1,
                                 const cv::Mat &P2, const cv::Mat &Q, int flags,
                                 const cv::Size &newImageSize, double balance) {
    return cv::fisheye::stereoRectify(
        cv::InputArray(K1), cv::InputArray(D1), cv::InputArray(K2),
        cv::InputArray(D2), imageSize, cv::InputArray(R), cv::InputArray(tvec),
        cv::OutputArray(R1), cv::OutputArray(R2), cv::OutputArray(P1),
        cv::OutputArray(P2), cv::OutputArray(Q), flags, newImageSize, balance);
  });
  mod.method(
      "stereoRectify",
      [](const cv::Mat &K1, const cv::Mat &D1, const cv::Mat &K2,
         const cv::Mat &D2, const cv::Size &imageSize, const cv::Mat &R,
         const cv::Mat &tvec, const cv::Mat &R1, const cv::Mat &R2,
         const cv::Mat &P1, const cv::Mat &P2, const cv::Mat &Q, int flags,
         const cv::Size &newImageSize, double balance, double fov_scale) {
        return cv::fisheye::stereoRectify(
            cv::InputArray(K1), cv::InputArray(D1), cv::InputArray(K2),
            cv::InputArray(D2), imageSize, cv::InputArray(R),
            cv::InputArray(tvec), cv::OutputArray(R1), cv::OutputArray(R2),
            cv::OutputArray(P1), cv::OutputArray(P2), cv::OutputArray(Q), flags,
            newImageSize, balance, fov_scale);
      });
}
