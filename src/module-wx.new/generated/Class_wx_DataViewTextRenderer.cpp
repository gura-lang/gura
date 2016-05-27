//----------------------------------------------------------------------------
// wxDataViewTextRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewTextRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewTextRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewTextRenderer::~Object_wx_DataViewTextRenderer()
{
}

Object *Object_wx_DataViewTextRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewTextRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewTextRenderer:");
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
// Class implementation for wxDataViewTextRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewTextRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewTextRenderer)
{
	return new Object_wx_DataViewTextRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
