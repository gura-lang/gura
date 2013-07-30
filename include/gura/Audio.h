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
		Chain *ConvertFormat(Format format) const;
	};
public:
	class GURA_DLLDECLARE IteratorEach : public Iterator {
	private:
		AutoPtr<Audio> _pAudio;
		size_t _iChannel;
		size_t _offset;
		AutoPtr<Chain> _pChain;
		const UChar *_buffp;
		size_t _cntRest;
		bool _doneFlag;
	public:
		IteratorEach(Audio *pAudio, size_t iChannel, size_t offset);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
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
	inline static UChar *PutData(Format format, UChar *buffp, int data) {
		switch (format) {
		case FORMAT_U8: {
			*buffp = static_cast<UChar>((data + 0x80) & 0xff);
			return buffp + 1;
		}
		case FORMAT_S8: {
			*buffp = static_cast<UChar>(static_cast<char>(data & 0xff));
			return buffp + 1;
		}
		case FORMAT_U16LE: {
			UShort num = static_cast<UShort>((data + 0x8000) & 0xffff);
			*(buffp + 0) = static_cast<UChar>(num >> 0);
			*(buffp + 1) = static_cast<UChar>(num >> 8);
			return buffp + 2;
		}
		case FORMAT_S16LE: {
			UShort num = static_cast<UShort>(static_cast<Short>(data & 0xffff));
			*(buffp + 0) = static_cast<UChar>(num >> 0);
			*(buffp + 1) = static_cast<UChar>(num >> 8);
			return buffp + 2;
		}
		case FORMAT_U16BE: {
			UShort num = static_cast<UShort>((data + 0x8000) & 0xffff);
			*(buffp + 0) = static_cast<UChar>(num >> 8);
			*(buffp + 1) = static_cast<UChar>(num >> 0);
			return buffp + 2;
		}
		case FORMAT_S16BE: {
			UShort num = static_cast<UShort>(static_cast<Short>(data & 0xffff));
			*(buffp + 0) = static_cast<UChar>(num >> 8);
			*(buffp + 1) = static_cast<UChar>(num >> 0);
			return buffp + 2;
		}
		default:
			break;
		}
		return buffp;
	}
	inline static const UChar *GetData(Format format, const UChar *buffp, int *pData) {
		switch (format) {
		case FORMAT_U8: {
			*pData = static_cast<int>(*buffp) - 0x80;
			return buffp + 1;
		}
		case FORMAT_S8: {
			*pData = static_cast<int>(static_cast<char>(*buffp));
			return buffp + 1;
		}
		case FORMAT_U16LE: {
			UShort num =
				(static_cast<UShort>(*(buffp + 0)) << 0) +
				(static_cast<UShort>(*(buffp + 1)) << 8);
			*pData = static_cast<int>(num) - 0x8000;
			return buffp + 2;
		}
		case FORMAT_S16LE: {
			UShort num =
				(static_cast<UShort>(*(buffp + 0)) << 0) +
				(static_cast<UShort>(*(buffp + 1)) << 8);
			*pData = static_cast<int>(static_cast<Short>(num));
			return buffp + 2;
		}
		case FORMAT_U16BE: {
			UShort num =
				(static_cast<UShort>(*(buffp + 0)) << 8) +
				(static_cast<UShort>(*(buffp + 1)) << 0);
			*pData = static_cast<int>(num) - 0x8000;
			return buffp + 2;
		}
		case FORMAT_S16BE: {
			UShort num =
				(static_cast<UShort>(*(buffp + 0)) << 8) +
				(static_cast<UShort>(*(buffp + 1)) << 0);
			*pData = static_cast<int>(static_cast<Short>(num));
			return buffp + 2;
		}
		default:
			break;
		}
		return buffp;
	}
	void AddChain(Chain *pChain);
	Chain *AllocChain(size_t nSamples);
	void FreeChain();
	size_t GetSamples() const;
	size_t GetBytes() const;
	bool PutData(size_t iChannel, size_t offset, int data);
	bool GetData(size_t iChannel, size_t offset, int *pData);
	bool StoreData(Environment &env, Signal sig,
						size_t iChannel, size_t offset, Iterator *pIterator);
	bool Read(Environment &env, Signal sig, Stream &stream, const char *audioType);
	bool Write(Environment &env, Signal sig, Stream &stream, const char *audioType);
	bool AddSineWave(Signal sig, size_t iChannel,
							double freq, size_t nSamples, int amplitude);
	Audio *ConvertFormat(Format format) const;
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
