//
// ClassCustom
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ClassCustom implementation
//-----------------------------------------------------------------------------
bool ClassCustom::IsCustom() const { return true; }

ClassCustom::ClassCustom(const ClassCustom &cls) :
	Class(cls), _pExprContent(dynamic_cast<Expr_Block *>(
				Expr::Reference(cls._pExprContent.get())))
{
}

ClassCustom::ClassCustom(Environment *pEnv, Class *pClassSuper,
				ValueType valType, Expr_Block *pExprContent) :
	Class(pClassSuper, valType), _pExprContent(pExprContent)
{
	AddLackingFrame(pEnv->GetFrameOwner());
}

ClassCustom::~ClassCustom()
{
}

Object *ClassCustom::CreateDescendant(Environment &env, Class *pClass)
{
	Signal &sig = GetSignal();
	Object *pObj = _pClassSuper->CreateDescendant(env, pClass);
	if (pObj == nullptr) {
		sig.SetError(ERR_ValueError,
					"not an inheritable class %s", _pClassSuper->GetName());
		return nullptr;
	}
	return pObj;
}

Function *ClassCustom::PrepareConstructor(Environment &env)
{
	Signal &sig = env.GetSignal();
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged);
	if (!_pExprContent.IsNull() &&
					!BuildContent(env, valueThis, _pExprContent.get())) {
		return nullptr;
	}
	FunctionCustom *pFuncInit = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__init__), ENVREF_NoEscalate));
	if (GetConstructor() == nullptr) {
		// nothing to do
	} else if (pFuncInit == nullptr) {
		Function *pFunc = GetConstructor();
		if (pFunc->IsAnonymous()) pFunc->SetSymbol(_pSymbol);
		return pFunc;
	} else {
		sig.SetError(ERR_DeclarationError, "struct can't have constructor");
		return nullptr;
	}
	AutoPtr<Constructor> pFunc;
	if (pFuncInit != nullptr) {
		pFunc.reset(new Constructor(pFuncInit->GetEnvScope(), Gura_Symbol(_anonymous_),
						Expr::Reference(pFuncInit->GetExprBody()), FUNCTYPE_Function));
		pFunc->CopyDeclare(*pFuncInit);
	} else if (!_pClassSuper.IsNull() && _pClassSuper->GetConstructor() != nullptr) {
		Function *pConstructorSuper = _pClassSuper->GetConstructor();
		Expr_Block *pExprBlock = new Expr_Block();
		ExprOwner *pExprOwnerParam = new ExprOwner();
		foreach_const (DeclarationOwner, ppDecl, pConstructorSuper->GetDeclOwner()) {
			Expr *pExpr = new Expr_Identifier((*ppDecl)->GetSymbol());
			pExprOwnerParam->push_back(pExpr);
			pExpr->SetParent(pExprBlock);
		}
		pExprBlock->SetExprOwnerParam(pExprOwnerParam);
		pFunc.reset(new Constructor(env, Gura_Symbol(_anonymous_),
												pExprBlock, FUNCTYPE_Function));
		pFunc->CopyDeclare(*pConstructorSuper);
	} else {
		pFunc.reset(new Constructor(env, Gura_Symbol(_anonymous_),
												new Expr_Block(), FUNCTYPE_Function));
		AutoPtr<Args> pArgsSub(new Args());
		if (!pFunc->CustomDeclare(env, SymbolSet::Null, *pArgsSub)) return nullptr;
	}
	pFunc->SetSymbol(_pSymbol);
	pFunc->SetClassToConstruct(this); // constructor is registered in this class
	pFunc->DeclareBlock(OCCUR_ZeroOrOnce);
	return pFunc.release();
}

bool ClassCustom::CastFrom(Environment &env, Value &value, const Declaration *pDecl)
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__cast__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged);
	AutoPtr<Environment> pEnvLocal(new Environment(this, ENVTYPE_local));
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(valueThis);
	pArgs->SetValue(value);
	value = pFunc->Eval(*pEnvLocal, *pArgs);
	if (sig.IsSignalled()) return false;
	return true;
}

bool ClassCustom::CastTo(Environment &env, Value &value, const Declaration &decl)
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__castto__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;
	AutoPtr<Environment> pEnvLocal(new Environment(this, ENVTYPE_local));
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(value);
	pArgs->SetValue(Value(new Object_declaration(env, decl.Reference())));
	value = pFunc->Eval(*pEnvLocal, *pArgs);
	if (sig.IsSignalled()) return false;
	return true;
}

bool ClassCustom::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__serialize__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;

	return false;
}

bool ClassCustom::Deserialize(Environment &env, Stream &stream, Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__deserialize__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;

	return false;
}

bool ClassCustom::Format_d(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_d__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_d(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_u(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_u__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_u(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_b(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_b__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_b(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_o(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_o__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_o(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_x(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_x__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_x(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_e(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_e__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_e(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_f(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_f__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_f(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_g(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_g__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_g(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_s(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_s__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_s(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_c(Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_c__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_c(pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_X(Signal &sig, Formatter *pFormatter,
	Formatter::Flags &flags, const Value &value, const FunctionCustom *pFunc) const
{
	AutoPtr<Environment> pEnvLocal(new Environment(this, ENVTYPE_local));
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(value);
	pArgs->SetValue(Value(new Object_formatter(*pEnvLocal, flags)));
	Value valueRtn = pFunc->Eval(*pEnvLocal, *pArgs);
	if (sig.IsSignalled()) return false;
	if (!valueRtn.MustBe_string(sig)) return false;
	return pFormatter->PutString(sig, valueRtn.GetString());
}

//-----------------------------------------------------------------------------
// ClassCustom::Constructor
//-----------------------------------------------------------------------------
ClassCustom::Constructor::Constructor(Environment &envScope,
				const Symbol *pSymbol, Expr *pExprBody, FunctionType funcType) :
		Function(envScope, pSymbol, funcType, FLAG_None), _pEnvScope(new Environment(envScope)),
		_pExprBody(pExprBody)
{
}

Value ClassCustom::Constructor::DoEval(Environment &env, Args &args) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Environment> pEnvLocal(PrepareEnvironment(env, args, false));
	if (pEnvLocal.IsNull()) return Value::Null;
	Value valueRtn(args.GetThis());
	if (!valueRtn.IsObject()) {
		Object *pObj = _pClassToConstruct->CreateDescendant(*pEnvLocal, _pClassToConstruct);
		valueRtn.InitAsObject(pObj);
	}
	Class *pClassSuper = _pClassToConstruct->GetClassSuper();
	Function *pConstructorSuper =
				(pClassSuper == nullptr)? nullptr : pClassSuper->GetConstructor();
	if (pConstructorSuper != nullptr) {
		const Expr *pExpr = GetExprBody();
		ExprOwner *pExprOwner = nullptr;
		if (pExpr->IsBlock()) {
			const Expr_Block *pExprBlock = dynamic_cast<const Expr_Block *>(pExpr);
			pExprOwner = ExprOwner::Reference(pExprBlock->GetExprOwnerParam());
		}
		AutoPtr<Environment> pEnvSuper(new Environment(pEnvLocal.get(), ENVTYPE_local));
		AutoPtr<Args> pArgsSub(new Args());
		pArgsSub->SetExprOwnerArg(pExprOwner);
		pArgsSub->SetThis(valueRtn);
		pConstructorSuper->Call(*pEnvSuper, *pArgsSub);
		if (sig.IsSignalled()) return Value::Null;
	}
	SeqPostHandler *pSeqPostHandler = nullptr;
	Value valueThis(valueRtn);
	valueThis.AddFlags(VFLAG_Privileged);
	pEnvLocal->AssignValue(Gura_Symbol(this_), valueThis, EXTRA_Public);
	GetExprBody()->Exec2(*pEnvLocal, pSeqPostHandler);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, args, valueRtn);
}


}
