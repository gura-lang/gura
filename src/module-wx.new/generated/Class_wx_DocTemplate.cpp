//----------------------------------------------------------------------------
// wxDocTemplate
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocTemplate
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocTemplate
//----------------------------------------------------------------------------
Object_wx_DocTemplate::~Object_wx_DocTemplate()
{
}

Object *Object_wx_DocTemplate::Clone() const
{
	return nullptr;
}

String Object_wx_DocTemplate::ToString(bool exprFlag)
{
	String rtn("<wx.DocTemplate:");
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
// Class implementation for wxDocTemplate
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocTemplate)
{
}

Gura_ImplementDescendantCreator(wx_DocTemplate)
{
	return new Object_wx_DocTemplate((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
