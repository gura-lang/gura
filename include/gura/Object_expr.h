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
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void DoAssignConstructor(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_expr
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_expr : public Object {
public:
	class Iterator_Each : public Iterator {
	private:
		Environment _env;
		AutoPtr<Expr_Container> _pExprContainer;
		ExprList::iterator _ppExpr;
	public:
		inline Iterator_Each(Environment &env, Expr_Container *pExprContainer) :
						Iterator(false), _env(env), _pExprContainer(pExprContainer),
						_ppExpr(pExprContainer->GetExprOwner().begin()) {}
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareObjectAccessor(expr)
private:
	Expr *_pExpr;
public:
	inline Object_expr(Environment &env, Expr *pExpr) :
						Object(env.LookupClass(VTYPE_expr)), _pExpr(pExpr) {}
	inline Object_expr(Class *pClass, Expr *pExpr) :
						Object(pClass), _pExpr(pExpr) {}
	Object_expr(const Object_expr &obj);
	virtual ~Object_expr();
	virtual Object *Clone() const;
	inline Expr *GetExpr() { return _pExpr; }
	inline const Expr *GetExpr() const { return _pExpr; }
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
