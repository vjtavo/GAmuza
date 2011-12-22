/*
 * Copyright (c) 2011 Dan Wilcox <danomatika@gmail.com>
 *
 * BSD Simplified License.
 * For information on usage and redistribution, and for a DISCLAIMER OF ALL
 * WARRANTIES, see the file, "LICENSE.txt," in this distribution.
 *
 * See https://github.com/danomatika/ofxPd for documentation
 *
 * This project uses libpd, copyrighted by Miller Puckette and others using the
 * "Standard Improved BSD License". See the file "LICENSE.txt" in src/pd.
 *
 * See http://gitorious.org/pdlib/pages/Libpd for documentation
 *
 */
#pragma once

#include <map>
#include <set>
#include <Poco/Mutex.h>

#include "z_libpd.h"
#include "ofxPdListener.h"

#ifndef HAVE_UNISTD_H
#warning You need to define HAVE_UNISTD_H in your project build settings!
#endif

///
///	a Pure Data instance
///
///	references:	http://gitorious.org/pdlib/pages/Libpd
///
/// note: libpd currently does not support multiple states and it is 
///       suggested that you use only one ofxPd object at a time
///
class ofxPd {
	
	public :

		ofxPd();
		virtual ~ofxPd();
        
        /// initialize resources
		///
		/// set the audio latency by setting the libpd ticks per buffer:
		/// ticks per buffer * lib pd block size (always 64)
		///
		/// ie 4 ticks per buffer * 64 = buffer len of 512
		///
		/// the lower the number of ticks, the faster the audio processing
		/// if you experience audio dropouts (audible clicks), increase the
		/// ticks per buffer
		///
		bool init(const int numOutChannels, const int numInChannels,
				  const int sampleRate, const int ticksPerBuffer=32);
        
        /// clear resources
        void clear();
		
		/// \section Search Path
		
		/// add to the pd search path
		/// takes an absolute or relative path (in data folder)
		/// note: fails silently if path not found
		void addToSearchPath(const std::string& path);
		
		/// clear the current pd search path
		void clearSearchPath();
		
		/// \section Patch
		
		/// open a patch, takes an absolute or relative path (in data folder)
		/// returns a Patch object
		Patch openPatch(const std::string& patch);
		
		/// close a patch, takes the patch's basename (filename without extension)
		void closePatch(const std::string& patch);
		
		/// close a path, takes a patch object
		/// clears the given Patch object
		void closePatch(Patch& patch);
		
		/// \section Dsp Control
		
		// turn on/off digital signal processing
		void dspOn();
		void dspOff();
		
		//// \section Receiving
		
		/// add/remove listener to receive events
		///
		/// listeners automatically receive print and midi events only,
		/// use subscribe() to plug a listener into a source
		///
		void addListener(ofxPdListener& listener);
		void removeListener(ofxPdListener& listener);
		bool listenerExists(ofxPdListener& listener);
		void clearListeners();	/// also unsubscribes all listeners
		
		/// add/remove receiver sources from libpd
		///
		/// aka the pd receive name
		///
		/// [r source]
		/// |
		///
		/// note: the global source (aka "") exists by default 
		///
		void addSource(const std::string& source);
		void removeSource(const std::string& source);
		bool sourceExists(const std::string& source);
		void clearSources();	/// listeners will be unsubscribed from *all* sources
		
		/// un/subscribe a listener to a receiver source from libpd
		///
		/// un/subscribe using a source name or "" for all sources,
		/// make sure to add the listener and source first
		///
		/// note: the global source (aka "") is added by default
		/// note: unsubscribing from the global source unsubscribes from *all*
		///       sources, so the listener will not recieve any message events,
		///		  but still get print and midi events
		///
		/// also: use negation if you want to subscribe to all sources but one:
		///
		/// pd.subscribe(listener);				// subscribe to all
		/// pd.unsubscribe(listener, "source"); // unsubscribe from "source"
		///
		void subscribe(ofxPdListener& listener, const std::string& source="");
		void unsubscribe(ofxPdListener& listener, const std::string& source="");
		bool isSubscribed(ofxPdListener& listener, const std::string& source="");
		
		/// \section Sending Functions
		
		/// messages
		void sendBang(const std::string& dest);
		void sendFloat(const std::string& dest, float value);
		void sendSymbol(const std::string& dest, const std::string& symbol);
		
		/// compound messages
		///
		/// pd.startList("test");	// "test" is the reciever name in pd
		/// pd.addSymbol("hello");
		/// pd.addFloat(1.23);
		/// pd.finish();
		///
		/// sends [list hello 1.23( -> [r test],
        /// you will need to use the [list trim] object on the reciving end 
		/// 
        /// startMsg sends a typed message -> [; test msg1 hello 1.23(
        ///
        /// pd.startMsg("test", "msg1");
        /// pd.addSymbol("hello");
		/// pd.addFloat(1.23);
		/// pd.finish();
        ///
		void startList(const std::string& dest);
		void startMsg(const std::string& dest, const std::string& msg);
		void addFloat(const float value);
		void addSymbol(const std::string& symbol);
		void finish();
        
        /// compound messages using the ofxPd List type
        ///
        /// List list;
        /// list.addSymbol("hello");
        /// list.addFloat(1.23);
        /// pd.sendList("test", list);
        ///
        /// sends [list hello 1.23( -> [r test]
        ///
        /// clear the list:
        ///
        /// list.clear();
        ///
        /// stream operators work as well:
        ///
        /// list << "hello" << 1.23;
        /// pd.sendMsg("test", "msg1", list);
        /// 
        /// sends a typed message -> [; test msg1 hello 1.23(
        ///
        void sendList(const std::string& dest, const List& list);
        void sendMsg(const std::string& dest, const std::string& msg, const List& list);
		
		/// midi
		///
		/// send midi messages, any out of range messages will be silently ignored
		///
		/// number ranges:
		/// pitch 		0 - 127
		/// velocity	0 - 127
		/// channel		1 - 16 * dev# (dev #0: 1-16, dev #1: 17-32, etc)
		/// control value	0 - 127
		/// program value	0 - 127
		/// bend value		-8192 - 8191
		/// touch value		0 - 127
		///
		/// note: in pd, [bendin] returns a range of 0 - 16383 while [bendout]
		///       returns a range of -8192 - 8192
		///
		void sendNote(const int pitch, const int velocity=64, const int channel=1);
		void sendCtl(const int controller, const int value, const int channel=1);
		void sendPgm(const int value, const int channel=1);
		void sendBend(const int value, const int channel=1);
		void sendTouch(const int value, const int channel=1);
		void sendPolyTouch(const int pitch, const int value, const int channel=1);		
		
		/// raw midi bytes
		///
		/// value is a raw midi byte value 0 - 255
		/// port is the raw port audio port #, see http://en.wikipedia.org/wiki/PortMidi 
		///
		void sendMidiByte(const int value, const int port=0);
		void sendSysExByte(const int value, const int port=0);
		void sendSysRTByte(const int value, const int port=0);
		
		/// \section Sending Stream Interface
		
		/// single messages
		///
		/// pd << Bang("test"); /// "test" is the reciever name in pd
		/// pd << Float("test", 100);
		/// pd << Symbol("test", "a symbol");
		///
		ofxPd& operator<<(const Bang& var);
		ofxPd& operator<<(const Float& var);
		ofxPd& operator<<(const Symbol& var);
		
		/// compound messages
		///
		/// pd << StartList("test") << 100 << 1.2 << "a symbol" << Finish();
		///
		ofxPd& operator<<(const StartList& var);
		ofxPd& operator<<(const StartMsg& var);
        
		/// add a float to the message
		ofxPd& operator<<(const bool var);
        ofxPd& operator<<(const int var);
        ofxPd& operator<<(const float var);
        ofxPd& operator<<(const double var);
        
		/// add a symbol to the message
		ofxPd& operator<<(const char var);
        ofxPd& operator<<(const char* var);
        ofxPd& operator<<(const std::string& var);
		
		/// midi
		///
		/// pd << Note(64) << Note(64, 60) << Note(64, 60, 1);
		/// pd << Ctl(100, 64) << Pgm(100, 1) << Bend(2000, 1);
		/// pd << Touch(127, 1) << PolyTouch(64, 127, 1);
		///
		ofxPd& operator<<(const Note& var);
		ofxPd& operator<<(const Ctl& var);
		ofxPd& operator<<(const Pgm& var);
		ofxPd& operator<<(const Bend& var);
		ofxPd& operator<<(const Touch& var);
		ofxPd& operator<<(const PolyTouch& var);
		
		/// compound raw midi byte stream
		///
		/// pd << StartMidi() << 0xEF << 0x45 << Finish();
		/// pd << StartSysEx() << 0xE7 << 0x45 << 0x56 << 0x17 << Finish();
		///
		ofxPd& operator<<(const StartMidi& var);
		ofxPd& operator<<(const StartSysEx& var);
		ofxPd& operator<<(const StartSysRT& var);
		
		/// finish a compound message or byte stream
        ofxPd& operator<<(const Finish& var);
		
		/// is a message currently in progress?
        inline bool isMsgInProgress() {return bMsgInProgress;}
		
		/// \section Array Access
		
		/// get pd array length
		/// returns 0 if array not found
		int getArrayLen(const std::string& arrayName);
		
		/// read from a pd array
		///
		/// resizes given vector to readLen, checks readLen and offset
		///
		/// returns true on success, false on failure
		///
		/// calling without setting readLen and offset reads the whole array:
		///
		/// vector<float> array1;
		/// readArray("array1", array1); 
		///
		bool readArray(const std::string& arrayName, std::vector<float>& dest,
												int readLen=-1, int offset=0);
		
		/// write to a pd array
		///
		/// calling without setting writeLen and offset writes the whole array:
		///
		/// writeArray("array1", array1); 
		///
		bool writeArray(const std::string& arrayName, std::vector<float>& source,
													int writeLen=-1, int offset=0);
		
		/// clear array and set to a specific value
		void clearArray(const std::string& arrayName, int value=0);
		
		/// \section Utils
		
		/// get the blocksize of pd (sample length per channel)
		static int getBlockSize();
        
        /// get/set the max length of messages and lists, default: 32
        void setMaxMsgLength(unsigned int len);
        unsigned int getMaxMsgLength();
		
		/// \section Audio Processing Callbacks
		
		/// the libpd processing is done in the audioOut callback
		virtual void audioIn(float * input, int bufferSize, int nChannels);
		virtual void audioOut(float * output, int bufferSize, int nChannels);
		
    private:
	
		bool bPdInited;						///< is pd inited?

		int sampleRate;						///< the audio sample rate
		int ticksPerBuffer;					///< how many pd blocks per buffer frame
		int numInChannels, numOutChannels;	///< number of channels in/out
		float *inputBuffer;  				///< interleaved input audio buffer
		
		bool bMsgInProgress;				///< is a compound message being constructed?
        int maxMsgLen;                      ///< maximum allowed message length
        int curMsgLen;                      ///< the length of the current message
		
		/// compound message status
		enum MsgType {
			LIST,
			MSG,
			MIDI,
			SYSEX,
			SYSRT
		} msgType;
		
		std::string msgDest;	///< message destination
		std::string msgMsg;		///< message target message
		int midiPort;			///< target midi port
	
		/// a receiving sources's pointer and bound listeners
		struct Source {
			
			// data
			void* pointer;						///< source pointer
			std::set<ofxPdListener*> listeners;	///< subscribed listeners

			// helper functions
			void addListener(ofxPdListener* listener) {
				listeners.insert(listener);
			}
			
			void removeListener(ofxPdListener* listener) {
				std::set<ofxPdListener*>::iterator iter;
				iter = listeners.find(listener);
				if(iter != listeners.end())
					listeners.erase(iter);
			}

			bool listenerExists(ofxPdListener* listener) {
				if(listeners.find(listener) != listeners.end())
					return true;
				return false;
			}
		};
			
		std::set<ofxPdListener*> listeners;		///< the listeners
		std::map<std::string,Source> sources;	///< bound sources
												///< first object always global
		
		std::string printMsg;	///< used to build a print message
		
		Poco::FastMutex mutex;	///< used to lock libpd for thread safety
		
		// libpd static callback functions
		static void _print(const char* s);
				
		static void _bang(const char* source);
		static void _float(const char* source, float value);
		static void _symbol(const char* source, const char* symbol);
		
		static void _list(const char* source, int argc, t_atom* argv); 
		static void _message(const char* source, const char *symbol,
												int argc, t_atom *argv);

		static void _noteon(int channel, int pitch, int velocity);
		static void _controlchange(int channel, int controller, int value);
		static void _programchange(int channel, int value);
		static void _pitchbend(int channel, int value);
		static void _aftertouch(int channel, int value);
		static void _polyaftertouch(int channel, int pitch, int value);
		
		static void _midibyte(int port, int byte);
};
