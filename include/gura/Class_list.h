//=============================================================================
// Gura class: list
//=============================================================================
#ifndef __GURA_CLASS_LIST_H__
#define __GURA_CLASS_LIST_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_list
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_list : public Class {
public:
	Class_list(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual bool CastFrom(Environment &env, Value &value, ULong flags);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
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
			Iterator(Finite), _pObj(pObj),
			_pValue(pObj->GetList().begin()), _pValueEnd(pObj->GetList().end()) {}
		inline IteratorEach(Object_list *pObj, size_t offset) :
			Iterator(Finite), _pObj(pObj),
			_pValue((offset < pObj->GetList().size())?
					pObj->GetList().begin() + offset : pObj->GetList().end()),
			_pValueEnd(pObj->GetList().end()) {}
		inline IteratorEach(Object_list *pObj, size_t offset, size_t cnt) :
			Iterator(Finite), _pObj(pObj),
			_pValue((offset < pObj->GetList().size())?
					pObj->GetList().begin() + offset : pObj->GetList().end()),
			_pValueEnd((offset + cnt < pObj->GetList().size())?
					pObj->GetList().begin() + offset + cnt : pObj->GetList().end()) {}
		virtual ~IteratorEach();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorReverse : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		ValueList::const_reverse_iterator _pValue;
	public:
		inline IteratorReverse(Object_list *pObj) :
			Iterator(Finite), _pObj(pObj), _pValue(pObj->GetList().rbegin()) {}
		virtual ~IteratorReverse();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorCycle : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		int _cnt;
		ValueList::const_iterator _pValue;
	public:
		inline IteratorCycle(Object_list *pObj, int cnt) :
			Iterator((cnt < 0)? Infinite : Finite), _pObj(pObj), _cnt(cnt), _pValue(pObj->GetList().begin()) {}
		virtual ~IteratorCycle();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorPingpong : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		int _cnt;
		bool _stickyFlagTop, _stickyFlagBtm;
		bool _forwardFlag;
		ValueList::const_iterator _pValueFwd;
		ValueList::const_reverse_iterator _pValueBwd;
	public:
		inline IteratorPingpong(Object_list *pObj, int cnt, bool stickyFlagTop, bool stickyFlagBtm) :
			Iterator((cnt < 0)? Infinite : Finite), _pObj(pObj), _cnt(cnt),
			_stickyFlagTop(stickyFlagTop), _stickyFlagBtm(stickyFlagBtm), _forwardFlag(true),
			_pValueFwd(pObj->GetList().begin()), _pValueBwd(pObj->GetList().rbegin()) {}
		virtual ~IteratorPingpong();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorFold : public Iterator {
	private:
		AutoPtr<Object_list> _pObj;
		size_t _offset;
		size_t _cntPerFold;
		size_t _cntStep;
		bool _listItemFlag;
		bool _neatFlag;
		bool _doneFlag;
	public:
		IteratorFold(Object_list *pObj, size_t cntPerFold,
					 size_t cntStep, bool listItemFlag, bool neatFlag);
		virtual ~IteratorFold();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
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
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
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
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class Comparator_Ascend {
	private:
		Environment &_env;
	public:
		inline Comparator_Ascend(Environment &env) : _env(env) {}
		inline bool operator()(const Value *pValue1, const Value *pValue2) const {
			return Value::Compare(_env, *pValue1, *pValue2) < 0;
		}
	};
	class Comparator_Descend {
	private:
		Environment &_env;
	public:
		inline Comparator_Descend(Environment &env) : _env(env) {}
		inline bool operator()(const Value *pValue1, const Value *pValue2) const {
			return Value::Compare(_env, *pValue1, *pValue2) > 0;
		}
	};
	class Comparator_Custom {
	private:
		Environment &_env;
		const Function *_pFunc;
	public:
		inline Comparator_Custom(Environment &env, const Function *pFunc) :
										_env(env), _pFunc(pFunc) {}
		bool operator()(const Value *pValue1, const Value *pValue2) const;
	};
public:
	Gura_DeclareObjectAccessor(list)
public:
	typedef std::vector<size_t> IndexList;
	class ValueVisitor_Index : public ValueVisitor {
	private:
		Environment &_env;
		const ValueList &_valList;
		IndexList _indexList;
	public:
		inline ValueVisitor_Index(Environment &env, const ValueList &valList) :
									_env(env), _valList(valList) {}
		virtual bool Visit(const Value &value);
		inline IndexList &GetIndexList() { return _indexList; }
	};
private:
	ValueList _valList;
	ValueType _valType;
public:
	inline Object_list(Class *pClass) :
		Object(pClass), _valType(VTYPE_undefined) {}
	inline Object_list(Environment &env) :
		Object(env.LookupClass(VTYPE_list)), _valType(VTYPE_undefined) {}
	inline Object_list(Environment &env, size_t n) :
		Object(env.LookupClass(VTYPE_list)), _valType(VTYPE_undefined) {
		_valList.reserve(n);
	}
	inline Object_list(Environment &env, size_t n, const Value &value) :
		Object(env.LookupClass(VTYPE_list)), _valList(n, value), _valType(value.GetValueType()) {}
	inline Object_list(Environment &env, const ValueList &valList) :
		Object(env.LookupClass(VTYPE_list)),
		_valList(valList), _valType(valList.GetValueTypeOfElements()) {}
	inline Object_list(const Object_list &obj) :
		Object(obj), _valList(obj._valList), _valType(obj._valType) {}
	virtual Object *Clone() const;
	inline const ValueList &GetList() const { return _valList; }
	inline ValueList &GetListForModify() { return _valList; }
	inline void SetValueType(ValueType valType) { _valType = valType; }
	inline ValueType GetValueType() const {
		return _valList.empty()? VTYPE_undefined : _valType;
	}
	inline size_t Size() const { return _valList.size(); }
	inline bool Empty() const { return _valList.empty(); }
	inline void Reserve(size_t n) { _valList.reserve(n); }
	inline void Clear() {
		_valList.clear();
		_valType = VTYPE_undefined;
	}
	inline void Add(const Value &value) {
		_valList.push_back(value);
		UpdateValueType(value);
	}
	inline void AddFast(const Value &value) {
		_valList.push_back(value);
	}
	inline void AddUndefined() {
		_valList.push_back(Value::Undefined);
		_valType = VTYPE_any;
	}
	inline void UpdateValueType(const Value &value) {
		ValueType valTypeAdded = value.GetValueType();
		if (_valType == VTYPE_undefined) {
			_valType = valTypeAdded;
		} else if (_valType != valTypeAdded) {
			_valType = VTYPE_any;
		}
	}
	inline void DetermineValueType() {
		_valType = _valList.GetValueTypeOfElements();
	}
	inline void Insert(size_t idx, const Value &value) {
		_valList.insert(_valList.begin() + idx, value);
		UpdateValueType(value);
	}
	inline void Erase(size_t idx) {
		_valList.erase(_valList.begin() + idx);
		if (_valList.empty()) _valType = VTYPE_undefined;
	}
	inline void EraseFast(size_t idx) {
		_valList.erase(_valList.begin() + idx);
	}
	inline bool Serialize(Environment &env, Stream &stream) const {
		return _valList.Serialize(env, stream);
	}
	inline bool Deserialize(Environment &env, Stream &stream) {
		return _valList.Deserialize(env, stream);
	}
#if NEW_INDEXING
	virtual Value IndexGet(Environment &env, const ValueList &valListIdx);
	Value IndexGetSub(Environment &env, const ValueList &valListIdx);
	const Value &IndexGet_Element(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const ValueList &valListIdx, const Value &value);
	void IndexSet_Element(Environment &env, const Value &valueIdx, const Value &value);
#else
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
#endif
	virtual Iterator *CreateIterator(Signal &sig);
	virtual String ToString(bool exprFlag);
	bool ValidateAndCast(Environment &env, const Declaration *pDecl, bool listElemFlag);
	Object_list *SortRank(Signal &sig, const Value &valDirective,
					const ValueList *pValListKey, bool rankFlag, bool stableFlag);
};

}

#endif
