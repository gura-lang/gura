//----------------------------------------------------------------------------
// wxVariantDataErrorCode
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantDataErrorCode
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariantDataErrorCode
//----------------------------------------------------------------------------
Object_wx_VariantDataErrorCode::~Object_wx_VariantDataErrorCode()
{
}

Object *Object_wx_VariantDataErrorCode::Clone() const
{
	return nullptr;
}

String Object_wx_VariantDataErrorCode::ToString(bool exprFlag)
{
	String rtn("<wx.VariantDataErrorCode:");
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
// Class implementation for wxVariantDataErrorCode
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantDataErrorCode)
{
}

Gura_ImplementDescendantCreator(wx_VariantDataErrorCode)
{
	return new Object_wx_VariantDataErrorCode((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
