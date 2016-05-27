//----------------------------------------------------------------------------
// wxVariantData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariantData
//----------------------------------------------------------------------------
Object_wx_VariantData::~Object_wx_VariantData()
{
}

Object *Object_wx_VariantData::Clone() const
{
	return nullptr;
}

String Object_wx_VariantData::ToString(bool exprFlag)
{
	String rtn("<wx.VariantData:");
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
// Class implementation for wxVariantData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantData)
{
}

Gura_ImplementDescendantCreator(wx_VariantData)
{
	return new Object_wx_VariantData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
