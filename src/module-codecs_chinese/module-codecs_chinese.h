//-----------------------------------------------------------------------------
// Gura codecs.chinese module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CODECS_CHINESE_H__
#define __GURA_MODULE_CODECS_CHINESE_H__

#include <gura.h>

Gura_BeginModuleHeader(codecs_chinese)

//-----------------------------------------------------------------------------
// Codec_CP936
//-----------------------------------------------------------------------------
class Codec_CP936 : public Codec_DBCS {
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

Gura_EndModuleHeader(codecs_chinese)

#endif
