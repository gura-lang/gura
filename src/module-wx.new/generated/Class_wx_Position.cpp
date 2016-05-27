//----------------------------------------------------------------------------
// wxPosition
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPosition
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPosition
//----------------------------------------------------------------------------
Object_wx_Position::~Object_wx_Position()
{
}

Object *Object_wx_Position::Clone() const
{
	return nullptr;
}

String Object_wx_Position::ToString(bool exprFlag)
{
	String rtn("<wx.Position:");
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
// Class implementation for wxPosition
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Position)
{
}

Gura_ImplementDescendantCreator(wx_Position)
{
	return new Object_wx_Position((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
