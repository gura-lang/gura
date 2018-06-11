#ifndef __MTP_CLASS_STORAGE_H__
#define __MTP_CLASS_STORAGE_H__
#include <gura.h>

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Storage
//-----------------------------------------------------------------------------
class Storage {
private:
	int _cntRef;
public:
	Gura_DeclareReferenceAccessor(Storage);
public:
	inline Storage() : _cntRef(1) {}
protected:
	inline ~Storage() {}
};

//-----------------------------------------------------------------------------
// Object_storage declaration
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
};

Gura_EndModuleScope(mtp)

#endif
