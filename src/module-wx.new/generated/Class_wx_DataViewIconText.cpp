//----------------------------------------------------------------------------
// wxDataViewIconText
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewIconText
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewIconText
//----------------------------------------------------------------------------
Object_wx_DataViewIconText::~Object_wx_DataViewIconText()
{
}

Object *Object_wx_DataViewIconText::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewIconText::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewIconText:");
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
// Class implementation for wxDataViewIconText
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewIconText)
{
}

Gura_ImplementDescendantCreator(wx_DataViewIconText)
{
	return new Object_wx_DataViewIconText((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
