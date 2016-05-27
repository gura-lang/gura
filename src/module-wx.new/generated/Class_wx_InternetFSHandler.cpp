//----------------------------------------------------------------------------
// wxInternetFSHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInternetFSHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInternetFSHandler
//----------------------------------------------------------------------------
Object_wx_InternetFSHandler::~Object_wx_InternetFSHandler()
{
}

Object *Object_wx_InternetFSHandler::Clone() const
{
	return nullptr;
}

String Object_wx_InternetFSHandler::ToString(bool exprFlag)
{
	String rtn("<wx.InternetFSHandler:");
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
// Class implementation for wxInternetFSHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_InternetFSHandler)
{
}

Gura_ImplementDescendantCreator(wx_InternetFSHandler)
{
	return new Object_wx_InternetFSHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
