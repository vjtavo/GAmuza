#include "ofxLibsndFileRecorder.h"

ofxLibsndFileRecorder::ofxLibsndFileRecorder(){
	initialized=false;
	recordingBuffer=NULL;
}


void ofxLibsndFileRecorder::setup(string fileName_, int audioFormat_, int sampleRate_, int numChannels_){
	
	sampleRate      = sampleRate_;
	numChannels     = numChannels_;
	recordingSize   = 0;
	audioFormat     = audioFormat_;
    fileName        = fileName_;
	
    outFile=new SndfileHandle(fileName,SFM_RDWR, audioFormat, numChannels, sampleRate);
	if(!outFile){
		cout<<"SndFileHandl outfile creation error\n";
		initialized=false;
	}
	else{
		recordingBuffer=(float*)realloc(recordingBuffer, sizeof(float));
		initialized=true;	
	}
}
void  ofxLibsndFileRecorder::close(){
	if(recordingBuffer!=NULL)
		free(recordingBuffer);
	recordingBuffer=NULL;
	initialized=false;
	recordingSize=0;
}

void ofxLibsndFileRecorder::addSamples(float* &input, int numSamples){
	if(initialized){
		recordingSize+=numSamples;
		recordingBuffer=(float*)realloc(recordingBuffer, recordingSize*sizeof(float));
		memcpy(&recordingBuffer[recordingSize-numSamples], input, numSamples*sizeof(float)); 	
	}
}

void ofxLibsndFileRecorder::finalize(){
	if(initialized){
		int res=outFile->write(recordingBuffer, recordingSize);
		sf_close(outFile->takeOwnership());
        if(recordingBuffer!=NULL){
            free(recordingBuffer);
        }
        recordingBuffer=NULL;
		initialized=false;
		recordingSize=0;
	}
}

string ofxLibsndFileRecorder::getFileName(){
    return fileName;
}