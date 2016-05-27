//----------------------------------------------------------------------------
// wxNumValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxNumValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxNumValidator
//----------------------------------------------------------------------------
Object_wx_NumValidator::~Object_wx_NumValidator()
{
}

Object *Object_wx_NumValidator::Clone() const
{
	return nullptr;
}

String Object_wx_NumValidator::ToString(bool exprFlag)
{
	String rtn("<wx.NumValidator:");
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
// Class implementation for wxNumValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_NumValidator)
{
}

Gura_ImplementDescendantCreator(wx_NumValidator)
{
	return new Object_wx_NumValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
