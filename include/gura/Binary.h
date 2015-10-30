//=============================================================================
// Binary
//=============================================================================
#ifndef __GURA_BINARY_H__
#define __GURA_BINARY_H__

#include "Common.h"
#include "Signal.h"
#include "Value.h"

namespace Gura {

class GURA_DLLDECLARE Binary : public String {
public:
	inline Binary() {}
	inline Binary(const Binary &binary) : String(binary) {}
	inline Binary(const String &str) : String(str) {}
	inline Binary(const char *str) : String(str) {}
	inline Binary(const char *buff, size_t size) : String(buff, size) {}
	inline Binary &operator=(const Binary &binary) {
		String::operator=(binary);
		return *this;
	}
public:
	bool Pack(Environment &env, size_t &offset,
				const char *format, const ValueList &valListArg);
	Value Unpack(Environment &env, size_t &offset,
				const char *format, const ValueList &valListArg, bool exceedErrorFlag);
	bool PackForward(Signal &sig, size_t offset, size_t bytes);
	bool UnpackForward(Signal &sig,size_t &offset, int distance, bool exceedErrorFlag);
	static void PackUShort(iterator pByte, bool bigEndianFlag, UShort num);
	static void PackULong(iterator pByte, bool bigEndianFlag, ULong num);
	static void PackUInt64(iterator pByte, bool bigEndianFlag, UInt64 num);
	static UShort UnpackUShort(iterator pByte, bool bigEndianFlag);
	static ULong UnpackULong(iterator pByte, bool bigEndianFlag);
	static UInt64 UnpackUInt64(iterator pByte, bool bigEndianFlag);
	static bool CheckString(Signal &sig,
				const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal &sig,
				const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal &sig, const ValueList &valList,
				ValueList::const_iterator pValue, Number numMin, Number numMax);
};

}

#endif
