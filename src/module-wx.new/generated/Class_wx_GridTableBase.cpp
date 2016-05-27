//----------------------------------------------------------------------------
// wxGridTableBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridTableBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridTableBase
//----------------------------------------------------------------------------
Object_wx_GridTableBase::~Object_wx_GridTableBase()
{
}

Object *Object_wx_GridTableBase::Clone() const
{
	return nullptr;
}

String Object_wx_GridTableBase::ToString(bool exprFlag)
{
	String rtn("<wx.GridTableBase:");
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
// Class implementation for wxGridTableBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridTableBase)
{
}

Gura_ImplementDescendantCreator(wx_GridTableBase)
{
	return new Object_wx_GridTableBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
