//
// CustomObject
//

#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CustomClasss implementation
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
	AddLackingFrame(pEnv);
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

Function *CustomClass::Prepare(Environment &env, Signal sig)
{
	Value valueSelf(this, Value::FLAG_NoOwner);
	if (!_pExprContent.IsNull() &&
					!BuildContent(env, sig, valueSelf, _pExprContent.get())) {
		return NULL;
	}
	AutoPtr<ClassPrototype> pFunc;
	FunctionType funcType = FUNCTYPE_Function;
	//FunctionType funcType = args.IsSet(Gura_Symbol(static_))?
	//										FUNCTYPE_Class : FUNCTYPE_Function;
	FunctionCustom *pFuncInit = dynamic_cast<FunctionCustom *>(
								LookupFunction(Gura_Symbol(__init__), false));
	if (pFuncInit != NULL) {
		pFunc.reset(new ClassPrototype(env, Gura_Symbol(_anonymous_),
								pFuncInit->GetExprBody()->IncRef(), funcType));
		pFunc->CopyDeclare(*pFuncInit);
	} else if (!_pClassSuper.IsNull() && _pClassSuper->GetConstructor() != NULL) {
		Function *pConstructorSuper = _pClassSuper->GetConstructor();
		Expr_Block *pExprBlock = new Expr_Block();
		Expr_BlockParam *pExprBlockParam = new Expr_BlockParam();
		foreach_const (DeclarationOwner, ppDecl, pConstructorSuper->GetDeclOwner()) {
			pExprBlockParam->AddExpr(new Expr_Symbol((*ppDecl)->GetSymbol()));
		}
		pExprBlock->SetParam(pExprBlockParam);
		pFunc.reset(new ClassPrototype(env, Gura_Symbol(_anonymous_),
												pExprBlock, funcType));
		pFunc->CopyDeclare(*pConstructorSuper);
	} else {
		pFunc.reset(new ClassPrototype(env, Gura_Symbol(_anonymous_),
												new Expr_Block(), funcType));
		Args argsSub(ExprList::Null);
		if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, argsSub)) return NULL;
	}
	pFunc->SetSymbol(_pSymbol);
	pFunc->SetClassToConstruct(this);
	pFunc->DeclareBlock(OCCUR_ZeroOrOnce);
	return pFunc.release();
}

void CustomClass::OnModuleEntry(Environment &env, Signal sig)
{
}

bool CustomClass::Serialize(Signal sig, Stream &stream, const Value &value) const
{
	return false;
}

bool CustomClass::Deserialize(Signal sig, Stream &stream, Value &value) const
{
	return false;
}

}
