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
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

class GURA_DLLDECLARE Object_environment : public Object {
public:
	Gura_DeclareObjectAccessor(environment)
private:
	Environment _env;
public:
	inline Object_environment(Environment &env) :
						Object(env.LookupClass(VTYPE_environment)), _env(env) {}
	inline Object_environment(Class *pClass, Environment &env) :
						Object(pClass), _env(env) {}
	Object_environment(const Object_environment &obj);
	inline Environment &GetEnv() { return _env; }
	virtual ~Object_environment();
	virtual Object *Clone() const;
	virtual bool DoDirProp(Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual Value DoSetProp(Signal sig, const Symbol *pSymbol, const Value &value,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(Signal sig, bool exprFlag);
};

}

#endif
