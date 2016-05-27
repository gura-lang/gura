//----------------------------------------------------------------------------
// wxPGProperty
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGProperty
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGProperty
//----------------------------------------------------------------------------
Object_wx_PGProperty::~Object_wx_PGProperty()
{
}

Object *Object_wx_PGProperty::Clone() const
{
	return nullptr;
}

String Object_wx_PGProperty::ToString(bool exprFlag)
{
	String rtn("<wx.PGProperty:");
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
// Class implementation for wxPGProperty
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGProperty)
{
}

Gura_ImplementDescendantCreator(wx_PGProperty)
{
	return new Object_wx_PGProperty((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
