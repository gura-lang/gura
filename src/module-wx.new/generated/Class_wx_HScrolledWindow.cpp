//----------------------------------------------------------------------------
// wxHScrolledWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHScrolledWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHScrolledWindow
//----------------------------------------------------------------------------
Object_wx_HScrolledWindow::~Object_wx_HScrolledWindow()
{
}

Object *Object_wx_HScrolledWindow::Clone() const
{
	return nullptr;
}

String Object_wx_HScrolledWindow::ToString(bool exprFlag)
{
	String rtn("<wx.HScrolledWindow:");
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
// Class implementation for wxHScrolledWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HScrolledWindow)
{
}

Gura_ImplementDescendantCreator(wx_HScrolledWindow)
{
	return new Object_wx_HScrolledWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
