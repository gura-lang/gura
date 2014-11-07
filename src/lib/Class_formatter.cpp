//=============================================================================
// Gura class: formatter
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_formatter
//-----------------------------------------------------------------------------
Object_formatter::Object_formatter(const Object_formatter &obj) :
										Object(obj), _flags(obj._flags)
{
}

Object_formatter::~Object_formatter()
{
}

Object *Object_formatter::Clone() const
{
	return new Object_formatter(*this);
}

bool Object_formatter::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_formatter::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

String Object_formatter::ToString(bool exprFlag)
{
	String str;
	str += "<formatter:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// formatter#getfieldminwidth()
Gura_DeclareMethod(formatter, getfieldminwidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(formatter, getfieldminwidth)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	return Value(flags.fieldMinWidth);
}

// formatter#getpadding()
Gura_DeclareMethod(formatter, getpadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(formatter, getpadding)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	char str[] = { flags.charPadding, '\0' };
	return Value(str);
}

// formatter#getplusmode()
Gura_DeclareMethod(formatter, getplusmode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(formatter, getplusmode)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	return Value(flags.plusMode);
}

// formatter#getprecision()
Gura_DeclareMethod(formatter, getprecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(formatter, getprecision)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	return Value(flags.precision);
}

// formatter#isleftalign()
Gura_DeclareMethod(formatter, isleftalign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(formatter, isleftalign)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	return Value(flags.leftAlignFlag);
}

// formatter#issharp()
Gura_DeclareMethod(formatter, issharp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(formatter, issharp)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	return Value(flags.sharpFlag);
}

// formatter#isuppercase()
Gura_DeclareMethod(formatter, isuppercase)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(formatter, isuppercase)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	return Value(flags.upperCaseFlag);
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_formatter::Class_formatter(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_formatter)
{
}

void Class_formatter::Prepare(Environment &env)
{
	Gura_AssignMethod(formatter, getfieldminwidth);
	Gura_AssignMethod(formatter, getpadding);
	Gura_AssignMethod(formatter, getplusmode);
	Gura_AssignMethod(formatter, getprecision);
	Gura_AssignMethod(formatter, isleftalign);
	Gura_AssignMethod(formatter, issharp);
	Gura_AssignMethod(formatter, isuppercase);
}

Object *Class_formatter::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
