//=============================================================================
// Packer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Packer
//-----------------------------------------------------------------------------
bool Packer::Pack(Environment &env, const char *format, const ValueList &valListArg)
{
	Signal &sig = env.GetSignal();
	enum {
		STAT_Format,
		STAT_Repeat,
		STAT_Encoding,
	} stat = STAT_Format;
	ValueList::const_iterator pValueArg = valListArg.begin();
	bool bigEndianFlag = IsBigEndian();
	int nRepeat = 1;
	String encoding;
	AutoPtr<Codec> pCodec(Codec::CreateCodecNone(false, false));
	for (const char *p = format; *p != '\0'; ) {
		char ch = *p;
		bool eatNextFlag = true;
		if (stat == STAT_Repeat) {
			if (IsDigit(ch)) {
				nRepeat = nRepeat * 10 + (ch - '0');
			} else {
				eatNextFlag = false;
				stat = STAT_Format;
			}
		} else if (stat == STAT_Encoding) {
			if (ch == '}') {
				if (encoding.empty()) {
					pCodec.reset(Codec::CreateCodecNone(false, false));
				} else {
					pCodec.reset(Codec::CreateCodec(sig, encoding.c_str(), false, false));
					if (sig.IsSignalled()) return false;
				}
				stat = STAT_Format;
			} else {
				encoding.push_back(ch);
			}
		} else if (IsDigit(ch)) {
			nRepeat = 0;
			eatNextFlag = false;
			stat = STAT_Repeat;
		} else if (ch == '*') {
			if (pValueArg == valListArg.end()) {
				sig.SetError(ERR_ValueError, "not enough arguments");
				return false;
			}
			if (!pValueArg->Is_number()) {
				sig.SetError(ERR_ValueError,
								"repeat specifier requires a number value");
				return false;
			}
			nRepeat = pValueArg->GetInt();
			pValueArg++;
		} else if (ch == '{') {
			encoding.clear();
			stat = STAT_Encoding;
		} else if (ch == '@') {
			bigEndianFlag = IsBigEndian();
		} else if (ch == '=') {
			bigEndianFlag = IsBigEndian();
		} else if (ch == '<') {
			bigEndianFlag = false;
		} else if (ch == '>') {
			bigEndianFlag = true;
		} else if (ch == '!') {
			bigEndianFlag = true;
		} else if (ch == 'x') {
			if (!PackPrepare(sig, nRepeat)) return false;
			PackForward(nRepeat);
			nRepeat = 1;
		} else if (ch == 'c') {
			if (!PackPrepare(sig, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckString(sig, valListArg, pValueArg)) return false;
				PackChar(pValueArg->GetString()[0]);
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			if (!PackPrepare(sig, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -128, 127)) return false;
				PackChar(pValueArg->GetChar());
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			if (!PackPrepare(sig, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 255)) return false;
				PackUChar(pValueArg->GetUChar());
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			if (!PackPrepare(sig, sizeof(Short) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -32768, 32767)) return false;
				PackShort(pValueArg->GetShort(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			if (!PackPrepare(sig, sizeof(UShort) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 65535)) return false;
				PackUShort(pValueArg->GetUShort(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			if (!PackPrepare(sig, sizeof(Int32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -2147483648., 2147483647.)) return false;
				PackInt32(pValueArg->GetInt32(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			if (!PackPrepare(sig, sizeof(UInt32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 4294967295.)) return false;
				PackUInt32(pValueArg->GetUInt32(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			if (!PackPrepare(sig, sizeof(Int32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -2147483648., 2147483647.)) return false;
				PackInt32(pValueArg->GetInt32(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			if (!PackPrepare(sig, sizeof(UInt32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 4294967295.)) return false;
				PackUInt32(pValueArg->GetUInt32(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			if (!PackPrepare(sig, sizeof(Int64) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				PackInt64(pValueArg->GetInt64(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			if (!PackPrepare(sig, sizeof(UInt64) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				PackUInt64(pValueArg->GetUInt64(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			if (!PackPrepare(sig, sizeof(float) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				PackFloat(pValueArg->GetFloat(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			if (!PackPrepare(sig, sizeof(double) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				PackDouble(pValueArg->GetDouble(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 's') {
			if (!PackPrepare(sig, nRepeat)) return false;
			if (!CheckString(sig, valListArg, pValueArg)) return false;
			const char *p = pValueArg->GetString();
			int nPacked = 0;
			char chConv;
			for ( ; nPacked < nRepeat && *p != '\0'; p++) {
				Codec::Result result = pCodec->GetEncoder()->FeedChar(*p, chConv);
				if (result == Codec::RESULT_Error) {
					sig.SetError(ERR_CodecError,
						"encoding error. specify a proper coding name by {coding}");
					return false;
				} else if (result == Codec::RESULT_Complete) {
					PackUChar(chConv), nPacked++;
					while (pCodec->GetEncoder()->FollowChar(chConv) && nPacked < nRepeat) {
						PackUChar(chConv), nPacked++;
					}
				}
			}
			for ( ; nPacked < nRepeat; nPacked++) {
				PackUChar('\0');
			}
			pValueArg++;
			nRepeat = 1;
		} else if (ch == 'p') {
			sig.SetError(ERR_ValueError, "sorry, not implemented yet");
			return false;
		} else if (ch == 'P') {
			sig.SetError(ERR_ValueError, "sorry, not implemented yet");
			return false;
		} else if (IsWhite(ch)) {
			// just ignore white characters
		} else {
			sig.SetError(ERR_ValueError, "invalid character in format");
			return false;
		}
		if (eatNextFlag) p++;
	}
	return true;
}

Value Packer::Unpack(Environment &env, const char *format,
					 const ValueList &valListArg, bool exceedErrorFlag)
{
	Signal &sig = env.GetSignal();
	enum {
		STAT_Format,
		STAT_Repeat,
		STAT_Encoding,
	} stat = STAT_Format;
	ValueList::const_iterator pValueArg = valListArg.begin();
	Value result;
	Object_list *pObjList = result.InitAsList(env);
	bool bigEndianFlag = IsBigEndian();
	int nRepeat = 1;
	String encoding;
	AutoPtr<Codec> pCodec(Codec::CreateCodecNone(false, false));
	for (const char *p = format; *p != '\0'; ) {
		char ch = *p;
		bool eatNextFlag = true;
		if (stat == STAT_Repeat) {
			if (IsDigit(ch)) {
				nRepeat = nRepeat * 10 + (ch - '0');
			} else {
				eatNextFlag = false;
				stat = STAT_Format;
			}
		} else if (stat == STAT_Encoding) {
			if (ch == '}') {
				if (encoding.empty()) {
					pCodec.reset(Codec::CreateCodecNone(false, false));
				} else {
					pCodec.reset(Codec::CreateCodec(sig, encoding.c_str(), false, false));
					if (sig.IsSignalled()) return Value::Nil;
				}
				stat = STAT_Format;
			} else {
				encoding.push_back(ch);
			}
		} else if (IsDigit(ch)) {
			nRepeat = 0;
			eatNextFlag = false;
			stat = STAT_Repeat;
		} else if (ch == '*') {
			if (pValueArg == valListArg.end()) {
				sig.SetError(ERR_ValueError, "not enough arguments");
				return false;
			}
			if (!pValueArg->Is_number()) {
				sig.SetError(ERR_ValueError,
								"repeat specifier requires a number value");
				return false;
			}
			nRepeat = pValueArg->GetInt();
			pValueArg++;
		} else if (ch == '{') {
			encoding.clear();
			stat = STAT_Encoding;
		} else if (ch == '@') {
			bigEndianFlag = IsBigEndian();
		} else if (ch == '=') {
			bigEndianFlag = IsBigEndian();
		} else if (ch == '<') {
			bigEndianFlag = false;
		} else if (ch == '>') {
			bigEndianFlag = true;
		} else if (ch == '!') {
			bigEndianFlag = true;
		} else if (ch == 'x') {
			const UChar *pByte = UnpackPrepare(sig, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			nRepeat = 1;
		} else if (ch == 'c') {
			const UChar *pByte = UnpackPrepare(sig, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			char str[2];
			str[1] = '\0';
			for (int i = 0; i < nRepeat; i++, pByte++) {
				str[0] = UnpackChar(pByte);
				pObjList->Add(Value(str));
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			const UChar *pByte = UnpackPrepare(sig, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				pObjList->Add(Value(UnpackChar(pByte)));
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			const UChar *pByte = UnpackPrepare(sig, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				pObjList->Add(Value(UnpackUChar(pByte)));
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(Short) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Short)) {
				pObjList->Add(Value(UnpackShort(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(UShort) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UShort)) {
				pObjList->Add(Value(UnpackUShort(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(Int32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32)) {
				pObjList->Add(Value(UnpackInt32(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(UInt32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32)) {
				pObjList->Add(Value(UnpackUInt32(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(Int32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32)) {
				pObjList->Add(Value(UnpackInt32(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(UInt32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32)) {
				pObjList->Add(Value(UnpackUInt32(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(Int64) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int64)) {
				pObjList->Add(Value(UnpackInt64(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(UInt64) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt64)) {
				pObjList->Add(Value(UnpackUInt64(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(float) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(float)) {
				pObjList->Add(Value(UnpackFloat(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			const UChar *pByte = UnpackPrepare(sig, sizeof(double) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(double)) {
				pObjList->Add(Value(UnpackDouble(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 's') {
			const UChar *pByte = UnpackPrepare(sig, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			String str;
			str.reserve(nRepeat);
			char chConv;
			for (int nUnpacked = 0; nUnpacked < nRepeat; nUnpacked++, pByte++) {
				Codec::Result result = pCodec->GetDecoder()->FeedChar(*pByte, chConv);
				if (result == Codec::RESULT_Error) {
					sig.SetError(ERR_CodecError,
						"decoding error. specify a proper coding name by {coding}");
					return false;
				} else if (result == Codec::RESULT_Complete) {
					str.push_back(chConv);
					while (pCodec->GetDecoder()->FollowChar(chConv)) str.push_back(chConv);
				}
			}
			// flush unprocessed characters
			if (pCodec->GetDecoder()->Flush(chConv)) while (pCodec->GetDecoder()->FollowChar(chConv)) ;
			pObjList->Add(Value(str));
			nRepeat = 1;
		} else if (ch == 'p') {
			sig.SetError(ERR_NotImplementedError, "sorry, not implemented yet");
			return Value::Nil;
		} else if (ch == 'P') {
			sig.SetError(ERR_NotImplementedError, "sorry, not implemented yet");
			return Value::Nil;
		} else if (IsWhite(ch)) {
			// just ignore white characters
		} else {
			sig.SetError(ERR_ValueError, "invalid character in format");
			return Value::Nil;
		}
		if (eatNextFlag) p++;
	}
	return result;
}

bool Packer::CheckString(Signal &sig,
				const ValueList &valList, ValueList::const_iterator pValue)
{
	if (pValue == valList.end()) {
		sig.SetError(ERR_ValueError, "not enough arguments");
		return false;
	} else if (!pValue->Is_string()) {
		sig.SetError(ERR_ValueError, "string value is expected");
		return false;
	}
	return true;
}

bool Packer::CheckNumber(Signal &sig,
				const ValueList &valList, ValueList::const_iterator pValue)
{
	if (pValue == valList.end()) {
		sig.SetError(ERR_ValueError, "not enough arguments");
		return false;
	} else if (!pValue->Is_number()) {
		sig.SetError(ERR_ValueError, "number value is expected");
		return false;
	}
	return true;
}

bool Packer::CheckNumber(Signal &sig, const ValueList &valList,
				ValueList::const_iterator pValue, Number numMin, Number numMax)
{
	if (!CheckNumber(sig, valList, pValue)) return false;
	Number num = pValue->GetNumber();
	if (num < numMin || num > numMax) {
		sig.SetError(ERR_ValueError, "number is out of range");
		return false;
	}
	return true;
}

void Packer::PackUShort(UShort num, bool bigEndianFlag)
{
	UChar buff[sizeof(UShort)];
	UChar *pByte = buff;
	UChar byte0 = static_cast<UChar>(num >> 8);
	UChar byte1 = static_cast<UChar>(num >> 0);
	if (bigEndianFlag) {
		*pByte++ = byte0;
		*pByte   = byte1;
	} else {
		*pByte++ = byte1;
		*pByte   = byte0;
	}
	PackBuffer(buff, sizeof(UShort));
}

void Packer::PackUInt32(UInt32 num, bool bigEndianFlag)
{
	UChar buff[sizeof(UInt32)];
	UChar *pByte = buff;
	UChar byte0 = static_cast<UChar>(num >> 24);
	UChar byte1 = static_cast<UChar>(num >> 16);
	UChar byte2 = static_cast<UChar>(num >> 8);
	UChar byte3 = static_cast<UChar>(num >> 0);
	if (bigEndianFlag) {
		*pByte++ = byte0;
		*pByte++ = byte1;
		*pByte++ = byte2;
		*pByte   = byte3;
	} else {
		*pByte++ = byte3;
		*pByte++ = byte2;
		*pByte++ = byte1;
		*pByte   = byte0;
	}
	PackBuffer(buff, sizeof(UInt32));
}

void Packer::PackUInt64(UInt64 num, bool bigEndianFlag)
{
	UChar buff[sizeof(UInt64)];
	UChar *pByte = buff;
	UChar byte0 = static_cast<UChar>(num >> 56);
	UChar byte1 = static_cast<UChar>(num >> 48);
	UChar byte2 = static_cast<UChar>(num >> 40);
	UChar byte3 = static_cast<UChar>(num >> 32);
	UChar byte4 = static_cast<UChar>(num >> 24);
	UChar byte5 = static_cast<UChar>(num >> 16);
	UChar byte6 = static_cast<UChar>(num >> 8);
	UChar byte7 = static_cast<UChar>(num >> 0);
	if (bigEndianFlag) {
		*pByte++ = byte0;
		*pByte++ = byte1;
		*pByte++ = byte2;
		*pByte++ = byte3;
		*pByte++ = byte4;
		*pByte++ = byte5;
		*pByte++ = byte6;
		*pByte   = byte7;
	} else {
		*pByte++ = byte7;
		*pByte++ = byte6;
		*pByte++ = byte5;
		*pByte++ = byte4;
		*pByte++ = byte3;
		*pByte++ = byte2;
		*pByte++ = byte1;
		*pByte   = byte0;
	}
	PackBuffer(buff, sizeof(UInt64));
}

UShort Packer::UnpackUShort(const UChar *pByte, bool bigEndianFlag)
{
	UChar byte0 = *pByte++;
	UChar byte1 = *pByte;
	if (bigEndianFlag) {
		return (static_cast<UShort>(byte0) << 8) + byte1;
	} else {
		return (static_cast<UShort>(byte1) << 8) + byte0;
	}
}

UInt32 Packer::UnpackUInt32(const UChar *pByte, bool bigEndianFlag)
{
	UChar byte0 = *pByte++;
	UChar byte1 = *pByte++;
	UChar byte2 = *pByte++;
	UChar byte3 = *pByte;
	if (bigEndianFlag) {
		return (static_cast<ULong>(byte0) << 24) +
				(static_cast<ULong>(byte1) << 16) +
				(static_cast<ULong>(byte2) << 8) +
				byte3;
	} else {
		return (static_cast<ULong>(byte3) << 24) +
				(static_cast<ULong>(byte2) << 16) +
				(static_cast<ULong>(byte1) << 8) +
				byte0;
	}
}

UInt64 Packer::UnpackUInt64(const UChar *pByte, bool bigEndianFlag)
{
	UChar byte0 = *pByte++;
	UChar byte1 = *pByte++;
	UChar byte2 = *pByte++;
	UChar byte3 = *pByte++;
	UChar byte4 = *pByte++;
	UChar byte5 = *pByte++;
	UChar byte6 = *pByte++;
	UChar byte7 = *pByte;
	if (bigEndianFlag) {
		return (static_cast<UInt64>(byte0) << 56) +
				(static_cast<UInt64>(byte1) << 48) +
				(static_cast<UInt64>(byte2) << 40) +
				(static_cast<UInt64>(byte3) << 32) +
				(static_cast<UInt64>(byte4) << 24) +
				(static_cast<UInt64>(byte5) << 16) +
				(static_cast<UInt64>(byte6) << 8) +
				byte7;
	} else {
		return (static_cast<UInt64>(byte7) << 56) +
				(static_cast<UInt64>(byte6) << 48) +
				(static_cast<UInt64>(byte5) << 40) +
				(static_cast<UInt64>(byte4) << 32) +
				(static_cast<UInt64>(byte3) << 24) +
				(static_cast<UInt64>(byte2) << 16) +
				(static_cast<UInt64>(byte1) << 8) +
				byte0;
	}
}

}
