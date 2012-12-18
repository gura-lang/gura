//
// Object_environment
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_environment
//-----------------------------------------------------------------------------
Object_environment::Object_environment(const Object_environment &obj) :
													Object(obj), _env(obj._env)
{
}

Object_environment::~Object_environment()
{
}

Object *Object_environment::Clone() const
{
	return new Object_environment(*this);
}

bool Object_environment::DoPropDir(Signal sig, SymbolSet &symbols)
{
	if (!Object::DoPropDir(sig, symbols)) return false;
	return true;
}

Value Object_environment::DoPropGet(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	const Value *pValue = GetEnv().LookupValue(pSymbol, true);
	if (pValue == NULL) return Value::Null;
	evaluatedFlag = true;
	return *pValue;
}

Value Object_environment::DoPropSet(Signal sig, const Symbol *pSymbol,
										const Value &value, bool &evaluatedFlag)
{
	GetEnv().AssignValue(pSymbol, value, true);
	evaluatedFlag = true;
	return value;
}

String Object_environment::ToString(Signal sig, bool exprFlag)
{
	String str;
	EnvType envType = _env.GetTopFrame().GetEnvType();
	str += "<environment:";
	str += GetEnvTypeName(envType);
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_environment
//-----------------------------------------------------------------------------
// environment#getprop!(symbol:symbol):map
Gura_DeclareMethodAlias(environment, getprop_X, "getprop!")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
}

Gura_ImplementMethod(environment, getprop_X)
{
	Object_environment *pSelf = Object_environment::GetSelfObj(args);
	const Symbol *pSymbol = args.GetSymbol(0);
	const Value *pValue = pSelf->GetEnv().LookupValue(pSymbol, false);
	if (pValue == NULL) {
		sig.SetError(ERR_ValueError,
			"environment doesn't have a property named '%s'", pSymbol->GetName());
		return Value::Null;
	}
	return *pValue;
}

// environment#setprop!(symbol:symbol, value):map
Gura_DeclareMethodAlias(environment, setprop_X, "setprop!")
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "value", VTYPE_any);
}

Gura_ImplementMethod(environment, setprop_X)
{
	Object_environment *pSelf = Object_environment::GetSelfObj(args);
	pSelf->GetEnv().AssignValue(args.GetSymbol(0), args.GetValue(1), false);
	return Value::Null;
}

// environment#eval(expr:expr):map
Gura_DeclareMethod(environment, eval)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "expr", VTYPE_expr);
	SetHelp("Evaluates the expr instance in the environment and returns its result.");
}

Gura_ImplementMethod(environment, eval)
{
	Object_environment *pSelf = Object_environment::GetSelfObj(args);
	return args.GetExpr(0)->Exec(pSelf->GetEnv(), sig);
}

// environment#lookup(symbol:symbol, escalate:boolean => true):map
Gura_DeclareMethod(environment, lookup)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "escalate", VTYPE_boolean,
						OCCUR_Once, FLAG_None, new Expr_Value(Value(true)));
	SetHelp(
	"Looks up a specified symbol in the environment and returns the associated value.\n"
	"In default, if the symbol is not defined in the environment, it will be searched\n"
	"in environments outside of the current one. Set escalate flag to false\n"
	"in order to disable such an escalation behaviour.\n"
	"Returns false when the symbol could not be found.");
}

Gura_ImplementMethod(environment, lookup)
{
	Object_environment *pSelf = Object_environment::GetSelfObj(args);
	const Value *pValue = pSelf->GetEnv().LookupValue(
								args.GetSymbol(0), args.GetBoolean(1));
	if (pValue == NULL) return Value::Null;
	return *pValue;
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_environment::Class_environment(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_environment)
{
	Gura_AssignMethod(environment, getprop_X);
	Gura_AssignMethod(environment, setprop_X);
	Gura_AssignMethod(environment, eval);
	Gura_AssignMethod(environment, lookup);
}

Object *Class_environment::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_environment::OnModuleEntry(Environment &env, Signal sig)
{
}

}
