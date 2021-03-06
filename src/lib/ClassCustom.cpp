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
	ClassFundamental(cls), _pExprContent(dynamic_cast<Expr_Block *>(
				Expr::Reference(cls._pExprContent.get())))
{
}

ClassCustom::ClassCustom(Environment *pEnv, Class *pClassSuper,
				ValueType valType, Expr_Block *pExprContent) :
	ClassFundamental(pClassSuper, valType), _pExprContent(pExprContent)
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

void ClassCustom::DoPrepare(Environment &env)
{
	Signal &sig = env.GetSignal();
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged);
	if (!_pExprContent.IsNull() && !BuildContent(env, valueThis, _pExprContent.get())) {
		return;
	}
	FunctionCustom *pFuncInit = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__init__), ENVREF_NoEscalate));
	if (GetConstructor() == nullptr) {
		// nothing to do
	} else if (pFuncInit == nullptr) {
		Function *pFunc = GetConstructor();
		if (pFunc->IsAnonymous()) pFunc->SetSymbol(_pSymbol);
		return;
	} else {
		sig.SetError(ERR_DeclarationError, "struct can't have constructor");
		return;
	}
	AutoPtr<Constructor> pFunc;
	if (pFuncInit != nullptr) {
		pFunc.reset(new Constructor(pFuncInit->GetEnvScope(), Gura_Symbol(_anonymous_),
						Expr::Reference(pFuncInit->GetExprBody()), FUNCTYPE_Function));
		pFunc->CopyDeclarationInfo(*pFuncInit);
		pFunc->GetHelpProvider().CopyHelp(pFuncInit->GetHelpProvider());
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
		pFunc->CopyDeclarationInfo(*pConstructorSuper);
		pFunc->GetHelpProvider().CopyHelp(pConstructorSuper->GetHelpProvider());
	} else {
		pFunc.reset(new Constructor(env, Gura_Symbol(_anonymous_),
												new Expr_Block(), FUNCTYPE_Function));
		if (!pFunc->CustomDeclare(env, CallerInfo::Empty, SymbolSet::Empty)) return;
	}
	pFunc->SetSymbol(_pSymbol);
	pFunc->SetClassToConstruct(this); // constructor is registered in this class
	pFunc->DeclareBlock(OCCUR_ZeroOrOnce);
}

bool ClassCustom::CastFrom(Environment &env, Value &value, ULong flags)
{
	Signal &sig = GetSignal();
#if 0
	if (value.Is_list()) {
		if (_pConstructor.IsNull()) return false;
		AutoPtr<Argument> pArg(new Argument(_pConstructor.get()));
		if (!pArg->StoreValues(env, value.GetList())) return false;
		value = _pConstructor->Eval(env, *pArg);
		return !sig.IsSignalled();
	}
#endif
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__cast__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;
	Value valueThis(this, VFLAG_NoFundOwner | VFLAG_Privileged);
	AutoPtr<Environment> pEnvLocal(Derive(ENVTYPE_local));
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(valueThis);
	if (!pArg->StoreValue(env, value)) return false;
	value = pFunc->Eval(*pEnvLocal, *pArg);
	if (sig.IsSignalled()) return false;
	return true;
}

bool ClassCustom::CastTo(Environment &env, Value &value, const Declaration &decl)
{
	Signal &sig = GetSignal();
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__castto__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;
	AutoPtr<Environment> pEnvLocal(Derive(ENVTYPE_local));
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(value);
	if (!pArg->StoreValue(env, Value(new Object_declaration(env, decl.Reference())))) return false;
	value = pFunc->Eval(*pEnvLocal, *pArg);
	if (sig.IsSignalled()) return false;
	return true;
}

Class::SerializeFmtVer ClassCustom::GetSerializeFmtVer() const
{
	return SerializeFmtVer_1;
}

bool ClassCustom::Serialize(Environment &env, Stream &stream, const Value &value) const
{
	FunctionCustom *pFunc = dynamic_cast<FunctionCustom *>(
					LookupFunction(Gura_Symbol(__serialize__), ENVREF_NoEscalate));
	if (pFunc == nullptr) return false;
	return false;
}

bool ClassCustom::Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const
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
	AutoPtr<Environment> pEnvLocal(Derive(ENVTYPE_local));
	AutoPtr<Argument> pArg(new Argument(pFunc));
	pArg->SetValueThis(value);
	if (!pArg->StoreValue(*pEnvLocal, Value(new Object_formatter(*pEnvLocal, flags)))) return false;
	Value valueRtn = pFunc->Eval(*pEnvLocal, *pArg);
	if (sig.IsSignalled()) return false;
	if (!valueRtn.MustBe_string(sig)) return false;
	return pFormatter->PutString(sig, valueRtn.GetString());
}

//-----------------------------------------------------------------------------
// ClassCustom::Constructor
//-----------------------------------------------------------------------------
ClassCustom::Constructor::Constructor(Environment &envScope,
				const Symbol *pSymbol, Expr *pExprBody, FunctionType funcType) :
	Function(envScope, pSymbol, funcType, FLAG_None), _pEnvScope(envScope.Clone()),
	_pExprBody(pExprBody)
{
}

Value ClassCustom::Constructor::DoEval(Environment &env, Argument &arg) const
{
	Signal &sig = env.GetSignal();
	AutoPtr<Environment> pEnvLocal(arg.PrepareEnvironment(env));
	if (pEnvLocal.IsNull()) return Value::Nil;
	Value valueRtn(arg.GetValueThis());
	if (!valueRtn.IsObject()) {
		Object *pObj = _pClassContainer->CreateDescendant(*pEnvLocal, _pClassContainer);
		valueRtn.InitAsObject(pObj);
	}
	Class *pClassSuper = _pClassContainer->GetClassSuper();
	Function *pConstructorSuper =
				(pClassSuper == nullptr)? nullptr : pClassSuper->GetConstructor();
	if (pConstructorSuper != nullptr) {
		const Expr *pExpr = GetExprBody();
		const ExprList *pExprListArg = &ExprList::Empty;
		if (pExpr->IsBlock()) {
			const Expr_Block *pExprBlock = dynamic_cast<const Expr_Block *>(pExpr);
			if (pExprBlock->GetExprOwnerParam() != nullptr) {
				pExprListArg = pExprBlock->GetExprOwnerParam();
			}
		}
		AutoPtr<Environment> pEnvSuper(pEnvLocal->Derive(ENVTYPE_local));
		CallerInfo callerInfo(*pExprListArg, nullptr, nullptr, nullptr);
		AutoPtr<Argument> pArg(new Argument(pConstructorSuper, callerInfo));
		pArg->SetValueThis(valueRtn);
		if (!pArg->EvalExpr(*pEnvSuper, callerInfo.GetExprListArg())) return Value::Nil;
		pConstructorSuper->EvalAuto(*pEnvSuper, *pArg);
		if (sig.IsSignalled()) return Value::Nil;
	}
	Value valueThis(valueRtn);
	valueThis.AddFlags(VFLAG_Privileged);
	pEnvLocal->AssignValue(Gura_Symbol(this_), valueThis, EXTRA_Public);
	GetExprBody()->Exec(*pEnvLocal);
	if (sig.IsSignalled()) return Value::Nil;
	return ReturnValue(env, arg, valueRtn);
}

}
