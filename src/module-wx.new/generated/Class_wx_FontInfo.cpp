//----------------------------------------------------------------------------
// wxFontInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontInfo
//----------------------------------------------------------------------------
Object_wx_FontInfo::~Object_wx_FontInfo()
{
}

Object *Object_wx_FontInfo::Clone() const
{
	return nullptr;
}

String Object_wx_FontInfo::ToString(bool exprFlag)
{
	String rtn("<wx.FontInfo:");
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
// Class implementation for wxFontInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontInfo)
{
}

Gura_ImplementDescendantCreator(wx_FontInfo)
{
	return new Object_wx_FontInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
