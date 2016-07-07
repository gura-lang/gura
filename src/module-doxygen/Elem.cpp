//=============================================================================
// Elem.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Elem
//-----------------------------------------------------------------------------
const Elem *Elem::Empty = nullptr;

Elem::Elem() : _cntRef(1)
{
}

Elem::~Elem()
{
}

void Elem::Initialize()
{
	Empty = new Elem_Empty();
}

//-----------------------------------------------------------------------------
// ElemList
//-----------------------------------------------------------------------------
void ElemList::Print(Environment &env, Stream &stream, int indentLevel) const
{
	foreach_const (ElemList, ppElem, *this) {
		const Elem *pElem = *ppElem;
		pElem->Print(env, stream, indentLevel);
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

const Elem *Elem_Container::ReduceContent() const
{
	return _elemOwner.empty()? Elem::Empty :
		(_elemOwner.size() == 1)? _elemOwner.front() : this;
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

void Elem_Container::Print(Environment &env, Stream &stream, int indentLevel) const
{
	Signal &sig = env.GetSignal();
	stream.Printf(sig, "%*s{\n", indentLevel * 2, "");
	_elemOwner.Print(env, stream, indentLevel + 1);
	stream.Printf(sig, "%*s}\n", indentLevel * 2, "");
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

void Elem_Empty::Print(Environment &env, Stream &stream, int indentLevel) const
{
	Signal &sig = env.GetSignal();
	stream.Printf(sig, "%*s-\n", indentLevel * 2, "");
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

void Elem_Text::Print(Environment &env, Stream &stream, int indentLevel) const
{
	Signal &sig = env.GetSignal();
	stream.Printf(sig, "%*s%s\n", indentLevel * 2, "", MakeQuotedString(_text.c_str()).c_str());
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
	ElemOwner::const_iterator ppElemArg = _elemArgs.begin();
	CommandFormat::ArgOwner::const_iterator ppArg = argOwner.begin();
	for ( ; ppElemArg != _elemArgs.end() && ppArg != argOwner.end(); ppElemArg++, ppArg++) {
		const Elem *pElemArg = *ppElemArg;
		const CommandFormat::Arg *pArg = *ppArg;
		rtn += pArg->GetName();
		rtn += ":'";
		rtn += pElemArg->ToString();
		rtn += "'";
	}
	rtn += "}";
	return "";
}

void Elem_Command::Print(Environment &env, Stream &stream, int indentLevel) const
{
	Signal &sig = env.GetSignal();
	stream.Printf(sig, "%*s@%s{", indentLevel * 2, "", _pCmdFmt->GetName());
	size_t iArg = 0;
	const CommandFormat::ArgOwner &argOwner = _pCmdFmt->GetArgOwner();
	foreach_const (CommandFormat::ArgOwner, ppArg, argOwner) {
		const CommandFormat::Arg *pArg = *ppArg;
		if (iArg > 0) stream.Printf(sig, ", ");
		stream.Printf(sig, "%s:%s", pArg->GetName(), pArg->GetArgTypeName());
		iArg++;
	}
	stream.Printf(sig, "}\n");
	_elemArgs.Print(env, stream, indentLevel + 1);
}

Gura_EndModuleScope(doxygen)
