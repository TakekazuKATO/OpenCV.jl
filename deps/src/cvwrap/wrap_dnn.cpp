#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_dnn_module(Module &mod) {
  mod.add_type<cv::dnn::experimental_dnn_v5::DictValue>("DictValue")
      .constructor<const cv::dnn::experimental_dnn_v5::DictValue &>()
      .constructor<int64>()
      .constructor<int>()
      .constructor<unsigned int>()
      .constructor<double>()
      .constructor<const cv::String &>()
      .constructor<const char *>()
      .method("size",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance) {
                return instance.size();
              })
      .method("isInt",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance) {
                return instance.isInt();
              })
      .method("isString",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance) {
                return instance.isString();
              })
      .method("isReal",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance) {
                return instance.isReal();
              })
      .method("getIntValue",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance) {
                return instance.getIntValue();
              })
      .method("getIntValue",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance,
                 int idx) { return instance.getIntValue(idx); })
      .method("getRealValue",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance) {
                return instance.getRealValue();
              })
      .method("getRealValue",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance,
                 int idx) { return instance.getRealValue(idx); })
      .method("getStringValue",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance) {
                return instance.getStringValue();
              })
      .method("getStringValue",
              [](const cv::dnn::experimental_dnn_v5::DictValue &instance,
                 int idx) { return instance.getStringValue(idx); })
      .method("operator=",
              [](cv::dnn::experimental_dnn_v5::DictValue &instance,
                 const cv::dnn::experimental_dnn_v5::DictValue &r) {
                return instance.operator=(r);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::Dict>("Dict")
      .method("has", [](const cv::dnn::experimental_dnn_v5::Dict &instance,
                        const cv::String &key) { return instance.has(key); })
      .method("ptr", [](cv::dnn::experimental_dnn_v5::Dict &instance,
                        const cv::String &key) { return instance.ptr(key); })
      .method("ptr", [](const cv::dnn::experimental_dnn_v5::Dict &instance,
                        const cv::String &key) { return instance.ptr(key); })
      .method("get", [](const cv::dnn::experimental_dnn_v5::Dict &instance,
                        const cv::String &key) { return instance.get(key); })
      .method("begin",
              [](const cv::dnn::experimental_dnn_v5::Dict &instance) {
                return instance.begin();
              })
      .method("end", [](const cv::dnn::experimental_dnn_v5::Dict &instance) {
        return instance.end();
      });
  mod.add_bits<cv::dnn::experimental_dnn_v5::Backend>("Backend");
  mod.set_const("DNN_BACKEND_DEFAULT",
                cv::dnn::experimental_dnn_v5::Backend::DNN_BACKEND_DEFAULT);
  mod.set_const("DNN_BACKEND_HALIDE",
                cv::dnn::experimental_dnn_v5::Backend::DNN_BACKEND_HALIDE);
  mod.set_const(
      "DNN_BACKEND_INFERENCE_ENGINE",
      cv::dnn::experimental_dnn_v5::Backend::DNN_BACKEND_INFERENCE_ENGINE);
  mod.set_const("DNN_BACKEND_OPENCV",
                cv::dnn::experimental_dnn_v5::Backend::DNN_BACKEND_OPENCV);
  mod.add_bits<cv::dnn::experimental_dnn_v5::Target>("Target");
  mod.set_const("DNN_TARGET_CPU",
                cv::dnn::experimental_dnn_v5::Target::DNN_TARGET_CPU);
  mod.set_const("DNN_TARGET_OPENCL",
                cv::dnn::experimental_dnn_v5::Target::DNN_TARGET_OPENCL);
  mod.set_const("DNN_TARGET_OPENCL_FP16",
                cv::dnn::experimental_dnn_v5::Target::DNN_TARGET_OPENCL_FP16);
  mod.set_const("DNN_TARGET_MYRIAD",
                cv::dnn::experimental_dnn_v5::Target::DNN_TARGET_MYRIAD);
  mod.add_type<cv::dnn::experimental_dnn_v5::LayerParams>("LayerParams")
      .method("blobs",
              [](const cv::dnn::experimental_dnn_v5::LayerParams &instance) {
                return instance.blobs;
              })
      .method("name",
              [](const cv::dnn::experimental_dnn_v5::LayerParams &instance) {
                return instance.name;
              })
      .method("type",
              [](const cv::dnn::experimental_dnn_v5::LayerParams &instance) {
                return instance.type;
              });
  /*mod.add_type<cv::dnn::experimental_dnn_v5::BackendNode>("BackendNode")
      .constructor<int>()
      .method("backendId",
              [](const cv::dnn::experimental_dnn_v5::BackendNode &instance) {
                return instance.backendId;
              });*/
  /*mod.add_type<cv::dnn::experimental_dnn_v5::BackendWrapper>(
     "BackendWrapper")
//.constructor<int, int>()
//.constructor<int, const cv::Mat &>()
//.constructor<const Ptr<cv::dnn::experimental_dnn_v5::BackendWrapper> &,
//             const cv::dnn::experimental_dnn_v5::MatShape &>()
.method("copyToHost",
[](cv::dnn::experimental_dnn_v5::BackendWrapper &instance) {
return instance.copyToHost();
})
.method("setHostDirty",
[](cv::dnn::experimental_dnn_v5::BackendWrapper &instance) {
return instance.setHostDirty();
})
.method("backendId",
[](const cv::dnn::experimental_dnn_v5::BackendWrapper &instance) {
return instance.backendId;
})
.method("targetId",
[](const cv::dnn::experimental_dnn_v5::BackendWrapper &instance) {
return instance.targetId;
});*/
  mod.add_type<cv::dnn::experimental_dnn_v5::Layer>("Layer")
      .method("blobs",
              [](const cv::dnn::experimental_dnn_v5::Layer &instance) {
                return instance.blobs;
              })
      /*.method(
          "finalize",
          [](cv::dnn::experimental_dnn_v5::Layer &instance,
             const std::vector<Mat *> &input, const std::vector<Mat> &output) {
            return instance.finalize(input, const_off(output));
          })
      .method(
          "forward",
          [](cv::dnn::experimental_dnn_v5::Layer &instance,
             const std::vector<Mat *> &input, const std::vector<Mat> &output,
             const std::vector<Mat> &internals) {
            return instance.forward(const_off(input), const_off(output),
                                    const_off(internals));
          })*/
      .method("forward",
              [](cv::dnn::experimental_dnn_v5::Layer &instance,
                 const std::vector<cv::Mat> &inputs,
                 const std::vector<cv::Mat> &outputs,
                 const std::vector<cv::Mat> &internals) {
                return instance.forward(cv::InputArrayOfArrays(inputs),
                                        cv::OutputArrayOfArrays(outputs),
                                        cv::OutputArrayOfArrays(internals));
              })
      .method("forward_fallback",
              [](cv::dnn::experimental_dnn_v5::Layer &instance,
                 const std::vector<cv::Mat> &inputs,
                 const std::vector<cv::Mat> &outputs,
                 const std::vector<cv::Mat> &internals) {
                return instance.forward_fallback(
                    cv::InputArrayOfArrays(inputs),
                    cv::OutputArrayOfArrays(outputs),
                    cv::OutputArrayOfArrays(internals));
              })
      .method(
          "finalize",
          [](cv::dnn::experimental_dnn_v5::Layer &instance,
             const std::vector<Mat> &inputs, const std::vector<Mat> &outputs) {
            return instance.finalize(inputs, const_off(outputs));
          })
      //.method("finalize",[](cv::dnn::experimental_dnn_v5::Layer &instance) {
      // return instance.finalize(  ); })
      .method(
          "run",
          [](cv::dnn::experimental_dnn_v5::Layer &instance,
             const std::vector<Mat> &inputs, const std::vector<Mat> &outputs,
             const std::vector<Mat> &internals) {
            return instance.run(inputs, const_off(outputs),
                                const_off(internals));
          })
      .method("inputNameToIndex",
              [](cv::dnn::experimental_dnn_v5::Layer &instance,
                 cv::String inputName) {
                return instance.inputNameToIndex(inputName);
              })
      .method("outputNameToIndex",
              [](cv::dnn::experimental_dnn_v5::Layer &instance,
                 const cv::String &outputName) {
                return instance.outputNameToIndex(outputName);
              })
      .method("supportBackend",
              [](cv::dnn::experimental_dnn_v5::Layer &instance, int backendId) {
                return instance.supportBackend(backendId);
              })
      /*.method(
          "initHalide",
          [](cv::dnn::experimental_dnn_v5::Layer &instance,
             const std::vector<
                 Ptr<cv::dnn::experimental_dnn_v5::BackendWrapper> > &inputs) {
            return instance.initHalide(inputs);
          })
      .method(
          "initInfEngine",
          [](cv::dnn::experimental_dnn_v5::Layer &instance,
             const std::vector<
                 Ptr<cv::dnn::experimental_dnn_v5::BackendWrapper> > &inputs) {
            return instance.initInfEngine(inputs);
          })
      .method("applyHalideScheduler",
              [](const cv::dnn::experimental_dnn_v5::Layer &instance,
                 cv::Ptr<cv::dnn::experimental_dnn_v5::BackendNode> &node,
                 const std::vector<Mat *> &inputs,
                 const std::vector<Mat> &outputs, int targetId) {
                return instance.applyHalideScheduler(node, inputs, outputs,
                                                     targetId);
              })
      .method(
          "tryAttach",
          [](cv::dnn::experimental_dnn_v5::Layer &instance,
             const cv::Ptr<cv::dnn::experimental_dnn_v5::BackendNode> &node) {
            return instance.tryAttach(node);
          })*/
      /*.method("setActivation",
              [](cv::dnn::experimental_dnn_v5::Layer &instance,
                 const cv::Ptr<cv::dnn::experimental_dnn_v5::ActivationLayer>
                     &layer) { return instance.setActivation(layer); })*/
      .method("tryFuse",
              [](cv::dnn::experimental_dnn_v5::Layer &instance,
                 cv::Ptr<cv::dnn::experimental_dnn_v5::Layer> &top) {
                return instance.tryFuse(top);
              })
      .method("unsetAttached",
              [](cv::dnn::experimental_dnn_v5::Layer &instance) {
                return instance.unsetAttached();
              })
      .method(
          "getMemoryShapes",
          [](const cv::dnn::experimental_dnn_v5::Layer &instance,
             const std::vector<cv::dnn::experimental_dnn_v5::MatShape> &inputs,
             const int requiredOutputs,
             const std::vector<cv::dnn::experimental_dnn_v5::MatShape> &outputs,
             const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                 &internals) {
            return instance.getMemoryShapes(inputs, requiredOutputs,
                                            const_off(outputs),
                                            const_off(internals));
          })
      .method(
          "getFLOPS",
          [](cv::dnn::experimental_dnn_v5::Layer &instance,
             const std::vector<cv::dnn::experimental_dnn_v5::MatShape> &inputs,
             const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                 &outputs) { return instance.getFLOPS(inputs, outputs); })
      .method("name",
              [](const cv::dnn::experimental_dnn_v5::Layer &instance) {
                return instance.name;
              })
      .method("type",
              [](const cv::dnn::experimental_dnn_v5::Layer &instance) {
                return instance.type;
              })
      .method("preferableTarget",
              [](const cv::dnn::experimental_dnn_v5::Layer &instance) {
                return instance.preferableTarget;
              })
      //.constructor<const cv::dnn::experimental_dnn_v5::LayerParams &>()
      .method("setParamsFrom",
              [](cv::dnn::experimental_dnn_v5::Layer &instance,
                 const cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.setParamsFrom(params);
              });
  mod.add_type<cv::dnn::experimental_dnn_v5::Net>("Net")
      .method("readFromModelOptimizer",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::String &xml, const cv::String &bin) {
                return instance.readFromModelOptimizer(xml, bin);
              })
      .method("empty",
              [](const cv::dnn::experimental_dnn_v5::Net &instance) {
                return instance.empty();
              })
      .method("addLayer",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::String &name, const cv::String &type,
                 cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.addLayer(name, type, params);
              })
      .method("addLayerToPrev",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::String &name, const cv::String &type,
                 cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.addLayerToPrev(name, type, params);
              })
      .method(
          "getLayerId",
          [](cv::dnn::experimental_dnn_v5::Net &instance,
             const cv::String &layer) { return instance.getLayerId(layer); })
      .method("getLayerNames",
              [](const cv::dnn::experimental_dnn_v5::Net &instance) {
                return instance.getLayerNames();
              })
      .method("getLayer",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 cv::dnn::experimental_dnn_v5::Net::LayerId layerId) {
                return instance.getLayer(layerId);
              })
      /*.method("getLayerInputs",
              [](cv::dnn::experimental_dnn_v5::Net &instance) {
                return instance.getLayerInputs();
              })*/
      .method("deleteLayer",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 cv::dnn::experimental_dnn_v5::Net::LayerId layer) {
                return instance.deleteLayer(layer);
              })
      .method(
          "connect",
          [](cv::dnn::experimental_dnn_v5::Net &instance, cv::String outPin,
             cv::String inpPin) { return instance.connect(outPin, inpPin); })
      .method("connect",
              [](cv::dnn::experimental_dnn_v5::Net &instance, int outLayerId,
                 int outNum, int inpLayerId, int inpNum) {
                return instance.connect(outLayerId, outNum, inpLayerId, inpNum);
              })
      .method("setInputsNames",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<String> &inputBlobNames) {
                return instance.setInputsNames(inputBlobNames);
              })
      .method("forward",
              [](cv::dnn::experimental_dnn_v5::Net &instance) {
                return instance.forward();
              })
      .method("forward",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::String &outputName) {
                return instance.forward(outputName);
              })
      .method("forward",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<cv::Mat> &outputBlobs) {
                return instance.forward(cv::OutputArrayOfArrays(outputBlobs));
              })
      .method("forward",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<cv::Mat> &outputBlobs,
                 const cv::String &outputName) {
                return instance.forward(cv::OutputArrayOfArrays(outputBlobs),
                                        outputName);
              })
      .method("forward",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<cv::Mat> &outputBlobs,
                 const std::vector<String> &outBlobNames) {
                return instance.forward(cv::OutputArrayOfArrays(outputBlobs),
                                        outBlobNames);
              })
      .method("forward",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<std::vector<Mat> > &outputBlobs,
                 const std::vector<String> &outBlobNames) {
                return instance.forward(const_off(outputBlobs), outBlobNames);
              })
      .method("setHalideScheduler",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::String &scheduler) {
                return instance.setHalideScheduler(scheduler);
              })
      .method("setPreferableBackend",
              [](cv::dnn::experimental_dnn_v5::Net &instance, int backendId) {
                return instance.setPreferableBackend(backendId);
              })
      .method("setPreferableTarget",
              [](cv::dnn::experimental_dnn_v5::Net &instance, int targetId) {
                return instance.setPreferableTarget(targetId);
              })
      .method(
          "setInput",
          [](cv::dnn::experimental_dnn_v5::Net &instance, const cv::Mat &blob) {
            return instance.setInput(cv::InputArray(blob));
          })
      .method("setInput",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::Mat &blob, const cv::String &name) {
                return instance.setInput(cv::InputArray(blob), name);
              })
      .method("setParam",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 cv::dnn::experimental_dnn_v5::Net::LayerId layer, int numParam,
                 const cv::Mat &blob) {
                return instance.setParam(layer, numParam, blob);
              })
      .method("getParam",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 cv::dnn::experimental_dnn_v5::Net::LayerId layer) {
                return instance.getParam(layer);
              })
      .method("getParam",
              [](cv::dnn::experimental_dnn_v5::Net &instance,
                 cv::dnn::experimental_dnn_v5::Net::LayerId layer,
                 int numParam) { return instance.getParam(layer, numParam); })
      .method("getUnconnectedOutLayers",
              [](const cv::dnn::experimental_dnn_v5::Net &instance) {
                return instance.getUnconnectedOutLayers();
              })
      .method("getLayersShapes",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &netInputShapes,
                 const std::vector<int> &layersIds,
                 const std::vector<std::vector<
                     cv::dnn::experimental_dnn_v5::MatShape> > &inLayersShapes,
                 const std::vector<
                     std::vector<cv::dnn::experimental_dnn_v5::MatShape> >
                     &outLayersShapes) {
                return instance.getLayersShapes(
                    netInputShapes, const_off(layersIds),
                    const_off(inLayersShapes), const_off(outLayersShapes));
              })
      .method("getLayersShapes",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::dnn::experimental_dnn_v5::MatShape &netInputShape,
                 const std::vector<int> &layersIds,
                 const std::vector<std::vector<
                     cv::dnn::experimental_dnn_v5::MatShape> > &inLayersShapes,
                 const std::vector<
                     std::vector<cv::dnn::experimental_dnn_v5::MatShape> >
                     &outLayersShapes) {
                return instance.getLayersShapes(
                    netInputShape, const_off(layersIds),
                    const_off(inLayersShapes), const_off(outLayersShapes));
              })
      .method("getLayerShapes",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::dnn::experimental_dnn_v5::MatShape &netInputShape,
                 const int layerId,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &inLayerShapes,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &outLayerShapes) {
                return instance.getLayerShapes(netInputShape, layerId,
                                               const_off(inLayerShapes),
                                               const_off(outLayerShapes));
              })
      .method("getLayerShapes",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &netInputShapes,
                 const int layerId,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &inLayerShapes,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &outLayerShapes) {
                return instance.getLayerShapes(netInputShapes, layerId,
                                               const_off(inLayerShapes),
                                               const_off(outLayerShapes));
              })
      .method(
          "getFLOPS",
          [](const cv::dnn::experimental_dnn_v5::Net &instance,
             const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                 &netInputShapes) { return instance.getFLOPS(netInputShapes); })
      .method("getFLOPS",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::dnn::experimental_dnn_v5::MatShape &netInputShape) {
                return instance.getFLOPS(netInputShape);
              })
      .method("getFLOPS",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const int layerId,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &netInputShapes) {
                return instance.getFLOPS(layerId, netInputShapes);
              })
      .method("getFLOPS",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const int layerId,
                 const cv::dnn::experimental_dnn_v5::MatShape &netInputShape) {
                return instance.getFLOPS(layerId, netInputShape);
              })
      .method("getLayerTypes",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<String> &layersTypes) {
                return instance.getLayerTypes(const_off(layersTypes));
              })
      .method("getLayersCount",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::String &layerType) {
                return instance.getLayersCount(layerType);
              })
      .method("getMemoryConsumption",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &netInputShapes,
                 size_t &weights, size_t &blobs) {
                return instance.getMemoryConsumption(netInputShapes, weights,
                                                     blobs);
              })
      .method("getMemoryConsumption",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::dnn::experimental_dnn_v5::MatShape &netInputShape,
                 size_t &weights, size_t &blobs) {
                return instance.getMemoryConsumption(netInputShape, weights,
                                                     blobs);
              })
      .method("getMemoryConsumption",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const int layerId,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &netInputShapes,
                 size_t &weights, size_t &blobs) {
                return instance.getMemoryConsumption(layerId, netInputShapes,
                                                     weights, blobs);
              })
      .method("getMemoryConsumption",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const int layerId,
                 const cv::dnn::experimental_dnn_v5::MatShape &netInputShape,
                 size_t &weights, size_t &blobs) {
                return instance.getMemoryConsumption(layerId, netInputShape,
                                                     weights, blobs);
              })
      .method("getMemoryConsumption",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const std::vector<cv::dnn::experimental_dnn_v5::MatShape>
                     &netInputShapes,
                 const std::vector<int> &layerIds,
                 const std::vector<size_t> &weights,
                 const std::vector<size_t> &blobs) {
                return instance.getMemoryConsumption(
                    netInputShapes, const_off(layerIds), const_off(weights),
                    const_off(blobs));
              })
      .method("getMemoryConsumption",
              [](const cv::dnn::experimental_dnn_v5::Net &instance,
                 const cv::dnn::experimental_dnn_v5::MatShape &netInputShape,
                 const std::vector<int> &layerIds,
                 const std::vector<size_t> &weights,
                 const std::vector<size_t> &blobs) {
                return instance.getMemoryConsumption(
                    netInputShape, const_off(layerIds), const_off(weights),
                    const_off(blobs));
              })
      .method("enableFusion",
              [](cv::dnn::experimental_dnn_v5::Net &instance, bool fusion) {
                return instance.enableFusion(fusion);
              })
      .method("getPerfProfile", [](cv::dnn::experimental_dnn_v5::Net &instance,
                                   const std::vector<double> &timings) {
        return instance.getPerfProfile(const_off(timings));
      });
  mod.method("readNetFromDarknet", [](const cv::String &cfgFile) {
    return cv::dnn::experimental_dnn_v5::readNetFromDarknet(cfgFile);
  });
  mod.method("readNetFromDarknet",
             [](const cv::String &cfgFile, const cv::String &darknetModel) {
               return cv::dnn::experimental_dnn_v5::readNetFromDarknet(
                   cfgFile, darknetModel);
             });
  mod.method("readNetFromCaffe", [](const cv::String &prototxt) {
    return cv::dnn::experimental_dnn_v5::readNetFromCaffe(prototxt);
  });
  mod.method("readNetFromCaffe", [](const cv::String &prototxt,
                                    const cv::String &caffeModel) {
    return cv::dnn::experimental_dnn_v5::readNetFromCaffe(prototxt, caffeModel);
  });
  mod.method("readNetFromCaffe", [](const char *bufferProto, size_t lenProto) {
    return cv::dnn::experimental_dnn_v5::readNetFromCaffe(bufferProto,
                                                          lenProto);
  });
  mod.method("readNetFromCaffe", [](const char *bufferProto, size_t lenProto,
                                    const char *bufferModel) {
    return cv::dnn::experimental_dnn_v5::readNetFromCaffe(bufferProto, lenProto,
                                                          bufferModel);
  });
  mod.method("readNetFromCaffe", [](const char *bufferProto, size_t lenProto,
                                    const char *bufferModel, size_t lenModel) {
    return cv::dnn::experimental_dnn_v5::readNetFromCaffe(
        bufferProto, lenProto, bufferModel, lenModel);
  });
  mod.method("readNetFromTensorflow", [](const cv::String &model) {
    return cv::dnn::experimental_dnn_v5::readNetFromTensorflow(model);
  });
  mod.method("readNetFromTensorflow", [](const cv::String &model,
                                         const cv::String &config) {
    return cv::dnn::experimental_dnn_v5::readNetFromTensorflow(model, config);
  });
  mod.method("readNetFromTensorflow",
             [](const char *bufferModel, size_t lenModel) {
               return cv::dnn::experimental_dnn_v5::readNetFromTensorflow(
                   bufferModel, lenModel);
             });
  mod.method(
      "readNetFromTensorflow",
      [](const char *bufferModel, size_t lenModel, const char *bufferConfig) {
        return cv::dnn::experimental_dnn_v5::readNetFromTensorflow(
            bufferModel, lenModel, bufferConfig);
      });
  mod.method("readNetFromTensorflow",
             [](const char *bufferModel, size_t lenModel,
                const char *bufferConfig, size_t lenConfig) {
               return cv::dnn::experimental_dnn_v5::readNetFromTensorflow(
                   bufferModel, lenModel, bufferConfig, lenConfig);
             });
  mod.method("readNetFromTorch", [](const cv::String &model) {
    return cv::dnn::experimental_dnn_v5::readNetFromTorch(model);
  });
  mod.method("readNetFromTorch", [](const cv::String &model, bool isBinary) {
    return cv::dnn::experimental_dnn_v5::readNetFromTorch(model, isBinary);
  });
  mod.method("readNet", [](const cv::String &model) {
    return cv::dnn::experimental_dnn_v5::readNet(model);
  });
  mod.method("readNet", [](const cv::String &model, const cv::String &config) {
    return cv::dnn::experimental_dnn_v5::readNet(model, config);
  });
  mod.method("readNet", [](const cv::String &model, const cv::String &config,
                           const cv::String &framework) {
    return cv::dnn::experimental_dnn_v5::readNet(model, config, framework);
  });
  mod.method("readTorchBlob", [](const cv::String &filename) {
    return cv::dnn::experimental_dnn_v5::readTorchBlob(filename);
  });
  mod.method("readTorchBlob", [](const cv::String &filename, bool isBinary) {
    return cv::dnn::experimental_dnn_v5::readTorchBlob(filename, isBinary);
  });
  mod.method("readNetFromModelOptimizer", [](const cv::String &xml,
                                             const cv::String &bin) {
    return cv::dnn::experimental_dnn_v5::readNetFromModelOptimizer(xml, bin);
  });
  mod.method("blobFromImage", [](const cv::Mat &image) {
    return cv::dnn::experimental_dnn_v5::blobFromImage(cv::InputArray(image));
  });
  mod.method("blobFromImage", [](const cv::Mat &image, double scalefactor) {
    return cv::dnn::experimental_dnn_v5::blobFromImage(cv::InputArray(image),
                                                       scalefactor);
  });
  mod.method("blobFromImage", [](const cv::Mat &image, double scalefactor,
                                 const cv::Size &size) {
    return cv::dnn::experimental_dnn_v5::blobFromImage(cv::InputArray(image),
                                                       scalefactor, size);
  });
  mod.method("blobFromImage", [](const cv::Mat &image, double scalefactor,
                                 const cv::Size &size, const cv::Scalar &mean) {
    return cv::dnn::experimental_dnn_v5::blobFromImage(cv::InputArray(image),
                                                       scalefactor, size, mean);
  });
  mod.method("blobFromImage",
             [](const cv::Mat &image, double scalefactor, const cv::Size &size,
                const cv::Scalar &mean, bool swapRB) {
               return cv::dnn::experimental_dnn_v5::blobFromImage(
                   cv::InputArray(image), scalefactor, size, mean, swapRB);
             });
  mod.method("blobFromImage", [](const cv::Mat &image, double scalefactor,
                                 const cv::Size &size, const cv::Scalar &mean,
                                 bool swapRB, bool crop) {
    return cv::dnn::experimental_dnn_v5::blobFromImage(
        cv::InputArray(image), scalefactor, size, mean, swapRB, crop);
  });
  mod.method("blobFromImage", [](const cv::Mat &image, const cv::Mat &blob) {
    return cv::dnn::experimental_dnn_v5::blobFromImage(cv::InputArray(image),
                                                       cv::OutputArray(blob));
  });
  mod.method("blobFromImage",
             [](const cv::Mat &image, const cv::Mat &blob, double scalefactor) {
               return cv::dnn::experimental_dnn_v5::blobFromImage(
                   cv::InputArray(image), cv::OutputArray(blob), scalefactor);
             });
  mod.method("blobFromImage", [](const cv::Mat &image, const cv::Mat &blob,
                                 double scalefactor, const cv::Size &size) {
    return cv::dnn::experimental_dnn_v5::blobFromImage(
        cv::InputArray(image), cv::OutputArray(blob), scalefactor, size);
  });
  mod.method("blobFromImage", [](const cv::Mat &image, const cv::Mat &blob,
                                 double scalefactor, const cv::Size &size,
                                 const cv::Scalar &mean) {
    return cv::dnn::experimental_dnn_v5::blobFromImage(
        cv::InputArray(image), cv::OutputArray(blob), scalefactor, size, mean);
  });
  mod.method("blobFromImage",
             [](const cv::Mat &image, const cv::Mat &blob, double scalefactor,
                const cv::Size &size, const cv::Scalar &mean, bool swapRB) {
               return cv::dnn::experimental_dnn_v5::blobFromImage(
                   cv::InputArray(image), cv::OutputArray(blob), scalefactor,
                   size, mean, swapRB);
             });
  mod.method(
      "blobFromImage",
      [](const cv::Mat &image, const cv::Mat &blob, double scalefactor,
         const cv::Size &size, const cv::Scalar &mean, bool swapRB, bool crop) {
        return cv::dnn::experimental_dnn_v5::blobFromImage(
            cv::InputArray(image), cv::OutputArray(blob), scalefactor, size,
            mean, swapRB, crop);
      });
  mod.method("blobFromImages", [](const std::vector<cv::Mat> &images) {
    return cv::dnn::experimental_dnn_v5::blobFromImages(
        cv::InputArrayOfArrays(images));
  });
  mod.method("blobFromImages",
             [](const std::vector<cv::Mat> &images, double scalefactor) {
               return cv::dnn::experimental_dnn_v5::blobFromImages(
                   cv::InputArrayOfArrays(images), scalefactor);
             });
  mod.method("blobFromImages", [](const std::vector<cv::Mat> &images,
                                  double scalefactor, cv::Size size) {
    return cv::dnn::experimental_dnn_v5::blobFromImages(
        cv::InputArrayOfArrays(images), scalefactor, size);
  });
  mod.method("blobFromImages",
             [](const std::vector<cv::Mat> &images, double scalefactor,
                cv::Size size, const cv::Scalar &mean) {
               return cv::dnn::experimental_dnn_v5::blobFromImages(
                   cv::InputArrayOfArrays(images), scalefactor, size, mean);
             });
  mod.method("blobFromImages", [](const std::vector<cv::Mat> &images,
                                  double scalefactor, cv::Size size,
                                  const cv::Scalar &mean, bool swapRB) {
    return cv::dnn::experimental_dnn_v5::blobFromImages(
        cv::InputArrayOfArrays(images), scalefactor, size, mean, swapRB);
  });
  mod.method("blobFromImages",
             [](const std::vector<cv::Mat> &images, double scalefactor,
                cv::Size size, const cv::Scalar &mean, bool swapRB, bool crop) {
               return cv::dnn::experimental_dnn_v5::blobFromImages(
                   cv::InputArrayOfArrays(images), scalefactor, size, mean,
                   swapRB, crop);
             });
  mod.method("blobFromImages",
             [](const std::vector<cv::Mat> &images, const cv::Mat &blob) {
               return cv::dnn::experimental_dnn_v5::blobFromImages(
                   cv::InputArrayOfArrays(images), cv::OutputArray(blob));
             });
  mod.method("blobFromImages", [](const std::vector<cv::Mat> &images,
                                  const cv::Mat &blob, double scalefactor) {
    return cv::dnn::experimental_dnn_v5::blobFromImages(
        cv::InputArrayOfArrays(images), cv::OutputArray(blob), scalefactor);
  });
  mod.method("blobFromImages",
             [](const std::vector<cv::Mat> &images, const cv::Mat &blob,
                double scalefactor, cv::Size size) {
               return cv::dnn::experimental_dnn_v5::blobFromImages(
                   cv::InputArrayOfArrays(images), cv::OutputArray(blob),
                   scalefactor, size);
             });
  mod.method("blobFromImages",
             [](const std::vector<cv::Mat> &images, const cv::Mat &blob,
                double scalefactor, cv::Size size, const cv::Scalar &mean) {
               return cv::dnn::experimental_dnn_v5::blobFromImages(
                   cv::InputArrayOfArrays(images), cv::OutputArray(blob),
                   scalefactor, size, mean);
             });
  mod.method("blobFromImages",
             [](const std::vector<cv::Mat> &images, const cv::Mat &blob,
                double scalefactor, cv::Size size, const cv::Scalar &mean,
                bool swapRB) {
               return cv::dnn::experimental_dnn_v5::blobFromImages(
                   cv::InputArrayOfArrays(images), cv::OutputArray(blob),
                   scalefactor, size, mean, swapRB);
             });
  mod.method("blobFromImages",
             [](const std::vector<cv::Mat> &images, const cv::Mat &blob,
                double scalefactor, cv::Size size, const cv::Scalar &mean,
                bool swapRB, bool crop) {
               return cv::dnn::experimental_dnn_v5::blobFromImages(
                   cv::InputArrayOfArrays(images), cv::OutputArray(blob),
                   scalefactor, size, mean, swapRB, crop);
             });
  mod.method("imagesFromBlob",
             [](const cv::Mat &blob_, const std::vector<cv::Mat> &images_) {
               return cv::dnn::experimental_dnn_v5::imagesFromBlob(
                   blob_, cv::OutputArrayOfArrays(images_));
             });
  mod.method("shrinkCaffeModel",
             [](const cv::String &src, const cv::String &dst) {
               return cv::dnn::experimental_dnn_v5::shrinkCaffeModel(src, dst);
             });
  mod.method("shrinkCaffeModel",
             [](const cv::String &src, const cv::String &dst,
                const std::vector<String> &layersTypes) {
               return cv::dnn::experimental_dnn_v5::shrinkCaffeModel(
                   src, dst, layersTypes);
             });
  mod.method("NMSBoxes",
             [](const std::vector<Rect> &bboxes,
                const std::vector<float> &scores, const float score_threshold,
                const float nms_threshold, const std::vector<int> &indices) {
               return cv::dnn::experimental_dnn_v5::NMSBoxes(
                   bboxes, scores, score_threshold, nms_threshold,
                   const_off(indices));
             });
  mod.method(
      "NMSBoxes",
      [](const std::vector<Rect> &bboxes, const std::vector<float> &scores,
         const float score_threshold, const float nms_threshold,
         const std::vector<int> &indices, const float eta) {
        return cv::dnn::experimental_dnn_v5::NMSBoxes(
            bboxes, scores, score_threshold, nms_threshold, const_off(indices),
            eta);
      });
  mod.method(
      "NMSBoxes",
      [](const std::vector<Rect> &bboxes, const std::vector<float> &scores,
         const float score_threshold, const float nms_threshold,
         const std::vector<int> &indices, const float eta, const int top_k) {
        return cv::dnn::experimental_dnn_v5::NMSBoxes(
            bboxes, scores, score_threshold, nms_threshold, const_off(indices),
            eta, top_k);
      });
  mod.method("NMSBoxes",
             [](const std::vector<RotatedRect> &bboxes,
                const std::vector<float> &scores, const float score_threshold,
                const float nms_threshold, const std::vector<int> &indices) {
               return cv::dnn::experimental_dnn_v5::NMSBoxes(
                   bboxes, scores, score_threshold, nms_threshold,
                   const_off(indices));
             });
  mod.method("NMSBoxes",
             [](const std::vector<RotatedRect> &bboxes,
                const std::vector<float> &scores, const float score_threshold,
                const float nms_threshold, const std::vector<int> &indices,
                const float eta) {
               return cv::dnn::experimental_dnn_v5::NMSBoxes(
                   bboxes, scores, score_threshold, nms_threshold,
                   const_off(indices), eta);
             });
  mod.method("NMSBoxes",
             [](const std::vector<RotatedRect> &bboxes,
                const std::vector<float> &scores, const float score_threshold,
                const float nms_threshold, const std::vector<int> &indices,
                const float eta, const int top_k) {
               return cv::dnn::experimental_dnn_v5::NMSBoxes(
                   bboxes, scores, score_threshold, nms_threshold,
                   const_off(indices), eta, top_k);
             });
  mod.add_type<cv::dnn::experimental_dnn_v5::LayerFactory>("LayerFactory")
      /*.method("registerLayer",
              [](cv::dnn::experimental_dnn_v5::LayerFactory &instance,
                 const cv::String &type,
                 cv::dnn::experimental_dnn_v5::LayerFactory::Constructor
                     constructor) {
                return instance.registerLayer(type, constructor);
              })*/
      .method(
          "unregisterLayer",
          [](cv::dnn::experimental_dnn_v5::LayerFactory &instance,
             const cv::String &type) { return instance.unregisterLayer(type); })
      .method("createLayerInstance",
              [](cv::dnn::experimental_dnn_v5::LayerFactory &instance,
                 const cv::String &type,
                 cv::dnn::experimental_dnn_v5::LayerParams &params) {
                return instance.createLayerInstance(type, params);
              });
}
