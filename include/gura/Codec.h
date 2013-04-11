#ifndef __GURA_CODEC_H__
#define __GURA_CODEC_H__

#include "Common.h"
#include "Signal.h"

namespace Gura {

class Binary;
class CodecFactory;
class CodecDecoder;
class CodecEncoder;

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
	String _encoding;
	std::auto_ptr<CodecEncoder> _pEncoder;
	std::auto_ptr<CodecDecoder> _pDecoder;
public:
	Gura_DeclareReferenceAccessor(Codec);
public:
	Codec();
	Codec(const Codec &codec);
	inline const char *GetEncoding() const { return _encoding.c_str(); }
	inline bool IsInstalled() const { return !_encoding.empty(); }
	inline CodecEncoder *GetEncoder() { return _pEncoder.get(); }
	inline CodecDecoder *GetDecoder() { return _pDecoder.get(); }
	bool InstallCodec(Signal sig, const char *encoding, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// CodecBase
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecBase {
public:
	typedef std::map<unsigned short, unsigned short> Map;
protected:
	CodecFactory *_pCodecFactory;
	int _idxBuff;
	bool _processEOLFlag;
	char _buffOut[8];
public:
	inline CodecBase(CodecFactory *pCodecFactory, bool processEOLFlag) :
		_pCodecFactory(pCodecFactory), _idxBuff(0), _processEOLFlag(processEOLFlag) {}
	bool FollowChar(char &chConv);
	inline void SetProcessEOLFlag(bool processEOLFlag) {
		_processEOLFlag = processEOLFlag;
	}
	inline bool IsProcessEOL() const { return _processEOLFlag; }
	const char *GetName() const;
	virtual Codec::Result FeedChar(char ch, char &chConv) = 0;
	virtual Codec::Result Flush(char &chConv);
	static const char *EncodingFromLANG();
protected:
	inline void StoreChar(char ch) { _buffOut[_idxBuff++] = ch; }
};

//-----------------------------------------------------------------------------
// Codec_None
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_None : public CodecBase {
public:
	inline Codec_None() : CodecBase(NULL, false) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// CodecEncoder
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecEncoder : public CodecBase {
public:
	inline CodecEncoder(CodecFactory *pCodecFactory, bool processEOLFlag) :
										CodecBase(pCodecFactory, processEOLFlag) {}
	bool Encode(Signal sig, Binary &dst, const char *str);
	inline bool Encode(Signal sig, Binary &dst, const String &src) {
		return Encode(sig, dst, src.c_str());
	}
	CodecEncoder *Duplicate() const;
};

//-----------------------------------------------------------------------------
// CodecDecoder
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecDecoder : public CodecBase {
public:
	inline CodecDecoder(CodecFactory *pCodecFactory, bool processEOLFlag) :
										CodecBase(pCodecFactory, processEOLFlag) {}
	bool Decode(Signal sig, String &dst, const char *buff, size_t bytes);
	bool Decode(Signal sig, String &dst, const Binary &src);
	CodecDecoder *Duplicate() const;
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
	virtual CodecEncoder *CreateEncoder(bool processEOLFlag) = 0;
	virtual CodecDecoder *CreateDecoder(bool processEOLFlag) = 0;
	static void Register(CodecFactory *pCodecFactory);
	static CodecFactory *Lookup(const char *name);
	static inline const List &GetList() { return *_pList; }
};

//-----------------------------------------------------------------------------
// UTF
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecEncoder_UTF : public CodecEncoder {
protected:
	int _cntChars;
	unsigned long _codeUTF32;
public:
	inline CodecEncoder_UTF(CodecFactory *pCodecFactory, bool processEOLFlag) :
		CodecEncoder(pCodecFactory, processEOLFlag), _cntChars(0), _codeUTF32(0x00000000) {}
	inline unsigned long GetUTF32() const { return _codeUTF32; }
	virtual Codec::Result FeedChar(char ch, char &chConv);
	virtual Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv) = 0;
};

class GURA_DLLDECLARE CodecDecoder_UTF : public CodecDecoder {
public:
	inline CodecDecoder_UTF(CodecFactory *pCodecFactory, bool processEOLFlag) :
		CodecDecoder(pCodecFactory, processEOLFlag) {}
	Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

}

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------
#define Gura_ImplementCodecFactory(symbol, dispname) \
class CodecFactory_##symbol : public CodecFactory {										\
public:																					\
	inline CodecFactory_##symbol(const char *name = (dispname)) : CodecFactory(name) {}	\
	virtual CodecEncoder *CreateEncoder(bool processEOLFlag);									\
	virtual CodecDecoder *CreateDecoder(bool processEOLFlag);									\
};																						\
CodecEncoder *CodecFactory_##symbol::CreateEncoder(bool processEOLFlag) { return new CodecEncoder_##symbol(this, processEOLFlag); } \
CodecDecoder *CodecFactory_##symbol::CreateDecoder(bool processEOLFlag) { return new CodecDecoder_##symbol(this, processEOLFlag); }

#define Gura_RegisterCodecFactory(symbol) \
CodecFactory::Register(new CodecFactory_##symbol())

#endif
