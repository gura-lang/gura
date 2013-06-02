#ifndef __SMFREADER_H__
#define __SMFREADER_H__
#include <gura.h>

Gura_BeginModule(midi)

class Port;

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
	class Event {
	protected:
		unsigned long _timeStamp;
	public:
		inline Event(unsigned long timeStamp) : _timeStamp(timeStamp) {}
		inline unsigned long GetTimeStamp() const { return _timeStamp; }
		virtual bool Exec(Signal sig, Port *pPort) = 0;
	};
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
		bool Exec(Signal sig, Port *pPort);
	};
	class EventOwner : public EventList {
	public:
		~EventOwner();
		void Clear();
	};
	class MIDIEvent : public Event {
	private:
		unsigned char _msg1, _msg2, _msg3;
	public:
		inline MIDIEvent(unsigned long timeStamp,
					unsigned char msg1, unsigned char msg2, unsigned char msg3) :
			Event(timeStamp), _msg1(msg1), _msg2(msg2), _msg3(msg3) {}
		virtual bool Exec(Signal sig, Port *pPort);
	};
private:
	unsigned long _timeStampTbl[NUM_CHANNELS];
	unsigned long _timeStampSysEx;
	unsigned long _timeStampMeta;
	EventOwner _eventOwner;
public:
	SMFReader();
	inline EventOwner &GetEventOwner() { return _eventOwner; }
	void ResetTimeStamp();
	bool Read(Signal sig, Stream &stream);
private:
	bool NotifyMetaEvent(Signal sig, unsigned long deltaTime,
			unsigned char eventType, unsigned char data[], size_t length);
};

}}

#endif
