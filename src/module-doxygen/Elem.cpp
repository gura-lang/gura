//=============================================================================
// Elem.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Elem
//-----------------------------------------------------------------------------
const Elem *Elem::Empty = nullptr;

Elem::Elem(Type type) : _cntRef(1), _type(type)
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
ElemOwner::ElemOwner() : _cntRef(1)
{
}

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
// Elem_Empty
//-----------------------------------------------------------------------------
Elem_Empty::Elem_Empty(Type type) : Elem(type)
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
// Elem_String
//-----------------------------------------------------------------------------
Elem_String::Elem_String(const String &str, Type type) : Elem(type), _str(str)
{
}

bool Elem_String::Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const
{
	Signal &sig = pRenderer->GetSignal();
	stream.Print(sig, _str.c_str());
	return sig.IsNoSignalled();
}

String Elem_String::ToString() const
{
	return MakeQuotedString(_str.c_str(), false);
}

void Elem_String::Print(Environment &env, SimpleStream &stream, int indentLevel) const
{
	Signal &sig = env.GetSignal();
	stream.Printf(sig, "%*s%s\n", indentLevel * 2, "", MakeQuotedString(_str.c_str()).c_str());
}

//-----------------------------------------------------------------------------
// Elem_Command
//-----------------------------------------------------------------------------
Elem_Command::Elem_Command(const CommandFormat *pCmdFmt, Type type) :
	Elem(type), _pCmdFmt(pCmdFmt), _pElemArgs(new ElemOwner())
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
	valListArg.reserve(_pElemArgs->size());
	foreach_const (ElemList, ppElemArg, *_pElemArgs) {
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
	ElemOwner::const_iterator ppElemArg = _pElemArgs->begin();
	CommandFormat::ArgOwner::const_iterator ppArg = argOwner.begin();
	for ( ; ppElemArg != _pElemArgs->end() && ppArg != argOwner.end(); ppElemArg++, ppArg++) {
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
	_pElemArgs->Print(env, stream, indentLevel + 1);
}

//-----------------------------------------------------------------------------
// Elem_Composite
//-----------------------------------------------------------------------------
Elem_Composite::Elem_Composite(Type type) : Elem(type), _pElemOwner(new ElemOwner())
{
}

Elem_Composite::Elem_Composite(ElemOwner *pElemOwner, Type type) :
	Elem(type), _pElemOwner(pElemOwner)
{
}

const Elem *Elem_Composite::ReduceContent() const
{
	return _pElemOwner->empty()? Elem::Empty :
		(_pElemOwner->size() == 1)? _pElemOwner->front() : this;
}

bool Elem_Composite::Render(Renderer *pRenderer, const Configuration *pCfg, SimpleStream &stream) const
{
	return _pElemOwner->Render(pRenderer, pCfg, stream);
}

String Elem_Composite::ToString() const
{
	String rtn;
	foreach_const (ElemOwner, ppElem, *_pElemOwner) {
		const Elem *pElem = *ppElem;
		rtn += pElem->ToString();
	}
	return "";
}

void Elem_Composite::Print(Environment &env, SimpleStream &stream, int indentLevel) const
{
	Signal &sig = env.GetSignal();
	stream.Printf(sig, "%*s[\n", indentLevel * 2, "");
	_pElemOwner->Print(env, stream, indentLevel + 1);
	stream.Printf(sig, "%*s]\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// Iterator_Elem
//-----------------------------------------------------------------------------
Iterator_Elem::Iterator_Elem(ElemOwner *pElemOwner) :
	Iterator(false), _pElemOwner(pElemOwner), _idx(0)
{
}

Iterator_Elem::Iterator_Elem(const Iterator_Elem &iter) :
	Iterator(false), _pElemOwner(iter._pElemOwner->Reference()), _idx(iter._idx)
{
}

Iterator *Iterator_Elem::Clone() const
{
	return new Iterator_Elem(*this);
}

Iterator *Iterator_Elem::GetSource()
{
	return nullptr;
}

bool Iterator_Elem::DoNext(Environment &env, Value &value)
{
	if (_idx < _pElemOwner->size()) {
		Elem *pElem = (*_pElemOwner)[_idx++];
		value = Value(new Object_elem(pElem->Reference()));
		return true;
	}
	return false;
}

String Iterator_Elem::ToString() const
{
	String rtn = "doxygen.elem";
	return rtn;
}

void Iterator_Elem::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_Elem_Command
//-----------------------------------------------------------------------------
Iterator_Elem_Command::Iterator_Elem_Command(ElemOwner *pElemOwner, const String &name) :
	Iterator(false), _pElemOwner(pElemOwner), _idx(0), _name(name)
{
}

Iterator_Elem_Command::Iterator_Elem_Command(const Iterator_Elem_Command &iter) :
	Iterator(false), _pElemOwner(iter._pElemOwner->Reference()), _idx(iter._idx), _name(iter._name)
{
}

Iterator *Iterator_Elem_Command::Clone() const
{
	return new Iterator_Elem_Command(*this);
}

Iterator *Iterator_Elem_Command::GetSource()
{
	return nullptr;
}

bool Iterator_Elem_Command::DoNext(Environment &env, Value &value)
{
	while (_idx < _pElemOwner->size()) {
		Elem *pElem = (*_pElemOwner)[_idx++];
		if (pElem->GetType() != Elem::TYPE_Command) continue;
		Elem_Command *pElemEx = dynamic_cast<Elem_Command *>(pElem);
		if (::strcmp(pElemEx->GetCommandFormat()->GetName(), _name.c_str()) != 0) continue;
		value = Value(new Object_elem(pElem->Reference()));
		return true;
	}
	return false;
}

String Iterator_Elem_Command::ToString() const
{
	String rtn = "doxygen.elem@command";
	return rtn;
}

void Iterator_Elem_Command::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_Elem_Composite
//-----------------------------------------------------------------------------
Iterator_Elem_Composite::Iterator_Elem_Composite(ElemOwner *pElemOwner) :
	Iterator(false), _pElemOwner(pElemOwner), _idx(0)
{
}

Iterator_Elem_Composite::Iterator_Elem_Composite(const Iterator_Elem_Composite &iter) :
	Iterator(false), _pElemOwner(iter._pElemOwner->Reference()), _idx(iter._idx)
{
}

Iterator *Iterator_Elem_Composite::Clone() const
{
	return new Iterator_Elem_Composite(*this);
}

Iterator *Iterator_Elem_Composite::GetSource()
{
	return nullptr;
}

bool Iterator_Elem_Composite::DoNext(Environment &env, Value &value)
{
	while (_idx < _pElemOwner->size()) {
		Elem *pElem = (*_pElemOwner)[_idx++];
		if (pElem->GetType() != Elem::TYPE_Composite) continue;
		value = Value(new Object_elem(pElem->Reference()));
		return true;
	}
	return false;
}

String Iterator_Elem_Composite::ToString() const
{
	String rtn = "doxygen.elem@composite";
	return rtn;
}

void Iterator_Elem_Composite::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModuleScope(doxygen)
