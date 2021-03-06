#include <iostream>

#include "ofMain.h"
#include "gamuza.h"
#include "gamuzaConstants.h"
#include "ofAppGlutWindow.h"

gamuza * gapp;

//========================================================================
int main( ){

    ofAppGlutWindow window;
    
    // antialiasing hacks
    window.setGlutDisplayString("rgba double samples>=4 depth");
    
	if(START_WITH_FULLSCREEN){
		ofSetupOpenGL(&window,MAIN_WINDOW_W,MAIN_WINDOW_H,OF_FULLSCREEN);
	}else{
		ofSetupOpenGL(&window,MAIN_WINDOW_W,MAIN_WINDOW_H,OF_WINDOW);
	}
	
	ofSetWindowTitle("GAmuza[0.3] | <http://www.gamuza.cc> | <http://www.d3cod3.org>");
	
	gapp = new gamuza();
	
	ofRunApp(gapp);

}
