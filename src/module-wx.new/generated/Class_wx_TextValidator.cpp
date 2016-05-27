//----------------------------------------------------------------------------
// wxTextValidator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextValidator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextValidator
//----------------------------------------------------------------------------
Object_wx_TextValidator::~Object_wx_TextValidator()
{
}

Object *Object_wx_TextValidator::Clone() const
{
	return nullptr;
}

String Object_wx_TextValidator::ToString(bool exprFlag)
{
	String rtn("<wx.TextValidator:");
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
// Class implementation for wxTextValidator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextValidator)
{
}

Gura_ImplementDescendantCreator(wx_TextValidator)
{
	return new Object_wx_TextValidator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
