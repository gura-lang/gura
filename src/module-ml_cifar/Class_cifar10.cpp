#include "stdafx.h"

Gura_BeginModuleScope(ml_cifar)

//-----------------------------------------------------------------------------
// ImageSet
//-----------------------------------------------------------------------------

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
// ml.mnist.ImageSet#nimages
Gura_DeclareProperty_R(ImageSet, nimages)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(ImageSet, nimages)
{
	ImageSet &imageSet = Object_ImageSet::GetObject(valueThis)->GetImageSet();
	return Value(imageSet.GetNumImages());
}

// ml.mnist.ImageSet#nrows
Gura_DeclareProperty_R(ImageSet, nrows)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(ImageSet, nrows)
{
	ImageSet &imageSet = Object_ImageSet::GetObject(valueThis)->GetImageSet();
	return Value(imageSet.GetNumRows());
}

// ml.mnist.ImageSet#ncols
Gura_DeclareProperty_R(ImageSet, ncols)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(ImageSet, ncols)
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
// ml.mnist.ImageSet#toarray(format?:symbol, rawdata?:boolean) {block?}
Gura_DeclareMethod(ImageSet, toarray)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareArg(env, "rawdata", VTYPE_boolean, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(ImageSet, toarray)
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
	bool rawDataFlag = false;
	AutoPtr<Object_array> pObj(new Object_array(env, imageSet.ToArray(flattenFlag, rawDataFlag)));
	return ReturnValue(env, arg, Value(pObj.release()));
}

//-----------------------------------------------------------------------------
// Implementation of class ml.mnist.ImageSet
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(ImageSet)
{
	// Assignment of properties
	Gura_AssignProperty(ImageSet, nimages);
	Gura_AssignProperty(ImageSet, nrows);
	Gura_AssignProperty(ImageSet, ncols);
	// Assignment of function
	Gura_AssignFunction(ImageSet);
	// Assignment of method
	Gura_AssignMethod(ImageSet, toarray);
}

Gura_EndModuleScope(ml_cifar)
