//----------------------------------------------------------------------------
// wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Object_wx_RichTextHeaderFooterData::~Object_wx_RichTextHeaderFooterData()
{
}

Object *Object_wx_RichTextHeaderFooterData::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextHeaderFooterData::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextHeaderFooterData:");
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
// Class implementation for wxRichTextHeaderFooterData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextHeaderFooterData)
{
}

Gura_ImplementDescendantCreator(wx_RichTextHeaderFooterData)
{
	return new Object_wx_RichTextHeaderFooterData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
