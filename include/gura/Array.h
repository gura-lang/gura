//=============================================================================
// Array
//=============================================================================
#ifndef __GURA_ARRAY_H__
#define __GURA_ARRAY_H__

#include "Memory.h"
#include "Iterator.h"
#include "Stream.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Array
//-----------------------------------------------------------------------------
class Array {
public:
	class Dimension {
	private:
		size_t _cnt;
		size_t _stride;
	public:
		inline Dimension(size_t cnt, size_t stride) : _cnt(cnt), _stride(stride) {}
		inline size_t GetCount() const { return _cnt; }
		inline size_t GetStride() const { return _stride; }
	};
	class Dimensions : public std::vector<Dimension> {
	public:
		static bool IsSameShape(const Dimensions &dimsA, const Dimensions &dimsB);
	};
protected:
	int _cntRef;
	AutoPtr<Memory> _pMemory;
	Dimensions _dims;
	size_t _offsetBase;
public:
	inline Array(const Array &src) : _cntRef(1),
		_pMemory(src._pMemory->Reference()), _dims(src._dims), _offsetBase(src._offsetBase) {}
	inline Array(Memory *pMemory, size_t cnt, size_t offsetBase = 0) : _cntRef(1),
		_pMemory(pMemory), _offsetBase(offsetBase) {
		_dims.reserve(1);
		_dims.push_back(Dimension(cnt, 0));
	}
	inline Array(Memory *pMemory, const Dimensions &dims, size_t offsetBase = 0) : _cntRef(1),
		_pMemory(pMemory), _dims(dims), _offsetBase(offsetBase) {}
	inline Memory &GetMemory() { return *_pMemory; }
	inline const Memory &GetMemory() const { return *_pMemory; }
	inline const Dimensions &GetDimensions() const { return _dims; }
	inline size_t GetSize() const { return _dims[0].GetCount(); }
	inline size_t GetOffsetBase() const { return _offsetBase; }
public:
	static bool CheckShape(Signal &sig, const Array &arrayA, const Array &arrayB);
};
	
}

#endif
