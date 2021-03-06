#ifndef _GAMUZA_MAIN
#define _GAMUZA_MAIN

// includes
#include "gamuzaIncludes.h"

// constants
#include "gamuzaConstants.h"


class gamuzaMain : public ofBaseApp, public ofxMidiListener{
	
	public:
		
		/////////////////////////////
		// standard OF functions
		void setup();
		void update();
		void draw();
		// overload exit function
		void exit();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		/////////////////////////////
	
		// audio functions
		void setupAudio();
		void audioIn(float *input, int bufferSize, int nChannels); 
		void audioOut(float *output, int bufferSize, int nChannels);
		void addAudioModule(int _wT, float _freq);
		void addAudioModule(int _wT, float _freq, int _ch);
        void addAudioSample(string _file);
        void addInputRecording();
		void resetAudioOutput();
    
        // MIDI functions
        void setupMidi();
        void updateMidi();
        void newMidiMessage(ofxMidiEventArgs& eventArgs);
			
		// loading settings from XML
		void loadGamuzaSettings();
		
		// GUI functions
		void setupGui();
		void setupStringVec();
		void updateGui();
		void drawGui();
		void gamuzaFullscreen();
		void resetWarpingPoints(int actualPanel);
        void initTimeline();
        void receivedTrigger(ofxTLTriggerEventArgs& trigger);
	
		// EXPORT function
		void saveFrame();
		void printFrame();
	
		// FILE dialog functions
		void openFileDialog();
		void saveFileDialog();
    
        // Video Export functions
        void exportVideoFileDialog();
        void stopExportVideo();
	
		// GUI Events
		void eventsIn(guiCallbackData & data);
		void grabBackgroundEvent(guiCallbackData & data);
		void resetInputWarping(guiCallbackData & data);
		void activateTrackingCF(guiCallbackData & data);
		void recordNoise(guiCallbackData & data);
		void changeAnalogPinMode(guiCallbackData & data);
		void changeDigitalPinMode(guiCallbackData & data);
		void sendDigitalValue(guiCallbackData & data);
		void resetMappingPoints(guiCallbackData & data);
	
		// FBO functions
		void setupFBO();
        void updateFBO();
		void drawFBO();
		void drawIntoFBO(int w, int h);
		void cvHomographyFBO();
		void glGridMeshFBO(int xCalib, int yCalib, int w, int h);
	
		// Live Coding functions
		void loadScript(string _script);
		void renderScript(string & _script);
		string readScript(string _scriptFile,bool dialog);
	
		// ARDUINO functions
		void setupArduino();
		void updateArduino();
		void prepareArduinoOscData();
		void loadArduinoSetting();
		void saveArduinoSetting();
	
		// OSC functions
		void setupOSC();
		void updateOSC();
		void sendBuffer();
		void cleanBuffer();
	
		//////////////////////////////////////////////
		// SETTINGS vars from XML
	
		// SCREENS settings
		int						mainScreenW;
		int						mainScreenH;
		int						projectionScreenW;
		int						projectionScreenH;
		float					INVprojectionScreenW;
		float					INVprojectionScreenH;
		int						FPS;
	
		// AUTOMATION settings
		bool					autoPilot;
		bool					autoLoadScript;
		string					autoScriptFile;
	
		// FBO settings
		int						gridRes;
		int						fboNumSamples;
	
		// TRACKING settings
		bool					trackingActivated;
		bool					openniActivated;
		bool					useVideoTest;
		int						workingW;
		int						workingH;
		int						totPixels;
		string					haarFinderFile;
	
		// AUDIO settings
		bool					audioActivated;
		int						audioDevID;
		int						audioOutputChannels;
		int						audioInputChannels;
		int						audioSamplingRate;
		int						audioBufferSize;
		int						audioNumBuffers;
		int						fftWindowUse;
	
		// ARDUINO settings
		bool					arduinoActivated;
		string					serialDevice;
		int						baudRate;
	
		// OSC settings
		bool					oscActivated;
		string					host_number;
		string					host_port;
    
        // MIDI settings
        int                     midiPortNumber;
		
		//////////////////////////////////////////////
		
		//////////////////////////////////////////////
		// GUI
		ofxControlPanel			gui;
		simpleFileLister		scriptsLister;
		simpleLogger			logger;
		ofxKeyMap				gamuzaKmap;
		ofTexture				emptyTexture;
        ofxTimeline             timeline;
        string                  actualTriggerName;
        
        float					previewW,previewH,previewY;
        float					lcPrevW, lcPrevH, lcPrevX, lcPrevY;
		float					guiPosX;
		float					guiPosY;
        float                   scaledMouseX,scaledMouseY;
		bool					isFullscreen;
        bool                    showTimeline;
		//////////////////////////////////////////////
	
		//////////////////////////////////////////////
		// FBO texture with mapping structure vars
		ofFbo					drawingFbo;
		ofFbo					finalTexture;
		ofTexture				drawingTexture;
        ofPixels                outputPix;
		ofShader				shaderColorCorrection;
		bool					useShader;
        bool					useSecondaryScreen;
		matrixAreas				finalTextureMapping;
	
		ofVideoPlayer			outputVideo;
        ofImage					tempFrame;
		//////////////////////////////////////////////
		
		//////////////////////////////////////////////
		// Live Coding vars
		ofxGLEditor				liveCoding;
		ofxLua					lua;
        scroller                scriptScroll;
        int                     liveKey;
		//////////////////////////////////////////////
	
		//////////////////////////////////////////////
		// OpenNI sensor Kinect vars
		openniTracking			sensorKinect;
		int						sensorKinectIndex;
		int						sensorKinectLedState;
		bool					useKinectInfrared;
		//////////////////////////////////////////////
	
		//////////////////////////////////////////////
		// Video Tracking vars
		sourceTracking			*inputCam;
		int						numCamInputs;
		int*					camDevices;
		string*					deviceNames;
		int						webcamsStartIndex;
		//////////////////////////////////////////////
		
		//////////////////////////////////////////////
		// Audio INPUT/OUTPUT stream vars
		ofSoundStream			soundStream;
		audioInputChannel		*inputAudioCH;
		int						audioInputStartIndex;
	
		gaDsp					gamuzaDSP;
		gaAmplifier				gamuzaAMP;
    
		vector<audioModule>		audioModules;
		int						audioModulesNum;
    
        vector<audioSample>     audioSamples;
        int                     audioSamplesNum;
        
        vector<audioSample>     inputRecSamples;
        int                     inputRecordingsNum;
        vector<float>           recBuffer;
        int                     recSize;
        int                     recChannel;
        bool                    recordingInput;
    
		float					*outputBufferCopy;
		float					mainVolume;
	
		bool					flagSystemLoaded;
		bool					computeAudioInput;
		bool					computeAudioOutput;
		//////////////////////////////////////////////
	
		//////////////////////////////////////////////
		// Arduino vars
		ofArduino				arduino;
		bool					useArduino;
		int						arduinoIndex;
		int						*digitalPinModes;
		int						*analogPinModes;
		int						*digitalPinValuesInput;
		int						*digitalPinValuesOutput;
		int						*analogPinValues;
	
		bool					useKalmanFilterArduino;
		float					arduino_smoothingFactor;
		
		ofxCvKalman				*kanalogPinValues[6];
		float					*_kalman_analogPinValues;
		float					*_s_analogPinValues;
		float					*_osc_analogPinValues;
		int						*_osc_digitalPinValuesInput;
		bool					sendOsc_AAP;
		bool					sendOsc_ADP;
		//////////////////////////////////////////////
    
        //////////////////////////////////////////////
        // MIDI vars
        ofxMidiOut              midiOut;
        ofxMidiIn               midiIn;
        vector<ofVec3f>         midiMapping;
        char                    midi_msg[255];
        int                     midi_port;
        int                     midi_id;
        int                     midi_valueOne;
        int                     midi_valueTwo;
        double                  midi_timestamp;
        //////////////////////////////////////////////
		
		//////////////////////////////////////////////
		// OSC vars
		bool					useOsc;
		int						oscIndex;
		//////////////////////////////////////////////
	
	private:
		
        ofxMemoryUsage          ramMemory;
        ofxVideoRecorder        movieExport;
        ofxLibsndFileRecorder   audioExport;
        threadedEncoding        threadMovieEncoding;
		ofMutex					gamuzaSetup;
		ofxXmlSettings			setting_data;
		int						currentSavedFrame;
        bool                    isExporting;
        bool                    isEncoding;
        bool                    exportAudio;
		
        int                     gamuzaMem;
		float					gamuzaRealFPS;
        float                   gamuzaExportFPS;
        int                     exportCodec;
		bool					useVSync;

			 
};

#endif
