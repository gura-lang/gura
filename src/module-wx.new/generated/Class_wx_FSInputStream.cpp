//----------------------------------------------------------------------------
// wxFSInputStream
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFSInputStream
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFSInputStream
//----------------------------------------------------------------------------
Object_wx_FSInputStream::~Object_wx_FSInputStream()
{
}

Object *Object_wx_FSInputStream::Clone() const
{
	return nullptr;
}

String Object_wx_FSInputStream::ToString(bool exprFlag)
{
	String rtn("<wx.FSInputStream:");
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
// Class implementation for wxFSInputStream
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FSInputStream)
{
}

Gura_ImplementDescendantCreator(wx_FSInputStream)
{
	return new Object_wx_FSInputStream((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
