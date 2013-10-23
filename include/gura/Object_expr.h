#ifndef __GURA_OBJECT_EXPR_H__
#define __GURA_OBJECT_EXPR_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_expr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_expr : public Class {
public:
	Class_expr(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_expr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_expr : public Object {
public:
	Gura_DeclareObjectAccessor(expr)
private:
	AutoPtr<Expr> _pExpr;
public:
	inline Object_expr(Environment &env, Expr *pExpr) :
						Object(env.LookupClass(VTYPE_expr)), _pExpr(pExpr) {}
	inline Object_expr(Class *pClass, Expr *pExpr) :
						Object(pClass), _pExpr(pExpr) {}
	Object_expr(const Object_expr &obj);
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	inline Expr *GetExpr() { return _pExpr.get(); }
	inline const Expr *GetExpr() const { return _pExpr.get(); }
};

//-----------------------------------------------------------------------------
// Iterator_expr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Iterator_expr : public Iterator {
private:
	size_t _idx;
	AutoPtr<ExprOwner> _pExprOwner;
public:
	Iterator_expr(ExprOwner *pExprOwner);
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

}

#endif
