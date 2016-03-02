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
public:
	class GURA_DLLDECLARE IteratorUnpack : public Iterator {
	private:
		AutoPtr<Pointer> _pPointer;
		String _format;
		ValueList _valListArg;
	public:
		IteratorUnpack(Pointer *pPointer, const char *format, const ValueList &valListArg);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
protected:
	int _cntRef;
	size_t _offset;
public:
	Gura_DeclareReferenceAccessor(Pointer)
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
	bool Pack(Environment &env, const char *format,
			  const ValueList &valListArg, bool forwardFlag);
	Value Unpack(Environment &env, const char *format,
				 const ValueList &valListArg, bool forwardFlag, bool exeedErrorFlag);
public:
	virtual Pointer *Clone() const = 0;
	virtual Object *GetTarget() const = 0;
	virtual const UChar *GetPointerC() const = 0;
	virtual size_t GetEntireSize() const = 0;
	virtual bool IsWritable() const = 0;
};

}

#endif
