//----------------------------------------------------------------------------
// wxRibbonGallery
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonGallery
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonGallery
//----------------------------------------------------------------------------
Object_wx_RibbonGallery::~Object_wx_RibbonGallery()
{
}

Object *Object_wx_RibbonGallery::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonGallery::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonGallery:");
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
// Class implementation for wxRibbonGallery
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonGallery)
{
}

Gura_ImplementDescendantCreator(wx_RibbonGallery)
{
	return new Object_wx_RibbonGallery((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
