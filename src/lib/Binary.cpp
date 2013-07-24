#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Binary
//-----------------------------------------------------------------------------
bool Binary::Pack(Environment &env, Signal sig, size_t &offset,
							const char *format, const ValueList &valList)
{
	enum {
		STAT_Format,
		STAT_Repeat,
		STAT_Encoding,
	} stat = STAT_Format;
	ValueList::const_iterator pValue = valList.begin();
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
			if (pValue == valList.end()) {
				sig.SetError(ERR_ValueError, "not enough arguments");
				return false;
			}
			if (!pValue->IsNumber()) {
				sig.SetError(ERR_ValueError,
								"repeat specifier requires a number value");
				return false;
			}
			nRepeat = pValue->GetInt();
			pValue++;
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
			if (!PackForward(sig, offset, nRepeat)) return false;
			offset += nRepeat;
			nRepeat = 1;
		} else if (ch == 'c') {
			if (!PackForward(sig, offset, nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte++, pValue++) {
				if (!CheckString(sig, valList, pValue)) return false;
				*pByte = pValue->GetString()[0];
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			if (!PackForward(sig, offset, nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte++, pValue++) {
				if (!CheckNumber(sig, valList, pValue, -128, 127)) return false;
				*pByte = pValue->GetChar();
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			if (!PackForward(sig, offset, nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte++, pValue++) {
				if (!CheckNumber(sig, valList, pValue, 0, 255)) return false;
				*pByte = pValue->GetUChar();
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			if (!PackForward(sig, offset, 2 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 2 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 2, pValue++) {
				if (!CheckNumber(sig, valList, pValue, -32768, 32767)) return false;
				UShort num = pValue->GetShort();
				PackUShort(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			if (!PackForward(sig, offset, 2 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 2 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 2, pValue++) {
				if (!CheckNumber(sig, valList, pValue, 0, 65535)) return false;
				UShort num = pValue->GetUShort();
				PackUShort(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 4, pValue++) {
				if (!CheckNumber(sig, valList, pValue, -2147483648., 2147483647.)) return false;
				ULong num = pValue->GetInt();
				PackULong(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 4, pValue++) {
				if (!CheckNumber(sig, valList, pValue, 0, 4294967295.)) return false;
				ULong num = pValue->GetUInt();
				PackULong(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 4, pValue++) {
				if (!CheckNumber(sig, valList, pValue, -2147483648., 2147483647.)) return false;
				ULong num = pValue->GetLong();
				PackULong(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 4, pValue++) {
				if (!CheckNumber(sig, valList, pValue, 0, 4294967295.)) return false;
				ULong num = pValue->GetULong();
				PackULong(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			if (!PackForward(sig, offset, 8 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 8 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pValue++) {
				if (!CheckNumber(sig, valList, pValue)) return false;
				Int64 num = static_cast<Int64>(pValue->GetNumber());
				PackUInt64(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			if (!PackForward(sig, offset, 8 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 8 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pValue++) {
				if (!CheckNumber(sig, valList, pValue)) return false;
				UInt64 num = static_cast<UInt64>(pValue->GetNumber());
				PackUInt64(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pValue++) {
				if (!CheckNumber(sig, valList, pValue)) return false;
				float num = static_cast<float>(pValue->GetNumber());
				UChar *buff = reinterpret_cast<UChar *>(&num);
				for (int j = 0; j < 4; j++, pByte++) *pByte = buff[j];
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			if (!PackForward(sig, offset, 8 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 8 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pValue++) {
				if (!CheckNumber(sig, valList, pValue)) return false;
				double num = static_cast<double>(pValue->GetNumber());
				UChar *buff = reinterpret_cast<UChar *>(&num);
				for (int j = 0; j < 8; j++, pByte++) *pByte = buff[j];
			}
			nRepeat = 1;
		} else if (ch == 's') {
			if (!PackForward(sig, offset, nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += nRepeat;
			if (!CheckString(sig, valList, pValue)) return false;
			const char *p = pValue->GetString();
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
			pValue++;
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

Value Binary::Unpack(Environment &env, Signal sig,
				size_t &offset, const char *format, bool exceedErrorFlag)
{
	enum {
		STAT_Format,
		STAT_Repeat,
		STAT_Encoding,
	} stat = STAT_Format;
	Value result;
	ValueList &valList = result.InitAsList(env);
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
					if (sig.IsSignalled()) return Value::Null;
				}
				stat = STAT_Format;
			} else {
				encoding.push_back(ch);
			}
		} else if (IsDigit(ch)) {
			nRepeat = 0;
			eatNextFlag = false;
			stat = STAT_Repeat;
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
			if (!UnpackForward(sig, offset, nRepeat, exceedErrorFlag)) return Value::Null;
			nRepeat = 1;
		} else if (ch == 'c') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, nRepeat, exceedErrorFlag)) return Value::Null;
			char str[2];
			str[1] = '\0';
			for (int i = 0; i < nRepeat; i++, pByte++) {
				str[0] = *pByte;
				valList.push_back(Value(env, str));
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				char num = *pByte;
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				UChar num = *pByte;
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 2 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 2) {
				short num = static_cast<short>(UnpackUShort(pByte, bigEndianFlag));
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 2 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 2) {
				UShort num = UnpackUShort(pByte, bigEndianFlag);
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 4 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 4) {
				int num = static_cast<int>(UnpackULong(pByte, bigEndianFlag));
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 4 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 4) {
				UInt num = static_cast<UInt>(UnpackULong(pByte, bigEndianFlag));
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 4 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 4) {
				long num = static_cast<long>(UnpackULong(pByte, bigEndianFlag));
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 4 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 4) {
				ULong num = static_cast<ULong>(UnpackULong(pByte, bigEndianFlag));
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 8 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 8) {
				Int64 num = static_cast<Int64>(UnpackUInt64(pByte, bigEndianFlag));
				valList.push_back(Value(static_cast<Number>(num)));
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 8 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 8) {
				UInt64 num = static_cast<UInt64>(UnpackUInt64(pByte, bigEndianFlag));
				valList.push_back(Value(static_cast<Number>(num)));
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 4 * nRepeat, exceedErrorFlag)) return Value::Null;
			char buff[4];
			for (int i = 0; i < nRepeat; i++) {
				for (int j = 0; j < 4; j++, pByte++) buff[j] = *pByte;
				float num = *(reinterpret_cast<float *>(buff));
				valList.push_back(Value(static_cast<Number>(num)));
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 8 * nRepeat, exceedErrorFlag)) return Value::Null;
			char buff[8];
			for (int i = 0; i < nRepeat; i++) {
				for (int j = 0; j < 8; j++, pByte++) buff[j] = *pByte;
				double num = *(reinterpret_cast<double *>(buff));
				valList.push_back(Value(static_cast<Number>(num)));
			}
			nRepeat = 1;
		} else if (ch == 's') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, nRepeat, exceedErrorFlag)) return Value::Null;
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
			valList.push_back(Value(env, str.c_str()));
			nRepeat = 1;
		} else if (ch == 'p') {
			//iterator pByte = begin() + offset;
			//if (!UnpackForward(sig, offset, nRepeat, exceedErrorFlag)) return Value::Null;
			//for (int i = 0; i < nRepeat; i++, pByte++) {
			//}
			//nRepeat = 1;
			sig.SetError(ERR_ValueError, "sorry, not implemented yet");
			return Value::Null;
		} else if (ch == 'P') {
			//iterator pByte = begin() + offset;
			//if (!UnpackForward(sig, offset, 4 * nRepeat, exceedErrorFlag)) return Value::Null;
			//for (int i = 0; i < nRepeat; i++, pByte += 4) {
			//}
			//nRepeat = 1;
			sig.SetError(ERR_ValueError, "sorry, not implemented yet");
			return Value::Null;
		} else if (IsWhite(ch)) {
			// just ignore white characters
		} else {
			sig.SetError(ERR_ValueError, "invalid character in format");
			return Value::Null;
		}
		if (eatNextFlag) p++;
	}
	return result;
}

bool Binary::PackForward(Signal sig, size_t offset, size_t bytes)
{
	if (offset + bytes > size()) {
		append(offset + bytes - size(), '\0');
	}
	return true;
}

bool Binary::UnpackForward(Signal sig, size_t &offset, int distance, bool exceedErrorFlag)
{
	if ((distance < 0 && offset < static_cast<size_t>(-distance)) ||
					(distance > 0 && offset + distance > size())) {
		if (exceedErrorFlag) {
			sig.SetError(ERR_IndexError, "pointer exceeds the range of binary");
		}
		return false;
	}
	offset += distance;
	return true;
}

void Binary::PackUShort(iterator pByte, bool bigEndianFlag, UShort num)
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

void Binary::PackULong(iterator pByte, bool bigEndianFlag, ULong num)
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

void Binary::PackUInt64(iterator pByte, bool bigEndianFlag, UInt64 num)
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

UShort Binary::UnpackUShort(iterator pByte, bool bigEndianFlag)
{
	UChar byte0 = static_cast<UChar>(*(pByte + 0));
	UChar byte1 = static_cast<UChar>(*(pByte + 1));
	if (bigEndianFlag) {
		return (static_cast<UShort>(byte0) << 8) + byte1;
	} else {
		return (static_cast<UShort>(byte1) << 8) + byte0;
	}
}

ULong Binary::UnpackULong(iterator pByte, bool bigEndianFlag)
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

UInt64 Binary::UnpackUInt64(iterator pByte, bool bigEndianFlag)
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

bool Binary::CheckString(Signal sig,
				const ValueList &valList, ValueList::const_iterator pValue)
{
	if (pValue == valList.end()) {
		sig.SetError(ERR_ValueError, "not enough arguments");
		return false;
	} else if (!pValue->IsString()) {
		sig.SetError(ERR_ValueError, "string value is expected");
		return false;
	}
	return true;
}

bool Binary::CheckNumber(Signal sig,
				const ValueList &valList, ValueList::const_iterator pValue)
{
	if (pValue == valList.end()) {
		sig.SetError(ERR_ValueError, "not enough arguments");
		return false;
	} else if (!pValue->IsNumber()) {
		sig.SetError(ERR_ValueError, "number value is expected");
		return false;
	}
	return true;
}

bool Binary::CheckNumber(Signal sig, const ValueList &valList,
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

}
