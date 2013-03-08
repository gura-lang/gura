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
class GURA_DLLDECLARE Codec_Encoder_USASCII : public Codec_Encoder {
public:
	inline Codec_Encoder_USASCII(CodecFactory *pCodecFactory, bool processEOLFlag) :
			Codec_Encoder(pCodecFactory, processEOLFlag) {}
	virtual Result FeedChar(char ch, char &chConv);
};

class GURA_DLLDECLARE Codec_Decoder_USASCII : public Codec_Decoder {
public:
	inline Codec_Decoder_USASCII(CodecFactory *pCodecFactory, bool processEOLFlag) :
			Codec_Decoder(pCodecFactory, processEOLFlag) {}
	virtual Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// UTF8
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_Encoder_UTF8 : public Codec_Encoder {
private:
	int _cntTrails;
public:
	inline Codec_Encoder_UTF8(CodecFactory *pCodecFactory, bool processEOLFlag) :
			Codec_Encoder(pCodecFactory, processEOLFlag), _cntTrails(0) {}
	virtual Result FeedChar(char ch, char &chConv);
};

class GURA_DLLDECLARE Codec_Decoder_UTF8 : public Codec_Decoder {
private:
	int _cntTrails;
public:
	inline Codec_Decoder_UTF8(CodecFactory *pCodecFactory, bool processEOLFlag) :
			Codec_Decoder(pCodecFactory, processEOLFlag), _cntTrails(0) {}
	virtual Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// UTF16LE
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_Encoder_UTF16LE : public Codec_Encoder_UTF {
public:
	inline Codec_Encoder_UTF16LE(CodecFactory *pCodecFactory, bool processEOLFlag) :
			Codec_Encoder_UTF(pCodecFactory, processEOLFlag) {}
	virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

class GURA_DLLDECLARE Codec_Decoder_UTF16LE : public Codec_Decoder_UTF {
public:
	enum Stat {
		STAT_First, STAT_Second, STAT_LowerFirst, STAT_LowerSecond,
	};
private:
	Stat _stat;
	unsigned long _code;
	unsigned long _codeLower;
public:
	inline Codec_Decoder_UTF16LE(CodecFactory *pCodecFactory, bool processEOLFlag) :
			Codec_Decoder_UTF(pCodecFactory, processEOLFlag),
			_stat(STAT_First), _code(0), _codeLower(0) {}
	virtual Result FeedChar(char ch, char &chConv);
};

}}

#endif
