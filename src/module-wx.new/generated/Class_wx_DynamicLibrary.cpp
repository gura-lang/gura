//----------------------------------------------------------------------------
// wxDynamicLibrary
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDynamicLibrary
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDynamicLibrary
//----------------------------------------------------------------------------
Object_wx_DynamicLibrary::~Object_wx_DynamicLibrary()
{
}

Object *Object_wx_DynamicLibrary::Clone() const
{
	return nullptr;
}

String Object_wx_DynamicLibrary::ToString(bool exprFlag)
{
	String rtn("<wx.DynamicLibrary:");
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
// Class implementation for wxDynamicLibrary
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DynamicLibrary)
{
}

Gura_ImplementDescendantCreator(wx_DynamicLibrary)
{
	return new Object_wx_DynamicLibrary((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
