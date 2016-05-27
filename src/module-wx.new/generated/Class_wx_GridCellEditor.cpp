//----------------------------------------------------------------------------
// wxGridCellEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellEditor
//----------------------------------------------------------------------------
Object_wx_GridCellEditor::~Object_wx_GridCellEditor()
{
}

Object *Object_wx_GridCellEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellEditor:");
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
// Class implementation for wxGridCellEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellEditor)
{
	return new Object_wx_GridCellEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
