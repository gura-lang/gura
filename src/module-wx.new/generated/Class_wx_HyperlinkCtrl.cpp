//----------------------------------------------------------------------------
// wxHyperlinkCtrl
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxHyperlinkCtrl
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Object_wx_HyperlinkCtrl::~Object_wx_HyperlinkCtrl()
{
}

Object *Object_wx_HyperlinkCtrl::Clone() const
{
	return nullptr;
}

String Object_wx_HyperlinkCtrl::ToString(bool exprFlag)
{
	String rtn("<wx.HyperlinkCtrl:");
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
// Class implementation for wxHyperlinkCtrl
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_HyperlinkCtrl)
{
}

Gura_ImplementDescendantCreator(wx_HyperlinkCtrl)
{
	return new Object_wx_HyperlinkCtrl((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
