//----------------------------------------------------------------------------
// wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
Object_wx_FileSystemWatcherEvent::~Object_wx_FileSystemWatcherEvent()
{
}

Object *Object_wx_FileSystemWatcherEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystemWatcherEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystemWatcherEvent:");
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
// Class implementation for wxFileSystemWatcherEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemWatcherEvent)
{
}

Gura_ImplementDescendantCreator(wx_FileSystemWatcherEvent)
{
	return new Object_wx_FileSystemWatcherEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
