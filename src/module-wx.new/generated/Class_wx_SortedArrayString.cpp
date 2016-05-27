//----------------------------------------------------------------------------
// wxSortedArrayString
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSortedArrayString
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSortedArrayString
//----------------------------------------------------------------------------
Object_wx_SortedArrayString::~Object_wx_SortedArrayString()
{
}

Object *Object_wx_SortedArrayString::Clone() const
{
	return nullptr;
}

String Object_wx_SortedArrayString::ToString(bool exprFlag)
{
	String rtn("<wx.SortedArrayString:");
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
// Class implementation for wxSortedArrayString
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SortedArrayString)
{
}

Gura_ImplementDescendantCreator(wx_SortedArrayString)
{
	return new Object_wx_SortedArrayString((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
