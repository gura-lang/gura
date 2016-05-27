//----------------------------------------------------------------------------
// wxMBConvUTF32
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF32
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMBConvUTF32
//----------------------------------------------------------------------------
Object_wx_MBConvUTF32::~Object_wx_MBConvUTF32()
{
}

Object *Object_wx_MBConvUTF32::Clone() const
{
	return nullptr;
}

String Object_wx_MBConvUTF32::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvUTF32:");
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
// Class implementation for wxMBConvUTF32
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF32)
{
}

Gura_ImplementDescendantCreator(wx_MBConvUTF32)
{
	return new Object_wx_MBConvUTF32((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
