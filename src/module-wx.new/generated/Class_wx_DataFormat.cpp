//----------------------------------------------------------------------------
// wxDataFormat
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDataFormat
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDataFormat
//----------------------------------------------------------------------------
Object_wx_DataFormat::~Object_wx_DataFormat()
{
}

Object *Object_wx_DataFormat::Clone() const
{
	return nullptr;
}

String Object_wx_DataFormat::ToString(bool exprFlag)
{
	String rtn("<wx.DataFormat:");
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
// Class implementation for wxDataFormat
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DataFormat)
{
}

Gura_ImplementDescendantCreator(wx_DataFormat)
{
	return new Object_wx_DataFormat((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
