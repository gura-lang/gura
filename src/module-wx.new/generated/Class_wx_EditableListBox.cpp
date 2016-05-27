//----------------------------------------------------------------------------
// wxEditableListBox
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEditableListBox
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEditableListBox
//----------------------------------------------------------------------------
Object_wx_EditableListBox::~Object_wx_EditableListBox()
{
}

Object *Object_wx_EditableListBox::Clone() const
{
	return nullptr;
}

String Object_wx_EditableListBox::ToString(bool exprFlag)
{
	String rtn("<wx.EditableListBox:");
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
// Class implementation for wxEditableListBox
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EditableListBox)
{
}

Gura_ImplementDescendantCreator(wx_EditableListBox)
{
	return new Object_wx_EditableListBox((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
