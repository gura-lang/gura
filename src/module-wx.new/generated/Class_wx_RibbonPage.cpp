//----------------------------------------------------------------------------
// wxRibbonPage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRibbonPage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRibbonPage
//----------------------------------------------------------------------------
Object_wx_RibbonPage::~Object_wx_RibbonPage()
{
}

Object *Object_wx_RibbonPage::Clone() const
{
	return nullptr;
}

String Object_wx_RibbonPage::ToString(bool exprFlag)
{
	String rtn("<wx.RibbonPage:");
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
// Class implementation for wxRibbonPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RibbonPage)
{
}

Gura_ImplementDescendantCreator(wx_RibbonPage)
{
	return new Object_wx_RibbonPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
