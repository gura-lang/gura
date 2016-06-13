//=============================================================================
// Elem.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)
//-----------------------------------------------------------------------------
// Elem
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ElemList
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ElemDict
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// ElemOwner
//-----------------------------------------------------------------------------
ElemOwner::~ElemOwner()
{
	Clear();
}

void ElemOwner::Clear()
{
	foreach (ElemOwner, ppElem, *this) {
		delete *ppElem;
	}
	clear();
}

//-----------------------------------------------------------------------------
// ElemDictOwner
//-----------------------------------------------------------------------------
ElemDictOwner::~ElemDictOwner()
{
	Clear();
}

void ElemDictOwner::Clear()
{
	foreach (ElemDictOwner, iter, *this) {
		delete iter->second;
	}
	clear();
}

//-----------------------------------------------------------------------------
// Elem_Container
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Elem_Text
//-----------------------------------------------------------------------------
Elem_Text::Elem_Text(const String &str) : _str(str)
{
}

//-----------------------------------------------------------------------------
// Elem_Command
//-----------------------------------------------------------------------------
Elem_Command::Elem_Command(const CommandFormat *pCmdFmt) : _pCmdFmt(pCmdFmt), _iArg(-1)
{
}

void Elem_Command::SetArgElem(Elem *pElem)
{
	_elemDictArg[GetArgCur()->GetName()] = pElem;
}

const CommandFormat::Arg *Elem_Command::NextArg()
{
	_iArg++;
	return GetArgCur();
}

const CommandFormat::Arg *Elem_Command::GetArgCur() const
{
	const CommandFormat::ArgOwner &argOwner = _pCmdFmt->GetArgOwner();
	return (_iArg < argOwner.size())? argOwner[_iArg] : nullptr;
}

Gura_EndModuleScope(doxygen)
