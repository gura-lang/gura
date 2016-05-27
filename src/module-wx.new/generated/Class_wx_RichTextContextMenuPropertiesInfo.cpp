//----------------------------------------------------------------------------
// wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
Object_wx_RichTextContextMenuPropertiesInfo::~Object_wx_RichTextContextMenuPropertiesInfo()
{
}

Object *Object_wx_RichTextContextMenuPropertiesInfo::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextContextMenuPropertiesInfo::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextContextMenuPropertiesInfo:");
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
// Class implementation for wxRichTextContextMenuPropertiesInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextContextMenuPropertiesInfo)
{
}

Gura_ImplementDescendantCreator(wx_RichTextContextMenuPropertiesInfo)
{
	return new Object_wx_RichTextContextMenuPropertiesInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
