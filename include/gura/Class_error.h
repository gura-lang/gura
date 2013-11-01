#ifndef __GURA_CLASS_ERROR_H__
#define __GURA_CLASS_ERROR_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_error / Object_error
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_error : public Class {
public:
	Class_error(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

class GURA_DLLDECLARE Object_error : public Object {
public:
	Gura_DeclareObjectAccessor(error)
private:
	Gura::Error _err;
public:
	inline Object_error(Environment &env, const Gura::Error &err) :
					Object(env.LookupClass(VTYPE_error)), _err(err) {}
	inline Object_error(Class *pClass, const Gura::Error &err) :
					Object(pClass), _err(err) {}
	Object_error(const Object_error &obj);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	virtual bool DoDirProp(Environment &env, Signal sig, SymbolSet &symbols);
	virtual Value DoGetProp(Environment &env, Signal sig, const Symbol *pSymbol,
							const SymbolSet &attrs, bool &evaluatedFlag);
	inline const Gura::Error &GetError() const { return _err; }
};

}

#endif
