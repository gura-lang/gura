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
	return nullptr;
}

bool Object_template::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	return true;
}

Value Object_template::DoGetProp(Environment &env, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
	return Value::Nil;
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
	bool autoIndentFlag = !arg.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = arg.IsSet(Gura_Symbol(lasteol));
	AutoPtr<Template> pTemplate(new Template());
	if (arg.Is_stream(0)) {
		if (!pTemplate->Read(env, arg.GetStream(0),
					autoIndentFlag, appendLastEOLFlag)) return Value::Nil;
	}
	return ReturnValue(env, arg,
					Value(new Object_template(env, pTemplate.release())));
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
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
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	bool autoIndentFlag = !arg.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = arg.IsSet(Gura_Symbol(lasteol));
	//SimpleStream_CStringReader streamSrc(arg.GetString(0));
	//pTemplate->Read(env, streamSrc, autoIndentFlag, appendLastEOLFlag);
	pTemplate->Parse(env, arg.GetString(0), nullptr, autoIndentFlag, appendLastEOLFlag);
	return Value::Nil;
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
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	bool autoIndentFlag = !arg.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = arg.IsSet(Gura_Symbol(lasteol));
	pTemplate->Read(env, arg.GetStream(0), autoIndentFlag, appendLastEOLFlag);
	return Value::Nil;
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
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	if (arg.Is_stream(0)) {
		Stream &streamDst = arg.GetStream(0);
		pTemplate->Render(env, &streamDst);
		return Value::Nil;
	} else {
		String strDst;
		SimpleStream_StringWriter streamDst(strDst);
		if (!pTemplate->Render(env, &streamDst)) return Value::Nil;
		return Value(strDst);
	}
}

//-----------------------------------------------------------------------------
// Implementation of methods for directives
//-----------------------------------------------------------------------------
// template#block(symbol:symbol):void
Gura_DeclareMethod(template_, block)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a template block which content is supposed to be replaced by a derived template.\n"
		"\n"
		"This method is called by template directive `${=block()}`\n"
		"during both the initialization and presentation phase of a template process.\n"
		"\n"
		"- **Initialization:** Creates a template block from the specified block\n"
		"  that is then registered in the current template with the specified symbol.\n"
		"- **Presentation:** Evaluates a template block registered with the specified symbol.\n"
		"\n"
		"Consider an example.\n"
		"Assume that a block associated with symbol `` `foo`` is declared\n"
		"in a template file named `base.tmpl` as below:\n"
		"\n"
		"`[base.tmpl]`\n"
		"\n"
		"    Block begins here.\n"
		"    ${=block(`foo)}\n"
		"    Content of base.\n"
		"    ${end}\n"
		"    Block ends here.\n"
		"\n"
		"This template renders the following result:\n"
		"\n"
		"    Block begins here.\n"
		"    Content of derived.\n"
		"    Block ends here.\n"
		"\n"
		"Below is another template named `derived.tmpl` that devies from `base.tmpl`\n"
		"and overrides the block `` `foo``.\n"
		"\n"
		"`[derived.tmpl]`\n"
		"\n"
		"    ${=extends('base.tmpl')}\n"
		"    \n"
		"    ${=block(`foo)}\n"
		"    Content of derived.\n"
		"    ${end}\n"
		"\n"
		"This template renders the following result:\n"
		"\n"
		"    Block begins here.\n"
		"    Content of derived.\n"
		"    Block ends here.\n");
}

Gura_ImplementMethod(template_, block)
{
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	const Symbol *pSymbol = arg.GetSymbol(0);
	const ValueEx *pValue = pTemplate->LookupValue(pSymbol);
	if (pValue != nullptr && pValue->Is_function()) {
		const Function *pFunc = pValue->GetFunction();
		AutoPtr<Argument> pArg(new Argument(pFunc));
		pArg->SetValueThis(arg.GetValueThis());
		pFunc->Eval(env, *pArg);
	}
	return Value::Nil;
}

// template#call(symbol:symbol, args*)
Gura_DeclareMethod(template_, call)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Calls a template macro that has been created by directive `${=define}`.\n"
		"\n"
		"This method is called by template directive `${=call()}`\n"
		"during the presentation phase of a template process.\n"
		"\n"
		"Below is an exemple to call a template macro:\n"
		"\n"
		"    ${=call(`show_person, 'Harry', 24)}\n"
		"\n"
		"This method would return `nil` if a line-break character is rendered at last\n"
		"and would return a null string otherwise.\n");
}

Gura_ImplementMethod(template_, call)
{
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	const Symbol *pSymbol = arg.GetSymbol(0);
	const ValueEx *pValue = pTemplate->LookupValue(pSymbol);
	if (pValue == nullptr || !pValue->Is_function()) {
		return Value::Nil;
	}
	const Function *pFunc = pValue->GetFunction();
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(arg.GetValueThis());
	if (!pArg->SetValues(env, arg.GetList(1))) return Value::Nil;
	pTemplate->ClearLastChar();
	pFunc->Eval(env, *pArg);
	return (pTemplate->GetLastChar() == '\n')? Value::Nil : Value("");
}

// template#define(symbol:symbol, `args*):void
Gura_DeclareMethod(template_, define)
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
		"This method is called by template directive `${=define()}`\n"
		"during the initialization phase of a template process.\n"
		"\n"
		"Below is an example to create a template macro:\n"
		"\n"
		"    ${=define(`show_person, name:string, age:number)}\n"
		"    ${name} is ${age} years old.\n"
		"    ${end}\n");
}

Gura_ImplementMethod(template_, define)
{
	// nothing to do
	return Value::Nil;
}

// template#embed(template:template)
Gura_DeclareMethod(template_, embed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "template", VTYPE_template);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Renders the specified template at the current position.\n"
		"\n"
		"This method is called by template directive `${=embed()}`\n"
		"during the presentation phase of a template process.\n"
		"\n"
		"Below is an example to embed a template file named `foo.tmpl`.\n"
		"\n"
		"    ${=embed('foo.tmpl')}\n"
		"\n"
		"As the template rendered by this method runs in a different context\n"
		"from the current one, macros and blocks that it defines\n"
		"are not reflected to the current context.\n"
		"\n"
		"This method would return `nil` if a line-break character is rendered at last\n"
		"and would return a null string otherwise.\n");
}

Gura_ImplementMethod(template_, embed)
{
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	Template *pTemplateEmbedded = Object_template::GetObject(arg, 0)->GetTemplate();
	SimpleStream *pStreamDst = pTemplate->GetStreamDst();
	pTemplateEmbedded->ClearLastChar();
	pTemplateEmbedded->Render(env, pStreamDst);
	return (pTemplateEmbedded->GetLastChar() == '\n')? Value::Nil : Value("");
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
		"Below is an example to declare the current template as one derived from `base.tmpl`.\n"
		"\n"
		"    ${=extends('base.tmpl')}\n");
}

Gura_ImplementMethod(template_, extends)
{
	// nothing to do
	return Value::Nil;
}

// template#super(symbol:symbol):void
Gura_DeclareMethod(template_, super)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Evaluates a template block registered with the specified symbol in a template\n"
		"from which the current template has derived.\n"
		"\n"
		"This method is called by template directive `${=super()}`\n"
		"during the presentation phase of a template process.\n"
		"The directive is intended to be used within a directive `${=block()}`.\n"
		"\n"
		"Consider an example.\n"
		"Assume that a block associated with symbol `` `foo`` is declared\n"
		"in a template named `base.tmpl` as below:\n"
		"\n"
		"`[base.tmpl]`\n"
		"\n"
		"    Block begins here.\n"
		"    ${=block(`foo)}\n"
		"    Content of base.\n"
		"    ${end}\n"
		"    Block ends here.\n"
		"\n"
		"This template renders the following result:\n"
		"\n"
		"    Block begins here.\n"
		"    Content of derived.\n"
		"    Block ends here.\n"
		"\n"
		"Below is another template named `derived.tmpl` that devies from `base.tmpl`\n"
		"and overrides the block `` `foo``.\n"
		"\n"
		"`[derived.tmpl]`\n"
		"\n"
		"    ${=extends('base.tmpl')}\n"
		"    \n"
		"    ${=block(`foo)}\n"
		"    ${=super(`foo)}\n"
		"    Content of derived.\n"
		"    ${end}\n"
		"\n"
		"This template renders the following result:\n"
		"\n"
		"    Block begins here.\n"
		"    Content of base.\n"
		"    Content of derived.\n"
		"    Block ends here.\n");
}

Gura_ImplementMethod(template_, super)
{
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	const Symbol *pSymbol = arg.GetSymbol(0);
	Template *pTemplateSuper = pTemplate->GetTemplateSuper();
	if (pTemplateSuper == nullptr) return Value::Nil;
	const ValueEx *pValue = pTemplateSuper->LookupValue(pSymbol);
	if (pValue != nullptr && pValue->Is_function()) {
		const Function *pFunc = pValue->GetFunction();
		AutoPtr<Argument> pArg(new Argument(pFunc));
		pArg->SetValueThis(arg.GetValueThis());
		pFunc->Eval(env, *pArg);
	}
	return Value::Nil;
}

// template#init_block(symbol:symbol):void {block}
Gura_DeclareMethod(template_, init_block)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareBlock(OCCUR_Once);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("block"));
}

Gura_ImplementMethod(template_, init_block)
{
	Signal &sig = env.GetSignal();
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	const Symbol *pSymbol = arg.GetSymbol(0);
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
						pSymbol, Expr::Reference(pExprBlock), FUNCTYPE_Instance));
	pFunc->SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_DynamicScope);
	ValueMap &valueMap = pTemplate->GetValueMap();
	if (valueMap.find(pSymbol) != valueMap.end()) {
		sig.SetError(ERR_KeyError, "duplicated symbol: %s", pSymbol->GetName());
		return Value::Nil;
	}
	valueMap[pSymbol] = Value(new Object_function(env, pFunc->Reference()));
	return Value::Nil;
}

// template#init_call(symbol:symbol, args*):void
Gura_DeclareMethod(template_, init_call)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_any, OCCUR_ZeroOrMore);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("call"));
}

Gura_ImplementMethod(template_, init_call)
{
	// nothing to do
	return Value::Nil;
}

// template#init_define(symbol:symbol, `args*):void {block}
Gura_DeclareMethod(template_, init_define)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_Once);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("define"));
}

Gura_ImplementMethod(template_, init_define)
{
	Signal &sig = env.GetSignal();
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	const Symbol *pSymbol = arg.GetSymbol(0);
	const Expr_Block *pExprBlock = arg.GetBlockCooked(env);
	if (sig.IsSignalled()) return Value::Nil;
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
						pSymbol, Expr::Reference(pExprBlock), FUNCTYPE_Instance));
	pFunc->SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_DynamicScope);
	AutoPtr<ExprOwner> pExprOwnerArg(new ExprOwner());
	foreach_const (ValueList, pValue, arg.GetList(1)) {
		pExprOwnerArg->push_back(pValue->GetExpr()->Reference());
	}
	CallerInfo callerInfo(*pExprOwnerArg, nullptr, nullptr, nullptr);
	if (!pFunc->CustomDeclare(env, callerInfo, SymbolSet::Empty)) return Value::Nil;
	ValueMap &valueMap = pTemplate->GetValueMap();
	if (valueMap.find(pSymbol) != valueMap.end()) {
		sig.SetError(ERR_KeyError, "duplicated symbol: %s", pSymbol->GetName());
		return Value::Nil;
	}
	valueMap[pSymbol] = Value(new Object_function(env, pFunc->Reference()));
	return Value::Nil;
}

// template#init_embed(template:template):void
Gura_DeclareMethod(template_, init_embed)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "template", VTYPE_template);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("embed"));
}

Gura_ImplementMethod(template_, init_embed)
{
	// nothing to do
	return Value::Nil;
}

// template#init_extends(template:template):void
Gura_DeclareMethod(template_, init_extends)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "template", VTYPE_template);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("extends"));
}

Gura_ImplementMethod(template_, init_extends)
{
	Template *pTemplate = Object_template::GetObjectThis(arg)->GetTemplate();
	Template *pTemplateSuper = Object_template::GetObject(arg, 0)->GetTemplate();
	pTemplate->SetTemplateSuper(pTemplateSuper->Reference());
	return Value::Nil;
}

// template#init_super(symbol:symbol):void
Gura_DeclareMethod(template_, init_super)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	LinkHelp(env.LookupClass(VTYPE_template), Symbol::Add("super"));
}

Gura_ImplementMethod(template_, init_super)
{
	// nothing to do
	return Value::Nil;
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
	// assignment of methods
	Gura_AssignMethod(template_, parse);
	Gura_AssignMethod(template_, read);
	Gura_AssignMethod(template_, render);
	// assignment of methods for directives
	Gura_AssignMethod(template_, block);
	Gura_AssignMethod(template_, call);
	Gura_AssignMethod(template_, define);
	Gura_AssignMethod(template_, embed);
	Gura_AssignMethod(template_, extends);
	Gura_AssignMethod(template_, super);
	Gura_AssignMethod(template_, init_block);
	Gura_AssignMethod(template_, init_call);
	Gura_AssignMethod(template_, init_define);
	Gura_AssignMethod(template_, init_embed);
	Gura_AssignMethod(template_, init_extends);
	Gura_AssignMethod(template_, init_super);
}

bool Class_template::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	env.LookupClass(VTYPE_stream)->CastFrom(env, value, pDecl);
	if (value.Is_stream()) {
		bool autoIndentFlag = true;
		bool appendLastEOLFlag = false;
		AutoPtr<Template> pTemplate(new Template());
		if (!pTemplate->Read(env, value.GetStream(),
							autoIndentFlag, appendLastEOLFlag)) return false;
		value = Value(new Object_template(env, pTemplate.release()));
		return true;
	}
	return false;
}

Object *Class_template::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
