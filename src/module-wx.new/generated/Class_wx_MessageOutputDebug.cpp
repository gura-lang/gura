//----------------------------------------------------------------------------
// wxMessageOutputDebug
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageOutputDebug
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageOutputDebug
//----------------------------------------------------------------------------
Object_wx_MessageOutputDebug::~Object_wx_MessageOutputDebug()
{
}

Object *Object_wx_MessageOutputDebug::Clone() const
{
	return nullptr;
}

String Object_wx_MessageOutputDebug::ToString(bool exprFlag)
{
	String rtn("<wx.MessageOutputDebug:");
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
// Class implementation for wxMessageOutputDebug
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageOutputDebug)
{
}

Gura_ImplementDescendantCreator(wx_MessageOutputDebug)
{
	return new Object_wx_MessageOutputDebug((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
