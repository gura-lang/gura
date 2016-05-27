//----------------------------------------------------------------------------
// wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
Object_wx_AuiDefaultToolBarArt::~Object_wx_AuiDefaultToolBarArt()
{
}

Object *Object_wx_AuiDefaultToolBarArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiDefaultToolBarArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiDefaultToolBarArt:");
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
// Class implementation for wxAuiDefaultToolBarArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiDefaultToolBarArt)
{
}

Gura_ImplementDescendantCreator(wx_AuiDefaultToolBarArt)
{
	return new Object_wx_AuiDefaultToolBarArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
