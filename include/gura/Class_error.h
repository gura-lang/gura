//=============================================================================
// Gura class: error
//=============================================================================
#ifndef __GURA_CLASS_ERROR_H__
#define __GURA_CLASS_ERROR_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_error
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_error : public Class {
public:
	Class_error(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_error
//-----------------------------------------------------------------------------
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
	inline const Gura::Error &GetError() const { return _err; }
};

}

#endif
