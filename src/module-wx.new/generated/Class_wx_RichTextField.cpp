//----------------------------------------------------------------------------
// wxRichTextField
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextField
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextField
//----------------------------------------------------------------------------
Object_wx_RichTextField::~Object_wx_RichTextField()
{
}

Object *Object_wx_RichTextField::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextField::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextField:");
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
// Class implementation for wxRichTextField
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextField)
{
}

Gura_ImplementDescendantCreator(wx_RichTextField)
{
	return new Object_wx_RichTextField((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
