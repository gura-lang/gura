//----------------------------------------------------------------------------
// wxIntegerValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxIntegerValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxIntegerValidator
//----------------------------------------------------------------------------
Object_wx_IntegerValidator::~Object_wx_IntegerValidator()
{
}

Object *Object_wx_IntegerValidator::Clone() const
{
	return nullptr;
}

String Object_wx_IntegerValidator::ToString(bool exprFlag)
{
	String rtn("<wx.IntegerValidator:");
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
// Class implementation for wxIntegerValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_IntegerValidator)
{
}

Gura_ImplementDescendantCreator(wx_IntegerValidator)
{
	return new Object_wx_IntegerValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
