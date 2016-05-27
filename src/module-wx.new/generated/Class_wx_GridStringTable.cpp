//----------------------------------------------------------------------------
// wxGridStringTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridStringTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridStringTable
//----------------------------------------------------------------------------
Object_wx_GridStringTable::~Object_wx_GridStringTable()
{
}

Object *Object_wx_GridStringTable::Clone() const
{
	return nullptr;
}

String Object_wx_GridStringTable::ToString(bool exprFlag)
{
	String rtn("<wx.GridStringTable:");
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
// Class implementation for wxGridStringTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridStringTable)
{
}

Gura_ImplementDescendantCreator(wx_GridStringTable)
{
	return new Object_wx_GridStringTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
