//----------------------------------------------------------------------------
// wxTarEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTarEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarEntry
//----------------------------------------------------------------------------
Object_wx_TarEntry::~Object_wx_TarEntry()
{
}

Object *Object_wx_TarEntry::Clone() const
{
	return nullptr;
}

String Object_wx_TarEntry::ToString(bool exprFlag)
{
	String rtn("<wx.TarEntry:");
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
// Class implementation for wxTarEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarEntry)
{
}

Gura_ImplementDescendantCreator(wx_TarEntry)
{
	return new Object_wx_TarEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
