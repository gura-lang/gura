//----------------------------------------------------------------------------
// wxTarInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTarInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTarInputStream
//----------------------------------------------------------------------------
Object_wx_TarInputStream::~Object_wx_TarInputStream()
{
}

Object *Object_wx_TarInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_TarInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.TarInputStream:");
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
// Class implementation for wxTarInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TarInputStream)
{
}

Gura_ImplementDescendantCreator(wx_TarInputStream)
{
	return new Object_wx_TarInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
