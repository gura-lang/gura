#include "stdafx.h"

Gura_BeginModuleScope(ceres)

//-----------------------------------------------------------------------------
// Object_Solver_Summary implementation
//-----------------------------------------------------------------------------
Object_Solver_Summary::Object_Solver_Summary() : Object(Gura_UserClass(Solver_Summary))
{
}

String Object_Solver_Summary::ToString(bool exprFlag)
{
	return String("<ceres.Solver$Summary>");
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of function
//-----------------------------------------------------------------------------
// ceres.Solver$Summary() {block?}
Gura_DeclareFunctionAlias(Solver_Summary, "Solver$Summary")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(Solver_Summary));
	AddHelp(
		Gura_Symbol(en),
		"");

}

Gura_ImplementFunction(Solver_Summary)
{
	Object_Solver_Summary *pObj = new Object_Solver_Summary();
	return ReturnValue(env, arg, Value(pObj));
}

//-----------------------------------------------------------------------------
// Implementation of method
//-----------------------------------------------------------------------------
Gura_DeclareMethod(Solver_Summary, BriefReport)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(Solver_Summary, BriefReport)
{
	ceres::Solver::Summary &summary = Object_Solver_Summary::GetObjectThis(arg)->GetSummary();
	return Value(summary.BriefReport().c_str());
}

//-----------------------------------------------------------------------------
// Implementation of class ceres.Solver$Summary
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(Solver_Summary)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(Solver_Summary);
	// Assignment of method
	Gura_AssignMethod(Solver_Summary, BriefReport);
}

Gura_EndModuleScope(ceres)
