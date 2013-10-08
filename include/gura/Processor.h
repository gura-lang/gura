#ifndef __GURA_PROCESSOR_H__
#define __GURA_PROCESSOR_H__

#include "Expr.h"

namespace Gura {

class Sequence {
protected:
	int _cntRef;
	AutoPtr<Environment> _pEnv;
	bool _doneFlag;
public:
	Gura_DeclareReferenceAccessor(Sequence)
public:
	Sequence(Environment *pEnv);
protected:
	virtual ~Sequence();
public:
	virtual bool Step(Signal sig, Value &result) = 0;
	virtual String ToString() const = 0;
	inline bool CheckDone() const { return _doneFlag; }
};

class Sequence_Root : public Sequence {
private:
	AutoPtr<ExprOwner> _pExprOwner;
	size_t _idxExpr;
public:
	Sequence_Root(Environment *pEnv, ExprOwner *pExprOwner);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
	inline const ExprOwner &GetExprOwner() const { return *_pExprOwner; }
};

class Sequence_Expr : public Sequence {
private:
	AutoPtr<ExprOwner> _pExprOwner;
	size_t _idxExpr;
public:
	Sequence_Expr(Environment *pEnv, ExprOwner *pExprOwner);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
	inline const ExprOwner &GetExprOwner() const { return *_pExprOwner; }
};

class Sequence_ExprForList : public Sequence {
private:
	AutoPtr<ExprOwner> _pExprOwner;
	size_t _idxExpr;
	Value _value;
	ValueList *_pValList;
public:
	Sequence_ExprForList(Environment *pEnv, ExprOwner *pExprOwner);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
	inline const ExprOwner &GetExprOwner() const { return *_pExprOwner; }
};

class Sequence_Iterator : public Sequence {
private:
	AutoPtr<Iterator> _pIterator;
public:
	Sequence_Iterator(Environment *pEnv, Iterator *pIterator);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
	inline Iterator *GetIterator() { return _pIterator.get(); }
};

class SequenceStack : public std::list<Sequence *> {
public:
	~SequenceStack();
	void Clear();
};

class Processor {
private:
	int _cntRef;
	SequenceStack _sequenceStack;
public:
	Gura_DeclareReferenceAccessor(Processor)
public:
	Processor();
	bool Step(Signal sig);
	inline void PushSequence(Sequence *pSequence) { _sequenceStack.push_back(pSequence); }
	inline bool CheckDone() const { return _sequenceStack.empty(); }
};

}

#endif
