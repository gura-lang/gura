//----------------------------------------------------------------------------
// wxFilterClassFactory
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFilterClassFactory
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFilterClassFactory
//----------------------------------------------------------------------------
Object_wx_FilterClassFactory::~Object_wx_FilterClassFactory()
{
}

Object *Object_wx_FilterClassFactory::Clone() const
{
	return nullptr;
}

String Object_wx_FilterClassFactory::ToString(bool exprFlag)
{
	String rtn("<wx.FilterClassFactory:");
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
// Class implementation for wxFilterClassFactory
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FilterClassFactory)
{
}

Gura_ImplementDescendantCreator(wx_FilterClassFactory)
{
	return new Object_wx_FilterClassFactory((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
