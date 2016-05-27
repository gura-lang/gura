//----------------------------------------------------------------------------
// wxStringClientData
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxStringClientData
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxStringClientData
//----------------------------------------------------------------------------
Object_wx_StringClientData::~Object_wx_StringClientData()
{
}

Object *Object_wx_StringClientData::Clone() const
{
	return nullptr;
}

String Object_wx_StringClientData::ToString(bool exprFlag)
{
	String rtn("<wx.StringClientData:");
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
// Class implementation for wxStringClientData
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_StringClientData)
{
}

Gura_ImplementDescendantCreator(wx_StringClientData)
{
	return new Object_wx_StringClientData((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
