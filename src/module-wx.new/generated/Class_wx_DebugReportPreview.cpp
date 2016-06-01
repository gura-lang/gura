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
Gura_DeclareMethod(wx_DebugReportPreview, wxDebugReportPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugReportPreview, wxDebugReportPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportPreview *pThis = Object_wx_DebugReportPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDebugReportPreview();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReportPreview, ~wxDebugReportPreview)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DebugReportPreview, ~wxDebugReportPreview)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportPreview *pThis = Object_wx_DebugReportPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDebugReportPreview();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DebugReportPreview, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dbgrpt", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DebugReportPreview, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_DebugReportPreview *pThis = Object_wx_DebugReportPreview::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dbgrpt = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDebugReportPreview
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DebugReportPreview)
{
	Gura_AssignMethod(wx_DebugReportPreview, wxDebugReportPreview);
	Gura_AssignMethod(wx_DebugReportPreview, ~wxDebugReportPreview);
	Gura_AssignMethod(wx_DebugReportPreview, Show);
}

Gura_ImplementDescendantCreator(wx_DebugReportPreview)
{
	return new Object_wx_DebugReportPreview((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
