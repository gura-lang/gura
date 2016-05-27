//----------------------------------------------------------------------------
// wxTaskBarButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTaskBarButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTaskBarButton
//----------------------------------------------------------------------------
Object_wx_TaskBarButton::~Object_wx_TaskBarButton()
{
}

Object *Object_wx_TaskBarButton::Clone() const
{
	return nullptr;
}

String Object_wx_TaskBarButton::ToString(bool exprFlag)
{
	String rtn("<wx.TaskBarButton:");
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
// Class implementation for wxTaskBarButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TaskBarButton)
{
}

Gura_ImplementDescendantCreator(wx_TaskBarButton)
{
	return new Object_wx_TaskBarButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
