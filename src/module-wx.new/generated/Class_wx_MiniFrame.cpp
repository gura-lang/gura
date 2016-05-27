//----------------------------------------------------------------------------
// wxMiniFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMiniFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMiniFrame
//----------------------------------------------------------------------------
Object_wx_MiniFrame::~Object_wx_MiniFrame()
{
}

Object *Object_wx_MiniFrame::Clone() const
{
	return nullptr;
}

String Object_wx_MiniFrame::ToString(bool exprFlag)
{
	String rtn("<wx.MiniFrame:");
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
// Class implementation for wxMiniFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MiniFrame)
{
}

Gura_ImplementDescendantCreator(wx_MiniFrame)
{
	return new Object_wx_MiniFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
