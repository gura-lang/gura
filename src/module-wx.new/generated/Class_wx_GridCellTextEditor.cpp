//----------------------------------------------------------------------------
// wxGridCellTextEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellTextEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellTextEditor
//----------------------------------------------------------------------------
Object_wx_GridCellTextEditor::~Object_wx_GridCellTextEditor()
{
}

Object *Object_wx_GridCellTextEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellTextEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellTextEditor:");
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
// Class implementation for wxGridCellTextEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellTextEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellTextEditor)
{
	return new Object_wx_GridCellTextEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
