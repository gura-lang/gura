//----------------------------------------------------------------------------
// wxTextAttrShadow
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrShadow
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrShadow
//----------------------------------------------------------------------------
Object_wx_TextAttrShadow::~Object_wx_TextAttrShadow()
{
}

Object *Object_wx_TextAttrShadow::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrShadow::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrShadow:");
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
// Class implementation for wxTextAttrShadow
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrShadow)
{
}

Gura_ImplementDescendantCreator(wx_TextAttrShadow)
{
	return new Object_wx_TextAttrShadow((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
