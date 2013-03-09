#ifndef __GURA_CLASS_H__
#define __GURA_CLASS_H__

#include "Common.h"
#include "Environment.h"
#include "Function.h"
#include "Iterator.h"
#include "Fundamental.h"

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
protected:
	inline Class(const Class &cls) : Fundamental(cls),
		_pClassSuper(Class::Reference(cls._pClassSuper.get())), _valType(cls._valType),
		_pSymbol(cls._pSymbol), _pConstructor(NULL) {}
public:
	Class(Environment *pEnvOuter, ValueType valType);
	virtual ~Class();
	virtual bool IsClass() const;
	virtual bool IsCustom() const;
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
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
	bool DirProp(Signal sig, SymbolSet &symbols, bool escalateFlag);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool CastTo(Environment &env, Signal sig, Value &value, const Declaration &decl);
	virtual String ToString(Signal sig, bool exprFlag);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

//-----------------------------------------------------------------------------
// Class_nil
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_nil : public Class {
public:
	Class_nil(Environment *pEnvOuter);
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
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual bool Serialize(Environment &env, Signal sig, Stream &stream, const Value &value) const;
	virtual bool Deserialize(Environment &env, Signal sig, Stream &stream, Value &value) const;
};

}

#endif
