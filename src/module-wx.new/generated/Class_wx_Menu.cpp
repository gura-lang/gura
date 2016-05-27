//----------------------------------------------------------------------------
// wxMenu
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMenu
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMenu
//----------------------------------------------------------------------------
Object_wx_Menu::~Object_wx_Menu()
{
}

Object *Object_wx_Menu::Clone() const
{
	return nullptr;
}

String Object_wx_Menu::ToString(bool exprFlag)
{
	String rtn("<wx.Menu:");
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
// Class implementation for wxMenu
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Menu)
{
}

Gura_ImplementDescendantCreator(wx_Menu)
{
	return new Object_wx_Menu((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
