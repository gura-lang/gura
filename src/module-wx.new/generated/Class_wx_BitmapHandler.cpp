//----------------------------------------------------------------------------
// wxBitmapHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBitmapHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBitmapHandler
//----------------------------------------------------------------------------
Object_wx_BitmapHandler::~Object_wx_BitmapHandler()
{
}

Object *Object_wx_BitmapHandler::Clone() const
{
	return nullptr;
}

String Object_wx_BitmapHandler::ToString(bool exprFlag)
{
	String rtn("<wx.BitmapHandler:");
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
// Class implementation for wxBitmapHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BitmapHandler)
{
}

Gura_ImplementDescendantCreator(wx_BitmapHandler)
{
	return new Object_wx_BitmapHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
