//=============================================================================
// Gura class: declaration
//=============================================================================
#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_declaration
//-----------------------------------------------------------------------------
Object *Object_declaration::Clone() const
{
	return new Object_declaration(*this);
}

bool Object_declaration::DoDirProp(Environment &env, Signal sig, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, sig, symbols)) return false;
	symbols.insert(Gura_Symbol(symbol));
	symbols.insert(Gura_Symbol(name));
	symbols.insert(Gura_Symbol(default_));
	return true;
}

Value Object_declaration::DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(symbol))) {
		return Value(_pDeclaration->GetSymbol());
	} else if (pSymbol->IsIdentical(Gura_Symbol(name))) {
		return Value(_pDeclaration->GetName());
	} else if (pSymbol->IsIdentical(Gura_Symbol(default_))) {
		const Expr *pExpr = _pDeclaration->GetExprDefault();
		if (pExpr == NULL) return Value::Null;
		return Value(new Object_expr(env, pExpr->Reference()));
	}
	evaluatedFlag = false;
	return Value::Null;
}

String Object_declaration::ToString(bool exprFlag)
{
	String str;
	str += "<declaration:";
	str += _pDeclaration->GetName();
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// declaration#istype(type+:expr)
Gura_DeclareMethod(declaration, istype)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "type", VTYPE_expr, OCCUR_OnceOrMore);
	AddHelp(
		Gura_Symbol(en), Help::FMT_markdown,
		"");
}

Gura_ImplementMethod(declaration, istype)
{
	const Declaration *pDeclaration = Object_declaration::GetThisObj(args)->GetDeclaration();
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(sig, args.GetList(0));
	if (pValueTypeInfo == NULL) return Value::Null;
	ValueType valType = pDeclaration->GetValueType();
	ValueType valTypeCmp = pValueTypeInfo->GetValueType();
	return Value(valType == valTypeCmp);
}

//----------------------------------------------------------------------------
// Implementation of class
//----------------------------------------------------------------------------
Class_declaration::Class_declaration(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_declaration)
{
}

void Class_declaration::Prepare(Environment &env)
{
	Gura_AssignMethod(declaration, istype);
}

//-----------------------------------------------------------------------------
// Iterator_declaration
//-----------------------------------------------------------------------------
Iterator_declaration::Iterator_declaration(DeclarationOwner *pDeclarationOwner) :
						Iterator(false), _idx(0), _pDeclarationOwner(pDeclarationOwner)
{
}

Iterator *Iterator_declaration::GetSource()
{
	return NULL;
}

bool Iterator_declaration::DoNext(Environment &env, Signal sig, Value &value)
{
	if (_idx < _pDeclarationOwner->size()) {
		Declaration *pDeclaration = (*_pDeclarationOwner)[_idx++];
		value = Value(new Object_declaration(env, pDeclaration->Reference()));
		return true;
	}
	return false;
}

String Iterator_declaration::ToString() const
{
	String rtn;
	rtn += "declaration";
	return rtn;
}

void Iterator_declaration::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

}
