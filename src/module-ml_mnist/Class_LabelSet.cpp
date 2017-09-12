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
		pArray.reset(ArrayT<UInt8>::Create2d(colMajorFlag, _nLabels, nCols));
		pArray->FillZero();
		const UInt8 *pLabel = reinterpret_cast<const UInt8 *>(_pMemory->GetPointer());
		UInt8 *pDst = dynamic_cast<ArrayT<UInt8> *>(pArray.get())->GetPointer();
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
// ml.mnist.LabelSet#ToArray(format?:symbol) {block?}
Gura_DeclareMethod(LabelSet, ToArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "rawdata", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(LabelSet, ToArray)
{
	LabelSet &labelSet = Object_LabelSet::GetObjectThis(arg)->GetLabelSet();
	bool rawDataFlag = arg.IsValid(0) && arg.GetBoolean(0);
	AutoPtr<Array> pArray(labelSet.ToArray(env, rawDataFlag));
	if (pArray.IsNull()) return Value::Nil;
	AutoPtr<Object_array> pObj(new Object_array(env, pArray.release()));
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
