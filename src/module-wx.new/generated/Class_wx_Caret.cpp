//----------------------------------------------------------------------------
// wxCaret
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCaret
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCaret
//----------------------------------------------------------------------------
Object_wx_Caret::~Object_wx_Caret()
{
}

Object *Object_wx_Caret::Clone() const
{
	return nullptr;
}

String Object_wx_Caret::ToString(bool exprFlag)
{
	String rtn("<wx.Caret:");
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
// Class implementation for wxCaret
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Caret)
{
}

Gura_ImplementDescendantCreator(wx_Caret)
{
	return new Object_wx_Caret((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
