//----------------------------------------------------------------------------
// wxFloatingPointValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFloatingPointValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFloatingPointValidator
//----------------------------------------------------------------------------
Object_wx_FloatingPointValidator::~Object_wx_FloatingPointValidator()
{
}

Object *Object_wx_FloatingPointValidator::Clone() const
{
	return nullptr;
}

String Object_wx_FloatingPointValidator::ToString(bool exprFlag)
{
	String rtn("<wx.FloatingPointValidator:");
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
// Class implementation for wxFloatingPointValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FloatingPointValidator)
{
}

Gura_ImplementDescendantCreator(wx_FloatingPointValidator)
{
	return new Object_wx_FloatingPointValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
