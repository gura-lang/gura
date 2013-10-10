#include "stdafx.h"

#define DBGPARSER(x)

namespace Gura {

//-----------------------------------------------------------------------------
// Sequence
//-----------------------------------------------------------------------------
Sequence::Sequence(Environment *pEnv) : _cntRef(1), _pEnv(pEnv), _doneFlag(false)
{
}

Sequence::~Sequence()
{
}

//-----------------------------------------------------------------------------
// Sequence_Root
//-----------------------------------------------------------------------------
Sequence_Root::Sequence_Root(Environment *pEnv, ExprOwner *pExprOwner) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
{
}

bool Sequence_Root::Step(Signal sig, Value &result)
{
	if (CheckDone()) return false;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	//::printf("# %s\n", pExpr->ToString(Expr::SCRSTYLE_Brief).c_str());
	result = pExpr->Exec(env, sig);
	if (sig.IsError()) {
		sig.AddExprCause(pExpr);
		result = Value::Null;
		_doneFlag = true;
		return false;
	} else if (sig.IsTerminate()) {
		env.GetConsoleErr()->PrintSignal(sig, sig);
		sig.ClearSignal();
		result = Value::Null;
		_doneFlag = true;
		return false;
	} else if (sig.IsSignalled()) {
		env.GetConsoleErr()->PrintSignal(sig, sig);
		sig.ClearSignal();
	} else if (!env.GetGlobal()->GetEchoFlag()) {
		// nothing to do
	} else if (result.IsValid()) {
		env.GetConsole()->Println(sig, result.ToString(sig).c_str());
	}
	return true;
}

String Sequence_Root::ToString() const
{
	String str;
	str += "<sequence_root>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Expr
//-----------------------------------------------------------------------------
Sequence_Expr::Sequence_Expr(Environment *pEnv, ExprOwner *pExprOwner, bool evalSymFuncFlag) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0),
						_evalSymFuncFlag(evalSymFuncFlag)
{
}

bool Sequence_Expr::Step(Signal sig, Value &result)
{
	if (CheckDone()) return false;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	result = pExpr->Exec(env, sig);
	if (sig.IsSignalled()) {
		sig.AddExprCause(pExpr);
		_doneFlag = true;
		return false;
	}
	if (_evalSymFuncFlag && result.IsFunction() &&
								result.GetFunction()->IsSymbolFunc()) {
		// symbol functions are only evaluated by a sequence of block.
		// in the folloiwng example, "return" shall be evaluated by a block
		// of "if" function.
		//   repeat { if (flag) { return } }
		// in the following example, "&&" operator returns "return" function
		// object as its result, and then the block of "repeat" shall evaluate it.
		//   repeat { flag && return }
		const Function *pFunc = result.GetFunction();
		AutoPtr<Args> pArgs(new Args());
		Value result = pFunc->EvalExpr(env, sig, *pArgs);
		if (sig.IsSignalled()) {
			sig.AddExprCause(pExpr);
			_doneFlag = true;
			return false;
		}
	}
	return true;
}

String Sequence_Expr::ToString() const
{
	String str;
	str += "<sequence_expr>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_CustomFunction
//-----------------------------------------------------------------------------
Sequence_CustomFunction::Sequence_CustomFunction(Environment *pEnv, CustomFunction *pCustomFunction) :
			Sequence_Expr(pEnv, NULL, true), _pCustomFunction(pCustomFunction)
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

bool Sequence_CustomFunction::Step(Signal sig, Value &result)
{
	Environment &env = *_pEnv;
	if (!Sequence_Expr::Step(sig, result)) return false;
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

String Sequence_CustomFunction::ToString() const
{
	String str;
	str += "<sequence_customfunction>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_ExprForList
//-----------------------------------------------------------------------------
Sequence_ExprForList::Sequence_ExprForList(Environment *pEnv, ExprOwner *pExprOwner) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
{
	_pValList = &_value.InitAsList(*pEnv);
}

bool Sequence_ExprForList::Step(Signal sig, Value &result)
{
	if (CheckDone()) return false;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return false;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	result = pExpr->Exec(env, sig);
	return true;
}

String Sequence_ExprForList::ToString() const
{
	String str;
	str += "<sequence_exprforlist>";
	return str;
}

//-----------------------------------------------------------------------------
// Sequence_Iterator
//-----------------------------------------------------------------------------
Sequence_Iterator::Sequence_Iterator(Environment *pEnv, Iterator *pIterator) :
									Sequence(pEnv), _pIterator(pIterator)
{
}

bool Sequence_Iterator::Step(Signal sig, Value &result)
{
	if (CheckDone()) return false;
	Environment &env = *_pEnv;
	if (!_pIterator->Next(env, sig, result)) {
		_doneFlag = true;
		return false;
	}
	return true;
}

String Sequence_Iterator::ToString() const
{
	String str;
	str += "<sequence_iterator>";
	return str;
}

//-----------------------------------------------------------------------------
// SequenceStack
//-----------------------------------------------------------------------------
SequenceStack::~SequenceStack()
{
	Clear();
}

void SequenceStack::Clear()
{
	foreach (SequenceStack, ppSequence, *this) {
		Sequence *pSequence = *ppSequence;
		Sequence::Delete(pSequence);
	}
	clear();
}

//-----------------------------------------------------------------------------
// Processor
//-----------------------------------------------------------------------------
Processor::Processor() : _cntRef(1)
{
}

bool Processor::Step(Signal sig, Value &result)
{
	if (CheckDone()) return true;
	Sequence *pSequence = _sequenceStack.back();
	pSequence->Step(sig, result);
	if (sig.IsSignalled()) return false;
	if (pSequence->CheckDone()) {
		Sequence::Delete(pSequence);
		_sequenceStack.pop_back();
	}
	if (result.IsSequence()) {
		_sequenceStack.push_back(result.GetSequence()->Reference());
		return true;
	}
	return true;
}

Value Processor::Run(Signal sig)
{
	Value result;
	while (!CheckDone()) {
		if (!Step(sig, result)) return Value::Null;
	}
	return result;
}

}
