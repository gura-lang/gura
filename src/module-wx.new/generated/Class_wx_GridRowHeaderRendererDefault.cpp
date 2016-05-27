//----------------------------------------------------------------------------
// wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
Object_wx_GridRowHeaderRendererDefault::~Object_wx_GridRowHeaderRendererDefault()
{
}

Object *Object_wx_GridRowHeaderRendererDefault::Clone() const
{
	return nullptr;
}

String Object_wx_GridRowHeaderRendererDefault::ToString(bool exprFlag)
{
	String rtn("<wx.GridRowHeaderRendererDefault:");
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
// Class implementation for wxGridRowHeaderRendererDefault
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridRowHeaderRendererDefault)
{
}

Gura_ImplementDescendantCreator(wx_GridRowHeaderRendererDefault)
{
	return new Object_wx_GridRowHeaderRendererDefault((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
