#ifndef __GURA_CODEC_H__
#define __GURA_CODEC_H__

#include "Common.h"
#include "Signal.h"

namespace Gura {

class Binary;
class CodecFactory;

//-----------------------------------------------------------------------------
// Codec
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec {
public:
	enum Result {
		RESULT_None,
		RESULT_Complete,
		RESULT_Error,
	};
	typedef std::map<unsigned short, unsigned short> Map;
protected:
	CodecFactory *_pCodecFactory;
	int _idxBuff;
	bool _processEOLFlag;
	char _buffOut[8];
public:
	inline Codec(CodecFactory *pCodecFactory, bool processEOLFlag) :
		_pCodecFactory(pCodecFactory), _idxBuff(0), _processEOLFlag(processEOLFlag) {}
	bool FollowChar(char &chConv);
	inline void SetProcessEOLFlag(bool processEOLFlag) {
		_processEOLFlag = processEOLFlag;
	}
	inline bool IsProcessEOL() const { return _processEOLFlag; }
	const char *GetName() const;
	virtual Result FeedChar(char ch, char &chConv) = 0;
	virtual Result Flush(char &chConv);
	static const char *EncodingFromLANG();
protected:
	inline void StoreChar(char ch) { _buffOut[_idxBuff++] = ch; }
};

//-----------------------------------------------------------------------------
// Codec_None
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_None : public Codec {
public:
	inline Codec_None() : Codec(NULL, false) {}
	virtual Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// Codec_Encoder
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_Encoder : public Codec {
public:
	inline Codec_Encoder(CodecFactory *pCodecFactory, bool processEOLFlag) :
										Codec(pCodecFactory, processEOLFlag) {}
	bool Encode(Signal sig, Binary &dst, const char *str);
	inline bool Encode(Signal sig, Binary &dst, const String &src) {
		return Encode(sig, dst, src.c_str());
	}
	Codec_Encoder *Duplicate() const;
};

//-----------------------------------------------------------------------------
// Codec_Decoder
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_Decoder : public Codec {
public:
	inline Codec_Decoder(CodecFactory *pCodecFactory, bool processEOLFlag) :
										Codec(pCodecFactory, processEOLFlag) {}
	bool Decode(Signal sig, String &dst, const char *buff, size_t bytes);
	bool Decode(Signal sig, String &dst, const Binary &src);
	Codec_Decoder *Duplicate() const;
};

//-----------------------------------------------------------------------------
// CodecFactory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecFactory {
public:
	typedef std::vector<CodecFactory *> List;
private:
	static List *_pList;
	String _name;
public:
	CodecFactory(const char *name);
	inline const char *GetName() const { return _name.c_str(); }
	virtual Codec_Encoder *CreateEncoder(bool processEOLFlag) = 0;
	virtual Codec_Decoder *CreateDecoder(bool processEOLFlag) = 0;
	static void Register(CodecFactory *pCodecFactory);
	static CodecFactory *Lookup(const char *name);
	static inline const List &GetList() { return *_pList; }
};

//-----------------------------------------------------------------------------
// UTF
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_Encoder_UTF : public Codec_Encoder {
protected:
	int _cntChars;
	unsigned long _codeUTF32;
public:
	inline Codec_Encoder_UTF(CodecFactory *pCodecFactory, bool processEOLFlag) :
		Codec_Encoder(pCodecFactory, processEOLFlag), _cntChars(0), _codeUTF32(0x00000000) {}
	inline unsigned long GetUTF32() const { return _codeUTF32; }
	virtual Result FeedChar(char ch, char &chConv);
	virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv) = 0;
};

class GURA_DLLDECLARE Codec_Decoder_UTF : public Codec_Decoder {
public:
	inline Codec_Decoder_UTF(CodecFactory *pCodecFactory, bool processEOLFlag) :
		Codec_Decoder(pCodecFactory, processEOLFlag) {}
	Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

}

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------
#define Gura_ImplementCodecFactory(symbol, dispname) \
class CodecFactory_##symbol : public CodecFactory {										\
public:																					\
	inline CodecFactory_##symbol(const char *name = (dispname)) : CodecFactory(name) {}	\
	virtual Codec_Encoder *CreateEncoder(bool processEOLFlag);									\
	virtual Codec_Decoder *CreateDecoder(bool processEOLFlag);									\
};																						\
Codec_Encoder *CodecFactory_##symbol::CreateEncoder(bool processEOLFlag) { return new Codec_Encoder_##symbol(this, processEOLFlag); } \
Codec_Decoder *CodecFactory_##symbol::CreateDecoder(bool processEOLFlag) { return new Codec_Decoder_##symbol(this, processEOLFlag); }

#define Gura_RegisterCodecFactory(symbol) \
CodecFactory::Register(new CodecFactory_##symbol())

#endif
