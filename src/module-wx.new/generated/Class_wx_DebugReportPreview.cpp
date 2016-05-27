//----------------------------------------------------------------------------
// wxDebugReportPreview
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportPreview
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportPreview
//----------------------------------------------------------------------------
Object_wx_DebugReportPreview::~Object_wx_DebugReportPreview()
{
}

Object *Object_wx_DebugReportPreview::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReportPreview::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportPreview:");
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
// Class implementation for wxDebugReportPreview
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportPreview)
{
}

Gura_ImplementDescendantCreator(wx_DebugReportPreview)
{
	return new Object_wx_DebugReportPreview((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
