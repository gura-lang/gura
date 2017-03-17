//=============================================================================
// Gura class: help
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

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
// Implementation of functions
//-----------------------------------------------------------------------------
// help@class(cls:class, lang?:symbol):map {block?}
Gura_DeclareFunctionAlias(help_at_class, "help@class")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "cls", VTYPE_Class);
	DeclareArg(env, "lang", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a `help` instance associated with the specified class `cls`.\n"
		"If the class has no help registred, this function would return `nil`.\n"
		"\n"
		"The argument `lang` is a symbol that indicates a natural language\n"
		"in which the help document is written.\n"
		"If this argument is omitted or the specified language doesn't exist,\n"
		"help information that has been registered at first would be returned as a default.\n");
}

Gura_ImplementFunction(help_at_class)
{
	const Class *pClass = arg.GetClassItself(0);
	const Symbol *pSymbol = arg.Is_symbol(1)? arg.GetSymbol(1) : env.GetLangCode();
	const Help *pHelp = pClass->GetHelpProvider().GetHelp(pSymbol, true);
	if (pHelp == nullptr) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_help(env, pHelp->Reference())));
}

// help@function(func:function, lang?:symbol):map {block?}
Gura_DeclareFunctionAlias(help_at_function, "help@function")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "func", VTYPE_function);
	DeclareArg(env, "lang", VTYPE_symbol, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Returns a `help` instance associated with the specified function instance `func`.\n"
		"If the function instance has no help registred, this function would return `nil`.\n"
		"\n"
		"The argument `lang` is a symbol that indicates a natural language\n"
		"in which the help document is written.\n"
		"If this argument is omitted or the specified language doesn't exist,\n"
		"help information that has been registered at first would be returned as a default.\n");
}

Gura_ImplementFunction(help_at_function)
{
	const Function *pFunc = Object_function::GetObject(arg, 0)->GetFunction();
	const Symbol *pSymbol = arg.Is_symbol(1)? arg.GetSymbol(1) : env.GetLangCode();
	const Help *pHelp = pFunc->GetHelpProvider().GetHelp(pSymbol, true);
	if (pHelp == nullptr) return Value::Nil;
	return ReturnValue(env, arg, Value(new Object_help(env, pHelp->Reference())));
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// help#title
Gura_DeclareProperty_R(help, title)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(help, title)
{
	const Help *pHelp = Object_help::GetObject(valueThis)->GetHelp();
	return Value(pHelp->MakeHelpTitle());
}

// help#lang
Gura_DeclareProperty_R(help, lang)
{
	SetPropAttr(VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(help, lang)
{
	const Help *pHelp = Object_help::GetObject(valueThis)->GetHelp();
	return Value(pHelp->GetLangCode());
}

// help#format
Gura_DeclareProperty_R(help, format)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(help, format)
{
	const Help *pHelp = Object_help::GetObject(valueThis)->GetHelp();
	return Value(pHelp->GetFormatNameSTL());
}

// help#doc
Gura_DeclareProperty_R(help, doc)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(help, doc)
{
	Help *pHelp = Object_help::GetObject(valueThis)->GetHelp();
	if (!pHelp->UpdateDocument(env)) return Value::Nil;
	return Value(pHelp->GetDocumentSTL());
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
		Gura_Symbol(en),
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
		Gura_Symbol(en),
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

// help#present():void
Gura_DeclareMethod(help, present)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
	);
}

Gura_ImplementMethod(help, present)
{
	Help *pHelp = Object_help::GetObjectThis(arg)->GetHelp();
	pHelp->Present(env);
	return Value::Nil;
}

// help.presenter(format:string):static:void {block}
Gura_DeclareClassMethod(help, presenter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
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

// help#render(format:string, out?:stream, header_offset?:number) {block?}
Gura_DeclareMethod(help, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	DeclareArg(env, "header_offset", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		""
	);
}

Gura_ImplementMethod(help, render)
{
	Help *pHelp = Object_help::GetObjectThis(arg)->GetHelp();
	const char *formatNameOut = arg.GetString(0);
	int headerOffset = arg.IsValid(2)? arg.GetInt(2) : 0;
	if (arg.IsValid(1)) {
		Stream &stream = arg.GetStream(1);
		pHelp->Render(env, formatNameOut, stream, headerOffset);
		return Value::Nil;
	} else {
		AutoPtr<StreamMemory> pStream(new StreamMemory(env));
		if (!pHelp->Render(env, formatNameOut, *pStream, headerOffset)) return Value::Nil;
		return Value(String(pStream->GetPointer(), pStream->GetSize()));
	}
}

// help.renderer(format:string, format_out:string):static:void {block}
Gura_DeclareClassMethod(help, renderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "format", VTYPE_string, OCCUR_Once);
	DeclareArg(env, "format_out", VTYPE_string, OCCUR_Once);
	DeclareBlock(OCCUR_Once);
	AddHelp(
		Gura_Symbol(en),
		"Registers a procedure with a name specified by the argument `format`\n"
		"that renders the help text in a format of `format_out`.\n"
		"\n"
		"The procedure is written in the block that takes block parameters:\n"
		"`|help:help, out:stream|`.\n"
	);
}

Gura_ImplementClassMethod(help, renderer)
{
	Signal &sig = env.GetSignal();
	const char *formatName = arg.GetString(0);
	const char *formatNameOut = arg.GetString(1);
	const Function *pFuncBlock = arg.GetBlockFunc(env, GetSymbolForBlock());
	if (sig.IsSignalled()) return Value::Nil;
	HelpRenderer::Register(env, new HelpRenderer(formatName, formatNameOut, pFuncBlock->Reference()));
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of operators
//-----------------------------------------------------------------------------
// [A %% B] ... BinaryOperator(ModMod, A, B)
Gura_ImplementBinaryOperator(ModMod, function, help)
{
	Function *pFunc = Object_function::GetObject(valueLeft)->GetFunction();
	Help *pHelp = Object_help::GetObject(valueRight)->GetHelp();
	pFunc->GetHelpProvider().AddHelp(pHelp->Reference());
	return valueLeft;
}

Gura_ImplementBinaryOperator(ModMod, Class, help)
{
	Class *pClass = valueLeft.GetClassItself();
	Help *pHelp = Object_help::GetObject(valueRight)->GetHelp();
	pClass->GetHelpProvider().AddHelp(pHelp->Reference());
	return valueLeft;
}

// [~A] ... UnaryOperator(Invert, A)
Gura_ImplementUnaryOperator(Inv, function)
{
	Function *pFunc = Object_function::GetObject(value)->GetFunction();
	const Symbol *pSymbolLangCode = env.GetLangCode();
	Help *pHelp = pFunc->GetHelpProvider().GetHelp(pSymbolLangCode, true);
	if (pHelp == nullptr) {
		HelpProvider::PresentTitle(env, pFunc);
		HelpProvider::PresentNoHelpDocument(env);
	} else {
		pHelp->Present(env);
	}
	return Value::Nil;
}

Gura_ImplementUnaryOperator(Inv, help)
{
	Help *pHelp = Object_help::GetObject(value)->GetHelp();
	pHelp->Present(env);
	return Value::Nil;
}

Gura_ImplementUnaryOperator(Inv, Class)
{
	Class *pClass = value.GetClassItself();
	const Symbol *pSymbolLangCode = env.GetLangCode();
	Function *pFunc = pClass->GetConstructor();
	if (pFunc == nullptr) {
		env.SetError(ERR_ValueError, "the class does not have a constructor");
		return Value::Nil;
	}
	Help *pHelp = pFunc->GetHelpProvider().GetHelp(pSymbolLangCode, true);
	if (pHelp == nullptr) {
		HelpProvider::PresentTitle(env, pFunc);
		HelpProvider::PresentNoHelpDocument(env);
	} else {
		pHelp->Present(env);
	}
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_help::Class_help(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_help)
{
}

void Class_help::DoPrepare(Environment &env)
{
	// Assignment of class
	Gura_AssignValue(help, Value(Reference()));
	// Assignment of functions
	Gura_AssignFunction(help_at_class);
	Gura_AssignFunction(help_at_function);
	// Assignment of properties
	Gura_AssignProperty(help, title);
	Gura_AssignProperty(help, lang);
	Gura_AssignProperty(help, format);
	Gura_AssignProperty(help, doc);
	// Assignment of methods
	Gura_AssignMethod(help, text_at_iterator);
	Gura_AssignMethod(help, text_at_block);
	Gura_AssignMethod(help, present);
	Gura_AssignMethod(help, presenter);
	Gura_AssignMethod(help, render);
	Gura_AssignMethod(help, renderer);
	// Assignment of operators
	Gura_AssignBinaryOperator(ModMod, function, help);
	Gura_AssignBinaryOperator(ModMod, Class, help);
	Gura_AssignUnaryOperator(Inv, function);
	Gura_AssignUnaryOperator(Inv, help);
	Gura_AssignUnaryOperator(Inv, Class);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

}
