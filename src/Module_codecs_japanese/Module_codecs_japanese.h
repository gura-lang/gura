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
class Codec_CP932 : public Codec_UTF {
public:
	class Decoder : public Codec_UTF::Decoder {
	private:
		unsigned short _codeCP932;
	public:
		inline Decoder(bool delcrFlag) :
					Codec_UTF::Decoder(delcrFlag), _codeCP932(0x0000) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class Encoder : public Codec_UTF::Encoder {
	public:
		inline Encoder(bool addcrFlag) :
					Codec_UTF::Encoder(addcrFlag) {}
		virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
	};
};

//-----------------------------------------------------------------------------
// EUCJP
//-----------------------------------------------------------------------------
class Codec_EUCJP : public Codec_UTF {
public:
	class Decoder : public Codec_UTF::Decoder {
	private:
		unsigned short _codeEUCJP;
	public:
		inline Decoder(bool delcrFlag) :
					Codec_UTF::Decoder(delcrFlag), _codeEUCJP(0x0000) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class Encoder : public Codec_UTF::Encoder {
	public:
		inline Encoder(bool addcrFlag) :
					Codec_UTF::Encoder(addcrFlag) {}
		virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
	};
};

//-----------------------------------------------------------------------------
// JIS
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
		unsigned short _codeJIS;
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
		virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
	};
};

}}

#endif
