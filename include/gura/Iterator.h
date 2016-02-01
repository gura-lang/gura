//=============================================================================
// Iterator
//=============================================================================
#ifndef __GURA_ITERATOR_H__
#define __GURA_ITERATOR_H__

#include "Environment.h"
#include "Signal.h"
#include "Value.h"

namespace Gura {

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
	std::unique_ptr<Share> _pShare;
	bool _infiniteFlag;
	bool _skipInvalidFlag;
	bool _repeaterFlag;
	bool _listOriginFlag;
public:
	Gura_DeclareReferenceAccessor(Iterator);
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Iterator");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
public:
	inline Iterator(bool infiniteFlag, bool skipInvalidFlag = false, bool repeaterFlag = false) :
		_cntRef(1), _idxCur(-1), _idxNext(0), _pShare(nullptr),
		_infiniteFlag(infiniteFlag), _skipInvalidFlag(skipInvalidFlag),
		_repeaterFlag(repeaterFlag), _listOriginFlag(false) {}
	inline Iterator(const Iterator &iter) :
		_cntRef(1), _idxCur(iter._idxCur), _idxNext(iter._idxNext), _pShare(nullptr),
		_infiniteFlag(iter._infiniteFlag), _skipInvalidFlag(iter._skipInvalidFlag),
		_repeaterFlag(iter._repeaterFlag), _listOriginFlag(iter._listOriginFlag) {}
	virtual ~Iterator();
	inline int GetIndexCur() const { return _idxCur; }
	inline int GetIndexNext() const { return _idxNext; }
	inline bool IsVirgin() const { return _idxNext == 0 && _pShare.get() == nullptr; }
	inline bool IsInfinite() const { return _infiniteFlag; }
	inline bool IsSkipInvalid() const { return _skipInvalidFlag; }
	inline bool IsRepeater() const { return _repeaterFlag; }
	inline bool IsListOrigin() const { return _listOriginFlag; }
	inline void SetInfiniteFlag(bool infiniteFlag) { _infiniteFlag = infiniteFlag; }
	inline void SetSkipInvalidFlag(bool skipInvalidFlag) { _skipInvalidFlag = skipInvalidFlag; }
	inline void SetRepeaterFlag(bool repeaterFlag) { _repeaterFlag = repeaterFlag; }
	inline void SetListOriginFlag(bool listOriginFlag) { _listOriginFlag = listOriginFlag; }
	inline bool Next(Environment &env, Value &value) {
		_idxCur = _idxNext;
		_idxNext++;
		return NextShared(env, 0, value);
	}
	bool NextShared(Environment &env, int id, Value &value);
	virtual bool IsSequence() const;
	virtual bool IsSequenceInf() const;
	Iterator *_Clone();
	virtual Iterator *Clone() const;
	bool Consume(Environment &env);
	Value ToList(Environment &env, bool alwaysListFlag, bool excludeNilFlag);
	Value Reduce(Environment &env, Value valueAccum, const Function *pFuncBlock);
	Value MinMax(Environment &env, bool maxFlag, const SymbolSet &attrs);
	Value Sum(Environment &env, size_t &cnt);
	Value Prod(Environment &env);
	Value Average(Environment &env, size_t &cnt);
	Value Variance(Environment &env, size_t &cnt);
	Value StandardDeviation(Environment &env, size_t &cnt);
	Value And(Environment &env);
	Value Or(Environment &env);
	size_t Find(Environment &env, const Value &criteria, Value &value);
	size_t FindTrue(Environment &env, Value &value);
	size_t Count(Environment &env, const Value &criteria);
	size_t CountTrue(Environment &env);
	Iterator *Filter(Environment &env, const Value &criteria);
	Iterator *While(Environment &env, const Value &criteria);
	Iterator *Since(Environment &env, const Value &criteria, bool containFirstFlag);
	Iterator *Until(Environment &env, const Value &criteria, bool containLastFlag);
	bool DoesContain(Environment &env, const Value &value);
	String Join(Environment &env, const char *sep);
	Binary Joinb(Environment &env);
	void PrintEach(Environment &env, Stream *pStream);
	void PrintfEach(Environment &env, Stream *pStream, const char *format);
	void PrintlnEach(Environment &env, Stream *pStream);
	virtual String ToString() const;
	static void SetError_InvalidDataTypeOfElement(Signal &sig);
	static void SetError_InfiniteNotAllowed(Signal &sig);
	virtual Iterator *GetSource() = 0;
	virtual bool DoNext(Environment &env, Value &value) = 0;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet) = 0;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
							const SymbolSet &attrs, bool &evaluatedFlag);
private:
	inline void operator=(const Iterator &iterator) {}
};

//-----------------------------------------------------------------------------
// IteratorList
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE IteratorList : public std::vector<Iterator *> {
public:
	inline IteratorList() {}
};

//-----------------------------------------------------------------------------
// IteratorOwner
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE IteratorOwner : public IteratorList {
public:
	inline IteratorOwner() {}
	IteratorOwner(const IteratorOwner &iterOwner);
	virtual ~IteratorOwner();
	bool Next(Environment &env, ValueList &valList);
	void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	bool IsInfinite() const;
	bool PrepareForMap(Signal &sig, const DeclarationList &declList, const ValueList &valListArg);
};

//-----------------------------------------------------------------------------
// IteratorDeque
//-----------------------------------------------------------------------------
typedef std::deque<Iterator *> IteratorDeque;

}

#endif
