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

Value Sequence_Root::Step(Signal sig)
{
	if (CheckDone()) return Value::Null;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return Value::Null;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	Value result = pExpr->Exec(*_pEnv, sig);
	if (sig.IsError()) {
		sig.AddExprCause(pExpr);
		result = Value::Null;
		_doneFlag = true;
	} else if (sig.IsTerminate()) {
		env.GetConsoleErr()->PrintSignal(sig, sig);
		sig.ClearSignal();
		result = Value::Null;
		_doneFlag = true;
	} else if (sig.IsSignalled()) {
		env.GetConsoleErr()->PrintSignal(sig, sig);
		sig.ClearSignal();
	} else if (!env.GetGlobal()->GetEchoFlag()) {
		// nothing to do
	} else if (result.IsValid()) {
		// pConsole must be retrieved here.
		env.GetConsole()->Println(sig, result.ToString(sig).c_str());
	}
	return result;
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
Sequence_Expr::Sequence_Expr(Environment *pEnv, ExprOwner *pExprOwner) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
{
}

Value Sequence_Expr::Step(Signal sig)
{
	if (CheckDone()) return Value::Null;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return Value::Null;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	Value result = pExpr->Exec(env, sig);
	return result;
}

String Sequence_Expr::ToString() const
{
	String str;
	str += "<sequence_expr>";
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

Value Sequence_ExprForList::Step(Signal sig)
{
	if (CheckDone()) return Value::Null;
	if (_idxExpr >= GetExprOwner().size()) {
		_doneFlag = true;
		return Value::Null;
	}
	Environment &env = *_pEnv;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	Value result = pExpr->Exec(env, sig);
	return result;
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

Value Sequence_Iterator::Step(Signal sig)
{
	if (CheckDone()) return Value::Null;
	Environment &env = *_pEnv;
	Value result;
	if (!_pIterator->Next(env, sig, result)) {
		_doneFlag = true;
		return Value::Null;
	}
	return result;
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

Value Processor::Step(Signal sig)
{
	if (CheckDone()) return Value::Null;
	Sequence *pSequence = _sequenceStack.back();
	Value result = pSequence->Step(sig);
	if (sig.IsSignalled()) return Value::Null;
	if (pSequence->CheckDone()) {
		Sequence::Delete(pSequence);
		_sequenceStack.pop_back();
	}
	if (result.IsSequence()) {
		_sequenceStack.push_back(result.GetSequence()->Reference());
		return Value::Null;
	}
	return result;
}

}
