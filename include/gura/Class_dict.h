//=============================================================================
// Gura class: dict
//=============================================================================
#ifndef __GURA_CLASS_DICT_H__
#define __GURA_CLASS_DICT_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_dict / Object_dict
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_dict : public Class {
public:
	Class_dict(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
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
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorValues : public Iterator {
	private:
		AutoPtr<Object_dict> _pObj;
		ValueDict::const_iterator _pCur;
	public:
		IteratorValues(Object_dict *pObj);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorItems : public Iterator {
	private:
		AutoPtr<Object_dict> _pObj;
		ValueDict::const_iterator _pCur;
	public:
		IteratorItems(Object_dict *pObj);
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
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
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
public:
	Gura_DeclareObjectAccessor(dict)
protected:
	AutoPtr<ValueDict> _pValDict;
public:
	inline Object_dict(Class *pClass, ValueDict *pValDict) :
					Object(pClass), _pValDict(pValDict) {}
	inline Object_dict(Environment &env, ValueDict *pValDict) :
					Object(env.LookupClass(VTYPE_dict)), _pValDict(pValDict) {}
	inline Object_dict(const Object_dict &obj) :
					Object(obj), _pValDict(new ValueDict(obj.GetDict())) {}
	virtual Object *Clone() const;
	inline ValueDict &GetDict() { return *_pValDict; }
	inline const ValueDict &GetDict() const { return *_pValDict; }
	inline bool GetIgnoreCaseFlag() const { return _pValDict->GetIgnoreCaseFlag(); }
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
	virtual Iterator *CreateIterator(Signal &sig);
	virtual String ToString(bool exprFlag);
	const Value *Find(Signal &sig, const Value &valueIdx) const;
	static void SetError_KeyNotFound(Signal &sig, const Value &valueIdx);
};

}

#endif
