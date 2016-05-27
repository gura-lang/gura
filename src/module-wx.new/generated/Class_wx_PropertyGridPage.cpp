//----------------------------------------------------------------------------
// wxPropertyGridPage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridPage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridPage
//----------------------------------------------------------------------------
Object_wx_PropertyGridPage::~Object_wx_PropertyGridPage()
{
}

Object *Object_wx_PropertyGridPage::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridPage::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridPage:");
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
// Class implementation for wxPropertyGridPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridPage)
{
}

Gura_ImplementDescendantCreator(wx_PropertyGridPage)
{
	return new Object_wx_PropertyGridPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
