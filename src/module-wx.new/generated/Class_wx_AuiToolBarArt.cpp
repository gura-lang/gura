//----------------------------------------------------------------------------
// wxAuiToolBarArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiToolBarArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiToolBarArt
//----------------------------------------------------------------------------
Object_wx_AuiToolBarArt::~Object_wx_AuiToolBarArt()
{
}

Object *Object_wx_AuiToolBarArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiToolBarArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiToolBarArt:");
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
// Class implementation for wxAuiToolBarArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiToolBarArt)
{
}

Gura_ImplementDescendantCreator(wx_AuiToolBarArt)
{
	return new Object_wx_AuiToolBarArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
