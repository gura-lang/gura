//----------------------------------------------------------------------------
// wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewBitmapRenderer::~Object_wx_DataViewBitmapRenderer()
{
}

Object *Object_wx_DataViewBitmapRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewBitmapRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewBitmapRenderer:");
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
// Class implementation for wxDataViewBitmapRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewBitmapRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewBitmapRenderer)
{
	return new Object_wx_DataViewBitmapRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
