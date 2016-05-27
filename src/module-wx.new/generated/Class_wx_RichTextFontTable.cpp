//----------------------------------------------------------------------------
// wxRichTextFontTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFontTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFontTable
//----------------------------------------------------------------------------
Object_wx_RichTextFontTable::~Object_wx_RichTextFontTable()
{
}

Object *Object_wx_RichTextFontTable::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFontTable::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFontTable:");
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
// Class implementation for wxRichTextFontTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFontTable)
{
}

Gura_ImplementDescendantCreator(wx_RichTextFontTable)
{
	return new Object_wx_RichTextFontTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
