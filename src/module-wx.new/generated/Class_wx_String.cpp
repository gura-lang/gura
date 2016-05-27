//----------------------------------------------------------------------------
// wxString
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxString
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxString
//----------------------------------------------------------------------------
Object_wx_String::~Object_wx_String()
{
}

Object *Object_wx_String::Clone() const
{
	return nullptr;
}

String Object_wx_String::ToString(bool exprFlag)
{
	String rtn("<wx.String:");
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
// Class implementation for wxString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_String)
{
}

Gura_ImplementDescendantCreator(wx_String)
{
	return new Object_wx_String((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
