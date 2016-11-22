//=============================================================================
// Gura class: array
//=============================================================================
#include "stdafx.h"

namespace Gura {

typedef Value (*IndexGetT)(Environment &env, const Value &valueIdx, Object_array *pObj);
typedef void (*IndexSetT)(Environment &env, const Value &valueIdx, const Value &value, Object_array *pObj);
typedef Value (*MethodT)(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf);

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
Value CallMethod(Environment &env, Argument &arg, const MethodT methods[],
				 const Function *pFunc, Array *pArraySelf)
{
	MethodT pMethod = methods[pArraySelf->GetElemType()];
	if (pMethod == nullptr) {
		env.SetError(ERR_TypeError, "no methods implemented");
		return Value::Nil;
	}
	return (*pMethod)(env, arg, pFunc, pArraySelf);
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
	return _pArray->ToString();
}

template<typename T_Elem>
Value IndexGetTmpl(Environment &env, const Value &valueIdx, Object_array *pObj)
{
	Signal &sig = env.GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_ValueError, "index must be a number");
		return Value::Nil;
	}
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pObj->GetArray());
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	Array::Dimensions::const_iterator pDim = dims.begin();
	size_t idx = valueIdx.GetSizeT();
	if (idx >= pDim->GetSize()) {
		sig.SetError(ERR_OutOfRangeError, "index is out of range");
		return Value::Nil;
	}
	if (pDim + 1 == dims.end()) {
		return Value(pArrayT->GetPointer()[idx]);
	}
	AutoPtr<ArrayT<T_Elem> > pArrayRtn(new ArrayT<T_Elem>(pArrayT->GetMemory().Reference()));
	pArrayRtn->SetDimension(pDim + 1, dims.end());
	pArrayRtn->SetOffsetBase(pArrayT->GetOffsetBase() + pDim->GetStride() * idx);
	return Value(new Object_arrayT<T_Elem>(pObj->GetClass(), pArrayRtn.release()));
}

Value Object_array::IndexGet(Environment &env, const Value &valueIdx)
{
	static const IndexGetT indexGets[] = {
		nullptr,
		&IndexGetTmpl<Char>,
		&IndexGetTmpl<UChar>,
		&IndexGetTmpl<Short>,
		&IndexGetTmpl<UShort>,
		&IndexGetTmpl<Int32>,
		&IndexGetTmpl<UInt32>,
		&IndexGetTmpl<Int64>,
		&IndexGetTmpl<UInt64>,
		&IndexGetTmpl<Float>,
		&IndexGetTmpl<Double>,
		//&IndexGetTmpl<Complex>,
	};
	return (*indexGets[GetArray()->GetElemType()])(env, valueIdx, this);
}

template<typename T_Elem>
void IndexSetTmpl(Environment &env, const Value &valueIdx, const Value &value, Object_array *pObj)
{
	Signal &sig = env.GetSignal();
	if (!valueIdx.Is_number()) {
		sig.SetError(ERR_ValueError, "index must be a number");
		return;
	}
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pObj->GetArray());
	size_t idx = valueIdx.GetSizeT();
	if (idx >= pArrayT->GetElemNum()) {
		sig.SetError(ERR_OutOfRangeError, "index is out of range");
		return;
	}
	pArrayT->GetPointer()[idx] = static_cast<T_Elem>(value.GetNumber());
}

void Object_array::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
	static const IndexSetT indexSets[] = {
		nullptr,
		&IndexSetTmpl<Char>,
		&IndexSetTmpl<UChar>,
		&IndexSetTmpl<Short>,
		&IndexSetTmpl<UShort>,
		&IndexSetTmpl<Int32>,
		&IndexSetTmpl<UInt32>,
		&IndexSetTmpl<Int64>,
		&IndexSetTmpl<UInt64>,
		&IndexSetTmpl<Float>,
		&IndexSetTmpl<Double>,
		//&IndexSetTmpl<Complex>,
	};
	(*indexSets[GetArray()->GetElemType()])(env, valueIdx, value, this);
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// array#average() {block?}
template<typename T_Elem>
Value Method_average(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	size_t n = pArrayT->GetElemNum();
	return pFunc->ReturnValue(env, arg, Value((n == 0)? 0 : pArrayT->Sum() / n));
}

Gura_DeclareMethod(array, average)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates an average value of elements in the array.\n"
		);
}

Gura_ImplementMethod(array, average)
{
	static const MethodT methods[] = {
		nullptr,
		&Method_average<Char>,
		&Method_average<UChar>,
		&Method_average<Short>,
		&Method_average<UShort>,
		&Method_average<Int32>,
		&Method_average<UInt32>,
		&Method_average<Int64>,
		&Method_average<UInt64>,
		&Method_average<Float>,
		&Method_average<Double>,
		//&Method_average<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
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
		);
}

Gura_ImplementClassMethod(array, dot)
{
	Signal &sig = env.GetSignal();
	const Array *pArrayL = Object_array::GetObject(arg, 0)->GetArray();
	const Array *pArrayR = Object_array::GetObject(arg, 1)->GetArray();
	AutoPtr<Array> pArrayResult(Array::Dot(sig, pArrayL, pArrayR));
	if (pArrayResult.IsNull()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayResult.release())));
}

// array#dump():void
template<typename T_Elem>
Value Method_dump(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	bool upperFlag = arg.IsSet(Gura_Symbol(upper));
	Stream *pStream = arg.IsValid(0)?
		&Object_stream::GetObject(arg, 0)->GetStream() : env.GetConsole();
	pArrayT->Dump(sig, *pStream, upperFlag);
	return Value::Nil;
}

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
	static const MethodT methods[] = {
		nullptr,
		&Method_dump<Char>,
		&Method_dump<UChar>,
		&Method_dump<Short>,
		&Method_dump<UShort>,
		&Method_dump<Int32>,
		&Method_dump<UInt32>,
		&Method_dump<Int64>,
		&Method_dump<UInt64>,
		&Method_dump<Float>,
		&Method_dump<Double>,
		//&Method_dump<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// arrayT#each() {block?}
template<typename T_Elem>
Value Method_each(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Iterator> pIterator(new Iterator_ArrayT_Each<T_Elem>(pArrayT->Reference()));
	return pFunc->ReturnIterator(env, arg, pIterator.release());
}

Gura_DeclareMethod(array, each)
{
	SetFuncAttr(VTYPE_iterator, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
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
	static const MethodT methods[] = {
		nullptr,
		&Method_each<Char>,
		&Method_each<UChar>,
		&Method_each<Short>,
		&Method_each<UShort>,
		&Method_each<Int32>,
		&Method_each<UInt32>,
		&Method_each<Int64>,
		&Method_each<UInt64>,
		&Method_each<Float>,
		&Method_each<Double>,
		//&Method_each<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#fill(value:number):void
template<typename T_Elem>
Value Method_fill(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	pArrayT->Fill(static_cast<T_Elem>(arg.GetNumber(0)));
	return Value::Nil;
}

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
	static const MethodT methods[] = {
		nullptr,
		&Method_fill<Char>,
		&Method_fill<UChar>,
		&Method_fill<Short>,
		&Method_fill<UShort>,
		&Method_fill<Int32>,
		&Method_fill<UInt32>,
		&Method_fill<Int64>,
		&Method_fill<UInt64>,
		&Method_fill<Float>,
		&Method_fill<Double>,
		//&Method_fill<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#flat()
template<typename T_Elem>
Value Method_flat(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	//const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	return Value::Nil;
}

Gura_DeclareMethod(array, flat)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"Flatten elements in the array.\n"
		);
}

Gura_ImplementMethod(array, flat)
{
	static const MethodT methods[] = {
		nullptr,
		&Method_flat<Char>,
		&Method_flat<UChar>,
		&Method_flat<Short>,
		&Method_flat<UShort>,
		&Method_flat<Int32>,
		&Method_flat<UInt32>,
		&Method_flat<Int64>,
		&Method_flat<UInt64>,
		&Method_flat<Float>,
		&Method_flat<Double>,
		//&Method_flat<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#head(n:number):map {block?}
template<typename T_Elem>
Value Method_head(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	if (n > pArrayT->GetElemNum()) {
		sig.SetError(ERR_OutOfRangeError, "offset is out of range");
		return Value::Nil;
	}
	size_t offsetBase = pArrayT->GetOffsetBase();
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(new ArrayT<T_Elem>(pArrayT->GetMemory().Reference()));
	pArrayTRtn->SetDimension(Array::Dimension(n));
	pArrayTRtn->SetOffsetBase(offsetBase);
	Value value(new Object_arrayT<T_Elem>(env, arg.GetValueThis().GetValueType(),
										  pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_DeclareMethod(array, head)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted specified number of elements\n"
		"from the beginning of the source.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod(array, head)
{
	static const MethodT methods[] = {
		nullptr,
		&Method_head<Char>,
		&Method_head<UChar>,
		&Method_head<Short>,
		&Method_head<UShort>,
		&Method_head<Int32>,
		&Method_head<UInt32>,
		&Method_head<Int64>,
		&Method_head<UInt64>,
		&Method_head<Float>,
		&Method_head<Double>,
		//&Method_head<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#offset(n:number):map {block?}
template<typename T_Elem>
Value Method_offset(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	if (n > pArrayT->GetElemNum()) {
		sig.SetError(ERR_OutOfRangeError, "offset is out of range");
		return Value::Nil;
		}
	size_t nElems = pArrayT->GetElemNum() - n;
	size_t offsetBase = pArrayT->GetOffsetBase() + n;
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(
		new ArrayT<T_Elem>(pArrayT->GetMemory().Reference()));
	pArrayTRtn->SetDimension(Array::Dimension(nElems));
	pArrayTRtn->SetOffsetBase(offsetBase);
	Value value(new Object_arrayT<T_Elem>(env, arg.GetValueThis().GetValueType(),
										  pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_DeclareMethod(array, offset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted elements of the source\n"
		"after skipping the first `n` elements.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod(array, offset)
{
	static const MethodT methods[] = {
		nullptr,
		&Method_offset<Char>,
		&Method_offset<UChar>,
		&Method_offset<Short>,
		&Method_offset<UShort>,
		&Method_offset<Int32>,
		&Method_offset<UInt32>,
		&Method_offset<Int64>,
		&Method_offset<UInt64>,
		&Method_offset<Float>,
		&Method_offset<Double>,
		//&Method_offset<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#paste(offset:number, src:array):map:void
template<typename T_Elem>
Value Method_paste(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t offset = arg.GetSizeT(0);
	const ArrayT<T_Elem> *pArrayTSrc = Object_arrayT<T_Elem>::GetObject(arg, 1)->GetArrayT();
	pArrayT->Paste(sig, offset, pArrayTSrc);
	return Value::Nil;
}

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
	static const MethodT methods[] = {
		nullptr,
		&Method_paste<Char>,
		&Method_paste<UChar>,
		&Method_paste<Short>,
		&Method_paste<UShort>,
		&Method_paste<Int32>,
		&Method_paste<UInt32>,
		&Method_paste<Int64>,
		&Method_paste<UInt64>,
		&Method_paste<Float>,
		&Method_paste<Double>,
		//&Method_paste<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#sum() {block?}
template<typename T_Elem>
Value Method_sum(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	return pFunc->ReturnValue(env, arg, Value(pArrayT->Sum()));
}

Gura_DeclareMethod(array, sum)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Calculates a summation value of elements in the array.\n"
		);
}

Gura_ImplementMethod(array, sum)
{
	static const MethodT methods[] = {
		nullptr,
		&Method_sum<Char>,
		&Method_sum<UChar>,
		&Method_sum<Short>,
		&Method_sum<UShort>,
		&Method_sum<Int32>,
		&Method_sum<UInt32>,
		&Method_sum<Int64>,
		&Method_sum<UInt64>,
		&Method_sum<Float>,
		&Method_sum<Double>,
		//&Method_sum<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

// array#tail(n:number):map {block?}
template<typename T_Elem>
Value Method_tail(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	if (n > pArrayT->GetElemNum()) {
		sig.SetError(ERR_OutOfRangeError, "offset is out of range");
		return Value::Nil;
	}
	size_t offsetBase = pArrayT->GetOffsetBase() + pArrayT->GetElemNum() - n;
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(
		new ArrayT<T_Elem>(pArrayT->GetMemory().Reference()));
	pArrayTRtn->SetDimension(Array::Dimension(n));
	pArrayTRtn->SetOffsetBase(offsetBase);
	Value value(new Object_arrayT<T_Elem>(env, arg.GetValueThis().GetValueType(),
										  pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_DeclareMethod(array, tail)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an array that has extracted specified number of elements\n"
		"from the bottom of the source.\n"
		"\n"
		"If `block` is specified, it would be evaluated with a block parameter\n"
		"`|array:array@T|`, where `array` is the created instance.\n"
		"In this case, the block's result would become the function's returned value.\n"
		);
}

Gura_ImplementMethod(array, tail)
{
	static const MethodT methods[] = {
		nullptr,
		&Method_tail<Char>,
		&Method_tail<UChar>,
		&Method_tail<Short>,
		&Method_tail<UShort>,
		&Method_tail<Int32>,
		&Method_tail<UInt32>,
		&Method_tail<Int64>,
		&Method_tail<UInt64>,
		&Method_tail<Float>,
		&Method_tail<Double>,
		//&Method_tail<Complex>,
	};
	return CallMethod(env, arg, methods, this, Object_array::GetObjectThis(arg)->GetArray());
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_array::Class_array(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_array)
{
}

void Class_array::Prepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(array, Value(Reference()));
	// method assignment
	Gura_AssignMethod(array, average);
	Gura_AssignMethod(array, dot);
	Gura_AssignMethod(array, dump);
	Gura_AssignMethod(array, each);
	Gura_AssignMethod(array, fill);
	Gura_AssignMethod(array, flat);
	Gura_AssignMethod(array, head);
	Gura_AssignMethod(array, offset);
	Gura_AssignMethod(array, paste);
	Gura_AssignMethod(array, sum);
	Gura_AssignMethod(array, tail);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en + 1);
}

}
