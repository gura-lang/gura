//=============================================================================
// Gura class: array
//=============================================================================
#include "stdafx.h"

namespace Gura {

typedef Value (*ConstructorT)(Environment &env, Argument &arg);
typedef Value (*PropertyGetterT)(Environment &env, Array *pArraySelf);
typedef Value (*EvalIndexGetT)(Environment &env, const ValueList &valListIdx, Object_array *pObj);
typedef void (*EvalIndexSetT)(Environment &env, const ValueList &valListIdx, const Value &value, Object_array *pObj);
typedef Iterator *(*CreateIteratorT)(Array *pArray);
typedef bool (*CastToT)(Environment &env, Value &value, const Declaration &decl, const Array *pArraySelf);

static const char *helpDoc_en = R"**(

)**";

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Value CallPropertyGetter(Environment &env,
						 const PropertyGetterT propertyGetters[], Array *pArraySelf)
{
	PropertyGetterT pPropertyGetter = propertyGetters[pArraySelf->GetElemType()];
	if (pPropertyGetter == nullptr) {
		env.SetError(ERR_TypeError, "no property implemented");
		return Value::Nil;
	}
	return (*pPropertyGetter)(env, pArraySelf);
}

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
		AutoPtr<ArrayT<T_Elem> > pArrayTRtn(ArrayT<T_Elem>::Create(pArrayT->GetColMajorFlag(), dimsRtn));
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
		AutoPtr<ArrayT<T_Elem> > pArrayTRtn(new ArrayT<T_Elem>(pArrayT->GetColMajorFlag()));
		pArrayTRtn->SetMemory(pArrayT->GetMemory().Reference(),
							  pArrayT->GetOffsetBase() + indexer.GetOffsetTarget());
		Array::Dimensions dimsRtn;
		indexer.MakeResultDimensions(dimsRtn);
		pArrayTRtn->SetDimensions(dimsRtn);
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
			FillDouble(pArrayT->GetPointer(), pArrayT->GetElemNum(), value.GetDouble(), 1);
		} else if (complexFlag && value.Is_complex()) {
			FillComplex(pArrayT->GetPointer(), pArrayT->GetElemNum(), value.GetComplex(), 1);
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
					!StoreValueAt(env, pElemDst, valueEach)) return;
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
					FillDouble(pElemTgt + indexer.GenerateOffset(), nElemsUnit, num, stridesUnit);
				} while (indexer.NextGenerator());
			}
		} else {
			FillDouble(pElemTgt, nElemsUnit, num, stridesUnit);
		}
	} else if (complexFlag && value.Is_complex()) {
		const Complex &num = value.GetComplex();
		if (indexer.HasGenerator()) {
			if (!indexer.IsEmptyGenerator()) {
				do {
					FillComplex(pElemTgt + indexer.GenerateOffset(), nElemsUnit, num, stridesUnit);
				} while (indexer.NextGenerator());
			}
		} else {
			FillComplex(pElemTgt, nElemsUnit, num, stridesUnit);
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
							!StoreValueAt(env, pElemDst, valueEach)) return;
					}
				} while (indexer.NextGenerator());
			}
		} else {
			T_Elem *pElemDst = pElemTgt;
			for (size_t i = 0; i < nElemsUnit; i++, pElemDst++) {
				if (!pIterator->Next(env, valueEach) ||
					!StoreValueAt(env, pElemDst, valueEach)) return;
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

template<typename T_Elem>
Iterator *CreateIteratorTmpl(Array *pArray)
{
	bool flatFlag = true;
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArray);
	return new Iterator_ArrayT_Each<T_Elem>(pArrayT->Reference(), flatFlag);
}

Iterator *Object_array::CreateIterator(Signal &sig)
{
	static const CreateIteratorT createIteratorTbl[] = {
		nullptr,
		&CreateIteratorTmpl<Boolean>,
		&CreateIteratorTmpl<Int8>,
		&CreateIteratorTmpl<UInt8>,
		&CreateIteratorTmpl<Int16>,
		&CreateIteratorTmpl<UInt16>,
		&CreateIteratorTmpl<Int32>,
		&CreateIteratorTmpl<UInt32>,
		&CreateIteratorTmpl<Int64>,
		&CreateIteratorTmpl<UInt64>,
		&CreateIteratorTmpl<Half>,
		&CreateIteratorTmpl<Float>,
		&CreateIteratorTmpl<Double>,
		&CreateIteratorTmpl<Complex>,
		//&CreateIteratorTmpl<Value>,
	};
	return (*createIteratorTbl[GetArray()->GetElemType()])(GetArray());
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
	bool colMajorFlag = false;
	AutoPtr<ArrayT<Double> > pArrayT(ArrayT<Double>::CreateFromExpr(env, colMajorFlag, arg.GetBlockCooked(env)));
	if (pArrayT.IsNull()) return Value::Nil;
	return Array::ToValue(env, pArrayT.release());
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

template<typename T_Elem>
bool CastToTmpl(Environment &env, Value &value, const Declaration &decl, const Array *pArraySelf)
{
	if (decl.IsType(VTYPE_list)) {
		AutoPtr<ArrayT<T_Elem> > pArrayT(
			dynamic_cast<const ArrayT<T_Elem> *>(pArraySelf)->Reference());
		Object_list *pObjList = value.InitAsList(env);
		pArrayT->CopyToList(pObjList);
		return true;
	} else if (decl.IsType(VTYPE_iterator)) {
		AutoPtr<ArrayT<T_Elem> > pArrayT(
			dynamic_cast<const ArrayT<T_Elem> *>(pArraySelf)->Reference());
		AutoPtr<Iterator> pIterator(new Iterator_ArrayT_Each<T_Elem>(pArrayT.release(), false));
		value = Value(new Object_iterator(env, pIterator.release()));
		return true;
	} else if (decl.IsType(VTYPE_memory)) {
		value = Value(new Object_memory(env, pArraySelf->GetMemory().Reference()));
		return true;
	}
	return false;
}

bool Class_array::CastTo(Environment &env, Value &value, const Declaration &decl)
{
	const Array *pArray = Object_array::GetObject(value)->GetArray();
	static const CastToT castTos[] = {
		nullptr,
		&CastToTmpl<Boolean>,
		&CastToTmpl<Int8>,
		&CastToTmpl<UInt8>,
		&CastToTmpl<Int16>,
		&CastToTmpl<UInt16>,
		&CastToTmpl<Int32>,
		&CastToTmpl<UInt32>,
		&CastToTmpl<Int64>,
		&CastToTmpl<UInt64>,
		&CastToTmpl<Half>,
		&CastToTmpl<Float>,
		&CastToTmpl<Double>,
		&CastToTmpl<Complex>,
		//&CastToTmpl<Value>,
	};
	return (*castTos[pArray->GetElemType()])(env, value, decl, pArray);
}

}
