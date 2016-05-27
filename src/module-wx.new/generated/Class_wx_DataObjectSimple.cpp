//----------------------------------------------------------------------------
// wxDataObjectSimple
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataObjectSimple
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataObjectSimple
//----------------------------------------------------------------------------
Object_wx_DataObjectSimple::~Object_wx_DataObjectSimple()
{
}

Object *Object_wx_DataObjectSimple::Clone() const
{
	return nullptr;
}

String Object_wx_DataObjectSimple::ToString(bool exprFlag)
{
	String rtn("<wx.DataObjectSimple:");
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
// Class implementation for wxDataObjectSimple
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataObjectSimple)
{
}

Gura_ImplementDescendantCreator(wx_DataObjectSimple)
{
	return new Object_wx_DataObjectSimple((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
