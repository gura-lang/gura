//----------------------------------------------------------------------------
// wxPageSetupDialogData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupDialogData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupDialogData
//----------------------------------------------------------------------------
Object_wx_PageSetupDialogData::~Object_wx_PageSetupDialogData()
{
}

Object *Object_wx_PageSetupDialogData::Clone() const
{
	return nullptr;
}

String Object_wx_PageSetupDialogData::ToString(bool exprFlag)
{
	String rtn("<wx.PageSetupDialogData:");
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
// Class implementation for wxPageSetupDialogData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupDialogData)
{
}

Gura_ImplementDescendantCreator(wx_PageSetupDialogData)
{
	return new Object_wx_PageSetupDialogData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
