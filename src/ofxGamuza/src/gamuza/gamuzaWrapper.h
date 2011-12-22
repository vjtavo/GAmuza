/*
 * Extending ofxLuaWrapper for GAmuza
 *
 * ORIGINAL FILE FROM:
 * Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxLua for documentation
 *
 * This project uses the following libraries:
 *
 * Lua, Copyright (c) 1994–2011 Lua.org, PUC-Rio using the MIT License.
 * See the file "COPYRIGHT" in src/lua.
 * See http://www.lua.org/docs.html for documentation
 *
 * Luabind, Copyright (c) 2003 Daniel Wallin and Arvid Norberg using the
 * MIT License. See the file "LICENSE" in src/luabind.
 * See http://www.rasterbar.com/products/luabind/docs.html for documentation
 *
 */
#pragma once

#include "ofMain.h"
#include "ofxLua.h"

#include "gamuzaGetters.h"
#include "gamuzaIncludes.h"

class ofGamuzaWrapper{
	
	public:
	
	/// static function called when binding
	static void bind(ofxLua& lua) {
		
		using namespace luabind;
		
		/// OpenFrameworks api wrapper
		///
		module(lua, "of")
		[
		 ///////////////////////////////
		 /// \section Graphics
		 
		 /// openGL wrappers
		 def("pushMatrix", &ofPushMatrix),
		 def("popMatrix", &ofPopMatrix),
		 def("translate", (void(*)(float,float,float)) &ofTranslate),
		 def("scale", &ofScale),
		 def("rotate", (void(*)(float,float,float,float)) &ofRotate),
		 def("rotateX", &ofRotateX),
		 def("rotateY", &ofRotateY),
		 def("rotateZ", &ofRotateZ),
		 def("rotate", (void(*)(float)) &ofRotate),
		 
		 /// drawing modes
		 def("setCircleResolution", &ofSetCircleResolution),
		 def("setCurveResolution", &ofSetCurveResolution),
		 
		 /// drawing options
		 def("noFill", &ofNoFill),
		 def("fill", &ofFill),
		 def("setLineWidth", &ofSetLineWidth),
		 
		 /// color options
		 def("setColor", (void(*)(int)) &ofSetColor),
		 def("setColor", (void(*)(int,int,int)) &ofSetColor),
		 def("setColor", (void(*)(int,int,int,int)) &ofSetColor),
		 def("setHexColor", (void(*)(int)) &ofSetHexColor),
		 
		 /// transparency
		 def("enableAlphaBlending", &ofEnableAlphaBlending),
		 def("disableAlphaBlending", &ofDisableAlphaBlending),
		 
		 /// smooth
		 def("enableSmoothing", &ofEnableSmoothing),
		 def("disableSmoothing", &ofDisableSmoothing),
		 
		 /// drawing style
		 def("setPolyMode", &ofSetPolyMode),
		 
		 /// background
		 def("background",	(void(*)(int)) &background),
		 def("background",	(void(*)(int,int)) &ofBackground),
		 def("background",	(void(*)(int,int,int)) &background),
		 def("background",	(void(*)(int,int,int,int)) &ofBackground),
		 //def("setBackgroundAuto",	(void(*)(bool)) &ofSetBackgroundAuto),
		 def("clear",		(void(*)(float,float,float,float)) &ofClear),
		 def("clearAlpha",	&ofClearAlpha),
		 
		 /// geometry
		 def("line", 	(void(*)(float,float,float,float)) &ofLine),
		 def("rect", 	(void(*)(float,float,float,float)) &ofRect),
		 def("triangle",	(void(*)(float,float,float,float,float,float)) &ofTriangle),
		 def("circle", 	(void(*)(float,float,float)) &ofCircle),
		 def("ellipse",	(void(*)(float,float,float,float)) &ofEllipse),
		 def("curve", 	(void(*)(float,float,float,float,float,float,float,float)) &ofCurve),
		 def("bezier",	(void(*)(float,float,float,float,float,float,float,float)) &ofBezier),
		 
		 /// polygons
		 def("beginShape", &ofBeginShape),
		 def("vertex",	(void(*)(float,float)) &ofVertex),
		 def("curveVertex", (void(*)(float,float)) &ofCurveVertex),
		 def("bezierVertex", (void(*)(float,float,float,float,float,float)) &ofBezierVertex),
		 def("endShape",	&ofEndShape),
		 def("nextContour", &ofNextContour),
		 
		 /// bitmapped text
		 def("drawBitmapString", (void(*)(string,float,float)) &ofDrawBitmapString),
		 
		 ///////////////////////////////
		 /// \section PolyLine
		 
		 class_<ofPolyline>("polyline")
		 .def(constructor<>())
         .def("clear", (void(ofPolyline::*)(void)) &ofPolyline::clear)
         .def("addVertex", (void(ofPolyline::*)(float,float,float)) &ofPolyline::addVertex) // float x, float y, float z
         .def("lineTo", (void(ofPolyline::*)(float,float,float)) &ofPolyline::lineTo) // float x, float y, float z
         .def("arc", (void(ofPolyline::*)(float,float,float,float,float,float,float,int)) &ofPolyline::arc) // float x, float y, float z, float radiusX, float radiusY, float angleBegin, float angleEnd, int curveResolution
         .def("curveTo", (void(ofPolyline::*)(float,float,float,int)) &ofPolyline::curveTo) // float x, float y, float z, int curveResolution
         .def("bezierTo", (void(ofPolyline::*)(float,float,float,float,float,float,float,float,float,int)) &ofPolyline::bezierTo) // float cx1, float cy1, float cz1, float cx2, float cy2, float cz2, float x, float y, float z, int curveResolution
         .def("quadBezierTo", (void(ofPolyline::*)(float,float,float,float,float,float,float,float,float,int)) &ofPolyline::quadBezierTo) // float cx1, float cy1, float cz1, float cx2, float cy2, float cz2, float x, float y, float z, int curveResolution
         .def("getSmoothed", (ofPolyline(ofPolyline::*)(int)) &ofPolyline::getSmoothed) // int smoothingSize
         .def("getResampledBySpacing", (ofPolyline(ofPolyline::*)(float)) &ofPolyline::getResampledBySpacing) // float spacing
         .def("getResampledByCount", (ofPolyline(ofPolyline::*)(int)) &ofPolyline::getResampledByCount) // int count
         .def("getBoundingBox", (ofRectangle(ofPolyline::*)(void)) &ofPolyline::getBoundingBox)
         .def("simplify", (void(ofPolyline::*)(float)) &ofPolyline::simplify)
         .def("close", (void(ofPolyline::*)(void)) &ofPolyline::close)
         .def("getPerimeter", (float(ofPolyline::*)(void)) &ofPolyline::getPerimeter)
         .def("draw", (void(ofPolyline::*)(void)) &ofPolyline::draw)
		 .enum_("windingMode")
		 [	
		  value("WINDING_ODD", OF_POLY_WINDING_ODD),
		  value("WINDING_NONZERO", OF_POLY_WINDING_NONZERO),
		  value("WINDING_POSITIVE", OF_POLY_WINDING_POSITIVE),
		  value("WINDING_NEGATIVE", OF_POLY_WINDING_NEGATIVE),
		  value("WINDING_ABS_GEQ_TWO", OF_POLY_WINDING_ABS_GEQ_TWO)
		  ],
		 
		 ///////////////////////////////
		 /// \section Rectangle
		 
		 class_<ofRectangle>("rectangle")
		 .def(constructor<>())
		 .def(constructor<const ofRectangle&>())
		 .def(constructor<float,float,float,float>())
		 .def("set", (void(ofRectangle::*)(float,float,float,float)) &ofRectangle::set)
		 .def("set", (void(ofRectangle::*)(const ofRectangle&)) &ofRectangle::set)
		 .def("setFromCenter", (void(ofRectangle::*)(float,float,float,float)) &ofRectangle::setFromCenter)
		 .def("inside", (bool(ofRectangle::*)(float,float)) &ofRectangle::inside)
		 .def_readonly("x", &ofRectangle::x)
		 .def_readonly("y", &ofRectangle::y)
		 .def_readonly("width", &ofRectangle::width)
		 .def_readonly("height", &ofRectangle::height),
		 
		 ///////////////////////////////
		 /// \section Color
		 
		 class_<ofColor>("color")
		 .def(constructor<>())
		 .def(constructor<float,float,float,float>())
		 .def(constructor<float,float>())
		 .def("set", (void(ofColor::*)(float,float,float,float)) &ofColor::set)
		 .def("set", (void(ofColor::*)(float,float)) &ofColor::set)
		 .def("setHex", &ofColor::setHex)
		 .def("getHex", &ofColor::getHex)
         .def("getClamped", (ofColor(ofColor::*)(void)) &ofColor::getClamped)
         .def("getInverted", (ofColor(ofColor::*)(void)) &ofColor::getInverted)
         .def("getNormalized", (ofColor(ofColor::*)(void)) &ofColor::getNormalized)
         .def("getLerped", (ofColor(ofColor::*)(const ofColor&, float)) &ofColor::getLerped)
		 .def("getHue", &ofColor::getHue)
		 .def("getSaturation", &ofColor::getSaturation)
		 .def("getBrightness", &ofColor::getBrightness)
		 .def("getLightness", &ofColor::getLightness)
		 .def("setHue", &ofColor::setHue)
		 .def("setSaturation", &ofColor::setSaturation)
		 .def("setBrightness", &ofColor::setBrightness)
         .def("setHsb", (void(ofColor::*)(float,float,float,float)) &ofColor::setHsb)
         .def("setHsb", (void(ofColor::*)(float,float,float)) &ofColor::setHsb)
         .def_readonly("r", &ofColor::r)
		 .def_readonly("g", &ofColor::g)
		 .def_readonly("b", &ofColor::b)
		 .def_readonly("a", &ofColor::a),
		 
		 ///////////////////////////////
		 /// \section Pixels
		 
		 class_<ofPixels>("pixels")
		 .def(constructor<>())
		 .def("allocate", (void(ofPixels::*)(int,int,int)) &ofPixels::allocate)
		 .def("allocate", (void(ofPixels::*)(int,int,ofPixelFormat)) &ofPixels::allocate)
		 .def("allocate", (void(ofPixels::*)(int,int,ofImageType)) &ofPixels::allocate)
		 .def("set", (void(ofPixels::*)(unsigned char)) &ofPixels::set)
		 .def("set", (void(ofPixels::*)(int,unsigned char)) &ofPixels::set)
         .def("crop", (void(ofPixels::*)(int,int,int,int)) &ofPixels::crop)
         .def("rotate90", &ofPixels::rotate90)
         .def("mirror", &ofPixels::mirror)
         .def("resize", (void(ofPixels::*)(int,int)) &ofPixels::resize)
		 .def("swapRgb", &ofPixels::swapRgb)
		 .def("clear", &ofPixels::clear)
         .def("getPixel", getPixel)
         .def("setPixel", setPixel)
         .def("getPixelIndex", &ofPixels::getPixelIndex)
		 .def("getColor", &ofPixels::getColor)
		 .def("setColor", &ofPixels::setColor)
		 .def("isAllocated", &ofPixels::isAllocated)
		 .def("getWidth", &ofPixels::getWidth)
		 .def("getHeight", &ofPixels::getHeight)
         .def("getBytesPerPixel", &ofPixels::getBytesPerPixel)
         .def("getBitsPerPixel", &ofPixels::getBitsPerPixel)
         .def("getBytesPerChannel", &ofPixels::getBytesPerChannel)
         .def("getBitsPerChannel", &ofPixels::getBitsPerChannel)
         .def("getNumChannels", &ofPixels::getNumChannels)
		 .def("getImageType", &ofPixels::getImageType)
		 .def("size", &ofPixels::size)
		 .enum_("format")
		 [
		  value("MONO", OF_PIXELS_MONO),
		  value("RGB", OF_PIXELS_RGB),
		  value("RGBA", OF_PIXELS_RGBA),
		  value("BGRA", OF_PIXELS_BGRA),
		  value("RGB565", OF_PIXELS_RGB565)
		  ],
		 
		 ///////////////////////////////
		 /// \section Texture
		 
		 class_<ofTexture>("texture")
		 .def(constructor<>())
		 .def("allocate", (void(ofTexture::*)(int,int,int)) &ofTexture::allocate)
		 .def("clear", (void(ofTexture::*)(void)) &ofTexture::clear)
		 .def("loadData", (void(ofTexture::*)(float*,int,int,int)) &ofTexture::loadData)
		 .def("loadData", (void(ofTexture::*)(unsigned char*,int,int,int)) &ofTexture::loadData)
		 .def("loadData", (void(ofTexture::*)(unsigned short*,int,int,int)) &ofTexture::loadData)
		 .def("loadData", (void(ofTexture::*)(ofPixels&)) &ofTexture::loadData)
         .def("loadScreenData", (void(ofTexture::*)(int,int,int,int)) &ofTexture::loadScreenData)
		 .def("setAnchorPercent", (void(ofTexture::*)(float,float)) &ofTexture::setAnchorPercent)
		 .def("setAnchorPoint", (void(ofTexture::*)(float,float)) &ofTexture::setAnchorPoint)
		 .def("resetAnchor", (void(ofTexture::*)(void)) &ofTexture::resetAnchor)
         .def("readToPixels", (void(ofTexture::*)(ofPixels&)) &ofTexture::readToPixels)
		 .def("draw", (void(ofTexture::*)(const ofRectangle&)) &ofTexture::draw)
		 .def("draw", (void(ofTexture::*)(const ofPoint&)) &ofTexture::draw)
		 .def("draw", (void(ofTexture::*)(const ofPoint&, float, float)) &ofTexture::draw)
		 .def("draw", (void(ofTexture::*)(float,float)) &ofTexture::draw)
		 .def("draw", (void(ofTexture::*)(float,float,float)) &ofTexture::draw)
		 .def("draw", (void(ofTexture::*)(float,float,float,float)) &ofTexture::draw)
		 .def("draw", (void(ofTexture::*)(float,float,float,float,float)) &ofTexture::draw)
		 .def("draw", (void(ofTexture::*)(ofPoint,ofPoint,ofPoint,ofPoint)) &ofTexture::draw)
		 .def("getWidth", &ofTexture::getWidth)
		 .def("getHeight", &ofTexture::getHeight)
		 .enum_("internalFormat")
		 [
		  value("GL_RGB5", GL_RGB5),
		  value("GL_RGB8", GL_RGB8),
		  value("GL_RGBA4", GL_RGBA4),
		  value("GL_RGBA8", GL_RGBA8)
		  ],
         
         ///////////////////////////////
		 /// \section FBO
         
         class_<ofFbo>("fbo")
		 .def(constructor<>())
		 .def("allocate", (void(ofFbo::*)(int,int,int,int)) &ofFbo::allocate) // int width, int height, int internalformat, int numSamples
         .def("draw", (void(ofFbo::*)(float,float)) &ofFbo::draw)
         .def("draw", (void(ofFbo::*)(float,float,float,float)) &ofFbo::draw)
         .def("beginFbo", &ofFbo::begin)
		 .def("endFbo", &ofFbo::end)
         .def("setAnchorPoint", &ofFbo::setAnchorPoint)
         .def("resetAnchor", &ofFbo::resetAnchor)
         .def("getWidth", &ofFbo::getWidth)
		 .def("getHeight", &ofFbo::getHeight)
         .def("bind", &ofFbo::bind)
		 .def("unbind", &ofFbo::unbind),
         
         ///////////////////////////////
		 /// \section SHADER
		 class_<ofShader>("shader")
		 .def(constructor<>())
         .def("load", (bool(ofShader::*)(string)) &ofShader::load)
         .def("load", (bool(ofShader::*)(string,string,string)) &ofShader::load)
         .def("beginShader", (void(ofShader::*)(void)) &ofShader::begin)
         .def("endShader", (void(ofShader::*)(void)) &ofShader::end)
         .def("setUniformTexture", (void(ofShader::*)(const char*,ofBaseHasTexture&,int)) &ofShader::setUniformTexture)
         .def("setUniformTexture", (void(ofShader::*)(const char*,ofTexture&,int)) &ofShader::setUniformTexture)
         .def("setUniform1i", (void(ofShader::*)(const char*,int)) &ofShader::setUniform1i)
         .def("setUniform2i", (void(ofShader::*)(const char*,int,int)) &ofShader::setUniform2i)
         .def("setUniform3i", (void(ofShader::*)(const char*,int,int,int)) &ofShader::setUniform3i)
         .def("setUniform4i", (void(ofShader::*)(const char*,int,int,int,int)) &ofShader::setUniform4i)
         .def("setUniform1f", (void(ofShader::*)(const char*,float)) &ofShader::setUniform1f)
         .def("setUniform2f", (void(ofShader::*)(const char*,float,float)) &ofShader::setUniform2f)
         .def("setUniform3f", (void(ofShader::*)(const char*,float,float,float)) &ofShader::setUniform3f)
         .def("setUniform4f", (void(ofShader::*)(const char*,float,float,float,float)) &ofShader::setUniform4f)
         .def("unload", (void(ofShader::*)(void)) &ofShader::unload),
         
		 ///////////////////////////////
		 /// \section Image
		 
		 class_<ofImage>("image")
		 .def(constructor<>())
		 .def(constructor<const string&>())
		 .def("allocate", &ofImage::allocate)
		 .def("clear", &ofImage::clear)
		 .def("loadImage", (bool(ofImage::*)(string)) &ofImage::loadImage)
		 .def("getPixels", &ofImage::getPixelsRef)
		 .def("setImageType", &ofImage::setImageType)
		 .def("getColor", &ofImage::getColor)
		 .def("setColor", &ofImage::setColor)
		 .def("resize", &ofImage::resize)
		 .def("mirror", &ofImage::mirror)
		 .def("update", &ofImage::update)
		 .def("draw", (void(ofImage::*)(float,float)) &ofImage::draw)
		 .def("draw", (void(ofImage::*)(float,float,float,float)) &ofImage::draw)
		 .def("getHeight", &ofImage::getHeight)
		 .def("getWidth", &ofImage::getWidth)
		 .def("allocated", &ofImage::bAllocated)
		 .def_readonly("width", &ofImage::width)
		 .def_readonly("height", &ofImage::height)
		 .def_readonly("bpp", &ofImage::bpp)
		 .enum_("imageType")
		 [
		  value("GRAYSCALE", OF_IMAGE_GRAYSCALE),
		  value("COLOR", OF_IMAGE_COLOR),
		  value("COLOR_ALPHA", OF_IMAGE_COLOR_ALPHA),
		  value("UNDEFINED", OF_IMAGE_UNDEFINED)
		  ],
		 
		 ///////////////////////////////
		 /// \section VideoPlayer
		 
		 class_<ofVideoPlayer>("videoPlayer")
		 .def(constructor<>())
		 .def("loadMovie", (bool(ofVideoPlayer::*)(string)) &ofVideoPlayer::loadMovie)
		 .def("closeMovie", (void(ofVideoPlayer::*)(void)) &ofVideoPlayer::closeMovie)
		 .def("close", (void(ofVideoPlayer::*)(void)) &ofVideoPlayer::close)
		 .def("update", (void(ofVideoPlayer::*)(void)) &ofVideoPlayer::update)
		 .def("idleMovie", (void(ofVideoPlayer::*)(void)) &ofVideoPlayer::idleMovie)
		 .def("play", (void(ofVideoPlayer::*)(void)) &ofVideoPlayer::play)
		 .def("stop", (void(ofVideoPlayer::*)(void)) &ofVideoPlayer::stop)
		 .def("isFrameNew", &ofVideoPlayer::isFrameNew)
		 .def("getPixels", (unsigned char*(ofVideoPlayer::*)(void)) &ofVideoPlayer::getPixels)
		 .def("getPosition", &ofVideoPlayer::getPosition)
		 .def("getSpeed", &ofVideoPlayer::getSpeed)
		 .def("getDuration", &ofVideoPlayer::getDuration)
		 .def("getIsMovieDone", &ofVideoPlayer::getIsMovieDone)
		 .def("setPosition", (void(ofVideoPlayer::*)(float)) &ofVideoPlayer::setPosition)
		 .def("setVolume", (void(ofVideoPlayer::*)(int)) &ofVideoPlayer::setVolume)
		 .def("setLoopState", &ofVideoPlayer::setLoopState)
		 .def("getLoopState", &ofVideoPlayer::getLoopState)
		 .def("setSpeed", (void(ofVideoPlayer::*)(float)) &ofVideoPlayer::setSpeed)
		 .def("setFrame", (void(ofVideoPlayer::*)(int)) &ofVideoPlayer::setFrame)
		 .def("setUseTexture", &ofVideoPlayer::setUseTexture)
		 .def("getTextureReference", &ofVideoPlayer::getTextureReference)
		 .def("draw", (void(ofVideoPlayer::*)(float,float)) &ofVideoPlayer::draw)
		 .def("draw", (void(ofVideoPlayer::*)(float,float,float,float)) &ofVideoPlayer::draw)
		 .def("draw", (void(ofVideoPlayer::*)(const ofPoint&)) &ofVideoPlayer::draw)
		 .def("draw", (void(ofVideoPlayer::*)(const ofRectangle&)) &ofVideoPlayer::draw)
		 .def("setAnchorPercent", (void(ofVideoPlayer::*)(float,float)) &ofVideoPlayer::setAnchorPercent)
		 .def("setAnchorPoint", (void(ofVideoPlayer::*)(float,float)) &ofVideoPlayer::setAnchorPoint)
		 .def("resetAnchor", &ofVideoPlayer::resetAnchor)
		 .def("setPaused", (void(ofVideoPlayer::*)(bool)) &ofVideoPlayer::setPaused)
		 .def("getCurrentFrame", &ofVideoPlayer::getCurrentFrame)
		 .def("getTotalNumFrames", &ofVideoPlayer::getTotalNumFrames)
		 .def("firstFrame", &ofVideoPlayer::firstFrame)
		 .def("nextFrame", &ofVideoPlayer::nextFrame)
		 .def("previousFrame", &ofVideoPlayer::previousFrame)
		 .def("getHeight", &ofVideoPlayer::getHeight)
		 .def("getWidth", &ofVideoPlayer::getWidth)
		 .def("isPaused", &ofVideoPlayer::isPaused)
		 .def("isLoaded", &ofVideoPlayer::isLoaded)
		 .def("isPlaying", &ofVideoPlayer::isPlaying)
		 .def_readonly("width", &ofVideoPlayer::width)
		 .def_readonly("height", &ofVideoPlayer::height)
		 .enum_("loopType")
		 [
		  value("NONE", OF_LOOP_NONE),
		  value("PALINDROME", OF_LOOP_PALINDROME),
		  value("NORMAL", OF_LOOP_NORMAL)
		  ],
		 
		 ///////////////////////////////
		 /// \section Font
		 
		 class_<ofTrueTypeFont>("font")
		 .def(constructor<>())
		 .def("loadFont", &loadFont2)
		 .def("loadFont", &loadFont4)
		 .def("loadFont", (void(ofTrueTypeFont::*)(string,int,bool,bool,bool,float)) &ofTrueTypeFont::loadFont)
		 .def("isLoaded", &ofTrueTypeFont::isLoaded)
		 .def("getLineHeight", &ofTrueTypeFont::getLineHeight)
		 .def("setLineHeight", &ofTrueTypeFont::setLineHeight)
		 .def("getLetterSpacing", &ofTrueTypeFont::getLetterSpacing)
		 .def("setLetterSpacing", &ofTrueTypeFont::setLetterSpacing)
		 .def("getSpaceSize", &ofTrueTypeFont::getSpaceSize)
		 .def("setSpaceSize", &ofTrueTypeFont::setSpaceSize)
		 .def("stringWidth", &ofTrueTypeFont::stringWidth)
		 .def("stringHeight", &ofTrueTypeFont::stringHeight)
		 .def("getStringBoundingBox", &ofTrueTypeFont::getStringBoundingBox)
		 .def("drawString", &ofTrueTypeFont::drawString)
		 .def("drawStringAsShapes", &ofTrueTypeFont::drawStringAsShapes),
		 
		 ///////////////////////////////
		 /// \section Sound Player
		 
		 class_<ofSoundPlayer>("soundPlayer")
		 .def(constructor<>())
		 .def("loadSound", (void(ofSoundPlayer::*)(string,bool)) &ofSoundPlayer::loadSound)
		 .def("unloadSound", (void(ofSoundPlayer::*)(void)) &ofSoundPlayer::unloadSound)
		 .def("play", (void(ofSoundPlayer::*)(void)) &ofSoundPlayer::play)
		 .def("stop", (void(ofSoundPlayer::*)(void)) &ofSoundPlayer::stop)
		 .def("setVolume", (void(ofSoundPlayer::*)(float)) &ofSoundPlayer::setVolume)
		 .def("setPan", (void(ofSoundPlayer::*)(float)) &ofSoundPlayer::setPan)
		 .def("setSpeed", (void(ofSoundPlayer::*)(float)) &ofSoundPlayer::setSpeed)
		 .def("setPaused", (void(ofSoundPlayer::*)(bool)) &ofSoundPlayer::setPaused)
		 .def("setLoop", (void(ofSoundPlayer::*)(bool)) &ofSoundPlayer::setLoop)
		 .def("setMultiPlay", (void(ofSoundPlayer::*)(bool)) &ofSoundPlayer::setMultiPlay)
		 .def("setPosition", (void(ofSoundPlayer::*)(float)) &ofSoundPlayer::setPosition)
		 .def("getPosition", (float(ofSoundPlayer::*)(void)) &ofSoundPlayer::getPosition)
		 .def("getIsPlaying", (bool(ofSoundPlayer::*)(void)) &ofSoundPlayer::getIsPlaying)
		 .def("getSpeed", (float(ofSoundPlayer::*)(void)) &ofSoundPlayer::getSpeed)
		 .def("getPan", (float(ofSoundPlayer::*)(void)) &ofSoundPlayer::getPan),
         
         ///////////////////////////////
		 /// \section Camera
         
         class_<ofCamera>("camera")
		 .def(constructor<>())
		 .def("setFov", (void(ofCamera::*)(float)) &ofCamera::setFov)
         .def("setNearClip", (void(ofCamera::*)(float)) &ofCamera::setNearClip)
		 .def("setFarClip", (void(ofCamera::*)(float)) &ofCamera::setFarClip)
         .def("enableOrtho", (void(ofCamera::*)(void)) &ofCamera::enableOrtho)
         .def("disableOrtho", (void(ofCamera::*)(void)) &ofCamera::disableOrtho)
         .def("getOrtho", (bool(ofCamera::*)(void)) &ofCamera::getOrtho)
         .def("setPosition", (void(ofCamera::*)(float,float,float)) &ofCamera::setPosition)
         .def("setPosition", (void(ofCamera::*)(const ofVec3f&)) &ofCamera::setPosition)
         .def("setScale", (void(ofCamera::*)(float)) &ofCamera::setScale)
         .def("setScale", (void(ofCamera::*)(float,float,float)) &ofCamera::setScale)
         .def("setScale", (void(ofCamera::*)(const ofVec3f&)) &ofCamera::setScale)
         .def("move", (void(ofCamera::*)(float,float,float)) &ofCamera::move)
         .def("move", (void(ofCamera::*)(const ofVec3f&)) &ofCamera::move)
         .def("truck", (void(ofCamera::*)(float)) &ofCamera::truck)
         .def("boom", (void(ofCamera::*)(float)) &ofCamera::boom)
         .def("dolly", (void(ofCamera::*)(float)) &ofCamera::dolly)
         .def("tilt", (void(ofCamera::*)(float)) &ofCamera::tilt)
         .def("pan", (void(ofCamera::*)(float)) &ofCamera::pan)
         .def("roll", (void(ofCamera::*)(float)) &ofCamera::roll)
         .def("rotate", (void(ofCamera::*)(float,const ofVec3f&)) &ofCamera::rotate)
         .def("rotate", (void(ofCamera::*)(float,float,float,float)) &ofCamera::rotate)
         .def("lookAt", (void(ofCamera::*)(const ofVec3f&,ofVec3f)) &ofCamera::lookAt)
         .def("orbit", (void(ofCamera::*)(float,float,float,const ofVec3f&)) &ofCamera::orbit)
         .def("transformGL", (void(ofCamera::*)(void)) &ofCamera::transformGL)
         .def("restoreTransformGL", (void(ofCamera::*)(void)) &ofCamera::restoreTransformGL)
         .def("resetTransform", (void(ofCamera::*)(void)) &ofCamera::resetTransform)
         .def("draw", (void(ofCamera::*)(void)) &ofCamera::draw)
         .def("getImagePlaneDistance", (float(ofCamera::*)(ofRectangle)) &ofCamera::getImagePlaneDistance)
         .def("cacheMatrices", (void(ofCamera::*)(bool)) &ofCamera::cacheMatrices)
         .def("beginCamera", (void(ofCamera::*)(ofRectangle)) &ofCamera::begin)
         .def("endCamera", (void(ofCamera::*)(void)) &ofCamera::end),
		 
		 ///////////////////////////////
		 /// \section Math
		 
		 def("nextPow2", (int(*)(int)) &ofNextPow2),
		 def("seedRandom", (void(*)(void)) &ofSeedRandom),
		 def("seedRandom", (void(*)(int)) &ofSeedRandom),
		 def("random", (float(*)(float)) &ofRandom),
		 def("random", (float(*)(float,float)) &ofRandom),
		 def("randomf", (float(*)(void)) &ofRandomf),
		 def("randomuf", (float(*)(void)) &ofRandomuf),
		 def("normalize", &ofNormalize),
		 def("map", &ofMap),
		 def("clamp", &ofClamp),
		 def("lerp", &ofLerp),
		 def("dist", &ofDist),
		 def("distSquared", &ofDistSquared),
		 def("sign", &ofSign),
		 def("inRange", &ofInRange),
		 def("radToDeg", &ofRadToDeg),
		 def("degToRad", &ofDegToRad),
		 def("lerpDegrees", &ofLerpDegrees),
		 def("lerpRadians", &ofLerpRadians),
		 def("angleDifferenceDegrees", &ofAngleDifferenceDegrees),
		 def("angleDifferenceRadians", &ofAngleDifferenceRadians),
		 def("wrapRadians", &ofWrapRadians),
		 def("wrapDegrees", &ofWrapDegrees),
		 def("noise", (float(*)(float)) &ofNoise),
		 def("noise", (float(*)(float,float)) &ofNoise),
		 def("noise", (float(*)(float,float,float)) &ofNoise),
		 def("noise", (float(*)(float,float,float,float)) &ofNoise),
		 def("signedNoise", (float(*)(float)) &ofSignedNoise),
		 def("signedNoise", (float(*)(float,float)) &ofSignedNoise),
		 def("signedNoise", (float(*)(float,float,float)) &ofSignedNoise),
		 def("signedNoise", (float(*)(float,float,float,float)) &ofSignedNoise),
		 
		 ///////////////////////////////
		 /// \section ofVec
		 
		 class_<ofVec2f>("vec2f")
		 .def(constructor<>())
		 .def(constructor<float,float>())
		 .def(constructor<const ofVec3f&>())
		 .def(constructor<const ofVec4f&>())
		 .def("set", (void(ofVec2f::*)(float,float)) &ofVec2f::set)
		 .def("set", (void(ofVec2f::*)(const ofVec2f&)) &ofVec2f::set),
		 
		 class_<ofVec3f>("vec3f")
		 .def(constructor<>())
		 .def(constructor<float,float,float>())
		 .def(constructor<const ofVec2f&>())
		 .def(constructor<const ofVec4f&>())
		 .def("set", (void(ofVec3f::*)(float,float,float)) &ofVec3f::set)
		 .def("set", (void(ofVec3f::*)(const ofVec3f&)) &ofVec3f::set),
		 
		 class_<ofVec4f>("vec4f")
		 .def(constructor<>())
		 .def(constructor<float,float,float,float>())
		 .def(constructor<const ofVec2f&>())
		 .def(constructor<const ofVec3f&>())
		 .def("set", (void(ofVec4f::*)(float,float,float,float)) &ofVec4f::set)
		 .def("set", (void(ofVec4f::*)(const ofVec4f&)) &ofVec4f::set),
		 
		 ///////////////////////////////
		 /// \section App
		 
		 /// input properties
		 def("mouseX", &getMouseX), // of.mouseX()
		 def("mouseY", &getMouseY), // of.mouseY()
		 
		 /// time
		 def("getFrameRate", &ofGetFrameRate),
		 def("getFrameNum", &ofGetFrameNum),
		 def("setFrameRate", &ofSetFrameRate),
		 def("sleepMillis", &ofSleepMillis),
		 def("getLastFrameTime", &ofGetLastFrameTime),
		 
		 /// cursor
		 // def("hideCursor", &ofHideCursor),
		 // def("showCursor", &ofShowCursor),
		 
		 /// window / screen
		 def("getWindowPositionX", &ofGetWindowPositionX),
		 def("getWindowPositionY", &ofGetWindowPositionY),
		 def("getScreenWidth", &ofGetScreenWidth),
		 def("getScreenHeight", &ofGetScreenHeight),
		 def("getWindowMode", &ofGetWindowMode),
		 def("getWidth", &ofGetWidth),
		 def("getHeight", &ofGetHeight),
		 def("getWindowWidth", &ofGetWindowWidth),
		 def("getWindowHeight", &ofGetWindowHeight),
         
         /// 3D
         def("getCurrentViewport", &ofGetCurrentViewport),
		 
		 ///////////////////////////////
		 /// \section Utils
		 
		 def("resetElapsedTimeCounter", &ofResetElapsedTimeCounter),
		 def("getElapsedTimef", &ofGetElapsedTimef),
		 def("getElapsedTimeMillis", &ofGetElapsedTimeMillis),
		 def("getElapsedTimeMicros", &ofGetElapsedTimeMicros),
		 def("getFrameNum", &ofGetFrameNum),
		 
		 def("getSeconds", &ofGetSeconds),
		 def("getMinutes", &ofGetMinutes),
		 def("getHours", &ofGetHours),
		 
		 def("getUnixTime", &ofGetUnixTime),
		 def("getSystemTime", &ofGetSystemTime),
		 def("getSystemTimeMicros", &ofGetSystemTimeMicros),
		 
		 def("getTimestampString", (string(*)(void)) &ofGetTimestampString),
		 def("getTimestampString", (string(*)(string)) &ofGetTimestampString),
		 
		 def("getYear", &ofGetYear),
		 def("getMonth", &ofGetMonth),
		 def("getDay", &ofGetDay),
		 def("getWeekday", &ofGetWeekday),
		 
		 def("toInt", (int(*)(const string&)) &ofToInt),
		 def("toChar", (char(*)(const string&)) &ofToChar),
		 def("toFloat", (float(*)(const string&)) &ofToFloat),
		 def("toBool", (bool(*)(const string&)) &ofToBool),
		 
		 def("toBinary", (string(*)(const string&)) &ofToBinary),
		 def("toBinary", (string(*)(const char*)) &ofToBinary),
		 
		 def("binaryToInt", (int(*)(const string&)) &ofBinaryToInt),
		 def("binaryToChar", (char(*)(const string&)) &ofBinaryToChar),
		 def("binaryToFloat", (float(*)(const string&)) &ofBinaryToFloat),
		 def("binaryToString", (string(*)(const string&)) &ofBinaryToString),
		 
		 def("splitString", (vector<string>(*)(const string&, const string&, bool)) &ofSplitString),
		 def("joinString", (string(*)(vector<string>, const string&)) &ofJoinString),
		 def("stringReplace", (void(*)(string&, string, string)) &ofStringReplace),
		 def("isStringInString", (bool(*)(string, string)) &ofIsStringInString),
		 
		 def("launchBrowser", &ofLaunchBrowser)
		];
        
        //////////////////////////////////////////////////////////////
		///////////////////////////////
		/// OF experimental addons api wrapper
		module(lua, "ofx")
		[
         
         ///////////////////////////////
         // OFXBULLET ---------------------------------------->>>>>>>>>>>>>>>>>>>>>>>>>>>>(UNSTABLE)
         class_<ofxBulletWorldRigid>("bulletWorldRigid")
         .def(constructor<>())
         .def("setup", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::setup)
         .def("update", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::update)
         .def("setCameraPosition", (void(ofxBulletWorldRigid::*)(ofVec3f)) &ofxBulletWorldRigid::setCameraPosition)
         .def("setCamera", (void(ofxBulletWorldRigid::*)(ofCamera)) &ofxBulletWorldRigid::setCamera)
         .def("enableCollisionEvents", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::enableCollisionEvents)
         .def("disableCollisionEvents", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::disableCollisionEvents)
         .def("checkCollisions", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::checkCollisions)
         .def("enableMousePickingEvents", (void(ofxBulletWorldRigid::*)(short int)) &ofxBulletWorldRigid::enableMousePickingEvents)
         .def("disableMousePickingEvents", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::disableMousePickingEvents)
         .def("checkMousePicking", (void(ofxBulletWorldRigid::*)(float,float)) &ofxBulletWorldRigid::checkMousePicking)
         .def("enableGrabbing", (void(ofxBulletWorldRigid::*)(short int)) &ofxBulletWorldRigid::enableGrabbing)
         .def("disableGrabbing", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::disableGrabbing)
         .def("enableDebugDraw", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::enableDebugDraw)
         .def("drawDebug", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::drawDebug)
         .def("checkWorld", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::checkWorld)
         .def("setGravity", (void(ofxBulletWorldRigid::*)(ofVec3f)) &ofxBulletWorldRigid::setGravity)
         .def("getGravity", (ofVec3f(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::getGravity)
         .def("removeMouseConstraint", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::removeMouseConstraint)
         .def("destroy", (void(ofxBulletWorldRigid::*)(void)) &ofxBulletWorldRigid::destroy),
         
         class_<ofxBulletBox>("bulletBox")
         .def(constructor<>())
         .def("init", (void(ofxBulletBox::*)(float,float,float)) &ofxBulletBox::init)
         .def("create", (void(ofxBulletBox::*)(btDiscreteDynamicsWorld*,ofVec3f,float,float,float,float)) &ofxBulletBox::create)
         .def("add", (void(ofxBulletBox::*)(void)) &ofxBulletBox::add)
         .def("remove", (void(ofxBulletBox::*)(void)) &ofxBulletBox::remove)
         .def("removeRigidBody", (void(ofxBulletBox::*)(void)) &ofxBulletBox::removeRigidBody)
         .def("draw", (void(ofxBulletBox::*)(void)) &ofxBulletBox::draw)
         .def("drawBox", (void(ofxBulletBox::*)(float,float,float)) &ofxBulletBox::drawBox)
         .def("getSize", (ofVec3f(ofxBulletBox::*)(void)) &ofxBulletBox::getSize)
         .def("isInside", (bool(ofxBulletBox::*)(const ofVec3f&,float)) &ofxBulletBox::isInside),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////
         // OFXGAUSSIAN
         def("gaussian", (float(*)(void)) &ofxGaussian)
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////
         // OFXMISSING
         
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////
         // OFXPD
         
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////
         // OFXSTEPSEQUENCER
         
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////
         // OFXSTRINGENCODERS
         
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
        ];
		
		//////////////////////////////////////////////////////////////
		///////////////////////////////
		/// gamuza core api wrapper
		module(lua, "ga")
		[
		 
         ///////////////////////////////
		 // app section
         def("key", &getKey), // ga.key()
         
		 ///////////////////////////////
		 // graphics section
		 def("background", (void(*)(float,float)) &gaBackground),
		 def("background", (void(*)(float,float,float,float)) &gaBackground),
		 def("cameraTexture", (ofTexture(*)(int)) &gaGetWebcamTexture),
         
         ///////////////////////////////
		 // timeline section
         def("playTimeline", (void(*)(void)) &gaPlayTimeline),
         def("stopTimeline", (void(*)(void)) &gaStopTimeline),
         def("setTimelineFrames", (void(*)(int)) &gaSetTimelineDurationInFrames),
         def("setTimelineLoop", (void(*)(int)) &gaSetTimelineLoopType),
         def("addTimelineKeyframes", (void(*)(string,string,float,float)) &gaAddTimelineKeyframes),
         def("getTimelineValue", (float(*)(string)) &gaGetTimelineKeyframeValue),
         def("getTimelineTrigger", (string(*)(void)) &gaGetTimelineTrigger),
         
         ///////////////////////////////
		 // pixel manipulation section
         def("cameraMiller", (ofTexture(*)(int,int,float,float,float,float)) &gaGetWebcamMiller),
		 
		 ///////////////////////////////
		 // audio synth section
		 def("wave", &gaSetupOSC),
		 def("monoWave", &gaSetupMonoOSC),
		 def("waveVolume", &gaSetOscVolume),
		 def("waveFrequency", &gaSetOscFrequency),
		 def("waveType", &gaSetOscWaveType),
		 def("waveTuning,", &gaSetOscTuning),
		 def("nToF", &gaNote),
         
         ///////////////////////////////
		 // audio sample section
         def("sample", (void(*)(string)) &gaSetupSample),
         def("samplePlay", (void(*)(int)) &gaSamplePlay),
         def("sampleStop", (void(*)(int)) &gaSampleStop),
		 def("sampleVolume", (void(*)(int,float)) &gaSetSampleVolume),
		 def("sampleLooping", (void(*)(int,bool)) &gaSetSampleLooping),
		 def("samplePaused", (void(*)(int,bool)) &gaSetSamplePaused),
         def("sampleSpeed", (void(*)(int,float)) &gaSetSampleSpeed),
         def("drawSample", (void(*)(int,int,int,int,int)) &gaDrawSampleWave),
         
         ///////////////////////////////
		 // midi section
         def("getMidiChannel", (int(*)(void)) &gaGetMidiChannel),
         def("getMidiByteOne", (int(*)(void)) &gaGetMidiByteOne),
         def("getMidiByteTwo", (int(*)(void)) &gaGetMidiByteTwo),
         def("getMidiValue", (float(*)(int,int)) &gaGetMidiValue),
		 
		 //////////////////////////////////////////////////////////////// GUI MODULES
		 ///////////////////////////////
		 // openni sensor kinect
		 def("oniBlobs", (int(*)(void)) &gaONIRunningBlob),
		 def("oniBlobX", (float(*)(int)) &gaONIBlobX),
		 def("oniBlobY", (float(*)(int)) &gaONIBlobY),
		 def("oniBlobW", (float(*)(int)) &gaONIBlobW),
		 def("oniBlobH", (float(*)(int)) &gaONIBlobH),
		 def("oniBlobAngle", (float(*)(int)) &gaONIBlobAngle),
		 def("oniBlobContourSize", (int(*)(int)) &gaONIBlobContourSize),
         def("oniBlobCPointX", (float(*)(int,int)) &gaONIBlobCPointX),
         def("oniBlobCPointY", (float(*)(int,int)) &gaONIBlobCPointY),
		 def("oniBlobGeometrySize", (int(*)(int)) &gaONIBlobGeometrySize),
         def("oniBlobGLineX1", (float(*)(int,int)) &gaONIBlobGLineX1),
         def("oniBlobGLineY1", (float(*)(int,int)) &gaONIBlobGLineY1),
         def("oniBlobGLineX2", (float(*)(int,int)) &gaONIBlobGLineX2),
         def("oniBlobGLineY2", (float(*)(int,int)) &gaONIBlobGLineY2),
		 def("oniOpticalFlowX", (float(*)(int,int)) &gaONIOpticalFlowX),
         def("oniOpticalFlowY", (float(*)(int,int)) &gaONIOpticalFlowY),
		 def("oniTrigger", (bool(*)(int)) &gaONITrigger),
		 def("oniHandX", (float(*)(int)) &gaONIHandX),
         def("oniHandY", (float(*)(int)) &gaONIHandY),
         def("oniHandZ", (float(*)(int)) &gaONIHandZ),
		 def("oniAccelerometerX", (float(*)(void)) &gaONIAccelerometerX),
         def("oniAccelerometerY", (float(*)(void)) &gaONIAccelerometerY),
         def("oniAccelerometerZ", (float(*)(void)) &gaONIAccelerometerZ),
		 def("oniTilt", (float(*)(void)) &gaONITilt),
		 
		 ///////////////////////////////
		 // webcam tracking
		 def("camMotionQ", (float(*)(int)) &gaCamMotionQ),
		 def("camMotionX", (float(*)(int)) &gaCamMotionX),
		 def("camMotionY", (float(*)(int)) &gaCamMotionY),
		 def("camBlobs", (int(*)(int)) &gaCamRunningBlob),
		 def("camBlobX", (float(*)(int,int)) &gaCamBlobX),
		 def("camBlobY", (float(*)(int,int)) &gaCamBlobY),
		 def("camBlobW", (float(*)(int,int)) &gaCamBlobW),
		 def("camBlobH", (float(*)(int,int)) &gaCamBlobH),
		 def("camBlobAngle", (float(*)(int,int)) &gaCamBlobAngle),
         def("camBlobContourSize", (int(*)(int,int)) &gaCamBlobContourSize),
         def("camBlobCPointX", (float(*)(int,int,int)) &gaCamBlobCPointX),
         def("camBlobCPointY", (float(*)(int,int,int)) &gaCamBlobCPointY),
		 def("camBlobGeometrySize", (int(*)(int,int)) &gaCamBlobGeometrySize),
         def("camBlobGLineX1", (float(*)(int,int,int)) &gaCamBlobGLineX1),
         def("camBlobGLineY1", (float(*)(int,int,int)) &gaCamBlobGLineY1),
         def("camBlobGLineX2", (float(*)(int,int,int)) &gaCamBlobGLineX2),
         def("camBlobGLineY2", (float(*)(int,int,int)) &gaCamBlobGLineY2),
		 def("camOpticalFlowX", (float(*)(int,int,int)) &gaCamOpticalFlowX),
         def("camOpticalFlowY", (float(*)(int,int,int)) &gaCamOpticalFlowY),
         def("camHaars", (int(*)(int)) &gaCamRunningHaar),
		 def("camHaarX", (float(*)(int,int)) &gaCamHaarX),
         def("camHaarY", (float(*)(int,int)) &gaCamHaarY),
         def("camHaarW", (float(*)(int,int)) &gaCamHaarW),
         def("camHaarH", (float(*)(int,int)) &gaCamHaarH),
		 def("camTrigger", (bool(*)(int,int)) &gaCamTrigger),
		 
		 ///////////////////////////////
		 // audio input
		 def("getVolume", (float(*)(int)) &gaGetVolume),
		 def("getPitch", (float(*)(int)) &gaGetPitch),
		 def("getBin", (float(*)(int,int)) &gaGetFFTBin),
		 def("getFFT", (float*(*)(int)) &gaGetFFTBins),
		 
		 ///////////////////////////////
		 // arduino
		 def("analogRead", (float(*)(int)) &gaGetAArduinoPin),
		 def("digitalRead", (int(*)(int)) &gaGetDArduinoPin),
		 def("digitalWrite", (void(*)(int,int)) &gaSetDArduinoPin)
		 //////////////////////////////////////////////////////////////// GUI MODULES
		 
		 
		];
		//////////////////////////////////////////////////////////////
		
		///////////////////////////////
		/// \section Add Values
		
		/// OF math constants		
		lua.doString("HALF_PI = "+ofToString(HALF_PI));
		lua.doString("PI = "+ofToString(PI));
		lua.doString("TWO_PI = "+ofToString(TWO_PI));
        lua.doString("FOUR_PI = "+ofToString(FOUR_PI));
        lua.doString("DEG_TO_RAD = "+ofToString(DEG_TO_RAD));
        lua.doString("RAD_TO_DEG = "+ofToString(RAD_TO_DEG));
        
        // OF key constants
        lua.doString("OF_KEY_RETURN = "+ofToString(OF_KEY_RETURN));
        lua.doString("OF_KEY_ESC = "+ofToString(OF_KEY_ESC));
        lua.doString("OF_KEY_F1 = "+ofToString(OF_KEY_F1));
        lua.doString("OF_KEY_F2 = "+ofToString(OF_KEY_F2));
        lua.doString("OF_KEY_F3 = "+ofToString(OF_KEY_F3));
        lua.doString("OF_KEY_F4 = "+ofToString(OF_KEY_F4));
        lua.doString("OF_KEY_F5 = "+ofToString(OF_KEY_F5));
        lua.doString("OF_KEY_F6 = "+ofToString(OF_KEY_F6));
        lua.doString("OF_KEY_F7 = "+ofToString(OF_KEY_F7));
        lua.doString("OF_KEY_F8 = "+ofToString(OF_KEY_F8));
        lua.doString("OF_KEY_F9 = "+ofToString(OF_KEY_F9));
        lua.doString("OF_KEY_F10 = "+ofToString(OF_KEY_F10));
        lua.doString("OF_KEY_F11 = "+ofToString(OF_KEY_F11));
        lua.doString("OF_KEY_F12 = "+ofToString(OF_KEY_F11));
        lua.doString("OF_KEY_LEFT = "+ofToString(OF_KEY_LEFT));
        lua.doString("OF_KEY_UP = "+ofToString(OF_KEY_UP));
        lua.doString("OF_KEY_RIGHT = "+ofToString(OF_KEY_RIGHT));
        lua.doString("OF_KEY_DOWN = "+ofToString(OF_KEY_DOWN));
        lua.doString("OF_KEY_PAGE_UP = "+ofToString(OF_KEY_PAGE_UP));
        lua.doString("OF_KEY_PAGE_DOWN = "+ofToString(OF_KEY_PAGE_DOWN));
        lua.doString("OF_KEY_HOME = "+ofToString(OF_KEY_HOME));
        lua.doString("OF_KEY_END = "+ofToString(OF_KEY_END));
        lua.doString("OF_KEY_INSERT = "+ofToString(OF_KEY_INSERT));
        lua.doString("OF_KEY_BACKSPACE = "+ofToString(OF_KEY_BACKSPACE));
        lua.doString("OF_KEY_DEL = "+ofToString(OF_KEY_DEL));
        
        // OF loop constants
        lua.doString("OF_LOOP_NONE = "+ofToString(OF_LOOP_NONE));
        lua.doString("OF_LOOP_NORMAL = "+ofToString(OF_LOOP_NORMAL));
        lua.doString("OF_LOOP_PALINDROME = "+ofToString(OF_LOOP_PALINDROME));
        
        // OF image type
        lua.doString("OF_IMAGE_GRAYSCALE = "+ofToString(OF_IMAGE_GRAYSCALE));
        lua.doString("OF_IMAGE_COLOR = "+ofToString(OF_IMAGE_COLOR));
        lua.doString("OF_IMAGE_COLOR_ALPHA = "+ofToString(OF_IMAGE_COLOR_ALPHA));
		
		// graphics
		lua.doString("OUTPUT_W = "+ofToString(gapp->gamuzaBase.projectionScreenW));
		lua.doString("OUTPUT_H = "+ofToString(gapp->gamuzaBase.projectionScreenH));
		lua.doString("CAPTURE_W = "+ofToString(gapp->gamuzaBase.workingW));
		lua.doString("CAPTURE_H = "+ofToString(gapp->gamuzaBase.workingH));
		lua.doString("CAPTURE_PIX = "+ofToString(gapp->gamuzaBase.totPixels));
		
		// video tracking
		lua.doString("MAX_BLOBS = "+ofToString(MAX_USERS_HARDLIMIT));
        lua.doString("OPTICAL_FLOW_GRID_X = "+ofToString((int)(gapp->gamuzaBase.workingW/OPTICAL_FLOW_COLS_STEP)));
        lua.doString("OPTICAL_FLOW_GRID_Y = "+ofToString((int)(gapp->gamuzaBase.workingH/OPTICAL_FLOW_ROWS_STEP)));
		
		// audio analysis
		lua.doString("FFT_BANDS = "+ofToString(BARK_SCALE_CRITICAL_BANDS));
		
		// audio synth
		lua.doString("SIN = "+ofToString(OSC_SINE_WAVE));
		lua.doString("COS = "+ofToString(OSC_COSINE_WAVE));
		lua.doString("SAW = "+ofToString(OSC_SAWTOOTH_WAVE));
		lua.doString("TRI = "+ofToString(OSC_TRIANGLE_WAVE));
		lua.doString("RECT = "+ofToString(OSC_RECT_WAVE));
		lua.doString("NOISE = "+ofToString(OSC_WHITE_NOISE));
		lua.doString("PINK = "+ofToString(OSC_PINK_NOISE));
		lua.doString("BROWN = "+ofToString(OSC_BROWN_NOISE));
		lua.doString("PHASOR = "+ofToString(OSC_PHASOR));
		lua.doString("PULSE = "+ofToString(OSC_PULSE));
		// notes
		lua.doString("DO_0 = "+ofToString(DO_0));
		lua.doString("DOB_0 = "+ofToString(DOB0));
		lua.doString("RE_0 = "+ofToString(RE_0));
		lua.doString("REB_0 = "+ofToString(REB_0));
		lua.doString("MI_0 = "+ofToString(MI_0));
		lua.doString("FA_0 = "+ofToString(FA_0));
		lua.doString("FAB_0 = "+ofToString(FAB_0));
		lua.doString("SOL_0 = "+ofToString(SOL_0));
		lua.doString("SOLB_0 = "+ofToString(SOLB_0));
		lua.doString("LA_0 = "+ofToString(LA_0));
		lua.doString("LAB_0 = "+ofToString(LAB_0));
		lua.doString("SI_0 = "+ofToString(SI_0));
		lua.doString("DO_1 = "+ofToString(DO_1));
		lua.doString("DOB_1 = "+ofToString(DOB1));
		lua.doString("RE_1 = "+ofToString(RE_1));
		lua.doString("REB_1 = "+ofToString(REB_1));
		lua.doString("MI_1 = "+ofToString(MI_1));
		lua.doString("FA_1 = "+ofToString(FA_1));
		lua.doString("FAB_1 = "+ofToString(FAB_1));
		lua.doString("SOL_1 = "+ofToString(SOL_1));
		lua.doString("SOLB_1 = "+ofToString(SOLB_1));
		lua.doString("LA_1 = "+ofToString(LA_1));
		lua.doString("LAB_1 = "+ofToString(LAB_1));
		lua.doString("SI_1 = "+ofToString(SI_1));
		lua.doString("DO_2 = "+ofToString(DO_2));
		lua.doString("DOB_2 = "+ofToString(DOB2));
		lua.doString("RE_2 = "+ofToString(RE_2));
		lua.doString("REB_2 = "+ofToString(REB_2));
		lua.doString("MI_2 = "+ofToString(MI_2));
		lua.doString("FA_2 = "+ofToString(FA_2));
		lua.doString("FAB_2 = "+ofToString(FAB_2));
		lua.doString("SOL_2 = "+ofToString(SOL_2));
		lua.doString("SOLB_2 = "+ofToString(SOLB_2));
		lua.doString("LA_2 = "+ofToString(LA_2));
		lua.doString("LAB_2 = "+ofToString(LAB_2));
		lua.doString("SI_2 = "+ofToString(SI_2));
		lua.doString("DO_3 = "+ofToString(DO_3));
		lua.doString("DOB_3 = "+ofToString(DOB3));
		lua.doString("RE_3 = "+ofToString(RE_3));
		lua.doString("REB_3 = "+ofToString(REB_3));
		lua.doString("MI_3 = "+ofToString(MI_3));
		lua.doString("FA_3 = "+ofToString(FA_3));
		lua.doString("FAB_3 = "+ofToString(FAB_3));
		lua.doString("SOL_3 = "+ofToString(SOL_3));
		lua.doString("SOLB_3 = "+ofToString(SOLB_3));
		lua.doString("LA_3 = "+ofToString(LA_3));
		lua.doString("LAB_3 = "+ofToString(LAB_3));
		lua.doString("SI_3 = "+ofToString(SI_3));
		lua.doString("DO_4 = "+ofToString(DO_4));
		lua.doString("DOB_4 = "+ofToString(DOB4));
		lua.doString("RE_4 = "+ofToString(RE_4));
		lua.doString("REB_4 = "+ofToString(REB_4));
		lua.doString("MI_4 = "+ofToString(MI_4));
		lua.doString("FA_4 = "+ofToString(FA_4));
		lua.doString("FAB_4 = "+ofToString(FAB_4));
		lua.doString("SOL_4 = "+ofToString(SOL_4));
		lua.doString("SOLB_4 = "+ofToString(SOLB_4));
		lua.doString("LA_4 = "+ofToString(LA_4));
		lua.doString("LAB_4 = "+ofToString(LAB_4));
		lua.doString("SI_4 = "+ofToString(SI_4));
		lua.doString("DO_5 = "+ofToString(DO_5));
		lua.doString("DOB_5 = "+ofToString(DOB5));
		lua.doString("RE_5 = "+ofToString(RE_5));
		lua.doString("REB_5 = "+ofToString(REB_5));
		lua.doString("MI_5 = "+ofToString(MI_5));
		lua.doString("FA_5 = "+ofToString(FA_5));
		lua.doString("FAB_5 = "+ofToString(FAB_5));
		lua.doString("SOL_5 = "+ofToString(SOL_5));
		lua.doString("SOLB_5 = "+ofToString(SOLB_5));
		lua.doString("LA_5 = "+ofToString(LA_5));
		lua.doString("LAB_5 = "+ofToString(LAB_5));
		lua.doString("SI_5 = "+ofToString(SI_5));
		lua.doString("DO_6 = "+ofToString(DO_6));
		lua.doString("DOB_6 = "+ofToString(DOB6));
		lua.doString("RE_6 = "+ofToString(RE_6));
		lua.doString("REB_6 = "+ofToString(REB_6));
		lua.doString("MI_6 = "+ofToString(MI_6));
		lua.doString("FA_6 = "+ofToString(FA_6));
		lua.doString("FAB_6 = "+ofToString(FAB_6));
		lua.doString("SOL_6 = "+ofToString(SOL_6));
		lua.doString("SOLB_6 = "+ofToString(SOLB_6));
		lua.doString("LA_6 = "+ofToString(LA_6));
		lua.doString("LAB_6 = "+ofToString(LAB_6));
		lua.doString("SI_6 = "+ofToString(SI_6));
		lua.doString("DO_7 = "+ofToString(DO_7));
		lua.doString("DOB_7 = "+ofToString(DOB7));
		lua.doString("RE_7 = "+ofToString(RE_7));
		lua.doString("REB_7 = "+ofToString(REB_7));
		lua.doString("MI_7 = "+ofToString(MI_7));
		lua.doString("FA_7 = "+ofToString(FA_7));
		lua.doString("FAB_7 = "+ofToString(FAB_7));
		lua.doString("SOL_7 = "+ofToString(SOL_7));
		lua.doString("SOLB_7 = "+ofToString(SOLB_7));
		lua.doString("LA_7 = "+ofToString(LA_7));
		lua.doString("LAB_7 = "+ofToString(LAB_7));
		lua.doString("SI_7 = "+ofToString(SI_7));
		lua.doString("DO_8 = "+ofToString(DO_8));
		lua.doString("DOB_8 = "+ofToString(DOB8));
		lua.doString("RE_8 = "+ofToString(RE_8));
		lua.doString("REB_8 = "+ofToString(REB_8));
		lua.doString("MI_8 = "+ofToString(MI_8));
		lua.doString("FA_8 = "+ofToString(FA_8));
		lua.doString("FAB_8 = "+ofToString(FAB_8));
		lua.doString("SOL_8 = "+ofToString(SOL_8));
		lua.doString("SOLB_8 = "+ofToString(SOLB_8));
		lua.doString("LA_8 = "+ofToString(LA_8));
		lua.doString("LAB_8 = "+ofToString(LAB_8));
		lua.doString("SI_8 = "+ofToString(SI_8));
		
		//////////////////////////////////////////////////////////////
		///////////////////////////////
		/// opengl core api wrapper
		module(lua, "gl")
		[
			 
			 def("enable", &glEnable),
			 def("disable", &glDisable),
			 def("depthMask",&glDepthMask),
			 def("begin", &glBegin),
			 def("vertex3f", &glVertex3f),
			 def("end", &glEnd),
			 def("clear", &glClear),
			 def("pushMatrix", &glPushMatrix),
			 def("popMatrix", &glPopMatrix),
			 def("rotate", &glRotatef),
			 def("color3f", &glColor3f),
			 def("color4f", &glColor4f),
			 def("matrixMode", &glMatrixMode),
			 def("loadIdentity", &glLoadIdentity),
			 def("viewport", &glViewport),
			 def("translate", &glTranslatef)
		];
		
		lua.doString("GL_POINTS = "+ofToString(GL_POINTS));
		lua.doString("GL_LINES = "+ofToString(GL_LINES));
		lua.doString("GL_LINE_STRIP = "+ofToString(GL_LINE_STRIP));
		lua.doString("GL_LINE_LOOP = "+ofToString(GL_LINE_LOOP));
		lua.doString("GL_TRIANGLES = "+ofToString(GL_TRIANGLES));
		lua.doString("GL_TRIANGLE_STRIP = "+ofToString(GL_TRIANGLE_STRIP));
		lua.doString("GL_TRIANGLE_FAN = "+ofToString(GL_TRIANGLE_FAN));
		lua.doString("GL_QUADS = "+ofToString(GL_QUADS));
		lua.doString("GL_QUAD_STRIP = "+ofToString(GL_QUAD_STRIP));
		lua.doString("GL_BLEND = "+ofToString(GL_BLEND));
		lua.doString("GL_DEPTH_TEST = "+ofToString(GL_DEPTH_TEST));
		lua.doString("GL_LUMINANCE = "+ofToString(GL_LUMINANCE));
		lua.doString("GL_RGB = "+ofToString(GL_RGB));
		lua.doString("GL_RGBA = "+ofToString(GL_RGBA));
		//////////////////////////////////////////////////////////////
		
	}
	
	////////////////////////////////////////////////////////
	/// \section Function & Object Wrappers
	
	/// background
	static void background(int brightness) 		{ofBackground(brightness);}
	static void background(int r, int g, int b)	{ofBackground(r, g, b);}
	
	/// ofPixels
	static unsigned char getPixel(ofPixels* pixels, int index) {
		return pixels->getPixels()[index];
	}
	static void setPixel(ofPixels* pixels, int index, unsigned char p) {
		pixels->getPixels()[index] = p;
	}
	
	/// global mouse vars
	static float getMouseX() {return (float)ofGetAppPtr()->mouseX;}
	static float getMouseY() {return (float)ofGetAppPtr()->mouseY;}
    
    /// global key vars
    static int getKey() {return (int)gapp->gamuzaBase.liveKey;}
	
	/// ofTrueTypeFont
	static void loadFont2(ofTrueTypeFont* font, string filename, int fontsize) {
		font->loadFont(filename, fontsize);
	}
	static void loadFont4(ofTrueTypeFont* font, string filename, int fontsize, bool _bAntiAliased, bool _bFullCharacterSet) {
		font->loadFont(filename, fontsize, _bAntiAliased, _bFullCharacterSet);
	}

};