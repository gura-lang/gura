#ifndef __SMFREADER_H__
#define __SMFREADER_H__
#include <gura.h>

Gura_BeginModule(midi)

class SMFReader {
public:
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
public:
	inline SMFReader() {}
	bool Read(Signal sig, Stream &stream);
	virtual void OnMIDIEvent(unsigned long deltaTime, unsigned char msg1, unsigned char msg2) = 0;
	virtual void OnMIDIEvent(unsigned long deltaTime, unsigned char msg1, unsigned char msg2, unsigned char msg3) = 0;
	virtual void OnSysExEvent(unsigned long deltaTime) = 0;
	virtual void OnMetaEvent(unsigned long deltaTime, unsigned char eventType, unsigned char data[], size_t length) = 0;
};

}}

#endif
