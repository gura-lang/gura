//=============================================================================
// Gura class: environment
//=============================================================================
#include "stdafx.h"

namespace Gura {

static const char *helpDoc_en = R"**(
)**";

//-----------------------------------------------------------------------------
// Object_environment
//-----------------------------------------------------------------------------
Object_environment::Object_environment(const Object_environment &obj) :
	Object(obj), _pEnv(obj._pEnv->Clone())
{
}

Object_environment::~Object_environment()
{
}

Object *Object_environment::Clone() const
{
	return new Object_environment(*this);
}

bool Object_environment::DoDirProp(Environment &env, SymbolSet &symbols)
{
	if (!Object::DoDirProp(env, symbols)) return false;
	return true;
}

Value Object_environment::DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	const Value *pValue = GetEnv().LookupValue(pSymbol, ENVREF_Escalate);
	if (pValue == nullptr) return Value::Nil;
	evaluatedFlag = true;
	return *pValue;
}

Value Object_environment::DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag)
{
	GetEnv().AssignValue(pSymbol, value, EXTRA_Public);
	evaluatedFlag = true;
	return value;
}

String Object_environment::ToString(bool exprFlag)
{
	String str;
	EnvType envType = _pEnv->GetTopFrame()->GetEnvType();
	str += "<environment:";
	str += GetEnvTypeName(envType);
	str += ">";
	return str;
}

//-----------------------------------------------------------------------------
// Implementation of methods
//-----------------------------------------------------------------------------
// environment#getprop!(symbol:symbol):map
Gura_DeclareMethodAlias(environment, getprop_X, "getprop!")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(environment, getprop_X)
{
	Signal &sig = env.GetSignal();
	Object_environment *pThis = Object_environment::GetObjectThis(arg);
	const Symbol *pSymbol = arg.GetSymbol(0);
	const Value *pValue = pThis->GetEnv().LookupValue(pSymbol, ENVREF_NoEscalate);
	if (pValue == nullptr) {
		sig.SetError(ERR_ValueError,
			"environment doesn't have a property named '%s'", pSymbol->GetName());
		return Value::Nil;
	}
	return *pValue;
}

// environment#lookup(symbol:symbol, escalate:boolean => true):map
Gura_DeclareMethod(environment, lookup)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "escalate", VTYPE_boolean,
			   OCCUR_Once, FLAG_None, 0, new Expr_Value(Value(true)));
	AddHelp(
		Gura_Symbol(en), 
		"Looks up a specified symbol in the environment and returns the associated value.\n"
		"In default, if the symbol is not defined in the environment, it will be searched\n"
		"in environments outside of the current one. Set escalate flag to false\n"
		"in order to disable such an escalation behaviour.\n"
		"Returns false when the symbol could not be found.");
}

Gura_ImplementMethod(environment, lookup)
{
	Object_environment *pThis = Object_environment::GetObjectThis(arg);
	EnvRefMode envRefMode = arg.GetBoolean(1)? ENVREF_Escalate : ENVREF_NoEscalate;
	const Value *pValue = pThis->GetEnv().LookupValue(arg.GetSymbol(0), envRefMode, 0);
	if (pValue == nullptr) return Value::Nil;
	return *pValue;
}

// environment#setprop!(symbol:symbol, value):map
Gura_DeclareMethodAlias(environment, setprop_X, "setprop!")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "symbol", VTYPE_symbol);
	DeclareArg(env, "value", VTYPE_any);
	AddHelp(
		Gura_Symbol(en),
		"");
}

Gura_ImplementMethod(environment, setprop_X)
{
	Object_environment *pThis = Object_environment::GetObjectThis(arg);
	pThis->GetEnv().AssignValue(arg.GetSymbol(0), arg.GetValue(1), EXTRA_Public);
	return Value::Nil;
}

//-----------------------------------------------------------------------------
// Implementation of class
//-----------------------------------------------------------------------------
Class_environment::Class_environment(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_environment)
{
}

void Class_environment::Prepare(Environment &env)
{
	Gura_AssignValue(environment, Value(Reference()));
	Gura_AssignMethod(environment, getprop_X);
	Gura_AssignMethod(environment, lookup);
	Gura_AssignMethod(environment, setprop_X);
	// help document
	AddHelpTemplate(env, Gura_Symbol(en), helpDoc_en + 1);
}

Object *Class_environment::CreateDescendant(Environment &env, Class *pClass)
{
	GURA_ERROREND(env, "this function must not be called");
	return nullptr;
}

}
