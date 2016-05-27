//----------------------------------------------------------------------------
// wxGridCellChoiceEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellChoiceEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Object_wx_GridCellChoiceEditor::~Object_wx_GridCellChoiceEditor()
{
}

Object *Object_wx_GridCellChoiceEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellChoiceEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellChoiceEditor:");
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
// Class implementation for wxGridCellChoiceEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellChoiceEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellChoiceEditor)
{
	return new Object_wx_GridCellChoiceEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
