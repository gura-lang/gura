#ifndef __SMF_H__
#define __SMF_H__
#include <gura.h>

Gura_BeginModule(midi)

class Port;

class SMF {
public:
	enum {
		NUM_CHANNELS = 16,
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
	class Event {
	protected:
		unsigned long _timeStamp;
	public:
		inline Event(unsigned long timeStamp) : _timeStamp(timeStamp) {}
		inline unsigned long GetTimeStamp() const { return _timeStamp; }
		virtual bool Play(Signal sig, Port *pPort) = 0;
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
		bool Play(Signal sig, Port *pPort);
	};
	class EventOwner : public EventList {
	public:
		~EventOwner();
		void Clear();
		bool AddSysExEvent(Signal sig, unsigned long timeStamp,
									const unsigned char buff[], size_t length);
		bool AddMetaEvent(Signal sig, unsigned long timeStamp,
				unsigned char eventType, const unsigned char buff[], size_t length);
	};
	class MIDIEvent : public Event {
	protected:
		unsigned char _status;
		unsigned char _channel;
		size_t _nParams;
		unsigned char _params[2];
	public:
		inline MIDIEvent(unsigned long timeStamp, unsigned char status, unsigned char channel, size_t nParams) :
				Event(timeStamp), _status(status), _channel(channel), _nParams(nParams) {}
		inline unsigned char GetStatus() const { return _status; }
		inline unsigned char GetChannel() const { return _channel; }
		inline void SetParam1st(unsigned char param) { _params[0] = param; }
		inline void SetParam2nd(unsigned char param) { _params[1] = param; }
		inline size_t CountParams() const { return _nParams; }
		static bool CheckStatus(unsigned char status) {
			return 0x80 <= status && status < 0xf0;
		}
	};
	class MIDIEvent_NoteOff : public MIDIEvent {
	public:
		enum { Status = 0x80 };
	public:
		inline MIDIEvent_NoteOff(unsigned long timeStamp, unsigned char channel) :
										MIDIEvent(timeStamp, Status, channel, 2) {}
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MIDIEvent_NoteOn : public MIDIEvent {
	public:
		enum { Status = 0x90 };
	public:
		inline MIDIEvent_NoteOn(unsigned long timeStamp, unsigned char channel) :
										MIDIEvent(timeStamp, Status, channel, 2) {}
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MIDIEvent_PolyphonicKeyPressure : public MIDIEvent {
	public:
		enum { Status = 0xa0 };
	public:
		inline MIDIEvent_PolyphonicKeyPressure(unsigned long timeStamp, unsigned char channel) :
										MIDIEvent(timeStamp, Status, channel, 2) {}
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MIDIEvent_ControlChange : public MIDIEvent {
	public:
		enum { Status = 0xb0 };
	public:
		inline MIDIEvent_ControlChange(unsigned long timeStamp, unsigned char channel) :
										MIDIEvent(timeStamp, Status, channel, 2) {}
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MIDIEvent_ProgramChange : public MIDIEvent {
	public:
		enum { Status = 0xc0 };
	public:
		inline MIDIEvent_ProgramChange(unsigned long timeStamp, unsigned char channel) :
										MIDIEvent(timeStamp, Status, channel, 1) {}
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MIDIEvent_ChannelPressure : public MIDIEvent {
	public:
		enum { Status = 0xd0 };
	public:
		inline MIDIEvent_ChannelPressure(unsigned long timeStamp, unsigned char channel) :
										MIDIEvent(timeStamp, Status, channel, 1) {}
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MIDIEvent_PitchBendChange : public MIDIEvent {
	public:
		enum { Status = 0xe0 };
	public:
		inline MIDIEvent_PitchBendChange(unsigned long timeStamp, unsigned char channel) :
										MIDIEvent(timeStamp, Status, channel, 2) {}
		virtual bool Play(Signal sig, Port *pPort);
	};
	class SysExEvent : public Event {
	private:
		Binary _binary;
	public:
		inline SysExEvent(unsigned long timeStamp, const unsigned char buff[], size_t length) :
				Event(timeStamp), _binary(reinterpret_cast<const char *>(buff), length) {}
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent : public Event {
	protected:
		unsigned char _eventType;
	public:
		inline MetaEvent(unsigned long timeStamp, unsigned char eventType) :
									Event(timeStamp), _eventType(eventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length) = 0;
		static void SetError_TooShortMetaEvent(Signal sig);
	};
	class MetaEvent_Unknown : public MetaEvent {
	private:
		Binary _binary;
	public:
		inline MetaEvent_Unknown(unsigned long timeStamp, unsigned char eventType) :
											MetaEvent(timeStamp, eventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_SequenceNumber : public MetaEvent {
	public:
		enum { EventType = 0x00 };
	private:
		unsigned short _number;
	public:
		inline MetaEvent_SequenceNumber(unsigned long timeStamp) :
									MetaEvent(timeStamp, EventType), _number(0) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_TextEvent : public MetaEvent {
	public:
		enum { EventType = 0x01 };
	private:
		String _text;
	public:
		inline MetaEvent_TextEvent(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_CopyrightNotice : public MetaEvent {
	public:
		enum { EventType = 0x02 };
	private:
		String _text;
	public:
		inline MetaEvent_CopyrightNotice(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_SequenceOrTrackName : public MetaEvent {
	public:
		enum { EventType = 0x03 };
	private:
		String _text;
	public:
		inline MetaEvent_SequenceOrTrackName(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_InstrumentName : public MetaEvent {
	public:
		enum { EventType = 0x04 };
	private:
		String _text;
	public:
		inline MetaEvent_InstrumentName(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_LyricText : public MetaEvent {
	public:
		enum { EventType = 0x05 };
	private:
		String _text;
	public:
		inline MetaEvent_LyricText(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_MarkerText : public MetaEvent {
	public:
		enum { EventType = 0x06 };
	private:
		String _text;
	public:
		inline MetaEvent_MarkerText(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_CuePoint : public MetaEvent {
	public:
		enum { EventType = 0x07 };
	private:
		String _text;
	public:
		inline MetaEvent_CuePoint(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_MIDIChannelPrefixAssignment : public MetaEvent {
	public:
		enum { EventType = 0x20 };
	public:
		unsigned char _channel;
	public:
		inline MetaEvent_MIDIChannelPrefixAssignment(unsigned long timeStamp) :
									MetaEvent(timeStamp, EventType), _channel(0) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_EndOfTrack : public MetaEvent {
	public:
		enum { EventType = 0x2f };
	public:
 		inline MetaEvent_EndOfTrack(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_TempoSetting : public MetaEvent {
	public:
		enum { EventType = 0x51 };
	private:
		unsigned long _mpqn;
	public:
		inline MetaEvent_TempoSetting(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType), _mpqn(0) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_SMPTEOffset : public MetaEvent {
	public:
		enum { EventType = 0x54 };
	private:
		unsigned char _hour, _minute, _second, _frame, _subFrame;
	public:
		inline MetaEvent_SMPTEOffset(unsigned long timeStamp) :
				MetaEvent(timeStamp, EventType), _hour(0), _minute(0), _second(0),
				_frame(0), _subFrame(0) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_TimeSignature : public MetaEvent {
	public:
		enum { EventType = 0x58 };
	private:
		unsigned char _numerator, _denominator;
		unsigned char _metronome, _cnt32nd;
	public:
		inline MetaEvent_TimeSignature(unsigned long timeStamp) :
				MetaEvent(timeStamp, EventType), _numerator(0), _denominator(0),
				_metronome(0), _cnt32nd(0) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_KeySignature : public MetaEvent {
	public:
		enum { EventType = 0x59 };
	private:
		unsigned char _key, _scale;
	public:
		inline MetaEvent_KeySignature(unsigned long timeStamp) :
						MetaEvent(timeStamp, EventType), _key(0), _scale(0) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
	class MetaEvent_SequencerSpecificEvent : public MetaEvent {
	public:
		enum { EventType = 0x7f };
	private:
		Binary _binary;
	public:
		inline MetaEvent_SequencerSpecificEvent(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const unsigned char buff[], size_t length);
		virtual bool Play(Signal sig, Port *pPort);
	};
private:
	unsigned long _timeStampTbl[NUM_CHANNELS];
	unsigned long _timeStampSysEx;
	unsigned long _timeStampMeta;
public:
	SMF();
	void ResetTimeStamp();
	bool Read(Signal sig, Stream &stream, EventOwner &eventOwner);
};

}}

#endif
