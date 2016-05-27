//----------------------------------------------------------------------------
// wxDir
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDir
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDir
//----------------------------------------------------------------------------
Object_wx_Dir::~Object_wx_Dir()
{
}

Object *Object_wx_Dir::Clone() const
{
	return nullptr;
}

String Object_wx_Dir::ToString(bool exprFlag)
{
	String rtn("<wx.Dir:");
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
// Class implementation for wxDir
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dir)
{
}

Gura_ImplementDescendantCreator(wx_Dir)
{
	return new Object_wx_Dir((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
