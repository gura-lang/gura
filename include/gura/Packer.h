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
	bool DoPack(Environment &env, size_t &offset,
			  const char *format, const ValueList &valListArg);
	Value DoUnpack(Environment &env, size_t &offset,
				 const char *format, const ValueList &valListArg, bool exceedErrorFlag);
	virtual bool PackPrepare(Signal &sig, size_t offset, size_t bytes) = 0;
	virtual void PackBuffer(size_t offset, const UChar *buff, size_t bytes) = 0;
	virtual const UChar *UnpackPrepare(Signal &sig, size_t offset,
								  size_t bytes, bool exceedErrorFlag) = 0;
private:
	static bool CheckString(Signal &sig,
							const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal &sig,
							const ValueList &valList, ValueList::const_iterator pValue);
	static bool CheckNumber(Signal &sig, const ValueList &valList,
							ValueList::const_iterator pValue, Number numMin, Number numMax);
private:
	inline void PackChar(size_t offset, Char num) {
		PackUChar(offset, static_cast<UChar>(num));
	}
	inline void PackUChar(size_t offset, UChar num) {
		PackBuffer(offset, &num, sizeof(UChar));
	}
	inline void PackShort(size_t offset, bool bigEndianFlag, Short num) {
		PackUShort(offset, bigEndianFlag, static_cast<UShort>(num));
	}
	void PackUShort(size_t offset, bool bigEndianFlag, UShort num);
	inline void PackInt32(size_t offset, bool bigEndianFlag, Int32 num) {
		PackUInt32(offset, bigEndianFlag, static_cast<UInt32>(num));
	}
	void PackUInt32(size_t offset, bool bigEndianFlag, UInt32 num);
	inline void PackInt64(size_t offset, bool bigEndianFlag, Int64 num) {
		PackUInt64(offset, bigEndianFlag, static_cast<UInt64>(num));
	}
	void PackUInt64(size_t offset, bool bigEndianFlag, UInt64 num);
	inline void PackFloat(size_t offset, bool bigEndianFlag, float num) {
		PackUInt32(offset, bigEndianFlag, *reinterpret_cast<UInt32 *>(&num));
	}
	inline void PackDouble(size_t offset, bool bigEndianFlag, double num) {
		PackUInt64(offset, bigEndianFlag, *reinterpret_cast<UInt64 *>(&num));
	}
private:
	inline static Char UnpackChar(const UChar *pByte) {
		return static_cast<Char>(UnpackUChar(pByte));
	}
	inline static UChar UnpackUChar(const UChar *pByte) { return *pByte; }
	inline static Short UnpackShort(const UChar *pByte, bool bigEndianFlag) {
		return static_cast<Short>(UnpackUShort(pByte, bigEndianFlag));
	}
	static UShort UnpackUShort(const UChar *pByte, bool bigEndianFlag);
	inline static Int32 UnpackInt32(const UChar *pByte, bool bigEndianFlag) {
		return static_cast<Int32>(UnpackUInt32(pByte, bigEndianFlag));
	}
	static UInt32 UnpackUInt32(const UChar *pByte, bool bigEndianFlag);
	inline static Int64 UnpackInt64(const UChar *pByte, bool bigEndianFlag) {
		return static_cast<Int64>(UnpackUInt64(pByte, bigEndianFlag));
	}
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
