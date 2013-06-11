#ifndef __PORT_H__
#define __PORT_H__
#include <gura.h>

#if defined(GURA_ON_MSWIN)
#elif defined(GURA_ON_LINUX)
#include <alsa/asoundlib.h>
#else
#error unknown platform
#endif

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Port
//-----------------------------------------------------------------------------
#if defined(GURA_ON_MSWIN)

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
	inline void Send(unsigned char msg1) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0));
	}
	inline void Send(unsigned char msg1, unsigned char msg2) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8));
	}
	inline void Send(unsigned char msg1, unsigned char msg2, unsigned char msg3) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8) +
					(static_cast<DWORD>(msg3) << 16));
	}
	inline void Send(unsigned char msg1, unsigned char msg2, unsigned char msg3,
					unsigned char msg4) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8) +
					(static_cast<DWORD>(msg3) << 16) +
					(static_cast<DWORD>(msg4) << 24));
	}
};

#elif defined(GURA_ON_LINUX)

class Port {
public:
private:
	snd_rawmidi_t *_out_rmidi;
public:
	inline Port() : _out_rmidi(NULL) {}
	inline ~Port() {
		Reset();
		Close();
	}
	static inline int GetNumDevs() {
		return 0;
	}
	inline bool Open(int id) {
		if (_out_rmidi != NULL) Close();
		char name[128];
		::sprintf(name, "hw:%d,%d,%d", 0, id, 0);
		return ::snd_rawmidi_open(NULL, &_out_rmidi, name, 0) >= 0;
	}
	inline void Close() {
		if (_out_rmidi != NULL) ::snd_rawmidi_close(_out_rmidi);
		_out_rmidi = NULL;
	}
	inline void Reset() {
	}
	inline void Send(unsigned char msg1) {
		unsigned char buff[1] = { msg1 };
		::snd_rawmidi_write(_out_rmidi, buff, sizeof(buff));
	}
	inline void Send(unsigned char msg1, unsigned char msg2) {
		unsigned char buff[2] = { msg1, msg2 };
		::snd_rawmidi_write(_out_rmidi, buff, sizeof(buff));
	}
	inline void Send(unsigned char msg1, unsigned char msg2, unsigned char msg3) {
		unsigned char buff[3] = { msg1, msg2, msg3 };
		::snd_rawmidi_write(_out_rmidi, buff, sizeof(buff));
	}
	inline void Send(unsigned char msg1, unsigned char msg2, unsigned char msg3,
					unsigned char msg4) {
		unsigned char buff[4] = { msg1, msg2, msg3, msg4 };
		::snd_rawmidi_write(_out_rmidi, buff, sizeof(buff));
	}
};

#else

#error unknown platform

#endif

}}

#endif
