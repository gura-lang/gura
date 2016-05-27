//----------------------------------------------------------------------------
// wxWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxWindow
//----------------------------------------------------------------------------
Object_wx_Window::~Object_wx_Window()
{
}

Object *Object_wx_Window::Clone() const
{
	return nullptr;
}

String Object_wx_Window::ToString(bool exprFlag)
{
	String rtn("<wx.Window:");
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
// Class implementation for wxWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Window)
{
}

Gura_ImplementDescendantCreator(wx_Window)
{
	return new Object_wx_Window((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
