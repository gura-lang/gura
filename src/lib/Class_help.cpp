//=============================================================================
// Gura class: help
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object implementation for help
//-----------------------------------------------------------------------------
Object_help::Object_help(Environment &env, Help *pHelp) :
			Object(env.LookupClass(VTYPE_help)), _pHelp(pHelp)
{
}

Object_help::Object_help(Class *pClass, Help *pHelp) :
			Object(pClass), _pHelp(pHelp)
{
}

Object *Object_help::Clone() const
{
	return nullptr; //new Object_help(*this);
}

bool Object_help::DoDirProp(Environment &env, Signal &sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(lang));
	symbols.insert(Gura_Symbol(text));
	return true;
}

Value Object_help::DoGetProp(Environment &env, Signal &sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(_pHelp->GetFormatNameSTL());
	} else if (pSymbol->IsIdentical(Gura_Symbol(lang))) {
		return Value(_pHelp->GetSymbol());
	} else if (pSymbol->IsIdentical(Gura_Symbol(text))) {
		return Value(_pHelp->GetTextSTL());
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_help::DoSetProp(Environment &env, Signal &sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return DoGetProp(env, sig, pSymbol, attrs, evaluatedFlag);
}

String Object_help::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<help:";
	rtn += _pHelp->GetSymbol()->GetName();
	rtn += ":";
	rtn += _pHelp->GetFormatName();
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// help.gettext_iterator_en() {block?}
Gura_DeclareClassMethod(help, gettext_iterator_en)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a help text for functions that return an iterator.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("str", "string"));
}

Gura_ImplementClassMethod(help, gettext_iterator_en)
{
	return ReturnValue(env, sig, args, Value(GURA_HELPTEXT_ITERATOR_en()));
}

// help.gettext_block_en(varname:string, typename:string) {block?}
Gura_DeclareClassMethod(help, gettext_block_en)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "varname", VTYPE_string);
	DeclareArg(env, "typename", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a help text for functions that take a block.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("str", "string"));
}

Gura_ImplementClassMethod(help, gettext_block_en)
{
	const char *varName = args.GetString(0);
	const char *typeName = args.GetString(1);
	String buff = Formatter::Format(
		sig, GURA_HELPTEXT_BLOCK_en("%s", "%s"), varName, typeName, varName);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, Value(buff));
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_help::Class_help(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_help)
{
}

void Class_help::Prepare(Environment &env)
{
	// class assignment
	Gura_AssignValue(help, Value(Reference()));
	// methods assignment
	Gura_AssignMethod(help, gettext_iterator_en);
	Gura_AssignMethod(help, gettext_block_en);
}

}
