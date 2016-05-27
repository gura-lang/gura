//----------------------------------------------------------------------------
// wxTextAttrSize
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrSize
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrSize
//----------------------------------------------------------------------------
Object_wx_TextAttrSize::~Object_wx_TextAttrSize()
{
}

Object *Object_wx_TextAttrSize::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrSize::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrSize:");
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
// Class implementation for wxTextAttrSize
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrSize)
{
}

Gura_ImplementDescendantCreator(wx_TextAttrSize)
{
	return new Object_wx_TextAttrSize((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
