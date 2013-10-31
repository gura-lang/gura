#ifndef __EVENT_H__
#define __EVENT_H__
#include <gura.h>

Gura_BeginModuleScope(midi)

class Track;
class EventList;
class Player;

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------
class Event {
public:
	Gura_DeclareReferenceAccessor(Event);
protected:
	int _cntRef;
	bool _enableRunningStatus;
	ULong _timeStamp;
public:
	inline Event(const Event &event) : _cntRef(1),
		_enableRunningStatus(event._enableRunningStatus), _timeStamp(event._timeStamp) {}
	inline Event(bool enableRunningStatus, ULong timeStamp) : _cntRef(1),
		_enableRunningStatus(enableRunningStatus), _timeStamp(timeStamp) {}
protected:
	virtual ~Event();
public:
	inline void EnableRunningStatus(bool enableRunningStatus) {
		_enableRunningStatus = enableRunningStatus;
	}
	inline bool IsEnabledRunningStatus() const { return _enableRunningStatus; }
	inline ULong GetTimeStamp() const { return _timeStamp; }
	inline void SetTimeStamp(ULong timeStamp) { _timeStamp = timeStamp; }
	virtual bool IsMIDIEvent() const;
	virtual bool IsSysExEvent() const;
	virtual bool IsMetaEvent() const;
	virtual UChar GetStatusCode() const = 0;
	virtual const Symbol *GetSymbol() const = 0;
	virtual String GetArgsName() const = 0;
	virtual bool Play(Signal sig, Player *pPlayer) const = 0;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const = 0;
	virtual Event *Clone() const = 0;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	static bool WriteVariableFormat(Signal sig, Stream &stream, ULong num);
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
	bool Write(Signal sig, Stream &stream) const;
};

//-----------------------------------------------------------------------------
// EventOwner
//-----------------------------------------------------------------------------
class EventOwner : public EventList {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(EventOwner);
public:
	inline EventOwner() : _cntRef(1) {}
protected:
	~EventOwner();
public:
	void Clear();
	void AddEvents(const EventList &eventList);
};

//-----------------------------------------------------------------------------
// MIDIEvent
//-----------------------------------------------------------------------------
class MIDIEvent : public Event {
protected:
	UChar _status;
	UChar _channel;
	size_t _nParams;
	UChar _params[2];
public:
	inline MIDIEvent(const MIDIEvent &event) : Event(event),
			_status(event._status), _channel(event._channel), _nParams(event._nParams) {
		::memcpy(_params, event._params, sizeof(_params));
	}
	inline MIDIEvent(ULong timeStamp, UChar status, UChar channel, size_t nParams) :
			Event(true, timeStamp),
			_status(status), _channel(channel), _nParams(nParams) {}
	inline UChar GetStatus() const { return _status; }
	inline UChar GetChannel() const { return _channel; }
	inline UChar GetStatusByte() const { return _status | _channel; }
	inline void SetParam1st(UChar param) { _params[0] = param; }
	inline void SetParam2nd(UChar param) { _params[1] = param; }
	inline size_t CountParams() const { return _nParams; }
	static bool CheckStatus(UChar status) {
		return 0x80 <= status && status < 0xf0;
	}
	virtual bool IsMIDIEvent() const;
	virtual UChar GetStatusCode() const;
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOff
//-----------------------------------------------------------------------------
class MIDIEvent_NoteOff : public MIDIEvent {
public:
	enum { Status = 0x80 };
public:
	inline MIDIEvent_NoteOff(const MIDIEvent_NoteOff &event) : MIDIEvent(event) {}
	inline MIDIEvent_NoteOff(ULong timeStamp, UChar channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	inline MIDIEvent_NoteOff(ULong timeStamp, UChar channel,
							UChar note, UChar velocity) :
									MIDIEvent(timeStamp, Status, channel, 2) {
		_params[0] = note, _params[1] = velocity;
	}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline UChar GetNote() const { return _params[0]; }
	inline UChar GetVelocity() const { return _params[1]; }
	inline void SetNote(UChar note) { _params[0] = note; }
	inline void SetVelocity(UChar velocity) { _params[1] = velocity; }
};

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOn
//-----------------------------------------------------------------------------
class MIDIEvent_NoteOn : public MIDIEvent {
public:
	enum { Status = 0x90 };
public:
	inline MIDIEvent_NoteOn(const MIDIEvent_NoteOn &event) : MIDIEvent(event) {}
	inline MIDIEvent_NoteOn(ULong timeStamp, UChar channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	inline MIDIEvent_NoteOn(ULong timeStamp, UChar channel,
							UChar note, UChar velocity) :
									MIDIEvent(timeStamp, Status, channel, 2) {
		_params[0] = note, _params[1] = velocity;
	}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline UChar GetNote() const { return _params[0]; }
	inline UChar GetVelocity() const { return _params[1]; }
	inline void SetNote(UChar note) { _params[0] = note; }
	inline void SetVelocity(UChar velocity) { _params[1] = velocity; }
};

//-----------------------------------------------------------------------------
// MIDIEvent_PolyPressure
//-----------------------------------------------------------------------------
class MIDIEvent_PolyPressure : public MIDIEvent {
public:
	enum { Status = 0xa0 };
public:
	inline MIDIEvent_PolyPressure(const MIDIEvent_PolyPressure &event) : MIDIEvent(event) {}
	inline MIDIEvent_PolyPressure(ULong timeStamp, UChar channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	inline MIDIEvent_PolyPressure(ULong timeStamp, UChar channel,
							UChar note, UChar value) :
									MIDIEvent(timeStamp, Status, channel, 2) {
		_params[0] = note, _params[1] = value;
	}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline UChar GetNote() const { return _params[0]; }
	inline UChar GetValue() const { return _params[1]; }
	inline void SetNote(UChar note) { _params[0] = note; }
	inline void SetValue(UChar value) { _params[1] = value; }
};

//-----------------------------------------------------------------------------
// MIDIEvent_ControlChange
//-----------------------------------------------------------------------------
class MIDIEvent_ControlChange : public MIDIEvent {
public:
	enum { Status = 0xb0 };
public:
	inline MIDIEvent_ControlChange(const MIDIEvent_ControlChange &event) : MIDIEvent(event) {}
	inline MIDIEvent_ControlChange(ULong timeStamp, UChar channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	inline MIDIEvent_ControlChange(ULong timeStamp, UChar channel,
							UChar controller, UChar value) :
									MIDIEvent(timeStamp, Status, channel, 2) {
		_params[0] = controller, _params[1] = value;
	}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline UChar GetController() const { return _params[0]; }
	inline UChar GetValue() const { return _params[1]; }
	inline void SetController(UChar controller) { _params[0] = controller; }
	inline void SetValue(UChar value) { _params[1] = value; }
};

//-----------------------------------------------------------------------------
// MIDIEvent_ProgramChange
//-----------------------------------------------------------------------------
class MIDIEvent_ProgramChange : public MIDIEvent {
public:
	enum { Status = 0xc0 };
public:
	inline MIDIEvent_ProgramChange(const MIDIEvent_ProgramChange &event) : MIDIEvent(event) {}
	inline MIDIEvent_ProgramChange(ULong timeStamp, UChar channel) :
									MIDIEvent(timeStamp, Status, channel, 1) {}
	inline MIDIEvent_ProgramChange(ULong timeStamp, UChar channel, UChar program) :
									MIDIEvent(timeStamp, Status, channel, 1) {
		_params[0] = program;
	}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline UChar GetProgram() const { return _params[0]; }
	inline void SetProgram(UChar program) { _params[0] = program; }
};

//-----------------------------------------------------------------------------
// MIDIEvent_ChannelPressure
//-----------------------------------------------------------------------------
class MIDIEvent_ChannelPressure : public MIDIEvent {
public:
	enum { Status = 0xd0 };
public:
	inline MIDIEvent_ChannelPressure(const MIDIEvent_ChannelPressure &event) : MIDIEvent(event) {}
	inline MIDIEvent_ChannelPressure(ULong timeStamp, UChar channel) :
									MIDIEvent(timeStamp, Status, channel, 1) {}
	inline MIDIEvent_ChannelPressure(ULong timeStamp, UChar channel, UChar pressure) :
									MIDIEvent(timeStamp, Status, channel, 1) {
		_params[0] = pressure;
	}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline UChar GetPressure() const { return _params[0]; }
	inline void SetPressure(UChar pressure) { _params[0] = pressure; }
};

//-----------------------------------------------------------------------------
// MIDIEvent_PitchBend
//-----------------------------------------------------------------------------
class MIDIEvent_PitchBend : public MIDIEvent {
public:
	enum { Status = 0xe0 };
public:
	inline MIDIEvent_PitchBend(const MIDIEvent_PitchBend &event) : MIDIEvent(event) {}
	inline MIDIEvent_PitchBend(ULong timeStamp, UChar channel) :
									MIDIEvent(timeStamp, Status, channel, 2) {}
	inline MIDIEvent_PitchBend(ULong timeStamp, UChar channel, UShort value) :
									MIDIEvent(timeStamp, Status, channel, 2) {
		_params[0] = static_cast<UChar>((value >> 0) & 0x7f);
		_params[1] = static_cast<UChar>((value >> 7) & 0x7f);
	}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	inline UShort GetValue() const {
		return (static_cast<UShort>(_params[0]) << 0) +
				(static_cast<UShort>(_params[1]) << 7);
	}
	inline void SetValue(UShort value) {
		_params[0] = static_cast<UChar>((value >> 0) & 0x7f);
		_params[1] = static_cast<UChar>((value >> 7) & 0x7f);
	}
};

//-----------------------------------------------------------------------------
// SysExEvent
//-----------------------------------------------------------------------------
class SysExEvent : public Event {
public:
	enum { StatusF0 = 0xf0, StatusF7 = 0xf7 };
private:
	Binary _binary;
public:
	inline SysExEvent(const SysExEvent &event) : Event(event), _binary(event._binary) {}
	inline SysExEvent(ULong timeStamp, const Binary &binary) :
								Event(false, timeStamp), _binary(binary) {}
	virtual bool IsSysExEvent() const;
	virtual UChar GetStatusCode() const;
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Event *Clone() const;
};

//-----------------------------------------------------------------------------
// MetaEvent
//-----------------------------------------------------------------------------
class MetaEvent : public Event {
public:
	enum { Status = 0xff };
protected:
	UChar _eventType;
public:
	inline MetaEvent(const MetaEvent &event) : Event(event), _eventType(event._eventType) {}
	inline MetaEvent(ULong timeStamp, UChar eventType) :
								Event(false, timeStamp), _eventType(eventType) {}
	inline UChar GetEventType() const { return _eventType; }
	virtual bool Prepare(Signal sig, const Binary &binary) = 0;
	virtual bool IsMetaEvent() const;
	virtual UChar GetStatusCode() const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	static bool Add(Signal sig, Track *pTrack, bool enableRunningStatus,
			ULong timeStamp, UChar eventType, const Binary &binary);
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
	inline MetaEvent_Unknown(ULong timeStamp, UChar eventType) :
										MetaEvent(timeStamp, eventType) {}
	inline MetaEvent_Unknown(ULong timeStamp, UChar eventType, const Binary &binary) :
										MetaEvent(timeStamp, eventType), _binary(binary) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// MetaEvent_SequenceNumber
//-----------------------------------------------------------------------------
class MetaEvent_SequenceNumber : public MetaEvent {
public:
	enum { EventType = 0x00 };
private:
	UShort _number;
public:
	inline MetaEvent_SequenceNumber(const MetaEvent_SequenceNumber &event) : MetaEvent(event),
										_number(event._number) {}
	inline MetaEvent_SequenceNumber(ULong timeStamp) :
								MetaEvent(timeStamp, EventType), _number(0) {}
	inline MetaEvent_SequenceNumber(ULong timeStamp, UShort number) :
								MetaEvent(timeStamp, EventType), _number(number) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline MetaEvent_TextEvent(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline MetaEvent_TextEvent(ULong timeStamp, const String &text) :
										MetaEvent(timeStamp, EventType), _text(text) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline MetaEvent_CopyrightNotice(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline MetaEvent_CopyrightNotice(ULong timeStamp, const String &text) :
										MetaEvent(timeStamp, EventType), _text(text) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline MetaEvent_SequenceOrTrackName(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline MetaEvent_SequenceOrTrackName(ULong timeStamp, const String &text) :
										MetaEvent(timeStamp, EventType), _text(text) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline MetaEvent_InstrumentName(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline MetaEvent_InstrumentName(ULong timeStamp, const String &text) :
										MetaEvent(timeStamp, EventType), _text(text) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline MetaEvent_LyricText(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline MetaEvent_LyricText(ULong timeStamp, const String &text) :
										MetaEvent(timeStamp, EventType), _text(text) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline MetaEvent_MarkerText(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline MetaEvent_MarkerText(ULong timeStamp, const String &text) :
										MetaEvent(timeStamp, EventType), _text(text) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline MetaEvent_CuePoint(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline MetaEvent_CuePoint(ULong timeStamp, const String &text) :
										MetaEvent(timeStamp, EventType), _text(text) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// MetaEvent_MIDIChannelPrefixAssignment
//-----------------------------------------------------------------------------
class MetaEvent_MIDIChannelPrefixAssignment : public MetaEvent {
public:
	enum { EventType = 0x20 };
public:
	UChar _channel;
public:
	inline MetaEvent_MIDIChannelPrefixAssignment(const MetaEvent_MIDIChannelPrefixAssignment &event) : MetaEvent(event),
										_channel(event._channel) {}
	inline MetaEvent_MIDIChannelPrefixAssignment(ULong timeStamp) :
								MetaEvent(timeStamp, EventType), _channel(0) {}
	inline MetaEvent_MIDIChannelPrefixAssignment(ULong timeStamp, UChar channel) :
								MetaEvent(timeStamp, EventType), _channel(channel) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// MetaEvent_EndOfTrack
//-----------------------------------------------------------------------------
class MetaEvent_EndOfTrack : public MetaEvent {
public:
	enum { EventType = 0x2f };
public:
	inline MetaEvent_EndOfTrack(const MetaEvent_EndOfTrack &event) : MetaEvent(event) {}
	inline MetaEvent_EndOfTrack(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline static bool CheckEvent(const Event *pEvent) {
		return pEvent != NULL && pEvent->IsMetaEvent() &&
			dynamic_cast<const MetaEvent *>(pEvent)->GetEventType() == EventType;
	}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// MetaEvent_TempoSetting
//-----------------------------------------------------------------------------
class MetaEvent_TempoSetting : public MetaEvent {
public:
	enum { EventType = 0x51 };
private:
	ULong _mpqn;	// usec / quarter-note
public:
	inline MetaEvent_TempoSetting(const MetaEvent_TempoSetting &event) : MetaEvent(event),
										_mpqn(event._mpqn) {}
	inline MetaEvent_TempoSetting(ULong timeStamp) :
									MetaEvent(timeStamp, EventType), _mpqn(0) {}
	inline MetaEvent_TempoSetting(ULong timeStamp, ULong mpqn) :
									MetaEvent(timeStamp, EventType), _mpqn(mpqn) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// MetaEvent_SMPTEOffset
//-----------------------------------------------------------------------------
class MetaEvent_SMPTEOffset : public MetaEvent {
public:
	enum { EventType = 0x54 };
private:
	UChar _hour, _minute, _second, _frame, _subFrame;
public:
	inline MetaEvent_SMPTEOffset(const MetaEvent_SMPTEOffset &event) : MetaEvent(event),
			_hour(event._hour), _minute(event._minute), _second(event._second),
			_frame(event._frame), _subFrame(event._subFrame) {}
	inline MetaEvent_SMPTEOffset(ULong timeStamp) :
			MetaEvent(timeStamp, EventType), _hour(0), _minute(0), _second(0),
			_frame(0), _subFrame(0) {}
	inline MetaEvent_SMPTEOffset(ULong timeStamp, UChar hour, UChar minute,
						UChar second, UChar frame, UChar subFrame) :
			MetaEvent(timeStamp, EventType), _hour(hour), _minute(minute), _second(second),
			_frame(frame), _subFrame(subFrame) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// MetaEvent_TimeSignature
//-----------------------------------------------------------------------------
class MetaEvent_TimeSignature : public MetaEvent {
public:
	enum { EventType = 0x58 };
private:
	UChar _numerator, _denominator;
	UChar _metronome, _cnt32nd;
public:
	inline MetaEvent_TimeSignature(const MetaEvent_TimeSignature &event) : MetaEvent(event),
			_numerator(event._numerator), _denominator(event._denominator),
			_metronome(event._metronome), _cnt32nd(event._cnt32nd) {}
	inline MetaEvent_TimeSignature(ULong timeStamp) :
			MetaEvent(timeStamp, EventType), _numerator(0), _denominator(0),
			_metronome(0), _cnt32nd(0) {}
	inline MetaEvent_TimeSignature(ULong timeStamp, UChar numerator,
				UChar denominator, UChar metronome, UChar cnt32nd) :
			MetaEvent(timeStamp, EventType), _numerator(numerator), _denominator(denominator),
			_metronome(metronome), _cnt32nd(cnt32nd) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// MetaEvent_KeySignature
//-----------------------------------------------------------------------------
class MetaEvent_KeySignature : public MetaEvent {
public:
	enum { EventType = 0x59 };
private:
	UChar _key, _scale;
public:
	inline MetaEvent_KeySignature(const MetaEvent_KeySignature &event) : MetaEvent(event),
							_key(event._key), _scale(event._scale) {}
	inline MetaEvent_KeySignature(ULong timeStamp) :
					MetaEvent(timeStamp, EventType), _key(0), _scale(0) {}
	inline MetaEvent_KeySignature(ULong timeStamp, UChar key, UChar scale) :
					MetaEvent(timeStamp, EventType), _key(key), _scale(scale) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
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
	inline MetaEvent_SequencerSpecificEvent(ULong timeStamp) :
										MetaEvent(timeStamp, EventType) {}
	inline MetaEvent_SequencerSpecificEvent(ULong timeStamp, const Binary &binary) :
										MetaEvent(timeStamp, EventType), _binary(binary) {}
	virtual const Symbol *GetSymbol() const;
	virtual String GetArgsName() const;
	virtual bool Prepare(Signal sig, const Binary &binary);
	virtual bool Play(Signal sig, Player *pPlayer) const;
	virtual bool Write(Signal sig, Stream &stream, const Event *pEventPrev) const;
	virtual Event *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
};

Gura_EndModuleScope(midi)

#endif
