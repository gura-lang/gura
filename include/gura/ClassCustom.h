//=============================================================================
// ClassCustom
//=============================================================================
#ifndef __GURA_CLASSCUSTOM_H__
#define __GURA_CLASSCUSTOM_H__

#include "Common.h"
#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ClassCustom
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ClassCustom : public Class {
public:
	class GURA_DLLDECLARE Constructor : public Function {
	private:
		AutoPtr<Environment> _pEnvScope;
		AutoPtr<Expr> _pExprBody;
	public:
		Constructor(Environment &envScope, const Symbol *pSymbol, Expr *pExpr,
														FunctionType funcType);
		inline const Expr *GetExprBody() const { return _pExprBody.get(); }
	private:
		virtual Value DoEval(Environment &env, Signal &sig, Args &args) const;
	};
private:
	AutoPtr<Expr_Block> _pExprContent;
public:
	ClassCustom(const ClassCustom &cls);
	ClassCustom(Environment *pEnv, Class *pClassSuper,
				ValueType valType, Expr_Block *pExprContent);
	virtual ~ClassCustom();
	virtual bool IsCustom() const;
	virtual Object *CreateDescendant(Environment &env, Signal &sig, Class *pClass);
	Function *PrepareConstructor(Environment &env, Signal &sig);
	virtual bool CastFrom(Environment &env, Signal &sig, Value &value, const Declaration *pDecl);
	virtual bool CastTo(Environment &env, Signal &sig, Value &value, const Declaration &decl);
	virtual bool Serialize(Environment &env, Signal &sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal &sig, Stream &stream, Value &value) const;
	virtual bool Format_d(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_e(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_s(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_c(Signal &sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	bool Format_X(Signal &sig, Formatter *pFormatter,
			Formatter::Flags &flags, const Value &value, const FunctionCustom *pFunc) const;
};

}

#endif
