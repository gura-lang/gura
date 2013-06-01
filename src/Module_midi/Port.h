#ifndef __PORT_H__
#define __PORT_H__
#include "MmlParser.h"
#include "SMFReader.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Port
//-----------------------------------------------------------------------------
class Port {
public:
	enum {
		NUM_CHANNELS = 16,
	};
	class Event {
	protected:
		unsigned long _timeStamp;
	public:
		inline Event(unsigned long timeStamp) : _timeStamp(timeStamp) {}
		inline unsigned long GetTimeStamp() const { return _timeStamp; }
		virtual bool Exec(Signal sig, Port *pPort) = 0;
	};
	class EventList : public std::vector<Event *> {
	public:
		class Comparator_TimeStamp {
		public:
			inline bool operator()(const Event *pEvent1, const Event *pEvent2) const {
				return pEvent1->GetTimeStamp() < pEvent2->GetTimeStamp();
			}
		};
	public:
		void Sort();
		bool Exec(Signal sig, Port *pPort);
	};
	class EventOwner : public EventList {
	public:
		~EventOwner();
		void Clear();
	};
	class MIDIEvent : public Event {
	private:
		unsigned char _msg1, _msg2, _msg3;
	public:
		inline MIDIEvent(unsigned long timeStamp,
					unsigned char msg1, unsigned char msg2, unsigned char msg3) :
			Event(timeStamp), _msg1(msg1), _msg2(msg2), _msg3(msg3) {}
		virtual bool Exec(Signal sig, Port *pPort);
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
	class SMFReaderEx : public SMFReader {
	private:
		EventOwner _eventOwner;
	public:
		inline SMFReaderEx() {}
		inline EventOwner &GetEventOwner() { return _eventOwner; }
		// virtual functions of SMFReader
		virtual void OnMIDIEvent(unsigned long deltaTime, unsigned char msg1,unsigned char msg2);
		virtual void OnMIDIEvent(unsigned long deltaTime, unsigned char msg1,unsigned char msg2, unsigned char msg3);
		virtual void OnSysExEvent(unsigned long deltaTime);
		virtual void OnMetaEvent(unsigned long deltaTime, unsigned char eventType, unsigned char data[], size_t length);
	};
private:
	HMIDIOUT _hMIDI;
	Channel *_pChannels[NUM_CHANNELS];
public:
	Port();
	~Port();
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
	bool Play(Signal sig, Stream &stream);
};

}}

#endif
