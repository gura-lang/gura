#include "stdafx.h"

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// Cifar10
//-----------------------------------------------------------------------------
Cifar10::Cifar10() : _pLabelSet(new LabelSet()), _pImageSet(new ImageSet())
{
}

bool Cifar10::Read(Signal &sig, Stream &stream)
{
	size_t bytesFile = stream.GetSize();
	if (bytesFile == InvalidSize) {
		sig.SetError(ERR_IOError, "size of the stream is unavailable");
		return false;
	}
	size_t nImages = bytesFile / Cifar10::EntryBytes;
	_pLabelSet->AllocMemory(nImages);
	_pImageSet->AllocMemory(nImages);
	UInt8 *pLabel = _pLabelSet->GetPointer();
	ImageSet::Packed *pPacked = _pImageSet->GetPointer();
	for (size_t iEntry = 0; iEntry < nImages; iEntry++) {
		if (stream.Read(sig, pLabel, sizeof(UInt8)) < sizeof(UInt8)) {
			sig.SetError(ERR_IOError, "failed to read data");
			return false;
		}
		if (stream.Read(sig, pPacked, sizeof(ImageSet::Packed)) < sizeof(ImageSet::Packed)) {
			sig.SetError(ERR_IOError, "failed to read data");
			return false;
		}
		pLabel++;
		pPacked++;
	}
	return true;
}

#if 0
template<typename T_Elem>
Array *CreateArrayOfImages(const Array::Dimensions &dims, const UInt8 *pElemSrc, bool normalizeFlag)
{
	bool colMajorFlag = false;
	AutoPtr<ArrayT<T_Elem> > pArrayT(ArrayT<T_Elem>::Create(colMajorFlag, dims));
	size_t nElems = pArrayT->GetElemNum();
	T_Elem *pElemDst = pArrayT->GetPointer();
	if (normalizeFlag) {
		for (size_t i = 0; i < nElems; i++, pElemSrc++, pElemDst++) {
			*pElemDst = static_cast<T_Elem>(*pElemSrc) / 255;
		}
	} else {
		for (size_t i = 0; i < nElems; i++, pElemSrc++, pElemDst++) {
			*pElemDst = static_cast<T_Elem>(*pElemSrc);
		}
	}
	return pArrayT.release();
}

Array *ImageSet::ToArray(Signal &sig, bool flattenFlag, Array::ElemType elemType, bool normalizeFlag) const
{
	bool colMajorFlag = false;
	AutoPtr<Array > pArray;
	Array::Dimensions dims;
	dims.push_back(Array::Dimension(_nImages));
	dims.push_back(Array::Dimension(nPlanes));
	if (flattenFlag) {
		dims.push_back(Array::Dimension(nRows * nCols));
	} else {
		dims.push_back(Array::Dimension(nRows));
		dims.push_back(Array::Dimension(nCols));
	}
	const UInt8 *pElemSrc = reinterpret_cast<const UInt8 *>(_pMemory->GetPointer());
	if (elemType == Array::ETYPE_UInt8) {
		bool colMajorFlag = false;
		pArray.reset(new ArrayT<UInt8>(colMajorFlag, _pMemory->Reference(), 0));
		pArray->SetDimensions(dims);
	} else if (elemType == Array::ETYPE_Half) {
		pArray.reset(CreateArrayOfImages<Half>(dims, pElemSrc, normalizeFlag));
	} else if (elemType == Array::ETYPE_Float) {
		pArray.reset(CreateArrayOfImages<Float>(dims, pElemSrc, normalizeFlag));
	} else if (elemType == Array::ETYPE_Double) {
		pArray.reset(CreateArrayOfImages<Double>(dims, pElemSrc, normalizeFlag));
	} else {
		sig.SetError(ERR_ValueError, "can't create an array of %s", Array::GetElemTypeName(elemType));
		return nullptr;
	}
	return pArray.release();
}
#endif

//-----------------------------------------------------------------------------
// Object_cifar10 implementation
//-----------------------------------------------------------------------------
Object_cifar10::Object_cifar10(Cifar10 *pCifar10) :
					Object(Gura_UserClass(cifar10)), _pCifar10(pCifar10)
{
}

String Object_cifar10::ToString(bool exprFlag)
{
	char buff[80];
	String str = "<cifar.cifar10";
	//::sprintf(buff, ":%zuimages", _pCifar10->GetNumImages());
	//str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.cifar.cifar10#labelset
Gura_DeclareProperty_R(cifar10, labelset)
{
	SetPropAttr(VTYPE_labelset);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(cifar10, labelset)
{
	const Cifar10 *pCifar10 = Object_cifar10::GetObject(valueThis)->GetCifar10();
	return Value(new Object_labelset(pCifar10->GetLabelSet()->Reference()));
}

// ml.cifar.cifar10#imageset
Gura_DeclareProperty_R(cifar10, imageset)
{
	SetPropAttr(VTYPE_imageset);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(cifar10, imageset)
{
	const Cifar10 *pCifar10 = Object_cifar10::GetObject(valueThis)->GetCifar10();
	return Value(new Object_imageset(pCifar10->GetImageSet()->Reference()));
}

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.cifar.cifar10(stream:stream):map {block?}
Gura_DeclareFunction(cifar10)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(cifar10));
	AddHelp(
		Gura_Symbol(en),
		"Reads CIFAR image set file from the specified `stream`\n"
		"and returns a `ml.cifar.cifar10` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("stream", "stream"));
}

Gura_ImplementFunction(cifar10)
{
	Stream &stream = arg.GetStream(0);
	std::unique_ptr<Cifar10> pCifar10(new Cifar10());
	if (!pCifar10->Read(env, stream)) return Value::Nil;
	Object_cifar10 *pObj = new Object_cifar10(pCifar10.release());
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class ml.cifar.cifar10
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(cifar10)
{
	// Assignment of properties
	Gura_AssignProperty(cifar10, labelset);
	Gura_AssignProperty(cifar10, imageset);
	// Assignment of function
	Gura_AssignFunction(cifar10);
	// Assignment of method
}

Gura_EndModuleScope(ml_cifar)
