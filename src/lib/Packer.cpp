//=============================================================================
// Packer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Packer
//-----------------------------------------------------------------------------
bool Packer::Pack(Environment &env, size_t &offset,
				  const char *format, const ValueList &valListArg)
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
			if (!PackAt(sig, offset, nRepeat)) return false;
			offset += nRepeat;
			nRepeat = 1;
		} else if (ch == 'c') {
			if (!PackAt(sig, offset, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset++, pValueArg++) {
				if (!CheckString(sig, valListArg, pValueArg)) return false;
				PackUChar(offset, pValueArg->GetString()[0]);
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			if (!PackAt(sig, offset, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -128, 127)) return false;
				PackUChar(offset, pValueArg->GetChar());
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			if (!PackAt(sig, offset, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 255)) return false;
				PackUChar(offset, pValueArg->GetUChar());
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			if (!PackAt(sig, offset, sizeof(Short) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(Short), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -32768, 32767)) return false;
				PackUShort(offset, bigEndianFlag, static_cast<UShort>(pValueArg->GetShort()));
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			if (!PackAt(sig, offset, sizeof(UShort) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(UShort), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 65535)) return false;
				PackUShort(offset, bigEndianFlag, pValueArg->GetUShort());
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			if (!PackAt(sig, offset, sizeof(Int32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(Int32), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -2147483648., 2147483647.)) return false;
				PackUInt32(offset, bigEndianFlag, static_cast<UInt32>(pValueArg->GetInt32()));
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			if (!PackAt(sig, offset, sizeof(UInt32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(UInt32), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 4294967295.)) return false;
				PackUInt32(offset, bigEndianFlag, pValueArg->GetUInt32());
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			if (!PackAt(sig, offset, sizeof(Int32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(Int32), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -2147483648., 2147483647.)) return false;
				PackUInt32(offset, bigEndianFlag, static_cast<UInt32>(pValueArg->GetInt32()));
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			if (!PackAt(sig, offset, sizeof(UInt32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(UInt32), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 4294967295.)) return false;
				PackUInt32(offset, bigEndianFlag, pValueArg->GetUInt32());
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			if (!PackAt(sig, offset, sizeof(Int64) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(Int64), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				PackUInt64(offset, bigEndianFlag, static_cast<UInt64>(pValueArg->GetInt64()));
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			if (!PackAt(sig, offset, sizeof(UInt64) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(UInt64), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				PackUInt64(offset, bigEndianFlag, pValueArg->GetUInt64());
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			if (!PackAt(sig, offset, sizeof(float) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(float), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				PackFloat(offset, bigEndianFlag, pValueArg->GetFloat());
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			if (!PackAt(sig, offset, sizeof(double) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, offset += sizeof(double), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				PackDouble(offset, bigEndianFlag, pValueArg->GetDouble());
			}
			nRepeat = 1;
		} else if (ch == 's') {
			if (!PackAt(sig, offset, nRepeat)) return false;
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
					PackUChar(offset, chConv), offset++, nPacked++;
					while (pCodec->GetEncoder()->FollowChar(chConv) && nPacked < nRepeat) {
						PackUChar(offset, chConv), offset++, nPacked++;
					}
				}
			}
			for ( ; nPacked < nRepeat; offset++, nPacked++) {
				PackUChar(offset, '\0');
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

Value Packer::Unpack(Environment &env, size_t &offset,
					 const char *format, const ValueList &valListArg, bool exceedErrorFlag)
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
			const UChar *pByte = UnpackAt(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			offset += nRepeat;
			nRepeat = 1;
		} else if (ch == 'c') {
			const UChar *pByte = UnpackAt(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			char str[2];
			str[1] = '\0';
			for (int i = 0; i < nRepeat; i++, pByte++) {
				str[0] = *pByte;
				pObjList->Add(Value(str));
			}
			offset += nRepeat;
			nRepeat = 1;
		} else if (ch == 'b') {
			const UChar *pByte = UnpackAt(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				Char num = *pByte;
				pObjList->Add(Value(num));
			}
			offset += nRepeat;
			nRepeat = 1;
		} else if (ch == 'B') {
			const UChar *pByte = UnpackAt(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				UChar num = *pByte;
				pObjList->Add(Value(num));
			}
			offset += nRepeat;
			nRepeat = 1;
		} else if (ch == 'h') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(Short) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Short)) {
				Short num = static_cast<Short>(UnpackUShort(pByte, bigEndianFlag));
				pObjList->Add(Value(num));
			}
			offset += sizeof(Short) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'H') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(UShort) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UShort)) {
				UShort num = UnpackUShort(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			offset += sizeof(UShort) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'i') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(Int32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32)) {
				Int32 num = static_cast<Int32>(UnpackUInt32(pByte, bigEndianFlag));
				pObjList->Add(Value(num));
			}
			offset += sizeof(Int32) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'I') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(UInt32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32)) {
				UInt32 num = UnpackUInt32(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			offset += sizeof(UInt32) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'l') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(Int32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32)) {
				Int32 num = static_cast<Int32>(UnpackUInt32(pByte, bigEndianFlag));
				pObjList->Add(Value(num));
			}
			offset += sizeof(Int32) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'L') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(UInt32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32)) {
				UInt32 num = UnpackUInt32(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			offset += sizeof(UInt32) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'q') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(Int64) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int64)) {
				Int64 num = static_cast<Int64>(UnpackUInt64(pByte, bigEndianFlag));
				pObjList->Add(Value(num));
			}
			offset += sizeof(Int64) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'Q') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(UInt64) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt64)) {
				UInt64 num = UnpackUInt64(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			offset += sizeof(UInt64) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'f') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(float) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(float)) {
				float num = UnpackFloat(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			offset += sizeof(float) * nRepeat;
			nRepeat = 1;
		} else if (ch == 'd') {
			const UChar *pByte = UnpackAt(sig, offset, sizeof(double) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(double)) {
				double num = UnpackDouble(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			offset += sizeof(double) * nRepeat;
			nRepeat = 1;
		} else if (ch == 's') {
			const UChar *pByte = UnpackAt(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			String str;
			//str.reserve(nRepeat);
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
			offset += nRepeat;
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

void Packer::PackUShort(size_t offset, bool bigEndianFlag, UShort num)
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
	PackBuffer(offset, buff, sizeof(UShort));
}

void Packer::PackUInt32(size_t offset, bool bigEndianFlag, UInt32 num)
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
	PackBuffer(offset, buff, sizeof(UInt32));
}

void Packer::PackUInt64(size_t offset, bool bigEndianFlag, UInt64 num)
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
	PackBuffer(offset, buff, sizeof(UInt64));
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
