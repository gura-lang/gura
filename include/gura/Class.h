//=============================================================================
// Class
//=============================================================================
#ifndef __GURA_CLASS_H__
#define __GURA_CLASS_H__

#include "Common.h"
#include "Environment.h"
#include "Function.h"
#include "Iterator.h"
#include "Fundamental.h"
#include "Formatter.h"

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------
#define Gura_ClassName(name) Class_##name

#define Gura_UserClass(name) \
(Class_##name::_pValueTypeInfo->GetClass())

#define Gura_ImplementClass(name) \
Class_##name::Class_##name(Environment *pEnvOuter) : Class(pEnvOuter)

#define Gura_DeclareUserClassBegin(name) \
GURA_DLLEXPORT extern ValueType VTYPE_##name; \
class GURA_DLLEXPORT Class_##name : public Class { \
public: \
	static ValueTypeInfo *_pValueTypeInfo; \
public: \
	inline Class_##name(Environment *pEnvOuter, ValueType valType) : Class(pEnvOuter, valType) {} \
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl); \
	virtual bool CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl); \
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass); \
	virtual void Prepare(Environment &env);

#define Gura_DeclareUserClassEnd(name) \
};

#define Gura_DeclareUserClass(name) \
Gura_DeclareUserClassBegin(name) \
Gura_DeclareUserClassEnd(name)

#define Gura_ImplementUserClass(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = NULL; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
bool Class_##name::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl) { return false; } \
bool Class_##name::CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl) { return false; } \
Object *Class_##name::CreateDescendant(Environment &env, Signal sig, Class *pClass) { return Class::CreateDescendant(env, sig, pClass); } \
void Class_##name::Prepare(Environment &env)

#define Gura_ImplementUserClassWithCast(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = NULL; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
Object *Class_##name::CreateDescendant(Environment &env, Signal sig, Class *pClass) { return Class::CreateDescendant(env, sig, pClass); } \
void Class_##name::Prepare(Environment &env)

#define Gura_ImplementUserInheritableClass(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = NULL; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
bool Class_##name::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl) { return false; } \
bool Class_##name::CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl) { return false; } \
void Class_##name::Prepare(Environment &env)

#define Gura_ImplementUserInheritableClassWithCast(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = NULL; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
void Class_##name::Prepare(Environment &env)

#define Gura_ImplementCastFrom(name) \
bool Class_##name::CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl)

#define Gura_ImplementCastTo(name) \
bool Class_##name::CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl)

#define Gura_ImplementDescendantCreator(name) \
Object *Class_##name::CreateDescendant(Environment &env, Signal sig, Class *pClass)

#define Gura_RealizeUserClassEx(name, str, pClassBase) do { \
	Class_##name::_pValueTypeInfo = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(Class_##name::_pValueTypeInfo); \
	VTYPE_##name = Class_##name::_pValueTypeInfo->GetValueType(); \
	Class_##name *pClass = new Class_##name(pClassBase, \
						Class_##name::_pValueTypeInfo->GetValueType()); \
	Class_##name::_pValueTypeInfo->SetClass(pClass); \
} while (0)

#define Gura_RealizeAndPrepareUserClassEx(name, str, pClassBase) do { \
	Class_##name::_pValueTypeInfo = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(Class_##name::_pValueTypeInfo); \
	VTYPE_##name = Class_##name::_pValueTypeInfo->GetValueType(); \
	Class_##name *pClass = new Class_##name(pClassBase, \
						Class_##name::_pValueTypeInfo->GetValueType()); \
	Class_##name::_pValueTypeInfo->SetClass(pClass); \
	pClass->Prepare(env); \
} while (0)

#define Gura_RealizeUserClass(name, pClassBase) \
Gura_RealizeUserClassEx(name, #name, pClassBase)

#define Gura_RealizeAndPrepareUserClass(name, pClassBase) \
Gura_RealizeAndPrepareUserClassEx(name, #name, pClassBase)

#define Gura_PrepareUserClass(name) \
Gura_UserClass(name)->Prepare(env);

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

class Class;

//-----------------------------------------------------------------------------
// Object
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object : public Fundamental {
protected:
	AutoPtr<Class> _pClass;
protected:
	Object(const Object &obj);
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

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class : public Fundamental {
protected:
	AutoPtr<Class> _pClassSuper;
	ValueType _valType;
	const Symbol *_pSymbol;
	AutoPtr<Function> _pConstructor;
public:
	Gura_DeclareReferenceAccessor(Class);
protected:
	inline Class(const Class &cls) : Fundamental(cls),
		_pClassSuper(Class::Reference(cls._pClassSuper.get())), _valType(cls._valType),
		_pSymbol(cls._pSymbol), _pConstructor(NULL) {}
public:
	Class(Environment *pEnvOuter, ValueType valType);
	virtual bool IsClass() const;
	virtual bool IsCustom() const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	virtual void Prepare(Environment &env);
	inline bool IsAnonymous() const {
		return _pSymbol->IsIdentical(Gura_Symbol(_anonymous_));
	}
	inline void SetSymbol(const Symbol *pSymbol) { _pSymbol = pSymbol; }
	inline const char *GetName() const { return _pSymbol->GetName(); }
	inline void SetValueType(ValueType valType) { _valType = valType; }
	inline ValueType GetValueType() const { return _valType; }
	inline ValueTypeInfo *GetValueTypeInfo() const {
		return ValueTypePool::GetInstance()->Lookup(_valType);
	}
	inline String MakeValueTypeName() const {
		return ValueTypePool::GetInstance()->Lookup(_valType)->MakeFullName();
	}
	inline Class *GetClassSuper() { return _pClassSuper.get(); }
	inline const Class *GetClassSuper() const { return _pClassSuper.get(); }
	inline void SetConstructor(Function *pConstructor) {
		_pConstructor.reset(pConstructor);
	}
	inline Function *GetConstructor() { return _pConstructor.get(); }
	inline const Function *GetConstructor() const { return _pConstructor.get(); }
	bool DirProp(Environment &env, Signal sig, SymbolSet &symbols, bool escalateFlag);
	virtual Value GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
			const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual Value EmptyIndexGetPrimitive(Environment &env, Signal sig, const Value &valueThis) const;
	virtual Value IndexGetPrimitive(Environment &env, Signal sig,
									const Value &valueThis, const Value &valueIdx) const;
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl);
	virtual String ToString(bool exprFlag);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	virtual bool Format_d(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_e(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_s(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_c(Signal sig, Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	bool BuildContent(Environment &env, Signal sig, const Value &valueThis,
		const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable = NULL);
};

}

#endif
