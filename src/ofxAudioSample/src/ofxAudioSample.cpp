#include "ofxAudioSample.h"


//--------------------------------------------------------------
ofxAudioSample::ofxAudioSample(){
    position = 0;
    speed = 1.0;
    mainSpeed = 1.0;
    resampligFactor = 1.0;
    isLooping   = false;
    isPlaying   = false;
    isPaused    = false;
    
}

//--------------------------------------------------------------
ofxAudioSample::~ofxAudioSample(){
    
}

//--------------------------------------------------------------
void ofxAudioSample::load(string tmpPath, float _hSampleRate) {
    
	myPath = ofToDataPath(tmpPath,true).c_str();
    
    SndfileHandle sndFile = SndfileHandle(myPath);
    
    myFormat        = sndFile.format();
    myChannels      = sndFile.channels();
    mySampleRate    = sndFile.samplerate();
    
    resampligFactor = _hSampleRate/mySampleRate;
    
    speed           = mainSpeed/resampligFactor;
    
    bufferSize = 4096 * myChannels;
    
    readBuffer = new float[bufferSize];
    
    ofVec2f _wF;
    int     readcount;
    int     readpointer;
    
    // convert all multichannel files to mono by averaging the channels
    float monoAverage;
    
    while(readcount = sndFile.readf(readBuffer, 4096)){
        readpointer = 0;
        _wF.set(0,0);
        for (int i = 0; i < readcount; i++) {
            // for each frame...
            monoAverage = 0;
            for(int j = 0; j < myChannels; j++) {
                monoAverage += readBuffer[readpointer + j];
            }
            monoAverage /= myChannels;
            readpointer += myChannels;
            // add the averaged sample to our vector of samples
            samples.push_back(monoAverage);
            
            // add to the waveform data
            _wF.x = MIN(_wF.x, monoAverage);
            _wF.y = MAX(_wF.y, monoAverage);
        }
        _waveForm.push_back(_wF);
    }
    
    position = 0;
    
}

//--------------------------------------------------------------
void ofxAudioSample::load(vector<float> _buf, int recSize) {
    
    samples = _buf;
    
    position = 0;
    
}

//--------------------------------------------------------------
float ofxAudioSample::update(){
    
    if(!isPlaying){
        output = 0;
    }else if(isPlaying && isPaused){
        output = 0;
    }else if(isPlaying && !isPaused){
        
        // update position
        position += speed;
        
        // check if reached EOF
        if(position > samples.size()-1) {
            if(isLooping) {
                position=0;
            }else{
                isPlaying = false;
                return 0;
            }
        }
        
        //check if position less than zero (reverse)
        if (position < 0) {
            if(isLooping) {
                position = samples.size()-1;
            }else{
                isPlaying = false;
                return 0;
            }
        }
        
        output = samples[1+(long)position];
        
    }
    
    return(output);
    
}

//--------------------------------------------------------------
void ofxAudioSample::stop(){
    position = 0;
    isPlaying = false;
}

//--------------------------------------------------------------
void ofxAudioSample::play(){
    if(speed > 0){
        position = 0;
    }else{
        position = getLength();
    }
    isPlaying = true;
}

//--------------------------------------------------------------
void ofxAudioSample::setPaused(bool bPaused){
    isPaused    = bPaused;
}

//--------------------------------------------------------------
void ofxAudioSample::setSpeed(float spd){
    mainSpeed = spd;
    speed     = mainSpeed/resampligFactor;
}

//--------------------------------------------------------------
void ofxAudioSample::setLooping(bool loop){
    if(loop) {
        isLooping   = true;
    }
    else {
        isLooping   = false;
    }
}

//--------------------------------------------------------------
void ofxAudioSample::setPosition(float _position){
	float pct = ofClamp(_position,0.0,1.0);
	position = pct * getLength();
}

//--------------------------------------------------------------
float ofxAudioSample::getSpeed(){
    return mainSpeed;
}

//--------------------------------------------------------------
int ofxAudioSample::getSampleRate(){
    return mySampleRate;
}

//--------------------------------------------------------------
bool ofxAudioSample::getIsPlaying(){
    return isPlaying;
}

//--------------------------------------------------------------
long ofxAudioSample::getLength(){
	long length;
	length=samples.size();
	return(length);
}

//--------------------------------------------------------------
float ofxAudioSample::getPosition(){
    float pos = position/getLength();
    pos = ofClamp(pos,0.0,1.0);
	return pos;
}

//--------------------------------------------------------------
int ofxAudioSample::getChannels(){
    return myChannels;
}

//--------------------------------------------------------------
void ofxAudioSample::drawWaveForm(int _x, int _y, int _w, int _h){
    
    float waveFormZoomX = (float)_waveForm.size()/(float)(_w+1.0);
    float waveFormDisplayScale = samples.size()/(_w+1.0);
    
	ofPushMatrix();
    ofTranslate(_x, _y, 0);
    
    ofEnableAlphaBlending();
	for (unsigned int i = 1; i < _waveForm.size(); i++){
            ofSetColor(255,231,118,120);
            ofLine((i-1)/waveFormZoomX, _h + (int)(_waveForm[i-1].x*_h), i/waveFormZoomX, _h +  (int)(_waveForm[i].y*_h));
            ofSetColor(118,118,118,70);
            ofLine(i/waveFormZoomX, _h + (int)(_waveForm[i].y*_h), i/waveFormZoomX, _h + (int) (_waveForm[i].x*_h));
	}
    ofDisableAlphaBlending();
    
	ofSetColor(216,64,64);
    ofLine(position/waveFormDisplayScale, -(float)_h*0.0, position/waveFormDisplayScale, (float)_h*2.0);
    
	ofPopMatrix();
    
}

//--------------------------------------------------------------
void ofxAudioSample::drawHead(int _x, int _y, int _w, int _h){
    
    float waveFormDisplayScale = samples.size()/(_w+1.0);
    
    ofPushMatrix();
    ofTranslate(_x, _y, 0);
    
    ofSetColor(216,64,64);
    ofLine(position/waveFormDisplayScale, -(float)_h*0.0, position/waveFormDisplayScale, (float)_h*2.0);
    
	ofPopMatrix();
}