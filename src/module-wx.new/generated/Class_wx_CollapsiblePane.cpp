//----------------------------------------------------------------------------
// wxCollapsiblePane
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCollapsiblePane
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCollapsiblePane
//----------------------------------------------------------------------------
Object_wx_CollapsiblePane::~Object_wx_CollapsiblePane()
{
}

Object *Object_wx_CollapsiblePane::Clone() const
{
	return nullptr;
}

String Object_wx_CollapsiblePane::ToString(bool exprFlag)
{
	String rtn("<wx.CollapsiblePane:");
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
// Class implementation for wxCollapsiblePane
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CollapsiblePane)
{
}

Gura_ImplementDescendantCreator(wx_CollapsiblePane)
{
	return new Object_wx_CollapsiblePane((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
