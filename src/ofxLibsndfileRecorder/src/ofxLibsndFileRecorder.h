#ifndef _OFXLIBSNDFILE_RECORDER
#define _OFXLIBSNDFILE_RECORDER

#include "sndfile.hh"
#include "ofMain.h"

/*****FORMAT EXAMPLES:  
 SF_FORMAT_AIFF | SF_FORMAT_PCM_16;
 SF_FORMAT_RAW | SF_FORMAT_PCM_16;
 SF_FORMAT_AU | SF_FORMAT_FLOAT;
 (see sndfile.h for more information)*/


class ofxLibsndFileRecorder{
	public :
	
	ofxLibsndFileRecorder();
	void setup(string fileName_, int audioFormat_, int sampleRate, int numChannels);
	void addSamples(float* &input, int numSamples);
	
	void finalize();
	void close();
    
    string getFileName();
		
	private:
		SndfileHandle	*outFile;
		bool			initialized;
		string			fileName;
		int				sampleRate;
		int				numChannels;		
		int				audioFormat;
		string			suffix;
		float			*recordingBuffer;
		int				recordingSize;
	
};

#endif