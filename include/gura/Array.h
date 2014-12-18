//=============================================================================
// Array
//=============================================================================
#ifndef __GURA_ARRAY_H__
#define __GURA_ARRAY_H__

#include "Memory.h"
#include "Iterator.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Array
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE Array {
private:
	int _cntRef;
	AutoPtr<Memory> _pMemory;
	size_t _cnt;
	size_t _offsetBase;
public:
	Gura_DeclareReferenceAccessor(Array);
public:
	inline Array(const Array &src) : _cntRef(1),
		_pMemory(src._pMemory->Reference()), _cnt(src._cnt), _offsetBase(src._offsetBase) {}
	inline Array(size_t cnt, size_t offsetBase = 0) : _cntRef(1),
		_pMemory(new MemoryHeap(sizeof(T_Elem) * cnt)), _cnt(cnt), _offsetBase(offsetBase) {}
	inline Array(Memory *pMemory, size_t cnt, size_t offsetBase = 0) : _cntRef(1),
		_pMemory(pMemory), _cnt(cnt), _offsetBase(offsetBase) {}
	inline Memory *GetMemory() { return _pMemory.get(); }
	inline const Memory *GetMemory() const { return _pMemory.get(); }
	inline T_Elem *GetPointer() {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + _offsetBase;
	}
	inline const T_Elem *GetPointer() const {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + _offsetBase;
	}
	inline size_t GetSize() const { return _cnt; }
	inline size_t GetOffsetBase() const { return _offsetBase; }
	inline operator T_Elem *() { return GetPointer(); }
	inline operator const T_Elem *() const { return GetPointer(); }
	void Fill(const T_Elem &num) {
		T_Elem *p = GetPointer();
		for (size_t i = 0; i < _cnt; i++, p++) {
			*p = num;
		}
	}
	void FillZero() {
		::memset(GetPointer(), 0x00, sizeof(T_Elem) * GetSize());
	}
	bool Paste(Signal sig, size_t offset, const Array *pArraySrc) {
		if (GetSize() < offset + pArraySrc->GetSize()) {
			sig.SetError(ERR_OutOfRangeError, "out of range");
			return false;
		}
		::memcpy(GetPointer() + offset, pArraySrc->GetPointer(),
				 sizeof(T_Elem) * pArraySrc->GetSize());
		return true;
	}
private:
	inline ~Array() {}
};

//-----------------------------------------------------------------------------
// Iterator_Array
//-----------------------------------------------------------------------------
template<typename T_Elem>
class GURA_DLLDECLARE Iterator_Array : public Iterator {
private:
	AutoPtr<Array<T_Elem> > _pArray;
	size_t _idx;
public:
	inline Iterator_Array(Array<T_Elem> *pArray) : Iterator(false), _pArray(pArray), _idx(0) {}
	virtual Iterator *GetSource() { return NULL; }
	virtual bool DoNext(Environment &env, Signal sig, Value &value) {
		if (_idx >= _pArray->GetSize()) return false;
		value = Value(*(_pArray->GetPointer() + _idx));
		_idx++;
		return true;
	}
	virtual String ToString() const {
		String rtn;
		rtn = "array";
		return rtn;
	}
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet) {
	}
};

//-----------------------------------------------------------------------------
// functions
//-----------------------------------------------------------------------------
template<typename T_Elem>
void CopyArrayToList(const Array<T_Elem> *pArray, ValueList &valList)
{
	const T_Elem *p = pArray->GetPointer();
	for (size_t cnt = pArray->GetSize(); cnt > 0; cnt--, p++) {
		valList.push_back(Value(*p));
	}
}

template<typename T_Elem>
Array<T_Elem> *CreateArrayFromList(const ValueList &valList)
{
	AutoPtr<Array<T_Elem> > pArray(new Array<T_Elem>(valList.size()));
	T_Elem *p = pArray->GetPointer();
	foreach_const (ValueList, pValue, valList) {
		*p++ = static_cast<T_Elem>(pValue->GetNumber());
	}
	return pArray.release();
}

template<typename T_Elem>
Array<T_Elem> *CreateArrayFromList(Signal sig, const ValueList &valList)
{
	AutoPtr<Array<T_Elem> > pArray(new Array<T_Elem>(valList.size()));
	T_Elem *p = pArray->GetPointer();
	foreach_const (ValueList, pValue, valList) {
		if (!pValue->Is_number() && !pValue->Is_boolean()) {
			sig.SetError(ERR_ValueError, "element must be a number or a boolean");
			return NULL;
		}
		*p++ = static_cast<T_Elem>(pValue->GetNumber());
	}
	return pArray.release();
}

}

#endif
