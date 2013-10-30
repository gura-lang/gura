#ifndef __GURA_CUSTOMFUNCTION_H__
#define __GURA_CUSTOMFUNCTION_H__

#include "Function.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CustomFunction
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE CustomFunction : public Function {
public:
	class GURA_DLLDECLARE SequenceEx : public Sequence {
	protected:
		AutoPtr<CustomFunction> _pCustomFunction;
		AutoPtr<ExprOwner> _pExprOwner;
		size_t _idxExpr;
	public:
		SequenceEx(Environment *pEnv, CustomFunction *pCustomFunction);
	public:
		virtual bool DoStep(Signal sig, Value &result);
		virtual String ToString() const;
	};
private:
	AutoPtr<Expr> _pExprBody;
public:
	CustomFunction(Environment &envScope, const Symbol *pSymbol,
									Expr *pExprBody, FunctionType funcType);
	virtual ~CustomFunction();
	virtual bool IsCustom() const;
	inline const Expr *GetExprBody() const { return _pExprBody.get(); }
	inline void SetExprBody(Expr *pExprBody) { _pExprBody.reset(pExprBody); }
	virtual Expr *DiffUnary(Environment &env, Signal sig,
						const Expr *pExprArg, const Symbol *pSymbol) const;
	static CustomFunction *CreateBlockFunc(Environment &env, Signal sig,
		const Symbol *pSymbol, const Expr_Block *pExprBlock, FunctionType funcType);
private:
	virtual Value DoEval(Environment &env, Signal sig, Args &args) const;
};

}

#endif
