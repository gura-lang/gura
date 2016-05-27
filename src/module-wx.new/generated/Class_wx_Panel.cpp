//----------------------------------------------------------------------------
// wxPanel
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPanel
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPanel
//----------------------------------------------------------------------------
Object_wx_Panel::~Object_wx_Panel()
{
}

Object *Object_wx_Panel::Clone() const
{
	return nullptr;
}

String Object_wx_Panel::ToString(bool exprFlag)
{
	String rtn("<wx.Panel:");
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
// Class implementation for wxPanel
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Panel)
{
}

Gura_ImplementDescendantCreator(wx_Panel)
{
	return new Object_wx_Panel((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
