#ifdef TARGET_LINUX
	//-------------------------

	//-------------------------
#endif

#ifdef TARGET_OSX
	//-------------------------
	#include <mach/mach_time.h>
	//-------------------------
#endif

//////////////////////////////////////
// main core of OpenFrameworks
#include "ofMain.h"

// official addons
#include "ofx3DModelLoader.h"
#include "ofxNetwork.h"
#include "ofxOpenCv.h"				// computer vision library
#include "ofxOsc.h"					// Open Sound Control communication library
#include "ofxVectorGraphics.h"
#include "ofxXmlSettings.h"			// read/write on/to xml file library

//////////////////////////////////////
// experimental addons

// GUI
#include "ofxControlPanel.h"		// graphical user interface library [from Theo Watson]
#include "ofxTimeline.h"            // Lightweight SDK for creating graphic timeline tools

// Multiple Windows handling
//#include "ofxFensterManager.h"

// OpenNI SensorKinect
#include "ofxOpenNI.h"				// Simple wrapper for OpenNI and SensorKinect

// live coding "fluxus" style
#include "ofxKeyMap.h"				// alt,ctrl,shift key detection
#include "ofxGLEditor.h"			// openGL text editor "fluxus" style <http://www.pawfal.org/fluxus/>

// live coding language
#include "ofxLua.h"					// Lua embedded scripting interpreter

// AUDIO
#include "ofxAudioSample.h"			// reading&writing audio sample from hard drive with libsndfile
#include "ofxPd.h"                  // a Pure Data addon for OpenFrameworks  - wrapper for libpd

// Midi input/output
#include "ofxMidi.h"                // MIDI input/output

// DMX input/output
#include "ofxDmx.h"                 // DMX input/output

// Video Exporter
#include "ofxVideoRecorder.h"       // Video recorder
#include "ofxLibsndFileRecorder.h"  // Audio recorder
#include "threadedEncoding.h"       // threaded encoding class for video/audio encoding with ffmpeg

// SYSTEM
#include "ofxMemoryUsage.h"         // System memory info
#include "ofxMissing.h"				// Date/Time, INI Reader, Recursive file listing. Roxlu missing utils
#include "ofxFileDialog.h"			// open/save file dialog
#include "ofxStringEncoders.h"		// Html string encoders (UTF8, unquote)
#include "ofxSubtitles.h"           // load/save .srt subtitles files

// PHYSICS
#include "ofxBullet.h"				// Bullet Physics Engine

// MATH
#include "ofxGaussian.h"            // A Gaussian random number generator

// LOGIC
#include "ofxLogicMachine.h"

// Pixels manipulators
#include "ofxHalftoner.h"           // 80's copy-machine art
#include "ofxChromaKey.h"
#include "ofxDither.h"
#include "ofxFX.h"

// Text Font addons
#include "ofxArcText.h"
#include "ofxFTGLFont.h"
#include "ofxWordPalette.h"

// Graphics
#include "ofxVoronoiGL.h"
#include "ofxSlitScan.h"            // simple utility for creating slit scan effects and video time delays

// NET
#include "ofxTwitter.h"

// 3D
#include "ofxSkyBox.h"

//////////////////////////////////////
// unofficial code

// GUI classes
#include "scroller.h"               // a simple scroller class

// webcam input classes
#include "sourceTracking.h"			// video input source class [from Emanuele Mazza]
#include "openniTracking.h"			// sensor kinect input source class [from Emanuele Mazza]
#include "matrixAreas.h"			// multiple points/areas mouse control, xml loading and saving [from Emanuele Mazza with great help from code fragment of Chris Sugrue]

// audio input [microphones, instruments, etc. routed via soundcard] class
#include "audioInputChannel.h"		// audio input source class [from Emanuele Mazza]

// audio Synthesis
#include "gaDsp.h"
#include "gaAmplifier.h"
#include "gaOscillator.h"
#include "audioModule.h"
#include "audioSample.h"
