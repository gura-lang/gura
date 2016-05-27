//----------------------------------------------------------------------------
// wxSimpleHtmlListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSimpleHtmlListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
Object_wx_SimpleHtmlListBox::~Object_wx_SimpleHtmlListBox()
{
}

Object *Object_wx_SimpleHtmlListBox::Clone() const
{
	return nullptr;
}

String Object_wx_SimpleHtmlListBox::ToString(bool exprFlag)
{
	String rtn("<wx.SimpleHtmlListBox:");
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
// Class implementation for wxSimpleHtmlListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SimpleHtmlListBox)
{
}

Gura_ImplementDescendantCreator(wx_SimpleHtmlListBox)
{
	return new Object_wx_SimpleHtmlListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
