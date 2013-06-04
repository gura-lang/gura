#include "SMF.h"
#include "Port.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// SMF
//-----------------------------------------------------------------------------
SMF::SMF() : _format(0), _numTrackChunks(0), _division(0)
{
	ResetTimeStamp();
}

void SMF::ResetTimeStamp()
{
	for (size_t i = 0; i < NUM_CHANNELS; i++) {
		_timeStampTbl[i] = 0;
	}
	_timeStampSysEx = 0;
	_timeStampMeta = 0;
}

bool SMF::Read(Signal sig, Stream &stream)
{
	enum Stat {
		STAT_EventStart,
		STAT_DeltaTime,
		STAT_Status,
		STAT_MIDIEvent_Param1st,
		STAT_MIDIEvent_Param2nd,
		STAT_SysExEventF0,
		STAT_SysExEventF7,
		STAT_MetaEvent_Type,
		STAT_MetaEvent_Length,
		STAT_MetaEvent_Data,
	};
	AutoPtr<Memory> pMemory(new MemoryHeap(1024));
	do {
		HeaderChunkTop headerChunkTop;
		if (stream.Read(sig, &headerChunkTop, HeaderChunkTop::Size) != HeaderChunkTop::Size) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		if (::strcmp(headerChunkTop.MThd, "MThd") != 0) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		size_t header_length = Gura_UnpackULong(headerChunkTop.header_length);
		HeaderChunk &headerChunk = *reinterpret_cast<HeaderChunk *>(pMemory->GetPointer());
		if (header_length > pMemory->GetSize()) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		if (stream.Read(sig, pMemory->GetPointer(), header_length) != header_length) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		_format = Gura_UnpackUShort(headerChunk.format);
		_numTrackChunks = Gura_UnpackUShort(headerChunk.num_track_chunks);
		_division = Gura_UnpackUShort(headerChunk.division);
	} while (0);
	_trackOwner.Clear();
	for (unsigned short i = 0; i < _numTrackChunks; i++) {
		TrackChunkTop trackChunkTop;
		if (stream.Read(sig, &trackChunkTop, TrackChunkTop::Size) != TrackChunkTop::Size) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		if (::strcmp(trackChunkTop.MTrk, "MTrk") != 0) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		_trackOwner.push_back(new Track());
		EventOwner &eventOwner = _trackOwner.back()->GetEventOwner();
		std::auto_ptr<MIDIEvent> pMIDIEvent;
		unsigned char eventType = 0x00;
		unsigned char buff[512];
		Stat stat = STAT_EventStart;
		unsigned long deltaTime = 0x00000000;
		unsigned long length = 0x00000000;
		unsigned long idxBuff = 0;
		unsigned char statusPrev = 0x00;
		size_t lengthRest = Gura_UnpackULong(trackChunkTop.length);
		while  (lengthRest > 0) {
			size_t lengthRead = ChooseMin(lengthRest, pMemory->GetSize());
			if (stream.Read(sig, pMemory->GetPointer(), lengthRead) != lengthRead) {
				sig.SetError(ERR_FormatError, "invalid SMF format");
				return false;
			}
			lengthRest -= lengthRead;
			unsigned char *p = reinterpret_cast<unsigned char *>(pMemory->GetPointer());
			for ( ; lengthRead > 0; p++, lengthRead--) {
				unsigned char data = *p;
				//::printf("%02x\n", data);
				bool continueFlag = false;
				do {
					continueFlag = false;
					if (stat == STAT_EventStart) {
						deltaTime = 0x00000000;
						length = 0x00000000;
						stat = STAT_DeltaTime;
					}
					if (stat == STAT_DeltaTime) {
						deltaTime = (deltaTime << 7) + (data & 0x7f);
						if ((data & 0x80) == 0) {
							stat = STAT_Status;
						}
					} else if (stat == STAT_Status) {
						unsigned char status = data;
						if ((status & 0x80) == 0) {
							// running status
							continueFlag = true;
							status = statusPrev;
						}
						statusPrev = status;
						if (MIDIEvent::CheckStatus(status)) {
							unsigned char statusUpper = status & 0xf0;
							unsigned char channel = status & 0x0f;
							unsigned long &timeStamp = _timeStampTbl[channel];
							timeStamp += deltaTime;
							if (statusUpper == MIDIEvent_NoteOff::Status) {
								pMIDIEvent.reset(new MIDIEvent_NoteOff(timeStamp, channel));
							} else if (statusUpper == MIDIEvent_NoteOn::Status) {
								pMIDIEvent.reset(new MIDIEvent_NoteOn(timeStamp, channel));
							} else if (statusUpper == MIDIEvent_PolyphonicKeyPressure::Status) {
								pMIDIEvent.reset(new MIDIEvent_PolyphonicKeyPressure(timeStamp, channel));
							} else if (statusUpper == MIDIEvent_ControlChange::Status) {
								pMIDIEvent.reset(new MIDIEvent_ControlChange(timeStamp, channel));
							} else if (statusUpper == MIDIEvent_ProgramChange::Status) {
								pMIDIEvent.reset(new MIDIEvent_ProgramChange(timeStamp, channel));
							} else if (statusUpper == MIDIEvent_ChannelPressure::Status) {
								pMIDIEvent.reset(new MIDIEvent_ChannelPressure(timeStamp, channel));
							} else if (statusUpper == MIDIEvent_PitchBendChange::Status) {
								pMIDIEvent.reset(new MIDIEvent_PitchBendChange(timeStamp, channel));
							} else {
								// this must not happen
								return false;
							}
							stat = STAT_MIDIEvent_Param1st;
						} else if (status == 0xf0) {
							stat = STAT_SysExEventF0;
						} else if (status == 0xf7) {
							stat = STAT_SysExEventF7;
						} else if (status == 0xff) {
							stat = STAT_MetaEvent_Type;
						} else {
							sig.SetError(ERR_FormatError, "unknown SMF status %02x", status);
							return false;
						}
					} else if (stat == STAT_MIDIEvent_Param1st) {
						pMIDIEvent->SetParam1st(data);
						if (pMIDIEvent->CountParams() == 1) {
							eventOwner.push_back(pMIDIEvent.release());
							stat = STAT_EventStart;
						} else {
							stat = STAT_MIDIEvent_Param2nd;
						}
					} else if (stat == STAT_MIDIEvent_Param2nd) {
						pMIDIEvent->SetParam2nd(data);
						eventOwner.push_back(pMIDIEvent.release());
						stat = STAT_EventStart;
					} else if (stat == STAT_SysExEventF0) {
						if (data == 0xf7) {
							_timeStampSysEx += deltaTime;
							eventOwner.push_back(new SysExEvent(_timeStampSysEx, buff, 0));
							stat = STAT_EventStart;
						}
					} else if (stat == STAT_SysExEventF7) {
						if (data == 0xf7) {
							_timeStampSysEx += deltaTime;
							eventOwner.push_back(new SysExEvent(_timeStampSysEx, buff, 0));
							stat = STAT_EventStart;
						}
					} else if (stat == STAT_MetaEvent_Type) {
						eventType = data;
						stat = STAT_MetaEvent_Length;
					} else if (stat == STAT_MetaEvent_Length) {
						length = (length << 7) + (data & 0x7f);
						if ((data & 0x80) != 0) {
							// nothing to do
						} else if (length == 0) {
							_timeStampMeta += deltaTime;
							if (!MetaEvent::Add(sig, eventOwner,
										_timeStampMeta, eventType, buff, 0)) {
								return false;
							}
							stat = STAT_EventStart;
						} else {
							idxBuff = 0;
							stat = STAT_MetaEvent_Data;
						}
					} else if (stat == STAT_MetaEvent_Data) {
						if (idxBuff < sizeof(buff)) buff[idxBuff] = data;
						idxBuff++;
						if (idxBuff == length) {
							_timeStampMeta += deltaTime;
							if (!MetaEvent::Add(sig, eventOwner, _timeStampMeta, eventType,
									buff, ChooseMin(static_cast<size_t>(length), sizeof(buff)))) {
								return false;
							}
							stat = STAT_EventStart;
						}
					}
				} while (continueFlag);
			}
		}
	}
	return true;
}

bool SMF::Play(Signal sig, Port *pPort) const
{
	EventOwner eventOwner;
	double deltaTimeUnit = .6 / GetDivision();
	foreach_const (TrackOwner, ppTrack, GetTrackOwner()) {
		const Track *pTrack = *ppTrack;
		foreach_const (EventOwner, ppEvent, pTrack->GetEventOwner()) {
			const Event *pEvent = *ppEvent;
			eventOwner.push_back(Event::Reference(pEvent));
		}
	}
	eventOwner.Sort();
	return eventOwner.Play(sig, pPort, deltaTimeUnit);
}

//-----------------------------------------------------------------------------
// SMF::SysExEvent
//-----------------------------------------------------------------------------
bool SMF::SysExEvent::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::SysExEvent::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::SysExEvent::ToString() const
{
	char str[128];
	::sprintf(str, "SysExEvent");
	return String(str);
}

Event *SMF::SysExEvent::Clone() const
{
	return new SysExEvent(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent
//-----------------------------------------------------------------------------
bool SMF::MetaEvent::Add(Signal sig, EventOwner &eventOwner, unsigned long timeStamp,
			unsigned char eventType, const unsigned char buff[], size_t length)
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
	if (pEvent->Prepare(sig, buff, length)) {
		eventOwner.push_back(pEvent);
		return true;
	}
	delete pEvent;
	return false;
}

void SMF::MetaEvent::SetError_TooShortMetaEvent(Signal sig)
{
	sig.SetError(ERR_FormatError, "too short meta event");
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_Unknown
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_Unknown::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_binary = Binary(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_Unknown::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_Unknown::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_Unknown::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent(%02x)", GetEventType());
	return String(str);
}

Event *SMF::MetaEvent_Unknown::Clone() const
{
	return new MetaEvent_Unknown(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_SequenceNumber
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_SequenceNumber::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length < 2) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_number =
		(static_cast<unsigned short>(buff[0]) << 8) +
		(static_cast<unsigned short>(buff[1]) << 0);
	return true;
}

bool SMF::MetaEvent_SequenceNumber::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_SequenceNumber::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_SequenceNumber::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-SequenceNumber number:%d", _number);
	return String(str);
}

Event *SMF::MetaEvent_SequenceNumber::Clone() const
{
	return new MetaEvent_SequenceNumber(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_TextEvent
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_TextEvent::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_text = String(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_TextEvent::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_TextEvent::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_TextEvent::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-TextEvent text:'%s'", _text.c_str());
	return String(str);
}

Event *SMF::MetaEvent_TextEvent::Clone() const
{
	return new MetaEvent_TextEvent(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_CopyrightNotice
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_CopyrightNotice::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_text = String(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_CopyrightNotice::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_CopyrightNotice::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_CopyrightNotice::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-CopyrightNotice text:'%s'", _text.c_str());
	return String(str);
}

Event *SMF::MetaEvent_CopyrightNotice::Clone() const
{
	return new MetaEvent_CopyrightNotice(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_SequenceOrTrackName
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_SequenceOrTrackName::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_text = String(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_SequenceOrTrackName::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_SequenceOrTrackName::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_SequenceOrTrackName::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-SequenceOrTrackName text:'%s'", _text.c_str());
	return String(str);
}

Event *SMF::MetaEvent_SequenceOrTrackName::Clone() const
{
	return new MetaEvent_SequenceOrTrackName(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_InstrumentName
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_InstrumentName::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_text = String(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_InstrumentName::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_InstrumentName::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_InstrumentName::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-InstrumentName text:'%s'", _text.c_str());
	return String(str);
}

Event *SMF::MetaEvent_InstrumentName::Clone() const
{
	return new MetaEvent_InstrumentName(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_LyricText
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_LyricText::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_text = String(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_LyricText::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_LyricText::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_LyricText::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-LyricText text:'%s'", _text.c_str());
	return String(str);
}

Event *SMF::MetaEvent_LyricText::Clone() const
{
	return new MetaEvent_LyricText(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_MarkerText
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_MarkerText::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_text = String(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_MarkerText::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_MarkerText::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_MarkerText::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-MarkerText text:'%s'", _text.c_str());
	return String(str);
}

Event *SMF::MetaEvent_MarkerText::Clone() const
{
	return new MetaEvent_MarkerText(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_CuePoint
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_CuePoint::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_text = String(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_CuePoint::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_CuePoint::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_CuePoint::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-CuePoint text:'%s'", _text.c_str());
	return String(str);
}

Event *SMF::MetaEvent_CuePoint::Clone() const
{
	return new MetaEvent_CuePoint(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_MIDIChannelPrefixAssignment
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_MIDIChannelPrefixAssignment::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length < 1) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_channel = buff[0];
	return true;
}

bool SMF::MetaEvent_MIDIChannelPrefixAssignment::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_MIDIChannelPrefixAssignment::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_MIDIChannelPrefixAssignment::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-MIDIChannelPrefixAssignment channel:%d", _channel);
	return String(str);
}

Event *SMF::MetaEvent_MIDIChannelPrefixAssignment::Clone() const
{
	return new MetaEvent_MIDIChannelPrefixAssignment(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_EndOfTrack
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_EndOfTrack::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	// no buff
	return true;
}

bool SMF::MetaEvent_EndOfTrack::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_EndOfTrack::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_EndOfTrack::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-EndOfTrack");
	return String(str);
}

Event *SMF::MetaEvent_EndOfTrack::Clone() const
{
	return new MetaEvent_EndOfTrack(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_TempoSetting
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_TempoSetting::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length < 2) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_mpqn =
		static_cast<unsigned long>(buff[0] << 16) +
		static_cast<unsigned long>(buff[1] << 8) +
		static_cast<unsigned long>(buff[2] << 0);
	return true;
}

bool SMF::MetaEvent_TempoSetting::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_TempoSetting::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_TempoSetting::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-TempoSetting mpqn:%d", _mpqn);
	return String(str);
}

Event *SMF::MetaEvent_TempoSetting::Clone() const
{
	return new MetaEvent_TempoSetting(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_SMPTEOffset
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_SMPTEOffset::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length < 5) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_hour = buff[0];
	_minute = buff[1];
	_second = buff[2];
	_frame = buff[3];
	_subFrame = buff[4];
	return true;
}

bool SMF::MetaEvent_SMPTEOffset::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_SMPTEOffset::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_SMPTEOffset::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-SMPTEOffset hour:%d minute:%d second:%d frame:%d subFrame:%d",
						_hour, _minute, _second, _frame, _subFrame);
	return String(str);
}

Event *SMF::MetaEvent_SMPTEOffset::Clone() const
{
	return new MetaEvent_SMPTEOffset(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_TimeSignature
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_TimeSignature::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length < 4) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_numerator = buff[0];
	_denominator = buff[1];
	_metronome = buff[2];
	_cnt32nd = buff[3];
	return true;
}

bool SMF::MetaEvent_TimeSignature::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_TimeSignature::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_TimeSignature::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-TimeSignature numerator:%d denominator:%d metronome:%d cnt32nd:%d",
							_numerator, _denominator, _metronome, _cnt32nd);
	return String(str);
}

Event *SMF::MetaEvent_TimeSignature::Clone() const
{
	return new MetaEvent_TimeSignature(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_KeySignature
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_KeySignature::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length < 2) {
		SetError_TooShortMetaEvent(sig);
		return false;
	}
	_key = buff[0];
	_scale = buff[1];
	return true;
}

bool SMF::MetaEvent_KeySignature::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_KeySignature::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_KeySignature::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-KeySignature key:%d scale:%d", _key, _scale);
	return String(str);
}

Event *SMF::MetaEvent_KeySignature::Clone() const
{
	return new MetaEvent_KeySignature(*this);
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_SequencerSpecificEvent
//-----------------------------------------------------------------------------
bool SMF::MetaEvent_SequencerSpecificEvent::Prepare(Signal sig, const unsigned char buff[], size_t length)
{
	if (length > 0) {
		_binary = Binary(reinterpret_cast<const char *>(buff), length);
	}
	return true;
}

bool SMF::MetaEvent_SequencerSpecificEvent::Play(Signal sig, Port *pPort) const
{
	return true;
}

bool SMF::MetaEvent_SequencerSpecificEvent::Serialize(Signal sig, Stream &stream) const
{
	return false;
}

String SMF::MetaEvent_SequencerSpecificEvent::ToString() const
{
	char str[128];
	::sprintf(str, "MetaEvent-SequencerSpecificEvent");
	return String(str);
}

Event *SMF::MetaEvent_SequencerSpecificEvent::Clone() const
{
	return new MetaEvent_SequencerSpecificEvent(*this);
}

}}
