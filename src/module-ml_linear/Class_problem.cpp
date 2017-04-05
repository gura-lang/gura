#include "stdafx.h"
#include "Class_problem.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Object_problem implementation
//-----------------------------------------------------------------------------
Object_problem::Object_problem() : Object(Gura_UserClass(problem))
{
	::memset(&_prob, 0x00, sizeof(_prob));
	_prob.l = _prob.n = 0;
	_prob.y = nullptr;
	_prob.x = nullptr;
	_prob.bias = 0;
}

String Object_problem::ToString(bool exprFlag)
{
	return String("<ml.linear.problem>");
}

bool Object_problem::HasValidEntity() const
{
	return false;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// ml.linear.problem() {block?}
Gura_DeclareFunction(problem)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(Gura_UserClass(problem));
	AddHelp(
		Gura_Symbol(en),
		"Creates an instance of ml.linear.problem.\n");
}

Gura_ImplementFunction(problem)
{
	return ReturnValue(env, arg, Value(new Object_problem()));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(problem)
{
	// Assignment of properties
	// Assignment of function
	Gura_AssignFunction(problem);
	// Assignment of value
	Gura_AssignValue(problem, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
