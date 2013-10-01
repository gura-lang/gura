#ifndef __GURA_PROCESSOR_H__
#define __GURA_PROCESSOR_H__

#include "Expr.h"

namespace Gura {

class Sequence {
public:
	enum Mode {
		MODE_Normal,
	};
private:
	int _cntRef;
	AutoPtr<Environment> _pEnv;
	AutoPtr<ExprOwner> _pExprOwner;
	Mode _mode;
	size_t _idxExpr;
public:
	Gura_DeclareReferenceAccessor(Sequence)
public:
	Sequence(const Environment &env, ExprOwner *pExprOwner, Mode mode);
private:
	inline ~Sequence() {}
public:
	Value Step(Signal sig);
	String ToString() const;
	inline bool CheckDone() const { return _idxExpr >= GetExprOwner().size(); }
	inline const ExprOwner &GetExprOwner() const { return *_pExprOwner; }
};

class SequenceStack : public std::list<Sequence *> {
public:
	~SequenceStack();
	void Clear();
};

class Processor {
private:
	SequenceStack _sequenceStack;
public:
	Processor();
	Value Step(Signal sig);
	inline bool CheckDone() const { return _sequenceStack.empty(); }
};

}

#endif
