//
// Object_function
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Object_function
//-----------------------------------------------------------------------------
bool Object_function::IsFunction() const { return true; }

Object_function::~Object_function()
{
}

bool Object_function::DoDirProp(Signal sig, SymbolSet &symbols)
{
	Class *pClass = GetFunction()->GetClassToConstruct();
	if (pClass != NULL) return pClass->DoDirProp(sig, symbols);
	if (!Object::DoDirProp(sig, symbols)) return false;
	symbols.insert(Gura_Symbol(symbol));
	symbols.insert(Gura_Symbol(name));
	symbols.insert(Gura_Symbol(fullname));
	symbols.insert(Gura_Symbol(args));
	symbols.insert(Gura_Symbol(expr));
	return true;
}

Value Object_function::DoGetProp(Signal sig, const Symbol *pSymbol, bool &evaluatedFlag)
{
	Environment &env = *this;
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(symbol))) {
		return Value(GetFunction()->GetSymbol());
	} else if (pSymbol->IsIdentical(Gura_Symbol(name))) {
		return Value(env, GetName().c_str());
	} else if (pSymbol->IsIdentical(Gura_Symbol(fullname))) {
		String fullName = GetFullName(sig);
		if (sig.IsSignalled()) return Value::Null;
		return Value(env, fullName.c_str());
	} else if (pSymbol->IsIdentical(Gura_Symbol(args))) {
		Value result;
		ValueList &valList = result.InitAsList(env);
		foreach_const (DeclarationList, ppDecl, GetFunction()->GetDeclOwner()) {
			valList.push_back(Value((*ppDecl)->GetSymbol()));
		}
		return result;
	} else if (pSymbol->IsIdentical(Gura_Symbol(expr))) {
		if (!GetFunction()->IsCustom()) return Value::Null;
		const FunctionCustom *pFuncCustom =
						dynamic_cast<const FunctionCustom *>(GetFunction());
		return Value(env, pFuncCustom->GetExprBody()->IncRef());
	} else if (pSymbol->IsIdentical(Gura_Symbol(help))) {
		const Symbol *pSymbol = Gura_Symbol(en);
		const char *helpStr = GetFunction()->GetHelp(pSymbol);
		if (helpStr == NULL) return Value::Null;
		return Value(env, helpStr);
	}
	evaluatedFlag = false;
	return Value::Null;
}

Value Object_function::DoSetProp(Signal sig,
				const Symbol *pSymbol, const Value &value, bool &evaluatedFlag)
{
	evaluatedFlag = true;
	if (pSymbol->IsIdentical(Gura_Symbol(symbol)) ||
						pSymbol->IsIdentical(Gura_Symbol(name))) {
		if (value.IsSymbol()) {
			GetFunction()->SetSymbol(value.GetSymbol());
		} else if (value.IsString()) {
			GetFunction()->SetSymbol(Symbol::Add(value.GetString()));
		} else {
			sig.SetError(ERR_TypeError, "symbol or string must be specified");
			return Value::Null;
		}
		return value;
	} else if (pSymbol->IsIdentical(Gura_Symbol(expr))) {
		if (!GetFunction()->IsCustom()) {
			sig.SetError(ERR_TypeError, "not a custom function");
			return Value::Null;
		}
		if (!value.IsExpr()) {
			sig.SetError(ERR_TypeError, "expr must be specified");
			return Value::Null;
		}
		FunctionCustom *pFuncCustom = dynamic_cast<FunctionCustom *>(GetFunction());
		pFuncCustom->SetExprBody(Expr::Reference(value.GetExpr()));
		return value;
	}
	return DoGetProp(sig, pSymbol, evaluatedFlag);
}

Value Object_function::DoCall(Environment &env, Signal sig, Args &args)
{
	if (args.GetThis().IsInvalid() ||
					(args.GetThis().IsModule() && _valueThis.IsValid())) {
		args.SetThis(_valueThis);
	}
	return _pFunc->EvalExpr(env, sig, args);
}

Value Object_function::Eval(Environment &env, Signal sig, ValueList &valListArg) const
{
	_pFunc->GetDeclOwner().Compensate(env, sig, valListArg);
	if (sig.IsSignalled()) return Value::Null;
	Args args(valListArg, _valueThis);
	return _pFunc->Eval(env, sig, args);
}

Object *Object_function::Clone() const
{
	return new Object_function(*this);
}

String Object_function::GetFullName(Signal sig)
{
	String str = MakePrefix(sig);
	if (sig.IsSignalled()) return String("");
	str += _pFunc->GetName();
	return str;
}

String Object_function::ToString(Signal sig, bool exprFlag)
{
	String str = MakePrefix(sig);
	if (sig.IsSignalled()) return String("");
	str += _pFunc->ToString();
	return str;
}

void Object_function::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
	if (_cntRef == 1) {
		_pFunc->GatherFollower(pFrame, envSet);
	}
}

String Object_function::MakePrefix(Signal sig) const
{
	String str;
	if (_valueThis.IsInvalid()) return str;
	if (_valueThis.IsPrimitive() || _valueThis.GetTinyBuffFlag()) {
		const Environment &env = *this;
		const Class *pClass = env.LookupClass(_valueThis.GetType());
		if (pClass != NULL) {
			str += pClass->GetName();
			str += "#";
			return str;
		}
	}
	const ObjectBase *pObj = _valueThis.ExtractObject(sig);
	if (sig.IsSignalled()) return str;
	if (pObj->IsModule()) {
		str += dynamic_cast<const Module *>(pObj)->GetName();
		str += ".";
	} else if (pObj->IsClass()) {
		str += dynamic_cast<const Class *>(pObj)->GetName();
		str += (_pFunc->GetType() == FUNCTYPE_Instance)? "#" : ".";
	} else if (pObj->IsObject()) {
		str += dynamic_cast<const Object *>(pObj)->GetClass()->GetName();
		str += "#";
	}
	return str;
}

//-----------------------------------------------------------------------------
// Global functions
//-----------------------------------------------------------------------------
// func = function(`args*) {block}
Gura_DeclareFunction(function)
{
	DeclareArg(env, "args", VTYPE_quote, OCCUR_ZeroOrMore);
	DeclareBlock(OCCUR_Once);
}

Gura_ImplementFunction(function)
{
	const Expr_Block *pExprBlock = args.GetBlock(env, sig);
	if (sig.IsSignalled()) return Value::Null;
	const Expr_BlockParam *pExprBlockParam = pExprBlock->GetParam();
	ExprList exprListArg;
	const ExprList *pExprListArg = &exprListArg;
	if (pExprBlockParam == NULL) {
		foreach_const (ValueList, pValue, args.GetList(0)) {
			exprListArg.push_back(const_cast<Expr *>(pValue->GetExpr()));
		}
		if (exprListArg.empty()) {
			pExprBlock->GatherSimpleLambdaArgs(exprListArg);
		}
	} else if (!args.GetList(0).empty()) {
		sig.SetError(ERR_SyntaxError, "argument list conflicts with block parameter.");
		return Value::Null;
	} else {
		pExprListArg = &pExprBlockParam->GetExprList();
	}
	AutoPtr<FunctionCustom> pFunc(new FunctionCustom(env,
			Gura_Symbol(_anonymous_), pExprBlock->IncRef(), FUNCTYPE_Function));
	Args argsSub(*pExprListArg, Value::Null, NULL, false, NULL, args.GetAttrs());
	if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, argsSub)) return Value::Null;
	return Value(env, pFunc.release(), Value::Null);
}

//-----------------------------------------------------------------------------
// Gura interfaces for Object_function
//-----------------------------------------------------------------------------
// function#addhelp(lang:symbol, help:string):map
Gura_DeclareMethod(function, addhelp)
{
	SetMode(RSLTMODE_Void, FLAG_Map);
	DeclareArg(env, "lang", VTYPE_symbol);
	DeclareArg(env, "help", VTYPE_string);
}

Gura_ImplementMethod(function, addhelp)
{
	Object_function *pThis = Object_function::GetThisObj(args);
	pThis->GetFunction()->AddHelp(args.GetSymbol(0), args.GetString(1));
	return Value::Null;
}

// function#gethelp(lang?:symbol):map
Gura_DeclareMethod(function, gethelp)
{
	SetMode(RSLTMODE_Normal, FLAG_Map);
	DeclareArg(env, "lang", VTYPE_symbol, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(function, gethelp)
{
	Object_function *pThis = Object_function::GetThisObj(args);
	const Symbol *pSymbol = args.IsSymbol(0)? args.GetSymbol(0) : Gura_Symbol(en);
	const char *helpStr = pThis->GetFunction()->GetHelp(pSymbol);
	if (helpStr == NULL) return Value::Null;
	return Value(env, helpStr);
}

// function#diff(var?:symbol)
Gura_DeclareMethod(function, diff)
{
	SetMode(RSLTMODE_Reduce, FLAG_None);
	DeclareArg(env, "var", VTYPE_symbol, OCCUR_ZeroOrOnce);
}

Gura_ImplementMethod(function, diff)
{
	Object_function *pThis = Object_function::GetThisObj(args);
	const Function *pFunc = pThis->GetFunction();
	const DeclarationOwner &declOwner = pFunc->GetDeclOwner();
	const Symbol *pSymbol = NULL;
	if (args.IsSymbol(0)) {
		pSymbol = args.GetSymbol(0);
	} else if (declOwner.empty()) {
		sig.SetError(ERR_ValueError, "variable symbol must be specified");
		return Value::Null;
	} else {
		pSymbol = declOwner.front()->GetSymbol();
	}
	AutoPtr<Expr> pExprDiff;
	if (pFunc->IsCustom()) {
		const FunctionCustom *pFuncCustom = dynamic_cast<const FunctionCustom *>(pFunc);
		pExprDiff.reset(pFuncCustom->GetExprBody()->MathDiff(env, sig, pSymbol));
		if (sig.IsSignalled()) return Value::Null;
	} else {
		AutoPtr<Expr> pExprArg(new Expr_Symbol(pSymbol));
		pExprDiff.reset(pFunc->DiffUnary(env, sig, pExprArg.get(), pSymbol));
		if (sig.IsSignalled()) return Value::Null;
	}
	AutoPtr<FunctionCustom> pFuncDiff(new FunctionCustom(env,
			Gura_Symbol(_anonymous_), pExprDiff.release(), FUNCTYPE_Function));
	pFuncDiff->CopyDeclare(*pFunc);
	return Value(env, pFuncDiff.release(), Value::Null);
}

//-----------------------------------------------------------------------------
// Classs implementation
//-----------------------------------------------------------------------------
Class_function::Class_function(Environment *pEnvOuter) : Class(pEnvOuter, VTYPE_function)
{
	// don't assign functions here, because the function objects themselves
	// shall be constructed here!!!!!!! instead, they must be assigned in
	// Prepare() funtion below.
}

void Class_function::Prepare()
{
	Gura_AssignMethod(function, addhelp);
	Gura_AssignMethod(function, gethelp);
	Gura_AssignMethod(function, diff);
}

bool Class_function::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	if (value.IsExpr()) {
		Function *pFunc = value.GetExpr()->
				ToFunction(env, sig, ValueList::Null, SymbolSet::Null);
		if (sig.IsSignalled()) return false;
		value = Value(env, pFunc, Value::Null);
		return true;
	}
	return false;
}

bool Class_function::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	return false;
}

bool Class_function::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	return false;
}

Object *Class_function::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	ERROREND(env, "this function must not be called");
	return NULL;
}

void Class_function::OnModuleEntry(Environment &env, Signal sig)
{
	Gura_AssignFunction(function);
	Gura_AssignFunctionEx(function, "&");
}

}
