//----------------------------------------------------------------------------
// wxTextAttrBorders
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrBorders
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrBorders
//----------------------------------------------------------------------------
Object_wx_TextAttrBorders::~Object_wx_TextAttrBorders()
{
}

Object *Object_wx_TextAttrBorders::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrBorders::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrBorders:");
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
// Class implementation for wxTextAttrBorders
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrBorders)
{
}

Gura_ImplementDescendantCreator(wx_TextAttrBorders)
{
	return new Object_wx_TextAttrBorders((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
