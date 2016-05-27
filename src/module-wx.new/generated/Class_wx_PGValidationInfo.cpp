//----------------------------------------------------------------------------
// wxPGValidationInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGValidationInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGValidationInfo
//----------------------------------------------------------------------------
Object_wx_PGValidationInfo::~Object_wx_PGValidationInfo()
{
}

Object *Object_wx_PGValidationInfo::Clone() const
{
	return nullptr;
}

String Object_wx_PGValidationInfo::ToString(bool exprFlag)
{
	String rtn("<wx.PGValidationInfo:");
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
// Class implementation for wxPGValidationInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGValidationInfo)
{
}

Gura_ImplementDescendantCreator(wx_PGValidationInfo)
{
	return new Object_wx_PGValidationInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
