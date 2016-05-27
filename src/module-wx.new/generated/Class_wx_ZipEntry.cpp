//----------------------------------------------------------------------------
// wxZipEntry
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxZipEntry
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxZipEntry
//----------------------------------------------------------------------------
Object_wx_ZipEntry::~Object_wx_ZipEntry()
{
}

Object *Object_wx_ZipEntry::Clone() const
{
	return nullptr;
}

String Object_wx_ZipEntry::ToString(bool exprFlag)
{
	String rtn("<wx.ZipEntry:");
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
// Class implementation for wxZipEntry
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ZipEntry)
{
}

Gura_ImplementDescendantCreator(wx_ZipEntry)
{
	return new Object_wx_ZipEntry((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
