#ifndef __GURA_OBJECT_H__
#define __GURA_OBJECT_H__

#include "Class.h"

#define Gura_DeclareObjectAccessorEx(T) \
inline static T *GetObject(const Value &value) { \
	return dynamic_cast<T *>(value.GetObject()); \
} \
inline static T *GetObject(Args &args, size_t idxArg) { \
	return dynamic_cast<T *>(args.GetObject(idxArg)); \
} \
inline static T *GetThisObj(Args &args) { \
	return dynamic_cast<T *>(args.GetThis().GetObject()); \
} \
inline static T *Reference(const T *pObj) { \
	return dynamic_cast<T *>(Object::Reference(pObj)); \
} \
inline T *Reference() const { return Reference(this); } \

#define Gura_DeclareObjectAccessor(name) \
Gura_DeclareObjectAccessorEx(Object_##name)

namespace Gura {

//-----------------------------------------------------------------------------
// Object
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object : public Fundamental {
protected:
	AutoPtr<Class> _pClass;
protected:
	inline Object(const Object &obj) :
			Fundamental(obj), _pClass(Class::Reference(obj._pClass.get())) {}
public:
	Object(Class *pClass);
protected:
	virtual ~Object();
public:
	Gura_DeclareReferenceAccessor(Object);
public:
	virtual Object *Clone() const;
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
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
					const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol,
					const Value &value, const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	bool DirProp(Environment &env, Signal sig, SymbolSet &symbols);
	Value EvalMethod(Environment &env, Signal sig, const Function *pFunc, const ValueList &valListArg);
	Value EvalMethod(Environment &env, Signal sig, const Symbol *pSymbol,
							const ValueList &valListArg, bool &evaluatedFlag);
};

}

#endif
