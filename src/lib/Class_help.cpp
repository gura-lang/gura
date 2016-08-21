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

bool Object_help::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(title));
	symbols.insert(Gura_Symbol(format));
	symbols.insert(Gura_Symbol(lang));
	symbols.insert(Gura_Symbol(text));
	return true;
}

Value Object_help::DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(title))) {
		return Value(_pHelp->GetTitleSTL());
	} else if (pSymbol->IsIdentical(Gura_Symbol(format))) {
		return Value(_pHelp->GetFormatNameSTL());
	} else if (pSymbol->IsIdentical(Gura_Symbol(lang))) {
		return Value(_pHelp->GetLangCode());
	} else if (pSymbol->IsIdentical(Gura_Symbol(text))) {
		return Value(_pHelp->GetTextSTL());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

Value Object_help::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag)
{
	return DoGetProp(env, pSymbol, attrs, evaluatedFlag);
}

String Object_help::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<help:";
	rtn += _pHelp->GetLangCode()->GetName();
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
	return ReturnValue(env, arg, Value(GURA_HELPTEXT_ITERATOR_en()));
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
	Signal &sig = env.GetSignal();
	const char *varName = arg.GetString(0);
	const char *typeName = arg.GetString(1);
	String buff = Formatter::Format(
		sig, GURA_HELPTEXT_BLOCK_en("%s", "%s"), varName, typeName, varName);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(buff));
}

// help.presenter(name:string):void {block}
Gura_DeclareClassMethod(help, presenter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "name", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Registers a presentation procedure with the specified `name`.\n"
		"\n"
		"The procedure is written in the block that takes block parameters:\n"
		"`|help:help|`.\n"
	);
}

Gura_ImplementClassMethod(help, presenter)
{
	Signal &sig = env.GetSignal();
	const char *formatName = arg.GetString(0);
	const Function *pFuncBlock = arg.GetBlockFunc(env, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Nil;
	HelpPresenter::Register(env, new HelpPresenterCustom(formatName, pFuncBlock->Reference()));
	return Value::Nil;
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
	Gura_AssignMethod(help, presenter);
}

}
