#include "stdafx.h"

Gura_BeginModuleScope(ml_mnist)

//-----------------------------------------------------------------------------
// ImageSet
//-----------------------------------------------------------------------------
bool ImageSet::Read(Signal &sig, Stream &stream)
{
	
	return true;
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
	return String("<mnist.ImageSet>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.ImageSet(stream:stream) {block?}
Gura_DeclareFunction(ImageSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(ImageSet));
	AddHelp(
		Gura_Symbol(en),
		"");

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
// Implementation of class ceres.ImageSet
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(ImageSet)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(ImageSet);
	// Assignment of method
}

Gura_EndModuleScope(ml_mnist)
