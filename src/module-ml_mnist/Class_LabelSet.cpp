#include "stdafx.h"

Gura_BeginModuleScope(ml_mnist)

//-----------------------------------------------------------------------------
// Object_LabelSet implementation
//-----------------------------------------------------------------------------
Object_LabelSet::Object_LabelSet(LabelSet *pLabelSet) :
					Object(Gura_UserClass(LabelSet)), _pLabelSet(pLabelSet)
{
}

String Object_LabelSet::ToString(bool exprFlag)
{
	return String("<mnist.LabelSet>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.LabelSet(stream:stream) {block?}
Gura_DeclareFunction(LabelSet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(LabelSet));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(LabelSet)
{
	Object_LabelSet *pObj = new Object_LabelSet(nullptr);
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of class ceres.LabelSet
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(LabelSet)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(LabelSet);
	// Assignment of method
}

Gura_EndModuleScope(ml_mnist)
