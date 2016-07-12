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

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Class implementation for doxygen.renderer
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(renderer)
{
	//Gura_AssignFunction(renderer);
}

Gura_EndModuleScope(doxygen)
