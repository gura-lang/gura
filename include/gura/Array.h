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
	size_t _offset;
public:
	Gura_DeclareReferenceAccessor(Array);
public:
	Array(size_t cnt, size_t offset = 0) : _cntRef(1),
		_pMemory(new MemoryHeap(sizeof(T_Elem) * cnt)), _offset(offset) {}
	Array(Memory *pMemory, size_t offset = 0) : _cntRef(1), _pMemory(pMemory), _offset(offset) {}
	Memory *GetMemory() { return _pMemory.get(); }
	const Memory *GetMemory() const { return _pMemory.get(); }
	T_Elem *GetPointer(size_t idx) {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + _offset + idx;
	}
	const T_Elem *GetPointer(size_t idx) const {
		return reinterpret_cast<T_Elem *>(_pMemory->GetPointer()) + _offset + idx;
	}
	size_t GetSize() const {
		return _pMemory->GetSize() / sizeof(T_Elem) - _offset;
	}
private:
	~Array() {}
};

}

#endif
