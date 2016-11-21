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
	enum ElemType {
		ETYPE_None,
		ETYPE_Char,
		ETYPE_UChar,
		ETYPE_Short,
		ETYPE_UShort,
		ETYPE_Int,
		ETYPE_UInt,
		ETYPE_Int32,
		ETYPE_UInt32,
		ETYPE_Int64,
		ETYPE_UInt64,
		ETYPE_Float,
		ETYPE_Double,
		ETYPE_Complex,
		ETYPE_Max,
	};
public:
	typedef Array *(*UnaryFunc)(Signal &sig, const Array &array);
	typedef Array *(*BinaryFunc)(Signal &sig, const Array &arrayL, const Array &arrayR);
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
	ElemType _elemType;
	AutoPtr<Memory> _pMemory;
	Dimensions _dims;
	size_t _offsetBase;
	size_t _elemNum;
protected:
	static BinaryFunc _binaryFuncTbl_Add[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Sub[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Mul[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Div[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Mod[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Pow[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_And[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Or[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Xor[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Shl[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Shr[ETYPE_Max][ETYPE_Max];
	static BinaryFunc _binaryFuncTbl_Dot[ETYPE_Max][ETYPE_Max];
public:
	Gura_DeclareReferenceAccessor(Array);
public:
	inline Array(ElemType elemType) : _cntRef(1),
		_elemType(elemType), _offsetBase(0), _elemNum(0) {}
	inline Array(ElemType elemType, const Array &src) : _cntRef(1),
		_elemType(elemType), _pMemory(src._pMemory->Reference()), _dims(src._dims),
		_offsetBase(src._offsetBase), _elemNum(src._elemNum) {}
	inline Array(ElemType elemType, Memory *pMemory) : _cntRef(1),
		_elemType(elemType), _pMemory(pMemory), _offsetBase(0), _elemNum(0) {}
protected:
	virtual ~Array();
public:
	void Initialize();
public:
	inline ElemType GetElemType() const { return _elemType; }
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
	static Array *ApplyUnaryFunc(Signal &sig, const UnaryFunc unaryFuncTbl[],
								 const Array *pArray, const char *name);
	static Array *ApplyBinaryFunc(Signal &sig, const BinaryFunc binaryFuncTbl[][ETYPE_Max],
								  const Array *pArrayL, const Array *pArrayR, const char *name);
	static Value ApplyBinaryFunc(Environment &env, const BinaryFunc binaryFuncTbl[][ETYPE_Max],
								  const Value &valueL, const Value &valueR, const char *name);
public:
	inline static Value Add(Environment &env, const Value &valueL, const Value &valueR) {
		return ApplyBinaryFunc(env, _binaryFuncTbl_Add, valueL, valueR, "add");
	}
	inline static Array *Add(Signal &sig, const Array *pArrayL, const Array *pArrayR) {
		return ApplyBinaryFunc(sig, _binaryFuncTbl_Add, pArrayL, pArrayR, "add");
	}
	inline static Array *Dot(Signal &sig, const Array *pArrayL, const Array *pArrayR) {
		return ApplyBinaryFunc(sig, _binaryFuncTbl_Dot, pArrayL, pArrayR, "dot");
	}
};
	
}

#endif
