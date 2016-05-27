//----------------------------------------------------------------------------
// wxTextAttrDimension
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrDimension
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrDimension
//----------------------------------------------------------------------------
Object_wx_TextAttrDimension::~Object_wx_TextAttrDimension()
{
}

Object *Object_wx_TextAttrDimension::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrDimension::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrDimension:");
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
// Class implementation for wxTextAttrDimension
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrDimension)
{
}

Gura_ImplementDescendantCreator(wx_TextAttrDimension)
{
	return new Object_wx_TextAttrDimension((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
