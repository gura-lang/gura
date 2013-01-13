#ifndef __GURA_OBJECT_H__
#define __GURA_OBJECT_H__

#include "Common.h"
#include "Environment.h"
#include "Function.h"
#include "Iterator.h"

#define Gura_DeclareObjectAccessorEx(T) \
inline static T *GetObject(const Value &value) { \
	return dynamic_cast<T *>(value.GetObj()); \
} \
inline static T *GetObject(Args &args, size_t idxArg) { \
	return dynamic_cast<T *>(args.GetObj(idxArg)); \
} \
inline static T *GetSelfObj(Args &args) { \
	return dynamic_cast<T *>(args.GetSelf().GetObj()); \
} \
inline static T *Reference(const T *pObj) { \
	return dynamic_cast<T *>(Object::Reference(pObj)); \
}

#define Gura_DeclareObjectAccessor(name) \
Gura_DeclareObjectAccessorEx(Object_##name)

namespace Gura {

//-----------------------------------------------------------------------------
// ObjectBase
//-----------------------------------------------------------------------------
class DLLDECLARE ObjectBase : public Environment, public ICallable {
protected:
	int _cntRef;
protected:
	inline ObjectBase(const ObjectBase &obj) :
							Environment(obj), _cntRef(obj._cntRef) {}
	ObjectBase(Environment *pEnvOuter, EnvType envType);
public:
	virtual ~ObjectBase();
	bool BuildContent(Environment &env, Signal sig, const Value &valueSelf,
		const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable = NULL);
	inline int DecRef() { if (_cntRef > 0) _cntRef--; return _cntRef; }
	inline int GetRefCnt() const { return _cntRef; }
	virtual bool IsFunction() const;
	virtual Iterator *CreateIterator(Signal sig);
	virtual bool DoPropDir(Signal sig, SymbolSet &symbols);
	virtual Value DoCall(Environment &env, Signal sig, Args &args);
	virtual String ToString(Signal sig, bool exprFlag) = 0;
	virtual void GatherFollower(Environment::Frame *pFrame, EnvironmentSet &envSet);
	inline bool PropDir(Signal sig, SymbolSet &symbols) {
		return DoPropDir(sig, symbols);
	}
};

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------
class DLLDECLARE Class : public ObjectBase {
protected:
	AutoPtr<Class> _pClassSuper;
	ValueType _valType;
	const Symbol *_pSymbol;
	AutoPtr<Function> _pConstructor;
protected:
	inline Class(const Class &cls) : ObjectBase(cls),
		_pClassSuper(Class::Reference(cls._pClassSuper.get())), _valType(cls._valType),
		_pSymbol(cls._pSymbol), _pConstructor(NULL) {}
public:
	Class(Environment *pEnvOuter, ValueType valType);
	virtual ~Class();
	virtual bool IsClass() const;
	virtual bool IsCustom() const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	virtual bool DoPropDir(Signal sig, SymbolSet &symbols);
	virtual void Prepare();
	inline Class *IncRef() { _cntRef++; return this; }
	inline static Class *Reference(const Class *pClass) {
		if (pClass == NULL) return NULL;
		Class *pClassCasted = const_cast<Class *>(pClass);
		pClassCasted->_cntRef++;
		return pClassCasted;
	}
	inline static void Delete(Class *pClass) {
		if (pClass != NULL && pClass->DecRef() <= 0) delete pClass;
	}
	inline bool IsAnonymous() const {
		return _pSymbol->IsIdentical(Gura_Symbol(_anonymous_));
	}
	inline void SetSymbol(const Symbol *pSymbol) { _pSymbol = pSymbol; }
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline void SetValueType(ValueType valType) { _valType = valType; }
	inline ValueType GetValueType() const { return _valType; }
	inline Class *GetClassSuper() { return _pClassSuper.get(); }
	inline const Class *GetClassSuper() const { return _pClassSuper.get(); }
	inline void SetConstructor(Function *pConstructor) {
		_pConstructor.reset(pConstructor);
	}
	inline Function *GetConstructor() { return _pConstructor.get(); }
	inline const Function *GetConstructor() const { return _pConstructor.get(); }
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl);
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool Serialize(Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_nil
//-----------------------------------------------------------------------------
class DLLDECLARE Class_nil : public Class {
public:
	Class_nil(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
};

//-----------------------------------------------------------------------------
// Class_symbol
//-----------------------------------------------------------------------------
class DLLDECLARE Class_symbol : public Class {
public:
	Class_symbol(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
};

//-----------------------------------------------------------------------------
// Class_boolean
//-----------------------------------------------------------------------------
class DLLDECLARE Class_boolean : public Class {
public:
	Class_boolean(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
};

//-----------------------------------------------------------------------------
// Class_number
//-----------------------------------------------------------------------------
class DLLDECLARE Class_number : public Class {
public:
	Class_number(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
};

//-----------------------------------------------------------------------------
// Class_complex
//-----------------------------------------------------------------------------
class DLLDECLARE Class_complex : public Class {
public:
	Class_complex(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
};

//-----------------------------------------------------------------------------
// Object
//-----------------------------------------------------------------------------
class DLLDECLARE Object : public ObjectBase {
protected:
	AutoPtr<Class> _pClass;
protected:
	inline Object(const Object &obj) :
			ObjectBase(obj), _pClass(Class::Reference(obj._pClass.get())) {}
public:
	Object(Class *pClass);
protected:
	virtual ~Object();
public:
	virtual Object *Clone() const;
	inline static Object *Reference(const Object *pObj) {
		if (pObj == NULL) return NULL;
		Object *pObjCasted = const_cast<Object *>(pObj);
		pObjCasted->_cntRef++;
		return pObjCasted;
	}
	static void Delete(Object *pObj);
	virtual bool IsObject() const;
	inline Class *GetClass() { return _pClass.get(); }
	inline const Class *GetClass() const { return _pClass.get(); }
	inline void SetClass(Class *pClass) { _pClass.reset(pClass); }
	const char *GetClassName() const;
	bool IsInstanceOf(ValueType valType) const;
	inline ValueType GetValueType() const { return _pClass->GetValueType(); }
	virtual int Compare(const Object *pObj) const;
	virtual Value EmptyIndexGet(Environment &env, Signal sig);
	virtual void EmptyIndexSet(Environment &env, Signal sig, const Value &value);
	virtual Value IndexGet(Environment &env, Signal sig, const Value &valueIdx);
	virtual void IndexSet(Environment &env, Signal sig, const Value &valueIdx, const Value &value);
	virtual bool DoPropDir(Signal sig, SymbolSet &symbols);
	virtual Value DoPropGet(Signal sig,
				const Symbol *pSymbol, bool &evaluatedFlag);
	virtual Value DoPropSet(Signal sig,
				const Symbol *pSymbol, const Value &value, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool DoSerialize(Signal sig, Stream &stream) const;
	virtual bool DoDeserialize(Signal sig, Stream &stream);
	Value EvalMethod(Signal sig, const Function *pFunc, const ValueList &valListArg);
	Value EvalMethod(Signal sig, const Symbol *pSymbol,
							const ValueList &valListArg, bool &evaluatedFlag);
};

}

#endif
