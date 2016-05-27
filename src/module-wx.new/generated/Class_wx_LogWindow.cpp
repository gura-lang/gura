//----------------------------------------------------------------------------
// wxLogWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogWindow
//----------------------------------------------------------------------------
Object_wx_LogWindow::~Object_wx_LogWindow()
{
}

Object *Object_wx_LogWindow::Clone() const
{
	return nullptr;
}

String Object_wx_LogWindow::ToString(bool exprFlag)
{
	String rtn("<wx.LogWindow:");
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
// Class implementation for wxLogWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogWindow)
{
}

Gura_ImplementDescendantCreator(wx_LogWindow)
{
	return new Object_wx_LogWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
