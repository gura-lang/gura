#ifndef __GURA_AUDIO_H__
#define __GURA_AUDIO_H__
#include "Common.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Audio
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Audio {
public:
	enum Format {
		FORMAT_None,
		FORMAT_U8, FORMAT_S8,
		FORMAT_U16LE, FORMAT_S16LE,
		FORMAT_U16BE, FORMAT_S16BE,
	};
	enum {
		MUTE_U8 = 0x80,
		MUTE_S8 = 0x00,
		MUTE_U16LE = 0x8000,
		MUTE_S16LE = 0x0000,
		MUTE_U16BE = 0x8000,
		MUTE_S16BE = 0x0000,
	};
	class Chain {
	private:
		int _cntRef;
		Format _format;
		size_t _nChannels;
		size_t _nSamplesPerSec;
		AutoPtr<Memory> _pMemory;
		AutoPtr<Chain> _pNext;
	public:
		Gura_DeclareReferenceAccessor(Chain);
	public:
		Chain(Format format, size_t nChannels, size_t nSamplesPerSec);
	private:
		inline ~Chain() {}
	public:
		inline Format GetFormat() const { return _format; }
		inline size_t GetChannels() const { return _nChannels; }
		inline void SetSamplesPerSec(size_t nSamplesPerSec) { _nSamplesPerSec = nSamplesPerSec; }
		inline size_t GetSamplesPerSec() const { return _nSamplesPerSec; }
		inline size_t GetBytesPerSample() const { return Audio::GetBytesPerSample(_format); }
		inline void SetMemory(Memory *pMemory) { _pMemory.reset(pMemory); }
		inline Memory *GetMemory() { return _pMemory.get(); }
		inline const Memory *GetMemory() const { return _pMemory.get(); }
		inline UChar *GetPointer() {
			return _pMemory.IsNull()? NULL : reinterpret_cast<UChar *>(_pMemory->GetPointer());
		}
		inline const UChar *GetPointer() const {
			return _pMemory.IsNull()? NULL : reinterpret_cast<const UChar *>(_pMemory->GetPointer());
		}
		inline size_t GetBytes() const { return _pMemory.IsNull()? 0 : _pMemory->GetSize(); }
		inline size_t GetSamples() const { return GetBytes() / (GetChannels() * GetBytesPerSample()); }
		inline Chain *GetNext() { return _pNext.get(); }
		inline const Chain *GetNext() const { return _pNext.get(); }
		inline void SetNext(Chain *pNext) { _pNext.reset(pNext); }
		void FillMute();
	};
private:
	int _cntRef;
	Format _format;
	size_t _nChannels;
	size_t _nSamplesPerSec;
	Chain *_pChainLast;
	AutoPtr<Chain> _pChainTop;
public:
	Gura_DeclareReferenceAccessor(Audio);
public:
	Audio(Format format, size_t nChannels, size_t nSamplesPerSec);
private:
	~Audio();
public:
	inline bool IsValid() const { return !_pChainTop.IsNull(); }
	inline Format GetFormat() const { return _format; }
	inline size_t GetChannels() const { return _nChannels; }
	inline void SetSamplesPerSec(size_t nSamplesPerSec) { _nSamplesPerSec = nSamplesPerSec; }
	inline size_t GetSamplesPerSec() const { return _nSamplesPerSec; }
	inline Chain *GetChainTop() { return _pChainTop.get(); }
	inline const Chain *GetChainTop() const { return _pChainTop.get(); }
	inline size_t GetBytesPerSample() const { return GetBytesPerSample(_format); }
	inline void StoreData(UChar *buffp, int data) {
		switch (_format) {
		case FORMAT_U8: {
			*buffp = static_cast<UChar>((data + 0x80) & 0xff);
			break;
		}
		case FORMAT_S8: {
			*buffp = static_cast<UChar>(static_cast<char>(data & 0xff));
			break;
		}
		case FORMAT_U16LE: {
			UShort num = static_cast<UShort>((data + 0x8000) & 0xffff);
			*(buffp + 0) = static_cast<UChar>(num >> 0);
			*(buffp + 1) = static_cast<UChar>(num >> 8);
			break;
		}
		case FORMAT_S16LE: {
			UShort num = static_cast<UShort>(static_cast<Short>(data & 0xffff));
			*(buffp + 0) = static_cast<UChar>(num >> 0);
			*(buffp + 1) = static_cast<UChar>(num >> 8);
			break;
		}
		case FORMAT_U16BE: {
			UShort num = static_cast<UShort>((data + 0x8000) & 0xffff);
			*(buffp + 0) = static_cast<UChar>(num >> 8);
			*(buffp + 1) = static_cast<UChar>(num >> 0);
			break;
		}
		case FORMAT_S16BE: {
			UShort num = static_cast<UShort>(static_cast<Short>(data & 0xffff));
			*(buffp + 0) = static_cast<UChar>(num >> 8);
			*(buffp + 1) = static_cast<UChar>(num >> 0);
			break;
		}
		default:
			break;
		}
	}
	Chain *AllocChain(Signal sig, size_t nSamples);
	void FreeChain();
	size_t GetSamples() const;
	size_t GetBytes() const;
	bool Read(Environment &env, Signal sig, Stream &stream, const char *audioType);
	bool Write(Environment &env, Signal sig, Stream &stream, const char *audioType);
	bool AddSineWave(Signal sig, size_t iChannel,
							double freq, size_t nSamples, int amplitude);
public:
	inline static size_t GetBytesPerSample(Format format) {
		return (format == FORMAT_U8 || format == FORMAT_S8)? 1 : 2;
	}
	inline static size_t CalcBytes(Format format, size_t nChannels, size_t nSamples) {
		return GetBytesPerSample(format) * nChannels * nSamples;
	}
	inline static int GetAmplitudeMax(Format format) {
		return (format == FORMAT_U8 || format == FORMAT_S8)? 0x7f :
			(format == FORMAT_U16LE || format == FORMAT_S16LE ||
			 format == FORMAT_U16BE || format == FORMAT_S16BE)? 0x7fff : 0;
	}
	static Format SymbolToFormat(Signal sig, const Symbol *pSymbol);
	static const Symbol *FormatToSymbol(Format format);
};

//-----------------------------------------------------------------------------
// AudioStreamer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE AudioStreamer {
public:
	typedef std::vector<AudioStreamer *> List;
private:
	const char *_audioType;
	static List *_pList;
public:
	inline AudioStreamer(const char *audioType) : _audioType(audioType) {}
	inline const char *GetAudioType() const { return _audioType; }
	virtual bool IsResponsible(Signal sig, Stream &stream) = 0;
	virtual bool Read(Environment &env, Signal sig, Audio *pAudio, Stream &stream) = 0;
	virtual bool Write(Environment &env, Signal sig, Audio *pAudio, Stream &stream) = 0;
public:
	static void Register(AudioStreamer *pAudioStreamer);
	static AudioStreamer *FindResponsible(Signal sig, Stream &stream, const char *audioType);
	static AudioStreamer *FindByAudioType(const char *audioType);
};

}

#endif
