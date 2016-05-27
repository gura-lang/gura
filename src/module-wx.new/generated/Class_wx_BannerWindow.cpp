//----------------------------------------------------------------------------
// wxBannerWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBannerWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBannerWindow
//----------------------------------------------------------------------------
Object_wx_BannerWindow::~Object_wx_BannerWindow()
{
}

Object *Object_wx_BannerWindow::Clone() const
{
	return nullptr;
}

String Object_wx_BannerWindow::ToString(bool exprFlag)
{
	String rtn("<wx.BannerWindow:");
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
// Class implementation for wxBannerWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BannerWindow)
{
}

Gura_ImplementDescendantCreator(wx_BannerWindow)
{
	return new Object_wx_BannerWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
