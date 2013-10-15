#ifndef __GURA_PROCESSOR_H__
#define __GURA_PROCESSOR_H__

#include "Expr.h"

namespace Gura {

class GURA_DLLDECLARE Sequence {
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
	static Value Return(Signal sig, Sequence *pSequence);
};

class GURA_DLLDECLARE Sequence_Root : public Sequence {
protected:
	AutoPtr<ExprOwner> _pExprOwner;
	size_t _idxExpr;
public:
	Sequence_Root(Environment *pEnv, ExprOwner *pExprOwner);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
	inline const ExprOwner &GetExprOwner() const { return *_pExprOwner; }
};

class GURA_DLLDECLARE Sequence_Expr : public Sequence {
protected:
	AutoPtr<ExprOwner> _pExprOwner;
	size_t _idxExpr;
	bool _evalSymFuncFlag;
public:
	Sequence_Expr(Environment *pEnv, ExprOwner *pExprOwner, bool evalSymFuncFlag);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
	inline const ExprOwner &GetExprOwner() const { return *_pExprOwner; }
};

class GURA_DLLDECLARE Sequence_CustomFunction : public Sequence_Expr {
protected:
	AutoPtr<CustomFunction> _pCustomFunction;
public:
	Sequence_CustomFunction(Environment *pEnv, CustomFunction *pCustomFunction);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
};

class GURA_DLLDECLARE Sequence_ExprForList : public Sequence {
protected:
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

class GURA_DLLDECLARE Sequence_Iterator : public Sequence {
protected:
	AutoPtr<Iterator> _pIterator;
public:
	Sequence_Iterator(Environment *pEnv, Iterator *pIterator);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
	inline Iterator *GetIterator() { return _pIterator.get(); }
};

class GURA_DLLDECLARE SequenceStack : public std::list<Sequence *> {
public:
	~SequenceStack();
	void Clear();
};

class GURA_DLLDECLARE Processor {
protected:
	int _cntRef;
	SequenceStack _sequenceStack;
public:
	Gura_DeclareReferenceAccessor(Processor)
public:
	Processor();
	bool Step(Signal sig, Value &value);
	inline void PushSequence(Sequence *pSequence) { _sequenceStack.push_back(pSequence); }
	inline bool CheckDone() const { return _sequenceStack.empty(); }
	Value Run(Signal sig);
};

}

#endif
