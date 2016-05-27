//----------------------------------------------------------------------------
// wxDynamicLibraryDetails
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDynamicLibraryDetails
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
Object_wx_DynamicLibraryDetails::~Object_wx_DynamicLibraryDetails()
{
}

Object *Object_wx_DynamicLibraryDetails::Clone() const
{
	return nullptr;
}

String Object_wx_DynamicLibraryDetails::ToString(bool exprFlag)
{
	String rtn("<wx.DynamicLibraryDetails:");
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
// Class implementation for wxDynamicLibraryDetails
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DynamicLibraryDetails)
{
}

Gura_ImplementDescendantCreator(wx_DynamicLibraryDetails)
{
	return new Object_wx_DynamicLibraryDetails((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
