#ifndef _OFXAUDIOSAMPLE
#define _OFXAUDIOSAMPLE

#include "sndfile.hh"

#include "ofMain.h"

class ofxAudioSample{
	
	public:
	
		
		ofxAudioSample();
		~ofxAudioSample();
	
		void	load(string tmpPath, float _hSampleRate);
        void	load(vector<float> _buf, int recSize);
        
        float   update();
		void	play();
		void    stop();
    
        void	setLooping(bool loop);
        void	setPosition(float _position);
        void    setPaused(bool bPaused);
        void    setSpeed(float speed);
		
		int		getChannels();
		int		getSampleRate();
		long	getLength();
        float	getPosition();
        float   getSpeed();
        bool    getIsPlaying();
    
        void    drawWaveForm(int _x, int _y, int _w, int _h);
        void    drawHead(int _x, int _y, int _w, int _h);
        
    
        int             myFormat;
        int             myChannels;
        int				mySampleRate;
        int             bufferSize;
        float           resampligFactor;

	private:
		
		string			myPath;
    
		float			position;
		float			speed;
        float           mainSpeed;
		float			output;
		bool			isLooping;
        bool            isPlaying;
        bool            isPaused;
		unsigned char	soundStatus;
        
        float*          readBuffer;
    
        vector<float>   samples;
        vector<ofVec2f> _waveForm;
	
};

#endif