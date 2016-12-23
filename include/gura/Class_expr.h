//=============================================================================
// Gura class: expr
//=============================================================================
#ifndef __GURA_CLASS_EXPR_H__
#define __GURA_CLASS_EXPR_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_expr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_expr : public Class {
public:
	Class_expr(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
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
	virtual String ToString(bool exprFlag);
	inline Expr *GetExpr() { return _pExpr.get(); }
	inline const Expr *GetExpr() const { return _pExpr.get(); }
};

}

#endif
