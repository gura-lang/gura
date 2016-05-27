//----------------------------------------------------------------------------
// wxInitializer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxInitializer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxInitializer
//----------------------------------------------------------------------------
Object_wx_Initializer::~Object_wx_Initializer()
{
}

Object *Object_wx_Initializer::Clone() const
{
	return nullptr;
}

String Object_wx_Initializer::ToString(bool exprFlag)
{
	String rtn("<wx.Initializer:");
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
// Class implementation for wxInitializer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Initializer)
{
}

Gura_ImplementDescendantCreator(wx_Initializer)
{
	return new Object_wx_Initializer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
