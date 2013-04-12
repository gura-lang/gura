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
class GURA_DLLDECLARE Codec_USASCII : public Codec {
public:
	class GURA_DLLDECLARE Decoder : public Codec::Decoder {
	public:
		inline Decoder(bool delcrFlag) : Codec::Decoder(delcrFlag) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class GURA_DLLDECLARE Encoder : public Codec::Encoder {
	public:
		inline Encoder(bool addcrFlag) : Codec::Encoder(addcrFlag) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
};

//-----------------------------------------------------------------------------
// UTF8
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_UTF8 : public Codec {
public:
	class GURA_DLLDECLARE Decoder : public Codec::Decoder {
	private:
		int _cntTrails;
	public:
		inline Decoder(bool delcrFlag) : Codec::Decoder(delcrFlag), _cntTrails(0) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class GURA_DLLDECLARE Encoder : public Codec::Encoder {
	private:
		int _cntTrails;
	public:
		inline Encoder(bool addcrFlag) : Codec::Encoder(addcrFlag), _cntTrails(0) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
};

//-----------------------------------------------------------------------------
// UTF16LE
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Codec_UTF16LE : public Codec_UTF {
public:
	class GURA_DLLDECLARE Decoder : public Codec_UTF::Decoder {
	public:
		enum Stat {
			STAT_First, STAT_Second, STAT_LowerFirst, STAT_LowerSecond,
		};
	private:
		Stat _stat;
		unsigned long _code;
		unsigned long _codeLower;
	public:
		inline Decoder(bool delcrFlag) : Codec_UTF::Decoder(delcrFlag),
				_stat(STAT_First), _code(0), _codeLower(0) {}
		virtual Result FeedChar(char ch, char &chConv);
	};
	class GURA_DLLDECLARE Encoder : public Codec_UTF::Encoder {
	public:
		inline Encoder(bool addcrFlag) : Codec_UTF::Encoder(addcrFlag) {}
		virtual Result FeedUTF32(unsigned long codeUTF32, char &chConv);
	};
};

}}

#endif
