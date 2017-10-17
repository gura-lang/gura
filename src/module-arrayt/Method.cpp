//=============================================================================
// Method.cpp
// Implementation of methods for array class.
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(arrayt)

typedef Value (*FuncT_Method)(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf);

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Value CallMethod(Environment &env, Argument &arg, const FuncT_Method funcTbl[],
				 const Function *pFunc, Array *pArraySelf)
{
	FuncT_Method func = funcTbl[pArraySelf->GetElemType()];
	if (func == nullptr) {
		env.SetError(ERR_TypeError, "no method implemented");
		return Value::Nil;
	}
	return (*func)(env, arg, pFunc, pArraySelf);
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
	pArrayRtn->SetColMajorFlag(true);
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayRtn.release())));
}

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

template<typename T_Elem, typename T_ElemCast>
void DumpInteger(Signal &sig, Stream &stream, const char *fmt, size_t cols, const T_Elem *p, size_t n)
{
	size_t col = 0;
	for (size_t i = 0; i < n; i++, p++) {
		if (col != 0) {
			stream.Printf(sig, " ");
		}
		stream.Printf(sig, fmt, static_cast<T_ElemCast>(*p));
		col++;
		if (col == cols) {
			stream.Printf(sig, "\n");
			col = 0;
		}
	}
	if (col != 0) stream.Printf(sig, "\n");
}

template<typename T_Elem, typename T_ElemCast>
void DumpFloat(Signal &sig, Stream &stream, const char *fmt, size_t cols, const T_Elem *p, size_t n)
{
	size_t col = 0;
	for (size_t i = 0; i < n; i++, p++) {
		if (col != 0) {
			stream.Printf(sig, " ");
		}
		T_ElemCast num = *reinterpret_cast<const T_ElemCast *>(p);
		stream.Printf(sig, fmt, num);
		col++;
		if (col == cols) {
			stream.Printf(sig, "\n");
			col = 0;
		}
	}
	if (col != 0) stream.Printf(sig, "\n");
}

template<typename T_Elem>
void Dump(Signal &sig, Stream &stream, const ArrayT<T_Elem> *pArrayT, bool upperFlag) {}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Boolean> *pArrayT, bool upperFlag)
{
	DumpInteger<Boolean, UInt8>(sig, stream, upperFlag? "%02X" : "%02x",
								24, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Int8> *pArrayT, bool upperFlag)
{
	DumpInteger<Int8, UInt8>(sig, stream, upperFlag? "%02X" : "%02x",
							 24, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<UInt8> *pArrayT, bool upperFlag)
{
	DumpInteger<UInt8, UInt8>(sig, stream, upperFlag? "%02X" : "%02x",
							  24, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Int16> *pArrayT, bool upperFlag)
{
	DumpInteger<Int16, UInt16>(sig, stream, upperFlag? "%04X" : "%04x",
							   16, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<UInt16> *pArrayT, bool upperFlag)
{
	DumpInteger<UInt16, UInt16>(sig, stream, upperFlag? "%04X" : "%04x",
								16, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Int32> *pArrayT, bool upperFlag)
{
	DumpInteger<Int32, UInt32>(sig, stream, upperFlag? "%08X" : "%08x",
							   8, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<UInt32> *pArrayT, bool upperFlag)
{
	DumpInteger<UInt32, UInt32>(sig, stream, upperFlag? "%08X" : "%08x",
								8, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Int64> *pArrayT, bool upperFlag)
{
	DumpInteger<Int64, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx",
							   4, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<UInt64> *pArrayT, bool upperFlag)
{
	DumpInteger<UInt64, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx",
								4, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Half> *pArrayT, bool upperFlag)
{
	DumpFloat<Half, UInt16>(sig, stream, upperFlag? "%04X" : "%04x",
							16, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Float> *pArrayT, bool upperFlag)
{
	DumpFloat<Float, UInt32>(sig, stream, upperFlag? "%08lX" : "%08lx",
							 8, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Double> *pArrayT, bool upperFlag)
{
	DumpFloat<Double, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx",
							  4, pArrayT->GetPointer(), pArrayT->GetElemNum());
}

template<>
void Dump(Signal &sig, Stream &stream, const ArrayT<Complex> *pArrayT, bool upperFlag)
{
	DumpFloat<Complex, UInt64>(sig, stream, upperFlag? "%016llX" : "%016llx",
							   4, pArrayT->GetPointer(), pArrayT->GetElemNum() * 2);
}

template<typename T_Elem>
Value FuncTmpl_dump(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	bool upperFlag = arg.IsSet(Gura_Symbol(upper));
	Stream *pStream = arg.IsValid(0)?
		&Object_stream::GetObject(arg, 0)->GetStream() : env.GetConsole();
	Dump<T_Elem>(sig, *pStream, pArrayT, upperFlag);
	return Value::Nil;
}

Gura_ImplementMethod(array, dump)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_dump);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_each(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Iterator> pIterator(new Iterator_ArrayT_Each<T_Elem>(
									pArrayT->Reference(), arg.IsSet(Gura_Symbol(flat))));
	return pFunc->ReturnIterator(env, arg, pIterator.release());
}

Gura_ImplementMethod(array, each)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_each);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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
		bool colMajorFlag = false;
		AutoPtr<Array> pArrayDst(Array::Create(elemType, colMajorFlag));
		pArrayDst->SetDimensions(pArraySelf->GetDimensions());
		pArrayDst->AllocMemory();
		if (!Array::CopyElements(env, pArrayDst.get(), pArraySelf)) return Value::Nil;
		value = Value(new Object_array(env, pArrayDst.release()));
	}
	return ReturnValue(env, arg, value);
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

template<typename T_Elem>
Value FuncTmpl_fill(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	if (!pArrayT->PrepareModification(env.GetSignal())) return Value::Nil;
	pArrayT->Fill(static_cast<T_Elem>(arg.GetNumber(0)));
	return Value::Nil;
}

Gura_ImplementMethod(array, fill)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_fill);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_paste(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t offset = arg.GetSizeT(0);
	const Array *pArraySrc = Object_array::GetObject(arg, 1)->GetArray();
	if (pArraySrc->GetElemType() != ArrayT<T_Elem>::ElemTypeThis) {
		sig.SetError(ERR_TypeError,
					 "source and destination array must cosist of elements of the same type");
		return Value::Nil;
	}
	const ArrayT<T_Elem> *pArrayTSrc = dynamic_cast<const ArrayT<T_Elem> *>(pArraySrc);
	if (!pArrayT->PrepareModification(sig)) return Value::Nil;
	pArrayT->Paste(sig, offset, pArrayTSrc);
	return Value::Nil;
}

Gura_ImplementMethod(array, paste)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_paste);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_roundoff(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	double threshold = arg.IsValid(0)? arg.GetDouble(0) : 1.e-6;
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Array> pArrayTRtn(pArrayT->RoundOff(threshold));
	return pFunc->ReturnValue(env, arg, Value(new Object_array(env, pArrayTRtn.release())));
}

Gura_ImplementMethod(array, roundoff)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_roundoff);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_tolist(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Value value;
	Object_list *pObjList = value.InitAsList(env);
	pArrayT->CopyToList(pObjList);
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, tolist)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_tolist);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

void AssignMethods(Environment &env)
{
	Gura_AssignMethodTo(VTYPE_array, array, argmax);
	Gura_AssignMethodTo(VTYPE_array, array, argmin);
	Gura_AssignMethodTo(VTYPE_array, array, colmajor);
	Gura_AssignMethodTo(VTYPE_array, array, dot);
	Gura_AssignMethodTo(VTYPE_array, array, dump);
	Gura_AssignMethodTo(VTYPE_array, array, each);
	Gura_AssignMethodTo(VTYPE_array, array, elemcast);
	Gura_AssignMethodTo(VTYPE_array, array, fill);
	Gura_AssignMethodTo(VTYPE_array, array, flatten);
	Gura_AssignMethodTo(VTYPE_array, array, head);
	Gura_AssignMethodTo(VTYPE_array, array, invert);
	Gura_AssignMethodTo(VTYPE_array, array, iselemsame);
	Gura_AssignMethodTo(VTYPE_array, array, issquare);
	Gura_AssignMethodTo(VTYPE_array, array, max);
	Gura_AssignMethodTo(VTYPE_array, array, mean);
	Gura_AssignMethodTo(VTYPE_array, array, min);
	Gura_AssignMethodTo(VTYPE_array, array, offset);
	Gura_AssignMethodTo(VTYPE_array, array, paste);
	Gura_AssignMethodTo(VTYPE_array, array, reshape);
	Gura_AssignMethodTo(VTYPE_array, array, roundoff);
	Gura_AssignMethodTo(VTYPE_array, array, std);
	Gura_AssignMethodTo(VTYPE_array, array, sum);
	Gura_AssignMethodTo(VTYPE_array, array, tail);
	Gura_AssignMethodTo(VTYPE_array, array, tolist);
	Gura_AssignMethodTo(VTYPE_array, array, transpose);
	Gura_AssignMethodTo(VTYPE_array, array, var);
}

Gura_EndModuleScope(arrayt)
