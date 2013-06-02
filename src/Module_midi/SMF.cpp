#include "SMF.h"
#include "Port.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// SMF
//-----------------------------------------------------------------------------
SMF::SMF()
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

bool SMF::Read(Signal sig, Stream &stream, EventOwner &eventOwner)
{
	enum Stat {
		STAT_EventStart,
		STAT_DeltaTime,
		STAT_Status,
		STAT_MIDIEvent,
		STAT_SysExEventF0,
		STAT_SysExEventF7,
		STAT_MetaEvent_Type,
		STAT_MetaEvent_Length,
		STAT_MetaEvent_Data,
	};
	AutoPtr<Memory> pMemory(new MemoryHeap(1024));
	unsigned short format = 0;
	unsigned short num_track_chunks = 0;
	unsigned short division = 0;
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
		format = Gura_UnpackUShort(headerChunk.format);
		num_track_chunks = Gura_UnpackUShort(headerChunk.num_track_chunks);
		division = Gura_UnpackUShort(headerChunk.division);
	} while (0);
	::printf("%d %d %d\n", format, num_track_chunks, division);
	for (unsigned short i = 0; i < num_track_chunks; i++) {
		TrackChunkTop trackChunkTop;
		if (stream.Read(sig, &trackChunkTop, TrackChunkTop::Size) != TrackChunkTop::Size) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		if (::strcmp(trackChunkTop.MTrk, "MTrk") != 0) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
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
						unsigned char statusUpper = status & 0xf0;
						if (statusUpper == 0x80 || statusUpper == 0x90 ||
								statusUpper == 0xa0 || statusUpper == 0xb0 ||
								statusUpper == 0xe0) {
							idxBuff = 0;
							length = 3;
							buff[idxBuff++] = status;
							stat = STAT_MIDIEvent;
						} else if (statusUpper == 0xc0 || statusUpper == 0xd0) {
							idxBuff = 0;
							length = 2;
							buff[idxBuff++] = status;
							stat = STAT_MIDIEvent;
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
					} else if (stat == STAT_MIDIEvent) {
						buff[idxBuff++] = data;
						if (idxBuff == length) {
							unsigned long &timeStamp = _timeStampTbl[buff[0] & 0x0f];
							timeStamp += deltaTime;
							if (length == 2) {
								eventOwner.push_back(new MIDIEvent(timeStamp,
													buff[0], buff[1], 0x00));
							} else if (length == 3) {
								eventOwner.push_back(new MIDIEvent(timeStamp,
													buff[0], buff[1], buff[2]));
							}
							stat = STAT_EventStart;
						}
					} else if (stat == STAT_SysExEventF0) {
						if (data == 0xf7) {
							_timeStampSysEx += deltaTime;
							//OnSysExEvent(_timeStampSysEx);
							stat = STAT_EventStart;
						}
					} else if (stat == STAT_SysExEventF7) {
						if (data == 0xf7) {
							_timeStampSysEx += deltaTime;
							//OnSysExEvent(_timeStampSysEx);
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
							if (!NotifyMetaEvent(sig, _timeStampMeta, eventType, buff, 0)) {
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
							if (!NotifyMetaEvent(sig, _timeStampMeta, eventType, buff,
									ChooseMin(static_cast<size_t>(length), sizeof(buff)))) {
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

bool SMF::NotifyMetaEvent(Signal sig, unsigned long timeStamp,
				unsigned char eventType, unsigned char data[], size_t length)
{
#if 0
	Event *pEvent = 
		(eventType == 0x00)? MetaEvent_SequenceNumber::Create(sig, timeStamp, data, length) :
		(eventType == 0x01)? MetaEvent_TextEvent::Create(sig, timeStamp, data, length) :
		(eventType == 0x02)? MetaEvent_CopyrightNotice::Create(sig, timeStamp, data, length) :
		(eventType == 0x03)? MetaEvent_SequenceOrTrackName::Create(sig, timeStamp, data, length) :
		(eventType == 0x04)? MetaEvent_InstrumentName::Create(sig, timeStamp, data, length) :
		(eventType == 0x05)? MetaEvent_LyricText::Create(sig, timeStamp, data, length) :
		(eventType == 0x2f)? MetaEvent_EndOfTrack::Create(sig, timeStamp, data, length) :
		(eventType == 0x51)? MetaEvent_TempoSetting::Create(sig, timeStamp, data, length) :
		(eventType == 0x58)? MetaEvent_TimeSignature::Create(sig, timeStamp, data, length) :
		(eventType == 0x59)? MetaEvent_KeySignature::Create(sig, timeStamp, data, length) :
		MetaEvent_Unknown::Create(sig, timeStamp, eventType, data, length);
	if (pEvent == NULL) return false;
	eventOwner.push_back(pEvent);
#endif
	return true;
}

//-----------------------------------------------------------------------------
// SMF::Event
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// EventList
//-----------------------------------------------------------------------------
void SMF::EventList::Sort()
{
	std::stable_sort(begin(), end(), Comparator_TimeStamp());
}

bool SMF::EventList::Play(Signal sig, Port *pPort)
{
	Event *pEventPrev = NULL;
	foreach (EventList, ppEvent, *this) {
		Event *pEvent = *ppEvent;
		if (pEventPrev != NULL &&
					pEventPrev->GetTimeStamp() < pEvent->GetTimeStamp()) {
			unsigned long deltaTime =
					pEvent->GetTimeStamp() - pEventPrev->GetTimeStamp();
			OAL::Sleep(.005 * deltaTime);
		}
		if (!pEvent->Play(sig, pPort)) return false;
		pEventPrev = pEvent;
	}
	return true;
}

//-----------------------------------------------------------------------------
// SMF::EventOwner
//-----------------------------------------------------------------------------
SMF::EventOwner::~EventOwner()
{
	Clear();
}

void SMF::EventOwner::Clear()
{
	foreach (EventOwner, ppEvent, *this) {
		Event *pEvent = *ppEvent;
		delete pEvent;
	}
	clear();
}

//-----------------------------------------------------------------------------
// SMF::MIDIEvent
//-----------------------------------------------------------------------------
bool SMF::MIDIEvent::Play(Signal sig, Port *pPort)
{
	pPort->RawWrite(_msg1, _msg2, _msg3);
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_Unknown
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_Unknown::Create(Signal sig, unsigned long timeStamp, unsigned char eventType, unsigned char data[], size_t length)
{
	
	return NULL;
}

bool SMF::MetaEvent_Unknown::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_SequenceNumber
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_SequenceNumber::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_SequenceNumber::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_TextEvent
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_TextEvent::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	MetaEvent_TextEvent *pEvent = new MetaEvent_TextEvent(timeStamp);
	pEvent->_text = String(reinterpret_cast<const char *>(data), length);
	return NULL;
}

bool SMF::MetaEvent_TextEvent::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_CopyrightNotice
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_CopyrightNotice::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_CopyrightNotice::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_SequenceOrTrackName
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_SequenceOrTrackName::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_SequenceOrTrackName::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_InstrumentName
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_InstrumentName::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_InstrumentName::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_LyricText
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_LyricText::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_LyricText::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_MarkerText
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_MarkerText::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_MarkerText::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_CuePoint
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_CuePoint::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_CuePoint::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_MIDIChannelPrefixAssignment
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_MIDIChannelPrefixAssignment::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_MIDIChannelPrefixAssignment::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_EndOfTrack
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_EndOfTrack::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_EndOfTrack::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_TempoSetting
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_TempoSetting::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_TempoSetting::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_SMPTEOffset
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_SMPTEOffset::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_SMPTEOffset::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_TimeSignature
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_TimeSignature::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_TimeSignature::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_KeySignature
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_KeySignature::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_KeySignature::Play(Signal sig, Port *pPort)
{
	return true;
}

//-----------------------------------------------------------------------------
// SMF::MetaEvent_SequencerSpecificEvent
//-----------------------------------------------------------------------------
SMF::Event *SMF::MetaEvent_SequencerSpecificEvent::Create(Signal sig, unsigned long timeStamp, unsigned char data[], size_t length)
{
	return NULL;
}

bool SMF::MetaEvent_SequencerSpecificEvent::Play(Signal sig, Port *pPort)
{
	return true;
}

}}
