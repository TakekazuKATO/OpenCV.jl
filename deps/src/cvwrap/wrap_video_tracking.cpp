#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_video_tracking_module(Module& mod) {
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
    .method("init",[](cv::KalmanFilter &instance,int  dynamParams,int  measureParams) {    return instance.init( dynamParams,measureParams ); })
    .method("init",[](cv::KalmanFilter &instance,int  dynamParams,int  measureParams,int  controlParams) {    return instance.init( dynamParams,measureParams,controlParams ); })
    .method("init",[](cv::KalmanFilter &instance,int  dynamParams,int  measureParams,int  controlParams,int  type) {    return instance.init( dynamParams,measureParams,controlParams,type ); })
    .method("predict",[](cv::KalmanFilter &instance) {    return instance.predict(  ); })
    .method("predict",[](cv::KalmanFilter &instance,const cv::Mat & control) {    return instance.predict( control ); })
    .method("correct",[](cv::KalmanFilter &instance,const cv::Mat & measurement) {    return instance.correct( measurement ); })
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
  mod.add_type<cv::DenseOpticalFlow>("DenseOpticalFlow")
    .method("calc",[](cv::DenseOpticalFlow &instance,const  cv::Mat & I0,const  cv::Mat & I1,const  cv::Mat & flow) {    return instance.calc( cv::InputArray(I0),cv::InputArray(I1),cv::InputOutputArray(flow) ); })
    .method("collectGarbage",[](cv::DenseOpticalFlow &instance) {    return instance.collectGarbage(  ); });
  mod.add_type<cv::SparseOpticalFlow>("SparseOpticalFlow")
    .method("calc",[](cv::SparseOpticalFlow &instance,const  cv::Mat & prevImg,const  cv::Mat & nextImg,const  cv::Mat & prevPts,const  cv::Mat & nextPts,const  cv::Mat & status,const  cv::Mat & err) {    return instance.calc( cv::InputArray(prevImg),cv::InputArray(nextImg),cv::InputArray(prevPts),cv::InputOutputArray(nextPts),cv::OutputArray(status),cv::OutputArray(err) ); });
  mod.add_type<cv::DualTVL1OpticalFlow>("DualTVL1OpticalFlow")
    .method("getTau",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getTau(  ); })
    .method("setTau",[](cv::DualTVL1OpticalFlow &instance,double  val) {    return instance.setTau( val ); })
    .method("getLambda",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getLambda(  ); })
    .method("setLambda",[](cv::DualTVL1OpticalFlow &instance,double  val) {    return instance.setLambda( val ); })
    .method("getTheta",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getTheta(  ); })
    .method("setTheta",[](cv::DualTVL1OpticalFlow &instance,double  val) {    return instance.setTheta( val ); })
    .method("getGamma",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getGamma(  ); })
    .method("setGamma",[](cv::DualTVL1OpticalFlow &instance,double  val) {    return instance.setGamma( val ); })
    .method("getScalesNumber",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getScalesNumber(  ); })
    .method("setScalesNumber",[](cv::DualTVL1OpticalFlow &instance,int  val) {    return instance.setScalesNumber( val ); })
    .method("getWarpingsNumber",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getWarpingsNumber(  ); })
    .method("setWarpingsNumber",[](cv::DualTVL1OpticalFlow &instance,int  val) {    return instance.setWarpingsNumber( val ); })
    .method("getEpsilon",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getEpsilon(  ); })
    .method("setEpsilon",[](cv::DualTVL1OpticalFlow &instance,double  val) {    return instance.setEpsilon( val ); })
    .method("getInnerIterations",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getInnerIterations(  ); })
    .method("setInnerIterations",[](cv::DualTVL1OpticalFlow &instance,int  val) {    return instance.setInnerIterations( val ); })
    .method("getOuterIterations",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getOuterIterations(  ); })
    .method("setOuterIterations",[](cv::DualTVL1OpticalFlow &instance,int  val) {    return instance.setOuterIterations( val ); })
    .method("getUseInitialFlow",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getUseInitialFlow(  ); })
    .method("setUseInitialFlow",[](cv::DualTVL1OpticalFlow &instance,bool  val) {    return instance.setUseInitialFlow( val ); })
    .method("getScaleStep",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getScaleStep(  ); })
    .method("setScaleStep",[](cv::DualTVL1OpticalFlow &instance,double  val) {    return instance.setScaleStep( val ); })
    .method("getMedianFiltering",[](const cv::DualTVL1OpticalFlow &instance) {    return instance.getMedianFiltering(  ); })
    .method("setMedianFiltering",[](cv::DualTVL1OpticalFlow &instance,int  val) {    return instance.setMedianFiltering( val ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance) {    return instance.create(  ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau) {    return instance.create( tau ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda) {    return instance.create( tau,lambda ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta) {    return instance.create( tau,lambda,theta ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales) {    return instance.create( tau,lambda,theta,nscales ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales,int  warps) {    return instance.create( tau,lambda,theta,nscales,warps ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales,int  warps,double  epsilon) {    return instance.create( tau,lambda,theta,nscales,warps,epsilon ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales,int  warps,double  epsilon,int  innnerIterations) {    return instance.create( tau,lambda,theta,nscales,warps,epsilon,innnerIterations ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales,int  warps,double  epsilon,int  innnerIterations,int  outerIterations) {    return instance.create( tau,lambda,theta,nscales,warps,epsilon,innnerIterations,outerIterations ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales,int  warps,double  epsilon,int  innnerIterations,int  outerIterations,double  scaleStep) {    return instance.create( tau,lambda,theta,nscales,warps,epsilon,innnerIterations,outerIterations,scaleStep ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales,int  warps,double  epsilon,int  innnerIterations,int  outerIterations,double  scaleStep,double  gamma) {    return instance.create( tau,lambda,theta,nscales,warps,epsilon,innnerIterations,outerIterations,scaleStep,gamma ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales,int  warps,double  epsilon,int  innnerIterations,int  outerIterations,double  scaleStep,double  gamma,int  medianFiltering) {    return instance.create( tau,lambda,theta,nscales,warps,epsilon,innnerIterations,outerIterations,scaleStep,gamma,medianFiltering ); })
    .method("create",[](cv::DualTVL1OpticalFlow &instance,double  tau,double  lambda,double  theta,int  nscales,int  warps,double  epsilon,int  innnerIterations,int  outerIterations,double  scaleStep,double  gamma,int  medianFiltering,bool  useInitialFlow) {    return instance.create( tau,lambda,theta,nscales,warps,epsilon,innnerIterations,outerIterations,scaleStep,gamma,medianFiltering,useInitialFlow ); });
  mod.method("createOptFlow_DualTVL1", []() {
    return cv::createOptFlow_DualTVL1(  );
  });
  mod.add_type<cv::FarnebackOpticalFlow>("FarnebackOpticalFlow")
    .method("getNumLevels",[](const cv::FarnebackOpticalFlow &instance) {    return instance.getNumLevels(  ); })
    .method("setNumLevels",[](cv::FarnebackOpticalFlow &instance,int  numLevels) {    return instance.setNumLevels( numLevels ); })
    .method("getPyrScale",[](const cv::FarnebackOpticalFlow &instance) {    return instance.getPyrScale(  ); })
    .method("setPyrScale",[](cv::FarnebackOpticalFlow &instance,double  pyrScale) {    return instance.setPyrScale( pyrScale ); })
    .method("getFastPyramids",[](const cv::FarnebackOpticalFlow &instance) {    return instance.getFastPyramids(  ); })
    .method("setFastPyramids",[](cv::FarnebackOpticalFlow &instance,bool  fastPyramids) {    return instance.setFastPyramids( fastPyramids ); })
    .method("getWinSize",[](const cv::FarnebackOpticalFlow &instance) {    return instance.getWinSize(  ); })
    .method("setWinSize",[](cv::FarnebackOpticalFlow &instance,int  winSize) {    return instance.setWinSize( winSize ); })
    .method("getNumIters",[](const cv::FarnebackOpticalFlow &instance) {    return instance.getNumIters(  ); })
    .method("setNumIters",[](cv::FarnebackOpticalFlow &instance,int  numIters) {    return instance.setNumIters( numIters ); })
    .method("getPolyN",[](const cv::FarnebackOpticalFlow &instance) {    return instance.getPolyN(  ); })
    .method("setPolyN",[](cv::FarnebackOpticalFlow &instance,int  polyN) {    return instance.setPolyN( polyN ); })
    .method("getPolySigma",[](const cv::FarnebackOpticalFlow &instance) {    return instance.getPolySigma(  ); })
    .method("setPolySigma",[](cv::FarnebackOpticalFlow &instance,double  polySigma) {    return instance.setPolySigma( polySigma ); })
    .method("getFlags",[](const cv::FarnebackOpticalFlow &instance) {    return instance.getFlags(  ); })
    .method("setFlags",[](cv::FarnebackOpticalFlow &instance,int  flags) {    return instance.setFlags( flags ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance) {    return instance.create(  ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance,int  numLevels) {    return instance.create( numLevels ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance,int  numLevels,double  pyrScale) {    return instance.create( numLevels,pyrScale ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance,int  numLevels,double  pyrScale,bool  fastPyramids) {    return instance.create( numLevels,pyrScale,fastPyramids ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance,int  numLevels,double  pyrScale,bool  fastPyramids,int  winSize) {    return instance.create( numLevels,pyrScale,fastPyramids,winSize ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance,int  numLevels,double  pyrScale,bool  fastPyramids,int  winSize,int  numIters) {    return instance.create( numLevels,pyrScale,fastPyramids,winSize,numIters ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance,int  numLevels,double  pyrScale,bool  fastPyramids,int  winSize,int  numIters,int  polyN) {    return instance.create( numLevels,pyrScale,fastPyramids,winSize,numIters,polyN ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance,int  numLevels,double  pyrScale,bool  fastPyramids,int  winSize,int  numIters,int  polyN,double  polySigma) {    return instance.create( numLevels,pyrScale,fastPyramids,winSize,numIters,polyN,polySigma ); })
    .method("create",[](cv::FarnebackOpticalFlow &instance,int  numLevels,double  pyrScale,bool  fastPyramids,int  winSize,int  numIters,int  polyN,double  polySigma,int  flags) {    return instance.create( numLevels,pyrScale,fastPyramids,winSize,numIters,polyN,polySigma,flags ); });
  mod.add_type<cv::SparsePyrLKOpticalFlow>("SparsePyrLKOpticalFlow")
    .method("getWinSize",[](const cv::SparsePyrLKOpticalFlow &instance) {    return instance.getWinSize(  ); })
    .method("setWinSize",[](cv::SparsePyrLKOpticalFlow &instance,cv::Size  winSize) {    return instance.setWinSize( winSize ); })
    .method("getMaxLevel",[](const cv::SparsePyrLKOpticalFlow &instance) {    return instance.getMaxLevel(  ); })
    .method("setMaxLevel",[](cv::SparsePyrLKOpticalFlow &instance,int  maxLevel) {    return instance.setMaxLevel( maxLevel ); })
    .method("getTermCriteria",[](const cv::SparsePyrLKOpticalFlow &instance) {    return instance.getTermCriteria(  ); })
    .method("setTermCriteria",[](cv::SparsePyrLKOpticalFlow &instance,cv::TermCriteria & crit) {    return instance.setTermCriteria( crit ); })
    .method("getFlags",[](const cv::SparsePyrLKOpticalFlow &instance) {    return instance.getFlags(  ); })
    .method("setFlags",[](cv::SparsePyrLKOpticalFlow &instance,int  flags) {    return instance.setFlags( flags ); })
    .method("getMinEigThreshold",[](const cv::SparsePyrLKOpticalFlow &instance) {    return instance.getMinEigThreshold(  ); })
    .method("setMinEigThreshold",[](cv::SparsePyrLKOpticalFlow &instance,double  minEigThreshold) {    return instance.setMinEigThreshold( minEigThreshold ); })
    .method("create",[](cv::SparsePyrLKOpticalFlow &instance) {    return instance.create(  ); })
    .method("create",[](cv::SparsePyrLKOpticalFlow &instance,cv::Size  winSize) {    return instance.create( winSize ); })
    .method("create",[](cv::SparsePyrLKOpticalFlow &instance,cv::Size  winSize,int  maxLevel) {    return instance.create( winSize,maxLevel ); })
    .method("create",[](cv::SparsePyrLKOpticalFlow &instance,cv::Size  winSize,int  maxLevel,cv::TermCriteria  crit) {    return instance.create( winSize,maxLevel,crit ); })
    .method("create",[](cv::SparsePyrLKOpticalFlow &instance,cv::Size  winSize,int  maxLevel,cv::TermCriteria  crit,int  flags) {    return instance.create( winSize,maxLevel,crit,flags ); })
    .method("create",[](cv::SparsePyrLKOpticalFlow &instance,cv::Size  winSize,int  maxLevel,cv::TermCriteria  crit,int  flags,double  minEigThreshold) {    return instance.create( winSize,maxLevel,crit,flags,minEigThreshold ); });
}
