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
#include "Operator.h"
#include "PropHandler.h"

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
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl); \
	virtual bool CastTo(Environment &env, Value &value, const Declaration &decl); \
	virtual Object *CreateDescendant(Environment &env, Class *pClass); \
	virtual void Prepare(Environment &env);

#define Gura_DeclareUserClassEnd(name) \
};

#define Gura_DeclareUserClass(name) \
Gura_DeclareUserClassBegin(name) \
Gura_DeclareUserClassEnd(name)

#define Gura_ImplementUserClass(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = nullptr; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
bool Class_##name::CastFrom(Environment &env, Value &value, const Declaration *pDecl) { return false; } \
bool Class_##name::CastTo(Environment &env, Value &value, const Declaration &decl) { return false; } \
Object *Class_##name::CreateDescendant(Environment &env, Class *pClass) { return Class::CreateDescendant(env, pClass); } \
void Class_##name::Prepare(Environment &env)

#define Gura_ImplementUserClassWithCast(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = nullptr; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
Object *Class_##name::CreateDescendant(Environment &env, Class *pClass) { return Class::CreateDescendant(env, pClass); } \
void Class_##name::Prepare(Environment &env)

#define Gura_ImplementUserInheritableClass(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = nullptr; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
bool Class_##name::CastFrom(Environment &env, Value &value, const Declaration *pDecl) { return false; } \
bool Class_##name::CastTo(Environment &env, Value &value, const Declaration &decl) { return false; } \
void Class_##name::Prepare(Environment &env)

#define Gura_ImplementUserInheritableClassWithCast(name) \
ValueTypeInfo *Class_##name::_pValueTypeInfo = nullptr; \
ValueType VTYPE_##name = static_cast<ValueType>(0); \
void Class_##name::Prepare(Environment &env)

#define Gura_ImplementCastFrom(name) \
bool Class_##name::CastFrom(Environment &env, Value &value, const Declaration *pDecl)

#define Gura_ImplementCastTo(name) \
bool Class_##name::CastTo(Environment &env, Value &value, const Declaration &decl)

#define Gura_ImplementDescendantCreator(name) \
Object *Class_##name::CreateDescendant(Environment &env, Class *pClass)

#define Gura_RealizeUserClassAlias(name, str, pClassBase) do { \
	Class_##name::_pValueTypeInfo = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(Class_##name::_pValueTypeInfo); \
	VTYPE_##name = Class_##name::_pValueTypeInfo->GetValueType(); \
	Class_##name *pClass = new Class_##name(pClassBase, \
						Class_##name::_pValueTypeInfo->GetValueType()); \
	Class_##name::_pValueTypeInfo->SetClass(pClass); \
} while (0)

#define Gura_RealizeAndPrepareUserClassAlias(name, str, pClassBase) do { \
	Class_##name::_pValueTypeInfo = ValueTypePool::GetInstance()->Add(Symbol::Add(str)); \
	env.AssignValueType(Class_##name::_pValueTypeInfo); \
	VTYPE_##name = Class_##name::_pValueTypeInfo->GetValueType(); \
	Class_##name *pClass = new Class_##name(pClassBase, \
						Class_##name::_pValueTypeInfo->GetValueType()); \
	Class_##name::_pValueTypeInfo->SetClass(pClass); \
	pClass->Prepare(env); \
	pClass->DeriveOperators(); \
} while (0)

#define Gura_RealizeUserClass(name, pClassBase) \
Gura_RealizeUserClassAlias(name, #name, pClassBase)

#define Gura_RealizeAndPrepareUserClass(name, pClassBase) \
Gura_RealizeAndPrepareUserClassAlias(name, #name, pClassBase)

#define Gura_PrepareUserClass(name) do { \
	Gura_UserClass(name)->Prepare(env); \
	Gura_UserClass(name)->DeriveOperators(); \
} while (0)

#define Gura_DeclareObjectAccessorEx(T) \
inline static T *GetObject(const Value &value) { \
	return dynamic_cast<T *>(value.GetFundamental()); \
} \
inline static T *GetObject(Argument &arg, size_t idxArg) { \
	return dynamic_cast<T *>(arg.GetFundamental(idxArg)); \
} \
inline static T *GetObjectThis(Argument &arg) { \
	return arg.GetValueThis().IsObject()? \
			dynamic_cast<T *>(arg.GetValueThis().GetFundamental()) : nullptr; \
} \
inline static T *Reference(const T *pObj) { \
	return dynamic_cast<T *>(Object::Reference(pObj)); \
} \
inline T *Reference() const { return Reference(this); }

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
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Object");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
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
	virtual Value EmptyIndexGet(Environment &env);
	virtual void EmptyIndexSet(Environment &env, const Value &value);
	virtual Value IndexGet(Environment &env, const Value &valueIdx);
	virtual void IndexSet(Environment &env, const Value &valueIdx, const Value &value);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
					const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol,
					const Value &value, const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	bool DirProp(Environment &env, SymbolSet &symbols);
	Value EvalMethod(Environment &env, const Function *pFunc, const ValueList &valListArg);
	Value EvalMethod(Environment &env, const Symbol *pSymbol,
							const ValueList &valListArg, bool &evaluatedFlag);
};

//-----------------------------------------------------------------------------
// Class
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class : public Fundamental, public HelpProvider::Holder {
protected:
	AutoPtr<Class> _pClassSuper;
	ValueType _valType;
	const Symbol *_pSymbol;
	AutoPtr<Function> _pConstructor;
	Operator::EntryList _operatorEntryList;
	AutoPtr<HelpProvider> _pHelpProvider;
	std::unique_ptr<PropHandlerMap> _pPropHandlerMap;
public:
	Gura_DeclareReferenceAccessor(Class);
public:
	inline static void *operator new(size_t size) {
		return MemoryPool::Allocate(size, "Class");
	}
	inline static void operator delete(void *pv) {
		MemoryPool::Deallocate(pv);
	}
protected:
	inline Class(const Class &cls) : Fundamental(cls),
		_pClassSuper(Class::Reference(cls._pClassSuper.get())), _valType(cls._valType),
		_pSymbol(cls._pSymbol), _pConstructor(nullptr) {}
public:
	Class(Environment *pEnvOuter, ValueType valType);
	virtual ~Class();
	virtual bool IsClass() const;
	virtual bool IsCustom() const;
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
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
	inline const Operator::EntryList &GetOperatorEntryList() const { return _operatorEntryList; }
	inline HelpProvider &GetHelpProvider() { return *_pHelpProvider; }
	inline const HelpProvider &GetHelpProvider() const { return *_pHelpProvider; }
	inline void AddHelp(const Symbol *pSymbol, const String &doc) {
		_pHelpProvider->AddHelp(new Help(pSymbol, doc));
	}
	inline void AddHelpTemplate(Environment &env, const Symbol *pSymbol, const String &doc) {
		_pHelpProvider->AddHelpTemplate(env, pSymbol, doc);
	}
	bool DirProp(Environment &env, SymbolSet &symbols, bool escalateFlag);
	//virtual Value GetPropPrimitive(const Value &valueThis,
	//		const Symbol *pSymbol, const SymbolSet &attrs, bool &evaluatedFlag) const;
	virtual Value EmptyIndexGetPrimitive(Environment &env, const Value &valueThis) const;
	virtual Value IndexGetPrimitive(Environment &env,
									const Value &valueThis, const Value &valueIdx) const;
	virtual bool CastFrom(Environment &env, Value &value, const Declaration *pDecl);
	virtual bool CastTo(Environment &env, Value &value, const Declaration &decl);
	virtual String ToString(bool exprFlag);
	virtual Value DoCall(
		Environment &env, const CallerInfo &callerInfo,
		const Value &valueThis, const Iterator *pIteratorThis,
		const TrailCtrlHolder *pTrailCtrlHolder);
	virtual bool Serialize(Environment &env, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Stream &stream, Value &value) const;
	virtual bool Format_d(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_u(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_b(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_o(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_x(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_e(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_f(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_g(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_s(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	virtual bool Format_c(Formatter *pFormatter, Formatter::Flags &flags, const Value &value) const;
	void AddOperatorEntry(OperatorEntry *pOperatorEntry);
	void DeriveOperators();
	void AssignPropHandler(PropHandler *pPropHandler);
	const PropHandler *LookupPropHandler(const Symbol *pSymbol);
	bool BuildContent(Environment &env, const Value &valueThis,
		const Expr_Block *pExprBlock, const SymbolSet *pSymbolsAssignable = nullptr);
	void SetError_NoConstructor() const;
public:
	// inherited from HelpProvider
	virtual String MakeHelpTitle() const;
};

}

#endif
