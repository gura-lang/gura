//----------------------------------------------------------------------------
// wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewIconTextRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewIconTextRenderer::~Object_wx_DataViewIconTextRenderer()
{
}

Object *Object_wx_DataViewIconTextRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewIconTextRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewIconTextRenderer:");
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
// Class implementation for wxDataViewIconTextRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewIconTextRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewIconTextRenderer)
{
	return new Object_wx_DataViewIconTextRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
