//----------------------------------------------------------------------------
// wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewChoiceRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewChoiceRenderer::~Object_wx_DataViewChoiceRenderer()
{
}

Object *Object_wx_DataViewChoiceRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewChoiceRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewChoiceRenderer:");
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
// Class implementation for wxDataViewChoiceRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewChoiceRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewChoiceRenderer)
{
	return new Object_wx_DataViewChoiceRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
