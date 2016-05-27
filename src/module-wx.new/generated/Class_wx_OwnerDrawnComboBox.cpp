//----------------------------------------------------------------------------
// wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Object_wx_OwnerDrawnComboBox::~Object_wx_OwnerDrawnComboBox()
{
}

Object *Object_wx_OwnerDrawnComboBox::Clone() const
{
	return nullptr;
}

String Object_wx_OwnerDrawnComboBox::ToString(bool exprFlag)
{
	String rtn("<wx.OwnerDrawnComboBox:");
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
// Class implementation for wxOwnerDrawnComboBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_OwnerDrawnComboBox)
{
}

Gura_ImplementDescendantCreator(wx_OwnerDrawnComboBox)
{
	return new Object_wx_OwnerDrawnComboBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
