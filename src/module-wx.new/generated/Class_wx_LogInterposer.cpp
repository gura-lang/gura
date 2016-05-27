//----------------------------------------------------------------------------
// wxLogInterposer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogInterposer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogInterposer
//----------------------------------------------------------------------------
Object_wx_LogInterposer::~Object_wx_LogInterposer()
{
}

Object *Object_wx_LogInterposer::Clone() const
{
	return nullptr;
}

String Object_wx_LogInterposer::ToString(bool exprFlag)
{
	String rtn("<wx.LogInterposer:");
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
// Class implementation for wxLogInterposer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogInterposer)
{
}

Gura_ImplementDescendantCreator(wx_LogInterposer)
{
	return new Object_wx_LogInterposer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
