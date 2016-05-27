//----------------------------------------------------------------------------
// wxVarScrollHelperBase
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVarScrollHelperBase
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVarScrollHelperBase
//----------------------------------------------------------------------------
Object_wx_VarScrollHelperBase::~Object_wx_VarScrollHelperBase()
{
}

Object *Object_wx_VarScrollHelperBase::Clone() const
{
	return nullptr;
}

String Object_wx_VarScrollHelperBase::ToString(bool exprFlag)
{
	String rtn("<wx.VarScrollHelperBase:");
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
// Class implementation for wxVarScrollHelperBase
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VarScrollHelperBase)
{
}

Gura_ImplementDescendantCreator(wx_VarScrollHelperBase)
{
	return new Object_wx_VarScrollHelperBase((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
