//----------------------------------------------------------------------------
// wxDocMDIChildFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocMDIChildFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocMDIChildFrame
//----------------------------------------------------------------------------
Object_wx_DocMDIChildFrame::~Object_wx_DocMDIChildFrame()
{
}

Object *Object_wx_DocMDIChildFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocMDIChildFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocMDIChildFrame:");
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
// Class implementation for wxDocMDIChildFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocMDIChildFrame)
{
}

Gura_ImplementDescendantCreator(wx_DocMDIChildFrame)
{
	return new Object_wx_DocMDIChildFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
