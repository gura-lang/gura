//----------------------------------------------------------------------------
// wxRichTextCommand
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextCommand
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextCommand
//----------------------------------------------------------------------------
Object_wx_RichTextCommand::~Object_wx_RichTextCommand()
{
}

Object *Object_wx_RichTextCommand::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextCommand::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextCommand:");
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
// Class implementation for wxRichTextCommand
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextCommand)
{
}

Gura_ImplementDescendantCreator(wx_RichTextCommand)
{
	return new Object_wx_RichTextCommand((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
