#ifndef __PORT_H__
#define __PORT_H__
#include <gura.h>

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
	int _fd;
public:
	inline Port() : _fd(-1) {}
	inline ~Port() {
		Reset();
		Close();
	}
	static inline int GetNumDevs() {
		return 0;
	}
	inline bool Open(int id) {
		if (_fd >= 0) Close();
		char devName[128];
		::sprintf(devName, "/dev/midi%d", id);
		_fd = ::open(devName, O_WRONLY);
		return _fd >= 0;
	}
	inline void Close() {
		if (_fd >= 0) ::close(fd);
		_fd = -1;
	}
	inline void Reset() {
		//if (_fd >= 0) ::ctrl();
	}
	inline void Send(unsigned char msg1) {
		unsigned char buff[1] = { msg1 };
		::write(_fd, buff, sizeof(buff));
	}
	inline void Send(unsigned char msg1, unsigned char msg2) {
		unsigned char buff[2] = { msg1, msg2 };
		::write(_fd, buff, sizeof(buff));
	}
	inline void Send(unsigned char msg1, unsigned char msg2, unsigned char msg3) {
		unsigned char buff[3] = { msg1, msg2, msg3 };
		::write(_fd, buff, sizeof(buff));
	}
	inline void Send(unsigned char msg1, unsigned char msg2, unsigned char msg3,
					unsigned char msg4) {
		unsigned char buff[4] = { msg1, msg2, msg3, msg4 };
		::write(_fd, buff, sizeof(buff));
	}
};

#else

#error unknown platform

#endif

}}

#endif
