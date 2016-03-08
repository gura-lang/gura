//=============================================================================
// Packer
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Packer
//-----------------------------------------------------------------------------
Packer::Packer() : _cntRef(1)
{
}

Packer::~Packer()
{
}

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
			if (!PackPrepare(env, nRepeat)) return false;
			PackForward(nRepeat);
			nRepeat = 1;
		} else if (ch == 'c') {
			if (!PackPrepare(env, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckString(env, valListArg, pValueArg)) return false;
				Store<Char>(pValueArg->GetString()[0], false);
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			if (!PackPrepare(env, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg, -128, 127)) return false;
				Store<Char>(pValueArg->GetChar(), false);
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			if (!PackPrepare(env, nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg, 0, 255)) return false;
				Store<UChar>(pValueArg->GetUChar(), false);
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			if (!PackPrepare(env, sizeof(Short) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg, -32768, 32767)) return false;
				Store<Short>(pValueArg->GetShort(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			if (!PackPrepare(env, sizeof(UShort) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg, 0, 65535)) return false;
				Store<UShort>(pValueArg->GetUShort(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			if (!PackPrepare(env, sizeof(Int32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg, -2147483648., 2147483647.)) return false;
				Store<Int32>(pValueArg->GetInt32(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			if (!PackPrepare(env, sizeof(UInt32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg, 0, 4294967295.)) return false;
				Store<UInt32>(pValueArg->GetUInt32(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			if (!PackPrepare(env, sizeof(Int32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg, -2147483648., 2147483647.)) return false;
				Store<Int32>(pValueArg->GetInt32(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			if (!PackPrepare(env, sizeof(UInt32) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg, 0, 4294967295.)) return false;
				Store<UInt32>(pValueArg->GetUInt32(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			if (!PackPrepare(env, sizeof(Int64) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg)) return false;
				Store<Int64>(pValueArg->GetInt64(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			if (!PackPrepare(env, sizeof(UInt64) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg)) return false;
				Store<UInt64>(pValueArg->GetUInt64(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			if (!PackPrepare(env, sizeof(float) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg)) return false;
				Store<Float>(pValueArg->GetFloat(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			if (!PackPrepare(env, sizeof(double) * nRepeat)) return false;
			for (int i = 0; i < nRepeat; i++, pValueArg++) {
				if (!CheckNumber(env, valListArg, pValueArg)) return false;
				Store<Double>(pValueArg->GetDouble(), bigEndianFlag);
			}
			nRepeat = 1;
		} else if (ch == 's') {
			if (!PackPrepare(env, nRepeat)) return false;
			if (!CheckString(env, valListArg, pValueArg)) return false;
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
					Store<UChar>(chConv, false), nPacked++;
					while (pCodec->GetEncoder()->FollowChar(chConv) && nPacked < nRepeat) {
						Store<UChar>(chConv, false), nPacked++;
					}
				}
			}
			for ( ; nPacked < nRepeat; nPacked++) {
				Store<UChar>('\0', false);
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
			const UChar *pByte = UnpackPrepare(env, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			nRepeat = 1;
		} else if (ch == 'c') {
			const UChar *pByte = UnpackPrepare(env, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			char str[2];
			str[1] = '\0';
			for (int i = 0; i < nRepeat; i++, pByte++) {
				str[0] = Extract<Char>(pByte, false);
				pObjList->Add(Value(str));
			}
			nRepeat = 1;
		} else if (ch == 'b') {
			const UChar *pByte = UnpackPrepare(env, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				pObjList->Add(Value(Extract<Char>(pByte, false)));
			}
			nRepeat = 1;
		} else if (ch == 'B') {
			const UChar *pByte = UnpackPrepare(env, nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte++) {
				pObjList->Add(Value(Extract<UChar>(pByte, false)));
			}
			nRepeat = 1;
		} else if (ch == 'h') {
			const UChar *pByte = UnpackPrepare(env, sizeof(Short) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Short)) {
				pObjList->Add(Value(Extract<Short>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'H') {
			const UChar *pByte = UnpackPrepare(env, sizeof(UShort) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UShort)) {
				pObjList->Add(Value(Extract<UShort>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'i') {
			const UChar *pByte = UnpackPrepare(env, sizeof(Int32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32)) {
				pObjList->Add(Value(Extract<Int32>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'I') {
			const UChar *pByte = UnpackPrepare(env, sizeof(UInt32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32)) {
				pObjList->Add(Value(Extract<UInt32>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'l') {
			const UChar *pByte = UnpackPrepare(env, sizeof(Int32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int32)) {
				pObjList->Add(Value(Extract<Int32>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'L') {
			const UChar *pByte = UnpackPrepare(env, sizeof(UInt32) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt32)) {
				pObjList->Add(Value(Extract<UInt32>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'q') {
			const UChar *pByte = UnpackPrepare(env, sizeof(Int64) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(Int64)) {
				pObjList->Add(Value(Extract<Int64>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'Q') {
			const UChar *pByte = UnpackPrepare(env, sizeof(UInt64) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(UInt64)) {
				pObjList->Add(Value(Extract<UInt64>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'f') {
			const UChar *pByte = UnpackPrepare(env, sizeof(float) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(float)) {
				pObjList->Add(Value(Extract<Float>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 'd') {
			const UChar *pByte = UnpackPrepare(env, sizeof(double) * nRepeat, exceedErrorFlag);
			if (pByte == nullptr) return Value::Nil;
			for (int i = 0; i < nRepeat; i++, pByte += sizeof(double)) {
				pObjList->Add(Value(Extract<Double>(pByte, bigEndianFlag)));
			}
			nRepeat = 1;
		} else if (ch == 's') {
			const UChar *pByte = UnpackPrepare(env, nRepeat, exceedErrorFlag);
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

#if 0
template<> bool Packer::Put<Char>(Environment &env, Char num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(Char))) return false;
	PackChar(num);
	return true;
}

template<> bool Packer::Put<UChar>(Environment &env, UChar num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(UChar))) return false;
	PackUChar(num);
	return true;
}

template<> bool Packer::Put<Short>(Environment &env, Short num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(Short))) return false;
	PackShort(num, bigEndianFlag);
	return true;
}

template<> bool Packer::Put<UShort>(Environment &env, UShort num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(UShort))) return false;
	PackUShort(num, bigEndianFlag);
	return true;
}

template<> bool Packer::Put<Int32>(Environment &env, Int32 num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(Int32))) return false;
	PackInt32(num, bigEndianFlag);
	return true;
}

template<> bool Packer::Put<UInt32>(Environment &env, UInt32 num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(UInt32))) return false;
	PackUInt32(num, bigEndianFlag);
	return true;
}

template<> bool Packer::Put<Int64>(Environment &env, Int64 num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(Int64))) return false;
	PackInt64(num, bigEndianFlag);
	return true;
}

template<> bool Packer::Put<UInt64>(Environment &env, UInt64 num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(UInt64))) return false;
	PackUInt64(num, bigEndianFlag);
	return true;
}

template<> bool Packer::Put<Float>(Environment &env, float num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(float))) return false;
	PackFloat(num, bigEndianFlag);
	return true;
}

template<> bool Packer::Put<Double>(Environment &env, double num, bool bigEndianFlag)
{
	if (!PackPrepare(env, sizeof(double))) return false;
	PackDouble(num, bigEndianFlag);
	return true;
}

template<> bool Packer::Get<Char>(Environment &env, Char *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(Char), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackChar(pByte);
	return true;
}

template<> bool Packer::Get<UChar>(Environment &env, UChar *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(UChar), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackUChar(pByte);
	return true;
}

template<> bool Packer::Get<Short>(Environment &env, Short *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(Short), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackShort(pByte, bigEndianFlag);
	return true;
}

template<> bool Packer::Get<UShort>(Environment &env, UShort *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(UShort), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackUShort(pByte, bigEndianFlag);
	return true;
}

template<> bool Packer::Get<Int32>(Environment &env, Int32 *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(Int32), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackInt32(pByte, bigEndianFlag);
	return true;
}

template<> bool Packer::Get<UInt32>(Environment &env, UInt32 *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(UInt32), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackUInt32(pByte, bigEndianFlag);
	return true;
}

template<> bool Packer::Get<Int64>(Environment &env, Int64 *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(Int64), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackInt64(pByte, bigEndianFlag);
	return true;
}

template<> bool Packer::Get<UInt64>(Environment &env, UInt64 *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(UInt64), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackUInt64(pByte, bigEndianFlag);
	return true;
}

template<> bool Packer::Get<Float>(Environment &env, float *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(float), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackFloat(pByte, bigEndianFlag);
	return true;
}

template<> bool Packer::Get<Double>(Environment &env, double *pNum, bool bigEndianFlag, bool exceedErrorFlag)
{
	const UChar *pByte = UnpackPrepare(env, sizeof(double), exceedErrorFlag);
	if (pByte == nullptr) return false;
	*pNum = UnpackDouble(pByte, bigEndianFlag);
	return true;
}
#endif

bool Packer::PutBuffer(Environment &env, const void *buff, size_t bytes)
{
	if (!PackPrepare(env, bytes)) return false;
	PackBuffer(buff, bytes);
	return true;
}

bool Packer::CheckString(Environment &env,
				const ValueList &valList, ValueList::const_iterator pValue)
{
	if (pValue == valList.end()) {
		env.SetError(ERR_ValueError, "not enough arguments");
		return false;
	} else if (!pValue->Is_string()) {
		env.SetError(ERR_ValueError, "string value is expected");
		return false;
	}
	return true;
}

bool Packer::CheckNumber(Environment &env,
				const ValueList &valList, ValueList::const_iterator pValue)
{
	if (pValue == valList.end()) {
		env.SetError(ERR_ValueError, "not enough arguments");
		return false;
	} else if (!pValue->Is_number()) {
		env.SetError(ERR_ValueError, "number value is expected");
		return false;
	}
	return true;
}

bool Packer::CheckNumber(Environment &env, const ValueList &valList,
				ValueList::const_iterator pValue, Number numMin, Number numMax)
{
	if (!CheckNumber(env, valList, pValue)) return false;
	Number num = pValue->GetNumber();
	if (num < numMin || num > numMax) {
		env.SetError(ERR_ValueError, "number is out of range");
		return false;
	}
	return true;
}

template<> void Packer::Store<Char>(Char num, bool bigEndianFlag)
{
	Store<UChar>(static_cast<UChar>(num), bigEndianFlag);
}

template<> void Packer::Store<UChar>(UChar num, bool bigEndianFlag)
{
	PackBuffer(&num, sizeof(UChar));
}

template<> void Packer::Store<Short>(Short num, bool bigEndianFlag)
{
	Store<UShort>(static_cast<UShort>(num), bigEndianFlag);
}

template<> void Packer::Store<UShort>(UShort num, bool bigEndianFlag)
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

template<> void Packer::Store<Int32>(Int32 num, bool bigEndianFlag)
{
	Store<UInt32>(static_cast<UInt32>(num), bigEndianFlag);
}

template<> void Packer::Store<UInt32>(UInt32 num, bool bigEndianFlag)
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

template<> void Packer::Store<Int64>(Int64 num, bool bigEndianFlag)
{
	Store<UInt64>(static_cast<UInt64>(num), bigEndianFlag);
}

template<> void Packer::Store<UInt64>(UInt64 num, bool bigEndianFlag)
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

template<> void Packer::Store<Float>(Float num, bool bigEndianFlag)
{
	Store<UInt32>(*reinterpret_cast<UInt32 *>(&num), bigEndianFlag);
}

template<> void Packer::Store<Double>(Double num, bool bigEndianFlag)
{
	Store<UInt64>(*reinterpret_cast<UInt64 *>(&num), bigEndianFlag);
}

template<> Char Packer::Extract<Char>(const UChar *pByte, bool bigEndianFlag)
{
	return static_cast<Char>(Extract<UChar>(pByte, bigEndianFlag));
}

template<> UChar Packer::Extract<UChar>(const UChar *pByte, bool bigEndianFlag)
{
	return *pByte;
}

template<> Short Packer::Extract<Short>(const UChar *pByte, bool bigEndianFlag)
{
	return static_cast<Short>(Extract<UShort>(pByte, bigEndianFlag));
}

template<> UShort Packer::Extract<UShort>(const UChar *pByte, bool bigEndianFlag)
{
	UChar byte0 = *pByte++;
	UChar byte1 = *pByte;
	if (bigEndianFlag) {
		return (static_cast<UShort>(byte0) << 8) + byte1;
	} else {
		return (static_cast<UShort>(byte1) << 8) + byte0;
	}
}

template<> Int32 Packer::Extract<Int32>(const UChar *pByte, bool bigEndianFlag)
{
	return static_cast<Int32>(Extract<UInt32>(pByte, bigEndianFlag));
}

template<> UInt32 Packer::Extract<UInt32>(const UChar *pByte, bool bigEndianFlag)
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

template<> Int64 Packer::Extract<Int64>(const UChar *pByte, bool bigEndianFlag)
{
	return static_cast<Int64>(Extract<UInt64>(pByte, bigEndianFlag));
}

template<> UInt64 Packer::Extract<UInt64>(const UChar *pByte, bool bigEndianFlag)
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

template<> Float Packer::Extract<Float>(const UChar *pByte, bool bigEndianFlag)
{
	UInt32 num = Extract<UInt32>(pByte, bigEndianFlag);
	return *reinterpret_cast<Float *>(&num);
}

template<> Double Packer::Extract<Double>(const UChar *pByte, bool bigEndianFlag)
{
	UInt64 num = Extract<UInt64>(pByte, bigEndianFlag);
	return *reinterpret_cast<Double *>(&num);
}

#if 0
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
#endif

//-----------------------------------------------------------------------------
// Packer::IteratorUnpack
//-----------------------------------------------------------------------------
Packer::IteratorUnpack::IteratorUnpack(Packer *pPacker,
				const char *format, const ValueList &valListArg) :
		Iterator(false), _pPacker(pPacker), _format(format), _valListArg(valListArg)
{
}

Iterator *Packer::IteratorUnpack::GetSource()
{
	return nullptr;
}

bool Packer::IteratorUnpack::DoNext(Environment &env, Value &value)
{
	value = _pPacker->Unpack(env, _format.c_str(), _valListArg, false);
	return value.IsValid();
}

String Packer::IteratorUnpack::ToString() const
{
	return String("packer.unpacks");
}

void Packer::IteratorUnpack::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
