//----------------------------------------------------------------------------
// wxXLocale
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxXLocale
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxXLocale
//----------------------------------------------------------------------------
Object_wx_XLocale::~Object_wx_XLocale()
{
}

Object *Object_wx_XLocale::Clone() const
{
	return nullptr;
}

String Object_wx_XLocale::ToString(bool exprFlag)
{
	String rtn("<wx.XLocale:");
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
// Class implementation for wxXLocale
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_XLocale)
{
}

Gura_ImplementDescendantCreator(wx_XLocale)
{
	return new Object_wx_XLocale((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
