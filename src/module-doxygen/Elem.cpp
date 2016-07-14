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
bool ElemList::Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const
{
	foreach_const (ElemList, ppElem, *this) {
		const Elem *pElem = *ppElem;
		if (!pElem->Render(pRenderer, pCfg, stream)) return false;
	}
	return true;
}

void ElemList::Print(Environment &env, SimpleStream &stream, int indentLevel) const
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

bool Elem_Container::Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const
{
	return _elemOwner.Render(pRenderer, pCfg, stream);
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

void Elem_Container::Print(Environment &env, SimpleStream &stream, int indentLevel) const
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

bool Elem_Empty::Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const
{
	// nothing to do
	return true;
}

String Elem_Empty::ToString() const
{
	return "";
}

void Elem_Empty::Print(Environment &env, SimpleStream &stream, int indentLevel) const
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

bool Elem_Text::Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const
{
	Signal &sig = pRenderer->GetSignal();
	stream.Print(sig, _text.c_str());
	return sig.IsNoSignalled();
}

String Elem_Text::ToString() const
{
	return MakeQuotedString(_text.c_str(), false);
}

void Elem_Text::Print(Environment &env, SimpleStream &stream, int indentLevel) const
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

bool Elem_Command::Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const
{
	Object *pObjAssoc = pRenderer->GetObjectAssoc();
	Environment &env = *pObjAssoc;
	Signal &sig = env.GetSignal();
	const Function *pFunc = pObjAssoc->LookupFunction(_pCmdFmt->GetSymbolEx(), ENVREF_Escalate);
	if (pFunc == nullptr) return true;
	ValueList valListArg;
	valListArg.reserve(_elemArgs.size());
	foreach_const (ElemList, ppElemArg, _elemArgs) {
		const Elem *pElemArg = *ppElemArg;
		String strArg;
		SimpleStream_StringWriter streamArg(strArg);
		if (!pElemArg->Render(pRenderer, pCfg, streamArg)) return false;
		valListArg.push_back(Value(strArg));
	}
	Value value = pObjAssoc->EvalMethod(env, pFunc, valListArg);
	if (value.Is_string()) {
		stream.Print(sig, value.GetString());
	}
	return env.IsNoSignalled();
}

String Elem_Command::ToString() const
{
	String rtn;
	rtn += _pCmdFmt->GetNameEx();
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

void Elem_Command::Print(Environment &env, SimpleStream &stream, int indentLevel) const
{
	Signal &sig = env.GetSignal();
	stream.Printf(sig, "%*s%s{", indentLevel * 2, "", _pCmdFmt->GetNameEx());
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
