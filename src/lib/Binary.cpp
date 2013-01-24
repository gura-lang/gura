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
	std::auto_ptr<Codec> pCodec(new Codec_None());
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
					pCodec.reset(new Codec_None());
				} else {
					CodecFactory *pCodecFactory =
									CodecFactory::Lookup(encoding.c_str());
					if (pCodecFactory == NULL) {
						sig.SetError(ERR_CodecError,
								"unsupported encoding '%s'", encoding.c_str());
						return false;
					}
					pCodec.reset(pCodecFactory->CreateEncoder(false));
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
				unsigned short num = pValue->GetShort();
				PackUShort(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			if (!PackForward(sig, offset, 2 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 2 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 2, pValue++) {
				if (!CheckNumber(sig, valList, pValue, 0, 65535)) return false;
				unsigned short num = pValue->GetUShort();
				PackUShort(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 4, pValue++) {
				if (!CheckNumber(sig, valList, pValue, -2147483648., 2147483647.)) return false;
				unsigned long num = pValue->GetInt();
				PackULong(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 4, pValue++) {
				if (!CheckNumber(sig, valList, pValue, 0, 4294967295.)) return false;
				unsigned long num = pValue->GetUInt();
				PackULong(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 4, pValue++) {
				if (!CheckNumber(sig, valList, pValue, -2147483648., 2147483647.)) return false;
				unsigned long num = pValue->GetLong();
				PackULong(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			if (!PackForward(sig, offset, 4 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 4 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pByte += 4, pValue++) {
				if (!CheckNumber(sig, valList, pValue, 0, 4294967295.)) return false;
				unsigned long num = pValue->GetULong();
				PackULong(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			if (!PackForward(sig, offset, 8 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 8 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pValue++) {
				if (!CheckNumber(sig, valList, pValue)) return false;
				int64 num = static_cast<int64>(pValue->GetNumber());
				PackUInt64(pByte, bigEndianFlag, num);
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			if (!PackForward(sig, offset, 8 * nRepeat)) return false;
			iterator pByte = begin() + offset;
			offset += 8 * nRepeat;
			for (int i = 0; i < nRepeat; i++, pValue++) {
				if (!CheckNumber(sig, valList, pValue)) return false;
				uint64 num = static_cast<uint64>(pValue->GetNumber());
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
				unsigned char *buff = reinterpret_cast<unsigned char *>(&num);
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
				unsigned char *buff = reinterpret_cast<unsigned char *>(&num);
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
				Codec::Result result = pCodec->FeedChar(*p, chConv);
				if (result == Codec::RESULT_Error) {
					sig.SetError(ERR_CodecError,
						"encoding error. specify a proper coding name by {coding}");
					return false;
				} else if (result == Codec::RESULT_Complete) {
					*pByte++ = chConv, nPacked++;
					while (pCodec->FollowChar(chConv) && nPacked < nRepeat) {
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
	std::auto_ptr<Codec> pCodec(new Codec_None());
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
					pCodec.reset(new Codec_None());
				} else {
					CodecFactory *pCodecFactory =
									CodecFactory::Lookup(encoding.c_str());
					if (pCodecFactory == NULL) {
						sig.SetError(ERR_CodecError,
								"unsupported encoding '%s'", encoding.c_str());
						return Value::Null;
					}
					pCodec.reset(pCodecFactory->CreateDecoder(false));
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
				unsigned char num = *pByte;
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
				unsigned short num = UnpackUShort(pByte, bigEndianFlag);
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
				unsigned int num = static_cast<unsigned int>(UnpackULong(pByte, bigEndianFlag));
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
				unsigned long num = static_cast<unsigned long>(UnpackULong(pByte, bigEndianFlag));
				valList.push_back(Value(num));
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 8 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 8) {
				int64 num = static_cast<int64>(UnpackUInt64(pByte, bigEndianFlag));
				valList.push_back(Value(static_cast<Number>(num)));
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			iterator pByte = begin() + offset;
			if (!UnpackForward(sig, offset, 8 * nRepeat, exceedErrorFlag)) return Value::Null;
			for (int i = 0; i < nRepeat; i++, pByte += 8) {
				uint64 num = static_cast<uint64>(UnpackUInt64(pByte, bigEndianFlag));
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
				Codec::Result result = pCodec->FeedChar(*pByte, chConv);
				if (result == Codec::RESULT_Error) {
					sig.SetError(ERR_CodecError,
						"decoding error. specify a proper coding name by {coding}");
					return false;
				} else if (result == Codec::RESULT_Complete) {
					str.push_back(chConv);
					while (pCodec->FollowChar(chConv)) str.push_back(chConv);
				}
			}
			// flush unprocessed characters
			if (pCodec->Flush(chConv)) while (pCodec->FollowChar(chConv)) ;
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

void Binary::PackUShort(iterator pByte, bool bigEndianFlag, unsigned short num)
{
	unsigned char byte0 = static_cast<unsigned char>(num >> 8);
	unsigned char byte1 = static_cast<unsigned char>(num >> 0);
	if (bigEndianFlag) {
		*(pByte + 0) = byte0;
		*(pByte + 1) = byte1;
	} else {
		*(pByte + 0) = byte1;
		*(pByte + 1) = byte0;
	}
}

void Binary::PackULong(iterator pByte, bool bigEndianFlag, unsigned long num)
{
	unsigned char byte0 = static_cast<unsigned char>(num >> 24);
	unsigned char byte1 = static_cast<unsigned char>(num >> 16);
	unsigned char byte2 = static_cast<unsigned char>(num >> 8);
	unsigned char byte3 = static_cast<unsigned char>(num >> 0);
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

void Binary::PackUInt64(iterator pByte, bool bigEndianFlag, uint64 num)
{
	unsigned char byte0 = static_cast<unsigned char>(num >> 56);
	unsigned char byte1 = static_cast<unsigned char>(num >> 48);
	unsigned char byte2 = static_cast<unsigned char>(num >> 40);
	unsigned char byte3 = static_cast<unsigned char>(num >> 32);
	unsigned char byte4 = static_cast<unsigned char>(num >> 24);
	unsigned char byte5 = static_cast<unsigned char>(num >> 16);
	unsigned char byte6 = static_cast<unsigned char>(num >> 8);
	unsigned char byte7 = static_cast<unsigned char>(num >> 0);
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

unsigned short Binary::UnpackUShort(iterator pByte, bool bigEndianFlag)
{
	unsigned char byte0 = static_cast<unsigned char>(*(pByte + 0));
	unsigned char byte1 = static_cast<unsigned char>(*(pByte + 1));
	if (bigEndianFlag) {
		return (static_cast<unsigned short>(byte0) << 8) + byte1;
	} else {
		return (static_cast<unsigned short>(byte1) << 8) + byte0;
	}
}

unsigned long Binary::UnpackULong(iterator pByte, bool bigEndianFlag)
{
	unsigned char byte0 = static_cast<unsigned char>(*(pByte + 0));
	unsigned char byte1 = static_cast<unsigned char>(*(pByte + 1));
	unsigned char byte2 = static_cast<unsigned char>(*(pByte + 2));
	unsigned char byte3 = static_cast<unsigned char>(*(pByte + 3));
	if (bigEndianFlag) {
		return (static_cast<unsigned long>(byte0) << 24) +
				(static_cast<unsigned long>(byte1) << 16) +
				(static_cast<unsigned long>(byte2) << 8) +
				byte3;
	} else {
		return (static_cast<unsigned long>(byte3) << 24) +
				(static_cast<unsigned long>(byte2) << 16) +
				(static_cast<unsigned long>(byte1) << 8) +
				byte0;
	}
}

uint64 Binary::UnpackUInt64(iterator pByte, bool bigEndianFlag)
{
	unsigned char byte0 = static_cast<unsigned char>(*(pByte + 0));
	unsigned char byte1 = static_cast<unsigned char>(*(pByte + 1));
	unsigned char byte2 = static_cast<unsigned char>(*(pByte + 2));
	unsigned char byte3 = static_cast<unsigned char>(*(pByte + 3));
	unsigned char byte4 = static_cast<unsigned char>(*(pByte + 4));
	unsigned char byte5 = static_cast<unsigned char>(*(pByte + 5));
	unsigned char byte6 = static_cast<unsigned char>(*(pByte + 6));
	unsigned char byte7 = static_cast<unsigned char>(*(pByte + 7));
	if (bigEndianFlag) {
		return (static_cast<uint64>(byte0) << 56) +
				(static_cast<uint64>(byte1) << 48) +
				(static_cast<uint64>(byte2) << 40) +
				(static_cast<uint64>(byte3) << 32) +
				(static_cast<uint64>(byte4) << 24) +
				(static_cast<uint64>(byte5) << 16) +
				(static_cast<uint64>(byte6) << 8) +
				byte7;
	} else {
		return (static_cast<uint64>(byte7) << 56) +
				(static_cast<uint64>(byte6) << 48) +
				(static_cast<uint64>(byte5) << 40) +
				(static_cast<uint64>(byte4) << 32) +
				(static_cast<uint64>(byte3) << 24) +
				(static_cast<uint64>(byte2) << 16) +
				(static_cast<uint64>(byte1) << 8) +
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
