#ifndef __GURA_BINARY_H__
#define __GURA_BINARY_H__

#include "Common.h"
#include "Signal.h"
#include "Value.h"

namespace Gura {

class GURA_DLLDECLARE Binary : public std::basic_string<char> {
public:
	inline Binary() {}
	inline Binary(const Binary &binary) : std::basic_string<char>(binary) {}
	inline Binary(const String &str) : std::basic_string<char>(str) {}
	inline Binary(const char *str) : std::basic_string<char>(str) {}
	inline Binary(const char *buff, size_t size) : std::basic_string<char>(buff, size) {}
	inline Binary &operator=(const Binary &binary) {
		std::basic_string<char>::operator=(binary);
		return *this;
	}
public:
	bool Pack(Environment &env, Signal sig,
				size_t &offset, const char *format, const ValueList &valList);
	Value Unpack(Environment &env, Signal sig,
				size_t &offset, const char *format, bool exceedErrorFlag);
	bool PackForward(Signal sig, size_t offset, size_t bytes);
	bool UnpackForward(Signal sig,size_t &offset, int distance, bool exceedErrorFlag);
	static void PackUShort(iterator pByte, bool bigEndianFlag, unsigned short num);
	static void PackULong(iterator pByte, bool bigEndianFlag, unsigned long num);
	static void PackUInt64(iterator pByte, bool bigEndianFlag, uint64 num);
	static unsigned short UnpackUShort(iterator pByte, bool bigEndianFlag);
	static unsigned long UnpackULong(iterator pByte, bool bigEndianFlag);
	static uint64 UnpackUInt64(iterator pByte, bool bigEndianFlag);
	static bool CheckString(Signal sig,
				const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal sig,
				const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal sig, const ValueList &valList,
				ValueList::const_iterator pValue, Number numMin, Number numMax);
};

}

#endif
