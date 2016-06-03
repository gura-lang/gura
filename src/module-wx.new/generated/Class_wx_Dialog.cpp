//----------------------------------------------------------------------------
// wxDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxDialog
//----------------------------------------------------------------------------
Object_wx_Dialog::~Object_wx_Dialog()
{
}

Object *Object_wx_Dialog::Clone() const
{
	return nullptr;
}

String Object_wx_Dialog::ToString(bool exprFlag)
{
	String rtn("<wx.Dialog:");
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
Gura_DeclareFunctionAlias(__wxDialog, "wxDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_Dialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDialog)
{
	//wxDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxDialog_1, "wxDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Dialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxDialog_1)
{
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//wxDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Dialog, __AddMainButtonId, "AddMainButtonId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __AddMainButtonId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->AddMainButtonId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __CanDoLayoutAdaptation, "CanDoLayoutAdaptation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __CanDoLayoutAdaptation)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->CanDoLayoutAdaptation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __Centre, "Centre")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __Centre)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Centre();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __Create)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __CreateButtonSizer, "CreateButtonSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __CreateButtonSizer)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CreateButtonSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __CreateSeparatedButtonSizer, "CreateSeparatedButtonSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __CreateSeparatedButtonSizer)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CreateSeparatedButtonSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __CreateSeparatedSizer, "CreateSeparatedSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __CreateSeparatedSizer)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->CreateSeparatedSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __CreateStdDialogButtonSizer, "CreateStdDialogButtonSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __CreateStdDialogButtonSizer)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CreateStdDialogButtonSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __CreateTextSizer, "CreateTextSizer")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __CreateTextSizer)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->CreateTextSizer();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __DoLayoutAdaptation, "DoLayoutAdaptation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __DoLayoutAdaptation)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->DoLayoutAdaptation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __EnableLayoutAdaptation, "EnableLayoutAdaptation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __EnableLayoutAdaptation)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableLayoutAdaptation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __EndModal, "EndModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __EndModal)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int retCode = arg.GetNumber(0)
	//pThis->GetEntity()->EndModal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetAffirmativeId, "GetAffirmativeId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetAffirmativeId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetAffirmativeId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetContentWindow, "GetContentWindow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetContentWindow)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetContentWindow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetEscapeId, "GetEscapeId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetEscapeId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetEscapeId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetLayoutAdaptationDone, "GetLayoutAdaptationDone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetLayoutAdaptationDone)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutAdaptationDone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetLayoutAdaptationLevel, "GetLayoutAdaptationLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetLayoutAdaptationLevel)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutAdaptationLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetLayoutAdaptationMode, "GetLayoutAdaptationMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetLayoutAdaptationMode)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutAdaptationMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetLayoutAdapter, "GetLayoutAdapter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetLayoutAdapter)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutAdapter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetMainButtonIds, "GetMainButtonIds")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetMainButtonIds)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMainButtonIds();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetReturnCode, "GetReturnCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetReturnCode)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetReturnCode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __GetToolBar, "GetToolBar")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __GetToolBar)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __Iconize, "Iconize")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __Iconize)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int iconize = arg.GetNumber(0)
	//pThis->GetEntity()->Iconize();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __IsIconized, "IsIconized")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __IsIconized)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsIconized();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __IsLayoutAdaptationEnabled, "IsLayoutAdaptationEnabled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __IsLayoutAdaptationEnabled)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsLayoutAdaptationEnabled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __IsMainButtonId, "IsMainButtonId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __IsMainButtonId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsMainButtonId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __IsModal, "IsModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __IsModal)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsModal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetAffirmativeId, "SetAffirmativeId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetAffirmativeId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetAffirmativeId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetEscapeId, "SetEscapeId")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetEscapeId)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetEscapeId();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetIcon, "SetIcon")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetIcon)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetIcons, "SetIcons")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icons", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetIcons)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int icons = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcons();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetLayoutAdaptationDone, "SetLayoutAdaptationDone")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "done", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetLayoutAdaptationDone)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int done = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutAdaptationDone();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetLayoutAdaptationLevel, "SetLayoutAdaptationLevel")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetLayoutAdaptationLevel)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutAdaptationLevel();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetLayoutAdaptationMode, "SetLayoutAdaptationMode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetLayoutAdaptationMode)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutAdaptationMode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetLayoutAdapter, "SetLayoutAdapter")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "adapter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetLayoutAdapter)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int adapter = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutAdapter();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __SetReturnCode, "SetReturnCode")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __SetReturnCode)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int retCode = arg.GetNumber(0)
	//pThis->GetEntity()->SetReturnCode();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __Show, "Show")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __Show)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __ShowModal)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __ShowWindowModal, "ShowWindowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, __ShowWindowModal)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowWindowModal();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Dialog, __ShowWindowModalThenDo, "ShowWindowModalThenDo")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "onEndModal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, __ShowWindowModalThenDo)
{
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int onEndModal = arg.GetNumber(0)
	//pThis->GetEntity()->ShowWindowModalThenDo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dialog)
{
	// Constructor assignment
	Gura_AssignFunction(__wxDialog);
	Gura_AssignFunction(__wxDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_Dialog, __AddMainButtonId);
	Gura_AssignMethod(wx_Dialog, __CanDoLayoutAdaptation);
	Gura_AssignMethod(wx_Dialog, __Centre);
	Gura_AssignMethod(wx_Dialog, __Create);
	Gura_AssignMethod(wx_Dialog, __CreateButtonSizer);
	Gura_AssignMethod(wx_Dialog, __CreateSeparatedButtonSizer);
	Gura_AssignMethod(wx_Dialog, __CreateSeparatedSizer);
	Gura_AssignMethod(wx_Dialog, __CreateStdDialogButtonSizer);
	Gura_AssignMethod(wx_Dialog, __CreateTextSizer);
	Gura_AssignMethod(wx_Dialog, __DoLayoutAdaptation);
	Gura_AssignMethod(wx_Dialog, __EnableLayoutAdaptation);
	Gura_AssignMethod(wx_Dialog, __EndModal);
	Gura_AssignMethod(wx_Dialog, __GetAffirmativeId);
	Gura_AssignMethod(wx_Dialog, __GetContentWindow);
	Gura_AssignMethod(wx_Dialog, __GetEscapeId);
	Gura_AssignMethod(wx_Dialog, __GetLayoutAdaptationDone);
	Gura_AssignMethod(wx_Dialog, __GetLayoutAdaptationLevel);
	Gura_AssignMethod(wx_Dialog, __GetLayoutAdaptationMode);
	Gura_AssignMethod(wx_Dialog, __GetLayoutAdapter);
	Gura_AssignMethod(wx_Dialog, __GetMainButtonIds);
	Gura_AssignMethod(wx_Dialog, __GetReturnCode);
	Gura_AssignMethod(wx_Dialog, __GetToolBar);
	Gura_AssignMethod(wx_Dialog, __Iconize);
	Gura_AssignMethod(wx_Dialog, __IsIconized);
	Gura_AssignMethod(wx_Dialog, __IsLayoutAdaptationEnabled);
	Gura_AssignMethod(wx_Dialog, __IsMainButtonId);
	Gura_AssignMethod(wx_Dialog, __IsModal);
	Gura_AssignMethod(wx_Dialog, __SetAffirmativeId);
	Gura_AssignMethod(wx_Dialog, __SetEscapeId);
	Gura_AssignMethod(wx_Dialog, __SetIcon);
	Gura_AssignMethod(wx_Dialog, __SetIcons);
	Gura_AssignMethod(wx_Dialog, __SetLayoutAdaptationDone);
	Gura_AssignMethod(wx_Dialog, __SetLayoutAdaptationLevel);
	Gura_AssignMethod(wx_Dialog, __SetLayoutAdaptationMode);
	Gura_AssignMethod(wx_Dialog, __SetLayoutAdapter);
	Gura_AssignMethod(wx_Dialog, __SetReturnCode);
	Gura_AssignMethod(wx_Dialog, __Show);
	Gura_AssignMethod(wx_Dialog, __ShowModal);
	Gura_AssignMethod(wx_Dialog, __ShowWindowModal);
	Gura_AssignMethod(wx_Dialog, __ShowWindowModalThenDo);
}

Gura_ImplementDescendantCreator(wx_Dialog)
{
	return new Object_wx_Dialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
