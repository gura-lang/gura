//----------------------------------------------------------------------------
// wxDocTemplate
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDocTemplate
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDocTemplate
//----------------------------------------------------------------------------
Object_wx_DocTemplate::~Object_wx_DocTemplate()
{
}

Object *Object_wx_DocTemplate::Clone() const
{
	return nullptr;
}

String Object_wx_DocTemplate::ToString(bool exprFlag)
{
	String rtn("<wx.DocTemplate:");
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
Gura_DeclareMethod(wx_DocTemplate, wxDocTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "descr", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "docTypeName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "viewTypeName", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "docClassInfo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "viewClassInfo", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, wxDocTemplate)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int manager = arg.GetNumber(0)
	//int descr = arg.GetNumber(1)
	//int filter = arg.GetNumber(2)
	//int dir = arg.GetNumber(3)
	//int ext = arg.GetNumber(4)
	//int docTypeName = arg.GetNumber(5)
	//int viewTypeName = arg.GetNumber(6)
	//int docClassInfo = arg.GetNumber(7)
	//int viewClassInfo = arg.GetNumber(8)
	//int flags = arg.GetNumber(9)
	//pThis->GetEntity()->wxDocTemplate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, CreateDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, CreateDocument)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->CreateDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, CreateView)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, CreateView)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->CreateView();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, FileMatchesTemplate)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, FileMatchesTemplate)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->FileMatchesTemplate();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetDefaultExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetDefaultExtension)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetDescription)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetDirectory)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetDocClassInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetDocClassInfo)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocClassInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetDocumentManager)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetDocumentName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetDocumentName)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetFileFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetFileFilter)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileFilter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetFlags)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetPageSetupDialogData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetPageSetupDialogData)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetPageSetupDialogData_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetPageSetupDialogData_1)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetViewClassInfo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetViewClassInfo)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewClassInfo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, GetViewName)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, GetViewName)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewName();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, InitDocument)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, InitDocument)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->InitDocument();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, IsVisible)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, IsVisible)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetDefaultExtension)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDefaultExtension)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ext = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultExtension();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetDescription)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDescription)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int descr = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescription();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetDirectory)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDirectory)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirectory();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetDocumentManager)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetDocumentManager)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int manager = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentManager();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetFileFilter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetFileFilter)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileFilter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_DocTemplate, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, SetFlags)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDocTemplate
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_DocTemplate)
{
	Gura_AssignMethod(wx_DocTemplate, wxDocTemplate);
	Gura_AssignMethod(wx_DocTemplate, CreateDocument);
	Gura_AssignMethod(wx_DocTemplate, CreateView);
	Gura_AssignMethod(wx_DocTemplate, FileMatchesTemplate);
	Gura_AssignMethod(wx_DocTemplate, GetDefaultExtension);
	Gura_AssignMethod(wx_DocTemplate, GetDescription);
	Gura_AssignMethod(wx_DocTemplate, GetDirectory);
	Gura_AssignMethod(wx_DocTemplate, GetDocClassInfo);
	Gura_AssignMethod(wx_DocTemplate, GetDocumentManager);
	Gura_AssignMethod(wx_DocTemplate, GetDocumentName);
	Gura_AssignMethod(wx_DocTemplate, GetFileFilter);
	Gura_AssignMethod(wx_DocTemplate, GetFlags);
	Gura_AssignMethod(wx_DocTemplate, GetPageSetupDialogData);
	Gura_AssignMethod(wx_DocTemplate, GetPageSetupDialogData_1);
	Gura_AssignMethod(wx_DocTemplate, GetViewClassInfo);
	Gura_AssignMethod(wx_DocTemplate, GetViewName);
	Gura_AssignMethod(wx_DocTemplate, InitDocument);
	Gura_AssignMethod(wx_DocTemplate, IsVisible);
	Gura_AssignMethod(wx_DocTemplate, SetDefaultExtension);
	Gura_AssignMethod(wx_DocTemplate, SetDescription);
	Gura_AssignMethod(wx_DocTemplate, SetDirectory);
	Gura_AssignMethod(wx_DocTemplate, SetDocumentManager);
	Gura_AssignMethod(wx_DocTemplate, SetFileFilter);
	Gura_AssignMethod(wx_DocTemplate, SetFlags);
}

Gura_ImplementDescendantCreator(wx_DocTemplate)
{
	return new Object_wx_DocTemplate((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
