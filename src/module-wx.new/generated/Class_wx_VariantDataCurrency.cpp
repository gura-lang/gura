//----------------------------------------------------------------------------
// wxVariantDataCurrency
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantDataCurrency
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariantDataCurrency
//----------------------------------------------------------------------------
Object_wx_VariantDataCurrency::~Object_wx_VariantDataCurrency()
{
}

Object *Object_wx_VariantDataCurrency::Clone() const
{
	return nullptr;
}

String Object_wx_VariantDataCurrency::ToString(bool exprFlag)
{
	String rtn("<wx.VariantDataCurrency:");
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
// Class implementation for wxVariantDataCurrency
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantDataCurrency)
{
}

Gura_ImplementDescendantCreator(wx_VariantDataCurrency)
{
	return new Object_wx_VariantDataCurrency((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
