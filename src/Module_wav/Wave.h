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
private:
	AutoPtr<Stream> _pStream;
public:
	Wave(Stream *pStream);
	void Clear();
	bool ReadChunks(Environment &env, Signal sig);
	void Print() const;
private:
	bool ReadSubChunk(Environment &env, Signal sig, size_t bytes);
	bool ReadStruct(Environment &env, Signal sig,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual);
	bool ReadString(Environment &env, Signal sig,
						char *str, size_t ckSizeMax, size_t ckSizeActual);
};

}}

#endif
