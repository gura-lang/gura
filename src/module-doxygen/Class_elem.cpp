//=============================================================================
// Class_elem.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_elem
//-----------------------------------------------------------------------------
Object_elem::~Object_elem()
{
}

Object *Object_elem::Clone() const
{
	return nullptr;
}

bool Object_elem::DoDirProp(Environment &env, SymbolSet &symbols)
{
#if 0
	Signal &sig = GetSignal();
	if (!Object::DoDirProp(env, symbols)) return false;
	symbols.insert(Gura_Symbol(string));
	symbols.insert(Gura_Symbol(begin));
	symbols.insert(Gura_Symbol(end));
#endif
	return true;
}

Value Object_elem::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(_elem.GetString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(begin))) {
		return Value(_elem.GetPosBegin());
	} else if (pSymbol->IsIdentical(Gura_Symbol(end))) {
		return Value(_elem.GetPosEnd());
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_elem::ToString(bool exprFlag)
{
	String rtn;
	//rtn += "<doxygen.elem:";
	//rtn += ">";
	rtn += _pElem->ToString();
	return rtn;
}

//----------------------------------------------------------------------------
// Methods
//----------------------------------------------------------------------------
// doxygen.elem#print(out?:stream):void
Gura_DeclareMethod(elem, print)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "out", VTYPE_stream, OCCUR_ZeroOrOnce);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(elem, print)
{
	Stream &stream = arg.IsValid(0)? arg.GetStream(0) : *env.GetConsole();
	const Elem *pElem = Object_elem::GetObjectThis(arg)->GetElem();
	pElem->Print(env, stream, 0);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.elem
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(elem)
{
	Gura_AssignMethod(elem, print);
}

Gura_EndModuleScope(doxygen)
