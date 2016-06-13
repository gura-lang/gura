//=============================================================================
// Elem.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)
//-----------------------------------------------------------------------------
// Elem
//-----------------------------------------------------------------------------
Elem::Elem() : _cntRef(1)
{
}

Elem::~Elem()
{
}

//-----------------------------------------------------------------------------
// ElemList
//-----------------------------------------------------------------------------
void ElemList::Print(int indentLevel) const
{
	foreach_const (ElemList, ppElem, *this) {
		(*ppElem)->Print(indentLevel);
	}
}

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
		Elem::Delete(*ppElem);
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
		Elem::Delete(iter->second);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Elem_Container
//-----------------------------------------------------------------------------
Elem_Container::Elem_Container()
{
}

void Elem_Container::AddElem(Elem *pElem)
{
	_elemOwner.push_back(pElem);
}

void Elem_Container::Print(int indentLevel) const
{
	::printf("%*sContainer\n", indentLevel * 2, "");
	_elemOwner.Print(indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Elem_Text
//-----------------------------------------------------------------------------
Elem_Text::Elem_Text(const String &str) : _str(str)
{
}

void Elem_Text::Print(int indentLevel) const
{
	::printf("%*s\"%s\"\n", indentLevel * 2, "", _str.c_str());
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

void Elem_Command::Print(int indentLevel) const
{
	const CommandFormat::ArgOwner &argOwner = _pCmdFmt->GetArgOwner();
	::printf("%*s@%s\n", indentLevel * 2, "", _pCmdFmt->GetName());
	foreach_const (CommandFormat::ArgOwner, ppArg, argOwner) {
		const char *name = (*ppArg)->GetName();
		::printf("%*s%s:\n", (indentLevel + 1) * 2, "", name);
	}
}

Gura_EndModuleScope(doxygen)
