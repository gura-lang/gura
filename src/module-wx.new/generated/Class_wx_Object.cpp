//----------------------------------------------------------------------------
// wxObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxObject
//----------------------------------------------------------------------------
Object_wx_Object::~Object_wx_Object()
{
}

Object *Object_wx_Object::Clone() const
{
	return nullptr;
}

String Object_wx_Object::ToString(bool exprFlag)
{
	String rtn("<wx.Object:");
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
// Class implementation for wxObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Object)
{
}

Gura_ImplementDescendantCreator(wx_Object)
{
	return new Object_wx_Object((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
