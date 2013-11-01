#ifndef __GURA_CLASS_ARGS_H__
#define __GURA_CLASS_ARGS_H__

#include "Class.h"
#include "OAL.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_args : public Class {
public:
	Class_args(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_args : public Object {
private:
	AutoPtr<Args> _pArgs;
public:
	Gura_DeclareObjectAccessor(args)
public:
	inline Object_args(Environment &env, Args *pArgs) :
					Object(env.LookupClass(VTYPE_args)), _pArgs(pArgs) {}
	inline Object_args(Class *pClass, Args *pArgs) :
					Object(pClass), _pArgs(pArgs) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Args *GetArgs() { return _pArgs.get(); }
};

}

#endif
