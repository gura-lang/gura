//----------------------------------------------------------------------------
// wxIconBundle
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIconBundle
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIconBundle
//----------------------------------------------------------------------------
Object_wx_IconBundle::~Object_wx_IconBundle()
{
}

Object *Object_wx_IconBundle::Clone() const
{
	return nullptr;
}

String Object_wx_IconBundle::ToString(bool exprFlag)
{
	String rtn("<wx.IconBundle:");
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
// Class implementation for wxIconBundle
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IconBundle)
{
	
}

Gura_ImplementDescendantCreator(wx_IconBundle)
{
	return new Object_wx_IconBundle((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
