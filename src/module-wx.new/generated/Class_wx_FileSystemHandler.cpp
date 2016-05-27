//----------------------------------------------------------------------------
// wxFileSystemHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileSystemHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Object_wx_FileSystemHandler::~Object_wx_FileSystemHandler()
{
}

Object *Object_wx_FileSystemHandler::Clone() const
{
	return nullptr;
}

String Object_wx_FileSystemHandler::ToString(bool exprFlag)
{
	String rtn("<wx.FileSystemHandler:");
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
// Class implementation for wxFileSystemHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileSystemHandler)
{
}

Gura_ImplementDescendantCreator(wx_FileSystemHandler)
{
	return new Object_wx_FileSystemHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
