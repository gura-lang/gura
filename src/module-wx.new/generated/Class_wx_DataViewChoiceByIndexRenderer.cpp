//----------------------------------------------------------------------------
// wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
Object_wx_DataViewChoiceByIndexRenderer::~Object_wx_DataViewChoiceByIndexRenderer()
{
}

Object *Object_wx_DataViewChoiceByIndexRenderer::Clone() const
{
	return nullptr;
}

String Object_wx_DataViewChoiceByIndexRenderer::ToString(bool exprFlag)
{
	String rtn("<wx.DataViewChoiceByIndexRenderer:");
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
// Class implementation for wxDataViewChoiceByIndexRenderer
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataViewChoiceByIndexRenderer)
{
}

Gura_ImplementDescendantCreator(wx_DataViewChoiceByIndexRenderer)
{
	return new Object_wx_DataViewChoiceByIndexRenderer((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
