//----------------------------------------------------------------------------
// wxBookCtrlBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBookCtrlBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBookCtrlBase
//----------------------------------------------------------------------------
Object_wx_BookCtrlBase::~Object_wx_BookCtrlBase()
{
}

Object *Object_wx_BookCtrlBase::Clone() const
{
	return nullptr;
}

String Object_wx_BookCtrlBase::ToString(bool exprFlag)
{
	String rtn("<wx.BookCtrlBase:");
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
// Class implementation for wxBookCtrlBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BookCtrlBase)
{
}

Gura_ImplementDescendantCreator(wx_BookCtrlBase)
{
	return new Object_wx_BookCtrlBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
