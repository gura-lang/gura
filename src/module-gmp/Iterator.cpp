//=============================================================================
// Iterator
//=============================================================================
#include "stdafx.h"

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Iterator_GmpSeqInf
//-----------------------------------------------------------------------------
bool Iterator_GmpSeqInf::IsSequenceInf() const
{
	return true;
}

Iterator *Iterator_GmpSeqInf::Clone() const
{
	return new Iterator_GmpSeqInf(*this);
}

Iterator *Iterator_GmpSeqInf::GetSource()
{
	return NULL;
}

bool Iterator_GmpSeqInf::DoNext(Environment &env, Signal sig, Value &value)
{
	value = Value(new Object_mpz(_num));
	_num += 1;
	return true;
}

String Iterator_GmpSeqInf::ToString() const
{
	String rtn;
	rtn += _numBegin.get_str();
	rtn += "L";
	rtn += "..";
	return rtn;
}

void Iterator_GmpSeqInf::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

//-----------------------------------------------------------------------------
// Iterator_GmpSeq
//-----------------------------------------------------------------------------
bool Iterator_GmpSeq::IsSequence() const { return true; }

Iterator *Iterator_GmpSeq::Clone() const
{
	return new Iterator_GmpSeq(*this);
}

Iterator *Iterator_GmpSeq::GetSource()
{
	return NULL;
}

bool Iterator_GmpSeq::DoNext(Environment &env, Signal sig, Value &value)
{
	if (!((_numStep > 0)? (_num <= _numEnd) : (_num >= _numEnd))) return false;
	value = Value(new Object_mpz(_num));
	_num += _numStep;
	return true;
}

String Iterator_GmpSeq::ToString() const
{
	String rtn;
	if (_numStep == 1. || _numStep == -1.) {
		rtn += _numBegin.get_str();
		rtn += "L";
		rtn += "..";
		rtn += _numEnd.get_str();
		rtn += "L";
	} else {
		rtn = "GmpSeq(";
		rtn += _numBegin.get_str();
		rtn += ",";
		rtn += _numEnd.get_str();
		rtn += ",";
		rtn += _numStep.get_str();
		rtn += ")";
	}
	return rtn;
}

void Iterator_GmpSeq::GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet)
{
}

Gura_EndModuleScope(gmp)
