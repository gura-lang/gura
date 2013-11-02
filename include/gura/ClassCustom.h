#ifndef __GURA_CLASSCUSTOM_H__
#define __GURA_CLASSCUSTOM_H__

#include "Common.h"
#include "Class.h"

namespace Gura {

class GURA_DLLDECLARE ClassCustom : public Class {
private:
	AutoPtr<Expr_Block> _pExprContent;
	Signal _sig;
public:
	ClassCustom(const ClassCustom &cls);
	ClassCustom(Environment *pEnv, Class *pClassSuper,
				ValueType valType, Expr_Block *pExprContent, Signal sig);
	virtual ~ClassCustom();
	virtual bool IsCustom() const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	Function *PrepareConstructor(Environment &env, Signal sig);
	inline Signal &GetSignal() { return _sig; }
	virtual bool Serialize(Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// ConstructorOfClassCustom
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ConstructorOfClassCustom : public Function {
private:
	AutoPtr<Environment> _pEnvScope;
	AutoPtr<Expr> _pExprBody;
public:
	ConstructorOfClassCustom(Environment &envScope, const Symbol *pSymbol, Expr *pExpr,
													FunctionType funcType);
	inline const Expr *GetExprBody() const { return _pExprBody.get(); }
private:
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

//-----------------------------------------------------------------------------
// ConstructorOfStruct
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ConstructorOfStruct : public Function {
public:
	ConstructorOfStruct(Environment &env);
	virtual bool IsConstructorOfStruct() const;
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

}

#endif
