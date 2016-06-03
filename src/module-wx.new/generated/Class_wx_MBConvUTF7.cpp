//----------------------------------------------------------------------------
// wxMBConvUTF7
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMBConvUTF7
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMBConvUTF7
//----------------------------------------------------------------------------
Object_wx_MBConvUTF7::~Object_wx_MBConvUTF7()
{
}

Object *Object_wx_MBConvUTF7::Clone() const
{
	return nullptr;
}

String Object_wx_MBConvUTF7::ToString(bool exprFlag)
{
	String rtn("<wx.MBConvUTF7:");
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
// Class implementation for wxMBConvUTF7
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MBConvUTF7)
{
	// Class assignment
	Gura_AssignValueEx("MBConvUTF7", Reference());
}

Gura_ImplementDescendantCreator(wx_MBConvUTF7)
{
	return new Object_wx_MBConvUTF7((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
