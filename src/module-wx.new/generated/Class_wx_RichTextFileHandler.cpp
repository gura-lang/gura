//----------------------------------------------------------------------------
// wxRichTextFileHandler
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextFileHandler
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextFileHandler
//----------------------------------------------------------------------------
Object_wx_RichTextFileHandler::~Object_wx_RichTextFileHandler()
{
}

Object *Object_wx_RichTextFileHandler::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextFileHandler::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextFileHandler:");
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
// Class implementation for wxRichTextFileHandler
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextFileHandler)
{
}

Gura_ImplementDescendantCreator(wx_RichTextFileHandler)
{
	return new Object_wx_RichTextFileHandler((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
