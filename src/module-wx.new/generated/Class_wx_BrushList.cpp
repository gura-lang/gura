//----------------------------------------------------------------------------
// wxBrushList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxBrushList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxBrushList
//----------------------------------------------------------------------------
Object_wx_BrushList::~Object_wx_BrushList()
{
}

Object *Object_wx_BrushList::Clone() const
{
	return nullptr;
}

String Object_wx_BrushList::ToString(bool exprFlag)
{
	String rtn("<wx.BrushList:");
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
// Class implementation for wxBrushList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_BrushList)
{
}

Gura_ImplementDescendantCreator(wx_BrushList)
{
	return new Object_wx_BrushList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
