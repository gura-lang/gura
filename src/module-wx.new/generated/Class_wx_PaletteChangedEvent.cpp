//----------------------------------------------------------------------------
// wxPaletteChangedEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPaletteChangedEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPaletteChangedEvent
//----------------------------------------------------------------------------
Object_wx_PaletteChangedEvent::~Object_wx_PaletteChangedEvent()
{
}

Object *Object_wx_PaletteChangedEvent::Clone() const
{
	return nullptr;
}

String Object_wx_PaletteChangedEvent::ToString(bool exprFlag)
{
	String rtn("<wx.PaletteChangedEvent:");
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
// Class implementation for wxPaletteChangedEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PaletteChangedEvent)
{
}

Gura_ImplementDescendantCreator(wx_PaletteChangedEvent)
{
	return new Object_wx_PaletteChangedEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
