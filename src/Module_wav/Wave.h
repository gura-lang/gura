#ifndef __WAVE_H__
#define __WAVE_H__
#include <gura.h>

Gura_BeginModule(wav)

#define FOURCC(c1, c2, c3, c4) \
	(static_cast<unsigned long>(c1) << 0) + (static_cast<unsigned long>(c2) << 8) + \
	(static_cast<unsigned long>(c3) << 16) + (static_cast<unsigned long>(c4) << 24)

class Wave {
public:
	enum {
		CKID_RIFF = FOURCC('R', 'I', 'F', 'F'),
		CKID_fmt  = FOURCC('f', 'm', 't', ' '),
		CKID_data = FOURCC('d', 'a', 't', 'a'),
	};
public:
	struct ChunkHdr {
	public:
		enum { Size = 8 };
		Gura_PackedULong_LE(ckID);
		Gura_PackedULong_LE(ckSize);
	public:
		void Print(int indentLevel) const;
	};
	class WAVEFORMAT {
	public:
		struct RawData {
			enum { Size = 16 };
			Gura_PackedUShort_LE(wFormatTag);
			Gura_PackedUShort_LE(nChannels);
			Gura_PackedULong_LE(nSamplesPerSec);
			Gura_PackedULong_LE(nAvgBytesPerSec);
			Gura_PackedUShort_LE(nBlockAlign);
			Gura_PackedUShort_LE(wBitsPerSample);
		};
	};
public:
	Wave();
	void Clear();
	bool Read(Environment &env, Signal sig, Stream &stream);
	void Print() const;
private:
	bool ReadSubChunk(Environment &env, Signal sig, Stream &stream, size_t bytes);
	bool ReadStruct(Environment &env, Signal sig, Stream &stream,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual);
	bool ReadString(Environment &env, Signal sig, Stream &stream,
						char *str, size_t ckSizeMax, size_t ckSizeActual);
};

}}

#endif
