//----------------------------------------------------------------------------
// wxTextAttr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttr
//----------------------------------------------------------------------------
Object_wx_TextAttr::~Object_wx_TextAttr()
{
}

Object *Object_wx_TextAttr::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttr::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttr:");
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
// Class implementation for wxTextAttr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttr)
{
}

Gura_ImplementDescendantCreator(wx_TextAttr)
{
	return new Object_wx_TextAttr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
