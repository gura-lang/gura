//-----------------------------------------------------------------------------
// Gura codecs.chinese module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(codecs_chinese)

//-----------------------------------------------------------------------------
// Codec_CP936
//-----------------------------------------------------------------------------
UShort Codec_CP936::Decoder::DBCSToUTF16(UShort codeDBCS)
{
	return CP936ToUTF16(codeDBCS);
}

UShort Codec_CP936::Encoder::UTF16ToDBCS(UShort codeUTF16)
{
	return UTF16ToCP936(codeUTF16);
}

//-----------------------------------------------------------------------------
// Gura module functions: chinese
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP936>("cp936"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP936>("gb2312"));
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(codecs_chinese, chinese)

Gura_RegisterModule(codecs_chinese)
