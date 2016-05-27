//----------------------------------------------------------------------------
// wxAuiSimpleTabArt
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiSimpleTabArt
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiSimpleTabArt
//----------------------------------------------------------------------------
Object_wx_AuiSimpleTabArt::~Object_wx_AuiSimpleTabArt()
{
}

Object *Object_wx_AuiSimpleTabArt::Clone() const
{
	return nullptr;
}

String Object_wx_AuiSimpleTabArt::ToString(bool exprFlag)
{
	String rtn("<wx.AuiSimpleTabArt:");
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
// Class implementation for wxAuiSimpleTabArt
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiSimpleTabArt)
{
}

Gura_ImplementDescendantCreator(wx_AuiSimpleTabArt)
{
	return new Object_wx_AuiSimpleTabArt((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
