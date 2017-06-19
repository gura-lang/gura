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
		{ "value",		ETYPE_Value		},
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
	_elemNum = stride;
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

//**************
bool Array::Serialize(Environment &env, Stream &stream) const
{
	return false;
}

//**************
Array *Array::Deserialize(Environment &env, Stream &stream)
{
	ElemType elemType = ETYPE_None;
	Array::Dimensions dims;
	AutoPtr<Array> pArray(Create(elemType, dims));
	return pArray.release();
}

template<typename T_Elem>
inline Array *CreateTmpl(const Array::Dimensions &dims) { return ArrayT<T_Elem>::Create(dims); }

typedef Array *(*CreateFunc)(const Array::Dimensions &dims);

Array *Array::Create(ElemType elemType, const Array::Dimensions &dims)
{
	const CreateFunc createFuncs[ETYPE_Max] = {
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

typedef void (*CopyElementsT)(void *pElemRawDst, const void *pElemRawSrc, size_t nElems);

bool Array::CopyElements(Environment &env, Array *pArrayDst, const Array *pArraySrc)
{
	size_t nElems = ChooseMin(pArrayDst->GetElemNum(), pArraySrc->GetElemNum());
	return CopyElements(env, pArrayDst->GetPointerRaw(), pArrayDst->GetElemType(),
						pArraySrc->GetPointerRaw(), pArraySrc->GetElemType(), nElems);
}

bool Array::CopyElements(Environment &env, void *pElemRawDst, ElemType elemTypeDst,
						 const void *pElemRawSrc, ElemType elemTypeSrc, size_t nElems)
{
	static const CopyElementsT copyElementsTbl[][ETYPE_Max] = {
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
	CopyElementsT copyElements = copyElementsTbl[elemTypeDst][elemTypeSrc];
	if (copyElements == nullptr) {
		env.SetError(ERR_TypeError, "can't copy elements from array@%s to array@%s",
					 GetElemTypeName(elemTypeSrc), GetElemTypeName(elemTypeDst));
		return false;
	}
	(*copyElements)(pElemRawDst, pElemRawSrc, nElems);
	return true;
}

Array *Array::ApplyUnaryFunc(Signal &sig, const UnaryFuncPack &pack, const Array *pArray)
{
	UnaryFunc unaryFunc = pack.unaryFuncs[pArray->GetElemType()];
	if (unaryFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*unaryFunc)(sig, pArray);
}

Value Array::ApplyUnaryFunc(Environment &env, const UnaryFuncPack &pack, const Value &value)
{
	Array *pArray = ApplyUnaryFunc(
		env.GetSignal(), pack, Object_array::GetObject(value)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Array *Array::ApplyBinaryFunc_array_array(
	Signal &sig, const BinaryFuncPack &pack, const Array *pArrayL, const Array *pArrayR)
{
	if (!CheckElemwiseCalculatable(sig, pack, pArrayL, pArrayR)) return nullptr;
	BinaryFunc_array_array binaryFunc_array_array =
		pack.binaryFuncs_array_array[pArrayL->GetElemType()][pArrayR->GetElemType()];
	if (binaryFunc_array_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_array)(sig, pArrayL, pArrayR);
}

Value Array::ApplyBinaryFunc_array_array(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_array_array(
		env.GetSignal(), pack,
		Object_array::GetObject(valueL)->GetArray(),
		Object_array::GetObject(valueR)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Array *Array::ApplyBinaryFunc_array_number(
	Signal &sig, const BinaryFuncPack &pack, const Array *pArrayL, Double numberR)
{
	BinaryFunc_array_number binaryFunc_array_number =
		pack.binaryFuncs_array_number[pArrayL->GetElemType()];
	if (binaryFunc_array_number == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_number)(sig, pArrayL, numberR);
}

Value Array::ApplyBinaryFunc_array_number(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_array_number(
		env.GetSignal(), pack,
		Object_array::GetObject(valueL)->GetArray(), valueR.GetDouble());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Array *Array::ApplyBinaryFunc_number_array(
	Signal &sig, const BinaryFuncPack &pack, Double numberL, const Array *pArrayR)
{
	BinaryFunc_number_array binaryFunc_number_array =
		pack.binaryFuncs_number_array[pArrayR->GetElemType()];
	if (binaryFunc_number_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_number_array)(sig, numberL, pArrayR);
}

Value Array::ApplyBinaryFunc_number_array(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_number_array(
		env.GetSignal(), pack,
		valueL.GetDouble(), Object_array::GetObject(valueR)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Array *Array::ApplyBinaryFunc_array_complex(
	Signal &sig, const BinaryFuncPack &pack, const Array *pArrayL, const Complex &complexR)
{
	BinaryFunc_array_complex binaryFunc_array_complex =
		pack.binaryFuncs_array_complex[pArrayL->GetElemType()];
	if (binaryFunc_array_complex == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_array_complex)(sig, pArrayL, complexR);
}

Value Array::ApplyBinaryFunc_array_complex(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_array_complex(
		env.GetSignal(), pack,
		Object_array::GetObject(valueL)->GetArray(), valueR.GetComplex());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

Array *Array::ApplyBinaryFunc_complex_array(
	Signal &sig, const BinaryFuncPack &pack, const Complex &complexL, const Array *pArrayR)
{
	BinaryFunc_complex_array binaryFunc_complex_array =
		pack.binaryFuncs_complex_array[pArrayR->GetElemType()];
	if (binaryFunc_complex_array == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply %s function on these arrays", pack.name);
		return nullptr;
	}
	return (*binaryFunc_complex_array)(sig, complexL, pArrayR);
}

Value Array::ApplyBinaryFunc_complex_array(
	Environment &env, const BinaryFuncPack &pack, const Value &valueL, const Value &valueR)
{
	Array *pArray = ApplyBinaryFunc_complex_array(
		env.GetSignal(), pack,
		valueL.GetComplex(), Object_array::GetObject(valueR)->GetArray());
	if (pArray == nullptr) return Value::Nil;
	return Value(new Object_array(env, pArray));
}

void Array::SetError_UnacceptableValueAsElement(Environment &env, const Value &value)
{
	env.SetError(ERR_ValueError, "value of %s can not be stored in array",
				 value.MakeValueTypeName().c_str());
}

Value Array::Dot(Environment &env, const Array *pArrayL, const Array *pArrayR)
{
	DotFunc dotFunc = dotFuncs[pArrayL->GetElemType()][pArrayR->GetElemType()];
	if (dotFunc == nullptr) {
		env.SetError(ERR_TypeError, "can't apply dot function on these arrays");
		return Value::Nil;
	}
	return (*dotFunc)(env, pArrayL, pArrayR);
}

Array *Array::Invert(Signal &sig, const Array *pArray, Double epsilon)
{
	InvertFunc invertFunc = invertFuncs[pArray->GetElemType()];
	if (invertFunc == nullptr) {
		sig.SetError(ERR_TypeError, "can't apply invert function on this array");
		return nullptr;
	}
	return (*invertFunc)(sig, pArray, epsilon);
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

//**************
bool Array::Dimensions::Serialize(Environment &env, Stream &stream) const
{
	return false;
}

//**************
bool Array::Dimensions::Deserialize(Environment &env, Stream &stream)
{
	return false;
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
// UnaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, const T_Elem &)>
Array *UnaryFuncTmpl(Signal &sig, const Array *pArray)
{
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(ArrayT<T_ElemResult>::
												Create(pArray->GetDimensions()));
	T_ElemResult *pResult = pArrayResult->GetPointer();
	const T_Elem *pElem = dynamic_cast<const ArrayT<T_Elem> *>(pArray)->GetPointer();
	size_t nElems = pArray->GetElemNum();
	for (size_t i = 0; i < nElems; i++, pResult++, pElem++) {
		op(*pResult, *pElem);
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_Elem, void (*op)(T_ElemResult &, const T_Elem &)>
Array *UnaryFuncTmpl_ExcludeZero(Signal &sig, const Array *pArray)
{
	if (pArray->DoesContainZero()) {
		sig.SetError(ERR_MathError, "the array contains zero as its element");
		return nullptr;
	}
	return UnaryFuncTmpl<T_ElemResult, T_Elem, op>(sig, pArray);
}

//------------------------------------------------------------------------------
// BinaryFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, const T_ElemL &, const T_ElemR &)>
Array *BinaryFuncTmpl_array_array(Signal &sig, const Array *pArrayL, const Array *pArrayR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult;
	if (nElemsL == nElemsR) {
		pArrayResult.reset(ArrayT<T_ElemResult>::Create(pArrayL->GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		for (size_t offset = 0; offset < nElemsL; offset++, pElemResult++) {
			op(*pElemResult, *(pElemL + offset), *(pElemR + offset));
		}
	} else if (nElemsL < nElemsR) {
		pArrayResult.reset(ArrayT<T_ElemResult>::Create(pArrayR->GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		size_t offsetL = 0;
		for (size_t offsetR = 0; offsetR < nElemsR; offsetR++, pElemResult++) {
			op(*pElemResult, *(pElemL + offsetL), *(pElemR + offsetR));
			offsetL++;
			if (offsetL >= nElemsL) offsetL = 0;
		}
	} else { // nElemsL > nElemsR
		pArrayResult.reset(ArrayT<T_ElemResult>::Create(pArrayL->GetDimensions()));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		size_t offsetR = 0;
		for (size_t offsetL = 0; offsetL < nElemsL; offsetL++, pElemResult++) {
			op(*pElemResult, *(pElemL + offsetL), *(pElemR + offsetR));
			offsetR++;
			if (offsetR >= nElemsR) offsetR = 0;
		}
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR,
		 void (*op)(T_ElemResult &, const T_ElemL &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_array_array(Signal &sig, const Array *pArrayL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_array<T_ElemResult, T_ElemL, T_ElemR, op>(sig, pArrayL, pArrayR);
}

template<typename T_ElemResult, typename T_ElemL,
		 void (*op)(T_ElemResult &, const T_ElemL &, const Double &)>
Array *BinaryFuncTmpl_array_number(Signal &sig, const Array *pArrayL, Double numberR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(ArrayT<T_ElemResult>::Create(pArrayL->GetDimensions()));
	T_ElemResult *pElemResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < nElemsL; i++, pElemResult++, pElemL++) {
		op(*pElemResult, *pElemL, numberR);
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_ElemL,
		 void (*op)(T_ElemResult &, const T_ElemL &, const Double &)>
Array *BinaryFuncTmpl_Div_array_number(Signal &sig, const Array *pArrayL, Double numberR)
{
	if (numberR == 0) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_number<T_ElemResult, T_ElemL, op>(sig, pArrayL, numberR);
}

template<typename T_ElemResult, typename T_ElemR,
		 void (*op)(T_ElemResult &, const Double &, const T_ElemR &)>
Array *BinaryFuncTmpl_number_array(Signal &sig, Double numberL, const Array *pArrayR)
{
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(ArrayT<T_ElemResult>::Create(pArrayR->GetDimensions()));
	T_ElemResult *pElemResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < nElemsR; i++, pElemResult++, pElemR++) {
		op(*pElemResult, numberL, *pElemR);
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_ElemR,
		 void (*op)(T_ElemResult &, const Double &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_number_array(Signal &sig, Double numberL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_number_array<T_ElemResult, T_ElemR, op>(sig, numberL, pArrayR);
}

template<typename T_ElemResult, typename T_ElemL,
		 void (*op)(T_ElemResult &, const T_ElemL &, const Complex &)>
Array *BinaryFuncTmpl_array_complex(Signal &sig, const Array *pArrayL, const Complex &complexR)
{
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
	size_t nElemsL = pArrayL->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(ArrayT<T_ElemResult>::Create(pArrayL->GetDimensions()));
	T_ElemResult *pElemResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < nElemsL; i++, pElemResult++, pElemL++) {
		op(*pElemResult, *pElemL, complexR);
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_ElemL,
		 void (*op)(T_ElemResult &, const T_ElemL &, const Complex &)>
Array *BinaryFuncTmpl_Div_array_complex(Signal &sig, const Array *pArrayL, const Complex &complexR)
{
	if (complexR == Complex::Zero) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_array_complex<T_ElemResult, T_ElemL, op>(sig, pArrayL, complexR);
}

template<typename T_ElemResult, typename T_ElemR,
		 void (*op)(T_ElemResult &, const Complex &, const T_ElemR &)>
Array *BinaryFuncTmpl_complex_array(Signal &sig, const Complex &complexL, const Array *pArrayR)
{
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
	size_t nElemsR = pArrayR->GetElemNum();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(ArrayT<T_ElemResult>::Create(pArrayR->GetDimensions()));
	T_ElemResult *pElemResult = pArrayResult->GetPointer();
	for (size_t i = 0; i < nElemsR; i++, pElemResult++, pElemR++) {
		op(*pElemResult, complexL, *pElemR);
	}
	return pArrayResult.release();
}

template<typename T_ElemResult, typename T_ElemR,
		 void (*op)(T_ElemResult &, const Complex &, const T_ElemR &)>
Array *BinaryFuncTmpl_Div_complex_array(Signal &sig, const Complex &complexL, const Array *pArrayR)
{
	if (pArrayR->DoesContainZero()) {
		Operator::SetError_DivideByZero(sig);
		return nullptr;
	}
	return BinaryFuncTmpl_complex_array<T_ElemResult, T_ElemR, op>(sig, complexL, pArrayR);
}

//------------------------------------------------------------------------------
// DotFuncTmpl
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_1d_2d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowR, size_t nColR)
{
	const T_ElemR *pElemBaseR = pElemR;
	for (size_t iColR = 0; iColR < nColR; iColR++, pElemBaseR++) {
		const T_ElemL *pElemWorkL = pElemL;
		const T_ElemR *pElemWorkR = pElemBaseR;
		T_ElemResult elemResult = 0;
		for (size_t iRowR = 0; iRowR < nRowR; iRowR++, pElemWorkL++, pElemWorkR += nColR) {
			elemResult +=
				static_cast<T_ElemResult>(*pElemWorkL) *
				static_cast<T_ElemResult>(*pElemWorkR);
		}
		*pElemResult++ = elemResult;
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_2d_1d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowL, size_t nColL)
{
	const T_ElemL *pElemBaseL = pElemL;
	for (size_t iRowL = 0; iRowL < nRowL; iRowL++, pElemBaseL += nColL) {
		const T_ElemL *pElemWorkL = pElemBaseL;
		const T_ElemR *pElemWorkR = pElemR;
		T_ElemResult elemResult = 0;
		for (size_t iColL = 0; iColL < nColL; iColL++, pElemWorkL++, pElemWorkR++) {
			elemResult +=
				static_cast<T_ElemResult>(*pElemWorkL) *
				static_cast<T_ElemResult>(*pElemWorkR);
		}
		*pElemResult++ = elemResult;
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_2d_2d(T_ElemResult *pElemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR,
					   size_t nRowL, size_t nColL_nRowR, size_t nColR)
{
	const T_ElemL *pElemBaseL = pElemL;
	for (size_t iRow = 0; iRow < nRowL; iRow++, pElemBaseL += nColL_nRowR) {
		const T_ElemR *pElemBaseR = pElemR;
		for (size_t iCol = 0; iCol < nColR; iCol++, pElemBaseR++) {
			const T_ElemL *pElemWorkL = pElemBaseL;
			const T_ElemR *pElemWorkR = pElemBaseR;
			T_ElemResult elemResult = 0;
			for (size_t i = 0; i < nColL_nRowR; i++, pElemWorkL++, pElemWorkR += nColR) {
				elemResult +=
					static_cast<T_ElemResult>(*pElemWorkL) *
					static_cast<T_ElemResult>(*pElemWorkR);
			}
			*pElemResult++ = elemResult;
		}
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void DotFuncTmpl_1d_1d(T_ElemResult &elemResult,
					   const T_ElemL *pElemL, const T_ElemR *pElemR, size_t nColL)
{
	elemResult = 0;
	for (size_t iColL = 0; iColL < nColL; iColL++, pElemL++, pElemR++) {
		elemResult +=
			static_cast<T_ElemResult>(*pElemL) *
			static_cast<T_ElemResult>(*pElemR);
	}
}

void SetError_CantCalcuateDotProduct(Environment &env, const Array *pArrayL, const Array *pArrayR)
{
	env.SetError(ERR_ValueError,
				 "failed in array calculation: (%s) |.| (%s)",
				 pArrayL->GetDimensions().ToString().c_str(),
				 pArrayR->GetDimensions().ToString().c_str());
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Value DotFuncTmpl(Environment &env, const Array *pArrayL, const Array *pArrayR)
{
	const Array::Dimensions &dimsL = pArrayL->GetDimensions();
	const Array::Dimensions &dimsR = pArrayR->GetDimensions();
	if (dimsL.size() == 1 && dimsR.size() == 1) {
		T_ElemResult elemResult = 0;
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		DotFuncTmpl_1d_1d(elemResult, pElemL, pElemR, nColL);
		return Value(elemResult);
	}
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult;
	if (dimsL.size() == 1 && dimsR.size() == 2) {
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		size_t nColR = dimsR[1].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayResult.reset(new ArrayT<T_ElemResult>(nColR));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		DotFuncTmpl_1d_2d(pElemResult, pElemL, pElemR, nRowR, nColR);
	} else if (dimsL.size() == 2 && dimsR.size() == 1) {
		size_t nRowL = dimsL[0].GetSize();
		size_t nColL = dimsL[1].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayResult.reset(new ArrayT<T_ElemResult>(nRowL));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		DotFuncTmpl_2d_1d(pElemResult, pElemL, pElemR, nRowL, nColL);
	} else if (dimsL.size() == 2 && dimsR.size() == 2) {
		size_t nRowL = dimsL[0].GetSize();
		size_t nColL = dimsL[1].GetSize();
		size_t nRowR = dimsR[0].GetSize();
		size_t nColR = dimsR[1].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		pArrayResult.reset(new ArrayT<T_ElemResult>(nRowL, nColR));
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		DotFuncTmpl_2d_2d(pElemResult, pElemL, pElemR, nRowL, nColL, nColR);
	} else if (dimsL.size() >= 2 && dimsR.size() >= 2) {
		size_t nRowL = (dimsL.rbegin() + 1)->GetSize();
		size_t nColL = dimsL.rbegin()->GetSize();
		size_t nRowR = (dimsR.rbegin() + 1)->GetSize();
		size_t nColR = dimsR.rbegin()->GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumL = pArrayL->GetElemNum();
		size_t elemNumR = pArrayR->GetElemNum();
		size_t elemNumMatResult = nRowL * nColR;
		size_t elemNumMatL = nRowL * nColL;
		size_t elemNumMatR = nRowR * nColR;
		size_t offsetL = 0, offsetR = 0;
		if (dimsL.size() < dimsR.size()) {
			pArrayResult.reset(new ArrayT<T_ElemResult>());
			pArrayResult->SetDimensions(dimsR.begin(), dimsR.begin() + dimsR.size() - 2,
										Array::Dimension(nRowL), Array::Dimension(nColR));
			pArrayResult->AllocMemory();
			T_ElemResult *pElemResult = pArrayResult->GetPointer();
			while (offsetR < elemNumR) {
				DotFuncTmpl_2d_2d(pElemResult, pElemL + offsetL, pElemR + offsetR,
								  nRowL, nColL, nColR);
				pElemResult += elemNumMatResult;
				offsetL += elemNumMatL;
				offsetR += elemNumMatR;
				if (offsetL >= elemNumL) offsetL = 0;
			}
		} else { // dimsL.size() >= dimsR.size()
			pArrayResult.reset(new ArrayT<T_ElemResult>());
			pArrayResult->SetDimensions(dimsL.begin(), dimsL.begin() + dimsL.size() - 2,
										Array::Dimension(nRowL), Array::Dimension(nColR));
			pArrayResult->AllocMemory();
			T_ElemResult *pElemResult = pArrayResult->GetPointer();
			while (offsetL < elemNumL) {
				DotFuncTmpl_2d_2d(pElemResult, pElemL + offsetL, pElemR + offsetR,
								  nRowL, nColL, nColR);
				pElemResult += elemNumMatResult;
				offsetL += elemNumMatL;
				offsetR += elemNumMatR;
				if (offsetR >= elemNumR) offsetR = 0;
			}
		}
	} else if (dimsL.size() == 1 && dimsR.size() >= 2) {
		size_t nColL = dimsL[0].GetSize();
		size_t nRowR = (dimsR.rbegin() + 1)->GetSize();
		size_t nColR = dimsR.rbegin()->GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumR = pArrayR->GetElemNum();
		size_t elemNumMatR = nRowR * nColR;
		size_t offsetR = 0;
		pArrayResult.reset(new ArrayT<T_ElemResult>());
		pArrayResult->SetDimensions(dimsR.begin(), dimsR.begin() + dimsR.size() - 2,
									Array::Dimension(nColR));
		pArrayResult->AllocMemory();
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		while (offsetR < elemNumR) {
			DotFuncTmpl_1d_2d(pElemResult, pElemL, pElemR + offsetR, nRowR, nColR);
			pElemResult += nColR;
			offsetR += elemNumMatR;
		}
	} else if (dimsL.size() >= 2 && dimsR.size() == 1) {
		size_t nRowL = (dimsL.rbegin() + 1)->GetSize();
		size_t nColL = dimsL.rbegin()->GetSize();
		size_t nRowR = dimsR[0].GetSize();
		if (nColL != nRowR) {
			SetError_CantCalcuateDotProduct(env, pArrayL, pArrayR);
			return Value::Nil;
		}
		const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(pArrayL)->GetPointer();
		const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(pArrayR)->GetPointer();
		size_t elemNumL = pArrayL->GetElemNum();
		size_t elemNumMatL = nRowL * nColL;
		size_t offsetL = 0;
		pArrayResult.reset(new ArrayT<T_ElemResult>());
		pArrayResult->SetDimensions(dimsL.begin(), dimsL.begin() + dimsL.size() - 2,
									Array::Dimension(nRowL));
		pArrayResult->AllocMemory();
		T_ElemResult *pElemResult = pArrayResult->GetPointer();
		while (offsetL < elemNumL) {
			DotFuncTmpl_2d_1d(pElemResult, pElemL + offsetL, pElemR, nRowL, nColL);
			pElemResult += nRowR;
			offsetL += elemNumMatL;
		}
	}
	return Value(new Object_array(env, pArrayResult.release()));
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
Array *InvertFuncTmpl(Signal &sig, const Array *pArray, Double epsilon)
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
	AutoPtr<ArrayT<T_Elem> > pArrayResult(ArrayT<T_Elem>::Create(pArrayT->GetDimensions()));
	size_t elemNumMat = nRows * nCols;
	const T_Elem *pElemOrg = pArrayT->GetPointer();
	T_Elem *pElemResult = pArrayResult->GetPointer();
	for (size_t cnt = pArrayResult->GetElemNum() / elemNumMat; cnt > 0; cnt--) {
		T_Elem det = 0;
		if (!InvertFuncTmpl_Sub(pElemResult, pElemOrg, nRows, det, pElemWork.get(), rows.get(), epsilon)) {
			sig.SetError(ERR_ValueError, "failed to calculate inverted matrix");
			return nullptr;
		}
		pElemResult += elemNumMat;
		pElemOrg += elemNumMat;
	}
	return pArrayResult.release();
}

//------------------------------------------------------------------------------
// Function tables
//------------------------------------------------------------------------------
#define ImplementUnaryFuncPack(op, name, symbol, func)	\
Array::UnaryFuncPack Array::unaryFuncPack_##op = { \
	name, \
	symbol, \
	{ \
		nullptr, \
		&func<Boolean,	Boolean,Operator_##op::Calc>,	\
		&func<Int8,		Int8,	Operator_##op::Calc>,	\
		&func<UInt8,	UInt8,	Operator_##op::Calc>,	\
		&func<Int16,	Int16,	Operator_##op::Calc>,	\
		&func<UInt16,	UInt16,	Operator_##op::Calc>,	\
		&func<Int32,	Int32,	Operator_##op::Calc>,	\
		&func<UInt32,	UInt32,	Operator_##op::Calc>,	\
		&func<Int64,	Int64,	Operator_##op::Calc>,	\
		&func<UInt64,	UInt64,	Operator_##op::Calc>,	\
		&func<Half,		Half,	Operator_##op::Calc>,	\
		&func<Float,	Float,	Operator_##op::Calc>,	\
		&func<Double,	Double,	Operator_##op::Calc>,	\
		&func<Complex,	Complex,Operator_##op::Calc>,	\
		nullptr, \
	}, \
}

#define ImplementBinaryFuncPack(op, name, symbol, funcPrefix)	\
Array::BinaryFuncPack Array::binaryFuncPack_##op = { \
	name, \
	symbol, \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Boolean,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int8,		Boolean,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	Boolean,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Boolean,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Boolean,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Boolean,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Boolean,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Boolean,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Boolean,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Boolean,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Boolean,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Boolean,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Boolean,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int8,		Int8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int8,		Int8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	Int8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Int8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt8,	UInt8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	UInt8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	UInt8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int16,	Int16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int16,	Int16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	Int16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt16,	UInt16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	UInt16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int32,	Int32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int32,	Int32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	Int32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt32,	UInt32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	UInt32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Int64,	Int64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Int64,	Int64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	Int64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Int64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Int64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Int64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Int64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<UInt64,	UInt64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		UInt64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	UInt64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	UInt64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	UInt64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Half,		Half,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Half,		Half,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Half,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Half,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Half,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Float,	Float,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Float,	Float,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Float,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Float,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Double,	Double,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Double,	Double,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Double,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Complex,	Complex,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Complex,	Complex,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_number<Int8,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int8,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt8,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int16,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt16,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int32,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt32,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Int64,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<UInt64,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Half,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Float,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Double,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Complex,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_number_array<Int8,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int8,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt8,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int16,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt16,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int32,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt32,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Int64,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<UInt64,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Half,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Float,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Double,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Complex,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_array_complex<Complex,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Complex,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_complex_array<Complex,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Complex,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	} \
}

#define ImplementBinaryFuncPack_Cmp(op, name, symbol, funcPrefix)	\
Array::BinaryFuncPack Array::binaryFuncPack_##op = { \
	name, \
	symbol, \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Boolean,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt8,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt16,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt32,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Int64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Int64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	UInt64,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Half,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Half,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Float,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Float,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Double,		Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Double,		Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, \
			&funcPrefix##_array_array<Boolean,	Complex,	Boolean,	Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt8,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt16,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt32,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Int64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	UInt64,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Half,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Float,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Double,		Operator_##op::Calc>, \
			&funcPrefix##_array_array<Boolean,	Complex,	Complex,	Operator_##op::Calc>, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, \
	}, { \
		nullptr, \
		&funcPrefix##_array_number<Boolean,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_number<Boolean,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_number_array<Boolean,		Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Int64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Half,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Float,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Double,		Operator_##op::Calc>, \
		&funcPrefix##_number_array<Boolean,		Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_array_complex<Boolean,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_array_complex<Boolean,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	}, { \
		nullptr, \
		&funcPrefix##_complex_array<Boolean,	Boolean,	Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt8,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt16,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt32,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Int64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	UInt64,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Half,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Float,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Double,		Operator_##op::Calc>, \
		&funcPrefix##_complex_array<Boolean,	Complex,	Operator_##op::Calc>, \
		nullptr, \
	} \
}

#define ImplementBinaryFuncPack_BitOp(op, name, symbol)	 \
Array::BinaryFuncPack Array::binaryFuncPack_##op = { \
	name, \
	symbol, \
	{ \
		{ \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,  \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Boolean,	Boolean,	Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int8,		Boolean,	Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		Boolean,	UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Boolean,	Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Boolean,	UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Boolean,	Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Boolean,	UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Boolean,	Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Boolean,	UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int8,		Int8,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int8,		Int8,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		Int8,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int8,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int8,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int8,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int8,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt8,		UInt8,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		UInt8,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt8,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt8,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt8,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt8,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt8,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int16,		Int16,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		Int16,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int16,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int16,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int16,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int16,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt16,		UInt16,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		UInt16,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt16,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt16,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt16,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int32,		Int32,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		Int32,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int32,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int32,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt32,		UInt32,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		UInt32,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt32,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<Int64,		Int64,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		Int64,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Boolean,	Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt8,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt16,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt32,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		Int64,		Operator_##op::Calc>, \
			&BinaryFuncTmpl_array_array<UInt64,		UInt64,		UInt64,		Operator_##op::Calc>, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
			nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, { \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
			nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		}, \
	}, { \
		nullptr, \
		&BinaryFuncTmpl_array_number<Int8,		Boolean,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int8,		Int8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt8,		UInt8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int16,		Int16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt16,	UInt16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int32,		Int32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt32,	UInt32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<Int64,		Int64,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_array_number<UInt64,	UInt64,		Operator_##op::Calc>,	\
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, \
		&BinaryFuncTmpl_number_array<Int8,		Boolean,	Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int8,		Int8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt8,		UInt8,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int16,		Int16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt16,	UInt16,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int32,		Int32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt32,	UInt32,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<Int64,		Int64,		Operator_##op::Calc>,	\
		&BinaryFuncTmpl_number_array<UInt64,	UInt64,		Operator_##op::Calc>,	\
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
		nullptr, \
	}, { \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
	}, { \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, \
	} \
}

ImplementUnaryFuncPack(Pos,				"pos",				"+",	UnaryFuncTmpl);
ImplementUnaryFuncPack(Neg,				"neg",				"-",	UnaryFuncTmpl);

ImplementBinaryFuncPack(Add,			"add",				"+",	BinaryFuncTmpl);
ImplementBinaryFuncPack(Sub,			"sub",				"-",	BinaryFuncTmpl);
ImplementBinaryFuncPack(Mul,			"mul",				"*",	BinaryFuncTmpl);
ImplementBinaryFuncPack(Div,			"div",				"/",	BinaryFuncTmpl_Div);
ImplementBinaryFuncPack(Mod,			"mod",				"%",	BinaryFuncTmpl_Div);
ImplementBinaryFuncPack(Pow,			"pow",				"**",	BinaryFuncTmpl);

ImplementBinaryFuncPack_Cmp(Eq,			"eq",				"==",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Ne,			"ne",				"!=",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Gt,			"gt",				">",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Lt,			"lt",				"<",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Ge,			"ge",				">=",	BinaryFuncTmpl);
ImplementBinaryFuncPack_Cmp(Le,			"le",				"<=",	BinaryFuncTmpl);

ImplementBinaryFuncPack_BitOp(And,		"and",				"&");
ImplementBinaryFuncPack_BitOp(Or,		"or",				"|");
ImplementBinaryFuncPack_BitOp(Xor,		"xor",				"^");
ImplementBinaryFuncPack_BitOp(Shl,		"shl",				"<<");
ImplementBinaryFuncPack_BitOp(Shr,		"shr",				">>");

ImplementUnaryFuncPack(Math_abs,		"math.abs",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_acos,		"math.acos",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_arg,		"math.arg",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_asin,		"math.asin",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_atan,		"math.atan",		"",		UnaryFuncTmpl);
ImplementBinaryFuncPack(Math_atan2,		"math.atan2",		"",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_ceil,		"math.ceil",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_conj,		"math.conj",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_cos,		"math.cos",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_cosh,		"math.cosh",		"",		UnaryFuncTmpl);
//ImplementBinaryFuncPack(Math_covariance,"math.covariance","",		BinaryFuncTmpl);
//ImplementBinaryFuncPack(Math_cross,	"math.cross",		"",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_delta,		"math.delta",		"",		UnaryFuncTmpl);
//ImplementBinaryFuncPack(Math_dot,		"math.dot",			"",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_exp,		"math.exp",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_floor,		"math.floor",		"",		UnaryFuncTmpl);
ImplementBinaryFuncPack(Math_hypot,		"math.hypot",		"",		BinaryFuncTmpl);
ImplementUnaryFuncPack(Math_imag,		"math.imag",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_log,		"math.log",			"",		UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncPack(Math_log10,		"math.log10",		"",		UnaryFuncTmpl_ExcludeZero);
ImplementUnaryFuncPack(Math_norm,		"math.norm",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_ramp,		"math.ramp",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_real,		"math.real",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sigmoid,	"math.sigmoid",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sin,		"math.sin",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sinh,		"math.sinh",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_sqrt,		"math.sqrt",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_tan,		"math.tan",			"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_tanh,		"math.tanh",		"",		UnaryFuncTmpl);
ImplementUnaryFuncPack(Math_unitstep,	"math.unitstep",	"",		UnaryFuncTmpl);

Array::DotFunc Array::dotFuncs[ETYPE_Max][ETYPE_Max] = {
	{
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int8,		Boolean,	Boolean	>,
		&DotFuncTmpl<Int8,		Boolean,	Int8	>,
		&DotFuncTmpl<UInt8,		Boolean,	UInt8	>,
		&DotFuncTmpl<Int16,		Boolean,	Int16	>,
		&DotFuncTmpl<UInt16,	Boolean,	UInt16	>,
		&DotFuncTmpl<Int32,		Boolean,	Int32	>,
		&DotFuncTmpl<UInt32,	Boolean,	UInt32	>,
		&DotFuncTmpl<Int64,		Boolean,	Int64	>,
		&DotFuncTmpl<UInt64,	Boolean,	UInt64	>,
		&DotFuncTmpl<Half,		Boolean,	Half	>,
		&DotFuncTmpl<Float,		Boolean,	Float	>,
		&DotFuncTmpl<Double,	Boolean,	Double	>,
		&DotFuncTmpl<Complex,	Boolean,	Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int8,		Int8,		Boolean	>,
		&DotFuncTmpl<Int8,		Int8,		Int8	>,
		&DotFuncTmpl<UInt8,		Int8,		UInt8	>,
		&DotFuncTmpl<Int16,		Int8,		Int16	>,
		&DotFuncTmpl<UInt16,	Int8,		UInt16	>,
		&DotFuncTmpl<Int32,		Int8,		Int32	>,
		&DotFuncTmpl<UInt32,	Int8,		UInt32	>,
		&DotFuncTmpl<Int64,		Int8,		Int64	>,
		&DotFuncTmpl<UInt64,	Int8,		UInt64	>,
		&DotFuncTmpl<Half,		Int8,		Half	>,
		&DotFuncTmpl<Float,		Int8,		Float	>,
		&DotFuncTmpl<Double,	Int8,		Double	>,
		&DotFuncTmpl<Complex,	Int8,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<UInt8,		UInt8,		Boolean	>,
		&DotFuncTmpl<UInt8,		UInt8,		Int8	>,
		&DotFuncTmpl<UInt8,		UInt8,		UInt8	>,
		&DotFuncTmpl<Int16,		UInt8,		Int16	>,
		&DotFuncTmpl<UInt16,	UInt8,		UInt16	>,
		&DotFuncTmpl<Int32,		UInt8,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt8,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt8,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt8,		UInt64	>,
		&DotFuncTmpl<Half,		UInt8,		Half	>,
		&DotFuncTmpl<Float,		UInt8,		Float	>,
		&DotFuncTmpl<Double,	UInt8,		Double	>,
		&DotFuncTmpl<Complex,	UInt8,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int16,		Int16,		Boolean	>,
		&DotFuncTmpl<Int16,		Int16,		Int8	>,
		&DotFuncTmpl<Int16,		Int16,		UInt8	>,
		&DotFuncTmpl<Int16,		Int16,		Int16	>,
		&DotFuncTmpl<UInt16,	Int16,		UInt16	>,
		&DotFuncTmpl<Int32,		Int16,		Int32	>,
		&DotFuncTmpl<UInt32,	Int16,		UInt32	>,
		&DotFuncTmpl<Int64,		Int16,		Int64	>,
		&DotFuncTmpl<UInt64,	Int16,		UInt64	>,
		&DotFuncTmpl<Half,		Int16,		Half	>,
		&DotFuncTmpl<Float,		Int16,		Float	>,
		&DotFuncTmpl<Double,	Int16,		Double	>,
		&DotFuncTmpl<Complex,	Int16,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<UInt16,	UInt16,		Boolean	>,
		&DotFuncTmpl<UInt16,	UInt16,		Int8	>,
		&DotFuncTmpl<UInt16,	UInt16,		UInt8	>,
		&DotFuncTmpl<UInt16,	UInt16,		Int16	>,
		&DotFuncTmpl<UInt16,	UInt16,		UInt16	>,
		&DotFuncTmpl<Int32,		UInt16,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt16,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt16,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt16,		UInt64	>,
		&DotFuncTmpl<Half,		UInt16,		Half	>,
		&DotFuncTmpl<Float,		UInt16,		Float	>,
		&DotFuncTmpl<Double,	UInt16,		Double	>,
		&DotFuncTmpl<Complex,	UInt16,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int32,		Int32,		Boolean	>,
		&DotFuncTmpl<Int32,		Int32,		Int8	>,
		&DotFuncTmpl<Int32,		Int32,		UInt8	>,
		&DotFuncTmpl<Int32,		Int32,		Int16	>,
		&DotFuncTmpl<Int32,		Int32,		UInt16	>,
		&DotFuncTmpl<Int32,		Int32,		Int32	>,
		&DotFuncTmpl<UInt32,	Int32,		UInt32	>,
		&DotFuncTmpl<Int64,		Int32,		Int64	>,
		&DotFuncTmpl<UInt64,	Int32,		UInt64	>,
		&DotFuncTmpl<Half,		Int32,		Half	>,
		&DotFuncTmpl<Float,		Int32,		Float	>,
		&DotFuncTmpl<Double,	Int32,		Double	>,
		&DotFuncTmpl<Complex,	Int32,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<UInt32,	UInt32,		Boolean	>,
		&DotFuncTmpl<UInt32,	UInt32,		Int8	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt8	>,
		&DotFuncTmpl<UInt32,	UInt32,		Int16	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt16	>,
		&DotFuncTmpl<UInt32,	UInt32,		Int32	>,
		&DotFuncTmpl<UInt32,	UInt32,		UInt32	>,
		&DotFuncTmpl<Int64,		UInt32,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt32,		UInt64	>,
		&DotFuncTmpl<Half,		UInt32,		Half	>,
		&DotFuncTmpl<Float,		UInt32,		Float	>,
		&DotFuncTmpl<Double,	UInt32,		Double	>,
		&DotFuncTmpl<Complex,	UInt32,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Int64,		Int64,		Boolean	>,
		&DotFuncTmpl<Int64,		Int64,		Int8	>,
		&DotFuncTmpl<Int64,		Int64,		UInt8	>,
		&DotFuncTmpl<Int64,		Int64,		Int16	>,
		&DotFuncTmpl<Int64,		Int64,		UInt16	>,
		&DotFuncTmpl<Int64,		Int64,		Int32	>,
		&DotFuncTmpl<Int64,		Int64,		UInt32	>,
		&DotFuncTmpl<Int64,		Int64,		Int64	>,
		&DotFuncTmpl<UInt64,	Int64,		UInt64	>,
		&DotFuncTmpl<Half,		Int64,		Half	>,
		&DotFuncTmpl<Float,		Int64,		Float	>,
		&DotFuncTmpl<Double,	Int64,		Double	>,
		&DotFuncTmpl<Complex,	Int64,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<UInt64,	UInt64,		Boolean	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int8	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt8	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int16	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt16	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int32	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt32	>,
		&DotFuncTmpl<UInt64,	UInt64,		Int64	>,
		&DotFuncTmpl<UInt64,	UInt64,		UInt64	>,
		&DotFuncTmpl<Half,		UInt64,		Half	>,
		&DotFuncTmpl<Float,		UInt64,		Float	>,
		&DotFuncTmpl<Double,	UInt64,		Double	>,
		&DotFuncTmpl<Complex,	UInt64,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Half,		Half,		Boolean	>,
		&DotFuncTmpl<Half,		Half,		Int8	>,
		&DotFuncTmpl<Half,		Half,		UInt8	>,
		&DotFuncTmpl<Half,		Half,		Int16	>,
		&DotFuncTmpl<Half,		Half,		UInt16	>,
		&DotFuncTmpl<Half,		Half,		Int32	>,
		&DotFuncTmpl<Half,		Half,		UInt32	>,
		&DotFuncTmpl<Half,		Half,		Int64	>,
		&DotFuncTmpl<Half,		Half,		UInt64	>,
		&DotFuncTmpl<Half,		Half,		Half	>,
		&DotFuncTmpl<Half,		Half,		Float	>,
		&DotFuncTmpl<Double,	Half,		Double	>,
		&DotFuncTmpl<Complex,	Half,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Float,		Float,		Boolean	>,
		&DotFuncTmpl<Float,		Float,		Int8	>,
		&DotFuncTmpl<Float,		Float,		UInt8	>,
		&DotFuncTmpl<Float,		Float,		Int16	>,
		&DotFuncTmpl<Float,		Float,		UInt16	>,
		&DotFuncTmpl<Float,		Float,		Int32	>,
		&DotFuncTmpl<Float,		Float,		UInt32	>,
		&DotFuncTmpl<Float,		Float,		Int64	>,
		&DotFuncTmpl<Float,		Float,		UInt64	>,
		&DotFuncTmpl<Float,		Float,		Half	>,
		&DotFuncTmpl<Float,		Float,		Float	>,
		&DotFuncTmpl<Double,	Float,		Double	>,
		&DotFuncTmpl<Complex,	Float,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Double,	Double,		Boolean	>,
		&DotFuncTmpl<Double,	Double,		Int8	>,
		&DotFuncTmpl<Double,	Double,		UInt8	>,
		&DotFuncTmpl<Double,	Double,		Int16	>,
		&DotFuncTmpl<Double,	Double,		UInt16	>,
		&DotFuncTmpl<Double,	Double,		Int32	>,
		&DotFuncTmpl<Double,	Double,		UInt32	>,
		&DotFuncTmpl<Double,	Double,		Int64	>,
		&DotFuncTmpl<Double,	Double,		UInt64	>,
		&DotFuncTmpl<Half,		Double,		Half	>,
		&DotFuncTmpl<Double,	Double,		Float	>,
		&DotFuncTmpl<Double,	Double,		Double	>,
		&DotFuncTmpl<Complex,	Double,		Complex	>,
		nullptr,
	}, {
		nullptr,
		&DotFuncTmpl<Complex,	Complex,	Boolean	>,
		&DotFuncTmpl<Complex,	Complex,	Int8	>,
		&DotFuncTmpl<Complex,	Complex,	UInt8	>,
		&DotFuncTmpl<Complex,	Complex,	Int16	>,
		&DotFuncTmpl<Complex,	Complex,	UInt16	>,
		&DotFuncTmpl<Complex,	Complex,	Int32	>,
		&DotFuncTmpl<Complex,	Complex,	UInt32	>,
		&DotFuncTmpl<Complex,	Complex,	Int64	>,
		&DotFuncTmpl<Complex,	Complex,	UInt64	>,
		&DotFuncTmpl<Complex,	Complex,	Half	>,
		&DotFuncTmpl<Complex,	Complex,	Float	>,
		&DotFuncTmpl<Complex,	Complex,	Double	>,
		&DotFuncTmpl<Complex,	Complex,	Complex	>,
		nullptr,
	}, {
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
		nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr,
	},
};

Array::InvertFunc Array::invertFuncs[ETYPE_Max] = {
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
};

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
			AutoPtr<Iterator> pIterator(valueIdx.CreateIterator(env.GetSignal()));
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

}
