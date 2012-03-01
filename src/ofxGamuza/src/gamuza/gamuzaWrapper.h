/*
 * Extending ofxLuaWrapper for GAmuza 0.3 | ALMOST ENTIRE OF 007 Wrapper + GAmuza Wrapper + SOME FUNCTIONS FROM OPENGL 2.1 Wrapper
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
        
        //////////////////////////////////////////////////////////////
		///////////////////////////////
		/// Utils from c++ api wrapper [pointers, vector, map, hashMap, ...]
		///
		module(lua, "c")
		[
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section Pointers
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section char*
         
         class_<intP>("intP")
         .def(constructor<>())
         .def(constructor<int>())
         .def("set",(void(intP::*)(int))&intP::set)
         .def_readwrite("p", &intP::p),
         
         class_<uintP>("uintP")
         .def(constructor<>())
         .def(constructor<int>())
         .def("set",(void(uintP::*)(int))&uintP::set)
         .def_readwrite("p", &uintP::p),
         
         class_<floatP>("floatP")
         .def(constructor<>())
         .def(constructor<int>())
         .def("set",(void(floatP::*)(int))&floatP::set)
         .def_readwrite("p", &floatP::p),
         
         class_<charP>("charP")
         .def(constructor<>())
         .def(constructor<int>())
         .def("set",(void(charP::*)(int))&charP::set)
         .def_readwrite("p", &charP::p),
         
         class_<ucharP>("ucharP")
         .def(constructor<>())
         .def(constructor<int>())
         .def("set",(void(ucharP::*)(int))&ucharP::set)
         .def_readwrite("p", &ucharP::p),
        
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section vector
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<int>
         
         class_<std::vector<int> >("vectorI")
         .def(constructor<>())
         .def("assign",(void(std::vector<int>::*)(size_t,const int&))&std::vector<int>::assign)
         //.def("at", &std::vector<int>::at)
         .def("at",(int&(std::vector<int>::*)(size_t))&std::vector<int>::at)
         .def("back",(int&(std::vector<int>::*)(void))&std::vector<int>::back)
         //.def("begin",(int&(std::vector<int>::*)(void))&std::vector<int>::begin)
         .def("capacity",(size_t(std::vector<int>::*)(void))&std::vector<int>::capacity)
         .def("clear",(void(std::vector<int>::*)(void))&std::vector<int>::clear)
         .def("empty",(bool(std::vector<int>::*)(void))&std::vector<int>::empty)
         //.def("end",(int&(std::vector<int>::*)(void))&std::vector<int>::end)
         //.def("erase",(int&(std::vector<int>::*)(int&))&std::vector<int>::erase)
         //.def("erase",(int&(std::vector<int>::*)(int&,int&))&std::vector<int>::erase)
         .def("front",(int&(std::vector<int>::*)(void))&std::vector<int>::front)
         .def("get_allocator",(int&(std::vector<int>::*)(void))&std::vector<int>::get_allocator)
         //.def("insert",(int&(std::vector<int>::*)(int&,int&))&std::vector<int>::insert)
         .def("max_size", (unsigned int(std::vector<int>::*)(void))&std::vector<int>::max_size)
         .def("pop_back", (void(std::vector<int>::*)(void))&std::vector<int>::pop_back)
         .def("push_back", (void(std::vector<int>::*)(const int&))&std::vector<int>::push_back)
         //.def("rbegin", &std::vector<int>::rbegin)
         //.def("rend", &std::vector<int>::rend)
         //.def("reserve", (void(std::vector<int>::*)(unsigned int))&std::vector<int>::reserve)
         //.def("resize", &std::vector<int>::resize)
         .def("size", (unsigned int(std::vector<int>::*)(void))&std::vector<int>::size)
         .def("swap",(void(std::vector<int>::*)(std::vector<int>&))&std::vector<int>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<float>
         
         class_<std::vector<float> >("vectorF")
         .def(constructor<>())
         .def("assign",(void(std::vector<float>::*)(size_t,const float&))&std::vector<float>::assign)
         //.def("at", &std::vector<float>::at)
         .def("at",(float&(std::vector<float>::*)(size_t))&std::vector<float>::at)
         .def("back",(float&(std::vector<float>::*)(void))&std::vector<float>::back)
         //.def("begin",(int&(std::vector<float>::*)(void))&std::vector<float>::begin)
         .def("capacity",(size_t(std::vector<float>::*)(void))&std::vector<float>::capacity)
         .def("clear",(void(std::vector<float>::*)(void))&std::vector<float>::clear)
         .def("empty",(bool(std::vector<float>::*)(void))&std::vector<float>::empty)
         //.def("end",(int&(std::vector<float>::*)(void))&std::vector<float>::end)
         //.def("erase",(int&(std::vector<float>::*)(int&))&std::vector<float>::erase)
         //.def("erase",(int&(std::vector<float>::*)(int&,int&))&std::vector<float>::erase)
         .def("front",(float&(std::vector<float>::*)(void))&std::vector<float>::front)
         .def("get_allocator",(int&(std::vector<float>::*)(void))&std::vector<float>::get_allocator)
         //.def("insert",(int&(std::vector<float>::*)(int&,int&))&std::vector<float>::insert)
         .def("max_size", (unsigned int(std::vector<float>::*)(void))&std::vector<float>::max_size)
         .def("pop_back", (void(std::vector<float>::*)(void))&std::vector<float>::pop_back)
         .def("push_back", (void(std::vector<float>::*)(const float&))&std::vector<float>::push_back)
         //.def("rbegin", &std::vector<int>::rbegin)
         //.def("rend", &std::vector<int>::rend)
         //.def("reserve", (void(std::vector<float>::*)(unsigned int))&std::vector<float>::reserve)
         //.def("resize", &std::vector<float>::resize)
         .def("size", (unsigned int(std::vector<float>::*)(void))&std::vector<float>::size)
         .def("swap",(void(std::vector<float>::*)(std::vector<float>&))&std::vector<float>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<string>
         
         class_<std::vector<string> >("vectorS")
         .def(constructor<>())
         .def("assign",(void(std::vector<string>::*)(size_t,const string&))&std::vector<string>::assign)
         //.def("at", &std::vector<string>::at)
         .def("at",(string&(std::vector<string>::*)(size_t))&std::vector<string>::at)
         .def("back",(string&(std::vector<string>::*)(void))&std::vector<string>::back)
         //.def("begin",(int&(std::vector<string>::*)(void))&std::vector<string>::begin)
         .def("capacity",(size_t(std::vector<string>::*)(void))&std::vector<string>::capacity)
         .def("clear",(void(std::vector<string>::*)(void))&std::vector<string>::clear)
         .def("empty",(bool(std::vector<string>::*)(void))&std::vector<string>::empty)
         //.def("end",(int&(std::vector<string>::*)(void))&std::vector<string>::end)
         //.def("erase",(int&(std::vector<string>::*)(int&))&std::vector<string>::erase)
         //.def("erase",(int&(std::vector<string>::*)(int&,int&))&std::vector<string>::erase)
         .def("front",(string&(std::vector<string>::*)(void))&std::vector<string>::front)
         .def("get_allocator",(int&(std::vector<string>::*)(void))&std::vector<string>::get_allocator)
         //.def("insert",(int&(std::vector<string>::*)(int&,int&))&std::vector<string>::insert)
         .def("max_size", (unsigned int(std::vector<string>::*)(void))&std::vector<string>::max_size)
         .def("pop_back", (void(std::vector<string>::*)(void))&std::vector<string>::pop_back)
         .def("push_back", (void(std::vector<string>::*)(const string&))&std::vector<string>::push_back)
         //.def("rbegin", &std::vector<int>::rbegin)
         //.def("rend", &std::vector<int>::rend)
         //.def("reserve", (void(std::vector<string>::*)(unsigned int))&std::vector<string>::reserve)
         //.def("resize", &std::vector<string>::resize)
         .def("size", (unsigned int(std::vector<string>::*)(void))&std::vector<string>::size)
         .def("swap",(void(std::vector<string>::*)(std::vector<string>&))&std::vector<string>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<char>
         
         class_<std::vector<char> >("vectorC")
         .def(constructor<>())
         .def("assign",(void(std::vector<char>::*)(size_t,const char&))&std::vector<char>::assign)
         //.def("at", &std::vector<char>::at)
         .def("at",(char&(std::vector<char>::*)(size_t))&std::vector<char>::at)
         .def("back",(char&(std::vector<char>::*)(void))&std::vector<char>::back)
         //.def("begin",(int&(std::vector<char>::*)(void))&std::vector<char>::begin)
         .def("capacity",(size_t(std::vector<char>::*)(void))&std::vector<char>::capacity)
         .def("clear",(void(std::vector<char>::*)(void))&std::vector<char>::clear)
         .def("empty",(bool(std::vector<char>::*)(void))&std::vector<char>::empty)
         //.def("end",(int&(std::vector<char>::*)(void))&std::vector<char>::end)
         //.def("erase",(int&(std::vector<char>::*)(int&))&std::vector<char>::erase)
         //.def("erase",(int&(std::vector<char>::*)(int&,int&))&std::vector<char>::erase)
         .def("front",(char&(std::vector<char>::*)(void))&std::vector<char>::front)
         .def("get_allocator",(int&(std::vector<char>::*)(void))&std::vector<char>::get_allocator)
         //.def("insert",(int&(std::vector<char>::*)(int&,int&))&std::vector<char>::insert)
         .def("max_size", (unsigned int(std::vector<char>::*)(void))&std::vector<char>::max_size)
         .def("pop_back", (void(std::vector<char>::*)(void))&std::vector<char>::pop_back)
         .def("push_back", (void(std::vector<char>::*)(const char&))&std::vector<char>::push_back)
         //.def("rbegin", &std::vector<int>::rbegin)
         //.def("rend", &std::vector<int>::rend)
         //.def("reserve", (void(std::vector<char>::*)(unsigned int))&std::vector<char>::reserve)
         //.def("resize", &std::vector<char>::resize)
         .def("size", (unsigned int(std::vector<char>::*)(void))&std::vector<char>::size)
         .def("swap",(void(std::vector<char>::*)(std::vector<char>&))&std::vector<char>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofVec2f>
         
         class_<vector<ofVec2f> >("vectorOFvec2f")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofVec2f>::*)(void))&std::vector<ofVec2f>::capacity)
         .def("clear",(void(std::vector<ofVec2f>::*)(void))&std::vector<ofVec2f>::clear)
         .def("empty",(bool(std::vector<ofVec2f>::*)(void))&std::vector<ofVec2f>::empty)
         .def("get_allocator",(int&(std::vector<ofVec2f>::*)(void))&std::vector<ofVec2f>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofVec2f>::*)(void))&std::vector<ofVec2f>::max_size)
         .def("pop_back", (void(std::vector<ofVec2f>::*)(void))&std::vector<ofVec2f>::pop_back)
         .def("push_back", (void(std::vector<ofVec2f>::*)(const char&))&std::vector<ofVec2f>::push_back)
         .def("size", (unsigned int(std::vector<ofVec2f>::*)(void))&std::vector<ofVec2f>::size)
         .def("swap",(void(std::vector<ofVec2f>::*)(std::vector<ofVec2f>&))&std::vector<ofVec2f>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofVec3f>
         
         class_<vector<ofVec3f> >("vectorOFvec3f")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofVec3f>::*)(void))&std::vector<ofVec3f>::capacity)
         .def("clear",(void(std::vector<ofVec3f>::*)(void))&std::vector<ofVec3f>::clear)
         .def("empty",(bool(std::vector<ofVec3f>::*)(void))&std::vector<ofVec3f>::empty)
         .def("get_allocator",(int&(std::vector<ofVec3f>::*)(void))&std::vector<ofVec3f>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofVec3f>::*)(void))&std::vector<ofVec3f>::max_size)
         .def("pop_back", (void(std::vector<ofVec3f>::*)(void))&std::vector<ofVec3f>::pop_back)
         .def("push_back", (void(std::vector<ofVec3f>::*)(const char&))&std::vector<ofVec3f>::push_back)
         .def("size", (unsigned int(std::vector<ofVec3f>::*)(void))&std::vector<ofVec3f>::size)
         .def("swap",(void(std::vector<ofVec3f>::*)(std::vector<ofVec3f>&))&std::vector<ofVec3f>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofVec4f>
         
         class_<vector<ofVec4f> >("vectorOFvec4f")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofVec4f>::*)(void))&std::vector<ofVec4f>::capacity)
         .def("clear",(void(std::vector<ofVec4f>::*)(void))&std::vector<ofVec4f>::clear)
         .def("empty",(bool(std::vector<ofVec4f>::*)(void))&std::vector<ofVec4f>::empty)
         .def("get_allocator",(int&(std::vector<ofVec4f>::*)(void))&std::vector<ofVec4f>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofVec4f>::*)(void))&std::vector<ofVec4f>::max_size)
         .def("pop_back", (void(std::vector<ofVec4f>::*)(void))&std::vector<ofVec4f>::pop_back)
         .def("push_back", (void(std::vector<ofVec4f>::*)(const char&))&std::vector<ofVec4f>::push_back)
         .def("size", (unsigned int(std::vector<ofVec4f>::*)(void))&std::vector<ofVec4f>::size)
         .def("swap",(void(std::vector<ofVec4f>::*)(std::vector<ofVec4f>&))&std::vector<ofVec4f>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofTexture>
         
         class_<vector<ofTexture> >("vectorOFtexture")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofTexture>::*)(void))&std::vector<ofTexture>::capacity)
         .def("clear",(void(std::vector<ofTexture>::*)(void))&std::vector<ofTexture>::clear)
         .def("empty",(bool(std::vector<ofTexture>::*)(void))&std::vector<ofTexture>::empty)
         .def("get_allocator",(int&(std::vector<ofTexture>::*)(void))&std::vector<ofTexture>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofTexture>::*)(void))&std::vector<ofTexture>::max_size)
         .def("pop_back", (void(std::vector<ofTexture>::*)(void))&std::vector<ofTexture>::pop_back)
         .def("push_back", (void(std::vector<ofTexture>::*)(const char&))&std::vector<ofTexture>::push_back)
         .def("size", (unsigned int(std::vector<ofTexture>::*)(void))&std::vector<ofTexture>::size)
         .def("swap",(void(std::vector<ofTexture>::*)(std::vector<ofTexture>&))&std::vector<ofTexture>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofPath>
         
         class_<vector<ofPath> >("vectorOFpath")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofPath>::*)(void))&std::vector<ofPath>::capacity)
         .def("clear",(void(std::vector<ofPath>::*)(void))&std::vector<ofPath>::clear)
         .def("empty",(bool(std::vector<ofPath>::*)(void))&std::vector<ofPath>::empty)
         .def("get_allocator",(int&(std::vector<ofPath>::*)(void))&std::vector<ofPath>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofPath>::*)(void))&std::vector<ofPath>::max_size)
         .def("pop_back", (void(std::vector<ofPath>::*)(void))&std::vector<ofPath>::pop_back)
         .def("push_back", (void(std::vector<ofPath>::*)(const char&))&std::vector<ofPath>::push_back)
         .def("size", (unsigned int(std::vector<ofPath>::*)(void))&std::vector<ofPath>::size)
         .def("swap",(void(std::vector<ofPath>::*)(std::vector<ofPath>&))&std::vector<ofPath>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofBuffer>
         
         class_<vector<ofBuffer> >("vectorOFbuffer")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofBuffer>::*)(void))&std::vector<ofBuffer>::capacity)
         .def("clear",(void(std::vector<ofBuffer>::*)(void))&std::vector<ofBuffer>::clear)
         .def("empty",(bool(std::vector<ofBuffer>::*)(void))&std::vector<ofBuffer>::empty)
         .def("get_allocator",(int&(std::vector<ofBuffer>::*)(void))&std::vector<ofBuffer>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofBuffer>::*)(void))&std::vector<ofBuffer>::max_size)
         .def("pop_back", (void(std::vector<ofBuffer>::*)(void))&std::vector<ofBuffer>::pop_back)
         .def("push_back", (void(std::vector<ofBuffer>::*)(const char&))&std::vector<ofBuffer>::push_back)
         .def("size", (unsigned int(std::vector<ofBuffer>::*)(void))&std::vector<ofBuffer>::size)
         .def("swap",(void(std::vector<ofBuffer>::*)(std::vector<ofBuffer>&))&std::vector<ofBuffer>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofFile>
         
         class_<vector<ofFile> >("vectorOFfile")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofFile>::*)(void))&std::vector<ofFile>::capacity)
         .def("clear",(void(std::vector<ofFile>::*)(void))&std::vector<ofFile>::clear)
         .def("empty",(bool(std::vector<ofFile>::*)(void))&std::vector<ofFile>::empty)
         .def("get_allocator",(int&(std::vector<ofFile>::*)(void))&std::vector<ofFile>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofFile>::*)(void))&std::vector<ofFile>::max_size)
         .def("pop_back", (void(std::vector<ofFile>::*)(void))&std::vector<ofFile>::pop_back)
         .def("push_back", (void(std::vector<ofFile>::*)(const char&))&std::vector<ofFile>::push_back)
         .def("size", (unsigned int(std::vector<ofFile>::*)(void))&std::vector<ofFile>::size)
         .def("swap",(void(std::vector<ofFile>::*)(std::vector<ofFile>&))&std::vector<ofFile>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofVideoPlayer>
         
         class_<vector<ofVideoPlayer> >("vectorOFvideoPlayer")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofVideoPlayer>::*)(void))&std::vector<ofVideoPlayer>::capacity)
         .def("clear",(void(std::vector<ofVideoPlayer>::*)(void))&std::vector<ofVideoPlayer>::clear)
         .def("empty",(bool(std::vector<ofVideoPlayer>::*)(void))&std::vector<ofVideoPlayer>::empty)
         .def("get_allocator",(int&(std::vector<ofVideoPlayer>::*)(void))&std::vector<ofVideoPlayer>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofVideoPlayer>::*)(void))&std::vector<ofVideoPlayer>::max_size)
         .def("pop_back", (void(std::vector<ofVideoPlayer>::*)(void))&std::vector<ofVideoPlayer>::pop_back)
         .def("push_back", (void(std::vector<ofVideoPlayer>::*)(const char&))&std::vector<ofVideoPlayer>::push_back)
         .def("size", (unsigned int(std::vector<ofVideoPlayer>::*)(void))&std::vector<ofVideoPlayer>::size)
         .def("swap",(void(std::vector<ofVideoPlayer>::*)(std::vector<ofVideoPlayer>&))&std::vector<ofVideoPlayer>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofPixels>
         
         class_<vector<ofPixels> >("vectorOFpixels")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofPixels>::*)(void))&std::vector<ofPixels>::capacity)
         .def("clear",(void(std::vector<ofPixels>::*)(void))&std::vector<ofPixels>::clear)
         .def("empty",(bool(std::vector<ofPixels>::*)(void))&std::vector<ofPixels>::empty)
         .def("get_allocator",(int&(std::vector<ofPixels>::*)(void))&std::vector<ofPixels>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofPixels>::*)(void))&std::vector<ofPixels>::max_size)
         .def("pop_back", (void(std::vector<ofPixels>::*)(void))&std::vector<ofPixels>::pop_back)
         .def("push_back", (void(std::vector<ofPixels>::*)(const char&))&std::vector<ofPixels>::push_back)
         .def("size", (unsigned int(std::vector<ofPixels>::*)(void))&std::vector<ofPixels>::size)
         .def("swap",(void(std::vector<ofPixels>::*)(std::vector<ofPixels>&))&std::vector<ofPixels>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofTrueTypeFont>
         
         class_<vector<ofTrueTypeFont> >("vectorOFfont")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofTrueTypeFont>::*)(void))&std::vector<ofTrueTypeFont>::capacity)
         .def("clear",(void(std::vector<ofTrueTypeFont>::*)(void))&std::vector<ofTrueTypeFont>::clear)
         .def("empty",(bool(std::vector<ofTrueTypeFont>::*)(void))&std::vector<ofTrueTypeFont>::empty)
         .def("get_allocator",(int&(std::vector<ofTrueTypeFont>::*)(void))&std::vector<ofTrueTypeFont>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofTrueTypeFont>::*)(void))&std::vector<ofTrueTypeFont>::max_size)
         .def("pop_back", (void(std::vector<ofTrueTypeFont>::*)(void))&std::vector<ofTrueTypeFont>::pop_back)
         .def("push_back", (void(std::vector<ofTrueTypeFont>::*)(const char&))&std::vector<ofTrueTypeFont>::push_back)
         .def("size", (unsigned int(std::vector<ofTrueTypeFont>::*)(void))&std::vector<ofTrueTypeFont>::size)
         .def("swap",(void(std::vector<ofTrueTypeFont>::*)(std::vector<ofTrueTypeFont>&))&std::vector<ofTrueTypeFont>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofImage>
         
         class_<vector<ofImage> >("vectorOFimage")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofImage>::*)(void))&std::vector<ofImage>::capacity)
         .def("clear",(void(std::vector<ofImage>::*)(void))&std::vector<ofImage>::clear)
         .def("empty",(bool(std::vector<ofImage>::*)(void))&std::vector<ofImage>::empty)
         .def("get_allocator",(int&(std::vector<ofImage>::*)(void))&std::vector<ofImage>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofImage>::*)(void))&std::vector<ofImage>::max_size)
         .def("pop_back", (void(std::vector<ofImage>::*)(void))&std::vector<ofImage>::pop_back)
         .def("push_back", (void(std::vector<ofImage>::*)(const char&))&std::vector<ofImage>::push_back)
         .def("size", (unsigned int(std::vector<ofImage>::*)(void))&std::vector<ofImage>::size)
         .def("swap",(void(std::vector<ofImage>::*)(std::vector<ofImage>&))&std::vector<ofImage>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofRectangle>
         
         class_<vector<ofRectangle> >("vectorOFrectangle")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofRectangle>::*)(void))&std::vector<ofRectangle>::capacity)
         .def("clear",(void(std::vector<ofRectangle>::*)(void))&std::vector<ofRectangle>::clear)
         .def("empty",(bool(std::vector<ofRectangle>::*)(void))&std::vector<ofRectangle>::empty)
         .def("get_allocator",(int&(std::vector<ofRectangle>::*)(void))&std::vector<ofRectangle>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofRectangle>::*)(void))&std::vector<ofRectangle>::max_size)
         .def("pop_back", (void(std::vector<ofRectangle>::*)(void))&std::vector<ofRectangle>::pop_back)
         .def("push_back", (void(std::vector<ofRectangle>::*)(const char&))&std::vector<ofRectangle>::push_back)
         .def("size", (unsigned int(std::vector<ofRectangle>::*)(void))&std::vector<ofRectangle>::size)
         .def("swap",(void(std::vector<ofRectangle>::*)(std::vector<ofRectangle>&))&std::vector<ofRectangle>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofSoundPlayer>
         
         class_<vector<ofSoundPlayer> >("vectorOFsoundPlayer")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofSoundPlayer>::*)(void))&std::vector<ofSoundPlayer>::capacity)
         .def("clear",(void(std::vector<ofSoundPlayer>::*)(void))&std::vector<ofSoundPlayer>::clear)
         .def("empty",(bool(std::vector<ofSoundPlayer>::*)(void))&std::vector<ofSoundPlayer>::empty)
         .def("get_allocator",(int&(std::vector<ofSoundPlayer>::*)(void))&std::vector<ofSoundPlayer>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofSoundPlayer>::*)(void))&std::vector<ofSoundPlayer>::max_size)
         .def("pop_back", (void(std::vector<ofSoundPlayer>::*)(void))&std::vector<ofSoundPlayer>::pop_back)
         .def("push_back", (void(std::vector<ofSoundPlayer>::*)(const char&))&std::vector<ofSoundPlayer>::push_back)
         .def("size", (unsigned int(std::vector<ofSoundPlayer>::*)(void))&std::vector<ofSoundPlayer>::size)
         .def("swap",(void(std::vector<ofSoundPlayer>::*)(std::vector<ofSoundPlayer>&))&std::vector<ofSoundPlayer>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofxCvColorImage>
         
         class_<vector<ofxCvColorImage> >("vectorOFXcvColorImage")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofxCvColorImage>::*)(void))&std::vector<ofxCvColorImage>::capacity)
         .def("clear",(void(std::vector<ofxCvColorImage>::*)(void))&std::vector<ofxCvColorImage>::clear)
         .def("empty",(bool(std::vector<ofxCvColorImage>::*)(void))&std::vector<ofxCvColorImage>::empty)
         .def("get_allocator",(int&(std::vector<ofxCvColorImage>::*)(void))&std::vector<ofxCvColorImage>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofxCvColorImage>::*)(void))&std::vector<ofxCvColorImage>::max_size)
         .def("pop_back", (void(std::vector<ofxCvColorImage>::*)(void))&std::vector<ofxCvColorImage>::pop_back)
         .def("push_back", (void(std::vector<ofxCvColorImage>::*)(const char&))&std::vector<ofxCvColorImage>::push_back)
         .def("size", (unsigned int(std::vector<ofxCvColorImage>::*)(void))&std::vector<ofxCvColorImage>::size)
         .def("swap",(void(std::vector<ofxCvColorImage>::*)(std::vector<ofxCvColorImage>&))&std::vector<ofxCvColorImage>::swap),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section std::vector<ofxCvGrayscaleImage>
         
         class_<vector<ofxCvGrayscaleImage> >("vectorOFXcvGrayscaleImage")
         .def(constructor<>())
         .def("capacity",(size_t(std::vector<ofxCvGrayscaleImage>::*)(void))&std::vector<ofxCvGrayscaleImage>::capacity)
         .def("clear",(void(std::vector<ofxCvGrayscaleImage>::*)(void))&std::vector<ofxCvGrayscaleImage>::clear)
         .def("empty",(bool(std::vector<ofxCvGrayscaleImage>::*)(void))&std::vector<ofxCvGrayscaleImage>::empty)
         .def("get_allocator",(int&(std::vector<ofxCvGrayscaleImage>::*)(void))&std::vector<ofxCvGrayscaleImage>::get_allocator)
         .def("max_size", (unsigned int(std::vector<ofxCvGrayscaleImage>::*)(void))&std::vector<ofxCvGrayscaleImage>::max_size)
         .def("pop_back", (void(std::vector<ofxCvGrayscaleImage>::*)(void))&std::vector<ofxCvGrayscaleImage>::pop_back)
         .def("push_back", (void(std::vector<ofxCvGrayscaleImage>::*)(const char&))&std::vector<ofxCvGrayscaleImage>::push_back)
         .def("size", (unsigned int(std::vector<ofxCvGrayscaleImage>::*)(void))&std::vector<ofxCvGrayscaleImage>::size)
         .def("swap",(void(std::vector<ofxCvGrayscaleImage>::*)(std::vector<ofxCvGrayscaleImage>&))&std::vector<ofxCvGrayscaleImage>::swap)
         
		];
        
        
        //////////////////////////////////////////////////////////////
		///////////////////////////////
		/// OpenFrameworks 007 api wrapper
		///
		module(lua, "of")
		[
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section arduino [ofArduino]
         
         // NOT AVAILABLE IN GAMUZA 0.3 IN THE LIVE CODING SYSTEM, MANAGED FROM GUI (arduino module)
         
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section 3D [ofNode, ofEasyCam, ofMesh, ofCamera]
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofNode
         
         class_<ofNode>("node")
		 .def(constructor<>())
		 .def("setParent", (void(ofNode::*)(ofNode&)) &ofNode::setParent)
         .def("clearParent", (void(ofNode::*)(void)) &ofNode::clearParent)
         .def("getParent", (ofNode(ofNode::*)(void)) &ofNode::getParent)
         .def("getPosition", (ofVec3f(ofNode::*)(void)) &ofNode::getPosition)
         .def("getX", (float(ofNode::*)(void)) &ofNode::getX)
         .def("getY", (float(ofNode::*)(void)) &ofNode::getY)
         .def("getZ", (float(ofNode::*)(void)) &ofNode::getZ)
         .def("getXAxis", (ofVec3f(ofNode::*)(void)) &ofNode::getXAxis)
         .def("getYAxis", (ofVec3f(ofNode::*)(void)) &ofNode::getYAxis)
         .def("getZAxis", (ofVec3f(ofNode::*)(void)) &ofNode::getZAxis)
         .def("getSideDir", (ofVec3f(ofNode::*)(void)) &ofNode::getSideDir)
         .def("getLookAtDir", (ofVec3f(ofNode::*)(void)) &ofNode::getLookAtDir)
         .def("getUpDir", (ofVec3f(ofNode::*)(void)) &ofNode::getUpDir)
         .def("getPitch", (float(ofNode::*)(void)) &ofNode::getPitch)
         .def("getHeading", (float(ofNode::*)(void)) &ofNode::getHeading)
         .def("getRoll", (float(ofNode::*)(void)) &ofNode::getRoll)
         .def("getOrientationQuat", (ofQuaternion(ofNode::*)(void)) &ofNode::getOrientationQuat)
         .def("getOrientationEuler", (ofVec3f(ofNode::*)(void)) &ofNode::getOrientationEuler)
         .def("getScale", (ofVec3f(ofNode::*)(void)) &ofNode::getScale)
         .def("getLocalTransformMatrix", (ofMatrix4x4(ofNode::*)(void)) &ofNode::getLocalTransformMatrix)
         .def("getGlobalTransformMatrix", (ofMatrix4x4(ofNode::*)(void)) &ofNode::getGlobalTransformMatrix)
         .def("getGlobalPosition", (ofVec3f(ofNode::*)(void)) &ofNode::getGlobalPosition)
         .def("getGlobalOrientation", (ofQuaternion(ofNode::*)(void)) &ofNode::getGlobalOrientation)
         .def("setTransformMatrix", (void(ofNode::*)(const ofMatrix4x4&)) &ofNode::setTransformMatrix)
         .def("setPosition", (void(ofNode::*)(float,float,float)) &ofNode::setPosition)
         .def("setPosition", (void(ofNode::*)(const ofVec3f&)) &ofNode::setPosition)
         .def("setGlobalPosition", (void(ofNode::*)(float,float,float)) &ofNode::setGlobalPosition)
         .def("setGlobalPosition", (void(ofNode::*)(const ofVec3f&)) &ofNode::setGlobalPosition)
         .def("setOrientation", (void(ofNode::*)(const ofQuaternion&)) &ofNode::setOrientation)
         .def("setOrientation", (void(ofNode::*)(const ofVec3f&)) &ofNode::setOrientation)
         .def("setGlobalOrientation", (void(ofNode::*)(const ofQuaternion&)) &ofNode::setGlobalOrientation)
         .def("setScale", (void(ofNode::*)(float,float,float)) &ofNode::setScale)
         .def("setScale", (void(ofNode::*)(const ofVec3f&)) &ofNode::setScale)         
         .def("move", (void(ofNode::*)(float,float,float)) &ofNode::move)
         .def("move", (void(ofNode::*)(const ofVec3f&)) &ofNode::move)
         .def("truck", (void(ofNode::*)(float)) &ofNode::truck)
         .def("boom", (void(ofNode::*)(float)) &ofNode::boom)
         .def("dolly", (void(ofNode::*)(float)) &ofNode::dolly)
         .def("tilt", (void(ofNode::*)(float)) &ofNode::tilt)
         .def("pan", (void(ofNode::*)(float)) &ofNode::pan)
         .def("roll", (void(ofNode::*)(float)) &ofNode::roll)
         .def("rotate", (void(ofNode::*)(const ofQuaternion&)) &ofNode::rotate)
         .def("rotate", (void(ofNode::*)(float,const ofVec3f&)) &ofNode::rotate)
         .def("rotate", (void(ofNode::*)(float,float,float,float)) &ofNode::rotate)
         .def("rotateAround", (void(ofNode::*)(const ofQuaternion&,const ofVec3f&)) &ofNode::rotateAround)
         .def("rotateAround", (void(ofNode::*)(float,const ofVec3f&,const ofVec3f&)) &ofNode::rotateAround)
         .def("lookAt", (void(ofNode::*)(const ofVec3f&,ofVec3f)) &ofNode::lookAt)
         .def("lookAt", (void(ofNode::*)(ofNode&,const ofVec3f&)) &ofNode::lookAt)
         .def("orbit", (void(ofNode::*)(float,float,float,const ofVec3f&)) &ofNode::orbit)
         .def("orbit", (void(ofNode::*)(float,float,float,ofNode&)) &ofNode::orbit)
         .def("transformGL", (void(ofNode::*)(void)) &ofNode::transformGL)
         .def("restoreTransformGL", (void(ofNode::*)(void)) &ofNode::restoreTransformGL)
         .def("resetTransform", (void(ofNode::*)(void)) &ofNode::resetTransform)
         .def("draw", (void(ofNode::*)(void)) &ofNode::draw),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofEasyCam
         
         class_<ofEasyCam>("easyCam")
		 .def(constructor<>())
         .def("beginCamera", (void(ofEasyCam::*)(ofRectangle)) &ofEasyCam::begin)
         .def("endCamera", (void(ofEasyCam::*)(void)) &ofEasyCam::end)
         .def("reset", (void(ofEasyCam::*)(void)) &ofEasyCam::reset)
         .def("setTarget", (void(ofEasyCam::*)(const ofVec3f&)) &ofEasyCam::setTarget)
         .def("setTarget", (void(ofEasyCam::*)(ofNode&)) &ofEasyCam::setTarget)
         .def("getTarget", (ofNode(ofEasyCam::*)(void)) &ofEasyCam::getTarget)
         .def("setDistance", (void(ofEasyCam::*)(float)) &ofEasyCam::setDistance)
         .def("getDistance", (float(ofEasyCam::*)(void)) &ofEasyCam::getDistance)
         .def("setDrag", (void(ofEasyCam::*)(float)) &ofEasyCam::setDrag)
         .def("getDrag", (float(ofEasyCam::*)(void)) &ofEasyCam::getDrag)
         .def("enableMouseInput", (void(ofEasyCam::*)(void)) &ofEasyCam::enableMouseInput)
         .def("disableMouseInput", (void(ofEasyCam::*)(void)) &ofEasyCam::disableMouseInput)
         .def("getMouseInputEnabled", (bool(ofEasyCam::*)(void)) &ofEasyCam::getMouseInputEnabled),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofMesh
         
         class_<ofMesh>("mesh")
		 .def(constructor<>())
         .def("setMode", (void(ofMesh::*)(ofPrimitiveMode)) &ofMesh::setMode)
         .def("getMode", (ofPrimitiveMode(ofMesh::*)(void)) &ofMesh::getMode)
         .def("clear", (void(ofMesh::*)(void)) &ofMesh::clear)
         .def("setupIndicesAuto", (void(ofMesh::*)(void)) &ofMesh::setupIndicesAuto)
         .def("getVertex", (ofVec3f(ofMesh::*)(int)) &ofMesh::getVertex)
         //.def("removeVertex", (void(ofMesh::*)(int)) &ofMesh::removeVertex)
         .def("clearVertices", (void(ofMesh::*)(void)) &ofMesh::clearVertices)
         .def("getNormal", (ofVec3f(ofMesh::*)(int)) &ofMesh::getNormal)
         //.def("removeNormal", (void(ofMesh::*)(int)) &ofMesh::removeNormal)
         .def("clearNormals", (void(ofMesh::*)(void)) &ofMesh::clearNormals)
         .def("getColor", (ofFloatColor(ofMesh::*)(int)) &ofMesh::getColor)
         //.def("removeColor", (void(ofMesh::*)(int)) &ofMesh::removeColor)
         .def("clearColors", (void(ofMesh::*)(void)) &ofMesh::clearColors)
         .def("getTexCoord", (ofVec2f(ofMesh::*)(int)) &ofMesh::getTexCoord)
         //.def("removeTexCoord", (void(ofMesh::*)(int)) &ofMesh::removeTexCoord)
         .def("clearTexCoords", (void(ofMesh::*)(void)) &ofMesh::clearTexCoords)
         .def("getIndex", (ofIndexType(ofMesh::*)(int)) &ofMesh::getTexCoord)
         .def("addIndex", (void(ofMesh::*)(ofIndexType)) &ofMesh::addIndex)
         //.def("removeIndex", (void(ofMesh::*)(int)) &ofMesh::removeIndex)
         .def("setIndex", (void(ofMesh::*)(int,ofIndexType)) &ofMesh::setIndex)
         .def("clearIndices", (void(ofMesh::*)(void)) &ofMesh::clearIndices)
         .def("addTriangle", (void(ofMesh::*)(ofIndexType,ofIndexType,ofIndexType)) &ofMesh::addTriangle)
         .def("getNumVertices", (int(ofMesh::*)(void)) &ofMesh::getNumVertices)
         .def("getNumColors", (int(ofMesh::*)(void)) &ofMesh::getNumColors)
         .def("getNumNormals", (int(ofMesh::*)(void)) &ofMesh::getNumNormals)
         .def("getNumTexCoords", (int(ofMesh::*)(void)) &ofMesh::getNumTexCoords)
         .def("getNumIndices", (int(ofMesh::*)(void)) &ofMesh::getNumIndices)
         .def("getVerticesPointer", (ofVec3f*(ofMesh::*)(void)) &ofMesh::getVerticesPointer)
         .def("getColorsPointer", (ofFloatColor*(ofMesh::*)(void)) &ofMesh::getColorsPointer)
         .def("getNormalsPointer", (ofVec3f*(ofMesh::*)(void)) &ofMesh::getNormalsPointer)
         .def("getTexCoordsPointer", (ofVec2f*(ofMesh::*)(void)) &ofMesh::getTexCoordsPointer)
         .def("getIndexPointer", (ofIndexType*(ofMesh::*)(void)) &ofMesh::getIndexPointer)
         .def("getVertices", (ofVec3f(ofMesh::*)(void)) &ofMesh::getVertices)
         .def("getColors", (ofFloatColor(ofMesh::*)(void)) &ofMesh::getColors)
         .def("getNormals", (ofVec3f(ofMesh::*)(void)) &ofMesh::getNormals)
         .def("getTexCoords", (ofVec2f(ofMesh::*)(void)) &ofMesh::getTexCoords)
         .def("getIndices", (ofIndexType(ofMesh::*)(void)) &ofMesh::getIndices)
         .def("setName", (void(ofMesh::*)(string)) &ofMesh::setName)
         .def("haveVertsChanged", (bool(ofMesh::*)(void)) &ofMesh::haveVertsChanged)
         .def("haveColorsChanged", (bool(ofMesh::*)(void)) &ofMesh::haveColorsChanged)
         .def("haveNormalsChanged", (bool(ofMesh::*)(void)) &ofMesh::haveNormalsChanged)
         .def("haveTexCoordsChanged", (bool(ofMesh::*)(void)) &ofMesh::haveTexCoordsChanged)
         .def("haveIndicesChanged", (bool(ofMesh::*)(void)) &ofMesh::haveIndicesChanged)
         .def("hasVertices", (bool(ofMesh::*)(void)) &ofMesh::hasVertices)
         .def("hasColors", (bool(ofMesh::*)(void)) &ofMesh::hasColors)
         .def("hasNormals", (bool(ofMesh::*)(void)) &ofMesh::hasNormals)
         .def("hasTexCoords", (bool(ofMesh::*)(void)) &ofMesh::hasTexCoords)
         .def("hasIndices", (bool(ofMesh::*)(void)) &ofMesh::hasIndices)
         .def("drawVertices", (void(ofMesh::*)(void)) &ofMesh::drawVertices)
         .def("drawWireframe", (void(ofMesh::*)(void)) &ofMesh::drawWireframe)
         .def("drawFaces", (void(ofMesh::*)(void)) &ofMesh::drawFaces)
         .def("draw", (void(ofMesh::*)(void)) &ofMesh::draw)
         .def("addVertex", (void(ofMesh::*)(const ofVec3f&)) &ofMesh::addVertex)
         .def("setVertex", (void(ofMesh::*)(int,const ofVec3f&)) &ofMesh::setVertex)
         .def("addNormal", (void(ofMesh::*)(const ofVec3f&)) &ofMesh::addNormal)
         .def("setNormal", (void(ofMesh::*)(int,const ofVec3f&)) &ofMesh::setNormal)
         .def("addColor", (void(ofMesh::*)(const ofFloatColor&)) &ofMesh::addColor)
         .def("setColor", (void(ofMesh::*)(int,const ofFloatColor&)) &ofMesh::setColor)
         .def("addTexCoord", (void(ofMesh::*)(const ofVec2f&)) &ofMesh::addTexCoord)
         .def("setTexCoord", (void(ofMesh::*)(int,const ofVec2f&)) &ofMesh::setTexCoord)
         .def("addIndices", (void(ofMesh::*)(const ofIndexType*,int)) &ofMesh::addIndices),
         //.def("getCentroid", (ofVec3f(ofMesh::*)(void)) &ofMesh::getCentroid)
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofCamera
         
         class_<ofCamera>("camera")
		 .def(constructor<>())
		 .def("setFov", (void(ofCamera::*)(float)) &ofCamera::setFov)
         .def("setNearClip", (void(ofCamera::*)(float)) &ofCamera::setNearClip)
		 .def("setFarClip", (void(ofCamera::*)(float)) &ofCamera::setFarClip)
         .def("enableOrtho", (void(ofCamera::*)(void)) &ofCamera::enableOrtho)
         .def("disableOrtho", (void(ofCamera::*)(void)) &ofCamera::disableOrtho)
         .def("getOrtho", (bool(ofCamera::*)(void)) &ofCamera::getOrtho)
         .def("getModelViewMatrix", (ofMatrix4x4(ofCamera::*)(void)) &ofCamera::getModelViewMatrix)
         //.def("getFov", (float(ofCamera::*)(void)) &ofCamera::getFov)
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
         
         .def("getProjectionMatrix", (ofMatrix4x4(ofCamera::*)(ofRectangle)) &ofCamera::getProjectionMatrix)
         .def("getModelViewProjectionMatrix", (ofMatrix4x4(ofCamera::*)(ofRectangle)) &ofCamera::getModelViewProjectionMatrix)
         .def("worldToScreen", (ofVec3f(ofCamera::*)(ofVec3f,ofRectangle)) &ofCamera::worldToScreen)
         .def("screenToWorld", (ofVec3f(ofCamera::*)(ofVec3f,ofRectangle)) &ofCamera::screenToWorld)
         .def("worldToCamera", (ofVec3f(ofCamera::*)(ofVec3f,ofRectangle)) &ofCamera::worldToCamera)
         .def("cameraToWorld", (ofVec3f(ofCamera::*)(ofVec3f,ofRectangle)) &ofCamera::cameraToWorld)
         
         .def("beginCamera", (void(ofCamera::*)(ofRectangle)) &ofCamera::begin)
         .def("endCamera", (void(ofCamera::*)(void)) &ofCamera::end),
         
         def("drawAxis", (void(*)(float)) &ofDrawAxis),
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section math [ofMath, ofMatrix3x3, ofMatrix4x4, ofQuaternion, ofVec2f, ofVec3f, ofVec4f]
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofMath
         
         def("seedRandom", (void(*)(void)) &ofSeedRandom),
		 def("seedRandom", (void(*)(int)) &ofSeedRandom),
         def("random", (float(*)(float)) &ofRandom),
		 def("random", (float(*)(float,float)) &ofRandom),
		 def("randomf", (float(*)(void)) &ofRandomf),
		 def("randomuf", (float(*)(void)) &ofRandomuf),
         def("nextPow2", (int(*)(int)) &ofNextPow2),
		 def("normalize", &ofNormalize),
		 def("map", (float(*)(float,float,float,float,float,bool)) &ofMap),
         def("map", &map5),
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
         //def("angleSumRadians", (float(*)(float,float)) &ofAngleSumRadians),
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
         def("insidePoly", (bool(*)(float,float,const vector<ofPoint>&)) &ofInsidePoly),
         def("insidePoly", (bool(*)(const ofPoint&,const vector<ofPoint>&)) &ofInsidePoly),
         def("lineSegmentIntersection", (bool(*)(ofPoint,ofPoint,ofPoint,ofPoint,ofPoint)) &ofLineSegmentIntersection),
         def("bezierPoint", (ofPoint(*)(ofPoint,ofPoint,ofPoint,ofPoint,float)) &ofBezierPoint),
         def("curvePoint", (ofPoint(*)(ofPoint,ofPoint,ofPoint,ofPoint,float)) &ofCurvePoint),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofMatrix3x3
         
         class_<ofMatrix3x3>("matrix3x3")
		 .def(constructor<>())
		 .def(constructor<float,float,float,float,float,float,float,float,float>())
         .def("set", (void(ofMatrix3x3::*)(float,float,float,float,float,float,float,float,float)) &ofMatrix3x3::set)
         .def("transpose", (void(ofMatrix3x3::*)(void)) &ofMatrix3x3::transpose)
         //.def("transpose", (void(ofMatrix3x3::*)(const ofMatrix3x3&)) &ofMatrix3x3::transpose)
         //.def("determinant", (float(ofMatrix3x3::*)(void)) &ofMatrix3x3::determinant)
         .def("determinant", (float(ofMatrix3x3::*)(const ofMatrix3x3&)) &ofMatrix3x3::determinant)
         .def("invert", (void(ofMatrix3x3::*)(void)) &ofMatrix3x3::invert)
         .def("inverse", (ofMatrix3x3(ofMatrix3x3::*)(const ofMatrix3x3&)) &ofMatrix3x3::inverse)
         .def(self + other<const ofMatrix3x3&>())
         .def(self - other<const ofMatrix3x3&>())
         .def(self * other<const ofMatrix3x3&>())
         .def(self + other<float>())
         .def(self - other<float>())
         .def(self * other<float>())
         .def(self / other<float>())
         .def_readonly("a", &ofMatrix3x3::a)
		 .def_readonly("b", &ofMatrix3x3::b)
         .def_readonly("c", &ofMatrix3x3::c)
		 .def_readonly("d", &ofMatrix3x3::d)
         .def_readonly("e", &ofMatrix3x3::e)
		 .def_readonly("f", &ofMatrix3x3::f)
         .def_readonly("g", &ofMatrix3x3::g)
		 .def_readonly("h", &ofMatrix3x3::h)
         .def_readonly("i", &ofMatrix3x3::i),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofMatrix4x4
         
         class_<ofMatrix4x4>("matrix4x4")
		 .def(constructor<>())
         .def(constructor<const ofMatrix4x4&>())
         .def(constructor<const ofQuaternion&>())
         //.def(constructor<float,float,float,float,float,float,float,float,float,float,float,float,float,float,float,float>())
         .def("getRowAsVec3f", (ofVec3f(ofMatrix4x4::*)(int)) &ofMatrix4x4::getRowAsVec3f)
         .def("getRowAsVec4f", (ofVec4f(ofMatrix4x4::*)(int)) &ofMatrix4x4::getRowAsVec4f)
         .def("isValid", (bool(ofMatrix4x4::*)(void)) &ofMatrix4x4::isValid)
         .def("isNaN", (bool(ofMatrix4x4::*)(void)) &ofMatrix4x4::isNaN)
         .def("set", (void(ofMatrix4x4::*)(const ofMatrix4x4&)) &ofMatrix4x4::set)
         .def("isIdentity", (bool(ofMatrix4x4::*)(void)) &ofMatrix4x4::isIdentity)
         .def("makeIdentityMatrix", (void(ofMatrix4x4::*)(void)) &ofMatrix4x4::makeIdentityMatrix)
         .def("makeScaleMatrix", (void(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::makeScaleMatrix)
         .def("makeScaleMatrix", (void(ofMatrix4x4::*)(float,float,float)) &ofMatrix4x4::makeScaleMatrix)
         .def("makeTranslationMatrix", (void(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::makeTranslationMatrix)
         .def("makeTranslationMatrix", (void(ofMatrix4x4::*)(float,float,float)) &ofMatrix4x4::makeTranslationMatrix)
         .def("makeRotationMatrix", (void(ofMatrix4x4::*)(float,const ofVec3f&)) &ofMatrix4x4::makeRotationMatrix)
         .def("makeRotationMatrix", (void(ofMatrix4x4::*)(float,float,float,float)) &ofMatrix4x4::makeRotationMatrix)
         .def("makeRotationMatrix", (void(ofMatrix4x4::*)(const ofQuaternion&)) &ofMatrix4x4::makeRotationMatrix)
         .def("makeRotationMatrix", (void(ofMatrix4x4::*)(float,const ofVec3f&,float,const ofVec3f&,float,const ofVec3f&)) &ofMatrix4x4::makeRotationMatrix)
         .def("makeInvertOf", (bool(ofMatrix4x4::*)(const ofMatrix4x4&)) &ofMatrix4x4::makeInvertOf)
         .def("makeOrthoNormalOf", (void(ofMatrix4x4::*)(const ofMatrix4x4&)) &ofMatrix4x4::makeOrthoNormalOf)
         .def("makeFromMultiplicationOf", (void(ofMatrix4x4::*)(const ofMatrix4x4&,const ofMatrix4x4&)) &ofMatrix4x4::makeFromMultiplicationOf)
         .def("getInverse", (void(ofMatrix4x4::*)(void)) &ofMatrix4x4::getInverse)
         .def("makeOrthoMatrix", (void(ofMatrix4x4::*)(double,double,double,double,double,double)) &ofMatrix4x4::makeOrthoMatrix)
         .def("makeOrtho2DMatrix", (void(ofMatrix4x4::*)(double,double,double,double)) &ofMatrix4x4::makeOrtho2DMatrix)
         .def("makeFrustumMatrix", (void(ofMatrix4x4::*)(double,double,double,double,double,double)) &ofMatrix4x4::makeFrustumMatrix)
         .def("makePerspectiveMatrix", (void(ofMatrix4x4::*)(double,double,double,double)) &ofMatrix4x4::makePerspectiveMatrix)
         .def("makeLookAtMatrix", (void(ofMatrix4x4::*)(const ofVec3f&,const ofVec3f&,const ofVec3f&)) &ofMatrix4x4::makeLookAtMatrix)
         .def("makeLookAtViewMatrix", (void(ofMatrix4x4::*)(const ofVec3f&,const ofVec3f&,const ofVec3f&)) &ofMatrix4x4::makeLookAtViewMatrix)
         .def("getOrtho", (bool(ofMatrix4x4::*)(double&,double&,double&,double&,double&,double&)) &ofMatrix4x4::getOrtho)
         .def("getFrustum", (bool(ofMatrix4x4::*)(double&,double&,double&,double&,double&,double&)) &ofMatrix4x4::getFrustum)
         .def("getPerspective", (bool(ofMatrix4x4::*)(double&,double&,double&,double&)) &ofMatrix4x4::getPerspective)
         .def("getLookAt", (void(ofMatrix4x4::*)(ofVec3f&,ofVec3f&,ofVec3f&,float)) &ofMatrix4x4::getLookAt)
         .def("decompose", (void(ofMatrix4x4::*)(ofVec3f&,ofQuaternion&,ofVec3f&,ofQuaternion&)) &ofMatrix4x4::decompose)
         //.def("postMult", (ofVec3f(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::postMult)
         //.def("postMult", (ofVec4f(ofMatrix4x4::*)(const ofVec4f&)) &ofMatrix4x4::postMult)
         .def(self * other<const ofVec3f&>())
         .def(self * other<const ofVec4f&>())
         .def(self * other<const ofMatrix4x4&>())
         //.def("preMult", (ofVec3f(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::preMult)
         //.def("preMult", (ofVec4f(ofMatrix4x4::*)(const ofVec4f&)) &ofMatrix4x4::preMult)
         .def("setRotate", (void(ofMatrix4x4::*)(const ofQuaternion&)) &ofMatrix4x4::setRotate)
         .def("setTranslation", (void(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::setTranslation)
         .def("rotate", (void(ofMatrix4x4::*)(const ofQuaternion&)) &ofMatrix4x4::rotate)
         .def("translate", (void(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::translate)
         .def("scale", (void(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::scale)
         .def("glRotate", (void(ofMatrix4x4::*)(const ofQuaternion&)) &ofMatrix4x4::glRotate)
         .def("glTranslate", (void(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::glTranslate)
         .def("glScale", (void(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::glScale)
         .def("getRotate", (ofQuaternion(ofMatrix4x4::*)(void)) &ofMatrix4x4::getRotate)
         .def("getTranslation", (ofVec3f(ofMatrix4x4::*)(void)) &ofMatrix4x4::getTranslation)
         .def("getScale", (ofVec3f(ofMatrix4x4::*)(void)) &ofMatrix4x4::getScale)
         //.def("newIdentityMatrix", (ofMatrix4x4(ofMatrix4x4::*)(void)) &ofMatrix4x4::newIdentityMatrix)
         //.def("newScaleMatrix", (ofMatrix4x4(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::newScaleMatrix)
         //.def("newTranslationMatrix", (ofMatrix4x4(ofMatrix4x4::*)(const ofVec3f&)) &ofMatrix4x4::newTranslationMatrix)
         //.def("newRotationMatrix", (ofMatrix4x4(ofMatrix4x4::*)(const ofVec3f&,const ofVec3f&)) &ofMatrix4x4::newRotationMatrix)
         //.def("newRotationMatrix", (ofMatrix4x4(ofMatrix4x4::*)(float,float,float,float)) &ofMatrix4x4::newRotationMatrix)
         //.def("newRotationMatrix", (ofMatrix4x4(ofMatrix4x4::*)(float,const ofVec3f&)) &ofMatrix4x4::newRotationMatrix)
         //.def("newRotationMatrix", (ofMatrix4x4(ofMatrix4x4::*)(float,const ofVec3f&,float,const ofVec3f&,float,const ofVec3f&)) &ofMatrix4x4::newRotationMatrix)
         //.def("getInverseOf", (ofMatrix4x4(ofMatrix4x4::*)(const ofMatrix4x4&)) &ofMatrix4x4::getInverseOf)
         //.def("getTransposedOf", (ofMatrix4x4(ofMatrix4x4::*)(const ofMatrix4x4&)) &ofMatrix4x4::getTransposedOf)
         //.def("getOrthoNormalOf", (ofMatrix4x4(ofMatrix4x4::*)(const ofMatrix4x4&)) &ofMatrix4x4::getOrthoNormalOf)
         //def("newOrthoMatrix", (ofMatrix4x4(ofMatrix4x4::*)(double,double,double,double,double,double)) &ofMatrix4x4::newOrthoMatrix)
         //.def("newOrtho2DMatrix", (ofMatrix4x4(ofMatrix4x4::*)(double,double,double,double)) &ofMatrix4x4::newOrtho2DMatrix)
         //.def("newFrustumMatrix", (ofMatrix4x4(ofMatrix4x4::*)(double,double,double,double,double,double)) &ofMatrix4x4::newFrustumMatrix)
         //.def("newPerspectiveMatrix", (ofMatrix4x4(ofMatrix4x4::*)(double,double,double,double)) &ofMatrix4x4::newPerspectiveMatrix)
         //.def("newLookAtMatrix", (ofMatrix4x4(ofMatrix4x4::*)(const ofVec3f&,const ofVec3f&,const ofVec3f&)) &ofMatrix4x4::newLookAtMatrix)
         //.def("transform3x3", (ofVec3f(ofMatrix4x4::*)(const ofVec3f&,const ofMatrix4x4&)) &ofMatrix4x4::transform3x3)
         //.def("transform3x3", (ofVec3f(ofMatrix4x4::*)(const ofMatrix4x4&,const ofVec3f&)) &ofMatrix4x4::transform3x3)
         .def_readonly("_mat", &ofMatrix4x4::_mat),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofQuaternion
         
         class_<ofQuaternion>("quaternion")
		 .def(constructor<>())
		 .def(constructor<float,float,float,float>())
		 .def(constructor<const ofVec4f&>())
         .def(constructor<float,const ofVec3f&>())
         .def(constructor<float,const ofVec3f&,float,const ofVec3f&,float,const ofVec3f&>())
         .def(self == other<const ofQuaternion&>())
         .def(self + other<const ofQuaternion&>())
         .def(self - other<const ofQuaternion&>())
         .def(self * other<const ofQuaternion&>())
         .def(self / other<const ofQuaternion&>())
         .def(self * other<const ofVec3f&>())
         .def(self * other<float>())
         .def(self / other<float>())
         .def("asVec4", (ofVec4f(ofQuaternion::*)(void)) &ofQuaternion::asVec4)
         .def("asVec3", (ofVec3f(ofQuaternion::*)(void)) &ofQuaternion::asVec3)
         .def("set", (void(ofQuaternion::*)(float,float,float,float)) &ofQuaternion::set)
         .def("set", (void(ofQuaternion::*)(const ofVec4f&)) &ofQuaternion::set)
         .def("set", (void(ofQuaternion::*)(const ofMatrix4x4&)) &ofQuaternion::set)
         .def("get", (void(ofQuaternion::*)(const ofMatrix4x4&)) &ofQuaternion::get)
         //.def("x", (float(ofQuaternion::*)(void)) &ofQuaternion::x)
         //.def("y", (float(ofQuaternion::*)(void)) &ofQuaternion::y)
         //.def("z", (float(ofQuaternion::*)(void)) &ofQuaternion::z)
         //.def("w", (float(ofQuaternion::*)(void)) &ofQuaternion::w)
         .def("zeroRotation", (bool(ofQuaternion::*)(void)) &ofQuaternion::zeroRotation)
         .def("length", (float(ofQuaternion::*)(void)) &ofQuaternion::length)
         .def("length2", (float(ofQuaternion::*)(void)) &ofQuaternion::length2)
         .def("conj", (ofQuaternion(ofQuaternion::*)(void)) &ofQuaternion::conj)
         .def("inverse", (ofQuaternion(ofQuaternion::*)(void)) &ofQuaternion::inverse)
         .def("makeRotate", (void(ofQuaternion::*)(float,float,float,float)) &ofQuaternion::makeRotate)
         .def("makeRotate", (void(ofQuaternion::*)(float,const ofVec3f&)) &ofQuaternion::makeRotate)
         .def("makeRotate", (void(ofQuaternion::*)(float,const ofVec3f&,float,const ofVec3f&,float,const ofVec3f&)) &ofQuaternion::makeRotate)
         .def("makeRotate", (void(ofQuaternion::*)(const ofVec3f&,const ofVec3f&)) &ofQuaternion::makeRotate)
         .def("makeRotate_original", (void(ofQuaternion::*)(const ofVec3f&,const ofVec3f&)) &ofQuaternion::makeRotate_original)
         //.def("getRotate", (void(ofQuaternion::*)(float&,float&,float&,float&)) &ofQuaternion::getRotate)
         //.def("getRotate", (void(ofQuaternion::*)(float&,ofVec3f&)) &ofQuaternion::getRotate)
         .def("getEuler", (void(ofQuaternion::*)(void)) &ofQuaternion::getEuler)
         .def("slerp", (void(ofQuaternion::*)(float,const ofQuaternion&,const ofQuaternion&)) &ofQuaternion::slerp)
         .def_readonly("_v", &ofQuaternion::_v),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofVec2f
         
         class_<ofVec2f>("vec2f")
		 .def(constructor<>())
		 .def(constructor<float,float>())
		 .def(constructor<const ofVec3f&>())
		 .def(constructor<const ofVec4f&>())
		 .def("set", (void(ofVec2f::*)(float,float)) &ofVec2f::set)
         .def("set", (void(ofVec2f::*)(const ofVec2f&)) &ofVec2f::set)
         .def(self == other<const ofVec2f&>())
         .def("match", (bool(ofVec2f::*)(const ofVec2f&,float)) &ofVec2f::match)
         .def("align", (bool(ofVec2f::*)(const ofVec2f&,float)) &ofVec2f::align)
         .def("alignRad", (bool(ofVec2f::*)(const ofVec2f&,float)) &ofVec2f::alignRad)
         .def(self + other<const ofVec2f&>())
         .def(self - other<const ofVec2f&>())
         .def(self * other<const ofVec2f&>())
         .def(self / other<const ofVec2f&>())
         .def(self + other<const float>())
         .def(self - other<const float>())
         .def(self * other<const float>())
         .def(self / other<const float>())
         .def("getScaled", (ofVec2f(ofVec2f::*)(const float)) &ofVec2f::getScaled)
         .def("scale", (ofVec2f&(ofVec2f::*)(const float)) &ofVec2f::scale)
         //.def("getRotated", (ofVec2f(ofVec2f::*)(float)) &ofVec2f::getRotated)
         //.def("getRotatedRad", (ofVec2f(ofVec2f::*)(float)) &ofVec2f::getRotatedRad)
         //.def("rotate", (ofVec2f(ofVec2f::*)(float)) &ofVec2f::rotate)
         //.def("rotateRad", (ofVec2f(ofVec2f::*)(float)) &ofVec2f::rotateRad)
         //.def("getRotated", (ofVec2f(ofVec2f::*)(float,const ofVec2f&)) &ofVec2f::getRotated)
         //.def("getRotatedRad", (ofVec2f(ofVec2f::*)(float,const ofVec2f&)) &ofVec2f::getRotatedRad)
         //.def("rotate", (ofVec2f(ofVec2f::*)(float,const ofVec2f&)) &ofVec2f::rotate)
         //.def("rotateRad", (ofVec2f(ofVec2f::*)(float,const ofVec2f&)) &ofVec2f::rotateRad)
		 //.def("rotated", (ofVec2f(ofVec2f::*)(float,const ofVec2f&)) &ofVec2f::rotated)
         .def("getMapped", (ofVec2f(ofVec2f::*)(const ofVec2f&,const ofVec2f&,const ofVec2f&)) &ofVec2f::getMapped)
         .def("map", (ofVec2f&(ofVec2f::*)(const ofVec2f&,const ofVec2f&,const ofVec2f&)) &ofVec2f::map)
         .def("distance", (float(ofVec2f::*)(const ofVec2f&)) &ofVec2f::distance)
         .def("squareDistance", (float(ofVec2f::*)(const ofVec2f&)) &ofVec2f::squareDistance)
         .def("getInterpolated", (ofVec2f(ofVec2f::*)(const ofVec2f&,float)) &ofVec2f::getInterpolated)
         .def("interpolate", (ofVec2f&(ofVec2f::*)(const ofVec2f&,float)) &ofVec2f::interpolate)
         .def("getMiddle", (ofVec2f(ofVec2f::*)(const ofVec2f&)) &ofVec2f::getMiddle)
         .def("middle", (ofVec2f&(ofVec2f::*)(const ofVec2f&)) &ofVec2f::middle)
         .def("average", (ofVec2f&(ofVec2f::*)(const ofVec2f&,int)) &ofVec2f::average)
         .def("getNormalized", (ofVec2f(ofVec2f::*)(void)) &ofVec2f::getNormalized)
         .def("normalize", (ofVec2f&(ofVec2f::*)(void)) &ofVec2f::normalize)
         .def("getLimited", (ofVec2f(ofVec2f::*)(float)) &ofVec2f::getLimited)
         .def("limit", (ofVec2f&(ofVec2f::*)(float)) &ofVec2f::limit)
         .def("getPerpendicular", (ofVec2f(ofVec2f::*)(void)) &ofVec2f::getPerpendicular)
         .def("perpendicular", (ofVec2f&(ofVec2f::*)(void)) &ofVec2f::perpendicular)
         .def("length", (float(ofVec2f::*)(void)) &ofVec2f::length)
         .def("squareLength", (float(ofVec2f::*)(void)) &ofVec2f::squareLength)
         .def("angle", (float(ofVec2f::*)(const ofVec2f&)) &ofVec2f::angle)
         .def("angleRad", (float(ofVec2f::*)(const ofVec2f&)) &ofVec2f::angleRad)
         .def("dot", (float(ofVec2f::*)(const ofVec2f&)) &ofVec2f::dot)
         .def("rescaled", (ofVec2f(ofVec2f::*)(const float)) &ofVec2f::rescaled)
         .def("rescale", (ofVec2f&(ofVec2f::*)(const float)) &ofVec2f::rescale)
         //.def("rotated", (ofVec2f(ofVec2f::*)(float)) &ofVec2f::rotated)
         .def("normalized", (ofVec2f(ofVec2f::*)(void)) &ofVec2f::normalized)
         .def("limited", (ofVec2f(ofVec2f::*)(float)) &ofVec2f::limited)
         .def("perpendiculared", (ofVec2f(ofVec2f::*)(void)) &ofVec2f::perpendiculared)
         .def("lengthSquared", (float(ofVec2f::*)(void)) &ofVec2f::lengthSquared)
         .def("interpolated", (ofVec2f(ofVec2f::*)(const ofVec2f&,float)) &ofVec2f::interpolated)
         .def("middled", (ofVec2f(ofVec2f::*)(const ofVec2f&)) &ofVec2f::middled)
         .def("mapped", (ofVec2f(ofVec2f::*)(const ofVec2f&,const ofVec2f&,const ofVec2f&)) &ofVec2f::mapped)
         .def("distanceSquared", (float(ofVec2f::*)(const ofVec2f&)) &ofVec2f::distanceSquared)
         .def_readwrite("x", &ofVec2f::x)
		 .def_readwrite("y", &ofVec2f::y),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofVec3f
         
         class_<ofVec3f>("vec3f")
		 .def(constructor<>())
		 .def(constructor<float,float,float>())
		 .def(constructor<const ofVec2f&>())
		 .def(constructor<const ofVec4f&>())
		 .def("set", (void(ofVec3f::*)(float,float,float)) &ofVec3f::set)
		 .def("set", (void(ofVec3f::*)(const ofVec3f&)) &ofVec3f::set)
         .def(self == other<const ofVec3f&>())
         .def("match", (bool(ofVec3f::*)(const ofVec3f&,float)) &ofVec3f::match)
         .def("align", (bool(ofVec3f::*)(const ofVec3f&,float)) &ofVec3f::align)
         .def("alignRad", (bool(ofVec3f::*)(const ofVec3f&,float)) &ofVec3f::alignRad)
         .def(self + other<const ofVec3f&>())
         .def(self - other<const ofVec3f&>())
         .def(self * other<const ofVec3f&>())
         .def(self / other<const ofVec3f&>())
         .def(self + other<const float>())
         .def(self - other<const float>())
         .def(self * other<const float>())
         .def(self / other<const float>())
         .def("getScaled", (ofVec3f(ofVec3f::*)(const float)) &ofVec3f::getScaled)
         .def("scale", (ofVec3f&(ofVec3f::*)(const float)) &ofVec3f::scale)
         //.def("getRotated", (ofVec3f(ofVec3f::*)(float)) &ofVec3f::getRotated)
         //.def("getRotatedRad", (ofVec3f(ofVec3f::*)(float)) &ofVec3f::getRotatedRad)
         //.def("rotate", (ofVec3f&(ofVec3f::*)(float)) &ofVec3f::rotate)
         //.def("rotateRad", (ofVec3f&(ofVec3f::*)(float)) &ofVec3f::rotateRad)
         //.def("getRotated", (ofVec3f(ofVec3f::*)(float,const ofVec3f&)) &ofVec3f::getRotated)
         //.def("getRotatedRad", (ofVec3f(ofVec3f::*)(float,const ofVec3f&)) &ofVec3f::getRotatedRad)
         //.def("rotate", (ofVec3f&(ofVec3f::*)(float,const ofVec3f&)) &ofVec3f::rotate)
         //.def("rotateRad", (ofVec3f&(ofVec3f::*)(float,const ofVec3f&)) &ofVec3f::rotateRad)
		 //.def("rotated", (ofVec3f(ofVec3f::*)(float,const ofVec3f&)) &ofVec3f::rotated)
         .def("getMapped", (ofVec3f(ofVec3f::*)(const ofVec3f&,const ofVec3f&,const ofVec3f&)) &ofVec3f::getMapped)
         .def("map", (ofVec3f&(ofVec3f::*)(const ofVec3f&,const ofVec3f&,const ofVec3f&)) &ofVec3f::map)
         .def("distance", (float(ofVec3f::*)(const ofVec3f&)) &ofVec3f::distance)
         .def("squareDistance", (float(ofVec3f::*)(const ofVec3f&)) &ofVec3f::squareDistance)
         .def("getInterpolated", (ofVec3f(ofVec3f::*)(const ofVec3f&,float)) &ofVec3f::getInterpolated)
         .def("interpolate", (ofVec3f&(ofVec3f::*)(const ofVec3f&,float)) &ofVec3f::interpolate)
         .def("getMiddle", (ofVec3f(ofVec3f::*)(const ofVec3f&)) &ofVec3f::getMiddle)
         .def("middle", (ofVec3f&(ofVec3f::*)(const ofVec3f&)) &ofVec3f::middle)
         .def("average", (ofVec3f&(ofVec3f::*)(const ofVec3f&,int)) &ofVec3f::average)
         .def("getNormalized", (ofVec3f(ofVec3f::*)(void)) &ofVec3f::getNormalized)
         .def("normalize", (ofVec3f&(ofVec3f::*)(void)) &ofVec3f::normalize)
         .def("getLimited", (ofVec3f(ofVec3f::*)(float)) &ofVec3f::getLimited)
         .def("limit", (ofVec3f&(ofVec3f::*)(float)) &ofVec3f::limit)
         .def("getCrossed", (ofVec3f(ofVec3f::*)(const ofVec3f&)) &ofVec3f::getCrossed)
         .def("cross", (ofVec3f&(ofVec3f::*)(const ofVec3f&)) &ofVec3f::cross)
         .def("getPerpendicular", (ofVec3f(ofVec3f::*)(void)) &ofVec3f::getPerpendicular)
         .def("perpendicular", (ofVec3f&(ofVec3f::*)(void)) &ofVec3f::perpendicular)
         .def("length", (float(ofVec3f::*)(void)) &ofVec3f::length)
         .def("squareLength", (float(ofVec3f::*)(void)) &ofVec3f::squareLength)
         .def("angle", (float(ofVec3f::*)(const ofVec3f&)) &ofVec3f::angle)
         .def("angleRad", (float(ofVec3f::*)(const ofVec3f&)) &ofVec3f::angleRad)
         .def("dot", (float(ofVec3f::*)(const ofVec3f&)) &ofVec3f::dot)
         .def("rescaled", (ofVec3f(ofVec3f::*)(const float)) &ofVec3f::rescaled)
         .def("rescale", (ofVec3f&(ofVec3f::*)(const float)) &ofVec3f::rescale)
         //.def("rotated", (ofVec3f(ofVec3f::*)(float)) &ofVec3f::rotated)
         .def("normalized", (ofVec3f(ofVec3f::*)(void)) &ofVec3f::normalized)
         .def("limited", (ofVec3f(ofVec3f::*)(float)) &ofVec3f::limited)
         .def("perpendiculared", (ofVec3f(ofVec3f::*)(void)) &ofVec3f::perpendiculared)
         .def("lengthSquared", (float(ofVec3f::*)(void)) &ofVec3f::lengthSquared)
         .def("interpolated", (ofVec3f(ofVec3f::*)(const ofVec3f&,float)) &ofVec3f::interpolated)
         .def("middled", (ofVec3f(ofVec3f::*)(const ofVec3f&)) &ofVec3f::middled)
         .def("mapped", (ofVec3f(ofVec3f::*)(const ofVec3f&,const ofVec3f&,const ofVec3f&)) &ofVec3f::mapped)
         .def("distanceSquared", (float(ofVec3f::*)(const ofVec3f&)) &ofVec3f::distanceSquared)
         .def_readwrite("x", &ofVec3f::x)
		 .def_readwrite("y", &ofVec3f::y)
         .def_readwrite("z", &ofVec3f::z),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofVec4f
         
         class_<ofVec4f>("vec4f")
		 .def(constructor<>())
		 .def(constructor<float,float,float,float>())
		 .def(constructor<const ofVec2f&>())
		 .def(constructor<const ofVec3f&>())
		 .def("set", (void(ofVec4f::*)(float,float,float,float)) &ofVec4f::set)
		 .def("set", (void(ofVec4f::*)(const ofVec4f&)) &ofVec4f::set)
         .def(self == other<const ofVec4f&>())
         .def("match", (bool(ofVec4f::*)(const ofVec4f&,float)) &ofVec4f::match)
         .def(self + other<const ofVec4f&>())
         .def(self - other<const ofVec4f&>())
         .def(self * other<const ofVec4f&>())
         .def(self / other<const ofVec4f&>())
         .def(self + other<const float>())
         .def(self - other<const float>())
         .def(self * other<const float>())
         .def(self / other<const float>())
         .def("getScaled", (ofVec4f(ofVec4f::*)(const float)) &ofVec4f::getScaled)
         .def("scale", (ofVec4f&(ofVec4f::*)(const float)) &ofVec4f::scale)
         //.def("getRotated", (ofVec4f(ofVec4f::*)(float)) &ofVec4f::getRotated)
         //.def("getRotatedRad", (ofVec4f(ofVec4f::*)(float)) &ofVec4f::getRotatedRad)
         //.def("rotate", (ofVec4f(ofVec4f::*)(float)) &ofVec4f::rotate)
         //.def("rotateRad", (ofVec4f(ofVec4f::*)(float)) &ofVec4f::rotateRad)
         //.def("getRotated", (ofVec4f(ofVec4f::*)(float,const ofVec4f&)) &ofVec4f::getRotated)
         //.def("getRotatedRad", (ofVec4f(ofVec4f::*)(float,const ofVec4f&)) &ofVec4f::getRotatedRad)
         //.def("rotate", (ofVec4f(ofVec4f::*)(float,const ofVec4f&)) &ofVec4f::rotate)
         //.def("rotateRad", (ofVec4f(ofVec4f::*)(float,const ofVec4f&)) &ofVec4f::rotateRad)
		 //.def("rotated", (ofVec4f(ofVec4f::*)(float,const ofVec4f&)) &ofVec4f::rotated)
         .def("distance", (float(ofVec4f::*)(const ofVec4f&)) &ofVec4f::distance)
         .def("squareDistance", (float(ofVec4f::*)(const ofVec4f&)) &ofVec4f::squareDistance)
         .def("getInterpolated", (ofVec4f(ofVec4f::*)(const ofVec4f&,float)) &ofVec4f::getInterpolated)
         .def("interpolate", (ofVec4f&(ofVec4f::*)(const ofVec4f&,float)) &ofVec4f::interpolate)
         .def("getMiddle", (ofVec4f(ofVec4f::*)(const ofVec4f&)) &ofVec4f::getMiddle)
         .def("middle", (ofVec4f&(ofVec4f::*)(const ofVec4f&)) &ofVec4f::middle)
         .def("average", (ofVec4f&(ofVec4f::*)(const ofVec4f&,int)) &ofVec4f::average)
         .def("getNormalized", (ofVec4f(ofVec4f::*)(void)) &ofVec4f::getNormalized)
         .def("normalize", (ofVec4f&(ofVec4f::*)(void)) &ofVec4f::normalize)
         .def("getLimited", (ofVec4f(ofVec4f::*)(float)) &ofVec4f::getLimited)
         .def("limit", (ofVec4f&(ofVec4f::*)(float)) &ofVec4f::limit)
         .def("length", (float(ofVec4f::*)(void)) &ofVec4f::length)
         .def("squareLength", (float(ofVec4f::*)(void)) &ofVec4f::squareLength)
         .def("dot", (float(ofVec4f::*)(const ofVec4f&)) &ofVec4f::dot)
         .def("rescaled", (ofVec4f(ofVec4f::*)(const float)) &ofVec4f::rescaled)
         .def("rescale", (ofVec4f&(ofVec4f::*)(const float)) &ofVec4f::rescale)
         .def("normalized", (ofVec4f(ofVec4f::*)(void)) &ofVec4f::normalized)
         .def("limited", (ofVec4f(ofVec4f::*)(float)) &ofVec4f::limited)
         .def("lengthSquared", (float(ofVec4f::*)(void)) &ofVec4f::lengthSquared)
         .def("interpolated", (ofVec4f(ofVec4f::*)(const ofVec4f&,float)) &ofVec4f::interpolated)
         .def("middled", (ofVec4f(ofVec4f::*)(const ofVec4f&)) &ofVec4f::middled)
         .def("distanceSquared", (float(ofVec4f::*)(const ofVec4f&)) &ofVec4f::distanceSquared)
         .def_readwrite("x", &ofVec4f::x)
		 .def_readwrite("y", &ofVec4f::y)
         .def_readwrite("z", &ofVec4f::z)
         .def_readwrite("w", &ofVec4f::w),
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section gl [ofMaterials, ofFbo, ofGLRenderer, ofVbo, ofTextureData, ofShader, ofVboMesh, ofTexture, ofGLUtils, ofLight]
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofMaterial
         
         class_<ofMaterial>("material")
		 .def(constructor<>())
         .def("setColors", (void(ofMaterial::*)(ofFloatColor,ofFloatColor,ofFloatColor,ofFloatColor)) &ofMaterial::setColors)
         .def("setDiffuseColor", (void(ofMaterial::*)(ofFloatColor)) &ofMaterial::setDiffuseColor)
         .def("setAmbientColor", (void(ofMaterial::*)(ofFloatColor)) &ofMaterial::setAmbientColor)
         .def("setSpecularColor", (void(ofMaterial::*)(ofFloatColor)) &ofMaterial::setSpecularColor)
         .def("setEmissiveColor", (void(ofMaterial::*)(ofFloatColor)) &ofMaterial::setEmissiveColor)
         .def("setShininess", (void(ofMaterial::*)(float)) &ofMaterial::setShininess)
         .def("getDiffuseColor", (ofFloatColor(ofMaterial::*)(void)) &ofMaterial::getDiffuseColor)
         .def("getAmbientColor", (ofFloatColor(ofMaterial::*)(void)) &ofMaterial::getAmbientColor)
         .def("getSpecularColor", (ofFloatColor(ofMaterial::*)(void)) &ofMaterial::getSpecularColor)
         .def("getEmissiveColor", (ofFloatColor(ofMaterial::*)(void)) &ofMaterial::getEmissiveColor)
         .def("getShininess", (float(ofMaterial::*)(void)) &ofMaterial::getShininess)
         .def("beginMaterial", (void(ofMaterial::*)(void)) &ofMaterial::begin)
		 .def("endMaterial", (void(ofMaterial::*)(void)) &ofMaterial::end),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofFbo
         
         class_<ofFbo>("fbo")
		 .def(constructor<>())
         .def(constructor<const ofFbo&>())
		 .def("allocate", (void(ofFbo::*)(int,int,int,int)) &ofFbo::allocate) // int width, int height, int internalformat, int numSamples
         .def("draw", (void(ofFbo::*)(float,float)) &ofFbo::draw)
         .def("draw", (void(ofFbo::*)(float,float,float,float)) &ofFbo::draw)
         .def("setAnchorPercent", (void(ofFbo::*)(float,float)) &ofFbo::setAnchorPercent)
         .def("setAnchorPoint", (void(ofFbo::*)(float,float)) &ofFbo::setAnchorPoint)
         .def("resetAnchor", (void(ofFbo::*)(void)) &ofFbo::resetAnchor)
         .def("setDefaultTextureIndex", (void(ofFbo::*)(int)) &ofFbo::setDefaultTextureIndex)
         .def("getDefaultTextureIndex", (int(ofFbo::*)(void)) &ofFbo::getDefaultTextureIndex)
         //.def("getTextureReference", (ofTexture(ofFbo::*)(void)) &ofFbo::getTextureReference)
         //.def("getTextureReference", (ofTexture(ofFbo::*)(int)) &ofFbo::getTextureReference)
         .def("setUseTexture", (void(ofFbo::*)(bool)) &ofFbo::setUseTexture)
         .def("beginFbo", (void(ofFbo::*)(void)) &ofFbo::begin)
		 .def("endFbo", (void(ofFbo::*)(void)) &ofFbo::end)
         .def("readToPixels", (void(ofFbo::*)(ofPixels&,int)) &ofFbo::readToPixels)
         .def("getWidth", (float(ofFbo::*)(void)) &ofFbo::getWidth)
		 .def("getHeight", (float(ofFbo::*)(void)) &ofFbo::getHeight)
         .def("bind", (void(ofFbo::*)(void)) &ofFbo::bind)
		 .def("unbind", (void(ofFbo::*)(void)) &ofFbo::unbind)
         .def("getNumTextures", (int(ofFbo::*)(void)) &ofFbo::getNumTextures)
         .def("getFbo", (GLuint(ofFbo::*)(void)) &ofFbo::getFbo)
         .def("getDepthBuffer", (GLuint(ofFbo::*)(void)) &ofFbo::getDepthBuffer)
         .def("getStencilBuffer", (GLuint(ofFbo::*)(void)) &ofFbo::getStencilBuffer)
         .def("checkGLSupport", (bool(*)(void)) &ofFbo::checkGLSupport)
         .def("maxColorAttachments", (int(*)(void)) &ofFbo::maxColorAttachments)
         .def("maxDrawBuffers", (int(*)(void)) &ofFbo::maxDrawBuffers)
         .def("maxSamples", (int(*)(void)) &ofFbo::maxSamples),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofGLRenderer
         
         class_<ofGLRenderer>("GLRenderer")
		 .def(constructor<bool>())
         .def("getType", (string(ofGLRenderer::*)(void)) &ofGLRenderer::getType)
         .def("setCurrentFBO", (void(ofGLRenderer::*)(ofFbo*)) &ofGLRenderer::setCurrentFBO)
         .def("update", (void(ofGLRenderer::*)(void)) &ofGLRenderer::update)
         .def("drawMesh", (void(ofGLRenderer::*)(ofMesh&)) &ofGLRenderer::draw)
         .def("drawMesh", (void(ofGLRenderer::*)(ofMesh&,ofPolyRenderMode)) &ofGLRenderer::draw)
         .def("drawPoly", (void(ofGLRenderer::*)(ofPolyline&)) &ofGLRenderer::draw)
         .def("drawPath", (void(ofGLRenderer::*)(ofPath&)) &ofGLRenderer::draw)
         .def("drawImage", (void(ofGLRenderer::*)(ofImage&,float,float,float,float,float)) &ofGLRenderer::draw)
         .def("rendersPathPrimitives", (bool(ofGLRenderer::*)(void)) &ofGLRenderer::rendersPathPrimitives)
         .def("pushView", (void(ofGLRenderer::*)(void)) &ofGLRenderer::pushView)
         .def("popView", (void(ofGLRenderer::*)(void)) &ofGLRenderer::popView)
         .def("viewport", (void(ofGLRenderer::*)(ofRectangle)) &ofGLRenderer::viewport)
         .def("viewport", (void(ofGLRenderer::*)(float,float,float,float,bool)) &ofGLRenderer::viewport)
         .def("setupScreenPerspective", (void(ofGLRenderer::*)(float,float,ofOrientation,bool,float,float,float)) &ofGLRenderer::setupScreenPerspective)
         .def("setupScreenOrtho", (void(ofGLRenderer::*)(float,float,ofOrientation,bool,float,float)) &ofGLRenderer::setupScreenOrtho)
         .def("getCurrentViewport", (ofRectangle(ofGLRenderer::*)(void)) &ofGLRenderer::getCurrentViewport)
         .def("getViewportWidth", (int(ofGLRenderer::*)(void)) &ofGLRenderer::getViewportWidth)
         .def("getViewportHeight", (int(ofGLRenderer::*)(void)) &ofGLRenderer::getViewportHeight)
         .def("pushMatrix", (void(ofGLRenderer::*)(void)) &ofGLRenderer::pushMatrix)
         .def("popMatrix", (void(ofGLRenderer::*)(void)) &ofGLRenderer::popMatrix)
         .def("translate", (void(ofGLRenderer::*)(const ofPoint&)) &ofGLRenderer::translate)
         .def("translate", (void(ofGLRenderer::*)(float,float,float)) &ofGLRenderer::translate)
         .def("scale", (void(ofGLRenderer::*)(float,float,float)) &ofGLRenderer::scale)
         .def("rotate", (void(ofGLRenderer::*)(float,float,float,float)) &ofGLRenderer::rotate)
         .def("rotate", (void(ofGLRenderer::*)(float)) &ofGLRenderer::rotate)
         .def("rotateX", (void(ofGLRenderer::*)(float)) &ofGLRenderer::rotateX)
         .def("rotateY", (void(ofGLRenderer::*)(float)) &ofGLRenderer::rotateY)
         .def("rotateZ", (void(ofGLRenderer::*)(float)) &ofGLRenderer::rotateZ)
         .def("setupGraphicDefaults", (void(ofGLRenderer::*)(void)) &ofGLRenderer::setupGraphicDefaults)
         .def("setupScreen", (void(ofGLRenderer::*)(void)) &ofGLRenderer::setupScreen)
         .def("setFillMode", (void(ofGLRenderer::*)(ofFillFlag)) &ofGLRenderer::setFillMode)
         .def("getFillMode", (ofFillFlag(ofGLRenderer::*)(void)) &ofGLRenderer::getFillMode)
         .def("setCircleResolution", (void(ofGLRenderer::*)(int)) &ofGLRenderer::setCircleResolution)
         .def("setRectMode", (void(ofGLRenderer::*)(ofRectMode)) &ofGLRenderer::setRectMode)
         .def("getRectMode", (ofRectMode(ofGLRenderer::*)(void)) &ofGLRenderer::getRectMode)
         .def("setLineWidth", (void(ofGLRenderer::*)(float)) &ofGLRenderer::setLineWidth)
         .def("setLineSmoothing", (void(ofGLRenderer::*)(bool)) &ofGLRenderer::setLineSmoothing)
         .def("setBlendMode", (void(ofGLRenderer::*)(ofBlendMode)) &ofGLRenderer::setBlendMode)
         .def("enablePointSprites", (void(ofGLRenderer::*)(void)) &ofGLRenderer::enablePointSprites)
         .def("disablePointSprites", (void(ofGLRenderer::*)(void)) &ofGLRenderer::disablePointSprites)
         .def("setColor", (void(ofGLRenderer::*)(int,int,int)) &ofGLRenderer::setColor)
         .def("setColor", (void(ofGLRenderer::*)(int,int,int,int)) &ofGLRenderer::setColor)
         .def("setColor", (void(ofGLRenderer::*)(const ofColor&)) &ofGLRenderer::setColor)
         .def("setColor", (void(ofGLRenderer::*)(const ofColor&,int)) &ofGLRenderer::setColor)
         .def("setColor", (void(ofGLRenderer::*)(int)) &ofGLRenderer::setColor)
         .def("setHexColor", (void(ofGLRenderer::*)(int)) &ofGLRenderer::setHexColor)
         .def("getBgColor", (ofFloatColor(ofGLRenderer::*)(void)) &ofGLRenderer::getBgColor)
         .def("bClearBg", (bool(ofGLRenderer::*)(void)) &ofGLRenderer::bClearBg)
         .def("background", (void(ofGLRenderer::*)(const ofColor&)) &ofGLRenderer::background)
         .def("background", (void(ofGLRenderer::*)(float)) &ofGLRenderer::background)
         .def("background", (void(ofGLRenderer::*)(int,float)) &ofGLRenderer::background)
         .def("background", (void(ofGLRenderer::*)(int,int,int,int)) &ofGLRenderer::background)
         .def("setBackgroundAuto", (void(ofGLRenderer::*)(bool)) &ofGLRenderer::setBackgroundAuto)
         .def("clear", (void(ofGLRenderer::*)(float,float,float,float)) &ofGLRenderer::clear)
         .def("clear", (void(ofGLRenderer::*)(float,float)) &ofGLRenderer::clear)
         .def("clearAlpha", (void(ofGLRenderer::*)(void)) &ofGLRenderer::clearAlpha)
         .def("drawLine", (void(ofGLRenderer::*)(float,float,float,float,float,float)) &ofGLRenderer::drawLine)
         .def("drawRectangle", (void(ofGLRenderer::*)(float,float,float,float,float)) &ofGLRenderer::drawRectangle)
         .def("drawTriangle", (void(ofGLRenderer::*)(float,float,float,float,float,float,float,float,float)) &ofGLRenderer::drawTriangle)
         .def("drawCircle", (void(ofGLRenderer::*)(float,float,float,float)) &ofGLRenderer::drawCircle)
         .def("drawEllipse", (void(ofGLRenderer::*)(float,float,float,float,float)) &ofGLRenderer::drawEllipse)
         .def("drawString", (void(ofGLRenderer::*)(string,float,float,float,ofDrawBitmapMode)) &ofGLRenderer::drawString),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofVbo
         
         class_<ofVbo>("vbo")
		 .def(constructor<>())
         .def(constructor<const ofVbo&>())
         .def("getVertId", (GLuint(ofVbo::*)(void)) &ofVbo::getVertId)
         .def("getColorId", (GLuint(ofVbo::*)(void)) &ofVbo::getColorId)
         .def("getNormalId", (GLuint(ofVbo::*)(void)) &ofVbo::getNormalId)
         .def("getTexCoordId", (GLuint(ofVbo::*)(void)) &ofVbo::getTexCoordId)
         .def("getIndexId", (GLuint(ofVbo::*)(void)) &ofVbo::getIndexId)
         .def("getIsAllocated", (bool(ofVbo::*)(void)) &ofVbo::getIsAllocated)
         .def("getUsingVerts", (bool(ofVbo::*)(void)) &ofVbo::getUsingVerts)
         .def("getUsingColors", (bool(ofVbo::*)(void)) &ofVbo::getUsingColors)
         .def("getUsingNormals", (bool(ofVbo::*)(void)) &ofVbo::getUsingNormals)
         .def("getUsingTexCoords", (bool(ofVbo::*)(void)) &ofVbo::getUsingTexCoords)
         .def("getUsingIndices", (bool(ofVbo::*)(void)) &ofVbo::getUsingIndices)
         .def("draw", (void(ofVbo::*)(int,int,int)) &ofVbo::draw)
         .def("drawElements", (void(ofVbo::*)(int,int)) &ofVbo::drawElements)
         .def("bind", (void(ofVbo::*)(void)) &ofVbo::bind)
         .def("unbind", (void(ofVbo::*)(void)) &ofVbo::unbind)
         .def("clear", (void(ofVbo::*)(void)) &ofVbo::clear)
         .def("setMesh", (void(ofVbo::*)(const ofMesh&,int)) &ofVbo::setMesh)
         .def("setVertex3Data", (void(ofVbo::*)(const ofVec3f*,int,int)) &ofVbo::setVertexData)
         .def("setVertex2Data", (void(ofVbo::*)(const ofVec2f*,int,int)) &ofVbo::setVertexData)
         .def("setColorData", (void(ofVbo::*)(const ofFloatColor*,int,int)) &ofVbo::setColorData)
         .def("setNormalData", (void(ofVbo::*)(const ofVec3f*,int,int)) &ofVbo::setNormalData)
         .def("setTexCoordData", (void(ofVbo::*)(const ofVec2f*,int,int)) &ofVbo::setTexCoordData)
         .def("setIndexData", (void(ofVbo::*)(const ofIndexType*,int,int)) &ofVbo::setIndexData)
         //.def("setVertexData", (void(ofVbo::*)(const float*,int,int,int,int)) &ofVbo::setColorData)
         //.def("setColorData", (void(ofVbo::*)(const ofFloatColor*,int,int,int)) &ofVbo::setColorData)
         //.def("setNormalData", (void(ofVbo::*)(const ofVec3f*,int,int,int)) &ofVbo::setNormalData)
         //.def("setTexCoordData", (void(ofVbo::*)(const ofVec2f*,int,int,int)) &ofVbo::setTexCoordData)
         .def("updateMesh", (void(ofVbo::*)(const ofMesh&)) &ofVbo::updateMesh)
         .def("updateVertex3Data", (void(ofVbo::*)(const ofVec3f*,int)) &ofVbo::updateVertexData)
         .def("updateVertex2Data", (void(ofVbo::*)(const ofVec2f*,int)) &ofVbo::updateVertexData)
         .def("updateColorData", (void(ofVbo::*)(const ofFloatColor*,int)) &ofVbo::updateColorData)
         .def("updateNormalData", (void(ofVbo::*)(const ofVec3f*,int)) &ofVbo::updateNormalData)
         .def("updateTexCoordDataF", (void(ofVbo::*)(const ofVec2f*,int)) &ofVbo::updateTexCoordData)
         .def("updateIndexData", (void(ofVbo::*)(const ofIndexType*,int)) &ofVbo::updateIndexData)
         .def("updateVertexDataF", (void(ofVbo::*)(const float*,int)) &ofVbo::updateVertexData)
         .def("updateColorDataF", (void(ofVbo::*)(const float*,int)) &ofVbo::updateColorData)
         .def("updateNormalDataF", (void(ofVbo::*)(const float*,int)) &ofVbo::updateNormalData)
         .def("updateTexCoordDataF", (void(ofVbo::*)(const float*,int)) &ofVbo::updateTexCoordData),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofTextureData
         
         class_<ofTextureData>("textureData")
		 .def(constructor<>())
         .def_readonly("textureID", &ofTextureData::textureID)
         .def_readonly("textureTarget", &ofTextureData::textureTarget)
         .def_readonly("glTypeInternal", &ofTextureData::glTypeInternal)
         .def_readonly("glType", &ofTextureData::glType)
         .def_readonly("pixelType", &ofTextureData::pixelType)
         .def_readonly("tex_t", &ofTextureData::tex_t)
         .def_readonly("tex_u", &ofTextureData::tex_u)
         .def_readonly("tex_w", &ofTextureData::tex_w)
         .def_readonly("tex_h", &ofTextureData::tex_h)
         .def_readonly("width", &ofTextureData::width)
         .def_readonly("height", &ofTextureData::height)
         .def_readonly("bFlipTexture", &ofTextureData::bFlipTexture)
         .def_readonly("compressionType", &ofTextureData::compressionType)
         .def_readonly("bAllocated", &ofTextureData::bAllocated),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofShader
         
         class_<ofShader>("shader")
		 .def(constructor<>())
         .def("load", (bool(ofShader::*)(string)) &ofShader::load)
         .def("load", (bool(ofShader::*)(string,string,string)) &ofShader::load)
         .def("unload", (void(ofShader::*)(void)) &ofShader::unload)
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
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofVboMesh
         
         class_<ofVboMesh>("vboMesh")
		 .def(constructor<>())
         .def(constructor<const ofMesh&>())
         .def("setUsage", (void(ofVboMesh::*)(int)) &ofVboMesh::setUsage)
         
         .def("setMode", (void(ofVboMesh::*)(ofPrimitiveMode)) &ofVboMesh::setMode)
         .def("getMode", (ofPrimitiveMode(ofVboMesh::*)(void)) &ofVboMesh::getMode)
         .def("clear", (void(ofVboMesh::*)(void)) &ofVboMesh::clear)
         .def("setupIndicesAuto", (void(ofVboMesh::*)(void)) &ofVboMesh::setupIndicesAuto)
         .def("getVertex", (ofVec3f(ofVboMesh::*)(int)) &ofVboMesh::getVertex)
         //.def("removeVertex", (void(ofVboMesh::*)(int)) &ofVboMesh::removeVertex)
         .def("clearVertices", (void(ofVboMesh::*)(void)) &ofVboMesh::clearVertices)
         .def("getNormal", (ofVec3f(ofVboMesh::*)(int)) &ofVboMesh::getNormal)
         //.def("removeNormal", (void(ofVboMesh::*)(int)) &ofVboMesh::removeNormal)
         .def("clearNormals", (void(ofVboMesh::*)(void)) &ofVboMesh::clearNormals)
         .def("getColor", (ofFloatColor(ofVboMesh::*)(int)) &ofVboMesh::getColor)
         //.def("removeColor", (void(ofVboMesh::*)(int)) &ofVboMesh::removeColor)
         .def("clearColors", (void(ofVboMesh::*)(void)) &ofVboMesh::clearColors)
         .def("getTexCoord", (ofVec2f(ofVboMesh::*)(int)) &ofVboMesh::getTexCoord)
         //.def("removeTexCoord", (void(ofVboMesh::*)(int)) &ofVboMesh::removeTexCoord)
         .def("clearTexCoords", (void(ofVboMesh::*)(void)) &ofVboMesh::clearTexCoords)
         .def("getIndex", (ofIndexType(ofVboMesh::*)(int)) &ofVboMesh::getTexCoord)
         .def("addIndex", (void(ofVboMesh::*)(ofIndexType)) &ofVboMesh::addIndex)
         //.def("removeIndex", (void(ofVboMesh::*)(int)) &ofVboMesh::removeIndex)
         .def("setIndex", (void(ofVboMesh::*)(int,ofIndexType)) &ofVboMesh::setIndex)
         .def("clearIndices", (void(ofVboMesh::*)(void)) &ofVboMesh::clearIndices)
         .def("addTriangle", (void(ofVboMesh::*)(ofIndexType,ofIndexType,ofIndexType)) &ofVboMesh::addTriangle)
         .def("getNumVertices", (int(ofVboMesh::*)(void)) &ofVboMesh::getNumVertices)
         .def("getNumColors", (int(ofVboMesh::*)(void)) &ofVboMesh::getNumColors)
         .def("getNumNormals", (int(ofVboMesh::*)(void)) &ofVboMesh::getNumNormals)
         .def("getNumTexCoords", (int(ofVboMesh::*)(void)) &ofVboMesh::getNumTexCoords)
         .def("getNumIndices", (int(ofVboMesh::*)(void)) &ofVboMesh::getNumIndices)
         .def("getVerticesPointer", (ofVec3f*(ofVboMesh::*)(void)) &ofVboMesh::getVerticesPointer)
         .def("getColorsPointer", (ofFloatColor*(ofVboMesh::*)(void)) &ofVboMesh::getColorsPointer)
         .def("getNormalsPointer", (ofVec3f*(ofVboMesh::*)(void)) &ofVboMesh::getNormalsPointer)
         .def("getTexCoordsPointer", (ofVec2f*(ofVboMesh::*)(void)) &ofVboMesh::getTexCoordsPointer)
         .def("getIndexPointer", (ofIndexType*(ofVboMesh::*)(void)) &ofVboMesh::getIndexPointer)
         .def("getVertices", (ofVec3f(ofVboMesh::*)(void)) &ofVboMesh::getVertices)
         .def("getColors", (ofFloatColor(ofVboMesh::*)(void)) &ofVboMesh::getColors)
         .def("getNormals", (ofVec3f(ofVboMesh::*)(void)) &ofVboMesh::getNormals)
         .def("getTexCoords", (ofVec2f(ofVboMesh::*)(void)) &ofVboMesh::getTexCoords)
         .def("getIndices", (ofIndexType(ofVboMesh::*)(void)) &ofVboMesh::getIndices)
         .def("setName", (void(ofVboMesh::*)(string)) &ofVboMesh::setName)
         .def("haveVertsChanged", (bool(ofVboMesh::*)(void)) &ofVboMesh::haveVertsChanged)
         .def("haveColorsChanged", (bool(ofVboMesh::*)(void)) &ofVboMesh::haveColorsChanged)
         .def("haveNormalsChanged", (bool(ofVboMesh::*)(void)) &ofVboMesh::haveNormalsChanged)
         .def("haveTexCoordsChanged", (bool(ofVboMesh::*)(void)) &ofVboMesh::haveTexCoordsChanged)
         .def("haveIndicesChanged", (bool(ofVboMesh::*)(void)) &ofVboMesh::haveIndicesChanged)
         .def("hasVertices", (bool(ofVboMesh::*)(void)) &ofVboMesh::hasVertices)
         .def("hasColors", (bool(ofVboMesh::*)(void)) &ofVboMesh::hasColors)
         .def("hasNormals", (bool(ofVboMesh::*)(void)) &ofVboMesh::hasNormals)
         .def("hasTexCoords", (bool(ofVboMesh::*)(void)) &ofVboMesh::hasTexCoords)
         .def("hasIndices", (bool(ofVboMesh::*)(void)) &ofVboMesh::hasIndices)
         .def("drawVertices", (void(ofVboMesh::*)(void)) &ofVboMesh::drawVertices)
         .def("drawWireframe", (void(ofVboMesh::*)(void)) &ofVboMesh::drawWireframe)
         .def("drawFaces", (void(ofVboMesh::*)(void)) &ofVboMesh::drawFaces)
         .def("draw", (void(ofVboMesh::*)(void)) &ofVboMesh::draw)
         .def("addVertex", (void(ofVboMesh::*)(const ofVec3f&)) &ofVboMesh::addVertex)
         .def("setVertex", (void(ofVboMesh::*)(int,const ofVec3f&)) &ofVboMesh::setVertex)
         .def("addNormal", (void(ofVboMesh::*)(const ofVec3f&)) &ofVboMesh::addNormal)
         .def("setNormal", (void(ofVboMesh::*)(int,const ofVec3f&)) &ofVboMesh::setNormal)
         .def("addColor", (void(ofVboMesh::*)(const ofFloatColor&)) &ofVboMesh::addColor)
         .def("setColor", (void(ofVboMesh::*)(int,const ofFloatColor&)) &ofVboMesh::setColor)
         .def("addTexCoord", (void(ofVboMesh::*)(const ofVec2f&)) &ofVboMesh::addTexCoord)
         .def("setTexCoord", (void(ofVboMesh::*)(int,const ofVec2f&)) &ofVboMesh::setTexCoord)
         .def("addIndices", (void(ofVboMesh::*)(const ofIndexType*,int)) &ofVboMesh::addIndices),
         //.def("getCentroid", (ofVec3f(ofVboMesh::*)(void)) &ofVboMesh::getCentroid),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofTexture
         
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
         .def("bAllocated", (bool(ofTexture::*)(void)) &ofTexture::bAllocated)
         .def("getCoordFromPoint", (ofPoint(ofTexture::*)(float,float)) &ofTexture::getCoordFromPoint)
         .def("getCoordFromPercent", (ofPoint(ofTexture::*)(float,float)) &ofTexture::getCoordFromPercent)
         .def("setTextureWrap", (void(ofTexture::*)(GLint,GLint)) &ofTexture::setTextureWrap)
         .def("setTextureMinMagFilter", (void(ofTexture::*)(GLint,GLint)) &ofTexture::setTextureMinMagFilter)
         .def("setCompression", (void(ofTexture::*)(ofTexCompression)) &ofTexture::setCompression)
         .def("isAllocated", (bool(ofTexture::*)(void)) &ofTexture::isAllocated)
         .def("bind", &ofTexture::bind)
         .def("unbind", &ofTexture::unbind)
		 .def("getWidth", &ofTexture::getWidth)
		 .def("getHeight", &ofTexture::getHeight),
         
         def("getGlInternalFormat", (int(*)(const ofPixels&)) &ofGetGlInternalFormat),
         def("getGlFormatAndType", (void(*)(int,int&,int&)) &ofGetGlFormatAndType),
         def("getImageTypeFromGLType", (ofImage(*)(int)) &ofGetImageTypeFromGLType),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofGLUtils
         
         def("getGLPolyMode", (GLuint(*)(ofPolyRenderMode)) &ofGetGLPolyMode),
         def("getOFPolyMode", (ofPolyRenderMode(*)(GLuint)) &ofGetOFPolyMode),
         def("getGLPrimitiveMode", (GLuint(*)(ofPolyRenderMode)) &ofGetGLPrimitiveMode),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofLight
         
         class_<ofLight>("light")
		 .def(constructor<>())
         .def(constructor<const ofLight&>())
         .def("destroy", (void(ofLight::*)(void)) &ofLight::destroy)
         .def("enable", (void(ofLight::*)(void)) &ofLight::enable)
         .def("disable", (void(ofLight::*)(void)) &ofLight::disable)
         .def("getIsEnabled", (bool(ofLight::*)(void)) &ofLight::getIsEnabled)
         .def("setDirectional", (void(ofLight::*)(void)) &ofLight::setDirectional)
         .def("getIsDirectional", (bool(ofLight::*)(void)) &ofLight::getIsDirectional)
         .def("setSpotlight", (void(ofLight::*)(float,float)) &ofLight::setSpotlight)
         .def("getIsSpotlight", (bool(ofLight::*)(void)) &ofLight::getIsSpotlight)
         .def("setSpotlightCutOff", (void(ofLight::*)(float)) &ofLight::setSpotlightCutOff)
         .def("setSpotConcentration", (void(ofLight::*)(float)) &ofLight::setSpotConcentration)
         .def("setPointLight", (void(ofLight::*)(void)) &ofLight::setPointLight)
         .def("getIsPointLight", (bool(ofLight::*)(void)) &ofLight::getIsPointLight)
         .def("setAttenuation", (void(ofLight::*)(float,float,float)) &ofLight::setAttenuation)
         .def("getType", (int(ofLight::*)(void)) &ofLight::getType)
         .def("setAmbientColor", (void(ofLight::*)(const ofFloatColor&)) &ofLight::setAmbientColor)
         .def("setDiffuseColor", (void(ofLight::*)(const ofFloatColor&)) &ofLight::setDiffuseColor)
         .def("setSpecularColor", (void(ofLight::*)(const ofFloatColor&)) &ofLight::setSpecularColor)
         .def("getAmbientColor", (ofFloatColor(ofLight::*)(void)) &ofLight::getAmbientColor)
         .def("getDiffuseColor", (ofFloatColor(ofLight::*)(void)) &ofLight::getDiffuseColor)
         .def("getSpecularColor", (ofFloatColor(ofLight::*)(void)) &ofLight::getSpecularColor)
         .def("getLightID", (int(ofLight::*)(void)) &ofLight::getLightID)
         .def("customDraw", (void(ofLight::*)(void)) &ofLight::customDraw)
         
         // from ofNode, transform functionality
         .def("getPosition", (ofVec3f(ofLight::*)(void)) &ofLight::getPosition)
         .def("getX", (float(ofLight::*)(void)) &ofLight::getX)
         .def("getY", (float(ofLight::*)(void)) &ofLight::getY)
         .def("getZ", (float(ofLight::*)(void)) &ofLight::getZ)
         .def("getXAxis", (ofVec3f(ofLight::*)(void)) &ofLight::getXAxis)
         .def("getYAxis", (ofVec3f(ofLight::*)(void)) &ofLight::getYAxis)
         .def("getZAxis", (ofVec3f(ofLight::*)(void)) &ofLight::getZAxis)
         .def("getSideDir", (ofVec3f(ofLight::*)(void)) &ofLight::getSideDir)
         .def("getLookAtDir", (ofVec3f(ofLight::*)(void)) &ofLight::getLookAtDir)
         .def("getUpDir", (ofVec3f(ofLight::*)(void)) &ofLight::getUpDir)
         .def("getPitch", (float(ofLight::*)(void)) &ofLight::getPitch)
         .def("getHeading", (float(ofLight::*)(void)) &ofLight::getHeading)
         .def("getRoll", (float(ofLight::*)(void)) &ofLight::getRoll)
         .def("getOrientationQuat", (ofQuaternion(ofLight::*)(void)) &ofLight::getOrientationQuat)
         .def("getOrientationEuler", (ofVec3f(ofLight::*)(void)) &ofLight::getOrientationEuler)
         .def("getScale", (ofVec3f(ofLight::*)(void)) &ofLight::getScale)
         .def("getLocalTransformMatrix", (ofMatrix4x4(ofLight::*)(void)) &ofLight::getLocalTransformMatrix)
         .def("getGlobalTransformMatrix", (ofMatrix4x4(ofLight::*)(void)) &ofLight::getGlobalTransformMatrix)
         .def("getGlobalPosition", (ofVec3f(ofLight::*)(void)) &ofLight::getGlobalPosition)
         .def("getGlobalOrientation", (ofQuaternion(ofLight::*)(void)) &ofLight::getGlobalOrientation)
         .def("setTransformMatrix", (void(ofLight::*)(const ofMatrix4x4&)) &ofLight::setTransformMatrix)
         .def("setPosition", (void(ofLight::*)(float,float,float)) &ofLight::setPosition)
         .def("setPosition", (void(ofLight::*)(const ofVec3f&)) &ofLight::setPosition)
         .def("setGlobalPosition", (void(ofLight::*)(float,float,float)) &ofLight::setGlobalPosition)
         .def("setGlobalPosition", (void(ofLight::*)(const ofVec3f&)) &ofLight::setGlobalPosition)
         .def("setOrientation", (void(ofLight::*)(const ofQuaternion&)) &ofLight::setOrientation)
         .def("setOrientation", (void(ofLight::*)(const ofVec3f&)) &ofLight::setOrientation)
         .def("setGlobalOrientation", (void(ofLight::*)(const ofQuaternion&)) &ofLight::setGlobalOrientation)
         .def("setScale", (void(ofLight::*)(float,float,float)) &ofLight::setScale)
         .def("setScale", (void(ofLight::*)(const ofVec3f&)) &ofLight::setScale)         
         .def("move", (void(ofLight::*)(float,float,float)) &ofLight::move)
         .def("move", (void(ofLight::*)(const ofVec3f&)) &ofLight::move)
         .def("truck", (void(ofLight::*)(float)) &ofLight::truck)
         .def("boom", (void(ofLight::*)(float)) &ofLight::boom)
         .def("dolly", (void(ofLight::*)(float)) &ofLight::dolly)
         .def("tilt", (void(ofLight::*)(float)) &ofLight::tilt)
         .def("pan", (void(ofLight::*)(float)) &ofLight::pan)
         .def("roll", (void(ofLight::*)(float)) &ofLight::roll)
         .def("rotate", (void(ofLight::*)(const ofQuaternion&)) &ofLight::rotate)
         .def("rotate", (void(ofLight::*)(float,const ofVec3f&)) &ofLight::rotate)
         .def("rotate", (void(ofLight::*)(float,float,float,float)) &ofLight::rotate)
         .def("rotateAround", (void(ofLight::*)(const ofQuaternion&,const ofVec3f&)) &ofLight::rotateAround)
         .def("rotateAround", (void(ofLight::*)(float,const ofVec3f&,const ofVec3f&)) &ofLight::rotateAround)
         .def("lookAt", (void(ofLight::*)(const ofVec3f&,ofVec3f)) &ofLight::lookAt)
         .def("lookAt", (void(ofLight::*)(ofNode&,const ofVec3f&)) &ofLight::lookAt)
         .def("orbit", (void(ofLight::*)(float,float,float,const ofVec3f&)) &ofLight::orbit)
         .def("orbit", (void(ofLight::*)(float,float,float,ofNode&)) &ofLight::orbit),
         
         def("enableLighting", (void(*)(void)) &ofEnableLighting),
         def("disableLighting", (void(*)(void)) &ofDisableLighting),
         def("enableSeparateSpecularLight", (void(*)(void)) &ofEnableSeparateSpecularLight),
         def("disableSeparateSpecularLight", (void(*)(void)) &ofDisableSeparateSpecularLight),
         def("getLightingEnabled", (bool(*)(void)) &ofGetLightingEnabled),
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section utils [ofDirectory, ofHttpResponse, ofFileDialogResult, ofLogError, ofLogWarning, ofSystemUtils,
         ///                    ofBuffer, ofFile, ofLogNotice, ofFileUtils, ofFilePath, ofHttpRequest, ofLogVerbose, ofLog,
         ///                    ofPtr, ofUtils, ofThread, ofLogFatalError, ofURLFileLoader]
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofDirectory
         
         class_<ofDirectory>("directory")
		 .def(constructor<>())
         .def(constructor<string>())
         .def("open", (void(ofDirectory::*)(string)) &ofDirectory::open)
         .def("close", (void(ofDirectory::*)(void)) &ofDirectory::close)
         .def("create", (bool(ofDirectory::*)(bool)) &ofDirectory::create)
         .def("exists", (bool(ofDirectory::*)(void)) &ofDirectory::exists)
         .def("path", (string(ofDirectory::*)(void)) &ofDirectory::path)
         //.def("canRead", (bool(ofDirectory::*)(void)) &ofDirectory::canRead)
         //.def("canWrite", (bool(ofDirectory::*)(void)) &ofDirectory::canWrite)
         //.def("canExecute", (bool(ofDirectory::*)(void)) &ofDirectory::canExecute)
         .def("isDirectory", (bool(ofDirectory::*)(void)) &ofDirectory::isDirectory)
         .def("isHidden", (bool(ofDirectory::*)(void)) &ofDirectory::isHidden)
         .def("setWriteable", (void(ofDirectory::*)(bool)) &ofDirectory::setWriteable)
         .def("setReadOnly", (void(ofDirectory::*)(bool)) &ofDirectory::setReadOnly)
         .def("setExecutable", (void(ofDirectory::*)(bool)) &ofDirectory::setExecutable)
         .def("setShowHidden", (void(ofDirectory::*)(bool)) &ofDirectory::setShowHidden)
         .def("copyTo", (bool(ofDirectory::*)(string,bool,bool)) &ofDirectory::copyTo)
         .def("moveTo", (bool(ofDirectory::*)(string,bool,bool)) &ofDirectory::moveTo)
         .def("renameTo", (bool(ofDirectory::*)(string,bool,bool)) &ofDirectory::renameTo)
         .def("remove", (bool(ofDirectory::*)(bool)) &ofDirectory::remove)
         .def("allowExt", (void(ofDirectory::*)(string)) &ofDirectory::allowExt)
         .def("listDir", (int(ofDirectory::*)(string)) &ofDirectory::listDir)
         .def("listDir", (int(ofDirectory::*)(void)) &ofDirectory::listDir)
         .def("getName", (string(ofDirectory::*)(unsigned int)) &ofDirectory::getName)
         .def("getPath", (string(ofDirectory::*)(unsigned int)) &ofDirectory::getPath)
         .def("getFile", (ofFile(ofDirectory::*)(unsigned int,ofFile)) &ofDirectory::getFile)
         .def("getFiles", (ofFile(ofDirectory::*)(void)) &ofDirectory::getFiles)
         .def("getShowHidden", (bool(ofDirectory::*)(void)) &ofDirectory::getShowHidden)
         .def("reset", (void(ofDirectory::*)(void)) &ofDirectory::reset)
         .def("sort", (void(ofDirectory::*)(void)) &ofDirectory::sort)
         .def("size", (unsigned int(ofDirectory::*)(void)) &ofDirectory::size)
         .def("numFiles", (int(ofDirectory::*)(void)) &ofDirectory::numFiles)
         .def("createDirectory", (bool(*)(string,bool,bool)) &ofDirectory::createDirectory)
         .def("isDirectoryEmpty", (bool(*)(string,bool)) &ofDirectory::isDirectoryEmpty)
         .def("doesDirectoryExist", (bool(*)(string,bool)) &ofDirectory::doesDirectoryExist)
         .def("removeDirectory", (bool(*)(string,bool,bool)) &ofDirectory::removeDirectory)
         //.def("getOriginalDirectory", (string(*)(void)) &ofDirectory::getOriginalDirectory)
         .def("getFile", (ofFile(ofDirectory::*)(unsigned int,ofFile)) &ofDirectory::getFile),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofHttpResponse
         
         class_<ofHttpResponse>("httpResponse")
		 .def(constructor<>())
         .def(constructor<ofHttpRequest,const ofBuffer&,int,string>())
         .def(constructor<ofHttpRequest,int,string>())
         .def_readonly("request", &ofHttpResponse::request)
		 .def_readonly("data", &ofHttpResponse::data)
         .def_readonly("status", &ofHttpResponse::status)
		 .def_readonly("error", &ofHttpResponse::error),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofFileDialogResult
         
         class_<ofFileDialogResult>("fileDialogResult")
		 .def(constructor<>())
         .def("getName", (string(ofFileDialogResult::*)(void)) &ofFileDialogResult::getName)
         .def("getPath", (string(ofFileDialogResult::*)(void)) &ofFileDialogResult::getPath)
         .def_readonly("filePath", &ofFileDialogResult::filePath)
		 .def_readonly("fileName", &ofFileDialogResult::fileName)
         .def_readonly("bSuccess", &ofFileDialogResult::bSuccess),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofSystemUtils
         
         def("systemAlertDialog", (void(*)(string)) &ofSystemAlertDialog),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofBuffer
         
         class_<ofBuffer>("buffer")
		 .def(constructor<>())
         .def(constructor<const char*,int>())
         .def(constructor<const ofBuffer&>())
         .def("set", (void(ofBuffer::*)(const char*,int)) &ofBuffer::set)
         .def("set", (bool(ofBuffer::*)(istream&)) &ofBuffer::set)
         .def("writeTo", (bool(ofBuffer::*)(ostream&)) &ofBuffer::writeTo)
         .def("clear", (void(ofBuffer::*)(void)) &ofBuffer::clear)
         .def("allocate", (void(ofBuffer::*)(long)) &ofBuffer::allocate)
         .def("getBinaryBuffer", (char*(ofBuffer::*)(void)) &ofBuffer::getBinaryBuffer)
         .def("getText", (string(ofBuffer::*)(void)) &ofBuffer::getText)
         .def("size", (long(ofBuffer::*)(void)) &ofBuffer::size)
         .def("getNextLine", (string(ofBuffer::*)(void)) &ofBuffer::getNextLine)
         .def("getFirstLine", (string(ofBuffer::*)(void)) &ofBuffer::getFirstLine)
         .def("isLastLine", (bool(ofBuffer::*)(void)) &ofBuffer::isLastLine)
         .def("resetLineReader", (void(ofBuffer::*)(void)) &ofBuffer::resetLineReader),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofFile
         
         class_<ofFile>("file")
		 .def(constructor<>())
         .def(constructor<const ofFile&>())
         .def("open", &openFile) // file:open("test/test.txt")
         .def("close", (void(ofFile::*)(void)) &ofFile::close)
         .def("create", (bool(ofFile::*)(void)) &ofFile::create)
         .def("exists", (bool(ofFile::*)(void)) &ofFile::exists)
         .def("path", (string(ofFile::*)(void)) &ofFile::path)
         .def("getExtension", (string(ofFile::*)(void)) &ofFile::getExtension)
         .def("getFileName", (string(ofFile::*)(void)) &ofFile::getFileName)
         .def("getBaseName", (string(ofFile::*)(void)) &ofFile::getBaseName)
         .def("getEnclosingDirectory", (string(ofFile::*)(void)) &ofFile::getEnclosingDirectory)
         .def("getAbsolutePath", (string(ofFile::*)(void)) &ofFile::getAbsolutePath)
         .def("canRead", (bool(ofFile::*)(void)) &ofFile::canRead)
         .def("canWrite", (bool(ofFile::*)(void)) &ofFile::canWrite)
         .def("canExecute", (bool(ofFile::*)(void)) &ofFile::canExecute)
         .def("isFile", (bool(ofFile::*)(void)) &ofFile::isFile)
         .def("isLink", (bool(ofFile::*)(void)) &ofFile::isLink)
         .def("isDirectory", (bool(ofFile::*)(void)) &ofFile::isDirectory)
         .def("isDevice", (bool(ofFile::*)(void)) &ofFile::isDevice)
         .def("isHidden", (bool(ofFile::*)(void)) &ofFile::isHidden)
         .def("setWriteable", (void(ofFile::*)(bool)) &ofFile::setWriteable)
         .def("setReadOnly", (void(ofFile::*)(bool)) &ofFile::setReadOnly)
         .def("setExecutable", (void(ofFile::*)(bool)) &ofFile::setExecutable)
         .def("copyTo", (bool(ofFile::*)(string,bool,bool)) &ofFile::copyTo)
         .def("moveTo", (bool(ofFile::*)(string,bool,bool)) &ofFile::moveTo)
         .def("renameTo", (bool(ofFile::*)(string,bool,bool)) &ofFile::renameTo)
         .def("remove", (bool(ofFile::*)(bool)) &ofFile::remove)
         .def("getSize", (uint64_t(ofFile::*)(void)) &ofFile::getSize)
         .def("readToBuffer", (ofBuffer(ofFile::*)(void)) &ofFile::readToBuffer)
         .def("writeFromBuffer", (bool(ofFile::*)(ofBuffer)) &ofFile::writeFromBuffer)
         .def("removeFile", (bool(*)(string,bool)) &ofFile::removeFile)
         .def("copyFromTo", (bool(*)(string,string,bool,bool)) &ofFile::copyFromTo)
         .def("moveFromTo", (bool(*)(string,string,bool,bool)) &ofFile::moveFromTo)
         .def("doesFileExist", (bool(*)(string,bool)) &ofFile::moveFromTo)
         .def("removeFile", (bool(*)(string,bool)) &ofFile::removeFile),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofFileUtils
         
         def("bufferFromFile", &ofBufferFromFile),
         def("bufferToFile", &ofBufferToFile),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofHttpRequest
         
         class_<ofHttpRequest>("httpRequest")
		 .def(constructor<>())
         .def(constructor<string,string,bool>())
         .def("getID", (int(ofHttpRequest::*)(void)) &ofHttpRequest::getID)
         .def_readonly("url", &ofHttpRequest::url)
         .def_readonly("name", &ofHttpRequest::name)
         .def_readonly("saveTo", &ofHttpRequest::saveTo),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofUtils
         
         def("getElapsedTimeMillis", &ofGetElapsedTimeMillis),
         def("getElapsedTimef", &ofGetElapsedTimef),
         def("getFrameNum", &ofGetFrameNum),
         def("getSeconds", &ofGetSeconds),
		 def("getMinutes", &ofGetMinutes),
		 def("getHours", &ofGetHours),
         def("launchBrowser", &ofLaunchBrowser),
         def("getVersionInfo", &ofGetVersionInfo),
         def("toInt", (int(*)(const string&)) &ofToInt),
         def("toFloat", (float(*)(const string&)) &ofToFloat),
         def("saveScreen", &ofSaveScreen),
         def("saveFrame", &ofSaveFrame),
         def("splitString", (vector<string>(*)(const string&, const string&, bool)) &ofSplitString),
         def("getYear", &ofGetYear),
		 def("getMonth", &ofGetMonth),
		 def("getDay", &ofGetDay),
		 def("getWeekday", &ofGetWeekday),
         def("resetElapsedTimeCounter", &ofResetElapsedTimeCounter),
         def("getElapsedTimeMicros", &ofGetElapsedTimeMicros),
         def("getUnixTime", &ofGetUnixTime),
         def("getSystemTime", &ofGetSystemTime),
         def("getSystemTimeMicros", &ofGetSystemTimeMicros),
         def("getTimestampString", (string(*)(void)) &ofGetTimestampString),
		 def("getTimestampString", (string(*)(string)) &ofGetTimestampString),
         def("toChar", (char(*)(const string&)) &ofToChar),
		 def("toBool", (bool(*)(const string&)) &ofToBool),
		 def("toBinary", (string(*)(const string&)) &ofToBinary),
		 def("toBinary", (string(*)(const char*)) &ofToBinary),
		 def("binaryToInt", (int(*)(const string&)) &ofBinaryToInt),
		 def("binaryToChar", (char(*)(const string&)) &ofBinaryToChar),
		 def("binaryToFloat", (float(*)(const string&)) &ofBinaryToFloat),
		 def("binaryToString", (string(*)(const string&)) &ofBinaryToString),
		 def("joinString", (string(*)(vector<string>, const string&)) &ofJoinString),
		 def("stringReplace", (void(*)(string&, string, string)) &ofStringReplace),
		 def("isStringInString", (bool(*)(string, string)) &ofIsStringInString),
		 def("getFrameRate", &ofGetFrameRate),
		 def("setFrameRate", &ofSetFrameRate),
		 def("sleepMillis", &ofSleepMillis),
		 def("getLastFrameTime", &ofGetLastFrameTime),
		 def("getFrameNum", &ofGetFrameNum),

         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofThread
         
         class_<ofThread>("thread")
		 .def(constructor<>())
         .def("isThreadRunning", (bool(ofThread::*)(void)) &ofThread::isThreadRunning)
         .def("startThread", (void(ofThread::*)(bool,bool)) &ofThread::startThread)
         .def("lock", (void(ofThread::*)(void)) &ofThread::lock)
         .def("unlock", (void(ofThread::*)(void)) &ofThread::unlock)
         .def("stopThread", (void(ofThread::*)(bool)) &ofThread::stopThread)
         .def("waitForThread", (void(ofThread::*)(bool)) &ofThread::waitForThread),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofURLFileLoader
         
         class_<ofURLFileLoader>("URLFileLoader")
		 .def(constructor<>())
         .def("get", (ofHttpResponse(ofURLFileLoader::*)(string)) &ofURLFileLoader::get)
         .def("getAsync", (int(ofURLFileLoader::*)(string,string)) &ofURLFileLoader::getAsync)
         .def("saveTo", (ofHttpResponse(ofURLFileLoader::*)(string,string)) &ofURLFileLoader::saveTo)
         .def("saveAsync", (int(ofURLFileLoader::*)(string,string)) &ofURLFileLoader::saveAsync)
         .def("remove", (void(ofURLFileLoader::*)(int)) &ofURLFileLoader::remove)
         .def("clear", (void(ofURLFileLoader::*)(void)) &ofURLFileLoader::clear),
         
         def("loadURL", (ofHttpResponse(*)(string)) &ofLoadURL),
         def("loadURLAsync", (int(*)(string,string)) &ofLoadURLAsync),
         def("saveURLTo", (ofHttpResponse(*)(string,string)) &ofSaveURLTo),
         def("saveURLAsync", (int(*)(string,string)) &ofSaveURLAsync),
         def("removeURLRequest", (void(*)(int)) &ofRemoveURLRequest),
         def("removeAllURLRequests", (void(*)(void)) &ofRemoveAllURLRequests),
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section Video [ofVideoPlayer, ofVideoGrabber]
         
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofVideoPlayer
         
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
		 .def_readonly("height", &ofVideoPlayer::height),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofVideoGrabber
         
         // LIMITED, ofVideoGrabber NOT AVAILABLE IN GAMUZA 0.3 IN THE LIVE CODING SYSTEM
         // &
         // MANAGED FROM GUI (video tracking module) & FROM gamuza LIVE CODING FUNCTIONS (ga. module)
         
         
		 ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section graphics [ofPath, ofImage, ofFloatImage, ofPixels, ofGraphics, ofPixelUtils, ofTrueTypeFont, ofTTFCharacter, ofPolyline, ofTessellator, ofRendererCollection]
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofPath
         
         class_<ofPath>("path")
		 .def(constructor<>())
		 .def("clear", (void(ofPath::*)(void)) &ofPath::clear)
         .def("newSubPath", (void(ofPath::*)(void)) &ofPath::newSubPath)
         .def("close", (void(ofPath::*)(void)) &ofPath::close)
         .def("lineTo", (void(ofPath::*)(const ofPoint&)) &ofPath::lineTo)
         .def("lineTo", (void(ofPath::*)(float,float,float)) &ofPath::lineTo)
         .def("moveTo", (void(ofPath::*)(const ofPoint&)) &ofPath::moveTo)
         .def("moveTo", (void(ofPath::*)(float,float,float)) &ofPath::moveTo)
         .def("curveTo", (void(ofPath::*)(const ofPoint&)) &ofPath::curveTo)
         .def("curveTo", (void(ofPath::*)(float,float)) &ofPath::curveTo)
         .def("curveTo", (void(ofPath::*)(float,float,float)) &ofPath::curveTo)
         .def("bezierTo", (void(ofPath::*)(const ofPoint&,const ofPoint&,const ofPoint&)) &ofPath::bezierTo)
         .def("bezierTo", (void(ofPath::*)(float,float,float,float,float,float)) &ofPath::bezierTo)
         .def("bezierTo", (void(ofPath::*)(float,float,float,float,float,float,float,float,float)) &ofPath::bezierTo)
         .def("quadBezierTo", (void(ofPath::*)(const ofPoint&,const ofPoint&,const ofPoint&)) &ofPath::quadBezierTo)
         .def("quadBezierTo", (void(ofPath::*)(float,float,float,float,float,float)) &ofPath::quadBezierTo)
         .def("quadBezierTo", (void(ofPath::*)(float,float,float,float,float,float,float,float,float)) &ofPath::quadBezierTo)
         .def("arc", (void(ofPath::*)(const ofPoint&,float,float,float,float)) &ofPath::arc)
         .def("arc", (void(ofPath::*)(float,float,float,float,float,float)) &ofPath::arc)
         .def("arc", (void(ofPath::*)(float,float,float,float,float,float,float)) &ofPath::arc)
         .def("setPolyWindingMode", (void(ofPath::*)(ofPolyWindingMode)) &ofPath::setPolyWindingMode)
         .def("setFilled", (void(ofPath::*)(bool)) &ofPath::setFilled)
         .def("setStrokeWidth", (void(ofPath::*)(float)) &ofPath::setStrokeWidth)
         .def("setColor", (void(ofPath::*)(const ofColor&)) &ofPath::setColor)
         .def("setHexColor", (void(ofPath::*)(int)) &ofPath::setHexColor)
         .def("setFillColor", (void(ofPath::*)(const ofColor&)) &ofPath::setFillColor)
         .def("setFillHexColor", (void(ofPath::*)(int)) &ofPath::setFillHexColor)
         .def("setStrokeColor", (void(ofPath::*)(const ofColor&)) &ofPath::setStrokeColor)
         .def("setStrokeHexColor", (void(ofPath::*)(int)) &ofPath::setStrokeHexColor)
         .def("getWindingMode", (ofPolyWindingMode(ofPath::*)(void)) &ofPath::getWindingMode)
         .def("isFilled", (bool(ofPath::*)(void)) &ofPath::isFilled)
         .def("getFillColor", (ofColor(ofPath::*)(void)) &ofPath::getFillColor)
         .def("getStrokeColor", (ofColor(ofPath::*)(void)) &ofPath::getStrokeColor)
         .def("getStrokeWidth", (float(ofPath::*)(void)) &ofPath::getStrokeWidth)
         .def("hasOutline", (bool(ofPath::*)(void)) &ofPath::hasOutline)
         .def("draw", (void(ofPath::*)(float,float)) &ofPath::draw)
         .def("draw", (void(ofPath::*)(void)) &ofPath::draw)
         //.def("getSubPaths", (ofSubPath(ofPath::*)(void)) &ofPath::getSubPaths)               NOT AVAILABLE
         .def("getOutline", (ofPolyline(ofPath::*)(void)) &ofPath::getOutline)
         .def("getTessellation", (ofMesh(ofPath::*)(void)) &ofPath::getTessellation)
         .def("simplify", (void(ofPath::*)(float)) &ofPath::simplify)
         .def("flagShapeChanged", (void(ofPath::*)(void)) &ofPath::flagShapeChanged)
         //.def("setMode", (void(ofPath::*)(Mode)) &ofPath::setMode)                            NOT AVAILABLE
         .def("setCurveResolution", (void(ofPath::*)(int)) &ofPath::setCurveResolution)
         .def("getCurveResolution", (int(ofPath::*)(void)) &ofPath::getCurveResolution)
         .def("setArcResolution", (void(ofPath::*)(int)) &ofPath::setArcResolution)
         .def("getArcResolution", (int(ofPath::*)(void)) &ofPath::getArcResolution)
         .def("setUseShapeColor", (void(ofPath::*)(bool)) &ofPath::setUseShapeColor)
         .def("getUseShapeColor", (bool(ofPath::*)(void)) &ofPath::getUseShapeColor)
         .def("tessellate", (void(ofPath::*)(void)) &ofPath::tessellate)
         .def("translate", (void(ofPath::*)(const ofPoint&)) &ofPath::translate)
         .def("rotate", (void(ofPath::*)(float,const ofVec3f&)) &ofPath::rotate)
         .def("scale", (void(ofPath::*)(float,float)) &ofPath::scale),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofImage
		 
		 class_<ofImage>("image")
		 .def(constructor<>())
		 .def(constructor<const string&>())
		 .def("allocate", (void(ofImage::*)(int,int,int)) &ofImage::allocate)
		 .def("clear", (void(ofImage::*)(void)) &ofImage::clear)
         .def("clone", (void(ofImage::*)(const ofImage&)) &ofImage::clone)
         .def("setUseTexture", (void(ofImage::*)(bool)) &ofImage::setUseTexture)
         .def("getTextureReference", (ofTexture&(ofImage::*)(void)) &ofImage::getTextureReference)
		 .def("loadImage", (bool(ofImage::*)(string)) &ofImage::loadImage)
         .def("saveImage", (void(ofImage::*)(string, ofImageQualityType)) &ofImage::saveImage)
         .def("saveImageBuffer", (void(ofImage::*)(ofBuffer&, ofImageQualityType)) &ofImage::saveImage)
		 .def("getPixels", (unsigned char*(ofImage::*)(void)) &ofImage::getPixels)
         .def("setFromPixels", (void(ofImage::*)(const ofPixels&)) &ofImage::setFromPixels)
		 .def("setImageType", (void(ofImage::*)(int)) &ofImage::setImageType)
         .def("resize", (void(ofImage::*)(int,int)) &ofImage::resize)
         .def("grabScreen", (void(ofImage::*)(int,int,int,int)) &ofImage::grabScreen)
         .def("update", (void(ofImage::*)(void)) &ofImage::update)
		 .def("draw", (void(ofImage::*)(float,float)) &ofImage::draw)
		 .def("draw", (void(ofImage::*)(float,float,float,float)) &ofImage::draw)
         .def("getWidth", (float(ofImage::*)(void)) &ofImage::getWidth)
         .def("getHeight", (float(ofImage::*)(void)) &ofImage::getHeight)
		 .def("getColor", (ofColor(ofImage::*)(int,int)) &ofImage::getColor)
		 .def("setColor", (void(ofImage::*)(int,int,ofColor)) &ofImage::setColor)
         .def("setImageType", (void(ofImage::*)(ofImageType)) &ofImage::setImageType)
         .def("crop", (void(ofImage::*)(int,int,int,int)) &ofImage::crop)
         .def("cropFrom", (void(ofImage::*)(ofImage&,int,int,int,int)) &ofImage::cropFrom)
         .def("rotate90", (void(ofImage::*)(int)) &ofImage::rotate90)
		 .def("mirror", (void(ofImage::*)(bool,bool)) &ofImage::mirror)
		 .def("setAnchorPoint", (void(ofImage::*)(float,float)) &ofImage::setAnchorPoint)
         .def("draw", (void(ofImage::*)(const ofRectangle&)) &ofImage::draw)
         .def("draw", (void(ofImage::*)(const ofPoint&,float,float)) &ofImage::draw)
         .def("draw", (void(ofImage::*)(float,float,float)) &ofImage::draw)
         .def("draw", (void(ofImage::*)(const ofPoint&)) &ofImage::draw)
         .def("draw", (void(ofImage::*)(float,float,float,float,float)) &ofImage::draw)
		 .def("bAllocated", (void(ofImage::*)(bool)) &ofImage::bAllocated)
         .def("reloadTexture", (void(ofImage::*)(void)) &ofImage::reloadTexture)
		 .def_readonly("width", &ofImage::width)
		 .def_readonly("height", &ofImage::height)
         .def_readonly("type", &ofImage::type)
		 .def_readonly("bpp", &ofImage::bpp),
         
         def("loadImage",	(bool(*)(ofPixels&,string)) &ofLoadImage),
         //def("loadImage",	(bool(*)(ofPixels&,const ofBuffer&)) &ofLoadImage),
         //def("loadImage",	(bool(*)(ofTexture&,string)) &ofLoadImage),
         //def("loadImage",	(bool(*)(ofTexture&,const ofBuffer&)) &ofLoadImage),
         def("saveImage",	(void(*)(ofPixels&,string,ofImageQualityType)) &ofSaveImage),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofFloatImage
		 
		 class_<ofFloatImage>("floatImage")
		 .def(constructor<>())
		 .def(constructor<const string&>())
		 .def("allocate", (void(ofFloatImage::*)(int,int,int)) &ofFloatImage::allocate)
		 .def("clear", (void(ofFloatImage::*)(void)) &ofFloatImage::clear)
         .def("clone", (void(ofFloatImage::*)(const ofFloatImage&)) &ofFloatImage::clone)
         .def("setUseTexture", (void(ofFloatImage::*)(bool)) &ofFloatImage::setUseTexture)
         .def("getTextureReference", (ofTexture&(ofFloatImage::*)(void)) &ofFloatImage::getTextureReference)
		 .def("loadImage", (bool(ofFloatImage::*)(string)) &ofFloatImage::loadImage)
         .def("saveImage", (void(ofFloatImage::*)(string, ofImageQualityType)) &ofFloatImage::saveImage)
         .def("saveImageBuffer", (void(ofFloatImage::*)(ofBuffer&, ofImageQualityType)) &ofFloatImage::saveImage)
		 .def("getPixels", (unsigned char*(ofFloatImage::*)(void)) &ofFloatImage::getPixels)
         //.def("setFromPixels", (void(ofImage::*)(const ofPixels&)) &ofImage::setFromPixels)
		 .def("setImageType", (void(ofFloatImage::*)(int)) &ofFloatImage::setImageType)
         .def("resize", (void(ofFloatImage::*)(int,int)) &ofFloatImage::resize)
         .def("grabScreen", (void(ofFloatImage::*)(int,int,int,int)) &ofFloatImage::grabScreen)
         .def("update", (void(ofFloatImage::*)(void)) &ofFloatImage::update)
		 .def("draw", (void(ofFloatImage::*)(float,float)) &ofFloatImage::draw)
		 .def("draw", (void(ofFloatImage::*)(float,float,float,float)) &ofFloatImage::draw)
         .def("getWidth", (float(ofFloatImage::*)(void)) &ofFloatImage::getWidth)
         .def("getHeight", (float(ofFloatImage::*)(void)) &ofFloatImage::getHeight)
		 .def("getColor", (ofColor(ofFloatImage::*)(int,int)) &ofFloatImage::getColor)
		 .def("setColor", (void(ofFloatImage::*)(int,int,ofColor)) &ofFloatImage::setColor)
         .def("setImageType", (void(ofFloatImage::*)(ofImageType)) &ofFloatImage::setImageType)
         .def("crop", (void(ofFloatImage::*)(int,int,int,int)) &ofFloatImage::crop)
         .def("cropFrom", (void(ofFloatImage::*)(ofFloatImage&,int,int,int,int)) &ofFloatImage::cropFrom)
         .def("rotate90", (void(ofFloatImage::*)(int)) &ofFloatImage::rotate90)
		 .def("mirror", (void(ofFloatImage::*)(bool,bool)) &ofFloatImage::mirror)
		 .def("setAnchorPoint", (void(ofFloatImage::*)(float,float)) &ofFloatImage::setAnchorPoint)
         .def("draw", (void(ofFloatImage::*)(const ofRectangle&)) &ofFloatImage::draw)
         .def("draw", (void(ofFloatImage::*)(const ofPoint&,float,float)) &ofFloatImage::draw)
         .def("draw", (void(ofFloatImage::*)(float,float,float)) &ofFloatImage::draw)
         .def("draw", (void(ofFloatImage::*)(const ofPoint&)) &ofFloatImage::draw)
         .def("draw", (void(ofFloatImage::*)(float,float,float,float,float)) &ofFloatImage::draw)
		 .def("bAllocated", (void(ofFloatImage::*)(bool)) &ofFloatImage::bAllocated)
         .def("reloadTexture", (void(ofFloatImage::*)(void)) &ofFloatImage::reloadTexture)
		 .def_readonly("width", &ofFloatImage::width)
		 .def_readonly("height", &ofFloatImage::height)
         .def_readonly("type", &ofFloatImage::type)
		 .def_readonly("bpp", &ofFloatImage::bpp),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofPixels
		 
		 class_<ofPixels>("pixels")
		 .def(constructor<>())
		 .def("allocate", (void(ofPixels::*)(int,int,int)) &ofPixels::allocate)
		 .def("set", (void(ofPixels::*)(unsigned char)) &ofPixels::set)
         //.def("setFromPixels", (void(ofPixels::*)(unsigned char*,int,int,ofImageType)) &ofPixels::setFromPixels)
         .def("setFromExternalPixels", (void(ofPixels::*)(unsigned char*,int,int,int)) &ofPixels::setFromExternalPixels)
         .def("setFromAlignedPixels", (void(ofPixels::*)(unsigned char*,int,int,int,int)) &ofPixels::setFromAlignedPixels)
         .def("swapRgb", (void(ofPixels::*)(void)) &ofPixels::swapRgb)
         .def("clear", (void(ofPixels::*)(void)) &ofPixels::clear)
         .def("getPixels", (unsigned char*(ofPixels::*)(void)) &ofPixels::getPixels)
         .def("getPixelIndex", (int(ofPixels::*)(int,int)) &ofPixels::getPixelIndex)
         .def("getColor", (ofColor(ofPixels::*)(int,int)) &ofPixels::getColor)
		 .def("setColor", (void(ofPixels::*)(int,int,ofColor)) &ofPixels::setColor)
         .def("isAllocated", (bool(ofPixels::*)(void)) &ofPixels::isAllocated)
         .def("getWidth", (int(ofPixels::*)(void)) &ofPixels::getWidth)
		 .def("getHeight", (int(ofPixels::*)(void)) &ofPixels::getHeight)
         .def("getBytesPerPixel", (int(ofPixels::*)(void)) &ofPixels::getBytesPerPixel)
         .def("getBitsPerPixel", (int(ofPixels::*)(void)) &ofPixels::getBitsPerPixel)
         .def("getImageType", (ofImageType(ofPixels::*)(void)) &ofPixels::getImageType)
         
         // from ofPixelUtils, useful here because of the live-coding lua system wrapper
         .def("crop", (void(ofPixels::*)(int,int,int,int)) &ofPixels::crop)
         .def("rotate90", (void(ofPixels::*)(int)) &ofPixels::rotate90)
         .def("mirror", (void(ofPixels::*)(bool,bool)) &ofPixels::mirror)
         .def("resize", (void(ofPixels::*)(int,int)) &ofPixels::resize),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofGraphics
         
		 def("background",	(void(*)(int)) &background),
		 def("background",	(void(*)(int,int)) &ofBackground),
		 def("background",	(void(*)(int,int,int)) &background),
		 def("background",	(void(*)(int,int,int,int)) &ofBackground),
         // float * ofBgColorPtr(void)              NOT AVAILABLE
         // void ofSetBackgroundAuto(bool)          NOT AVAILABLE
         // bool ofbClearBg()(void)                 NOT AVAILABLE
         def("setCircleResolution", (void(*)(int)) &ofSetCircleResolution),
         def("setRectMode", (void(*)(int)) &ofSetRectMode),                     // of.setCircleResolution(OF_RECTMODE_CENTER || OF_RECTMODE_CORNER)
         def("getRectMode", (ofRectMode(*)(void)) &ofGetRectMode),
         def("rect", (void(*)(float,float,float,float)) &ofRect),
		 def("triangle", (void(*)(float,float,float,float,float,float)) &ofTriangle),
		 def("circle", (void(*)(float,float,float)) &ofCircle),
		 def("ellipse",	(void(*)(float,float,float,float)) &ofEllipse),
         def("line", (void(*)(float,float,float,float)) &ofLine),
         def("curve", (void(*)(float,float,float,float,float,float,float,float)) &ofCurve),
		 def("bezier", (void(*)(float,float,float,float,float,float,float,float)) &ofBezier),
         def("setPolyMode", (void(*)(int)) &ofSetPolyMode),
         def("beginShape", (void(*)(void)) &ofBeginShape),
         def("vertex",	(void(*)(float,float)) &ofVertex),
		 def("curveVertex", (void(*)(float,float)) &ofCurveVertex),
		 def("bezierVertex", (void(*)(float,float,float,float,float,float)) &ofBezierVertex),
		 def("nextContour", (void(*)(bool)) &ofNextContour),
         def("endShape", (void(*)(bool)) &ofEndShape),
         def("noFill", (void(*)(void)) &ofNoFill),
		 def("fill", (void(*)(void)) &ofFill),
         def("setColor", (void(*)(int)) &setColor1),
         def("setColor", (void(*)(int,int)) &setColor2),
         def("setColor", (void(*)(int,int,int)) &ofSetColor),
		 def("setColor", (void(*)(int,int,int,int)) &ofSetColor),
		 def("setHexColor", (void(*)(int)) &ofSetHexColor),
         def("enableAlphaBlending", (void(*)(void)) &ofEnableAlphaBlending),
		 def("disableAlphaBlending", (void(*)(void)) &ofDisableAlphaBlending),
         def("enableSmoothing", (void(*)(void)) &ofEnableSmoothing),
		 def("disableSmoothing", (void(*)(void)) &ofDisableSmoothing),
         def("drawBitmapString", (void(*)(string,float,float)) &ofDrawBitmapString),
         def("rotate", (void(*)(float,float,float,float)) &ofRotate),
         def("rotateX", (void(*)(float)) &ofRotateX),
		 def("rotateY", (void(*)(float)) &ofRotateY),
		 def("rotateZ", (void(*)(float)) &ofRotateZ),
         def("pushStyle", (void(*)(void)) &ofPushStyle),
         def("popStyle", (void(*)(void)) &ofPopStyle),
         def("setStyle", (void(*)(ofStyle)) &ofSetStyle),
         def("getStyle", (void(*)(ofStyle)) &ofGetStyle),
         def("setLineWidth", (void(*)(float)) &ofSetLineWidth),
         def("pushMatrix", (void(*)(void)) &ofPushMatrix),
		 def("popMatrix", (void(*)(void)) &ofPopMatrix),
         def("translate", (void(*)(float,float,float)) &ofTranslate),
		 def("scale", (void(*)(float,float,float)) &ofScale),
         // void ofSetCurrentRenderer(ofPtr< ofBaseRenderer >)              NOT AVAILABLE
         // ofPtr ofGetCurrentRenderer(void)                                NOT AVAILABLE
         // ofPtr ofGetGLRenderer(void)                                     NOT AVAILABLE
         def("beginSaveScreenAsPDF", (void(*)(string,bool,bool,ofRectangle)) &ofBeginSaveScreenAsPDF), // ofBeginSaveScreenAsPDF(filename, bMultipage=false, b3D=false, viewport)
         def("endSaveScreenAsPDF", (void(*)(void)) &ofEndSaveScreenAsPDF),
         def("pushView", (void(*)(void)) &ofPushView),
		 def("popView", (void(*)(void)) &ofPopView),
         def("viewport", (void(*)(ofRectangle)) &ofViewport),
         def("viewport", (void(*)(float,float,float,float,bool)) &ofViewport), // ofViewport(x=0,y=0,width=0,height=0,invertY=true)
         //def("setupScreenPerspective", (void(*)(float,float,ofOrientation,bool,float,float,float)) &ofSetupScreenPerspective),        NOT AVAILABLE
         //def("setupScreenOrtho", (void(*)(float,float,ofOrientation,bool,float,float)) &ofSetupScreenOrtho),                          NOT AVAILABLE
         def("getCurrentViewport", (ofRectangle(*)(void)) &ofGetCurrentViewport),
         def("getViewportWidth", (int(*)(void)) &ofGetViewportWidth),
         def("getViewportHeight", (int(*)(void)) &ofGetViewportHeight),
         //def("orientationToDegrees", (int(*)(ofOrientation)) &ofOrientationToDegrees),                                                NOT AVAILABLE
         //def("setCoordHandedness", (void(*)(ofHandednessType)) &ofSetCoordHandedness),                                                NOT AVAILABLE
         //def("getCoordHandedness", (ofHandednessType(*)(void)) &ofGetCoordHandedness),                                                NOT AVAILABLE
         def("translate", (void(*)(const ofPoint&)) &ofTranslate),
         def("rotate", (void(*)(float)) &ofRotate),
         // def("setupScreen", (void(*)(void)) &ofSetupScreen),                                                                         NOT AVAILABLE
		 def("setCurveResolution", (void(*)(int)) &ofSetCurveResolution),
         def("setSphereResolution", (void(*)(int)) &ofSetSphereResolution),
         def("getFill", (ofFillFlag(*)(void)) &ofGetFill),
         def("setColor", (void(*)(const ofColor&)) &ofSetColor),
         def("setColor", (void(*)(const ofColor&,int)) &ofSetColor),
         def("enableBlendMode", (void(*)(ofBlendMode)) &ofEnableBlendMode),
		 def("disableBlendMode", (void(*)(void)) &ofDisableBlendMode),
         def("enablePointSprites", (void(*)(void)) &ofEnablePointSprites),
		 def("disablePointSprites", (void(*)(void)) &ofDisablePointSprites),
         //def("setPolyMode", (void(*)(ofPolyWindingMode)) &ofSetPolyMode),     NOT AVAILABLE
         //def("setRectMode", (void(*)(ofRectMode)) &ofSetRectMode),            NOT AVAILABLE
         // void ofBackground(int r, int g, int b, int a=255)                   NOT AVAILABLE
         // void ofBackground(int brightness, int alpha=255)                    NOT AVAILABLE
         // void ofBackground(const ofColor &c)                                 NOT AVAILABLE
         // void ofBackgroundHex(int hexColor, int alpha=255)                   NOT AVAILABLE
         // void ofSetBackgroundColor(int r, int g, int b, int a=255)           NOT AVAILABLE
         // void ofSetBackgroundColor(int brightness, int alpha=255)            NOT AVAILABLE
         // void ofSetBackgroundColor(const ofColor &c)                         NOT AVAILABLE
         // void ofSetBackgroundColorHex(int hexColor, int alpha=255)           NOT AVAILABLE
		 def("clear", (void(*)(float,float,float,float)) &ofClear),
         def("clear", (void(*)(float,float)) &ofClear),
		 def("clearAlpha", (void(*)(void)) &ofClearAlpha),
         def("triangle", (void(*)(float,float,float,float,float,float,float,float,float)) &ofTriangle),
         def("triangle", (void(*)(const ofPoint&,const ofPoint&,const ofPoint&)) &ofTriangle),
         def("circle", (void(*)(float,float,float,float)) &ofCircle),
         def("circle", (void(*)(const ofPoint&,float)) &ofCircle),
         def("ellipse",	(void(*)(float,float,float,float,float)) &ofEllipse),
         def("ellipse",	(void(*)(const ofPoint&,float,float)) &ofEllipse),
         def("line", (void(*)(float,float,float,float,float,float)) &ofLine),
         def("line", (void(*)(const ofPoint&,const ofPoint&)) &ofLine),
         def("rect", (void(*)(const ofRectangle&)) &ofRect),
         def("rect", (void(*)(const ofPoint&,float,float)) &ofRect),
         def("rect", (void(*)(float,float,float,float,float)) &ofRect),
         // def("curve", (void(*)(float,float,float,float,float,float,float,float,float,float,float,float)) &ofCurve),
         // def("bezier", (void(*)(float,float,float,float,float,float,float,float,float,float,float,float)) &ofBezier),
         //def("vertex", (void(*)(float,float,float)) &ofVertex),
         def("vertex", (void(*)(ofPoint&)) &ofVertex),
         // void ofVertexes(const vector< ofPoint > &polyPoints)                NOT AVAILABLE
         def("curveVertex",	(void(*)(ofPoint&)) &ofCurveVertex),
         // void ofCurveVertexes(const vector< ofPoint > &curvePoints)          NOT AVAILABLE
         def("bezierVertex", (void(*)(const ofPoint&,const ofPoint&,const ofPoint&)) &ofBezierVertex),
         def("bezierVertex", (void(*)(float,float,float,float,float,float,float,float,float)) &ofBezierVertex),
         def("sphere", (void(*)(float,float,float,float)) &ofSphere),
         def("sphere", (void(*)(float,float,float)) &ofSphere),
         def("sphere", (void(*)(const ofPoint&,float)) &ofSphere),
         def("sphere", (void(*)(float)) &ofSphere),
         def("box", (void(*)(float,float,float,float)) &ofBox),
         def("box", (void(*)(float,float,float)) &ofBox),
         def("box", (void(*)(const ofPoint&,float)) &ofBox),
         def("box", (void(*)(float)) &ofBox),
         // void ofSetDrawBitmapMode(ofDrawBitmapMode mode)                     NOT AVAILABLE
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofPixelsUtils
         
         // NOT AVAILABLE IN GAMUZA 0.3 IN THE LIVE CODING SYSTEM
         
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofTrueTypeFont
		 
		 class_<ofTrueTypeFont>("font")
		 .def(constructor<>())
         .def("loadFont", &loadFont2)
		 .def("loadFont", &loadFont4)
         .def("loadFont", (void(ofTrueTypeFont::*)(string,int)) &ofTrueTypeFont::loadFont)
		 .def("loadFont", (void(ofTrueTypeFont::*)(string,int,bool,bool,bool)) &ofTrueTypeFont::loadFont)
         .def("loadFont", (void(ofTrueTypeFont::*)(string,int,bool,bool,bool,float,int)) &ofTrueTypeFont::loadFont)
		 .def("getLineHeight", (float(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getLineHeight)
		 .def("setLineHeight", (void(ofTrueTypeFont::*)(float)) &ofTrueTypeFont::setLineHeight)
         .def("stringWidth", (float(ofTrueTypeFont::*)(string)) &ofTrueTypeFont::stringWidth)
		 .def("stringHeight", (float(ofTrueTypeFont::*)(string)) &ofTrueTypeFont::stringHeight)
         .def("getStringBoundingBox", (ofRectangle(ofTrueTypeFont::*)(string,float,float)) &ofTrueTypeFont::getStringBoundingBox)
         .def("drawString", (void(ofTrueTypeFont::*)(string,float,float)) &ofTrueTypeFont::drawString)
         .def("drawStringAsShapes", (void(ofTrueTypeFont::*)(string,float,float)) &ofTrueTypeFont::drawStringAsShapes)
         .def("isLoaded", (bool(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::isLoaded)
         .def("isAntiAliased", (bool(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::isAntiAliased)
         .def("hasFullCharacterSet", (bool(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::hasFullCharacterSet)
         .def("getSize", (int(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getSize)
		 .def("getLetterSpacing", (float(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getLetterSpacing)
		 .def("setLetterSpacing", (void(ofTrueTypeFont::*)(float)) &ofTrueTypeFont::setLetterSpacing)
		 .def("getSpaceSize", (float(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getSpaceSize)
		 .def("setSpaceSize", (void(ofTrueTypeFont::*)(float)) &ofTrueTypeFont::setSpaceSize)
		 .def("getNumCharacters", (int(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getNumCharacters)
         .def("getCharacterAsPoints", (ofTTFCharacter(ofTrueTypeFont::*)(int)) &ofTrueTypeFont::getCharacterAsPoints)
		 .def("getStringAsPoints", (vector<ofTTFCharacter>(ofTrueTypeFont::*)(string)) &ofTrueTypeFont::getStringAsPoints)
         .def("bind", (void(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::bind)
         .def("unbind", (void(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::unbind),
         // .def("setGlobalDpi", (void(ofTrueTypeFont::*)(int)) &ofTrueTypeFont::setGlobalDpi)                      NOT AVAILABLE
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofPolyLine
		 
		 class_<ofPolyline>("polyline")
		 .def(constructor<>())
         .def("clear", (void(ofPolyline::*)(void)) &ofPolyline::clear)
         .def("addVertex", (void(ofPolyline::*)(float,float,float)) &ofPolyline::addVertex)
         .def("addVertexes", (void(ofPolyline::*)(const vector<ofPoint>&)) &ofPolyline::addVertexes)
         .def("lineTo", (void(ofPolyline::*)(const ofPoint&)) &ofPolyline::lineTo)
         .def("lineTo", (void(ofPolyline::*)(float,float,float)) &ofPolyline::lineTo)
         .def("arc", (void(ofPolyline::*)(const ofPoint&,float,float,float,float,int)) &ofPolyline::arc)
         .def("arc", (void(ofPolyline::*)(float,float,float,float,float,float,int)) &ofPolyline::arc)
         .def("arc", (void(ofPolyline::*)(float,float,float,float,float,float,float,int)) &ofPolyline::arc)
         .def("curveTo", (void(ofPolyline::*)(const ofPoint&,int)) &ofPolyline::curveTo)
         .def("curveTo", (void(ofPolyline::*)(float,float,float,int)) &ofPolyline::curveTo) // float x, float y, float z, int curveResolution
         .def("bezierTo", (void(ofPolyline::*)(const ofPoint&,const ofPoint&,const ofPoint&,int)) &ofPolyline::bezierTo)
         .def("bezierTo", (void(ofPolyline::*)(float,float,float,float,float,float,int)) &ofPolyline::bezierTo)
         .def("bezierTo", (void(ofPolyline::*)(float,float,float,float,float,float,float,float,float,int)) &ofPolyline::bezierTo)
         .def("quadBezierTo", (void(ofPolyline::*)(const ofPoint&,const ofPoint&,const ofPoint&,int)) &ofPolyline::quadBezierTo)
         .def("quadBezierTo", (void(ofPolyline::*)(float,float,float,float,float,float,int)) &ofPolyline::quadBezierTo)
         .def("quadBezierTo", (void(ofPolyline::*)(float,float,float,float,float,float,float,float,float,int)) &ofPolyline::quadBezierTo)
         .def("getSmoothed", (ofPolyline(ofPolyline::*)(int,float)) &ofPolyline::getSmoothed) // int smoothingSize
         .def("getResampledBySpacing", (ofPolyline(ofPolyline::*)(float)) &ofPolyline::getResampledBySpacing) // float spacing
         .def("getResampledByCount", (ofPolyline(ofPolyline::*)(int)) &ofPolyline::getResampledByCount) // int count
         .def("getBoundingBox", (ofRectangle(ofPolyline::*)(void)) &ofPolyline::getBoundingBox)
         .def("getClosestPoint", (ofPoint(ofPolyline::*)(const ofPoint&,unsigned int*)) &ofPolyline::getClosestPoint)
         .def("simplify", (void(ofPolyline::*)(float)) &ofPolyline::simplify)
         .def("size", (size_t(ofPolyline::*)(void)) &ofPolyline::size)
         .def("resize", (void(ofPolyline::*)(size_t)) &ofPolyline::resize)
         .def("setClosed", (void(ofPolyline::*)(bool)) &ofPolyline::setClosed)
         .def("isClosed", (bool(ofPolyline::*)(void)) &ofPolyline::isClosed)
         .def("close", (void(ofPolyline::*)(void)) &ofPolyline::close)
         .def("hasChanged", (bool(ofPolyline::*)(void)) &ofPolyline::hasChanged)
         .def("getVertices", (vector<ofPoint>&(ofPolyline::*)(void)) &ofPolyline::getVertices)
         .def("getPerimeter", (float(ofPolyline::*)(void)) &ofPolyline::getPerimeter)
         .def("draw", (void(ofPolyline::*)(void)) &ofPolyline::draw),
		 
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofTessellator
         
         class_<ofTessellator>("tessellator")
		 .def(constructor<>())
         .def(constructor<const ofTessellator&>()),
         // void ofTessellator::tessellateToMesh(const vector< ofPolyline > &src, ofPolyWindingMode polyWindingMode, ofMesh &dstmesh, bool bIs2D=false)
         //.def("tessellateToMesh", (float(ofTessellator::*)(const ofPolyline&, ofPolyWindingMode, ofMesh&,bool)) &ofTessellator::tessellateToMesh),
         // void ofTessellator::tessellateToPolylines(const vector< ofPolyline > &src, ofPolyWindingMode polyWindingMode, vector< ofPolyline > &dstpoly, bool bIs2D=false)
         // void ofTessellator::tessellateToPolylines(const ofPolyline &src, ofPolyWindingMode polyWindingMode, vector< ofPolyline > &dstpoly, bool bIs2D=false)
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofRendererCollection
         
         // NOT AVAILABLE IN GAMUZA 0.3 IN THE LIVE CODING SYSTEM
         
		 
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section types [ofColor, ofStyle, ofTypes, ofRectangle, ofPoint]
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofColor
		 
		 class_<ofColor>("color")
		 .def(constructor<>())
		 .def(constructor<float,float,float,float>())
         .def(constructor<ofColor const&>())
         .def(constructor<ofColor const&,float>())
		 .def(constructor<float,float>())
         .def("getHex", (int(ofColor::*)(void)) &ofColor::getHex)
         .def("clamp", (ofColor(ofColor::*)(void)) &ofColor::clamp)
         .def("invert", (ofColor(ofColor::*)(void)) &ofColor::invert)
         .def("normalize", (ofColor(ofColor::*)(void)) &ofColor::normalize)
         .def("getClamped", (ofColor(ofColor::*)(void)) &ofColor::getClamped)
         .def("getInverted", (ofColor(ofColor::*)(void)) &ofColor::getInverted)
         .def("getNormalized", (ofColor(ofColor::*)(void)) &ofColor::getNormalized)
         .def("getHue", (float(ofColor::*)(void)) &ofColor::getHue)
		 .def("getSaturation", (float(ofColor::*)(void)) &ofColor::getSaturation)
		 .def("getBrightness", (float(ofColor::*)(void)) &ofColor::getBrightness)
         .def("getLightness", (float(ofColor::*)(void)) &ofColor::getLightness)
         .def("setHue", (void(ofColor::*)(float)) &ofColor::setHue)
		 .def("setSaturation", (void(ofColor::*)(float)) &ofColor::setSaturation)
		 .def("setBrightness", (void(ofColor::*)(float)) &ofColor::setBrightness)
         .def("setHsb", (void(ofColor::*)(float,float,float,float)) &ofColor::setHsb)
         .def("setHsb", (void(ofColor::*)(float,float,float)) &ofColor::setHsb)
		 .def("set", (void(ofColor::*)(float,float,float,float)) &ofColor::set)
		 .def("set", (void(ofColor::*)(float,float)) &ofColor::set)
         .def("set", (void(ofColor::*)(ofColor const&)) &ofColor::set)
		 .def("setHex", (void(ofColor::*)(int,float)) &ofColor::setHex)
		 .def("lerp", (ofColor(ofColor::*)(const ofColor&, float)) &ofColor::lerp)
         .def("getLerped", (ofColor(ofColor::*)(const ofColor&, float)) &ofColor::getLerped)
		 .def("getHsb", (void(ofColor::*)(float&,float&,float&)) &ofColor::getHsb)
		 //.def("fromHsb", (ofColor(ofColor::*)(float,float,float,float)) &ofColor::fromHsb)    NOT AVAILABLE
		 //.def("fromHex", (ofColor(ofColor::*)(int,float)) &ofColor::fromHex)                  NOT AVAILABLE
         .def_readonly("r", &ofColor::r)
		 .def_readonly("g", &ofColor::g)
		 .def_readonly("b", &ofColor::b)
		 .def_readonly("a", &ofColor::a),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofFloatColor
		 
		 class_<ofFloatColor>("floatColor")
		 .def(constructor<>())
		 .def(constructor<float,float,float,float>())
         .def(constructor<ofFloatColor const&>())
         .def(constructor<ofFloatColor const&,float>())
		 .def(constructor<float,float>())
         .def("getHex", (int(ofFloatColor::*)(void)) &ofFloatColor::getHex)
         .def("clamp", (ofFloatColor(ofFloatColor::*)(void)) &ofFloatColor::clamp)
         .def("invert", (ofFloatColor(ofFloatColor::*)(void)) &ofFloatColor::invert)
         .def("normalize", (ofFloatColor(ofFloatColor::*)(void)) &ofFloatColor::normalize)
         .def("getClamped", (ofFloatColor(ofFloatColor::*)(void)) &ofFloatColor::getClamped)
         .def("getInverted", (ofFloatColor(ofFloatColor::*)(void)) &ofFloatColor::getInverted)
         .def("getNormalized", (ofFloatColor(ofFloatColor::*)(void)) &ofFloatColor::getNormalized)
         .def("getHue", (float(ofFloatColor::*)(void)) &ofFloatColor::getHue)
		 .def("getSaturation", (float(ofFloatColor::*)(void)) &ofFloatColor::getSaturation)
		 .def("getBrightness", (float(ofFloatColor::*)(void)) &ofFloatColor::getBrightness)
         .def("getLightness", (float(ofFloatColor::*)(void)) &ofFloatColor::getLightness)
         .def("setHue", (void(ofFloatColor::*)(float)) &ofFloatColor::setHue)
		 .def("setSaturation", (void(ofFloatColor::*)(float)) &ofFloatColor::setSaturation)
		 .def("setBrightness", (void(ofFloatColor::*)(float)) &ofFloatColor::setBrightness)
         .def("setHsb", (void(ofFloatColor::*)(float,float,float,float)) &ofFloatColor::setHsb)
         .def("setHsb", (void(ofFloatColor::*)(float,float,float)) &ofFloatColor::setHsb)
		 .def("set", (void(ofFloatColor::*)(float,float,float,float)) &ofFloatColor::set)
		 .def("set", (void(ofFloatColor::*)(float,float)) &ofFloatColor::set)
         .def("set", (void(ofFloatColor::*)(ofFloatColor const&)) &ofFloatColor::set)
		 .def("setHex", (void(ofFloatColor::*)(int,float)) &ofFloatColor::setHex)
		 .def("lerp", (ofFloatColor(ofFloatColor::*)(const ofFloatColor&, float)) &ofFloatColor::lerp)
         .def("getLerped", (ofFloatColor(ofFloatColor::*)(const ofFloatColor&, float)) &ofFloatColor::getLerped)
		 .def("getHsb", (void(ofFloatColor::*)(float&,float&,float&)) &ofFloatColor::getHsb)
		 //.def("fromHsb", (ofFloatColor(ofFloatColor::*)(float,float,float,float)) &ofFloatColor::fromHsb)    NOT AVAILABLE
		 //.def("fromHex", (ofFloatColor(ofFloatColor::*)(int,float)) &ofFloatColor::fromHex)                  NOT AVAILABLE
         .def_readonly("r", &ofFloatColor::r)
		 .def_readonly("g", &ofFloatColor::g)
		 .def_readonly("b", &ofFloatColor::b)
		 .def_readonly("a", &ofFloatColor::a),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofShortColor
		 
		 class_<ofShortColor>("shortColor")
		 .def(constructor<>())
		 .def(constructor<float,float,float,float>())
         .def(constructor<ofShortColor const&>())
         .def(constructor<ofShortColor const&,float>())
		 .def(constructor<float,float>())
         .def("getHex", (int(ofShortColor::*)(void)) &ofShortColor::getHex)
         .def("clamp", (ofShortColor(ofShortColor::*)(void)) &ofShortColor::clamp)
         .def("invert", (ofShortColor(ofShortColor::*)(void)) &ofShortColor::invert)
         .def("normalize", (ofShortColor(ofShortColor::*)(void)) &ofShortColor::normalize)
         .def("getClamped", (ofShortColor(ofShortColor::*)(void)) &ofShortColor::getClamped)
         .def("getInverted", (ofShortColor(ofShortColor::*)(void)) &ofShortColor::getInverted)
         .def("getNormalized", (ofShortColor(ofShortColor::*)(void)) &ofShortColor::getNormalized)
         .def("getHue", (float(ofShortColor::*)(void)) &ofShortColor::getHue)
		 .def("getSaturation", (float(ofShortColor::*)(void)) &ofShortColor::getSaturation)
		 .def("getBrightness", (float(ofShortColor::*)(void)) &ofShortColor::getBrightness)
         .def("getLightness", (float(ofShortColor::*)(void)) &ofShortColor::getLightness)
         .def("setHue", (void(ofShortColor::*)(float)) &ofShortColor::setHue)
		 .def("setSaturation", (void(ofShortColor::*)(float)) &ofShortColor::setSaturation)
		 .def("setBrightness", (void(ofShortColor::*)(float)) &ofShortColor::setBrightness)
         .def("setHsb", (void(ofShortColor::*)(float,float,float,float)) &ofShortColor::setHsb)
         .def("setHsb", (void(ofShortColor::*)(float,float,float)) &ofShortColor::setHsb)
		 .def("set", (void(ofShortColor::*)(float,float,float,float)) &ofShortColor::set)
		 .def("set", (void(ofShortColor::*)(float,float)) &ofShortColor::set)
         .def("set", (void(ofShortColor::*)(ofShortColor const&)) &ofShortColor::set)
		 .def("setHex", (void(ofShortColor::*)(int,float)) &ofShortColor::setHex)
		 .def("lerp", (ofShortColor(ofShortColor::*)(const ofShortColor&, float)) &ofShortColor::lerp)
         .def("getLerped", (ofShortColor(ofShortColor::*)(const ofShortColor&, float)) &ofShortColor::getLerped)
		 .def("getHsb", (void(ofShortColor::*)(float&,float&,float&)) &ofShortColor::getHsb)
		 //.def("fromHsb", (ofShortColor(ofShortColor::*)(float,float,float,float)) &ofShortColor::fromHsb)    NOT AVAILABLE
		 //.def("fromHex", (ofShortColor(ofShortColor::*)(int,float)) &ofShortColor::fromHex)                  NOT AVAILABLE
         .def_readonly("r", &ofShortColor::r)
		 .def_readonly("g", &ofShortColor::g)
		 .def_readonly("b", &ofShortColor::b)
		 .def_readonly("a", &ofShortColor::a),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofStyle
         
         class_<ofStyle>("style")
		 .def(constructor<>())
         .def_readwrite("color", &ofStyle::color)
         .def_readwrite("polyMode", &ofStyle::polyMode)
         .def_readwrite("rectMode", &ofStyle::rectMode)
         .def_readwrite("bFill", &ofStyle::bFill)
         // .def_readwrite("blending", &ofStyle::blending)                              NOT AVAILABLE
         .def_readwrite("smoothing", &ofStyle::smoothing)
         .def_readwrite("circleResolution", &ofStyle::circleResolution)
         .def_readwrite("lineWidth", &ofStyle::lineWidth)
         .def_readwrite("bgColor", &ofStyle::bgColor)
         .def_readwrite("drawBitmapMode", &ofStyle::drawBitmapMode)
         .def_readwrite("blendingMode", &ofStyle::blendingMode)
         .def_readwrite("sphereResolution", &ofStyle::sphereResolution)
         .def_readwrite("curveResolution", &ofStyle::curveResolution),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofTypes
         
         ////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofRectangle
         
         class_<ofRectangle>("rectangle")
		 .def(constructor<>())
         .def(constructor<float,float,float,float>())
         //.def(constructor<ofPoint,float,float>())                                     NOT AVAILABLE
		 .def(constructor<ofRectangle const&>())
		 .def("set", (void(ofRectangle::*)(float,float,float,float)) &ofRectangle::set)
         .def("set", (void(ofRectangle::*)(ofPoint,float,float)) &ofRectangle::set)
		 .def("set", (void(ofRectangle::*)(const ofRectangle&)) &ofRectangle::set)
		 .def("setFromCenter", (void(ofRectangle::*)(float,float,float,float)) &ofRectangle::setFromCenter)
         .def("setFromCenter", (void(ofRectangle::*)(ofPoint,float,float)) &ofRectangle::setFromCenter)
         .def("getCenter", (ofPoint(ofRectangle::*)(void)) &ofRectangle::getCenter)
         .def("inside", (bool(ofRectangle::*)(ofPoint)) &ofRectangle::inside)
		 .def("inside", (bool(ofRectangle::*)(float,float)) &ofRectangle::inside)
		 .def_readonly("x", &ofRectangle::x)
		 .def_readonly("y", &ofRectangle::y)
		 .def_readonly("width", &ofRectangle::width)
		 .def_readonly("height", &ofRectangle::height),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofPoint
         
         
         // NOT AVAILABLE IN GAMUZA 0.3 IN THE LIVE CODING SYSTEM
         //
         // Use instead ofVec2f --> in live coding of.vec2f()
         
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section events [ofKeyEventArgs, ofAudioEventArgs, ofCoreEvents, ofEventArgs, ofEvent, ofMouseEventArgs, ofResizeEventArgs, ofEvents, ofEventUtils]
         
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofEvents
         
         def("getMousePressed", &ofGetMousePressed),
         def("getKeyPressed", &ofGetKeyPressed),
         def("getMouseX", &ofGetMouseX),
         def("getMouseY", &ofGetMouseY),
         def("getPreviousMouseX", &ofGetPreviousMouseX),
         def("getPreviousMouseY", &ofGetPreviousMouseY),
         
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section sound [ofSoundPlayer, ofSoundStream]
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofSoundPlayer
		 
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
		 .def("getPan", (float(ofSoundPlayer::*)(void)) &ofSoundPlayer::getPan)
         //.def("setPositionMS", (void(ofSoundPlayer::*)(int)) &ofSoundPlayer::setPositionMS)
         //.def("getPositionMS", (int(ofSoundPlayer::*)(void)) &ofSoundPlayer::getPositionMS)
         //.def_readonly("isStreaming", &ofSoundPlayer::isStreaming)
		 //.def_readonly("bMultiPlay", &ofSoundPlayer::bMultiPlay)
		 //.def_readonly("bLoop", &ofSoundPlayer::bLoop)
		 //.def_readonly("bLoadedOk", &ofSoundPlayer::bLoadedOk)
         //.def_readonly("bPaused", &ofSoundPlayer::bPaused)
		 //.def_readonly("pan", &ofSoundPlayer::pan)
		 //.def_readonly("volume", &ofSoundPlayer::volume)
		 //.def_readonly("speed", &ofSoundPlayer::speed)
         //.def_readonly("length", &ofSoundPlayer::length),
         
         ///////////////////////////////////////////////////////////////////////////////////
		 /// \section ofSoundStream
         
         // LIMITED, ofSoundStream NOT AVAILABLE IN GAMUZA 0.3 IN THE LIVE CODING SYSTEM
         // &
         // MANAGED FROM GUI (audio module) & FROM gamuza LIVE CODING FUNCTIONS (ga. module)
         
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section application [ofAppBaseWindow, ofDragInfo, ofAppRunner, ofBaseApp]
         
         // NOT AVAILABLE IN GAMUZA 0.3 IN THE LIVE CODING SYSTEM, DUE TO THE HYBRID LIVE-CODING NATURE OF GAMUZA
        
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 /// \section serial
         
         // NOT AVAILABLE IN GAMUZA 0.3 IN THE LIVE CODING SYSTEM, MANAGED FROM GUI (arduino module)
         
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		 
		 
		];
        
        //////////////////////////////////////////////////////////////
		///////////////////////////////
		/// OpenFrameworks 007 addons api wrapper
		module(lua, "ofx")
		[
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFX3DMODELLOADER
         
         ///////////////////////////////
         // ofx3DBaseLoader
         class_<ofx3DBaseLoader>("BaseLoader3D")
         .def(constructor<>())
         .def("loadModel", (void(ofx3DBaseLoader::*)(string,float)) &ofx3DBaseLoader::loadModel)
         .def("loadModel", (void(ofx3DBaseLoader::*)(string)) &ofx3DBaseLoader::loadModel)
         .def("draw", (void(ofx3DBaseLoader::*)(void)) &ofx3DBaseLoader::draw)
         .def_readonly("hasTexture", &ofx3DBaseLoader::hasTexture),
         
         ///////////////////////////////
         // ofx3DModelLoader
         class_<ofx3DModelLoader>("ModelLoader3D")
         .def(constructor<>())
         .def("loadModel", (void(ofx3DModelLoader::*)(string,float)) &ofx3DModelLoader::loadModel)
         .def("setPosition", (void(ofx3DModelLoader::*)(float,float,float)) &ofx3DModelLoader::setPosition)
         .def("setScale", (void(ofx3DModelLoader::*)(float,float,float)) &ofx3DModelLoader::setScale)
         .def("setRotation", (void(ofx3DModelLoader::*)(int,float,float,float,float)) &ofx3DModelLoader::setRotation)
         .def("draw", (void(ofx3DModelLoader::*)(void)) &ofx3DModelLoader::draw)
         .def_readonly("rotAngle", &ofx3DModelLoader::rotAngle)
         .def_readonly("rotAxis", &ofx3DModelLoader::rotAxis)
         .def_readonly("scale", &ofx3DModelLoader::scale)
         .def_readonly("pos", &ofx3DModelLoader::pos)
         .def_readonly("numRotations", &ofx3DModelLoader::numRotations)
         .def_readonly("model", &ofx3DModelLoader::model),
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXNETWORK
         
         ///////////////////////////////
         // ofxTCPClient
         class_<ofxTCPClient>("TCPClient")
         .def(constructor<>())
         .def("setVerbose", (void(ofxTCPClient::*)(bool)) &ofxTCPClient::setVerbose)
         .def("setup", (bool(ofxTCPClient::*)(string,int,bool)) &ofxTCPClient::setup)
         .def("setMessageDelimiter", (void(ofxTCPClient::*)(string)) &ofxTCPClient::setMessageDelimiter)
         .def("close", (bool(ofxTCPClient::*)(void)) &ofxTCPClient::close)
         .def("send", (bool(ofxTCPClient::*)(string)) &ofxTCPClient::send)
         .def("sendRaw", (bool(ofxTCPClient::*)(string)) &ofxTCPClient::sendRaw)
         .def("getNumReceivedBytes", (int(ofxTCPClient::*)(void)) &ofxTCPClient::getNumReceivedBytes)
         .def("sendRawBytes", (bool(ofxTCPClient::*)(const char*, const int)) &ofxTCPClient::sendRawBytes)
         .def("receive", (string(ofxTCPClient::*)(void)) &ofxTCPClient::receive)
         .def("receiveRaw", (string(ofxTCPClient::*)(void)) &ofxTCPClient::receiveRaw)
         .def("receiveRawBytes", (int(ofxTCPClient::*)(const char*,int)) &ofxTCPClient::receiveRawBytes)
         .def("isConnected", (bool(ofxTCPClient::*)(void)) &ofxTCPClient::isConnected)
         .def("getPort", (int(ofxTCPClient::*)(void)) &ofxTCPClient::getPort)
         .def("getIP", (string(ofxTCPClient::*)(void)) &ofxTCPClient::getIP)
         .def("setup", (bool(ofxTCPClient::*)(int,bool)) &ofxTCPClient::setup)
         .def_readonly("TCPClient", &ofxTCPClient::TCPClient),
         
         ///////////////////////////////
         // ofxUDPManager
         class_<ofxUDPManager>("UDPManager")
         .def(constructor<>())
         .def("Close", (bool(ofxUDPManager::*)(void)) &ofxUDPManager::Close)
         .def("Create", (bool(ofxUDPManager::*)(void)) &ofxUDPManager::Create)
         .def("Connect", (bool(ofxUDPManager::*)(const char*,unsigned short)) &ofxUDPManager::Connect)
         .def("ConnectMcast", (bool(ofxUDPManager::*)(const char*,unsigned short)) &ofxUDPManager::ConnectMcast)
         .def("Bind", (bool(ofxUDPManager::*)(unsigned short)) &ofxUDPManager::Bind)
         .def("BindMcast", (bool(ofxUDPManager::*)(const char*,unsigned short)) &ofxUDPManager::BindMcast)
         .def("Send", (int(ofxUDPManager::*)(const char*,const int)) &ofxUDPManager::Send)
         .def("SendAll", (int(ofxUDPManager::*)(const char*,const int)) &ofxUDPManager::SendAll)
         .def("Receive", (int(ofxUDPManager::*)(const char*,const int)) &ofxUDPManager::Receive)
         .def("SetTimeoutSend", (void(ofxUDPManager::*)(int)) &ofxUDPManager::SetTimeoutSend)
         .def("SetTimeoutReceive", (void(ofxUDPManager::*)(int)) &ofxUDPManager::SetTimeoutReceive)
         .def("GetTimeoutSend", (int(ofxUDPManager::*)(void)) &ofxUDPManager::GetTimeoutSend)
         .def("GetTimeoutReceive", (int(ofxUDPManager::*)(void)) &ofxUDPManager::GetTimeoutReceive)
         .def("GetRemoteAddr", (bool(ofxUDPManager::*)(const char*)) &ofxUDPManager::GetRemoteAddr)
         .def("SetReceiveBufferSize", (bool(ofxUDPManager::*)(int)) &ofxUDPManager::SetReceiveBufferSize)
         .def("SetSendBufferSize", (bool(ofxUDPManager::*)(int)) &ofxUDPManager::SetSendBufferSize)
         .def("GetReceiveBufferSize", (int(ofxUDPManager::*)(void)) &ofxUDPManager::GetReceiveBufferSize)
         .def("GetSendBufferSize", (int(ofxUDPManager::*)(void)) &ofxUDPManager::GetSendBufferSize)
         .def("SetReuseAddress", (bool(ofxUDPManager::*)(bool)) &ofxUDPManager::SetReuseAddress)
         .def("SetEnableBroadcast", (bool(ofxUDPManager::*)(bool)) &ofxUDPManager::SetEnableBroadcast)
         .def("SetNonBlocking", (bool(ofxUDPManager::*)(bool)) &ofxUDPManager::SetNonBlocking)
         .def("GetMaxMsgSize", (int(ofxUDPManager::*)(void)) &ofxUDPManager::GetMaxMsgSize)
         .def("GetTTL", (int(ofxUDPManager::*)(void)) &ofxUDPManager::GetTTL)
         .def("SetTTL", (bool(ofxUDPManager::*)(int)) &ofxUDPManager::SetTTL),
         
         ///////////////////////////////
         // ofxTCPManager
         class_<ofxTCPManager>("TCPManager")
         .def(constructor<>())
         .def("Close", (bool(ofxTCPManager::*)(void)) &ofxTCPManager::Close)
         .def("Create", (bool(ofxTCPManager::*)(void)) &ofxTCPManager::Create)
         .def("Listen", (bool(ofxTCPManager::*)(int)) &ofxTCPManager::Listen)
         .def("Connect", (bool(ofxTCPManager::*)(const char*,unsigned short)) &ofxTCPManager::Connect)
         .def("Bind", (bool(ofxTCPManager::*)(unsigned short)) &ofxTCPManager::Bind)
         .def("Accept", (bool(ofxTCPManager::*)(ofxTCPManager&)) &ofxTCPManager::Accept)
         .def("Send", (int(ofxTCPManager::*)(const char*,const int)) &ofxTCPManager::Send)
         .def("SendAll", (int(ofxTCPManager::*)(const char*,const int)) &ofxTCPManager::SendAll)
         .def("Receive", (int(ofxTCPManager::*)(const char*,const int)) &ofxTCPManager::Receive)
         .def("ReceiveAll", (int(ofxTCPManager::*)(const char*,const int)) &ofxTCPManager::ReceiveAll)
         .def("Write", (int(ofxTCPManager::*)(const char*,const int)) &ofxTCPManager::Write)
         .def("GetRemoteAddr", &ofxTCPManager::GetRemoteAddr)
         .def("GetInetAddr", &ofxTCPManager::GetInetAddr)
         .def("SetTimeoutSend", (void(ofxTCPManager::*)(int)) &ofxTCPManager::SetTimeoutSend)
         .def("SetTimeoutReceive", (void(ofxTCPManager::*)(int)) &ofxTCPManager::SetTimeoutReceive)
         .def("SetTimeoutAccept", (void(ofxTCPManager::*)(int)) &ofxTCPManager::SetTimeoutAccept)
         .def("GetTimeoutSend", (int(ofxTCPManager::*)(void)) &ofxTCPManager::GetTimeoutSend)
         .def("GetTimeoutReceive", (int(ofxTCPManager::*)(void)) &ofxTCPManager::GetTimeoutReceive)
         .def("GetTimeoutAccept", (int(ofxTCPManager::*)(void)) &ofxTCPManager::GetTimeoutAccept)
         .def("SetReceiveBufferSize", (bool(ofxTCPManager::*)(int)) &ofxTCPManager::SetReceiveBufferSize)
         .def("SetSendBufferSize", (bool(ofxTCPManager::*)(int)) &ofxTCPManager::SetSendBufferSize)
         .def("GetReceiveBufferSize", (int(ofxTCPManager::*)(void)) &ofxTCPManager::GetReceiveBufferSize)
         .def("GetSendBufferSize", (int(ofxTCPManager::*)(void)) &ofxTCPManager::GetSendBufferSize)
         .def("GetMaxConnections", (int(ofxTCPManager::*)(void)) &ofxTCPManager::GetMaxConnections)
         .def("SetNonBlocking", (bool(ofxTCPManager::*)(bool)) &ofxTCPManager::SetNonBlocking)
         .def("CheckHost", (bool(ofxTCPManager::*)(const char*)) &ofxTCPManager::CheckHost)
         .def("CleanUp", (void(ofxTCPManager::*)(void)) &ofxTCPManager::CleanUp),
         
         ///////////////////////////////
         // ofxTCPServer
         class_<ofxTCPServer>("TCPServer")
         .def(constructor<>())
         .def("setVerbose", (void(ofxTCPServer::*)(bool)) &ofxTCPServer::setVerbose)
         .def("setup", (bool(ofxTCPServer::*)(int,bool)) &ofxTCPServer::setup)
         .def("setMessageDelimiter", (void(ofxTCPServer::*)(string)) &ofxTCPServer::setMessageDelimiter)
         .def("close", (bool(ofxTCPServer::*)(void)) &ofxTCPServer::close)
         .def("disconnectClient", (bool(ofxTCPServer::*)(int)) &ofxTCPServer::disconnectClient)
         .def("getNumClients", (int(ofxTCPServer::*)(void)) &ofxTCPServer::getNumClients)
         .def("getLastID", (int(ofxTCPServer::*)(void)) &ofxTCPServer::getLastID)
         .def("getPort", (int(ofxTCPServer::*)(void)) &ofxTCPServer::getPort)
         .def("isConnected", (bool(ofxTCPServer::*)(void)) &ofxTCPServer::isConnected)
         .def("getClientPort", (int(ofxTCPServer::*)(int)) &ofxTCPServer::getClientPort)
         .def("getClientIP", (string(ofxTCPServer::*)(int)) &ofxTCPServer::getClientIP)
         .def("isClientSetup", (bool(ofxTCPServer::*)(int)) &ofxTCPServer::isClientSetup)
         .def("isClientConnected", (bool(ofxTCPServer::*)(int)) &ofxTCPServer::isClientConnected)
         .def("send", (bool(ofxTCPServer::*)(int,string)) &ofxTCPServer::send)
         .def("sendToAll", (bool(ofxTCPServer::*)(string)) &ofxTCPServer::sendToAll)
         .def("sendRawBytes", (bool(ofxTCPServer::*)(int, const char*, const int)) &ofxTCPServer::sendRawBytes)
         .def("sendRawBytesToAll", (bool(ofxTCPServer::*)(const char*, const int)) &ofxTCPServer::sendRawBytesToAll)
         .def("getNumReceivedBytes", (int(ofxTCPServer::*)(int)) &ofxTCPServer::getNumReceivedBytes)
         .def("receive", (string(ofxTCPServer::*)(int)) &ofxTCPServer::receive)
         .def("receiveRawBytes", (void(ofxTCPServer::*)(int, const char*, int)) &ofxTCPServer::receiveRawBytes)
         .def_readonly("TCPServer", &ofxTCPServer::TCPServer)
		 .def_readonly("TCPConnections", &ofxTCPServer::TCPConnections),
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXVECTORGRAPHICS
         
         class_<ofxVectorGraphics>("vectorGraphics")
         .def(constructor<>())
         .def("beginEPS", (void(ofxVectorGraphics::*)(string,int,int,int,int)) &ofxVectorGraphics::beginEPS)
         .def("endEPS", (void(ofxVectorGraphics::*)(void)) &ofxVectorGraphics::endEPS)
         .def("enableDraw", (void(ofxVectorGraphics::*)(void)) &ofxVectorGraphics::enableDraw)
         .def("disableDraw", (void(ofxVectorGraphics::*)(void)) &ofxVectorGraphics::disableDraw)
         .def("enableCenterRect", (void(ofxVectorGraphics::*)(void)) &ofxVectorGraphics::enableCenterRect)
         .def("disableCenterRect", (void(ofxVectorGraphics::*)(void)) &ofxVectorGraphics::disableCenterRect)
         .def("fill", (void(ofxVectorGraphics::*)(void)) &ofxVectorGraphics::fill)
         .def("noFill", (void(ofxVectorGraphics::*)(void)) &ofxVectorGraphics::noFill)
         .def("setLineWidth", (void(ofxVectorGraphics::*)(float)) &ofxVectorGraphics::setLineWidth)
         .def("setColor", (void(ofxVectorGraphics::*)(int,int,int)) &ofxVectorGraphics::setColor)
         .def("setColor", (void(ofxVectorGraphics::*)(int)) &ofxVectorGraphics::setColor)
         .def("changeColor", (void(ofxVectorGraphics::*)(float,float,float)) &ofxVectorGraphics::changeColor)
         .def("rect", (void(ofxVectorGraphics::*)(float,float,float,float)) &ofxVectorGraphics::rect)
         .def("triangle", (void(ofxVectorGraphics::*)(float,float,float,float,float,float)) &ofxVectorGraphics::triangle)
         .def("circle", (void(ofxVectorGraphics::*)(float,float,float)) &ofxVectorGraphics::circle)
         .def("ellipse", (void(ofxVectorGraphics::*)(float,float,float,float)) &ofxVectorGraphics::ellipse)
         .def("line", (void(ofxVectorGraphics::*)(float,float,float,float)) &ofxVectorGraphics::line)
         .def("arc", (void(ofxVectorGraphics::*)(float,float,float,float,float)) &ofxVectorGraphics::arc)
         .def("bezier", (void(ofxVectorGraphics::*)(float,float,float,float,float,float,float,float)) &ofxVectorGraphics::bezier)
         .def("curve", (void(ofxVectorGraphics::*)(float,float,float,float,float,float,float,float)) &ofxVectorGraphics::curve)
         .def("beginShape", (void(ofxVectorGraphics::*)(void)) &ofxVectorGraphics::beginShape)
         .def("polyVertex", (void(ofxVectorGraphics::*)(float,float)) &ofxVectorGraphics::polyVertex)
         .def("bezierVertex", (void(ofxVectorGraphics::*)(float,float,float,float,float,float)) &ofxVectorGraphics::bezierVertex)
         .def("curveVertex", (void(ofxVectorGraphics::*)(float,float)) &ofxVectorGraphics::curveVertex)
         .def("endShape", (void(ofxVectorGraphics::*)(bool)) &ofxVectorGraphics::endShape)
         .def_readonly("creeps", &ofxVectorGraphics::creeps),
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXOPENCV
         
         ///////////////////////////////
         // ofxCvColorImage
         
         class_<ofxCvColorImage>("cvColorImage")
         .def(constructor<>())
         .def(constructor<const ofxCvColorImage&>())
         
         .def("allocate", (void(ofxCvColorImage::*)(int,int)) &ofxCvColorImage::allocate)
         .def("clear", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::clear)
         .def("getWidth", (float(ofxCvColorImage::*)(void)) &ofxCvColorImage::getWidth)
         .def("getHeight", (float(ofxCvColorImage::*)(void)) &ofxCvColorImage::getHeight)
         .def("setUseTexture", (void(ofxCvColorImage::*)(bool)) &ofxCvColorImage::setUseTexture)
         .def("getTextureReference", (ofTexture&(ofxCvColorImage::*)(void)) &ofxCvColorImage::getTextureReference)
         .def("flagImageChanged", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::flagImageChanged)
         .def("setROI", (void(ofxCvColorImage::*)(int,int,int,int)) &ofxCvColorImage::setROI)
         .def("setROI", (void(ofxCvColorImage::*)(const ofRectangle&)) &ofxCvColorImage::setROI)
         .def("getROI", (ofRectangle(ofxCvColorImage::*)(void)) &ofxCvColorImage::getROI)
         .def("resetROI", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::resetROI)
         .def("getIntersectionROI", (ofRectangle(ofxCvColorImage::*)(const ofRectangle&,const ofRectangle&)) &ofxCvColorImage::getIntersectionROI)
         .def("setFromPixels", (void(ofxCvColorImage::*)(const ofPixels&)) &ofxCvColorImage::setFromPixels)
         .def("setRoiFromPixels", (void(ofxCvColorImage::*)(const ofPixels&)) &ofxCvColorImage::setRoiFromPixels)
         .def("updateTexture", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::updateTexture)
         .def("draw", (void(ofxCvColorImage::*)(float,float)) &ofxCvColorImage::draw)
         .def("draw", (void(ofxCvColorImage::*)(float,float,float,float)) &ofxCvColorImage::draw)
         .def("draw", (void(ofxCvColorImage::*)(const ofRectangle&)) &ofxCvColorImage::draw)
         .def("drawROI", (void(ofxCvColorImage::*)(float,float)) &ofxCvColorImage::drawROI)
         .def("drawROI", (void(ofxCvColorImage::*)(float,float,float,float)) &ofxCvColorImage::drawROI)
         .def("setAnchorPercent", (void(ofxCvColorImage::*)(float,float)) &ofxCvColorImage::setAnchorPercent)
         .def("setAnchorPoint", (void(ofxCvColorImage::*)(float,float)) &ofxCvColorImage::setAnchorPoint)
         .def("resetAnchor", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::resetAnchor)
         .def("erode", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::erode)
         .def("dilate", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::dilate)
         .def("blur", (void(ofxCvColorImage::*)(int)) &ofxCvColorImage::blur)
         .def("blurGaussian", (void(ofxCvColorImage::*)(int)) &ofxCvColorImage::blurGaussian)
         .def("invert", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::invert)
         .def("mirror", (void(ofxCvColorImage::*)(bool,bool)) &ofxCvColorImage::mirror)
         .def("translate", (void(ofxCvColorImage::*)(float,float)) &ofxCvColorImage::translate)
         .def("rotate", (void(ofxCvColorImage::*)(float,float,float)) &ofxCvColorImage::rotate)
         .def("scale", (void(ofxCvColorImage::*)(float,float)) &ofxCvColorImage::scale)
         .def("transform", (void(ofxCvColorImage::*)(float,float,float,float,float,float,float)) &ofxCvColorImage::transform)
         .def("undistort", (void(ofxCvColorImage::*)(float,float,float,float,float,float,float,float)) &ofxCvColorImage::undistort)
         .def("warpPerspective", (void(ofxCvColorImage::*)(const ofPoint&,const ofPoint&,const ofPoint&,const ofPoint&)) &ofxCvColorImage::warpPerspective)
         .def("warpIntoMe", (void(ofxCvColorImage::*)(ofxCvImage&,const ofPoint,const ofPoint)) &ofxCvColorImage::warpIntoMe)
         .def("countNonZeroInRegion", (void(ofxCvColorImage::*)(int,int,int,int)) &ofxCvColorImage::countNonZeroInRegion)
         
         .def("set", (void(ofxCvColorImage::*)(float)) &ofxCvColorImage::set)
         .def("set", (void(ofxCvColorImage::*)(int,int,int)) &ofxCvColorImage::set)
         .def("setFromGrayscalePlanarImages", (void(ofxCvColorImage::*)(ofxCvGrayscaleImage&,ofxCvGrayscaleImage&,ofxCvGrayscaleImage&)) &ofxCvColorImage::setFromGrayscalePlanarImages)
         .def("convertToGrayscalePlanarImages", (void(ofxCvColorImage::*)(ofxCvGrayscaleImage&,ofxCvGrayscaleImage&,ofxCvGrayscaleImage&)) &ofxCvColorImage::convertToGrayscalePlanarImages)
         .def("convertToGrayscalePlanarImages", (void(ofxCvColorImage::*)(ofxCvGrayscaleImage&,int)) &ofxCvColorImage::convertToGrayscalePlanarImages)
         .def("contrastStretch", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::contrastStretch)
         .def("convertToRange", (void(ofxCvColorImage::*)(float,float)) &ofxCvColorImage::convertToRange)
         .def("resize", (void(ofxCvColorImage::*)(int,int)) &ofxCvColorImage::resize)
         .def("scaleIntoMe", &scaleIntoMeColor)
         .def("convertRgbToHsv", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::convertRgbToHsv)
         .def("convertHsvToRgb", (void(ofxCvColorImage::*)(void)) &ofxCvColorImage::convertHsvToRgb)
         .def_readonly("width", &ofxCvColorImage::width)
		 .def_readonly("height", &ofxCvColorImage::height)
         .def_readonly("bAllocated", &ofxCvColorImage::bAllocated),
         
         ///////////////////////////////
         // ofxCvGrayscaleImage
         
         class_<ofxCvGrayscaleImage>("cvGrayscaleImage")
         .def(constructor<>())
         .def(constructor<const ofxCvGrayscaleImage&>())
         
         .def("allocate", (void(ofxCvGrayscaleImage::*)(int,int)) &ofxCvGrayscaleImage::allocate)
         .def("clear", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::clear)
         .def("getWidth", (float(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::getWidth)
         .def("getHeight", (float(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::getHeight)
         .def("setUseTexture", (void(ofxCvGrayscaleImage::*)(bool)) &ofxCvGrayscaleImage::setUseTexture)
         .def("getTextureReference", (ofTexture&(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::getTextureReference)
         .def("flagImageChanged", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::flagImageChanged)
         .def("setROI", (void(ofxCvGrayscaleImage::*)(int,int,int,int)) &ofxCvGrayscaleImage::setROI)
         .def("setROI", (void(ofxCvGrayscaleImage::*)(const ofRectangle&)) &ofxCvGrayscaleImage::setROI)
         .def("getROI", (ofRectangle(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::getROI)
         .def("resetROI", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::resetROI)
         .def("getIntersectionROI", (ofRectangle(ofxCvGrayscaleImage::*)(const ofRectangle&,const ofRectangle&)) &ofxCvGrayscaleImage::getIntersectionROI)
         .def("setFromPixels", (void(ofxCvGrayscaleImage::*)(const ofPixels&)) &ofxCvGrayscaleImage::setFromPixels)
         .def("setRoiFromPixels", (void(ofxCvGrayscaleImage::*)(const ofPixels&)) &ofxCvGrayscaleImage::setRoiFromPixels)
         .def("updateTexture", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::updateTexture)
         .def("draw", (void(ofxCvGrayscaleImage::*)(float,float)) &ofxCvGrayscaleImage::draw)
         .def("draw", (void(ofxCvGrayscaleImage::*)(float,float,float,float)) &ofxCvGrayscaleImage::draw)
         .def("draw", (void(ofxCvGrayscaleImage::*)(const ofRectangle&)) &ofxCvGrayscaleImage::draw)
         .def("drawROI", (void(ofxCvGrayscaleImage::*)(float,float)) &ofxCvGrayscaleImage::drawROI)
         .def("drawROI", (void(ofxCvGrayscaleImage::*)(float,float,float,float)) &ofxCvGrayscaleImage::drawROI)
         .def("setAnchorPercent", (void(ofxCvGrayscaleImage::*)(float,float)) &ofxCvGrayscaleImage::setAnchorPercent)
         .def("setAnchorPoint", (void(ofxCvGrayscaleImage::*)(float,float)) &ofxCvGrayscaleImage::setAnchorPoint)
         .def("resetAnchor", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::resetAnchor)
         .def("erode", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::erode)
         .def("dilate", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::dilate)
         .def("blur", (void(ofxCvGrayscaleImage::*)(int)) &ofxCvGrayscaleImage::blur)
         .def("blurGaussian", (void(ofxCvGrayscaleImage::*)(int)) &ofxCvGrayscaleImage::blurGaussian)
         .def("invert", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::invert)
         .def("mirror", (void(ofxCvGrayscaleImage::*)(bool,bool)) &ofxCvGrayscaleImage::mirror)
         .def("translate", (void(ofxCvGrayscaleImage::*)(float,float)) &ofxCvGrayscaleImage::translate)
         .def("rotate", (void(ofxCvGrayscaleImage::*)(float,float,float)) &ofxCvGrayscaleImage::rotate)
         .def("scale", (void(ofxCvGrayscaleImage::*)(float,float)) &ofxCvGrayscaleImage::scale)
         .def("transform", (void(ofxCvGrayscaleImage::*)(float,float,float,float,float,float,float)) &ofxCvGrayscaleImage::transform)
         .def("undistort", (void(ofxCvGrayscaleImage::*)(float,float,float,float,float,float,float,float)) &ofxCvGrayscaleImage::undistort)
         .def("warpPerspective", (void(ofxCvGrayscaleImage::*)(const ofPoint&,const ofPoint&,const ofPoint&,const ofPoint&)) &ofxCvGrayscaleImage::warpPerspective)
         .def("warpIntoMe", (void(ofxCvGrayscaleImage::*)(ofxCvImage&,const ofPoint,const ofPoint)) &ofxCvGrayscaleImage::warpIntoMe)
         .def("countNonZeroInRegion", (void(ofxCvGrayscaleImage::*)(int,int,int,int)) &ofxCvGrayscaleImage::countNonZeroInRegion)
         
         .def("set", (void(ofxCvGrayscaleImage::*)(float)) &ofxCvGrayscaleImage::set)
         .def("setFromCvColorImage", (void(ofxCvGrayscaleImage::*)(ofxCvColorImage&)) &ofxCvGrayscaleImage::setFromCvColorImage)
         .def("absDiff", (void(ofxCvGrayscaleImage::*)(ofxCvGrayscaleImage&)) &ofxCvGrayscaleImage::absDiff)
         .def("absDiff", (void(ofxCvGrayscaleImage::*)(ofxCvGrayscaleImage&,ofxCvGrayscaleImage&)) &ofxCvGrayscaleImage::absDiff)
         .def("contrastStretch", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::contrastStretch)
         .def("convertToRange", (void(ofxCvGrayscaleImage::*)(float,float)) &ofxCvGrayscaleImage::convertToRange)
         .def("threshold", (void(ofxCvGrayscaleImage::*)(int,bool)) &ofxCvGrayscaleImage::threshold)
         .def("adaptiveThreshold", (void(ofxCvGrayscaleImage::*)(int,int,bool,bool)) &ofxCvGrayscaleImage::adaptiveThreshold)
         .def("brightnessContrast", (void(ofxCvGrayscaleImage::*)(float,float)) &ofxCvGrayscaleImage::brightnessContrast)
         .def("resize", (void(ofxCvGrayscaleImage::*)(int,int)) &ofxCvGrayscaleImage::resize)
         .def("scaleIntoMe", &scaleIntoMeGray)
         .def("blurHeavily", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::blurHeavily)
         .def("erode_3x3", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::erode_3x3)
         .def("dilate_3x3", (void(ofxCvGrayscaleImage::*)(void)) &ofxCvGrayscaleImage::dilate_3x3)
         .def("setFromColorImage", (void(ofxCvGrayscaleImage::*)(ofxCvFloatImage&)) &ofxCvGrayscaleImage::setFromColorImage)
         .def_readonly("width", &ofxCvGrayscaleImage::width)
		 .def_readonly("height", &ofxCvGrayscaleImage::height)
         .def_readonly("bAllocated", &ofxCvGrayscaleImage::bAllocated),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXARCTEXT --> extending ofTrueTypeFont
         class_<ofxArcText>("arcText")
         .def(constructor<>())
         .def(constructor<bool>())
         
         .def("loadFont", &loadArcFont2)
		 .def("loadFont", &loadArcFont4)
         .def("stringWidth", (float(ofTrueTypeFont::*)(string)) &ofTrueTypeFont::stringWidth)
		 .def("stringHeight", (float(ofTrueTypeFont::*)(string)) &ofTrueTypeFont::stringHeight)
         .def("getStringBoundingBox", (ofRectangle(ofTrueTypeFont::*)(string,float,float)) &ofTrueTypeFont::getStringBoundingBox)
         .def("getSize", (int(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getSize)
		 .def("getLetterSpacing", (float(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getLetterSpacing)
		 .def("setLetterSpacing", (void(ofTrueTypeFont::*)(float)) &ofTrueTypeFont::setLetterSpacing)
		 .def("getSpaceSize", (float(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getSpaceSize)
		 .def("setSpaceSize", (void(ofTrueTypeFont::*)(float)) &ofTrueTypeFont::setSpaceSize)
		 .def("getNumCharacters", (int(ofTrueTypeFont::*)(void)) &ofTrueTypeFont::getNumCharacters)
		 .def("getStringAsPoints", (ofTTFCharacter(ofTrueTypeFont::*)(string)) &ofTrueTypeFont::getStringAsPoints)
         
         .def("drawString", (void(ofxArcText::*)(string,float,float,float)) &ofxArcText::drawString)
         .def("getCharacterWidth", (float(ofxArcText::*)(char)) &ofxArcText::getCharacterWidth),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXBOX2D
         class_<ofxBox2d>("box2d")
         .def(constructor<>())
         .def("init", (void(ofxBox2d::*)(void)) &ofxBox2d::init)
         .def("setFPS", (void(ofxBox2d::*)(float)) &ofxBox2d::setFPS)
         
         .def("mousePressed", (void(ofxBox2d::*)(ofMouseEventArgs&)) &ofxBox2d::mousePressed)
         .def("mouseDragged", (void(ofxBox2d::*)(ofMouseEventArgs&)) &ofxBox2d::mouseDragged)
         .def("mouseReleased", (void(ofxBox2d::*)(ofMouseEventArgs&)) &ofxBox2d::mouseReleased)
         
         .def("registerGrabbing", (void(ofxBox2d::*)(void)) &ofxBox2d::registerGrabbing)
         .def("grabShapeDown", (void(ofxBox2d::*)(float,float)) &ofxBox2d::grabShapeDown)
         .def("grabShapeUp", (void(ofxBox2d::*)(float,float)) &ofxBox2d::grabShapeUp)
         .def("grabShapeDragged", (void(ofxBox2d::*)(float,float)) &ofxBox2d::grabShapeDragged)
         .def("getWorld", (b2World*(ofxBox2d::*)(void)) &ofxBox2d::getWorld)
         .def("getBodyCount", (int(ofxBox2d::*)(void)) &ofxBox2d::getBodyCount)
         .def("getJointCount", (int(ofxBox2d::*)(void)) &ofxBox2d::getJointCount)
         .def("enableGrabbing", (void(ofxBox2d::*)(void)) &ofxBox2d::enableGrabbing)
         .def("disableGrabbing", (void(ofxBox2d::*)(void)) &ofxBox2d::disableGrabbing)
         .def("setContactListener", (void(ofxBox2d::*)(ofxBox2dContactListener*)) &ofxBox2d::setContactListener)
         .def("setIterations", (void(ofxBox2d::*)(int,int)) &ofxBox2d::setIterations)
         .def("setGravity", (void(ofxBox2d::*)(float,float)) &ofxBox2d::setGravity)
         .def("setGravity", (void(ofxBox2d::*)(ofPoint)) &ofxBox2d::setGravity)
         .def("setBounds", (void(ofxBox2d::*)(ofPoint,ofPoint)) &ofxBox2d::setBounds)
         .def("createBounds", (void(ofxBox2d::*)(float,float,float,float)) &ofxBox2d::createBounds)
         .def("createBounds", (void(ofxBox2d::*)(ofRectangle&)) &ofxBox2d::createBounds)
         .def("createGround", (void(ofxBox2d::*)(const ofPoint&,const ofPoint&)) &ofxBox2d::createGround)
         .def("createGround", (void(ofxBox2d::*)(float,float,float,float)) &ofxBox2d::createGround)
         .def("checkBounds", (void(ofxBox2d::*)(bool)) &ofxBox2d::checkBounds)
         
         .def("update", (void(ofxBox2d::*)(void)) &ofxBox2d::update)
         .def("draw", (void(ofxBox2d::*)(void)) &ofxBox2d::draw)
         .def("drawGround", (void(ofxBox2d::*)(void)) &ofxBox2d::drawGround),
         
         class_<ofxBox2dCircle>("box2dCircle")
         .def(constructor<>())
         
         // from ofxBox2dBaseShape
         .def("isBody", (bool(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::isBody)
         .def("isFixed", (bool(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::isFixed)
         .def("getWorld", (b2World*(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::getWorld)
         .def("create", (void(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::create)
         .def("setBounce", (void(ofxBox2dCircle::*)(float)) &ofxBox2dCircle::setBounce)
         .def("setDensity", (void(ofxBox2dCircle::*)(float)) &ofxBox2dCircle::setDensity)
         .def("setFriction", (void(ofxBox2dCircle::*)(float)) &ofxBox2dCircle::setFriction)
         .def("setPhysics", (void(ofxBox2dCircle::*)(float,float,float)) &ofxBox2dCircle::setPhysics)
         .def("setData", (void*(ofxBox2dCircle::*)(void*)) &ofxBox2dCircle::setData)
         .def("getData", (void*(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::getData)
         .def("setFilterData", (void(ofxBox2dCircle::*)(b2Filter)) &ofxBox2dCircle::setFilterData)
         .def("enableGravity", (void(ofxBox2dCircle::*)(bool)) &ofxBox2dCircle::enableGravity)
         .def("setFixedRotation", (void(ofxBox2dCircle::*)(bool)) &ofxBox2dCircle::setFixedRotation)
         .def("setRotationFriction", (void(ofxBox2dCircle::*)(float)) &ofxBox2dCircle::setRotationFriction)
         .def("getRotation", (float(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::getRotation)
         .def("getPosition", (ofVec2f(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::getPosition)
         .def("getB2DPosition", (ofVec2f(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::getB2DPosition)
         .def("setVelocity", (void(ofxBox2dCircle::*)(float,float)) &ofxBox2dCircle::setVelocity)
         .def("setVelocity", (void(ofxBox2dCircle::*)(ofVec2f)) &ofxBox2dCircle::setVelocity)
         .def("getVelocity", (ofVec2f(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::getVelocity)
         .def("setDamping", (void(ofxBox2dCircle::*)(float)) &ofxBox2dCircle::setDamping)
         .def("setDamping", (void(ofxBox2dCircle::*)(float,float)) &ofxBox2dCircle::setDamping)
         .def("addForce", (void(ofxBox2dCircle::*)(ofVec2f,float)) &ofxBox2dCircle::addForce)
         .def("addImpulseForce", (void(ofxBox2dCircle::*)(ofVec2f,ofVec2f)) &ofxBox2dCircle::addImpulseForce)
         .def("destroy", (void(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::destroy)
         .def("update", (void(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::update)
         
         .def("setup", (void(ofxBox2dCircle::*)(b2World*,float,float,float)) &ofxBox2dCircle::setup)
         .def("getRadius", (float(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::getRadius)
         .def("setRadius", (void(ofxBox2dCircle::*)(float)) &ofxBox2dCircle::setRadius)
         .def("draw", (void(ofxBox2dCircle::*)(void)) &ofxBox2dCircle::draw)
         .def("addAttractionPoint", (void(ofxBox2dCircle::*)(float,float,float)) &ofxBox2dCircle::addAttractionPoint)
         .def("addAttractionPoint", (void(ofxBox2dCircle::*)(ofVec2f,float)) &ofxBox2dCircle::addAttractionPoint)
         .def("addRepulsionForce", (void(ofxBox2dCircle::*)(float,float,float)) &ofxBox2dCircle::addRepulsionForce)
         .def("addRepulsionForce", (void(ofxBox2dCircle::*)(ofVec2f,float)) &ofxBox2dCircle::addRepulsionForce),
         
         class_<ofxBox2dJoint>("box2dJoint")
         .def(constructor<>())
         .def(constructor<b2World*,b2Body*,b2Body*,float,float,bool>())
         .def(constructor<b2World*,b2Body*,b2Body*,b2Vec2,b2Vec2,float,float,bool>())
         
         .def("setWorld", (void(ofxBox2dJoint::*)(b2World*)) &ofxBox2dJoint::setWorld)
         .def("setup", (void(ofxBox2dJoint::*)(b2World*,b2Body*,b2Body*,float,float,bool)) &ofxBox2dJoint::setup)
         .def("setup", (void(ofxBox2dJoint::*)(b2World*,b2Body*,b2Body*,b2Vec2,b2Vec2,float,float,bool)) &ofxBox2dJoint::setup)
         .def("isSetup", (bool(ofxBox2dJoint::*)(void)) &ofxBox2dJoint::isSetup)
         .def("draw", (void(ofxBox2dJoint::*)(void)) &ofxBox2dJoint::draw)
         .def("destroy", (void(ofxBox2dJoint::*)(void)) &ofxBox2dJoint::destroy)
         .def("setLength", (void(ofxBox2dJoint::*)(float)) &ofxBox2dJoint::setLength)
         .def("getLength", (float(ofxBox2dJoint::*)(void)) &ofxBox2dJoint::getLength)
         .def("setFrequency", (void(ofxBox2dJoint::*)(float)) &ofxBox2dJoint::setFrequency)
         .def("getFrequency", (float(ofxBox2dJoint::*)(void)) &ofxBox2dJoint::getFrequency)
         .def("setDamping", (void(ofxBox2dJoint::*)(float)) &ofxBox2dJoint::setDamping)
         .def("getDamping", (float(ofxBox2dJoint::*)(void)) &ofxBox2dJoint::getDamping)
         .def("getReactionForce", (ofVec2f(ofxBox2dJoint::*)(float)) &ofxBox2dJoint::getReactionForce)
         .def("getReactionForceB2D", (b2Vec2(ofxBox2dJoint::*)(float)) &ofxBox2dJoint::getReactionForceB2D)
         .def("getReactionTorque", (float(ofxBox2dJoint::*)(float)) &ofxBox2dJoint::getReactionTorque),
         
         class_<ofxBox2dPolygon>("box2dPolygon")
         .def(constructor<>())
         
         // from ofPolyline
         .def("clear", (void(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::clear)
         .def("addVertex", (void(ofxBox2dPolygon::*)(float,float,float)) &ofxBox2dPolygon::addVertex)
         .def("lineTo", (void(ofxBox2dPolygon::*)(const ofPoint&)) &ofxBox2dPolygon::lineTo)
         .def("lineTo", (void(ofxBox2dPolygon::*)(float,float,float)) &ofxBox2dPolygon::lineTo)
         .def("arc", (void(ofxBox2dPolygon::*)(const ofPoint&,float,float,float,float,int)) &ofxBox2dPolygon::arc)
         .def("arc", (void(ofxBox2dPolygon::*)(float,float,float,float,float,float,int)) &ofxBox2dPolygon::arc)
         .def("arc", (void(ofxBox2dPolygon::*)(float,float,float,float,float,float,float,int)) &ofxBox2dPolygon::arc)
         .def("curveTo", (void(ofxBox2dPolygon::*)(const ofPoint&,int)) &ofxBox2dPolygon::curveTo)
         .def("curveTo", (void(ofxBox2dPolygon::*)(float,float,float,int)) &ofxBox2dPolygon::curveTo)
         .def("bezierTo", (void(ofxBox2dPolygon::*)(const ofPoint&,const ofPoint&,const ofPoint&,int)) &ofxBox2dPolygon::bezierTo)
         .def("bezierTo", (void(ofxBox2dPolygon::*)(float,float,float,float,float,float,int)) &ofxBox2dPolygon::bezierTo)
         .def("bezierTo", (void(ofxBox2dPolygon::*)(float,float,float,float,float,float,float,float,float,int)) &ofxBox2dPolygon::bezierTo)
         .def("quadBezierTo", (void(ofxBox2dPolygon::*)(const ofPoint&,const ofPoint&,const ofPoint&,int)) &ofxBox2dPolygon::quadBezierTo)
         .def("quadBezierTo", (void(ofxBox2dPolygon::*)(float,float,float,float,float,float,int)) &ofxBox2dPolygon::quadBezierTo)
         .def("quadBezierTo", (void(ofxBox2dPolygon::*)(float,float,float,float,float,float,float,float,float,int)) &ofxBox2dPolygon::quadBezierTo)
         .def("getSmoothed", (ofxBox2dPolygon(ofxBox2dPolygon::*)(int,float)) &ofxBox2dPolygon::getSmoothed)
         .def("getResampledBySpacing", (ofxBox2dPolygon(ofxBox2dPolygon::*)(float)) &ofxBox2dPolygon::getResampledBySpacing)
         .def("getResampledByCount", (ofxBox2dPolygon(ofxBox2dPolygon::*)(int)) &ofxBox2dPolygon::getResampledByCount)
         .def("getBoundingBox", (ofRectangle(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getBoundingBox)
         .def("getClosestPoint", (ofPoint(ofxBox2dPolygon::*)(const ofPoint&,unsigned int*)) &ofxBox2dPolygon::getClosestPoint)
         .def("simplify", (void(ofxBox2dPolygon::*)(float)) &ofxBox2dPolygon::simplify)
         .def("size", (size_t(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::size)
         .def("resize", (void(ofxBox2dPolygon::*)(size_t)) &ofxBox2dPolygon::resize)
         .def("setClosed", (void(ofxBox2dPolygon::*)(bool)) &ofxBox2dPolygon::setClosed)
         .def("isClosed", (bool(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::isClosed)
         .def("close", (void(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::close)
         .def("hasChanged", (bool(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::hasChanged)
         .def("getVertices", (ofPoint(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getVertices)
         .def("getPerimeter", (float(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getPerimeter)
         
         // from ofxBox2dBaseShape
         .def("isBody", (bool(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::isBody)
         .def("isFixed", (bool(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::isFixed)
         .def("getWorld", (b2World*(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getWorld)
         .def("create", (void(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::create)
         .def("setBounce", (void(ofxBox2dPolygon::*)(float)) &ofxBox2dPolygon::setBounce)
         .def("setDensity", (void(ofxBox2dPolygon::*)(float)) &ofxBox2dPolygon::setDensity)
         .def("setFriction", (void(ofxBox2dPolygon::*)(float)) &ofxBox2dPolygon::setFriction)
         .def("setPhysics", (void(ofxBox2dPolygon::*)(float,float,float)) &ofxBox2dPolygon::setPhysics)
         .def("setData", (void*(ofxBox2dPolygon::*)(void*)) &ofxBox2dPolygon::setData)
         .def("getData", (void*(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getData)
         .def("setFilterData", (void(ofxBox2dPolygon::*)(b2Filter)) &ofxBox2dPolygon::setFilterData)
         .def("enableGravity", (void(ofxBox2dPolygon::*)(bool)) &ofxBox2dPolygon::enableGravity)
         .def("setFixedRotation", (void(ofxBox2dPolygon::*)(bool)) &ofxBox2dPolygon::setFixedRotation)
         .def("setRotationFriction", (void(ofxBox2dPolygon::*)(float)) &ofxBox2dPolygon::setRotationFriction)
         .def("getRotation", (float(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getRotation)
         .def("getPosition", (ofVec2f(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getPosition)
         .def("getB2DPosition", (ofVec2f(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getB2DPosition)
         .def("setVelocity", (void(ofxBox2dPolygon::*)(float,float)) &ofxBox2dPolygon::setVelocity)
         .def("setVelocity", (void(ofxBox2dPolygon::*)(ofVec2f)) &ofxBox2dPolygon::setVelocity)
         .def("getVelocity", (ofVec2f(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getVelocity)
         .def("setDamping", (void(ofxBox2dPolygon::*)(float)) &ofxBox2dPolygon::setDamping)
         .def("setDamping", (void(ofxBox2dPolygon::*)(float,float)) &ofxBox2dPolygon::setDamping)
         .def("addForce", (void(ofxBox2dPolygon::*)(ofVec2f,float)) &ofxBox2dPolygon::addForce)
         .def("addImpulseForce", (void(ofxBox2dPolygon::*)(ofVec2f,ofVec2f)) &ofxBox2dPolygon::addImpulseForce)
         .def("destroy", (void(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::destroy)
         .def("update", (void(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::update)
         
         .def("setup", (void(ofxBox2dPolygon::*)(b2World*)) &ofxBox2dPolygon::setup)
         .def("addTriangle", (void(ofxBox2dPolygon::*)(const ofVec2f&,const ofVec2f&,const ofVec2f&)) &ofxBox2dPolygon::addTriangle)
         //.def("addVertexes", (void(ofxBox2dPolygon::*)(vector <ofVec2f>&)) &ofxBox2dPolygon::addVertexes)
         .def("addVertexes", (void(ofxBox2dPolygon::*)(ofPolyline&)) &ofxBox2dPolygon::addVertexes)
         .def("simplify", (void(ofxBox2dPolygon::*)(float)) &ofxBox2dPolygon::simplify)
         .def("triangulate", (void(ofxBox2dPolygon::*)(float,int)) &ofxBox2dPolygon::triangulate)
         .def("getCenter", (ofVec2f(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getCenter)
         .def("getArea", (float(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::getArea)
         .def("isGoodShape", (bool(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::isGoodShape)
         .def("setAsEdge", (void(ofxBox2dPolygon::*)(bool)) &ofxBox2dPolygon::setAsEdge)
         .def("addAttractionPoint", (void(ofxBox2dPolygon::*)(ofVec2f,float)) &ofxBox2dPolygon::addAttractionPoint)
         .def("addAttractionPoint", (void(ofxBox2dPolygon::*)(float,float,float)) &ofxBox2dPolygon::addAttractionPoint)
         .def("addRepulsionForce", (void(ofxBox2dPolygon::*)(ofVec2f,float)) &ofxBox2dPolygon::addRepulsionForce)
         .def("addRepulsionForce", (void(ofxBox2dPolygon::*)(float,float,float)) &ofxBox2dPolygon::addRepulsionForce)
         .def("updateShape", (void(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::updateShape)
         .def("create", (void(ofxBox2dPolygon::*)(b2World*)) &ofxBox2dPolygon::create)
         .def("draw", (void(ofxBox2dPolygon::*)(void)) &ofxBox2dPolygon::draw),
         
         class_<ofxBox2dRect>("box2dRect")
         .def(constructor<>())
         
         // from ofxBox2dBaseShape
         .def("isBody", (bool(ofxBox2dRect::*)(void)) &ofxBox2dRect::isBody)
         .def("isFixed", (bool(ofxBox2dRect::*)(void)) &ofxBox2dRect::isFixed)
         .def("getWorld", (b2World*(ofxBox2dRect::*)(void)) &ofxBox2dRect::getWorld)
         .def("create", (void(ofxBox2dRect::*)(void)) &ofxBox2dRect::create)
         .def("setBounce", (void(ofxBox2dRect::*)(float)) &ofxBox2dRect::setBounce)
         .def("setDensity", (void(ofxBox2dRect::*)(float)) &ofxBox2dRect::setDensity)
         .def("setFriction", (void(ofxBox2dRect::*)(float)) &ofxBox2dRect::setFriction)
         .def("setPhysics", (void(ofxBox2dRect::*)(float,float,float)) &ofxBox2dRect::setPhysics)
         .def("setData", (void*(ofxBox2dRect::*)(void*)) &ofxBox2dRect::setData)
         .def("getData", (void*(ofxBox2dRect::*)(void)) &ofxBox2dRect::getData)
         .def("setFilterData", (void(ofxBox2dRect::*)(b2Filter)) &ofxBox2dRect::setFilterData)
         .def("enableGravity", (void(ofxBox2dRect::*)(bool)) &ofxBox2dRect::enableGravity)
         .def("setFixedRotation", (void(ofxBox2dRect::*)(bool)) &ofxBox2dRect::setFixedRotation)
         .def("setRotationFriction", (void(ofxBox2dRect::*)(float)) &ofxBox2dRect::setRotationFriction)
         .def("getRotation", (float(ofxBox2dRect::*)(void)) &ofxBox2dRect::getRotation)
         .def("getPosition", (ofVec2f(ofxBox2dRect::*)(void)) &ofxBox2dRect::getPosition)
         .def("getB2DPosition", (ofVec2f(ofxBox2dRect::*)(void)) &ofxBox2dRect::getB2DPosition)
         .def("setVelocity", (void(ofxBox2dRect::*)(float,float)) &ofxBox2dRect::setVelocity)
         .def("setVelocity", (void(ofxBox2dRect::*)(ofVec2f)) &ofxBox2dRect::setVelocity)
         .def("getVelocity", (ofVec2f(ofxBox2dRect::*)(void)) &ofxBox2dRect::getVelocity)
         .def("setDamping", (void(ofxBox2dRect::*)(float)) &ofxBox2dRect::setDamping)
         .def("setDamping", (void(ofxBox2dRect::*)(float,float)) &ofxBox2dRect::setDamping)
         .def("addForce", (void(ofxBox2dRect::*)(ofVec2f,float)) &ofxBox2dRect::addForce)
         .def("addImpulseForce", (void(ofxBox2dRect::*)(ofVec2f,ofVec2f)) &ofxBox2dRect::addImpulseForce)
         .def("destroy", (void(ofxBox2dRect::*)(void)) &ofxBox2dRect::destroy)
         .def("update", (void(ofxBox2dRect::*)(void)) &ofxBox2dRect::update)
         
         .def("setup", (void(ofxBox2dRect::*)(b2World*,ofRectangle)) &ofxBox2dRect::setup)
         .def("setup", (void(ofxBox2dRect::*)(b2World*,float,float,float,float)) &ofxBox2dRect::setup)
         .def("draw", (void(ofxBox2dRect::*)(void)) &ofxBox2dRect::draw)
         .def("getWidth", (float(ofxBox2dRect::*)(void)) &ofxBox2dRect::getWidth)
         .def("getHeight", (float(ofxBox2dRect::*)(void)) &ofxBox2dRect::getHeight)
         .def("addAttractionPoint", (void(ofxBox2dRect::*)(float,float,float)) &ofxBox2dRect::addAttractionPoint)
         .def("addAttractionPoint", (void(ofxBox2dRect::*)(ofVec2f,float)) &ofxBox2dRect::addAttractionPoint)
         .def("addRepulsionForce", (void(ofxBox2dRect::*)(float,float,float)) &ofxBox2dRect::addRepulsionForce)
         .def("addRepulsionForce", (void(ofxBox2dRect::*)(ofVec2f,float)) &ofxBox2dRect::addRepulsionForce),
         
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXCHROMAKEY --> extending ofImage
         class_<ofxChromaKey>("chromaKey")
         .def(constructor<>())
         .def("setPixels", (void(ofxChromaKey::*)(ofPixelsRef)) &ofxChromaKey::setPixels)
         .def("setPixels", (void(ofxChromaKey::*)(unsigned char*,int,int)) &ofxChromaKey::setPixels)
         .def("learnBgColor", (void(ofxChromaKey::*)(ofPixelsRef)) &ofxChromaKey::learnBgColor)
         .def("setBgColor", (void(ofxChromaKey::*)(ofColor)) &ofxChromaKey::setBgColor)
         .def("getBgColor", (ofColor(ofxChromaKey::*)(void)) &ofxChromaKey::getBgColor)
         .def("setThreshold", (void(ofxChromaKey::*)(float)) &ofxChromaKey::setThreshold)
         .def("drawBgColor", (void(ofxChromaKey::*)(int,int,int,int)) &ofxChromaKey::drawBgColor)
         .def("draw", (void(ofxChromaKey::*)(int,int,int,int,bool)) &ofxChromaKey::draw)
         .def("getThreshold", (float(ofxChromaKey::*)(void)) &ofxChromaKey::getThreshold),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXDITHER
         class_<ofxDither>("dither")
         .def(constructor<>())
         .def("ordered", &ditherOrdered)
         .def("floyd_steinberg", (void(ofxDither::*)(ofImage&,ofImage&)) &ofxDither::dither_floyd_steinberg)
         .def("atkinson", (void(ofxDither::*)(ofImage&,ofImage&)) &ofxDither::dither_atkinson),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXDMX
         class_<ofxDmx>("dmx")
         .def(constructor<>())
         .def("connect", (bool(ofxDmx::*)(int,unsigned int)) &ofxDmx::connect)
         .def("connect", (bool(ofxDmx::*)(string,unsigned int)) &ofxDmx::connect)
         .def("disconnect", (void(ofxDmx::*)(void)) &ofxDmx::disconnect)
         .def("setLevel", (bool(ofxDmx::*)(unsigned int,unsigned char)) &ofxDmx::setLevel)
         .def("clear", (void(ofxDmx::*)(void)) &ofxDmx::clear)
         .def("getLevel", (unsigned char(ofxDmx::*)(unsigned int)) &ofxDmx::getLevel)
         .def("update", (void(ofxDmx::*)(bool)) &ofxDmx::update)
         .def("setChannels", (void(ofxDmx::*)(unsigned int)) &ofxDmx::setChannels)
         .def("isConnected", (bool(ofxDmx::*)(void)) &ofxDmx::isConnected),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXFTGLFONT
         class_<ofxFTGLFont>("FTGLFont")
         .def(constructor<>())
         .def("loadFont", &loadFont2FTGL)
         .def("loadFont", &loadFont4FTGL)
         .def("setSize", (void(ofxFTGLFont::*)(int)) &ofxFTGLFont::setSize)
         .def("setLineHeight", (void(ofxFTGLFont::*)(float)) &ofxFTGLFont::setLineHeight)
         .def("getStringBoundingBox", (ofRectangle(ofxFTGLFont::*)(string,float,float)) &ofxFTGLFont::getStringBoundingBox)
         .def("drawString", (void(ofxFTGLFont::*)(string,float,float)) &ofxFTGLFont::drawString),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXFX
         
         class_<ofxBloom>("bloom")
         .def(constructor<>())
         .def("allocate", (void(ofxBloom::*)(int,int)) &ofxBloom::allocate)
         .def("getTextureReference", (ofTexture&(ofxBloom::*)(void)) &ofxBloom::getTextureReference)
         .def("beginFx", (void(ofxBloom::*)(void)) &ofxBloom::begin)
         .def("endFx", (void(ofxBloom::*)(bool)) &ofxBloom::end)
         .def("draw", (void(ofxBloom::*)(int,int)) &ofxBloom::draw),
         
         class_<ofxBlur>("blur")
         .def(constructor<>())
         .def("allocate", (void(ofxBlur::*)(int,int)) &ofxBlur::allocate)
         .def("setPasses", (ofxBlur&(ofxBlur::*)(int)) &ofxBlur::setPasses)
         .def("setRadius", (ofxBlur&(ofxBlur::*)(float)) &ofxBlur::setRadius)
         .def("getTextureReference", (ofTexture&(ofxBlur::*)(void)) &ofxBlur::getTextureReference)
         .def("beginFx", (void(ofxBlur::*)(void)) &ofxBlur::begin)
         .def("endFx", (void(ofxBlur::*)(bool)) &ofxBlur::end)
         .def("draw", (void(ofxBlur::*)(int,int)) &ofxBlur::draw),
         
         class_<ofxBlurFast>("blurFast")
         .def(constructor<>())
         .def("allocate", (void(ofxBlurFast::*)(int,int)) &ofxBlurFast::allocate)
         .def("setPasses", (ofxBlurFast&(ofxBlurFast::*)(int)) &ofxBlurFast::setPasses)
         .def("setFade", (ofxBlurFast&(ofxBlurFast::*)(float)) &ofxBlurFast::setFade)
         .def("getTextureReference", (ofTexture&(ofxBlurFast::*)(void)) &ofxBlurFast::getTextureReference)
         .def("beginFx", (void(ofxBlurFast::*)(void)) &ofxBlurFast::begin)
         .def("endFx", (void(ofxBlurFast::*)(bool)) &ofxBlurFast::end)
         .def("draw", (void(ofxBlurFast::*)(int,int)) &ofxBlurFast::draw),
         
         class_<ofxConway>("conway")
         .def(constructor<>())
         .def("allocate", (void(ofxConway::*)(int,int)) &ofxConway::allocate)
         .def("getTextureReference", (ofTexture&(ofxConway::*)(void)) &ofxConway::getTextureReference)
         .def("beginFx", (void(ofxConway::*)(void)) &ofxConway::begin)
         .def("endFx", (void(ofxConway::*)(bool)) &ofxConway::end)
         .def("update", (void(ofxConway::*)(void)) &ofxConway::update)
         .def("draw", (void(ofxConway::*)(int,int)) &ofxConway::draw),
         
         class_<ofxFlocking>("flocking")
         .def(constructor<>())
         .def("allocate", (void(ofxFlocking::*)(int,int,int)) &ofxFlocking::allocate)
         .def("setParticleSize", (ofxFlocking&(ofxFlocking::*)(float)) &ofxFlocking::setParticleSize)
         .def("setTimpeStep", (ofxFlocking&(ofxFlocking::*)(float)) &ofxFlocking::setTimpeStep)
         .def("getTextureReference", (ofTexture&(ofxFlocking::*)(void)) &ofxFlocking::getTextureReference)
         .def("beginFx", (void(ofxFlocking::*)(void)) &ofxFlocking::begin)
         .def("endFx", (void(ofxFlocking::*)(void)) &ofxFlocking::end)
         .def("update", (void(ofxFlocking::*)(void)) &ofxFlocking::update)
         .def("draw", (void(ofxFlocking::*)(int,int)) &ofxFlocking::draw),
         
         class_<ofxFluid>("fluid")
         .def(constructor<>())
         .def("allocate", (void(ofxFluid::*)(int,int,float)) &ofxFluid::allocate)
         .def("setDensity", (ofxFluid&(ofxFluid::*)(ofTexture&)) &ofxFluid::setDensity)
         .def("setVelocity", (ofxFluid&(ofxFluid::*)(ofTexture&)) &ofxFluid::setVelocity)
         .def("setTemperature", (ofxFluid&(ofxFluid::*)(ofTexture&)) &ofxFluid::setTemperature)
         .def("setGravity", (ofxFluid&(ofxFluid::*)(ofVec2f)) &ofxFluid::setGravity)
         .def("setDensityDissipation", (ofxFluid&(ofxFluid::*)(float)) &ofxFluid::setDensityDissipation)
         .def("setVelocityDissipation", (ofxFluid&(ofxFluid::*)(float)) &ofxFluid::setVelocityDissipation)
         .def("setTemperatureDissipation", (ofxFluid&(ofxFluid::*)(float)) &ofxFluid::setTemperatureDissipation)
         .def("addTemporalForce", &addTemporalForce)
         .def("addConstantForce", &addConstantForce)
         .def("beginFx", (void(ofxFluid::*)(void)) &ofxFluid::begin)
         .def("endFx", (void(ofxFluid::*)(void)) &ofxFluid::end)
         .def("update", (void(ofxFluid::*)(void)) &ofxFluid::update)
         .def("draw", (void(ofxFluid::*)(int,int)) &ofxFluid::draw),
         
         class_<ofxGlow>("glow")
         .def(constructor<>())
         .def("allocate", (void(ofxGlow::*)(int,int)) &ofxGlow::allocate)
         .def("setPasses", (ofxGlow&(ofxGlow::*)(int)) &ofxGlow::setPasses)
         .def("setRadius", (ofxGlow&(ofxGlow::*)(float)) &ofxGlow::setRadius)
         .def("getTextureReference", (ofTexture&(ofxGlow::*)(void)) &ofxGlow::getTextureReference)
         .def("beginFx", (void(ofxGlow::*)(void)) &ofxGlow::begin)
         .def("endFx", (void(ofxGlow::*)(bool)) &ofxGlow::end)
         .def("draw", (void(ofxGlow::*)(int,int)) &ofxGlow::draw),
         
         class_<ofxGrayScott>("grayScott")
         .def(constructor<>())
         .def("allocate", (void(ofxGrayScott::*)(int,int)) &ofxGrayScott::allocate)
         .def("setIterations", (ofxGrayScott&(ofxGrayScott::*)(int)) &ofxGrayScott::setIterations)
         .def("setDiffU", (ofxGrayScott&(ofxGrayScott::*)(float)) &ofxGrayScott::setDiffU)
         .def("setDiffV", (ofxGrayScott&(ofxGrayScott::*)(float)) &ofxGrayScott::setDiffV)
         .def("setK", (ofxGrayScott&(ofxGrayScott::*)(float)) &ofxGrayScott::setK)
         .def("setF", (ofxGrayScott&(ofxGrayScott::*)(float)) &ofxGrayScott::setF)
         .def("getTextureReference", (ofTexture&(ofxGrayScott::*)(void)) &ofxGrayScott::getTextureReference)
         .def("getDiffU", (float(ofxGrayScott::*)(void)) &ofxGrayScott::getDiffU)
         .def("getDiffV", (float(ofxGrayScott::*)(void)) &ofxGrayScott::getDiffV)
         .def("getK", (float(ofxGrayScott::*)(void)) &ofxGrayScott::getK)
         .def("getF", (float(ofxGrayScott::*)(void)) &ofxGrayScott::getF)
         .def("beginFx", (void(ofxGrayScott::*)(void)) &ofxGrayScott::begin)
         .def("endFx", (void(ofxGrayScott::*)(bool)) &ofxGrayScott::end)
         .def("update", (void(ofxGrayScott::*)(void)) &ofxGrayScott::update)
         .def("draw", (void(ofxGrayScott::*)(int,int)) &ofxGrayScott::draw),
         
         class_<ofxMask>("mask")
         .def(constructor<>())
         .def("allocate", (void(ofxMask::*)(int,int)) &ofxMask::allocate)
         .def("getTextureReference", (ofTexture&(ofxMask::*)(void)) &ofxMask::getTextureReference)
         .def("beginMask", (void(ofxMask::*)(void)) &ofxMask::beginMask)
         .def("endMask", (void(ofxMask::*)(void)) &ofxMask::endMask)
         .def("beginFx", (void(ofxMask::*)(void)) &ofxMask::begin)
         .def("endFx", (void(ofxMask::*)(bool)) &ofxMask::end)
         .def("draw", (void(ofxMask::*)(int,int)) &ofxMask::draw),
         
         class_<ofxOldTv>("oldTv")
         .def(constructor<>())
         .def("allocate", (void(ofxOldTv::*)(int,int)) &ofxOldTv::allocate)
         .def("setBrightness", (ofxOldTv&(ofxOldTv::*)(float)) &ofxOldTv::setBrightness)
         .def("setRows", (ofxOldTv&(ofxOldTv::*)(float)) &ofxOldTv::setRows)
         .def("getTextureReference", (ofTexture&(ofxOldTv::*)(void)) &ofxOldTv::getTextureReference)
         .def("beginFx", (void(ofxOldTv::*)(void)) &ofxOldTv::begin)
         .def("endFx", (void(ofxOldTv::*)(bool)) &ofxOldTv::end)
         .def("draw", (void(ofxOldTv::*)(int,int)) &ofxOldTv::draw),
         
         class_<ofxWater>("water")
         .def(constructor<>())
         .def("allocate", (ofxWater&(ofxWater::*)(int,int)) &ofxWater::allocate)
         .def("loadBackground", (ofxWater&(ofxWater::*)(string)) &ofxWater::loadBackground)
         .def("linkBackground", (ofxWater&(ofxWater::*)(ofTexture*)) &ofxWater::linkBackground)
         .def("setThreshold", (ofxWater&(ofxWater::*)(float)) &ofxWater::setThreshold)
         .def("setDensity", (ofxWater&(ofxWater::*)(float)) &ofxWater::setDensity)
         .def("setFade", (ofxWater&(ofxWater::*)(float)) &ofxWater::setFade)
         .def("getTextureReference", (ofTexture&(ofxWater::*)(void)) &ofxWater::getTextureReference)
         .def("beginFx", (void(ofxWater::*)(void)) &ofxWater::begin)
         .def("endFx", (void(ofxWater::*)(bool)) &ofxWater::end)
         .def("update", (void(ofxWater::*)(void)) &ofxWater::update)
         .def("draw", (void(ofxWater::*)(int,int)) &ofxWater::draw),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXGAUSSIAN
         def("gaussian", (float(*)(void)) &ofxGaussian),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXLOGICMACHINE
         class_<ofxLogicMachine>("logicMachine")
         .def(constructor<>())
         .def("CreateTargetValues", (void(ofxLogicMachine::*)(void)) &ofxLogicMachine::CreateTargetValues)
         .def("setupSimulation", (void(ofxLogicMachine::*)(void)) &ofxLogicMachine::setupSimulation)
         .def("PerformSimulation", (void(ofxLogicMachine::*)(void)) &ofxLogicMachine::PerformSimulation)
         .def("EvaluateSimulation", (void(ofxLogicMachine::*)(void)) &ofxLogicMachine::EvaluateSimulation)
         .def("DrawSimulation", (void(ofxLogicMachine::*)(int,int,int,int)) &ofxLogicMachine::DrawSimulation)
         .def("EvolvePopulation", (void(ofxLogicMachine::*)(void)) &ofxLogicMachine::EvolvePopulation)
         .def_readwrite("mouseX", &ofxLogicMachine::mouseX)
         .def_readwrite("mouseY", &ofxLogicMachine::mouseY)
         .def_readonly("bestCode", &ofxLogicMachine::bestCode)
         .def_readonly("bestFitness", &ofxLogicMachine::bestFitness),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXMISSING
         def("getDateTimeAsString", (string(*)(string)) &getDateTimeAsString),
         def("MD5", (string(*)(string)) &md5),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXSKYBOX
         class_<ofxSkyBox>("skyBox")
         .def(constructor<>())
         .def("load", (void(ofxSkyBox::*)(void)) &ofxSkyBox::load)
         .def("draw", (void(ofxSkyBox::*)(void)) &ofxSkyBox::draw),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXSUBTITLES
         class_<ofxSubtitles>("subtitles")
         .def(constructor<>())
         .def("load", (void(ofxSubtitles::*)(const string&)) &ofxSubtitles::load)
         .def("save", (void(ofxSubtitles::*)(const string&)) &ofxSubtitles::save)
         .def("add", (void(ofxSubtitles::*)(float,string)) &ofxSubtitles::add)
         .def("add", (void(ofxSubtitles::*)(float,float,string)) &ofxSubtitles::add)
         .def("getHowMany", (int(ofxSubtitles::*)(float,float)) &ofxSubtitles::getHowMany)
         .def("getFirstSubN", (int(ofxSubtitles::*)(float)) &ofxSubtitles::getFirstSubN)
         .def("getLineAt", (string(ofxSubtitles::*)(float)) &ofxSubtitles::getLineAt)
         .def("isStringAt", (bool(ofxSubtitles::*)(string,float)) &ofxSubtitles::isStringAt)
         .def("replace", (void(ofxSubtitles::*)(string,string,float)) &ofxSubtitles::replace)
         .def("loadfont", (void(ofxSubtitles::*)(const string&)) &ofxSubtitles::loadfont)
         .def("setScreen", (void(ofxSubtitles::*)(int,int)) &ofxSubtitles::setScreen)
         .def("setColor", (void(ofxSubtitles::*)(int,int,int)) &ofxSubtitles::setColor)
         .def("setColor", (void(ofxSubtitles::*)(int,int,int,int)) &ofxSubtitles::setColor)
         .def("draw", (void(ofxSubtitles::*)(float)) &ofxSubtitles::draw)
         .def("draw", (void(ofxSubtitles::*)(int,int,float)) &ofxSubtitles::draw)
         .def("draw", (void(ofxSubtitles::*)(int,int,int,int,float)) &ofxSubtitles::draw),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXTWITTERSTREAM
         class_<ofxTwitter>("twitter")
         .def(constructor<>())
         .def("connect", (void(ofxTwitter::*)(string,string,string,string)) &ofxTwitter::connect)
         .def("hasNewTweets", (bool(ofxTwitter::*)(void)) &ofxTwitter::hasNewTweets)
         .def("getNextTweet", (ofxTweet(ofxTwitter::*)(void)) &ofxTwitter::getNextTweet),
         
         class_<ofxTweet>("tweet")
         .def(constructor<>())
         .def("getText", (string(ofxTweet::*)(void)) &ofxTweet::getText)
         .def("getID", (string(ofxTweet::*)(void)) &ofxTweet::getID)
         .def("getScreenName", (string(ofxTweet::*)(void)) &ofxTweet::getScreenName)
         .def("getAvatar", (string(ofxTweet::*)(void)) &ofxTweet::getAvatar)
         .def("getUserID", (string(ofxTweet::*)(void)) &ofxTweet::getUserID),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXVORONOIGL
         class_<ofxVoronoiGL>("voronoiGL")
         .def(constructor<>())
         .def(constructor<float,float,float>())
         .def("setup", (void(ofxVoronoiGL::*)(int,int,float)) &ofxVoronoiGL::setup)
         .def("update", (void(ofxVoronoiGL::*)(void)) &ofxVoronoiGL::update)
         .def("drawOnScreen", (void(ofxVoronoiGL::*)(int,int)) &ofxVoronoiGL::drawOnScreen)
         .def("drawFBOOnScreen", (void(ofxVoronoiGL::*)(int,int)) &ofxVoronoiGL::drawFBOOnScreen)
         .def("clear", (void(ofxVoronoiGL::*)(void)) &ofxVoronoiGL::clear)
         .def("setPoint", (void(ofxVoronoiGL::*)(int,int)) &ofxVoronoiGL::setPoint)
         .def("setPoint", (void(ofxVoronoiGL::*)(ofPoint&)) &ofxVoronoiGL::setPoint)
         .def("setPolygon", (void(ofxVoronoiGL::*)(vector<ofPoint>&)) &ofxVoronoiGL::setPolygon)
         .def_readwrite("alpha", &ofxVoronoiGL::alpha)
         .def_readwrite("drawPoly", &ofxVoronoiGL::drawPoly)
         .def_readwrite("perFeatureV", &ofxVoronoiGL::perFeatureV)
         .def_readwrite("skeleton", &ofxVoronoiGL::skeleton)
         .def_readwrite("drawCenters", &ofxVoronoiGL::drawCenters),
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
         ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
         // OFXWORDPALETTE
         class_<WordWithSize>("WordWithSize")
         .def(constructor<>())
         .def_readwrite("word", &WordWithSize::word)
         .def_readwrite("box", &WordWithSize::box),
         
         class_<ofxWordPalette>("wordPalette")
         .def(constructor<>())
         .def("setup", (void(ofxWordPalette::*)(int,int,string,int,float)) &ofxWordPalette::setup)
         .def("setWords", (void(ofxWordPalette::*)(string)) &ofxWordPalette::setWords)
         .def("bindPalette", (void(ofxWordPalette::*)(void)) &ofxWordPalette::bindPalette)
         .def("drawWord", (void(ofxWordPalette::*)(string,ofVec2f,float)) &ofxWordPalette::drawWord)
         .def("drawWordWS", (void(ofxWordPalette::*)(WordWithSize&,ofVec2f,float)) &ofxWordPalette::drawWord)
         .def("unbindPalette", (void(ofxWordPalette::*)(void)) &ofxWordPalette::unbindPalette)
         .def("drawTypePalette", (void(ofxWordPalette::*)(ofVec2f)) &ofxWordPalette::drawTypePalette)
         .def("getBoundingTextureCoordsForWord", (void(ofxWordPalette::*)(string,ofVec2f[4])) &ofxWordPalette::getBoundingTextureCoordsForWord)
         .def("getRandomWord", (WordWithSize&(ofxWordPalette::*)(void)) &ofxWordPalette::getRandomWord)
         .def("getWordMatchingWidth", (WordWithSize&(ofxWordPalette::*)(float)) &ofxWordPalette::getWordMatchingWidth)
         .def("getShortestWord", (WordWithSize&(ofxWordPalette::*)(void)) &ofxWordPalette::getShortestWord)
         .def("getLongestWord", (WordWithSize&(ofxWordPalette::*)(void)) &ofxWordPalette::getLongestWord)
         .def("getTextureReference", (ofTexture&(ofxWordPalette::*)(void)) &ofxWordPalette::getTextureReference)
         .def("setUseTexture", (void(ofxWordPalette::*)(bool)) &ofxWordPalette::setUseTexture)
         //////////////////////////////////////////////////////////////////////////////////////////////////
         
        ];
        
        // addons CONSTANTS
        
		
		//////////////////////////////////////////////////////////////
		///////////////////////////////
		/// gamuza core api wrapper
		module(lua, "ga")
		[
		 
         ///////////////////////////////
		 // app section
         def("key", &getKey), // ga.key()
         def("mouseX", &getMouseX),  // ga.mouseX()
		 def("mouseY", &getMouseY),  // ga.mouseY()
         def("system", &system),
         
         ///////////////////////////////
		 // string section
         def("stringReplace", (int(*)(string&,string,string)) &gaStringReplace),
         
		 ///////////////////////////////
		 // graphics section
		 def("background", (void(*)(float,float)) &gaBackground),
		 def("background", (void(*)(float,float,float,float)) &gaBackground),
		 def("cameraTexture", (ofTexture(*)(int)) &gaGetWebcamTexture),
         def("cameraPixelsRef", (ofPixelsRef(*)(int)) &gaGetWebcamPixelsRef),
         def("saveFrame", (void(*)(string)) &gaSaveFrame),
         
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
		 // audio input
		 def("getVolume", (float(*)(int)) &gaGetVolume),
		 def("getPitch", (float(*)(int)) &gaGetPitch),
		 def("getBin", (float(*)(int,int)) &gaGetFFTBand),
		 def("getFFT", (float(*)(int,int)) &gaGetFFTBin),
		 
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
         def("drawHead", (void(*)(int,int,int,int,int)) &gaDrawSampleHead),
         def("drawSample", (void(*)(int,int,int,int,int)) &gaDrawSampleWave),
         
         ///////////////////////////////
		 // audio input recording section
         def("startRec", (void(*)(int)) &gaStartInputRecording),
         def("stopRec", (void(*)(void)) &gaStopInputRecording),
         def("recSamplePlay", (void(*)(int)) &gaInputRecPlay),
         def("recSampleStop", (void(*)(int)) &gaInputRecStop),
		 def("recSampleVolume", (void(*)(int,float)) &gaSetInputRecVolume),
		 def("recSampleLooping", (void(*)(int,bool)) &gaSetInputRecLooping),
		 def("recSamplePaused", (void(*)(int,bool)) &gaSetInputRecPaused),
         def("recSampleSpeed", (void(*)(int,float)) &gaSetInputRecSpeed),
         def("drawRecHead", (void(*)(int,int,int,int,int)) &gaDrawInputRecHead),
         
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
		 // arduino
         def("serialDevice", (string(*)(void)) &gaGetSerialDevName),
		 def("analogRead", (float(*)(int)) &gaGetAArduinoPin),
		 def("digitalRead", (int(*)(int)) &gaGetDArduinoPin),
		 def("digitalWrite", (void(*)(int,int)) &gaSetDArduinoPin)
		 //////////////////////////////////////////////////////////////// GUI MODULES
		 
		 
		];
		//////////////////////////////////////////////////////////////
		
		///////////////////////////////
		/// \section CONSTANTS
		
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
        
        // OF RECTMODES
        lua.doString("OF_RECTMODE_CENTER = "+ofToString(OF_RECTMODE_CENTER));
        lua.doString("OF_RECTMODE_CORNER = "+ofToString(OF_RECTMODE_CORNER));
        
        // OF loop constants
        lua.doString("OF_LOOP_NONE = "+ofToString(OF_LOOP_NONE));
        lua.doString("OF_LOOP_NORMAL = "+ofToString(OF_LOOP_NORMAL));
        lua.doString("OF_LOOP_PALINDROME = "+ofToString(OF_LOOP_PALINDROME));
        
        // OF pixel formats
        lua.doString("OF_PIXELS_MONO = "+ofToString(OF_PIXELS_MONO));
        lua.doString("OF_PIXELS_RGB = "+ofToString(OF_PIXELS_RGB));
        lua.doString("OF_PIXELS_RGBA = "+ofToString(OF_PIXELS_RGBA));
        lua.doString("OF_PIXELS_BGRA = "+ofToString(OF_PIXELS_BGRA));
        
        // OF image type
        lua.doString("OF_IMAGE_GRAYSCALE = "+ofToString(OF_IMAGE_GRAYSCALE));
        lua.doString("OF_IMAGE_COLOR = "+ofToString(OF_IMAGE_COLOR));
        lua.doString("OF_IMAGE_COLOR_ALPHA = "+ofToString(OF_IMAGE_COLOR_ALPHA));
        lua.doString("OF_IMAGE_UNDEFINED = "+ofToString(OF_IMAGE_UNDEFINED));
        
        // OF image quality type
        lua.doString("OF_IMAGE_QUALITY_BEST = "+ofToString(OF_IMAGE_QUALITY_BEST));
        lua.doString("OF_IMAGE_QUALITY_HIGH = "+ofToString(OF_IMAGE_QUALITY_HIGH));
        lua.doString("OF_IMAGE_QUALITY_MEDIUM = "+ofToString(OF_IMAGE_QUALITY_MEDIUM));
        lua.doString("OF_IMAGE_QUALITY_LOW = "+ofToString(OF_IMAGE_QUALITY_LOW));
        lua.doString("OF_IMAGE_QUALITY_WORST = "+ofToString(OF_IMAGE_QUALITY_WORST));
        
        // OF image format
        lua.doString("OF_IMAGE_FORMAT_BMP = "+ofToString(OF_IMAGE_FORMAT_BMP));
        lua.doString("OF_IMAGE_FORMAT_ICO = "+ofToString(OF_IMAGE_FORMAT_ICO));
        lua.doString("OF_IMAGE_FORMAT_JPEG = "+ofToString(OF_IMAGE_FORMAT_JPEG));
        lua.doString("OF_IMAGE_FORMAT_JNG = "+ofToString(OF_IMAGE_FORMAT_JNG));
        lua.doString("OF_IMAGE_FORMAT_KOALA = "+ofToString(OF_IMAGE_FORMAT_KOALA));
        lua.doString("OF_IMAGE_FORMAT_LBM = "+ofToString(OF_IMAGE_FORMAT_LBM));
        lua.doString("OF_IMAGE_FORMAT_IFF = "+ofToString(OF_IMAGE_FORMAT_IFF));
        lua.doString("OF_IMAGE_FORMAT_MNG = "+ofToString(OF_IMAGE_FORMAT_MNG));
        lua.doString("OF_IMAGE_FORMAT_PBM = "+ofToString(OF_IMAGE_FORMAT_PBM));
        lua.doString("OF_IMAGE_FORMAT_PBMRAW = "+ofToString(OF_IMAGE_FORMAT_PBMRAW));
        lua.doString("OF_IMAGE_FORMAT_PCD = "+ofToString(OF_IMAGE_FORMAT_PCD));
        lua.doString("OF_IMAGE_FORMAT_PCX = "+ofToString(OF_IMAGE_FORMAT_PCX));
        lua.doString("OF_IMAGE_FORMAT_PGM = "+ofToString(OF_IMAGE_FORMAT_PGM));
        lua.doString("OF_IMAGE_FORMAT_PGMRAW = "+ofToString(OF_IMAGE_FORMAT_PGMRAW));
        lua.doString("OF_IMAGE_FORMAT_PNG = "+ofToString(OF_IMAGE_FORMAT_PNG));
        lua.doString("OF_IMAGE_FORMAT_PPM = "+ofToString(OF_IMAGE_FORMAT_PPM));
        lua.doString("OF_IMAGE_FORMAT_PPMRAW = "+ofToString(OF_IMAGE_FORMAT_PPMRAW));
        lua.doString("OF_IMAGE_FORMAT_RAS = "+ofToString(OF_IMAGE_FORMAT_RAS));
        lua.doString("OF_IMAGE_FORMAT_TARGA = "+ofToString(OF_IMAGE_FORMAT_TARGA));
        lua.doString("OF_IMAGE_FORMAT_TIFF = "+ofToString(OF_IMAGE_FORMAT_TIFF));
        lua.doString("OF_IMAGE_FORMAT_WBMP = "+ofToString(OF_IMAGE_FORMAT_WBMP));
        lua.doString("OF_IMAGE_FORMAT_PSD = "+ofToString(OF_IMAGE_FORMAT_PSD));
        lua.doString("OF_IMAGE_FORMAT_CUT = "+ofToString(OF_IMAGE_FORMAT_CUT));
        lua.doString("OF_IMAGE_FORMAT_XBM = "+ofToString(OF_IMAGE_FORMAT_XBM));
        lua.doString("OF_IMAGE_FORMAT_XPM = "+ofToString(OF_IMAGE_FORMAT_XPM));
        lua.doString("OF_IMAGE_FORMAT_DDS = "+ofToString(OF_IMAGE_FORMAT_DDS));
        lua.doString("OF_IMAGE_FORMAT_GIF = "+ofToString(OF_IMAGE_FORMAT_GIF));
        lua.doString("OF_IMAGE_FORMAT_HDR = "+ofToString(OF_IMAGE_FORMAT_HDR));
        lua.doString("OF_IMAGE_FORMAT_FAXG3 = "+ofToString(OF_IMAGE_FORMAT_FAXG3));
        lua.doString("OF_IMAGE_FORMAT_SGI = "+ofToString(OF_IMAGE_FORMAT_SGI));
        lua.doString("OF_IMAGE_FORMAT_EXR = "+ofToString(OF_IMAGE_FORMAT_EXR));
        lua.doString("OF_IMAGE_FORMAT_J2K = "+ofToString(OF_IMAGE_FORMAT_J2K));
        lua.doString("OF_IMAGE_FORMAT_JP2 = "+ofToString(OF_IMAGE_FORMAT_JP2));
        lua.doString("OF_IMAGE_FORMAT_PFM = "+ofToString(OF_IMAGE_FORMAT_PFM));
        lua.doString("OF_IMAGE_FORMAT_PICT = "+ofToString(OF_IMAGE_FORMAT_PICT));
        lua.doString("OF_IMAGE_FORMAT_RAW = "+ofToString(OF_IMAGE_FORMAT_RAW));
        
        // OF polyline winding mode
        lua.doString("OF_POLY_WINDING_ODD = "+ofToString(OF_POLY_WINDING_ODD));
        lua.doString("OF_POLY_WINDING_NONZERO = "+ofToString(OF_POLY_WINDING_NONZERO));
        lua.doString("OF_POLY_WINDING_POSITIVE = "+ofToString(OF_POLY_WINDING_POSITIVE));
        lua.doString("OF_POLY_WINDING_NEGATIVE = "+ofToString(OF_POLY_WINDING_NEGATIVE));
        lua.doString("OF_POLY_WINDING_ABS_GEQ_TWO = "+ofToString(OF_POLY_WINDING_ABS_GEQ_TWO));
        
        // OF primitives
        lua.doString("OF_PRIMITIVE_TRIANGLES = "+ofToString(OF_PRIMITIVE_TRIANGLES));
        lua.doString("OF_PRIMITIVE_TRIANGLE_STRIP = "+ofToString(OF_PRIMITIVE_TRIANGLE_STRIP));
        lua.doString("OF_PRIMITIVE_TRIANGLE_FAN = "+ofToString(OF_PRIMITIVE_TRIANGLE_FAN));
        lua.doString("OF_PRIMITIVE_LINES = "+ofToString(OF_PRIMITIVE_LINES));
        lua.doString("OF_PRIMITIVE_LINE_STRIP = "+ofToString(OF_PRIMITIVE_LINE_STRIP));
        lua.doString("OF_PRIMITIVE_LINE_LOOP = "+ofToString(OF_PRIMITIVE_LINE_LOOP));
        lua.doString("OF_PRIMITIVE_POINTS = "+ofToString(OF_PRIMITIVE_POINTS));
        
        // OF gl legacy
        lua.doString("OF_TRIANGLES_MODE = "+ofToString(OF_TRIANGLES_MODE));
        lua.doString("OF_TRIANGLE_STRIP_MODE = "+ofToString(OF_TRIANGLE_STRIP_MODE));
        lua.doString("OF_TRIANGLE_FAN_MODE = "+ofToString(OF_TRIANGLE_FAN_MODE));
        lua.doString("OF_LINES_MODE = "+ofToString(OF_LINES_MODE));
        lua.doString("OF_LINE_STRIP_MODE = "+ofToString(OF_LINE_STRIP_MODE));
        lua.doString("OF_LINE_LOOP_MODE = "+ofToString(OF_LINE_LOOP_MODE));
        lua.doString("OF_POINTS_MODE = "+ofToString(OF_POINTS_MODE));
        
        // OF mesh modes
        lua.doString("OF_MESH_POINTS = "+ofToString(OF_MESH_POINTS));
        lua.doString("OF_MESH_WIREFRAME = "+ofToString(OF_MESH_WIREFRAME));
        lua.doString("OF_MESH_FILL = "+ofToString(OF_MESH_FILL));
        
        // OF blending modes
        lua.doString("OF_BLENDMODE_DISABLED = "+ofToString(OF_BLENDMODE_DISABLED));
        lua.doString("OF_BLENDMODE_ALPHA = "+ofToString(OF_BLENDMODE_ALPHA));
        lua.doString("OF_BLENDMODE_ADD = "+ofToString(OF_BLENDMODE_ADD));
        lua.doString("OF_BLENDMODE_SUBTRACT = "+ofToString(OF_BLENDMODE_SUBTRACT));
        lua.doString("OF_BLENDMODE_MULTIPLY = "+ofToString(OF_BLENDMODE_MULTIPLY));
        lua.doString("OF_BLENDMODE_SCREEN = "+ofToString(OF_BLENDMODE_SCREEN));
        
        // OF bitmap draw modes
        lua.doString("OF_BITMAPMODE_SIMPLE = "+ofToString(OF_BITMAPMODE_SIMPLE));
        lua.doString("OF_BITMAPMODE_SCREEN = "+ofToString(OF_BITMAPMODE_SCREEN));
        lua.doString("OF_BITMAPMODE_VIEWPORT = "+ofToString(OF_BITMAPMODE_VIEWPORT));
        lua.doString("OF_BITMAPMODE_MODEL = "+ofToString(OF_BITMAPMODE_MODEL));
        lua.doString("OF_BITMAPMODE_MODEL_BILLBOARD = "+ofToString(OF_BITMAPMODE_MODEL_BILLBOARD));
		
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
        lua.doString("BUFFER_SIZE = "+ofToString(gapp->gamuzaBase.audioBufferSize));
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
		
	}
	
	////////////////////////////////////////////////////////
	/// \section Function & Object Wrappers
	
	/// ofGraphics
	static void background(int brightness)                                  {ofBackground(brightness);}
	static void background(int r, int g, int b)                             {ofBackground(r, g, b);}
    static void setColor1(int gray)                                         {ofSetColor(gray,gray,gray);}
    static void setColor2(int gray, int alpha)                              {ofSetColor(gray,gray,gray,alpha);}
    static void map5(float v,float iMin,float iMax,float oMin,float oMax)   {ofMap(v,iMin,iMax,oMin,oMax,false);}
    
    /// ofTrueTypeFont
	static void loadFont2(ofTrueTypeFont* font, string filename, int fontsize) {
		font->loadFont(filename, fontsize);
	}
	static void loadFont4(ofTrueTypeFont* font, string filename, int fontsize, bool _bAntiAliased, bool _bFullCharacterSet) {
		font->loadFont(filename, fontsize, _bAntiAliased, _bFullCharacterSet);
	}
    static void loadFont2FTGL(ofxFTGLFont* font, string filename, int fontsize) {
		font->loadFont(filename, fontsize);
	}
    static void loadFont4FTGL(ofxFTGLFont* font, string filename, int fontsize, bool _bAntiAliased, bool _bFullCharacterSet) {
		font->loadFont(filename, fontsize, _bAntiAliased, _bFullCharacterSet);
	}
    
    /// ofxArcText
	static void loadArcFont2(ofxArcText* font, string filename, int fontsize) {
		font->loadFont(filename, fontsize);
	}
	static void loadArcFont4(ofxArcText* font, string filename, int fontsize, bool _bAntiAliased, bool _bFullCharacterSet) {
		font->loadFont(filename, fontsize, _bAntiAliased, _bFullCharacterSet);
	}
    
    /// ofxDither
    static void ditherOrdered(ofxDither* d, ofImage& imageIn, ofImage& imageOut) {
        d->dither_ordered(imageIn,imageOut);
    }
    
    /// ofFile
    static void openFile(ofFile* file,string path){
        file->open(path);
    }
    
    /// ofxFx --> ofxFluid
    static void addTemporalForce(ofxFluid* fluid, ofVec2f _pos, ofVec2f _dir, ofColor _col, float _rad){
        fluid->addTemporalForce(_pos,_dir,_col,_rad);
    }
    
    static void addConstantForce(ofxFluid* fluid, ofVec2f _pos, ofVec2f _dir, ofColor _col, float _rad){
        fluid->addConstantForce(_pos,_dir,_col,_rad);
    }
    
    /// ofxOpenCv
    static void scaleIntoMeGray(ofxCvGrayscaleImage* src, ofxCvImage& img){
        src->scaleIntoMe(img);
    }
    
    static void scaleIntoMeColor(ofxCvColorImage* src, ofxCvImage& img){
        src->scaleIntoMe(img);
    }
	
	/// global mouse vars
	static float getMouseX() {return (float)gapp->gamuzaBase.scaledMouseX;}
	static float getMouseY() {return (float)gapp->gamuzaBase.scaledMouseY;}
    
    /// global key vars
    static int getKey() {return (int)gapp->gamuzaBase.liveKey;}

};