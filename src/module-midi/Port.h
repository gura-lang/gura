#ifndef __PORT_H__
#define __PORT_H__
#include <gura.h>

#if defined(GURA_ON_MSWIN)
#elif defined(GURA_ON_LINUX)
#include <alsa/asoundlib.h>
#elif defined(GURA_ON_DARWIN)
#include <CoreMIDI/CoreMIDI.h>
#else
#error unknown platform
#endif

Gura_BeginModuleScope(midi)

//-----------------------------------------------------------------------------
// Port
//-----------------------------------------------------------------------------
#if defined(GURA_ON_MSWIN)

class Port {
private:
	int _cntRef;
	HMIDIOUT _hMIDI;
public:
	Gura_DeclareReferenceAccessor(Port);
public:
	inline Port() : _cntRef(1), _hMIDI(NULL) {}
protected:
	inline ~Port() {
		Reset();
		Close();
	}
public:
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
	inline void Send(UChar msg1) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0));
	}
	inline void Send(UChar msg1, UChar msg2) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8));
	}
	inline void Send(UChar msg1, UChar msg2, UChar msg3) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8) +
					(static_cast<DWORD>(msg3) << 16));
	}
	inline void Send(UChar msg1, UChar msg2, UChar msg3,
					UChar msg4) {
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
	int _cntRef;
	snd_rawmidi_t *_out_rmidi;
public:
	Gura_DeclareReferenceAccessor(Port);
public:
	inline Port() : _cntRef(1), _out_rmidi(NULL) {}
protected:
	inline ~Port() {
		Reset();
		Close();
	}
public:
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
	inline void Send(UChar msg1) {
		UChar buff[1] = { msg1 };
		::snd_rawmidi_write(_out_rmidi, buff, sizeof(buff));
	}
	inline void Send(UChar msg1, UChar msg2) {
		UChar buff[2] = { msg1, msg2 };
		::snd_rawmidi_write(_out_rmidi, buff, sizeof(buff));
	}
	inline void Send(UChar msg1, UChar msg2, UChar msg3) {
		UChar buff[3] = { msg1, msg2, msg3 };
		::snd_rawmidi_write(_out_rmidi, buff, sizeof(buff));
	}
	inline void Send(UChar msg1, UChar msg2, UChar msg3,
					UChar msg4) {
		UChar buff[4] = { msg1, msg2, msg3, msg4 };
		::snd_rawmidi_write(_out_rmidi, buff, sizeof(buff));
	}
};

#elif defined(GURA_ON_DARWIN)

class Port {
private:
	int _cntRef;
	MIDIPortRef _port;
public:
	Gura_DeclareReferenceAccessor(Port);
public:
	inline Port() : _cntRef(1), _port(0) {}
protected:
	inline ~Port() {
		Reset();
		Close();
	}
public:
	static inline int GetNumDevs() {
		return ::MIDIGetNumberOfDevices();
	}
	inline bool Open(int id) {
		if (_port != 0) Close();
		MIDIClientRef client;
		char *portName;
		return ::MIDIOutputPortCreate(client, portName, &_port) == MMSYSERR_NOERROR;
	}
	inline void Close() {
		if (_port != NULL) ::MIDIPortDispose(&_port);
		_hMIDI = NULL;
	}
	inline void Reset() {
		if (_hMIDI != NULL) ::midiOutReset(_hMIDI);
	}
	inline void Send(UChar msg1) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0));
	}
	inline void Send(UChar msg1, UChar msg2) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8));
	}
	inline void Send(UChar msg1, UChar msg2, UChar msg3) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8) +
					(static_cast<DWORD>(msg3) << 16));
	}
	inline void Send(UChar msg1, UChar msg2, UChar msg3,
					UChar msg4) {
		::midiOutShortMsg(_hMIDI,
					(static_cast<DWORD>(msg1) << 0) +
					(static_cast<DWORD>(msg2) << 8) +
					(static_cast<DWORD>(msg3) << 16) +
					(static_cast<DWORD>(msg4) << 24));
	}
};

#else

#error unknown platform

#endif

Gura_EndModuleScope(midi)

#endif
