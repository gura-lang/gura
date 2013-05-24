#ifndef __GURA_STRUCTOBJECT_H__
#define __GURA_STRUCTOBJECT_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// StructClass / StructObject
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE StructClass : public Class {
public:
	StructClass(Environment *pEnvOuter);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

class GURA_DLLDECLARE StructObject : public Object {
public:
	Gura_DeclareObjectAccessorEx(StructObject)
public:
	inline StructObject(Class *pClass) : Object(pClass) {}
	inline StructObject(Environment &env) : Object(env.LookupClass(VTYPE_Struct)) {}
	StructObject(const StructObject &obj);
	virtual ~StructObject();
	virtual Object *Clone() const;
	virtual String ToString(Signal sig, bool exprFlag);
	const DeclarationList &GetDeclList() const;
};

}

#endif
