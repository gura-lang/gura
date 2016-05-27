//----------------------------------------------------------------------------
// wxStaticBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticBox
//----------------------------------------------------------------------------
Object_wx_StaticBox::~Object_wx_StaticBox()
{
}

Object *Object_wx_StaticBox::Clone() const
{
	return nullptr;
}

String Object_wx_StaticBox::ToString(bool exprFlag)
{
	String rtn("<wx.StaticBox:");
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
// Class implementation for wxStaticBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticBox)
{
}

Gura_ImplementDescendantCreator(wx_StaticBox)
{
	return new Object_wx_StaticBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
