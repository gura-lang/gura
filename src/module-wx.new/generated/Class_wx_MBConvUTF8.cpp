//----------------------------------------------------------------------------
// wxMBConvUTF8
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF8
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMBConvUTF8
//----------------------------------------------------------------------------
Object_wx_MBConvUTF8::~Object_wx_MBConvUTF8()
{
}

Object *Object_wx_MBConvUTF8::Clone() const
{
	return nullptr;
}

String Object_wx_MBConvUTF8::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvUTF8:");
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
// Class implementation for wxMBConvUTF8
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF8)
{
	// Class assignment
	Gura_AssignValueEx("MBConvUTF8", Reference());
}

Gura_ImplementDescendantCreator(wx_MBConvUTF8)
{
	return new Object_wx_MBConvUTF8((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
