//----------------------------------------------------------------------------
// wxPreferencesPage
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPreferencesPage
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPreferencesPage
//----------------------------------------------------------------------------
Object_wx_PreferencesPage::~Object_wx_PreferencesPage()
{
}

Object *Object_wx_PreferencesPage::Clone() const
{
	return nullptr;
}

String Object_wx_PreferencesPage::ToString(bool exprFlag)
{
	String rtn("<wx.PreferencesPage:");
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
// Class implementation for wxPreferencesPage
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreferencesPage)
{
}

Gura_ImplementDescendantCreator(wx_PreferencesPage)
{
	return new Object_wx_PreferencesPage((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
