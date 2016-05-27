//----------------------------------------------------------------------------
// wxArchiveFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArchiveFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArchiveFSHandler
//----------------------------------------------------------------------------
Object_wx_ArchiveFSHandler::~Object_wx_ArchiveFSHandler()
{
}

Object *Object_wx_ArchiveFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_ArchiveFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.ArchiveFSHandler:");
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
// Class implementation for wxArchiveFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArchiveFSHandler)
{
}

Gura_ImplementDescendantCreator(wx_ArchiveFSHandler)
{
	return new Object_wx_ArchiveFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
