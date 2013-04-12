//-----------------------------------------------------------------------------
// Gura codecs.basoc module
//-----------------------------------------------------------------------------
#ifndef __MODULE_CODECS_BASIC_H__
#define __MODULE_CODECS_BASIC_H__

#include <gura.h>

Gura_BeginModule(codecs_basic)

//-----------------------------------------------------------------------------
// USASCII
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecDecoder_USASCII : public CodecDecoder {
public:
	inline CodecDecoder_USASCII(bool delcrFlag) : CodecDecoder(delcrFlag) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

class GURA_DLLDECLARE CodecEncoder_USASCII : public CodecEncoder {
public:
	inline CodecEncoder_USASCII(bool addcrFlag) : CodecEncoder(addcrFlag) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// UTF8
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecDecoder_UTF8 : public CodecDecoder {
private:
	int _cntTrails;
public:
	inline CodecDecoder_UTF8(bool delcrFlag) : CodecDecoder(delcrFlag), _cntTrails(0) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

class GURA_DLLDECLARE CodecEncoder_UTF8 : public CodecEncoder {
private:
	int _cntTrails;
public:
	inline CodecEncoder_UTF8(bool addcrFlag) : CodecEncoder(addcrFlag), _cntTrails(0) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// UTF16LE
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CodecDecoder_UTF16LE : public CodecDecoder_UTF {
public:
	enum Stat {
		STAT_First, STAT_Second, STAT_LowerFirst, STAT_LowerSecond,
	};
private:
	Stat _stat;
	unsigned long _code;
	unsigned long _codeLower;
public:
	inline CodecDecoder_UTF16LE(bool delcrFlag) : CodecDecoder_UTF(delcrFlag),
			_stat(STAT_First), _code(0), _codeLower(0) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

class GURA_DLLDECLARE CodecEncoder_UTF16LE : public CodecEncoder_UTF {
public:
	inline CodecEncoder_UTF16LE(bool addcrFlag) : CodecEncoder_UTF(addcrFlag) {}
	virtual Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

}}

#endif
