//----------------------------------------------------------------------------
// wxHeaderColumn
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHeaderColumn
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHeaderColumn
//----------------------------------------------------------------------------
Object_wx_HeaderColumn::~Object_wx_HeaderColumn()
{
}

Object *Object_wx_HeaderColumn::Clone() const
{
	return nullptr;
}

String Object_wx_HeaderColumn::ToString(bool exprFlag)
{
	String rtn("<wx.HeaderColumn:");
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
// Class implementation for wxHeaderColumn
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HeaderColumn)
{
}

Gura_ImplementDescendantCreator(wx_HeaderColumn)
{
	return new Object_wx_HeaderColumn((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
