//----------------------------------------------------------------------------
// wxCmdLineArgs
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCmdLineArgs
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCmdLineArgs
//----------------------------------------------------------------------------
Object_wx_CmdLineArgs::~Object_wx_CmdLineArgs()
{
}

Object *Object_wx_CmdLineArgs::Clone() const
{
	return nullptr;
}

String Object_wx_CmdLineArgs::ToString(bool exprFlag)
{
	String rtn("<wx.CmdLineArgs:");
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
// Class implementation for wxCmdLineArgs
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CmdLineArgs)
{
}

Gura_ImplementDescendantCreator(wx_CmdLineArgs)
{
	return new Object_wx_CmdLineArgs((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
