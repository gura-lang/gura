#ifndef __CONTENT_H__
#define __CONTENT_H__
#include <gura.h>
#include "Track.h"

Gura_BeginModule(midi)

//-----------------------------------------------------------------------------
// Content
//-----------------------------------------------------------------------------
class Content {
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
	AutoPtr<TrackOwner> _pTrackOwner;
	AutoPtr<Property> _pProperty;
public:
	Content();
	inline void SetFormat(unsigned short format) { _format = format; }
	inline unsigned short GetFormat() const { return _format; }
	inline TrackOwner &GetTrackOwner() { return *_pTrackOwner; }
	inline const TrackOwner &GetTrackOwner() const { return *_pTrackOwner; }
	Property *GetProperty() { return _pProperty.get(); }
	void ResetTimeStamp();
	bool Read(Environment &env, Signal sig, Stream &stream);
	bool Write(Environment &env, Signal sig, Stream &stream);
	bool Play(Signal sig, Port *pPort, double speed, bool backgroundFlag) const;
	bool ParseMML(Signal sig, const ValueList &valList);
};

}}

#endif
