//----------------------------------------------------------------------------
// wxGridRowHeaderRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridRowHeaderRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridRowHeaderRenderer
//----------------------------------------------------------------------------
Object_wx_GridRowHeaderRenderer::~Object_wx_GridRowHeaderRenderer()
{
}

Object *Object_wx_GridRowHeaderRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridRowHeaderRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridRowHeaderRenderer:");
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
// Class implementation for wxGridRowHeaderRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridRowHeaderRenderer)
{
	// Class assignment
	Gura_AssignValueEx("GridRowHeaderRenderer", Reference());
}

Gura_ImplementDescendantCreator(wx_GridRowHeaderRenderer)
{
	return new Object_wx_GridRowHeaderRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
