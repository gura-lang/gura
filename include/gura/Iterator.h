#ifndef __GURA_ITERATOR_H__
#define __GURA_ITERATOR_H__

#include "Environment.h"
#include "Signal.h"
#include "Expr.h"
#include "Declaration.h"
#include "Value.h"
#include "OAL.h"

#define ITERATOR_HELP \
"If a block is specified, it executes the block while evaluating the iterator\n" \
"and returns the last evaluated value in the block as its own result.\n" \
"Otherwise, it returns an iterator or a list according to the attribute\n" \
"In default, it returns an iterator. If attribute :xiter is specified, it returns\n" \
"an iterator that eliminates nil value from the iterated result.\n" \
"If one of attributes :list, :xlist, :set and :xset is specified, it gathers results\n" \
"and returns a list of them. The rule is as follows\n" \
" :list  a list of result values\n" \
" :xlist a list of result values eliminating nil\n" \
" :set   a list of unique values of results\n" \
" :xset  a list of unique values of results eliminating nil\n"

namespace Gura {

class Expr_Caller;
class Args;
class IteratorOwner;

//-----------------------------------------------------------------------------
// Iterator
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator {
public:
	class DLLDECLARE Share {
	public:
		typedef std::vector<size_t> IndexList;
	private:
		bool _doneFlag;
		size_t _indexMin;
		IndexList _indexList;
		ValueDeque _valueDeque;
	public:
		Share();
		~Share();
		inline bool IsDone() const { return _doneFlag; }
		inline void SetDone() { _doneFlag = true; }
		int Register();
		bool Next(int id, Value &value);
		void Store(int id, const Value &value);
	};
protected:
	int _cntRef;
	Share *_pShare;
	bool _virginFlag;
	bool _infiniteFlag;
	bool _skipInvalidFlag;
public:
	inline Iterator(bool infiniteFlag, bool skipInvalidFlag = false) :
			_cntRef(1), _pShare(NULL), _virginFlag(true),
			_infiniteFlag(infiniteFlag), _skipInvalidFlag(skipInvalidFlag) {}
	inline Iterator(const Iterator &iter) :
			_cntRef(1), _pShare(NULL),
			_infiniteFlag(iter._infiniteFlag), _skipInvalidFlag(iter._skipInvalidFlag) {}
	inline int IncRef() { _cntRef++; return _cntRef; }
	inline int DecRef() { if (_cntRef > 0) _cntRef--; return _cntRef; }
	inline int GetRefCnt() const { return _cntRef; }
	static void Delete(Iterator *pIterator);
	inline static Iterator *Reference(const Iterator *pIterator) {
		if (pIterator == NULL) return NULL;
		Iterator *pIteratorCasted = const_cast<Iterator *>(pIterator);
		pIteratorCasted->IncRef();
		return pIteratorCasted;
	}
	inline bool IsVirgin() const { return _virginFlag && _pShare == NULL; }
	inline bool IsInfinite() const { return _infiniteFlag; }
	inline bool IsSkipInvalid() const { return _skipInvalidFlag; }
	inline void SetInfiniteFlag(bool infiniteFlag) { _infiniteFlag = infiniteFlag; }
	inline void SetSkipInvalidFlag(bool skipInvalidFlag) { _skipInvalidFlag = skipInvalidFlag; }
	inline bool Next(Environment &env, Signal sig, Value &value) {
		_virginFlag = false;
		return NextShared(env, sig, 0, value);
	}
	bool NextShared(Environment &env, Signal sig, int id, Value &value);
	virtual bool IsSequence() const;
	virtual bool IsSequenceInf() const;
	Iterator *_Clone();
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value) = 0;
	bool Consume(Environment &env, Signal sig);
	Value ToList(Environment &env, Signal sig,
								bool alwaysListFlag, bool excludeNilFlag);
	Value Eval(Environment &env, Signal sig, Args &args);
	Value Eval(Environment &env, Signal sig,
								Args &args, const Function *pFuncBlock);
	Value Reduce(Environment &env, Signal sig,
								Value valueAccum, const Function *pFuncBlock);
	Value MinMax(Environment &env, Signal sig,
									bool maxFlag, const SymbolSet &attrs);
	Value Sum(Environment &env, Signal sig, size_t &cnt);
	Value Average(Environment &env, Signal sig, size_t &cnt);
	Value Variance(Environment &env, Signal sig, size_t &cnt);
	Value StandardDeviation(Environment &env, Signal sig, size_t &cnt);
	Value And(Environment &env, Signal sig);
	Value Or(Environment &env, Signal sig);
	size_t Find(Environment &env, Signal sig, const Value &criteria);
	size_t FindTrue(Environment &env, Signal sig);
	size_t Count(Environment &env, Signal sig, const Value &criteria);
	size_t CountTrue(Environment &env, Signal sig);
	Iterator *Filter(Environment &env, Signal sig, const Value &criteria);
	size_t Seek(Environment &env, Signal sig, const Value &criteria, Value &value);
	size_t SeekTrue(Environment &env, Signal sig, Value &value);
	Iterator *While(Environment &env, Signal sig, const Value &criteria);
	Iterator *Since(Environment &env, Signal sig, const Value &criteria, bool containFirstFlag);
	Iterator *Until(Environment &env, Signal sig, const Value &criteria, bool containLastFlag);
	bool IsContain(Environment &env, Signal sig, const Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet) = 0;
	static void SetError_InvalidDataTypeOfElement(Signal sig);
	static void SetError_InfiniteNotAllowed(Signal sig);
protected:
	virtual ~Iterator();
	static bool PrepareRepeaterIterators(Environment &env, Signal sig,
						const ValueList &valListArg, ExprList &exprLeftList,
						IteratorOwner &iteratorOwner);
private:
	inline void operator=(const Iterator &iterator) {}
};

//-----------------------------------------------------------------------------
// Iterator_GenericClone
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_GenericClone : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	int _id;
public:
	inline Iterator_GenericClone(Iterator *pIterator, int id) :
			Iterator(pIterator->IsInfinite(), pIterator->IsSkipInvalid()),
			_pIterator(pIterator), _id(id) {}
	virtual ~Iterator_GenericClone();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// IteratorOwner
//-----------------------------------------------------------------------------
class DLLDECLARE IteratorOwner : public std::vector<Iterator *> {
public:
	inline IteratorOwner() {}
	IteratorOwner(const IteratorOwner &iterOwner);
	virtual ~IteratorOwner();
	bool Next(Environment &env, Signal sig, ValueList &valList);
	void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	bool IsInfinite() const;
	bool PrepareForMap(Signal sig, const DeclarationList &declList, const ValueList &valListArg);
};

//-----------------------------------------------------------------------------
// Iterator_Constant
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Constant : public Iterator {
private:
	Value _value;
public:
	inline Iterator_Constant(const Value &value) : Iterator(true), _value(value) {}
	inline Iterator_Constant(const Iterator_Constant &iter) :
										Iterator(true), _value(iter._value) {}
	virtual ~Iterator_Constant();
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_OneShot
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_OneShot : public Iterator {
private:
	Value _value;
	bool _doneFlag;
public:
	inline Iterator_OneShot(const Value &value) :
				Iterator(false), _value(value), _doneFlag(false) {}
	inline Iterator_OneShot(const Iterator_OneShot &iter) :
				Iterator(false), _value(iter._value), _doneFlag(iter._doneFlag) {}
	virtual ~Iterator_OneShot();
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Fill
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Fill : public Iterator {
private:
	int _cnt;
	Value _value;
	int _idx;
public:
	inline Iterator_Fill(int cnt, const Value &value) :
				Iterator(false), _cnt(cnt), _value(value), _idx(0) {}
	inline Iterator_Fill(const Iterator_Fill &iter) :
				Iterator(false), _cnt(iter._cnt), _value(iter._value),
				_idx(iter._idx) {}
	virtual ~Iterator_Fill();
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Rand
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Rand : public Iterator {
private:
	int _cnt;
	int _range;
	int _idx;
public:
	inline Iterator_Rand(int cnt, int range) :
						Iterator(false), _cnt(cnt), _range(range), _idx(0) {}
	virtual ~Iterator_Rand();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Range
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Range : public Iterator {
private:
	Number _num;
	Number _numBegin;
	Number _numEnd;
	Number _numStep;
public:
	inline Iterator_Range(Number numBegin, Number numEnd, Number numStep) :
			Iterator(false), _num(numBegin),
			_numBegin(numBegin), _numEnd(numEnd), _numStep(numStep) {}
	inline Iterator_Range(const Iterator_Range &iter) :
			Iterator(iter), _num(iter._num),
			_numBegin(iter._numBegin), _numEnd(iter._numEnd), _numStep(iter._numStep) {}
	virtual ~Iterator_Range();
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Sequence
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Sequence : public Iterator {
private:
	Number _num;
	Number _numBegin;
	Number _numEnd;
	Number _numStep;
public:
	inline Iterator_Sequence(Number numBegin, Number numEnd, Number numStep) :
			Iterator(false), _num(numBegin),
			_numBegin(numBegin), _numEnd(numEnd), _numStep(numStep) {}
	inline Iterator_Sequence(const Iterator_Sequence &iter) :
			Iterator(iter), _num(iter._num),
			_numBegin(iter._numBegin), _numEnd(iter._numEnd), _numStep(iter._numStep) {}
	virtual ~Iterator_Sequence();
	virtual bool IsSequence() const;
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	inline Number GetBegin() const { return _numBegin; }
	inline Number GetEnd() const { return _numEnd; }
	inline Number GetStep() const { return _numStep; }
};

//-----------------------------------------------------------------------------
// Iterator_SequenceInf
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_SequenceInf : public Iterator {
private:
	Number _num;
	Number _numBegin;
public:
	inline Iterator_SequenceInf(Number numBegin) :
					Iterator(true), _num(numBegin), _numBegin(numBegin) {}
	inline Iterator_SequenceInf(const Iterator_SequenceInf &iter) :
					Iterator(iter), _num(iter._num), _numBegin(iter._numBegin) {}
	virtual ~Iterator_SequenceInf();
	virtual bool IsSequenceInf() const;
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	inline Number GetBegin() const { return _numBegin; }
};

//-----------------------------------------------------------------------------
// Iterator_Interval
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Interval : public Iterator {
private:
	Number _numBegin;
	Number _numEnd;
	int _numSamples;
	Number _numDenom;
	int _iFactor;
	int _idx;
public:
	inline Iterator_Interval(Number numBegin, Number numEnd,
								int numSamples, Number numDenom, int iFactor) :
		Iterator(false), _numBegin(numBegin), _numEnd(numEnd), _numSamples(numSamples), 
		_numDenom(numDenom), _iFactor(iFactor), _idx(0) {}
	inline Iterator_Interval(Number numBegin, Number numEnd, int numSamples) :
		Iterator(false), _numBegin(numBegin), _numEnd(numEnd), _numSamples(numSamples), 
		_numDenom(numSamples - 1), _iFactor(0), _idx(0) {}
	inline Iterator_Interval(const Iterator_Interval &iter) :
		Iterator(iter), _numBegin(iter._numBegin), _numEnd(iter._numEnd), _numSamples(iter._numSamples),
		_numDenom(iter._numDenom), _iFactor(iter._iFactor), _idx(iter._idx) {}
	virtual ~Iterator_Interval();
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
protected:
	inline bool _DoNext(Number &num) {
		if (_idx >= _numSamples) return false;
		num = (_numEnd - _numBegin) * _iFactor / _numDenom + _numBegin;
		_iFactor++, _idx++;
		return true;
	}
};

#if 0
//-----------------------------------------------------------------------------
// Iterator_Fork
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Fork : public Iterator, public OAL::Thread {
private:
	Environment _env;
	AutoPtr<Function> _pFunc;
	Value _valueSelf;
	IteratorOwner _iterOwner;
	ValueList _valListA;
	ValueList _valListB;
	ValueList *_pValListToWrite;
	ValueList *_pValListToRead;
	ValueList::iterator _pValueRead;
	OAL::Semaphore _semaphore;
	bool _doneFlag;
	struct {
		bool blockedFlag;
		OAL::Event event;
	} _readBlock;
	struct {
		bool blockedFlag;
		OAL::Event event;
	} _writeBlock;
public:
	Iterator_Fork(Environment &env, Signal sig,
		Function *pFunc, const Value &valueSelf, const ValueList &valListArg);
	virtual ~Iterator_Fork();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void Run();
	void SwapList();
	void ForkProcess();
};
#endif

//-----------------------------------------------------------------------------
// Iterator_ExplicitMap
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_ExplicitMap : public Iterator {
private:
	Environment _env;
	Signal _sig;
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Object_function> _pObjFunc;
public:
	Iterator_ExplicitMap(Environment &env, Signal sig,
							Iterator *pIterator, Object_function *pObjFunc);
	Iterator_ExplicitMap(const Iterator_ExplicitMap &iter);
	virtual ~Iterator_ExplicitMap();
	virtual Iterator *Clone() const;
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_ImplicitMap
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_ImplicitMap : public Iterator {
private:
	Environment _env;
	Signal _sig;
	AutoPtr<Function> _pFunc;
	Value _valueSelf;
	AutoPtr<Iterator> _pIteratorSelf;
	IteratorOwner _iterOwner;
	bool _doneSelfFlag;
public:
	Iterator_ImplicitMap(Environment &env, Signal sig, Function *pFunc,
			const Value &valueSelf, Iterator *pIteratorSelf,
			const ValueList &valListArg, bool skipInvalidFlag);
	virtual ~Iterator_ImplicitMap();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_MemberMap
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_MemberMap : public Iterator {
private:
	Environment _env;
	Signal _sig;
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Expr> _pExpr;
public:
	inline Iterator_MemberMap(Environment &env, Signal sig, Iterator *pIterator, Expr *pExpr) :
		Iterator(pIterator->IsInfinite()), _env(env), _sig(sig), _pIterator(pIterator), _pExpr(pExpr) {}
	virtual ~Iterator_MemberMap();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_MethodMap
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_MethodMap : public Iterator {
private:
	Environment _env;
	Signal _sig;
	AutoPtr<Iterator> _pIteratorSelf;
	AutoPtr<Expr_Caller> _pExprCaller;
public:
	inline Iterator_MethodMap(Environment &env, Signal sig, Iterator *pIteratorSelf, Expr_Caller *pExprCaller) :
		Iterator(pIteratorSelf->IsInfinite()), _env(env), _sig(sig),
		_pIteratorSelf(pIteratorSelf), _pExprCaller(pExprCaller) {}
	virtual ~Iterator_MethodMap();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_FuncBinder
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_FuncBinder : public Iterator {
private:
	Environment _env;
	AutoPtr<Function> _pFunc;
	Value _valueSelf;
	AutoPtr<Iterator> _pIterator;
public:
	Iterator_FuncBinder(Environment &env,
				Function *pFunc, const Value &valueSelf, Iterator *pIterator);
	virtual ~Iterator_FuncBinder();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Delay
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Delay : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	Number _delay;
public:
	inline Iterator_Delay(Iterator *pIterator, Number delay) : 
		Iterator(pIterator->IsInfinite()), _pIterator(pIterator), _delay(delay) {}
	virtual ~Iterator_Delay();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Skip
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Skip : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	int _nSkip;
public:
	inline Iterator_Skip(Iterator *pIterator, int nSkip) :
		Iterator(pIterator->IsInfinite()), _pIterator(pIterator), _nSkip(nSkip) {}
	virtual ~Iterator_Skip();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_SkipInvalid
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_SkipInvalid : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
public:
	inline Iterator_SkipInvalid(Iterator *pIterator) :
				Iterator(pIterator->IsInfinite()), _pIterator(pIterator) {}
	virtual ~Iterator_SkipInvalid();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_RoundOff
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_RoundOff : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	Number _threshold;
public:
	inline Iterator_RoundOff(Iterator *pIterator, Number threshold) :
		Iterator(pIterator->IsInfinite()), _pIterator(pIterator), _threshold(threshold) {}
	virtual ~Iterator_RoundOff();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_FilterWithFunc
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_FilterWithFunc : public Iterator {
private:
	Environment _env;
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Object_function> _pObjFunc;
public:
	inline Iterator_FilterWithFunc(Environment &env,
							Iterator *pIterator, Object_function *pObjFunc) :
			Iterator(pIterator->IsInfinite()), _env(env),
			_pIterator(pIterator), _pObjFunc(pObjFunc) {}
	virtual ~Iterator_FilterWithFunc();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_FilterWithIter
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_FilterWithIter : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Iterator> _pIteratorCriteria;
public:
	inline Iterator_FilterWithIter(Iterator *pIterator, Iterator *pIteratorCriteria) :
			Iterator(pIterator->IsInfinite() && pIteratorCriteria->IsInfinite()),
			_pIterator(pIterator), _pIteratorCriteria(pIteratorCriteria) {}
	virtual ~Iterator_FilterWithIter();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_WhileWithFunc
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_WhileWithFunc : public Iterator {
private:
	Environment _env;
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Object_function> _pObjFunc;
public:
	inline Iterator_WhileWithFunc(Environment &env,
							Iterator *pIterator, Object_function *pObjFunc) :
			Iterator(pIterator->IsInfinite()), _env(env),
			_pIterator(pIterator), _pObjFunc(pObjFunc) {}
	virtual ~Iterator_WhileWithFunc();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_WhileWithIter
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_WhileWithIter : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Iterator> _pIteratorCriteria;
public:
	inline Iterator_WhileWithIter(Iterator *pIterator, Iterator *pIteratorCriteria) :
			Iterator(pIterator->IsInfinite() && pIteratorCriteria->IsInfinite()),
			_pIterator(pIterator), _pIteratorCriteria(pIteratorCriteria) {}
	virtual ~Iterator_WhileWithIter();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_UntilWithFunc
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_UntilWithFunc : public Iterator {
private:
	Environment _env;
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Object_function> _pObjFunc;
	bool _containLastFlag;
public:
	inline Iterator_UntilWithFunc(Environment &env, Iterator *pIterator,
								Object_function *pObjFunc, bool containLastFlag) :
			Iterator(pIterator->IsInfinite()), _env(env),
			_pIterator(pIterator), _pObjFunc(pObjFunc), _containLastFlag(containLastFlag) {}
	virtual ~Iterator_UntilWithFunc();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_UntilWithIter
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_UntilWithIter : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Iterator> _pIteratorCriteria;
	bool _containLastFlag;
public:
	inline Iterator_UntilWithIter(Iterator *pIterator,
								Iterator *pIteratorCriteria, bool containLastFlag) :
			Iterator(pIterator->IsInfinite() && pIteratorCriteria->IsInfinite()),
			_pIterator(pIterator), _pIteratorCriteria(pIteratorCriteria),
			_containLastFlag(containLastFlag) {}
	virtual ~Iterator_UntilWithIter();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_SinceWithFunc
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_SinceWithFunc : public Iterator {
private:
	Environment _env;
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Object_function> _pObjFunc;
	bool _containFirstFlag;
public:
	inline Iterator_SinceWithFunc(Environment &env, Iterator *pIterator,
								Object_function *pObjFunc, bool containFirstFlag) :
			Iterator(pIterator->IsInfinite()), _env(env),
			_pIterator(pIterator), _pObjFunc(pObjFunc), _containFirstFlag(containFirstFlag) {}
	virtual ~Iterator_SinceWithFunc();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_SinceWithIter
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_SinceWithIter : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	AutoPtr<Iterator> _pIteratorCriteria;
	bool _containFirstFlag;
public:
	inline Iterator_SinceWithIter(Iterator *pIterator,
								Iterator *pIteratorCriteria, bool containFirstFlag) :
			Iterator(pIterator->IsInfinite() && pIteratorCriteria->IsInfinite()),
			_pIterator(pIterator), _pIteratorCriteria(pIteratorCriteria),
			_containFirstFlag(containFirstFlag) {}
	virtual ~Iterator_SinceWithIter();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Replace
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Replace : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	Value _value;
	Value _valueReplace;
public:
	inline Iterator_Replace(Iterator *pIterator,
							const Value &value, const Value &valueReplace) :
			Iterator(pIterator->IsInfinite()), _pIterator(pIterator),
			_value(value), _valueReplace(valueReplace) {}
	virtual ~Iterator_Replace();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_ReplaceInvalid
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_ReplaceInvalid : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	Value _valueReplace;
public:
	inline Iterator_ReplaceInvalid(Iterator *pIterator, const Value &valueReplace) :
			Iterator(pIterator->IsInfinite()), _pIterator(pIterator),
			_valueReplace(valueReplace) {}
	virtual ~Iterator_ReplaceInvalid();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Format
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Format : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	String _format;
public:
	inline Iterator_Format(Iterator *pIterator, const char *format) :
			Iterator(pIterator->IsInfinite()),
			_pIterator(pIterator), _format(format) {}
	virtual ~Iterator_Format();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Pack
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Pack : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	String _format;
public:
	inline Iterator_Pack(Iterator *pIterator, const char *format) :
			Iterator(pIterator->IsInfinite()),
			_pIterator(pIterator), _format(format) {}
	virtual ~Iterator_Pack();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Zipv
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Zipv : public Iterator {
private:
	IteratorOwner _iterOwner;
public:
	inline Iterator_Zipv(const IteratorOwner &iterOwner) :
		Iterator(iterOwner.IsInfinite()), _iterOwner(iterOwner) {}
	virtual ~Iterator_Zipv();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_RunLength
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_RunLength : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	int _cnt;
	bool _doneFlag;
	Value _valuePrev;
public:
	inline Iterator_RunLength(Iterator *pIterator) :
		Iterator(pIterator->IsInfinite()), _pIterator(pIterator),
		_cnt(0), _doneFlag(false) {}
	virtual ~Iterator_RunLength();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Align
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Align : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	int _cnt;
	Value _valueFill;
public:
	inline Iterator_Align(Iterator *pIterator, int cnt, const Value &valueFill) :
		Iterator(false), _pIterator(pIterator), _cnt(cnt), _valueFill(valueFill) {}
	virtual ~Iterator_Align();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Head
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Head : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	int _cnt;
public:
	inline Iterator_Head(Iterator *pIterator, int cnt) :
						Iterator(false), _pIterator(pIterator), _cnt(cnt) {}
	virtual ~Iterator_Head();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Fold
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Fold : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	int _cnt;
	bool _listItemFlag;
public:
	inline Iterator_Fold(Iterator *pIterator, int cnt, bool listItemFlag) :
			Iterator(pIterator->IsInfinite()),
			_pIterator(pIterator), _cnt(cnt), _listItemFlag(listItemFlag) {}
	virtual ~Iterator_Fold();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_FoldSeg
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_FoldSeg : public Iterator {
private:
	AutoPtr<Iterator> _pIterator;
	int _cnt;
	Value _valueNext;
public:
	inline Iterator_FoldSeg(Iterator *pIterator, int cnt, const Value &valueNext) :
			Iterator(false), _pIterator(pIterator),
			_cnt(cnt), _valueNext(valueNext) {}
	virtual ~Iterator_FoldSeg();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_Concat
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_Concat : public Iterator {
private:
	IteratorOwner _iterOwner;
	IteratorOwner::iterator _ppIterator;
public:
	inline Iterator_Concat() : Iterator(false), _ppIterator(_iterOwner.begin()) {}
	virtual ~Iterator_Concat();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	void Add(Iterator *pIterator);
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_repeat
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_repeat : public Iterator {
private:
	Environment _env;
	AutoPtr<Function> _pFuncBlock;
	bool _standaloneFlag;
	AutoPtr<Iterator> _pIteratorSub;
	int _cnt;
	int _idx;
public:
	Iterator_repeat(Environment &env, Signal sig, Function *pFuncBlock,
					bool skipInvalidFlag, bool standaloneFlag, int cnt);
	virtual ~Iterator_repeat();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_while
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_while : public Iterator {
private:
	Environment _env;
	AutoPtr<Function> _pFuncBlock;
	bool _standaloneFlag;
	AutoPtr<Iterator> _pIteratorSub;
	AutoPtr<Expr> _pExpr;
	int _idx;
public:
	Iterator_while(Environment &env, Signal sig, Function *pFuncBlock,
					bool skipInvalidFlag, bool standaloneFlag, Expr *pExpr);
	virtual ~Iterator_while();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_for
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_for : public Iterator {
private:
	Environment _env;
	AutoPtr<Function> _pFuncBlock;
	bool _standaloneFlag;
	AutoPtr<Iterator> _pIteratorSub;
	ExprList _exprLeftList;
	IteratorOwner _iteratorOwner;
	int _idx;
	bool _doneFlag;
public:
	Iterator_for(Environment &env, Signal sig, Function *pFuncBlock,
			bool skipInvalidFlag, bool standaloneFlag, const ValueList &valListArg);
	virtual ~Iterator_for();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
};

//-----------------------------------------------------------------------------
// Iterator_cross
//-----------------------------------------------------------------------------
class DLLDECLARE Iterator_cross : public Iterator {
private:
	Environment _env;
	AutoPtr<Function> _pFuncBlock;
	bool _standaloneFlag;
	AutoPtr<Iterator> _pIteratorSub;
	ExprList _exprLeftList;
	IteratorOwner _iteratorOwner;
	IteratorOwner _iteratorOwnerOrg;
	ValueList _valListArg;
	int _idx;
	bool _doneFlag;
public:
	Iterator_cross(Environment &env, Signal sig, Function *pFuncBlock,
			bool skipInvalidFlag, bool standaloneFlag, const ValueList &valListArg);
	virtual ~Iterator_cross();
	virtual bool DoNext(Environment &env, Signal sig, Value &value);
	virtual String ToString(Signal sig) const;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
private:
	bool AdvanceIterators(Environment &env, Signal sig);
};

}

#endif
