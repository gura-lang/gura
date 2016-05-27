//----------------------------------------------------------------------------
// wxHashMap
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHashMap
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHashMap
//----------------------------------------------------------------------------
Object_wx_HashMap::~Object_wx_HashMap()
{
}

Object *Object_wx_HashMap::Clone() const
{
	return nullptr;
}

String Object_wx_HashMap::ToString(bool exprFlag)
{
	String rtn("<wx.HashMap:");
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
// Class implementation for wxHashMap
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HashMap)
{
}

Gura_ImplementDescendantCreator(wx_HashMap)
{
	return new Object_wx_HashMap((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
