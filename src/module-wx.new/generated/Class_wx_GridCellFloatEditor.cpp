//----------------------------------------------------------------------------
// wxGridCellFloatEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellFloatEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Object_wx_GridCellFloatEditor::~Object_wx_GridCellFloatEditor()
{
}

Object *Object_wx_GridCellFloatEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellFloatEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellFloatEditor:");
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
// Class implementation for wxGridCellFloatEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellFloatEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellFloatEditor)
{
	return new Object_wx_GridCellFloatEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
