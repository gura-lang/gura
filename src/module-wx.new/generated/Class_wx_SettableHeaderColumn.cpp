//----------------------------------------------------------------------------
// wxSettableHeaderColumn
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSettableHeaderColumn
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSettableHeaderColumn
//----------------------------------------------------------------------------
Object_wx_SettableHeaderColumn::~Object_wx_SettableHeaderColumn()
{
}

Object *Object_wx_SettableHeaderColumn::Clone() const
{
	return nullptr;
}

String Object_wx_SettableHeaderColumn::ToString(bool exprFlag)
{
	String rtn("<wx.SettableHeaderColumn:");
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
// Class implementation for wxSettableHeaderColumn
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SettableHeaderColumn)
{
}

Gura_ImplementDescendantCreator(wx_SettableHeaderColumn)
{
	return new Object_wx_SettableHeaderColumn((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
