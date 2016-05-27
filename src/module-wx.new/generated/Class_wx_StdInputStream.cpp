//----------------------------------------------------------------------------
// wxStdInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStdInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStdInputStream
//----------------------------------------------------------------------------
Object_wx_StdInputStream::~Object_wx_StdInputStream()
{
}

Object *Object_wx_StdInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_StdInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.StdInputStream:");
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
// Class implementation for wxStdInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StdInputStream)
{
}

Gura_ImplementDescendantCreator(wx_StdInputStream)
{
	return new Object_wx_StdInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
