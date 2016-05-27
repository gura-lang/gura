//----------------------------------------------------------------------------
// wxTextAttrDimensions
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrDimensions
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrDimensions
//----------------------------------------------------------------------------
Object_wx_TextAttrDimensions::~Object_wx_TextAttrDimensions()
{
}

Object *Object_wx_TextAttrDimensions::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrDimensions::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrDimensions:");
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
// Class implementation for wxTextAttrDimensions
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrDimensions)
{
}

Gura_ImplementDescendantCreator(wx_TextAttrDimensions)
{
	return new Object_wx_TextAttrDimensions((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
