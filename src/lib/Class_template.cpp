//=============================================================================
// template class
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
// Gura interfaces for template
//-----------------------------------------------------------------------------
// template(src?:stream:r):map:[noindent,lasteol] {block?}
Gura_DeclareFunctionAlias(template_, "template")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Read);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
	DeclareBlock(OCCUR_ZeroOrOnce);
	SetClassToConstruct(env.LookupClass(VTYPE_template));
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

// template#block(symbol:symbol):void {block}
Gura_DeclareMethod(template_, block)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementMethod(template_, block)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	const Function *pFunc = args.GetBlockFunc(env, sig, pSymbol);
	if (pFunc == NULL) return Value::Null;
	ValueMap &valueMap = pTemplate->GetValueMap();
	valueMap[pSymbol] = Value(new Object_function(env, pFunc->Reference()));
	return Value::Null;
}

// template#embed(template):void
Gura_DeclareMethod(template_, embed)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "template", VTYPE_any);
}

Gura_ImplementMethod(template_, embed)
{
	// nothing to do
	return Value::Null;
}

// template#inherit(super:template):void
Gura_DeclareMethod(template_, inherit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "super", VTYPE_template);
}

Gura_ImplementMethod(template_, inherit)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	Template *pTemplateSuper = Object_template::GetObject(args, 0)->GetTemplate();
	pTemplate->SetTemplateSuper(pTemplateSuper->Reference());
	return Value::Null;
}

// template#parse(str:string):void:[noindent,lasteol]
Gura_DeclareMethod(template_, parse)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "str", VTYPE_string);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
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

// template#read(src:stream:r):void:[noindent,lasteol]
Gura_DeclareMethod(template_, read)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "src", VTYPE_stream, OCCUR_Once, FLAG_Read);
	DeclareAttr(Gura_Symbol(noindent));
	DeclareAttr(Gura_Symbol(lasteol));
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
	SetMode(RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "dst", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
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

// template#render_block(symbol:symbol):void
Gura_DeclareMethod(template_, render_block)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
}

Gura_ImplementMethod(template_, render_block)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	const ValueEx *pValue = pTemplate->LookupValue(pSymbol);
	if (pValue == NULL) return Value::Null;
	if (!pValue->Is_function()) return Value::Null;
	AutoPtr<Args> pArgs(new Args());
	pValue->GetFunction()->Eval(env, sig, *pArgs);
	return Value::Null;
}

// template#render_embed(template:template):void
Gura_DeclareMethod(template_, render_embed)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "template", VTYPE_template);
}

Gura_ImplementMethod(template_, render_embed)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	Template *pTemplateToEmbed = Object_template::GetObject(args, 0)->GetTemplate();
	SimpleStream *pStreamDst = pTemplate->GetStreamDst();
	pTemplateToEmbed->Render(env, sig, pStreamDst);
	return Value::Null;
}

// template#render_inherit(stream:stream):void:[lasteol,noindent]
Gura_DeclareMethod(template_, render_inherit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareAttr(Gura_Symbol(lasteol));
	DeclareAttr(Gura_Symbol(noindent));
}

Gura_ImplementMethod(template_, render_inherit)
{
	// nothing to do
	return Value::Null;
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_template::Class_template(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_template)
{
}

void Class_template::Prepare(Environment &env)
{
	Gura_AssignFunction(template_);
	Gura_AssignMethod(template_, block);
	Gura_AssignMethod(template_, embed);
	Gura_AssignMethod(template_, inherit);
	Gura_AssignMethod(template_, parse);
	Gura_AssignMethod(template_, read);
	Gura_AssignMethod(template_, render);
	Gura_AssignMethod(template_, render_block);
	Gura_AssignMethod(template_, render_embed);
	Gura_AssignMethod(template_, render_inherit);
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
