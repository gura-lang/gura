//----------------------------------------------------------------------------
// wxProcess
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxProcess
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxProcess
//----------------------------------------------------------------------------
Object_wx_Process::~Object_wx_Process()
{
}

Object *Object_wx_Process::Clone() const
{
	return nullptr;
}

String Object_wx_Process::ToString(bool exprFlag)
{
	String rtn("<wx.Process:");
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
// Class implementation for wxProcess
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Process)
{
}

Gura_ImplementDescendantCreator(wx_Process)
{
	return new Object_wx_Process((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
