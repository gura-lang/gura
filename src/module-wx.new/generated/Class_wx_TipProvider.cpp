//----------------------------------------------------------------------------
// wxTipProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTipProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTipProvider
//----------------------------------------------------------------------------
Object_wx_TipProvider::~Object_wx_TipProvider()
{
}

Object *Object_wx_TipProvider::Clone() const
{
	return nullptr;
}

String Object_wx_TipProvider::ToString(bool exprFlag)
{
	String rtn("<wx.TipProvider:");
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
// Class implementation for wxTipProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TipProvider)
{
}

Gura_ImplementDescendantCreator(wx_TipProvider)
{
	return new Object_wx_TipProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
