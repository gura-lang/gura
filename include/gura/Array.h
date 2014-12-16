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
public:
	class GURA_DLLDECLARE Iterator {
	private:
		AutoPtr<Array<T_Elem> > _pArray;
		size_t _idx;
	public:
		inline Iterator(Array<T_Elem> *pArray) : Iterator(false), _pArray(pArray), _idx(0) {}
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
	};
private:
	int _cntRef;
	AutoPtr<Memory> _pMemory;
	size_t _cnt;
	size_t _offsetBase;
public:
	Gura_DeclareReferenceAccessor(Array);
public:
	inline Array(size_t cnt, size_t offsetBase = 0) : _cntRef(1),
			_pMemory(new MemoryHeap(sizeof(T_Elem) * cnt)), _cnt(cnt), _offsetBase(offsetBase) {
		::memset(_pMemory->GetPointer(), sizeof(T_Elem) * cnt, 0x00);
	}
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
	void AddToList(ValueList &valList) const {
		const T_Elem *p = GetPointer();
		for (size_t i = 0; i < _cnt; i++) {
			valList.push_back(Value(*p));
		}
	}
	static Array *CreateFromList(Signal sig, const ValueList &valList) {
		AutoPtr<Array<T_Elem> > pArray(new Array<T_Elem>(valList.size(), valList.size()));
		T_Elem *p = pArray->GetPointer();
		foreach_const (ValueList, pValue, valList) {
			if (!pValue->Is_number()) {
				sig.SetError(ERR_ValueError, "element must be a number");
				return NULL;
			}
			*p++ = static_cast<T_Elem>(pValue->GetNumber());
		}
		return pArray.release();
	}
private:
	inline ~Array() {}
};

}

#endif
