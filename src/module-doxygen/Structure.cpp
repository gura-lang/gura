//=============================================================================
// Structure.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Structure
//-----------------------------------------------------------------------------
Structure::Structure(bool afterMemberFlag) :
	_cntRef(1), _afterMemberFlag(afterMemberFlag),
	_pStructureOwner(new StructureOwner()), _pElemOwner(new ElemOwner())
{
}

//-----------------------------------------------------------------------------
// StructureList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// StructureOwner
//-----------------------------------------------------------------------------
StructureOwner::StructureOwner() : _cntRef(1)
{
}

StructureOwner::~StructureOwner()
{
	Clear();
}

void StructureOwner::Clear()
{
	foreach (StructureOwner, ppStructure, *this) {
		Structure::Delete(*ppStructure);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Iterator_Structure
//-----------------------------------------------------------------------------
Iterator_Structure::Iterator_Structure(StructureOwner *pStructureOwner) :
	Iterator(false), _pStructureOwner(pStructureOwner), _idx(0)
{
}

Iterator_Structure::Iterator_Structure(const Iterator_Structure &iter) :
	Iterator(false), _pStructureOwner(iter._pStructureOwner->Reference()), _idx(iter._idx)
{
}

Iterator *Iterator_Structure::Clone() const
{
	return new Iterator_Structure(*this);
}

Iterator *Iterator_Structure::GetSource()
{
	return nullptr;
}

bool Iterator_Structure::DoNext(Environment &env, Value &value)
{
	if (_idx >= _pStructureOwner->size()) return false;
	Structure *pStructure = (*_pStructureOwner)[_idx++];
	value = Value(new Object_structure(pStructure->Reference()));
	return true;
}

String Iterator_Structure::ToString() const
{
	String rtn = "doxygen.structure";
	return rtn;
}

void Iterator_Structure::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModuleScope(doxygen)
