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
	symbols.insert(Gura_Symbol(body));
	foreach (ValueMap, iter, _pTemplate->GetValueMap()) {
		const Symbol *pSymbol = iter->first;
		symbols.insert(pSymbol);
	}
	return true;
}

Value Object_template::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
						const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(body))) {
		const Function *pFuncForBody = _pTemplate->GetFuncForBody();
		if (pFuncForBody == NULL) return Value::Null;
		return Value(new Object_function(env, pFuncForBody->Reference()));
	} else {
		const ValueEx *pValue = _pTemplate->LookupValue(pSymbol);
		if (pValue != NULL) return *pValue;
	}
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
// template#inherit(stream:stream):void:[lasteol,noindent]
Gura_DeclareMethod(template, inherit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareAttr(Gura_Symbol(lasteol));
	DeclareAttr(Gura_Symbol(noindent));
}

Gura_ImplementMethod(template, inherit)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	Template::Parser parser(autoIndentFlag, appendLastEOLFlag);
	AutoPtr<Template> pTemplateSuper(parser.ParseStream(env, sig, args.GetStream(0)));
	if (pTemplateSuper.IsNull()) return Value::Null;
	pTemplate->SetTemplateSuper(pTemplateSuper.release());
	return Value::Null;
}

// template#present_inherit(stream:stream):void:[lasteol,noindent]
Gura_DeclareMethod(template, present_inherit)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "stream", VTYPE_stream);
	DeclareAttr(Gura_Symbol(lasteol));
	DeclareAttr(Gura_Symbol(noindent));
}

Gura_ImplementMethod(template, present_inherit)
{
	return Value::Null;
}

// template#block(symbol:symbol):void {block}
Gura_DeclareMethod(template, block)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementMethod(template, block)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	const Function *pFunc = args.GetBlockFunc(env, sig, pSymbol);
	if (pFunc == NULL) return Value::Null;
	ValueMap &valueMap = pTemplate->GetValueMap();
	valueMap[pSymbol] = Value(new Object_function(env, pFunc->Reference()));
	return Value::Null;
}

// template#present_block(symbol:symbol):void
Gura_DeclareMethod(template, present_block)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "symbol", VTYPE_symbol);
}

Gura_ImplementMethod(template, present_block)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	const Symbol *pSymbol = args.GetSymbol(0);
	ValueMap &valueMap = pTemplate->GetValueMap();
	ValueMap::iterator iter = valueMap.find(pSymbol);
	if (iter == valueMap.end()) return Value::Null;
	Value &value = iter->second;
	if (!value.Is_function()) return Value::Null;
	AutoPtr<Args> pArgs(new Args());
	value.GetFunction()->Eval(env, sig, *pArgs);
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
	Gura_AssignMethod(template, inherit);
	Gura_AssignMethod(template, present_inherit);
	Gura_AssignMethod(template, block);
	Gura_AssignMethod(template, present_block);
}

Object *Class_template::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
