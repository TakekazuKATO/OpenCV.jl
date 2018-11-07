#include <opencv2/dnn/all_layers.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_dnn_all_layers_module(Module &mod) {
  mod.add_type<cv::dnn::experimental_dnn_v5::BlankLayer>("BlankLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::BlankLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::LSTMLayer>("LSTMLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              })
      .method("setWeights",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance,
                 const cv::Mat &Wh, const cv::Mat &Wx,
                 const cv::Mat &b) { return instance.setWeights(Wh, Wx, b); })
      .method("setOutShape",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance) {
                return instance.setOutShape();
              })
      .method("setOutShape",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance,
                 const cv::dnn::experimental_dnn_v5::MatShape &outTailShape) {
                return instance.setOutShape(outTailShape);
              })
      .method("setUseTimstampsDim",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance) {
                return instance.setUseTimstampsDim();
              })
      .method("setUseTimstampsDim",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance, bool use) {
                return instance.setUseTimstampsDim(use);
              })
      .method("setProduceCellOutput",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance) {
                return instance.setProduceCellOutput();
              })
      .method(
          "setProduceCellOutput",
          [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance, bool produce) {
            return instance.setProduceCellOutput(produce);
          })
      .method("inputNameToIndex",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance,
                 cv::String inputName) {
                return instance.inputNameToIndex(inputName);
              })
      .method("outputNameToIndex",
              [](cv::dnn::experimental_dnn_v5::LSTMLayer &instance,
                 const cv::String &outputName) {
                return instance.outputNameToIndex(outputName);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::RNNLayer>("RNNLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::RNNLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              })
      .method("setWeights",
              [](cv::dnn::experimental_dnn_v5::RNNLayer &instance,
                 const cv::Mat &Wxh, const cv::Mat &bh, const cv::Mat &Whh,
                 const cv::Mat &Who, const cv::Mat &bo) {
                return instance.setWeights(Wxh, bh, Whh, Who, bo);
              })
      .method("setProduceHiddenOutput",
              [](cv::dnn::experimental_dnn_v5::RNNLayer &instance) {
                return instance.setProduceHiddenOutput();
              })
      .method(
          "setProduceHiddenOutput",
          [](cv::dnn::experimental_dnn_v5::RNNLayer &instance, bool produce) {
            return instance.setProduceHiddenOutput(produce);
          });
  mod.add_type<cv::dnn::experimental_dnn_v5::BaseConvolutionLayer>(
         "BaseConvolutionLayer")
      .method("kernel",
              [](const cv::dnn::experimental_dnn_v5::BaseConvolutionLayer
                     &instance) { return instance.kernel; })
      .method("stride",
              [](const cv::dnn::experimental_dnn_v5::BaseConvolutionLayer
                     &instance) { return instance.stride; })
      .method("pad", [](const cv::dnn::experimental_dnn_v5::BaseConvolutionLayer
                            &instance) { return instance.pad; })
      .method("dilation",
              [](const cv::dnn::experimental_dnn_v5::BaseConvolutionLayer
                     &instance) { return instance.dilation; })
      .method("adjustPad",
              [](const cv::dnn::experimental_dnn_v5::BaseConvolutionLayer
                     &instance) { return instance.adjustPad; })
      .method("padMode",
              [](const cv::dnn::experimental_dnn_v5::BaseConvolutionLayer
                     &instance) { return instance.padMode; })
      .method("numOutput",
              [](const cv::dnn::experimental_dnn_v5::BaseConvolutionLayer
                     &instance) { return instance.numOutput; });
  mod.add_type<cv::dnn::experimental_dnn_v5::ConvolutionLayer>(
         "ConvolutionLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ConvolutionLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::DeconvolutionLayer>(
         "DeconvolutionLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::DeconvolutionLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::LRNLayer>("LRNLayer")
      .method("type",
              [](const cv::dnn::experimental_dnn_v5::LRNLayer &instance) {
                return instance.type;
              })
      .method("size",
              [](const cv::dnn::experimental_dnn_v5::LRNLayer &instance) {
                return instance.size;
              })
      .method("alpha",
              [](const cv::dnn::experimental_dnn_v5::LRNLayer &instance) {
                return instance.alpha;
              })
      .method("beta",
              [](const cv::dnn::experimental_dnn_v5::LRNLayer &instance) {
                return instance.beta;
              })
      .method("bias",
              [](const cv::dnn::experimental_dnn_v5::LRNLayer &instance) {
                return instance.bias;
              })
      .method("normBySize",
              [](const cv::dnn::experimental_dnn_v5::LRNLayer &instance) {
                return instance.normBySize;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::LRNLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::PoolingLayer>("PoolingLayer")
      .method("type",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.type;
              })
      .method("kernel",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.kernel;
              })
      .method("stride",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.stride;
              })
      .method("pad",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.pad;
              })
      .method("globalPooling",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.globalPooling;
              })
      .method("computeMaxIdx",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.computeMaxIdx;
              })
      .method("padMode",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.padMode;
              })
      .method("ceilMode",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.ceilMode;
              })
      .method("avePoolPaddedArea",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.avePoolPaddedArea;
              })
      .method("pooledSize",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.pooledSize;
              })
      .method("spatialScale",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.spatialScale;
              })
      .method("psRoiOutChannels",
              [](const cv::dnn::experimental_dnn_v5::PoolingLayer &instance) {
                return instance.psRoiOutChannels;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::PoolingLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::SoftmaxLayer>("SoftmaxLayer")
      .method("logSoftMax",
              [](const cv::dnn::experimental_dnn_v5::SoftmaxLayer &instance) {
                return instance.logSoftMax;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::SoftmaxLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::InnerProductLayer>(
         "InnerProductLayer")
      .method(
          "axis",
          [](const cv::dnn::experimental_dnn_v5::InnerProductLayer &instance) {
            return instance.axis;
          })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::InnerProductLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::MVNLayer>("MVNLayer")
      .method("eps",
              [](const cv::dnn::experimental_dnn_v5::MVNLayer &instance) {
                return instance.eps;
              })
      .method("normVariance",
              [](const cv::dnn::experimental_dnn_v5::MVNLayer &instance) {
                return instance.normVariance;
              })
      .method("acrossChannels",
              [](const cv::dnn::experimental_dnn_v5::MVNLayer &instance) {
                return instance.acrossChannels;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::MVNLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ReshapeLayer>("ReshapeLayer")
      .method("newShapeDesc",
              [](const cv::dnn::experimental_dnn_v5::ReshapeLayer &instance) {
                return instance.newShapeDesc;
              })
      .method("newShapeRange",
              [](const cv::dnn::experimental_dnn_v5::ReshapeLayer &instance) {
                return instance.newShapeRange;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ReshapeLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::FlattenLayer>("FlattenLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::FlattenLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ConcatLayer>("ConcatLayer")
      .method("axis",
              [](const cv::dnn::experimental_dnn_v5::ConcatLayer &instance) {
                return instance.axis;
              })
      .method("padding",
              [](const cv::dnn::experimental_dnn_v5::ConcatLayer &instance) {
                return instance.padding;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ConcatLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::SplitLayer>("SplitLayer")
      .method("outputsCount",
              [](const cv::dnn::experimental_dnn_v5::SplitLayer &instance) {
                return instance.outputsCount;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::SplitLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::SliceLayer>("SliceLayer")
      .method("sliceRanges",
              [](const cv::dnn::experimental_dnn_v5::SliceLayer &instance) {
                return instance.sliceRanges;
              })
      .method("axis",
              [](const cv::dnn::experimental_dnn_v5::SliceLayer &instance) {
                return instance.axis;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::SliceLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::PermuteLayer>("PermuteLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::PermuteLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ShuffleChannelLayer>(
         "ShuffleChannelLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ShuffleChannelLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              })
      .method("group",
              [](const cv::dnn::experimental_dnn_v5::ShuffleChannelLayer
                     &instance) { return instance.group; });
  mod.add_type<cv::dnn::experimental_dnn_v5::PaddingLayer>("PaddingLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::PaddingLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ActivationLayer>("ActivationLayer")
      .method("forwardSlice",
              [](const cv::dnn::experimental_dnn_v5::ActivationLayer &instance,
                 const float *src, float *dst, int len, size_t outPlaneSize,
                 int cn0, int cn1) {
                return instance.forwardSlice(src, dst, len, outPlaneSize, cn0,
                                             cn1);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ReLULayer>("ReLULayer")
      .method("negativeSlope",
              [](const cv::dnn::experimental_dnn_v5::ReLULayer &instance) {
                return instance.negativeSlope;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ReLULayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ReLU6Layer>("ReLU6Layer")
      .method("minValue",
              [](const cv::dnn::experimental_dnn_v5::ReLU6Layer &instance) {
                return instance.minValue;
              })
      .method("maxValue",
              [](const cv::dnn::experimental_dnn_v5::ReLU6Layer &instance) {
                return instance.maxValue;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ReLU6Layer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ChannelsPReLULayer>(
         "ChannelsPReLULayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ChannelsPReLULayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ELULayer>("ELULayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ELULayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::TanHLayer>("TanHLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::TanHLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::SigmoidLayer>("SigmoidLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::SigmoidLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::BNLLLayer>("BNLLLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::BNLLLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::AbsLayer>("AbsLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::AbsLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::PowerLayer>("PowerLayer")
      .method("power",
              [](const cv::dnn::experimental_dnn_v5::PowerLayer &instance) {
                return instance.power;
              })
      .method("scale",
              [](const cv::dnn::experimental_dnn_v5::PowerLayer &instance) {
                return instance.scale;
              })
      .method("shift",
              [](const cv::dnn::experimental_dnn_v5::PowerLayer &instance) {
                return instance.shift;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::PowerLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::CropLayer>("CropLayer")
      .method("startAxis",
              [](const cv::dnn::experimental_dnn_v5::CropLayer &instance) {
                return instance.startAxis;
              })
      .method("offset",
              [](const cv::dnn::experimental_dnn_v5::CropLayer &instance) {
                return instance.offset;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::CropLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::EltwiseLayer>("EltwiseLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::EltwiseLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::BatchNormLayer>("BatchNormLayer")
      .method("hasWeights",
              [](const cv::dnn::experimental_dnn_v5::BatchNormLayer &instance) {
                return instance.hasWeights;
              })
      .method("hasBias",
              [](const cv::dnn::experimental_dnn_v5::BatchNormLayer &instance) {
                return instance.hasBias;
              })
      .method("epsilon",
              [](const cv::dnn::experimental_dnn_v5::BatchNormLayer &instance) {
                return instance.epsilon;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::BatchNormLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::MaxUnpoolLayer>("MaxUnpoolLayer")
      .method("poolKernel",
              [](const cv::dnn::experimental_dnn_v5::MaxUnpoolLayer &instance) {
                return instance.poolKernel;
              })
      .method("poolPad",
              [](const cv::dnn::experimental_dnn_v5::MaxUnpoolLayer &instance) {
                return instance.poolPad;
              })
      .method("poolStride",
              [](const cv::dnn::experimental_dnn_v5::MaxUnpoolLayer &instance) {
                return instance.poolStride;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::MaxUnpoolLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ScaleLayer>("ScaleLayer")
      .method("hasBias",
              [](const cv::dnn::experimental_dnn_v5::ScaleLayer &instance) {
                return instance.hasBias;
              })
      .method("axis",
              [](const cv::dnn::experimental_dnn_v5::ScaleLayer &instance) {
                return instance.axis;
              })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ScaleLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ShiftLayer>("ShiftLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ShiftLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::PriorBoxLayer>("PriorBoxLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::PriorBoxLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ReorgLayer>("ReorgLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ReorgLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::RegionLayer>("RegionLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::RegionLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::DetectionOutputLayer>(
         "DetectionOutputLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::DetectionOutputLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::NormalizeBBoxLayer>(
         "NormalizeBBoxLayer")
      .method(
          "pnorm",
          [](const cv::dnn::experimental_dnn_v5::NormalizeBBoxLayer &instance) {
            return instance.pnorm;
          })
      .method(
          "epsilon",
          [](const cv::dnn::experimental_dnn_v5::NormalizeBBoxLayer &instance) {
            return instance.epsilon;
          })
      .method(
          "acrossSpatial",
          [](const cv::dnn::experimental_dnn_v5::NormalizeBBoxLayer &instance) {
            return instance.acrossSpatial;
          })
      .method("create",
              [](cv::dnn::experimental_dnn_v5::NormalizeBBoxLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ResizeLayer>("ResizeLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ResizeLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::InterpLayer>("InterpLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::InterpLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::ProposalLayer>("ProposalLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::ProposalLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::CropAndResizeLayer>(
         "CropAndResizeLayer")
      .method("create",
              [](cv::dnn::experimental_dnn_v5::CropAndResizeLayer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.create(params);
              });
}
