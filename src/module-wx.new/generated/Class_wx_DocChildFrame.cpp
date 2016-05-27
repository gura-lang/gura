//----------------------------------------------------------------------------
// wxDocChildFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocChildFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocChildFrame
//----------------------------------------------------------------------------
Object_wx_DocChildFrame::~Object_wx_DocChildFrame()
{
}

Object *Object_wx_DocChildFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocChildFrame:");
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
// Class implementation for wxDocChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocChildFrame)
{
}

Gura_ImplementDescendantCreator(wx_DocChildFrame)
{
	return new Object_wx_DocChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
