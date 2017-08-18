#include "stdafx.h"

Gura_BeginModuleScope(arrayt)

typedef Value (*FuncT_Method)(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf);

//-----------------------------------------------------------------------------
// utilities
//-----------------------------------------------------------------------------
template<typename T_Elem, bool (*op)(T_Elem, T_Elem)>
Array *FindMinMax(const ArrayT<T_Elem> *pArrayT,
				  Array::Dimensions::const_iterator pDimAxis)
{
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_Elem> > pArrayTValue(
		ArrayT<T_Elem>::Create(dims.begin(), pDimAxis, pDimAxis + 1, dims.end()));
	pArrayTValue->FillZero();
	const T_Elem *pElem = pArrayT->GetPointer();
	T_Elem *pElemValue = pArrayTValue->GetPointer();
	if (pDimAxis + 1 == dims.end()) {
		size_t cnt = pArrayT->GetElemNum() / pDimAxis->GetSize();
		while (cnt-- > 0) {
			*pElemValue = *pElem;
			pElem++;
			for (size_t i = 1; i < pDimAxis->GetSize(); i++, pElem++) {
				if ((*op)(*pElemValue, *pElem)) *pElemValue = *pElem;
			}
			pElemValue++;
		}
	} else {
		size_t stride = pDimAxis->GetStride();
		size_t cnt = pArrayT->GetElemNum() / (pDimAxis->GetSize() * stride);
		while (cnt-- > 0) {
			for (size_t j = 0; j < stride; j++, pElem++) {
				*(pElemValue + j) = *pElem;
			}
			for (size_t i = 1; i < pDimAxis->GetSize(); i++) {
				T_Elem *pElemValueWk = pElemValue;
				for (size_t j = 0; j < stride; j++, pElemValueWk++, pElem++) {
					if ((*op)(*pElemValueWk, *pElem)) *pElemValueWk = *pElem;
				}
			}
			pElemValue += stride;
		}
	}
	return pArrayTValue.release();
}

template<typename T_Elem, bool (*op)(T_Elem, T_Elem)>
Array *FindMinMaxIndex(const ArrayT<T_Elem> *pArrayT,
					   Array::Dimensions::const_iterator pDimAxis)
{
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<UInt32> > pArrayTIndex(
		ArrayT<UInt32>::Create(dims.begin(), pDimAxis, pDimAxis + 1, dims.end()));
	AutoPtr<Memory> pMemoryValue(new MemoryHeap(pArrayTIndex->GetElemNum() * sizeof(T_Elem)));
	pArrayTIndex->FillZero();
	const T_Elem *pElem = pArrayT->GetPointer();
	UInt32 *pElemIndex = pArrayTIndex->GetPointer();
	T_Elem *pElemValue = reinterpret_cast<T_Elem *>(pMemoryValue->GetPointer());
	if (pDimAxis + 1 == dims.end()) {
		size_t cnt = pArrayT->GetElemNum() / pDimAxis->GetSize();
		while (cnt-- > 0) {
			*pElemIndex = 0;
			*pElemValue = *pElem;
			pElem++;
			for (size_t i = 1; i < pDimAxis->GetSize(); i++, pElem++) {
				if ((*op)(*pElemValue, *pElem)) {
					*pElemIndex = static_cast<UInt32>(i);
					*pElemValue = *pElem;
				}
			}
			pElemIndex++;
			pElemValue++;
		}
	} else {
		size_t stride = pDimAxis->GetStride();
		size_t cnt = pArrayT->GetElemNum() / (pDimAxis->GetSize() * stride);
		while (cnt-- > 0) {
			for (size_t j = 0; j < stride; j++, pElem++) {
				*(pElemIndex + j) = 0;
				*(pElemValue + j) = *pElem;
			}
			for (size_t i = 1; i < pDimAxis->GetSize(); i++) {
				T_Elem *pElemValueWk = pElemValue;
				for (size_t j = 0; j < stride; j++, pElemValueWk++, pElem++) {
					if ((*op)(*pElemValueWk, *pElem)) {
						*(pElemIndex + j) = static_cast<UInt32>(i);
						*pElemValueWk = *pElem;
					}
				}
			}
			pElemIndex += stride;
			pElemValue += stride;
		}
	}
	return pArrayTIndex.release();
}

template<typename T_Elem, bool (*op)(T_Elem, T_Elem)>
T_Elem FindMinMaxFlat(const ArrayT<T_Elem> *pArrayT)
{
	const T_Elem *p = pArrayT->GetPointer();
	T_Elem rtn = *p++;
	for (size_t i = 1; i < pArrayT->GetElemNum(); i++, p++) {
		if ((*op)(rtn, *p)) rtn = *p;
	}
	return rtn;
}

template<typename T_Elem, bool (*op)(T_Elem, T_Elem)>
size_t FindMinMaxIndexFlat(const ArrayT<T_Elem> *pArrayT)
{
	const T_Elem *p = pArrayT->GetPointer();
	size_t index = 0;
	T_Elem value = *p++;
	for (size_t i = 1; i < pArrayT->GetElemNum(); i++, p++) {
		if ((*op)(value, *p)) {
			index = i;
			value = *p;
		}
	}
	return index;
}

template<typename T_ElemResult, typename T_Elem>
ArrayT<T_ElemResult> *CalcSum(const ArrayT<T_Elem> *pArrayT,
							  Array::Dimensions::const_iterator pDimAxis, bool meanFlag)
{
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(
		ArrayT<T_ElemResult>::Create(dims.begin(), pDimAxis, pDimAxis + 1, dims.end()));
	pArrayTResult->FillZero();
	Double denom = static_cast<Double>(pDimAxis->GetSize());
	const T_Elem *pElemTop = pArrayT->GetPointer();
	T_ElemResult *pElemResult = pArrayTResult->GetPointer();
	if (pDimAxis + 1 == dims.end()) {
		size_t axisSize = pDimAxis->GetSize();
		const T_Elem *pElem = pElemTop;
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += axisSize) {
			T_ElemResult accum = 0;
			for (size_t i = 0; i < axisSize; i++, pElem++) {
				accum += *pElem;
			}
			*pElemResult++ = meanFlag? accum / denom : accum;
		}
	} else {
		size_t stride = pDimAxis->GetStride();
		size_t axisSize = pDimAxis->GetSize();
		size_t stepSize = axisSize * stride;
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += stepSize) {
			for (size_t j = 0; j < stride; j++) {
				const T_Elem *pElem = pElemTop + offset + j;
				T_ElemResult accum = 0;
				for (size_t i = 0; i < axisSize; i++, pElem += stride) {
					accum += *pElem;
				}
				*pElemResult++ = meanFlag? accum / denom : accum;
			}
		}
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_Elem>
T_ElemResult CalcSumFlat(const ArrayT<T_Elem> *pArrayT, bool meanFlag)
{
	Double denom = static_cast<Double>(pArrayT->GetElemNum());
	if (denom == 0) return 0;
	T_ElemResult accum = 0;
	const T_Elem *pElem = pArrayT->GetPointer();
	for (size_t i = 0; i < pArrayT->GetElemNum(); i++, pElem++) {
		accum += *pElem;
	}
	return meanFlag? accum / denom : accum;
}

template<typename T_ElemResult, typename T_Elem>
ArrayT<T_ElemResult> *CalcVar(const ArrayT<T_Elem> *pArrayT,
							  Array::Dimensions::const_iterator pDimAxis,
							  bool populationFlag, bool stdFlag)
{
	const Array::Dimensions &dims = pArrayT->GetDimensions();
	AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(
		ArrayT<T_ElemResult>::Create(dims.begin(), pDimAxis, pDimAxis + 1, dims.end()));
	pArrayTResult->FillZero();
	Double denom = static_cast<Double>(pDimAxis->GetSize());
	Double denomVar = (denom <= 1)? 1 : populationFlag? denom : denom - 1;
	const T_Elem *pElemTop = pArrayT->GetPointer();
	T_ElemResult *pElemResult = pArrayTResult->GetPointer();
	if (pDimAxis + 1 == dims.end()) {
		size_t axisSize = pDimAxis->GetSize();
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += axisSize) {
			const T_Elem *pElemSave = pElemTop + offset;
			T_ElemResult mean = 0;
			do {
				const T_Elem *pElem = pElemSave;
				for (size_t i = 0; i < axisSize; i++, pElem++) {
					mean += *pElem;
				}
				mean /= denom;
			} while (0);
			T_ElemResult accum = 0;
			do {
				const T_Elem *pElem = pElemSave;
				for (size_t i = 0; i < axisSize; i++, pElem++) {
					T_ElemResult tmp = *pElem - mean;
					accum += tmp * tmp;
				}
				accum /= denomVar;
			} while (0);
			if (stdFlag) Operator_Math_sqrt::Calc(accum, accum);
			*pElemResult++ = accum;
		}
	} else {
		size_t stride = pDimAxis->GetStride();
		size_t axisSize = pDimAxis->GetSize();
		size_t stepSize = pDimAxis->GetSize() * stride;
		for (size_t offset = 0; offset < pArrayT->GetElemNum(); offset += stepSize) {
			for (size_t j = 0; j < stride; j++) {
				const T_Elem *pElemSave = pElemTop + offset + j;
				T_ElemResult mean = 0;
				do {
					const T_Elem *pElem = pElemSave;
					for (size_t i = 0; i < axisSize; i++, pElem += stride) {
						mean += *pElem;
					}
					mean /= denom;
				} while (0);
				T_ElemResult accum = 0;
				do {
					const T_Elem *pElem = pElemSave;
					for (size_t i = 0; i < axisSize; i++, pElem += stride) {
						T_ElemResult tmp = *pElem - mean;
						accum += tmp * tmp;
					}
					accum /= denomVar;
				} while (0);
				if (stdFlag) Operator_Math_sqrt::Calc(accum, accum);
				*pElemResult++ = accum;
			}
		}
	}
	return pArrayTResult.release();
}

template<typename T_ElemResult, typename T_Elem>
T_ElemResult CalcVarFlat(const ArrayT<T_Elem> *pArrayT, bool populationFlag, bool stdFlag)
{
	Double denom = static_cast<Double>(pArrayT->GetElemNum());
	if (denom == 0) return 0;
	Double denomVar = (denom <= 1)? 1 : populationFlag? denom : denom - 1;
	T_ElemResult mean = 0;
	do {
		const T_Elem *pElem = pArrayT->GetPointer();
		for (size_t i = 0; i < pArrayT->GetElemNum(); i++, pElem++) {
			mean += *pElem;
		}
		mean /= denom;
	} while (0);
	T_ElemResult accum = 0;
	do {
		const T_Elem *pElem = pArrayT->GetPointer();
		for (size_t i = 0; i < pArrayT->GetElemNum(); i++, pElem++) {
			T_ElemResult tmp = *pElem - mean;
			accum += tmp * tmp;
		}
		accum /= denomVar;
	} while (0);
	if (stdFlag) Operator_Math_sqrt::Calc(accum, accum);
	return accum;
}

Value CallMethod(Environment &env, Argument &arg, const FuncT_Method funcTbl[],
				 const Function *pFunc, Array *pArraySelf)
{
	FuncT_Method func = funcTbl[pArraySelf->GetElemType()];
	if (func == nullptr) {
		env.SetError(ERR_TypeError, "no method implemented");
		return Value::Nil;
	}
	return env, arg, (*func)(env, arg, pFunc, pArraySelf);
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

template<typename T_Elem>
Value FuncTmpl_argmax(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	bool lastIndexFlag = arg.IsSet(Gura_Symbol(last_index));
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	if (pArrayT->GetElemNum() == 0) return Value::Nil;
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn = Value(
				lastIndexFlag? FindMinMaxIndexFlat<T_Elem, CompareLe>(pArrayT) :
				FindMinMaxIndexFlat<T_Elem, CompareLt>(pArrayT));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			AutoPtr<Array> pArrayResult(
				lastIndexFlag? FindMinMaxIndex<T_Elem, CompareLe>(pArrayT, pDimAxis) :
				FindMinMaxIndex<T_Elem, CompareLt>(pArrayT, pDimAxis));
			if (pArrayResult.IsNull()) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayResult.release()));
		}
	} else {
		valueRtn = Value(
			lastIndexFlag? FindMinMaxIndexFlat<T_Elem, CompareLe>(pArrayT) :
			FindMinMaxIndexFlat<T_Elem, CompareLt>(pArrayT));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, argmax)
{
	static const FuncT_Method funcTbl[Array::ETYPE_Max] = {
		nullptr,
		&FuncTmpl_argmax<Boolean>,
		&FuncTmpl_argmax<Int8>,
		&FuncTmpl_argmax<UInt8>,
		&FuncTmpl_argmax<Int16>,
		&FuncTmpl_argmax<UInt16>,
		&FuncTmpl_argmax<Int32>,
		&FuncTmpl_argmax<UInt32>,
		&FuncTmpl_argmax<Int64>,
		&FuncTmpl_argmax<UInt64>,
		&FuncTmpl_argmax<Half>,
		&FuncTmpl_argmax<Float>,
		&FuncTmpl_argmax<Double>,
		nullptr,
		//&FuncTmpl_argmax<Value, Value>,
	};
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_argmin(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	bool lastIndexFlag = arg.IsSet(Gura_Symbol(last_index));
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	if (pArrayT->GetElemNum() == 0) return Value::Nil;
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn = Value(
				lastIndexFlag? FindMinMaxIndexFlat<T_Elem, CompareGe>(pArrayT) :
				FindMinMaxIndexFlat<T_Elem, CompareGt>(pArrayT));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			AutoPtr<Array> pArrayResult(
				lastIndexFlag? FindMinMaxIndex<T_Elem, CompareGe>(pArrayT, pDimAxis) :
				FindMinMaxIndex<T_Elem, CompareGt>(pArrayT, pDimAxis));
			if (pArrayResult.IsNull()) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayResult.release()));
		}
	} else {
		valueRtn = Value(
			lastIndexFlag? FindMinMaxIndexFlat<T_Elem, CompareGe>(pArrayT) :
			FindMinMaxIndexFlat<T_Elem, CompareGt>(pArrayT));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, argmin)
{
	static const FuncT_Method funcTbl[Array::ETYPE_Max] = {
		nullptr,
		&FuncTmpl_argmin<Boolean>,
		&FuncTmpl_argmin<Int8>,
		&FuncTmpl_argmin<UInt8>,
		&FuncTmpl_argmin<Int16>,
		&FuncTmpl_argmin<UInt16>,
		&FuncTmpl_argmin<Int32>,
		&FuncTmpl_argmin<UInt32>,
		&FuncTmpl_argmin<Int64>,
		&FuncTmpl_argmin<UInt64>,
		&FuncTmpl_argmin<Half>,
		&FuncTmpl_argmin<Float>,
		&FuncTmpl_argmin<Double>,
		nullptr,
		//&FuncTmpl_argmin<Value, Value>,
	};
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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
	Array::ElemType elemType = Array::SymbolToElemTypeWithError(env, arg.GetSymbol(0));
	if (env.IsSignalled()) return Value::Nil;
	Value value;
	if (pArraySelf->GetElemType() == elemType) {
		value = Value(new Object_array(env, pArraySelf->Clone()));
	} else {
		AutoPtr<Array> pArrayDst(Array::Create(elemType, pArraySelf->GetDimensions()));
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

template<typename T_Elem>
Value FuncTmpl_flatten(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Array> pArrayTRtn(pArrayT->Flatten());
	return pFunc->ReturnValue(env, arg, Value(new Object_array(env, pArrayTRtn.release())));
}

Gura_ImplementMethod(array, flatten)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_flatten);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_head(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(pArrayT->Head(sig, n));
	if (pArrayTRtn.IsNull()) return Value::Nil;
	Value value(new Object_array(env, pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, head)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_head);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_invert(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	Double epsilon = arg.IsValid(0)? arg.GetDouble(0) : 1.0e-6;
	AutoPtr<Array> pArrayRtn(Array::ApplyInvertFunc(sig, nullptr, pArrayT, epsilon));
	if (pArrayRtn.IsNull()) return Value::Nil;
	Value value(new Object_array(env, pArrayRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, invert)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_invert);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_max(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	bool indexFlag = arg.IsSet(Gura_Symbol(index));
	bool lastIndexFlag = arg.IsSet(Gura_Symbol(last_index));
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	if (pArrayT->GetElemNum() == 0) return Value::Nil;
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn =
				indexFlag? Value(FindMinMaxIndexFlat<T_Elem, CompareLt>(pArrayT)) :
				lastIndexFlag? Value(FindMinMaxIndexFlat<T_Elem, CompareLe>(pArrayT)) :
				Value(FindMinMaxFlat<T_Elem, CompareLt>(pArrayT));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			AutoPtr<Array> pArrayResult(
				indexFlag? FindMinMaxIndex<T_Elem, CompareLt>(pArrayT, pDimAxis) :
				lastIndexFlag? FindMinMaxIndex<T_Elem, CompareLe>(pArrayT, pDimAxis) :
				FindMinMax<T_Elem, CompareLt>(pArrayT, pDimAxis));
			if (pArrayResult.IsNull()) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayResult.release()));
		}
	} else {
		valueRtn =
			indexFlag? Value(FindMinMaxIndexFlat<T_Elem, CompareLt>(pArrayT)) :
			lastIndexFlag? Value(FindMinMaxIndexFlat<T_Elem, CompareLe>(pArrayT)) :
			Value(FindMinMaxFlat<T_Elem, CompareLt>(pArrayT));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, max)
{
	static const FuncT_Method funcTbl[Array::ETYPE_Max] = {
		nullptr,
		&FuncTmpl_max<Boolean>,
		&FuncTmpl_max<Int8>,
		&FuncTmpl_max<UInt8>,
		&FuncTmpl_max<Int16>,
		&FuncTmpl_max<UInt16>,
		&FuncTmpl_max<Int32>,
		&FuncTmpl_max<UInt32>,
		&FuncTmpl_max<Int64>,
		&FuncTmpl_max<UInt64>,
		&FuncTmpl_max<Half>,
		&FuncTmpl_max<Float>,
		&FuncTmpl_max<Double>,
		nullptr,
		//&FuncTmpl_max<Value, Value>,
	};
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_ElemResult, typename T_Elem>
Value FuncTmpl_mean(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn = Value(CalcSumFlat<T_ElemResult, T_Elem>(pArrayT, true));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(CalcSum<T_ElemResult, T_Elem>(pArrayT, pDimAxis, true));
			if (pArrayTResult.IsNull()) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayTResult.release()));
		}
	} else {
		valueRtn = Value(CalcSumFlat<T_ElemResult, T_Elem>(pArrayT, true));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, mean)
{
	static const FuncT_Method funcTbl[Array::ETYPE_Max] = {
		nullptr,
		&FuncTmpl_mean<UInt32, Boolean>,
		&FuncTmpl_mean<Int8, Int8>,
		&FuncTmpl_mean<UInt8, UInt8>,
		&FuncTmpl_mean<Int16, Int16>,
		&FuncTmpl_mean<UInt16, UInt16>,
		&FuncTmpl_mean<Int32, Int32>,
		&FuncTmpl_mean<UInt32, UInt32>,
		&FuncTmpl_mean<Int64, Int64>,
		&FuncTmpl_mean<UInt64, UInt64>,
		&FuncTmpl_mean<Half, Half>,
		&FuncTmpl_mean<Float, Float>,
		&FuncTmpl_mean<Double, Double>,
		&FuncTmpl_mean<Complex, Complex>,
		//&FuncTmpl_mean<Value, Value>,
	};
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_min(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	bool indexFlag = arg.IsSet(Gura_Symbol(index));
	bool lastIndexFlag = arg.IsSet(Gura_Symbol(last_index));
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	if (pArrayT->GetElemNum() == 0) return Value::Nil;
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn =
				indexFlag? Value(FindMinMaxIndexFlat<T_Elem, CompareGt>(pArrayT)) :
				lastIndexFlag? Value(FindMinMaxIndexFlat<T_Elem, CompareGe>(pArrayT)) :
				Value(FindMinMaxFlat<T_Elem, CompareGt>(pArrayT));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			AutoPtr<Array> pArrayResult(
				indexFlag? FindMinMaxIndex<T_Elem, CompareGt>(pArrayT, pDimAxis) :
				lastIndexFlag? FindMinMaxIndex<T_Elem, CompareGe>(pArrayT, pDimAxis) :
				FindMinMax<T_Elem, CompareGt>(pArrayT, pDimAxis));
			if (pArrayResult.IsNull()) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayResult.release()));
		}
	} else {
		valueRtn =
			indexFlag? Value(FindMinMaxIndexFlat<T_Elem, CompareGt>(pArrayT)) :
			lastIndexFlag? Value(FindMinMaxIndexFlat<T_Elem, CompareGe>(pArrayT)) :
			Value(FindMinMaxFlat<T_Elem, CompareGt>(pArrayT));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, min)
{
	static const FuncT_Method funcTbl[Array::ETYPE_Max] = {
		nullptr,
		&FuncTmpl_min<Boolean>,
		&FuncTmpl_min<Int8>,
		&FuncTmpl_min<UInt8>,
		&FuncTmpl_min<Int16>,
		&FuncTmpl_min<UInt16>,
		&FuncTmpl_min<Int32>,
		&FuncTmpl_min<UInt32>,
		&FuncTmpl_min<Int64>,
		&FuncTmpl_min<UInt64>,
		&FuncTmpl_min<Half>,
		&FuncTmpl_min<Float>,
		&FuncTmpl_min<Double>,
		nullptr,
		//&FuncTmpl_min<Value, Value>,
	};
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_offset(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(pArrayT->Offset(sig, n));
	if (pArrayTRtn.IsNull()) return Value::Nil;
	Value value(new Object_array(env, pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, offset)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_offset);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_reshape(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	Signal &sig = env.GetSignal();
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	AutoPtr<Array> pArrayTRtn(pArrayT->Reshape(sig, arg.GetList(0)));
	if (pArrayTRtn.IsNull()) return Value::Nil;
	return pFunc->ReturnValue(env, arg, Value(new Object_array(env, pArrayTRtn.release())));
}

Gura_ImplementMethod(array, reshape)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_reshape);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_ElemResult, typename T_Elem>
Value FuncTmpl_std(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	bool populationFlag = arg.IsSet(Gura_Symbol(p));
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn = Value(CalcVarFlat<T_ElemResult, T_Elem>(pArrayT, populationFlag, true));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(CalcVar<T_ElemResult, T_Elem>(pArrayT, pDimAxis, populationFlag, true));
			if (pArrayTResult.IsNull()) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayTResult.release()));
		}
	} else {
		valueRtn = Value(CalcVarFlat<T_ElemResult, T_Elem>(pArrayT, populationFlag, true));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, std)
{
	static const FuncT_Method funcTbl[Array::ETYPE_Max] = {
		nullptr,
		&FuncTmpl_std<UInt32, Boolean>,
		&FuncTmpl_std<Int8, Int8>,
		&FuncTmpl_std<UInt8, UInt8>,
		&FuncTmpl_std<Int16, Int16>,
		&FuncTmpl_std<UInt16, UInt16>,
		&FuncTmpl_std<Int32, Int32>,
		&FuncTmpl_std<UInt32, UInt32>,
		&FuncTmpl_std<Int64, Int64>,
		&FuncTmpl_std<UInt64, UInt64>,
		&FuncTmpl_std<Half, Half>,
		&FuncTmpl_std<Float, Float>,
		&FuncTmpl_std<Double, Double>,
		&FuncTmpl_std<Complex, Complex>,
		//&FuncTmpl_std<Value, Value>,
	};
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_ElemResult, typename T_Elem>
Value FuncTmpl_sum(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn = Value(CalcSumFlat<T_ElemResult, T_Elem>(pArrayT, false));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(CalcSum<T_ElemResult, T_Elem>(pArrayT, pDimAxis, false));
			if (pArrayTResult.IsNull()) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayTResult.release()));
		}
	} else {
		valueRtn = Value(CalcSumFlat<T_ElemResult, T_Elem>(pArrayT, false));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, sum)
{
	static const FuncT_Method funcTbl[Array::ETYPE_Max] = {
		nullptr,
		&FuncTmpl_sum<UInt32, Boolean>,
		&FuncTmpl_sum<Int8, Int8>,
		&FuncTmpl_sum<UInt8, UInt8>,
		&FuncTmpl_sum<Int16, Int16>,
		&FuncTmpl_sum<UInt16, UInt16>,
		&FuncTmpl_sum<Int32, Int32>,
		&FuncTmpl_sum<UInt32, UInt32>,
		&FuncTmpl_sum<Int64, Int64>,
		&FuncTmpl_sum<UInt64, UInt64>,
		&FuncTmpl_sum<Half, Half>,
		&FuncTmpl_sum<Float, Float>,
		&FuncTmpl_sum<Double, Double>,
		&FuncTmpl_sum<Complex, Complex>,
		//&FuncTmpl_sum<Value, Value>,
	};
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_Elem>
Value FuncTmpl_tail(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	size_t n = arg.GetSizeT(0);
	AutoPtr<ArrayT<T_Elem> > pArrayTRtn(pArrayT->Tail(sig, n));
	if (pArrayTRtn.IsNull()) return Value::Nil;
	Value value(new Object_array(env, pArrayTRtn.release()));
	return pFunc->ReturnValue(env, arg, value);
}

Gura_ImplementMethod(array, tail)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_tail);
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

template<typename T_Elem>
Value FuncTmpl_transpose(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Signal &sig = env.GetSignal();
	AutoPtr<Array> pArrayTRtn;
	if (arg.IsValid(0)) {
		pArrayTRtn.reset(pArrayT->Transpose(sig, arg.GetList(0)));
		if (pArrayTRtn.IsNull()) return Value::Nil;
	} else {
		pArrayTRtn.reset(pArrayT->Transpose());
	}
	return pFunc->ReturnValue(env, arg, Value(new Object_array(env, pArrayTRtn.release())));
}

Gura_ImplementMethod(array, transpose)
{
	DeclareFunctionTable1D(FuncT_Method, funcTbl, FuncTmpl_transpose);
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
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

template<typename T_ElemResult, typename T_Elem>
Value FuncTmpl_var(Environment &env, Argument &arg, const Function *pFunc, Array *pArraySelf)
{
	bool populationFlag = arg.IsSet(Gura_Symbol(p));
	const ArrayT<T_Elem> *pArrayT = dynamic_cast<ArrayT<T_Elem> *>(pArraySelf);
	Value valueRtn;
	if (arg.IsValid(0)) {
		size_t axis = arg.GetSizeT(0);
		const Array::Dimensions &dims = pArrayT->GetDimensions();
		if (axis >= dims.size()) {
			env.SetError(ERR_OutOfRangeError, "specified axis is out of range");
			return Value::Nil;
		} else if (axis == 0 && dims.size() == 1) {
			valueRtn = Value(CalcVarFlat<T_ElemResult, T_Elem>(pArrayT, populationFlag, false));
		} else {
			Array::Dimensions::const_iterator pDimAxis = dims.begin() + axis;
			AutoPtr<ArrayT<T_ElemResult> > pArrayTResult(CalcVar<T_ElemResult, T_Elem>(pArrayT, pDimAxis, populationFlag, false));
			if (pArrayTResult.IsNull()) return Value::Nil;
			valueRtn = Value(new Object_array(env, pArrayTResult.release()));
		}
	} else {
		valueRtn = Value(CalcVarFlat<T_ElemResult, T_Elem>(pArrayT, populationFlag, false));
	}
	return pFunc->ReturnValue(env, arg, valueRtn);
}

Gura_ImplementMethod(array, var)
{
	static const FuncT_Method funcTbl[Array::ETYPE_Max] = {
		nullptr,
		&FuncTmpl_var<UInt32, Boolean>,
		&FuncTmpl_var<Int8, Int8>,
		&FuncTmpl_var<UInt8, UInt8>,
		&FuncTmpl_var<Int16, Int16>,
		&FuncTmpl_var<UInt16, UInt16>,
		&FuncTmpl_var<Int32, Int32>,
		&FuncTmpl_var<UInt32, UInt32>,
		&FuncTmpl_var<Int64, Int64>,
		&FuncTmpl_var<UInt64, UInt64>,
		&FuncTmpl_var<Half, Half>,
		&FuncTmpl_var<Float, Float>,
		&FuncTmpl_var<Double, Double>,
		&FuncTmpl_var<Complex, Complex>,
		//&FuncTmpl_var<Value, Value>,
	};
	return CallMethod(env, arg, funcTbl, this, Object_array::GetObjectThis(arg)->GetArray());
}

void AssignMethods(Environment &env)
{
	Gura_AssignMethodTo(VTYPE_array, array, argmax);
	Gura_AssignMethodTo(VTYPE_array, array, argmin);
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
	Gura_AssignMethodTo(VTYPE_array, array, transpose);
	Gura_AssignMethodTo(VTYPE_array, array, var);
}

Gura_EndModuleScope(arrayt)
