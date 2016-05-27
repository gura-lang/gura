//----------------------------------------------------------------------------
// wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
Object_wx_GridHeaderLabelsRenderer::~Object_wx_GridHeaderLabelsRenderer()
{
}

Object *Object_wx_GridHeaderLabelsRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridHeaderLabelsRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridHeaderLabelsRenderer:");
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
// Class implementation for wxGridHeaderLabelsRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridHeaderLabelsRenderer)
{
}

Gura_ImplementDescendantCreator(wx_GridHeaderLabelsRenderer)
{
	return new Object_wx_GridHeaderLabelsRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
