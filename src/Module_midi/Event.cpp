#include "Event.h"
#include "Content.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Event
//-----------------------------------------------------------------------------
bool Event::IsMIDIEvent() const { return false; }
bool Event::IsSysExEvent() const { return false; }
bool Event::IsMetaEvent() const { return false; }

Event::~Event()
{
	// virtual destructor
}

bool Event::WriteVariableFormat(Signal sig, Stream &stream, unsigned long num)
{
	unsigned char buff[32];
	unsigned char *p = buff + sizeof(buff);
	size_t bytes = 0;
	while (bytes < sizeof(buff)) {
		unsigned char data = static_cast<unsigned char>(num & 0x7f);
		if (bytes > 0) data |= 0x80;
		num >>= 7;
		p--, bytes++;
		*p = data;
		if (num == 0) break;
	}
	return stream.Write(sig, p, bytes) == bytes;
}

//-----------------------------------------------------------------------------
// Event::Player
//-----------------------------------------------------------------------------
Event::Player::Player(Port *pPort, unsigned short division, unsigned long mpqn) :
							_pPort(pPort), _division(division), _mpqn(mpqn)
{
}

bool Event::Player::Play(Signal sig, const EventList &eventList)
{
	Event *pEventPrev = NULL;
	foreach_const (EventList, ppEvent, eventList) {
		Event *pEvent = *ppEvent;
		if (pEventPrev != NULL &&
					pEventPrev->GetTimeStamp() < pEvent->GetTimeStamp()) {
			unsigned long deltaTime =
					pEvent->GetTimeStamp() - pEventPrev->GetTimeStamp();
			double delayTime = static_cast<double>(_mpqn) *
										deltaTime / _division / 1000000;
			OAL::Sleep(delayTime);
		}
		if (!pEvent->Play(sig, this)) return false;
		pEventPrev = pEvent;
	}
	return true;
}

//-----------------------------------------------------------------------------
// EventList
//-----------------------------------------------------------------------------
void EventList::Sort()
{
	std::stable_sort(begin(), end(), Comparator_TimeStamp());
}

//-----------------------------------------------------------------------------
// EventOwner
//-----------------------------------------------------------------------------
EventOwner::~EventOwner()
{
	Clear();
}

void EventOwner::Clear()
{
	foreach (EventOwner, ppEvent, *this) {
		Event *pEvent = *ppEvent;
		Event::Delete(pEvent);
	}
	clear();
}

void EventOwner::AddEvents(const EventList &eventList)
{
	foreach_const (EventList, ppEvent, eventList) {
		Event *pEvent = *ppEvent;
		push_back(Event::Reference(pEvent));
	}
}

//-----------------------------------------------------------------------------
// MIDIEvent
//-----------------------------------------------------------------------------
bool MIDIEvent::IsMIDIEvent() const { return true; }

unsigned char MIDIEvent::GetStatusCode() const
{
	return _status | _channel;
}

bool MIDIEvent::Play(Signal sig, Player *pPlayer) const
{
	if (_nParams == 1) {
		pPlayer->GetPort()->Send(_status | _channel, _params[0]);
	} else {
		pPlayer->GetPort()->Send(_status | _channel, _params[0], _params[1]);
	}
	return true;
}

bool MIDIEvent::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	size_t bytes = 0;
	unsigned char buff[8];
	if (!IsEnabledRunningStatus() || pEventPrev == NULL || !pEventPrev->IsMIDIEvent() ||
			dynamic_cast<const MIDIEvent *>(pEventPrev)->GetStatusByte() != GetStatusByte()) {
		buff[bytes++] = GetStatusByte();
	}
	for (int i = 0; i < _nParams; i++) {
		buff[bytes++] = _params[i];
	}
	return stream.Write(sig, buff, bytes) == bytes;
}

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOff
//-----------------------------------------------------------------------------
String MIDIEvent_NoteOff::GetName() const
{
	return "NoteOff";
}

String MIDIEvent_NoteOff::GetArgsName() const
{
	char str[128];
	::sprintf(str, "channel:%d note:%d velocity:%d",
								GetChannel(), GetNote(), GetVelocity());
	return String(str);
}

Event *MIDIEvent_NoteOff::Clone() const
{
	return new MIDIEvent_NoteOff(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_NoteOn
//-----------------------------------------------------------------------------
String MIDIEvent_NoteOn::GetName() const
{
	return "NoteOn";
}

String MIDIEvent_NoteOn::GetArgsName() const
{
	char str[128];
	::sprintf(str, "channel:%d note:%d velocity:%d",
								GetChannel(), GetNote(), GetVelocity());
	return String(str);
}

Event *MIDIEvent_NoteOn::Clone() const
{
	return new MIDIEvent_NoteOn(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_PolyPressure
//-----------------------------------------------------------------------------
String MIDIEvent_PolyPressure::GetName() const
{
	return "PolyPressure";
}

String MIDIEvent_PolyPressure::GetArgsName() const
{
	char str[128];
	::sprintf(str, "channel:%d note:%d value:%d",
								GetChannel(), GetNote(), GetValue());
	return String(str);
}

Event *MIDIEvent_PolyPressure::Clone() const
{
	return new MIDIEvent_PolyPressure(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ControlChange
//-----------------------------------------------------------------------------
String MIDIEvent_ControlChange::GetName() const
{
	return "ControlChange";
}

String MIDIEvent_ControlChange::GetArgsName() const
{
	char str[128];
	::sprintf(str, "channel:%d controller:%d value:%d",
								GetChannel(), GetController(), GetValue());
	return String(str);
}

Event *MIDIEvent_ControlChange::Clone() const
{
	return new MIDIEvent_ControlChange(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ProgramChange
//-----------------------------------------------------------------------------
String MIDIEvent_ProgramChange::GetName() const
{
	return "ProgramChange";
}

String MIDIEvent_ProgramChange::GetArgsName() const
{
	char str[128];
	::sprintf(str, "channel:%d program:%d", GetChannel(), GetProgram());
	return String(str);
}

Event *MIDIEvent_ProgramChange::Clone() const
{
	return new MIDIEvent_ProgramChange(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_ChannelPressure
//-----------------------------------------------------------------------------
String MIDIEvent_ChannelPressure::GetName() const
{
	return "ChannelPressure";
}

String MIDIEvent_ChannelPressure::GetArgsName() const
{
	char str[128];
	::sprintf(str, "channel:%d pressure:%d", GetChannel(), GetPressure());
	return String(str);
}

Event *MIDIEvent_ChannelPressure::Clone() const
{
	return new MIDIEvent_ChannelPressure(*this);
}

//-----------------------------------------------------------------------------
// MIDIEvent_PitchBend
//-----------------------------------------------------------------------------
String MIDIEvent_PitchBend::GetName() const
{
	return "PitchBend";
}

String MIDIEvent_PitchBend::GetArgsName() const
{
	char str[128];
	::sprintf(str, "channel:%d value:%d", GetChannel(), GetValue());
	return String(str);
}

Event *MIDIEvent_PitchBend::Clone() const
{
	return new MIDIEvent_PitchBend(*this);
}

//-----------------------------------------------------------------------------
// SysExEvent
//-----------------------------------------------------------------------------
bool SysExEvent::IsSysExEvent() const { return true; }

unsigned char SysExEvent::GetStatusCode() const
{
	return static_cast<unsigned char>(_binary[0]);
}

String SysExEvent::GetName() const
{
	return "SysExEvent";
}

String SysExEvent::GetArgsName() const
{
	char str[128];
	::sprintf(str, "%dbytes", _binary.size());
	return String(str);
}

bool SysExEvent::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool SysExEvent::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	return stream.Write(sig, _binary.data(), _binary.size()) == _binary.size();
}

Event *SysExEvent::Clone() const
{
	return new SysExEvent(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent
//-----------------------------------------------------------------------------
bool MetaEvent::IsMetaEvent() const { return true; }

unsigned char MetaEvent::GetStatusCode() const
{
	return Status;
}

bool MetaEvent::Add(Signal sig, EventOwner &eventOwner, unsigned long timeStamp,
							unsigned char eventType, const Binary &binary)
{
	MetaEvent *pEvent = NULL;
	if (eventType == MetaEvent_SequenceNumber::EventType) {
		pEvent = new MetaEvent_SequenceNumber(timeStamp);
	} else if (eventType == MetaEvent_TextEvent::EventType) {
		pEvent = new MetaEvent_TextEvent(timeStamp);
	} else if (eventType == MetaEvent_CopyrightNotice::EventType) {
		pEvent = new MetaEvent_CopyrightNotice(timeStamp);
	} else if (eventType == MetaEvent_SequenceOrTrackName::EventType) {
		pEvent = new MetaEvent_SequenceOrTrackName(timeStamp);
	} else if (eventType == MetaEvent_InstrumentName::EventType) {
		pEvent = new MetaEvent_InstrumentName(timeStamp);
	} else if (eventType == MetaEvent_LyricText::EventType) {
		pEvent = new MetaEvent_LyricText(timeStamp);
	} else if (eventType == MetaEvent_MarkerText::EventType) {
		pEvent = new MetaEvent_MarkerText(timeStamp);
	} else if (eventType == MetaEvent_CuePoint::EventType) {
		pEvent = new MetaEvent_CuePoint(timeStamp);
	} else if (eventType == MetaEvent_MIDIChannelPrefixAssignment::EventType) {
		pEvent = new MetaEvent_MIDIChannelPrefixAssignment(timeStamp);
	} else if (eventType == MetaEvent_EndOfTrack::EventType) {
		pEvent = new MetaEvent_EndOfTrack(timeStamp);
	} else if (eventType == MetaEvent_TempoSetting::EventType) {
		pEvent = new MetaEvent_TempoSetting(timeStamp);
	} else if (eventType == MetaEvent_SMPTEOffset::EventType) {
		pEvent = new MetaEvent_SMPTEOffset(timeStamp);
	} else if (eventType == MetaEvent_TimeSignature::EventType) {
		pEvent = new MetaEvent_TimeSignature(timeStamp);
	} else if (eventType == MetaEvent_KeySignature::EventType) {
		pEvent = new MetaEvent_KeySignature(timeStamp);
	} else if (eventType == MetaEvent_SequencerSpecificEvent::EventType) {
		pEvent = new MetaEvent_SequencerSpecificEvent(timeStamp);
	} else {
		pEvent = new MetaEvent_Unknown(timeStamp, eventType);
	}
	if (pEvent->Prepare(sig, binary)) {
		eventOwner.push_back(pEvent);
		return true;
	}
	delete pEvent;
	return false;
}

bool MetaEvent::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	const size_t bytes = 2;
	unsigned char buff[bytes];
	buff[0] = Status;
	buff[1] = _eventType;
	return stream.Write(sig, buff, bytes) == bytes;
}

void MetaEvent::SetError_TooShortMetaEvent(Signal sig)
{
	sig.SetError(ERR_FormatError, "too short meta event");
}

//-----------------------------------------------------------------------------
// MetaEvent_Unknown
//-----------------------------------------------------------------------------
bool MetaEvent_Unknown::Prepare(Signal sig, const Binary &binary)
{
	_binary = binary;
	return true;
}

bool MetaEvent_Unknown::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_Unknown::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_binary.size()))) return false;
	return stream.Write(sig, _binary.data(), _binary.size()) == _binary.size();
}

String MetaEvent_Unknown::GetName() const
{
	char str[128];
	::sprintf(str, "MetaEvent(%02x)", GetEventType());
	return String(str);
}

String MetaEvent_Unknown::GetArgsName() const
{
	char str[128];
	::sprintf(str, "");
	return String(str);
}

Event *MetaEvent_Unknown::Clone() const
{
	return new MetaEvent_Unknown(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_SequenceNumber
//-----------------------------------------------------------------------------
bool MetaEvent_SequenceNumber::Prepare(Signal sig, const Binary &binary)
{
	if (binary.size() < 2) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_number =
		(static_cast<unsigned short>(static_cast<unsigned char>(binary[0])) << 8) +
		(static_cast<unsigned short>(static_cast<unsigned char>(binary[1])) << 0);
	return true;
}

bool MetaEvent_SequenceNumber::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_SequenceNumber::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	const size_t bytes = 2;
	unsigned char buff[bytes];
	buff[0] = static_cast<unsigned char>(_number >> 8);
	buff[1] = static_cast<unsigned char>(_number >> 0);
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(bytes))) return false;
	return stream.Write(sig, buff, bytes) == bytes;
}

String MetaEvent_SequenceNumber::GetName() const
{
	return "SequenceNumber";
}

String MetaEvent_SequenceNumber::GetArgsName() const
{
	char str[128];
	::sprintf(str, "number:%d", _number);
	return String(str);
}

Event *MetaEvent_SequenceNumber::Clone() const
{
	return new MetaEvent_SequenceNumber(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_TextEvent
//-----------------------------------------------------------------------------
bool MetaEvent_TextEvent::Prepare(Signal sig, const Binary &binary)
{
	_text = String(binary);
	return true;
}

bool MetaEvent_TextEvent::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_TextEvent::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_text.size()))) return false;
	return stream.Write(sig, _text.data(), _text.size()) == _text.size();
}

String MetaEvent_TextEvent::GetName() const
{
	return "TextEvent";
}

String MetaEvent_TextEvent::GetArgsName() const
{
	char str[128];
	::sprintf(str, "text:%s", MakeQuotedString(_text.c_str()).c_str());
	return String(str);
}

Event *MetaEvent_TextEvent::Clone() const
{
	return new MetaEvent_TextEvent(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_CopyrightNotice
//-----------------------------------------------------------------------------
bool MetaEvent_CopyrightNotice::Prepare(Signal sig, const Binary &binary)
{
	_text = String(binary);
	return true;
}

bool MetaEvent_CopyrightNotice::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_CopyrightNotice::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_text.size()))) return false;
	return stream.Write(sig, _text.data(), _text.size()) == _text.size();
}

String MetaEvent_CopyrightNotice::GetName() const
{
	return "CopyrightNotice";
}

String MetaEvent_CopyrightNotice::GetArgsName() const
{
	char str[128];
	::sprintf(str, "text:%s", MakeQuotedString(_text.c_str()).c_str());
	return String(str);
}

Event *MetaEvent_CopyrightNotice::Clone() const
{
	return new MetaEvent_CopyrightNotice(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_SequenceOrTrackName
//-----------------------------------------------------------------------------
bool MetaEvent_SequenceOrTrackName::Prepare(Signal sig, const Binary &binary)
{
	_text = String(binary);
	return true;
}

bool MetaEvent_SequenceOrTrackName::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_SequenceOrTrackName::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_text.size()))) return false;
	return stream.Write(sig, _text.data(), _text.size()) == _text.size();
}

String MetaEvent_SequenceOrTrackName::GetName() const
{
	return "SequenceOrTrackName";
}

String MetaEvent_SequenceOrTrackName::GetArgsName() const
{
	char str[128];
	::sprintf(str, "text:%s", MakeQuotedString(_text.c_str()).c_str());
	return String(str);
}

Event *MetaEvent_SequenceOrTrackName::Clone() const
{
	return new MetaEvent_SequenceOrTrackName(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_InstrumentName
//-----------------------------------------------------------------------------
bool MetaEvent_InstrumentName::Prepare(Signal sig, const Binary &binary)
{
	_text = String(binary);
	return true;
}

bool MetaEvent_InstrumentName::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_InstrumentName::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_text.size()))) return false;
	return stream.Write(sig, _text.data(), _text.size()) == _text.size();
}

String MetaEvent_InstrumentName::GetName() const
{
	return "InstrumentName";
}

String MetaEvent_InstrumentName::GetArgsName() const
{
	char str[128];
	::sprintf(str, "text:%s", MakeQuotedString(_text.c_str()).c_str());
	return String(str);
}

Event *MetaEvent_InstrumentName::Clone() const
{
	return new MetaEvent_InstrumentName(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_LyricText
//-----------------------------------------------------------------------------
bool MetaEvent_LyricText::Prepare(Signal sig, const Binary &binary)
{
	_text = String(binary);
	return true;
}

bool MetaEvent_LyricText::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_LyricText::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_text.size()))) return false;
	return stream.Write(sig, _text.data(), _text.size()) == _text.size();
}

String MetaEvent_LyricText::GetName() const
{
	return "LyricText";
}

String MetaEvent_LyricText::GetArgsName() const
{
	char str[128];
	::sprintf(str, "text:%s", MakeQuotedString(_text.c_str()).c_str());
	return String(str);
}

Event *MetaEvent_LyricText::Clone() const
{
	return new MetaEvent_LyricText(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_MarkerText
//-----------------------------------------------------------------------------
bool MetaEvent_MarkerText::Prepare(Signal sig, const Binary &binary)
{
	_text = String(binary);
	return true;
}

bool MetaEvent_MarkerText::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_MarkerText::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_text.size()))) return false;
	return stream.Write(sig, _text.data(), _text.size()) == _text.size();
}

String MetaEvent_MarkerText::GetName() const
{
	return "MarkerText";
}

String MetaEvent_MarkerText::GetArgsName() const
{
	char str[128];
	::sprintf(str, "text:%s", MakeQuotedString(_text.c_str()).c_str());
	return String(str);
}

Event *MetaEvent_MarkerText::Clone() const
{
	return new MetaEvent_MarkerText(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_CuePoint
//-----------------------------------------------------------------------------
bool MetaEvent_CuePoint::Prepare(Signal sig, const Binary &binary)
{
	_text = String(binary);
	return true;
}

bool MetaEvent_CuePoint::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_CuePoint::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_text.size()))) return false;
	return stream.Write(sig, _text.data(), _text.size()) == _text.size();
}

String MetaEvent_CuePoint::GetName() const
{
	return "CuePoint";
}

String MetaEvent_CuePoint::GetArgsName() const
{
	char str[128];
	::sprintf(str, "text:%s", MakeQuotedString(_text.c_str()).c_str());
	return String(str);
}

Event *MetaEvent_CuePoint::Clone() const
{
	return new MetaEvent_CuePoint(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_MIDIChannelPrefixAssignment
//-----------------------------------------------------------------------------
bool MetaEvent_MIDIChannelPrefixAssignment::Prepare(Signal sig, const Binary &binary)
{
	if (binary.size() < 1) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_channel = static_cast<unsigned char>(binary[0]);
	return true;
}

bool MetaEvent_MIDIChannelPrefixAssignment::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_MIDIChannelPrefixAssignment::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	const size_t bytes = 1;
	unsigned char buff[bytes];
	buff[0] = _channel;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(bytes))) return false;
	return stream.Write(sig, buff, bytes) == bytes;
}

String MetaEvent_MIDIChannelPrefixAssignment::GetName() const
{
	return "MIDICHannelPrefixAssignment";
}

String MetaEvent_MIDIChannelPrefixAssignment::GetArgsName() const
{
	char str[128];
	::sprintf(str, "channel:%d", _channel);
	return String(str);
}

Event *MetaEvent_MIDIChannelPrefixAssignment::Clone() const
{
	return new MetaEvent_MIDIChannelPrefixAssignment(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_EndOfTrack
//-----------------------------------------------------------------------------
bool MetaEvent_EndOfTrack::Prepare(Signal sig, const Binary &binary)
{
	// no buff
	return true;
}

bool MetaEvent_EndOfTrack::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_EndOfTrack::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, 0)) return false;
	return true;
}

String MetaEvent_EndOfTrack::GetName() const
{
	return "EndOfTrack";
}

String MetaEvent_EndOfTrack::GetArgsName() const
{
	char str[128];
	::sprintf(str, "");
	return String(str);
}

Event *MetaEvent_EndOfTrack::Clone() const
{
	return new MetaEvent_EndOfTrack(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_TempoSetting
//-----------------------------------------------------------------------------
bool MetaEvent_TempoSetting::Prepare(Signal sig, const Binary &binary)
{
	if (binary.size() < 3) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_mpqn =
		(static_cast<unsigned long>(static_cast<unsigned char>(binary[0])) << 16) +
		(static_cast<unsigned long>(static_cast<unsigned char>(binary[1])) << 8) +
		(static_cast<unsigned long>(static_cast<unsigned char>(binary[2])) << 0);
	return true;
}

bool MetaEvent_TempoSetting::Play(Signal sig, Player *pPlayer) const
{
	pPlayer->SetMPQN(_mpqn);
	return true;
}

bool MetaEvent_TempoSetting::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	const size_t bytes = 3;
	unsigned char buff[bytes];
	buff[0] = static_cast<unsigned char>(_mpqn >> 16);
	buff[1] = static_cast<unsigned char>(_mpqn >> 8);
	buff[2] = static_cast<unsigned char>(_mpqn >> 0);
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(bytes))) return false;
	return stream.Write(sig, buff, bytes) == bytes;
}

String MetaEvent_TempoSetting::GetName() const
{
	return "TempoSetting";
}

String MetaEvent_TempoSetting::GetArgsName() const
{
	char str[128];
	::sprintf(str, "mpqn:%d", _mpqn);
	return String(str);
}

Event *MetaEvent_TempoSetting::Clone() const
{
	return new MetaEvent_TempoSetting(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_SMPTEOffset
//-----------------------------------------------------------------------------
bool MetaEvent_SMPTEOffset::Prepare(Signal sig, const Binary &binary)
{
	if (binary.size() < 5) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_hour = static_cast<unsigned char>(binary[0]);
	_minute = static_cast<unsigned char>(binary[1]);
	_second = static_cast<unsigned char>(binary[2]);
	_frame = static_cast<unsigned char>(binary[3]);
	_subFrame = static_cast<unsigned char>(binary[4]);
	return true;
}

bool MetaEvent_SMPTEOffset::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_SMPTEOffset::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	const size_t bytes = 5;
	unsigned char buff[bytes];
	buff[0] = _hour;
	buff[1] = _minute;
	buff[2] = _second;
	buff[3] = _frame;
	buff[4] = _subFrame;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(bytes))) return false;
	return stream.Write(sig, buff, bytes) == bytes;
}

String MetaEvent_SMPTEOffset::GetName() const
{
	return "SMPTEOffset";
}

String MetaEvent_SMPTEOffset::GetArgsName() const
{
	char str[128];
	::sprintf(str, "hour:%d minute:%d second:%d frame:%d subFrame:%d",
						_hour, _minute, _second, _frame, _subFrame);
	return String(str);
}

Event *MetaEvent_SMPTEOffset::Clone() const
{
	return new MetaEvent_SMPTEOffset(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_TimeSignature
//-----------------------------------------------------------------------------
bool MetaEvent_TimeSignature::Prepare(Signal sig, const Binary &binary)
{
	if (binary.size() < 4) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_numerator = static_cast<unsigned char>(binary[0]);
	_denominator = static_cast<unsigned char>(binary[1]);
	_metronome = static_cast<unsigned char>(binary[2]);
	_cnt32nd = static_cast<unsigned char>(binary[3]);
	return true;
}

bool MetaEvent_TimeSignature::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_TimeSignature::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	const size_t bytes = 4;
	unsigned char buff[bytes];
	buff[0] = _numerator;
	buff[1] = _denominator;
	buff[2] = _metronome;
	buff[3] = _cnt32nd;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(bytes))) return false;
	return stream.Write(sig, buff, bytes) == bytes;
}

String MetaEvent_TimeSignature::GetName() const
{
	return "TimeSignature";
}

String MetaEvent_TimeSignature::GetArgsName() const
{
	char str[128];
	::sprintf(str, "numerator:%d denominator:%d metronome:%d cnt32nd:%d",
							_numerator, _denominator, _metronome, _cnt32nd);
	return String(str);
}

Event *MetaEvent_TimeSignature::Clone() const
{
	return new MetaEvent_TimeSignature(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_KeySignature
//-----------------------------------------------------------------------------
bool MetaEvent_KeySignature::Prepare(Signal sig, const Binary &binary)
{
	if (binary.size() < 2) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_key = static_cast<unsigned char>(binary[0]);
	_scale = static_cast<unsigned char>(binary[1]);
	return true;
}

bool MetaEvent_KeySignature::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_KeySignature::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	const size_t bytes = 2;
	unsigned char buff[bytes];
	buff[0] = _key;
	buff[1] = _scale;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(bytes))) return false;
	return stream.Write(sig, buff, bytes) == bytes;
}

String MetaEvent_KeySignature::GetName() const
{
	return "KeySignature";
}

String MetaEvent_KeySignature::GetArgsName() const
{
	char str[128];
	::sprintf(str, "key:%d scale:%d", _key, _scale);
	return String(str);
}

Event *MetaEvent_KeySignature::Clone() const
{
	return new MetaEvent_KeySignature(*this);
}

//-----------------------------------------------------------------------------
// MetaEvent_SequencerSpecificEvent
//-----------------------------------------------------------------------------
bool MetaEvent_SequencerSpecificEvent::Prepare(Signal sig, const Binary &binary)
{
	_binary = binary;
	return true;
}

bool MetaEvent_SequencerSpecificEvent::Play(Signal sig, Player *pPlayer) const
{
	return true;
}

bool MetaEvent_SequencerSpecificEvent::Write(Signal sig, Stream &stream, const Event *pEventPrev) const
{
	if (!MetaEvent::Write(sig, stream, pEventPrev)) return false;
	if (!WriteVariableFormat(sig, stream, static_cast<unsigned long>(_binary.size()))) return false;
	return stream.Write(sig, _binary.data(), _binary.size()) == _binary.size();
}

String MetaEvent_SequencerSpecificEvent::GetName() const
{
	return "SequencerSpecificEvent";
}

String MetaEvent_SequencerSpecificEvent::GetArgsName() const
{
	char str[128];
	::sprintf(str, "%dbytes", _binary.size());
	return String(str);
}

Event *MetaEvent_SequencerSpecificEvent::Clone() const
{
	return new MetaEvent_SequencerSpecificEvent(*this);
}

}}
