//----------------------------------------------------------------------------
// wxDataViewCustomRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewCustomRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewCustomRenderer::~Object_wx_DataViewCustomRenderer()
{
}

Object *Object_wx_DataViewCustomRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewCustomRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewCustomRenderer:");
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
// Class implementation for wxDataViewCustomRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewCustomRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewCustomRenderer)
{
	return new Object_wx_DataViewCustomRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
