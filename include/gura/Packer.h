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
	virtual bool PackAt(Signal &sig, size_t offset, size_t bytes) = 0;
	virtual void PackBuffer(size_t offset, const UChar *buff, size_t bytes) = 0;
	virtual const UChar *UnpackAt(Signal &sig, size_t offset,
								  size_t bytes, bool exceedErrorFlag) = 0;
private:
	static bool CheckString(Signal &sig,
							const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal &sig,
							const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal &sig, const ValueList &valList,
							ValueList::const_iterator pValue, Number numMin, Number numMax);
private:
	inline void PackUChar(size_t offset, UChar num) {
		PackBuffer(offset, &num, sizeof(UChar));
	}
	void PackUShort(size_t offset, bool bigEndianFlag, UShort num);
	void PackUInt32(size_t offset, bool bigEndianFlag, UInt32 num);
	void PackUInt64(size_t offset, bool bigEndianFlag, UInt64 num);
	inline void PackFloat(size_t offset, bool bigEndianFlag, float num) {
		PackUInt32(offset, bigEndianFlag, *reinterpret_cast<UInt32 *>(&num));
	}
	inline void PackDouble(size_t offset, bool bigEndianFlag, double num) {
		PackUInt64(offset, bigEndianFlag, *reinterpret_cast<UInt64 *>(&num));
	}
private:
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
