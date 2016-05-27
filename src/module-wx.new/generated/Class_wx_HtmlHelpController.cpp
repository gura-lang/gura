//----------------------------------------------------------------------------
// wxHtmlHelpController
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlHelpController
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlHelpController
//----------------------------------------------------------------------------
Object_wx_HtmlHelpController::~Object_wx_HtmlHelpController()
{
}

Object *Object_wx_HtmlHelpController::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlHelpController::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlHelpController:");
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
// Class implementation for wxHtmlHelpController
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlHelpController)
{
}

Gura_ImplementDescendantCreator(wx_HtmlHelpController)
{
	return new Object_wx_HtmlHelpController((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
