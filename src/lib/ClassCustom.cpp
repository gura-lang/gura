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
				Expr::Reference(cls._pExprContent.get()))), _sig(cls._sig)
{
}

ClassCustom::ClassCustom(Environment *pEnv, Class *pClassSuper,
				ValueType valType, Expr_Block *pExprContent, Signal sig) :
	Class(pClassSuper, valType), _pExprContent(pExprContent), _sig(sig)
{
	AddLackingFrame(pEnv->GetFrameOwner());
}

ClassCustom::~ClassCustom()
{
}

Object *ClassCustom::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	Object *pObj = _pClassSuper->CreateDescendant(env, sig, pClass);
	if (pObj == nullptr) {
		sig.SetError(ERR_ValueError,
					"not an inheritable class %s", _pClassSuper->GetName());
		return nullptr;
	}
	return pObj;
}

Function *ClassCustom::PrepareConstructor(Environment &env, Signal sig)
{
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged);
	if (!_pExprContent.IsNull() &&
					!BuildContent(env, sig, valueThis, _pExprContent.get())) {
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
		if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, *pArgsSub)) return nullptr;
	}
	pFunc->SetSymbol(_pSymbol);
	pFunc->SetClassToConstruct(this); // constructor is registered in this class
	pFunc->DeclareBlock(OCCUR_ZeroOrOnce);
	return pFunc.release();
}

bool ClassCustom::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__cast__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged);
	AutoPtr<Environment> pEnvLocal(new Environment(this, ENVTYPE_local));
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(valueThis);
	pArgs->SetValue(value);
	value = pFunc->Eval(*pEnvLocal, sig, *pArgs);
	if (sig.IsSignalled()) return false;
	return true;
}

bool ClassCustom::CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl)
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__castto__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;
	AutoPtr<Environment> pEnvLocal(new Environment(this, ENVTYPE_local));
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(value);
	pArgs->SetValue(Value(new Object_declaration(env, decl.Reference())));
	value = pFunc->Eval(*pEnvLocal, sig, *pArgs);
	if (sig.IsSignalled()) return false;
	return true;
}

bool ClassCustom::Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__serialize__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;

	return false;
}

bool ClassCustom::Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__deserialize__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;

	return false;
}

bool ClassCustom::Format_d(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_d__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_d(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_u(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_u__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_u(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_b(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_b__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_b(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_o(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_o__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_o(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_x(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_x__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_x(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_e(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_e__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_e(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_f(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_f__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_f(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_g(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_g__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_g(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_s(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_s__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_s(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_c(Signal sig, Formatter *pFormatter,
					Formatter::Flags &flags, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__format_c__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return Class::Format_c(sig, pFormatter, flags, value);
	return Format_X(sig, pFormatter, flags, value, pFunc);
}

bool ClassCustom::Format_X(Signal sig, Formatter *pFormatter,
	Formatter::Flags &flags, const Value &value, const FunctionCustom *pFunc) const
{
	AutoPtr<Environment> pEnvLocal(new Environment(this, ENVTYPE_local));
	AutoPtr<Args> pArgs(new Args());
	pArgs->SetThis(value);
	pArgs->SetValue(Value(new Object_formatter(*pEnvLocal, flags)));
	Value valueRtn = pFunc->Eval(*pEnvLocal, sig, *pArgs);
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

Value ClassCustom::Constructor::DoEval(Environment &env, Signal sig, Args &args) const
{
	AutoPtr<Environment> pEnvLocal(PrepareEnvironment(env, sig, args, false));
	if (pEnvLocal.IsNull()) return Value::Null;
	Value valueRtn(args.GetThis());
	if (!valueRtn.IsObject()) {
		Object *pObj = _pClassToConstruct->CreateDescendant(*pEnvLocal, sig, _pClassToConstruct);
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
		pConstructorSuper->Call(*pEnvSuper, sig, *pArgsSub);
		if (sig.IsSignalled()) return Value::Null;
	}
	SeqPostHandler *pSeqPostHandler = nullptr;
	Value valueThis(valueRtn);
	valueThis.AddFlags(VFLAG_Privileged);
	pEnvLocal->AssignValue(Gura_Symbol(this_), valueThis, EXTRA_Public);
	GetExprBody()->Exec2(*pEnvLocal, sig, pSeqPostHandler);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, valueRtn);
}


}
