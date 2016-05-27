//----------------------------------------------------------------------------
// wxArrayString
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxArrayString
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxArrayString
//----------------------------------------------------------------------------
Object_wx_ArrayString::~Object_wx_ArrayString()
{
}

Object *Object_wx_ArrayString::Clone() const
{
	return nullptr;
}

String Object_wx_ArrayString::ToString(bool exprFlag)
{
	String rtn("<wx.ArrayString:");
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
// Class implementation for wxArrayString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ArrayString)
{
}

Gura_ImplementDescendantCreator(wx_ArrayString)
{
	return new Object_wx_ArrayString((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
