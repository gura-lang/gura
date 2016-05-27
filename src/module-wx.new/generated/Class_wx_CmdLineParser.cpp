//----------------------------------------------------------------------------
// wxCmdLineParser
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCmdLineParser
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCmdLineParser
//----------------------------------------------------------------------------
Object_wx_CmdLineParser::~Object_wx_CmdLineParser()
{
}

Object *Object_wx_CmdLineParser::Clone() const
{
	return nullptr;
}

String Object_wx_CmdLineParser::ToString(bool exprFlag)
{
	String rtn("<wx.CmdLineParser:");
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
// Class implementation for wxCmdLineParser
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_CmdLineParser)
{
}

Gura_ImplementDescendantCreator(wx_CmdLineParser)
{
	return new Object_wx_CmdLineParser((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
