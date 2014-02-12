//-----------------------------------------------------------------------------
// Gura codecs.korean module
//-----------------------------------------------------------------------------
#ifndef __GURA_MODULE_CODECS_KOREAN_H__
#define __GURA_MODULE_CODECS_KOREAN_H__

#include <gura.h>

Gura_BeginModuleHeader(codecs_korean)

//-----------------------------------------------------------------------------
// Codec_CP949
//-----------------------------------------------------------------------------
class Codec_CP949 : public Codec_DBCS {
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

Gura_EndModuleHeader(codecs_korean)

#endif
