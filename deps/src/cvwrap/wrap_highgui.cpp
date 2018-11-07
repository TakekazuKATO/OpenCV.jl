#include <opencv2/opencv.hpp>
#include "jlcxx/jlcxx.hpp"
#include "modules.hpp"
using namespace jlcxx;
using namespace cv;
JLCXX_MODULE
define_highgui_module(Module& mod) {
  mod.add_bits<cv::WindowFlags>("WindowFlags");
  mod.set_const("WINDOW_NORMAL",cv::WindowFlags::WINDOW_NORMAL);
  mod.set_const("WINDOW_AUTOSIZE",cv::WindowFlags::WINDOW_AUTOSIZE);
  mod.set_const("WINDOW_OPENGL",cv::WindowFlags::WINDOW_OPENGL);
  mod.set_const("WINDOW_FULLSCREEN",cv::WindowFlags::WINDOW_FULLSCREEN);
  mod.set_const("WINDOW_FREERATIO",cv::WindowFlags::WINDOW_FREERATIO);
  mod.set_const("WINDOW_KEEPRATIO",cv::WindowFlags::WINDOW_KEEPRATIO);
  mod.set_const("WINDOW_GUI_EXPANDED",cv::WindowFlags::WINDOW_GUI_EXPANDED);
  mod.set_const("WINDOW_GUI_NORMAL",cv::WindowFlags::WINDOW_GUI_NORMAL);
  mod.add_bits<cv::WindowPropertyFlags>("WindowPropertyFlags");
  mod.set_const("WND_PROP_FULLSCREEN",cv::WindowPropertyFlags::WND_PROP_FULLSCREEN);
  mod.set_const("WND_PROP_AUTOSIZE",cv::WindowPropertyFlags::WND_PROP_AUTOSIZE);
  mod.set_const("WND_PROP_ASPECT_RATIO",cv::WindowPropertyFlags::WND_PROP_ASPECT_RATIO);
  mod.set_const("WND_PROP_OPENGL",cv::WindowPropertyFlags::WND_PROP_OPENGL);
  mod.set_const("WND_PROP_VISIBLE",cv::WindowPropertyFlags::WND_PROP_VISIBLE);
  mod.add_bits<cv::MouseEventTypes>("MouseEventTypes");
  mod.set_const("EVENT_MOUSEMOVE",cv::MouseEventTypes::EVENT_MOUSEMOVE);
  mod.set_const("EVENT_LBUTTONDOWN",cv::MouseEventTypes::EVENT_LBUTTONDOWN);
  mod.set_const("EVENT_RBUTTONDOWN",cv::MouseEventTypes::EVENT_RBUTTONDOWN);
  mod.set_const("EVENT_MBUTTONDOWN",cv::MouseEventTypes::EVENT_MBUTTONDOWN);
  mod.set_const("EVENT_LBUTTONUP",cv::MouseEventTypes::EVENT_LBUTTONUP);
  mod.set_const("EVENT_RBUTTONUP",cv::MouseEventTypes::EVENT_RBUTTONUP);
  mod.set_const("EVENT_MBUTTONUP",cv::MouseEventTypes::EVENT_MBUTTONUP);
  mod.set_const("EVENT_LBUTTONDBLCLK",cv::MouseEventTypes::EVENT_LBUTTONDBLCLK);
  mod.set_const("EVENT_RBUTTONDBLCLK",cv::MouseEventTypes::EVENT_RBUTTONDBLCLK);
  mod.set_const("EVENT_MBUTTONDBLCLK",cv::MouseEventTypes::EVENT_MBUTTONDBLCLK);
  mod.set_const("EVENT_MOUSEWHEEL",cv::MouseEventTypes::EVENT_MOUSEWHEEL);
  mod.set_const("EVENT_MOUSEHWHEEL",cv::MouseEventTypes::EVENT_MOUSEHWHEEL);
  mod.add_bits<cv::MouseEventFlags>("MouseEventFlags");
  mod.set_const("EVENT_FLAG_LBUTTON",cv::MouseEventFlags::EVENT_FLAG_LBUTTON);
  mod.set_const("EVENT_FLAG_RBUTTON",cv::MouseEventFlags::EVENT_FLAG_RBUTTON);
  mod.set_const("EVENT_FLAG_MBUTTON",cv::MouseEventFlags::EVENT_FLAG_MBUTTON);
  mod.set_const("EVENT_FLAG_CTRLKEY",cv::MouseEventFlags::EVENT_FLAG_CTRLKEY);
  mod.set_const("EVENT_FLAG_SHIFTKEY",cv::MouseEventFlags::EVENT_FLAG_SHIFTKEY);
  mod.set_const("EVENT_FLAG_ALTKEY",cv::MouseEventFlags::EVENT_FLAG_ALTKEY);
  mod.add_bits<cv::QtFontWeights>("QtFontWeights");
  mod.set_const("QT_FONT_LIGHT",cv::QtFontWeights::QT_FONT_LIGHT);
  mod.set_const("QT_FONT_NORMAL",cv::QtFontWeights::QT_FONT_NORMAL);
  mod.set_const("QT_FONT_DEMIBOLD",cv::QtFontWeights::QT_FONT_DEMIBOLD);
  mod.set_const("QT_FONT_BOLD",cv::QtFontWeights::QT_FONT_BOLD);
  mod.set_const("QT_FONT_BLACK",cv::QtFontWeights::QT_FONT_BLACK);
  mod.add_bits<cv::QtFontStyles>("QtFontStyles");
  mod.set_const("QT_STYLE_NORMAL",cv::QtFontStyles::QT_STYLE_NORMAL);
  mod.set_const("QT_STYLE_ITALIC",cv::QtFontStyles::QT_STYLE_ITALIC);
  mod.set_const("QT_STYLE_OBLIQUE",cv::QtFontStyles::QT_STYLE_OBLIQUE);
  mod.add_bits<cv::QtButtonTypes>("QtButtonTypes");
  mod.set_const("QT_PUSH_BUTTON",cv::QtButtonTypes::QT_PUSH_BUTTON);
  mod.set_const("QT_CHECKBOX",cv::QtButtonTypes::QT_CHECKBOX);
  mod.set_const("QT_RADIOBOX",cv::QtButtonTypes::QT_RADIOBOX);
  mod.set_const("QT_NEW_BUTTONBAR",cv::QtButtonTypes::QT_NEW_BUTTONBAR);
  mod.method("namedWindow", [](const cv::String & winname) {
    return cv::namedWindow( winname );
  });
  mod.method("namedWindow", [](const cv::String & winname,int  flags) {
    return cv::namedWindow( winname,flags );
  });
  mod.method("destroyWindow", [](const cv::String & winname) {
    return cv::destroyWindow( winname );
  });
  mod.method("destroyAllWindows", []() {
    return cv::destroyAllWindows(  );
  });
  mod.method("startWindowThread", []() {
    return cv::startWindowThread(  );
  });
  mod.method("waitKeyEx", []() {
    return cv::waitKeyEx(  );
  });
  mod.method("waitKeyEx", [](int  delay) {
    return cv::waitKeyEx( delay );
  });
  mod.method("waitKey", []() {
    return cv::waitKey(  );
  });
  mod.method("waitKey", [](int  delay) {
    return cv::waitKey( delay );
  });
  mod.method("imshow", [](const cv::String & winname,const  cv::Mat & mat) {
    return cv::imshow( winname,cv::InputArray(mat) );
  });
  mod.method("resizeWindow", [](const cv::String & winname,int  width,int  height) {
    return cv::resizeWindow( winname,width,height );
  });
  mod.method("resizeWindow", [](const cv::String & winname,const cv::Size & size) {
    return cv::resizeWindow( winname,size );
  });
  mod.method("moveWindow", [](const cv::String & winname,int  x,int  y) {
    return cv::moveWindow( winname,x,y );
  });
  mod.method("setWindowProperty", [](const cv::String & winname,int  prop_id,double  prop_value) {
    return cv::setWindowProperty( winname,prop_id,prop_value );
  });
  mod.method("setWindowTitle", [](const cv::String & winname,const cv::String & title) {
    return cv::setWindowTitle( winname,title );
  });
  mod.method("getWindowProperty", [](const cv::String & winname,int  prop_id) {
    return cv::getWindowProperty( winname,prop_id );
  });
  mod.method("getWindowImageRect", [](const cv::String & winname) {
    return cv::getWindowImageRect( winname );
  });
  mod.method("setMouseCallback", [](const cv::String & winname,cv::MouseCallback  onMouse) {
    return cv::setMouseCallback( winname,onMouse );
  });
  mod.method("setMouseCallback", [](const cv::String & winname,cv::MouseCallback  onMouse,void * userdata) {
    return cv::setMouseCallback( winname,onMouse,userdata );
  });
  mod.method("getMouseWheelDelta", [](int  flags) {
    return cv::getMouseWheelDelta( flags );
  });
  mod.method("selectROI", [](const cv::String & windowName,const  cv::Mat & img) {
    return cv::selectROI( windowName,cv::InputArray(img) );
  });
  mod.method("selectROI", [](const cv::String & windowName,const  cv::Mat & img,bool  showCrosshair) {
    return cv::selectROI( windowName,cv::InputArray(img),showCrosshair );
  });
  mod.method("selectROI", [](const cv::String & windowName,const  cv::Mat & img,bool  showCrosshair,bool  fromCenter) {
    return cv::selectROI( windowName,cv::InputArray(img),showCrosshair,fromCenter );
  });
  mod.method("selectROI", [](const  cv::Mat & img) {
    return cv::selectROI( cv::InputArray(img) );
  });
  mod.method("selectROI", [](const  cv::Mat & img,bool  showCrosshair) {
    return cv::selectROI( cv::InputArray(img),showCrosshair );
  });
  mod.method("selectROI", [](const  cv::Mat & img,bool  showCrosshair,bool  fromCenter) {
    return cv::selectROI( cv::InputArray(img),showCrosshair,fromCenter );
  });
  mod.method("selectROIs", [](const cv::String & windowName,const  cv::Mat & img,std::vector<cv::Rect> & boundingBoxes) {
    return cv::selectROIs( windowName,cv::InputArray(img),boundingBoxes );
  });
  mod.method("selectROIs", [](const cv::String & windowName,const  cv::Mat & img,std::vector<cv::Rect> & boundingBoxes,bool  showCrosshair) {
    return cv::selectROIs( windowName,cv::InputArray(img),boundingBoxes,showCrosshair );
  });
  mod.method("selectROIs", [](const cv::String & windowName,const  cv::Mat & img,std::vector<cv::Rect> & boundingBoxes,bool  showCrosshair,bool  fromCenter) {
    return cv::selectROIs( windowName,cv::InputArray(img),boundingBoxes,showCrosshair,fromCenter );
  });
  mod.method("createTrackbar", [](const cv::String & trackbarname,const cv::String & winname,int * value,int  count) {
    return cv::createTrackbar( trackbarname,winname,value,count );
  });
  mod.method("createTrackbar", [](const cv::String & trackbarname,const cv::String & winname,int * value,int  count,cv::TrackbarCallback  onChange) {
    return cv::createTrackbar( trackbarname,winname,value,count,onChange );
  });
  mod.method("createTrackbar", [](const cv::String & trackbarname,const cv::String & winname,int * value,int  count,cv::TrackbarCallback  onChange,void * userdata) {
    return cv::createTrackbar( trackbarname,winname,value,count,onChange,userdata );
  });
  mod.method("getTrackbarPos", [](const cv::String & trackbarname,const cv::String & winname) {
    return cv::getTrackbarPos( trackbarname,winname );
  });
  mod.method("setTrackbarPos", [](const cv::String & trackbarname,const cv::String & winname,int  pos) {
    return cv::setTrackbarPos( trackbarname,winname,pos );
  });
  mod.method("setTrackbarMax", [](const cv::String & trackbarname,const cv::String & winname,int  maxval) {
    return cv::setTrackbarMax( trackbarname,winname,maxval );
  });
  mod.method("setTrackbarMin", [](const cv::String & trackbarname,const cv::String & winname,int  minval) {
    return cv::setTrackbarMin( trackbarname,winname,minval );
  });
  mod.method("imshow", [](const cv::String & winname,const cv::ogl::Texture2D & tex) {
    return cv::imshow( winname,tex );
  });
  mod.method("setOpenGlDrawCallback", [](const cv::String & winname,cv::OpenGlDrawCallback  onOpenGlDraw) {
    return cv::setOpenGlDrawCallback( winname,onOpenGlDraw );
  });
  mod.method("setOpenGlDrawCallback", [](const cv::String & winname,cv::OpenGlDrawCallback  onOpenGlDraw,void * userdata) {
    return cv::setOpenGlDrawCallback( winname,onOpenGlDraw,userdata );
  });
  mod.method("setOpenGlContext", [](const cv::String & winname) {
    return cv::setOpenGlContext( winname );
  });
  mod.method("updateWindow", [](const cv::String & winname) {
    return cv::updateWindow( winname );
  });
  mod.add_type<cv::QtFont>("QtFont")
    .method("nameFont",[](const cv::QtFont &instance){return instance.nameFont;})
    .method("color",[](const cv::QtFont &instance){return instance.color;})
    .method("font_face",[](const cv::QtFont &instance){return instance.font_face;})
    .method("ascii",[](const cv::QtFont &instance){return instance.ascii;})
    .method("greek",[](const cv::QtFont &instance){return instance.greek;})
    .method("cyrillic",[](const cv::QtFont &instance){return instance.cyrillic;})
    .method("hscale",[](const cv::QtFont &instance){return instance.hscale;})
    .method("vscale",[](const cv::QtFont &instance){return instance.vscale;})
    .method("shear",[](const cv::QtFont &instance){return instance.shear;})
    .method("thickness",[](const cv::QtFont &instance){return instance.thickness;})
    .method("dx",[](const cv::QtFont &instance){return instance.dx;})
    .method("line_type",[](const cv::QtFont &instance){return instance.line_type;});
  mod.method("fontQt", [](const cv::String & nameFont) {
    return cv::fontQt( nameFont );
  });
  mod.method("fontQt", [](const cv::String & nameFont,int  pointSize) {
    return cv::fontQt( nameFont,pointSize );
  });
  mod.method("fontQt", [](const cv::String & nameFont,int  pointSize,cv::Scalar  color) {
    return cv::fontQt( nameFont,pointSize,color );
  });
  mod.method("fontQt", [](const cv::String & nameFont,int  pointSize,cv::Scalar  color,int  weight) {
    return cv::fontQt( nameFont,pointSize,color,weight );
  });
  mod.method("fontQt", [](const cv::String & nameFont,int  pointSize,cv::Scalar  color,int  weight,int  style) {
    return cv::fontQt( nameFont,pointSize,color,weight,style );
  });
  mod.method("fontQt", [](const cv::String & nameFont,int  pointSize,cv::Scalar  color,int  weight,int  style,int  spacing) {
    return cv::fontQt( nameFont,pointSize,color,weight,style,spacing );
  });
  mod.method("addText", [](const cv::Mat & img,const cv::String & text,cv::Point  org,const cv::QtFont & font) {
    return cv::addText( img,text,org,font );
  });
  mod.method("addText", [](const cv::Mat & img,const cv::String & text,cv::Point  org,const cv::String & nameFont) {
    return cv::addText( img,text,org,nameFont );
  });
  mod.method("addText", [](const cv::Mat & img,const cv::String & text,cv::Point  org,const cv::String & nameFont,int  pointSize) {
    return cv::addText( img,text,org,nameFont,pointSize );
  });
  mod.method("addText", [](const cv::Mat & img,const cv::String & text,cv::Point  org,const cv::String & nameFont,int  pointSize,cv::Scalar  color) {
    return cv::addText( img,text,org,nameFont,pointSize,color );
  });
  mod.method("addText", [](const cv::Mat & img,const cv::String & text,cv::Point  org,const cv::String & nameFont,int  pointSize,cv::Scalar  color,int  weight) {
    return cv::addText( img,text,org,nameFont,pointSize,color,weight );
  });
  mod.method("addText", [](const cv::Mat & img,const cv::String & text,cv::Point  org,const cv::String & nameFont,int  pointSize,cv::Scalar  color,int  weight,int  style) {
    return cv::addText( img,text,org,nameFont,pointSize,color,weight,style );
  });
  mod.method("addText", [](const cv::Mat & img,const cv::String & text,cv::Point  org,const cv::String & nameFont,int  pointSize,cv::Scalar  color,int  weight,int  style,int  spacing) {
    return cv::addText( img,text,org,nameFont,pointSize,color,weight,style,spacing );
  });
  mod.method("displayOverlay", [](const cv::String & winname,const cv::String & text) {
    return cv::displayOverlay( winname,text );
  });
  mod.method("displayOverlay", [](const cv::String & winname,const cv::String & text,int  delayms) {
    return cv::displayOverlay( winname,text,delayms );
  });
  mod.method("displayStatusBar", [](const cv::String & winname,const cv::String & text) {
    return cv::displayStatusBar( winname,text );
  });
  mod.method("displayStatusBar", [](const cv::String & winname,const cv::String & text,int  delayms) {
    return cv::displayStatusBar( winname,text,delayms );
  });
  mod.method("saveWindowParameters", [](const cv::String & windowName) {
    return cv::saveWindowParameters( windowName );
  });
  mod.method("loadWindowParameters", [](const cv::String & windowName) {
    return cv::loadWindowParameters( windowName );
  });
  mod.method("startLoop", [](int * pt2Func,int  argc,char * argv) {
    return cv::startLoop( pt2Func,argc,argv );
  });
  mod.method("stopLoop", []() {
    return cv::stopLoop(  );
  });
  mod.method("createButton", [](const cv::String & bar_name,cv::ButtonCallback  on_change) {
    return cv::createButton( bar_name,on_change );
  });
  mod.method("createButton", [](const cv::String & bar_name,cv::ButtonCallback  on_change,void * userdata) {
    return cv::createButton( bar_name,on_change,userdata );
  });
  mod.method("createButton", [](const cv::String & bar_name,cv::ButtonCallback  on_change,void * userdata,int  type) {
    return cv::createButton( bar_name,on_change,userdata,type );
  });
  mod.method("createButton", [](const cv::String & bar_name,cv::ButtonCallback  on_change,void * userdata,int  type,bool  initial_button_state) {
    return cv::createButton( bar_name,on_change,userdata,type,initial_button_state );
  });
}
