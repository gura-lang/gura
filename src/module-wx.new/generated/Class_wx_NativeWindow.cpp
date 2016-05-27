//----------------------------------------------------------------------------
// wxNativeWindow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNativeWindow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNativeWindow
//----------------------------------------------------------------------------
Object_wx_NativeWindow::~Object_wx_NativeWindow()
{
}

Object *Object_wx_NativeWindow::Clone() const
{
	return nullptr;
}

String Object_wx_NativeWindow::ToString(bool exprFlag)
{
	String rtn("<wx.NativeWindow:");
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
// Class implementation for wxNativeWindow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NativeWindow)
{
}

Gura_ImplementDescendantCreator(wx_NativeWindow)
{
	return new Object_wx_NativeWindow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
