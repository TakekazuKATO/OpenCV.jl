#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_tracking_module(Module& mod) {
  mod.set_const("OPTFLOW_USE_INITIAL_FLOW",(int)cv::OPTFLOW_USE_INITIAL_FLOW);
  mod.set_const("OPTFLOW_LK_GET_MIN_EIGENVALS",(int)cv::OPTFLOW_LK_GET_MIN_EIGENVALS);
  mod.set_const("OPTFLOW_FARNEBACK_GAUSSIAN",(int)cv::OPTFLOW_FARNEBACK_GAUSSIAN);
  mod.method("CamShift", [](const  cv::Mat & probImage,cv::Rect & window,cv::TermCriteria  criteria) {
    return cv::CamShift( cv::InputArray(probImage),window,criteria );
  });
  mod.method("meanShift", [](const  cv::Mat & probImage,cv::Rect & window,cv::TermCriteria  criteria) {
    return cv::meanShift( cv::InputArray(probImage),window,criteria );
  });
  mod.method("calcOpticalFlowPyrLK", [](const  cv::Mat & prevImg,const  cv::Mat & nextImg,const  cv::Mat & prevPts,const  cv::Mat & nextPts,const  cv::Mat & status,const  cv::Mat & err) {
    return cv::calcOpticalFlowPyrLK( cv::InputArray(prevImg),cv::InputArray(nextImg),cv::InputArray(prevPts),cv::InputOutputArray(nextPts),cv::OutputArray(status),cv::OutputArray(err) );
  });
  mod.method("calcOpticalFlowPyrLK", [](const  cv::Mat & prevImg,const  cv::Mat & nextImg,const  cv::Mat & prevPts,const  cv::Mat & nextPts,const  cv::Mat & status,const  cv::Mat & err,cv::Size  winSize) {
    return cv::calcOpticalFlowPyrLK( cv::InputArray(prevImg),cv::InputArray(nextImg),cv::InputArray(prevPts),cv::InputOutputArray(nextPts),cv::OutputArray(status),cv::OutputArray(err),winSize );
  });
  mod.method("calcOpticalFlowPyrLK", [](const  cv::Mat & prevImg,const  cv::Mat & nextImg,const  cv::Mat & prevPts,const  cv::Mat & nextPts,const  cv::Mat & status,const  cv::Mat & err,cv::Size  winSize,int  maxLevel) {
    return cv::calcOpticalFlowPyrLK( cv::InputArray(prevImg),cv::InputArray(nextImg),cv::InputArray(prevPts),cv::InputOutputArray(nextPts),cv::OutputArray(status),cv::OutputArray(err),winSize,maxLevel );
  });
  mod.method("calcOpticalFlowPyrLK", [](const  cv::Mat & prevImg,const  cv::Mat & nextImg,const  cv::Mat & prevPts,const  cv::Mat & nextPts,const  cv::Mat & status,const  cv::Mat & err,cv::Size  winSize,int  maxLevel,cv::TermCriteria  criteria) {
    return cv::calcOpticalFlowPyrLK( cv::InputArray(prevImg),cv::InputArray(nextImg),cv::InputArray(prevPts),cv::InputOutputArray(nextPts),cv::OutputArray(status),cv::OutputArray(err),winSize,maxLevel,criteria );
  });
  mod.method("calcOpticalFlowPyrLK", [](const  cv::Mat & prevImg,const  cv::Mat & nextImg,const  cv::Mat & prevPts,const  cv::Mat & nextPts,const  cv::Mat & status,const  cv::Mat & err,cv::Size  winSize,int  maxLevel,cv::TermCriteria  criteria,int  flags) {
    return cv::calcOpticalFlowPyrLK( cv::InputArray(prevImg),cv::InputArray(nextImg),cv::InputArray(prevPts),cv::InputOutputArray(nextPts),cv::OutputArray(status),cv::OutputArray(err),winSize,maxLevel,criteria,flags );
  });
  mod.method("calcOpticalFlowPyrLK", [](const  cv::Mat & prevImg,const  cv::Mat & nextImg,const  cv::Mat & prevPts,const  cv::Mat & nextPts,const  cv::Mat & status,const  cv::Mat & err,cv::Size  winSize,int  maxLevel,cv::TermCriteria  criteria,int  flags,double  minEigThreshold) {
    return cv::calcOpticalFlowPyrLK( cv::InputArray(prevImg),cv::InputArray(nextImg),cv::InputArray(prevPts),cv::InputOutputArray(nextPts),cv::OutputArray(status),cv::OutputArray(err),winSize,maxLevel,criteria,flags,minEigThreshold );
  });
  mod.method("calcOpticalFlowFarneback", [](const  cv::Mat & prev,const  cv::Mat & next,const  cv::Mat & flow,double  pyr_scale,int  levels,int  winsize,int  iterations,int  poly_n,double  poly_sigma,int  flags) {
    return cv::calcOpticalFlowFarneback( cv::InputArray(prev),cv::InputArray(next),cv::InputOutputArray(flow),pyr_scale,levels,winsize,iterations,poly_n,poly_sigma,flags );
  });
  mod.method("estimateRigidTransform", [](const  cv::Mat & src,const  cv::Mat & dst,bool  fullAffine) {
    return cv::estimateRigidTransform( cv::InputArray(src),cv::InputArray(dst),fullAffine );
  });
  mod.method("estimateRigidTransform", [](const  cv::Mat & src,const  cv::Mat & dst,bool  fullAffine,int  ransacMaxIters,double  ransacGoodRatio,int  ransacSize0) {
    return cv::estimateRigidTransform( cv::InputArray(src),cv::InputArray(dst),fullAffine,ransacMaxIters,ransacGoodRatio,ransacSize0 );
  });
  mod.set_const("MOTION_TRANSLATION",(int)cv::MOTION_TRANSLATION);
  mod.set_const("MOTION_EUCLIDEAN",(int)cv::MOTION_EUCLIDEAN);
  mod.set_const("MOTION_AFFINE",(int)cv::MOTION_AFFINE);
  mod.set_const("MOTION_HOMOGRAPHY",(int)cv::MOTION_HOMOGRAPHY);
  mod.method("findTransformECC", [](const  cv::Mat & templateImage,const  cv::Mat & inputImage,const  cv::Mat & warpMatrix,int  motionType,cv::TermCriteria  criteria,const  cv::Mat & inputMask) {
    return cv::findTransformECC( cv::InputArray(templateImage),cv::InputArray(inputImage),cv::InputOutputArray(warpMatrix),motionType,criteria,cv::InputArray(inputMask) );
  });
  mod.add_type<cv::KalmanFilter>("KalmanFilter")
    .constructor<int, int, int, int>()
    .method("statePre",[](const cv::KalmanFilter &instance){return instance.statePre;})
    .method("statePost",[](const cv::KalmanFilter &instance){return instance.statePost;})
    .method("transitionMatrix",[](const cv::KalmanFilter &instance){return instance.transitionMatrix;})
    .method("controlMatrix",[](const cv::KalmanFilter &instance){return instance.controlMatrix;})
    .method("measurementMatrix",[](const cv::KalmanFilter &instance){return instance.measurementMatrix;})
    .method("processNoiseCov",[](const cv::KalmanFilter &instance){return instance.processNoiseCov;})
    .method("measurementNoiseCov",[](const cv::KalmanFilter &instance){return instance.measurementNoiseCov;})
    .method("errorCovPre",[](const cv::KalmanFilter &instance){return instance.errorCovPre;})
    .method("gain",[](const cv::KalmanFilter &instance){return instance.gain;})
    .method("errorCovPost",[](const cv::KalmanFilter &instance){return instance.errorCovPost;})
    .method("temp1",[](const cv::KalmanFilter &instance){return instance.temp1;})
    .method("temp2",[](const cv::KalmanFilter &instance){return instance.temp2;})
    .method("temp3",[](const cv::KalmanFilter &instance){return instance.temp3;})
    .method("temp4",[](const cv::KalmanFilter &instance){return instance.temp4;})
    .method("temp5",[](const cv::KalmanFilter &instance){return instance.temp5;});
  mod.add_type<cv::DenseOpticalFlow>("DenseOpticalFlow");
  mod.add_type<cv::SparseOpticalFlow>("SparseOpticalFlow");
  mod.add_type<cv::DualTVL1OpticalFlow>("DualTVL1OpticalFlow");
  mod.method("createOptFlow_DualTVL1", []() {
    return cv::createOptFlow_DualTVL1(  );
  });
  mod.add_type<cv::FarnebackOpticalFlow>("FarnebackOpticalFlow");
  mod.add_type<cv::SparsePyrLKOpticalFlow>("SparsePyrLKOpticalFlow");
}
