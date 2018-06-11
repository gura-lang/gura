#ifndef __MTP_CLASS_STORAGE_H__
#define __MTP_CLASS_STORAGE_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Object_storage declaration
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(storage);

class Object_storage : public Object {
public:
	Gura_DeclareObjectAccessor(storage)
public:
	Object_storage();
	virtual String ToString(bool exprFlag);
};

Gura_EndModuleScope(mtp)

#endif
