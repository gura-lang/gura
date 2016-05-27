//----------------------------------------------------------------------------
// wxRibbonArtProvider
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonArtProvider
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonArtProvider
//----------------------------------------------------------------------------
Object_wx_RibbonArtProvider::~Object_wx_RibbonArtProvider()
{
}

Object *Object_wx_RibbonArtProvider::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonArtProvider::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonArtProvider:");
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
// Class implementation for wxRibbonArtProvider
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonArtProvider)
{
}

Gura_ImplementDescendantCreator(wx_RibbonArtProvider)
{
	return new Object_wx_RibbonArtProvider((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
