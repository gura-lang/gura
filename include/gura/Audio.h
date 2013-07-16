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
private:
	int _cntRef;
	Format _format;
	size_t _nChannels;
	size_t _len;
	UChar *_buff;
	AutoPtr<Memory> _pMemory;
public:
	Gura_DeclareReferenceAccessor(Audio);
public:
	inline Audio(Format format, size_t nChannels) : _cntRef(1),
				_format(format), _nChannels(nChannels), _len(0), _buff(NULL) {}
private:
	~Audio();
public:
	inline bool IsValid() const { return _buff != NULL; }
	inline Format GetFormat() const { return _format; }
	inline size_t GetChannels() const { return _nChannels; }
	inline size_t GetLength() const { return _len; }
	inline UChar *GetBuffer() { return _buff; }
	inline size_t GetBytesPerData() const {
		return (_format == FORMAT_U8 || _format == FORMAT_S8)? 1 : 2;
	}
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
	bool AllocBuffer(Signal sig, size_t len);
	void FreeBuffer();
	bool SetSineWave(Signal sig, size_t iChannel,
			size_t pitch, int phase, int amplitude, size_t offset, size_t len);
	static Format SymbolToFormat(Signal sig, const Symbol *pSymbol);
	static const Symbol *FormatToSymbol(Format format);
};

}

#endif
