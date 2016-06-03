//----------------------------------------------------------------------------
// wxDebugReportPreviewStd
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDebugReportPreviewStd
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Object_wx_DebugReportPreviewStd::~Object_wx_DebugReportPreviewStd()
{
}

Object *Object_wx_DebugReportPreviewStd::Clone() const
{
	return nullptr;
}

String Object_wx_DebugReportPreviewStd::ToString(bool exprFlag)
{
	String rtn("<wx.DebugReportPreviewStd:");
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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxDebugReportPreviewStd, "wxDebugReportPreviewStd")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementFunction(__wxDebugReportPreviewStd)
{
	//wxDebugReportPreviewStd();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DebugReportPreviewStd, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dbgrpt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportPreviewStd, __Show)
{
	Object_wx_DebugReportPreviewStd *pThis = Object_wx_DebugReportPreviewStd::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dbgrpt = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugReportPreviewStd
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportPreviewStd)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDebugReportPreviewStd);
	// Method assignment
	Gura_AssignMethod(wx_DebugReportPreviewStd, __Show);
}

Gura_ImplementDescendantCreator(wx_DebugReportPreviewStd)
{
	return new Object_wx_DebugReportPreviewStd((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
