#ifndef __EVENT_H__
#define __EVENT_H__
#include <gura.h>

Gura_BeginModule(midi)

class Port;

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------
class Event {
public:
	Gura_DeclareReferenceAccessor(Event);
protected:
	int _cntRef;
	unsigned long _timeStamp;
public:
	inline Event(const Event &event) : _cntRef(1), _timeStamp(event._timeStamp) {}
	inline Event(unsigned long timeStamp) : _cntRef(1), _timeStamp(timeStamp) {}
protected:
	virtual ~Event();
public:
	inline unsigned long GetTimeStamp() const { return _timeStamp; }
	virtual bool Play(Signal sig, Port *pPort) const = 0;
	virtual bool Serialize(Signal sig, Stream &stream) const = 0;
	virtual String ToString() const = 0;
	virtual Event *Clone() const = 0;
};

//-----------------------------------------------------------------------------
// EventList
//-----------------------------------------------------------------------------
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
	bool Play(Signal sig, Port *pPort, double deltaTimeUnit) const;
	bool Write(Signal sig, Stream &stream) const;
};

//-----------------------------------------------------------------------------
// EventOwner
//-----------------------------------------------------------------------------
class EventOwner : public EventList {
public:
	~EventOwner();
	void Clear();
	bool AddMetaEvent(Signal sig, unsigned long timeStamp,
			unsigned char eventType, const unsigned char buff[], size_t length);
};

//-----------------------------------------------------------------------------
// MIDIEvent
//-----------------------------------------------------------------------------
class MIDIEvent : public Event {
protected:
	unsigned char _status;
	unsigned char _channel;
	size_t _nParams;
	unsigned char _params[2];
public:
	inline MIDIEvent(const MIDIEvent &event) : Event(event),
			_status(event._status), _channel(event._channel), _nParams(event._nParams) {
		::memcpy(_params, event._params, sizeof(_params));
	}
	inline MIDIEvent(unsigned long timeStamp, unsigned char status, unsigned char channel, size_t nParams) :
			Event(timeStamp), _status(status), _channel(channel), _nParams(nParams) {}
	inline unsigned char GetStatus() const { return _status; }
	inline unsigned char GetChannel() const { return _channel; }
	inline void SetParam1st(unsigned char param) { _params[0] = param; }
	inline void SetParam2nd(unsigned char param) { _params[1] = param; }
	inline size_t CountParams() const { return _nParams; }
	static bool CheckStatus(unsigned char status) {
		return 0x80 <= status && status < 0xf0;
	}
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Serialize(Signal sig, Stream &stream) const;
};

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOff
//-----------------------------------------------------------------------------
class MIDIEvent_NoteOff : public MIDIEvent {
public:
	enum { Status = 0x80 };
public:
	inline MIDIEvent_NoteOff(const MIDIEvent_NoteOff &event) : MIDIEvent(event) {}
	inline MIDIEvent_NoteOff(unsigned long timeStamp, unsigned char channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	inline MIDIEvent_NoteOff(unsigned long timeStamp, unsigned char channel,
							unsigned char note, unsigned char velocity) :
									MIDIEvent(timeStamp, Status, channel, 2) {
		_params[0] = note, _params[1] = velocity;
	}
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOn
//-----------------------------------------------------------------------------
class MIDIEvent_NoteOn : public MIDIEvent {
public:
	enum { Status = 0x90 };
public:
	inline MIDIEvent_NoteOn(const MIDIEvent_NoteOn &event) : MIDIEvent(event) {}
	inline MIDIEvent_NoteOn(unsigned long timeStamp, unsigned char channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	inline MIDIEvent_NoteOn(unsigned long timeStamp, unsigned char channel,
							unsigned char note, unsigned char velocity) :
									MIDIEvent(timeStamp, Status, channel, 2) {
		_params[0] = note, _params[1] = velocity;
	}
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MIDIEvent_PolyphonicKeyPressure
//-----------------------------------------------------------------------------
class MIDIEvent_PolyphonicKeyPressure : public MIDIEvent {
public:
	enum { Status = 0xa0 };
public:
	inline MIDIEvent_PolyphonicKeyPressure(const MIDIEvent_PolyphonicKeyPressure &event) : MIDIEvent(event) {}
	inline MIDIEvent_PolyphonicKeyPressure(unsigned long timeStamp, unsigned char channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MIDIEvent_ControlChange
//-----------------------------------------------------------------------------
class MIDIEvent_ControlChange : public MIDIEvent {
public:
	enum { Status = 0xb0 };
public:
	inline MIDIEvent_ControlChange(const MIDIEvent_ControlChange &event) : MIDIEvent(event) {}
	inline MIDIEvent_ControlChange(unsigned long timeStamp, unsigned char channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MIDIEvent_ProgramChange
//-----------------------------------------------------------------------------
class MIDIEvent_ProgramChange : public MIDIEvent {
public:
	enum { Status = 0xc0 };
public:
	inline MIDIEvent_ProgramChange(const MIDIEvent_ProgramChange &event) : MIDIEvent(event) {}
	inline MIDIEvent_ProgramChange(unsigned long timeStamp, unsigned char channel) :
									MIDIEvent(timeStamp, Status, channel, 1) {}
	inline MIDIEvent_ProgramChange(unsigned long timeStamp, unsigned char channel, unsigned char program) :
									MIDIEvent(timeStamp, Status, channel, 1) {
		_params[0] = program;
	}
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MIDIEvent_ChannelPressure
//-----------------------------------------------------------------------------
class MIDIEvent_ChannelPressure : public MIDIEvent {
public:
	enum { Status = 0xd0 };
public:
	inline MIDIEvent_ChannelPressure(const MIDIEvent_ChannelPressure &event) : MIDIEvent(event) {}
	inline MIDIEvent_ChannelPressure(unsigned long timeStamp, unsigned char channel) :
									MIDIEvent(timeStamp, Status, channel, 1) {}
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MIDIEvent_PitchBendChange
//-----------------------------------------------------------------------------
class MIDIEvent_PitchBendChange : public MIDIEvent {
public:
	enum { Status = 0xe0 };
public:
	inline MIDIEvent_PitchBendChange(const MIDIEvent_PitchBendChange &event) : MIDIEvent(event) {}
	inline MIDIEvent_PitchBendChange(unsigned long timeStamp, unsigned char channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	virtual String ToString() const;
	virtual Event *Clone() const;
};

}}

#endif
