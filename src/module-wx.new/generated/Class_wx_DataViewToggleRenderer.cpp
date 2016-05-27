//----------------------------------------------------------------------------
// wxDataViewToggleRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewToggleRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewToggleRenderer::~Object_wx_DataViewToggleRenderer()
{
}

Object *Object_wx_DataViewToggleRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewToggleRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewToggleRenderer:");
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
// Class implementation for wxDataViewToggleRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewToggleRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewToggleRenderer)
{
	return new Object_wx_DataViewToggleRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
