//=============================================================================
// Codec
// encoding names are specified in http://www.iana.org/assignments/character-sets
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Codec
//-----------------------------------------------------------------------------
CodecFactory *Codec::_pFactory_None = NULL;

// Byte Order Mark of Unicode
const char *Codec::BOM_UTF8 = "\xef\xbb\xbf";
const char *Codec::BOM_UTF16BE = "\xfe\xff";
const char *Codec::BOM_UTF16LE = "\xff\xfe";
const char *Codec::BOM_UTF32BE = "\x00\x00\xfe\xff";
const char *Codec::BOM_UTF32LE = "\xff\xfe\x00\x00";

Codec::Codec(CodecFactory *pFactory, Decoder *pDecoder, Encoder *pEncoder) :
	_cntRef(1), _pFactory(pFactory), _pDecoder(pDecoder), _pEncoder(pEncoder)
{
}

Codec *Codec::Duplicate() const
{
	return _pFactory->CreateCodec(_pDecoder->GetDelcrFlag(), _pEncoder->GetAddcrFlag());
}

Codec *Codec::CreateCodecNone(bool delcrFlag, bool addcrFlag)
{
	return _pFactory_None->CreateCodec(delcrFlag, addcrFlag);
}

Codec *Codec::CreateCodec(Signal sig, const char *encoding, bool delcrFlag, bool addcrFlag)
{
	if (encoding == NULL) encoding = "none";
	CodecFactory *pFactory = CodecFactory::Lookup(encoding);
	if (pFactory == NULL) {
		sig.SetError(ERR_CodecError, "unsupported encoding %s", encoding);
		return NULL;
	}
	return pFactory->CreateCodec(delcrFlag, addcrFlag);
}

const char *Codec::EncodingFromLANG()
{
	const char *encodingDefault = "utf-8";
	struct AssocInfo {
		const char *key;
		const char *value;
	};
	String str = OAL::GetEnv("LANG");
	if (str.empty()) return encodingDefault;
	const char *strp = str.c_str();
	const char *p = ::strchr(strp, '.');
	String langLeft, langRight;
	if (p == NULL) {
		langLeft = strp;
	} else {
		langLeft = String(strp, p - strp);
		langRight = p + 1;
	}
	if (langRight.empty()) {
		static const AssocInfo assocInfoTbl[] = {
			{ "C",		"us-ascii" },
			{ "en_US",	"us-ascii" },
			{ "ja",	 	"euc-jp" },
			{ "ja_JP",	"euc-jp" },
		};
		for (int i = 0; i < ArraySizeOf(assocInfoTbl); i++) {
			if (::strcasecmp(langLeft.c_str(), assocInfoTbl[i].key) == 0) {
				return assocInfoTbl[i].value;
			}
		}
	} else {
		static const AssocInfo assocInfoTbl[] = {
			{ "eucJP",	"euc-jp" },
			{ "ujis",	"euc-jp" },
			{ "utf-8",	"utf-8" },
			{ "utf8",	"utf-8" },
			{ "utf-16",	"utf-16" },
			{ "utf16",	"utf-16" },
			{ "SJIS",	"shift_jis" },
		};
		for (int i = 0; i < ArraySizeOf(assocInfoTbl); i++) {
			if (::strcasecmp(langRight.c_str(), assocInfoTbl[i].key) == 0) {
				return assocInfoTbl[i].value;
			}
		}
	}
	return encodingDefault;
}

void Codec::Initialize()
{
	_pFactory_None = new CodecFactoryTmpl<Codec_None>("none");
	CodecFactory::Register(_pFactory_None);
}

//-----------------------------------------------------------------------------
// Codec::DecEncBase
//-----------------------------------------------------------------------------
bool Codec::DecEncBase::FollowChar(char &chConv)
{
	if (_idxBuff <= 0) return false;
	chConv = _buffOut[--_idxBuff];
	return true;
}

Codec::Result Codec::DecEncBase::Flush(char &chConv)
{
	return Codec::RESULT_None;
}

//-----------------------------------------------------------------------------
// CodecFactory
//-----------------------------------------------------------------------------
CodecFactory::List *CodecFactory::_pList = NULL;

CodecFactory::CodecFactory(const char *encoding) : _encoding(encoding)
{
}

void CodecFactory::Register(CodecFactory *pFactory)
{
	if (_pList == NULL) {
		_pList = new List();
	}
	_pList->push_back(pFactory);
}

CodecFactory *CodecFactory::Lookup(const char *encoding)
{
	if (encoding == NULL || _pList == NULL) return NULL;
	foreach (List, ppFactory, *_pList) {
		CodecFactory *pFactory = *ppFactory;
		if (::strcasecmp(pFactory->GetEncoding(), encoding) == 0) {
			return pFactory;
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// Codec::Decoder
//-----------------------------------------------------------------------------
bool Codec::Decoder::Decode(Signal sig, String &dst, const char *buff, size_t bytes)
{
	char ch;
	for (const char *p = buff; bytes > 0; p++, bytes--) {
		Codec::Result rtn = FeedChar(*p, ch);
		if (rtn == Codec::RESULT_Complete) {
			dst.push_back(ch);
			while (FollowChar(ch)) dst.push_back(ch);
		} else if (rtn == Codec::RESULT_Error) {
			sig.SetError(ERR_CodecError, "failed to decode a binary");
			return false;
		}
	}
	if (Flush(ch) == Codec::RESULT_Complete) {
		dst.push_back(ch);
		while (FollowChar(ch)) dst.push_back(ch);
	}
	return true;
}

bool Codec::Decoder::Decode(Signal sig, String &dst, const Binary &src)
{
	return Decode(sig, dst, src.data(), src.size());
}

//-----------------------------------------------------------------------------
// Codec::Encoder
//-----------------------------------------------------------------------------
bool Codec::Encoder::Encode(Signal sig, Binary &dst, const char *str)
{
	char ch;
	for (const char *p = str; *p != '\0'; p++) {
		Codec::Result rtn = FeedChar(*p, ch);
		if (rtn == Codec::RESULT_Complete) {
			dst.push_back(ch);
			while (FollowChar(ch)) dst.push_back(ch);
		} else if (rtn == Codec::RESULT_Error) {
			sig.SetError(ERR_CodecError, "failed to encode a string");
			return false;
		}
	}
	if (Flush(ch) == Codec::RESULT_Complete) {
		dst.push_back(ch);
		while (FollowChar(ch)) dst.push_back(ch);
	}
	return true;
}

//-----------------------------------------------------------------------------
// Codec_None
//-----------------------------------------------------------------------------
Codec::Result Codec_None::Decoder::FeedChar(char ch, char &chConv)
{
	if (GetDelcrFlag() && ch == '\r') return Codec::RESULT_None;
	chConv = ch;
	return Codec::RESULT_Complete;
}

Codec::Result Codec_None::Encoder::FeedChar(char ch, char &chConv)
{
	if (GetAddcrFlag() && ch == '\n') {
		StoreChar('\n');
		chConv = '\r';
	} else {
		chConv = ch;
	}
	return Codec::RESULT_Complete;
}

//-----------------------------------------------------------------------------
// Codec_UTF
//-----------------------------------------------------------------------------
Codec::Result Codec_UTF::Decoder::FeedUTF32(ULong codeUTF32, char &chConv)
{
	_idxBuff = 0;
	if ((codeUTF32 & ~0x7f) == 0) {
		chConv = static_cast<char>(codeUTF32);
		return Codec::RESULT_Complete;
	}
	StoreChar(0x80 | static_cast<char>(codeUTF32 & 0x3f)); codeUTF32 >>= 6;
	if ((codeUTF32 & ~0x1f) == 0) {
		chConv = 0xc0 | static_cast<char>(codeUTF32);
		return Codec::RESULT_Complete;
	}
	StoreChar(0x80 | static_cast<char>(codeUTF32 & 0x3f)); codeUTF32 >>= 6;
	if ((codeUTF32 & ~0x0f) == 0) {
		chConv = 0xe0 | static_cast<char>(codeUTF32);
		return Codec::RESULT_Complete;
	}
	StoreChar(0x80 | static_cast<char>(codeUTF32 & 0x3f)); codeUTF32 >>= 6;
	if ((codeUTF32 & ~0x07) == 0) {
		chConv = 0xf0 | static_cast<char>(codeUTF32);
		return Codec::RESULT_Complete;
	}
	_idxBuff = 0;
	chConv = '\0';
	return Codec::RESULT_Error;
}

Codec::Result Codec_UTF::Encoder::FeedChar(char ch, char &chConv)
{
	Codec::Result rtn = Codec::RESULT_None;
	if ((ch & 0x80) == 0x00) {
		rtn = FeedUTF32(static_cast<UChar>(ch), chConv);
		_cntChars = 0;
	} else if ((ch & 0xc0) == 0x80) {
		if (_cntChars == 1) {
			_codeUTF32 = (_codeUTF32 << 6) | (ch & 0x3f);
			rtn = FeedUTF32(_codeUTF32, chConv);
			_codeUTF32 = 0x00000000;
			_cntChars = 0;
		} else if (_cntChars > 0) {
			_codeUTF32 = (_codeUTF32 << 6) | (ch & 0x3f);
			_cntChars--;
		} else {
			_codeUTF32 = 0x00000000;
		}
	} else if ((ch & 0xe0) == 0xc0) {
		_codeUTF32 = static_cast<UChar>(ch & 0x1f);
		_cntChars = 1;
	} else if ((ch & 0xf0) == 0xe0) {
		_codeUTF32 = static_cast<UChar>(ch & 0x0f);
		_cntChars = 2;
	} else if ((ch & 0xf8) == 0xf0) {
		_codeUTF32 = static_cast<UChar>(ch & 0x07);
		_cntChars = 3;
	} else if ((ch & 0xfc) == 0xf8) {
		_codeUTF32 = static_cast<UChar>(ch & 0x03);
		_cntChars = 4;
	} else {
		_codeUTF32 = static_cast<UChar>(ch & 0x01);
		_cntChars = 5;
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Codec_DBCS
//-----------------------------------------------------------------------------
Codec::Result Codec_DBCS::Decoder::FeedChar(char ch, char &chConv)
{
	ULong codeUTF32 = 0x00000000;
	if (_codeDBCS == 0x0000) {
		if (IsSJISFirst(ch)) {
			_codeDBCS = static_cast<UChar>(ch);
			return RESULT_None;
		}
		codeUTF32 = DBCSToUTF16(static_cast<UChar>(ch));
	} else {
		_codeDBCS = (_codeDBCS << 8) | static_cast<UChar>(ch);
		codeUTF32 = DBCSToUTF16(_codeDBCS);
		_codeDBCS = 0x0000;
	}
	if (GetDelcrFlag() && codeUTF32 == '\r') return RESULT_None;
	return FeedUTF32(codeUTF32, chConv);
}

Codec::Result Codec_DBCS::Encoder::FeedUTF32(ULong codeUTF32, char &chConv)
{
	UShort codeDBCS = UTF16ToDBCS(static_cast<UShort>(codeUTF32));
	if (codeDBCS == 0x0000) {
		chConv = '\0';
		return RESULT_Error;
	} else if ((codeDBCS & ~0xff) == 0) {
		char ch = static_cast<char>(codeDBCS & 0xff);
		if (GetAddcrFlag() && ch == '\n') {
			StoreChar('\n');
			chConv = '\r';
		} else {
			chConv = ch;
		}
	} else {
		StoreChar(static_cast<char>(codeDBCS & 0xff));
		chConv = static_cast<char>(codeDBCS >> 8);
	}
	return RESULT_Complete;
}

}
