//----------------------------------------------------------------------------
// wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Object_wx_GridCellAutoWrapStringEditor::~Object_wx_GridCellAutoWrapStringEditor()
{
}

Object *Object_wx_GridCellAutoWrapStringEditor::Clone() const
{
	return nullptr;
}

String Object_wx_GridCellAutoWrapStringEditor::ToString(bool exprFlag)
{
	String rtn("<wx.GridCellAutoWrapStringEditor:");
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
// Class implementation for wxGridCellAutoWrapStringEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCellAutoWrapStringEditor)
{
}

Gura_ImplementDescendantCreator(wx_GridCellAutoWrapStringEditor)
{
	return new Object_wx_GridCellAutoWrapStringEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
