//=============================================================================
// Pointer
//=============================================================================
#ifndef __GURA_POINTER_H__
#define __GURA_POINTER_H__

#include "Environment.h"
#include "Signal.h"
#include "Value.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Pointer
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Pointer : public Packer {
protected:
	size_t _offset;
public:
	Pointer(size_t offset);
protected:
	virtual ~Pointer();
public:
	inline void SetOffset(size_t offset) { _offset = offset; }
	inline size_t GetOffset() const { return _offset; }
	inline void Reset() { _offset = 0; }
	inline size_t GetSize() const {
		size_t bytesEntire = GetEntireSize();
		return (_offset < bytesEntire)? bytesEntire - _offset : 0;
	}
	bool Advance(Environment &env, int distance);
	bool PackStay(Environment &env, const char *format, const ValueList &valListArg);
	Value UnpackStay(Environment &env, const char *format,
				 const ValueList &valListArg, bool exeedErrorFlag);
	template<typename T> bool PutStay(Environment &env, T num, bool bigEndianFlag) {
		size_t offset = _offset;
		bool rtn = Put<T>(env, num, bigEndianFlag);
		_offset = offset;
		return rtn;
	}
	template<typename T> bool GetStay(Environment &env, T *pNum, bool bigEndianFlag, bool exceedErrorFlag) {
		size_t offset = _offset;
		bool rtn = Get<T>(env, pNum, bigEndianFlag, exceedErrorFlag);
		_offset = offset;
		return rtn;
	}
public:
	virtual Pointer *Clone() const = 0;
	virtual Object *GetTarget() const = 0;
	virtual const UChar *GetPointerC() const = 0;
	virtual size_t GetEntireSize() const = 0;
	virtual bool IsWritable() const = 0;
};

}

#endif
