//----------------------------------------------------------------------------
// wxRichToolTip
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichToolTip
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichToolTip
//----------------------------------------------------------------------------
Object_wx_RichToolTip::~Object_wx_RichToolTip()
{
}

Object *Object_wx_RichToolTip::Clone() const
{
	return nullptr;
}

String Object_wx_RichToolTip::ToString(bool exprFlag)
{
	String rtn("<wx.RichToolTip:");
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
// Class implementation for wxRichToolTip
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichToolTip)
{
}

Gura_ImplementDescendantCreator(wx_RichToolTip)
{
	return new Object_wx_RichToolTip((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
