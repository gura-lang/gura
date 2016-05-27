//----------------------------------------------------------------------------
// wxFileSystemWatcher
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystemWatcher
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileSystemWatcher
//----------------------------------------------------------------------------
Object_wx_FileSystemWatcher::~Object_wx_FileSystemWatcher()
{
}

Object *Object_wx_FileSystemWatcher::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystemWatcher::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystemWatcher:");
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
// Class implementation for wxFileSystemWatcher
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemWatcher)
{
}

Gura_ImplementDescendantCreator(wx_FileSystemWatcher)
{
	return new Object_wx_FileSystemWatcher((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
