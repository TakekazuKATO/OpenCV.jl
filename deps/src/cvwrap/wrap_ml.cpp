#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_ml_module(Module &mod) {
  mod.add_bits<cv::ml::VariableTypes>("VariableTypes");
  mod.set_const("VAR_NUMERICAL", cv::ml::VariableTypes::VAR_NUMERICAL);
  mod.set_const("VAR_ORDERED", cv::ml::VariableTypes::VAR_ORDERED);
  mod.set_const("VAR_CATEGORICAL", cv::ml::VariableTypes::VAR_CATEGORICAL);
  mod.add_bits<cv::ml::ErrorTypes>("ErrorTypes");
  mod.set_const("TEST_ERROR", cv::ml::ErrorTypes::TEST_ERROR);
  mod.set_const("TRAIN_ERROR", cv::ml::ErrorTypes::TRAIN_ERROR);
  mod.add_bits<cv::ml::SampleTypes>("SampleTypes");
  mod.set_const("ROW_SAMPLE", cv::ml::SampleTypes::ROW_SAMPLE);
  mod.set_const("COL_SAMPLE", cv::ml::SampleTypes::COL_SAMPLE);
  mod.add_type<cv::ml::ParamGrid>("ParamGrid")
      .constructor<double, double, double>()
      .method("minVal",
              [](const cv::ml::ParamGrid &instance) { return instance.minVal; })
      .method("maxVal",
              [](const cv::ml::ParamGrid &instance) { return instance.maxVal; })
      .method("logStep", [](const cv::ml::ParamGrid &instance) {
        return instance.logStep;
      });
  mod.add_type<cv::ml::TrainData>("TrainData");
  mod.add_type<cv::ml::StatModel>("StatModel");
  mod.add_type<cv::ml::NormalBayesClassifier>("NormalBayesClassifier");
  mod.add_type<cv::ml::KNearest>("KNearest");
  mod.add_type<cv::ml::SVM>("SVM");
  mod.add_type<cv::ml::EM>("EM");
  mod.add_type<cv::ml::DTrees>("DTrees");
  mod.add_type<cv::ml::RTrees>("RTrees");
  mod.add_type<cv::ml::Boost>("Boost");
  mod.add_type<cv::ml::ANN_MLP>("ANN_MLP");
  mod.add_type<cv::ml::LogisticRegression>("LogisticRegression");
  mod.add_type<cv::ml::SVMSGD>("SVMSGD");
  mod.method("randMVNormal", [](const cv::Mat &mean, const cv::Mat &cov,
                                int nsamples, const cv::Mat &samples) {
    return cv::ml::randMVNormal(cv::InputArray(mean), cv::InputArray(cov),
                                nsamples, cv::OutputArray(samples));
  });
  mod.method("createConcentricSpheresTestSet",
             [](int nsamples, int nfeatures, int nclasses,
                const cv::Mat &samples, const cv::Mat &responses) {
               return cv::ml::createConcentricSpheresTestSet(
                   nsamples, nfeatures, nclasses, cv::OutputArray(samples),
                   cv::OutputArray(responses));
             });
  // mod.add_type<cv::ml::ANN_MLP_ANNEAL>("ANN_MLP_ANNEAL");
}
