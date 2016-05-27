//----------------------------------------------------------------------------
// wxFontPickerEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontPickerEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontPickerEvent
//----------------------------------------------------------------------------
Object_wx_FontPickerEvent::~Object_wx_FontPickerEvent()
{
}

Object *Object_wx_FontPickerEvent::Clone() const
{
	return nullptr;
}

String Object_wx_FontPickerEvent::ToString(bool exprFlag)
{
	String rtn("<wx.FontPickerEvent:");
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
// Class implementation for wxFontPickerEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontPickerEvent)
{
}

Gura_ImplementDescendantCreator(wx_FontPickerEvent)
{
	return new Object_wx_FontPickerEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
