//----------------------------------------------------------------------------
// wxStaticText
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticText
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticText
//----------------------------------------------------------------------------
Object_wx_StaticText::~Object_wx_StaticText()
{
}

Object *Object_wx_StaticText::Clone() const
{
	return nullptr;
}

String Object_wx_StaticText::ToString(bool exprFlag)
{
	String rtn("<wx.StaticText:");
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
// Class implementation for wxStaticText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticText)
{
}

Gura_ImplementDescendantCreator(wx_StaticText)
{
	return new Object_wx_StaticText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
