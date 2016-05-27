//----------------------------------------------------------------------------
// wxRichTextObjectAddress
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextObjectAddress
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextObjectAddress
//----------------------------------------------------------------------------
Object_wx_RichTextObjectAddress::~Object_wx_RichTextObjectAddress()
{
}

Object *Object_wx_RichTextObjectAddress::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextObjectAddress::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextObjectAddress:");
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
// Class implementation for wxRichTextObjectAddress
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextObjectAddress)
{
}

Gura_ImplementDescendantCreator(wx_RichTextObjectAddress)
{
	return new Object_wx_RichTextObjectAddress((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
