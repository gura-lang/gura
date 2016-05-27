//----------------------------------------------------------------------------
// wxChoicebook
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxChoicebook
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxChoicebook
//----------------------------------------------------------------------------
Object_wx_Choicebook::~Object_wx_Choicebook()
{
}

Object *Object_wx_Choicebook::Clone() const
{
	return nullptr;
}

String Object_wx_Choicebook::ToString(bool exprFlag)
{
	String rtn("<wx.Choicebook:");
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
// Class implementation for wxChoicebook
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Choicebook)
{
}

Gura_ImplementDescendantCreator(wx_Choicebook)
{
	return new Object_wx_Choicebook((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
