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
// help.text@iterator(lang:symbol):static {block?}
Gura_DeclareClassMethodAlias(help, text_at_iterator, "text@iterator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "lang", VTYPE_symbol);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a help text for functions that return an iterator.\n"
		"\n"
		"The argument `lang` is a symbol that specifies the language in which the text is written,\n"
		"e.g. `` `en`` for English and `` `ja`` for Japanese.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("str", "string"));
}

Gura_ImplementClassMethod(help, text_at_iterator)
{
	const Symbol *pSymbolLangCode = arg.GetSymbol(0);
	const char *str =
		pSymbolLangCode->IsIdentical(Gura_Symbol(en))? GURA_HELPTEXT_ITERATOR_en() :
		GURA_HELPTEXT_ITERATOR_en();
	return ReturnValue(env, arg, Value(str));
}

// help.text@block(lang:symbol, varname:string, typename:string):static {block?}
Gura_DeclareClassMethodAlias(help, text_at_block, "text@block")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "lang", VTYPE_symbol);
	DeclareArg(env, "varname", VTYPE_string);
	DeclareArg(env, "typename", VTYPE_string);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Returns a help text that for functions that take a block .\n"
		"\n"
		"The argument `lang` is a symbol that specifies the language in which the text is written,\n"
		"e.g. `` `en`` for English and `` `ja`` for Japanese.\n"
		"\n"
		"In the text, variable names would be replaced by `varname` and type names by `typename`.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("str", "string"));
}

Gura_ImplementClassMethod(help, text_at_block)
{
	Signal &sig = env.GetSignal();
	const Symbol *pSymbolLangCode = arg.GetSymbol(0);
	const char *varName = arg.GetString(1);
	const char *typeName = arg.GetString(2);
	const char *str =
		pSymbolLangCode->IsIdentical(Gura_Symbol(en))? GURA_HELPTEXT_BLOCK_en("%s", "%s") :
		GURA_HELPTEXT_BLOCK_en("%s", "%s");
	String buff = Formatter::Format(sig, str, varName, typeName, varName);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, Value(buff));
}

// help.presenter(format:string):static:void {block}
Gura_DeclareClassMethod(help, presenter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Registers a presentation procedure with a name specified by the argument `format`.\n"
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
	HelpRenderer::Register(env, new HelpRenderer(formatName, "", pFuncBlock->Reference()));
	return Value::Nil;
}

// help.render(format:string, out?:stream) {block?}
Gura_DeclareMethod(help, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		""
	);
}

Gura_ImplementMethod(help, render)
{
	Help *pHelp = Object_help::GetObjectThis(arg)->GetHelp();
	const char *formatNameOut = arg.GetString(0);
	Stream &stream = arg.GetStream(1);
	pHelp->Render(env, formatNameOut, stream);
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
	Gura_AssignMethod(help, text_at_iterator);
	Gura_AssignMethod(help, text_at_block);
	Gura_AssignMethod(help, presenter);
	Gura_AssignMethod(help, render);
}

}
