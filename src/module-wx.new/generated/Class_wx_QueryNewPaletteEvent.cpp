//----------------------------------------------------------------------------
// wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxQueryNewPaletteEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
Object_wx_QueryNewPaletteEvent::~Object_wx_QueryNewPaletteEvent()
{
}

Object *Object_wx_QueryNewPaletteEvent::Clone() const
{
	return nullptr;
}

String Object_wx_QueryNewPaletteEvent::ToString(bool exprFlag)
{
	String rtn("<wx.QueryNewPaletteEvent:");
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
// Class implementation for wxQueryNewPaletteEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_QueryNewPaletteEvent)
{
}

Gura_ImplementDescendantCreator(wx_QueryNewPaletteEvent)
{
	return new Object_wx_QueryNewPaletteEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
