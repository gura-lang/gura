//----------------------------------------------------------------------------
// wxCSConv
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCSConv
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCSConv
//----------------------------------------------------------------------------
Object_wx_CSConv::~Object_wx_CSConv()
{
}

Object *Object_wx_CSConv::Clone() const
{
	return nullptr;
}

String Object_wx_CSConv::ToString(bool exprFlag)
{
	String rtn("<wx.CSConv:");
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
// Class implementation for wxCSConv
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CSConv)
{
}

Gura_ImplementDescendantCreator(wx_CSConv)
{
	return new Object_wx_CSConv((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
