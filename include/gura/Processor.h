#ifndef __GURA_PROCESSOR_H__
#define __GURA_PROCESSOR_H__

#include "Expr.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Sequence
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Sequence_Root
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Sequence_Expr
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Sequence_CustomFunction
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Sequence_CustomFunction : public Sequence_Expr {
protected:
	AutoPtr<CustomFunction> _pCustomFunction;
public:
	Sequence_CustomFunction(Environment *pEnv, CustomFunction *pCustomFunction);
public:
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
};

//-----------------------------------------------------------------------------
// Sequence_ExprForList
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Sequence_Iterator
//-----------------------------------------------------------------------------
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

//-----------------------------------------------------------------------------
// Sequence_Call
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Sequence_Call : public Sequence {
private:
	enum Stat {
		STAT_Init, STAT_ExprArgs, STAT_OptArgs, STAT_NamedArgs, STAT_Exec,
	};
	class GURA_DLLDECLARE ExprMap : public std::map<const Symbol *, Expr *, Symbol::KeyCompare_UniqNumber> {
	public:
		~ExprMap();
	};
private:
	class GURA_DLLDECLARE Sequence_StoreDict : public Sequence {
	private:
		AutoPtr<Sequence_Call> _pSequenceCall;
		AutoPtr<Expr> _pExprLeft;
		AutoPtr<Expr> _pExprRight;
	public:
		inline Sequence_StoreDict(Environment *pEnv, Sequence_Call *pSequenceCall, Expr *pExprLeft, Expr *pExprRight) :
						Sequence(pEnv), _pSequenceCall(pSequenceCall),
						_pExprLeft(pExprLeft), _pExprRight(pExprRight) {}
		virtual bool Step(Signal sig, Value &result);
		virtual String ToString() const;
	};
	class GURA_DLLDECLARE Sequence_ExpandMod : public Sequence {
	private:
		AutoPtr<Sequence_Call> _pSequenceCall;
		AutoPtr<Expr> _pExprArg;
	public:
		inline Sequence_ExpandMod(Environment *pEnv, Sequence_Call *pSequenceCall, Expr *pExprArg) :
				Sequence(pEnv), _pSequenceCall(pSequenceCall), _pExprArg(pExprArg) {}
		virtual bool Step(Signal sig, Value &result);
		virtual String ToString() const;
	};
	class GURA_DLLDECLARE Sequence_ExpandMul : public Sequence {
	private:
		AutoPtr<Sequence_Call> _pSequenceCall;
		AutoPtr<Expr> _pExprArg;
	public:
		inline Sequence_ExpandMul(Environment *pEnv, Sequence_Call *pSequenceCall, Expr *pExprArg) :
				Sequence(pEnv), _pSequenceCall(pSequenceCall), _pExprArg(pExprArg) {}
		virtual bool Step(Signal sig, Value &result);
		virtual String ToString() const;
	};
	class GURA_DLLDECLARE Sequence_ValListArg : public Sequence {
	private:
		AutoPtr<Sequence_Call> _pSequenceCall;
		AutoPtr<Expr> _pExprArg;
		bool _skipDeclFlag;
	public:
		inline Sequence_ValListArg(Environment *pEnv, Sequence_Call *pSequenceCall, Expr *pExprArg, bool skipDeclFlag) :
				Sequence(pEnv), _pSequenceCall(pSequenceCall), _pExprArg(pExprArg), _skipDeclFlag(skipDeclFlag) {}
		virtual bool Step(Signal sig, Value &result);
		virtual String ToString() const;
	};
	class GURA_DLLDECLARE Sequence_ValDictArg : public Sequence {
	private:
		AutoPtr<Sequence_Call> _pSequenceCall;
		bool _skipDeclFlag;
	public:
		inline Sequence_ValDictArg(Environment *pEnv, Sequence_Call *pSequenceCall) :
								Sequence(pEnv), _pSequenceCall(pSequenceCall) {}
		virtual bool Step(Signal sig, Value &result);
		virtual String ToString() const;
	};
private:
	Stat _stat;
	AutoPtr<Function> _pFunc;
	AutoPtr<Args> _pArgs;
	ExprMap _exprMap;
	ExprMap::iterator _iterExprMap;
	DeclarationList::const_iterator _ppDecl;
	ExprList::const_iterator _ppExprArg;
	bool _stayDeclPointerFlag;
	bool _mapFlag;
public:
	Sequence_Call(Environment *pEnv, Function *pFunc, Args &args);
public:
	inline Args *GetArgs() { return _pArgs.get(); }
	inline ExprMap &GetExprMap() { return _exprMap; }
	inline ExprMap::iterator NextIterExprMap() { return _iterExprMap++; }
	virtual bool Step(Signal sig, Value &result);
	virtual String ToString() const;
	void SkipDeclarations(size_t nSkipDecl);
};

//-----------------------------------------------------------------------------
// SequenceStack
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE SequenceStack : public std::list<Sequence *> {
public:
	~SequenceStack();
	void Clear();
};

//-----------------------------------------------------------------------------
// Processor
//-----------------------------------------------------------------------------
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
