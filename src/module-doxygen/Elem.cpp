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

Gura_EndModuleScope(doxygen)
