//----------------------------------------------------------------------------
// wxArchiveInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveInputStream
//----------------------------------------------------------------------------
Object_wx_ArchiveInputStream::~Object_wx_ArchiveInputStream()
{
}

Object *Object_wx_ArchiveInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveInputStream:");
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
// Method implementation
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Class implementation for wxArchiveInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveInputStream)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveInputStream)
{
	return new Object_wx_ArchiveInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
