//=============================================================================
// Array
//=============================================================================
#include "stdafx.h"
#include "gura/Array.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Array
//-----------------------------------------------------------------------------
Array::MapToElemType Array::_mapToElemType;

Array::~Array()
{
}

void Array::Bootup()
{
	static const struct {
		const char *name;
		ElemType elemType;
	} tbl[] = {
		{ "boolean",	ETYPE_Boolean	},
		{ "int8",		ETYPE_Int8		},
		{ "uint8",		ETYPE_UInt8		},
		{ "int16",		ETYPE_Int16		},
		{ "uint16",		ETYPE_UInt16	},
		{ "int32",		ETYPE_Int32		},
		{ "uint32",		ETYPE_UInt32	},
		{ "int64",		ETYPE_Int64		},
		{ "uint64",		ETYPE_UInt64	},
		{ "half",		ETYPE_Half		},
		{ "float",		ETYPE_Float		},
		{ "double",		ETYPE_Double	},
		{ "complex",	ETYPE_Complex	},
		{ "value",		ETYPE_reserved1	},
	};
	for (size_t i = 0; i < ArraySizeOf(tbl); i++) {
		_mapToElemType[Symbol::Add(tbl[i].name)] = tbl[i].elemType;
	}
}

size_t Array::GetElemBytes(ElemType elemType)
{
	const static size_t elemBytesTbl[ETYPE_Max] = {
		0,
		ArrayT<Boolean>::ElemBytes,
		ArrayT<Int8>::ElemBytes,
		ArrayT<UInt8>::ElemBytes,
		ArrayT<Int16>::ElemBytes,
		ArrayT<UInt16>::ElemBytes,
		ArrayT<Int32>::ElemBytes,
		ArrayT<UInt32>::ElemBytes,
		ArrayT<Int64>::ElemBytes,
		ArrayT<UInt64>::ElemBytes,
		ArrayT<Half>::ElemBytes,
		ArrayT<Float>::ElemBytes,
		ArrayT<Double>::ElemBytes,
		ArrayT<Complex>::ElemBytes,
		//ArrayT<Value>::ElemBytes,
	};
	return elemBytesTbl[elemType];
}

const char *Array::GetElemTypeName(ElemType elemType)
{
	const static char *elemTypeNameTbl[ETYPE_Max] = {
		"",
		ArrayT<Boolean>::ElemTypeName,
		ArrayT<Int8>::ElemTypeName,
		ArrayT<UInt8>::ElemTypeName,
		ArrayT<Int16>::ElemTypeName,
		ArrayT<UInt16>::ElemTypeName,
		ArrayT<Int32>::ElemTypeName,
		ArrayT<UInt32>::ElemTypeName,
		ArrayT<Int64>::ElemTypeName,
		ArrayT<UInt64>::ElemTypeName,
		ArrayT<Half>::ElemTypeName,
		ArrayT<Float>::ElemTypeName,
		ArrayT<Double>::ElemTypeName,
		ArrayT<Complex>::ElemTypeName,
		//ArrayT<Value>::ElemTypeName,
	};
	return elemTypeNameTbl[elemType];
}

void Array::SetDimension(const Dimension &dim)
{
	_dims.reserve(1);
	_dims.push_back(dim);
	UpdateMetrics();
}

void Array::SetDimensions(const Dimension &dimRow, const Dimension &dimCol)
{
	_dims.reserve(2);
	_dims.push_back(dimRow);
	_dims.push_back(dimCol);
	UpdateMetrics();
}

void Array::SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd)
{
	_dims.reserve(std::distance(pDim, pDimEnd));
	std::copy(pDim, pDimEnd, std::back_inserter(_dims));
	UpdateMetrics();
}

void Array::SetDimensions(const Dimension &dim,
						  Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd)
{
	_dims.reserve(std::distance(pDim, pDimEnd) + 1);
	_dims.push_back(dim);
	_dims.insert(_dims.end(), pDim, pDimEnd);
	UpdateMetrics();
}

void Array::SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
						  const Dimension &dim)
{
	_dims.reserve(std::distance(pDim, pDimEnd) + 1);
	_dims.insert(_dims.end(), pDim, pDimEnd);
	_dims.push_back(dim);
	UpdateMetrics();
}

void Array::SetDimensions(Dimensions::const_iterator pDim1, Dimensions::const_iterator pDim1End,
						  Dimensions::const_iterator pDim2, Dimensions::const_iterator pDim2End)
{
	_dims.reserve(std::distance(pDim1, pDim1End) + std::distance(pDim2, pDim2End));
	_dims.insert(_dims.end(), pDim1, pDim1End);
	_dims.insert(_dims.end(), pDim2, pDim2End);
	UpdateMetrics();
}

void Array::SetDimensions(const Dimensions &dims)
{
	_dims = dims;
	UpdateMetrics();
}

void Array::SetDimensions(const ValueList &valList)
{
	_dims.reserve(valList.size());
	foreach_const (ValueList, pValue, valList) {
		_dims.push_back(pValue->GetSizeT());
	}
	UpdateMetrics();
}

void Array::SetDimensions(Dimensions::const_iterator pDim, Dimensions::const_iterator pDimEnd,
						  const Dimension &dimRow, const Dimension &dimCol)
{
	_dims.reserve(std::distance(pDim, pDimEnd) + 2);
	_dims.insert(_dims.end(), pDim, pDimEnd);
	_dims.push_back(dimRow);
	_dims.push_back(dimCol);
	UpdateMetrics();
}

void Array::UpdateMetrics()
{
	size_t stride = 1;
	foreach_reverse (Dimensions, pDim, _dims) {
		pDim->SetStride(stride);
		stride *= pDim->GetSize();
		pDim->SetElemNumProd(stride);
	}
	_elemNum = stride;	// set to one when _dims is empty
}

void Array::FillZero()
{
	::memset(GetPointerRaw(), 0x00, GetElemBytes() * GetElemNum());
}

template<typename T_Elem>
void FillTmpl(Array *pArray, Double num) {
	dynamic_cast<ArrayT<T_Elem> *>(pArray)->Fill(static_cast<T_Elem>(num));
}

typedef void (*FillFuncT)(Array *pArray, Double num);

void Array::Fill(Double num)
{
	const FillFuncT fillFuncs[ETYPE_Max] = {
		nullptr,
		&FillTmpl<Boolean>,
		&FillTmpl<Int8>,
		&FillTmpl<UInt8>,
		&FillTmpl<Int16>,
		&FillTmpl<UInt16>,
		&FillTmpl<Int32>,
		&FillTmpl<UInt32>,
		&FillTmpl<Int64>,
		&FillTmpl<UInt64>,
		&FillTmpl<Half>,
		&FillTmpl<Float>,
		&FillTmpl<Double>,
		&FillTmpl<Complex>,
		//&FillTmpl<Value>,
	};
	(*fillFuncs[GetElemType()])(this, num);
}

bool Array::IsSquare() const
{
	if (_dims.size() < 2) return false;
	Dimensions::const_reverse_iterator pDim = _dims.rbegin();
	return pDim->GetSize() == (pDim + 1)->GetSize();
}

bool Array::HasShape(size_t size) const
{
	return (_dims.size() == 1) && _dims[0].GetSize() == size;
}

bool Array::HasShape(size_t sizeRow, size_t sizeCol) const
{
	return (_dims.size() == 2) && _dims[0].GetSize() == sizeRow && _dims[1].GetSize() == sizeCol;
}

bool Array::HasSameElements(const Array &array) const
{
	if (GetElemType() != array.GetElemType()) return false;
	if (!Dimensions::IsSameShape(GetDimensions(), array.GetDimensions())) return false;
	size_t bytes = GetElemBytes() * GetElemNum();
	if (memcmp(GetPointerRaw(), array.GetPointerRaw(), bytes) != 0) return false;
	return true;
}

bool Array::PrepareModification(Signal &sig)
{
	if (_pMemory->GetCntRef() > 1) {
		_pMemory.reset(_pMemory->Clone());
		if (_pMemory.IsNull()) {
			sig.SetError(ERR_MemoryError, "failed to allocate memory for array");
			return false;
		}
	}
	return true;
}

Value Array::ToValue(Environment &env, Array *pArray)
{
	return !pArray->IsScalar()? Value(new Object_array(env, pArray)) :
		pArray->IsElemType(ETYPE_Complex)? Value(pArray->GetScalarComplex()) :
		Value(pArray->GetScalarNumber());
}

bool Array::Serialize(Environment &env, Stream &stream) const
{
	if (!stream.SerializeUInt8(env, static_cast<UInt8>(_elemType))) return false;
	if (!_dims.Serialize(env, stream)) return false;
	size_t bytes = GetElemBytes() * GetElemNum();
	if (stream.Write(env, GetPointerRaw(), bytes) < bytes) return false;
	return true;
}

Array *Array::Deserialize(Environment &env, Stream &stream)
{
	UInt8 elemType = 0;
	if (!stream.DeserializeUInt8(env, elemType)) return nullptr;
	Array::Dimensions dims;
	if (!dims.Deserialize(env, stream)) return nullptr;
	AutoPtr<Array> pArray(Create(static_cast<ElemType>(elemType), dims));
	size_t bytes = pArray->GetElemBytes() * pArray->GetElemNum();
	if (stream.Read(env, pArray->GetPointerRaw(), bytes) < bytes) return nullptr;
	return pArray.release();
}

template<typename T_Elem>
Array *CreateTmpl(const Array::Dimensions &dims) { return ArrayT<T_Elem>::Create(dims); }

typedef Array *(*CreateFuncT)(const Array::Dimensions &dims);

Array *Array::Create(ElemType elemType, const Array::Dimensions &dims)
{
	const CreateFuncT createFuncs[ETYPE_Max] = {
		nullptr,
		&CreateTmpl<Boolean>,
		&CreateTmpl<Int8>,
		&CreateTmpl<UInt8>,
		&CreateTmpl<Int16>,
		&CreateTmpl<UInt16>,
		&CreateTmpl<Int32>,
		&CreateTmpl<UInt32>,
		&CreateTmpl<Int64>,
		&CreateTmpl<UInt64>,
		&CreateTmpl<Half>,
		&CreateTmpl<Float>,
		&CreateTmpl<Double>,
		&CreateTmpl<Complex>,
		//&CreateTmpl<Value>,
	};
	return (*createFuncs[elemType])(dims);
}

Array::ElemType Array::SymbolToElemType(const Symbol *pSymbol)
{
	MapToElemType::const_iterator iter = _mapToElemType.find(pSymbol);
	return (iter == _mapToElemType.end())? ETYPE_None : iter->second;
}

Array::ElemType Array::SymbolToElemTypeWithError(Environment &env, const Symbol *pSymbol)
{
	ElemType elemType = SymbolToElemType(pSymbol);
	if (elemType == ETYPE_None) {
		env.SetError(ERR_ValueError, "invalid symbol for element type of array: %s",
					 pSymbol->GetName());
	}
	return elemType;
}

bool Array::CheckShape(Signal &sig, const Array *pArrayA, const Array *pArrayB)
{
	if (Dimensions::IsSameShape(pArrayA->GetDimensions(), pArrayB->GetDimensions())) {
		return true;
	}
	sig.SetError(ERR_ValueError, "mismatched dimension of arrays between (%s) and (%s)",
				 pArrayA->GetDimensions().ToString().c_str(),
				 pArrayB->GetDimensions().ToString().c_str());
	return false;
}

bool Array::CheckElemwiseCalculatable(Signal &sig, const BinaryFuncPack &pack,
									  const Array *pArrayL, const Array *pArrayR)
{
	if (Dimensions::IsElemwiseCalculatable(
			pArrayL->GetDimensions(), pArrayR->GetDimensions())) {
		return true;
	}
	if (*pack.symbol == '\0') {
		sig.SetError(ERR_ValueError,
					 "failed in array calculation: %s((%s), (%s))",
					 pack.name,
					 pArrayL->GetDimensions().ToString().c_str(),
					 pArrayR->GetDimensions().ToString().c_str());
	} else {
		sig.SetError(ERR_ValueError,
					 "failed in array calculation: (%s) %s (%s)",
					 pArrayL->GetDimensions().ToString().c_str(), pack.symbol,
					 pArrayR->GetDimensions().ToString().c_str());
	}
	return false;
}

template<typename T_ElemDst, typename T_ElemSrc>
void CopyElementsTmpl(void *pElemRawDst, const void *pElemRawSrc, size_t nElems)
{
	T_ElemDst *pElemDst = reinterpret_cast<T_ElemDst *>(pElemRawDst);
	const T_ElemSrc *pElemSrc = reinterpret_cast<const T_ElemSrc *>(pElemRawSrc);
	for (size_t i = 0; i < nElems; i++, pElemDst++, pElemSrc++) {
		*pElemDst = static_cast<T_ElemDst>(*pElemSrc);
	}
}

typedef void (*CopyElementsFuncT)(void *pElemRawDst, const void *pElemRawSrc, size_t nElems);

bool Array::CopyElements(Environment &env, Array *pArrayDst, const Array *pArraySrc)
{
	size_t nElems = ChooseMin(pArrayDst->GetElemNum(), pArraySrc->GetElemNum());
	return CopyElements(env, pArrayDst->GetPointerRaw(), pArrayDst->GetElemType(),
						pArraySrc->GetPointerRaw(), pArraySrc->GetElemType(), nElems);
}

bool Array::CopyElements(Environment &env, void *pElemRawDst, ElemType elemTypeDst,
						 const void *pElemRawSrc, ElemType elemTypeSrc, size_t nElems)
{
	static const CopyElementsFuncT copyElementsFuncs[][ETYPE_Max] = {
		{
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Boolean, Boolean>,
			&CopyElementsTmpl<Boolean, Int8>,
			&CopyElementsTmpl<Boolean, UInt8>,
			&CopyElementsTmpl<Boolean, Int16>,
			&CopyElementsTmpl<Boolean, UInt16>,
			&CopyElementsTmpl<Boolean, Int32>,
			&CopyElementsTmpl<Boolean, UInt32>,
			&CopyElementsTmpl<Boolean, Int64>,
			&CopyElementsTmpl<Boolean, UInt64>,
			&CopyElementsTmpl<Boolean, Half>,
			&CopyElementsTmpl<Boolean, Float>,
			&CopyElementsTmpl<Boolean, Double>,
			&CopyElementsTmpl<Boolean, Complex>,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Int8, Boolean>,
			&CopyElementsTmpl<Int8, Int8>,
			&CopyElementsTmpl<Int8, UInt8>,
			&CopyElementsTmpl<Int8, Int16>,
			&CopyElementsTmpl<Int8, UInt16>,
			&CopyElementsTmpl<Int8, Int32>,
			&CopyElementsTmpl<Int8, UInt32>,
			&CopyElementsTmpl<Int8, Int64>,
			&CopyElementsTmpl<Int8, UInt64>,
			&CopyElementsTmpl<Int8, Half>,
			&CopyElementsTmpl<Int8, Float>,
			&CopyElementsTmpl<Int8, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<UInt8, Boolean>,
			&CopyElementsTmpl<UInt8, Int8>,
			&CopyElementsTmpl<UInt8, UInt8>,
			&CopyElementsTmpl<UInt8, Int16>,
			&CopyElementsTmpl<UInt8, UInt16>,
			&CopyElementsTmpl<UInt8, Int32>,
			&CopyElementsTmpl<UInt8, UInt32>,
			&CopyElementsTmpl<UInt8, Int64>,
			&CopyElementsTmpl<UInt8, UInt64>,
			&CopyElementsTmpl<UInt8, Half>,
			&CopyElementsTmpl<UInt8, Float>,
			&CopyElementsTmpl<UInt8, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Int16, Boolean>,
			&CopyElementsTmpl<Int16, Int8>,
			&CopyElementsTmpl<Int16, UInt8>,
			&CopyElementsTmpl<Int16, Int16>,
			&CopyElementsTmpl<Int16, UInt16>,
			&CopyElementsTmpl<Int16, Int32>,
			&CopyElementsTmpl<Int16, UInt32>,
			&CopyElementsTmpl<Int16, Int64>,
			&CopyElementsTmpl<Int16, UInt64>,
			&CopyElementsTmpl<Int16, Half>,
			&CopyElementsTmpl<Int16, Float>,
			&CopyElementsTmpl<Int16, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<UInt16, Boolean>,
			&CopyElementsTmpl<UInt16, Int8>,
			&CopyElementsTmpl<UInt16, UInt8>,
			&CopyElementsTmpl<UInt16, Int16>,
			&CopyElementsTmpl<UInt16, UInt16>,
			&CopyElementsTmpl<UInt16, Int32>,
			&CopyElementsTmpl<UInt16, UInt32>,
			&CopyElementsTmpl<UInt16, Int64>,
			&CopyElementsTmpl<UInt16, UInt64>,
			&CopyElementsTmpl<UInt16, Half>,
			&CopyElementsTmpl<UInt16, Float>,
			&CopyElementsTmpl<UInt16, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Int32, Boolean>,
			&CopyElementsTmpl<Int32, Int8>,
			&CopyElementsTmpl<Int32, UInt8>,
			&CopyElementsTmpl<Int32, Int16>,
			&CopyElementsTmpl<Int32, UInt16>,
			&CopyElementsTmpl<Int32, Int32>,
			&CopyElementsTmpl<Int32, UInt32>,
			&CopyElementsTmpl<Int32, Int64>,
			&CopyElementsTmpl<Int32, UInt64>,
			&CopyElementsTmpl<Int32, Half>,
			&CopyElementsTmpl<Int32, Float>,
			&CopyElementsTmpl<Int32, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<UInt32, Boolean>,
			&CopyElementsTmpl<UInt32, Int8>,
			&CopyElementsTmpl<UInt32, UInt8>,
			&CopyElementsTmpl<UInt32, Int16>,
			&CopyElementsTmpl<UInt32, UInt16>,
			&CopyElementsTmpl<UInt32, Int32>,
			&CopyElementsTmpl<UInt32, UInt32>,
			&CopyElementsTmpl<UInt32, Int64>,
			&CopyElementsTmpl<UInt32, UInt64>,
			&CopyElementsTmpl<UInt32, Half>,
			&CopyElementsTmpl<UInt32, Float>,
			&CopyElementsTmpl<UInt32, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Int64, Boolean>,
			&CopyElementsTmpl<Int64, Int8>,
			&CopyElementsTmpl<Int64, UInt8>,
			&CopyElementsTmpl<Int64, Int16>,
			&CopyElementsTmpl<Int64, UInt16>,
			&CopyElementsTmpl<Int64, Int32>,
			&CopyElementsTmpl<Int64, UInt32>,
			&CopyElementsTmpl<Int64, Int64>,
			&CopyElementsTmpl<Int64, UInt64>,
			&CopyElementsTmpl<Int64, Half>,
			&CopyElementsTmpl<Int64, Float>,
			&CopyElementsTmpl<Int64, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<UInt64, Boolean>,
			&CopyElementsTmpl<UInt64, Int8>,
			&CopyElementsTmpl<UInt64, UInt8>,
			&CopyElementsTmpl<UInt64, Int16>,
			&CopyElementsTmpl<UInt64, UInt16>,
			&CopyElementsTmpl<UInt64, Int32>,
			&CopyElementsTmpl<UInt64, UInt32>,
			&CopyElementsTmpl<UInt64, Int64>,
			&CopyElementsTmpl<UInt64, UInt64>,
			&CopyElementsTmpl<UInt64, Half>,
			&CopyElementsTmpl<UInt64, Float>,
			&CopyElementsTmpl<UInt64, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Half,	Boolean>,
			&CopyElementsTmpl<Half,	Int8>,
			&CopyElementsTmpl<Half, UInt8>,
			&CopyElementsTmpl<Half, Int16>,
			&CopyElementsTmpl<Half, UInt16>,
			&CopyElementsTmpl<Half, Int32>,
			&CopyElementsTmpl<Half, UInt32>,
			&CopyElementsTmpl<Half, Int64>,
			&CopyElementsTmpl<Half, UInt64>,
			&CopyElementsTmpl<Half, Half>,
			&CopyElementsTmpl<Half, Float>,
			&CopyElementsTmpl<Half, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Float, Boolean>,
			&CopyElementsTmpl<Float, Int8>,
			&CopyElementsTmpl<Float, UInt8>,
			&CopyElementsTmpl<Float, Int16>,
			&CopyElementsTmpl<Float, UInt16>,
			&CopyElementsTmpl<Float, Int32>,
			&CopyElementsTmpl<Float, UInt32>,
			&CopyElementsTmpl<Float, Int64>,
			&CopyElementsTmpl<Float, UInt64>,
			&CopyElementsTmpl<Float, Half>,
			&CopyElementsTmpl<Float, Float>,
			&CopyElementsTmpl<Float, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Double, Boolean>,
			&CopyElementsTmpl<Double, Int8>,
			&CopyElementsTmpl<Double, UInt8>,
			&CopyElementsTmpl<Double, Int16>,
			&CopyElementsTmpl<Double, UInt16>,
			&CopyElementsTmpl<Double, Int32>,
			&CopyElementsTmpl<Double, UInt32>,
			&CopyElementsTmpl<Double, Int64>,
			&CopyElementsTmpl<Double, UInt64>,
			&CopyElementsTmpl<Double, Half>,
			&CopyElementsTmpl<Double, Float>,
			&CopyElementsTmpl<Double, Double>,
			nullptr,
			nullptr,
		}, {
			nullptr,
			&CopyElementsTmpl<Complex, Boolean>,
			&CopyElementsTmpl<Complex, Int8>,
			&CopyElementsTmpl<Complex, UInt8>,
			&CopyElementsTmpl<Complex, Int16>,
			&CopyElementsTmpl<Complex, UInt16>,
			&CopyElementsTmpl<Complex, Int32>,
			&CopyElementsTmpl<Complex, UInt32>,
			&CopyElementsTmpl<Complex, Int64>,
			&CopyElementsTmpl<Complex, UInt64>,
			&CopyElementsTmpl<Complex, Half>,
			&CopyElementsTmpl<Complex, Float>,
			&CopyElementsTmpl<Complex, Double>,
			&CopyElementsTmpl<Complex, Complex>,
			nullptr,
		}, {
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		},
	};
	CopyElementsFuncT copyElementsFunc = copyElementsFuncs[elemTypeDst][elemTypeSrc];
	if (copyElementsFunc == nullptr) {
		env.SetError(ERR_TypeError, "can't copy elements from array@%s to array@%s",
					 GetElemTypeName(elemTypeSrc), GetElemTypeName(elemTypeDst));
		return false;
	}
	(*copyElementsFunc)(pElemRawDst, pElemRawSrc, nElems);
	return true;
}

Array *Array::ApplyUnaryFunc(Signal &sig, const UnaryFuncPack &pack, Array *pArrayResult, const Array *pArray)
{
	UnaryFuncT unaryFunc = pack.table.funcs[pArray->GetElemType()];
	if (unaryFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*unaryFunc)(sig, pArrayResult, pArray);
}

Value Array::ApplyUnaryFuncOnValue(Environment &env, const UnaryFuncPack &pack, const Value &value)
{
	Array *pArray = ApplyUnaryFunc(
		env, pack, nullptr, Object_array::GetObject(value)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return ToValue(env, pArray);
}

Array *Array::ApplyBinaryFunc(
	Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Array *pArrayL, const Array *pArrayR)
{
	if (!pArrayL->IsScalar() && !pArrayR->IsScalar()) {
		return ApplyBinaryFunc_array_array(sig, pack, pArrayResult, pArrayL, pArrayR);
	} else if (!pArrayL->IsScalar() && pArrayR->IsScalar()) {
		if (pArrayR->IsElemType(ETYPE_Complex)) {
			return ApplyBinaryFunc_array_complex(sig, pack, pArrayResult, pArrayL, pArrayR->GetScalarComplex());
		} else {
			return ApplyBinaryFunc_array_number(sig, pack, pArrayResult, pArrayL, pArrayR->GetScalarNumber());
		}
	} else if (pArrayL->IsScalar() && !pArrayR->IsScalar()) {
		if (pArrayL->IsElemType(ETYPE_Complex)) {
			return ApplyBinaryFunc_complex_array(sig, pack, pArrayResult, pArrayL->GetScalarComplex(), pArrayR);
		} else {
			return ApplyBinaryFunc_number_array(sig, pack, pArrayResult, pArrayL->GetScalarNumber(), pArrayR);
		}
	} else {
		if (!pArrayL->IsElemType(ETYPE_Complex) && !pArrayR->IsElemType(ETYPE_Complex)) {
			if (pack.table.func_number_number == nullptr) {
				sig.SetError(ERR_TypeError, "can't apply %s function on these scalars", pack.name);
				return nullptr;
			}
			return (*pack.table.func_number_number)(
				sig, pArrayResult, pArrayL->GetScalarNumber(), pArrayR->GetScalarNumber());
		} else {
			if (pack.table.func_complex_complex == nullptr) {
				sig.SetError(ERR_TypeError, "can't apply %s function on these scalars", pack.name);
				return nullptr;
			}
			return (*pack.table.func_complex_complex)(
				sig, pArrayResult, pArrayL->GetScalarComplex(), pArrayR->GetScalarComplex());
		}
	}
	return nullptr;
}

Array *Array::ApplyBinaryFunc_array_array(
	Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Array *pArrayL, const Array *pArrayR)
{
	if (pack.elemwiseFlag && !CheckElemwiseCalculatable(sig, pack, pArrayL, pArrayR)) return nullptr;
	BinaryFuncT_array_array binaryFunc_array_array =
		pack.table.funcs_array_array[pArrayL->GetElemType()][pArrayR->GetElemType()];
	if (binaryFunc_array_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_array)(sig, pArrayResult, pArrayL, pArrayR);
}

Value Array::ApplyBinaryFuncOnValue_array_array(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_array_array(
		env, pack, nullptr,
		Object_array::GetObject(valueL)->GetArray(),
		Object_array::GetObject(valueR)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return ToValue(env, pArray);
}

Array *Array::ApplyBinaryFunc_array_number(
	Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Array *pArrayL, Double numberR)
{
	BinaryFuncT_array_number binaryFunc_array_number =
		pack.table.funcs_array_number[pArrayL->GetElemType()];
	if (binaryFunc_array_number == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_number)(sig, pArrayResult, pArrayL, numberR);
}

Value Array::ApplyBinaryFuncOnValue_array_number(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_array_number(
		env, pack, nullptr,
		Object_array::GetObject(valueL)->GetArray(), valueR.GetDouble());
	if (pArray == nullptr) return Value::Nil;
	return ToValue(env, pArray);
}

Array *Array::ApplyBinaryFunc_number_array(
	Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, Double numberL, const Array *pArrayR)
{
	BinaryFuncT_number_array binaryFunc_number_array =
		pack.table.funcs_number_array[pArrayR->GetElemType()];
	if (binaryFunc_number_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_number_array)(sig, pArrayResult, numberL, pArrayR);
}

Value Array::ApplyBinaryFuncOnValue_number_array(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_number_array(
		env, pack, nullptr,
		valueL.GetDouble(), Object_array::GetObject(valueR)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return ToValue(env, pArray);
}

Array *Array::ApplyBinaryFunc_array_complex(
	Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Array *pArrayL, const Complex &complexR)
{
	BinaryFuncT_array_complex binaryFunc_array_complex =
		pack.table.funcs_array_complex[pArrayL->GetElemType()];
	if (binaryFunc_array_complex == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_complex)(sig, pArrayResult, pArrayL, complexR);
}

Value Array::ApplyBinaryFuncOnValue_array_complex(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_array_complex(
		env, pack, nullptr,
		Object_array::GetObject(valueL)->GetArray(), valueR.GetComplex());
	if (pArray == nullptr) return Value::Nil;
	return ToValue(env, pArray);
}

Array *Array::ApplyBinaryFunc_complex_array(
	Signal &sig, const BinaryFuncPack &pack, Array *pArrayResult, const Complex &complexL, const Array *pArrayR)
{
	BinaryFuncT_complex_array binaryFunc_complex_array =
		pack.table.funcs_complex_array[pArrayR->GetElemType()];
	if (binaryFunc_complex_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_complex_array)(sig, pArrayResult, complexL, pArrayR);
}

Value Array::ApplyBinaryFuncOnValue_complex_array(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_complex_array(
		env, pack, nullptr,
		valueL.GetComplex(), Object_array::GetObject(valueR)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return ToValue(env, pArray);
}

Array *Array::ApplyInvertFunc(Signal &sig, Array *pArrayResult, const Array *pArray, Double epsilon)
{
	InvertFuncT invertFunc = invertFuncTable.funcs[pArray->GetElemType()];
	if (invertFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply invert function on this array");
		return nullptr;
	}
	return (*invertFunc)(sig, pArrayResult, pArray, epsilon);
}

template<>
Array *Array::ApplyFilterFunc(
	Signal &sig, Array *pArrayResult, const Array *pArray, const Filter_MaxPool &filter)
{
	MaxPoolFilterFuncT filterFunc = maxPoolFilterFuncTable.funcs[pArray->GetElemType()];
	if (filterFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply invert function on this array");
		return nullptr;
	}
	return (*filterFunc)(sig, pArrayResult, pArray, filter);
}

void Array::SetError_UnacceptableValueAsElement(Environment &env, const Value &value)
{
	env.SetError(ERR_ValueError, "value of %s can not be stored in array",
				 value.MakeValueTypeName().c_str());
}

//-----------------------------------------------------------------------------
// Array::Dimension
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Array::Dimensions
//-----------------------------------------------------------------------------
String Array::Dimensions::ToString(const char *sep) const
{
	String rtn;
	char buff[80];
	foreach_const (Dimensions, pDim, *this) {
		::sprintf(buff, "%ld", pDim->GetSize());
		if (!rtn.empty()) rtn += sep;
		rtn += buff;
	}
	return rtn;
}

bool Array::Dimensions::Serialize(Environment &env, Stream &stream) const
{
	if (!stream.SerializePackedUInt64(env, static_cast<UInt64>(size()))) return false;
	foreach_const (Dimensions, pDim, *this) {
		if (!stream.SerializePackedUInt64(env, static_cast<UInt64>(pDim->GetSize()))) return false;
	}	
	return true;
}

bool Array::Dimensions::Deserialize(Environment &env, Stream &stream)
{
	clear();
	UInt64 nDims = 0;
	if (!stream.DeserializePackedUInt64(env, nDims)) return false;
	reserve(nDims);
	for (UInt64 i = 0; i < nDims; i++) {
		UInt64 size = 0;
		if (!stream.DeserializePackedUInt64(env, size)) return false;
		push_back(size);
	}
	return true;
}

bool Array::Dimensions::IsSameShape(const Dimensions &dimsA, const Dimensions &dimsB)
{
	if (dimsA.size() != dimsB.size()) return false;
	Dimensions::const_iterator pDimA = dimsA.begin();
	Dimensions::const_iterator pDimB = dimsB.begin();
	for ( ; pDimA != dimsA.end(); pDimA++, pDimB++) {
		if (pDimA->GetSize() != pDimB->GetSize()) return false;
	}
	return true;
}

bool Array::Dimensions::IsElemwiseCalculatable(const Dimensions &dimsA, const Dimensions &dimsB)
{
	Dimensions::const_reverse_iterator pA = dimsA.rbegin();
	Dimensions::const_reverse_iterator pB = dimsB.rbegin();
	for ( ; pA != dimsA.rend() && pB != dimsB.rend(); pA++, pB++) {
		if (pA->GetSize() != pB->GetSize()) return false;
	}
	return true;
}

//------------------------------------------------------------------------------
// InvertFuncTmpl
//------------------------------------------------------------------------------
template<typename T_Elem> inline Double _CalcInvError(const T_Elem &num)
{
	return std::abs(static_cast<Double>(num));
}

template<> inline Double _CalcInvError<Complex>(const Complex &num)
{
	return std::norm(num);
}

template<typename T_Elem> inline Double _CalcInvErrorThreshold(Double epsilon)
{
	return epsilon;
}

template<> inline Double _CalcInvErrorThreshold<Complex>(Double epsilon)
{
	return epsilon * epsilon;
}

template<typename T_Elem>
bool InvertFuncTmpl_Sub(T_Elem *pElemResult, const T_Elem *pElemOrg, size_t nRows,
						T_Elem &det, T_Elem *pElemWork, T_Elem *rows[], Double epsilon)
{
	static const Double invErrThreshold = _CalcInvErrorThreshold<T_Elem>(epsilon);
	size_t nCols = nRows;
	size_t nCols2 = nCols * 2;
	size_t bytesPerRow = nCols * sizeof(T_Elem);
	det = 1;
	do {
		const T_Elem *pElemSrc = pElemOrg;
		T_Elem *pElemDst = pElemWork;
		::memset(pElemWork, 0x00, nRows * nCols2 * sizeof(T_Elem));
		for (size_t iRow = 0; iRow < nRows; iRow++, pElemDst += nCols2, pElemSrc += nCols) {
			::memcpy(pElemDst, pElemSrc, bytesPerRow);
			*(pElemDst + nCols + iRow) = 1;
			rows[iRow] = pElemDst;
		}
	} while (0);
	for (size_t iRowPivot = 0; iRowPivot < nRows; iRowPivot++) {
		size_t iRowMax = iRowPivot;
		Double invErrMax = _CalcInvError<T_Elem>(rows[iRowMax][iRowPivot]);
		for (size_t iRow = iRowMax + 1; iRow < nRows; iRow++) {
			Double invErr = _CalcInvError<T_Elem>(rows[iRow][iRowPivot]);
			if (invErrMax < invErr) {
				iRowMax = iRow;
				invErrMax = invErr;
			}
		}
		if (invErrMax < invErrThreshold) {
			det = 0;
			return false;
		}
		if (iRowPivot != iRowMax) {
			std::swap(rows[iRowPivot], rows[iRowMax]);
			det = -det;
		}
		do {
			T_Elem *pElemPivot = rows[iRowPivot];
			T_Elem factor = *(pElemPivot + iRowPivot);
			det *= factor;
			for (size_t cnt = nCols2; cnt > 0; cnt--, pElemPivot++) {
				*pElemPivot /= factor;
			}
		} while (0);
		for (size_t iRow = 0; iRow < nRows; iRow++) {
			if (iRowPivot == iRow) continue;
			T_Elem *pElemPivot = rows[iRowPivot];
			T_Elem *pElemEach = rows[iRow];
			T_Elem factor = *(pElemEach + iRowPivot);
			for (size_t cnt = nCols2; cnt > 0; cnt--, pElemPivot++, pElemEach++) {
				*pElemEach -= *pElemPivot * factor;
			}
		}
	}
	if (pElemResult != nullptr) {
		T_Elem *pElemDst = pElemResult;
		for (size_t iRow = 0; iRow < nRows; iRow++, pElemDst += nCols) {
			::memcpy(pElemDst, rows[iRow] + nCols, bytesPerRow);
		}
	}
	return true;
}

template<typename T_Elem>
Array *InvertFuncTmpl(Signal &sig, Array *pArrayResult, const Array *pArray, Double epsilon)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<const ArrayT<T_Elem> *>(pArray);
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	if (dims.size() < 2) {
		sig.SetError(ERR_ValueError, "inversion can only be calculated with matrix");
		return nullptr;
	}
	size_t nRows = (dims.rbegin() + 1)->GetSize();
	size_t nCols = dims.rbegin()->GetSize();
	if (nRows != nCols) {
		sig.SetError(ERR_ValueError, "inversion can only be applied to square matrix");
		return nullptr;
	}
	std::unique_ptr<T_Elem []> pElemWork(new T_Elem [nRows * nCols * 2]);
	std::unique_ptr<T_Elem *[]> rows(new T_Elem *[nRows]);
	AutoPtr<ArrayT<T_Elem> > pArrayTResult(ArrayT<T_Elem>::Create(pArrayT->GetDimensions()));
	size_t elemNumMat = nRows * nCols;
	const T_Elem *pElemOrg = pArrayT->GetPointer();
	T_Elem *pElemResult = pArrayTResult->GetPointer();
	for (size_t cnt = pArrayTResult->GetElemNum() / elemNumMat; cnt > 0; cnt--) {
		T_Elem det = 0;
		if (!InvertFuncTmpl_Sub(pElemResult, pElemOrg, nRows, det, pElemWork.get(), rows.get(), epsilon)) {
			sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
			return nullptr;
		}
		pElemResult += elemNumMat;
		pElemOrg += elemNumMat;
	}
	return pArrayTResult.release();
}

//-----------------------------------------------------------------------------
// Array::Indexer
//-----------------------------------------------------------------------------
Array::Indexer::Indexer(const Dimensions &dims) :
	_dims(dims), _pDim(dims.begin()), _offsetTarget(0)
{
}

bool Array::Indexer::InitIndices(Environment &env, const ValueList &valListIdx)
{
	_offsetTarget = 0;
	foreach_const (ValueList, pValueIdx, valListIdx) {
		if (_pDim == _dims.end()) {
			env.SetError(ERR_IndexError, "number of indices exceeds dimensions");
			return false;
		}
		const Value &valueIdx = *pValueIdx;
		if (valueIdx.Is_number()) {
			size_t idx = valueIdx.GetSizeT();
			if (idx >= _pDim->GetSize()) {
				env.SetError(ERR_OutOfRangeError, "index is out of range");
				return false;
			}
			_offsetTarget += idx * _pDim->GetStride();
		} else if (valueIdx.IsListOrIterator()) {
			AutoPtr<Iterator> pIterator(valueIdx.CreateIterator(env));
			if (env.IsSignalled()) return false;
			std::unique_ptr<Generator> pGenerator(new Generator(*_pDim));
			Value valueIdxEach;
			while (pIterator->Next(env, valueIdxEach)) {
				if (valueIdxEach.Is_number()) {
					size_t idx = valueIdxEach.GetSizeT();
					if (idx >= _pDim->GetSize()) break;
					pGenerator->AddIndex(idx);
				} else {
					env.SetError(ERR_ValueError, "index must be a number");
					return false;
				}
			}
			if (pGenerator->IsEmpty()) {
				env.SetError(ERR_ValueError, "no indices specified");
				return false;
			}
			if (_pGeneratorOwner.get() == nullptr) {
				_pGeneratorOwner.reset(new GeneratorOwner());
			}
			_pGeneratorOwner->push_back(pGenerator.release());
		} else {
			env.SetError(ERR_ValueError, "index must be a number");
			return false;
		}
		_pDim++;
	}
	if (_pGeneratorOwner.get() != nullptr) _pGeneratorOwner->Reset();
	return true;
}

void Array::Indexer::MakeResultDimensions(Dimensions &dimsRtn)
{
	if (_pGeneratorOwner.get() == nullptr) {
		dimsRtn.reserve(std::distance(_pDim, _dims.end()));
	} else {
		dimsRtn.reserve(_pGeneratorOwner->size() + std::distance(_pDim, _dims.end()));
		foreach (GeneratorOwner, ppGenerator, *_pGeneratorOwner) {
			Generator *pGenerator = *ppGenerator;
			dimsRtn.push_back(Dimension(pGenerator->GetSize()));
		}
	}
	dimsRtn.insert(dimsRtn.end(), _pDim, _dims.end());
}

//-----------------------------------------------------------------------------
// Array::Indexer::Generator
//-----------------------------------------------------------------------------
bool Array::Indexer::Generator::Next()
{
	_pIndex++;
	if (_pIndex != _indices.end()) return true;
	_pIndex = _indices.begin();
	return false;
}

//-----------------------------------------------------------------------------
// Array::Indexer::GeneratorList
//-----------------------------------------------------------------------------
void Array::Indexer::GeneratorList::Reset()
{
	foreach (GeneratorList, ppGenerator, *this) {
		Generator *pGenerator = *ppGenerator;
		pGenerator->Reset();
	}
}

size_t Array::Indexer::GeneratorList::CalcOffset() const
{
	size_t offset = 0;
	foreach_const (GeneratorList, ppGenerator, *this) {
		const Generator *pGenerator = *ppGenerator;
		offset += pGenerator->CalcOffset();
	}
	return offset;
}

bool Array::Indexer::GeneratorList::Next()
{
	foreach_reverse (GeneratorList, ppGenerator, *this) {
		Generator *pGenerator = *ppGenerator;
		if (pGenerator->Next()) return true;
	}
	return false;
}

void Array::Indexer::GeneratorList::Print() const
{
	foreach_const (GeneratorList, ppGenerator, *this) {
		const Generator *pGenerator = *ppGenerator;
		if (ppGenerator != begin()) ::printf(", ");
		::printf("%lu", pGenerator->GetIndex());
	}
	::printf("\n");
}

//-----------------------------------------------------------------------------
// Array::Indexer::GeneratorOwner
//-----------------------------------------------------------------------------
Array::Indexer::GeneratorOwner::~GeneratorOwner()
{
	Clear();
}

void Array::Indexer::GeneratorOwner::Clear()
{
	foreach (GeneratorOwner, ppGenerator, *this) {
		Generator *pGenerator = *ppGenerator;
		delete pGenerator;
	}
	clear();
}

//-----------------------------------------------------------------------------
// ArrayList
//-----------------------------------------------------------------------------
const ArrayList ArrayList::Empty;

//-----------------------------------------------------------------------------
// ArrayOwner
//-----------------------------------------------------------------------------
ArrayOwner::ArrayOwner() : _cntRef(1)
{
}

ArrayOwner::~ArrayOwner()
{
	Clear();
}

void ArrayOwner::Clear()
{
	foreach (ArrayOwner, ppArray, *this) {
		Array::Delete(*ppArray);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Function Pack
//-----------------------------------------------------------------------------
Array::UnaryFuncPack Array::unaryFuncPack_Pos =				{ "pos",			"+",			};
Array::UnaryFuncPack Array::unaryFuncPack_Neg =				{ "neg",			"-",			};
Array::BinaryFuncPack Array::binaryFuncPack_Add =			{ "add",			"+",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Sub =			{ "sub",			"-",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Mul =			{ "mul",			"*",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Div =			{ "div",			"/",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Mod =			{ "mod",			"%",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Pow =			{ "pow",			"**",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Dot =			{ "dot",			"|.|",	false	};
Array::BinaryFuncPack Array::binaryFuncPack_Eq =			{ "eq",				"==",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Ne =			{ "ne",				"!=",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Gt =			{ "gt",				">",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Lt =			{ "lt",				"<",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Ge =			{ "ge",				">=",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Le =			{ "le",				"<=",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_And =			{ "and",			"&",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Or =			{ "or",				"|",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Xor =			{ "xor",			"^",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Shl =			{ "shl",			"<<",	true	};
Array::BinaryFuncPack Array::binaryFuncPack_Shr =			{ "shr",			">>",	true	};
Array::UnaryFuncPack Array::unaryFuncPack_Math_abs =		{ "math.abs",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_acos =		{ "math.acos",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_arg =		{ "math.arg",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_asin =		{ "math.asin",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_atan =		{ "math.atan",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_ceil =		{ "math.ceil",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_conj	=		{ "math.conj",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_cos =		{ "math.cos",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_cosh =		{ "math.cosh",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_delta =		{ "math.delta",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_exp =		{ "math.exp",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_floor =		{ "math.floor",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_imag =		{ "math.imag",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_log =		{ "math.log",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_log10 =		{ "math.log10",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_norm =		{ "math.norm",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_real =		{ "math.real",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_relu =		{ "math.relu",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_sigmoid =	{ "math.sigmoid",	"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_sin =		{ "math.sin",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_sinh =		{ "math.sinh",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_sqrt =		{ "math.sqrt",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_tan =		{ "math.tan",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_tanh =		{ "math.tanh",		"",				};
Array::UnaryFuncPack Array::unaryFuncPack_Math_unitstep =	{ "math.unitstep",	"",				};

//-----------------------------------------------------------------------------
// Function Table
//-----------------------------------------------------------------------------
Array::InvertFuncTable Array::invertFuncTable = {
	{
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		nullptr,
		&InvertFuncTmpl<Half>,
		&InvertFuncTmpl<Float>,
		&InvertFuncTmpl<Double>,
		&InvertFuncTmpl<Complex>,
		nullptr,
	}
};

Array::MaxPoolFilterFuncTable Array::maxPoolFilterFuncTable = {{nullptr}};

}
