//----------------------------------------------------------------------------
// wxStandardPaths
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStandardPaths
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStandardPaths
//----------------------------------------------------------------------------
Object_wx_StandardPaths::~Object_wx_StandardPaths()
{
}

Object *Object_wx_StandardPaths::Clone() const
{
	return nullptr;
}

String Object_wx_StandardPaths::ToString(bool exprFlag)
{
	String rtn("<wx.StandardPaths:");
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
// Class implementation for wxStandardPaths
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StandardPaths)
{
	// Class assignment
	Gura_AssignValueEx("StandardPaths", Reference());
}

Gura_ImplementDescendantCreator(wx_StandardPaths)
{
	return new Object_wx_StandardPaths((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
