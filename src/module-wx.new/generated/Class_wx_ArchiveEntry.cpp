//----------------------------------------------------------------------------
// wxArchiveEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveEntry
//----------------------------------------------------------------------------
Object_wx_ArchiveEntry::~Object_wx_ArchiveEntry()
{
}

Object *Object_wx_ArchiveEntry::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveEntry::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveEntry:");
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
// Class implementation for wxArchiveEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveEntry)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveEntry)
{
	return new Object_wx_ArchiveEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
