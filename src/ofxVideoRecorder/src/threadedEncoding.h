#ifndef THREADED_ENCODING
#define THREADED_ENCODING

#include "ofMain.h"
#include "ofxVideoRecorder.h"

//---------------------------------------------------------------
// Threaded encoding with ffmpeg class
//---------------------------------------------------------------
class threadedEncoding : public ofThread
{
    public:
    
        threadedEncoding();
    
        void setup(int _aChannels);
    
        void encode(string _fn, string _an, int _fr, int _comp, bool _expAudio);
    
        void threadedFunction();
        void encodeThreaded(string _fn, string _an, int _fr, int _comp, bool _expAudio);
    
        string  fileName;
        string  audioFileName;
        int     frameRate;
        int     compression;
        int     audioChannels;
        bool    exportAudio;
    
};
//---------------------------------------------------------------
 
#endif

