#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_LossFunction implementation
//-----------------------------------------------------------------------------
Object_LossFunction::Object_LossFunction() : Object(Gura_UserClass(LossFunction))
{
}

String Object_LossFunction::ToString(bool exprFlag)
{
	return String("<ceres.LossFunction>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.LossFunction() {block?}
Gura_DeclareFunction(LossFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(LossFunction));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(LossFunction)
{
	Object_LossFunction *pObj = new Object_LossFunction();
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Gura interfaces for ceres.LossFunction
//-----------------------------------------------------------------------------
// implementation of class ceres.LossFunction
Gura_ImplementUserClass(LossFunction)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(LossFunction);
}

Gura_EndModuleScope(ceres)
