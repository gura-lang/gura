#ifndef __GURA_OBJECT_LIST_H__
#define __GURA_OBJECT_LIST_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_list
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_list : public Class {
public:
	Class_list(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_list
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_list : public Object {
public:
	class IteratorEach : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		ValueList::const_iterator _pValue;
		ValueList::const_iterator _pValueEnd;
	public:
		inline IteratorEach(Object_list *pObj) :
			Iterator(false), _pObj(pObj),
			_pValue(pObj->GetList().begin()), _pValueEnd(pObj->GetList().end()) {}
		inline IteratorEach(Object_list *pObj, size_t offset) :
			Iterator(false), _pObj(pObj),
			_pValue((offset < pObj->GetList().size())?
					pObj->GetList().begin() + offset : pObj->GetList().end()),
			_pValueEnd(pObj->GetList().end()) {}
		inline IteratorEach(Object_list *pObj, size_t offset, size_t cnt) :
			Iterator(false), _pObj(pObj),
			_pValue((offset < pObj->GetList().size())?
					pObj->GetList().begin() + offset : pObj->GetList().end()),
			_pValueEnd((offset + cnt < pObj->GetList().size())?
					pObj->GetList().begin() + offset + cnt : pObj->GetList().end()) {}
		virtual ~IteratorEach();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorReverse : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		ValueList::reverse_iterator _pValue;
	public:
		inline IteratorReverse(Object_list *pObj) :
			Iterator(false), _pObj(pObj), _pValue(pObj->GetList().rbegin()) {}
		virtual ~IteratorReverse();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorRound : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		int _cnt;
		ValueList::iterator _pValue;
	public:
		inline IteratorRound(Object_list *pObj, int cnt) :
			Iterator(cnt < 0), _pObj(pObj), _pValue(pObj->GetList().begin()), _cnt(cnt) {}
		virtual ~IteratorRound();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorPingpong : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		int _cnt;
		bool _stickyFlagL, _stickyFlagR;
		bool _forwardFlag;
		ValueList::iterator _pValueFwd;
		ValueList::reverse_iterator _pValueBwd;
	public:
		inline IteratorPingpong(Object_list *pObj, int cnt, bool stickyFlagL, bool stickyFlagR) :
			Iterator(cnt < 0), _pObj(pObj), _cnt(cnt),
			_stickyFlagL(stickyFlagL), _stickyFlagR(stickyFlagR), _forwardFlag(true),
			_pValueFwd(pObj->GetList().begin()), _pValueBwd(pObj->GetList().rbegin()) {}
		virtual ~IteratorPingpong();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorFold : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		size_t _offset;
		size_t _cntPerFold;
		size_t _cntStep;
		bool _listItemFlag;
	public:
		IteratorFold(Object_list *pObj, size_t cntPerFold, size_t cntStep, bool listItemFlag);
		virtual ~IteratorFold();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorPermutation : public Iterator {
	public:
		typedef std::vector<size_t> IndexList;
	private:
		AutoPtr<Object_list> _pObj;
		IndexList _indexList;
		int _cnt;
		bool _validFlag;
	public:
		IteratorPermutation(Object_list *pObj, int cnt);
		~IteratorPermutation();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorCombination : public Iterator {
	public:
		typedef std::vector<size_t> IndexList;
	private:
		AutoPtr<Object_list> _pObj;
		IndexList _indexList;
		int _cnt;
		bool _validFlag;
	public:
		IteratorCombination(Object_list *pObj, int cnt);
		~IteratorCombination();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class Comparator_Ascend {
	public:
		inline bool operator()(const Value *pValue1, const Value *pValue2) const {
			return Value::Compare(*pValue1, *pValue2) < 0;
		}
	};
	class Comparator_Descend {
	public:
		inline bool operator()(const Value *pValue1, const Value *pValue2) const {
			return Value::Compare(*pValue1, *pValue2) > 0;
		}
	};
	class Comparator_Custom {
	private:
		Environment &_env;
		Signal &_sig;
		const Function *_pFunc;
	public:
		inline Comparator_Custom(Environment &env, Signal &sig, const Function *pFunc) :
										_env(env), _sig(sig), _pFunc(pFunc) {}
		bool operator()(const Value *pValue1, const Value *pValue2) const;
	};
public:
	Gura_DeclareObjectAccessor(list)
public:
	typedef std::vector<size_t> IndexList;
	class ValueVisitor_Index : public ValueVisitor {
	private:
		Environment &_env;
		Signal _sig;
		const ValueList &_valList;
		IndexList _indexList;
	public:
		inline ValueVisitor_Index(Environment &env, Signal sig, const ValueList &valList) :
									_env(env), _sig(sig), _valList(valList) {}
		virtual bool Visit(const Value &value);
		inline IndexList &GetIndexList() { return _indexList; }
	};
private:
	ValueList _valList;
public:
	inline Object_list(Class *pClass) : Object(pClass) {}
	inline Object_list(Environment &env) : Object(env.LookupClass(VTYPE_list)) {}
	inline Object_list(Environment &env, size_t n) : Object(env.LookupClass(VTYPE_list)) {
		_valList.reserve(n);
	}
	inline Object_list(Environment &env, size_t n, const Value &value) :
						Object(env.LookupClass(VTYPE_list)), _valList(n, value) {}
	inline Object_list(Environment &env, const ValueList &valList) :
						Object(env.LookupClass(VTYPE_list)), _valList(valList) {}
	inline Object_list(const Object_list &obj) :
									Object(obj), _valList(obj._valList) {}
	virtual Object *Clone() const;
	inline ValueList &GetList() { return _valList; }
	inline const ValueList &GetList() const { return _valList; }
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value);
	virtual Iterator *CreateIterator(Signal sig);
	virtual String ToString(Signal sig, bool exprFlag);
	Object_list *SortRank(Signal sig, const Value &valDirective,
					const ValueList *pValListKey, bool rankFlag, bool stableFlag);
};

}

#endif
