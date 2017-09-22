#include "stdafx.h"

Gura_BeginModuleScope(ml_mnist)

//-----------------------------------------------------------------------------
// ImageSet
//-----------------------------------------------------------------------------
bool ImageSet::Read(Signal &sig, Stream &stream)
{
	size_t bytesRead = 0;
	Header header;
	bytesRead = stream.Read(sig, &header, sizeof(header));
	if (bytesRead < sizeof(header)) {
		sig.SetError(ERR_FormatError, "invalid format of MNIST image file");
		return false;
	}
	UInt32 magicNumber = Gura_UnpackUInt32(header.magicNumber);
	if (magicNumber != 0x00000803) {
		sig.SetError(ERR_FormatError, "invalid magic number of MNIST image file: %08x", magicNumber);
		return false;
	}
	_nImages = Gura_UnpackUInt32(header.nImages);
	_nRows = Gura_UnpackUInt32(header.nRows);
	_nCols = Gura_UnpackUInt32(header.nCols);
	size_t bytesImage = _nImages * _nRows * _nCols;
	_pMemory.reset(new MemoryHeap(bytesImage));
	bytesRead = stream.Read(sig, _pMemory->GetPointer(), bytesImage);
	if (bytesRead < bytesImage) {
		sig.SetError(ERR_FormatError, "invalid format of MNIST image file");
		return false;
	}
	return true;
}

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
	AutoPtr<Array > pArray;
	Array::Dimensions dims;
	dims.push_back(Array::Dimension(_nImages));
	if (flattenFlag) {
		dims.push_back(Array::Dimension(_nRows * _nCols));
	} else {
		dims.push_back(Array::Dimension(_nRows));
		dims.push_back(Array::Dimension(_nCols));
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

//-----------------------------------------------------------------------------
// Object_imageset implementation
//-----------------------------------------------------------------------------
Object_imageset::Object_imageset(ImageSet *pImageSet) :
					Object(Gura_UserClass(imageset)), _pImageSet(pImageSet)
{
}

String Object_imageset::ToString(bool exprFlag)
{
	char buff[80];
	String str = "<mnist.imageset";
	::sprintf(buff, ":images=%zu", _pImageSet->GetNumImages());
	str += buff;
	::sprintf(buff, ":rows=%zu", _pImageSet->GetNumRows());
	str += buff;
	::sprintf(buff, ":columns=%zu", _pImageSet->GetNumColumns());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.mnist.imageset#nimages
Gura_DeclareProperty_R(imageset, nimages)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(imageset, nimages)
{
	ImageSet &imageSet = Object_imageset::GetObject(valueThis)->GetImageSet();
	return Value(imageSet.GetNumImages());
}

// ml.mnist.imageset#nrows
Gura_DeclareProperty_R(imageset, nrows)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(imageset, nrows)
{
	ImageSet &imageSet = Object_imageset::GetObject(valueThis)->GetImageSet();
	return Value(imageSet.GetNumRows());
}

// ml.mnist.imageset#ncols
Gura_DeclareProperty_R(imageset, ncols)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(imageset, ncols)
{
	ImageSet &imageSet = Object_imageset::GetObject(valueThis)->GetImageSet();
	return Value(imageSet.GetNumColumns());
}

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.mnist.imageset(stream:stream):map {block?}
Gura_DeclareFunction(imageset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(imageset));
	AddHelp(
		Gura_Symbol(en),
		"Reads MNIST image set file from the specified `stream`\n"
		"and returns a `ml.mnist.imageset` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("stream", "stream"));
}

Gura_ImplementFunction(imageset)
{
	std::unique_ptr<ImageSet> pImageSet(new ImageSet());
	if (!pImageSet->Read(env, arg.GetStream(0))) return Value::Nil;
	Object_imageset *pObj = new Object_imageset(pImageSet.release());
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// ml.mnist.imageset#toarray(shape?:symbol, elemtype?:symbol, normlize?:boolean):map {block?}
Gura_DeclareMethod(imageset, toarray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "shape", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "normalize", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` instance from the MNIST image set.\n"
		"\n"
		"Arguments:\n"
		"\n"
		"- `shape` .. element shape that takes `` `flat`` or `` `matrix``. Default is `` `flat``.\n"
		"- `elemtype` .. element type of created `array` that takes `` `uint8``, `` `half``, `` `float`` or `` `double``. Default is `` `float``.\n"
		"- `normalize` .. specifies whether it normlizes element values into a range of `[0, 1)`.\n"
		"                 Default is `true` when `elemtype` is `` `half``, `` `float`` or `` `double``.\n"
		"                 Ignored and always treated as `false` when `elemtype` is `` `uint8``.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(imageset, toarray)
{
	ImageSet &imageSet = Object_imageset::GetObjectThis(arg)->GetImageSet();
	bool flattenFlag = false;
	if (arg.IsValid(0)) {
		const Symbol *pSymbol = arg.GetSymbol(0);
		if (pSymbol->IsIdentical(Gura_Symbol(flat))) {
			flattenFlag = true;
		} else if (pSymbol->IsIdentical(Gura_Symbol(matrix))) {
			flattenFlag = false;
		} else {
			env.SetError(ERR_ValueError, "argument format takes `` `flat` or `` `matrix``");
			return Value::Nil;
		}
	}
	Array::ElemType elemType = Array::ETYPE_Float;
	if (arg.IsValid(1)) {
		elemType = Array::SymbolToElemType(env, arg.GetSymbol(1));
		if (env.IsSignalled()) return Value::Nil;
	}
	bool normalizeFlag = (elemType != Array::ETYPE_UInt8);
	if (arg.IsValid(2)) {
		normalizeFlag = arg.GetBoolean(2);
	}
	AutoPtr<Array> pArray(imageSet.ToArray(env, flattenFlag, elemType, normalizeFlag));
	if (pArray.IsNull()) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_array(env, pArray.release())));
}

//-----------------------------------------------------------------------------
// Implementation of class ml.mnist.imageset
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(imageset)
{
	// Assignment of properties
	Gura_AssignProperty(imageset, nimages);
	Gura_AssignProperty(imageset, nrows);
	Gura_AssignProperty(imageset, ncols);
	// Assignment of function
	Gura_AssignFunction(imageset);
	// Assignment of method
	Gura_AssignMethod(imageset, toarray);
}

Gura_EndModuleScope(ml_mnist)
