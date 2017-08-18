//=============================================================================
// Array
//=============================================================================
#ifndef __GURA_ARRAY_H__
#define __GURA_ARRAY_H__

#include "Memory.h"
#include "Iterator.h"
#include "Stream.h"

namespace Gura {

class Filter_MaxPool;
	
//-----------------------------------------------------------------------------
// Array
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Array {
public:
	enum ElemType {
		ETYPE_None,
		ETYPE_Boolean,
		ETYPE_Int8,
		ETYPE_UInt8,
		ETYPE_Int16,
		ETYPE_UInt16,
		ETYPE_Int32,
		ETYPE_UInt32,
		ETYPE_Int64,
		ETYPE_UInt64,
		ETYPE_Half,
		ETYPE_Float,
		ETYPE_Double,
		ETYPE_Complex,
		ETYPE_reserved1,
		ETYPE_Max,
	};
public:
	typedef Array *(*UnaryFuncT)(Signal &sig, Array *pArrayResult, const Array *pArray);
	typedef Array *(*BinaryFuncT_array_array)(Signal &sig, Array *pArrayResult,
											 const Array *pArrayL, const Array *pArrayR);
	typedef Array *(*BinaryFuncT_array_number)(Signal &sig, Array *pArrayResult,
											  const Array *pArrayL, Double numberR);
	typedef Array *(*BinaryFuncT_number_array)(Signal &sig, Array *pArrayResult,
											  Double numberL, const Array *pArrayR);
	typedef Array *(*BinaryFuncT_array_complex)(Signal &sig, Array *pArrayResult,
											   const Array *pArrayL, const Complex &complexR);
	typedef Array *(*BinaryFuncT_complex_array)(Signal &sig, Array *pArrayResult,
											   const Complex &complexL, const Array *pArrayR);
	typedef Array *(*BinaryFuncT_number_number)(Signal &sig, Array *pArrayResult,
											   Double numberL, Double numberR);
	typedef Array *(*BinaryFuncT_complex_complex)(Signal &sig, Array *pArrayResult,
												 const Complex &complexL, const Complex &complexR);
	typedef Array *(*InvertFuncT)(Signal &sig, Array *pArrayResult, const Array *pArray, Double epsilon);
	typedef Array *(*MaxPoolFilterFuncT)(Signal &sig, Array *pArrayResult,
										 const Array *pArray, const Filter_MaxPool &filter);
	struct UnaryFuncTable {
		UnaryFuncT unaryFuncs[ETYPE_Max];
	};
	struct UnaryFuncPack {
		const char *name;
		const char *symbol;
		UnaryFuncTable table;
	};
	struct BinaryFuncTable {
		BinaryFuncT_array_array binaryFuncs_array_array[ETYPE_Max][ETYPE_Max];
		BinaryFuncT_array_number binaryFuncs_array_number[ETYPE_Max];
		BinaryFuncT_number_array binaryFuncs_number_array[ETYPE_Max];
		BinaryFuncT_array_complex binaryFuncs_array_complex[ETYPE_Max];
		BinaryFuncT_complex_array binaryFuncs_complex_array[ETYPE_Max];
		BinaryFuncT_number_number binaryFunc_number_number;
		BinaryFuncT_complex_complex binaryFunc_complex_complex;
	};
	struct BinaryFuncPack {
		const char *name;
		const char *symbol;
		bool elemwiseFlag;
		BinaryFuncTable table;
	};
	typedef std::map<const Symbol *, ElemType, Symbol::LessThan> MapToElemType;
public:
	static UnaryFuncPack unaryFuncPack_Pos;
	static UnaryFuncPack unaryFuncPack_Neg;
	static BinaryFuncPack binaryFuncPack_Add;
	static BinaryFuncPack binaryFuncPack_Sub;
	static BinaryFuncPack binaryFuncPack_Mul;
	static BinaryFuncPack binaryFuncPack_Div;
	static BinaryFuncPack binaryFuncPack_Mod;
	static BinaryFuncPack binaryFuncPack_Pow;
	static BinaryFuncPack binaryFuncPack_Dot;
	static BinaryFuncPack binaryFuncPack_Eq;
	static BinaryFuncPack binaryFuncPack_Ne;
	static BinaryFuncPack binaryFuncPack_Gt;
	static BinaryFuncPack binaryFuncPack_Lt;
	static BinaryFuncPack binaryFuncPack_Ge;
	static BinaryFuncPack binaryFuncPack_Le;
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
	static UnaryFuncPack unaryFuncPack_Math_ceil;
	static UnaryFuncPack unaryFuncPack_Math_conj;
	static UnaryFuncPack unaryFuncPack_Math_cos;
	static UnaryFuncPack unaryFuncPack_Math_cosh;
	static UnaryFuncPack unaryFuncPack_Math_delta;
	static UnaryFuncPack unaryFuncPack_Math_exp;
	static UnaryFuncPack unaryFuncPack_Math_floor;
	static UnaryFuncPack unaryFuncPack_Math_imag;
	static UnaryFuncPack unaryFuncPack_Math_log;
	static UnaryFuncPack unaryFuncPack_Math_log10;
	static UnaryFuncPack unaryFuncPack_Math_norm;
	static UnaryFuncPack unaryFuncPack_Math_real;
	static UnaryFuncPack unaryFuncPack_Math_relu;
	static UnaryFuncPack unaryFuncPack_Math_sigmoid;
	static UnaryFuncPack unaryFuncPack_Math_sin;
	static UnaryFuncPack unaryFuncPack_Math_sinh;
	static UnaryFuncPack unaryFuncPack_Math_sqrt;
	static UnaryFuncPack unaryFuncPack_Math_tan;
	static UnaryFuncPack unaryFuncPack_Math_tanh;
	static UnaryFuncPack unaryFuncPack_Math_unitstep;
	static InvertFuncT invertFuncs[ETYPE_Max];
public:
	class GURA_DLLDECLARE Dimension {
	private:
		size_t _size;
		size_t _elemNumProd;	// calculated by Array::UpdateMetrics()
		size_t _stride;			// calculated by Array::UpdateMetrics() 
	public:
		inline Dimension() : _size(0), _elemNumProd(0), _stride(0) {}
		inline Dimension(size_t size) : _size(size), _elemNumProd(0), _stride(0) {}
		inline size_t GetSize() const { return _size; }
		inline size_t GetElemNumProd() const { return _elemNumProd; }
		inline size_t GetStride() const { return _stride; }
		inline void SetElemNumProd(size_t elemNumProd) { _elemNumProd = elemNumProd; }
		inline void SetStride(size_t stride) { _stride = stride; }
	};
	class GURA_DLLDECLARE Dimensions : public std::vector<Dimension> {
	public:
		String ToString(const char *sep = ", ") const;
		bool Serialize(Environment &env, Stream &stream) const;
		bool Deserialize(Environment &env, Stream &stream);
		static bool IsSameShape(const Dimensions &dimsA, const Dimensions &dimsB);
		static bool IsElemwiseCalculatable(const Dimensions &dimsA, const Dimensions &dimsB);
	};
	class GURA_DLLDECLARE Indexer {
	public:
		class GURA_DLLDECLARE Generator {
		private:
			const Dimension &_dim;
			SizeTList _indices;
			SizeTList::const_iterator _pIndex;
		public:
			inline Generator(const Dimension &dim) : _dim(dim) {}
			inline void AddIndex(size_t idx) { _indices.push_back(idx); }
			inline bool IsEmpty() const { return _indices.empty(); }
			inline size_t CalcOffset() const { return _dim.GetStride() * GetIndex(); }
			inline void Reset() { _pIndex = _indices.begin(); }
			inline size_t GetIndex() const { return *_pIndex; }
			inline size_t GetSize() const { return _indices.size(); }
			bool Next();
		};
		class GURA_DLLDECLARE GeneratorList : public std::vector<Generator *> {
		public:
			void Reset();
			size_t CalcOffset() const;
			bool Next();
			void Print() const;
		};
		class GURA_DLLDECLARE GeneratorOwner : public GeneratorList {
		public:
			~GeneratorOwner();
			void Clear();
		};
	private:
		const Dimensions &_dims;
		Dimensions::const_iterator _pDim;
		size_t _offsetTarget;
		std::unique_ptr<GeneratorOwner> _pGeneratorOwner;
	public:
		Indexer(const Dimensions &dims);
		bool InitIndices(Environment &env, const ValueList &valListIdx);
		void MakeResultDimensions(Dimensions &dimsRtn);
		inline size_t GetOffsetTarget() const { return _offsetTarget; }
		inline bool HasGenerator() const { return _pGeneratorOwner.get() != nullptr; }
		inline size_t GenerateOffset() const { return _pGeneratorOwner->CalcOffset(); }
		inline bool NextGenerator() { return _pGeneratorOwner->Next(); }
		inline size_t GetElemNumUnit() const {
			return (_pDim == _dims.end())? 1 : _pDim->GetElemNumProd();
		}
		inline bool IsTargetScalar() const { return _pDim == _dims.end(); }
	};
protected:
	int _cntRef;
	ElemType _elemType;
	AutoPtr<Memory> _pMemory;
	Dimensions _dims;
	size_t _offsetBase;
	size_t _elemNum;
	static MapToElemType _mapToElemType;
public:
	Gura_DeclareReferenceAccessor(Array);
protected:
	inline Array(ElemType elemType) : _cntRef(1),
		_elemType(elemType), _offsetBase(0), _elemNum(0) {}
	inline Array(ElemType elemType, const Array &src) : _cntRef(1),
		_elemType(elemType), _pMemory(src._pMemory->Reference()), _dims(src._dims),
		_offsetBase(src._offsetBase), _elemNum(src._elemNum) {}
	inline Array(ElemType elemType, Memory *pMemory, size_t offsetBase) : _cntRef(1),
		_elemType(elemType), _pMemory(pMemory), _offsetBase(offsetBase), _elemNum(0) {}
protected:
	virtual ~Array();
public:
	static void Bootup();
public:
	inline ElemType GetElemType() const { return _elemType; }
	inline bool IsElemType(ElemType elemType) const { return _elemType == elemType; }
	inline void SetMemory(Memory *pMemory, size_t offsetBase) {
		_pMemory.reset(pMemory), _offsetBase = offsetBase;
	}
	inline Memory &GetMemory() { return *_pMemory; }
	inline const Memory &GetMemory() const { return *_pMemory; }
	inline Dimensions &GetDimensions() { return _dims; }
	inline const Dimensions &GetDimensions() const { return _dims; }
	inline bool IsScalar() const { return _dims.empty(); }
	inline size_t GetElemNum() const { return _elemNum; }
	inline void SetOffsetBase(size_t offsetBase) { _offsetBase = offsetBase; }
	inline size_t GetOffsetBase() const { return _offsetBase; }
	inline char *GetPointerRawOrigin() { return _pMemory->GetPointer(); }
	inline const char *GetPointerRawOrigin() const { return _pMemory->GetPointer(); }
	inline char *GetPointerRaw() { return GetPointerRawOrigin() + GetOffsetBase() * GetElemBytes(); }
	inline const char *GetPointerRaw() const { return GetPointerRawOrigin() + GetOffsetBase() * GetElemBytes(); }
	virtual Array *Clone() const = 0;
	virtual String ToString(bool exprFlag) const = 0;
	virtual bool DoesContainZero() const = 0;
	virtual bool DoesContainMinus() const = 0;
	virtual bool DoesContainZeroOrMinus() const = 0;
	virtual Double GetScalarNumber() const = 0;
	virtual Complex GetScalarComplex() const = 0;
	static size_t GetElemBytes(ElemType elemType);
	inline size_t GetElemBytes() const { return GetElemBytes(_elemType); }
	static const char *GetElemTypeName(ElemType elemType);
	inline const char *GetElemTypeName() const { return GetElemTypeName(_elemType); }
	void SetDimension(const Dimension &dim);
	void SetDimensions(const Dimension &dimRow, const Dimension &dimCol);
	void SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd);
	void SetDimensions(const Dimension &dim,
					   Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd);
	void SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
					   const Dimension &dim);
	void SetDimensions(Dimensions::const_iterator pDim1, Dimensions::const_iterator pDim1End,
					   Dimensions::const_iterator pDim2, Dimensions::const_iterator pDim2End);
	void SetDimensions(const Dimensions &dims);
	void SetDimensions(const ValueList &valList);
	void SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
					   const Dimension &dimRow, const Dimension &dimCol);
	void UpdateMetrics();
	void FillZero();
	void Fill(Double num); // overwritten by ArrayT
	bool IsSquare() const;
	bool HasShape(size_t size) const;
	bool HasShape(size_t sizeRow, size_t sizeCol) const;
	bool HasShape(const Value &valList) const;
	bool HasSameElements(const Array &array) const;
	bool PrepareModification(Signal &sig);
	static Value ToValue(Environment &env, Array *pArray);
	bool Serialize(Environment &env, Stream &stream) const;
	static Array *Deserialize(Environment &env, Stream &stream);
public:
	static Array *Create(ElemType elemType, const Dimensions &dims);
public:
	static ElemType SymbolToElemType(const Symbol *pSymbol);
	static ElemType SymbolToElemTypeWithError(Environment &env, const Symbol *pSymbol);
	static bool CheckShape(Signal &sig, const Array *pArrayA, const Array *pArrayB);
	static bool CheckElemwiseCalculatable(Signal &sig, const BinaryFuncPack &pack,
										  const Array *pArrayL, const Array *pArrayR);
	static bool CopyElements(Environment &env, Array *pArrayDst, const Array *pArraySrc);
	static bool CopyElements(Environment &env, void *pElemRawDst, ElemType elemTypeDst,
							 const void *pElemRawSrc, ElemType elemTypeSrc, size_t nElems);
	static Array *ApplyUnaryFunc(
		Signal &sig, const UnaryFuncPack &pack, Array *pArrayResult, const Array *pArray);
	static Value ApplyUnaryFuncOnValue(
		Environment &env, const UnaryFuncPack &pack, const Value &value);
	static Array *ApplyBinaryFunc(
		Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Array *pArrayL, const Array *pArrayR);
	static Array *ApplyBinaryFunc_array_array(
		Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Array *pArrayL, const Array *pArrayR);
	static Value ApplyBinaryFuncOnValue_array_array(
		Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR);
	static Array *ApplyBinaryFunc_array_number(
		Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Array *pArrayL, Double numberR);
	static Value ApplyBinaryFuncOnValue_array_number(
		Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR);
	static Array *ApplyBinaryFunc_number_array(
		Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, Double numberL, const Array *pArrayR);
	static Value ApplyBinaryFuncOnValue_number_array(
		Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR);
	static Array *ApplyBinaryFunc_array_complex(
		Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Array *pArrayL, const Complex &complexR);
	static Value ApplyBinaryFuncOnValue_array_complex(
		Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR);
	static Array *ApplyBinaryFunc_complex_array(
		Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Complex &complexL, const Array *pArrayR);
	static Value ApplyBinaryFuncOnValue_complex_array(
		Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR);
	static Array *ApplyInvertFunc(
		Signal &sig, Array *pArrayResult, const Array *pArray, Double epsilon);
	static void SetError_UnacceptableValueAsElement(Environment &env, const Value &value);
};
	
//-----------------------------------------------------------------------------
// ArrayList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ArrayList : public std::vector<Array *> {
public:
	static const ArrayList Empty;
public:
	inline ArrayList() {}
};

//-----------------------------------------------------------------------------
// ArrayOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ArrayOwner : public ArrayList {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(ArrayOwner);
public:
	ArrayOwner();
private:
	~ArrayOwner();
public:
	void Clear();
};



}

#endif
