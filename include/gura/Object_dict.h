#ifndef __GURA_OBJECT_DICT_H__
#define __GURA_OBJECT_DICT_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_dict / Object_dict
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_dict : public Class {
public:
	Class_dict(Environment *pEnvOuter);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void DoAssignConstructor(Environment &env, Signal sig);
};

class GURA_DLLDECLARE Object_dict : public Object {
public:
	class IteratorKeys : public Iterator {
	private:
		AutoPtr<Object_dict> _pObj;
		ValueDict::const_iterator _pCur;
	public:
		IteratorKeys(Object_dict *pObj);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorValues : public Iterator {
	private:
		AutoPtr<Object_dict> _pObj;
		ValueDict::const_iterator _pCur;
	public:
		IteratorValues(Object_dict *pObj);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorItems : public Iterator {
	private:
		AutoPtr<Object_dict> _pObj;
		ValueDict::const_iterator _pCur;
	public:
		IteratorItems(Object_dict *pObj);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorGet : public Iterator {
	private:
		AutoPtr<Object_dict> _pObj;
		AutoPtr<Iterator> _pIteratorKey;
		Value _valDefault;
		bool _raiseFlag;
		bool _setDefaultFlag;
	public:
		IteratorGet(Object_dict *pObj, Iterator *pIteratorKey,
					const Value &valDefault, bool raiseFlag, bool setDefaultFlag);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Signal sig, Value &value);
		virtual String ToString(Signal sig) const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareObjectAccessor(dict)
protected:
	ValueDict _valDict;
	bool _ignoreCaseFlag;
public:
	inline Object_dict(Class *pClass, bool ignoreCaseFlag) : Object(pClass),
		_valDict(ignoreCaseFlag? Value::KeyCompareIgnoreCase : Value::KeyCompareCase),
		_ignoreCaseFlag(ignoreCaseFlag) {}
	inline Object_dict(Environment &env, bool ignoreCaseFlag) : Object(env.LookupClass(VTYPE_dict)),
		_valDict(ignoreCaseFlag? Value::KeyCompareIgnoreCase : Value::KeyCompareCase),
		_ignoreCaseFlag(ignoreCaseFlag) {}
	inline Object_dict(const Object_dict &obj) : Object(obj),
		_valDict(obj._valDict), _ignoreCaseFlag(obj._ignoreCaseFlag) {}
	virtual Object *Clone() const;
	inline ValueDict &GetDict() { return _valDict; }
	inline const ValueDict &GetDict() const { return _valDict; }
	inline bool GetIgnoreCaseFlag() const { return _ignoreCaseFlag; }
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value);
	virtual Iterator *CreateIterator(Signal sig);
	virtual String ToString(Signal sig, bool exprFlag);
	const Value *Find(Signal sig, const Value &valueIdx) const;
	static void SetError_KeyNotFound(Signal sig, const Value &valueIdx);
};

}

#endif
