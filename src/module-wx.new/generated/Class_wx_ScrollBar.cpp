//----------------------------------------------------------------------------
// wxScrollBar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScrollBar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScrollBar
//----------------------------------------------------------------------------
Object_wx_ScrollBar::~Object_wx_ScrollBar()
{
}

Object *Object_wx_ScrollBar::Clone() const
{
	return nullptr;
}

String Object_wx_ScrollBar::ToString(bool exprFlag)
{
	String rtn("<wx.ScrollBar:");
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
// Class implementation for wxScrollBar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScrollBar)
{
}

Gura_ImplementDescendantCreator(wx_ScrollBar)
{
	return new Object_wx_ScrollBar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
