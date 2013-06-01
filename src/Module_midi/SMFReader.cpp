#include "SMFReader.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// SMFReader
//-----------------------------------------------------------------------------
bool SMFReader::Read(Signal sig, Stream &stream)
{
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
	enum Stat {
		STAT_EventStart,
		STAT_DeltaTime,
		STAT_EventId,
		STAT_MIDIEvent,
		STAT_SysExEventF0,
		STAT_SysExEventF7,
		STAT_MetaEvent_Type,
		STAT_MetaEvent_Length,
		STAT_MetaEvent_Data,
	};
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
		unsigned char data[256];
		Stat stat = STAT_EventStart;
		unsigned long deltaTime = 0x00000000;
		unsigned long length = 0x00000000;
		unsigned long idxData = 0;
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
				unsigned char ch = *p;
				if (stat == STAT_EventStart) {
					deltaTime = 0x00000000;
					length = 0x00000000;
					stat = STAT_DeltaTime;
				}
				if (stat == STAT_DeltaTime) {
					deltaTime = (deltaTime << 7) + (ch & 0x7f);
					if ((ch & 0x80) == 0) {
						stat = STAT_EventId;
					}
				} else if (stat == STAT_EventId) {
					unsigned char chUpper = ch & 0xf0;
					if (chUpper == 0x80 || chUpper == 0x90 || chUpper == 0xa0
										|| chUpper == 0xb0 || chUpper == 0xe0) {
						idxData = 0;
						length = 3;
						data[idxData++] = ch;
						stat = STAT_MIDIEvent;
					} else if (chUpper == 0xc0 || chUpper == 0xd0) {
						idxData = 0;
						length = 2;
						data[idxData++] = ch;
						stat = STAT_MIDIEvent;
					} else if (ch == 0xf0) {
						stat = STAT_SysExEventF0;
					} else if (ch == 0xf7) {
						stat = STAT_SysExEventF7;
					} else if (ch == 0xff) {
						stat = STAT_MetaEvent_Type;
					} else {
						sig.SetError(ERR_FormatError, "unknown SMF event id %02x", ch);
						return false;
					}
				} else if (stat == STAT_MIDIEvent) {
					data[idxData++] = ch;
					if (idxData == length) {
						OnMIDIEvent(deltaTime, data, length);
						stat = STAT_EventStart;
					}
				} else if (stat == STAT_SysExEventF0) {
					if (ch == 0xf7) {
						OnSysExEvent(deltaTime);
						stat = STAT_EventStart;
					}
				} else if (stat == STAT_SysExEventF7) {
					if (ch == 0xf7) {
						OnSysExEvent(deltaTime);
						stat = STAT_EventStart;
					}
				} else if (stat == STAT_MetaEvent_Type) {
					eventType = ch;
					stat = STAT_MetaEvent_Length;
				} else if (stat == STAT_MetaEvent_Length) {
					length = (length << 7) + (ch & 0x7f);
					if ((ch & 0x80) != 0) {
						// nothing to do
					} else if (length == 0) {
						OnMetaEvent(deltaTime, eventType, data, 0);
						stat = STAT_EventStart;
					} else {
						idxData = 0;
						stat = STAT_MetaEvent_Data;
					}
				} else if (stat == STAT_MetaEvent_Data) {
					if (idxData < sizeof(data)) data[idxData] = ch;
					idxData++;
					if (idxData == length) {
						OnMetaEvent(deltaTime, eventType, data, ChooseMin(
								static_cast<size_t>(length), sizeof(data)));
						stat = STAT_EventStart;
					}
				}
			}
		}
	}
	return true;
}

}}
