//----------------------------------------------------------------------------
// wxFontList
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontList
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontList
//----------------------------------------------------------------------------
Object_wx_FontList::~Object_wx_FontList()
{
}

Object *Object_wx_FontList::Clone() const
{
	return nullptr;
}

String Object_wx_FontList::ToString(bool exprFlag)
{
	String rtn("<wx.FontList:");
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
// Class implementation for wxFontList
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontList)
{
}

Gura_ImplementDescendantCreator(wx_FontList)
{
	return new Object_wx_FontList((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
