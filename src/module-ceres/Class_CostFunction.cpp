#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_CostFunction implementation
//-----------------------------------------------------------------------------
Object_CostFunction::Object_CostFunction() : Object(Gura_UserClass(CostFunction)), _pCostFunction(nullptr)
{
}

String Object_CostFunction::ToString(bool exprFlag)
{
	String str = "<ceres.CostFunction";
	if (_pCostFunction == nullptr) str += ":invalid";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.CostFunction() {block?}
Gura_DeclareFunction(CostFunction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(CostFunction));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(CostFunction)
{
	Object_CostFunction *pObj = new Object_CostFunction();
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of class ceres.CostFunction
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(CostFunction)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(CostFunction);
}

Gura_EndModuleScope(ceres)
