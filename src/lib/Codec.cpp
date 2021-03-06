//=============================================================================
// Codec
// encoding names are specified in http://www.iana.org/assignments/character-sets
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Codec
//-----------------------------------------------------------------------------
CodecFactory *Codec::_pFactory_None = nullptr;

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

Codec *Codec::CreateCodec(Signal &sig, const char *encoding, bool delcrFlag, bool addcrFlag)
{
	if (encoding == nullptr) encoding = "none";
	CodecFactory *pFactory = CodecFactory::Lookup(encoding);
	if (pFactory == nullptr) {
		sig.SetError(ERR_CodecError, "unsupported encoding %s", encoding);
		return nullptr;
	}
	return pFactory->CreateCodec(delcrFlag, addcrFlag);
}

void Codec::Bootup()
{
	_pFactory_None = new CodecFactoryTmpl<Codec_None>("none");
	CodecFactory::Register(_pFactory_None);
}

UShort Codec::DBCSToUTF16(const CodeRow codeRows[], int nCodeRows, UShort codeDBCS)
{
	int codeH = (codeDBCS >> 8) & 0xff;
	int codeL = codeDBCS & 0xff;
	if (codeH >= nCodeRows) return 0x0000;
	const CodeRow &codeRow = codeRows[codeH];
	if (codeH == 0) {
		return (codeL < codeRow.nCols)? codeRow.row[codeL] : 0x0000;
	} else if (codeL < 0x40) {
		return 0x0000;
	} else {
		int iCol = codeL - 0x40;
		return (iCol < codeRow.nCols)? codeRow.row[iCol] : 0x0000;
	}
}

UShort Codec::UTF16ToDBCS(const CodeRow codeRows[], int nCodeRows, UShort codeUTF16, Map **ppMap)
{
	Map *pMap = *ppMap;
	if (*ppMap == nullptr) {
		*ppMap = new Map();
		pMap = *ppMap;
		const CodeRow *pCodeRow = codeRows;
		for (int codeL = 0; codeL < pCodeRow->nCols; codeL++) {
			UShort codeUTF16 = pCodeRow->row[codeL];
			UShort codeDBCS = static_cast<UShort>(codeL);
			if (pMap->find(codeUTF16) == pMap->end()) {
				(*pMap)[codeUTF16] = codeDBCS;
			}
		}
		pCodeRow++;
		for (int codeH = 1; codeH < nCodeRows; codeH++, pCodeRow++) {
			UShort codeDBCSBase = static_cast<UShort>(codeH << 8);
			for (int iCol = 0; iCol < pCodeRow->nCols; iCol++) {
				UShort codeUTF16 = pCodeRow->row[iCol];
				if (codeUTF16 == 0x0000) continue;
				UShort codeL = static_cast<UShort>(iCol + 0x40);
				UShort codeDBCS = codeDBCSBase + codeL;
				//printf("%04x -> %04x\n", codeUTF16, codeDBCS);
				if (pMap->find(codeUTF16) == pMap->end()) {
					(*pMap)[codeUTF16] = codeDBCS;
				}
			}
		}
	}
	Map::iterator iter = pMap->find(codeUTF16);
	return (iter == pMap->end())? 0x0000 : iter->second;
}

Codec::WidthProp Codec::GetWidthProp(UInt32 codeUTF32)
{
	for (const WidthInfo *p = _widthInfoTbl; p->codeUTF32Ceil != 0x000000; p++) {
		if (codeUTF32 < p->codeUTF32Ceil) return p->widthProp;
	}
	return WIDTHPROP_N;
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
CodecFactory::List *CodecFactory::_pList = nullptr;

CodecFactory::CodecFactory(const char *encoding) : _encoding(encoding)
{
}

void CodecFactory::Register(CodecFactory *pFactory)
{
	if (_pList == nullptr) {
		_pList = new List();
	}
	_pList->push_back(pFactory);
}

CodecFactory *CodecFactory::Lookup(const char *encoding)
{
	if (encoding == nullptr || _pList == nullptr) return nullptr;
	foreach (List, ppFactory, *_pList) {
		CodecFactory *pFactory = *ppFactory;
		if (::strcasecmp(pFactory->GetEncoding(), encoding) == 0) {
			return pFactory;
		}
	}
	return nullptr;
}

//-----------------------------------------------------------------------------
// Codec::Decoder
//-----------------------------------------------------------------------------
bool Codec::Decoder::Decode(Signal &sig, String &dst, const char *buff, size_t bytes)
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

bool Codec::Decoder::Decode(Signal &sig, String &dst, const Binary &src)
{
	return Decode(sig, dst, src.data(), src.size());
}

//-----------------------------------------------------------------------------
// Codec::Encoder
//-----------------------------------------------------------------------------
bool Codec::Encoder::Encode(Signal &sig, Binary &dst, const char *str)
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
Codec::Result Codec_UTF::Decoder::FeedUTF32(UInt32 codeUTF32, char &chConv)
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
	StoreChar(0x80 | static_cast<char>(codeUTF32 & 0x3f)); codeUTF32 >>= 6;
	if ((codeUTF32 & ~0x03) == 0) {
		chConv = 0xf8 | static_cast<char>(codeUTF32);
		return Codec::RESULT_Complete;
	}
	StoreChar(0x80 | static_cast<char>(codeUTF32 & 0x3f)); codeUTF32 >>= 6;
	chConv = 0xfc | static_cast<char>(codeUTF32);
	return Codec::RESULT_Complete;
}

Codec::Result Codec_UTF::Encoder::FeedChar(char ch, char &chConv)
{
	Codec::Result rtn = Codec::RESULT_None;
	UChar _ch = static_cast<UChar>(ch);
	if ((_ch & 0x80) == 0x00) {
		rtn = FeedUTF32(_ch, chConv);
		_cntChars = 0;
	} else if ((_ch & 0xc0) == 0x80) {
		if (_cntChars == 1) {
			_codeUTF32 = (_codeUTF32 << 6) | (_ch & 0x3f);
			rtn = FeedUTF32(_codeUTF32, chConv);
			_codeUTF32 = 0x00000000;
			_cntChars = 0;
		} else if (_cntChars > 0) {
			_codeUTF32 = (_codeUTF32 << 6) | (_ch & 0x3f);
			_cntChars--;
		} else {
			_codeUTF32 = 0x00000000;
		}
	} else if ((_ch & 0xe0) == 0xc0) {
		_codeUTF32 = _ch & 0x1f;
		_cntChars = 1;
	} else if ((_ch & 0xf0) == 0xe0) {
		_codeUTF32 = _ch & 0x0f;
		_cntChars = 2;
	} else if ((_ch & 0xf8) == 0xf0) {
		_codeUTF32 = _ch & 0x07;
		_cntChars = 3;
	} else if ((_ch & 0xfc) == 0xf8) {
		_codeUTF32 = _ch & 0x03;
		_cntChars = 4;
	} else {
		_codeUTF32 = _ch & 0x01;
		_cntChars = 5;
	}
	return rtn;
}

//-----------------------------------------------------------------------------
// Codec_SBCS
//-----------------------------------------------------------------------------
Codec::Result Codec_SBCS::Decoder::FeedChar(char ch, char &chConv)
{
	chConv = static_cast<UChar>(_codeTbl[static_cast<UChar>(ch)]);
	return (chConv == '\0')? RESULT_Error : RESULT_Complete;
}

Codec::Result Codec_SBCS::Encoder::FeedUTF32(UInt32 codeUTF32, char &chConv)
{
	if (_pMap == nullptr) {
		_pMap = new Map();
		for (int codeSBCS = 0; codeSBCS < 256; codeSBCS++) {
			UShort codeUTF16 = _codeTbl[codeSBCS];
			if (_pMap->find(codeUTF16) == _pMap->end()) {
				(*_pMap)[codeUTF16] = codeSBCS;
			}
		}
	}
	Map::iterator iter = _pMap->find(static_cast<UShort>(codeUTF32));
	if (iter == _pMap->end()) return RESULT_Error;
	chConv = static_cast<UChar>(iter->second);
	return RESULT_Complete;
}

//-----------------------------------------------------------------------------
// Codec_DBCS
//-----------------------------------------------------------------------------
bool Codec_DBCS::Decoder::IsLeadByte(UChar ch)
{
	return ch >= 0x80;
}

Codec::Result Codec_DBCS::Decoder::FeedChar(char ch, char &chConv)
{
	UChar _ch = static_cast<UChar>(ch);
	UInt32 codeUTF32 = 0x00000000;
	if (_codeDBCS == 0x0000) {
		if (IsLeadByte(_ch)) {
			_codeDBCS = _ch;
			return RESULT_None;
		}
		codeUTF32 = DBCSToUTF16(_ch);
	} else {
		_codeDBCS = (_codeDBCS << 8) | _ch;
		codeUTF32 = DBCSToUTF16(_codeDBCS);
		_codeDBCS = 0x0000;
	}
	if (GetDelcrFlag() && codeUTF32 == '\r') return RESULT_None;
	return FeedUTF32(codeUTF32, chConv);
}

Codec::Result Codec_DBCS::Encoder::FeedUTF32(UInt32 codeUTF32, char &chConv)
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
