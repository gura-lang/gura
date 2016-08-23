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
	return true;
}

Value Object_renderer::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = false;
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
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"Creates a `doxygen.renderer` instance.\n"
		"\n"
		GURA_HELPTEXT_BLOCK_en("renderer", "doxygen.renderer"));
}

Gura_ImplementFunction(renderer)
{
	Signal &sig = env.GetSignal();
	Object_renderer *pObj = Object_renderer::GetObjectThis(arg);
	if (pObj == nullptr) {
		pObj = new Object_renderer();
		pObj->SetRenderer(new Renderer(pObj));
		return ReturnValue(env, arg, Value(pObj));
	}
	return ReturnValue(env, arg, arg.GetValueThis());
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for doxygen.renderer
//-----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(renderer)
{
	Gura_AssignFunction(renderer);
}

Gura_ImplementDescendantCreator(renderer)
{
	Object_renderer *pObj = new Object_renderer((pClass == nullptr)? this : pClass);
	pObj->SetRenderer(new Renderer(pObj));
	return pObj;
}

Gura_EndModuleScope(doxygen)
