//----------------------------------------------------------------------------
// wxStaticLine
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStaticLine
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStaticLine
//----------------------------------------------------------------------------
Object_wx_StaticLine::~Object_wx_StaticLine()
{
}

Object *Object_wx_StaticLine::Clone() const
{
	return nullptr;
}

String Object_wx_StaticLine::ToString(bool exprFlag)
{
	String rtn("<wx.StaticLine:");
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
// Class implementation for wxStaticLine
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StaticLine)
{
}

Gura_ImplementDescendantCreator(wx_StaticLine)
{
	return new Object_wx_StaticLine((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
