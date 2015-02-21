//=============================================================================
// Gura class: template
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_template
//-----------------------------------------------------------------------------
Object_template::Object_template(Environment &env, Template *pTemplate) :
				Object(env.LookupClass(VTYPE_template)), _pTemplate(pTemplate)
{
}

Object_template::Object_template(Class *pClass, Template *pTemplate) :
										Object(pClass), _pTemplate(pTemplate)
{
}

Object *Object_template::Clone() const
{
	return NULL;
}

bool Object_template::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	return true;
}

Value Object_template::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Null;
}

String Object_template::ToString(bool exprFlag)
{
	String str;
	str += "<template:";
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of functions
//-----------------------------------------------------------------------------
// template(src?:stream:r):map:[lasteol,noindent] {block?}
Gura_DeclareFunctionAlias(template_, "template")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_template));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `template` instance.\n"
		"\n"
		"If the stream `src` is specified, the instance would be initialized\n"
		"with the parsed result of the script-embedded text from the stream.\n"
		"\n"
		"Following attributes would customize the parser's behavior:\n"
		"\n"
		"- `:lasteol`\n"
		"- `:noindent`\n");
}

Gura_ImplementFunction(template_)
{
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	AutoPtr<Template> pTemplate(new Template());
	if (args.Is_stream(0)) {
		if (!pTemplate->Read(env, sig, args.GetStream(0),
					autoIndentFlag, appendLastEOLFlag)) return Value::Null;
	}
	return ReturnValue(env, sig, args,
					Value(new Object_template(env, pTemplate.release())));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// template#block(symbol:symbol):void
Gura_DeclareMethod(template_, block)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Declares a template block.\n"
		"\n"
		"This method is called by template directive `${=block()}`\n"
		"during both the initialization and presentation phase of a template process.\n"
		"\n"
		"- *Initialization*: Creates a template block from the specified block\n"
		"  that is then registered in the current template with the specified symbol.\n"
		"- *Presentation*: Evaluates a template block registered with the specified symbol.\n"
		"\n"
		"Below is an example to declare a template block:\n"
		"\n"
		"    ${=block(`header)}\n"
		"    Default Header\n"
		"    ${end}\n"
		"\n");
}

Gura_ImplementMethod(template_, block)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	const ValueEx *pValue = pTemplate->LookupValue(pSymbol);
	if (pValue != NULL && pValue->Is_function()) {
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetThis(args.GetThis());
		pValue->GetFunction()->Eval(env, sig, *pArgs);
	}
	return Value::Null;
}

// template#call(symbol:symbol, args*):void
Gura_DeclareMethod(template_, call)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Calls a template macro that has been created by directive `${=def}`.\n"
		"\n"
		"This method is called by template directive `${=call()}`\n"
		"during the presentation phase of a template process.\n"
		"\n"
		"Below is an exemple of a template text:\n"
		"\n"
		"    ${=call(`show_person, 'Harry', 24)}\n");
}

Gura_ImplementMethod(template_, call)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	const ValueEx *pValue = pTemplate->LookupValue(pSymbol);
	if (pValue == NULL || !pValue->Is_function()) {
		return Value::Null;
	}
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(args.GetThis());
	pArgs->SetValueListArg(args.GetList(1));
	pValue->GetFunction()->Eval(env, sig, *pArgs);
	return Value::Null;
}

// template#def(symbol:symbol, `args*):void
Gura_DeclareMethod(template_, def)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a template macro from the specified block,\n"
		"which is supposed to be called by `${=call}` directive,\n"
		"and associates it with the specified symbol.\n"
		"\n"
		"This method is called by template directive `${=def()}`\n"
		"during the initialization phase of a template process.\n"
		"\n"
		"Below is an example to create a template macro:\n"
		"\n"
		"    ${=def(`show_person, name:string, age:number)}\n"
		"    ${name} is ${age} years old.\n"
		"    ${end}\n");
}

Gura_ImplementMethod(template_, def)
{
	// nothing to do
	return Value::Null;
}

// template#embed(template:template):void
Gura_DeclareMethod(template_, embed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "template", VTYPE_template);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Renders the specified template at the current position.\n"
		"\n"
		"This method is called by template directive `${=embed()}`\n"
		"during the presentation phase of a template process.\n"
		"\n"
		"Below is an example to embeds a template file named `foo.tmpl`.\n"
		"\n"
		"    ${=embed('foo.tmpl')}\n");
}

Gura_ImplementMethod(template_, embed)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	Template *pTemplateToEmbed = Object_template::GetObject(args, 0)->GetTemplate();
	SimpleStream *pStreamDst = pTemplate->GetStreamDst();
	pTemplateToEmbed->Render(env, sig, pStreamDst);
	return Value::Null;
}

// template#extends(template:template):void
Gura_DeclareMethod(template_, extends)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "template", VTYPE_template);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Declares the current template as a derived one from the specified template.\n"
		"\n"
		"This method is called by template directive `${=extends()}`\n"
		"during the initialization phase of a template process.\n"
		"\n"
		"The directive must appear in a template only once.\n"
		"An error occurs if the current template has already derived from another template.\n"
		"\n"
		"Below is an example to declare an extention from a template file named `base.tmpl`.\n"
		"\n"
		"    ${=extends('base.tmpl')}\n");
}

Gura_ImplementMethod(template_, extends)
{
	// nothing to do
	return Value::Null;
}

// template#parse(str:string):void:[lasteol,noindent]
Gura_DeclareMethod(template_, parse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "str", VTYPE_string);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `template` instance by parsing a script-embedded text in a string.\n"
		"\n"
		"Following attributes would customize the parser's behavior:\n"
		"\n"
		"- `:lasteol`\n"
		"- `:noindent`\n");
}

Gura_ImplementMethod(template_, parse)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	SimpleStream_CStringReader streamSrc(args.GetString(0));
	pTemplate->Read(env, sig, streamSrc, autoIndentFlag, appendLastEOLFlag);
	return Value::Null;
}

// template#read(src:stream:r):void:[lasteol,noindent]
Gura_DeclareMethod(template_, read)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `template` instance by parsing a script-embedded text from a stream.\n"
		"\n"
		"Following attributes would customize the parser's behavior:\n"
		"\n"
		"- `:lasteol`\n"
		"- `:noindent`\n");
}

Gura_ImplementMethod(template_, read)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	pTemplate->Read(env, sig, args.GetStream(0), autoIndentFlag, appendLastEOLFlag);
	return Value::Null;
}

// template#render(dst?:stream:w)
Gura_DeclareMethod(template_, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Renders stored content to the specified stream.\n"
		"\n"
		"If the stream is omitted, the function returns the rendered result as a string.\n");
}

Gura_ImplementMethod(template_, render)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	if (args.Is_stream(0)) {
		Stream &streamDst = args.GetStream(0);
		pTemplate->Render(env, sig, &streamDst);
		return Value::Null;
	} else {
		String strDst;
		SimpleStream_StringWriter streamDst(strDst);
		if (!pTemplate->Render(env, sig, &streamDst)) return Value::Null;
		return Value(strDst);
	}
}

// template#super(symbol:symbol):void
Gura_DeclareMethod(template_, super)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Evaluates a template block registered with the specified symbol in a template\n"
		"that the current template has derived from.\n"
		"\n"
		"This method is called by template directive `${=super()}`\n"
		"during the presentation phase of a template process.\n"
		"\n"
		"The directive is intended to be used within a directive `${=block()}`.\n"
		"Assume that a block associated with symbol `` `foo`` is declared\n"
		"in a template named `base.tmpl` as below:\n"
		"\n"
		"[base.tmpl]\n"
		"\n"
		"    ${=block(`foo)}\n"
		"    Content of base.\n"
		"    ${end}\n"		
		"\n"
		"Below is another template named `derived.tmpl` that devies from `base.tmpl`\n"
		"and overrides the block `` `foo``.\n"
		"\n"
		"[derived.tmpl]\n"
		"\n"
		"    ${=extends('base.tmpl')}\n"
		"    \n"
		"    ${=block(`foo)}\n"
		"    ${=super(`foo)}\n"
		"    Content of derived.\n"
		"    ${end}\n"
		"\n"
		"Below is an output of the template:\n"
		"\n"
		"    Content of base.\n"
		"    Content of derived.\n");
}

Gura_ImplementMethod(template_, super)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	Template *pTemplateSuper = pTemplate->GetTemplateSuper();
	if (pTemplateSuper == NULL) return Value::Null;
	const ValueEx *pValue = pTemplateSuper->LookupValue(pSymbol);
	if (pValue != NULL && pValue->Is_function()) {
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetThis(args.GetThis());
		pValue->GetFunction()->Eval(env, sig, *pArgs);
	}
	return Value::Null;
}

// template#_init_block(symbol:symbol):void {block}
Gura_DeclareMethod(template_, _init_block)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareBlock(OCCUR_Once);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("block"));
}

Gura_ImplementMethod(template_, _init_block)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
						pSymbol, Expr::Reference(pExprBlock), FUNCTYPE_Instance));
	pFunc->SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_DynamicScope);
	ValueMap &valueMap = pTemplate->GetValueMap();
	if (valueMap.find(pSymbol) != valueMap.end()) {
		sig.SetError(ERR_KeyError, "duplicated symbol: %s", pSymbol->GetName());
		return Value::Null;
	}
	valueMap[pSymbol] = Value(new Object_function(env, pFunc->Reference()));
	return Value::Null;
}

// template#_init_call(symbol:symbol, args*):void
Gura_DeclareMethod(template_, _init_call)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("call"));
}

Gura_ImplementMethod(template_, _init_call)
{
	// nothing to do
	return Value::Null;
}

// template#_init_def(symbol:symbol, `args*):void {block}
Gura_DeclareMethod(template_, _init_def)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_Once);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("def"));
}

Gura_ImplementMethod(template_, _init_def)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
						pSymbol, Expr::Reference(pExprBlock), FUNCTYPE_Instance));
	pFunc->SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_DynamicScope);
	AutoPtr<Args> pArgsSub(new Args());
	do {
		AutoPtr<ExprOwner> pExprOwnerArg(new ExprOwner());
		foreach_const (ValueList, pValue, args.GetList(1)) {
			pExprOwnerArg->push_back(pValue->GetExpr()->Reference());
		}
		pArgsSub->SetExprOwnerArg(pExprOwnerArg.release());
	} while (0);
	//pArgsSub->SetAttrs(args.GetAttrs());
	if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, *pArgsSub)) return Value::Null;
	ValueMap &valueMap = pTemplate->GetValueMap();
	if (valueMap.find(pSymbol) != valueMap.end()) {
		sig.SetError(ERR_KeyError, "duplicated symbol: %s", pSymbol->GetName());
		return Value::Null;
	}
	valueMap[pSymbol] = Value(new Object_function(env, pFunc->Reference()));
	return Value::Null;
}

// template#_init_embed(template:template):void
Gura_DeclareMethod(template_, _init_embed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "template", VTYPE_template);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("embed"));
}

Gura_ImplementMethod(template_, _init_embed)
{
	// nothing to do
	return Value::Null;
}

// template#_init_extends(template:template):void
Gura_DeclareMethod(template_, _init_extends)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "template", VTYPE_template);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("extends"));
}

Gura_ImplementMethod(template_, _init_extends)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	Template *pTemplateSuper = Object_template::GetObject(args, 0)->GetTemplate();
	if (pTemplate->GetTemplateSuper() != NULL) {
		sig.SetError(ERR_DeclarationError,
					 "the current template has already derived from another template.");
		return Value::Null;
	}
	pTemplate->SetTemplateSuper(pTemplateSuper->Reference());
	return Value::Null;
}

// template#_init_super(symbol:symbol):void
Gura_DeclareMethod(template_, _init_super)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("super"));
}

Gura_ImplementMethod(template_, _init_super)
{
	// nothing to do
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_template::Class_template(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_template)
{
}

void Class_template::Prepare(Environment &env)
{
	Gura_AssignFunction(template_);
	Gura_AssignMethod(template_, block);
	Gura_AssignMethod(template_, call);
	Gura_AssignMethod(template_, def);
	Gura_AssignMethod(template_, embed);
	Gura_AssignMethod(template_, extends);
	Gura_AssignMethod(template_, parse);
	Gura_AssignMethod(template_, read);
	Gura_AssignMethod(template_, render);
	Gura_AssignMethod(template_, super);
	Gura_AssignMethod(template_, _init_block);
	Gura_AssignMethod(template_, _init_call);
	Gura_AssignMethod(template_, _init_def);
	Gura_AssignMethod(template_, _init_embed);
	Gura_AssignMethod(template_, _init_extends);
	Gura_AssignMethod(template_, _init_super);
}

bool Class_template::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, sig, value, pDecl);
	if (value.Is_stream()) {
		bool autoIndentFlag = true;
		bool appendLastEOLFlag = false;
		AutoPtr<Template> pTemplate(new Template());
		if (!pTemplate->Read(env, sig, value.GetStream(),
							autoIndentFlag, appendLastEOLFlag)) return false;
		value = Value(new Object_template(env, pTemplate.release()));
		return true;
	}
	return false;
}

Object *Class_template::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
