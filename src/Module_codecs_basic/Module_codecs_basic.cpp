//-----------------------------------------------------------------------------
// Gura codecs.basic module
//-----------------------------------------------------------------------------
#include "stdafx.h"
#include "Module_codecs_basic.h"

Gura_BeginModule(codecs_basic)

//-----------------------------------------------------------------------------
// None
//-----------------------------------------------------------------------------
Codec::Result CodecEncoder_None::FeedChar(char ch, char &chConv)
{
	if (IsProcessEOL() && ch == '\n') {
		StoreChar('\n');
		chConv = '\r';
	} else {
		chConv = ch;
	}
	return Codec::RESULT_Complete;
}

Codec::Result CodecDecoder_None::FeedChar(char ch, char &chConv)
{
	if (IsProcessEOL() && ch == '\r') return Codec::RESULT_None;
	chConv = ch;
	return Codec::RESULT_Complete;
}

Gura_ImplementCodecFactory(None, "none")

//-----------------------------------------------------------------------------
// USASCII
//-----------------------------------------------------------------------------
Codec::Result CodecEncoder_USASCII::FeedChar(char ch, char &chConv)
{
	// acceptable character code is between 0x00 and 0x7f
	if (ch & 0x80) return Codec::RESULT_Error;
	if (IsProcessEOL() && ch == '\n') {
		StoreChar('\n');
		chConv = '\r';
	} else {
		chConv = ch;
	}
	return Codec::RESULT_Complete;
}

Codec::Result CodecDecoder_USASCII::FeedChar(char ch, char &chConv)
{
	// acceptable character code is between 0x00 and 0x7f
	if (ch & 0x80) return Codec::RESULT_Error;
	if (IsProcessEOL() && ch == '\r') return Codec::RESULT_None;
	chConv = ch;
	return Codec::RESULT_Complete;
}

Gura_ImplementCodecFactory(USASCII, "us-ascii")

//-----------------------------------------------------------------------------
// UTF8
//-----------------------------------------------------------------------------
Codec::Result CodecEncoder_UTF8::FeedChar(char ch, char &chConv)
{
	if (IsProcessEOL() && ch == '\n') {
		StoreChar('\n');
		chConv = '\r';
		return Codec::RESULT_Complete;
	}
	if (_cntTrails > 0) {
		if ((ch & 0xc0) != 0x80) return Codec::RESULT_Error;
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
		return Codec::RESULT_Error;
	}
	chConv = ch;
	return Codec::RESULT_Complete;
}

Codec::Result CodecDecoder_UTF8::FeedChar(char ch, char &chConv)
{
	if (IsProcessEOL() && ch == '\r') return Codec::RESULT_None;
	if (_cntTrails > 0) {
		if ((ch & 0xc0) != 0x80) return Codec::RESULT_Error;
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
		return Codec::RESULT_Error;
	}
	chConv = ch;
	return Codec::RESULT_Complete;
}

Gura_ImplementCodecFactory(UTF8, "utf-8")

//-----------------------------------------------------------------------------
// UTF16LE
//-----------------------------------------------------------------------------
Codec::Result CodecEncoder_UTF16LE::FeedUTF32(unsigned long codeUTF32, char &chConv)
{
	if (IsProcessEOL() && codeUTF32 == '\n') {
		StoreChar('\0');
		StoreChar('\n');
		StoreChar('\0');
		chConv = '\r';
	} else if (codeUTF32 < 0x10000) {
		StoreChar(static_cast<char>((codeUTF32 >> 8) & 0xff));
		chConv = static_cast<char>((codeUTF32 >> 0) & 0xff);
	} else {
		// surrogate pair
		unsigned long code = (codeUTF32 - 0x10000) & 0xfffff;
		unsigned long codeUpper = (code >> 12) + 0xd800;
		unsigned long codeLower = (code & 0x3ff) + 0xdc00;
		StoreChar(static_cast<char>((codeLower >> 8) & 0xff));
		StoreChar(static_cast<char>((codeLower >> 0) & 0xff));
		StoreChar(static_cast<char>((codeUpper >> 8) & 0xff));
		chConv = static_cast<char>((codeUpper >> 0) & 0xff);
	}
	return Codec::RESULT_Complete;
}

Codec::Result CodecDecoder_UTF16LE::FeedChar(char ch, char &chConv)
{
	unsigned long chCasted =
				static_cast<unsigned long>(static_cast<unsigned char>(ch));
	if (_stat == STAT_First) {
		_code = chCasted;
		_stat = STAT_Second;
	} else if (_stat == STAT_Second) {
		_code |= (chCasted << 8);
		if (IsProcessEOL() && _code == '\r') {
			_stat = STAT_First;
		} else if (0xd800 <= _code && _code <= 0xdbff) {
			// surrogate pair
			_stat = STAT_LowerFirst;
		} else {
			_stat = STAT_First;
			return FeedUTF32(_code, chConv);
		}
	} else if (_stat == STAT_LowerFirst) {
		_codeLower = chCasted;
		_stat = STAT_LowerSecond;
	} else if (_stat == STAT_LowerSecond) {
		_codeLower |= (chCasted << 8);
		if (0xdc00 <= _codeLower && _codeLower <= 0xdfff) {
			unsigned long codeUTF32 = 0x10000 +
						((_code - 0xd800) << 10) + (_codeLower - 0xdc00);
			return FeedUTF32(codeUTF32, chConv);
		} else {
			// just ignore illegal codes
		}
		_stat = STAT_First;
	}
	return Codec::RESULT_None;
}

Gura_ImplementCodecFactory(UTF16LE, "utf-16")

//-----------------------------------------------------------------------------
// Gura module functions: codecs.basic
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	Gura_RegisterCodecFactory(None);
	Gura_RegisterCodecFactory(USASCII);
	Gura_RegisterCodecFactory(UTF8);
	Gura_RegisterCodecFactory(UTF16LE);
}

Gura_ModuleTerminate()
{
}

Gura_EndModule(codecs_basic, basic)

Gura_RegisterModule(codecs_basic)
