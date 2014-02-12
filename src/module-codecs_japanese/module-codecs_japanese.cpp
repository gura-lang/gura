//-----------------------------------------------------------------------------
// Gura codecs.japanese module
//-----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleBody(codecs_japanese)

//-----------------------------------------------------------------------------
// Codec_CP932
//-----------------------------------------------------------------------------
UShort Codec_CP932::Decoder::DBCSToUTF16(UShort codeDBCS)
{
	return CP932ToUTF16(codeDBCS);
}

UShort Codec_CP932::Encoder::UTF16ToDBCS(UShort codeUTF16)
{
	return UTF16ToCP932(codeUTF16);
}

//-----------------------------------------------------------------------------
// Codec_EUCJP
//-----------------------------------------------------------------------------
Codec::Result Codec_EUCJP::Decoder::FeedChar(char ch, char &chConv)
{
	ULong codeUTF32 = 0x00000000;
	if (_codeEUCJP == 0x0000) {
		if (ch & 0x80) {
			_codeEUCJP = static_cast<UChar>(ch);
			return RESULT_None;
		}
		codeUTF32 = CP932ToUTF16(static_cast<UChar>(ch));
	} else {
		_codeEUCJP = (_codeEUCJP << 8) | static_cast<UChar>(ch);
		UShort codeCP932 = EUCJPToCP932(_codeEUCJP);
		codeUTF32 = CP932ToUTF16(codeCP932);
		_codeEUCJP = 0x0000;
	}
	if (GetDelcrFlag() && codeUTF32 == '\r') return RESULT_None;
	return FeedUTF32(codeUTF32, chConv);
}

Codec::Result Codec_EUCJP::Encoder::FeedUTF32(ULong codeUTF32, char &chConv)
{
	UShort codeCP932 = UTF16ToCP932(static_cast<UShort>(codeUTF32));
	UShort codeEUCJP = CP932ToEUCJP(codeCP932);
	if (codeEUCJP == 0x0000) {
		chConv = '\0';
		return RESULT_Error;
	} else if ((codeEUCJP & ~0xff) == 0) {
		char ch = static_cast<char>(codeEUCJP & 0xff);
		if (GetAddcrFlag() && ch == '\n') {
			StoreChar('\n');
			chConv = '\r';
		} else {
			chConv = ch;
		}
	} else {
		StoreChar(static_cast<char>(codeEUCJP & 0xff));
		chConv = static_cast<char>(codeEUCJP >> 8);
	}
	return RESULT_Complete;
}

//-----------------------------------------------------------------------------
// Codec_JIS
//-----------------------------------------------------------------------------
Codec::Result Codec_JIS::Decoder::FeedChar(char ch, char &chConv)
{
	if (_stat == STAT_Start) {
		if (ch == 0x1b) {
			_codeJIS = 0x0000;
			_stat = STAT_Escape;
			return RESULT_None;
		}
	} else if (_stat == STAT_Escape) {
		if (ch == '$') {
			_stat = STAT_Dollar;
		} else if (ch == '&') {
			_stat = STAT_Ampersand;
		} else if (ch == '(') {
			_stat = STAT_LParenthesis;
		} else {
			return RESULT_Error;
		}
		return RESULT_None;
	} else if (_stat == STAT_Dollar) {
		if (ch == '@') {
			_mode = MODE_JISC;
			_stat = STAT_Start;
		} else if (ch == 'B') {
			_mode = MODE_JISX1983;
			_stat = STAT_Start;
		} else {
			return RESULT_Error;
		}
		return RESULT_None;
	} else if (_stat == STAT_Ampersand) {
		if (ch == '@') {
			_stat = STAT_JISX1990;
		} else {
			return RESULT_Error;
		}
		return RESULT_None;
	} else if (_stat == STAT_LParenthesis) {
		if (ch == 'B') {
			_mode = MODE_ASCII;
			_stat = STAT_Start;
		} else if (ch == 'J') {
			_mode = MODE_JISROMA;
			_stat = STAT_Start;
		} else if (ch == 'I') {
			_mode = MODE_JISKANA;
			_stat = STAT_Start;
		} else {
			return RESULT_Error;
		}
		return RESULT_None;
	} else if (_stat == STAT_JISX1990) {
		if (ch == 0x1b) {
			_stat = STAT_Escape2nd;
		} else {
			return RESULT_Error;
		}
		return RESULT_None;
	} else if (_stat == STAT_Escape2nd) {
		if (ch == '$') {
			_stat = STAT_Dollar2nd;
		} else {
			return RESULT_Error;
		}
		return RESULT_None;
	} else if (_stat == STAT_Dollar2nd) {
		if (ch == 'B') {
			_mode = MODE_JISX1990;
			_stat = STAT_Start;
		} else {
			return RESULT_Error;
		}
		return RESULT_None;
	}
	UShort codeCP932 = 0x0000;
	if (_mode == MODE_JISC || _mode == MODE_JISX1983 || _mode == MODE_JISX1990) {
		if (_codeJIS == 0x0000) {
			_codeJIS = ch;
			return RESULT_None;
		}
		_codeJIS = (_codeJIS << 8) | ch;
		codeCP932 = JISToCP932(_codeJIS);
	} else if (_mode == MODE_ASCII) {
		codeCP932 = ch;
	} else if (_mode == MODE_JISROMA) {
		codeCP932 = ch;	// incorrect process
	} else if (_mode == MODE_JISKANA) {
		if (0x20 < ch && ch < 0x60) {
			codeCP932 = static_cast<UChar>(ch) + 0x80;
		} else {
			return RESULT_Error;
		}
	}
	if (GetDelcrFlag() && codeCP932 == '\r') return RESULT_None;
	ULong codeUTF32 = CP932ToUTF16(codeCP932);
	_codeJIS = 0x0000;
	return FeedUTF32(codeUTF32, chConv);
}

Codec::Result Codec_JIS::Encoder::FeedUTF32(ULong codeUTF32, char &chConv)
{
	UShort codeCP932 = UTF16ToCP932(static_cast<UShort>(codeUTF32));
	if (codeCP932 < 0x80) {
		char ch = static_cast<char>(codeCP932 & 0xff);
		if (_mode == MODE_ASCII) {
			if (GetAddcrFlag() && ch == '\n') {
				StoreChar('\n');
				chConv = '\r';
			} else {
				chConv = ch;
			}
		} else {
			if (GetAddcrFlag() && ch == '\n') {
				StoreChar('\n');
				StoreChar('\r');
			} else {
				StoreChar(ch);
			}
			StoreChar('B');
			StoreChar('(');
			chConv = 0x1b;
			_mode = MODE_ASCII;
		}
	} else if (0xa0 < codeCP932 && codeCP932 < 0xe0) {
		if (_mode != MODE_JISKANA) {
			StoreChar('I');
			StoreChar('(');
			chConv = 0x1b;
			_mode = MODE_JISKANA;
		}
		chConv = static_cast<UChar>(codeCP932 - 0x80);
	} else if (codeCP932 < 0x100) {
		return RESULT_Error;
	} else {
		UShort codeJIS = CP932ToJIS(codeCP932);
		if (codeJIS == 0x0000) {
			chConv = '\0';
			return RESULT_Error;
		}
		if (_mode == MODE_JISC) {
			StoreChar(static_cast<char>(codeJIS & 0xff));
			chConv = static_cast<char>(codeJIS >> 8);
		} else {
			StoreChar(static_cast<char>(codeJIS & 0xff));
			StoreChar(static_cast<char>(codeJIS >> 8));
			StoreChar('@');
			StoreChar('$');
			chConv = 0x1b;
			_mode = MODE_JISC;
		}
	}
	return RESULT_Complete;
}

//-----------------------------------------------------------------------------
// Gura module functions: japanese
//-----------------------------------------------------------------------------
// Module entry
Gura_ModuleEntry()
{
	CodecFactory::Register(new CodecFactoryTmpl<Codec_EUCJP>("euc-jp"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP932>("cp932"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP932>("shift_jis"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_CP932>("ms_kanji"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_JIS>("jis"));
	CodecFactory::Register(new CodecFactoryTmpl<Codec_JIS>("iso-2022-jp"));
}

Gura_ModuleTerminate()
{
}

Gura_EndModuleBody(codecs_japanese, japanese)

Gura_RegisterModule(codecs_japanese)
