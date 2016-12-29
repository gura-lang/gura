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

//-----------------------------------------------------------------------------
// Implementation of properties
//-----------------------------------------------------------------------------
// doxygen.structure#aftermember
Gura_DeclareProperty_R(structure, aftermember)
{
	SetPropAttr(VTYPE_boolean);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(structure, aftermember)
{
	Structure *pStructure = Object_structure::GetObject(valueThis)->GetStructure();
	return Value(pStructure->GetAfterMemberFlag());
}

// doxygen.structure#source
Gura_DeclareProperty_R(structure, source)
{
	SetPropAttr(VTYPE_string);
	AddHelp(
		Gura_Symbol(en),
		""
		);
}

Gura_ImplementPropertyGetter(structure, source)
{
	Structure *pStructure = Object_structure::GetObject(valueThis)->GetStructure();
	return Value(pStructure->GetSource());
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
	// Assignment of properties
	Gura_AssignProperty(structure, aftermember);
	Gura_AssignProperty(structure, source);
	// Assignment of methods
	Gura_AssignMethod(structure, elems);
	Gura_AssignMethod(structure, substructures);
	// Assignment of value
	Gura_AssignValue(structure, Value(Reference()));
}

Gura_EndModuleScope(doxygen)
