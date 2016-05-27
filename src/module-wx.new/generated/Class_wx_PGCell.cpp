//----------------------------------------------------------------------------
// wxPGCell
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGCell
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGCell
//----------------------------------------------------------------------------
Object_wx_PGCell::~Object_wx_PGCell()
{
}

Object *Object_wx_PGCell::Clone() const
{
	return nullptr;
}

String Object_wx_PGCell::ToString(bool exprFlag)
{
	String rtn("<wx.PGCell:");
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
// Class implementation for wxPGCell
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGCell)
{
}

Gura_ImplementDescendantCreator(wx_PGCell)
{
	return new Object_wx_PGCell((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
