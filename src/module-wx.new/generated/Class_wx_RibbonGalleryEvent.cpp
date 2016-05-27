//----------------------------------------------------------------------------
// wxRibbonGalleryEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonGalleryEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonGalleryEvent
//----------------------------------------------------------------------------
Object_wx_RibbonGalleryEvent::~Object_wx_RibbonGalleryEvent()
{
}

Object *Object_wx_RibbonGalleryEvent::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonGalleryEvent::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonGalleryEvent:");
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
// Class implementation for wxRibbonGalleryEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonGalleryEvent)
{
}

Gura_ImplementDescendantCreator(wx_RibbonGalleryEvent)
{
	return new Object_wx_RibbonGalleryEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
