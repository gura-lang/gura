//----------------------------------------------------------------------------
// wxDocMDIParentFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocMDIParentFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocMDIParentFrame
//----------------------------------------------------------------------------
Object_wx_DocMDIParentFrame::~Object_wx_DocMDIParentFrame()
{
}

Object *Object_wx_DocMDIParentFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocMDIParentFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocMDIParentFrame:");
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
// Class implementation for wxDocMDIParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocMDIParentFrame)
{
}

Gura_ImplementDescendantCreator(wx_DocMDIParentFrame)
{
	return new Object_wx_DocMDIParentFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
