//----------------------------------------------------------------------------
// wxRect
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRect
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRect
//----------------------------------------------------------------------------
Object_wx_Rect::~Object_wx_Rect()
{
}

Object *Object_wx_Rect::Clone() const
{
	return nullptr;
}

String Object_wx_Rect::ToString(bool exprFlag)
{
	String rtn("<wx.Rect:");
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
// Class implementation for wxRect
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Rect)
{
}

Gura_ImplementDescendantCreator(wx_Rect)
{
	return new Object_wx_Rect((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
