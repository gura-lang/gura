//----------------------------------------------------------------------------
// wxSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSizer
//----------------------------------------------------------------------------
Object_wx_Sizer::~Object_wx_Sizer()
{
}

Object *Object_wx_Sizer::Clone() const
{
	return nullptr;
}

String Object_wx_Sizer::ToString(bool exprFlag)
{
	String rtn("<wx.Sizer:");
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
// Class implementation for wxSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Sizer)
{
}

Gura_ImplementDescendantCreator(wx_Sizer)
{
	return new Object_wx_Sizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
