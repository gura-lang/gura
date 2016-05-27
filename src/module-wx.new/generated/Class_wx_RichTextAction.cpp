//----------------------------------------------------------------------------
// wxRichTextAction
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextAction
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextAction
//----------------------------------------------------------------------------
Object_wx_RichTextAction::~Object_wx_RichTextAction()
{
}

Object *Object_wx_RichTextAction::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextAction::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextAction:");
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
// Class implementation for wxRichTextAction
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextAction)
{
}

Gura_ImplementDescendantCreator(wx_RichTextAction)
{
	return new Object_wx_RichTextAction((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
