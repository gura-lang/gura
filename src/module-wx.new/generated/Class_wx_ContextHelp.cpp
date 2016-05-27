//----------------------------------------------------------------------------
// wxContextHelp
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxContextHelp
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxContextHelp
//----------------------------------------------------------------------------
Object_wx_ContextHelp::~Object_wx_ContextHelp()
{
}

Object *Object_wx_ContextHelp::Clone() const
{
	return nullptr;
}

String Object_wx_ContextHelp::ToString(bool exprFlag)
{
	String rtn("<wx.ContextHelp:");
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
// Class implementation for wxContextHelp
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ContextHelp)
{
}

Gura_ImplementDescendantCreator(wx_ContextHelp)
{
	return new Object_wx_ContextHelp((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
