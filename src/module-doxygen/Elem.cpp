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
		const Elem *pElem = *ppElem;
		pElem->Print(indentLevel);
	}
}

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
// Elem_Container
//-----------------------------------------------------------------------------
Elem_Container::Elem_Container()
{
}

String Elem_Container::ToString() const
{
	String rtn;
	foreach_const (ElemOwner, ppElem, _elemOwner) {
		const Elem *pElem = *ppElem;
		rtn += pElem->ToString();
	}
	return "";
}

void Elem_Container::Print(int indentLevel) const
{
	::printf("%*scontainer:\n", indentLevel * 2, "");
	_elemOwner.Print(indentLevel);
}

//-----------------------------------------------------------------------------
// Elem_Empty
//-----------------------------------------------------------------------------
Elem_Empty::Elem_Empty()
{
}

String Elem_Empty::ToString() const
{
	return "";
}

void Elem_Empty::Print(int indentLevel) const
{
	::printf("%*sempty\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// Elem_Text
//-----------------------------------------------------------------------------
Elem_Text::Elem_Text(const String &text) : _text(text)
{
}

String Elem_Text::ToString() const
{
	return MakeQuotedString(_text.c_str(), false);
}

void Elem_Text::Print(int indentLevel) const
{
	::printf("%*stext:%s\n", indentLevel * 2, "", MakeQuotedString(_text.c_str()).c_str());
}

//-----------------------------------------------------------------------------
// Elem_Command
//-----------------------------------------------------------------------------
Elem_Command::Elem_Command(const CommandFormat *pCmdFmt) : _pCmdFmt(pCmdFmt)
{
}

String Elem_Command::ToString() const
{
	String rtn;
	rtn += "@";
	rtn += _pCmdFmt->GetName();
	rtn += "{";
	const CommandFormat::ArgOwner &argOwner = _pCmdFmt->GetArgOwner();
	CommandFormat::ArgOwner::const_iterator ppArg = argOwner.begin();
	foreach_const (ElemOwner, ppElemArg, _elemArgs) {
		if (ppArg == argOwner.end()) break;
		const Elem *pElemArg = *ppElemArg;
		const CommandFormat::Arg *pArg = *ppArg;
		rtn += pArg->GetName();
		rtn += ":'";
		rtn += pElemArg->ToString();
		rtn += "'";
		ppArg++;
	}
	rtn += "}";
	return "";
}

void Elem_Command::Print(int indentLevel) const
{
	::printf("%*scommand:%s\n", indentLevel * 2, "", _pCmdFmt->GetName());
	_elemArgs.Print(indentLevel + 1);
}

Gura_EndModuleScope(doxygen)
