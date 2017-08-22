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
	_nColumns = Gura_UnpackUInt32(header.nColumns);
	size_t bytesImage = _nImages * _nRows * _nColumns;
	_pMemory.reset(new MemoryHeap(bytesImage));
	bytesRead = stream.Read(sig, _pMemory->GetPointer(), bytesImage);
	if (bytesRead < bytesImage) {
		sig.SetError(ERR_FormatError, "invalid format of MNIST image file");
		return false;
	}
	return true;
}

Array *ImageSet::ToArray(bool flattenFlag) const
{
	AutoPtr<ArrayT<UInt8> > pArrayT(new ArrayT<UInt8>(_pMemory->Reference(), 0));
	Array::Dimensions dims;
	dims.push_back(Array::Dimension(_nImages));
	if (flattenFlag) {
		dims.push_back(Array::Dimension(_nRows * _nColumns));
	} else {
		dims.push_back(Array::Dimension(_nRows));
		dims.push_back(Array::Dimension(_nColumns));
	}
	pArrayT->SetDimensions(dims);
	return pArrayT.release();
}

//-----------------------------------------------------------------------------
// Object_ImageSet implementation
//-----------------------------------------------------------------------------
Object_ImageSet::Object_ImageSet(ImageSet *pImageSet) :
					Object(Gura_UserClass(ImageSet)), _pImageSet(pImageSet)
{
}

String Object_ImageSet::ToString(bool exprFlag)
{
	char buff[80];
	String str = "<mnist.ImageSet";
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
// ml.mnist.ImageSet#nImages
Gura_DeclareProperty_R(ImageSet, nImages)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(ImageSet, nImages)
{
	ImageSet &imageSet = Object_ImageSet::GetObject(valueThis)->GetImageSet();
	return Value(imageSet.GetNumImages());
}

// ml.mnist.ImageSet#nRows
Gura_DeclareProperty_R(ImageSet, nRows)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(ImageSet, nRows)
{
	ImageSet &imageSet = Object_ImageSet::GetObject(valueThis)->GetImageSet();
	return Value(imageSet.GetNumRows());
}

// ml.mnist.ImageSet#nColumns
Gura_DeclareProperty_R(ImageSet, nColumns)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(ImageSet, nColumns)
{
	ImageSet &imageSet = Object_ImageSet::GetObject(valueThis)->GetImageSet();
	return Value(imageSet.GetNumColumns());
}

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.mnist.ImageSet(stream:stream):map {block?}
Gura_DeclareFunction(ImageSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(ImageSet));
	AddHelp(
		Gura_Symbol(en),
		"Reads MNIST image set file from the specified `stream`\n"
		"and returns a `ml.mnist.ImageSet` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("stream", "stream"));
}

Gura_ImplementFunction(ImageSet)
{
	std::unique_ptr<ImageSet> pImageSet(new ImageSet());
	if (!pImageSet->Read(env, arg.GetStream(0))) return Value::Nil;
	Object_ImageSet *pObj = new Object_ImageSet(pImageSet.release());
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
// ml.mnist.ImageSet#ToArray(format?:symbol) {block?}
Gura_DeclareMethod(ImageSet, ToArray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(ImageSet, ToArray)
{
	ImageSet &imageSet = Object_ImageSet::GetObjectThis(arg)->GetImageSet();
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
	AutoPtr<Object_array> pObj(new Object_array(env, imageSet.ToArray(flattenFlag)));
	return ReturnValue(env, arg, Value(pObj.release()));
}

//-----------------------------------------------------------------------------
// Implementation of class ml.mnist.ImageSet
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(ImageSet)
{
	// Assignment of properties
	Gura_AssignProperty(ImageSet, nImages);
	Gura_AssignProperty(ImageSet, nRows);
	Gura_AssignProperty(ImageSet, nColumns);
	// Assignment of function
	Gura_AssignFunction(ImageSet);
	// Assignment of method
	Gura_AssignMethod(ImageSet, ToArray);
}

Gura_EndModuleScope(ml_mnist)
