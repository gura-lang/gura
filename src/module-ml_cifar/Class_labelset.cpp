#include "stdafx.h"

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// LabelSet
//-----------------------------------------------------------------------------
template<typename T_Elem>
Array *CreateArrayOfLabels(Signal &sig, const UInt8 *pElemSrc, size_t nLabels, bool onehotFlag)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT;
#if 0
	if (onehotFlag) {
		size_t nCols = 10;
		pArrayT.reset(ArrayT<T_Elem>::Create2d(colMajorFlag, nLabels, nCols));
		pArrayT->FillZero();
		T_Elem *pElemDst = pArrayT->GetPointer();
		for (size_t i = 0; i < nLabels; i++, pElemSrc++, pElemDst += nCols) {
			UInt8 label = *pElemSrc;
			if (label >= 10) {
				sig.SetError(ERR_FormatError, "invalid data in label file");
				return nullptr;
			}
			*(pElemDst + label) = 1;
		}
	} else {
		pArrayT.reset(ArrayT<T_Elem>::Create1d(colMajorFlag, nLabels));
		T_Elem *pElemDst = pArrayT->GetPointer();
		for (size_t i = 0; i < nLabels; i++, pElemSrc++, pElemDst++) {
			*pElemDst = static_cast<T_Elem>(*pElemSrc);
		}
	}
#endif
	return pArrayT.release();
}

Array *LabelSet::ToArray(Signal &sig, bool onehotFlag, Array::ElemType elemType) const
{
	bool colMajorFlag = false;
	AutoPtr<Array> pArray;
	const UInt8 *pElemSrc = reinterpret_cast<const UInt8 *>(_pMemory->GetPointer());
	if (elemType == Array::ETYPE_UInt8) {
		if (onehotFlag) {
			pArray.reset(CreateArrayOfLabels<UInt8>(sig, pElemSrc, _nLabels, onehotFlag));
		} else {
			pArray.reset(new ArrayT<UInt8>(colMajorFlag, _pMemory->Reference(), 0));
			pArray->SetDimension(_nLabels);
		}
	} else if (elemType == Array::ETYPE_Half) {
		pArray.reset(CreateArrayOfLabels<Half>(sig, pElemSrc, _nLabels, onehotFlag));
	} else if (elemType == Array::ETYPE_Float) {
		pArray.reset(CreateArrayOfLabels<Float>(sig, pElemSrc, _nLabels, onehotFlag));
	} else if (elemType == Array::ETYPE_Double) {
		pArray.reset(CreateArrayOfLabels<Double>(sig, pElemSrc, _nLabels, onehotFlag));
	} else {
		sig.SetError(ERR_ValueError, "can't create an array of %s", Array::GetElemTypeName(elemType));
		return nullptr;
	}
	return sig.IsSignalled()? nullptr : pArray.release();
}

void LabelSet::AllocMemory(size_t nLabels)
{
	_pMemory.reset(new MemoryHeap(nLabels * sizeof(UInt8)));
	_nLabels = nLabels;
}

//-----------------------------------------------------------------------------
// Object_labelset implementation
//-----------------------------------------------------------------------------
Object_labelset::Object_labelset(LabelSet *pLabelSet) :
					Object(Gura_UserClass(labelset)), _pLabelSet(pLabelSet)
{
}

String Object_labelset::ToString(bool exprFlag)
{
	char buff[80];
	String str = "<cifar.labelset";
	::sprintf(buff, "labels=%zu", _pLabelSet->GetNumLabels());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.cifar.labelset#nlabels
Gura_DeclareProperty_R(labelset, nlabels)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(labelset, nlabels)
{
	LabelSet *pLabelSet = Object_labelset::GetObject(valueThis)->GetLabelSet();
	return Value(pLabelSet->GetNumLabels());
}

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// ml.cifar.labelset#toarray(onehot?:boolean, elemtype?:symbol) {block?}
Gura_DeclareMethod(labelset, toarray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "onehot", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` instance from the CIFAR label set.\n"
		"\n"
		"Arguments:\n"
		"\n"
		"- `onehot` .. one-hot data is created when set to `true`. Raw data is stored otherwise. Default is `true`.\n"
		"- `elemtype` .. element type of created `array` that takes `` `uint8``, `` `half``, `` `float`` or `` `double``. Default is `` `float``.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(labelset, toarray)
{
	LabelSet *pLabelSet = Object_labelset::GetObjectThis(arg)->GetLabelSet();
	bool onehotFlag = true;
	if (arg.IsValid(0)) {
		onehotFlag = arg.GetBoolean(0);
	}
	Array::ElemType elemType = Array::ETYPE_Float;
	if (arg.IsValid(1)) {
		elemType = Array::SymbolToElemType(env, arg.GetSymbol(1));
		if (env.IsSignalled()) return Value::Nil;
	}
	AutoPtr<Array> pArray(pLabelSet->ToArray(env, onehotFlag, elemType));
	if (pArray.IsNull()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class ml.cifar.labelset
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(labelset)
{
	// Assignment of properties
	Gura_AssignProperty(labelset, nlabels);
	// Assignment of function
	// Assignment of method
	Gura_AssignMethod(labelset, toarray);
}

Gura_EndModuleScope(ml_cifar)
