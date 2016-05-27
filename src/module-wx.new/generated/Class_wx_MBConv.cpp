//----------------------------------------------------------------------------
// wxMBConv
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConv
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMBConv
//----------------------------------------------------------------------------
Object_wx_MBConv::~Object_wx_MBConv()
{
}

Object *Object_wx_MBConv::Clone() const
{
	return nullptr;
}

String Object_wx_MBConv::ToString(bool exprFlag)
{
	String rtn("<wx.MBConv:");
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
// Class implementation for wxMBConv
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConv)
{
}

Gura_ImplementDescendantCreator(wx_MBConv)
{
	return new Object_wx_MBConv((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
