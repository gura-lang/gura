//----------------------------------------------------------------------------
// wxTextAttrBorder
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrBorder
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrBorder
//----------------------------------------------------------------------------
Object_wx_TextAttrBorder::~Object_wx_TextAttrBorder()
{
}

Object *Object_wx_TextAttrBorder::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrBorder::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrBorder:");
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
// Class implementation for wxTextAttrBorder
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrBorder)
{
}

Gura_ImplementDescendantCreator(wx_TextAttrBorder)
{
	return new Object_wx_TextAttrBorder((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
