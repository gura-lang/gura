//----------------------------------------------------------------------------
// wxPropertyGridIterator
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPropertyGridIterator
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPropertyGridIterator
//----------------------------------------------------------------------------
Object_wx_PropertyGridIterator::~Object_wx_PropertyGridIterator()
{
}

Object *Object_wx_PropertyGridIterator::Clone() const
{
	return nullptr;
}

String Object_wx_PropertyGridIterator::ToString(bool exprFlag)
{
	String rtn("<wx.PropertyGridIterator:");
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
// Class implementation for wxPropertyGridIterator
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PropertyGridIterator)
{
}

Gura_ImplementDescendantCreator(wx_PropertyGridIterator)
{
	return new Object_wx_PropertyGridIterator((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
