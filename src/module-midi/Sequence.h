#ifndef __SEQUENCE_H__
#define __SEQUENCE_H__
#include <gura.h>
#include "Track.h"
#include "Player.h"

Gura_BeginModuleScope(midi)

//-----------------------------------------------------------------------------
// Sequence
//-----------------------------------------------------------------------------
class Sequence {
public:
	struct HeaderChunkTop {
		enum { Size = 8 };
		char MThd[4];
		Gura_PackedUInt32_BE(header_length);
	};
	struct HeaderChunk {
		enum { Size = 6 };
		Gura_PackedUInt16_BE(format);
		Gura_PackedUInt16_BE(num_track_chunks);
		Gura_PackedUInt16_BE(division);
	};
	struct TrackChunkTop {
		enum { Size = 8 };
		char MTrk[4];
		Gura_PackedUInt32_BE(length);
	};
private:
	UInt16 _format;
	AutoPtr<TrackOwner> _pTrackOwner;
	AutoPtr<Property> _pProperty;
public:
	Sequence();
	inline void SetFormat(UInt16 format) { _format = format; }
	inline UInt16 GetFormat() const { return _format; }
	inline TrackOwner &GetTrackOwner() { return *_pTrackOwner; }
	inline const TrackOwner &GetTrackOwner() const { return *_pTrackOwner; }
	Property *GetProperty() { return _pProperty.get(); }
	void ResetTimeStamp();
	bool Read(Environment &env, Stream &stream);
	bool Write(Environment &env, Stream &stream);
	Player *GeneratePlayer(Signal &sig, Port *pPort, double speed, int cntRepeat) const;
	bool ParseStreamMML(Signal &sig, SimpleStream &stream);
	bool ParseStringMML(Signal &sig, const char *str);
};

Gura_EndModuleScope(midi)

#endif
