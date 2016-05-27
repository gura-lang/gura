//----------------------------------------------------------------------------
// wxAcceleratorTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAcceleratorTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAcceleratorTable
//----------------------------------------------------------------------------
Object_wx_AcceleratorTable::~Object_wx_AcceleratorTable()
{
}

Object *Object_wx_AcceleratorTable::Clone() const
{
	return nullptr;
}

String Object_wx_AcceleratorTable::ToString(bool exprFlag)
{
	String rtn("<wx.AcceleratorTable:");
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
// Class implementation for wxAcceleratorTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AcceleratorTable)
{
}

Gura_ImplementDescendantCreator(wx_AcceleratorTable)
{
	return new Object_wx_AcceleratorTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
