#include "stdafx.h"

namespace Gura {

//-----------------------------------------------------------------------------
// CustomFunction
//-----------------------------------------------------------------------------
bool CustomFunction::IsCustom() const { return true; }

CustomFunction::CustomFunction(Environment &envScope,
				const Symbol *pSymbol, Expr *pExprBody, FunctionType funcType) :
		Function(envScope, pSymbol, funcType, FLAG_None), _pExprBody(pExprBody)
{
}

CustomFunction::~CustomFunction()
{
}

Value CustomFunction::DoEval(Environment &env, Signal sig, Args &args) const
{
	AutoPtr<Environment> pEnvLocal(PrepareEnvironment(env, sig, args));
	if (pEnvLocal.get() == NULL) return Value::Null;
	if (_funcType != FUNCTYPE_Block) {
		Value valueThis(args.GetThis());
		valueThis.AddFlags(VFLAG_Privileged);
		pEnvLocal->AssignValue(Gura_Symbol(this), valueThis, EXTRA_Public);
	}
	pEnvLocal->AssignValue(Gura_Symbol(__args__),
				Value(new Object_args(env, args.Reference())), EXTRA_Public);
#if 0
	Sequence *pSequence = new CustomFunction::SequenceEx(pEnvLocal.release(),
								dynamic_cast<CustomFunction *>(Reference()));
	return Sequence::Return(sig, pSequence);
#else
	SeqPostHandler *pSeqPostHandler = NULL;
	Value result = GetExprBody()->Exec(*pEnvLocal, sig, pSeqPostHandler);
	EnvType envType = pEnvLocal->GetEnvType();
	if (envType == ENVTYPE_block) {
		// nothing to do. simply pass the signal to the outside.
	} else if (!sig.IsSignalled()) {
		// nothing to do
	} else if (sig.IsBreak()) {
		sig.ClearSignal();
	} else if (sig.IsContinue()) {
		sig.ClearSignal();
	} else if (sig.IsReturn()) {
		result = sig.GetValue();
		sig.ClearSignal();
	}
	return result;
#endif
}

Expr *CustomFunction::DiffUnary(Environment &env, Signal sig,
							const Expr *pExprArg, const Symbol *pSymbol) const
{
	SetError_MathDiffError(sig);
	return NULL;
}

CustomFunction *CustomFunction::CreateBlockFunc(Environment &env, Signal sig,
	const Symbol *pSymbol, const Expr_Block *pExprBlock, FunctionType funcType)
{
	AutoPtr<CustomFunction> pFunc(new CustomFunction(env,
							pSymbol, Expr::Reference(pExprBlock), funcType));
	pFunc->_declOwner.AllowTooManyArgs(true);
	const Expr_BlockParam *pExprBlockParam = pExprBlock->GetParam();
	if (pExprBlockParam != NULL) {
		AutoPtr<Args> pArgs(new Args());
		pArgs->SetExprOwnerArg(pExprBlockParam->GetExprOwner().Reference());
		if (!pFunc->CustomDeclare(env, sig, SymbolSet::Null, *pArgs)) {
			return NULL;
		}
	}
	return pFunc.release();
}

//-----------------------------------------------------------------------------
// CustomFunction::SequenceEx
//-----------------------------------------------------------------------------
CustomFunction::SequenceEx::SequenceEx(Environment *pEnv, CustomFunction *pCustomFunction) :
		ExprOwner::SequenceEx(pEnv, NULL, true), _pCustomFunction(pCustomFunction)
{
	const Expr *pExprBody = _pCustomFunction->GetExprBody();
	if (pExprBody == NULL) {
		_pExprOwner.reset(new ExprOwner());
	} else if (pExprBody->IsBlock()) {
		const Expr_Block *pExprBlock = dynamic_cast<const Expr_Block *>(pExprBody);
		_pExprOwner.reset(pExprBlock->GetExprOwner().Reference());
	} else {
		_pExprOwner.reset(new ExprOwner());
		_pExprOwner->push_back(pExprBody->Reference());
	}
}

bool CustomFunction::SequenceEx::DoStep(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	if (!ExprOwner::SequenceEx::DoStep(sig, result)) return false;
	if (env.GetEnvType() == ENVTYPE_block) {
		// nothing to do. simply pass the signal to the outside.
	} else if (!sig.IsSignalled()) {
		// nothing to do
	} else if (sig.IsBreak()) {
		sig.ClearSignal();
	} else if (sig.IsContinue()) {
		sig.ClearSignal();
	} else if (sig.IsReturn()) {
		result = sig.GetValue();
		sig.ClearSignal();
	}
	return true;
}

String CustomFunction::SequenceEx::ToString() const
{
	String str;
	str += "<sequence:customfunction>";
	return str;
}

}
