//----------------------------------------------------------------------------
// wxPrintPreview
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintPreview
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintPreview
//----------------------------------------------------------------------------
Object_wx_PrintPreview::~Object_wx_PrintPreview()
{
}

Object *Object_wx_PrintPreview::Clone() const
{
	return nullptr;
}

String Object_wx_PrintPreview::ToString(bool exprFlag)
{
	String rtn("<wx.PrintPreview:");
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
// Class implementation for wxPrintPreview
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintPreview)
{
}

Gura_ImplementDescendantCreator(wx_PrintPreview)
{
	return new Object_wx_PrintPreview((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
