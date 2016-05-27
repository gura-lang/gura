//----------------------------------------------------------------------------
// wxGBSpan
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGBSpan
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGBSpan
//----------------------------------------------------------------------------
Object_wx_GBSpan::~Object_wx_GBSpan()
{
}

Object *Object_wx_GBSpan::Clone() const
{
	return nullptr;
}

String Object_wx_GBSpan::ToString(bool exprFlag)
{
	String rtn("<wx.GBSpan:");
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
// Class implementation for wxGBSpan
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GBSpan)
{
}

Gura_ImplementDescendantCreator(wx_GBSpan)
{
	return new Object_wx_GBSpan((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
