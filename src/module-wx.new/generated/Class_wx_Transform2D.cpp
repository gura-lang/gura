//----------------------------------------------------------------------------
// wxTransform2D
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTransform2D
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTransform2D
//----------------------------------------------------------------------------
Object_wx_Transform2D::~Object_wx_Transform2D()
{
}

Object *Object_wx_Transform2D::Clone() const
{
	return nullptr;
}

String Object_wx_Transform2D::ToString(bool exprFlag)
{
	String rtn("<wx.Transform2D:");
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
// Class implementation for wxTransform2D
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Transform2D)
{
}

Gura_ImplementDescendantCreator(wx_Transform2D)
{
	return new Object_wx_Transform2D((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
