//----------------------------------------------------------------------------
// wxAuiNotebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAuiNotebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAuiNotebook
//----------------------------------------------------------------------------
Object_wx_AuiNotebook::~Object_wx_AuiNotebook()
{
}

Object *Object_wx_AuiNotebook::Clone() const
{
	return nullptr;
}

String Object_wx_AuiNotebook::ToString(bool exprFlag)
{
	String rtn("<wx.AuiNotebook:");
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
// Class implementation for wxAuiNotebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AuiNotebook)
{
}

Gura_ImplementDescendantCreator(wx_AuiNotebook)
{
	return new Object_wx_AuiNotebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
