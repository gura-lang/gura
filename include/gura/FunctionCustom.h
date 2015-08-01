//=============================================================================
// FunctionCustom
//=============================================================================
#ifndef __GURA_FUNCTIONCUSTOM_H__
#define __GURA_FUNCTIONCUSTOM_H__

#include "Function.h"

namespace Gura {

//-----------------------------------------------------------------------------
// FunctionCustom
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE FunctionCustom : public Function {
public:
	class GURA_DLLDECLARE SequenceEx : public Sequence {
	protected:
		AutoPtr<FunctionCustom> _pFunctionCustom;
		AutoPtr<ExprOwner> _pExprOwner;
		size_t _idxExpr;
	public:
		SequenceEx(Environment *pEnv, FunctionCustom *pFunctionCustom);
	public:
		virtual bool DoStep(Signal &sig, Value &result);
		virtual String ToString() const;
	};
private:
	AutoPtr<Expr> _pExprBody;
public:
	FunctionCustom(Environment &envScope, const Symbol *pSymbol,
									Expr *pExprBody, FunctionType funcType);
	virtual ~FunctionCustom();
	virtual bool IsCustom() const;
	inline Expr *GetExprBody() { return _pExprBody.get(); }
	inline const Expr *GetExprBody() const { return _pExprBody.get(); }
	inline void SetExprBody(Expr *pExprBody) { _pExprBody.reset(pExprBody); }
	virtual Expr *MathDiff(Environment &env,
						const Expr *pExprArg, const Symbol *pSymbol) const;
	static FunctionCustom *CreateBlockFunc(Environment &env, Signal &sig,
		const Symbol *pSymbol, const Expr_Block *pExprBlock, FunctionType funcType);
private:
	virtual Value DoEval(Environment &env, Args &args) const;
};

}

#endif
