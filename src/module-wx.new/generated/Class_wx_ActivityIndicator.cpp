//----------------------------------------------------------------------------
// wxActivityIndicator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxActivityIndicator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxActivityIndicator
//----------------------------------------------------------------------------
Object_wx_ActivityIndicator::~Object_wx_ActivityIndicator()
{
}

Object *Object_wx_ActivityIndicator::Clone() const
{
	return nullptr;
}

String Object_wx_ActivityIndicator::ToString(bool exprFlag)
{
	String rtn("<wx.ActivityIndicator:");
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
// Class implementation for wxActivityIndicator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ActivityIndicator)
{
}

Gura_ImplementDescendantCreator(wx_ActivityIndicator)
{
	return new Object_wx_ActivityIndicator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
