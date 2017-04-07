#include "stdafx.h"
#include "Class_problem.h"

Gura_BeginModuleScope(ml_linear)

//-----------------------------------------------------------------------------
// Entry
//-----------------------------------------------------------------------------
Entry *Entry::Create(Signal &sig, const Value &valueY, const ValueList &valListX)
{
	if (!valueY.Is_number()) {
		sig.SetError(ERR_ValueError, "y must be a number");
		return nullptr;
	}
	if (valListX.GetValueTypeOfElements() != VTYPE_number) {
		sig.SetError(ERR_ValueError, "x must contain numbers");
		return nullptr;
	}
	Entry *pEntry = reinterpret_cast<Entry *>(
		::malloc(sizeof(Entry) + sizeof(struct feature_node) * valListX.size()));
	pEntry->y = valueY.GetDouble();
	foreach_const (ValueList, pValueX, valListX) {
		//pEntry->feature_node
	}
	return pEntry;
}

//-----------------------------------------------------------------------------
// EntryOwner
//-----------------------------------------------------------------------------
EntryOwner::~EntryOwner()
{
	Clear();
}

void EntryOwner::Clear()
{
	foreach (EntryOwner, ppEntry, *this) {
		::free(*ppEntry);
	}
}

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

Object_problem::~Object_problem()
{
	delete[] _prob.y;
	delete[] _prob.x;
}

String Object_problem::ToString(bool exprFlag)
{
	return String("<ml.linear.problem>");
}

struct problem &Object_problem::UpdateEntity()
{
	delete[] _prob.y;
	delete[] _prob.x;
	_prob.l = _prob.n = 0;
	_prob.y = nullptr;
	_prob.x = nullptr;
	return _prob;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// ml.linear.problem.add()
Gura_DeclareMethod(problem, add)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(problem, add)
{
	Object_problem *pObjProb = Object_problem::GetObjectThis(arg);
	return Value::Nil;
}

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
	// Assignment of methods
	Gura_AssignMethod(problem, add);
	// Assignment of function
	Gura_AssignFunction(problem);
	// Assignment of value
	Gura_AssignValue(problem, Value(Reference()));
}

Gura_EndModuleScope(ml_linear)
