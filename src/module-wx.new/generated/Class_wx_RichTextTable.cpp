//----------------------------------------------------------------------------
// wxRichTextTable
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextTable
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextTable
//----------------------------------------------------------------------------
Object_wx_RichTextTable::~Object_wx_RichTextTable()
{
}

Object *Object_wx_RichTextTable::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextTable::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextTable:");
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
// Class implementation for wxRichTextTable
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextTable)
{
}

Gura_ImplementDescendantCreator(wx_RichTextTable)
{
	return new Object_wx_RichTextTable((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
