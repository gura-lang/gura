//----------------------------------------------------------------------------
// wxFileSystem
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystem
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileSystem
//----------------------------------------------------------------------------
Object_wx_FileSystem::~Object_wx_FileSystem()
{
}

Object *Object_wx_FileSystem::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystem::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystem:");
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
// Class implementation for wxFileSystem
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystem)
{
}

Gura_ImplementDescendantCreator(wx_FileSystem)
{
	return new Object_wx_FileSystem((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
