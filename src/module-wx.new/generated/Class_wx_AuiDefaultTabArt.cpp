//----------------------------------------------------------------------------
// wxAuiDefaultTabArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiDefaultTabArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiDefaultTabArt
//----------------------------------------------------------------------------
Object_wx_AuiDefaultTabArt::~Object_wx_AuiDefaultTabArt()
{
}

Object *Object_wx_AuiDefaultTabArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiDefaultTabArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiDefaultTabArt:");
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
// Class implementation for wxAuiDefaultTabArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiDefaultTabArt)
{
}

Gura_ImplementDescendantCreator(wx_AuiDefaultTabArt)
{
	return new Object_wx_AuiDefaultTabArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
