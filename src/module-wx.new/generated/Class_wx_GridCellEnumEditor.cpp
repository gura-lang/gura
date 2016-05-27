//----------------------------------------------------------------------------
// wxGridCellEnumEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellEnumEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellEnumEditor
//----------------------------------------------------------------------------
Object_wx_GridCellEnumEditor::~Object_wx_GridCellEnumEditor()
{
}

Object *Object_wx_GridCellEnumEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellEnumEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellEnumEditor:");
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
// Class implementation for wxGridCellEnumEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellEnumEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellEnumEditor)
{
	return new Object_wx_GridCellEnumEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
