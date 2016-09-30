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
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_UserSymbol(aftermember));
	symbols.insert(Gura_UserSymbol(source));
	return true;
}

Value Object_structure::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(aftermember))) {
		return Value(_pStructure->GetAfterMemberFlag());
	} else if (pSymbol->IsIdentical(Gura_UserSymbol(source))) {
		return Value(_pStructure->GetSource());
	}
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_structure::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.structure";
	do {
		char buff[32];
		::sprintf(buff, ":%ldelems", _pStructure->GetElemOwner().size());
		rtn += buff;
	} while (0);
	rtn += ">";
	return rtn;
}

//----------------------------------------------------------------------------
// Constructor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.structure#elems() {block?}
Gura_DeclareMethod(structure, elems)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that returns `doxygen.elem` instances of all the elements contained in the structure.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(structure, elems)
{
	const Structure *pStructure = Object_structure::GetObjectThis(arg)->GetStructure();
	AutoPtr<Iterator> pIterator(
		new Iterator_Elem(pStructure->GetElemOwner().Reference()));
	return ReturnIterator(env, arg, pIterator.release());
}

// doxygen.structure#substructures() {block?}
Gura_DeclareMethod(structure, substructures)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	DeclareBlock(OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en),
		"Creates an iterator that returns `doxygen.structure` instances of sub structures contained in the structure.\n"
		"\n"
		GURA_HELPTEXT_ITERATOR_en());
}

Gura_ImplementMethod(structure, substructures)
{
	const Structure *pStructure = Object_structure::GetObjectThis(arg)->GetStructure();
	AutoPtr<Iterator> pIterator(
		new Iterator_Structure(pStructure->GetStructureOwner().Reference()));
	return ReturnIterator(env, arg, pIterator.release());
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.structure
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(structure)
{
	Gura_AssignValue(structure, Value(Reference()));
	Gura_AssignMethod(structure, elems);
	Gura_AssignMethod(structure, substructures);
}

Gura_EndModuleScope(doxygen)
