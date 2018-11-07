#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_core_module(Module& mod) {
  mod.add_type<cv::Exception>("Exception")
    .constructor<int, const cv::String &, const cv::String &, const cv::String &, int>()
    .method("msg",[](const cv::Exception &instance){return instance.msg;})
    .method("code",[](const cv::Exception &instance){return instance.code;})
    .method("err",[](const cv::Exception &instance){return instance.err;})
    .method("func",[](const cv::Exception &instance){return instance.func;})
    .method("file",[](const cv::Exception &instance){return instance.file;})
    .method("line",[](const cv::Exception &instance){return instance.line;});
  mod.method("error", [](const cv::Exception & exc) {
    return cv::error( exc );
  });
  mod.add_bits<cv::SortFlags>("SortFlags");
  mod.set_const("SORT_EVERY_ROW",cv::SortFlags::SORT_EVERY_ROW);
  mod.set_const("SORT_EVERY_COLUMN",cv::SortFlags::SORT_EVERY_COLUMN);
  mod.set_const("SORT_ASCENDING",cv::SortFlags::SORT_ASCENDING);
  mod.set_const("SORT_DESCENDING",cv::SortFlags::SORT_DESCENDING);
  mod.add_bits<cv::CovarFlags>("CovarFlags");
  mod.set_const("COVAR_SCRAMBLED",cv::CovarFlags::COVAR_SCRAMBLED);
  mod.set_const("COVAR_NORMAL",cv::CovarFlags::COVAR_NORMAL);
  mod.set_const("COVAR_USE_AVG",cv::CovarFlags::COVAR_USE_AVG);
  mod.set_const("COVAR_SCALE",cv::CovarFlags::COVAR_SCALE);
  mod.set_const("COVAR_ROWS",cv::CovarFlags::COVAR_ROWS);
  mod.set_const("COVAR_COLS",cv::CovarFlags::COVAR_COLS);
  mod.add_bits<cv::KmeansFlags>("KmeansFlags");
  mod.set_const("KMEANS_RANDOM_CENTERS",cv::KmeansFlags::KMEANS_RANDOM_CENTERS);
  mod.set_const("KMEANS_PP_CENTERS",cv::KmeansFlags::KMEANS_PP_CENTERS);
  mod.set_const("KMEANS_USE_INITIAL_LABELS",cv::KmeansFlags::KMEANS_USE_INITIAL_LABELS);
  mod.add_bits<cv::LineTypes>("LineTypes");
  mod.set_const("FILLED",cv::LineTypes::FILLED);
  mod.set_const("LINE_4",cv::LineTypes::LINE_4);
  mod.set_const("LINE_8",cv::LineTypes::LINE_8);
  mod.set_const("LINE_AA",cv::LineTypes::LINE_AA);
  mod.add_bits<cv::HersheyFonts>("HersheyFonts");
  mod.set_const("FONT_HERSHEY_SIMPLEX",cv::HersheyFonts::FONT_HERSHEY_SIMPLEX);
  mod.set_const("FONT_HERSHEY_PLAIN",cv::HersheyFonts::FONT_HERSHEY_PLAIN);
  mod.set_const("FONT_HERSHEY_DUPLEX",cv::HersheyFonts::FONT_HERSHEY_DUPLEX);
  mod.set_const("FONT_HERSHEY_COMPLEX",cv::HersheyFonts::FONT_HERSHEY_COMPLEX);
  mod.set_const("FONT_HERSHEY_TRIPLEX",cv::HersheyFonts::FONT_HERSHEY_TRIPLEX);
  mod.set_const("FONT_HERSHEY_COMPLEX_SMALL",cv::HersheyFonts::FONT_HERSHEY_COMPLEX_SMALL);
  mod.set_const("FONT_HERSHEY_SCRIPT_SIMPLEX",cv::HersheyFonts::FONT_HERSHEY_SCRIPT_SIMPLEX);
  mod.set_const("FONT_HERSHEY_SCRIPT_COMPLEX",cv::HersheyFonts::FONT_HERSHEY_SCRIPT_COMPLEX);
  mod.set_const("FONT_ITALIC",cv::HersheyFonts::FONT_ITALIC);
  mod.add_bits<cv::ReduceTypes>("ReduceTypes");
  mod.set_const("REDUCE_SUM",cv::ReduceTypes::REDUCE_SUM);
  mod.set_const("REDUCE_AVG",cv::ReduceTypes::REDUCE_AVG);
  mod.set_const("REDUCE_MAX",cv::ReduceTypes::REDUCE_MAX);
  mod.set_const("REDUCE_MIN",cv::ReduceTypes::REDUCE_MIN);
  mod.method("swap", [](cv::UMat & a,cv::UMat & b) {
    return cv::swap( a,b );
  });
  mod.method("borderInterpolate", [](int  p,int  len,int  borderType) {
    return cv::borderInterpolate( p,len,borderType );
  });
  mod.method("copyMakeBorder", [](const  cv::Mat & src,const  cv::Mat & dst,int  top,int  bottom,int  left,int  right,int  borderType) {
    return cv::copyMakeBorder( cv::InputArray(src),cv::OutputArray(dst),top,bottom,left,right,borderType );
  });
  mod.method("copyMakeBorder", [](const  cv::Mat & src,const  cv::Mat & dst,int  top,int  bottom,int  left,int  right,int  borderType,const cv::Scalar & value) {
    return cv::copyMakeBorder( cv::InputArray(src),cv::OutputArray(dst),top,bottom,left,right,borderType,value );
  });
  mod.method("add", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,const  cv::Mat & mask) {
    return cv::add( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),cv::InputArray(mask) );
  });
  mod.method("add", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,const  cv::Mat & mask,int  dtype) {
    return cv::add( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),cv::InputArray(mask),dtype );
  });
  mod.method("subtract", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,const  cv::Mat & mask) {
    return cv::subtract( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),cv::InputArray(mask) );
  });
  mod.method("subtract", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,const  cv::Mat & mask,int  dtype) {
    return cv::subtract( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),cv::InputArray(mask),dtype );
  });
  mod.method("multiply", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::multiply( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("multiply", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,double  scale) {
    return cv::multiply( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),scale );
  });
  mod.method("multiply", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,double  scale,int  dtype) {
    return cv::multiply( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),scale,dtype );
  });
  mod.method("divide", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::divide( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("divide", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,double  scale) {
    return cv::divide( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),scale );
  });
  mod.method("divide", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,double  scale,int  dtype) {
    return cv::divide( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),scale,dtype );
  });
  mod.method("divide", [](double  scale,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::divide( scale,cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("divide", [](double  scale,const  cv::Mat & src2,const  cv::Mat & dst,int  dtype) {
    return cv::divide( scale,cv::InputArray(src2),cv::OutputArray(dst),dtype );
  });
  mod.method("scaleAdd", [](const  cv::Mat & src1,double  alpha,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::scaleAdd( cv::InputArray(src1),alpha,cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("addWeighted", [](const  cv::Mat & src1,double  alpha,const  cv::Mat & src2,double  beta,double  gamma,const  cv::Mat & dst) {
    return cv::addWeighted( cv::InputArray(src1),alpha,cv::InputArray(src2),beta,gamma,cv::OutputArray(dst) );
  });
  mod.method("addWeighted", [](const  cv::Mat & src1,double  alpha,const  cv::Mat & src2,double  beta,double  gamma,const  cv::Mat & dst,int  dtype) {
    return cv::addWeighted( cv::InputArray(src1),alpha,cv::InputArray(src2),beta,gamma,cv::OutputArray(dst),dtype );
  });
  mod.method("convertScaleAbs", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::convertScaleAbs( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("convertScaleAbs", [](const  cv::Mat & src,const  cv::Mat & dst,double  alpha) {
    return cv::convertScaleAbs( cv::InputArray(src),cv::OutputArray(dst),alpha );
  });
  mod.method("convertScaleAbs", [](const  cv::Mat & src,const  cv::Mat & dst,double  alpha,double  beta) {
    return cv::convertScaleAbs( cv::InputArray(src),cv::OutputArray(dst),alpha,beta );
  });
  mod.method("convertFp16", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::convertFp16( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("LUT", [](const  cv::Mat & src,const  cv::Mat & lut,const  cv::Mat & dst) {
    return cv::LUT( cv::InputArray(src),cv::InputArray(lut),cv::OutputArray(dst) );
  });
  mod.method("sum", [](const  cv::Mat & src) {
    return cv::sum( cv::InputArray(src) );
  });
  mod.method("countNonZero", [](const  cv::Mat & src) {
    return cv::countNonZero( cv::InputArray(src) );
  });
  mod.method("findNonZero", [](const  cv::Mat & src,const  cv::Mat & idx) {
    return cv::findNonZero( cv::InputArray(src),cv::OutputArray(idx) );
  });
  mod.method("mean", [](const  cv::Mat & src,const  cv::Mat & mask) {
    return cv::mean( cv::InputArray(src),cv::InputArray(mask) );
  });
  mod.method("meanStdDev", [](const  cv::Mat & src,const  cv::Mat & mean,const  cv::Mat & stddev,const  cv::Mat & mask) {
    return cv::meanStdDev( cv::InputArray(src),cv::OutputArray(mean),cv::OutputArray(stddev),cv::InputArray(mask) );
  });
  mod.method("norm", [](const  cv::Mat & src1,int  normType,const  cv::Mat & mask) {
    return cv::norm( cv::InputArray(src1),normType,cv::InputArray(mask) );
  });
  mod.method("norm", [](const  cv::Mat & src1,const  cv::Mat & src2,int  normType,const  cv::Mat & mask) {
    return cv::norm( cv::InputArray(src1),cv::InputArray(src2),normType,cv::InputArray(mask) );
  });
  mod.method("norm", [](const cv::SparseMat & src,int  normType) {
    return cv::norm( src,normType );
  });
  mod.method("PSNR", [](const  cv::Mat & src1,const  cv::Mat & src2) {
    return cv::PSNR( cv::InputArray(src1),cv::InputArray(src2) );
  });
  mod.method("batchDistance", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dist,int  dtype,const  cv::Mat & nidx,int  normType,int  K,const  cv::Mat & mask) {
    return cv::batchDistance( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dist),dtype,cv::OutputArray(nidx),normType,K,cv::InputArray(mask) );
  });
  mod.method("batchDistance", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dist,int  dtype,const  cv::Mat & nidx,int  normType,int  K,const  cv::Mat & mask,int  update) {
    return cv::batchDistance( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dist),dtype,cv::OutputArray(nidx),normType,K,cv::InputArray(mask),update );
  });
  mod.method("batchDistance", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dist,int  dtype,const  cv::Mat & nidx,int  normType,int  K,const  cv::Mat & mask,int  update,bool  crosscheck) {
    return cv::batchDistance( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dist),dtype,cv::OutputArray(nidx),normType,K,cv::InputArray(mask),update,crosscheck );
  });
  mod.method("normalize", [](const  cv::Mat & src,const  cv::Mat & dst,double  alpha,double  beta,int  norm_type,int  dtype,const  cv::Mat & mask) {
    return cv::normalize( cv::InputArray(src),cv::InputOutputArray(dst),alpha,beta,norm_type,dtype,cv::InputArray(mask) );
  });
  mod.method("normalize", [](const cv::SparseMat & src,cv::SparseMat & dst,double  alpha,int  normType) {
    return cv::normalize( src,dst,alpha,normType );
  });
  mod.method("minMaxLoc", [](const  cv::Mat & src,double * minVal,double * maxVal,cv::Point * minLoc,cv::Point * maxLoc,const  cv::Mat & mask) {
    return cv::minMaxLoc( cv::InputArray(src),minVal,maxVal,minLoc,maxLoc,cv::InputArray(mask) );
  });
  mod.method("minMaxIdx", [](const  cv::Mat & src,double * minVal,double * maxVal,int * minIdx,int * maxIdx,const  cv::Mat & mask) {
    return cv::minMaxIdx( cv::InputArray(src),minVal,maxVal,minIdx,maxIdx,cv::InputArray(mask) );
  });
  mod.method("minMaxLoc", [](const cv::SparseMat & a,double * minVal,double * maxVal) {
    return cv::minMaxLoc( a,minVal,maxVal );
  });
  mod.method("minMaxLoc", [](const cv::SparseMat & a,double * minVal,double * maxVal,int * minIdx) {
    return cv::minMaxLoc( a,minVal,maxVal,minIdx );
  });
  mod.method("minMaxLoc", [](const cv::SparseMat & a,double * minVal,double * maxVal,int * minIdx,int * maxIdx) {
    return cv::minMaxLoc( a,minVal,maxVal,minIdx,maxIdx );
  });
  mod.method("reduce", [](const  cv::Mat & src,const  cv::Mat & dst,int  dim,int  rtype) {
    return cv::reduce( cv::InputArray(src),cv::OutputArray(dst),dim,rtype );
  });
  mod.method("reduce", [](const  cv::Mat & src,const  cv::Mat & dst,int  dim,int  rtype,int  dtype) {
    return cv::reduce( cv::InputArray(src),cv::OutputArray(dst),dim,rtype,dtype );
  });
  mod.method("extractChannel", [](const  cv::Mat & src,const  cv::Mat & dst,int  coi) {
    return cv::extractChannel( cv::InputArray(src),cv::OutputArray(dst),coi );
  });
  mod.method("insertChannel", [](const  cv::Mat & src,const  cv::Mat & dst,int  coi) {
    return cv::insertChannel( cv::InputArray(src),cv::InputOutputArray(dst),coi );
  });
  mod.method("flip", [](const  cv::Mat & src,const  cv::Mat & dst,int  flipCode) {
    return cv::flip( cv::InputArray(src),cv::OutputArray(dst),flipCode );
  });
  mod.add_bits<cv::RotateFlags>("RotateFlags");
  mod.set_const("ROTATE_90_CLOCKWISE",cv::RotateFlags::ROTATE_90_CLOCKWISE);
  mod.set_const("ROTATE_180",cv::RotateFlags::ROTATE_180);
  mod.set_const("ROTATE_90_COUNTERCLOCKWISE",cv::RotateFlags::ROTATE_90_COUNTERCLOCKWISE);
  mod.method("rotate", [](const  cv::Mat & src,const  cv::Mat & dst,int  rotateCode) {
    return cv::rotate( cv::InputArray(src),cv::OutputArray(dst),rotateCode );
  });
  mod.method("repeat", [](const  cv::Mat & src,int  ny,int  nx,const  cv::Mat & dst) {
    return cv::repeat( cv::InputArray(src),ny,nx,cv::OutputArray(dst) );
  });
  mod.method("repeat", [](const cv::Mat & src,int  ny,int  nx) {
    return cv::repeat( src,ny,nx );
  });
  mod.method("hconcat", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::hconcat( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("vconcat", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::vconcat( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("bitwise_and", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,const  cv::Mat & mask) {
    return cv::bitwise_and( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),cv::InputArray(mask) );
  });
  mod.method("bitwise_or", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,const  cv::Mat & mask) {
    return cv::bitwise_or( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),cv::InputArray(mask) );
  });
  mod.method("bitwise_xor", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,const  cv::Mat & mask) {
    return cv::bitwise_xor( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),cv::InputArray(mask) );
  });
  mod.method("bitwise_not", [](const  cv::Mat & src,const  cv::Mat & dst,const  cv::Mat & mask) {
    return cv::bitwise_not( cv::InputArray(src),cv::OutputArray(dst),cv::InputArray(mask) );
  });
  mod.method("absdiff", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::absdiff( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("inRange", [](const  cv::Mat & src,const  cv::Mat & lowerb,const  cv::Mat & upperb,const  cv::Mat & dst) {
    return cv::inRange( cv::InputArray(src),cv::InputArray(lowerb),cv::InputArray(upperb),cv::OutputArray(dst) );
  });
  mod.method("compare", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,int  cmpop) {
    return cv::compare( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),cmpop );
  });
  mod.method("min", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::min( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("min", [](const cv::UMat & src1,const cv::UMat & src2,cv::UMat & dst) {
    return cv::min( src1,src2,dst );
  });
  mod.method("max", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::max( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("max", [](const cv::UMat & src1,const cv::UMat & src2,cv::UMat & dst) {
    return cv::max( src1,src2,dst );
  });
  mod.method("sqrt", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::sqrt( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("pow", [](const  cv::Mat & src,double  power,const  cv::Mat & dst) {
    return cv::pow( cv::InputArray(src),power,cv::OutputArray(dst) );
  });
  mod.method("exp", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::exp( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("log", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::log( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("polarToCart", [](const  cv::Mat & magnitude,const  cv::Mat & angle,const  cv::Mat & x,const  cv::Mat & y) {
    return cv::polarToCart( cv::InputArray(magnitude),cv::InputArray(angle),cv::OutputArray(x),cv::OutputArray(y) );
  });
  mod.method("polarToCart", [](const  cv::Mat & magnitude,const  cv::Mat & angle,const  cv::Mat & x,const  cv::Mat & y,bool  angleInDegrees) {
    return cv::polarToCart( cv::InputArray(magnitude),cv::InputArray(angle),cv::OutputArray(x),cv::OutputArray(y),angleInDegrees );
  });
  mod.method("cartToPolar", [](const  cv::Mat & x,const  cv::Mat & y,const  cv::Mat & magnitude,const  cv::Mat & angle) {
    return cv::cartToPolar( cv::InputArray(x),cv::InputArray(y),cv::OutputArray(magnitude),cv::OutputArray(angle) );
  });
  mod.method("cartToPolar", [](const  cv::Mat & x,const  cv::Mat & y,const  cv::Mat & magnitude,const  cv::Mat & angle,bool  angleInDegrees) {
    return cv::cartToPolar( cv::InputArray(x),cv::InputArray(y),cv::OutputArray(magnitude),cv::OutputArray(angle),angleInDegrees );
  });
  mod.method("phase", [](const  cv::Mat & x,const  cv::Mat & y,const  cv::Mat & angle) {
    return cv::phase( cv::InputArray(x),cv::InputArray(y),cv::OutputArray(angle) );
  });
  mod.method("phase", [](const  cv::Mat & x,const  cv::Mat & y,const  cv::Mat & angle,bool  angleInDegrees) {
    return cv::phase( cv::InputArray(x),cv::InputArray(y),cv::OutputArray(angle),angleInDegrees );
  });
  mod.method("magnitude", [](const  cv::Mat & x,const  cv::Mat & y,const  cv::Mat & magnitude) {
    return cv::magnitude( cv::InputArray(x),cv::InputArray(y),cv::OutputArray(magnitude) );
  });
  mod.method("checkRange", [](const  cv::Mat & a) {
    return cv::checkRange( cv::InputArray(a) );
  });
  mod.method("checkRange", [](const  cv::Mat & a,bool  quiet) {
    return cv::checkRange( cv::InputArray(a),quiet );
  });
  mod.method("checkRange", [](const  cv::Mat & a,bool  quiet,cv::Point * pos) {
    return cv::checkRange( cv::InputArray(a),quiet,pos );
  });
  mod.method("checkRange", [](const  cv::Mat & a,bool  quiet,cv::Point * pos,double  minVal) {
    return cv::checkRange( cv::InputArray(a),quiet,pos,minVal );
  });
  mod.method("checkRange", [](const  cv::Mat & a,bool  quiet,cv::Point * pos,double  minVal,double  maxVal) {
    return cv::checkRange( cv::InputArray(a),quiet,pos,minVal,maxVal );
  });
  mod.method("patchNaNs", [](const  cv::Mat & a) {
    return cv::patchNaNs( cv::InputOutputArray(a) );
  });
  mod.method("patchNaNs", [](const  cv::Mat & a,double  val) {
    return cv::patchNaNs( cv::InputOutputArray(a),val );
  });
  mod.method("gemm", [](const  cv::Mat & src1,const  cv::Mat & src2,double  alpha,const  cv::Mat & src3,double  beta,const  cv::Mat & dst) {
    return cv::gemm( cv::InputArray(src1),cv::InputArray(src2),alpha,cv::InputArray(src3),beta,cv::OutputArray(dst) );
  });
  mod.method("gemm", [](const  cv::Mat & src1,const  cv::Mat & src2,double  alpha,const  cv::Mat & src3,double  beta,const  cv::Mat & dst,int  flags) {
    return cv::gemm( cv::InputArray(src1),cv::InputArray(src2),alpha,cv::InputArray(src3),beta,cv::OutputArray(dst),flags );
  });
  mod.method("mulTransposed", [](const  cv::Mat & src,const  cv::Mat & dst,bool  aTa,const  cv::Mat & delta) {
    return cv::mulTransposed( cv::InputArray(src),cv::OutputArray(dst),aTa,cv::InputArray(delta) );
  });
  mod.method("mulTransposed", [](const  cv::Mat & src,const  cv::Mat & dst,bool  aTa,const  cv::Mat & delta,double  scale) {
    return cv::mulTransposed( cv::InputArray(src),cv::OutputArray(dst),aTa,cv::InputArray(delta),scale );
  });
  mod.method("mulTransposed", [](const  cv::Mat & src,const  cv::Mat & dst,bool  aTa,const  cv::Mat & delta,double  scale,int  dtype) {
    return cv::mulTransposed( cv::InputArray(src),cv::OutputArray(dst),aTa,cv::InputArray(delta),scale,dtype );
  });
  mod.method("transpose", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::transpose( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("transform", [](const  cv::Mat & src,const  cv::Mat & dst,const  cv::Mat & m) {
    return cv::transform( cv::InputArray(src),cv::OutputArray(dst),cv::InputArray(m) );
  });
  mod.method("perspectiveTransform", [](const  cv::Mat & src,const  cv::Mat & dst,const  cv::Mat & m) {
    return cv::perspectiveTransform( cv::InputArray(src),cv::OutputArray(dst),cv::InputArray(m) );
  });
  mod.method("completeSymm", [](const  cv::Mat & m) {
    return cv::completeSymm( cv::InputOutputArray(m) );
  });
  mod.method("completeSymm", [](const  cv::Mat & m,bool  lowerToUpper) {
    return cv::completeSymm( cv::InputOutputArray(m),lowerToUpper );
  });
  mod.method("setIdentity", [](const  cv::Mat & mtx) {
    return cv::setIdentity( cv::InputOutputArray(mtx) );
  });
  mod.method("setIdentity", [](const  cv::Mat & mtx,const cv::Scalar & s) {
    return cv::setIdentity( cv::InputOutputArray(mtx),s );
  });
  mod.method("determinant", [](const  cv::Mat & mtx) {
    return cv::determinant( cv::InputArray(mtx) );
  });
  mod.method("trace", [](const  cv::Mat & mtx) {
    return cv::trace( cv::InputArray(mtx) );
  });
  mod.method("invert", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::invert( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("invert", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags) {
    return cv::invert( cv::InputArray(src),cv::OutputArray(dst),flags );
  });
  mod.method("solve", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst) {
    return cv::solve( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst) );
  });
  mod.method("solve", [](const  cv::Mat & src1,const  cv::Mat & src2,const  cv::Mat & dst,int  flags) {
    return cv::solve( cv::InputArray(src1),cv::InputArray(src2),cv::OutputArray(dst),flags );
  });
  mod.method("sort", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags) {
    return cv::sort( cv::InputArray(src),cv::OutputArray(dst),flags );
  });
  mod.method("sortIdx", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags) {
    return cv::sortIdx( cv::InputArray(src),cv::OutputArray(dst),flags );
  });
  mod.method("solveCubic", [](const  cv::Mat & coeffs,const  cv::Mat & roots) {
    return cv::solveCubic( cv::InputArray(coeffs),cv::OutputArray(roots) );
  });
  mod.method("solvePoly", [](const  cv::Mat & coeffs,const  cv::Mat & roots) {
    return cv::solvePoly( cv::InputArray(coeffs),cv::OutputArray(roots) );
  });
  mod.method("solvePoly", [](const  cv::Mat & coeffs,const  cv::Mat & roots,int  maxIters) {
    return cv::solvePoly( cv::InputArray(coeffs),cv::OutputArray(roots),maxIters );
  });
  mod.method("eigen", [](const  cv::Mat & src,const  cv::Mat & eigenvalues,const  cv::Mat & eigenvectors) {
    return cv::eigen( cv::InputArray(src),cv::OutputArray(eigenvalues),cv::OutputArray(eigenvectors) );
  });
  mod.method("eigenNonSymmetric", [](const  cv::Mat & src,const  cv::Mat & eigenvalues,const  cv::Mat & eigenvectors) {
    return cv::eigenNonSymmetric( cv::InputArray(src),cv::OutputArray(eigenvalues),cv::OutputArray(eigenvectors) );
  });
  mod.method("calcCovarMatrix", [](const  cv::Mat & samples,const  cv::Mat & covar,const  cv::Mat & mean,int  flags) {
    return cv::calcCovarMatrix( cv::InputArray(samples),cv::OutputArray(covar),cv::InputOutputArray(mean),flags );
  });
  mod.method("calcCovarMatrix", [](const  cv::Mat & samples,const  cv::Mat & covar,const  cv::Mat & mean,int  flags,int  ctype) {
    return cv::calcCovarMatrix( cv::InputArray(samples),cv::OutputArray(covar),cv::InputOutputArray(mean),flags,ctype );
  });
  mod.method("PCACompute", [](const  cv::Mat & data,const  cv::Mat & mean,const  cv::Mat & eigenvectors) {
    return cv::PCACompute( cv::InputArray(data),cv::InputOutputArray(mean),cv::OutputArray(eigenvectors) );
  });
  mod.method("PCACompute", [](const  cv::Mat & data,const  cv::Mat & mean,const  cv::Mat & eigenvectors,int  maxComponents) {
    return cv::PCACompute( cv::InputArray(data),cv::InputOutputArray(mean),cv::OutputArray(eigenvectors),maxComponents );
  });
  mod.method("PCACompute", [](const  cv::Mat & data,const  cv::Mat & mean,const  cv::Mat & eigenvectors,double  retainedVariance) {
    return cv::PCACompute( cv::InputArray(data),cv::InputOutputArray(mean),cv::OutputArray(eigenvectors),retainedVariance );
  });
  mod.method("PCAProject", [](const  cv::Mat & data,const  cv::Mat & mean,const  cv::Mat & eigenvectors,const  cv::Mat & result) {
    return cv::PCAProject( cv::InputArray(data),cv::InputArray(mean),cv::InputArray(eigenvectors),cv::OutputArray(result) );
  });
  mod.method("PCABackProject", [](const  cv::Mat & data,const  cv::Mat & mean,const  cv::Mat & eigenvectors,const  cv::Mat & result) {
    return cv::PCABackProject( cv::InputArray(data),cv::InputArray(mean),cv::InputArray(eigenvectors),cv::OutputArray(result) );
  });
  mod.method("SVDecomp", [](const  cv::Mat & src,const  cv::Mat & w,const  cv::Mat & u,const  cv::Mat & vt) {
    return cv::SVDecomp( cv::InputArray(src),cv::OutputArray(w),cv::OutputArray(u),cv::OutputArray(vt) );
  });
  mod.method("SVDecomp", [](const  cv::Mat & src,const  cv::Mat & w,const  cv::Mat & u,const  cv::Mat & vt,int  flags) {
    return cv::SVDecomp( cv::InputArray(src),cv::OutputArray(w),cv::OutputArray(u),cv::OutputArray(vt),flags );
  });
  mod.method("SVBackSubst", [](const  cv::Mat & w,const  cv::Mat & u,const  cv::Mat & vt,const  cv::Mat & rhs,const  cv::Mat & dst) {
    return cv::SVBackSubst( cv::InputArray(w),cv::InputArray(u),cv::InputArray(vt),cv::InputArray(rhs),cv::OutputArray(dst) );
  });
  mod.method("Mahalanobis", [](const  cv::Mat & v1,const  cv::Mat & v2,const  cv::Mat & icovar) {
    return cv::Mahalanobis( cv::InputArray(v1),cv::InputArray(v2),cv::InputArray(icovar) );
  });
  mod.method("dft", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::dft( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("dft", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags) {
    return cv::dft( cv::InputArray(src),cv::OutputArray(dst),flags );
  });
  mod.method("dft", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags,int  nonzeroRows) {
    return cv::dft( cv::InputArray(src),cv::OutputArray(dst),flags,nonzeroRows );
  });
  mod.method("idft", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::idft( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("idft", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags) {
    return cv::idft( cv::InputArray(src),cv::OutputArray(dst),flags );
  });
  mod.method("idft", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags,int  nonzeroRows) {
    return cv::idft( cv::InputArray(src),cv::OutputArray(dst),flags,nonzeroRows );
  });
  mod.method("dct", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::dct( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("dct", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags) {
    return cv::dct( cv::InputArray(src),cv::OutputArray(dst),flags );
  });
  mod.method("idct", [](const  cv::Mat & src,const  cv::Mat & dst) {
    return cv::idct( cv::InputArray(src),cv::OutputArray(dst) );
  });
  mod.method("idct", [](const  cv::Mat & src,const  cv::Mat & dst,int  flags) {
    return cv::idct( cv::InputArray(src),cv::OutputArray(dst),flags );
  });
  mod.method("mulSpectrums", [](const  cv::Mat & a,const  cv::Mat & b,const  cv::Mat & c,int  flags) {
    return cv::mulSpectrums( cv::InputArray(a),cv::InputArray(b),cv::OutputArray(c),flags );
  });
  mod.method("mulSpectrums", [](const  cv::Mat & a,const  cv::Mat & b,const  cv::Mat & c,int  flags,bool  conjB) {
    return cv::mulSpectrums( cv::InputArray(a),cv::InputArray(b),cv::OutputArray(c),flags,conjB );
  });
  mod.method("getOptimalDFTSize", [](int  vecsize) {
    return cv::getOptimalDFTSize( vecsize );
  });
  mod.method("theRNG", []() {
    return cv::theRNG(  );
  });
  mod.method("setRNGSeed", [](int  seed) {
    return cv::setRNGSeed( seed );
  });
  mod.method("randu", [](const  cv::Mat & dst,const  cv::Mat & low,const  cv::Mat & high) {
    return cv::randu( cv::InputOutputArray(dst),cv::InputArray(low),cv::InputArray(high) );
  });
  mod.method("randn", [](const  cv::Mat & dst,const  cv::Mat & mean,const  cv::Mat & stddev) {
    return cv::randn( cv::InputOutputArray(dst),cv::InputArray(mean),cv::InputArray(stddev) );
  });
  mod.method("randShuffle", [](const  cv::Mat & dst) {
    return cv::randShuffle( cv::InputOutputArray(dst) );
  });
  mod.method("randShuffle", [](const  cv::Mat & dst,double  iterFactor) {
    return cv::randShuffle( cv::InputOutputArray(dst),iterFactor );
  });
  mod.method("randShuffle", [](const  cv::Mat & dst,double  iterFactor,cv::RNG * rng) {
    return cv::randShuffle( cv::InputOutputArray(dst),iterFactor,rng );
  });
  mod.add_type<cv::PCA>("PCA")
    .constructor<cv::InputArray, cv::InputArray, int, int>()
    .constructor<cv::InputArray, cv::InputArray, int, double>()
    .method("eigenvectors",[](const cv::PCA &instance){return instance.eigenvectors;})
    .method("eigenvalues",[](const cv::PCA &instance){return instance.eigenvalues;})
    .method("mean",[](const cv::PCA &instance){return instance.mean;});
  mod.add_type<cv::LDA>("LDA")
    .constructor<int>()
    .constructor<cv::InputArrayOfArrays, cv::InputArray, int>();
  mod.add_type<cv::SVD>("SVD")
    .constructor<cv::InputArray, int>()
    .method("u",[](const cv::SVD &instance){return instance.u;})
    .method("w",[](const cv::SVD &instance){return instance.w;})
    .method("vt",[](const cv::SVD &instance){return instance.vt;});
  mod.add_type<cv::RNG>("RNG")
    .constructor<uint64>()
    .method("state",[](const cv::RNG &instance){return instance.state;});
  mod.add_type<cv::RNG_MT19937>("RNG_MT19937")
    .constructor<unsigned int>();
  mod.method("kmeans", [](const  cv::Mat & data,int  K,const  cv::Mat & bestLabels,cv::TermCriteria  criteria,int  attempts,int  flags,const  cv::Mat & centers) {
    return cv::kmeans( cv::InputArray(data),K,cv::InputOutputArray(bestLabels),criteria,attempts,flags,cv::OutputArray(centers) );
  });
  mod.add_type<cv::Formatted>("Formatted");
  mod.add_type<cv::Formatter>("Formatter");
  mod.add_type<cv::Algorithm>("Algorithm");
  mod.add_type<cv::Param>("Param");
}
