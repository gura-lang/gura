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
	unsigned short _division;
	unsigned long _mpqn;
	AutoPtr<TrackOwner> _pTrackOwner;
public:
	SMF();
	inline void SetFormat(unsigned short format) { _format = format; }
	inline unsigned short GetFormat() const { return _format; }
	inline void SetDivision(unsigned short division) { _division = division; }
	inline unsigned short GetDivision() const { return _division; }
	inline void SetMPQN(unsigned long mpqn) { _mpqn = mpqn; }
	inline unsigned long GetMPQN() const { return _mpqn; }
	inline TrackOwner &GetTrackOwner() { return *_pTrackOwner; }
	inline const TrackOwner &GetTrackOwner() const { return *_pTrackOwner; }
	void ResetTimeStamp();
	bool Read(Environment &env, Signal sig, Stream &stream);
	bool Write(Environment &env, Signal sig, Stream &stream);
	bool Play(Signal sig, Port *pPort) const;
};

}}

#endif
