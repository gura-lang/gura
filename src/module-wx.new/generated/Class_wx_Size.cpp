//----------------------------------------------------------------------------
// wxSize
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSize
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSize
//----------------------------------------------------------------------------
Object_wx_Size::~Object_wx_Size()
{
}

Object *Object_wx_Size::Clone() const
{
	return nullptr;
}

String Object_wx_Size::ToString(bool exprFlag)
{
	String rtn("<wx.Size:");
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
// Class implementation for wxSize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Size)
{
}

Gura_ImplementDescendantCreator(wx_Size)
{
	return new Object_wx_Size((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
