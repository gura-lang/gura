//----------------------------------------------------------------------------
// wxAddRemoveAdaptor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAddRemoveAdaptor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAddRemoveAdaptor
//----------------------------------------------------------------------------
Object_wx_AddRemoveAdaptor::~Object_wx_AddRemoveAdaptor()
{
}

Object *Object_wx_AddRemoveAdaptor::Clone() const
{
	return nullptr;
}

String Object_wx_AddRemoveAdaptor::ToString(bool exprFlag)
{
	String rtn("<wx.AddRemoveAdaptor:");
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
// Class implementation for wxAddRemoveAdaptor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AddRemoveAdaptor)
{
}

Gura_ImplementDescendantCreator(wx_AddRemoveAdaptor)
{
	return new Object_wx_AddRemoveAdaptor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
