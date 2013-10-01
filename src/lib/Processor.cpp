#include "stdafx.h"

#define DBGPARSER(x)

namespace Gura {

//-----------------------------------------------------------------------------
// Sequence
//-----------------------------------------------------------------------------
Sequence::Sequence(Environment *pEnv, ExprOwner *pExprOwner, Mode mode) :
		_cntRef(1), _pEnv(pEnv), _pExprOwner(pExprOwner), _mode(mode), _idxExpr(0)
{
}

Value Sequence::Step(Signal sig)
{
	if (CheckDone()) return Value::Null;
	const Expr *pExpr = GetExprOwner()[_idxExpr++];
	Value rtn = pExpr->Exec(*_pEnv, sig);
	return rtn;
}

String Sequence::ToString() const
{
	String str;
	str += "<sequence>";
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
Processor::Processor()
{
}

Value Processor::Step(Signal sig)
{
	if (CheckDone()) return Value::Null;
	Sequence *pSequence = _sequenceStack.back();
	Value rtn = pSequence->Step(sig);
	if (sig.IsSignalled()) return Value::Null;
	if (pSequence->CheckDone()) {
		Sequence::Delete(pSequence);
		_sequenceStack.pop_back();
	}
	if (rtn.IsSequence()) {
		_sequenceStack.push_back(rtn.GetSequence()->Reference());
		return Value::Null;
	}
	return rtn;
}

}
