//----------------------------------------------------------------------------
// wxFileDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFileDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFileDialog
//----------------------------------------------------------------------------
Object_wx_FileDialog::~Object_wx_FileDialog()
{
}

Object *Object_wx_FileDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FileDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FileDialog:");
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
// Class implementation for wxFileDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FileDialog)
{
}

Gura_ImplementDescendantCreator(wx_FileDialog)
{
	return new Object_wx_FileDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
