//----------------------------------------------------------------------------
// wxCmdLineArg
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCmdLineArg
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCmdLineArg
//----------------------------------------------------------------------------
Object_wx_CmdLineArg::~Object_wx_CmdLineArg()
{
}

Object *Object_wx_CmdLineArg::Clone() const
{
	return nullptr;
}

String Object_wx_CmdLineArg::ToString(bool exprFlag)
{
	String rtn("<wx.CmdLineArg:");
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
// Class implementation for wxCmdLineArg
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CmdLineArg)
{
}

Gura_ImplementDescendantCreator(wx_CmdLineArg)
{
	return new Object_wx_CmdLineArg((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
