//----------------------------------------------------------------------------
// wxDataViewRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewRenderer::~Object_wx_DataViewRenderer()
{
}

Object *Object_wx_DataViewRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewRenderer:");
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
// Class implementation for wxDataViewRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewRenderer)
{
	return new Object_wx_DataViewRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
