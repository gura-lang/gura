#ifndef __GURA_CUSTOMCLASS_H__
#define __GURA_CUSTOMCLASS_H__

#include "Common.h"
#include "Object.h"

namespace Gura {

class GURA_DLLDECLARE CustomClass : public Class {
private:
	AutoPtr<Expr_Block> _pExprContent;
	Signal _sig;
public:
	CustomClass(const CustomClass &cls);
	CustomClass(Environment *pEnv, Class *pClassSuper,
				ValueType valType, Expr_Block *pExprContent, Signal sig);
	virtual ~CustomClass();
	virtual bool IsCustom() const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	Function *PrepareConstructor(Environment &env, Signal sig);
	static void OnModuleEntry(Environment &env, Signal sig);
	inline Signal &GetSignal() { return _sig; }
	virtual bool Serialize(Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// ConstructorOfCustomClass
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ConstructorOfCustomClass : public Function {
private:
	Environment _envScope;
	AutoPtr<Expr> _pExprBody;
public:
	ConstructorOfCustomClass(Environment &envScope, const Symbol *pSymbol, Expr *pExpr,
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
