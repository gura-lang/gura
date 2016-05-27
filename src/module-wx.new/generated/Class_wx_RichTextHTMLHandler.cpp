//----------------------------------------------------------------------------
// wxRichTextHTMLHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextHTMLHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Object_wx_RichTextHTMLHandler::~Object_wx_RichTextHTMLHandler()
{
}

Object *Object_wx_RichTextHTMLHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextHTMLHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextHTMLHandler:");
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
// Class implementation for wxRichTextHTMLHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextHTMLHandler)
{
}

Gura_ImplementDescendantCreator(wx_RichTextHTMLHandler)
{
	return new Object_wx_RichTextHTMLHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
