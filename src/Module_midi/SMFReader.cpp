#include "SMFReader.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// SMFReader
//-----------------------------------------------------------------------------
SMFReader::SMFReader()
{
	ResetTimeStamp();
}

void SMFReader::ResetTimeStamp()
{
	for (size_t i = 0; i < NUM_CHANNELS; i++) {
		_timeStampTbl[i] = 0;
	}
	_timeStampSysEx = 0;
	_timeStampMeta = 0;
}

bool SMFReader::Read(Signal sig, Stream &stream)
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
							int channel = buff[0] & 0x0f;
							_timeStampTbl[channel] += deltaTime;
							if (length == 2) {
								OnMIDIEvent(_timeStampTbl[channel], buff[0], buff[1]);
							} else if (length == 3) {
								OnMIDIEvent(_timeStampTbl[channel], buff[0], buff[1], buff[2]);
							}
							stat = STAT_EventStart;
						}
					} else if (stat == STAT_SysExEventF0) {
						if (data == 0xf7) {
							_timeStampSysEx += deltaTime;
							OnSysExEvent(_timeStampSysEx);
							stat = STAT_EventStart;
						}
					} else if (stat == STAT_SysExEventF7) {
						if (data == 0xf7) {
							_timeStampSysEx += deltaTime;
							OnSysExEvent(_timeStampSysEx);
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
						if (idxBuff < sizeof(buff) - 1) {
							buff[idxBuff] = data;
							buff[idxBuff + 1] = 0x00;
						}
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

void SMFReader::OnMetaEvent_SequenceNumber(unsigned long timeStamp)
{
	::printf("SequenceNumber\n");
}

void SMFReader::OnMetaEvent_Text(unsigned long timeStamp, const char *text)
{
	::printf("Text: %s\n", text);
}

void SMFReader::OnMetaEvent_CopyrightNotice(unsigned long timeStamp, const char *text)
{
	::printf("CopyrightNotice: %s\n", text);
}

void SMFReader::OnMetaEvent_SequenceTrackName(unsigned long timeStamp, const char *text)
{
	::printf("SequenceTrackName: %s\n", text);
}

void SMFReader::OnMetaEvent_InstrumentName(unsigned long timeStamp, const char *text)
{
	::printf("InstrumentName: %s\n", text);
}

void SMFReader::OnMetaEvent_Lylic(unsigned long timeStamp, const char *text)
{
	::printf("Lylic: %s\n", text);
}

void SMFReader::OnMetaEvent_EndOfTrack(unsigned long timeStamp)
{
	::printf("EndOfTrack\n");
}

void SMFReader::OnMetaEvent_SetTempo(unsigned long timeStamp)
{
	::printf("SetTempo\n");
}

void SMFReader::OnMetaEvent_TimeSignature(unsigned long timeStamp)
{
	::printf("TimeSignature\n");
}

void SMFReader::OnMetaEvent_KeySignature(unsigned long timeStamp)
{
	::printf("KeySignature\n");
}

bool SMFReader::NotifyMetaEvent(Signal sig, unsigned long timeStamp,
				unsigned char eventType, unsigned char data[], size_t length)
{
	if (eventType == 0x00) {
		OnMetaEvent_SequenceNumber(timeStamp);
	} else if (eventType == 0x01) {
		OnMetaEvent_Text(timeStamp, reinterpret_cast<char *>(data));
	} else if (eventType == 0x02) {
		OnMetaEvent_CopyrightNotice(timeStamp, reinterpret_cast<char *>(data));
	} else if (eventType == 0x03) {
		OnMetaEvent_SequenceTrackName(timeStamp, reinterpret_cast<char *>(data));
	} else if (eventType == 0x04) {
		OnMetaEvent_InstrumentName(timeStamp, reinterpret_cast<char *>(data));
	} else if (eventType == 0x05) {
		OnMetaEvent_Lylic(timeStamp, reinterpret_cast<char *>(data));
	} else if (eventType == 0x2f) {
		OnMetaEvent_EndOfTrack(timeStamp);
	} else if (eventType == 0x51) {
		OnMetaEvent_SetTempo(timeStamp);
	} else if (eventType == 0x58) {
		OnMetaEvent_TimeSignature(timeStamp);
	} else if (eventType == 0x59) {
		OnMetaEvent_KeySignature(timeStamp);
	} else {
		// unknown meta event
		::printf("%08x MetaEvent %02x\n", timeStamp, eventType);
	}
	return true;
}

}}
