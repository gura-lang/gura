//----------------------------------------------------------------------------
// wxPreviewFrame
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewFrame
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPreviewFrame
//----------------------------------------------------------------------------
Object_wx_PreviewFrame::~Object_wx_PreviewFrame()
{
}

Object *Object_wx_PreviewFrame::Clone() const
{
	return nullptr;
}

String Object_wx_PreviewFrame::ToString(bool exprFlag)
{
	String rtn("<wx.PreviewFrame:");
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
// Class implementation for wxPreviewFrame
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewFrame)
{
}

Gura_ImplementDescendantCreator(wx_PreviewFrame)
{
	return new Object_wx_PreviewFrame((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
