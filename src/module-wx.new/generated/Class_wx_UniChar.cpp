//----------------------------------------------------------------------------
// wxUniChar
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUniChar
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUniChar
//----------------------------------------------------------------------------
Object_wx_UniChar::~Object_wx_UniChar()
{
}

Object *Object_wx_UniChar::Clone() const
{
	return nullptr;
}

String Object_wx_UniChar::ToString(bool exprFlag)
{
	String rtn("<wx.UniChar:");
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
// Class implementation for wxUniChar
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UniChar)
{
}

Gura_ImplementDescendantCreator(wx_UniChar)
{
	return new Object_wx_UniChar((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
