#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_video_background_segm_module(Module& mod) {
  mod.add_type<cv::BackgroundSubtractor>("BackgroundSubtractor")
    .method("apply",[](cv::BackgroundSubtractor &instance,const  cv::Mat & image,const  cv::Mat & fgmask) {    return instance.apply( cv::InputArray(image),cv::OutputArray(fgmask) ); })
    .method("apply",[](cv::BackgroundSubtractor &instance,const  cv::Mat & image,const  cv::Mat & fgmask,double  learningRate) {    return instance.apply( cv::InputArray(image),cv::OutputArray(fgmask),learningRate ); })
    .method("getBackgroundImage",[](const cv::BackgroundSubtractor &instance,const  cv::Mat & backgroundImage) {    return instance.getBackgroundImage( cv::OutputArray(backgroundImage) ); });
  mod.add_type<cv::BackgroundSubtractorMOG2>("BackgroundSubtractorMOG2")
    .method("getHistory",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getHistory(  ); })
    .method("setHistory",[](cv::BackgroundSubtractorMOG2 &instance,int  history) {    return instance.setHistory( history ); })
    .method("getNMixtures",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getNMixtures(  ); })
    .method("setNMixtures",[](cv::BackgroundSubtractorMOG2 &instance,int  nmixtures) {    return instance.setNMixtures( nmixtures ); })
    .method("getBackgroundRatio",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getBackgroundRatio(  ); })
    .method("setBackgroundRatio",[](cv::BackgroundSubtractorMOG2 &instance,double  ratio) {    return instance.setBackgroundRatio( ratio ); })
    .method("getVarThreshold",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getVarThreshold(  ); })
    .method("setVarThreshold",[](cv::BackgroundSubtractorMOG2 &instance,double  varThreshold) {    return instance.setVarThreshold( varThreshold ); })
    .method("getVarThresholdGen",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getVarThresholdGen(  ); })
    .method("setVarThresholdGen",[](cv::BackgroundSubtractorMOG2 &instance,double  varThresholdGen) {    return instance.setVarThresholdGen( varThresholdGen ); })
    .method("getVarInit",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getVarInit(  ); })
    .method("setVarInit",[](cv::BackgroundSubtractorMOG2 &instance,double  varInit) {    return instance.setVarInit( varInit ); })
    .method("getVarMin",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getVarMin(  ); })
    .method("setVarMin",[](cv::BackgroundSubtractorMOG2 &instance,double  varMin) {    return instance.setVarMin( varMin ); })
    .method("getVarMax",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getVarMax(  ); })
    .method("setVarMax",[](cv::BackgroundSubtractorMOG2 &instance,double  varMax) {    return instance.setVarMax( varMax ); })
    .method("getComplexityReductionThreshold",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getComplexityReductionThreshold(  ); })
    .method("setComplexityReductionThreshold",[](cv::BackgroundSubtractorMOG2 &instance,double  ct) {    return instance.setComplexityReductionThreshold( ct ); })
    .method("getDetectShadows",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getDetectShadows(  ); })
    .method("setDetectShadows",[](cv::BackgroundSubtractorMOG2 &instance,bool  detectShadows) {    return instance.setDetectShadows( detectShadows ); })
    .method("getShadowValue",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getShadowValue(  ); })
    .method("setShadowValue",[](cv::BackgroundSubtractorMOG2 &instance,int  value) {    return instance.setShadowValue( value ); })
    .method("getShadowThreshold",[](const cv::BackgroundSubtractorMOG2 &instance) {    return instance.getShadowThreshold(  ); })
    .method("setShadowThreshold",[](cv::BackgroundSubtractorMOG2 &instance,double  threshold) {    return instance.setShadowThreshold( threshold ); })
    .method("apply",[](cv::BackgroundSubtractorMOG2 &instance,const  cv::Mat & image,const  cv::Mat & fgmask) {    return instance.apply( cv::InputArray(image),cv::OutputArray(fgmask) ); })
    .method("apply",[](cv::BackgroundSubtractorMOG2 &instance,const  cv::Mat & image,const  cv::Mat & fgmask,double  learningRate) {    return instance.apply( cv::InputArray(image),cv::OutputArray(fgmask),learningRate ); });
  mod.method("createBackgroundSubtractorMOG2", []() {
    return cv::createBackgroundSubtractorMOG2(  );
  });
  mod.method("createBackgroundSubtractorMOG2", [](int  history) {
    return cv::createBackgroundSubtractorMOG2( history );
  });
  mod.method("createBackgroundSubtractorMOG2", [](int  history,double  varThreshold) {
    return cv::createBackgroundSubtractorMOG2( history,varThreshold );
  });
  mod.method("createBackgroundSubtractorMOG2", [](int  history,double  varThreshold,bool  detectShadows) {
    return cv::createBackgroundSubtractorMOG2( history,varThreshold,detectShadows );
  });
  mod.add_type<cv::BackgroundSubtractorKNN>("BackgroundSubtractorKNN")
    .method("getHistory",[](const cv::BackgroundSubtractorKNN &instance) {    return instance.getHistory(  ); })
    .method("setHistory",[](cv::BackgroundSubtractorKNN &instance,int  history) {    return instance.setHistory( history ); })
    .method("getNSamples",[](const cv::BackgroundSubtractorKNN &instance) {    return instance.getNSamples(  ); })
    .method("setNSamples",[](cv::BackgroundSubtractorKNN &instance,int  _nN) {    return instance.setNSamples( _nN ); })
    .method("getDist2Threshold",[](const cv::BackgroundSubtractorKNN &instance) {    return instance.getDist2Threshold(  ); })
    .method("setDist2Threshold",[](cv::BackgroundSubtractorKNN &instance,double  _dist2Threshold) {    return instance.setDist2Threshold( _dist2Threshold ); })
    .method("getkNNSamples",[](const cv::BackgroundSubtractorKNN &instance) {    return instance.getkNNSamples(  ); })
    .method("setkNNSamples",[](cv::BackgroundSubtractorKNN &instance,int  _nkNN) {    return instance.setkNNSamples( _nkNN ); })
    .method("getDetectShadows",[](const cv::BackgroundSubtractorKNN &instance) {    return instance.getDetectShadows(  ); })
    .method("setDetectShadows",[](cv::BackgroundSubtractorKNN &instance,bool  detectShadows) {    return instance.setDetectShadows( detectShadows ); })
    .method("getShadowValue",[](const cv::BackgroundSubtractorKNN &instance) {    return instance.getShadowValue(  ); })
    .method("setShadowValue",[](cv::BackgroundSubtractorKNN &instance,int  value) {    return instance.setShadowValue( value ); })
    .method("getShadowThreshold",[](const cv::BackgroundSubtractorKNN &instance) {    return instance.getShadowThreshold(  ); })
    .method("setShadowThreshold",[](cv::BackgroundSubtractorKNN &instance,double  threshold) {    return instance.setShadowThreshold( threshold ); });
  mod.method("createBackgroundSubtractorKNN", []() {
    return cv::createBackgroundSubtractorKNN(  );
  });
  mod.method("createBackgroundSubtractorKNN", [](int  history) {
    return cv::createBackgroundSubtractorKNN( history );
  });
  mod.method("createBackgroundSubtractorKNN", [](int  history,double  dist2Threshold) {
    return cv::createBackgroundSubtractorKNN( history,dist2Threshold );
  });
  mod.method("createBackgroundSubtractorKNN", [](int  history,double  dist2Threshold,bool  detectShadows) {
    return cv::createBackgroundSubtractorKNN( history,dist2Threshold,detectShadows );
  });
}
