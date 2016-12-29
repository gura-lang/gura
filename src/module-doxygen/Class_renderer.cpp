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

String Object_renderer::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.renderer:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// doxygen.renderer#cfg
Gura_DeclareProperty_R(renderer, cfg)
{
	SetPropAttr(VTYPE_configuration);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(renderer, cfg)
{
	Renderer *pRenderer = Object_renderer::GetObject(valueThis)->GetRenderer();
	return Value(new Object_configuration(pRenderer->GetConfiguration()->Reference()));
}

// doxygen.renderer#out
Gura_DeclareProperty_R(renderer, out)
{
	SetPropAttr(VTYPE_stream);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(renderer, out)
{
	Renderer *pRenderer = Object_renderer::GetObject(valueThis)->GetRenderer();
	return Value(new Object_stream(env, pRenderer->GetStream()->Reference()));
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
		Gura_Symbol(en),
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
