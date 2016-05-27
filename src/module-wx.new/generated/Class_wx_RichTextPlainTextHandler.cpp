//----------------------------------------------------------------------------
// wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextPlainTextHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
Object_wx_RichTextPlainTextHandler::~Object_wx_RichTextPlainTextHandler()
{
}

Object *Object_wx_RichTextPlainTextHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextPlainTextHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextPlainTextHandler:");
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
// Class implementation for wxRichTextPlainTextHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextPlainTextHandler)
{
}

Gura_ImplementDescendantCreator(wx_RichTextPlainTextHandler)
{
	return new Object_wx_RichTextPlainTextHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
