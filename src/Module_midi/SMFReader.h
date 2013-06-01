#ifndef __SMFREADER_H__
#define __SMFREADER_H__
#include <gura.h>

Gura_BeginModule(midi)

class SMFReader {
public:
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
	virtual void OnMIDIEvent(unsigned long deltaTime, unsigned char data[], size_t length) = 0;
	virtual void OnSysExEvent(unsigned long deltaTime) = 0;
	virtual void OnMetaEvent(unsigned long deltaTime, unsigned char eventType, unsigned char data[], size_t length) = 0;
};

}}

#endif
