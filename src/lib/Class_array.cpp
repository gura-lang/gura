//=============================================================================
// Gura class: array
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//------------------------------------------------------------------------------
// Utility functions
//------------------------------------------------------------------------------
template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
void CalcDotProduct(T_ElemResult *pElemResult, const T_ElemL *pElemL, const T_ElemR *pElemR,
				size_t rowL, size_t colL_rowR, size_t colR)
{
	const T_ElemL *pElemBaseL = pElemL;
	for (size_t iRow = 0; iRow < rowL; iRow++, pElemBaseL += colL_rowR) {
		const T_ElemR *pElemBaseR = pElemR;
		for (size_t iCol = 0; iCol < colR; iCol++, pElemBaseR++) {
			const T_ElemL *pElemWorkL = pElemBaseL;
			const T_ElemR *pElemWorkR = pElemBaseR;
			T_ElemResult elemResult = 0;
			for (size_t i = 0; i < colL_rowR; i++, pElemWorkL++, pElemWorkR += colR) {
				elemResult += static_cast<T_ElemResult>(*pElemWorkL) * *pElemWorkR;
			}
			*pElemResult++ = elemResult;
		}
	}
}

template<typename T_ElemResult, typename T_ElemL, typename T_ElemR>
Array *CalcDotProduct(const Array &arrayL, const Array &arrayR)
{
	const Array::Dimensions &dimsL = arrayL.GetDimensions();
	const Array::Dimensions &dimsR = arrayR.GetDimensions();
	size_t rowL = dimsL[0].GetSize();
	size_t colL_rowR = dimsL[1].GetSize();
	size_t colR = dimsR[1].GetSize();
	AutoPtr<ArrayT<T_ElemResult> > pArrayResult(new ArrayT<T_ElemResult>(rowL, colR));
	size_t elemNumResult = pArrayResult->GetElemNum();
	size_t elemNumL = arrayL.GetElemNum();
	size_t elemNumR = arrayR.GetElemNum();
	T_ElemResult *pElemResult = pArrayResult->GetPointer();
	const T_ElemL *pElemL = dynamic_cast<const ArrayT<T_ElemL> *>(&arrayL)->GetPointer();
	const T_ElemR *pElemR = dynamic_cast<const ArrayT<T_ElemR> *>(&arrayR)->GetPointer();
	if (dimsL.size() == dimsR.size()) {
		CalcDotProduct(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
	} else if (dimsL.size() < dimsR.size()) {
		size_t elemNumMatR = colL_rowR * colR;
		for (size_t cnt = elemNumR / elemNumMatR; cnt > 0; cnt--) {
			CalcDotProduct(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
			pElemResult += elemNumResult;
			pElemR += elemNumR;
		}
	} else { // dimsL.size() > dimsR.size()
		size_t elemNumMatL = rowL * colL_rowR;
		for (size_t cnt = elemNumL / elemNumMatL; cnt > 0; cnt--) {
			CalcDotProduct(pElemResult, pElemL, pElemR, rowL, colL_rowR, colR);
			pElemResult += elemNumResult;
			pElemL += elemNumL;
		}
	}
	return pArrayResult.release();
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
	return "<array>";
}

Value Object_array::IndexGet(Environment &env, const Value &valueIdx)
{
	return Value::Nil;
}

void Object_array::IndexSet(Environment &env, const Value &valueIdx, const Value &value)
{
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
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

typedef Array *(*ArrayOpType)(const Array &arrayL, const Array &arrayR);

ArrayOpType arrayOpMat_dot[Array::ETYPE_max][Array::ETYPE_max];

void sub()
{
	arrayOpMat_dot[Array::ETYPE_Double][Array::ETYPE_Double] = &CalcDotProduct<Double, Double, Double>;
}

Gura_ImplementClassMethod(array, dot)
{
	const Array *pArrayA = Object_array::GetObject(arg, 0)->GetArray();
	const Array *pArrayB = Object_array::GetObject(arg, 1)->GetArray();
	ArrayOpType arrayOp = arrayOpMat_dot[pArrayA->GetElemType()][pArrayB->GetElemType()];
	AutoPtr<Array> pArrayResult((*arrayOp)(*pArrayA, *pArrayB));
	return ReturnValue(env, arg, Value(new Object_array(env, pArrayResult.release())));
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
	Gura_AssignMethod(array, dot);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en + 1);
}

}
