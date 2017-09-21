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

Array *LabelSet::ToArray(Signal &sig, bool rawDataFlag) const
{
	bool colMajorFlag = false;
	AutoPtr<Array> pArray;
	if (rawDataFlag) {
		pArray.reset(new ArrayT<UInt8>(colMajorFlag, _pMemory->Reference(), 0));
		pArray->SetDimension(_nLabels);
	} else {
		size_t nCols = 10;
		pArray.reset(ArrayT<Float>::Create2d(colMajorFlag, _nLabels, nCols));
		pArray->FillZero();
		const UInt8 *pLabel = reinterpret_cast<const UInt8 *>(_pMemory->GetPointer());
		Float *pDst = dynamic_cast<ArrayT<Float> *>(pArray.get())->GetPointer();
		for (size_t i = 0; i < _nLabels; i++, pLabel++) {
			UInt8 label = *pLabel;
			if (label >= 10) {
				sig.SetError(ERR_FormatError, "invalid data in label file");
				return nullptr;
			}
			*(pDst + label) = 1;
			pDst += nCols;
		}
	}
	return pArray.release();
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
// ml.mnist.labelset#toarray(rawdata?:boolean) {block?}
Gura_DeclareMethod(labelset, toarray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rawdata", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(labelset, toarray)
{
	LabelSet &labelSet = Object_labelset::GetObjectThis(arg)->GetLabelSet();
	bool rawDataFlag = arg.IsValid(0) && arg.GetBoolean(0);
	AutoPtr<Array> pArray(labelSet.ToArray(env, rawDataFlag));
	if (pArray.IsNull()) return Value::Nil;
	AutoPtr<Object_array> pObj(new Object_array(env, pArray.release()));
	return ReturnValue(env, arg, Value(pObj.release()));
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
