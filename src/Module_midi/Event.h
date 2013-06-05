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
	enum { NUM_CHANNELS = 16 };
	class TimeStampManager {
	private:
		unsigned long _timeStampTbl[NUM_CHANNELS];
		unsigned long _timeStampSysEx;
		unsigned long _timeStampMeta;
	public:
		TimeStampManager();
		unsigned long UpdateDelta(unsigned char status, unsigned long timeDelta);
		unsigned long UpdateTimeStamp(unsigned char channel, unsigned long timeStamp);
		unsigned long UpdateTimeStampSysEx(unsigned long timeStamp);
		unsigned long UpdateTimeStampMeta(unsigned long timeStamp);
	};
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
	virtual bool IsMIDIEvent() const;
	virtual bool IsSysExEvent() const;
	virtual bool IsMetaEvent() const;
	virtual unsigned long UpdateTimeStamp(TimeStampManager &timeStampManager) const = 0;
	virtual bool Play(Signal sig, Port *pPort) const = 0;
	virtual bool Write(Signal sig, Stream &stream) const = 0;
	virtual String ToString() const = 0;
	virtual Event *Clone() const = 0;
	static bool WriteVariableFormat(Signal sig, Stream &stream, unsigned long num);
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
	virtual bool IsMIDIEvent() const;
	virtual unsigned long UpdateTimeStamp(TimeStampManager &timeStampManager) const;
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
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

//-----------------------------------------------------------------------------
// SysExEvent
//-----------------------------------------------------------------------------
class SysExEvent : public Event {
private:
	Binary _binary;
public:
	inline SysExEvent(const SysExEvent &event) : Event(event), _binary(event._binary) {}
	inline SysExEvent(unsigned long timeStamp, const Binary &binary) :
									Event(timeStamp), _binary(binary) {}
	virtual bool IsSysExEvent() const;
	virtual unsigned long UpdateTimeStamp(TimeStampManager &timeStampManager) const;
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent
//-----------------------------------------------------------------------------
class MetaEvent : public Event {
protected:
	unsigned char _eventType;
public:
	inline MetaEvent(const MetaEvent &event) : Event(event), _eventType(event._eventType) {}
	inline MetaEvent(unsigned long timeStamp, unsigned char eventType) :
								Event(timeStamp), _eventType(eventType) {}
	inline unsigned char GetEventType() const { return _eventType; }
	virtual bool Prepare(Signal sig, const Binary &binary) = 0;
	virtual bool IsMetaEvent() const;
	virtual unsigned long UpdateTimeStamp(TimeStampManager &timeStampManager) const;
	static bool Add(Signal sig, EventOwner &eventOwner, unsigned long timeStamp,
			unsigned char eventType, const Binary &binary);
	static void SetError_TooShortMetaEvent(Signal sig);
};

//-----------------------------------------------------------------------------
// MetaEvent_Unknown
//-----------------------------------------------------------------------------
class MetaEvent_Unknown : public MetaEvent {
private:
	Binary _binary;
public:
	inline MetaEvent_Unknown(const MetaEvent_Unknown &event) : MetaEvent(event),
										_binary(event._binary) {}
	inline MetaEvent_Unknown(unsigned long timeStamp, unsigned char eventType) :
										MetaEvent(timeStamp, eventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_SequenceNumber
//-----------------------------------------------------------------------------
class MetaEvent_SequenceNumber : public MetaEvent {
public:
	enum { EventType = 0x00 };
private:
	unsigned short _number;
public:
	inline MetaEvent_SequenceNumber(const MetaEvent_SequenceNumber &event) : MetaEvent(event),
										_number(event._number) {}
	inline MetaEvent_SequenceNumber(unsigned long timeStamp) :
								MetaEvent(timeStamp, EventType), _number(0) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_TextEvent
//-----------------------------------------------------------------------------
class MetaEvent_TextEvent : public MetaEvent {
public:
	enum { EventType = 0x01 };
private:
	String _text;
public:
	inline MetaEvent_TextEvent(const MetaEvent_TextEvent &event) : MetaEvent(event),
										_text(event._text) {}
	inline MetaEvent_TextEvent(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_CopyrightNotice
//-----------------------------------------------------------------------------
class MetaEvent_CopyrightNotice : public MetaEvent {
public:
	enum { EventType = 0x02 };
private:
	String _text;
public:
	inline MetaEvent_CopyrightNotice(const MetaEvent_CopyrightNotice &event) : MetaEvent(event),
										_text(event._text) {}
	inline MetaEvent_CopyrightNotice(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_SequenceOrTrackName
//-----------------------------------------------------------------------------
class MetaEvent_SequenceOrTrackName : public MetaEvent {
public:
	enum { EventType = 0x03 };
private:
	String _text;
public:
	inline MetaEvent_SequenceOrTrackName(const MetaEvent_SequenceOrTrackName &event) : MetaEvent(event),
										_text(event._text) {}
	inline MetaEvent_SequenceOrTrackName(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_InstrumentName
//-----------------------------------------------------------------------------
class MetaEvent_InstrumentName : public MetaEvent {
public:
	enum { EventType = 0x04 };
private:
	String _text;
public:
	inline MetaEvent_InstrumentName(const MetaEvent_InstrumentName &event) : MetaEvent(event),
										_text(event._text) {}
	inline MetaEvent_InstrumentName(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_LyricText
//-----------------------------------------------------------------------------
class MetaEvent_LyricText : public MetaEvent {
public:
	enum { EventType = 0x05 };
private:
	String _text;
public:
	inline MetaEvent_LyricText(const MetaEvent_LyricText &event) : MetaEvent(event),
										_text(event._text) {}
	inline MetaEvent_LyricText(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_MarkerText
//-----------------------------------------------------------------------------
class MetaEvent_MarkerText : public MetaEvent {
public:
	enum { EventType = 0x06 };
private:
	String _text;
public:
	inline MetaEvent_MarkerText(const MetaEvent_MarkerText &event) : MetaEvent(event),
										_text(event._text) {}
	inline MetaEvent_MarkerText(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_CuePoint
//-----------------------------------------------------------------------------
class MetaEvent_CuePoint : public MetaEvent {
public:
	enum { EventType = 0x07 };
private:
	String _text;
public:
	inline MetaEvent_CuePoint(const MetaEvent_CuePoint &event) : MetaEvent(event),
										_text(event._text) {}
	inline MetaEvent_CuePoint(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_MIDIChannelPrefixAssignment
//-----------------------------------------------------------------------------
class MetaEvent_MIDIChannelPrefixAssignment : public MetaEvent {
public:
	enum { EventType = 0x20 };
public:
	unsigned char _channel;
public:
	inline MetaEvent_MIDIChannelPrefixAssignment(const MetaEvent_MIDIChannelPrefixAssignment &event) : MetaEvent(event),
										_channel(event._channel) {}
	inline MetaEvent_MIDIChannelPrefixAssignment(unsigned long timeStamp) :
								MetaEvent(timeStamp, EventType), _channel(0) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_EndOfTrack
//-----------------------------------------------------------------------------
class MetaEvent_EndOfTrack : public MetaEvent {
public:
	enum { EventType = 0x2f };
public:
	inline MetaEvent_EndOfTrack(const MetaEvent_EndOfTrack &event) : MetaEvent(event) {}
 		inline MetaEvent_EndOfTrack(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_TempoSetting
//-----------------------------------------------------------------------------
class MetaEvent_TempoSetting : public MetaEvent {
public:
	enum { EventType = 0x51 };
private:
	unsigned long _mpqn;
public:
	inline MetaEvent_TempoSetting(const MetaEvent_TempoSetting &event) : MetaEvent(event),
										_mpqn(event._mpqn) {}
	inline MetaEvent_TempoSetting(unsigned long timeStamp) :
									MetaEvent(timeStamp, EventType), _mpqn(0) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_SMPTEOffset
//-----------------------------------------------------------------------------
class MetaEvent_SMPTEOffset : public MetaEvent {
public:
	enum { EventType = 0x54 };
private:
	unsigned char _hour, _minute, _second, _frame, _subFrame;
public:
	inline MetaEvent_SMPTEOffset(const MetaEvent_SMPTEOffset &event) : MetaEvent(event),
			_hour(event._hour), _minute(event._minute), _second(event._second),
			_frame(event._frame), _subFrame(event._subFrame) {}
	inline MetaEvent_SMPTEOffset(unsigned long timeStamp) :
			MetaEvent(timeStamp, EventType), _hour(0), _minute(0), _second(0),
			_frame(0), _subFrame(0) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_TimeSignature
//-----------------------------------------------------------------------------
class MetaEvent_TimeSignature : public MetaEvent {
public:
	enum { EventType = 0x58 };
private:
	unsigned char _numerator, _denominator;
	unsigned char _metronome, _cnt32nd;
public:
	inline MetaEvent_TimeSignature(const MetaEvent_TimeSignature &event) : MetaEvent(event),
			_numerator(event._numerator), _denominator(event._denominator),
			_metronome(event._metronome), _cnt32nd(event._cnt32nd) {}
	inline MetaEvent_TimeSignature(unsigned long timeStamp) :
			MetaEvent(timeStamp, EventType), _numerator(0), _denominator(0),
			_metronome(0), _cnt32nd(0) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_KeySignature
//-----------------------------------------------------------------------------
class MetaEvent_KeySignature : public MetaEvent {
public:
	enum { EventType = 0x59 };
private:
	unsigned char _key, _scale;
public:
	inline MetaEvent_KeySignature(const MetaEvent_KeySignature &event) : MetaEvent(event),
							_key(event._key), _scale(event._scale) {}
	inline MetaEvent_KeySignature(unsigned long timeStamp) :
					MetaEvent(timeStamp, EventType), _key(0), _scale(0) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent_SequencerSpecificEvent
//-----------------------------------------------------------------------------
class MetaEvent_SequencerSpecificEvent : public MetaEvent {
public:
	enum { EventType = 0x7f };
private:
	Binary _binary;
public:
	inline MetaEvent_SequencerSpecificEvent(const MetaEvent_SequencerSpecificEvent &event) : MetaEvent(event),
										_binary(event._binary) {}
	inline MetaEvent_SequencerSpecificEvent(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Port *pPort) const;
	virtual bool Write(Signal sig, Stream &stream) const;
	virtual String ToString() const;
	virtual Event *Clone() const;
};

}}

#endif
