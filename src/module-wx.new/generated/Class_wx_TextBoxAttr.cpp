//----------------------------------------------------------------------------
// wxTextBoxAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextBoxAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextBoxAttr
//----------------------------------------------------------------------------
Object_wx_TextBoxAttr::~Object_wx_TextBoxAttr()
{
}

Object *Object_wx_TextBoxAttr::Clone() const
{
	return nullptr;
}

String Object_wx_TextBoxAttr::ToString(bool exprFlag)
{
	String rtn("<wx.TextBoxAttr:");
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
// Class implementation for wxTextBoxAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextBoxAttr)
{
}

Gura_ImplementDescendantCreator(wx_TextBoxAttr)
{
	return new Object_wx_TextBoxAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
