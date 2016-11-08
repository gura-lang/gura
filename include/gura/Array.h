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
class GURA_DLLDECLARE Array {
public:
	class GURA_DLLDECLARE Dimension {
	private:
		size_t _cnt;
		size_t _stride;
	public:
		inline Dimension() : _cnt(0), _stride(0) {}
		inline Dimension(size_t cnt) : _cnt(cnt), _stride(0) {}
		inline size_t GetCount() const { return _cnt; }
		inline size_t GetStride() const { return _stride; }
		inline void SetStride(size_t stride) { _stride = stride; }
	};
	class GURA_DLLDECLARE Dimensions : public std::vector<Dimension> {
	public:
		static bool IsSameShape(const Dimensions &dimsA, const Dimensions &dimsB);
		static bool IsElemwiseCalculatable(const Dimensions &dimsA, const Dimensions &dimsB);
	};
protected:
	int _cntRef;
	AutoPtr<Memory> _pMemory;
	Dimensions _dims;
	size_t _offsetBase;
	size_t _cntTotal;
public:
	inline Array() : _cntRef(1), _offsetBase(0), _cntTotal(0) {}
	inline Array(const Array &src) : _cntRef(1),
		_pMemory(src._pMemory->Reference()), _dims(src._dims),
		_offsetBase(src._offsetBase), _cntTotal(src._cntTotal) {}
	inline Array(Memory *pMemory) : _cntRef(1),
		_pMemory(pMemory), _offsetBase(0), _cntTotal(0) {}
	inline void SetSize1D(size_t cnt) {
		_dims.reserve(1);
		_dims.push_back(Dimension(cnt));
		UpdateMetrics();
	}
	inline void SetSize(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd) {
		_dims.reserve(std::distance(pDim, pDimEnd));
		std::copy(pDim, pDimEnd, std::back_inserter(_dims));
		UpdateMetrics();
	}
	inline void SetSize(const Dimensions &dims) {
		_dims = dims;
		UpdateMetrics();
	}
	inline Memory &GetMemory() { return *_pMemory; }
	inline const Memory &GetMemory() const { return *_pMemory; }
	inline Dimensions &GetDimensions() { return _dims; }
	inline const Dimensions &GetDimensions() const { return _dims; }
	inline size_t GetCountTotal() const { return _cntTotal; }
	inline void SetOffsetBase(size_t offsetBase) { _offsetBase = offsetBase; }
	inline size_t GetOffsetBase() const { return _offsetBase; }
	void UpdateMetrics();
public:
	static bool CheckShape(Signal &sig, const Array &arrayA, const Array &arrayB);
	static bool CheckElemwiseCalculatable(Signal &sig, const Array &arrayA, const Array &arrayB);
};
	
}

#endif
