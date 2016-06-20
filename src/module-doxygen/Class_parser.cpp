//=============================================================================
// Class_parser.cpp
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(doxygen)

//-----------------------------------------------------------------------------
// Object_parser
//-----------------------------------------------------------------------------
Object_parser::~Object_parser()
{
}

Object *Object_parser::Clone() const
{
	return nullptr;
}

bool Object_parser::DoDirProp(Environment &env, SymbolSet &symbols)
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

Value Object_parser::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
#if 0
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(string))) {
		return Value(_parser.GetString());
	} else if (pSymbol->IsIdentical(Gura_Symbol(begin))) {
		return Value(_parser.GetPosBegin());
	} else if (pSymbol->IsIdentical(Gura_Symbol(end))) {
		return Value(_parser.GetPosEnd());
	}
#endif
	evaluatedFlag = false;
	return Value::Nil;
}

String Object_parser::ToString(bool exprFlag)
{
	String rtn;
	rtn += "<doxygen.parser:";
	rtn += ">";
	return rtn;
}

//-----------------------------------------------------------------------------
// Class implementation for doxygen.parser
//-----------------------------------------------------------------------------
Gura_ImplementUserClass(parser)
{
	Gura_AssignValue(parser, Reference());
}

Gura_EndModuleScope(doxygen)
