//----------------------------------------------------------------------------
// wxGridCellBoolEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellBoolEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Object_wx_GridCellBoolEditor::~Object_wx_GridCellBoolEditor()
{
}

Object *Object_wx_GridCellBoolEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellBoolEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellBoolEditor:");
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
// Class implementation for wxGridCellBoolEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellBoolEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellBoolEditor)
{
	return new Object_wx_GridCellBoolEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
