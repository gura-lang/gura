#ifndef __SMF_H__
#define __SMF_H__
#include <gura.h>
#include "Track.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// SMF
//-----------------------------------------------------------------------------
class SMF {
public:
	enum { NUM_CHANNELS = 16 };
	struct HeaderChunkTop {
		enum { Size = 8 };
		char MThd[4];
		Gura_PackedULong_BE(header_length);
	};
	struct HeaderChunk {
		enum { Size = 6 };
		Gura_PackedUShort_BE(format);
		Gura_PackedUShort_BE(num_track_chunks);
		Gura_PackedUShort_BE(division);
	};
	struct TrackChunkTop {
		enum { Size = 8 };
		char MTrk[4];
		Gura_PackedULong_BE(length);
	};
	class SysExEvent : public Event {
	private:
		Binary _binary;
	public:
		inline SysExEvent(const SysExEvent &event) : Event(event), _binary(event._binary) {}
		inline SysExEvent(unsigned long timeStamp, const Binary &binary) :
										Event(timeStamp), _binary(binary) {}
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent : public Event {
	protected:
		unsigned char _eventType;
	public:
		inline MetaEvent(const MetaEvent &event) : Event(event), _eventType(event._eventType) {}
		inline MetaEvent(unsigned long timeStamp, unsigned char eventType) :
									Event(timeStamp), _eventType(eventType) {}
		inline unsigned char GetEventType() const { return _eventType; }
		virtual bool Prepare(Signal sig, const Binary &binary) = 0;
		static bool Add(Signal sig, EventOwner &eventOwner, unsigned long timeStamp,
				unsigned char eventType, const Binary &binary);
		static void SetError_TooShortMetaEvent(Signal sig);
	};
	class MetaEvent_Unknown : public MetaEvent {
	private:
		Binary _binary;
	public:
		inline MetaEvent_Unknown(const MetaEvent_Unknown &event) : MetaEvent(event),
											_binary(event._binary) {}
		inline MetaEvent_Unknown(unsigned long timeStamp, unsigned char eventType) :
											MetaEvent(timeStamp, eventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_SequenceNumber : public MetaEvent {
	public:
		enum { EventType = 0x00 };
	private:
		unsigned short _number;
	public:
		inline MetaEvent_SequenceNumber(const MetaEvent_SequenceNumber &event) : MetaEvent(event),
											_number(event._number) {}
		inline MetaEvent_SequenceNumber(unsigned long timeStamp) :
									MetaEvent(timeStamp, EventType), _number(0) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_TextEvent : public MetaEvent {
	public:
		enum { EventType = 0x01 };
	private:
		String _text;
	public:
		inline MetaEvent_TextEvent(const MetaEvent_TextEvent &event) : MetaEvent(event),
											_text(event._text) {}
		inline MetaEvent_TextEvent(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_CopyrightNotice : public MetaEvent {
	public:
		enum { EventType = 0x02 };
	private:
		String _text;
	public:
		inline MetaEvent_CopyrightNotice(const MetaEvent_CopyrightNotice &event) : MetaEvent(event),
											_text(event._text) {}
		inline MetaEvent_CopyrightNotice(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_SequenceOrTrackName : public MetaEvent {
	public:
		enum { EventType = 0x03 };
	private:
		String _text;
	public:
		inline MetaEvent_SequenceOrTrackName(const MetaEvent_SequenceOrTrackName &event) : MetaEvent(event),
											_text(event._text) {}
		inline MetaEvent_SequenceOrTrackName(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_InstrumentName : public MetaEvent {
	public:
		enum { EventType = 0x04 };
	private:
		String _text;
	public:
		inline MetaEvent_InstrumentName(const MetaEvent_InstrumentName &event) : MetaEvent(event),
											_text(event._text) {}
		inline MetaEvent_InstrumentName(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_LyricText : public MetaEvent {
	public:
		enum { EventType = 0x05 };
	private:
		String _text;
	public:
		inline MetaEvent_LyricText(const MetaEvent_LyricText &event) : MetaEvent(event),
											_text(event._text) {}
		inline MetaEvent_LyricText(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_MarkerText : public MetaEvent {
	public:
		enum { EventType = 0x06 };
	private:
		String _text;
	public:
		inline MetaEvent_MarkerText(const MetaEvent_MarkerText &event) : MetaEvent(event),
											_text(event._text) {}
		inline MetaEvent_MarkerText(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_CuePoint : public MetaEvent {
	public:
		enum { EventType = 0x07 };
	private:
		String _text;
	public:
		inline MetaEvent_CuePoint(const MetaEvent_CuePoint &event) : MetaEvent(event),
											_text(event._text) {}
		inline MetaEvent_CuePoint(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_MIDIChannelPrefixAssignment : public MetaEvent {
	public:
		enum { EventType = 0x20 };
	public:
		unsigned char _channel;
	public:
		inline MetaEvent_MIDIChannelPrefixAssignment(const MetaEvent_MIDIChannelPrefixAssignment &event) : MetaEvent(event),
											_channel(event._channel) {}
		inline MetaEvent_MIDIChannelPrefixAssignment(unsigned long timeStamp) :
									MetaEvent(timeStamp, EventType), _channel(0) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_EndOfTrack : public MetaEvent {
	public:
		enum { EventType = 0x2f };
	public:
		inline MetaEvent_EndOfTrack(const MetaEvent_EndOfTrack &event) : MetaEvent(event) {}
 		inline MetaEvent_EndOfTrack(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_TempoSetting : public MetaEvent {
	public:
		enum { EventType = 0x51 };
	private:
		unsigned long _mpqn;
	public:
		inline MetaEvent_TempoSetting(const MetaEvent_TempoSetting &event) : MetaEvent(event),
											_mpqn(event._mpqn) {}
		inline MetaEvent_TempoSetting(unsigned long timeStamp) :
										MetaEvent(timeStamp, EventType), _mpqn(0) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_SMPTEOffset : public MetaEvent {
	public:
		enum { EventType = 0x54 };
	private:
		unsigned char _hour, _minute, _second, _frame, _subFrame;
	public:
		inline MetaEvent_SMPTEOffset(const MetaEvent_SMPTEOffset &event) : MetaEvent(event),
				_hour(event._hour), _minute(event._minute), _second(event._second),
				_frame(event._frame), _subFrame(event._subFrame) {}
		inline MetaEvent_SMPTEOffset(unsigned long timeStamp) :
				MetaEvent(timeStamp, EventType), _hour(0), _minute(0), _second(0),
				_frame(0), _subFrame(0) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_TimeSignature : public MetaEvent {
	public:
		enum { EventType = 0x58 };
	private:
		unsigned char _numerator, _denominator;
		unsigned char _metronome, _cnt32nd;
	public:
		inline MetaEvent_TimeSignature(const MetaEvent_TimeSignature &event) : MetaEvent(event),
				_numerator(event._numerator), _denominator(event._denominator),
				_metronome(event._metronome), _cnt32nd(event._cnt32nd) {}
		inline MetaEvent_TimeSignature(unsigned long timeStamp) :
				MetaEvent(timeStamp, EventType), _numerator(0), _denominator(0),
				_metronome(0), _cnt32nd(0) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_KeySignature : public MetaEvent {
	public:
		enum { EventType = 0x59 };
	private:
		unsigned char _key, _scale;
	public:
		inline MetaEvent_KeySignature(const MetaEvent_KeySignature &event) : MetaEvent(event),
								_key(event._key), _scale(event._scale) {}
		inline MetaEvent_KeySignature(unsigned long timeStamp) :
						MetaEvent(timeStamp, EventType), _key(0), _scale(0) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
	class MetaEvent_SequencerSpecificEvent : public MetaEvent {
	public:
		enum { EventType = 0x7f };
	private:
		Binary _binary;
	public:
		inline MetaEvent_SequencerSpecificEvent(const MetaEvent_SequencerSpecificEvent &event) : MetaEvent(event),
											_binary(event._binary) {}
		inline MetaEvent_SequencerSpecificEvent(unsigned long timeStamp) :
											MetaEvent(timeStamp, EventType) {}
		virtual bool Prepare(Signal sig, const Binary &binary);
		virtual bool Play(Signal sig, Port *pPort) const;
		virtual bool Write(Signal sig, Stream &stream) const;
		virtual String ToString() const;
		virtual Event *Clone() const;
	};
private:
	unsigned short _format;
	unsigned short _numTrackChunks;
	unsigned short _division;
	unsigned long _timeStampTbl[NUM_CHANNELS];
	unsigned long _timeStampSysEx;
	unsigned long _timeStampMeta;
	TrackOwner _trackOwner;
public:
	SMF();
	inline unsigned short GetFormat() const { return _format; }
	inline unsigned short GetNumTrackChunks() const { return _numTrackChunks; }
	inline unsigned short GetDivision() const { return _division; }
	inline TrackOwner &GetTrackOwner() { return _trackOwner; }
	inline const TrackOwner &GetTrackOwner() const { return _trackOwner; }
	void ResetTimeStamp();
	bool Read(Signal sig, Stream &stream);
	bool Write(Signal sig, Stream &stream);
	bool Play(Signal sig, Port *pPort) const;
};

}}

#endif
