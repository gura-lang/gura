//-----------------------------------------------------------------------------
// Gura codec.japanese module
//-----------------------------------------------------------------------------
#ifndef __MODULE_CODECS_JAPANESE_H__
#define __MODULE_CODECS_JAPANESE_H__

#include <gura.h>
#include "Conv_Japanese.h"

Gura_BeginModule(codecs_japanese)

enum Mode {
	MODE_JISC,
	MODE_JISX1983,
	MODE_JISX1990,
	MODE_ASCII,
	MODE_JISROMA,
	MODE_JISKANA,
};

//-----------------------------------------------------------------------------
// CP932
//-----------------------------------------------------------------------------
class CodecEncoder_CP932 : public CodecEncoder_UTF {
public:
	inline CodecEncoder_CP932(CodecFactory *pCodecFactory, bool processEOLFlag) :
				CodecEncoder_UTF(pCodecFactory, processEOLFlag) {}
	virtual Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

class CodecDecoder_CP932 : public CodecDecoder_UTF {
private:
	unsigned short _codeCP932;
public:
	inline CodecDecoder_CP932(CodecFactory *pCodecFactory, bool processEOLFlag) :
				CodecDecoder_UTF(pCodecFactory, processEOLFlag), _codeCP932(0x0000) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// EUCJP
//-----------------------------------------------------------------------------
class CodecEncoder_EUCJP : public CodecEncoder_UTF {
public:
	inline CodecEncoder_EUCJP(CodecFactory *pCodecFactory, bool processEOLFlag) :
				CodecEncoder_UTF(pCodecFactory, processEOLFlag) {}
	virtual Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

class CodecDecoder_EUCJP : public CodecDecoder_UTF {
private:
	unsigned short _codeEUCJP;
public:
	inline CodecDecoder_EUCJP(CodecFactory *pCodecFactory, bool processEOLFlag) :
				CodecDecoder_UTF(pCodecFactory, processEOLFlag), _codeEUCJP(0x0000) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// JIS
//-----------------------------------------------------------------------------
class CodecEncoder_JIS : public CodecEncoder_UTF {
private:
	Mode _mode;
public:
	inline CodecEncoder_JIS(CodecFactory *pCodecFactory, bool processEOLFlag) :
			CodecEncoder_UTF(pCodecFactory, processEOLFlag), _mode(MODE_ASCII) {}
	virtual Codec::Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

class CodecDecoder_JIS : public CodecDecoder_UTF {
public:
	enum Stat {
		STAT_Start,
		STAT_Escape,
		STAT_Dollar, STAT_Ampersand, STAT_LParenthesis,
		STAT_JISX1990,
		STAT_Escape2nd, STAT_Dollar2nd,
	};
private:
	Mode _mode;
	Stat _stat;
	unsigned short _codeJIS;
public:
	inline CodecDecoder_JIS(CodecFactory *pCodecFactory, bool processEOLFlag) :
			CodecDecoder_UTF(pCodecFactory, processEOLFlag),
			_mode(MODE_ASCII), _stat(STAT_Start), _codeJIS(0x0000) {}
	virtual Codec::Result FeedChar(char ch, char &chConv);
};

}}

#endif
