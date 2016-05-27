//----------------------------------------------------------------------------
// wxVScrolledWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVScrolledWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVScrolledWindow
//----------------------------------------------------------------------------
Object_wx_VScrolledWindow::~Object_wx_VScrolledWindow()
{
}

Object *Object_wx_VScrolledWindow::Clone() const
{
	return nullptr;
}

String Object_wx_VScrolledWindow::ToString(bool exprFlag)
{
	String rtn("<wx.VScrolledWindow:");
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
// Class implementation for wxVScrolledWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VScrolledWindow)
{
}

Gura_ImplementDescendantCreator(wx_VScrolledWindow)
{
	return new Object_wx_VScrolledWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
