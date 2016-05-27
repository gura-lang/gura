//----------------------------------------------------------------------------
// wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
Object_wx_GridColumnHeaderRendererDefault::~Object_wx_GridColumnHeaderRendererDefault()
{
}

Object *Object_wx_GridColumnHeaderRendererDefault::Clone() const
{
	return nullptr;
}

String Object_wx_GridColumnHeaderRendererDefault::ToString(bool exprFlag)
{
	String rtn("<wx.GridColumnHeaderRendererDefault:");
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
// Class implementation for wxGridColumnHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridColumnHeaderRendererDefault)
{
}

Gura_ImplementDescendantCreator(wx_GridColumnHeaderRendererDefault)
{
	return new Object_wx_GridColumnHeaderRendererDefault((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
