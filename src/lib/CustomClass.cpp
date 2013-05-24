//
// CustomClass
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CustomClass implementation
//-----------------------------------------------------------------------------
bool CustomClass::IsCustom() const { return true; }

CustomClass::CustomClass(const CustomClass &cls) :
	Class(cls), _pExprContent(dynamic_cast<Expr_Block *>(
				Expr::Reference(cls._pExprContent.get()))), _sig(cls._sig)
{
}

CustomClass::CustomClass(Environment *pEnv, Class *pClassSuper,
				ValueType valType, Expr_Block *pExprContent, Signal sig) :
	Class(pClassSuper, valType), _pExprContent(pExprContent), _sig(sig)
{
	AddLackingFrame(pEnv->GetFrameOwner());
}

CustomClass::~CustomClass()
{
}

Object *CustomClass::CreateDescendant(Environment &env, Signal sig, Class *pClass)
{
	Object *pObj = _pClassSuper->CreateDescendant(env, sig, pClass);
	if (pObj == NULL) {
		sig.SetError(ERR_ValueError,
					"not an inheritable class %s", _pClassSuper->GetName());
		return NULL;
	}
	return pObj;
}

Function *CustomClass::PrepareConstructor(Environment &env, Signal sig)
{
	Value valueThis(this, VFLAG_NoOwner | VFLAG_Privileged);
	if (!_pExprContent.IsNull() &&
					!BuildContent(env, sig, valueThis, _pExprContent.get())) {
		return NULL;
	}
	CustomFunction *pFuncInit = dynamic_cast<CustomFunction *>(
					LookupFunction(Gura_Symbol(__init__), ENVREF_NoEscalate));
	if (GetConstructor() == NULL) {
		// nothing to do
	} else if (pFuncInit == NULL) {
		return GetConstructor();
	} else {
		sig.SetError(ERR_DeclarationError, "struct can't have constructor");
		return NULL;
	}
	AutoPtr<ConstructorOfCustomClass> pFunc;
	if (pFuncInit != NULL) {
		pFunc.reset(new ConstructorOfCustomClass(env, Gura_Symbol(_anonymous_),
						Expr::Reference(pFuncInit->GetExprBody()), FUNCTYPE_Function));
		pFunc->CopyDeclare(*pFuncInit);
	} else if (!_pClassSuper.IsNull() && _pClassSuper->GetConstructor() != NULL) {
		Function *pConstructorSuper = _pClassSuper->GetConstructor();
		Expr_Block *pExprBlock = new Expr_Block();
		Expr_BlockParam *pExprBlockParam = new Expr_BlockParam();
		foreach_const (DeclarationOwner, ppDecl, pConstructorSuper->GetDeclOwner()) {
			pExprBlockParam->AddExpr(new Expr_Symbol((*ppDecl)->GetSymbol()));
		}
		pExprBlock->SetParam(pExprBlockParam);
		pFunc.reset(new ConstructorOfCustomClass(env, Gura_Symbol(_anonymous_),
												pExprBlock, FUNCTYPE_Function));
		pFunc->CopyDeclare(*pConstructorSuper);
	} else {
		pFunc.reset(new ConstructorOfCustomClass(env, Gura_Symbol(_anonymous_),
												new Expr_Block(), FUNCTYPE_Function));
		Args argsSub(ExprList::Null);
		if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, argsSub)) return NULL;
	}
	pFunc->SetSymbol(_pSymbol);
	pFunc->SetClassToConstruct(this); // constructor is registered in this class
	pFunc->DeclareBlock(OCCUR_ZeroOrOnce);
	return pFunc.release();
}

bool CustomClass::Serialize(Signal sig, Stream &stream, const Value &value) const
{
	return false;
}

bool CustomClass::Deserialize(Signal sig, Stream &stream, Value &value) const
{
	return false;
}

//-----------------------------------------------------------------------------
// ConstructorOfCustomClass
//-----------------------------------------------------------------------------
ConstructorOfCustomClass::ConstructorOfCustomClass(Environment &envScope,
				const Symbol *pSymbol, Expr *pExprBody, FunctionType funcType) :
		Function(envScope, pSymbol, funcType, FLAG_None), _envScope(envScope),
		_pExprBody(pExprBody)
{
}

Value ConstructorOfCustomClass::DoEval(Environment &env, Signal sig, Args &args) const
{
	std::auto_ptr<Environment> pEnvLocal(PrepareEnvironment(env, sig, args));
	if (pEnvLocal.get() == NULL) return Value::Null;
	EnvType envType = pEnvLocal->GetEnvType();
	Value valueRtn(args.GetThis());
	if (!valueRtn.IsObject()) {
		Object *pObj = _pClassToConstruct->CreateDescendant(*pEnvLocal, sig, _pClassToConstruct);
		valueRtn.InitAsObject(pObj);
	}
	Class *pClassSuper = _pClassToConstruct->GetClassSuper();
	Function *pConstructorSuper =
				(pClassSuper == NULL)? NULL : pClassSuper->GetConstructor();
	if (pConstructorSuper != NULL) {
		const Expr *pExpr = GetExprBody();
		const ExprList *pExprList = &ExprList::Null;
		if (pExpr->IsBlock()) {
			const Expr_Block *pExprBlock = dynamic_cast<const Expr_Block *>(pExpr);
			const Expr_BlockParam *pExprParam = pExprBlock->GetParam();
			if (pExprParam != NULL) {
				pExprList = &pExprParam->GetExprOwner();
			}
		}
		Environment envSuper(pEnvLocal.get(), ENVTYPE_local);
		Args argsSub(*pExprList, valueRtn);
		pConstructorSuper->EvalExpr(envSuper, sig, argsSub);
		if (sig.IsSignalled()) return Value::Null;
	}
	Value valueThis(valueRtn);
	valueThis.AddFlags(VFLAG_Privileged);
	pEnvLocal->AssignValue(Gura_Symbol(this), valueThis, EXTRA_Public);
	GetExprBody()->Exec(*pEnvLocal, sig);
	if (sig.IsSignalled()) return Value::Null;
	return ReturnValue(env, sig, args, valueRtn);
}

//-----------------------------------------------------------------------------
// ConstructorOfStruct
//-----------------------------------------------------------------------------
bool ConstructorOfStruct::IsConstructorOfStruct() const { return true; }

ConstructorOfStruct::ConstructorOfStruct(Environment &env) :
		Function(env, Gura_Symbol(_anonymous_), FUNCTYPE_Function, FLAG_None)
{
}

Value ConstructorOfStruct::DoEval(Environment &env, Signal sig, Args &args) const
{
	Object *pObjThis = NULL;
	Value valueRtn(args.GetThis());
	if (valueRtn.IsObject()) {
		pObjThis = valueRtn.GetObject();
	} else {
		pObjThis = _pClassToConstruct->CreateDescendant(env, sig, _pClassToConstruct);
		valueRtn.InitAsObject(pObjThis);
	}
	ValueList::const_iterator pValue = args.GetArgs().begin();
	DeclarationList::const_iterator ppDecl = GetDeclOwner().begin();
	for ( ; pValue != args.GetArgs().end() && ppDecl != GetDeclOwner().end();
														pValue++, ppDecl++) {
		const Declaration *pDecl = *ppDecl;
		pObjThis->AssignValue(pDecl->GetSymbol(), *pValue, EXTRA_Public);
	}
	return ReturnValue(env, sig, args, valueRtn);
}

}
