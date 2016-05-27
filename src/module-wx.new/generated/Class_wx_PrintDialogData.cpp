//----------------------------------------------------------------------------
// wxPrintDialogData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintDialogData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintDialogData
//----------------------------------------------------------------------------
Object_wx_PrintDialogData::~Object_wx_PrintDialogData()
{
}

Object *Object_wx_PrintDialogData::Clone() const
{
	return nullptr;
}

String Object_wx_PrintDialogData::ToString(bool exprFlag)
{
	String rtn("<wx.PrintDialogData:");
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
// Class implementation for wxPrintDialogData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintDialogData)
{
}

Gura_ImplementDescendantCreator(wx_PrintDialogData)
{
	return new Object_wx_PrintDialogData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
