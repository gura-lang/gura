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
	class Format {
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
	private:
		int _cntRef;
		UShort _wFormatTag;
		UShort _nChannels;
		ULong _nSamplesPerSec;
		ULong _nAvgBytesPerSec;
		UShort _nBlockAlign;
		UShort _wBitsPerSample;
	public:
		Gura_DeclareReferenceAccessor(Format);
	public:
		Format();
		Format(const RawData &rawData);
	private:
		inline ~Format() {}
	public:
		void Print() const;
		Audio *ReadAudio(Signal sig, Stream &stream, size_t ckSize) const;
		bool Write(Signal sig, Stream &stream) const;
	};
private:
	AutoPtr<Format> _pFormat;
	AutoPtr<Audio> _pAudio;
public:
	Wave();
	void Clear();
	bool Read(Signal sig, Stream &stream);
	bool Write(Signal sig, Stream &stream);
	void Print() const;
	inline Format *GetFormat() const { return _pFormat.get(); }
	inline Audio *GetAudio() const { return _pAudio.get(); }
private:
	bool ReadSubChunk(Signal sig, Stream &stream, size_t bytes);
	static bool ReadStruct(Signal sig, Stream &stream,
						void *rawData, size_t ckSizeExpect, size_t ckSizeActual);
	static bool ReadString(Signal sig, Stream &stream,
						char *str, size_t ckSizeMax, size_t ckSizeActual);
};

}}

#endif
