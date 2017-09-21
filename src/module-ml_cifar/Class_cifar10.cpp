#include "stdafx.h"

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// Cifar10
//-----------------------------------------------------------------------------
Cifar10::Cifar10() : _nEntries(0)
{
}

bool Cifar10::Read(Signal &sig, Stream &stream)
{
	size_t bytesFile = stream.GetSize();
	if (bytesFile == InvalidSize) {
		sig.SetError(ERR_IOError, "size of the stream is unavailable");
		return false;
	}
	size_t nEntries = bytesFile / Cifar10::EntryBytes;
	_pMemoryLabel.reset(new MemoryHeap(nEntries * sizeof(UChar)));
	_pMemoryImageData.reset(new MemoryHeap(nEntries * sizeof(ImageData)));
	UChar *pLabel = reinterpret_cast<UChar *>(_pMemoryLabel->GetPointer());
	ImageData *pImageData = reinterpret_cast<ImageData *>(_pMemoryImageData->GetPointer());
	for (size_t iEntry = 0; iEntry < nEntries; iEntry++) {
		if (stream.Read(sig, pLabel, sizeof(UChar)) < sizeof(UChar)) {
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
	return true;
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
	::sprintf(buff, ":%zuentries", _pCifar10->GetNumEntries());
	str += buff;
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// ml.cifar.cifar10#nentries
Gura_DeclareProperty_R(cifar10, nentries)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(cifar10, nentries)
{
	const Cifar10 *pCifar10 = Object_cifar10::GetObject(valueThis)->GetCifar10();
	return Value(pCifar10->GetNumEntries());
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

//-----------------------------------------------------------------------------
// Implementation of class ml.cifar.cifar10
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(cifar10)
{
	// Assignment of properties
	Gura_AssignProperty(cifar10, nentries);
	Gura_AssignProperty(cifar10, nrows);
	Gura_AssignProperty(cifar10, ncols);
	// Assignment of function
	Gura_AssignFunction(cifar10);
	// Assignment of method
}

Gura_EndModuleScope(ml_cifar)
