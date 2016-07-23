//=============================================================================
// Class_elem.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_elem
//-----------------------------------------------------------------------------
Object_elem::~Object_elem()
{
}

Object *Object_elem::Clone() const
{
	return nullptr;
}

bool Object_elem::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Object_elem::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Nil;
}

String Object_elem::ToString(bool exprFlag)
{
	String rtn;
	//rtn += "<doxygen.elem:";
	//rtn += ">";
	rtn += _pElem->ToString();
	return rtn;
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.elem#print(indent?:number, out?:stream):void
Gura_DeclareMethod(elem, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "indent", VTYPE_number, OCCUR_ZeroOrOnce);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(elem, print)
{
	const Elem *pElem = Object_elem::GetObjectThis(arg)->GetElem();
	int indentLevel = arg.IsValid(0)? arg.GetInt(0) : 0;
	Stream &stream = arg.IsValid(1)? arg.GetStream(1) : *env.GetConsole();
	pElem->Print(env, stream, indentLevel);
	return Value::Nil;
}

// doxygen.elem#render(renderer:doxygen.renderer, cfg?:doxygen.configuration, out?:stream:w)
Gura_DeclareMethod(elem, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_renderer, OCCUR_Once);
	DeclareArg(env, "cfg", VTYPE_configuration, OCCUR_ZeroOrOnce);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(elem, render)
{
	const Elem *pElem = Object_elem::GetObjectThis(arg)->GetElem();
	Renderer *pRenderer = Object_renderer::GetObject(arg, 0)->GetRenderer();
	const Configuration *pCfg = arg.IsValid(1)?
		Object_configuration::GetObject(arg, 1)->GetConfiguration() : nullptr;
	if (arg.IsValid(2)) {
		SimpleStream &stream = arg.GetStream(2);
		pElem->Render(pRenderer, pCfg, stream);
		return Value::Nil;
	} else {
		String str;
		SimpleStream_StringWriter stream(str);
		if (!pElem->Render(pRenderer, pCfg, stream)) return Value::Nil;
		return Value(str);
	}
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.elem
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(elem)
{
	Gura_AssignMethod(elem, print);
	Gura_AssignMethod(elem, render);
}

Gura_EndModuleScope(doxygen)
