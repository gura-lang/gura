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

Array *LabelSet::ToArray() const
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<UInt8> > pArrayT(new ArrayT<UInt8>(colMajorFlag, _pMemory->Reference(), 0));
	Array::Dimensions dims;
	dims.push_back(Array::Dimension(_nLabels));
	pArrayT->SetDimensions(dims);
	return pArrayT.release();
}

//-----------------------------------------------------------------------------
// Object_LabelSet implementation
//-----------------------------------------------------------------------------
Object_LabelSet::Object_LabelSet(LabelSet *pLabelSet) :
					Object(Gura_UserClass(LabelSet)), _pLabelSet(pLabelSet)
{
}

String Object_LabelSet::ToString(bool exprFlag)
{
	char buff[80];
	String str = "<mnist.LabelSet";
	::sprintf(buff, "labels=%zu", _pLabelSet->GetNumLabels());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.mnist.LabelSet#nLabels
Gura_DeclareProperty_R(LabelSet, nLabels)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(LabelSet, nLabels)
{
	LabelSet &labelSet = Object_LabelSet::GetObject(valueThis)->GetLabelSet();
	return Value(labelSet.GetNumLabels());
}

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.mnist.LabelSet(stream:stream):map {block?}
Gura_DeclareFunction(LabelSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(LabelSet));
	AddHelp(
		Gura_Symbol(en),
		"Reads MNIST label set file from the specified `stream`\n"
		"and returns a `ml.mnist.LabelSet` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("stream", "stream"));
}

Gura_ImplementFunction(LabelSet)
{
	std::unique_ptr<LabelSet> pLabelSet(new LabelSet());
	if (!pLabelSet->Read(env, arg.GetStream(0))) return Value::Nil;
	Object_LabelSet *pObj = new Object_LabelSet(pLabelSet.release());
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// ml.mnist.LabelSet#ToArray() {block?}
Gura_DeclareMethod(LabelSet, ToArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(LabelSet, ToArray)
{
	LabelSet &labelSet = Object_LabelSet::GetObjectThis(arg)->GetLabelSet();
	AutoPtr<Object_array> pObj(new Object_array(env, labelSet.ToArray()));
	return ReturnValue(env, arg, Value(pObj.release()));
}

//-----------------------------------------------------------------------------
// Implementation of class ml.mnist.LabelSet
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(LabelSet)
{
	// Assignment of properties
	Gura_AssignProperty(LabelSet, nLabels);
	// Assignment of function
	Gura_AssignFunction(LabelSet);
	// Assignment of method
	Gura_AssignMethod(LabelSet, ToArray);
}

Gura_EndModuleScope(ml_mnist)
