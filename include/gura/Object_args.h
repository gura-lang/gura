#ifndef __GURA_OBJECT_ARGS_H__
#define __GURA_OBJECT_ARGS_H__

#include "Object.h"
#include "OAL.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_args : public Class {
public:
	Class_args(Environment *pEnvOuter);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
	static void OnModuleEntry(Environment &env, Signal sig);
};

//-----------------------------------------------------------------------------
// Object_args
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_args : public Object {
private:
	SymbolSet _attrs;
public:
	Gura_DeclareObjectAccessor(args)
public:
	inline Object_args(Environment &env, const Args &args) :
			Object(env.LookupClass(VTYPE_args)), _attrs(args.GetAttrs()) {}
	inline Object_args(Class *pClass, const Args &args) :
			Object(pClass), _attrs(args.GetAttrs()) {}
	virtual ~Object_args();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	inline const SymbolSet &GetAttrs() const { return _attrs; }
};

}

#endif
