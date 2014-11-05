//=============================================================================
// Iterator
//=============================================================================
#ifndef __GURA_ITERATOR_H__
#define __GURA_ITERATOR_H__

#include "Environment.h"
#include "Signal.h"
#include "Value.h"

#define GURA_ITERATOR_HELP \
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

class Args;
class DeclarationList;

//-----------------------------------------------------------------------------
// Iterator
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Iterator {
public:
	class GURA_DLLDECLARE Share {
	public:
		typedef std::vector<size_t> IndexList;
	private:
		bool _doneFlag;
		size_t _indexMin;
		IndexList _indexList;
		ValueDeque _valueDeque;
	public:
		Share();
		inline bool IsDone() const { return _doneFlag; }
		inline void SetDone() { _doneFlag = true; }
		int Register();
		bool Next(int id, Value &value);
		void Store(int id, const Value &value);
	};
protected:
	int _cntRef;
	int _idxCur;
	int _idxNext;
	std::auto_ptr<Share> _pShare;
	bool _infiniteFlag;
	bool _skipInvalidFlag;
	bool _repeaterFlag;
public:
	Gura_DeclareReferenceAccessor(Iterator);
public:
	inline Iterator(bool infiniteFlag, bool skipInvalidFlag = false, bool repeaterFlag = false) :
			_cntRef(1), _idxCur(-1), _idxNext(0), _pShare(NULL),
			_infiniteFlag(infiniteFlag), _skipInvalidFlag(skipInvalidFlag),
			_repeaterFlag(repeaterFlag) {}
	inline Iterator(const Iterator &iter) :
			_cntRef(1), _idxCur(iter._idxCur), _idxNext(iter._idxNext), _pShare(NULL),
			_infiniteFlag(iter._infiniteFlag), _skipInvalidFlag(iter._skipInvalidFlag),
			_repeaterFlag(iter._repeaterFlag) {}
	virtual ~Iterator();
	inline int GetIndexCur() const { return _idxCur; }
	inline int GetIndexNext() const { return _idxNext; }
	inline bool IsVirgin() const { return _idxNext == 0 && _pShare.get() == NULL; }
	inline bool IsInfinite() const { return _infiniteFlag; }
	inline bool IsSkipInvalid() const { return _skipInvalidFlag; }
	inline bool IsRepeater() const { return _repeaterFlag; }
	inline void SetInfiniteFlag(bool infiniteFlag) { _infiniteFlag = infiniteFlag; }
	inline void SetSkipInvalidFlag(bool skipInvalidFlag) { _skipInvalidFlag = skipInvalidFlag; }
	inline void SetRepeaterFlag(bool repeaterFlag) { _repeaterFlag = repeaterFlag; }
	inline bool Next(Environment &env, Signal sig, Value &value) {
		_idxCur = _idxNext;
		_idxNext++;
		return NextShared(env, sig, 0, value);
	}
	bool NextShared(Environment &env, Signal sig, int id, Value &value);
	virtual bool IsSequence() const;
	virtual bool IsSequenceInf() const;
	Iterator *_Clone();
	virtual Iterator *Clone() const;
	bool Consume(Environment &env, Signal sig);
	Value ToList(Environment &env, Signal sig,
								bool alwaysListFlag, bool excludeNilFlag);
	Value Eval(Environment &env, Signal sig, Args &args);
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
	size_t Find(Environment &env, Signal sig, const Value &criteria, Value &value);
	size_t FindTrue(Environment &env, Signal sig, Value &value);
	size_t Count(Environment &env, Signal sig, const Value &criteria);
	size_t CountTrue(Environment &env, Signal sig);
	Iterator *Filter(Environment &env, Signal sig, const Value &criteria);
	Iterator *While(Environment &env, Signal sig, const Value &criteria);
	Iterator *Since(Environment &env, Signal sig, const Value &criteria, bool containFirstFlag);
	Iterator *Until(Environment &env, Signal sig, const Value &criteria, bool containLastFlag);
	bool DoesContain(Environment &env, Signal sig, const Value &value);
	virtual String ToString() const;
	static void SetError_InvalidDataTypeOfElement(Signal sig);
	static void SetError_InfiniteNotAllowed(Signal sig);
	virtual Iterator *GetSource() = 0;
	virtual bool DoNext(Environment &env, Signal sig, Value &value) = 0;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet) = 0;
private:
	inline void operator=(const Iterator &iterator) {}
};

//-----------------------------------------------------------------------------
// IteratorOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE IteratorOwner : public std::vector<Iterator *> {
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
// IteratorDeque
//-----------------------------------------------------------------------------
typedef std::deque<Iterator *> IteratorDeque;

}

#endif
