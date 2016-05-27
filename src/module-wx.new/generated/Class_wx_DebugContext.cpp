//----------------------------------------------------------------------------
// wxDebugContext
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugContext
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugContext
//----------------------------------------------------------------------------
Object_wx_DebugContext::~Object_wx_DebugContext()
{
}

Object *Object_wx_DebugContext::Clone() const
{
	return nullptr;
}

String Object_wx_DebugContext::ToString(bool exprFlag)
{
	String rtn("<wx.DebugContext:");
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
// Class implementation for wxDebugContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugContext)
{
}

Gura_ImplementDescendantCreator(wx_DebugContext)
{
	return new Object_wx_DebugContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
