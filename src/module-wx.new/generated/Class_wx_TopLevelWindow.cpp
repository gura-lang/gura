//----------------------------------------------------------------------------
// wxTopLevelWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTopLevelWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTopLevelWindow
//----------------------------------------------------------------------------
Object_wx_TopLevelWindow::~Object_wx_TopLevelWindow()
{
}

Object *Object_wx_TopLevelWindow::Clone() const
{
	return nullptr;
}

String Object_wx_TopLevelWindow::ToString(bool exprFlag)
{
	String rtn("<wx.TopLevelWindow:");
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
// Class implementation for wxTopLevelWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TopLevelWindow)
{
}

Gura_ImplementDescendantCreator(wx_TopLevelWindow)
{
	return new Object_wx_TopLevelWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
