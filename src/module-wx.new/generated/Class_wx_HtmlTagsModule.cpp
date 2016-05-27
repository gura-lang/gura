//----------------------------------------------------------------------------
// wxHtmlTagsModule
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlTagsModule
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlTagsModule
//----------------------------------------------------------------------------
Object_wx_HtmlTagsModule::~Object_wx_HtmlTagsModule()
{
}

Object *Object_wx_HtmlTagsModule::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlTagsModule::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlTagsModule:");
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
// Class implementation for wxHtmlTagsModule
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlTagsModule)
{
}

Gura_ImplementDescendantCreator(wx_HtmlTagsModule)
{
	return new Object_wx_HtmlTagsModule((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
