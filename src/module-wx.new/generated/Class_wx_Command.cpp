//----------------------------------------------------------------------------
// wxCommand
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxCommand
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxCommand
//----------------------------------------------------------------------------
Object_wx_Command::~Object_wx_Command()
{
}

Object *Object_wx_Command::Clone() const
{
	return nullptr;
}

String Object_wx_Command::ToString(bool exprFlag)
{
	String rtn("<wx.Command:");
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
// Class implementation for wxCommand
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Command)
{
}

Gura_ImplementDescendantCreator(wx_Command)
{
	return new Object_wx_Command((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
