//----------------------------------------------------------------------------
// wxVariantDataSafeArray
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVariantDataSafeArray
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVariantDataSafeArray
//----------------------------------------------------------------------------
Object_wx_VariantDataSafeArray::~Object_wx_VariantDataSafeArray()
{
}

Object *Object_wx_VariantDataSafeArray::Clone() const
{
	return nullptr;
}

String Object_wx_VariantDataSafeArray::ToString(bool exprFlag)
{
	String rtn("<wx.VariantDataSafeArray:");
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
// Class implementation for wxVariantDataSafeArray
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VariantDataSafeArray)
{
}

Gura_ImplementDescendantCreator(wx_VariantDataSafeArray)
{
	return new Object_wx_VariantDataSafeArray((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
