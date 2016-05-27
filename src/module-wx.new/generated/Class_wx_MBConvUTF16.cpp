//----------------------------------------------------------------------------
// wxMBConvUTF16
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF16
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMBConvUTF16
//----------------------------------------------------------------------------
Object_wx_MBConvUTF16::~Object_wx_MBConvUTF16()
{
}

Object *Object_wx_MBConvUTF16::Clone() const
{
	return nullptr;
}

String Object_wx_MBConvUTF16::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvUTF16:");
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
// Class implementation for wxMBConvUTF16
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF16)
{
}

Gura_ImplementDescendantCreator(wx_MBConvUTF16)
{
	return new Object_wx_MBConvUTF16((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
