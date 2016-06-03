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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxDocTemplate, "wxDocTemplate")
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
	SetClassToConstruct(Gura_UserClass(wx_DocTemplate));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDocTemplate)
{
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
	//wxDocTemplate();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_DocTemplate, __CreateDocument, "CreateDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __CreateDocument)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->CreateDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __CreateView, "CreateView")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __CreateView)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->CreateView();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __FileMatchesTemplate, "FileMatchesTemplate")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __FileMatchesTemplate)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int path = arg.GetNumber(0)
	//pThis->GetEntity()->FileMatchesTemplate();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetDefaultExtension, "GetDefaultExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetDefaultExtension)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDefaultExtension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetDescription, "GetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetDescription)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetDirectory, "GetDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetDirectory)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetDocClassInfo, "GetDocClassInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetDocClassInfo)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocClassInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetDocumentManager, "GetDocumentManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetDocumentManager)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetDocumentName, "GetDocumentName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetDocumentName)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDocumentName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetFileFilter, "GetFileFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetFileFilter)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFileFilter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetFlags)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetPageSetupDialogData, "GetPageSetupDialogData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetPageSetupDialogData)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetPageSetupDialogData_1, "GetPageSetupDialogData_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetPageSetupDialogData_1)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupDialogData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetViewClassInfo, "GetViewClassInfo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetViewClassInfo)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewClassInfo();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __GetViewName, "GetViewName")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __GetViewName)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetViewName();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __InitDocument, "InitDocument")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "doc", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "path", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __InitDocument)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int doc = arg.GetNumber(0)
	//int path = arg.GetNumber(1)
	//int flags = arg.GetNumber(2)
	//pThis->GetEntity()->InitDocument();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __IsVisible, "IsVisible")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_DocTemplate, __IsVisible)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsVisible();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __SetDefaultExtension, "SetDefaultExtension")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ext", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __SetDefaultExtension)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ext = arg.GetNumber(0)
	//pThis->GetEntity()->SetDefaultExtension();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __SetDescription, "SetDescription")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "descr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __SetDescription)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int descr = arg.GetNumber(0)
	//pThis->GetEntity()->SetDescription();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __SetDirectory, "SetDirectory")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dir", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __SetDirectory)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dir = arg.GetNumber(0)
	//pThis->GetEntity()->SetDirectory();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __SetDocumentManager, "SetDocumentManager")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "manager", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __SetDocumentManager)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int manager = arg.GetNumber(0)
	//pThis->GetEntity()->SetDocumentManager();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __SetFileFilter, "SetFileFilter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "filter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __SetFileFilter)
{
	Object_wx_DocTemplate *pThis = Object_wx_DocTemplate::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int filter = arg.GetNumber(0)
	//pThis->GetEntity()->SetFileFilter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_DocTemplate, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_DocTemplate, __SetFlags)
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
	// Constructor assignment
	Gura_AssignFunction(__wxDocTemplate);
	// Method assignment
	Gura_AssignMethod(wx_DocTemplate, __CreateDocument);
	Gura_AssignMethod(wx_DocTemplate, __CreateView);
	Gura_AssignMethod(wx_DocTemplate, __FileMatchesTemplate);
	Gura_AssignMethod(wx_DocTemplate, __GetDefaultExtension);
	Gura_AssignMethod(wx_DocTemplate, __GetDescription);
	Gura_AssignMethod(wx_DocTemplate, __GetDirectory);
	Gura_AssignMethod(wx_DocTemplate, __GetDocClassInfo);
	Gura_AssignMethod(wx_DocTemplate, __GetDocumentManager);
	Gura_AssignMethod(wx_DocTemplate, __GetDocumentName);
	Gura_AssignMethod(wx_DocTemplate, __GetFileFilter);
	Gura_AssignMethod(wx_DocTemplate, __GetFlags);
	Gura_AssignMethod(wx_DocTemplate, __GetPageSetupDialogData);
	Gura_AssignMethod(wx_DocTemplate, __GetPageSetupDialogData_1);
	Gura_AssignMethod(wx_DocTemplate, __GetViewClassInfo);
	Gura_AssignMethod(wx_DocTemplate, __GetViewName);
	Gura_AssignMethod(wx_DocTemplate, __InitDocument);
	Gura_AssignMethod(wx_DocTemplate, __IsVisible);
	Gura_AssignMethod(wx_DocTemplate, __SetDefaultExtension);
	Gura_AssignMethod(wx_DocTemplate, __SetDescription);
	Gura_AssignMethod(wx_DocTemplate, __SetDirectory);
	Gura_AssignMethod(wx_DocTemplate, __SetDocumentManager);
	Gura_AssignMethod(wx_DocTemplate, __SetFileFilter);
	Gura_AssignMethod(wx_DocTemplate, __SetFlags);
}

Gura_ImplementDescendantCreator(wx_DocTemplate)
{
	return new Object_wx_DocTemplate((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
