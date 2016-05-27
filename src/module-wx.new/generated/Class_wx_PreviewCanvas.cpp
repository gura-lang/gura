//----------------------------------------------------------------------------
// wxPreviewCanvas
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPreviewCanvas
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPreviewCanvas
//----------------------------------------------------------------------------
Object_wx_PreviewCanvas::~Object_wx_PreviewCanvas()
{
}

Object *Object_wx_PreviewCanvas::Clone() const
{
	return nullptr;
}

String Object_wx_PreviewCanvas::ToString(bool exprFlag)
{
	String rtn("<wx.PreviewCanvas:");
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
// Class implementation for wxPreviewCanvas
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PreviewCanvas)
{
}

Gura_ImplementDescendantCreator(wx_PreviewCanvas)
{
	return new Object_wx_PreviewCanvas((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
