//----------------------------------------------------------------------------
// wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextAttrDimensionConverter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
Object_wx_TextAttrDimensionConverter::~Object_wx_TextAttrDimensionConverter()
{
}

Object *Object_wx_TextAttrDimensionConverter::Clone() const
{
	return nullptr;
}

String Object_wx_TextAttrDimensionConverter::ToString(bool exprFlag)
{
	String rtn("<wx.TextAttrDimensionConverter:");
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
// Class implementation for wxTextAttrDimensionConverter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextAttrDimensionConverter)
{
}

Gura_ImplementDescendantCreator(wx_TextAttrDimensionConverter)
{
	return new Object_wx_TextAttrDimensionConverter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
