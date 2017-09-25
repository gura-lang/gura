#include "stdafx.h"

Gura_BeginModuleScope(ml_mnist)

//-----------------------------------------------------------------------------
// LabelSet
//-----------------------------------------------------------------------------
bool LabelSet::Read(Signal &sig, Stream &stream)
{
	size_t bytesRead = 0;
	Header header;
	bytesRead = stream.Read(sig, &header, sizeof(header));
	if (bytesRead < sizeof(header)) {
		sig.SetError(ERR_FormatError, "invalid format of MNIST image file");
		return false;
	}
	UInt32 magicNumber = Gura_UnpackUInt32(header.magicNumber);
	if (magicNumber != 0x00000801) {
		sig.SetError(ERR_FormatError, "invalid magic number of MNIST label file: %08x", magicNumber);
		return false;
	}
	_nLabels = Gura_UnpackUInt32(header.nLabels);
	size_t bytesLabel = _nLabels;
	_pMemory.reset(new MemoryHeap(bytesLabel));
	bytesRead = stream.Read(sig, _pMemory->GetPointer(), bytesLabel);
	if (bytesRead < bytesLabel) {
		sig.SetError(ERR_FormatError, "invalid format of MNIST label file");
		return false;
	}
	return true;
}

template<typename T_Elem>
Array *CreateArrayOfLabels(Signal &sig, const UInt8 *pElemSrc, size_t nLabels, bool onehotFlag)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT;
	if (onehotFlag) {
		size_t labelMax = 0;
		for (size_t i = 0; i < nLabels; i++) {
			UInt8 label = *(pElemSrc + i);
			if (labelMax < label) labelMax = label;
		}
		size_t nCols = labelMax + 1;
		pArrayT.reset(ArrayT<T_Elem>::Create2d(colMajorFlag, nLabels, nCols));
		pArrayT->FillZero();
		T_Elem *pElemDst = pArrayT->GetPointer();
		for (size_t i = 0; i < nLabels; i++, pElemDst += nCols) {
			UInt8 label = *(pElemSrc + i);
			*(pElemDst + label) = 1;
		}
	} else {
		pArrayT.reset(ArrayT<T_Elem>::Create1d(colMajorFlag, nLabels));
		T_Elem *pElemDst = pArrayT->GetPointer();
		for (size_t i = 0; i < nLabels; i++, pElemSrc++, pElemDst++) {
			*pElemDst = static_cast<T_Elem>(*pElemSrc);
		}
	}
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
	String str = "<mnist.labelset";
	::sprintf(buff, "labels=%zu", _pLabelSet->GetNumLabels());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.mnist.labelset#nlabels
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
	LabelSet &labelSet = Object_labelset::GetObject(valueThis)->GetLabelSet();
	return Value(labelSet.GetNumLabels());
}

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.mnist.labelset(stream:stream):map {block?}
Gura_DeclareFunction(labelset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(labelset));
	AddHelp(
		Gura_Symbol(en),
		"Reads MNIST label set file from the specified `stream`\n"
		"and returns a `ml.mnist.labelset` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("stream", "stream"));
}

Gura_ImplementFunction(labelset)
{
	std::unique_ptr<LabelSet> pLabelSet(new LabelSet());
	if (!pLabelSet->Read(env, arg.GetStream(0))) return Value::Nil;
	Object_labelset *pObj = new Object_labelset(pLabelSet.release());
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// ml.mnist.labelset#toarray(onehot?:boolean, elemtype?:symbol) {block?}
Gura_DeclareMethod(labelset, toarray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "onehot", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` instance from the MNIST label set.\n"
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
	LabelSet &labelSet = Object_labelset::GetObjectThis(arg)->GetLabelSet();
	bool onehotFlag = true;
	if (arg.IsValid(0)) {
		onehotFlag = arg.GetBoolean(0);
	}
	Array::ElemType elemType = Array::ETYPE_Float;
	if (arg.IsValid(1)) {
		elemType = Array::SymbolToElemType(env, arg.GetSymbol(1));
		if (env.IsSignalled()) return Value::Nil;
	}
	AutoPtr<Array> pArray(labelSet.ToArray(env, onehotFlag, elemType));
	if (pArray.IsNull()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class ml.mnist.labelset
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(labelset)
{
	// Assignment of properties
	Gura_AssignProperty(labelset, nlabels);
	// Assignment of function
	Gura_AssignFunction(labelset);
	// Assignment of method
	Gura_AssignMethod(labelset, toarray);
}

Gura_EndModuleScope(ml_mnist)
