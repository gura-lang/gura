#ifndef __MIDIHANDLE_H__
#define __MIDIHANDLE_H__
#include "MmlParser.h"

//-----------------------------------------------------------------------------
// MIDIHandle
//-----------------------------------------------------------------------------
class MIDIHandle {
public:
	enum {
		NUM_CHANNELS = 16,
	};
	class Channel : public MmlParser {
	private:
		MIDIHandle *_pHandle;
		char _channel;
	public:
		inline Channel(MIDIHandle *pHandle, char channel) :
									_pHandle(pHandle), _channel(channel) {}
		inline char GetChannel() const { return _channel; }
	protected:
		// virtual functions of MmlParser
		virtual void OnMmlNote(unsigned char note, int length);
		virtual void OnMmlRest(int length);
		virtual void OnMmlVolume(int volume);
		virtual void OnMmlTone(int tone);
		virtual void OnMmlTempo(int tempo);
	};
private:
	HMIDIOUT _hMIDI;
	Channel *_pChannels[NUM_CHANNELS];
public:
	MIDIHandle();
	~MIDIHandle();
	static inline int GetNumDevs() {
		return ::midiOutGetNumDevs();
	}
	inline bool Open(int id) {
		if (_hMIDI != NULL) Close();
		return ::midiOutOpen(&_hMIDI, id, 0, 0, CALLBACK_NULL) == MMSYSERR_NOERROR;
	}
	inline void Close() {
		if (_hMIDI != NULL) ::midiOutClose(_hMIDI);
		_hMIDI = NULL;
	}
	inline void Reset() {
		if (_hMIDI != NULL) ::midiOutReset(_hMIDI);
	}
	inline void RawWrite(unsigned char msg1) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0));
	}
	inline void RawWrite(unsigned char msg1, unsigned char msg2) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8));
	}
	inline void RawWrite(unsigned char msg1, unsigned char msg2, unsigned char msg3) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8) +
					(static_cast<DWORD>(msg3) << 16));
	}
	inline void RawWrite(unsigned char msg1, unsigned char msg2, unsigned char msg3,
					unsigned char msg4) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8) +
					(static_cast<DWORD>(msg3) << 16) +
					(static_cast<DWORD>(msg4) << 24));
	}
	void MmlPlay(char channel, const char *mml);
};

#endif
