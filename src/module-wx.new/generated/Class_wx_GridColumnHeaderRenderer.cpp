//----------------------------------------------------------------------------
// wxGridColumnHeaderRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridColumnHeaderRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridColumnHeaderRenderer
//----------------------------------------------------------------------------
Object_wx_GridColumnHeaderRenderer::~Object_wx_GridColumnHeaderRenderer()
{
}

Object *Object_wx_GridColumnHeaderRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_GridColumnHeaderRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.GridColumnHeaderRenderer:");
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
// Class implementation for wxGridColumnHeaderRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridColumnHeaderRenderer)
{
	
}

Gura_ImplementDescendantCreator(wx_GridColumnHeaderRenderer)
{
	return new Object_wx_GridColumnHeaderRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
