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
class Codec_Encoder_CP932 : public Codec_Encoder_UTF {
public:
	inline Codec_Encoder_CP932(CodecFactory *pCodecFactory, bool processEOLFlag) :
				Codec_Encoder_UTF(pCodecFactory, processEOLFlag) {}
	virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

class Codec_Decoder_CP932 : public Codec_Decoder_UTF {
private:
	unsigned short _codeCP932;
public:
	inline Codec_Decoder_CP932(CodecFactory *pCodecFactory, bool processEOLFlag) :
				Codec_Decoder_UTF(pCodecFactory, processEOLFlag), _codeCP932(0x0000) {}
	virtual Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// EUCJP
//-----------------------------------------------------------------------------
class Codec_Encoder_EUCJP : public Codec_Encoder_UTF {
public:
	inline Codec_Encoder_EUCJP(CodecFactory *pCodecFactory, bool processEOLFlag) :
				Codec_Encoder_UTF(pCodecFactory, processEOLFlag) {}
	virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

class Codec_Decoder_EUCJP : public Codec_Decoder_UTF {
private:
	unsigned short _codeEUCJP;
public:
	inline Codec_Decoder_EUCJP(CodecFactory *pCodecFactory, bool processEOLFlag) :
				Codec_Decoder_UTF(pCodecFactory, processEOLFlag), _codeEUCJP(0x0000) {}
	virtual Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// JIS
//-----------------------------------------------------------------------------
class Codec_Encoder_JIS : public Codec_Encoder_UTF {
private:
	Mode _mode;
public:
	inline Codec_Encoder_JIS(CodecFactory *pCodecFactory, bool processEOLFlag) :
			Codec_Encoder_UTF(pCodecFactory, processEOLFlag), _mode(MODE_ASCII) {}
	virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

class Codec_Decoder_JIS : public Codec_Decoder_UTF {
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
	inline Codec_Decoder_JIS(CodecFactory *pCodecFactory, bool processEOLFlag) :
			Codec_Decoder_UTF(pCodecFactory, processEOLFlag),
			_mode(MODE_ASCII), _stat(STAT_Start), _codeJIS(0x0000) {}
	virtual Result FeedChar(char ch, char &chConv);
};

}}

#endif
