//----------------------------------------------------------------------------
// wxPGMultiButton
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGMultiButton
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGMultiButton
//----------------------------------------------------------------------------
Object_wx_PGMultiButton::~Object_wx_PGMultiButton()
{
}

Object *Object_wx_PGMultiButton::Clone() const
{
	return nullptr;
}

String Object_wx_PGMultiButton::ToString(bool exprFlag)
{
	String rtn("<wx.PGMultiButton:");
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
// Class implementation for wxPGMultiButton
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGMultiButton)
{
}

Gura_ImplementDescendantCreator(wx_PGMultiButton)
{
	return new Object_wx_PGMultiButton((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
