//=============================================================================
// Packer
//=============================================================================
#ifndef __GURA_PACKER_H__
#define __GURA_PACKER_H__

#include "Common.h"
#include "Signal.h"
#include "Value.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Packer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Packer {
public:
	bool Pack(Environment &env, size_t &offset,
			  const char *format, const ValueList &valListArg);
	Value Unpack(Environment &env, size_t &offset,
				 const char *format, const ValueList &valListArg, bool exceedErrorFlag);
	virtual UChar *PackForward(Signal &sig, size_t &offset, size_t bytes) = 0;
	virtual const UChar *UnpackForward(Signal &sig, size_t &offset,
									   int distance, bool exceedErrorFlag) = 0;
private:
	static bool CheckString(Signal &sig,
							const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal &sig,
							const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal &sig, const ValueList &valList,
							ValueList::const_iterator pValue, Number numMin, Number numMax);
	static void PackUShort(UChar *pByte, bool bigEndianFlag, UShort num);
	static void PackUInt32(UChar *pByte, bool bigEndianFlag, UInt32 num);
	static void PackUInt64(UChar *pByte, bool bigEndianFlag, UInt64 num);
	inline static void PackFloat(UChar *pByte, bool bigEndianFlag, float num) {
		PackUInt32(pByte, bigEndianFlag, *reinterpret_cast<UInt32 *>(&num));
	}
	inline static void PackDouble(UChar *pByte, bool bigEndianFlag, double num) {
		PackUInt64(pByte, bigEndianFlag, *reinterpret_cast<UInt64 *>(&num));
	}
	static UShort UnpackUShort(const UChar *pByte, bool bigEndianFlag);
	static UInt32 UnpackUInt32(const UChar *pByte, bool bigEndianFlag);
	static UInt64 UnpackUInt64(const UChar *pByte, bool bigEndianFlag);
	inline static float UnpackFloat(const UChar *pByte, bool bigEndianFlag) {
		UInt32 num = UnpackUInt32(pByte, bigEndianFlag);
		return *reinterpret_cast<float *>(&num);
	}
	inline static double UnpackDouble(const UChar *pByte, bool bigEndianFlag) {
		UInt64 num = UnpackUInt64(pByte, bigEndianFlag);
		return *reinterpret_cast<double *>(&num);
	}
};

}

#endif
