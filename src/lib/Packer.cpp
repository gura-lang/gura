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
			UChar *pByte = PackForward(sig, offset, nRepeat);
			if (pByte == nullptr) return false;
			nRepeat = 1;
		} else if (ch == 'c') {
			UChar *pByte = PackForward(sig, offset, nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte++, pValueArg++) {
				if (!CheckString(sig, valListArg, pValueArg)) return false;
				*pByte = pValueArg->GetString()[0];
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			UChar *pByte = PackForward(sig, offset, nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -128, 127)) return false;
				*pByte = pValueArg->GetChar();
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			UChar *pByte = PackForward(sig, offset, nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte++, pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 255)) return false;
				*pByte = pValueArg->GetUChar();
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			UChar *pByte = PackForward(sig, offset, sizeof(Short) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Short), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -32768, 32767)) return false;
				UShort num = static_cast<UShort>(pValueArg->GetShort());
				PackUShort(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			UChar *pByte = PackForward(sig, offset, sizeof(UShort) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UShort), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 65535)) return false;
				UShort num = pValueArg->GetUShort();
				PackUShort(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			UChar *pByte = PackForward(sig, offset, sizeof(Int32) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -2147483648., 2147483647.)) return false;
				UInt32 num = static_cast<UInt32>(pValueArg->GetInt32());
				PackUInt32(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			UChar *pByte = PackForward(sig, offset, sizeof(UInt32) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 4294967295.)) return false;
				UInt32 num = pValueArg->GetUInt32();
				PackUInt32(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			UChar *pByte = PackForward(sig, offset, sizeof(Int32) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, -2147483648., 2147483647.)) return false;
				UInt32 num = static_cast<UInt32>(pValueArg->GetInt32());
				PackUInt32(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			UChar *pByte = PackForward(sig, offset, sizeof(UInt32) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg, 0, 4294967295.)) return false;
				UInt32 num = pValueArg->GetUInt32();
				PackUInt32(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			UChar *pByte = PackForward(sig, offset, sizeof(Int64) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int64), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				UInt64 num = static_cast<UInt64>(pValueArg->GetInt64());
				PackUInt64(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			UChar *pByte = PackForward(sig, offset, sizeof(UInt64) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt64), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				UInt64 num = pValueArg->GetUInt64();
				PackUInt64(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			UChar *pByte = PackForward(sig, offset, sizeof(float) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(float), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				float num = pValueArg->GetFloat();
				PackFloat(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			UChar *pByte = PackForward(sig, offset, sizeof(double) * nRepeat);
			if (pByte == nullptr) return false;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(double), pValueArg++) {
				if (!CheckNumber(sig, valListArg, pValueArg)) return false;
				double num = pValueArg->GetDouble();
				PackDouble(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 's') {
			UChar *pByte = PackForward(sig, offset, nRepeat);
			if (pByte == nullptr) return false;
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
					*pByte++ = chConv, nPacked++;
					while (pCodec->GetEncoder()->FollowChar(chConv) && nPacked < nRepeat) {
						*pByte++ = chConv, nPacked++;
					}
				}
			}
			for ( ; nPacked < nRepeat; nPacked++, pByte++) {
				*pByte = '\0';
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
			const UChar *pByte = UnpackForward(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			nRepeat = 1;
		} else if (ch == 'c') {
			const UChar *pByte = UnpackForward(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			char str[2];
			str[1] = '\0';
			for (int i = 0; i < nRepeat; i++, pByte++) {
				str[0] = *pByte;
				pObjList->Add(Value(str));
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			const UChar *pByte = UnpackForward(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				Char num = *pByte;
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			const UChar *pByte = UnpackForward(sig, offset, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				UChar num = *pByte;
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(Short) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Short)) {
				Short num = static_cast<Short>(UnpackUShort(pByte, bigEndianFlag));
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(UShort) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UShort)) {
				UShort num = UnpackUShort(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(Int32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32)) {
				Int32 num = static_cast<Int32>(UnpackUInt32(pByte, bigEndianFlag));
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(UInt32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32)) {
				UInt32 num = UnpackUInt32(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(Int32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32)) {
				Int32 num = static_cast<Int32>(UnpackUInt32(pByte, bigEndianFlag));
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(UInt32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32)) {
				UInt32 num = UnpackUInt32(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(Int64) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int64)) {
				Int64 num = static_cast<Int64>(UnpackUInt64(pByte, bigEndianFlag));
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(UInt64) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt64)) {
				UInt64 num = UnpackUInt64(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(float) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(float)) {
				float num = UnpackFloat(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			const UChar *pByte = UnpackForward(sig, offset, sizeof(double) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(double)) {
				double num = UnpackDouble(pByte, bigEndianFlag);
				pObjList->Add(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 's') {
			const UChar *pByte = UnpackForward(sig, offset, nRepeat, exceedErrorFlag);
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
			nRepeat = 1;
		} else if (ch == 'p') {
			//iterator pByte = begin() + offset;
			//if (!UnpackForward(sig, offset, nRepeat, exceedErrorFlag)) return Value::Nil;
			//for (int i = 0; i < nRepeat; i++, pByte++) {
			//}
			//nRepeat = 1;
			sig.SetError(ERR_ValueError, "sorry, not implemented yet");
			return Value::Nil;
		} else if (ch == 'P') {
			//iterator pByte = begin() + offset;
			//if (!UnpackForward(sig, offset, 4 * nRepeat, exceedErrorFlag)) return Value::Nil;
			//for (int i = 0; i < nRepeat; i++, pByte += 4) {
			//}
			//nRepeat = 1;
			sig.SetError(ERR_ValueError, "sorry, not implemented yet");
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

void Packer::PackUShort(UChar *pByte, bool bigEndianFlag, UShort num)
{
	UChar byte0 = static_cast<UChar>(num >> 8);
	UChar byte1 = static_cast<UChar>(num >> 0);
	if (bigEndianFlag) {
		*(pByte + 0) = byte0;
		*(pByte + 1) = byte1;
	} else {
		*(pByte + 0) = byte1;
		*(pByte + 1) = byte0;
	}
}

void Packer::PackUInt32(UChar *pByte, bool bigEndianFlag, UInt32 num)
{
	UChar byte0 = static_cast<UChar>(num >> 24);
	UChar byte1 = static_cast<UChar>(num >> 16);
	UChar byte2 = static_cast<UChar>(num >> 8);
	UChar byte3 = static_cast<UChar>(num >> 0);
	if (bigEndianFlag) {
		*(pByte + 0) = byte0;
		*(pByte + 1) = byte1;
		*(pByte + 2) = byte2;
		*(pByte + 3) = byte3;
	} else {
		*(pByte + 0) = byte3;
		*(pByte + 1) = byte2;
		*(pByte + 2) = byte1;
		*(pByte + 3) = byte0;
	}
}

void Packer::PackUInt64(UChar *pByte, bool bigEndianFlag, UInt64 num)
{
	UChar byte0 = static_cast<UChar>(num >> 56);
	UChar byte1 = static_cast<UChar>(num >> 48);
	UChar byte2 = static_cast<UChar>(num >> 40);
	UChar byte3 = static_cast<UChar>(num >> 32);
	UChar byte4 = static_cast<UChar>(num >> 24);
	UChar byte5 = static_cast<UChar>(num >> 16);
	UChar byte6 = static_cast<UChar>(num >> 8);
	UChar byte7 = static_cast<UChar>(num >> 0);
	if (bigEndianFlag) {
		*(pByte + 0) = byte0;
		*(pByte + 1) = byte1;
		*(pByte + 2) = byte2;
		*(pByte + 3) = byte3;
		*(pByte + 4) = byte4;
		*(pByte + 5) = byte5;
		*(pByte + 6) = byte6;
		*(pByte + 7) = byte7;
	} else {
		*(pByte + 0) = byte7;
		*(pByte + 1) = byte6;
		*(pByte + 2) = byte5;
		*(pByte + 3) = byte4;
		*(pByte + 4) = byte3;
		*(pByte + 5) = byte2;
		*(pByte + 6) = byte1;
		*(pByte + 7) = byte0;
	}
}

UShort Packer::UnpackUShort(const UChar *pByte, bool bigEndianFlag)
{
	UChar byte0 = static_cast<UChar>(*(pByte + 0));
	UChar byte1 = static_cast<UChar>(*(pByte + 1));
	if (bigEndianFlag) {
		return (static_cast<UShort>(byte0) << 8) + byte1;
	} else {
		return (static_cast<UShort>(byte1) << 8) + byte0;
	}
}

UInt32 Packer::UnpackUInt32(const UChar *pByte, bool bigEndianFlag)
{
	UChar byte0 = static_cast<UChar>(*(pByte + 0));
	UChar byte1 = static_cast<UChar>(*(pByte + 1));
	UChar byte2 = static_cast<UChar>(*(pByte + 2));
	UChar byte3 = static_cast<UChar>(*(pByte + 3));
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
	UChar byte0 = static_cast<UChar>(*(pByte + 0));
	UChar byte1 = static_cast<UChar>(*(pByte + 1));
	UChar byte2 = static_cast<UChar>(*(pByte + 2));
	UChar byte3 = static_cast<UChar>(*(pByte + 3));
	UChar byte4 = static_cast<UChar>(*(pByte + 4));
	UChar byte5 = static_cast<UChar>(*(pByte + 5));
	UChar byte6 = static_cast<UChar>(*(pByte + 6));
	UChar byte7 = static_cast<UChar>(*(pByte + 7));
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
