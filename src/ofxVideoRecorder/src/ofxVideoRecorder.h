#pragma once

#include "ofMain.h"
#include <queue>
#include "FreeImage.h"

FI_STRUCT (FIMEMORYHEADER)
{
    /// remember to delete the buffer
    bool delete_me;
    /// file length
    long filelen;
    /// buffer size
    long datalen;
    /// current position
    long curpos;
    /// start buffer address
    void *data;
};

class ofxVideoRecorder : public ofThread
{
public:
    ofxVideoRecorder()
    {
        bIsInitialized = false;
    }
    bool setup(string fname, int w, int h, int fps, int comp)
    {
        if(bIsInitialized)
        {
            close();
        }

        width = w;
        height = h;
        frameRate = fps;
        compression = comp;
        fileName = fname;
        bIsInitialized = videoFile.open(fileName+".mjpg",ofFile::WriteOnly,true);
        if(!isThreadRunning())
            startThread(true, false);
        return bIsInitialized;
    }

    void addFrame(const ofPixels pixels)
    {
        if(bIsInitialized)
        {
            ofPixels * buffer = new ofPixels(pixels);

            lock();
            frames.push(buffer);
            unlock();
            condition.signal();
        }
    }

    void close()
    {
        bIsInitialized = false;
        waitForThread(false);
        if(videoFile.is_open())
        {
            videoFile.close();
        }
    }
    int encodeVideo()
    {
        if(bIsInitialized) close();
        char cmd[1024];
        switch (compression) {
            case 0: // raw
                sprintf(cmd,"ffmpeg -y -i -r %2$d %1$s.mjpg -r %2$d -vcodec copy %1$s.mov; rm %1$s.mjpg",fileName.c_str(), frameRate);
                break;
            case 1: // h264 HD
                sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -b 6144k -bt 8192k -vcodec libx264 -pass 1 -threads 0 -vpre hq -wpredp 0 %1$s.mp4; rm %1$s.mjpg",fileName.c_str(), frameRate);
                break;
            case 2: // iPhone 320
                sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s 320x240 -b 200k -bt 240k -vcodec libx264 -pass 1 -threads 0 -bf 0 -flags2 -wpred-dct8x8 -level 13 -maxrate 768k -bufsize 3M -acodec libfaac -ac 2 -ar 48000 -ab 192k %1$s.mp4; rm %1$s.mjpg",fileName.c_str(), frameRate);
                break;
            case 3: // iPhone 640
                sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s 640x480 -b 200k -bt 240k -vcodec libx264 -pass 1 -threads 0 -bf 0 -refs 1 -flags2 -wpred-dct8x8 -level 30 -maxrate 10M -bufsize 10M -acodec libfaac -ac 2 -ar 48000 -ab 192k %1$s.mp4; rm %1$s.mjpg",fileName.c_str(), frameRate);
                break;
            case 4: // iPad 1024
                sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -r %2$d -s 1024x768 -b 6144k -bt 8192k -vcodec libx264 -pass 1 -threads 0 -bf 0 -refs 1 -flags2 -wpred-dct8x8 -level 30 -maxrate 10M -bufsize 10M -acodec libfaac -ac 2 -ar 48000 -ab 192k %1$s.mp4; rm %1$s.mjpg",fileName.c_str(), frameRate);
                break;
            case 5: // 3gp(mobile)
                sprintf(cmd,"ffmpeg -y -i %1$s.mjpg -s 176x144 -vcodec libx264 -pass 1 -threads 0 -r 25 -b 12200 -ab 12200 -ac 1 -ar 8000 %1$s.3gp; rm %1$s.mjpg",fileName.c_str());
                break;
            case 6: // vimeo SD
                sprintf(cmd,"ffmpeg -y -i %1$s.mjpg  -r %2$d -acodec libfaac -ac 2 -ab 320k -ar 44100 -vcodec libx264 -pass 1 -threads 0 -vpre hq -wpredp 0 -s 640x480 -b 2000k -bt 2800k -crf 24 %1$s.mp4; rm %1$s.mjpg",fileName.c_str(), frameRate);
                break;
            case 7: // vimeo 720p
                sprintf(cmd,"ffmpeg -y -i %1$s.mjpg  -r %2$d -acodec libfaac -ac 2 -ab 320k -ar 44100 -vcodec libx264 -pass 1 -threads 0 -vpre hq -wpredp 0 -s 1280x720 -b 6144k -bt 8192k -crf 24 %1$s.mp4; rm %1$s.mjpg",fileName.c_str(), frameRate);
                break;
            case 8: // vimeo 1080p
                sprintf(cmd,"ffmpeg -y -i %1$s.mjpg  -r %2$d -acodec libfaac -ac 2 -ab 320k -ar 44100 -vcodec libx264 -pass 1 -threads 0 -vpre hq -wpredp 0 -s 1920x1080 -b 6144k -bt 8192k -crf 24 %1$s.mp4; rm %1$s.mjpg",fileName.c_str(), frameRate);
                break;
            default:
                break;
        }

        return system(cmd);
    }

    void threadedFunction()
    {
        while(isThreadRunning())
        {
            ofPixels * frame = NULL;
			lock();
			if(!frames.empty()) {
				frame = frames.front();
				frames.pop();
			}
			unlock();

			if(frame){
				frame->swapRgb();

				FIBITMAP * bmp = FreeImage_ConvertFromRawBits(frame->getPixels(), width, height, 4*width, 32, FI_RGBA_RED_MASK,FI_RGBA_GREEN_MASK,FI_RGBA_BLUE_MASK, true);
                FIBITMAP * converted = FreeImage_ConvertTo24Bits(bmp);
                FIBITMAP * final = FreeImage_ColorQuantize(converted, FIQ_WUQUANT);
				FIMEMORY *hmem = FreeImage_OpenMemory();

				FreeImage_SaveToMemory(FIF_JPEG, final, hmem, 100);


				long file_size = FreeImage_TellMemory(hmem);
				videoFile.write((char *)(((FIMEMORYHEADER*)(hmem->data))->data), file_size);
                FreeImage_Unload(final);
                FreeImage_Unload(converted);
				FreeImage_Unload(bmp);
				FreeImage_CloseMemory(hmem);

				delete frame;
			} else {
				if(bIsInitialized){
					//ofSleepMillis(1.0/(float)frameRate);
					condition.wait(conditionMutex);
				}else{
					break;
				}
			}
        }
    }

    int getNumFramesInQueue()
    {
        return frames.size();
    }
    bool isInitialized()
    {
        return bIsInitialized;
    }
    string getFileName()
    {
        return fileName;
    }

private:
    string fileName;
    ofFile videoFile;
    int width, height, frameRate, compression;
    bool bIsInitialized;
    queue<ofPixels *> frames;
    Poco::Condition condition;
    ofMutex conditionMutex;
};
