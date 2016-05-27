//----------------------------------------------------------------------------
// wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
Object_wx_GridCornerHeaderRendererDefault::~Object_wx_GridCornerHeaderRendererDefault()
{
}

Object *Object_wx_GridCornerHeaderRendererDefault::Clone() const
{
	return nullptr;
}

String Object_wx_GridCornerHeaderRendererDefault::ToString(bool exprFlag)
{
	String rtn("<wx.GridCornerHeaderRendererDefault:");
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
// Class implementation for wxGridCornerHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCornerHeaderRendererDefault)
{
}

Gura_ImplementDescendantCreator(wx_GridCornerHeaderRendererDefault)
{
	return new Object_wx_GridCornerHeaderRendererDefault((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
