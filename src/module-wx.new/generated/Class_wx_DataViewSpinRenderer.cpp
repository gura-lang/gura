//----------------------------------------------------------------------------
// wxDataViewSpinRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewSpinRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewSpinRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewSpinRenderer::~Object_wx_DataViewSpinRenderer()
{
}

Object *Object_wx_DataViewSpinRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewSpinRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewSpinRenderer:");
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
// Class implementation for wxDataViewSpinRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewSpinRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewSpinRenderer)
{
	return new Object_wx_DataViewSpinRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
