//----------------------------------------------------------------------------
// wxEncodingConverter
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxEncodingConverter
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxEncodingConverter
//----------------------------------------------------------------------------
Object_wx_EncodingConverter::~Object_wx_EncodingConverter()
{
}

Object *Object_wx_EncodingConverter::Clone() const
{
	return nullptr;
}

String Object_wx_EncodingConverter::ToString(bool exprFlag)
{
	String rtn("<wx.EncodingConverter:");
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
// Class implementation for wxEncodingConverter
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_EncodingConverter)
{
}

Gura_ImplementDescendantCreator(wx_EncodingConverter)
{
	return new Object_wx_EncodingConverter((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
