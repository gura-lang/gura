//=============================================================================
// Gura class: argument
//=============================================================================
#ifndef __GURA_CLASS_ARGUMENT_H__
#define __GURA_CLASS_ARGUMENT_H__

#include "Class.h"
#include "OAL.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_argument
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_argument : public Class {
public:
	Class_argument(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_argument
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_argument : public Object {
private:
	AutoPtr<Argument> _pArg;
public:
	Gura_DeclareObjectAccessor(argument)
public:
	inline Object_argument(Environment &env, Argument *pArg) :
					Object(env.LookupClass(VTYPE_argument)), _pArg(pArg) {}
	inline Object_argument(Class *pClass, Argument *pArg) :
					Object(pClass), _pArg(pArg) {}
	virtual Object *Clone() const;
	virtual bool DoDirProp(Environment &env, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, const Symbol *pSymbol,
								const SymbolSet &attrs, bool &evaluatedFlag);
	virtual String ToString(bool exprFlag);
	inline Argument *GetArgument() { return _pArg.get(); }
};

}

#endif
