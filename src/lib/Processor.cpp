//=============================================================================
// Processor
//=============================================================================
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

bool Sequence::Step(Signal &sig, Value &result)
{
	if (!DoStep(sig, result)) return false;
	if (CheckDone() && !_pSeqPostHandler.IsNull()) {
		bool rtn = _pSeqPostHandler->DoPost(sig, result);
		_pSeqPostHandler.reset(nullptr);
		return rtn;
	}
	return true;
}

Value Sequence::Return(Signal &sig, Sequence *pSequence)
{
	Value result;
	while (!pSequence->CheckDone()) {
		pSequence->Step(sig, result);
		if (sig.IsSignalled()) break;
	}
	Sequence::Delete(pSequence);
	return result;
}

//-----------------------------------------------------------------------------
// SeqPostHandler
//-----------------------------------------------------------------------------
SeqPostHandler::~SeqPostHandler()
{
	// virtual destructor
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

bool Processor::Step(Signal &sig, Value &result)
{
	if (CheckDone()) return true;
	Sequence *pSequence = _sequenceStack.back();
	if (!pSequence->Step(sig, result)) return false;
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

Value Processor::Run(Signal &sig)
{
	Value result;
	while (!CheckDone()) {
		if (!Step(sig, result)) return Value::Nil;
	}
	return result;
}

Value Processor::Run(Environment *pEnv, Signal &sig, const Expr *pExpr)
{
	AutoPtr<Processor> pProcessor(new Processor());
	if (pExpr->IsRoot()) {
		const Expr_Root *pExprRoot = dynamic_cast<const Expr_Root *>(pExpr);
		pProcessor->PushSequence(new Expr::SequenceRoot(
							pEnv, pExprRoot->GetExprOwner().Reference()));
	} else {
		AutoPtr<ExprOwner> pExprOwner(new ExprOwner());
		pExprOwner->push_back(pExpr->Reference());
		pProcessor->PushSequence(new Expr::SequenceRoot(pEnv, pExprOwner->Reference()));
	}
	return pProcessor->Run(sig);
}

}
