//----------------------------------------------------------------------------
// wxAnyValueType
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAnyValueType
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAnyValueType
//----------------------------------------------------------------------------
Object_wx_AnyValueType::~Object_wx_AnyValueType()
{
}

Object *Object_wx_AnyValueType::Clone() const
{
	return nullptr;
}

String Object_wx_AnyValueType::ToString(bool exprFlag)
{
	String rtn("<wx.AnyValueType:");
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
// Class implementation for wxAnyValueType
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AnyValueType)
{
}

Gura_ImplementDescendantCreator(wx_AnyValueType)
{
	return new Object_wx_AnyValueType((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
