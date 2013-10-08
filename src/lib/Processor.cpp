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
	
	::printf("# %s\n", pExpr->ToString(Expr::SCRSTYLE_Brief).c_str());
	
	result = pExpr->Exec(*_pEnv, sig);
	if (sig.IsError()) {
		::printf("line.%d\n", __LINE__);
		sig.AddExprCause(pExpr);
		_doneFlag = true;
		return false;
	} else if (sig.IsTerminate()) {
		::printf("line.%d\n", __LINE__);
		env.GetConsoleErr()->PrintSignal(sig, sig);
		sig.ClearSignal();
		_doneFlag = true;
		return false;
	} else if (sig.IsSignalled()) {
		::printf("line.%d\n", __LINE__);
		env.GetConsoleErr()->PrintSignal(sig, sig);
		sig.ClearSignal();
	} else if (!env.GetGlobal()->GetEchoFlag()) {
		::printf("line.%d\n", __LINE__);
		// nothing to do
	} else if (result.IsValid()) {
		::printf("line.%d\n", __LINE__);
		// pConsole must be retrieved here.
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
Sequence_Expr::Sequence_Expr(Environment *pEnv, ExprOwner *pExprOwner) :
						Sequence(pEnv), _pExprOwner(pExprOwner), _idxExpr(0)
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
	return true;
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

bool Processor::Step(Signal sig)
{
	if (CheckDone()) return true;
	Sequence *pSequence = _sequenceStack.back();
	Value result;
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

}
