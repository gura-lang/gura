//----------------------------------------------------------------------------
// wxGridCornerHeaderRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridCornerHeaderRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridCornerHeaderRenderer
//----------------------------------------------------------------------------
Object_wx_GridCornerHeaderRenderer::~Object_wx_GridCornerHeaderRenderer()
{
}

Object *Object_wx_GridCornerHeaderRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridCornerHeaderRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridCornerHeaderRenderer:");
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
// Class implementation for wxGridCornerHeaderRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridCornerHeaderRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridCornerHeaderRenderer)
{
	return new Object_wx_GridCornerHeaderRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
