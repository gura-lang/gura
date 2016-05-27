//----------------------------------------------------------------------------
// wxAboutDialogInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAboutDialogInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Object_wx_AboutDialogInfo::~Object_wx_AboutDialogInfo()
{
}

Object *Object_wx_AboutDialogInfo::Clone() const
{
	return nullptr;
}

String Object_wx_AboutDialogInfo::ToString(bool exprFlag)
{
	String rtn("<wx.AboutDialogInfo:");
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
// Class implementation for wxAboutDialogInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AboutDialogInfo)
{
}

Gura_ImplementDescendantCreator(wx_AboutDialogInfo)
{
	return new Object_wx_AboutDialogInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
