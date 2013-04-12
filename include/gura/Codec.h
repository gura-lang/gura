#ifndef __GURA_CODEC_H__
#define __GURA_CODEC_H__

#include "Common.h"
#include "Signal.h"

namespace Gura {

class Binary;
class Codec;
class CodecDecoder;
class CodecEncoder;

//-----------------------------------------------------------------------------
// CodecFactory
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecFactory {
public:
	typedef std::vector<CodecFactory *> List;
private:
	static List *_pList;
	String _encoding;
public:
	CodecFactory(const char *encoding);
	inline const char *GetEncoding() const { return _encoding.c_str(); }
	virtual Codec *CreateCodec(bool delcrFlag, bool addcrFlag) = 0;
	static void Register(CodecFactory *pFactory);
	static CodecFactory *Lookup(const char *name);
	static inline const List &GetList() { return *_pList; }
};

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
private:
	int _cntRef;
	CodecFactory *_pFactory;
	std::auto_ptr<CodecDecoder> _pDecoder;
	std::auto_ptr<CodecEncoder> _pEncoder;
	static CodecFactory *_pFactory_None;
public:
	Gura_DeclareReferenceAccessor(Codec);
public:
	Codec(CodecFactory *pFactory, CodecDecoder *pDecoder, CodecEncoder *pEncoder);
private:
	inline Codec(const Codec &codec) {}
public:
	inline const char *GetEncoding() const { return _pFactory->GetEncoding(); }
	inline CodecFactory *GetFactory() { return _pFactory; }
	inline const CodecFactory *GetFactory() const { return _pFactory; }
	inline CodecDecoder *GetDecoder() { return _pDecoder.get(); }
	inline CodecEncoder *GetEncoder() { return _pEncoder.get(); }
	Codec *Duplicate() const;
	static Codec *CreateCodecNone(bool delcrFlag, bool addcrFlag);
	static Codec *CreateCodec(Signal sig, const char *encoding, bool delcrFlag, bool addcrFlag);
	static void Initialize();
public:
	static const char *EncodingFromLANG();
};

//-----------------------------------------------------------------------------
// CodecBase
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecBase {
public:
	typedef std::map<unsigned short, unsigned short> Map;
protected:
	int _idxBuff;
	char _buffOut[8];
public:
	inline CodecBase() : _idxBuff(0) {}
	bool FollowChar(char &chConv);
	virtual Codec::Result FeedChar(char ch, char &chConv) = 0;
	virtual Codec::Result Flush(char &chConv);
protected:
	inline void StoreChar(char ch) { _buffOut[_idxBuff++] = ch; }
};

//-----------------------------------------------------------------------------
// CodecDecoder
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecDecoder : public CodecBase {
private:
	bool _delcrFlag;
public:
	inline CodecDecoder(bool delcrFlag) : _delcrFlag(delcrFlag) {}
	inline void SetDelcrFlag(bool delcrFlag) { _delcrFlag = delcrFlag; }
	inline bool GetDelcrFlag() const { return _delcrFlag; }
	bool Decode(Signal sig, String &dst, const char *buff, size_t bytes);
	bool Decode(Signal sig, String &dst, const Binary &src);
	CodecDecoder *Duplicate() const;
};

//-----------------------------------------------------------------------------
// CodecEncoder
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecEncoder : public CodecBase {
private:
	bool _addcrFlag;
public:
	inline CodecEncoder(bool addcrFlag) : _addcrFlag(addcrFlag) {}
	bool Encode(Signal sig, Binary &dst, const char *str);
	inline void SetAddcrFlag(bool addcrFlag) { _addcrFlag = addcrFlag; }
	inline bool GetAddcrFlag() const { return _addcrFlag; }
	inline bool Encode(Signal sig, Binary &dst, const String &src) {
		return Encode(sig, dst, src.c_str());
	}
	CodecEncoder *Duplicate() const;
};

//-----------------------------------------------------------------------------
// None
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecFactory_None : public CodecFactory {
public:
	inline CodecFactory_None(const char *name = "none") : CodecFactory(name) {}
	virtual Codec *CreateCodec(bool delcrFlag, bool addcrFlag);
};

class GURA_DLLDECLARE CodecDecoder_None : public CodecDecoder {
public:
	inline CodecDecoder_None(bool delcrFlag) : CodecDecoder(delcrFlag) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

class GURA_DLLDECLARE CodecEncoder_None : public CodecEncoder {
public:
	inline CodecEncoder_None(bool addcrFlag) : CodecEncoder(addcrFlag) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// UTF
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecDecoder_UTF : public CodecDecoder {
public:
	inline CodecDecoder_UTF(bool delcrFlag) : CodecDecoder(delcrFlag) {}
	Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

class GURA_DLLDECLARE CodecEncoder_UTF : public CodecEncoder {
protected:
	int _cntChars;
	unsigned long _codeUTF32;
public:
	inline CodecEncoder_UTF(bool addcrFlag) :
			CodecEncoder(addcrFlag), _cntChars(0), _codeUTF32(0x00000000) {}
	inline unsigned long GetUTF32() const { return _codeUTF32; }
	virtual Codec::Result FeedChar(char ch, char &chConv);
	virtual Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv) = 0;
};

}

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------
#define Gura_ImplementCodecFactory(symbol, encoding_) \
class CodecFactory_##symbol : public CodecFactory {										\
public:																					\
	inline CodecFactory_##symbol(const char *encoding = (encoding_)) : CodecFactory(encoding) {}	\
	virtual Codec *CreateCodec(bool delcrFlag, bool addcrFlag);							\
};																						\
Codec *CodecFactory_##symbol::CreateCodec(bool delcrFlag, bool addcrFlag) {				\
	return new Codec(this,																\
			new CodecDecoder_##symbol(delcrFlag),										\
			new CodecEncoder_##symbol(addcrFlag));										\
}

#define Gura_RegisterCodecFactory(symbol) \
CodecFactory::Register(new CodecFactory_##symbol())

#endif
