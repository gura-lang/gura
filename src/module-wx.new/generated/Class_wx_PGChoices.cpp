//----------------------------------------------------------------------------
// wxPGChoices
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGChoices
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGChoices
//----------------------------------------------------------------------------
Object_wx_PGChoices::~Object_wx_PGChoices()
{
}

Object *Object_wx_PGChoices::Clone() const
{
	return nullptr;
}

String Object_wx_PGChoices::ToString(bool exprFlag)
{
	String rtn("<wx.PGChoices:");
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
// Class implementation for wxPGChoices
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGChoices)
{
}

Gura_ImplementDescendantCreator(wx_PGChoices)
{
	return new Object_wx_PGChoices((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
