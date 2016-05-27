//----------------------------------------------------------------------------
// wxMsgCatalog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMsgCatalog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMsgCatalog
//----------------------------------------------------------------------------
Object_wx_MsgCatalog::~Object_wx_MsgCatalog()
{
}

Object *Object_wx_MsgCatalog::Clone() const
{
	return nullptr;
}

String Object_wx_MsgCatalog::ToString(bool exprFlag)
{
	String rtn("<wx.MsgCatalog:");
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
// Class implementation for wxMsgCatalog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MsgCatalog)
{
}

Gura_ImplementDescendantCreator(wx_MsgCatalog)
{
	return new Object_wx_MsgCatalog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
