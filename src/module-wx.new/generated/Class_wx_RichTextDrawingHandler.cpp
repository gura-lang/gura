//----------------------------------------------------------------------------
// wxRichTextDrawingHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextDrawingHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextDrawingHandler
//----------------------------------------------------------------------------
Object_wx_RichTextDrawingHandler::~Object_wx_RichTextDrawingHandler()
{
}

Object *Object_wx_RichTextDrawingHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextDrawingHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextDrawingHandler:");
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
// Class implementation for wxRichTextDrawingHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextDrawingHandler)
{
}

Gura_ImplementDescendantCreator(wx_RichTextDrawingHandler)
{
	return new Object_wx_RichTextDrawingHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
