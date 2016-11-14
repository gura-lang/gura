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
		size_t _size;
		size_t _stride;
	public:
		inline Dimension() : _size(0), _stride(0) {}
		inline Dimension(size_t size) : _size(size), _stride(0) {}
		inline size_t GetSize() const { return _size; }
		inline size_t GetStride() const { return _stride; }
		inline void SetStride(size_t stride) { _stride = stride; }
	};
	class GURA_DLLDECLARE Dimensions : public std::vector<Dimension> {
	public:
		static bool IsSameShape(const Dimensions &dimsA, const Dimensions &dimsB);
		static bool IsElemwiseCalculatable(const Dimensions &dimsA, const Dimensions &dimsB);
		static bool IsDotProductCalculatable(const Dimensions &dimsA, const Dimensions &dimsB);
	};
protected:
	int _cntRef;
	AutoPtr<Memory> _pMemory;
	Dimensions _dims;
	size_t _offsetBase;
	size_t _elemNum;
public:
	Gura_DeclareReferenceAccessor(Array);
public:
	inline Array() : _cntRef(1), _offsetBase(0), _elemNum(0) {}
	inline Array(const Array &src) : _cntRef(1),
		_pMemory(src._pMemory->Reference()), _dims(src._dims),
		_offsetBase(src._offsetBase), _elemNum(src._elemNum) {}
	inline Array(Memory *pMemory) : _cntRef(1),
		_pMemory(pMemory), _offsetBase(0), _elemNum(0) {}
protected:
	virtual ~Array();
public:
	inline void SetDimension(const Dimension &dim) {
		_dims.reserve(1);
		_dims.push_back(dim);
		UpdateMetrics();
	}
	inline void SetDimension(const Dimension &dimRow, const Dimension &dimCol) {
		_dims.reserve(2);
		_dims.push_back(dimRow);
		_dims.push_back(dimCol);
		UpdateMetrics();
	}
	inline void SetDimension(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd) {
		_dims.reserve(std::distance(pDim, pDimEnd));
		std::copy(pDim, pDimEnd, std::back_inserter(_dims));
		UpdateMetrics();
	}
	inline void SetDimension(const Dimensions &dims) {
		_dims = dims;
		UpdateMetrics();
	}
	inline Memory &GetMemory() { return *_pMemory; }
	inline const Memory &GetMemory() const { return *_pMemory; }
	inline Dimensions &GetDimensions() { return _dims; }
	inline const Dimensions &GetDimensions() const { return _dims; }
	inline size_t GetElemNum() const { return _elemNum; }
	inline void SetOffsetBase(size_t offsetBase) { _offsetBase = offsetBase; }
	inline size_t GetOffsetBase() const { return _offsetBase; }
	void UpdateMetrics();
	bool HasShape(size_t size) const;
	bool HasShape(size_t sizeRow, size_t sizeCol) const;
public:
	static bool CheckShape(Signal &sig, const Array &arrayA, const Array &arrayB);
	static bool CheckElemwiseCalculatable(Signal &sig, const Array &arrayA, const Array &arrayB);
	static bool CheckDotProductCalculatable(Signal &sig, const Array &arrayA, const Array &arrayB);
};
	
}

#endif
