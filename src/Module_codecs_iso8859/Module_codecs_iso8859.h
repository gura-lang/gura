//-----------------------------------------------------------------------------
// Gura codecs.iso8859 module
//-----------------------------------------------------------------------------
#ifndef __MODULE_CODECS_ISO8859_H__
#define __MODULE_CODECS_ISO8859_H__

#include <gura.h>

Gura_BeginModule(codecs_iso8859)

//-----------------------------------------------------------------------------
// Codec_Encoder_ISO8859
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859 : public Codec_Encoder_UTF {
private:
	const unsigned short *_codeTbl;
	Map *&_pMap;
public:
	inline Codec_Encoder_ISO8859(CodecFactory *pCodecFactory, bool processEOLFlag, const unsigned short *codeTbl, Map *&pMap) :
			Codec_Encoder_UTF(pCodecFactory, processEOLFlag), _codeTbl(codeTbl), _pMap(pMap) {}
	virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
};

//-----------------------------------------------------------------------------
// Codec_Decoder_ISO8859
//-----------------------------------------------------------------------------
class Codec_Decoder_ISO8859 : public Codec_Decoder_UTF {
private:
	const unsigned short *_codeTbl;
public:
	inline Codec_Decoder_ISO8859(CodecFactory *pCodecFactory, bool processEOLFlag, const unsigned short *codeTbl) :
			Codec_Decoder_UTF(pCodecFactory, processEOLFlag), _codeTbl(codeTbl) {}
	virtual Result FeedChar(char ch, char &chConv);
};

//-----------------------------------------------------------------------------
// ISO8859-1
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_1 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_1(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_1 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_1(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-2
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_2 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_2(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_2 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_2(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-3
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_3 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_3(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_3 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_3(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-4
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_4 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_4(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_4 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_4(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-5
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_5 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_5(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_5 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_5(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-6
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_6 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_6(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_6 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_6(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-7
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_7 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_7(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_7 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_7(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-8
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_8 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_8(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_8 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_8(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-9
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_9 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_9(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_9 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_9(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-10
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_10 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_10(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_10 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_10(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-11
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_11 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_11(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_11 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_11(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-13
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_13 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_13(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_13 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_13(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-14
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_14 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_14(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_14 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_14(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-15
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_15 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_15(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_15 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_15(CodecFactory *pCodecFactory, bool processEOLFlag);
};

//-----------------------------------------------------------------------------
// ISO8859-16
//-----------------------------------------------------------------------------
class Codec_Encoder_ISO8859_16 : public Codec_Encoder_ISO8859 {
public:
	Codec_Encoder_ISO8859_16(CodecFactory *pCodecFactory, bool processEOLFlag);
};

class Codec_Decoder_ISO8859_16 : public Codec_Decoder_ISO8859 {
public:
	Codec_Decoder_ISO8859_16(CodecFactory *pCodecFactory, bool processEOLFlag);
};

}}

#endif
