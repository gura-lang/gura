//----------------------------------------------------------------------------
// wxDataViewModelNotifier
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewModelNotifier
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewModelNotifier
//----------------------------------------------------------------------------
Object_wx_DataViewModelNotifier::~Object_wx_DataViewModelNotifier()
{
}

Object *Object_wx_DataViewModelNotifier::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewModelNotifier::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewModelNotifier:");
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
// Class implementation for wxDataViewModelNotifier
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewModelNotifier)
{
}

Gura_ImplementDescendantCreator(wx_DataViewModelNotifier)
{
	return new Object_wx_DataViewModelNotifier((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
