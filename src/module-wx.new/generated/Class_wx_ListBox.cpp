//----------------------------------------------------------------------------
// wxListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxListBox
//----------------------------------------------------------------------------
Object_wx_ListBox::~Object_wx_ListBox()
{
}

Object *Object_wx_ListBox::Clone() const
{
	return nullptr;
}

String Object_wx_ListBox::ToString(bool exprFlag)
{
	String rtn("<wx.ListBox:");
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
// Class implementation for wxListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ListBox)
{
}

Gura_ImplementDescendantCreator(wx_ListBox)
{
	return new Object_wx_ListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
