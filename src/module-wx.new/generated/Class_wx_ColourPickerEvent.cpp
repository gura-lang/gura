//----------------------------------------------------------------------------
// wxColourPickerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxColourPickerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxColourPickerEvent
//----------------------------------------------------------------------------
Object_wx_ColourPickerEvent::~Object_wx_ColourPickerEvent()
{
}

Object *Object_wx_ColourPickerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_ColourPickerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.ColourPickerEvent:");
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
// Class implementation for wxColourPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ColourPickerEvent)
{
}

Gura_ImplementDescendantCreator(wx_ColourPickerEvent)
{
	return new Object_wx_ColourPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
