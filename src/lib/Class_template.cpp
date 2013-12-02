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
	bool autoIndentFlag = !args.IsSet(Gura_Symbol(noindent));
	bool appendLastEOLFlag = args.IsSet(Gura_Symbol(lasteol));
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
	//Template::Parser parser(autoIndentFlag, appendLastEOLFlag);
	//AutoPtr<Template> pTemplateSuper(parser.ParseStream(env, sig, args.GetStream(0)));
	//if (pTemplateSuper.IsNull()) return Value::Null;
	//pTemplate->SetTemplateSuper(pTemplateSuper.release());
	return Value::Null;
}

// template#block(name:string):void {block}
Gura_DeclareMethod(template, block)
{
	SetMode(RSLTMODE_Void, FLAG_None);
	DeclareArg(env, "name", VTYPE_string);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementMethod(template, block)
{
	Template *pTemplate = Object_template::GetThisObj(args)->GetTemplate();
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
	Gura_AssignMethod(template, block);
}

Object *Class_template::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return NULL;
}

}
