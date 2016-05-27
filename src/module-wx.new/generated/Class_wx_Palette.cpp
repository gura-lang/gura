//----------------------------------------------------------------------------
// wxPalette
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPalette
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPalette
//----------------------------------------------------------------------------
Object_wx_Palette::~Object_wx_Palette()
{
}

Object *Object_wx_Palette::Clone() const
{
	return nullptr;
}

String Object_wx_Palette::ToString(bool exprFlag)
{
	String rtn("<wx.Palette:");
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
// Class implementation for wxPalette
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Palette)
{
}

Gura_ImplementDescendantCreator(wx_Palette)
{
	return new Object_wx_Palette((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
