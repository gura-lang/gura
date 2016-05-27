//----------------------------------------------------------------------------
// wxGCDC
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGCDC
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGCDC
//----------------------------------------------------------------------------
Object_wx_GCDC::~Object_wx_GCDC()
{
}

Object *Object_wx_GCDC::Clone() const
{
	return nullptr;
}

String Object_wx_GCDC::ToString(bool exprFlag)
{
	String rtn("<wx.GCDC:");
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
// Class implementation for wxGCDC
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GCDC)
{
}

Gura_ImplementDescendantCreator(wx_GCDC)
{
	return new Object_wx_GCDC((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
