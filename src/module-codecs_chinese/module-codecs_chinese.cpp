//-----------------------------------------------------------------------------
// Gura codecs.chinese module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(codecs_chinese)

//-----------------------------------------------------------------------------
// Codec_CP936
//-----------------------------------------------------------------------------
bool Codec_CP936::Decoder::IsLeadByte(UChar ch)
{
	return ch > 0x80;
}

UShort Codec_CP936::Decoder::DBCSToUTF16(UShort codeDBCS)
{
	return CP936ToUTF16(codeDBCS);
}

UShort Codec_CP936::Encoder::UTF16ToDBCS(UShort codeUTF16)
{
	return UTF16ToCP936(codeUTF16);
}

//-----------------------------------------------------------------------------
// Codec_CP950
//-----------------------------------------------------------------------------
UShort Codec_CP950::Decoder::DBCSToUTF16(UShort codeDBCS)
{
	return CP950ToUTF16(codeDBCS);
}

UShort Codec_CP950::Encoder::UTF16ToDBCS(UShort codeUTF16)
{
	return UTF16ToCP950(codeUTF16);
}

//-----------------------------------------------------------------------------
// Gura module functions: chinese
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP936>("cp936"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP936>("gb2312"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP936>("gbk"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP950>("cp950"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP950>("big5"));
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(codecs_chinese, chinese)

Gura_RegisterModule(codecs_chinese)
