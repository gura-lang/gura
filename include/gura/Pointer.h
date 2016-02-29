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
class GURA_DLLDECLARE Pointer {
protected:
	int _cntRef;
	size_t _offset;
public:
	Gura_DeclareReferenceAccessor(Pointer)
public:
	Pointer(size_t offset);
	virtual ~Pointer();
	inline size_t GetOffset() const { return _offset; }
	inline void Reset() { _offset = 0; }
	bool Advance(Environment &env, int distance, bool exceedErrorFlag);
public:
	virtual Pointer *Clone() const = 0;
	virtual Object *GetTarget() const = 0;
	virtual size_t GetSize() const = 0;
	virtual bool IsWritable() const = 0;
	virtual bool Pack(Environment &env, bool forwardFlag,
					  const char *format, const ValueList &valListArg) = 0;
	virtual Value Unpack(Environment &env, bool forwardFlag,
						 const char *format, const ValueList &valListArg, bool exeedErrorFlag) = 0;
	virtual Iterator *CreateUnpackIterator(const char *format, const ValueList &valList) = 0;
};

}

#endif
