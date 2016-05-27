//----------------------------------------------------------------------------
// wxSashLayoutWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSashLayoutWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Object_wx_SashLayoutWindow::~Object_wx_SashLayoutWindow()
{
}

Object *Object_wx_SashLayoutWindow::Clone() const
{
	return nullptr;
}

String Object_wx_SashLayoutWindow::ToString(bool exprFlag)
{
	String rtn("<wx.SashLayoutWindow:");
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
// Class implementation for wxSashLayoutWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SashLayoutWindow)
{
}

Gura_ImplementDescendantCreator(wx_SashLayoutWindow)
{
	return new Object_wx_SashLayoutWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
