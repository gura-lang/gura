#ifndef __GURA_OBJECTOFSTRUCT_H__
#define __GURA_OBJECTOFSTRUCT_H__

#include "Object.h"

namespace Gura {

//-----------------------------------------------------------------------------
// ClassOfStruct / ObjectOfStruct
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE ClassOfStruct : public Class {
public:
	ClassOfStruct(Environment *pEnvOuter);
	virtual void Prepare(Environment &env);
	virtual bool CastFrom(Environment &env, Signal sig, Value &value, const Declaration *pDecl);
	virtual Object *CreateDescendant(Environment &env, Signal sig, Class *pClass);
};

class GURA_DLLDECLARE ObjectOfStruct : public Object {
public:
	Gura_DeclareObjectAccessorEx(ObjectOfStruct)
public:
	inline ObjectOfStruct(Class *pClass) : Object(pClass) {}
	inline ObjectOfStruct(Environment &env) : Object(env.LookupClass(VTYPE_Struct)) {}
	ObjectOfStruct(const ObjectOfStruct &obj);
	virtual ~ObjectOfStruct();
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	const DeclarationList &GetDeclList() const;
};

}

#endif
