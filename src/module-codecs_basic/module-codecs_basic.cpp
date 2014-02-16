//-----------------------------------------------------------------------------
// Gura codecs.basic module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(codecs_basic)

//-----------------------------------------------------------------------------
// Codec_USASCII
//-----------------------------------------------------------------------------
Codec::Result Codec_USASCII::Decoder::FeedChar(char ch, char &chConv)
{
	// acceptable character code is between 0x00 and 0x7f
	if (ch & 0x80) return RESULT_Error;
	if (GetDelcrFlag() && ch == '\r') return RESULT_None;
	chConv = ch;
	return RESULT_Complete;
}

Codec::Result Codec_USASCII::Encoder::FeedChar(char ch, char &chConv)
{
	// acceptable character code is between 0x00 and 0x7f
	if (ch & 0x80) return RESULT_Error;
	if (GetAddcrFlag() && ch == '\n') {
		StoreChar('\n');
		chConv = '\r';
	} else {
		chConv = ch;
	}
	return RESULT_Complete;
}

//-----------------------------------------------------------------------------
// Codec_UTF8
//-----------------------------------------------------------------------------
Codec::Result Codec_UTF8::Decoder::FeedChar(char ch, char &chConv)
{
	if (GetDelcrFlag() && ch == '\r') return RESULT_None;
	if (_cntTrails > 0) {
		if ((ch & 0xc0) != 0x80) return RESULT_Error;
		_cntTrails--;
	} else if ((ch & 0x80) == 0x00) {
		// nothing to do
	} else if ((ch & 0xe0) == 0xc0) {
		_cntTrails = 1;
	} else if ((ch & 0xf0) == 0xe0) {
		_cntTrails = 2;
	} else if ((ch & 0xf8) == 0xf0) {
		_cntTrails = 3;
	} else if ((ch & 0xfc) == 0xf8) {
		_cntTrails = 4;
	} else if ((ch & 0xfe) == 0xfc) {
		_cntTrails = 5;
	} else {
		return RESULT_Error;
	}
	chConv = ch;
	return RESULT_Complete;
}

Codec::Result Codec_UTF8::Encoder::FeedChar(char ch, char &chConv)
{
	if (GetAddcrFlag() && ch == '\n') {
		StoreChar('\n');
		chConv = '\r';
		return RESULT_Complete;
	}
	if (_cntTrails > 0) {
		if ((ch & 0xc0) != 0x80) return RESULT_Error;
		_cntTrails--;
	} else if ((ch & 0x80) == 0x00) {
		// nothing to do
	} else if ((ch & 0xe0) == 0xc0) {
		_cntTrails = 1;
	} else if ((ch & 0xf0) == 0xe0) {
		_cntTrails = 2;
	} else if ((ch & 0xf8) == 0xf0) {
		_cntTrails = 3;
	} else if ((ch & 0xfc) == 0xf8) {
		_cntTrails = 4;
	} else if ((ch & 0xfe) == 0xfc) {
		_cntTrails = 5;
	} else {
		return RESULT_Error;
	}
	chConv = ch;
	return RESULT_Complete;
}

//-----------------------------------------------------------------------------
// Gura module functions: codecs.basic
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	CodecFactory::Register(new CodecFactoryTmpl<Codec_USASCII>("us-ascii"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_UTF8>("utf-8"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_UTF16<8, 0> >("utf-16"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_UTF16<0, 8> >("utf-16le"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_UTF16<8, 0> >("utf-16be"));
	return true;
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(codecs_basic, basic)

Gura_RegisterModule(codecs_basic)
