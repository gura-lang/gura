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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__DebugReportPreview, "DebugReportPreview")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_DebugReportPreview));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__DebugReportPreview)
{
	//wxDebugReportPreview();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DebugReportPreview, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dbgrpt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportPreview, __Show)
{
	Object_wx_DebugReportPreview *pThis = Object_wx_DebugReportPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxDebugReport& dbgrpt = arg.GetNumber(0)
	//pThis->GetEntity()->Show(dbgrpt);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugReportPreview
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportPreview)
{
	// Constructor assignment
	Gura_AssignFunction(__DebugReportPreview);
	// Method assignment
	Gura_AssignMethod(wx_DebugReportPreview, __Show);
}

Gura_ImplementDescendantCreator(wx_DebugReportPreview)
{
	return new Object_wx_DebugReportPreview((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
