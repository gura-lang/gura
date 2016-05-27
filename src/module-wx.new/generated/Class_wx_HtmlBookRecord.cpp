//----------------------------------------------------------------------------
// wxHtmlBookRecord
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHtmlBookRecord
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHtmlBookRecord
//----------------------------------------------------------------------------
Object_wx_HtmlBookRecord::~Object_wx_HtmlBookRecord()
{
}

Object *Object_wx_HtmlBookRecord::Clone() const
{
	return nullptr;
}

String Object_wx_HtmlBookRecord::ToString(bool exprFlag)
{
	String rtn("<wx.HtmlBookRecord:");
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
// Class implementation for wxHtmlBookRecord
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HtmlBookRecord)
{
}

Gura_ImplementDescendantCreator(wx_HtmlBookRecord)
{
	return new Object_wx_HtmlBookRecord((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
