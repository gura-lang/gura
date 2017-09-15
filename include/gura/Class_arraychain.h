//=============================================================================
// Gura class: arraychain
//=============================================================================
#ifndef __GURA_CLASS_ARRAYCHAIN_H__
#define __GURA_CLASS_ARRAYCHAIN_H__

#include "Class.h"

namespace Gura {

//-----------------------------------------------------------------------------
// Class_arraychain
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Class_arraychain : public ClassFundamental {
public:
	Class_arraychain(Environment *pEnvOuter);
	virtual void DoPrepare(Environment &env);
	virtual Object *CreateDescendant(Environment &env, Class *pClass);
};

//-----------------------------------------------------------------------------
// Object_arraychain
//-----------------------------------------------------------------------------
class GURA_DLLDECLARE Object_arraychain : public Object {
protected:
	AutoPtr<ArrayChain> _pArrayChain;
public:
	Gura_DeclareObjectAccessor(arraychain)
public:
	Object_arraychain(Environment &env, ArrayChain *pArrayChain);
	Object_arraychain(Class *pClass, ArrayChain *pArrayChain);
	virtual Object *Clone() const;
	virtual String ToString(bool exprFlag);
	inline ArrayChain *GetArrayChain() { return _pArrayChain.get(); }
	inline const ArrayChain *GetArrayChain() const { return _pArrayChain.get(); }
};

}

#endif
