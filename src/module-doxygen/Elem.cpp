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
String ElemList::GetText() const
{
	String rtn;
	foreach_const (ElemList, ppElem, *this) {
		rtn += (*ppElem)->GetText();
	}
	return rtn;
}

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

String Elem_Container::GetText() const
{
	return _elemOwner.GetText();
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

String Elem_Text::GetText() const
{
	return _str;
}

void Elem_Text::Print(int indentLevel) const
{
	::printf("%*s%s\n", indentLevel * 2, "", MakeQuotedString(_str.c_str()).c_str());
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

bool Elem_Command::NextArg()
{
	const CommandFormat::ArgOwner &argOwner = _pCmdFmt->GetArgOwner();
	_iArg++;
	return _iArg < argOwner.size();
}

const CommandFormat::Arg *Elem_Command::GetArgCur() const
{
	const CommandFormat::ArgOwner &argOwner = _pCmdFmt->GetArgOwner();
	return (_iArg < argOwner.size())? argOwner[_iArg] : nullptr;
}

String Elem_Command::GetText() const
{
	return "";
}

void Elem_Command::Print(int indentLevel) const
{
	const CommandFormat::ArgOwner &argOwner = _pCmdFmt->GetArgOwner();
	::printf("%*s@%s\n", indentLevel * 2, "", _pCmdFmt->GetName());
	foreach_const (CommandFormat::ArgOwner, ppArg, argOwner) {
		const CommandFormat::Arg *pArg = *ppArg;
		const char *name = pArg->GetName();
		ElemDict::const_iterator iter = _elemDictArg.find(name);
		::printf("%*s%s<%s>: %s\n", (indentLevel + 1) * 2, "", name, pArg->GetArgTypeName(),
				 (iter == _elemDictArg.end())? "(none)" :
					 MakeQuotedString(iter->second->GetText().c_str()).c_str());
	}
}

Gura_EndModuleScope(doxygen)
