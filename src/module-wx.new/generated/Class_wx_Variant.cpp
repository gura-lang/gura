//----------------------------------------------------------------------------
// wxVariant
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariant
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariant
//----------------------------------------------------------------------------
Object_wx_Variant::~Object_wx_Variant()
{
}

Object *Object_wx_Variant::Clone() const
{
	return nullptr;
}

String Object_wx_Variant::ToString(bool exprFlag)
{
	String rtn("<wx.Variant:");
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
// Class implementation for wxVariant
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Variant)
{
}

Gura_ImplementDescendantCreator(wx_Variant)
{
	return new Object_wx_Variant((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
