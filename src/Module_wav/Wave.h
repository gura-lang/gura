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
	// Defined wFormatTag
	enum {
		FORMAT_G723_ADPCM			= 0x0014, // Antex Electronics Corporation
		FORMAT_ANTEX_ADPCME			= 0x0033, // Antex Electronics Corporation
		FORMAT_G721_ADPCM			= 0x0040, // Antex Electronics Corporation
		FORMAT_APTX					= 0x0025, // Audio Processing Technology
		FORMAT_AUDIOFILE_AF36		= 0x0024, // Audiofile, Inc.
		FORMAT_AUDIOFILE_AF10		= 0x0026, // Audiofile, Inc.
		FORMAT_CONTROL_RES_VQLPC	= 0x0034, // Control Resources Limited
		FORMAT_CONTROL_RES_CR10		= 0x0037, // Control Resources Limited
		FORMAT_CREATIVE_ADPCM		= 0x0200, // Creative Labs, Inc
		FORMAT_DOLBY_AC2			= 0x0030, // Dolby Laboratories
		FORMAT_DSPGROUP_TRUESPEECH	= 0x0022, // DSP Group, Inc
		FORMAT_DIGISTD				= 0x0015, // DSP Solutions, Inc.
		FORMAT_DIGIFIX				= 0x0016, // DSP Solutions, Inc.
		FORMAT_DIGIREAL				= 0x0035, // DSP Solutions, Inc.
		FORMAT_DIGIADPCM			= 0x0036, // DSP Solutions, Inc.
		FORMAT_ECHOSC1				= 0x0023, // Echo Speech Corporation
		FORMAT_FM_TOWNS_SND			= 0x0300, // Fujitsu Corp.
		FORMAT_IBM_CVSD				= 0x0005, // IBM Corporation
		FORMAT_OLIGSM				= 0x1000, // Ing C. Olivetti & C., S.p.A.
		FORMAT_OLIADPCM				= 0x1001, // Ing C. Olivetti & C., S.p.A.
		FORMAT_OLICELP				= 0x1002, // Ing C. Olivetti & C., S.p.A.
		FORMAT_OLISBC				= 0x1003, // Ing C. Olivetti & C., S.p.A.
		FORMAT_OLIOPR				= 0x1004, // Ing C. Olivetti & C., S.p.A.
		FORMAT_DVI_ADPCM			= 0x0011, // Intel Corporation
		FORMAT_UNKNOWN				= 0x0000, // Microsoft Corporation
		FORMAT_PCM					= 0x0001, // Microsoft Corporation
		FORMAT_ADPCM				= 0x0002, // Microsoft Corporation
		FORMAT_ALAW					= 0x0006, // Microsoft Corporation
		FORMAT_MULAW				= 0x0007, // Microsoft Corporation
		FORMAT_GSM610				= 0x0031, // Microsoft Corporation
		FORMAT_MPEG					= 0x0050, // Microsoft Corporation
		FORMAT_NMS_VBXADPCM			= 0x0038, // Natural MicroSystems
		FORMAT_OKI_ADPCM			= 0x0010, // OKI
		FORMAT_SIERRA_ADPCM			= 0x0013, // Sierra Semiconductor Corp
		FORMAT_SONARC				= 0x0021, // Speech Compression
		FORMAT_MEDIASPACE_ADPCM		= 0x0012, // Videologic
		FORMAT_YAMAHA_ADPCM			= 0x0020, // Yamaha Corporation of America
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
