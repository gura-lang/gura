//=============================================================================
// Gura class: environment
//=============================================================================
#ifndef __GURA_CLASS_ENVIRONMENT_H__
#define __GURA_CLASS_ENVIRONMENT_H__

#include "Class.h"
#include "Environment.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_environment
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_environment : public ClassFundamental {
public:
	Class_environment(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_environment
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_environment : public Object {
public:
	Gura_DeclareObjectAccessor(environment)
private:
	AutoPtr<Environment> _pEnv;
public:
	inline Object_environment(Environment &env) :
		Object(env.LookupClass(VTYPE_environment)), _pEnv(env.Clone()) {}
	inline Object_environment(Class *pClass, Environment &env) :
		Object(pClass), _pEnv(env.Clone()) {}
	Object_environment(const Object_environment &obj);
	inline Environment &GetEnv() { return *_pEnv; }
	virtual ~Object_environment();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
};

}

#endif
