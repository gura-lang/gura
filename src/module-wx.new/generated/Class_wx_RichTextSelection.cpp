//----------------------------------------------------------------------------
// wxRichTextSelection
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextSelection
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextSelection
//----------------------------------------------------------------------------
Object_wx_RichTextSelection::~Object_wx_RichTextSelection()
{
}

Object *Object_wx_RichTextSelection::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextSelection::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextSelection:");
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
// Class implementation for wxRichTextSelection
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextSelection)
{
}

Gura_ImplementDescendantCreator(wx_RichTextSelection)
{
	return new Object_wx_RichTextSelection((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
