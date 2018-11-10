#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
template <typename C>
struct get_template_type;

template <template <typename> class C, typename T>
struct get_template_type<C<T>> {
  using type = T;
};

namespace jlcxx {

template <>
struct static_type_mapping<char> {
  typedef char type;
  static jl_datatype_t* julia_type() { return jl_int8_type; }
};
template <>
inline jl_value_t* box(const char& i) {
  return jl_box_int8(i);
}
template <>
inline char unbox(jl_value_t* v) {
  return jl_unbox_int8(v);
}

template <>
struct static_type_mapping<ushort> {
  typedef ushort type;
  static jl_datatype_t* julia_type() { return jl_uint16_type; }
};
template <>
inline jl_value_t* box(const ushort& i) {
  return jl_box_uint16(i);
}
template <>
inline ushort unbox(jl_value_t* v) {
  return jl_unbox_uint16(v);
}

template <>
struct IsBits<CpuFeatures> : std::true_type {};
template <>
struct IsBits<cv::Error::Code> : std::true_type {};
template <>
struct IsBits<cv::DecompTypes> : std::true_type {};
template <>
struct IsBits<cv::NormTypes> : std::true_type {};
template <>
struct IsBits<cv::CmpTypes> : std::true_type {};
template <>
struct IsBits<cv::GemmFlags> : std::true_type {};
template <>
struct IsBits<cv::DftFlags> : std::true_type {};
template <>
struct IsBits<cv::BorderTypes> : std::true_type {};
template <>
struct IsBits<cv::UMatUsageFlags> : std::true_type {};
template <>
struct IsBits<cv::SortFlags> : std::true_type {};
template <>
struct IsBits<cv::CovarFlags> : std::true_type {};
template <>
struct IsBits<cv::KmeansFlags> : std::true_type {};
template <>
struct IsBits<cv::LineTypes> : std::true_type {};
template <>
struct IsBits<cv::HersheyFonts> : std::true_type {};
template <>
struct IsBits<cv::ReduceTypes> : std::true_type {};
template <>
struct IsBits<cv::RotateFlags> : std::true_type {};
template <>
struct IsBits<cv::instr::TYPE> : std::true_type {};
template <>
struct IsBits<cv::instr::IMPL> : std::true_type {};
template <>
struct IsBits<cv::instr::FLAGS> : std::true_type {};
template <>
struct IsBits<cv::SolveLPResult> : std::true_type {};
template <>
struct IsBits<cv::cuda::FeatureSet> : std::true_type {};
template <>
struct IsBits<cv::videostab::MotionModel> : std::true_type {};
template <>
struct IsBits<cv::ImreadModes> : std::true_type {};
template <>
struct IsBits<cv::ImwriteFlags> : std::true_type {};
template <>
struct IsBits<cv::ImwriteEXRTypeFlags> : std::true_type {};
template <>
struct IsBits<cv::ImwritePNGFlags> : std::true_type {};
template <>
struct IsBits<cv::ImwritePAMFlags> : std::true_type {};
template <>
struct IsBits<cv::MorphTypes> : std::true_type {};
template <>
struct IsBits<cv::MorphShapes> : std::true_type {};
template <>
struct IsBits<cv::InterpolationFlags> : std::true_type {};
template <>
struct IsBits<cv::InterpolationMasks> : std::true_type {};
template <>
struct IsBits<cv::DistanceTypes> : std::true_type {};
template <>
struct IsBits<cv::DistanceTransformMasks> : std::true_type {};
template <>
struct IsBits<cv::ThresholdTypes> : std::true_type {};
template <>
struct IsBits<cv::AdaptiveThresholdTypes> : std::true_type {};
template <>
struct IsBits<cv::UndistortTypes> : std::true_type {};
template <>
struct IsBits<cv::GrabCutClasses> : std::true_type {};
template <>
struct IsBits<cv::GrabCutModes> : std::true_type {};
template <>
struct IsBits<cv::DistanceTransformLabelTypes> : std::true_type {};
template <>
struct IsBits<cv::FloodFillFlags> : std::true_type {};
template <>
struct IsBits<cv::ConnectedComponentsTypes> : std::true_type {};
template <>
struct IsBits<cv::ConnectedComponentsAlgorithmsTypes> : std::true_type {};
template <>
struct IsBits<cv::RetrievalModes> : std::true_type {};
template <>
struct IsBits<cv::ContourApproximationModes> : std::true_type {};
template <>
struct IsBits<cv::ShapeMatchModes> : std::true_type {};
template <>
struct IsBits<cv::HoughModes> : std::true_type {};
template <>
struct IsBits<cv::LineSegmentDetectorModes> : std::true_type {};
template <>
struct IsBits<cv::HistCompMethods> : std::true_type {};
template <>
struct IsBits<cv::ColorConversionCodes> : std::true_type {};
template <>
struct IsBits<cv::RectanglesIntersectTypes> : std::true_type {};
template <>
struct IsBits<cv::TemplateMatchModes> : std::true_type {};
template <>
struct IsBits<cv::ColormapTypes> : std::true_type {};
template <>
struct IsBits<cv::MarkerTypes> : std::true_type {};
template <>
struct IsBits<cv::VideoCaptureAPIs> : std::true_type {};
template <>
struct IsBits<cv::VideoCaptureProperties> : std::true_type {};
template <>
struct IsBits<cv::VideoCaptureModes> : std::true_type {};
template <>
struct IsBits<cv::VideoWriterProperties> : std::true_type {};
template <>
struct IsBits<cvflann::flann_algorithm_t> : std::true_type {};
template <>
struct IsBits<cvflann::flann_centers_init_t> : std::true_type {};
template <>
struct IsBits<cvflann::flann_log_level_t> : std::true_type {};
template <>
struct IsBits<cvflann::flann_distance_t> : std::true_type {};
template <>
struct IsBits<cv::ml::VariableTypes> : std::true_type {};
template <>
struct IsBits<cv::ml::ErrorTypes> : std::true_type {};
template <>
struct IsBits<cv::ml::SampleTypes> : std::true_type {};
template <>
struct IsBits<cv::dnn::experimental_dnn_34_v7::Backend> : std::true_type {};
template <>
struct IsBits<cv::dnn::experimental_dnn_34_v7::Target> : std::true_type {};

template <typename T>
struct IsSmartPointerType<cv::Ptr<T>> : std::true_type {};

// Complex numbers
template <typename NumberT>
struct IsFundamental<cv::Complex<NumberT>> : std::true_type {};

template <typename NumberT>
struct static_type_mapping<cv::Complex<NumberT>> {
  typedef cv::Complex<NumberT> type;
  static jl_datatype_t* julia_type() {
    static jl_datatype_t* dt = nullptr;
    if (dt == nullptr) {
      dt = (jl_datatype_t*)apply_type(
          jlcxx::julia_type("Complex"),
          jl_svec1(static_type_mapping<NumberT>::julia_type()));
      protect_from_gc(dt);
    }
    return dt;
  }
};

template <typename NumberT>
struct ConvertToCpp<cv::Complex<NumberT>, true, false, false> {
  cv::Complex<NumberT> operator()(cv::Complex<NumberT> julia_value) const {
    return julia_value;
  }
};

template <typename NumberT>
struct ConvertToJulia<cv::Complex<NumberT>, true, false, false> {
  jlcxx::detail::JuliaComplex<NumberT> operator()(
      cv::Complex<NumberT> cpp_value) const {
    return {cpp_value.re, cpp_value.im};
  }
};

template <>
struct IsValueType<cv::String> : std::true_type {};
template <>
struct static_type_mapping<cv::String> {
  typedef jl_value_t* type;
  static jl_datatype_t* julia_type() {
    return (jl_datatype_t*)jl_get_global(jl_base_module,
                                         jl_symbol("AbstractString"));
  }
};
template <>
struct JLCXX_API ConvertToJulia<cv::String, false, false, false> {
  jl_value_t* operator()(const cv::String& str) const {
    return jl_cstr_to_string(str.c_str());
  }
};
template <>
struct ConvertToCpp<cv::String, false, false, false> {
  cv::String operator()(jl_value_t* jstr) const {
    return cv::String(ConvertToCpp<const char*, false, false, false>()(jstr));
  }
};

template <>
struct IsValueType<cv::Mat> : std::true_type {};
template <>
struct static_type_mapping<cv::Mat> {
  typedef jl_array_t* type;
  static jl_datatype_t* julia_type() {
    return (jl_datatype_t*)jl_get_global(jl_base_module, jl_symbol("Array"));
  }
};
template <>
struct ConvertToJulia<cv::Mat, false, false, false> {
  // template <typename MatT>
  jl_array_t* operator()(cv::Mat&& mat) const {
    int depth = mat.depth();
    int channels = mat.channels();
    switch (depth) {
      case CV_8U:
        return wrap_array(true, (uint8_t*)mat.data, mat.size[0], mat.size[1],
                          channels);
      case CV_8S:
        return wrap_array(true, (int8_t*)mat.data, mat.size[0], mat.size[1],
                          channels);
      case CV_16U:
        return wrap_array(true, (uint16_t*)mat.data, mat.size[0], mat.size[1],
                          channels);
      case CV_16S:
        return wrap_array(true, (int16_t*)mat.data, mat.size[0], mat.size[1],
                          channels);
      case CV_32S:
        return wrap_array(true, (int32_t*)mat.data, mat.size[0], mat.size[1],
                          channels);
      case CV_32F:
        return wrap_array(true, (float*)mat.data, mat.size[0], mat.size[1],
                          channels);
      case CV_64F:
        return wrap_array(true, (double*)mat.data, mat.size[0], mat.size[1],
                          channels);
    }
    return nullptr;
  }
};
template <>
struct ConvertToCpp<cv::Mat, false, false, false> {
  cv::Mat operator()(jl_array_t* arr) const {
    jl_datatype_t* type = (jl_datatype_t*)jl_array_eltype((jl_value_t*)arr);
    int c = 1;
    if (jl_array_ndims(arr) > 1) c = jl_array_dim(arr, 2);
    int cvtype = 0;
    if (type == jl_uint8_type)
      cvtype = CV_8UC(c);
    else if (type == jl_int8_type)
      cvtype = CV_8SC(c);
    else if (type == jl_uint16_type)
      cvtype = CV_16UC(c);
    else if (type == jl_int16_type)
      cvtype = CV_16SC(c);
    else if (type == jl_int32_type)
      cvtype = CV_32SC(c);
    else if (type == jl_float32_type)
      cvtype = CV_32FC(c);
    else if (type == jl_float64_type)
      cvtype = CV_64FC(c);
    else {
      std::cerr << "unsupported value type " << jlcxx::julia_type_name(type)
                << std::endl;
    }
    return cv::Mat(jl_array_dim(arr, 0), jl_array_dim(arr, 1), cvtype,
                   jl_array_data(arr));
  }
};

template <typename T, int Dim>
struct IsValueType<cv::Vec<T, Dim>> : std::true_type {};

// Conversions
template <typename T, int Dim>
struct static_type_mapping<cv::Vec<T, Dim>> {
  typedef jl_array_t* type;
  static jl_datatype_t* julia_type() {
    return (jl_datatype_t*)apply_array_type(
        static_type_mapping<T>::julia_type(), 1);
  }
};
template <typename T, int Dim>
struct ConvertToJulia<cv::Vec<T, Dim>, false, false, false> {
  // template <typename MatT>
  jl_array_t* operator()(cv::Vec<T, Dim>&& vec) const {
    return wrap_array(true, (T*)vec.val, Dim);
  }
};
template <typename T, int Dim>
struct ConvertToCpp<cv::Vec<T, Dim>, false, false, false> {
  cv::Vec<T, Dim> operator()(jl_array_t* arr) const {
    return cv::Vec<T, Dim>((const T*)jl_array_data(arr));
  }
};

template <typename T, int N, int M>
struct IsValueType<cv::Matx<T, N, M>> : std::true_type {};

// Conversions
template <typename T, int N, int M>
struct static_type_mapping<cv::Matx<T, N, M>> {
  typedef jl_array_t* type;
  static jl_datatype_t* julia_type() {
    return (jl_datatype_t*)apply_array_type(
        static_type_mapping<T>::julia_type(), 2);
  }
};
template <typename T, int N, int M>
struct ConvertToJulia<cv::Matx<T, N, M>, false, false, false> {
  // template <typename MatT>
  jl_array_t* operator()(cv::Matx<T, N, M>&& vec) const {
    return wrap_array(true, (T*)vec.val, N, M);
  }
};
template <typename T, int N, int M>
struct ConvertToCpp<cv::Matx<T, N, M>, false, false, false> {
  cv::Matx<T, N, M> operator()(jl_array_t* arr) const {
    return cv::Matx<T, N, M>((const T*)jl_array_data(arr));
  }
};

template <typename T>
struct IsValueType<std::vector<T>> : std::true_type {};

// Conversions
template <typename T>
struct static_type_mapping<std::vector<T>> {
  typedef jl_array_t* type;
  static jl_datatype_t* julia_type() {
    return (jl_datatype_t*)apply_array_type(
        static_type_mapping<T>::julia_type(), 1);
  }
};
template <typename T>
struct ConvertToJulia<std::vector<T>, false, false, false> {
  // template <typename MatT>
  jl_array_t* operator()(std::vector<T>&& vec) const {
    auto arr = make_julia_array(vec.data(), vec.size());
    return arr.wrapped();
  }
};
template <class T>
T& const_off(const T& ref) {
  return const_cast<T&>(ref);
}

template <typename T>
struct ConvertToCpp<std::vector<T>, false, false, false> {
  std::vector<T> operator()(jl_array_t* arr) const {
    ArrayRef<T> aref(arr);
    return std::vector<T>((T*)aref.data(), (T*)aref.data() + aref.size());
  }
};

}  // namespace jlcxx