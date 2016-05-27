//----------------------------------------------------------------------------
// wxPreferencesEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPreferencesEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPreferencesEditor
//----------------------------------------------------------------------------
Object_wx_PreferencesEditor::~Object_wx_PreferencesEditor()
{
}

Object *Object_wx_PreferencesEditor::Clone() const
{
	return nullptr;
}

String Object_wx_PreferencesEditor::ToString(bool exprFlag)
{
	String rtn("<wx.PreferencesEditor:");
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
// Class implementation for wxPreferencesEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreferencesEditor)
{
}

Gura_ImplementDescendantCreator(wx_PreferencesEditor)
{
	return new Object_wx_PreferencesEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
