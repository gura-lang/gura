//----------------------------------------------------------------------------
// wxGridCellNumberEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellNumberEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Object_wx_GridCellNumberEditor::~Object_wx_GridCellNumberEditor()
{
}

Object *Object_wx_GridCellNumberEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellNumberEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellNumberEditor:");
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
// Class implementation for wxGridCellNumberEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellNumberEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellNumberEditor)
{
	return new Object_wx_GridCellNumberEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
