//----------------------------------------------------------------------------
// wxLogRecordInfo
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLogRecordInfo
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLogRecordInfo
//----------------------------------------------------------------------------
Object_wx_LogRecordInfo::~Object_wx_LogRecordInfo()
{
}

Object *Object_wx_LogRecordInfo::Clone() const
{
	return nullptr;
}

String Object_wx_LogRecordInfo::ToString(bool exprFlag)
{
	String rtn("<wx.LogRecordInfo:");
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
// Class implementation for wxLogRecordInfo
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LogRecordInfo)
{
}

Gura_ImplementDescendantCreator(wx_LogRecordInfo)
{
	return new Object_wx_LogRecordInfo((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
