#include "stdafx.h"

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// Cifar10
//-----------------------------------------------------------------------------
Cifar10::Cifar10() : _nImages(0)
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
	_pMemoryLabel.reset(new MemoryHeap(nImages * sizeof(UInt8)));
	_pMemoryImageData.reset(new MemoryHeap(nImages * sizeof(ImageData)));
	UInt8 *pLabel = reinterpret_cast<UInt8 *>(_pMemoryLabel->GetPointer());
	ImageData *pImageData = reinterpret_cast<ImageData *>(_pMemoryImageData->GetPointer());
	for (size_t iEntry = 0; iEntry < nImages; iEntry++) {
		if (stream.Read(sig, pLabel, sizeof(UInt8)) < sizeof(UInt8)) {
			sig.SetError(ERR_IOError, "failed to read data");
			return false;
		}
		if (stream.Read(sig, pImageData, sizeof(ImageData)) < sizeof(ImageData)) {
			sig.SetError(ERR_IOError, "failed to read data");
			return false;
		}
		pLabel++;
		pImageData++;
	}
	_nImages = nImages;
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

Array *Cifar10::ImageDataToArray(Signal &sig, bool flattenFlag, Array::ElemType elemType, bool normalizeFlag) const
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
	const UInt8 *pElemSrc = reinterpret_cast<const UInt8 *>(_pMemoryImageData->GetPointer());
	if (elemType == Array::ETYPE_UInt8) {
		bool colMajorFlag = false;
		pArray.reset(new ArrayT<UInt8>(colMajorFlag, _pMemoryImageData->Reference(), 0));
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
	::sprintf(buff, ":%zuimages", _pCifar10->GetNumImages());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.cifar.cifar10#nimages
Gura_DeclareProperty_R(cifar10, nimages)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(cifar10, nimages)
{
	const Cifar10 *pCifar10 = Object_cifar10::GetObject(valueThis)->GetCifar10();
	return Value(pCifar10->GetNumImages());
}

// ml.cifar.cifar10#nrows
Gura_DeclareProperty_R(cifar10, nrows)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(cifar10, nrows)
{
	return Value(Cifar10::nRows);
}

// ml.cifar.cifar10#ncols
Gura_DeclareProperty_R(cifar10, ncols)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(cifar10, ncols)
{
	return Value(Cifar10::nCols);
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
// ml.cifar.cifar10#imgtoarray(shape?:symbol, elemtype?:symbol, normalize?:boolean) {block?}
Gura_DeclareMethod(cifar10, imgtoarray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "shape", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "elemtype", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "normalize", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an `array` instance from the image data in CIFAR-10 database.\n"
		"\n"
		"Arguments:\n"
		"\n"
		"- `shape` .. element shape that takes `` `flat`` or `` `matrix``. Default is `` `flat``.\n"
		"- `elemtype` .. element type of created `array` that takes `` `uint8``, `` `half``, `` `float`` or `` `double``. Default is `` `float``.\n"
		"- `normalize` .. specifies whether it maps element values of `[0, 255]` into a range of `[0, 1]`.\n"
		"                 Default is `true` when `elemtype` is `` `half``, `` `float`` or `` `double``.\n"
		"                 Ignored and always treated as `false` when `elemtype` is `` `uint8``.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("array", "array"));
}

Gura_ImplementMethod(cifar10, imgtoarray)
{
	const Cifar10 *pCifar10 = Object_cifar10::GetObjectThis(arg)->GetCifar10();
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
	AutoPtr<Object_array> pObj(new Object_array(env, pCifar10->ImageDataToArray(env, flattenFlag, elemType, normalizeFlag)));
	return ReturnValue(env, arg, Value(pObj.release()));
}

//-----------------------------------------------------------------------------
// Implementation of class ml.cifar.cifar10
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(cifar10)
{
	// Assignment of properties
	Gura_AssignProperty(cifar10, nimages);
	Gura_AssignProperty(cifar10, nrows);
	Gura_AssignProperty(cifar10, ncols);
	// Assignment of function
	Gura_AssignFunction(cifar10);
	// Assignment of method
	Gura_AssignMethod(cifar10, imgtoarray);
}

Gura_EndModuleScope(ml_cifar)
