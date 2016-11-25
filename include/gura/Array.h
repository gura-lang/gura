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
		ETYPE_Int8,
		ETYPE_UInt8,
		ETYPE_Int16,
		ETYPE_UInt16,
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
	typedef Array *(*BinaryFunc_array_array)(Signal &sig, const Array &arrayL, const Array &arrayR);
	typedef Array *(*BinaryFunc_array_number)(Signal &sig, const Array &arrayL, Number numberR);
	typedef Array *(*BinaryFunc_number_array)(Signal &sig, Number numberL, const Array &arrayR);
	struct UnaryFuncPack {
		const char *name;
		UnaryFunc unaryFuncs[ETYPE_Max];
	};
	struct BinaryFuncPack {
		const char *name;
		BinaryFunc_array_array binaryFuncs_array_array[ETYPE_Max][ETYPE_Max];
		BinaryFunc_array_number binaryFuncs_array_number[ETYPE_Max];
		BinaryFunc_number_array binaryFuncs_number_array[ETYPE_Max];
	};
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
public:
	static UnaryFuncPack unaryFuncPack_Pos;
	static UnaryFuncPack unaryFuncPack_Neg;
	static BinaryFuncPack binaryFuncPack_Add;
	static BinaryFuncPack binaryFuncPack_Sub;
	static BinaryFuncPack binaryFuncPack_Mul;
	static BinaryFuncPack binaryFuncPack_Div;
	static BinaryFuncPack binaryFuncPack_Mod;
	static BinaryFuncPack binaryFuncPack_Pow;
	static BinaryFuncPack binaryFuncPack_And;
	static BinaryFuncPack binaryFuncPack_Or;
	static BinaryFuncPack binaryFuncPack_Xor;
	static BinaryFuncPack binaryFuncPack_Shl;
	static BinaryFuncPack binaryFuncPack_Shr;
	static BinaryFuncPack binaryFuncPack_Dot;
	static UnaryFunc unaryFuncTbl_Pos[ETYPE_Max];
	static UnaryFunc unaryFuncTbl_Neg[ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Add[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Sub[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Mul[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Div[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Mod[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Pow[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_And[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Or[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Xor[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Shl[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Shr[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_array binaryFuncs_array_array_Dot[ETYPE_Max][ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Add[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Sub[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Mul[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Div[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Mod[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Pow[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_And[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Or[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Xor[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Shl[ETYPE_Max];
	static BinaryFunc_array_number binaryFuncs_array_number_Shr[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Add[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Sub[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Mul[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Div[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Mod[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Pow[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_And[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Or[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Xor[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Shl[ETYPE_Max];
	static BinaryFunc_number_array binaryFuncs_number_array_Shr[ETYPE_Max];
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
	inline void SetDimensions(const Dimension &dimRow, const Dimension &dimCol) {
		_dims.reserve(2);
		_dims.push_back(dimRow);
		_dims.push_back(dimCol);
		UpdateMetrics();
	}
	inline void SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd) {
		_dims.reserve(std::distance(pDim, pDimEnd));
		std::copy(pDim, pDimEnd, std::back_inserter(_dims));
		UpdateMetrics();
	}
	inline void SetDimensions(const Dimensions &dims) {
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
	virtual String ToString() const;
	void UpdateMetrics();
	bool HasShape(size_t size) const;
	bool HasShape(size_t sizeRow, size_t sizeCol) const;
public:
	static bool CheckShape(Signal &sig, const Array &arrayA, const Array &arrayB);
	static bool CheckElemwiseCalculatable(Signal &sig, const Array &arrayA, const Array &arrayB);
	static bool CheckDotProductCalculatable(Signal &sig, const Array &arrayA, const Array &arrayB);
	static Array *ApplyUnaryFunc(Signal &sig, const UnaryFuncPack &pack, const Array *pArray);
	static Array *ApplyBinaryFunc_array_array(
		Signal &sig, const BinaryFuncPack &pack, const Array *pArrayL, const Array *pArrayR);
	static Value ApplyBinaryFunc_array_array(
		Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR);
	static Array *ApplyBinaryFunc_array_number(
		Signal &sig, const BinaryFuncPack &pack, const Array *pArrayL, Number numberR);
	static Value ApplyBinaryFunc_array_number(
		Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR);
	static Array *ApplyBinaryFunc_number_array(
		Signal &sig, const BinaryFuncPack &pack, Number numberL, const Array *pArrayR);
	static Value ApplyBinaryFunc_number_array(
		Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR);
public:
	inline static Array *Dot(Signal &sig, const Array *pArrayL, const Array *pArrayR) {
		return ApplyBinaryFunc_array_array(sig, binaryFuncPack_Dot, pArrayL, pArrayR);
	}
};
	
}

#endif
