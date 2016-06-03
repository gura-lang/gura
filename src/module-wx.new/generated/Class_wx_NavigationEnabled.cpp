//----------------------------------------------------------------------------
// wxNavigationEnabled
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNavigationEnabled
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNavigationEnabled
//----------------------------------------------------------------------------
Object_wx_NavigationEnabled::~Object_wx_NavigationEnabled()
{
}

Object *Object_wx_NavigationEnabled::Clone() const
{
	return nullptr;
}

String Object_wx_NavigationEnabled::ToString(bool exprFlag)
{
	String rtn("<wx.NavigationEnabled:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxNavigationEnabled, "wxNavigationEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxNavigationEnabled)
{
	//wxNavigationEnabled();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxNavigationEnabled
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NavigationEnabled)
{
	// Constructor assignment
	Gura_AssignFunction(__wxNavigationEnabled);
}

Gura_ImplementDescendantCreator(wx_NavigationEnabled)
{
	return new Object_wx_NavigationEnabled((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
