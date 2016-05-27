//----------------------------------------------------------------------------
// wxMemoryFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMemoryFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMemoryFSHandler
//----------------------------------------------------------------------------
Object_wx_MemoryFSHandler::~Object_wx_MemoryFSHandler()
{
}

Object *Object_wx_MemoryFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_MemoryFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.MemoryFSHandler:");
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
// Class implementation for wxMemoryFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MemoryFSHandler)
{
}

Gura_ImplementDescendantCreator(wx_MemoryFSHandler)
{
	return new Object_wx_MemoryFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
