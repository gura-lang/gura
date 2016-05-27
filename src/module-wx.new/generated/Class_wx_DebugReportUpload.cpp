//----------------------------------------------------------------------------
// wxDebugReportUpload
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportUpload
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Object_wx_DebugReportUpload::~Object_wx_DebugReportUpload()
{
}

Object *Object_wx_DebugReportUpload::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReportUpload::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportUpload:");
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
// Class implementation for wxDebugReportUpload
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportUpload)
{
}

Gura_ImplementDescendantCreator(wx_DebugReportUpload)
{
	return new Object_wx_DebugReportUpload((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
