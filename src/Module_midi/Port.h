#ifndef __PORT_H__
#define __PORT_H__
#include <gura.h>

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Port
//-----------------------------------------------------------------------------
class Port {
public:
private:
	HMIDIOUT _hMIDI;
public:
	inline Port() : _hMIDI(NULL) {}
	inline ~Port() {
		Reset();
		Close();
	}
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
};

#if 0
class Player {
public:
	enum {
		NUM_CHANNELS = 16,
	};
	class Channel : public MmlParser {
	private:
		Port *_pPort;
		char _channel;
	public:
		inline Channel(Port *pPort, char channel) :
									_pPort(pPort), _channel(channel) {}
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
	Channel *_pChannels[NUM_CHANNELS];
public:
	Player();
	~Player();
	void MmlPlay(char channel, const char *mml);
	bool Play(Signal sig, Port *pPort, Stream &stream);
};
#endif

}}

#endif
