//----------------------------------------------------------------------------
// wxPersistentTLW
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPersistentTLW
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPersistentTLW
//----------------------------------------------------------------------------
Object_wx_PersistentTLW::~Object_wx_PersistentTLW()
{
}

Object *Object_wx_PersistentTLW::Clone() const
{
	return nullptr;
}

String Object_wx_PersistentTLW::ToString(bool exprFlag)
{
	String rtn("<wx.PersistentTLW:");
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
// Class implementation for wxPersistentTLW
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PersistentTLW)
{
}

Gura_ImplementDescendantCreator(wx_PersistentTLW)
{
	return new Object_wx_PersistentTLW((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
