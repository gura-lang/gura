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

Value Sequence::Return(Signal sig, Sequence *pSequence)
{
	Value result;
	while (!pSequence->CheckDone()) {
		if (!pSequence->Step(sig, result)) {
			result = Value::Null;
			break;
		}
	}
	Sequence::Delete(pSequence);
	return result;
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
