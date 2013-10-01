#ifndef __GURA_OBJECT_ENVIRONMENT_H__
#define __GURA_OBJECT_ENVIRONMENT_H__

#include "Object.h"
#include "Environment.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_environment / Object_environment
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_environment : public Class {
public:
	Class_environment(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

class GURA_DLLDECLARE Object_environment : public Object {
public:
	Gura_DeclareObjectAccessor(environment)
private:
	AutoPtr<Environment> _pEnv;
public:
	inline Object_environment(Environment &env) :
			Object(env.LookupClass(VTYPE_environment)), _pEnv(new Environment(env)) {}
	inline Object_environment(Class *pClass, Environment &env) :
						Object(pClass), _pEnv(new Environment(env)) {}
	Object_environment(const Object_environment &obj);
	inline Environment &GetEnv() { return *_pEnv; }
	virtual ~Object_environment();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Environment &env, Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
