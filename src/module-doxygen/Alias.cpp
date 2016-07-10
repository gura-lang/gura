//=============================================================================
// Alias.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Alias
//-----------------------------------------------------------------------------
Alias::Alias()
{
}

bool Alias::Parse(const char *str)
{
	return true;
}

String Alias::Evaluate(Environment &env, const StringList &strArgs) const
{
	String rtn;
	if (!_elemOwner.Evaluate(env, rtn, strArgs)) return "";
	return rtn;
}

//-----------------------------------------------------------------------------
// Alias::Elem
//-----------------------------------------------------------------------------
Alias::Elem::~Elem()
{
}

//-----------------------------------------------------------------------------
// Alias::Elem_Text
//-----------------------------------------------------------------------------
bool Alias::Elem_Text::Evaluate(Environment &env, String &rtn, const StringList &strArgs) const
{
	return true;
}

//-----------------------------------------------------------------------------
// Alias::Elem_ArgRef
//-----------------------------------------------------------------------------
bool Alias::Elem_ArgRef::Evaluate(Environment &env, String &rtn, const StringList &strArgs) const
{
	return true;
}

//-----------------------------------------------------------------------------
// Alias::ElemList
//-----------------------------------------------------------------------------
bool Alias::ElemList::Evaluate(Environment &env, String &rtn, const StringList &strArgs) const
{
	foreach_const (ElemList, ppElem, *this) {
		const Elem *pElem = *ppElem;
		if (!pElem->Evaluate(env, rtn, strArgs)) return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Alias::ElemOwner
//-----------------------------------------------------------------------------
Alias::ElemOwner::~ElemOwner()
{
	Clear();
}

void Alias::ElemOwner::Clear()
{
	foreach (ElemOwner, ppElem, *this) {
		delete *ppElem;
	}
	clear();
}

//-----------------------------------------------------------------------------
// Aliases
//-----------------------------------------------------------------------------
bool Aliases::Parse(const char *str)
{
	return true;
}

Gura_EndModuleScope(doxygen)
