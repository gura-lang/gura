//=============================================================================
// Gura class: array
//=============================================================================
#include "stdafx.h"

namespace Gura {

typedef Value (*ConstructorT)(Environment &env, Argument &arg);
typedef Value (*EvalIndexGetT)(Environment &env, const ValueList &valListIdx, Object_array *pObj);
typedef void (*EvalIndexSetT)(Environment &env, const ValueList &valListIdx, const Value &value, Object_array *pObj);

static const char *helpDoc_en = R"**(

)**";

//-----------------------------------------------------------------------------
// Object_array
//-----------------------------------------------------------------------------
Object *Object_array::Clone() const
{
	return nullptr;
}

String Object_array::ToString(bool exprFlag)
{
	return _pArray->ToString(exprFlag);
}

template<typename T_Elem>
Value EvalIndexGetTmpl(Environment &env, const ValueList &valListIdx, Object_array *pObj)
{
	if (valListIdx.empty()) return Value::Nil;
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pObj->GetArray());
	Array::Indexer indexer(pArrayT);
	if (!indexer.InitIndices(env, valListIdx)) return Value::Nil;
	Value valueRtn;
	if (indexer.HasGenerator()) {
		Array::Dimensions dimsRtn;
		indexer.MakeResultDimensions(dimsRtn);
		AutoPtr<ArrayT<T_Elem> > pArrayTRtn(ArrayT<T_Elem>::Create(dimsRtn));
		if (pArrayT->IsColMajor()) pArrayTRtn->SetColMajor();
		if (!indexer.IsEmptyGenerator()) {
			size_t nElemsUnit = indexer.GetElemNumUnit();
			size_t bytesUnit = nElemsUnit * pArrayTRtn->GetElemBytes();
			const T_Elem *pElemTgt = pArrayT->GetPointer() + indexer.GetOffsetTarget();
			T_Elem *pElemDst = pArrayTRtn->GetPointer();
			do {
				::memcpy(pElemDst, pElemTgt + indexer.GenerateOffset(), bytesUnit);
				pElemDst += nElemsUnit;
			} while (indexer.NextGenerator());
		}
		valueRtn = Array::ToValue(env, pArrayTRtn.release());
	} else if (indexer.IsTargetScalar()) {
		const T_Elem *pElemTgt = pArrayT->GetPointer() + indexer.GetOffsetTarget();
		valueRtn = Value(*pElemTgt);
	} else {
		AutoPtr<ArrayT<T_Elem> > pArrayTRtn(ArrayT<T_Elem>::Create());
		pArrayTRtn->SetMemory(pArrayT->GetMemory().Reference(),
							  pArrayT->GetOffsetBase() + indexer.GetOffsetTarget());
		Array::Dimensions dimsRtn;
		indexer.MakeResultDimensions(dimsRtn);
		pArrayTRtn->SetDimensions(dimsRtn);
		if (pArrayT->IsColMajor()) pArrayTRtn->SetColMajor();
		valueRtn = Array::ToValue(env, pArrayTRtn.release());
	}
	return valueRtn;
}

Value Object_array::EvalIndexGet(Environment &env, const ValueList &valListIdx)
{
	static const EvalIndexGetT evalIndexGetTbl[] = {
		nullptr,
		&EvalIndexGetTmpl<Boolean>,
		&EvalIndexGetTmpl<Int8>,
		&EvalIndexGetTmpl<UInt8>,
		&EvalIndexGetTmpl<Int16>,
		&EvalIndexGetTmpl<UInt16>,
		&EvalIndexGetTmpl<Int32>,
		&EvalIndexGetTmpl<UInt32>,
		&EvalIndexGetTmpl<Int64>,
		&EvalIndexGetTmpl<UInt64>,
		&EvalIndexGetTmpl<Half>,
		&EvalIndexGetTmpl<Float>,
		&EvalIndexGetTmpl<Double>,
		&EvalIndexGetTmpl<Complex>,
		//&EvalIndexGetTmpl<Value>,
	};
	return (*evalIndexGetTbl[GetArray()->GetElemType()])(env, valListIdx, this);
}

template<typename T_Elem>
void EvalIndexSetTmpl(Environment &env, const ValueList &valListIdx, const Value &value, Object_array *pObj)
{
	const bool complexFlag = (ArrayT<T_Elem>::ElemTypeThis == Array::ETYPE_Complex);
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pObj->GetArray());
	if (!pArrayT->PrepareModification(env.GetSignal())) return;
	if (valListIdx.empty()) {
		if (value.Is_number() || value.Is_boolean()) {
			ArrayT<T_Elem>::FillDouble(pArrayT->GetPointer(), pArrayT->GetElemNum(), value.GetDouble(), 1);
		} else if (complexFlag && value.Is_complex()) {
			ArrayT<T_Elem>::FillComplex(pArrayT->GetPointer(), pArrayT->GetElemNum(), value.GetComplex(), 1);
		} else if (value.IsListOrIterator()) {
			AutoPtr<Iterator> pIteratorSrc(value.CreateIterator(env.GetSignal()));
			if (env.IsSignalled()) return;
			AutoPtr<Iterator> pIterator(
				new Iterator_Flatten(pIteratorSrc.release(), Iterator_Flatten::MODE_DepthFirstSearch));
			Value valueEach;
			T_Elem *pElemDst = pArrayT->GetPointer();
			size_t nElems = pArrayT->GetElemNum();
			for (size_t i = 0; i < nElems; i++, pElemDst++) {
				if (!pIterator->Next(env, valueEach) ||
					!ArrayT<T_Elem>::StoreValueAt(env, pElemDst, valueEach)) return;
			}
		} else {
			Array::SetError_UnacceptableValueAsElement(env, value);
		}
		return;
	}
	Array::Indexer indexer(pArrayT);
	if (!indexer.InitIndices(env, valListIdx)) return;
	T_Elem *pElemTgt = pArrayT->GetPointer() + indexer.GetOffsetTarget();
	size_t nElemsUnit = indexer.GetElemNumUnit();
	size_t stridesUnit = indexer.GetStridesUnit();
	if (value.Is_number() || value.Is_boolean()) {
		Double num = value.GetDouble();
		if (indexer.HasGenerator()) {
			if (!indexer.IsEmptyGenerator()) {
				do {
					ArrayT<T_Elem>::FillDouble(pElemTgt + indexer.GenerateOffset(), nElemsUnit, num, stridesUnit);
				} while (indexer.NextGenerator());
			}
		} else {
			ArrayT<T_Elem>::FillDouble(pElemTgt, nElemsUnit, num, stridesUnit);
		}
	} else if (complexFlag && value.Is_complex()) {
		const Complex &num = value.GetComplex();
		if (indexer.HasGenerator()) {
			if (!indexer.IsEmptyGenerator()) {
				do {
					ArrayT<T_Elem>::FillComplex(pElemTgt + indexer.GenerateOffset(), nElemsUnit, num, stridesUnit);
				} while (indexer.NextGenerator());
			}
		} else {
			ArrayT<T_Elem>::FillComplex(pElemTgt, nElemsUnit, num, stridesUnit);
		}
		
	} else if (value.IsListOrIterator()) {
		AutoPtr<Iterator> pIteratorSrc(value.CreateIterator(env.GetSignal()));
		if (env.IsSignalled()) return;
		AutoPtr<Iterator> pIterator(
			new Iterator_Flatten(pIteratorSrc.release(), Iterator_Flatten::MODE_DepthFirstSearch));
		Value valueEach;
		if (indexer.HasGenerator()) {
			if (!indexer.IsEmptyGenerator()) {
				do {
					T_Elem *pElemDst = pElemTgt + indexer.GenerateOffset();
					for (size_t i = 0; i < nElemsUnit; i++, pElemDst++) {
						if (!pIterator->Next(env, valueEach) ||
							!ArrayT<T_Elem>::StoreValueAt(env, pElemDst, valueEach)) return;
					}
				} while (indexer.NextGenerator());
			}
		} else {
			T_Elem *pElemDst = pElemTgt;
			for (size_t i = 0; i < nElemsUnit; i++, pElemDst++) {
				if (!pIterator->Next(env, valueEach) ||
					!ArrayT<T_Elem>::StoreValueAt(env, pElemDst, valueEach)) return;
			}
		}
	} else if (value.IsInstanceOf(VTYPE_array)) {
		Array *pArraySrc = Object_array::GetObject(value)->GetArray();
		if (indexer.HasGenerator()) {
			if (!indexer.IsEmptyGenerator()) {
				char *pElemSrc = pArraySrc->GetPointerRaw();
				size_t nElemsSrc = pArraySrc->GetElemNum();
				size_t elemBytesSrc = pArraySrc->GetElemBytes();
				do {
					T_Elem *pElemDst = pElemTgt + indexer.GenerateOffset();
					size_t nElemsToCopy = ChooseMin(nElemsUnit, nElemsSrc);
					if (!Array::CopyElements(env, pElemDst, pArrayT->GetElemType(),
											 pElemSrc, pArraySrc->GetElemType(), nElemsToCopy)) return;
					nElemsSrc -= nElemsToCopy;
					if (nElemsSrc == 0) {
						pElemSrc = pArraySrc->GetPointerRaw();
						nElemsSrc = pArraySrc->GetElemNum();
					} else {
						pElemSrc += nElemsToCopy * elemBytesSrc;
					}
				} while (indexer.NextGenerator());
			}
		} else {
			T_Elem *pElemDst = pElemTgt;
			char *pElemSrc = pArraySrc->GetPointerRaw();
			size_t nElemsSrc = pArraySrc->GetElemNum();
			size_t nElemsToCopy = ChooseMin(nElemsUnit, nElemsSrc);
			if (!Array::CopyElements(env, pElemDst, pArrayT->GetElemType(),
									 pElemSrc, pArraySrc->GetElemType(), nElemsToCopy)) return;
		}
	} else {
		Array::SetError_UnacceptableValueAsElement(env, value);
	}
}

void Object_array::EvalIndexSet(Environment &env, const ValueList &valListIdx, const Value &value)
{
	static const EvalIndexSetT evalIndexSetTbl[] = {
		nullptr,
		&EvalIndexSetTmpl<Boolean>,
		&EvalIndexSetTmpl<Int8>,
		&EvalIndexSetTmpl<UInt8>,
		&EvalIndexSetTmpl<Int16>,
		&EvalIndexSetTmpl<UInt16>,
		&EvalIndexSetTmpl<Int32>,
		&EvalIndexSetTmpl<UInt32>,
		&EvalIndexSetTmpl<Int64>,
		&EvalIndexSetTmpl<UInt64>,
		&EvalIndexSetTmpl<Half>,
		&EvalIndexSetTmpl<Float>,
		&EvalIndexSetTmpl<Double>,
		&EvalIndexSetTmpl<Complex>,
		//&EvalIndexSetTmpl<Value>,
	};
	(*evalIndexSetTbl[GetArray()->GetElemType()])(env, valListIdx, value, this);
}

Iterator *Object_array::CreateIterator(Signal &sig)
{
	const bool flatFlag = false;
	return GetArray()->CreateIteratorEach(flatFlag);
}

//-----------------------------------------------------------------------------
// Object_array::PointerEx
//-----------------------------------------------------------------------------
Object_array::PointerEx::PointerEx(size_t offset, Object_array *pObjArray) :
	Pointer(offset), _pObjArray(pObjArray)
{
}

Object_array::PointerEx::PointerEx(const PointerEx &ptr) :
	Pointer(ptr), _pObjArray(dynamic_cast<Object_array *>(ptr._pObjArray->Reference()))
{
}

bool Object_array::PointerEx::StorePrepare(Signal &sig, size_t bytes)
{
	Memory &memory = GetMemory();
	if (_offset + bytes <= memory.GetSize()) return true;
	sig.SetError(ERR_OutOfRangeError, "pointer exceeds the range of memory");
	return false;
}

void Object_array::PointerEx::StoreBuffer(const void *buff, size_t bytes)
{
	Memory &memory = GetMemory();
	if (_offset >= memory.GetSize()) return;
	size_t bytesToCopy = ChooseMin(memory.GetSize() - _offset, bytes);
	if (buff != nullptr) ::memcpy(memory.GetPointer(_offset), buff, bytesToCopy);
	_offset += bytesToCopy;
}

const UChar *Object_array::PointerEx::ExtractPrepare(
	Signal &sig, size_t bytes, bool exceedErrorFlag)
{
	Memory &memory = GetMemory();
	if (_offset + bytes <= memory.GetSize()) {
		const UChar *p = reinterpret_cast<const UChar *>(memory.GetPointer(_offset));
		_offset += bytes;
		return p;
	}
	if (exceedErrorFlag) {
		sig.SetError(ERR_OutOfRangeError, "pointer exceeds the range of memory");
	}
	return nullptr;
}

Pointer *Object_array::PointerEx::Clone() const
{
	return new PointerEx(*this);
}

Object *Object_array::PointerEx::GetTarget() const
{
	return _pObjArray.get();
}

const UChar *Object_array::PointerEx::GetPointerC() const
{
	return reinterpret_cast<const UChar *>(GetMemory().GetPointer(_offset));
}

UChar *Object_array::PointerEx::GetWritablePointerC() const
{
	return reinterpret_cast<UChar *>(GetMemory().GetPointer(_offset));
}

size_t Object_array::PointerEx::GetEntireSize() const
{
	return GetMemory().GetSize();
}

bool Object_array::PointerEx::IsWritable() const
{
	return true;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// array#elembytes
Gura_DeclareProperty_R(array, elembytes)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Returns the size of each element in bytes.");
}

Gura_ImplementPropertyGetter(array, elembytes)
{
	Array *pArray = Object_array::GetObject(valueThis)->GetArray();
	return Value(pArray->GetElemBytes());
}

// array#elemtype
Gura_DeclareProperty_R(array, elemtype)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"Returns the type name of the elements as a `symbol` including:\n"
		"`` `boolean``,\n"
		"`` `int8``,\n"
		"`` `uint8``,\n"
		"`` `int16``,\n"
		"`` `uint16``,\n"
		"`` `int32``,\n"
		"`` `uint32``,\n"
		"`` `int64``,\n"
		"`` `uint64``,\n"
		"`` `half``,\n"
		"`` `float``,\n"
		"`` `double`` and\n"
		"`` `complex``.");
}

Gura_ImplementPropertyGetter(array, elemtype)
{
	Array *pArray = Object_array::GetObject(valueThis)->GetArray();
	return Value(Symbol::Add(pArray->GetElemTypeName()));
}

// array#major
Gura_DeclareProperty_R(array, major)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"Returns the major-mode in symbols `` `row`` or `` `column``.");
}

Gura_ImplementPropertyGetter(array, major)
{
	Array *pArray = Object_array::GetObject(valueThis)->GetArray();
	return Value(pArray->IsColMajor()? Gura_Symbol(column) : Gura_Symbol(row));
}

// array#memoryid
Gura_DeclareProperty_R(array, memoryid)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		"Returns the id of memory.");
}

Gura_ImplementPropertyGetter(array, memoryid)
{
	Array *pArray = Object_array::GetObject(valueThis)->GetArray();
	return Value(pArray->GetMemory().MakeId());
}

// array#ndim
Gura_DeclareProperty_R(array, ndim)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Returns the number of dimensions.");
}

Gura_ImplementPropertyGetter(array, ndim)
{
	Array *pArray = Object_array::GetObject(valueThis)->GetArray();
	return Value(pArray->GetDimensions().size());
}

// array#p
Gura_DeclareProperty_R(array, p)
{
	SetPropAttr(VTYPE_pointer);
	AddHelp(
		Gura_Symbol(en),
		"Returns the pointer through which you can inspect and modify the content of the array\n"
		"as a binary data.");
}

Gura_ImplementPropertyGetter(array, p)
{
	Object_array *pObj = Object_array::GetObject(valueThis);
	Pointer *pPointer = new Object_array::PointerEx(0, pObj->Reference());
	return Value(new Object_pointer(env, pPointer));
}

// array#shape
Gura_DeclareProperty_R(array, shape)
{
	SetPropAttr(VTYPE_number, FLAG_ListVar);
	AddHelp(
		Gura_Symbol(en),
		"Returns a list of sizes of each dimension.");
}

Gura_ImplementPropertyGetter(array, shape)
{
	Array *pArray = Object_array::GetObject(valueThis)->GetArray();
	Value value;
	Object_list *pObjList = value.InitAsList(env);
	Array::Dimensions &dims = pArray->GetDimensions();
	pObjList->Reserve(dims.size());
	foreach_const (Array::Dimensions, pDim, dims) {
		pObjList->AddFast(Value(pDim->GetSize()));
	}
	pObjList->SetValueType(VTYPE_number);
	return value;
}

// array#size
Gura_DeclareProperty_R(array, size)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"Returns the total number of elements.");
}

Gura_ImplementPropertyGetter(array, size)
{
	Array *pArray = Object_array::GetObject(valueThis)->GetArray();
	return Value(pArray->GetElemNum());
}

// array#T
Gura_DeclareProperty_R(array, T)
{
	SetPropAttr(VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		"Return an array with its row and column being tranposed."
		);
}

Gura_ImplementPropertyGetter(array, T)
{
	Array *pArray = Object_array::GetObject(valueThis)->GetArray();
	AutoPtr<Array> pArrayRtn;
	pArray->Transpose2d(pArrayRtn);
	return Array::ToValue(env, pArrayRtn.release());
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// array(src?, elemtype?:symbol) {block?}
Gura_DeclareFunction(array)
{
	SetFuncAttr(VTYPE_array_at_double, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "src", VTYPE_any, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_array));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` instance that contains `double` type of elements\n"
		"from a `list` or an `iterator` specified as an argument `src`\n"
		"or from elements described in the block.\n"
		"The followings are examples to create an `array` instance:\n"
		"\n"
		"    array([[0, 1, 2], [3, 4, 5]])\n"
		"    array {{0, 1, 2}, {3, 4, 5}}\n"
		"\n"
		"Specifying the argument `elemtype` would create an array of element type other than `double`.\n"
		"The following examples create an `array` instance of `int32` elements:\n"
		"\n"
		"    array([[0, 1, 2], [3, 4, 5]], elemtype => `int32)\n"
		"    array(elemtype => `int32) {{0, 1, 2}, {3, 4, 5}}\n"
		"\n"
		"Available element types are:\n"
		"\n"
		"    `int8, `uint8, `int16, `uint16, `int32, `uint32, `int64, `uint64\n"
		"    `half, `float, `double, `complex\n"
		"\n"
		"Functions named `array@T` where `T` gets an element type name are also provided\n"
		"to create an `array` instance of a specific type more easily.\n"
		"Using these functions could simplify the code above like this:"
		"\n"
		"    array@int32 ([[0, 1, 2], [3, 4, 5]])\n"
		"    array@int32 {{0, 1, 2}, {3, 4, 5}}\n");
}

Gura_ImplementFunction(array)
{
	static const ConstructorT constructorTbl[] = {
		nullptr,
		&Object_arrayT<Boolean>::Constructor,
		&Object_arrayT<Int8>::Constructor,
		&Object_arrayT<UInt8>::Constructor,
		&Object_arrayT<Int16>::Constructor,
		&Object_arrayT<UInt16>::Constructor,
		&Object_arrayT<Int32>::Constructor,
		&Object_arrayT<UInt32>::Constructor,
		&Object_arrayT<Int64>::Constructor,
		&Object_arrayT<UInt64>::Constructor,
		&Object_arrayT<Half>::Constructor,
		&Object_arrayT<Float>::Constructor,
		&Object_arrayT<Double>::Constructor,
		&Object_arrayT<Complex>::Constructor,
		//&Object_arrayT<Value>::Constructor,
	};
	Array::ElemType elemType = arg.IsValid(1)?
		Array::SymbolToElemType(env, arg.GetSymbol(1)) : Array::ETYPE_Double;
	if (env.IsSignalled()) return Value::Nil;
	return (*constructorTbl[elemType])(env, arg);
}

// @@ {block?}
Gura_DeclareFunctionAlias(at_at, "@@")
{
	SetFuncAttr(VTYPE_array_at_double, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array@double` instance that contains elements described in the block.\n"
		"The example below creates an array with a dimension of 2 rows and 3 columns:\n"
		"\n"
		"    @@{{0, 1, 2}, {3, 4, 5}}\n");
}

Gura_ImplementFunction(at_at)
{
	AutoPtr<ArrayT<Double> > pArrayT(ArrayT<Double>::CreateFromExpr(env, arg.GetBlockCooked(env)));
	if (pArrayT.IsNull()) return Value::Nil;
	return Array::ToValue(env, pArrayT.release());
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// array#argmax(axis?:number):[last_index] {block?}
Gura_DeclareMethod(array, argmax)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(last_index));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns index of a maximum number of elements in the target `array`.\n");
}

Gura_ImplementMethod(array, argmax)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	ssize_t axis = arg.IsValid(0)? arg.GetSizeT(0) : -1;
	bool lastFlag = arg.IsSet(Gura_Symbol(last_index));
	if (!pArraySelf->FindMaxIndex(env, pArrayRtn, axis, lastFlag)) return Value::Nil;
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#argmin(axis?:number):[last_index] {block?}
Gura_DeclareMethod(array, argmin)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(last_index));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns index of a minimum number of elements in the target `array`.\n");
}

Gura_ImplementMethod(array, argmin)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	ssize_t axis = arg.IsValid(0)? arg.GetSizeT(0) : -1;
	bool lastFlag = arg.IsSet(Gura_Symbol(last_index));
	if (!pArraySelf->FindMinIndex(env, pArrayRtn, axis, lastFlag)) return Value::Nil;
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

#if 0
// array#colmajor() {block?}
Gura_DeclareMethod(array, colmajor)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an array with column-major flag turned on.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, colmajor)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	if (pArraySelf->GetDimensions().size() != 1) {
		env.SetError(ERR_ValueError, "unable to turn on column-major flag of a multi-dimensional array");
		return Value::Nil;
	}
	AutoPtr<Array> pArrayRtn(pArraySelf->Clone());
	pArrayRtn->SetColMajor();
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}
#endif

// array.dot(a:array, b:array):static:map {block?}
Gura_DeclareClassMethod(array, dot)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "a", VTYPE_array);
	DeclareArg(env, "b", VTYPE_array);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a dot product between two arrays that have one or two dimensions.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementClassMethod(array, dot)
{
	Value valResult = Array::ApplyBinaryFuncOnValue_array_array(
		env, Array::binaryFuncPack_Dot, arg.GetValue(0), arg.GetValue(1));
	if (env.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, valResult);
}

// array#dump():void
Gura_DeclareMethod(array, dump)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(upper));
	AddHelp(
		Gura_Symbol(en),
		"Prints out a binary dump of the array's content.\n"
		);
}

Gura_ImplementMethod(array, dump)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	bool upperFlag = arg.IsSet(Gura_Symbol(upper));
	Stream *pStream = arg.IsValid(0)? &Object_stream::GetObject(arg, 0)->GetStream() : env.GetConsole();
	pArraySelf->Dump(env, *pStream, upperFlag);
	return Value::Nil;
}

// array#each():[flat] {block?}
Gura_DeclareMethod(array, each)
{
	SetFuncAttr(VTYPE_iterator, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(flat));
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that iterates each element in the array.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en()
		"\n"
		"The block parameter is `|elem:number, idx:number|`\n"
		"where `elem` is the element value.\n"
		);
}

Gura_ImplementMethod(array, each)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Iterator> pIterator(pArraySelf->CreateIteratorEach(arg.IsSet(Gura_Symbol(flat))));
	return ReturnIterator(env, arg, pIterator.release());
}

// array#elemcast(elemtype:symbol) {block?}
Gura_DeclareMethod(array, elemcast)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "elemtype", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Cast value type of contained elements.\n"
		"\n"
		"Available symbols for `elemtype` are as follows:\n"
		"\n"
		"- `` `boolean``\n"
		"- `` `int8``\n"
		"- `` `uint8``\n"
		"- `` `int16``\n"
		"- `` `uint16``\n"
		"- `` `int32``\n"
		"- `` `uint32``\n"
		"- `` `int64``\n"
		"- `` `uint64``\n"
		"- `` `half``\n"
		"- `` `float``\n"
		"- `` `double``\n"
		"- `` `complex``\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, elemcast)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	Array::ElemType elemType = Array::SymbolToElemType(env, arg.GetSymbol(0));
	if (env.IsSignalled()) return Value::Nil;
	Value value;
	if (pArraySelf->GetElemType() == elemType) {
		value = Value(new Object_array(env, pArraySelf->Clone()));
	} else {
		AutoPtr<Array> pArrayDst(Array::Create(elemType));
		pArrayDst->SetDimensions(pArraySelf->GetDimensions());
		pArrayDst->AllocMemory();
		if (!Array::CopyElements(env, pArrayDst.get(), pArraySelf)) return Value::Nil;
		value = Value(new Object_array(env, pArrayDst.release()));
	}
	return ReturnValue(env, arg, value);
}

// array#expand_kernelvec1d(size:number, strides:number, size_pad:number, channel_pos?:symbol, padnum?:number) {block?}
Gura_DeclareMethod(array, expand_kernelvec1d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size_pad", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "padnum", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementMethod(array, expand_kernelvec1d)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	size_t sizeKernel = arg.GetSizeT(0);
	size_t stridesKernel = arg.GetSizeT(1);
	size_t sizePad = arg.GetSizeT(2);
	Array::ChannelPos channelPos = Array::CHANNELPOS_First;
	if (arg.IsValid(3) &&
		(channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3))) == Array::CHANNELPOS_None) return Value::Nil;
	Double padNum = arg.IsValid(4)? arg.GetDouble(4) : 0;
	pArraySelf->ExpandKernelVec1d(pArrayRtn, sizeKernel, stridesKernel, sizePad, channelPos, padNum);
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#expand_kernelvec2d(size[]:number, strides[]:number, size_pad[]:number, channel_pos?:symbol, padnum?:number) {block?}
Gura_DeclareMethod(array, expand_kernelvec2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "size_pad", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "padnum", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementMethod(array, expand_kernelvec2d)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	Value value1, value2;
	if (!arg.GetListValues(0, &value1, &value2)) {
		env.SetError(ERR_ValueError, "argument 'size' must have two elements");
		return Value::Nil;
	}
	size_t sizeKernelRow = value1.GetSizeT();
	size_t sizeKernelCol = value2.GetSizeT();
	if (!arg.GetListValues(1, &value1, &value2)) {
		env.SetError(ERR_ValueError, "argument 'strides' must have two elements");
		return Value::Nil;
	}
	size_t stridesKernelRow = value1.GetSizeT();
	size_t stridesKernelCol = value2.GetSizeT();
	if (!arg.GetListValues(2, &value1, &value2)) {
		env.SetError(ERR_ValueError, "argument 'size_pad' must have two elements");
		return Value::Nil;
	}
	size_t sizePadRow = value1.GetSizeT();
	size_t sizePadCol = value2.GetSizeT();
	Array::ChannelPos channelPos = Array::CHANNELPOS_First;
	if (arg.IsValid(3) &&
		(channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3))) == Array::CHANNELPOS_None) return Value::Nil;
	Double padNum = arg.IsValid(4)? arg.GetDouble(4) : 0;
	pArraySelf->ExpandKernelVec2d(pArrayRtn, sizeKernelRow, sizeKernelCol,
								  stridesKernelRow, stridesKernelCol, sizePadRow, sizePadCol,
								  channelPos, padNum);
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#expand_kernelvec3d(size[]:number, strides[]:number, size_pad[]:number, channel_pos?:symbol, padnum?:number) {block?}
Gura_DeclareMethod(array, expand_kernelvec3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "size_pad", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "padnum", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementMethod(array, expand_kernelvec3d)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	Value value1, value2, value3;
	if (!arg.GetListValues(0, &value1, &value2, &value3)) {
		env.SetError(ERR_ValueError, "argument 'size' must have three elements");
		return Value::Nil;
	}
	size_t sizeKernelPlane = value1.GetSizeT();
	size_t sizeKernelRow = value2.GetSizeT();
	size_t sizeKernelCol = value3.GetSizeT();
	if (!arg.GetListValues(1, &value1, &value2, &value3)) {
		env.SetError(ERR_ValueError, "argument 'strides' must have three elements");
		return Value::Nil;
	}
	size_t stridesKernelPlane = value1.GetSizeT();
	size_t stridesKernelRow = value2.GetSizeT();
	size_t stridesKernelCol = value3.GetSizeT();
	if (!arg.GetListValues(2, &value1, &value2, &value3)) {
		env.SetError(ERR_ValueError, "argument 'size_pad' must have three elements");
		return Value::Nil;
	}
	size_t sizePadPlane = value1.GetSizeT();
	size_t sizePadRow = value2.GetSizeT();
	size_t sizePadCol = value3.GetSizeT();
	Array::ChannelPos channelPos = Array::CHANNELPOS_First;
	if (arg.IsValid(3) &&
		(channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(3))) == Array::CHANNELPOS_None) return Value::Nil;
	Double padNum = arg.IsValid(4)? arg.GetDouble(4) : 0;
	pArraySelf->ExpandKernelVec3d(pArrayRtn, sizeKernelPlane, sizeKernelRow, sizeKernelCol,
								  stridesKernelPlane, stridesKernelRow, stridesKernelCol,
								  sizePadPlane, sizePadRow, sizePadCol,
								  channelPos, padNum);
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#fill(value:number):void
Gura_DeclareMethod(array, fill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Fills array with a specified value.\n"
		);
}

Gura_ImplementMethod(array, fill)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	if (!pArraySelf->PrepareModification(env)) return Value::Nil;
	pArraySelf->Fill(arg.GetDouble(0));
	return Value::Nil;
}

// array#flatten() {block?}
Gura_DeclareMethod(array, flatten)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has flattened elements in the target `array`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, flatten)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	pArraySelf->Flatten(pArrayRtn);
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

// array#head(n:number):map {block?}
Gura_DeclareMethod(array, head)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has extracted `n` elements from the beginning of the target `array`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, head)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	size_t n = arg.GetSizeT(0);
	AutoPtr<Array> pArrayRtn;
	if (!pArraySelf->Head(env, pArrayRtn, n)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

// array#invert(eps?:number) {block?}
Gura_DeclareMethod(array, invert)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "eps", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has elements of inverted matrix of the target `array`."
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, invert)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	Double epsilon = arg.IsValid(0)? arg.GetDouble(0) : 1.0e-6;
	AutoPtr<Array> pArrayRtn;
	if (!Array::ApplyInvertFunc(env, pArrayRtn, pArraySelf, epsilon)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

// array#iselemsame(array:array)
Gura_DeclareMethod(array, iselemsame)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "array", VTYPE_array);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target `array` instance has the same elements\n"
		"with the specified `array`.\n");
}

Gura_ImplementMethod(array, iselemsame)
{
	Array *pArray = Object_array::GetObjectThis(arg)->GetArray();
	Array *pArrayCmp = Object_array::GetObject(arg, 0)->GetArray();
	return Value(pArray->HasSameElements(*pArrayCmp));
}

// array#issquare()
Gura_DeclareMethod(array, issquare)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Returns `true` if the target `array` consists square matrices.");
}

Gura_ImplementMethod(array, issquare)
{
	Array *pArray = Object_array::GetObjectThis(arg)->GetArray();
	return Value(pArray->IsSquare());
}

// array#max(axis?:number):[index,last_index] {block?}
Gura_DeclareMethod(array, max)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Finds a maximum number of elements in the target `array`.\n");
}

Gura_ImplementMethod(array, max)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	ssize_t axis = arg.IsValid(0)? arg.GetSizeT(0) : -1;
	bool lastFlag = arg.IsSet(Gura_Symbol(last_index));
	bool indexFlag = lastFlag || arg.IsSet(Gura_Symbol(index));
	if (indexFlag) {
		if (!pArraySelf->FindMaxIndex(env, pArrayRtn, axis, lastFlag)) return Value::Nil;
	} else {
		if (!pArraySelf->FindMax(env, pArrayRtn, axis)) return Value::Nil;
	}
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#mean(axis?:number) {block?}
Gura_DeclareMethod(array, mean)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates an mean value of elements in the array.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, mean)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	ssize_t axis = arg.IsValid(0)? arg.GetSizeT(0) : -1;
	if (!pArraySelf->CalcSum(env, pArrayRtn, axis, true)) return Value::Nil;
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#min(axis?:number):[index,last_index] {block?}
Gura_DeclareMethod(array, min)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(index));
	DeclareAttr(Gura_Symbol(last_index));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Finds a minimum number of elements in the target `array`.\n");
}

Gura_ImplementMethod(array, min)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	ssize_t axis = arg.IsValid(0)? arg.GetSizeT(0) : -1;
	bool lastFlag = arg.IsSet(Gura_Symbol(last_index));
	bool indexFlag = lastFlag || arg.IsSet(Gura_Symbol(index));
	if (indexFlag) {
		if (!pArraySelf->FindMinIndex(env, pArrayRtn, axis, lastFlag)) return Value::Nil;
	} else {
		if (!pArraySelf->FindMin(env, pArrayRtn, axis)) return Value::Nil;
	}
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#offset(n:number):map {block?}
Gura_DeclareMethod(array, offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has extracted elements of the target `array` after skipping its first `n` elements.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, offset)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	size_t n = arg.GetSizeT(0);
	AutoPtr<Array> pArrayRtn;
	if (!pArraySelf->Offset(env, pArrayRtn, n)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

// array#paste(offset:number, src:array):map:void
Gura_DeclareMethod(array, paste)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "offset", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "src", VTYPE_array, OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Pastes elements of `src` into the target `array` instance.\n"
		"\n"
		"The argument `offset` specifies the posision where elements are pasted in\n"
		);
}

Gura_ImplementMethod(array, paste)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	size_t offset = arg.GetSizeT(0);
	const Array *pArraySrc = Object_array::GetObject(arg, 1)->GetArray();
	if (!pArraySelf->PrepareModification(env)) return Value::Nil;
	pArraySelf->Paste(env, offset, pArraySrc);
	return Value::Nil;
}

// array#reshape(dims[]:number:nil) {block?}
Gura_DeclareMethod(array, reshape)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dims", VTYPE_number, OCCUR_Once, FLAG_ListVar | FLAG_Nil);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has reshaped the target `array` according to a list of\n"
		"dimension size specified by `dims`.\n"
		"\n"
		"Below are examples:\n"
		"\n"
		"    x = array(1..24)\n"
		"    a = x.reshape([6, 4])    // a is an array of 6x4.\n"
		"    b = x.reshape([2, 3, 4]) // b is an array of 2x3x4.\n"
		"\n"
		"A value of `nil` in the list of dimension means it would be calculated from the whole size\n"
		"and other dimension sizes. Only one `nil` is allowed to exist.\n"
		"\n"
		"    x = array(1..24)\n"
		"    b = x.reshape([2, nil, 4]) // b is an array of 2x3x4.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, reshape)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	if (!pArraySelf->Reshape(env, pArrayRtn, arg.GetList(0))) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

// array#restore_kernelvec1d(size_out:number, size:number, strides:number,
//                           size_pad:number, channel_pos?:symbol) {block?}
Gura_DeclareMethod(array, restore_kernelvec1d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size_out", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "size_pad", VTYPE_number, OCCUR_Once);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementMethod(array, restore_kernelvec1d)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	size_t sizeOut = arg.GetSizeT(0);
	size_t sizeKernel = arg.GetSizeT(1);
	size_t stridesKernel = arg.GetSizeT(2);
	size_t sizePad = arg.GetSizeT(3);
	Array::ChannelPos channelPos = Array::CHANNELPOS_First;
	if (arg.IsValid(4) &&
		(channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(4))) == Array::CHANNELPOS_None) return Value::Nil;
	pArraySelf->RestoreKernelVec1d(pArrayRtn, sizeOut, sizeKernel, stridesKernel, sizePad, channelPos);
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#restore_kernelvec2d(size_out[]:number, size[]:number, strides[]:number,
//                           size_pad[]:number, channel_pos?:symbol) {block?}
Gura_DeclareMethod(array, restore_kernelvec2d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size_out", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "size_pad", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementMethod(array, restore_kernelvec2d)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	Value value1, value2;
	if (!arg.GetListValues(0, &value1, &value2)) {
		env.SetError(ERR_ValueError, "argument 'size_out' must have two elements");
		return Value::Nil;
	}
	size_t sizeOutRow = value1.GetSizeT();
	size_t sizeOutCol = value2.GetSizeT();
	if (!arg.GetListValues(1, &value1, &value2)) {
		env.SetError(ERR_ValueError, "argument 'size' must have two elements");
		return Value::Nil;
	}
	size_t sizeKernelRow = value1.GetSizeT();
	size_t sizeKernelCol = value2.GetSizeT();
	if (!arg.GetListValues(2, &value1, &value2)) {
		env.SetError(ERR_ValueError, "argument 'strides' must have two elements");
		return Value::Nil;
	}
	size_t stridesKernelRow = value1.GetSizeT();
	size_t stridesKernelCol = value2.GetSizeT();
	if (!arg.GetListValues(3, &value1, &value2)) {
		env.SetError(ERR_ValueError, "argument 'size_pad' must have two elements");
		return Value::Nil;
	}
	size_t sizePadRow = value1.GetSizeT();
	size_t sizePadCol = value2.GetSizeT();
	Array::ChannelPos channelPos = Array::CHANNELPOS_First;
	if (arg.IsValid(4) &&
		(channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(4))) == Array::CHANNELPOS_None) return Value::Nil;
	pArraySelf->RestoreKernelVec2d(pArrayRtn, sizeOutRow, sizeOutCol, sizeKernelRow, sizeKernelCol,
								  stridesKernelRow, stridesKernelCol, sizePadRow, sizePadCol,
								  channelPos);
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#restore_kernelvec3d(size_out[]:number, size[]:number, strides[]:number,
//                           size_pad[]:number, channel_pos?:symbol) {block?}
Gura_DeclareMethod(array, restore_kernelvec3d)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "size_out", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "size", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "strides", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "size_pad", VTYPE_number, OCCUR_Once, FLAG_ListVar);
	DeclareArg(env, "channel_pos", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementMethod(array, restore_kernelvec3d)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	Value value1, value2, value3;
	if (!arg.GetListValues(0, &value1, &value2, &value3)) {
		env.SetError(ERR_ValueError, "argument 'size_out' must have three elements");
		return Value::Nil;
	}
	size_t sizeOutPlane = value1.GetSizeT();
	size_t sizeOutRow = value2.GetSizeT();
	size_t sizeOutCol = value3.GetSizeT();
	if (!arg.GetListValues(1, &value1, &value2, &value3)) {
		env.SetError(ERR_ValueError, "argument 'size' must have three elements");
		return Value::Nil;
	}
	size_t sizeKernelPlane = value1.GetSizeT();
	size_t sizeKernelRow = value2.GetSizeT();
	size_t sizeKernelCol = value3.GetSizeT();
	if (!arg.GetListValues(2, &value1, &value2, &value3)) {
		env.SetError(ERR_ValueError, "argument 'strides' must have three elements");
		return Value::Nil;
	}
	size_t stridesKernelPlane = value1.GetSizeT();
	size_t stridesKernelRow = value2.GetSizeT();
	size_t stridesKernelCol = value3.GetSizeT();
	if (!arg.GetListValues(3, &value1, &value2, &value3)) {
		env.SetError(ERR_ValueError, "argument 'sizepad' must have three elements");
		return Value::Nil;
	}
	size_t sizePadPlane = value1.GetSizeT();
	size_t sizePadRow = value2.GetSizeT();
	size_t sizePadCol = value3.GetSizeT();
	Array::ChannelPos channelPos = Array::CHANNELPOS_First;
	if (arg.IsValid(4) &&
		(channelPos = Array::SymbolToChannelPos(env, arg.GetSymbol(4))) == Array::CHANNELPOS_None) return Value::Nil;
	pArraySelf->RestoreKernelVec3d(pArrayRtn, sizeOutPlane, sizeOutRow, sizeOutCol,
								   sizeKernelPlane, sizeKernelRow, sizeKernelCol,
								   stridesKernelPlane, stridesKernelRow, stridesKernelCol,
								   sizePadPlane, sizePadRow, sizePadCol, channelPos);
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#roundoff(threshold?:number) {block?}
Gura_DeclareMethod(array, roundoff)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "threshold", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has rounded off elements less than `threshold` to zero in the target `array`.\n"
		"The default value for `threshold` is `1.0e-6` when omitted.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, roundoff)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	double threshold = arg.IsValid(0)? arg.GetDouble(0) : 1.e-6;
	AutoPtr<Array> pArrayRtn;
	pArraySelf->RoundOff(pArrayRtn, threshold);
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

// array#std(axis?:number):[p] {block?}
Gura_DeclareMethod(array, std)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(p));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a standard deviation value of elements in the target `array`.\n"
		"\n"
		"In default, it calculates an unbiased estimation of standard deviation\n"
		"in which the summation of squared deviations is divided by `(n - 1)`.\n"
		"Specifying `:p` attributes will calculate a population variance that divides\n"
		"that summation by `n`.\n");
}

Gura_ImplementMethod(array, std)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	bool populationFlag = arg.IsSet(Gura_Symbol(p));
	AutoPtr<Array> pArrayRtn;
	ssize_t axis = arg.IsValid(0)? arg.GetSizeT(0) : -1;
	if (!pArraySelf->CalcVar(env, pArrayRtn, axis, populationFlag, true)) return Value::Nil;
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#sum(axis?:number) {block?}
Gura_DeclareMethod(array, sum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a summation value of elements in the target `array`.\n");
}

Gura_ImplementMethod(array, sum)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	ssize_t axis = arg.IsValid(0)? arg.GetSizeT(0) : -1;
	if (!pArraySelf->CalcSum(env, pArrayRtn, axis, false)) return Value::Nil;
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

// array#tail(n:number):map {block?}
Gura_DeclareMethod(array, tail)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns an `array` instance as a result that\n"
		"has extracted `n` elements from the bottom of the target `array`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, tail)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	size_t n = arg.GetSizeT(0);
	AutoPtr<Array> pArrayRtn;
	if (!pArraySelf->Tail(env, pArrayRtn, n)) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

// array#tolist() {block?}
Gura_DeclareMethod(array, tolist)
{
	SetFuncAttr(VTYPE_list, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Converts the array to list.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("list", "list"));
}

Gura_ImplementMethod(array, tolist)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	Value value;
	Object_list *pObjList = value.InitAsList(env);
	pArraySelf->CopyToList(pObjList);
	return ReturnValue(env, arg, value);
}

// array#transpose(axes[]?:number) {block?}
Gura_DeclareMethod(array, transpose)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "axes", VTYPE_number, OCCUR_ZeroOrOnce, FLAG_ListVar);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array instance that transposes axes of the original array\n"
		"according to the specified argument `axes`.\n"
		"\n"
		"If the argument is not specified, two axes at the lowest rank, which correspond to\n"
		"row and column for a matrix, would be transposed.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(array, transpose)
{
	const Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	AutoPtr<Array> pArrayRtn;
	if (arg.IsValid(0)) {
		if (!pArraySelf->Transpose(env, pArrayRtn, arg.GetList(0))) return Value::Nil;
	} else {
		pArraySelf->Transpose2d(pArrayRtn);
	}
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

// array#var(axis?:number):[p] {block?}
Gura_DeclareMethod(array, var)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "axis", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareAttr(Gura_Symbol(p));
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a variation value of elements in the target `array`.\n"
		"\n"
		"In default, it calculates an unbiased estimation of standard deviation\n"
		"in which the summation of squared deviations is divided by `(n - 1)`.\n"
		"Specifying `:p` attributes will calculate a population variance that divides\n"
		"that summation by `n`.\n");
}

Gura_ImplementMethod(array, var)
{
	Array *pArraySelf = Object_array::GetObjectThis(arg)->GetArray();
	bool populationFlag = arg.IsSet(Gura_Symbol(p));
	AutoPtr<Array> pArrayRtn;
	ssize_t axis = arg.IsValid(0)? arg.GetSizeT(0) : -1;
	if (!pArraySelf->CalcVar(env, pArrayRtn, axis, populationFlag, false)) return Value::Nil;
	return ReturnValue(env, arg, Array::ToValue(env, pArrayRtn.release()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_array::Class_array(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_array)
{
}

void Class_array::DoPrepare(Environment &env)
{
	// Assignment of properties
	Gura_AssignProperty(array, elembytes);
	Gura_AssignProperty(array, elemtype);
	Gura_AssignProperty(array, major);
	Gura_AssignProperty(array, memoryid);
	Gura_AssignProperty(array, ndim);
	Gura_AssignProperty(array, p);
	Gura_AssignProperty(array, shape);
	Gura_AssignProperty(array, size);
	Gura_AssignProperty(array, T);
	// Assignment of function
	Gura_AssignFunction(array);
	Gura_AssignFunction(at_at);
	// Assignment of method
	Gura_AssignMethod(array, argmax);
	Gura_AssignMethod(array, argmin);
	//Gura_AssignMethod(array, colmajor);
	Gura_AssignMethod(array, dot);
	Gura_AssignMethod(array, dump);
	Gura_AssignMethod(array, each);
	Gura_AssignMethod(array, elemcast);
	Gura_AssignMethod(array, expand_kernelvec1d);
	Gura_AssignMethod(array, expand_kernelvec2d);
	Gura_AssignMethod(array, expand_kernelvec3d);
	Gura_AssignMethod(array, fill);
	Gura_AssignMethod(array, flatten);
	Gura_AssignMethod(array, head);
	Gura_AssignMethod(array, invert);
	Gura_AssignMethod(array, iselemsame);
	Gura_AssignMethod(array, issquare);
	Gura_AssignMethod(array, max);
	Gura_AssignMethod(array, mean);
	Gura_AssignMethod(array, min);
	Gura_AssignMethod(array, offset);
	Gura_AssignMethod(array, paste);
	Gura_AssignMethod(array, reshape);
	Gura_AssignMethod(array, restore_kernelvec1d);
	Gura_AssignMethod(array, restore_kernelvec2d);
	Gura_AssignMethod(array, restore_kernelvec3d);
	Gura_AssignMethod(array, roundoff);
	Gura_AssignMethod(array, std);
	Gura_AssignMethod(array, sum);
	Gura_AssignMethod(array, tail);
	Gura_AssignMethod(array, tolist);
	Gura_AssignMethod(array, transpose);
	Gura_AssignMethod(array, var);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

Class::SerializeFmtVer Class_array::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool Class_array::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	const Array *pArray = Object_array::GetObject(value)->GetArray();
	return pArray->Serialize(env, stream);
}

bool Class_array::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
{
	if (serializeFmtVer == SerializeFmtVer_1) {
		AutoPtr<Array> pArray(Array::Deserialize(env, stream));
		if (pArray.IsNull()) return false;
		value = Array::ToValue(env, pArray.release());
		return true;
	}
	SetError_UnsupportedSerializeFmtVer(serializeFmtVer);
	return false;
}

bool Class_array::CastFrom(Environment &env, Value &value, ULong flags)
{
	return false;
}

bool Class_array::CastTo(Environment &env, Value &value, const Declaration &decl)
{
	const Array *pArray = Object_array::GetObject(value)->GetArray();
	if (decl.IsType(VTYPE_list)) {
		Value valueCasted;
		Object_list *pObjList = valueCasted.InitAsList(env);
		pArray->CopyToList(pObjList);
		value = valueCasted;
		return true;
	} else if (decl.IsType(VTYPE_iterator)) {
		const bool flatFlag = false;
		AutoPtr<Iterator> pIterator(pArray->CreateIteratorEach(flatFlag));
		value = Value(new Object_iterator(env, pIterator.release()));
		return true;
	} else if (decl.IsType(VTYPE_memory)) {
		value = Value(new Object_memory(env, pArray->GetMemory().Reference()));
		return true;
	}
	return false;
}

}
