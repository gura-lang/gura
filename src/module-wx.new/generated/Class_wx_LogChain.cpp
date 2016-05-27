//----------------------------------------------------------------------------
// wxLogChain
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogChain
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogChain
//----------------------------------------------------------------------------
Object_wx_LogChain::~Object_wx_LogChain()
{
}

Object *Object_wx_LogChain::Clone() const
{
	return nullptr;
}

String Object_wx_LogChain::ToString(bool exprFlag)
{
	String rtn("<wx.LogChain:");
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
// Class implementation for wxLogChain
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogChain)
{
}

Gura_ImplementDescendantCreator(wx_LogChain)
{
	return new Object_wx_LogChain((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
