//----------------------------------------------------------------------------
// wxThumbBarButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxThumbBarButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxThumbBarButton
//----------------------------------------------------------------------------
Object_wx_ThumbBarButton::~Object_wx_ThumbBarButton()
{
}

Object *Object_wx_ThumbBarButton::Clone() const
{
	return nullptr;
}

String Object_wx_ThumbBarButton::ToString(bool exprFlag)
{
	String rtn("<wx.ThumbBarButton:");
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
// Class implementation for wxThumbBarButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThumbBarButton)
{
}

Gura_ImplementDescendantCreator(wx_ThumbBarButton)
{
	return new Object_wx_ThumbBarButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
