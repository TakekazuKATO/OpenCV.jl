#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_videoio_module(Module &mod) {
  mod.add_bits<cv::VideoCaptureAPIs>("VideoCaptureAPIs");
  mod.set_const("CAP_ANY", cv::VideoCaptureAPIs::CAP_ANY);
  mod.set_const("CAP_VFW", cv::VideoCaptureAPIs::CAP_VFW);
  mod.set_const("CAP_V4L", cv::VideoCaptureAPIs::CAP_V4L);
  mod.set_const("CAP_V4L2", cv::VideoCaptureAPIs::CAP_V4L2);
  mod.set_const("CAP_FIREWIRE", cv::VideoCaptureAPIs::CAP_FIREWIRE);
  mod.set_const("CAP_FIREWARE", cv::VideoCaptureAPIs::CAP_FIREWARE);
  mod.set_const("CAP_IEEE1394", cv::VideoCaptureAPIs::CAP_IEEE1394);
  mod.set_const("CAP_DC1394", cv::VideoCaptureAPIs::CAP_DC1394);
  mod.set_const("CAP_CMU1394", cv::VideoCaptureAPIs::CAP_CMU1394);
  mod.set_const("CAP_QT", cv::VideoCaptureAPIs::CAP_QT);
  mod.set_const("CAP_UNICAP", cv::VideoCaptureAPIs::CAP_UNICAP);
  mod.set_const("CAP_DSHOW", cv::VideoCaptureAPIs::CAP_DSHOW);
  mod.set_const("CAP_PVAPI", cv::VideoCaptureAPIs::CAP_PVAPI);
  mod.set_const("CAP_OPENNI", cv::VideoCaptureAPIs::CAP_OPENNI);
  mod.set_const("CAP_OPENNI_ASUS", cv::VideoCaptureAPIs::CAP_OPENNI_ASUS);
  mod.set_const("CAP_ANDROID", cv::VideoCaptureAPIs::CAP_ANDROID);
  mod.set_const("CAP_XIAPI", cv::VideoCaptureAPIs::CAP_XIAPI);
  mod.set_const("CAP_AVFOUNDATION", cv::VideoCaptureAPIs::CAP_AVFOUNDATION);
  mod.set_const("CAP_GIGANETIX", cv::VideoCaptureAPIs::CAP_GIGANETIX);
  mod.set_const("CAP_MSMF", cv::VideoCaptureAPIs::CAP_MSMF);
  mod.set_const("CAP_WINRT", cv::VideoCaptureAPIs::CAP_WINRT);
  mod.set_const("CAP_INTELPERC", cv::VideoCaptureAPIs::CAP_INTELPERC);
  mod.set_const("CAP_OPENNI2", cv::VideoCaptureAPIs::CAP_OPENNI2);
  mod.set_const("CAP_OPENNI2_ASUS", cv::VideoCaptureAPIs::CAP_OPENNI2_ASUS);
  mod.set_const("CAP_GPHOTO2", cv::VideoCaptureAPIs::CAP_GPHOTO2);
  mod.set_const("CAP_GSTREAMER", cv::VideoCaptureAPIs::CAP_GSTREAMER);
  mod.set_const("CAP_FFMPEG", cv::VideoCaptureAPIs::CAP_FFMPEG);
  mod.set_const("CAP_IMAGES", cv::VideoCaptureAPIs::CAP_IMAGES);
  mod.set_const("CAP_ARAVIS", cv::VideoCaptureAPIs::CAP_ARAVIS);
  mod.set_const("CAP_OPENCV_MJPEG", cv::VideoCaptureAPIs::CAP_OPENCV_MJPEG);
  mod.set_const("CAP_INTEL_MFX", cv::VideoCaptureAPIs::CAP_INTEL_MFX);
  // mod.set_const("CAP_XINE",cv::VideoCaptureAPIs::CAP_XINE);
  mod.add_bits<cv::VideoCaptureProperties>("VideoCaptureProperties");
  mod.set_const("CAP_PROP_POS_MSEC",
                cv::VideoCaptureProperties::CAP_PROP_POS_MSEC);
  mod.set_const("CAP_PROP_POS_FRAMES",
                cv::VideoCaptureProperties::CAP_PROP_POS_FRAMES);
  mod.set_const("CAP_PROP_POS_AVI_RATIO",
                cv::VideoCaptureProperties::CAP_PROP_POS_AVI_RATIO);
  mod.set_const("CAP_PROP_FRAME_WIDTH",
                cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH);
  mod.set_const("CAP_PROP_FRAME_HEIGHT",
                cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT);
  mod.set_const("CAP_PROP_FPS", cv::VideoCaptureProperties::CAP_PROP_FPS);
  mod.set_const("CAP_PROP_FOURCC", cv::VideoCaptureProperties::CAP_PROP_FOURCC);
  mod.set_const("CAP_PROP_FRAME_COUNT",
                cv::VideoCaptureProperties::CAP_PROP_FRAME_COUNT);
  mod.set_const("CAP_PROP_FORMAT", cv::VideoCaptureProperties::CAP_PROP_FORMAT);
  mod.set_const("CAP_PROP_MODE", cv::VideoCaptureProperties::CAP_PROP_MODE);
  mod.set_const("CAP_PROP_BRIGHTNESS",
                cv::VideoCaptureProperties::CAP_PROP_BRIGHTNESS);
  mod.set_const("CAP_PROP_CONTRAST",
                cv::VideoCaptureProperties::CAP_PROP_CONTRAST);
  mod.set_const("CAP_PROP_SATURATION",
                cv::VideoCaptureProperties::CAP_PROP_SATURATION);
  mod.set_const("CAP_PROP_HUE", cv::VideoCaptureProperties::CAP_PROP_HUE);
  mod.set_const("CAP_PROP_GAIN", cv::VideoCaptureProperties::CAP_PROP_GAIN);
  mod.set_const("CAP_PROP_EXPOSURE",
                cv::VideoCaptureProperties::CAP_PROP_EXPOSURE);
  mod.set_const("CAP_PROP_CONVERT_RGB",
                cv::VideoCaptureProperties::CAP_PROP_CONVERT_RGB);
  mod.set_const("CAP_PROP_WHITE_BALANCE_BLUE_U",
                cv::VideoCaptureProperties::CAP_PROP_WHITE_BALANCE_BLUE_U);
  mod.set_const("CAP_PROP_RECTIFICATION",
                cv::VideoCaptureProperties::CAP_PROP_RECTIFICATION);
  mod.set_const("CAP_PROP_MONOCHROME",
                cv::VideoCaptureProperties::CAP_PROP_MONOCHROME);
  mod.set_const("CAP_PROP_SHARPNESS",
                cv::VideoCaptureProperties::CAP_PROP_SHARPNESS);
  mod.set_const("CAP_PROP_AUTO_EXPOSURE",
                cv::VideoCaptureProperties::CAP_PROP_AUTO_EXPOSURE);
  mod.set_const("CAP_PROP_GAMMA", cv::VideoCaptureProperties::CAP_PROP_GAMMA);
  mod.set_const("CAP_PROP_TEMPERATURE",
                cv::VideoCaptureProperties::CAP_PROP_TEMPERATURE);
  mod.set_const("CAP_PROP_TRIGGER",
                cv::VideoCaptureProperties::CAP_PROP_TRIGGER);
  mod.set_const("CAP_PROP_TRIGGER_DELAY",
                cv::VideoCaptureProperties::CAP_PROP_TRIGGER_DELAY);
  mod.set_const("CAP_PROP_WHITE_BALANCE_RED_V",
                cv::VideoCaptureProperties::CAP_PROP_WHITE_BALANCE_RED_V);
  mod.set_const("CAP_PROP_ZOOM", cv::VideoCaptureProperties::CAP_PROP_ZOOM);
  mod.set_const("CAP_PROP_FOCUS", cv::VideoCaptureProperties::CAP_PROP_FOCUS);
  mod.set_const("CAP_PROP_GUID", cv::VideoCaptureProperties::CAP_PROP_GUID);
  mod.set_const("CAP_PROP_ISO_SPEED",
                cv::VideoCaptureProperties::CAP_PROP_ISO_SPEED);
  mod.set_const("CAP_PROP_BACKLIGHT",
                cv::VideoCaptureProperties::CAP_PROP_BACKLIGHT);
  mod.set_const("CAP_PROP_PAN", cv::VideoCaptureProperties::CAP_PROP_PAN);
  mod.set_const("CAP_PROP_TILT", cv::VideoCaptureProperties::CAP_PROP_TILT);
  mod.set_const("CAP_PROP_ROLL", cv::VideoCaptureProperties::CAP_PROP_ROLL);
  mod.set_const("CAP_PROP_IRIS", cv::VideoCaptureProperties::CAP_PROP_IRIS);
  mod.set_const("CAP_PROP_SETTINGS",
                cv::VideoCaptureProperties::CAP_PROP_SETTINGS);
  mod.set_const("CAP_PROP_BUFFERSIZE",
                cv::VideoCaptureProperties::CAP_PROP_BUFFERSIZE);
  mod.set_const("CAP_PROP_AUTOFOCUS",
                cv::VideoCaptureProperties::CAP_PROP_AUTOFOCUS);
  mod.set_const("CAP_PROP_SAR_NUM",
                cv::VideoCaptureProperties::CAP_PROP_SAR_NUM);
  mod.set_const("CAP_PROP_SAR_DEN",
                cv::VideoCaptureProperties::CAP_PROP_SAR_DEN);
  mod.set_const("CV__CAP_PROP_LATEST",
                cv::VideoCaptureProperties::CV__CAP_PROP_LATEST);
  mod.add_bits<cv::VideoCaptureModes>("VideoCaptureModes");
  mod.set_const("CAP_MODE_BGR", cv::VideoCaptureModes::CAP_MODE_BGR);
  mod.set_const("CAP_MODE_RGB", cv::VideoCaptureModes::CAP_MODE_RGB);
  mod.set_const("CAP_MODE_GRAY", cv::VideoCaptureModes::CAP_MODE_GRAY);
  mod.set_const("CAP_MODE_YUYV", cv::VideoCaptureModes::CAP_MODE_YUYV);
  mod.add_bits<cv::VideoWriterProperties>("VideoWriterProperties");
  mod.set_const("VIDEOWRITER_PROP_QUALITY",
                cv::VideoWriterProperties::VIDEOWRITER_PROP_QUALITY);
  mod.set_const("VIDEOWRITER_PROP_FRAMEBYTES",
                cv::VideoWriterProperties::VIDEOWRITER_PROP_FRAMEBYTES);
  mod.set_const("VIDEOWRITER_PROP_NSTRIPES",
                cv::VideoWriterProperties::VIDEOWRITER_PROP_NSTRIPES);
  mod.set_const("CAP_PROP_DC1394_OFF", (int)cv::CAP_PROP_DC1394_OFF);
  mod.set_const("CAP_PROP_DC1394_MODE_MANUAL",
                (int)cv::CAP_PROP_DC1394_MODE_MANUAL);
  mod.set_const("CAP_PROP_DC1394_MODE_AUTO",
                (int)cv::CAP_PROP_DC1394_MODE_AUTO);
  mod.set_const("CAP_PROP_DC1394_MODE_ONE_PUSH_AUTO",
                (int)cv::CAP_PROP_DC1394_MODE_ONE_PUSH_AUTO);
  mod.set_const("CAP_PROP_DC1394_MAX", (int)cv::CAP_PROP_DC1394_MAX);
  mod.set_const("CAP_OPENNI_DEPTH_GENERATOR",
                (int)cv::CAP_OPENNI_DEPTH_GENERATOR);
  mod.set_const("CAP_OPENNI_IMAGE_GENERATOR",
                (int)cv::CAP_OPENNI_IMAGE_GENERATOR);
  mod.set_const("CAP_OPENNI_IR_GENERATOR", (int)cv::CAP_OPENNI_IR_GENERATOR);
  mod.set_const("CAP_OPENNI_GENERATORS_MASK",
                (int)cv::CAP_OPENNI_GENERATORS_MASK);
  mod.set_const("CAP_PROP_OPENNI_OUTPUT_MODE",
                (int)cv::CAP_PROP_OPENNI_OUTPUT_MODE);
  mod.set_const("CAP_PROP_OPENNI_FRAME_MAX_DEPTH",
                (int)cv::CAP_PROP_OPENNI_FRAME_MAX_DEPTH);
  mod.set_const("CAP_PROP_OPENNI_BASELINE", (int)cv::CAP_PROP_OPENNI_BASELINE);
  mod.set_const("CAP_PROP_OPENNI_FOCAL_LENGTH",
                (int)cv::CAP_PROP_OPENNI_FOCAL_LENGTH);
  mod.set_const("CAP_PROP_OPENNI_REGISTRATION",
                (int)cv::CAP_PROP_OPENNI_REGISTRATION);
  mod.set_const("CAP_PROP_OPENNI_REGISTRATION_ON",
                (int)cv::CAP_PROP_OPENNI_REGISTRATION_ON);
  mod.set_const("CAP_PROP_OPENNI_APPROX_FRAME_SYNC",
                (int)cv::CAP_PROP_OPENNI_APPROX_FRAME_SYNC);
  mod.set_const("CAP_PROP_OPENNI_MAX_BUFFER_SIZE",
                (int)cv::CAP_PROP_OPENNI_MAX_BUFFER_SIZE);
  mod.set_const("CAP_PROP_OPENNI_CIRCLE_BUFFER",
                (int)cv::CAP_PROP_OPENNI_CIRCLE_BUFFER);
  mod.set_const("CAP_PROP_OPENNI_MAX_TIME_DURATION",
                (int)cv::CAP_PROP_OPENNI_MAX_TIME_DURATION);
  mod.set_const("CAP_PROP_OPENNI_GENERATOR_PRESENT",
                (int)cv::CAP_PROP_OPENNI_GENERATOR_PRESENT);
  mod.set_const("CAP_PROP_OPENNI2_SYNC", (int)cv::CAP_PROP_OPENNI2_SYNC);
  mod.set_const("CAP_PROP_OPENNI2_MIRROR", (int)cv::CAP_PROP_OPENNI2_MIRROR);
  mod.set_const("CAP_OPENNI_IMAGE_GENERATOR_PRESENT",
                (int)cv::CAP_OPENNI_IMAGE_GENERATOR_PRESENT);
  mod.set_const("CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE",
                (int)cv::CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE);
  mod.set_const("CAP_OPENNI_DEPTH_GENERATOR_PRESENT",
                (int)cv::CAP_OPENNI_DEPTH_GENERATOR_PRESENT);
  mod.set_const("CAP_OPENNI_DEPTH_GENERATOR_BASELINE",
                (int)cv::CAP_OPENNI_DEPTH_GENERATOR_BASELINE);
  mod.set_const("CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH",
                (int)cv::CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH);
  mod.set_const("CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION",
                (int)cv::CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION);
  mod.set_const("CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON",
                (int)cv::CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON);
  mod.set_const("CAP_OPENNI_IR_GENERATOR_PRESENT",
                (int)cv::CAP_OPENNI_IR_GENERATOR_PRESENT);
  mod.set_const("CAP_OPENNI_DEPTH_MAP", (int)cv::CAP_OPENNI_DEPTH_MAP);
  mod.set_const("CAP_OPENNI_POINT_CLOUD_MAP",
                (int)cv::CAP_OPENNI_POINT_CLOUD_MAP);
  mod.set_const("CAP_OPENNI_DISPARITY_MAP", (int)cv::CAP_OPENNI_DISPARITY_MAP);
  mod.set_const("CAP_OPENNI_DISPARITY_MAP_32F",
                (int)cv::CAP_OPENNI_DISPARITY_MAP_32F);
  mod.set_const("CAP_OPENNI_VALID_DEPTH_MASK",
                (int)cv::CAP_OPENNI_VALID_DEPTH_MASK);
  mod.set_const("CAP_OPENNI_BGR_IMAGE", (int)cv::CAP_OPENNI_BGR_IMAGE);
  mod.set_const("CAP_OPENNI_GRAY_IMAGE", (int)cv::CAP_OPENNI_GRAY_IMAGE);
  mod.set_const("CAP_OPENNI_IR_IMAGE", (int)cv::CAP_OPENNI_IR_IMAGE);
  mod.set_const("CAP_OPENNI_VGA_30HZ", (int)cv::CAP_OPENNI_VGA_30HZ);
  mod.set_const("CAP_OPENNI_SXGA_15HZ", (int)cv::CAP_OPENNI_SXGA_15HZ);
  mod.set_const("CAP_OPENNI_SXGA_30HZ", (int)cv::CAP_OPENNI_SXGA_30HZ);
  mod.set_const("CAP_OPENNI_QVGA_30HZ", (int)cv::CAP_OPENNI_QVGA_30HZ);
  mod.set_const("CAP_OPENNI_QVGA_60HZ", (int)cv::CAP_OPENNI_QVGA_60HZ);
  mod.set_const("CAP_PROP_GSTREAMER_QUEUE_LENGTH",
                (int)cv::CAP_PROP_GSTREAMER_QUEUE_LENGTH);
  mod.set_const("CAP_PROP_PVAPI_MULTICASTIP",
                (int)cv::CAP_PROP_PVAPI_MULTICASTIP);
  mod.set_const("CAP_PROP_PVAPI_FRAMESTARTTRIGGERMODE",
                (int)cv::CAP_PROP_PVAPI_FRAMESTARTTRIGGERMODE);
  mod.set_const("CAP_PROP_PVAPI_DECIMATIONHORIZONTAL",
                (int)cv::CAP_PROP_PVAPI_DECIMATIONHORIZONTAL);
  mod.set_const("CAP_PROP_PVAPI_DECIMATIONVERTICAL",
                (int)cv::CAP_PROP_PVAPI_DECIMATIONVERTICAL);
  mod.set_const("CAP_PROP_PVAPI_BINNINGX", (int)cv::CAP_PROP_PVAPI_BINNINGX);
  mod.set_const("CAP_PROP_PVAPI_BINNINGY", (int)cv::CAP_PROP_PVAPI_BINNINGY);
  mod.set_const("CAP_PROP_PVAPI_PIXELFORMAT",
                (int)cv::CAP_PROP_PVAPI_PIXELFORMAT);
  mod.set_const("CAP_PVAPI_FSTRIGMODE_FREERUN",
                (int)cv::CAP_PVAPI_FSTRIGMODE_FREERUN);
  mod.set_const("CAP_PVAPI_FSTRIGMODE_SYNCIN1",
                (int)cv::CAP_PVAPI_FSTRIGMODE_SYNCIN1);
  mod.set_const("CAP_PVAPI_FSTRIGMODE_SYNCIN2",
                (int)cv::CAP_PVAPI_FSTRIGMODE_SYNCIN2);
  mod.set_const("CAP_PVAPI_FSTRIGMODE_FIXEDRATE",
                (int)cv::CAP_PVAPI_FSTRIGMODE_FIXEDRATE);
  mod.set_const("CAP_PVAPI_FSTRIGMODE_SOFTWARE",
                (int)cv::CAP_PVAPI_FSTRIGMODE_SOFTWARE);
  mod.set_const("CAP_PVAPI_DECIMATION_OFF", (int)cv::CAP_PVAPI_DECIMATION_OFF);
  mod.set_const("CAP_PVAPI_DECIMATION_2OUTOF4",
                (int)cv::CAP_PVAPI_DECIMATION_2OUTOF4);
  mod.set_const("CAP_PVAPI_DECIMATION_2OUTOF8",
                (int)cv::CAP_PVAPI_DECIMATION_2OUTOF8);
  mod.set_const("CAP_PVAPI_DECIMATION_2OUTOF16",
                (int)cv::CAP_PVAPI_DECIMATION_2OUTOF16);
  mod.set_const("CAP_PVAPI_PIXELFORMAT_MONO8",
                (int)cv::CAP_PVAPI_PIXELFORMAT_MONO8);
  mod.set_const("CAP_PVAPI_PIXELFORMAT_MONO16",
                (int)cv::CAP_PVAPI_PIXELFORMAT_MONO16);
  mod.set_const("CAP_PVAPI_PIXELFORMAT_BAYER8",
                (int)cv::CAP_PVAPI_PIXELFORMAT_BAYER8);
  mod.set_const("CAP_PVAPI_PIXELFORMAT_BAYER16",
                (int)cv::CAP_PVAPI_PIXELFORMAT_BAYER16);
  mod.set_const("CAP_PVAPI_PIXELFORMAT_RGB24",
                (int)cv::CAP_PVAPI_PIXELFORMAT_RGB24);
  mod.set_const("CAP_PVAPI_PIXELFORMAT_BGR24",
                (int)cv::CAP_PVAPI_PIXELFORMAT_BGR24);
  mod.set_const("CAP_PVAPI_PIXELFORMAT_RGBA32",
                (int)cv::CAP_PVAPI_PIXELFORMAT_RGBA32);
  mod.set_const("CAP_PVAPI_PIXELFORMAT_BGRA32",
                (int)cv::CAP_PVAPI_PIXELFORMAT_BGRA32);
  mod.set_const("CAP_PROP_XI_DOWNSAMPLING", (int)cv::CAP_PROP_XI_DOWNSAMPLING);
  mod.set_const("CAP_PROP_XI_DATA_FORMAT", (int)cv::CAP_PROP_XI_DATA_FORMAT);
  mod.set_const("CAP_PROP_XI_OFFSET_X", (int)cv::CAP_PROP_XI_OFFSET_X);
  mod.set_const("CAP_PROP_XI_OFFSET_Y", (int)cv::CAP_PROP_XI_OFFSET_Y);
  mod.set_const("CAP_PROP_XI_TRG_SOURCE", (int)cv::CAP_PROP_XI_TRG_SOURCE);
  mod.set_const("CAP_PROP_XI_TRG_SOFTWARE", (int)cv::CAP_PROP_XI_TRG_SOFTWARE);
  mod.set_const("CAP_PROP_XI_GPI_SELECTOR", (int)cv::CAP_PROP_XI_GPI_SELECTOR);
  mod.set_const("CAP_PROP_XI_GPI_MODE", (int)cv::CAP_PROP_XI_GPI_MODE);
  mod.set_const("CAP_PROP_XI_GPI_LEVEL", (int)cv::CAP_PROP_XI_GPI_LEVEL);
  mod.set_const("CAP_PROP_XI_GPO_SELECTOR", (int)cv::CAP_PROP_XI_GPO_SELECTOR);
  mod.set_const("CAP_PROP_XI_GPO_MODE", (int)cv::CAP_PROP_XI_GPO_MODE);
  mod.set_const("CAP_PROP_XI_LED_SELECTOR", (int)cv::CAP_PROP_XI_LED_SELECTOR);
  mod.set_const("CAP_PROP_XI_LED_MODE", (int)cv::CAP_PROP_XI_LED_MODE);
  mod.set_const("CAP_PROP_XI_MANUAL_WB", (int)cv::CAP_PROP_XI_MANUAL_WB);
  mod.set_const("CAP_PROP_XI_AUTO_WB", (int)cv::CAP_PROP_XI_AUTO_WB);
  mod.set_const("CAP_PROP_XI_AEAG", (int)cv::CAP_PROP_XI_AEAG);
  mod.set_const("CAP_PROP_XI_EXP_PRIORITY", (int)cv::CAP_PROP_XI_EXP_PRIORITY);
  mod.set_const("CAP_PROP_XI_AE_MAX_LIMIT", (int)cv::CAP_PROP_XI_AE_MAX_LIMIT);
  mod.set_const("CAP_PROP_XI_AG_MAX_LIMIT", (int)cv::CAP_PROP_XI_AG_MAX_LIMIT);
  mod.set_const("CAP_PROP_XI_AEAG_LEVEL", (int)cv::CAP_PROP_XI_AEAG_LEVEL);
  mod.set_const("CAP_PROP_XI_TIMEOUT", (int)cv::CAP_PROP_XI_TIMEOUT);
  mod.set_const("CAP_PROP_XI_EXPOSURE", (int)cv::CAP_PROP_XI_EXPOSURE);
  mod.set_const("CAP_PROP_XI_EXPOSURE_BURST_COUNT",
                (int)cv::CAP_PROP_XI_EXPOSURE_BURST_COUNT);
  mod.set_const("CAP_PROP_XI_GAIN_SELECTOR",
                (int)cv::CAP_PROP_XI_GAIN_SELECTOR);
  mod.set_const("CAP_PROP_XI_GAIN", (int)cv::CAP_PROP_XI_GAIN);
  mod.set_const("CAP_PROP_XI_DOWNSAMPLING_TYPE",
                (int)cv::CAP_PROP_XI_DOWNSAMPLING_TYPE);
  mod.set_const("CAP_PROP_XI_BINNING_SELECTOR",
                (int)cv::CAP_PROP_XI_BINNING_SELECTOR);
  mod.set_const("CAP_PROP_XI_BINNING_VERTICAL",
                (int)cv::CAP_PROP_XI_BINNING_VERTICAL);
  mod.set_const("CAP_PROP_XI_BINNING_HORIZONTAL",
                (int)cv::CAP_PROP_XI_BINNING_HORIZONTAL);
  mod.set_const("CAP_PROP_XI_BINNING_PATTERN",
                (int)cv::CAP_PROP_XI_BINNING_PATTERN);
  mod.set_const("CAP_PROP_XI_DECIMATION_SELECTOR",
                (int)cv::CAP_PROP_XI_DECIMATION_SELECTOR);
  mod.set_const("CAP_PROP_XI_DECIMATION_VERTICAL",
                (int)cv::CAP_PROP_XI_DECIMATION_VERTICAL);
  mod.set_const("CAP_PROP_XI_DECIMATION_HORIZONTAL",
                (int)cv::CAP_PROP_XI_DECIMATION_HORIZONTAL);
  mod.set_const("CAP_PROP_XI_DECIMATION_PATTERN",
                (int)cv::CAP_PROP_XI_DECIMATION_PATTERN);
  mod.set_const("CAP_PROP_XI_TEST_PATTERN_GENERATOR_SELECTOR",
                (int)cv::CAP_PROP_XI_TEST_PATTERN_GENERATOR_SELECTOR);
  mod.set_const("CAP_PROP_XI_TEST_PATTERN", (int)cv::CAP_PROP_XI_TEST_PATTERN);
  mod.set_const("CAP_PROP_XI_IMAGE_DATA_FORMAT",
                (int)cv::CAP_PROP_XI_IMAGE_DATA_FORMAT);
  mod.set_const("CAP_PROP_XI_SHUTTER_TYPE", (int)cv::CAP_PROP_XI_SHUTTER_TYPE);
  mod.set_const("CAP_PROP_XI_SENSOR_TAPS", (int)cv::CAP_PROP_XI_SENSOR_TAPS);
  mod.set_const("CAP_PROP_XI_AEAG_ROI_OFFSET_X",
                (int)cv::CAP_PROP_XI_AEAG_ROI_OFFSET_X);
  mod.set_const("CAP_PROP_XI_AEAG_ROI_OFFSET_Y",
                (int)cv::CAP_PROP_XI_AEAG_ROI_OFFSET_Y);
  mod.set_const("CAP_PROP_XI_AEAG_ROI_WIDTH",
                (int)cv::CAP_PROP_XI_AEAG_ROI_WIDTH);
  mod.set_const("CAP_PROP_XI_AEAG_ROI_HEIGHT",
                (int)cv::CAP_PROP_XI_AEAG_ROI_HEIGHT);
  mod.set_const("CAP_PROP_XI_BPC", (int)cv::CAP_PROP_XI_BPC);
  mod.set_const("CAP_PROP_XI_WB_KR", (int)cv::CAP_PROP_XI_WB_KR);
  mod.set_const("CAP_PROP_XI_WB_KG", (int)cv::CAP_PROP_XI_WB_KG);
  mod.set_const("CAP_PROP_XI_WB_KB", (int)cv::CAP_PROP_XI_WB_KB);
  mod.set_const("CAP_PROP_XI_WIDTH", (int)cv::CAP_PROP_XI_WIDTH);
  mod.set_const("CAP_PROP_XI_HEIGHT", (int)cv::CAP_PROP_XI_HEIGHT);
  mod.set_const("CAP_PROP_XI_REGION_SELECTOR",
                (int)cv::CAP_PROP_XI_REGION_SELECTOR);
  mod.set_const("CAP_PROP_XI_REGION_MODE", (int)cv::CAP_PROP_XI_REGION_MODE);
  mod.set_const("CAP_PROP_XI_LIMIT_BANDWIDTH",
                (int)cv::CAP_PROP_XI_LIMIT_BANDWIDTH);
  mod.set_const("CAP_PROP_XI_SENSOR_DATA_BIT_DEPTH",
                (int)cv::CAP_PROP_XI_SENSOR_DATA_BIT_DEPTH);
  mod.set_const("CAP_PROP_XI_OUTPUT_DATA_BIT_DEPTH",
                (int)cv::CAP_PROP_XI_OUTPUT_DATA_BIT_DEPTH);
  mod.set_const("CAP_PROP_XI_IMAGE_DATA_BIT_DEPTH",
                (int)cv::CAP_PROP_XI_IMAGE_DATA_BIT_DEPTH);
  mod.set_const("CAP_PROP_XI_OUTPUT_DATA_PACKING",
                (int)cv::CAP_PROP_XI_OUTPUT_DATA_PACKING);
  mod.set_const("CAP_PROP_XI_OUTPUT_DATA_PACKING_TYPE",
                (int)cv::CAP_PROP_XI_OUTPUT_DATA_PACKING_TYPE);
  mod.set_const("CAP_PROP_XI_IS_COOLED", (int)cv::CAP_PROP_XI_IS_COOLED);
  mod.set_const("CAP_PROP_XI_COOLING", (int)cv::CAP_PROP_XI_COOLING);
  mod.set_const("CAP_PROP_XI_TARGET_TEMP", (int)cv::CAP_PROP_XI_TARGET_TEMP);
  mod.set_const("CAP_PROP_XI_CHIP_TEMP", (int)cv::CAP_PROP_XI_CHIP_TEMP);
  mod.set_const("CAP_PROP_XI_HOUS_TEMP", (int)cv::CAP_PROP_XI_HOUS_TEMP);
  mod.set_const("CAP_PROP_XI_HOUS_BACK_SIDE_TEMP",
                (int)cv::CAP_PROP_XI_HOUS_BACK_SIDE_TEMP);
  mod.set_const("CAP_PROP_XI_SENSOR_BOARD_TEMP",
                (int)cv::CAP_PROP_XI_SENSOR_BOARD_TEMP);
  mod.set_const("CAP_PROP_XI_CMS", (int)cv::CAP_PROP_XI_CMS);
  mod.set_const("CAP_PROP_XI_APPLY_CMS", (int)cv::CAP_PROP_XI_APPLY_CMS);
  mod.set_const("CAP_PROP_XI_IMAGE_IS_COLOR",
                (int)cv::CAP_PROP_XI_IMAGE_IS_COLOR);
  mod.set_const("CAP_PROP_XI_COLOR_FILTER_ARRAY",
                (int)cv::CAP_PROP_XI_COLOR_FILTER_ARRAY);
  mod.set_const("CAP_PROP_XI_GAMMAY", (int)cv::CAP_PROP_XI_GAMMAY);
  mod.set_const("CAP_PROP_XI_GAMMAC", (int)cv::CAP_PROP_XI_GAMMAC);
  mod.set_const("CAP_PROP_XI_SHARPNESS", (int)cv::CAP_PROP_XI_SHARPNESS);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_00", (int)cv::CAP_PROP_XI_CC_MATRIX_00);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_01", (int)cv::CAP_PROP_XI_CC_MATRIX_01);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_02", (int)cv::CAP_PROP_XI_CC_MATRIX_02);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_03", (int)cv::CAP_PROP_XI_CC_MATRIX_03);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_10", (int)cv::CAP_PROP_XI_CC_MATRIX_10);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_11", (int)cv::CAP_PROP_XI_CC_MATRIX_11);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_12", (int)cv::CAP_PROP_XI_CC_MATRIX_12);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_13", (int)cv::CAP_PROP_XI_CC_MATRIX_13);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_20", (int)cv::CAP_PROP_XI_CC_MATRIX_20);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_21", (int)cv::CAP_PROP_XI_CC_MATRIX_21);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_22", (int)cv::CAP_PROP_XI_CC_MATRIX_22);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_23", (int)cv::CAP_PROP_XI_CC_MATRIX_23);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_30", (int)cv::CAP_PROP_XI_CC_MATRIX_30);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_31", (int)cv::CAP_PROP_XI_CC_MATRIX_31);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_32", (int)cv::CAP_PROP_XI_CC_MATRIX_32);
  mod.set_const("CAP_PROP_XI_CC_MATRIX_33", (int)cv::CAP_PROP_XI_CC_MATRIX_33);
  mod.set_const("CAP_PROP_XI_DEFAULT_CC_MATRIX",
                (int)cv::CAP_PROP_XI_DEFAULT_CC_MATRIX);
  mod.set_const("CAP_PROP_XI_TRG_SELECTOR", (int)cv::CAP_PROP_XI_TRG_SELECTOR);
  mod.set_const("CAP_PROP_XI_ACQ_FRAME_BURST_COUNT",
                (int)cv::CAP_PROP_XI_ACQ_FRAME_BURST_COUNT);
  mod.set_const("CAP_PROP_XI_DEBOUNCE_EN", (int)cv::CAP_PROP_XI_DEBOUNCE_EN);
  mod.set_const("CAP_PROP_XI_DEBOUNCE_T0", (int)cv::CAP_PROP_XI_DEBOUNCE_T0);
  mod.set_const("CAP_PROP_XI_DEBOUNCE_T1", (int)cv::CAP_PROP_XI_DEBOUNCE_T1);
  mod.set_const("CAP_PROP_XI_DEBOUNCE_POL", (int)cv::CAP_PROP_XI_DEBOUNCE_POL);
  mod.set_const("CAP_PROP_XI_LENS_MODE", (int)cv::CAP_PROP_XI_LENS_MODE);
  mod.set_const("CAP_PROP_XI_LENS_APERTURE_VALUE",
                (int)cv::CAP_PROP_XI_LENS_APERTURE_VALUE);
  mod.set_const("CAP_PROP_XI_LENS_FOCUS_MOVEMENT_VALUE",
                (int)cv::CAP_PROP_XI_LENS_FOCUS_MOVEMENT_VALUE);
  mod.set_const("CAP_PROP_XI_LENS_FOCUS_MOVE",
                (int)cv::CAP_PROP_XI_LENS_FOCUS_MOVE);
  mod.set_const("CAP_PROP_XI_LENS_FOCUS_DISTANCE",
                (int)cv::CAP_PROP_XI_LENS_FOCUS_DISTANCE);
  mod.set_const("CAP_PROP_XI_LENS_FOCAL_LENGTH",
                (int)cv::CAP_PROP_XI_LENS_FOCAL_LENGTH);
  mod.set_const("CAP_PROP_XI_LENS_FEATURE_SELECTOR",
                (int)cv::CAP_PROP_XI_LENS_FEATURE_SELECTOR);
  mod.set_const("CAP_PROP_XI_LENS_FEATURE", (int)cv::CAP_PROP_XI_LENS_FEATURE);
  mod.set_const("CAP_PROP_XI_DEVICE_MODEL_ID",
                (int)cv::CAP_PROP_XI_DEVICE_MODEL_ID);
  mod.set_const("CAP_PROP_XI_DEVICE_SN", (int)cv::CAP_PROP_XI_DEVICE_SN);
  mod.set_const("CAP_PROP_XI_IMAGE_DATA_FORMAT_RGB32_ALPHA",
                (int)cv::CAP_PROP_XI_IMAGE_DATA_FORMAT_RGB32_ALPHA);
  mod.set_const("CAP_PROP_XI_IMAGE_PAYLOAD_SIZE",
                (int)cv::CAP_PROP_XI_IMAGE_PAYLOAD_SIZE);
  mod.set_const("CAP_PROP_XI_TRANSPORT_PIXEL_FORMAT",
                (int)cv::CAP_PROP_XI_TRANSPORT_PIXEL_FORMAT);
  mod.set_const("CAP_PROP_XI_SENSOR_CLOCK_FREQ_HZ",
                (int)cv::CAP_PROP_XI_SENSOR_CLOCK_FREQ_HZ);
  mod.set_const("CAP_PROP_XI_SENSOR_CLOCK_FREQ_INDEX",
                (int)cv::CAP_PROP_XI_SENSOR_CLOCK_FREQ_INDEX);
  mod.set_const("CAP_PROP_XI_SENSOR_OUTPUT_CHANNEL_COUNT",
                (int)cv::CAP_PROP_XI_SENSOR_OUTPUT_CHANNEL_COUNT);
  mod.set_const("CAP_PROP_XI_FRAMERATE", (int)cv::CAP_PROP_XI_FRAMERATE);
  mod.set_const("CAP_PROP_XI_COUNTER_SELECTOR",
                (int)cv::CAP_PROP_XI_COUNTER_SELECTOR);
  mod.set_const("CAP_PROP_XI_COUNTER_VALUE",
                (int)cv::CAP_PROP_XI_COUNTER_VALUE);
  mod.set_const("CAP_PROP_XI_ACQ_TIMING_MODE",
                (int)cv::CAP_PROP_XI_ACQ_TIMING_MODE);
  mod.set_const("CAP_PROP_XI_AVAILABLE_BANDWIDTH",
                (int)cv::CAP_PROP_XI_AVAILABLE_BANDWIDTH);
  mod.set_const("CAP_PROP_XI_BUFFER_POLICY",
                (int)cv::CAP_PROP_XI_BUFFER_POLICY);
  mod.set_const("CAP_PROP_XI_LUT_EN", (int)cv::CAP_PROP_XI_LUT_EN);
  mod.set_const("CAP_PROP_XI_LUT_INDEX", (int)cv::CAP_PROP_XI_LUT_INDEX);
  mod.set_const("CAP_PROP_XI_LUT_VALUE", (int)cv::CAP_PROP_XI_LUT_VALUE);
  mod.set_const("CAP_PROP_XI_TRG_DELAY", (int)cv::CAP_PROP_XI_TRG_DELAY);
  mod.set_const("CAP_PROP_XI_TS_RST_MODE", (int)cv::CAP_PROP_XI_TS_RST_MODE);
  mod.set_const("CAP_PROP_XI_TS_RST_SOURCE",
                (int)cv::CAP_PROP_XI_TS_RST_SOURCE);
  mod.set_const("CAP_PROP_XI_IS_DEVICE_EXIST",
                (int)cv::CAP_PROP_XI_IS_DEVICE_EXIST);
  mod.set_const("CAP_PROP_XI_ACQ_BUFFER_SIZE",
                (int)cv::CAP_PROP_XI_ACQ_BUFFER_SIZE);
  mod.set_const("CAP_PROP_XI_ACQ_BUFFER_SIZE_UNIT",
                (int)cv::CAP_PROP_XI_ACQ_BUFFER_SIZE_UNIT);
  mod.set_const("CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_SIZE",
                (int)cv::CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_SIZE);
  mod.set_const("CAP_PROP_XI_BUFFERS_QUEUE_SIZE",
                (int)cv::CAP_PROP_XI_BUFFERS_QUEUE_SIZE);
  mod.set_const("CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_COMMIT",
                (int)cv::CAP_PROP_XI_ACQ_TRANSPORT_BUFFER_COMMIT);
  mod.set_const("CAP_PROP_XI_RECENT_FRAME", (int)cv::CAP_PROP_XI_RECENT_FRAME);
  mod.set_const("CAP_PROP_XI_DEVICE_RESET", (int)cv::CAP_PROP_XI_DEVICE_RESET);
  mod.set_const("CAP_PROP_XI_COLUMN_FPN_CORRECTION",
                (int)cv::CAP_PROP_XI_COLUMN_FPN_CORRECTION);
  mod.set_const("CAP_PROP_XI_ROW_FPN_CORRECTION",
                (int)cv::CAP_PROP_XI_ROW_FPN_CORRECTION);
  mod.set_const("CAP_PROP_XI_SENSOR_MODE", (int)cv::CAP_PROP_XI_SENSOR_MODE);
  mod.set_const("CAP_PROP_XI_HDR", (int)cv::CAP_PROP_XI_HDR);
  mod.set_const("CAP_PROP_XI_HDR_KNEEPOINT_COUNT",
                (int)cv::CAP_PROP_XI_HDR_KNEEPOINT_COUNT);
  mod.set_const("CAP_PROP_XI_HDR_T1", (int)cv::CAP_PROP_XI_HDR_T1);
  mod.set_const("CAP_PROP_XI_HDR_T2", (int)cv::CAP_PROP_XI_HDR_T2);
  mod.set_const("CAP_PROP_XI_KNEEPOINT1", (int)cv::CAP_PROP_XI_KNEEPOINT1);
  mod.set_const("CAP_PROP_XI_KNEEPOINT2", (int)cv::CAP_PROP_XI_KNEEPOINT2);
  mod.set_const("CAP_PROP_XI_IMAGE_BLACK_LEVEL",
                (int)cv::CAP_PROP_XI_IMAGE_BLACK_LEVEL);
  mod.set_const("CAP_PROP_XI_HW_REVISION", (int)cv::CAP_PROP_XI_HW_REVISION);
  mod.set_const("CAP_PROP_XI_DEBUG_LEVEL", (int)cv::CAP_PROP_XI_DEBUG_LEVEL);
  mod.set_const("CAP_PROP_XI_AUTO_BANDWIDTH_CALCULATION",
                (int)cv::CAP_PROP_XI_AUTO_BANDWIDTH_CALCULATION);
  mod.set_const("CAP_PROP_XI_FFS_FILE_ID", (int)cv::CAP_PROP_XI_FFS_FILE_ID);
  mod.set_const("CAP_PROP_XI_FFS_FILE_SIZE",
                (int)cv::CAP_PROP_XI_FFS_FILE_SIZE);
  mod.set_const("CAP_PROP_XI_FREE_FFS_SIZE",
                (int)cv::CAP_PROP_XI_FREE_FFS_SIZE);
  mod.set_const("CAP_PROP_XI_USED_FFS_SIZE",
                (int)cv::CAP_PROP_XI_USED_FFS_SIZE);
  mod.set_const("CAP_PROP_XI_FFS_ACCESS_KEY",
                (int)cv::CAP_PROP_XI_FFS_ACCESS_KEY);
  mod.set_const("CAP_PROP_XI_SENSOR_FEATURE_SELECTOR",
                (int)cv::CAP_PROP_XI_SENSOR_FEATURE_SELECTOR);
  mod.set_const("CAP_PROP_XI_SENSOR_FEATURE_VALUE",
                (int)cv::CAP_PROP_XI_SENSOR_FEATURE_VALUE);
  mod.set_const("CAP_PROP_IOS_DEVICE_FOCUS",
                (int)cv::CAP_PROP_IOS_DEVICE_FOCUS);
  mod.set_const("CAP_PROP_IOS_DEVICE_EXPOSURE",
                (int)cv::CAP_PROP_IOS_DEVICE_EXPOSURE);
  mod.set_const("CAP_PROP_IOS_DEVICE_FLASH",
                (int)cv::CAP_PROP_IOS_DEVICE_FLASH);
  mod.set_const("CAP_PROP_IOS_DEVICE_WHITEBALANCE",
                (int)cv::CAP_PROP_IOS_DEVICE_WHITEBALANCE);
  mod.set_const("CAP_PROP_IOS_DEVICE_TORCH",
                (int)cv::CAP_PROP_IOS_DEVICE_TORCH);
  mod.set_const("CAP_PROP_GIGA_FRAME_OFFSET_X",
                (int)cv::CAP_PROP_GIGA_FRAME_OFFSET_X);
  mod.set_const("CAP_PROP_GIGA_FRAME_OFFSET_Y",
                (int)cv::CAP_PROP_GIGA_FRAME_OFFSET_Y);
  mod.set_const("CAP_PROP_GIGA_FRAME_WIDTH_MAX",
                (int)cv::CAP_PROP_GIGA_FRAME_WIDTH_MAX);
  mod.set_const("CAP_PROP_GIGA_FRAME_HEIGH_MAX",
                (int)cv::CAP_PROP_GIGA_FRAME_HEIGH_MAX);
  mod.set_const("CAP_PROP_GIGA_FRAME_SENS_WIDTH",
                (int)cv::CAP_PROP_GIGA_FRAME_SENS_WIDTH);
  mod.set_const("CAP_PROP_GIGA_FRAME_SENS_HEIGH",
                (int)cv::CAP_PROP_GIGA_FRAME_SENS_HEIGH);
  mod.set_const("CAP_PROP_INTELPERC_PROFILE_COUNT",
                (int)cv::CAP_PROP_INTELPERC_PROFILE_COUNT);
  mod.set_const("CAP_PROP_INTELPERC_PROFILE_IDX",
                (int)cv::CAP_PROP_INTELPERC_PROFILE_IDX);
  mod.set_const("CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE",
                (int)cv::CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE);
  mod.set_const("CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE",
                (int)cv::CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE);
  mod.set_const("CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD",
                (int)cv::CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD);
  mod.set_const("CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ",
                (int)cv::CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ);
  mod.set_const("CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT",
                (int)cv::CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT);
  mod.set_const("CAP_INTELPERC_DEPTH_GENERATOR",
                (int)cv::CAP_INTELPERC_DEPTH_GENERATOR);
  mod.set_const("CAP_INTELPERC_IMAGE_GENERATOR",
                (int)cv::CAP_INTELPERC_IMAGE_GENERATOR);
  mod.set_const("CAP_INTELPERC_GENERATORS_MASK",
                (int)cv::CAP_INTELPERC_GENERATORS_MASK);
  mod.set_const("CAP_INTELPERC_DEPTH_MAP", (int)cv::CAP_INTELPERC_DEPTH_MAP);
  mod.set_const("CAP_INTELPERC_UVDEPTH_MAP",
                (int)cv::CAP_INTELPERC_UVDEPTH_MAP);
  mod.set_const("CAP_INTELPERC_IR_MAP", (int)cv::CAP_INTELPERC_IR_MAP);
  mod.set_const("CAP_INTELPERC_IMAGE", (int)cv::CAP_INTELPERC_IMAGE);
  mod.set_const("CAP_PROP_GPHOTO2_PREVIEW", (int)cv::CAP_PROP_GPHOTO2_PREVIEW);
  mod.set_const("CAP_PROP_GPHOTO2_WIDGET_ENUMERATE",
                (int)cv::CAP_PROP_GPHOTO2_WIDGET_ENUMERATE);
  mod.set_const("CAP_PROP_GPHOTO2_RELOAD_CONFIG",
                (int)cv::CAP_PROP_GPHOTO2_RELOAD_CONFIG);
  mod.set_const("CAP_PROP_GPHOTO2_RELOAD_ON_CHANGE",
                (int)cv::CAP_PROP_GPHOTO2_RELOAD_ON_CHANGE);
  mod.set_const("CAP_PROP_GPHOTO2_COLLECT_MSGS",
                (int)cv::CAP_PROP_GPHOTO2_COLLECT_MSGS);
  mod.set_const("CAP_PROP_GPHOTO2_FLUSH_MSGS",
                (int)cv::CAP_PROP_GPHOTO2_FLUSH_MSGS);
  mod.set_const("CAP_PROP_SPEED", (int)cv::CAP_PROP_SPEED);
  mod.set_const("CAP_PROP_APERTURE", (int)cv::CAP_PROP_APERTURE);
  mod.set_const("CAP_PROP_EXPOSUREPROGRAM", (int)cv::CAP_PROP_EXPOSUREPROGRAM);
  mod.set_const("CAP_PROP_VIEWFINDER", (int)cv::CAP_PROP_VIEWFINDER);
  mod.set_const("CAP_PROP_IMAGES_BASE", (int)cv::CAP_PROP_IMAGES_BASE);
  mod.set_const("CAP_PROP_IMAGES_LAST", (int)cv::CAP_PROP_IMAGES_LAST);
  mod.add_type<cv::VideoCapture>("VideoCapture")
      .constructor<const cv::String &>()
      .constructor<const cv::String &, int>()
      .constructor<int>()
      .method("open",
              [](cv::VideoCapture &instance, const cv::String &filename) {
                return instance.open(filename);
              })
      .method("open", [](cv::VideoCapture &instance,
                         int index) { return instance.open(index); })
      .method("open",
              [](cv::VideoCapture &instance, int cameraNum, int apiPreference) {
                return instance.open(cameraNum, apiPreference);
              })
      .method(
          "isOpened",
          [](const cv::VideoCapture &instance) { return instance.isOpened(); })
      .method("release",
              [](cv::VideoCapture &instance) { return instance.release(); })
      .method("grab",
              [](cv::VideoCapture &instance) { return instance.grab(); })
      .method("retrieve",
              [](cv::VideoCapture &instance, const cv::Mat &image) {
                return instance.retrieve(cv::OutputArray(image));
              })
      .method("retrieve",
              [](cv::VideoCapture &instance, const cv::Mat &image, int flag) {
                return instance.retrieve(cv::OutputArray(image), flag);
              })
      .method("operator>>",
              [](cv::VideoCapture &instance, cv::UMat &image) {
                return instance.operator>>(image);
              })
      .method("read",
              [](cv::VideoCapture &instance, const cv::Mat &image) {
                return instance.read(cv::OutputArray(image));
              })
      .method("set", [](cv::VideoCapture &instance, int propId,
                        double value) { return instance.set(propId, value); })
      .method("get", [](const cv::VideoCapture &instance,
                        int propId) { return instance.get(propId); })
      .method("open", [](cv::VideoCapture &instance, const cv::String &filename,
                         int apiPreference) {
        return instance.open(filename, apiPreference);
      });
  mod.add_type<cv::VideoWriter>("VideoWriter")
      .constructor<const cv::String &, int, double, cv::Size, bool>()
      .constructor<const cv::String &, int, int, double, cv::Size, bool>()
      .method("open",
              [](cv::VideoWriter &instance, const cv::String &filename,
                 int fourcc, double fps, cv::Size frameSize) {
                return instance.open(filename, fourcc, fps, frameSize);
              })
      .method("open",
              [](cv::VideoWriter &instance, const cv::String &filename,
                 int fourcc, double fps, cv::Size frameSize, bool isColor) {
                return instance.open(filename, fourcc, fps, frameSize, isColor);
              })
      .method(
          "open",
          [](cv::VideoWriter &instance, const cv::String &filename,
             int apiPreference, int fourcc, double fps, cv::Size frameSize) {
            return instance.open(filename, apiPreference, fourcc, fps,
                                 frameSize);
          })
      .method("open",
              [](cv::VideoWriter &instance, const cv::String &filename,
                 int apiPreference, int fourcc, double fps, cv::Size frameSize,
                 bool isColor) {
                return instance.open(filename, apiPreference, fourcc, fps,
                                     frameSize, isColor);
              })
      .method(
          "isOpened",
          [](const cv::VideoWriter &instance) { return instance.isOpened(); })
      .method("release",
              [](cv::VideoWriter &instance) { return instance.release(); })
      .method("operator<<",
              [](cv::VideoWriter &instance, const cv::Mat &image) {
                return instance.operator<<(image);
              })
      .method("write",
              [](cv::VideoWriter &instance, const cv::Mat &image) {
                return instance.write(image);
              })
      .method("set", [](cv::VideoWriter &instance, int propId,
                        double value) { return instance.set(propId, value); })
      .method("get", [](const cv::VideoWriter &instance,
                        int propId) { return instance.get(propId); })
      .method("fourcc",
              [](cv::VideoWriter &instance, char c1, char c2, char c3,
                 char c4) { return instance.fourcc(c1, c2, c3, c4); });
}
