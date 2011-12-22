#include "threadedEncoding.h"

//---------------------------------------------------------------
threadedEncoding::threadedEncoding(){

}

//---------------------------------------------------------------
void threadedEncoding::setup(int _aChannels){
    this->audioChannels = _aChannels;
}

//---------------------------------------------------------------
void threadedEncoding::encode(string _fn, string _an, int _fr, int _comp, bool _expAudio){
    char cmd[1024];
    switch (_comp) {
        case 0: // raw
            sprintf(cmd,"ffmpeg -y -i -r %2$d %1$s.mjpg -r %2$d %1$s.mov; rm %1$s.mjpg;",_fn.c_str(), _fr);
            break;
        case 1: // h264 HD
            sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -b:v 6144k -bt 8192k -vcodec libx264 -pass 1 -threads 0 -vpre hq -wpredp 0 %1$s.mp4; rm %1$s.mjpg",_fn.c_str(), _fr);

            break;
        case 2: // iPhone 320
            sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s 480x320 -aspect 3:2 -b:v 200k -bt 240k -vcodec libx264 -pass 1 -threads 0 -bf 0 -flags2 -wpred-dct8x8 -level 13 -maxrate 768k -bufsize 3M %1$s.mp4; rm %1$s.mjpg",_fn.c_str(), _fr);

            break;
        case 3: // iPhone 640
            sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s 960x640 -aspect 3:2 -b:v 200k -bt 240k -vcodec libx264 -pass 1 -threads 0 -bf 0 -refs 1 -flags2 -wpred-dct8x8 -level 30 -maxrate 10M -bufsize 10M %1$s.mp4; rm %1$s.mjpg",_fn.c_str(), _fr);

            break;
        case 4: // iPad 1024
            sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s 1024x768 -aspect 4:3 -b:v 6144k -bt 8192k -vcodec libx264 -pass 1 -threads 0 -bf 0 -refs 1 -flags2 -wpred-dct8x8 -level 13 -maxrate 10M -bufsize 10M %1$s.mp4; rm %1$s.mjpg",_fn.c_str(), _fr);

            break;
        case 5: // 3gp
            sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -s 176x144 -aspect 11:9 -vcodec libx264 -pass 1 -threads 0 -r 25 -b 200k -bt 240k %1$s.3gp; rm %1$s.mjpg",_fn.c_str());
            break;
        case 6: // vimeo SD
            sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s 640x480 -aspect 4:3 -vcodec libx264 -pass 1 -threads 0 -vpre hq -wpredp 0 -b:v 2000k -bt 2800k -crf 24 %1$s.mp4; rm %1$s.mjpg",_fn.c_str(), _fr);

            break;
        case 7: // vimeo 720p
            sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s hd720 -aspect 16:9 -vcodec libx264 -pass 1 -threads 0 -vpre hq -wpredp 0 -b:v 6144k -bt 8192k -crf 24 %1$s.mp4; rm %1$s.mjpg",_fn.c_str(), _fr);

            break;
        case 8: // vimeo 1080p
            sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s hd1080 -aspect 16:9 -vcodec libx264 -pass 1 -threads 0 -vpre hq -wpredp 0 -b:v 6144k -bt 8192k -crf 24 %1$s.mp4; rm %1$s.mjpg",_fn.c_str(), _fr);

            break;
        default:
            break;
    }

    system(cmd);
}

//---------------------------------------------------------------
void threadedEncoding::threadedFunction(){
    if(lock()){
        encode(fileName, audioFileName, frameRate,compression,exportAudio);
        unlock();
    }
    stopThread();
}

//---------------------------------------------------------------
void threadedEncoding::encodeThreaded(string _fn, string _an, int _fr, int _comp, bool _expAudio){
    this->fileName      = _fn;
    this->audioFileName = _an;
    this->frameRate     = _fr;
    this->compression   = _comp;
    this->exportAudio   = _expAudio;
    startThread(false,false);
}
