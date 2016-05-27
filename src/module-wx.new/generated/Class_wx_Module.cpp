//----------------------------------------------------------------------------
// wxModule
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxModule
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxModule
//----------------------------------------------------------------------------
Object_wx_Module::~Object_wx_Module()
{
}

Object *Object_wx_Module::Clone() const
{
	return nullptr;
}

String Object_wx_Module::ToString(bool exprFlag)
{
	String rtn("<wx.Module:");
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
// Class implementation for wxModule
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Module)
{
}

Gura_ImplementDescendantCreator(wx_Module)
{
	return new Object_wx_Module((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
