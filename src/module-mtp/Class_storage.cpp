#include "stdafx.h"

Gura_BeginModuleScope(mtp)

//-----------------------------------------------------------------------------
// Object_storage implementation
//-----------------------------------------------------------------------------
Object_storage::Object_storage(Storage *pStorage) : Object(Gura_UserClass(storage)), _pStorage(pStorage)
{
}

String Object_storage::ToString(bool exprFlag)
{
	return String("<mtp.storage>");
}

//-----------------------------------------------------------------------------
// Gura interfaces for mtp.storage
//-----------------------------------------------------------------------------
// implementation of class storage
Gura_ImplementUserClass(storage)
{
	// Assignment of value
	Gura_AssignValue(storage, Value(Reference()));
}

Gura_EndModuleScope(mtp)
