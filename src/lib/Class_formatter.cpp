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

bool Object_formatter::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	return true;
}

Value Object_formatter::DoGetProp(Environment &env, const Symbol *pSymbol,
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
// formatter#getminwidth()
Gura_DeclareMethod(formatter, getminwidth)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an expected minimum width for the field.\n"
		"\n"
		"For example, with `'%3d'`, this method would return `3`.\n");
}

Gura_ImplementMethod(formatter, getminwidth)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	return Value(flags.fieldMinWidth);
}

// formatter#getpadding()
Gura_DeclareMethod(formatter, getpadding)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a string containing a padding character, a space or `'0'`.\n"
		"\n"
		"In default, a space is used for padding.\n"
		"For example, with `'%3d'`, this method would return `' '`.\n"
		"\n"
		"When a character `'0'` appears after `'%'`, that becomes the padding character.\n"
		"For example, with `'%03d'`, this method would return `'0'`.\n");
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a symbol that indicates an expected action when a positive number appears.\n"
		"\n"
		"- `` `none`` .. No character ahead of the number.\n"
		"- `` `space`` .. A space should be inserted.\n"
		"- `` `plus`` .. A plus character should be inserted.\n");
}

Gura_ImplementMethod(formatter, getplusmode)
{
	const Formatter::Flags &flags = Object_formatter::GetThisObj(args)->GetFlags();
	const Symbol *pSymbol =
		(flags.plusMode == Formatter::PLUSMODE_None)? Gura_Symbol(none) :
		(flags.plusMode == Formatter::PLUSMODE_Space)? Gura_Symbol(space) :
		(flags.plusMode == Formatter::PLUSMODE_Plus)? Gura_Symbol(plus) :
		Gura_Symbol(none);
	return Value(pSymbol);
}

// formatter#getprecision()
Gura_DeclareMethod(formatter, getprecision)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns an expected precision for the field.\n"
		"\n"
		"For example, with `'%.3d'`, this method would return `3`.\n");
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if the field is expected to be aligned on left.\n"
		"\n"
		"For example, with `'%-3d'`, this method would return `true`.\n");
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if the specifier sequence includes `'#'` flag,\n"
		"which means some literal prefixes such as `0x` are expected to be appended at the top.\n"
		"\n"
		"For example, with `'%#x'`, this method would return `true`.\n");
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns `true` if alphabet characters are expected to be shown in upper case.\n"
		"\n"
		"Upper case characters are requested\n"
		"when a specifier such as `'%X'`, `'%E'` and `'%G'` is specified.\n");
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
	Gura_AssignValue(formatter, Value(Reference()));
	Gura_AssignMethod(formatter, getminwidth);
	Gura_AssignMethod(formatter, getpadding);
	Gura_AssignMethod(formatter, getplusmode);
	Gura_AssignMethod(formatter, getprecision);
	Gura_AssignMethod(formatter, isleftalign);
	Gura_AssignMethod(formatter, issharp);
	Gura_AssignMethod(formatter, isuppercase);
}

Object *Class_formatter::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
