#ifndef __MIDIHANDLE_H__
#define __MIDIHANDLE_H__

//-----------------------------------------------------------------------------
// MIDIHandle
//-----------------------------------------------------------------------------
class MIDIHandle {
private:
	HMIDIOUT _hMIDI;
public:
	inline MIDIHandle() : _hMIDI(NULL) {}
	inline ~MIDIHandle() {
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
	void MMLPlay(const char *mml);
};

#endif
