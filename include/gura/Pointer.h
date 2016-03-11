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
	class GURA_DLLDECLARE StreamEx : public Stream {
	private:
		AutoPtr<Pointer> _pPointer;
	public:
		StreamEx(Environment &env, Pointer *pPointer);
		virtual ~StreamEx();
		virtual const char *GetName() const;
		virtual const char *GetIdentifier() const;
		virtual size_t DoRead(Signal &sig, void *buff, size_t len);
		virtual size_t DoWrite(Signal &sig, const void *buff, size_t len);
		virtual bool DoSeek(Signal &sig, long offset, size_t offsetPrev, SeekMode seekMode);
		virtual bool DoFlush(Signal &sig);
		virtual bool DoClose(Signal &sig);
		virtual size_t DoGetSize();
		inline Pointer &GetPointer() { return *_pPointer; }
		inline const Pointer &GetPointer() const { return *_pPointer; }
	};
protected:
	size_t _offset;
public:
	Pointer(size_t offset);
	Pointer(const Pointer &ptr);
protected:
	virtual ~Pointer();
public:
	inline void SetOffset(size_t offset) { _offset = offset; }
	inline size_t GetOffset() const { return _offset; }
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
