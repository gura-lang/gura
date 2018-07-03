//=============================================================================
// Gura class: mtp.storage
//=============================================================================
#ifndef __GURA_MODULE_MTP_CLASS_STORAGE_H__
#define __GURA_MODULE_MTP_CLASS_STORAGE_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Declaration of Object_storage
//-----------------------------------------------------------------------------
Gura_DeclareUserClass(storage);

class Object_storage : public Object {
private:
	AutoPtr<Storage> _pStorage;
public:
	Gura_DeclareObjectAccessor(storage)
public:
	Object_storage(Storage *pStorage);
	virtual String ToString(bool exprFlag);
	inline Storage *GetStorage() { return _pStorage.get(); }
	inline const Storage *GetStorage() const { return _pStorage.get(); }
};

Gura_EndModuleScope(mtp)

#endif
