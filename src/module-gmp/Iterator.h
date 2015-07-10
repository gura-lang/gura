//=============================================================================
// Iterator
//=============================================================================
#ifndef __GMP_ITERATOR_H__
#define __GMP_ITERATOR_H__

Gura_BeginModuleScope(gmp)

//-----------------------------------------------------------------------------
// Iterator_GmpSeqInf
//-----------------------------------------------------------------------------
class Iterator_GmpSeqInf : public Iterator {
private:
	mpz_class _num;
	mpz_class _numBegin;
public:
	inline Iterator_GmpSeqInf(const mpz_class &numBegin) :
					Iterator(true), _num(numBegin), _numBegin(numBegin) {}
	inline Iterator_GmpSeqInf(const Iterator_GmpSeqInf &iter) :
					Iterator(iter), _num(iter._num), _numBegin(iter._numBegin) {}
	virtual bool IsSequenceInf() const;
	virtual Iterator *Clone() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal &sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_GmpSeq
//-----------------------------------------------------------------------------
class Iterator_GmpSeq : public Iterator {
private:
	mpz_class _num;
	mpz_class _numBegin;
	mpz_class _numEnd;
	mpz_class _numStep;
public:
	inline Iterator_GmpSeq(const mpz_class &numBegin, const mpz_class &numEnd, const mpz_class &numStep) :
			Iterator(false), _num(numBegin),
			_numBegin(numBegin), _numEnd(numEnd), _numStep(numStep) {}
	inline Iterator_GmpSeq(const Iterator_GmpSeq &iter) :
			Iterator(iter), _num(iter._num),
			_numBegin(iter._numBegin), _numEnd(iter._numEnd), _numStep(iter._numStep) {}
	virtual bool IsSequence() const;
	virtual Iterator *Clone() const;
	virtual Iterator *GetSource();
	virtual bool DoNext(Environment &env, Signal &sig, Value &value);
	virtual String ToString() const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

Gura_EndModuleScope(gmp)

#endif
