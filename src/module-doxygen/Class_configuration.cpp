//=============================================================================
// Class_configuration.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_configuration
//-----------------------------------------------------------------------------
Object_configuration::~Object_configuration()
{
}

Object *Object_configuration::Clone() const
{
	return nullptr;
}

bool Object_configuration::DoDirProp(Environment &env, SymbolSet &symbols)
{
#if 0
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(elem));
#endif
	return true;
}

Value Object_configuration::DoGetProp(Environment &env, const Symbol *pSymbol,
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

String Object_configuration::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.configuration:";
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
// Class implementation for doxygen.configuration
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(configuration)
{
	//Gura_AssignFunction(configuration);
}

Gura_EndModuleScope(doxygen)
