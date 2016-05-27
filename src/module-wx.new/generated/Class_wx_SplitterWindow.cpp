//----------------------------------------------------------------------------
// wxSplitterWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSplitterWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSplitterWindow
//----------------------------------------------------------------------------
Object_wx_SplitterWindow::~Object_wx_SplitterWindow()
{
}

Object *Object_wx_SplitterWindow::Clone() const
{
	return nullptr;
}

String Object_wx_SplitterWindow::ToString(bool exprFlag)
{
	String rtn("<wx.SplitterWindow:");
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
// Class implementation for wxSplitterWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SplitterWindow)
{
}

Gura_ImplementDescendantCreator(wx_SplitterWindow)
{
	return new Object_wx_SplitterWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
