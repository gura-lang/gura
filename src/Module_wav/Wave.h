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
	// values for wFormatTag
	enum {
		FORMAT_G723_ADPCM			= 0x0014,
		FORMAT_ANTEX_ADPCME			= 0x0033,
		FORMAT_G721_ADPCM			= 0x0040,
		FORMAT_APTX					= 0x0025,
		FORMAT_AUDIOFILE_AF36		= 0x0024,
		FORMAT_AUDIOFILE_AF10		= 0x0026,
		FORMAT_CONTROL_RES_VQLPC	= 0x0034,
		FORMAT_CONTROL_RES_CR10		= 0x0037,
		FORMAT_CREATIVE_ADPCM		= 0x0200,
		FORMAT_DOLBY_AC2			= 0x0030,
		FORMAT_DSPGROUP_TRUESPEECH	= 0x0022,
		FORMAT_DIGISTD				= 0x0015,
		FORMAT_DIGIFIX				= 0x0016,
		FORMAT_DIGIREAL				= 0x0035,
		FORMAT_DIGIADPCM			= 0x0036,
		FORMAT_ECHOSC1				= 0x0023,
		FORMAT_FM_TOWNS_SND			= 0x0300,
		FORMAT_IBM_CVSD				= 0x0005,
		FORMAT_OLIGSM				= 0x1000,
		FORMAT_OLIADPCM				= 0x1001,
		FORMAT_OLICELP				= 0x1002,
		FORMAT_OLISBC				= 0x1003,
		FORMAT_OLIOPR				= 0x1004,
		FORMAT_DVI_ADPCM			= 0x0011,
		FORMAT_UNKNOWN				= 0x0000,
		FORMAT_PCM					= 0x0001,
		FORMAT_ADPCM				= 0x0002,
		FORMAT_ALAW					= 0x0006,
		FORMAT_MULAW				= 0x0007,
		FORMAT_GSM610				= 0x0031,
		FORMAT_MPEG					= 0x0050,
		FORMAT_NMS_VBXADPCM			= 0x0038,
		FORMAT_OKI_ADPCM			= 0x0010,
		FORMAT_SIERRA_ADPCM			= 0x0013,
		FORMAT_SONARC				= 0x0021,
		FORMAT_MEDIASPACE_ADPCM		= 0x0012,
		FORMAT_YAMAHA_ADPCM			= 0x0020,
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
		Format(UShort wFormatTag, UShort nChannels, ULong nSamplesPerSec,
				ULong nAvgBytesPerSec, UShort nBlockAlign, UShort wBitsPerSample);
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
	bool SetAudio(Signal sig, const Audio *pAudio);
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
