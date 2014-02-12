//-----------------------------------------------------------------------------
// Gura codecs.japanese module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CODECS_JAPANESE_H__
#define __GURA_MODULE_CODECS_JAPANESE_H__

#include <gura.h>

Gura_BeginModuleHeader(codecs_japanese)

enum Mode {
	MODE_JISC,
	MODE_JISX1983,
	MODE_JISX1990,
	MODE_ASCII,
	MODE_JISROMA,
	MODE_JISKANA,
};

//-----------------------------------------------------------------------------
// Codec_CP932
//-----------------------------------------------------------------------------
class Codec_CP932 : public Codec_DBCS {
public:
	class Decoder : public Codec_DBCS::Decoder {
	public:
		inline Decoder(bool delcrFlag) : Codec_DBCS::Decoder(delcrFlag) {}
		virtual UShort DBCSToUTF16(UShort codeDBCS);
	};
	class Encoder : public Codec_DBCS::Encoder {
	public:
		inline Encoder(bool addcrFlag) : Codec_DBCS::Encoder(addcrFlag) {}
		virtual UShort UTF16ToDBCS(UShort codeUTF16);
	};
};

//-----------------------------------------------------------------------------
// Codec_EUCJP
//-----------------------------------------------------------------------------
class Codec_EUCJP : public Codec_UTF {
public:
	class Decoder : public Codec_UTF::Decoder {
	private:
		UShort _codeEUCJP;
	public:
		inline Decoder(bool delcrFlag) :
					Codec_UTF::Decoder(delcrFlag), _codeEUCJP(0x0000) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class Encoder : public Codec_UTF::Encoder {
	public:
		inline Encoder(bool addcrFlag) :
					Codec_UTF::Encoder(addcrFlag) {}
		virtual Result FeedUTF32(ULong codeUTF32, char &chConv);
	};
};

//-----------------------------------------------------------------------------
// Codec_JIS
//-----------------------------------------------------------------------------
class Codec_JIS : public Codec_UTF {
public:
	class Decoder : public Codec_UTF::Decoder {
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
		UShort _codeJIS;
	public:
		inline Decoder(bool delcrFlag) :
				Codec_UTF::Decoder(delcrFlag),
				_mode(MODE_ASCII), _stat(STAT_Start), _codeJIS(0x0000) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class Encoder : public Codec_UTF::Encoder {
	private:
		Mode _mode;
	public:
		inline Encoder(bool addcrFlag) :
				Codec_UTF::Encoder(addcrFlag), _mode(MODE_ASCII) {}
		virtual Result FeedUTF32(ULong codeUTF32, char &chConv);
	};
};

Gura_EndModuleHeader(codecs_japanese)

#endif
