//=============================================================================
// Class_renderer.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_renderer
//-----------------------------------------------------------------------------
Object_renderer::~Object_renderer()
{
}

Object *Object_renderer::Clone() const
{
	return nullptr;
}

bool Object_renderer::DoDirProp(Environment &env, SymbolSet &symbols)
{
#if 0
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(elem));
#endif
	return true;
}

Value Object_renderer::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(elem))) {
		return _pElem.IsNull()? Value::Nil : Value(new Object_elem(_pElem->Reference()));
	}
	evaluatedFlag = false;
#endif
	return Value::Nil;
}

String Object_renderer::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.renderer:";
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------
// doxygen.renderer() {block?}
Gura_DeclareFunction(renderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(renderer));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(renderer)
{
	Signal &sig = env.GetSignal();
	Object_renderer *pObj = Object_renderer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_renderer();
		pObj->SetRenderer(new Renderer());
		return ReturnValue(env, arg, Value(pObj));
	}
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.renderer#render(doc:doxygen.document, out?:stream:w)
Gura_DeclareMethod(renderer, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "doc", VTYPE_document, OCCUR_Once);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(renderer, render)
{
	Renderer *pRenderer = Object_renderer::GetObjectThis(arg)->GetRenderer();
	
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.renderer
//-----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(renderer)
{
	Gura_AssignFunction(renderer);
	Gura_AssignMethod(renderer, render);
}

Gura_ImplementDescendantCreator(renderer)
{
	Object_renderer *pObj = new Object_renderer((pClass == nullptr)? this : pClass);
	pObj->SetRenderer(new Renderer());
	return pObj;
}

Gura_EndModuleScope(doxygen)
