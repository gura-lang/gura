//----------------------------------------------------------------------------
// wxDCFontChanger
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDCFontChanger
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDCFontChanger
//----------------------------------------------------------------------------
Object_wx_DCFontChanger::~Object_wx_DCFontChanger()
{
}

Object *Object_wx_DCFontChanger::Clone() const
{
	return nullptr;
}

String Object_wx_DCFontChanger::ToString(bool exprFlag)
{
	String rtn("<wx.DCFontChanger:");
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
// Class implementation for wxDCFontChanger
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DCFontChanger)
{
}

Gura_ImplementDescendantCreator(wx_DCFontChanger)
{
	return new Object_wx_DCFontChanger((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
