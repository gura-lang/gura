#include "SMF.h"
#include "Port.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// SMF
//-----------------------------------------------------------------------------
SMF::SMF() : _format(0), _division(0), _pTrackOwner(new TrackOwner())
{
}

bool SMF::Read(Environment &env, Signal sig, Stream &stream)
{
	enum Stat {
		STAT_EventStart,
		STAT_DeltaTime,
		STAT_Status,
		STAT_MIDIEvent_Param1st,
		STAT_MIDIEvent_Param2nd,
		STAT_SysExEvent,
		STAT_MetaEvent_Type,
		STAT_MetaEvent_Length,
		STAT_MetaEvent_Data,
	};
	AutoPtr<Memory> pMemory(new MemoryHeap(1024));
	size_t numTrackChunks = 0;
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
		if (_format != 0 && _format != 1) {
			sig.SetError(ERR_FormatError, "supported format is 0 or 1");
			return false;
		}
		numTrackChunks = Gura_UnpackUShort(headerChunk.num_track_chunks);
		_division = Gura_UnpackUShort(headerChunk.division);
	} while (0);
	GetTrackOwner().Clear();
	for (size_t i = 0; i < numTrackChunks; i++) {
		TrackChunkTop trackChunkTop;
		if (stream.Read(sig, &trackChunkTop, TrackChunkTop::Size) != TrackChunkTop::Size) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		if (::strcmp(trackChunkTop.MTrk, "MTrk") != 0) {
			sig.SetError(ERR_FormatError, "invalid SMF format");
			return false;
		}
		GetTrackOwner().push_back(new Track());
		EventOwner &eventOwner = GetTrackOwner().back()->GetEventOwner();
		std::auto_ptr<MIDIEvent> pMIDIEvent;
		unsigned char eventType = 0x00;
		Binary binary;
		Stat stat = STAT_EventStart;
		unsigned long deltaTime = 0x00000000;
		unsigned long timeStamp = 0x00000000;
		unsigned long length = 0x00000000;
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
						binary.clear();
					}
					if (stat == STAT_DeltaTime) {
						deltaTime = (deltaTime << 7) + (data & 0x7f);
						if ((data & 0x80) == 0) {
							stat = STAT_Status;
						}
					} else if (stat == STAT_Status) {
						bool enableRunningStatus = true;
						unsigned char status = data;
						if ((status & 0x80) == 0) {
							// running status
							continueFlag = true;
							status = statusPrev;
						} else if (status == statusPrev) {
							enableRunningStatus = false;
						}
						timeStamp += deltaTime;
						statusPrev = status;
						if (MIDIEvent::CheckStatus(status)) {
							unsigned char statusUpper = status & 0xf0;
							unsigned char channel = status & 0x0f;
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
							pMIDIEvent->EnableRunningStaus(enableRunningStatus);
							stat = STAT_MIDIEvent_Param1st;
						} else if (status == SysExEvent::StatusF0 ||
											status == SysExEvent::StatusF7) {
							binary.push_back(data);
							stat = STAT_SysExEvent;
						} else if (status == MetaEvent::Status) {
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
					} else if (stat == STAT_SysExEvent) {
						binary.push_back(data);
						if (data == 0xf7) {
							eventOwner.push_back(new SysExEvent(timeStamp, binary));
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
							if (!MetaEvent::Add(sig, eventOwner,
											timeStamp, eventType, binary)) {
								return false;
							}
							stat = STAT_EventStart;
						} else {
							stat = STAT_MetaEvent_Data;
						}
					} else if (stat == STAT_MetaEvent_Data) {
						binary.push_back(data);
						if (binary.size() == length) {
							if (!MetaEvent::Add(sig, eventOwner,
											timeStamp, eventType, binary)) {
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

bool SMF::Write(Environment &env, Signal sig, Stream &stream)
{
	do {
		HeaderChunkTop headerChunkTop;
		::memcpy(headerChunkTop.MThd, "MThd", sizeof(headerChunkTop.MThd));
		Gura_PackULong(headerChunkTop.header_length, HeaderChunk::Size);
		if (stream.Write(sig, &headerChunkTop, HeaderChunkTop::Size) != HeaderChunkTop::Size) {
			return false;
		}
	} while (0);
	do {
		HeaderChunk headerChunk;
		Gura_PackUShort(headerChunk.format, GetFormat());
		Gura_PackUShort(headerChunk.num_track_chunks,
						static_cast<unsigned short>(GetTrackOwner().size()));
		Gura_PackUShort(headerChunk.division, GetDivision());
		if (stream.Write(sig, &headerChunk, HeaderChunk::Size) != HeaderChunk::Size) {
			return false;
		}
	} while (0);
	foreach_const (TrackOwner, ppTrack, GetTrackOwner()) {
		const Track *pTrack = *ppTrack;
		AutoPtr<StreamMemory> pStreamMemory(new StreamMemory(env, sig));
		const Event *pEventPrev = NULL;
		unsigned long timeStamp = 0x00000000;
		foreach_const (EventOwner, ppEvent, pTrack->GetEventOwner()) {
			Event *pEvent = *ppEvent;
			unsigned long timeDelta = pEvent->GetTimeStamp() - timeStamp;
			timeStamp = pEvent->GetTimeStamp();
			if (!Event::WriteVariableFormat(sig, *pStreamMemory, timeDelta)) return false;
			if (!pEvent->Write(sig, *pStreamMemory, pEventPrev)) return false;
			pEventPrev = pEvent;
		}
		if (!MetaEvent_EndOfTrack::CheckEvent(pEventPrev)) {
			unsigned long timeDelta = 100;
			timeStamp += timeDelta;
			AutoPtr<Event> pEvent(new MetaEvent_EndOfTrack(timeStamp));
			if (!Event::WriteVariableFormat(sig, *pStreamMemory, timeDelta)) return false;
			if (!pEvent->Write(sig, *pStreamMemory, pEventPrev)) return false;
		}
		TrackChunkTop trackChunkTop;
		::memcpy(trackChunkTop.MTrk, "MTrk", sizeof(trackChunkTop.MTrk));
		Gura_PackULong(trackChunkTop.length, static_cast<unsigned long>(pStreamMemory->GetSize()));
		if (stream.Write(sig, &trackChunkTop, TrackChunkTop::Size) != TrackChunkTop::Size) {
			return false;
		}
		if (stream.Write(sig, pStreamMemory->GetPointer(),
					pStreamMemory->GetSize()) != pStreamMemory->GetSize()) {
			return false;
		}
	}
	return true;
}

bool SMF::Play(Signal sig, Port *pPort) const
{
	AutoPtr<EventOwner> pEventOwner(new EventOwner());
	foreach_const (TrackOwner, ppTrack, GetTrackOwner()) {
		const Track *pTrack = *ppTrack;
		foreach_const (EventOwner, ppEvent, pTrack->GetEventOwner()) {
			const Event *pEvent = *ppEvent;
			pEventOwner->push_back(Event::Reference(pEvent));
		}
	}
	pEventOwner->Sort();
	return pEventOwner->Play(sig, pPort, GetDivision(), 1000000);
}


}}
