//----------------------------------------------------------------------------
// wxPGEditor
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPGEditor
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPGEditor
//----------------------------------------------------------------------------
Object_wx_PGEditor::~Object_wx_PGEditor()
{
}

Object *Object_wx_PGEditor::Clone() const
{
	return nullptr;
}

String Object_wx_PGEditor::ToString(bool exprFlag)
{
	String rtn("<wx.PGEditor:");
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
// Class implementation for wxPGEditor
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PGEditor)
{
}

Gura_ImplementDescendantCreator(wx_PGEditor)
{
	return new Object_wx_PGEditor((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
