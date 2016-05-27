//----------------------------------------------------------------------------
// wxRichTextDrawingContext
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextDrawingContext
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextDrawingContext
//----------------------------------------------------------------------------
Object_wx_RichTextDrawingContext::~Object_wx_RichTextDrawingContext()
{
}

Object *Object_wx_RichTextDrawingContext::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextDrawingContext::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextDrawingContext:");
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
// Class implementation for wxRichTextDrawingContext
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextDrawingContext)
{
}

Gura_ImplementDescendantCreator(wx_RichTextDrawingContext)
{
	return new Object_wx_RichTextDrawingContext((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
