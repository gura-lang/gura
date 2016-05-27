//----------------------------------------------------------------------------
// wxLayoutConstraints
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLayoutConstraints
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Object_wx_LayoutConstraints::~Object_wx_LayoutConstraints()
{
}

Object *Object_wx_LayoutConstraints::Clone() const
{
	return nullptr;
}

String Object_wx_LayoutConstraints::ToString(bool exprFlag)
{
	String rtn("<wx.LayoutConstraints:");
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
// Class implementation for wxLayoutConstraints
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LayoutConstraints)
{
}

Gura_ImplementDescendantCreator(wx_LayoutConstraints)
{
	return new Object_wx_LayoutConstraints((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
