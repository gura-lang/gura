//-----------------------------------------------------------------------------
// Codec
// encoding names are specified in http://www.iana.org/assignments/character-sets
//-----------------------------------------------------------------------------
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Codec
//-----------------------------------------------------------------------------
const char *Codec::GetName() const
{
	return (_pCodecFactory == NULL)? "none" : _pCodecFactory->GetName();
}

bool Codec::FollowChar(char &chConv)
{
	if (_idxBuff <= 0) return false;
	chConv = _buffOut[--_idxBuff];
	return true;
}

Codec::Result Codec::Flush(char &chConv)
{
	return RESULT_None;
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
		for (int i = 0; i < NUMBEROF(assocInfoTbl); i++) {
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
		for (int i = 0; i < NUMBEROF(assocInfoTbl); i++) {
			if (::strcasecmp(langRight.c_str(), assocInfoTbl[i].key) == 0) {
				return assocInfoTbl[i].value;
			}
		}
	}
	return encodingDefault;
}

//-----------------------------------------------------------------------------
// CodecFactory
//-----------------------------------------------------------------------------
CodecFactory::List *CodecFactory::_pList = NULL;

CodecFactory::CodecFactory(const char *name) : _name(name)
{
}

void CodecFactory::Register(CodecFactory *pCodecFactory)
{
	if (_pList == NULL) {
		_pList = new List();
	}
	_pList->push_back(pCodecFactory);
}

CodecFactory *CodecFactory::Lookup(const char *name)
{
	if (name == NULL || _pList == NULL) return NULL;
	foreach (List, ppCodecFactory, *_pList) {
		CodecFactory *pCodecFactory = *ppCodecFactory;
		if (::strcasecmp(pCodecFactory->GetName(), name) == 0) {
			return pCodecFactory;
		}
	}
	return NULL;
}

//-----------------------------------------------------------------------------
// Codec_None
//-----------------------------------------------------------------------------
Codec::Result Codec_None::FeedChar(char ch, char &chConv)
{
	chConv = ch;
	return RESULT_Complete;
}

//-----------------------------------------------------------------------------
// Codec_Encoder
//-----------------------------------------------------------------------------
bool Codec_Encoder::Encode(Signal sig, Binary &dst, const char *str)
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

Codec_Encoder *Codec_Encoder::Duplicate() const
{
	return _pCodecFactory->CreateEncoder(_processEOLFlag);
}

//-----------------------------------------------------------------------------
// Codec_Decoder
//-----------------------------------------------------------------------------
bool Codec_Decoder::Decode(Signal sig, String &dst, const char *buff, size_t bytes)
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

bool Codec_Decoder::Decode(Signal sig, String &dst, const Binary &src)
{
	return Decode(sig, dst, src.data(), src.size());
}

Codec_Decoder *Codec_Decoder::Duplicate() const
{
	return _pCodecFactory->CreateDecoder(_processEOLFlag);
}

//-----------------------------------------------------------------------------
// UTF
//-----------------------------------------------------------------------------
Codec::Result Codec_Encoder_UTF::FeedChar(char ch, char &chConv)
{
	Result rtn = RESULT_None;
	if ((ch & 0x80) == 0x00) {
		rtn = FeedUTF32(static_cast<unsigned char>(ch), chConv);
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
		_codeUTF32 = static_cast<unsigned char>(ch & 0x1f);
		_cntChars = 1;
	} else if ((ch & 0xf0) == 0xe0) {
		_codeUTF32 = static_cast<unsigned char>(ch & 0x0f);
		_cntChars = 2;
	} else if ((ch & 0xf8) == 0xf0) {
		_codeUTF32 = static_cast<unsigned char>(ch & 0x07);
		_cntChars = 3;
	} else if ((ch & 0xfc) == 0xf8) {
		_codeUTF32 = static_cast<unsigned char>(ch & 0x03);
		_cntChars = 4;
	} else {
		_codeUTF32 = static_cast<unsigned char>(ch & 0x01);
		_cntChars = 5;
	}
	return rtn;
}

Codec::Result Codec_Decoder_UTF::FeedUTF32(unsigned long codeUTF32, char &chConv)
{
	_idxBuff = 0;
	if ((codeUTF32 & ~0x7f) == 0) {
		chConv = static_cast<char>(codeUTF32);
		return RESULT_Complete;
	}
	StoreChar(0x80 | static_cast<char>(codeUTF32 & 0x3f)); codeUTF32 >>= 6;
	if ((codeUTF32 & ~0x1f) == 0) {
		chConv = 0xc0 | static_cast<char>(codeUTF32);
		return RESULT_Complete;
	}
	StoreChar(0x80 | static_cast<char>(codeUTF32 & 0x3f)); codeUTF32 >>= 6;
	if ((codeUTF32 & ~0x0f) == 0) {
		chConv = 0xe0 | static_cast<char>(codeUTF32);
		return RESULT_Complete;
	}
	StoreChar(0x80 | static_cast<char>(codeUTF32 & 0x3f)); codeUTF32 >>= 6;
	if ((codeUTF32 & ~0x07) == 0) {
		chConv = 0xf0 | static_cast<char>(codeUTF32);
		return RESULT_Complete;
	}
	_idxBuff = 0;
	chConv = '\0';
	return RESULT_Error;
}

}
