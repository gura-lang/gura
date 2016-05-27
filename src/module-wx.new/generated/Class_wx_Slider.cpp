//----------------------------------------------------------------------------
// wxSlider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSlider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSlider
//----------------------------------------------------------------------------
Object_wx_Slider::~Object_wx_Slider()
{
}

Object *Object_wx_Slider::Clone() const
{
	return nullptr;
}

String Object_wx_Slider::ToString(bool exprFlag)
{
	String rtn("<wx.Slider:");
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
// Class implementation for wxSlider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Slider)
{
}

Gura_ImplementDescendantCreator(wx_Slider)
{
	return new Object_wx_Slider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
