//=============================================================================
// Gura class: dict
//=============================================================================
#ifndef __GURA_CLASS_DICT_H__
#define __GURA_CLASS_DICT_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_dict
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_dict : public ClassFundamental {
public:
	Class_dict(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual SerializeFmtVer GetSerializeFmtVer() const;
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value, SerializeFmtVer serializeFmtVer) const;
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_dict
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_dict : public Object {
public:
	class IteratorEx : public Iterator {
	protected:
		AutoPtr<Object_dict> _pObj;
		bool _validFlag;
	public:
		IteratorEx(Finiteness finiteness, Object_dict *pObj) :
					Iterator(finiteness), _pObj(pObj), _validFlag(true) {}
		inline void Invalidate() { _validFlag = false; }
	};
	class IteratorKeys : public IteratorEx {
	private:
		ValueDict::const_iterator _pCur;
	public:
		IteratorKeys(Object_dict *pObj);
		~IteratorKeys();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorValues : public IteratorEx {
	private:
		ValueDict::const_iterator _pCur;
	public:
		IteratorValues(Object_dict *pObj);
		~IteratorValues();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	class IteratorItems : public IteratorEx {
	private:
		ValueDict::const_iterator _pCur;
	public:
		IteratorItems(Object_dict *pObj);
		~IteratorItems();
		virtual Iterator *GetSource();
		virtual bool DoNext(Environment &env, Value &value);
		virtual String ToString() const;
		virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	};
	typedef std::vector<IteratorEx *> IteratorExList;
public:
	Gura_DeclareObjectAccessor(dict)
protected:
	AutoPtr<ValueDict> _pValDict;
	IteratorExList _iterList;
	bool _writableFlag;
public:
	inline Object_dict(Class *pClass, ValueDict *pValDict, bool writableFlag) :
		Object(pClass), _pValDict(pValDict), _writableFlag(writableFlag) {}
	inline Object_dict(Environment &env, ValueDict *pValDict, bool writableFlag) :
		Object(env.LookupClass(VTYPE_dict)), _pValDict(pValDict), _writableFlag(writableFlag) {}
	inline Object_dict(const Object_dict &obj) :
		Object(obj), _pValDict(new ValueDict(obj.GetDict())), _writableFlag(obj._writableFlag) {}
	virtual Object *Clone() const;
	inline void AddIterator(IteratorEx *pIterator) { _iterList.push_back(pIterator); }
	inline void RemoveIterator(IteratorEx *pIterator) {
		_iterList.erase(std::find(_iterList.begin(), _iterList.end(), pIterator));
	}
	inline ValueDict &GetDict() { return *_pValDict; }
	inline const ValueDict &GetDict() const { return *_pValDict; }
	inline bool GetIgnoreCaseFlag() const { return _pValDict->GetIgnoreCaseFlag(); }
	inline bool IsWritable() const { return _writableFlag; }
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
	virtual Iterator *CreateIterator(Signal &sig);
	virtual String ToString(bool exprFlag);
	const Value *Find(Signal &sig, const Value &valueIdx) const;
	void InvalidateIterators();
	static void SetError_KeyNotFound(Signal &sig, const Value &valueIdx);
};

}

#endif
