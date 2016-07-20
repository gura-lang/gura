//=============================================================================
// Class_structure.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_structure
//-----------------------------------------------------------------------------
Object_structure::~Object_structure()
{
}

Object *Object_structure::Clone() const
{
	return nullptr;
}

bool Object_structure::DoDirProp(Environment &env, SymbolSet &symbols)
{
#if 0
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(elem));
#endif
	return true;
}

Value Object_structure::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(elem))) {
		return _pStructure.IsNull()? Value::Nil :
			Value(new Object_elem(_pStructure->GetElemTop()->Reference()));
	}
	evaluatedFlag = false;
#endif
	return Value::Nil;
}

String Object_structure::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.structure:";
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.structure#render(renderer:doxygen.renderer, cfg?:doxygen.configuration, out?:stream:w)
Gura_DeclareMethod(structure, render)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareArg(env, "renderer", VTYPE_renderer, OCCUR_Once);
	DeclareArg(env, "cfg", VTYPE_configuration, OCCUR_ZeroOrOnce);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce, FLAG_Write);
}

Gura_ImplementMethod(structure, render)
{
	Structure *pStruct = Object_structure::GetObjectThis(arg)->GetStructure();
	Renderer *pRenderer = Object_renderer::GetObject(arg, 0)->GetRenderer();
	const Configuration *pCfg = arg.IsValid(1)?
		Object_configuration::GetObject(arg, 1)->GetConfiguration() : nullptr;
	if (arg.IsValid(2)) {
		SimpleStream &stream = arg.GetStream(2);
		pStruct->GetElemOwner().Render(pRenderer, pCfg, stream);
		return Value::Nil;
	} else {
		String str;
		SimpleStream_StringWriter stream(str);
		if (!pStruct->GetElemOwner().Render(pRenderer, pCfg, stream)) return Value::Nil;
		return Value(str);
	}
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.structure
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(structure)
{
	Gura_AssignValue(structure, Value(Reference()));
	Gura_AssignMethod(structure, render);
}

Gura_EndModuleScope(doxygen)
