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

//-----------------------------------------------------------------------------
// Class implementation for doxygen.structure
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(structure)
{
	Gura_AssignValue(structure, Value(Reference()));
	//Gura_AssignFunction(structure);
	//Gura_AssignMethod(structure, render);
}

Gura_EndModuleScope(doxygen)
