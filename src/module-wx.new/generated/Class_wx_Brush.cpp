//----------------------------------------------------------------------------
// wxBrush
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBrush
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBrush
//----------------------------------------------------------------------------
Object_wx_Brush::~Object_wx_Brush()
{
}

Object *Object_wx_Brush::Clone() const
{
	return nullptr;
}

String Object_wx_Brush::ToString(bool exprFlag)
{
	String rtn("<wx.Brush:");
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
// Class implementation for wxBrush
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Brush)
{
}

Gura_ImplementDescendantCreator(wx_Brush)
{
	return new Object_wx_Brush((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
