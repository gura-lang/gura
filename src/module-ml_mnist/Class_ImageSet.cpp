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
	AutoPtr<Memory> pMemory(new MemoryHeap(bytesImage));
	bytesRead = stream.Read(sig, pMemory->GetPointer(), bytesImage);
	if (bytesRead < bytesImage) {
		sig.SetError(ERR_FormatError, "invalid format of MNIST image file");
		return false;
	}
	return true;
}

const Array *ImageSet::GetArray() const
{
	AutoPtr<ArrayT<UInt8> > pArrayT(new ArrayT<UInt8>(_pMemory->Reference(), 0));
	Array::Dimensions dims;
	dims.push_back(Array::Dimension(_nImages));
	dims.push_back(Array::Dimension(_nRows));
	dims.push_back(Array::Dimension(_nColumns));
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

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ml.mnist.ImageSet(stream:stream) {block?}
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

//-----------------------------------------------------------------------------
// Implementation of class ml.mnist.ImageSet
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(ImageSet)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(ImageSet);
	// Assignment of method
}

Gura_EndModuleScope(ml_mnist)
