//=============================================================================
// Gura class: declaration
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_declaration
//-----------------------------------------------------------------------------
Object *Object_declaration::Clone() const
{
	return new Object_declaration(*this);
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
// Implementation of properties
//-----------------------------------------------------------------------------
// declaration#symbol
Gura_DeclareProperty_R(declaration, symbol)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"A `symbol` instance that represents the declaration's name.");
}

Gura_ImplementPropertyGetter(declaration, symbol)
{
	const Declaration *pDeclaration = Object_declaration::GetObject(valueThis)->GetDeclaration();
	return Value(pDeclaration->GetSymbol());
}

// declaration#name
Gura_DeclareProperty_R(declaration, name)
{
	SetPropAttr(VTYPE_number);
	AddHelp(
		Gura_Symbol(en),
		"A `string` instance that represents the declaration's name.");
}

Gura_ImplementPropertyGetter(declaration, name)
{
	const Declaration *pDeclaration = Object_declaration::GetObject(valueThis)->GetDeclaration();
	return Value(pDeclaration->GetName());
}

// declaration#default
Gura_DeclarePropertyAlias_R(declaration, default_, "default")
{
	SetPropAttr(VTYPE_number, FLAG_Nil);
	AddHelp(
		Gura_Symbol(en),
		"An `expr` instance that represents a default value in the declaration if exists.\n"
		"This is `nil` when no default value is specified.\n");
}

Gura_ImplementPropertyGetter(declaration, default_)
{
	const Declaration *pDeclaration = Object_declaration::GetObject(valueThis)->GetDeclaration();
	const Expr *pExpr = pDeclaration->GetExprDefault();
	if (pExpr == nullptr) return Value::Nil;
	return Value(new Object_expr(env, pExpr->Reference()));
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
		Gura_Symbol(en),
		"Return `true` if the declaration is defined as a type that is specified in the arguments.\n"
		"\n"
		"The argument `type` has following formats:\n"
		"\n"
		"- a single symbol.\n"
		"- a sequence of symbols joined by a dot.\n"
		"\n"
		"In the second format, a symbol on the left side indicates a container\n"
		"such as a module and a class.\n"
		"\n"
		"Below is an example to check if the declaration is defined as `number` type.\n"
		"\n"
		"    decl.istype(`number)\n"
		"\n"
		"Below is an example to check if the declaration is defined as `re.match` type,\n"
		"which is a type named `match` defined in `re` module.\n"
		"\n"
		"    decl.istype(`re.match)\n"
		"\n"
		"You can also specify a type by describing factors in separate arguments like below:\n"
		"\n"
		"    decl.istype(`re, `match)\n");
}

Gura_ImplementMethod(declaration, istype)
{
	const Declaration *pDeclaration = Object_declaration::GetObjectThis(arg)->GetDeclaration();
	const ValueTypeInfo *pValueTypeInfo = env.LookupValueType(arg.GetList(0));
	if (pValueTypeInfo == nullptr) return Value::Nil;
	ValueType valType = pDeclaration->GetValueType();
	ValueType valTypeCmp = pValueTypeInfo->GetValueType();
	return Value(valType == valTypeCmp);
}

//----------------------------------------------------------------------------
// Implementation of class
//----------------------------------------------------------------------------
Class_declaration::Class_declaration(Environment *pEnvOuter) : ClassFundamental(pEnvOuter, VTYPE_declaration)
{
}

void Class_declaration::DoPrepare(Environment &env)
{
	// Assignment of properties
	Gura_AssignProperty(declaration, symbol);
	Gura_AssignProperty(declaration, name);
	Gura_AssignProperty(declaration, default_);
	// Assignment of method
	Gura_AssignMethod(declaration, istype);
	// Assignment of value
	Gura_AssignValue(declaration, Value(Reference()));
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en);
}

//-----------------------------------------------------------------------------
// Iterator_declaration
//-----------------------------------------------------------------------------
Iterator_declaration::Iterator_declaration(DeclarationOwner *pDeclarationOwner) :
						Iterator(Finite), _idx(0), _pDeclarationOwner(pDeclarationOwner)
{
}

Iterator *Iterator_declaration::GetSource()
{
	return nullptr;
}

bool Iterator_declaration::DoNext(Environment &env, Value &value)
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
