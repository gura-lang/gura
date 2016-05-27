//----------------------------------------------------------------------------
// wxGraphicsObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGraphicsObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGraphicsObject
//----------------------------------------------------------------------------
Object_wx_GraphicsObject::~Object_wx_GraphicsObject()
{
}

Object *Object_wx_GraphicsObject::Clone() const
{
	return nullptr;
}

String Object_wx_GraphicsObject::ToString(bool exprFlag)
{
	String rtn("<wx.GraphicsObject:");
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
// Class implementation for wxGraphicsObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GraphicsObject)
{
}

Gura_ImplementDescendantCreator(wx_GraphicsObject)
{
	return new Object_wx_GraphicsObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
