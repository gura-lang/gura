//----------------------------------------------------------------------------
// wxStdDialogButtonSizer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdDialogButtonSizer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Object_wx_StdDialogButtonSizer::~Object_wx_StdDialogButtonSizer()
{
}

Object *Object_wx_StdDialogButtonSizer::Clone() const
{
	return nullptr;
}

String Object_wx_StdDialogButtonSizer::ToString(bool exprFlag)
{
	String rtn("<wx.StdDialogButtonSizer:");
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
// Class implementation for wxStdDialogButtonSizer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdDialogButtonSizer)
{
}

Gura_ImplementDescendantCreator(wx_StdDialogButtonSizer)
{
	return new Object_wx_StdDialogButtonSizer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
