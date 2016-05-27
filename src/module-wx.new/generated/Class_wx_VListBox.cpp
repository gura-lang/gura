//----------------------------------------------------------------------------
// wxVListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxVListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxVListBox
//----------------------------------------------------------------------------
Object_wx_VListBox::~Object_wx_VListBox()
{
}

Object *Object_wx_VListBox::Clone() const
{
	return nullptr;
}

String Object_wx_VListBox::ToString(bool exprFlag)
{
	String rtn("<wx.VListBox:");
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
// Class implementation for wxVListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_VListBox)
{
}

Gura_ImplementDescendantCreator(wx_VListBox)
{
	return new Object_wx_VListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
