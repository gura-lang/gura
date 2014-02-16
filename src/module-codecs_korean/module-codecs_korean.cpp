//-----------------------------------------------------------------------------
// Gura codecs.korean module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(codecs_korean)

//-----------------------------------------------------------------------------
// Codec_CP949
//-----------------------------------------------------------------------------
UShort Codec_CP949::Decoder::DBCSToUTF16(UShort codeDBCS)
{
	return CP949ToUTF16(codeDBCS);
}

UShort Codec_CP949::Encoder::UTF16ToDBCS(UShort codeUTF16)
{
	return UTF16ToCP949(codeUTF16);
}

//-----------------------------------------------------------------------------
// Gura module functions: korean
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP949>("cp949"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP949>("euc-kr"));
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(codecs_korean, korean)

Gura_RegisterModule(codecs_korean)
