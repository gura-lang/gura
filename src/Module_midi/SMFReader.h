#ifndef __SMFREADER_H__
#define __SMFREADER_H__
#include <gura.h>

Gura_BeginModule(midi)

class SMFReader {
public:
	enum {
		NUM_CHANNELS = 16,
	};
#if 0
	enum MIDIEvent {
		MIDIEVT_None,
		MIDIEVT_NoteOff,
		MIDIEVT_NoteOn,
		MIDIEVT_PolyphonicKeyPressure,
		MIDIEVT_ControlChange,
		MIDIEVT_ProgramChange,
		MIDIEVT_ChannelPressure,
		MIDIEVT_PitchBendChange,
	};
	enum MetaEvent {
		METAEVT_None,
		METAEVT_SequenceNumber,
		METAEVT_TextEvent,
		METAEVT_CopyrightNotice,
		METAEVT_SequenceOrTrackName,
		METAEVT_InstrumentName,
		METAEVT_LyricText,
		METAEVT_MarkerText,
		METAEVT_CuePoint,
		METAEVT_MIDIChannelPrefixAssignment,
		METAEVT_EndOfTrack,
		METAEVT_TempoSetting,
		METAEVT_SMPTEOffset,
		METAEVT_TimeSignature,
		METAEVT_KeySignature,
		METAEVT_SequencerSpecificEvent,
	};
#endif
	struct HeaderChunkTop {
		enum { Size = 8 };
		char MThd[4];
		Gura_PackedULong_BE(header_length);
	};
	struct HeaderChunk {
		Gura_PackedUShort_BE(format);
		Gura_PackedUShort_BE(num_track_chunks);
		Gura_PackedUShort_BE(division);
	};
	struct TrackChunkTop {
		enum { Size = 8 };
		char MTrk[4];
		Gura_PackedULong_BE(length);
	};
private:
	unsigned long _timeStampTbl[NUM_CHANNELS];
	unsigned long _timeStampSysEx;
	unsigned long _timeStampMeta;
public:
	SMFReader();
	void ResetTimeStamp();
	bool Read(Signal sig, Stream &stream);
	virtual void OnMIDIEvent(unsigned long timeStamp, unsigned char msg1, unsigned char msg2) = 0;
	virtual void OnMIDIEvent(unsigned long timeStamp, unsigned char msg1, unsigned char msg2, unsigned char msg3) = 0;
	virtual void OnSysExEvent(unsigned long timeStamp) = 0;
	virtual void OnMetaEvent_SequenceNumber(unsigned long timeStamp);
	virtual void OnMetaEvent_Text(unsigned long timeStamp, const char *text);
	virtual void OnMetaEvent_CopyrightNotice(unsigned long timeStamp, const char *text);
	virtual void OnMetaEvent_SequenceTrackName(unsigned long timeStamp, const char *text);
	virtual void OnMetaEvent_InstrumentName(unsigned long timeStamp, const char *text);
	virtual void OnMetaEvent_Lylic(unsigned long timeStamp, const char *text);
	virtual void OnMetaEvent_EndOfTrack(unsigned long timeStamp);
	virtual void OnMetaEvent_SetTempo(unsigned long timeStamp);
	virtual void OnMetaEvent_TimeSignature(unsigned long timeStamp);
	virtual void OnMetaEvent_KeySignature(unsigned long timeStamp);
private:
	bool NotifyMetaEvent(Signal sig, unsigned long deltaTime,
			unsigned char eventType, unsigned char data[], size_t length);
};

}}

#endif
