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
