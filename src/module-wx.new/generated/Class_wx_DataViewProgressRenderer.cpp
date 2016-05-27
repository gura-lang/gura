//----------------------------------------------------------------------------
// wxDataViewProgressRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewProgressRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewProgressRenderer::~Object_wx_DataViewProgressRenderer()
{
}

Object *Object_wx_DataViewProgressRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewProgressRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewProgressRenderer:");
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
// Class implementation for wxDataViewProgressRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewProgressRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewProgressRenderer)
{
	return new Object_wx_DataViewProgressRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
