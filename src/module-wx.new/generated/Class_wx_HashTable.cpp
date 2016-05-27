//----------------------------------------------------------------------------
// wxHashTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHashTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHashTable
//----------------------------------------------------------------------------
Object_wx_HashTable::~Object_wx_HashTable()
{
}

Object *Object_wx_HashTable::Clone() const
{
	return nullptr;
}

String Object_wx_HashTable::ToString(bool exprFlag)
{
	String rtn("<wx.HashTable:");
	if (GetEntity() == nullptr) {
		rtn += "invalid>";
	} else {
		char buff[64];
		::sprintf(buff, "%p>", GetEntity());
		rtn += buff;
	}
	return rtn;
}

//----------------------------------------------------------------------------
// Class implementation for wxHashTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashTable)
{
}

Gura_ImplementDescendantCreator(wx_HashTable)
{
	return new Object_wx_HashTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
