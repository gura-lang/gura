//----------------------------------------------------------------------------
// wxMDIChildFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMDIChildFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMDIChildFrame
//----------------------------------------------------------------------------
Object_wx_MDIChildFrame::~Object_wx_MDIChildFrame()
{
}

Object *Object_wx_MDIChildFrame::Clone() const
{
	return nullptr;
}

String Object_wx_MDIChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.MDIChildFrame:");
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
// Class implementation for wxMDIChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MDIChildFrame)
{
}

Gura_ImplementDescendantCreator(wx_MDIChildFrame)
{
	return new Object_wx_MDIChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
