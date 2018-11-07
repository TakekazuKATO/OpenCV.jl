#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_photo_module(Module& mod) {
  mod.set_const("INPAINT_NS",(int)cv::INPAINT_NS);
  mod.set_const("INPAINT_TELEA",(int)cv::INPAINT_TELEA);
  mod.set_const("NORMAL_CLONE",(int)cv::NORMAL_CLONE);
  mod.set_const("MIXED_CLONE",(int)cv::MIXED_CLONE);
  mod.set_const("MONOCHROME_TRANSFER",(int)cv::MONOCHROME_TRANSFER);
  mod.set_const("RECURS_FILTER",(int)cv::RECURS_FILTER);
  mod.set_const("NORMCONV_FILTER",(int)cv::NORMCONV_FILTER);
  mod.method("inpaint", [](const  cv::Mat & src,const  cv::Mat & inpaintMask,const  cv::Mat & dst,double  inpaintRadius,int  flags) {
    return cv::inpaint( cv::InputArray(src),cv::InputArray(inpaintMask),cv::OutputArray(dst),inpaintRadius,flags );
  });
  mod.method("fastNlMeansDenoising", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::fastNlMeansDenoising( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("fastNlMeansDenoising", [](const  cv::Mat & src,const  cv::Mat & dst,float  h) {
    return cv::fastNlMeansDenoising( cv::InputArray(src),cv::OutputArray(dst),h );
  });
  mod.method("fastNlMeansDenoising", [](const  cv::Mat & src,const  cv::Mat & dst,float  h,int  templateWindowSize) {
    return cv::fastNlMeansDenoising( cv::InputArray(src),cv::OutputArray(dst),h,templateWindowSize );
  });
  mod.method("fastNlMeansDenoising", [](const  cv::Mat & src,const  cv::Mat & dst,float  h,int  templateWindowSize,int  searchWindowSize) {
    return cv::fastNlMeansDenoising( cv::InputArray(src),cv::OutputArray(dst),h,templateWindowSize,searchWindowSize );
  });
  mod.method("fastNlMeansDenoising", [](const  cv::Mat & src,const  cv::Mat & dst,const std::vector<float> & h) {
    return cv::fastNlMeansDenoising( cv::InputArray(src),cv::OutputArray(dst),h );
  });
  mod.method("fastNlMeansDenoising", [](const  cv::Mat & src,const  cv::Mat & dst,const std::vector<float> & h,int  templateWindowSize) {
    return cv::fastNlMeansDenoising( cv::InputArray(src),cv::OutputArray(dst),h,templateWindowSize );
  });
  mod.method("fastNlMeansDenoising", [](const  cv::Mat & src,const  cv::Mat & dst,const std::vector<float> & h,int  templateWindowSize,int  searchWindowSize) {
    return cv::fastNlMeansDenoising( cv::InputArray(src),cv::OutputArray(dst),h,templateWindowSize,searchWindowSize );
  });
  mod.method("fastNlMeansDenoising", [](const  cv::Mat & src,const  cv::Mat & dst,const std::vector<float> & h,int  templateWindowSize,int  searchWindowSize,int  normType) {
    return cv::fastNlMeansDenoising( cv::InputArray(src),cv::OutputArray(dst),h,templateWindowSize,searchWindowSize,normType );
  });
  mod.method("fastNlMeansDenoisingColored", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::fastNlMeansDenoisingColored( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("fastNlMeansDenoisingColored", [](const  cv::Mat & src,const  cv::Mat & dst,float  h) {
    return cv::fastNlMeansDenoisingColored( cv::InputArray(src),cv::OutputArray(dst),h );
  });
  mod.method("fastNlMeansDenoisingColored", [](const  cv::Mat & src,const  cv::Mat & dst,float  h,float  hColor) {
    return cv::fastNlMeansDenoisingColored( cv::InputArray(src),cv::OutputArray(dst),h,hColor );
  });
  mod.method("fastNlMeansDenoisingColored", [](const  cv::Mat & src,const  cv::Mat & dst,float  h,float  hColor,int  templateWindowSize) {
    return cv::fastNlMeansDenoisingColored( cv::InputArray(src),cv::OutputArray(dst),h,hColor,templateWindowSize );
  });
  mod.method("fastNlMeansDenoisingColored", [](const  cv::Mat & src,const  cv::Mat & dst,float  h,float  hColor,int  templateWindowSize,int  searchWindowSize) {
    return cv::fastNlMeansDenoisingColored( cv::InputArray(src),cv::OutputArray(dst),h,hColor,templateWindowSize,searchWindowSize );
  });
  mod.set_const("LDR_SIZE",(int)cv::LDR_SIZE);
  mod.add_type<cv::Tonemap>("Tonemap");
  mod.method("createTonemap", []() {
    return cv::createTonemap(  );
  });
  mod.method("createTonemap", [](float  gamma) {
    return cv::createTonemap( gamma );
  });
  mod.add_type<cv::TonemapDrago>("TonemapDrago");
  mod.method("createTonemapDrago", []() {
    return cv::createTonemapDrago(  );
  });
  mod.method("createTonemapDrago", [](float  gamma) {
    return cv::createTonemapDrago( gamma );
  });
  mod.method("createTonemapDrago", [](float  gamma,float  saturation) {
    return cv::createTonemapDrago( gamma,saturation );
  });
  mod.method("createTonemapDrago", [](float  gamma,float  saturation,float  bias) {
    return cv::createTonemapDrago( gamma,saturation,bias );
  });
  mod.add_type<cv::TonemapDurand>("TonemapDurand");
  mod.method("createTonemapDurand", []() {
    return cv::createTonemapDurand(  );
  });
  mod.method("createTonemapDurand", [](float  gamma) {
    return cv::createTonemapDurand( gamma );
  });
  mod.method("createTonemapDurand", [](float  gamma,float  contrast) {
    return cv::createTonemapDurand( gamma,contrast );
  });
  mod.method("createTonemapDurand", [](float  gamma,float  contrast,float  saturation) {
    return cv::createTonemapDurand( gamma,contrast,saturation );
  });
  mod.method("createTonemapDurand", [](float  gamma,float  contrast,float  saturation,float  sigma_space) {
    return cv::createTonemapDurand( gamma,contrast,saturation,sigma_space );
  });
  mod.method("createTonemapDurand", [](float  gamma,float  contrast,float  saturation,float  sigma_space,float  sigma_color) {
    return cv::createTonemapDurand( gamma,contrast,saturation,sigma_space,sigma_color );
  });
  mod.add_type<cv::TonemapReinhard>("TonemapReinhard");
  mod.method("createTonemapReinhard", []() {
    return cv::createTonemapReinhard(  );
  });
  mod.method("createTonemapReinhard", [](float  gamma) {
    return cv::createTonemapReinhard( gamma );
  });
  mod.method("createTonemapReinhard", [](float  gamma,float  intensity) {
    return cv::createTonemapReinhard( gamma,intensity );
  });
  mod.method("createTonemapReinhard", [](float  gamma,float  intensity,float  light_adapt) {
    return cv::createTonemapReinhard( gamma,intensity,light_adapt );
  });
  mod.method("createTonemapReinhard", [](float  gamma,float  intensity,float  light_adapt,float  color_adapt) {
    return cv::createTonemapReinhard( gamma,intensity,light_adapt,color_adapt );
  });
  mod.add_type<cv::TonemapMantiuk>("TonemapMantiuk");
  mod.method("createTonemapMantiuk", []() {
    return cv::createTonemapMantiuk(  );
  });
  mod.method("createTonemapMantiuk", [](float  gamma) {
    return cv::createTonemapMantiuk( gamma );
  });
  mod.method("createTonemapMantiuk", [](float  gamma,float  scale) {
    return cv::createTonemapMantiuk( gamma,scale );
  });
  mod.method("createTonemapMantiuk", [](float  gamma,float  scale,float  saturation) {
    return cv::createTonemapMantiuk( gamma,scale,saturation );
  });
  mod.add_type<cv::AlignExposures>("AlignExposures");
  mod.add_type<cv::AlignMTB>("AlignMTB");
  mod.method("createAlignMTB", []() {
    return cv::createAlignMTB(  );
  });
  mod.method("createAlignMTB", [](int  max_bits) {
    return cv::createAlignMTB( max_bits );
  });
  mod.method("createAlignMTB", [](int  max_bits,int  exclude_range) {
    return cv::createAlignMTB( max_bits,exclude_range );
  });
  mod.method("createAlignMTB", [](int  max_bits,int  exclude_range,bool  cut) {
    return cv::createAlignMTB( max_bits,exclude_range,cut );
  });
  mod.add_type<cv::CalibrateCRF>("CalibrateCRF");
  mod.add_type<cv::CalibrateDebevec>("CalibrateDebevec");
  mod.method("createCalibrateDebevec", []() {
    return cv::createCalibrateDebevec(  );
  });
  mod.method("createCalibrateDebevec", [](int  samples) {
    return cv::createCalibrateDebevec( samples );
  });
  mod.method("createCalibrateDebevec", [](int  samples,float  lambda) {
    return cv::createCalibrateDebevec( samples,lambda );
  });
  mod.method("createCalibrateDebevec", [](int  samples,float  lambda,bool  random) {
    return cv::createCalibrateDebevec( samples,lambda,random );
  });
  mod.add_type<cv::CalibrateRobertson>("CalibrateRobertson");
  mod.method("createCalibrateRobertson", []() {
    return cv::createCalibrateRobertson(  );
  });
  mod.method("createCalibrateRobertson", [](int  max_iter) {
    return cv::createCalibrateRobertson( max_iter );
  });
  mod.method("createCalibrateRobertson", [](int  max_iter,float  threshold) {
    return cv::createCalibrateRobertson( max_iter,threshold );
  });
  mod.add_type<cv::MergeExposures>("MergeExposures");
  mod.add_type<cv::MergeDebevec>("MergeDebevec");
  mod.method("createMergeDebevec", []() {
    return cv::createMergeDebevec(  );
  });
  mod.add_type<cv::MergeMertens>("MergeMertens");
  mod.method("createMergeMertens", []() {
    return cv::createMergeMertens(  );
  });
  mod.method("createMergeMertens", [](float  contrast_weight) {
    return cv::createMergeMertens( contrast_weight );
  });
  mod.method("createMergeMertens", [](float  contrast_weight,float  saturation_weight) {
    return cv::createMergeMertens( contrast_weight,saturation_weight );
  });
  mod.method("createMergeMertens", [](float  contrast_weight,float  saturation_weight,float  exposure_weight) {
    return cv::createMergeMertens( contrast_weight,saturation_weight,exposure_weight );
  });
  mod.add_type<cv::MergeRobertson>("MergeRobertson");
  mod.method("createMergeRobertson", []() {
    return cv::createMergeRobertson(  );
  });
  mod.method("decolor", [](const  cv::Mat & src,const  cv::Mat & grayscale,const  cv::Mat & color_boost) {
    return cv::decolor( cv::InputArray(src),cv::OutputArray(grayscale),cv::OutputArray(color_boost) );
  });
  mod.method("seamlessClone", [](const  cv::Mat & src,const  cv::Mat & dst,const  cv::Mat & mask,cv::Point  p,const  cv::Mat & blend,int  flags) {
    return cv::seamlessClone( cv::InputArray(src),cv::InputArray(dst),cv::InputArray(mask),p,cv::OutputArray(blend),flags );
  });
  mod.method("colorChange", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst) {
    return cv::colorChange( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst) );
  });
  mod.method("colorChange", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst,float  red_mul) {
    return cv::colorChange( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst),red_mul );
  });
  mod.method("colorChange", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst,float  red_mul,float  green_mul) {
    return cv::colorChange( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst),red_mul,green_mul );
  });
  mod.method("colorChange", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst,float  red_mul,float  green_mul,float  blue_mul) {
    return cv::colorChange( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst),red_mul,green_mul,blue_mul );
  });
  mod.method("illuminationChange", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst) {
    return cv::illuminationChange( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst) );
  });
  mod.method("illuminationChange", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst,float  alpha) {
    return cv::illuminationChange( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst),alpha );
  });
  mod.method("illuminationChange", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst,float  alpha,float  beta) {
    return cv::illuminationChange( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst),alpha,beta );
  });
  mod.method("textureFlattening", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst) {
    return cv::textureFlattening( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst) );
  });
  mod.method("textureFlattening", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst,float  low_threshold) {
    return cv::textureFlattening( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst),low_threshold );
  });
  mod.method("textureFlattening", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst,float  low_threshold,float  high_threshold) {
    return cv::textureFlattening( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst),low_threshold,high_threshold );
  });
  mod.method("textureFlattening", [](const  cv::Mat & src,const  cv::Mat & mask,const  cv::Mat & dst,float  low_threshold,float  high_threshold,int  kernel_size) {
    return cv::textureFlattening( cv::InputArray(src),cv::InputArray(mask),cv::OutputArray(dst),low_threshold,high_threshold,kernel_size );
  });
  mod.method("edgePreservingFilter", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::edgePreservingFilter( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("edgePreservingFilter", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags) {
    return cv::edgePreservingFilter( cv::InputArray(src),cv::OutputArray(dst),flags );
  });
  mod.method("edgePreservingFilter", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags,float  sigma_s) {
    return cv::edgePreservingFilter( cv::InputArray(src),cv::OutputArray(dst),flags,sigma_s );
  });
  mod.method("edgePreservingFilter", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags,float  sigma_s,float  sigma_r) {
    return cv::edgePreservingFilter( cv::InputArray(src),cv::OutputArray(dst),flags,sigma_s,sigma_r );
  });
  mod.method("detailEnhance", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::detailEnhance( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("detailEnhance", [](const  cv::Mat & src,const  cv::Mat & dst,float  sigma_s) {
    return cv::detailEnhance( cv::InputArray(src),cv::OutputArray(dst),sigma_s );
  });
  mod.method("detailEnhance", [](const  cv::Mat & src,const  cv::Mat & dst,float  sigma_s,float  sigma_r) {
    return cv::detailEnhance( cv::InputArray(src),cv::OutputArray(dst),sigma_s,sigma_r );
  });
  mod.method("pencilSketch", [](const  cv::Mat & src,const  cv::Mat & dst1,const  cv::Mat & dst2) {
    return cv::pencilSketch( cv::InputArray(src),cv::OutputArray(dst1),cv::OutputArray(dst2) );
  });
  mod.method("pencilSketch", [](const  cv::Mat & src,const  cv::Mat & dst1,const  cv::Mat & dst2,float  sigma_s) {
    return cv::pencilSketch( cv::InputArray(src),cv::OutputArray(dst1),cv::OutputArray(dst2),sigma_s );
  });
  mod.method("pencilSketch", [](const  cv::Mat & src,const  cv::Mat & dst1,const  cv::Mat & dst2,float  sigma_s,float  sigma_r) {
    return cv::pencilSketch( cv::InputArray(src),cv::OutputArray(dst1),cv::OutputArray(dst2),sigma_s,sigma_r );
  });
  mod.method("pencilSketch", [](const  cv::Mat & src,const  cv::Mat & dst1,const  cv::Mat & dst2,float  sigma_s,float  sigma_r,float  shade_factor) {
    return cv::pencilSketch( cv::InputArray(src),cv::OutputArray(dst1),cv::OutputArray(dst2),sigma_s,sigma_r,shade_factor );
  });
  mod.method("stylization", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::stylization( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("stylization", [](const  cv::Mat & src,const  cv::Mat & dst,float  sigma_s) {
    return cv::stylization( cv::InputArray(src),cv::OutputArray(dst),sigma_s );
  });
  mod.method("stylization", [](const  cv::Mat & src,const  cv::Mat & dst,float  sigma_s,float  sigma_r) {
    return cv::stylization( cv::InputArray(src),cv::OutputArray(dst),sigma_s,sigma_r );
  });
}
