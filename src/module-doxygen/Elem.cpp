//=============================================================================
// Elem.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Elem
//-----------------------------------------------------------------------------
const Elem *Elem::Empty = nullptr;

Elem::Elem(Type type) : _cntRef(1), _type(type), _pElemPrev(nullptr), _pElemNext(nullptr)
{
}

Elem::Elem(ElemOwner *pElemChildren, Type type) :
	_cntRef(1), _type(type), _pElemChildren(pElemChildren),
	_pElemPrev(nullptr), _pElemNext(nullptr)
{
}

Elem::~Elem()
{
}

void Elem::Initialize()
{
	Empty = new Elem_Empty();
}

size_t Elem::GetIndex() const
{
	size_t idx = 0;
	for (const Elem *pElem = GetElemPrev(); pElem != nullptr && pElem->IsSameType(this);
		 pElem = pElem->GetElemPrev()) idx++;
	return idx;
}

const Elem *Elem::ReduceContent() const
{
	return this;
}

bool Elem::IsSameType(const Elem *pElem) const
{
	return pElem->GetType() == GetType();
}

//-----------------------------------------------------------------------------
// ElemList
//-----------------------------------------------------------------------------
bool ElemList::Render(Renderer *pRenderer) const
{
	foreach_const (ElemList, ppElem, *this) {
		const Elem *pElem = *ppElem;
		if (!pElem->Render(pRenderer)) return false;
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

void ElemOwner::AddElem(Elem *pElem)
{
	if (!empty()) {
		Elem *pElemPrev = back();
		pElemPrev->SetElemNext(pElem);
		pElem->SetElemPrev(pElemPrev);
	}
	ElemList::push_back(pElem);
}

//-----------------------------------------------------------------------------
// Elem_Empty
//-----------------------------------------------------------------------------
Elem_Empty::Elem_Empty(Type type) : Elem(type)
{
}

bool Elem_Empty::DoDirProp(Environment &env, SymbolSet &symbols)
{
	return true;
}

Value Elem_Empty::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	return Value::Nil;
}

bool Elem_Empty::Render(Renderer *pRenderer) const
{
	// nothing to do
	return true;
}

String Elem_Empty::ToString() const
{
	return "";
}

String Elem_Empty::MakeTypeName() const
{
	return "empty";
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

bool Elem_String::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_UserSymbol(string));
	return true;
}

Value Elem_String::DoGetProp(Environment &env, const Symbol *pSymbol,
							 const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(string))) {
		return Value(_str);
	}	
	evaluatedFlag = false;
	return Value::Nil;
}

bool Elem_String::Render(Renderer *pRenderer) const
{
	Signal &sig = pRenderer->GetSignal();
	pRenderer->GetStream()->Print(sig, _str.c_str());
	return sig.IsNoSignalled();
}

String Elem_String::ToString() const
{
	return MakeQuotedString(_str.c_str(), false);
}

String Elem_String::MakeTypeName() const
{
	return "string";
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
	if (pCmdFmt->GetEndDetector() != nullptr) {
		_pElemChildren.reset(new ElemOwner());
	}
}

bool Elem_Command::DoDirProp(Environment &env, SymbolSet &symbols)
{
	const CommandFormat::ArgIndexMap &argIndexMap = _pCmdFmt->GetArgIndexMap();
	foreach_const (CommandFormat::ArgIndexMap, iter, argIndexMap) {
		symbols.insert(iter->first);
	}
	return true;
}

Value Elem_Command::DoGetProp(Environment &env, const Symbol *pSymbol,
							  const SymbolSet &attrs, bool &evaluatedFlag)
{
	int idx = _pCmdFmt->GetArgIndex(pSymbol);
	if (idx < 0) return Value::Nil;
	evaluatedFlag = true;
	if (idx < static_cast<int>(_pElemArgs->size())) {
		return Value(new Object_elem(_pElemArgs->At(idx)->Reference()));
	}
	return Value::Nil;
}

bool Elem_Command::Render(Renderer *pRenderer) const
{
	Object *pObjAssoc = pRenderer->GetObjectAssoc();
	Environment &env = *pObjAssoc;
	Signal &sig = env.GetSignal();
	const Function *pFunc = pObjAssoc->LookupFunction(_pCmdFmt->GetSymbolEx(), ENVREF_Escalate);
	if (pFunc == nullptr) return true;
	ValueList valListArg;
	valListArg.reserve(1);
	valListArg.push_back(Value(new Object_elem(Reference())));
	pObjAssoc->EvalMethod(env, pFunc, valListArg);
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

String Elem_Command::MakeTypeName() const
{
	String rtn;
	rtn += "command:";
	rtn += _pCmdFmt->GetNameEx();
	return rtn;
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
	if (IsParent()) {
		stream.Printf(sig, "%*s----\n", (indentLevel + 1) * 2, "");
		_pElemChildren->Print(env, stream, indentLevel + 1);
	}
}

bool Elem_Command::IsSameType(const Elem *pElem) const
{
	if (pElem->GetType() == GetType()) {
		const Elem_Command *pElemEx = dynamic_cast<const Elem_Command *>(pElem);
		return pElemEx->GetCommandFormat() == GetCommandFormat();
	}
	return false;
}

//-----------------------------------------------------------------------------
// Elem_Text
//-----------------------------------------------------------------------------
Elem_Text::Elem_Text(Type type) : Elem(new ElemOwner(), type)
{
}

Elem_Text::Elem_Text(ElemOwner *pElemChildren, Type type) :
	Elem(pElemChildren, type)
{
}

const Elem *Elem_Text::ReduceContent() const
{
	return _pElemChildren->empty()? Elem::Empty :
		(_pElemChildren->size() == 1)? _pElemChildren->front() : this;
}

bool Elem_Text::DoDirProp(Environment &env, SymbolSet &symbols)
{
	symbols.insert(Gura_UserSymbol(children));
	return true;
}

Value Elem_Text::DoGetProp(Environment &env, const Symbol *pSymbol,
						   const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_UserSymbol(children))) {
		AutoPtr<Iterator> pIterator(new Iterator_Elem(_pElemChildren->Reference()));
		return Value(new Object_iterator(env, pIterator.release()));
	}	
	evaluatedFlag = false;
	return Value::Nil;
}

bool Elem_Text::Render(Renderer *pRenderer) const
{
	return _pElemChildren->Render(pRenderer);
}

String Elem_Text::ToString() const
{
	String rtn;
	foreach_const (ElemOwner, ppElem, *_pElemChildren) {
		const Elem *pElem = *ppElem;
		rtn += pElem->ToString();
	}
	return "";
}

String Elem_Text::MakeTypeName() const
{
	return "text";
}

void Elem_Text::Print(Environment &env, SimpleStream &stream, int indentLevel) const
{
	Signal &sig = env.GetSignal();
	stream.Printf(sig, "%*s[\n", indentLevel * 2, "");
	_pElemChildren->Print(env, stream, indentLevel + 1);
	stream.Printf(sig, "%*s]\n", indentLevel * 2, "");
}

//-----------------------------------------------------------------------------
// Iterator_Elem
//-----------------------------------------------------------------------------
Iterator_Elem::Iterator_Elem(ElemOwner *pElemOwner) :
	Iterator(Finite), _pElemOwner(pElemOwner), _idx(0)
{
}

Iterator_Elem::Iterator_Elem(const Iterator_Elem &iter) :
	Iterator(Finite), _pElemOwner(iter._pElemOwner->Reference()), _idx(iter._idx)
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
		Elem *pElem = _pElemOwner->At(_idx);
		_idx++;
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

Gura_EndModuleScope(doxygen)
