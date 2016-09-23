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
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(out));
	symbols.insert(Gura_UserSymbol(cfg));
	return true;
}

Value Object_renderer::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(out))) {
		return Value(new Object_stream(env, _pRenderer->GetStream()->Reference()));
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(cfg))) {
		return Value(new Object_configuration(_pRenderer->GetConfiguration()->Reference()));
	}
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
// doxygen.renderer(out:stream, cfg:doxygen.configuration) {block?}
Gura_DeclareFunction(renderer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "out", VTYPE_stream);
	DeclareArg(env, "cfg", VTYPE_configuration);
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
	Value valueThis = arg.GetValueThis();
	if (valueThis.IsInvalid()) {
		Object_renderer *pObj = new Object_renderer();
		pObj->SetRenderer(new Renderer(pObj));
		valueThis = Value(pObj);
	}
	Renderer *pRenderer = Object_renderer::GetObject(valueThis)->GetRenderer();
	Stream &stream = arg.GetStream(0);
	pRenderer->SetStream(stream.Reference());
	const Configuration *pCfg = Object_configuration::GetObject(arg, 1)->GetConfiguration();
	pRenderer->SetConfiguration(pCfg->Reference());
	return ReturnValue(env, arg, valueThis);
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
