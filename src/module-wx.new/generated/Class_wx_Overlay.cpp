//----------------------------------------------------------------------------
// wxOverlay
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxOverlay
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxOverlay
//----------------------------------------------------------------------------
Object_wx_Overlay::~Object_wx_Overlay()
{
}

Object *Object_wx_Overlay::Clone() const
{
	return nullptr;
}

String Object_wx_Overlay::ToString(bool exprFlag)
{
	String rtn("<wx.Overlay:");
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
// Class implementation for wxOverlay
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Overlay)
{
}

Gura_ImplementDescendantCreator(wx_Overlay)
{
	return new Object_wx_Overlay((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
