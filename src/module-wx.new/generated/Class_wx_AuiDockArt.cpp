//----------------------------------------------------------------------------
// wxAuiDockArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiDockArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiDockArt
//----------------------------------------------------------------------------
Object_wx_AuiDockArt::~Object_wx_AuiDockArt()
{
}

Object *Object_wx_AuiDockArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiDockArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiDockArt:");
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
// Class implementation for wxAuiDockArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiDockArt)
{
}

Gura_ImplementDescendantCreator(wx_AuiDockArt)
{
	return new Object_wx_AuiDockArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
