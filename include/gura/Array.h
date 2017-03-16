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
	typedef Array *(*UnaryFunc)(Signal &sig, const Array *pArray);
	typedef Array *(*BinaryFunc_array_array)(Signal &sig, const Array *pArrayL, const Array *pArrayR);
	typedef Array *(*BinaryFunc_array_number)(Signal &sig, const Array *pArrayL, Number numberR);
	typedef Array *(*BinaryFunc_number_array)(Signal &sig, Number numberL, const Array *pArrayR);
	typedef Value (*DotFunc)(Environment &env, const Array *pArrayL, const Array *pArrayR);
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
	static UnaryFuncPack unaryFuncPack_Math_abs;
	static UnaryFuncPack unaryFuncPack_Math_acos;
	static UnaryFuncPack unaryFuncPack_Math_arg;
	static UnaryFuncPack unaryFuncPack_Math_asin;
	static UnaryFuncPack unaryFuncPack_Math_atan;
	static BinaryFuncPack binaryFuncPack_Math_atan2;
	static UnaryFuncPack unaryFuncPack_Math_ceil;
	static UnaryFuncPack unaryFuncPack_Math_conj;
	static UnaryFuncPack unaryFuncPack_Math_cos;
	static UnaryFuncPack unaryFuncPack_Math_cosh;
	//static UnaryFuncPack unaryFuncPack_Math_cross;
	static UnaryFuncPack unaryFuncPack_Math_delta;
	//static UnaryFuncPack unaryFuncPack_Math_dot;
	static UnaryFuncPack unaryFuncPack_Math_exp;
	static UnaryFuncPack unaryFuncPack_Math_floor;
	static BinaryFuncPack binaryFuncPack_Math_hypot;
	static UnaryFuncPack unaryFuncPack_Math_imag;
	static UnaryFuncPack unaryFuncPack_Math_log;
	static UnaryFuncPack unaryFuncPack_Math_log10;
	static UnaryFuncPack unaryFuncPack_Math_norm;
	static UnaryFuncPack unaryFuncPack_Math_ramp;
	static UnaryFuncPack unaryFuncPack_Math_real;
	static UnaryFuncPack unaryFuncPack_Math_sin;
	static UnaryFuncPack unaryFuncPack_Math_sinh;
	static UnaryFuncPack unaryFuncPack_Math_sqrt;
	static UnaryFuncPack unaryFuncPack_Math_tan;
	static UnaryFuncPack unaryFuncPack_Math_tanh;
	static UnaryFuncPack unaryFuncPack_Math_unitstep;
	static DotFunc dotFuncs[ETYPE_Max][ETYPE_Max];
	static UnaryFunc invertFuncs[ETYPE_Max];
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
	inline Memory &GetMemory() { return *_pMemory; }
	inline const Memory &GetMemory() const { return *_pMemory; }
	inline Dimensions &GetDimensions() { return _dims; }
	inline const Dimensions &GetDimensions() const { return _dims; }
	inline size_t GetElemNum() const { return _elemNum; }
	inline void SetOffsetBase(size_t offsetBase) { _offsetBase = offsetBase; }
	inline size_t GetOffsetBase() const { return _offsetBase; }
	virtual String ToString(bool exprFlag) const;
	virtual bool DoesContainZero() const;
	const char *GetElemTypeName() const;
	void SetDimension(const Dimension &dim);
	void SetDimensions(const Dimension &dimRow, const Dimension &dimCol);
	void SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd);
	void SetDimensions(const Dimension &dim,
					   Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd);
	void SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
					   const Dimension &dim);
	void SetDimensions(const Dimensions &dims);
	void SetDimensions(const ValueList &valList);
	void SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
					   const Dimension &dimRow, const Dimension &dimCol);
	void UpdateMetrics();
	bool HasShape(size_t size) const;
	bool HasShape(size_t sizeRow, size_t sizeCol) const;
	bool HasShape(const Value &valList) const;
	bool PrepareModification(Signal &sig);
public:
	static bool CheckShape(Signal &sig, const Array *pArrayA, const Array *pArrayB);
	static bool CheckElemwiseCalculatable(Signal &sig, const Array *pArrayL, const Array *pArrayR);
	static Array *ApplyUnaryFunc(Signal &sig, const UnaryFuncPack &pack, const Array *pArray);
	static Value ApplyUnaryFunc(Environment &env, const UnaryFuncPack &pack, const Value &value);
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
	static Value Dot(Environment &env, const Array *pArrayL, const Array *pArrayR);
	static Array *Invert(Signal &sig, const Array *pArray);
};
	
}

#endif
