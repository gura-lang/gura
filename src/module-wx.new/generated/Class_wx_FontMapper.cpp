//----------------------------------------------------------------------------
// wxFontMapper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFontMapper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFontMapper
//----------------------------------------------------------------------------
Object_wx_FontMapper::~Object_wx_FontMapper()
{
}

Object *Object_wx_FontMapper::Clone() const
{
	return nullptr;
}

String Object_wx_FontMapper::ToString(bool exprFlag)
{
	String rtn("<wx.FontMapper:");
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
// Class implementation for wxFontMapper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FontMapper)
{
}

Gura_ImplementDescendantCreator(wx_FontMapper)
{
	return new Object_wx_FontMapper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
