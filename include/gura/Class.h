#ifndef __GURA_CLASS_H__
#define __GURA_CLASS_H__

#include "Common.h"
#include "Environment.h"
#include "Function.h"
#include "Iterator.h"
#include "Fundamental.h"

//-----------------------------------------------------------------------------
// macros
//-----------------------------------------------------------------------------
#define Gura_UserClass(name) \
(Class_##name::_pValueTypeInfo->GetClass())

#define Gura_ImplementClass(name) \
Class_##name::Class_##name(Environment *pEnvOuter) : Class(pEnvOuter)

#define Gura_DeclareUserClass(name) \
class GURA_DLLEXPORT Class_##name : public Class { \
public: \
	inline Class_##name(Environment *pEnvOuter, ValueType valType) : Class(pEnvOuter, valType) {} \
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl); \
	virtual bool CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl); \
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass); \
	virtual void Prepare(Environment &env); \
public: \
	static ValueTypeInfo *_pValueTypeInfo; \
}; \
GURA_DLLEXPORT extern ValueType VTYPE_##name;

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
	pClass->Prepare(env); \
} while (0)

#define Gura_RealizeUserClassExWithoutPrepare(name, str, pClassBase) do { \
	Class_##name::_pValueTypeInfo = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(Class_##name::_pValueTypeInfo); \
	VTYPE_##name = Class_##name::_pValueTypeInfo->GetValueType(); \
	Class_##name *pClass = new Class_##name(pClassBase, \
						Class_##name::_pValueTypeInfo->GetValueType()); \
	Class_##name::_pValueTypeInfo->SetClass(pClass); \
} while (0)

#define Gura_RealizeUserClass(name, pClassBase) \
Gura_RealizeUserClassEx(name, #name, pClassBase)

#define Gura_RealizeUserClassWithoutPrepare(name, pClassBase) \
Gura_RealizeUserClassExWithoutPrepare(name, #name, pClassBase)

namespace Gura {

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
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
	bool BuildContent(Environment &env, Signal sig, const Value &valueThis,
		const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable = NULL);
};

//-----------------------------------------------------------------------------
// Class_nil
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_nil : public Class {
public:
	Class_nil(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_undefined
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_undefined : public Class {
public:
	Class_undefined(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_symbol
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_symbol : public Class {
public:
	Class_symbol(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_boolean
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_boolean : public Class {
public:
	Class_boolean(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_number
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_number : public Class {
public:
	Class_number(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_complex
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_complex : public Class {
public:
	Class_complex(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Value GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
			const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_fraction
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_fraction : public Class {
public:
	Class_fraction(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Value GetPropPrimitive(Environment &env, Signal sig, const Value &valueThis,
			const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_quote
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_quote : public Class {
public:
	Class_quote(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_any
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_any : public Class {
public:
	Class_any(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

}

#endif
