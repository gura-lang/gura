//=============================================================================
// Gura class: propdeclaration
//=============================================================================
#ifndef __GURA_CLASS_PROPDECLARATION_H__
#define __GURA_CLASS_PROPDECLARATION_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_propdeclaration
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_propdeclaration : public Class {
public:
	Class_propdeclaration(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_propdeclaration
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_propdeclaration : public Object {
public:
	Gura_DeclareObjectAccessor(propdeclaration)
private:
	AutoPtr<PropDeclaration> _pPropDeclaration;
public:
	inline Object_propdeclaration(Class *pClass, PropDeclaration *pPropDeclaration) :
		Object(pClass), _pPropDeclaration(pPropDeclaration) {}
	inline Object_propdeclaration(Environment &env, PropDeclaration *pPropDeclaration) :
		Object(env.LookupClass(VTYPE_propdeclaration)), _pPropDeclaration(pPropDeclaration) {}
	Object_propdeclaration(const Object_propdeclaration &obj);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline const PropDeclaration *GetPropDeclaration() const { return _pPropDeclaration.get(); }
};

}

#endif
