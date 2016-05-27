//----------------------------------------------------------------------------
// wxUniCharRef
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxUniCharRef
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxUniCharRef
//----------------------------------------------------------------------------
Object_wx_UniCharRef::~Object_wx_UniCharRef()
{
}

Object *Object_wx_UniCharRef::Clone() const
{
	return nullptr;
}

String Object_wx_UniCharRef::ToString(bool exprFlag)
{
	String rtn("<wx.UniCharRef:");
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
// Class implementation for wxUniCharRef
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_UniCharRef)
{
}

Gura_ImplementDescendantCreator(wx_UniCharRef)
{
	return new Object_wx_UniCharRef((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
