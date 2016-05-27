//----------------------------------------------------------------------------
// wxDocParentFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocParentFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocParentFrame
//----------------------------------------------------------------------------
Object_wx_DocParentFrame::~Object_wx_DocParentFrame()
{
}

Object *Object_wx_DocParentFrame::Clone() const
{
	return nullptr;
}

String Object_wx_DocParentFrame::ToString(bool exprFlag)
{
	String rtn("<wx.DocParentFrame:");
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
// Class implementation for wxDocParentFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocParentFrame)
{
}

Gura_ImplementDescendantCreator(wx_DocParentFrame)
{
	return new Object_wx_DocParentFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
