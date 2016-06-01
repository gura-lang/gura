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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_Dialog, wxDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, wxDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, wxDialog_1)
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

Gura_ImplementMethod(wx_Dialog, wxDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int name = arg.GetNumber(6)
	//pThis->GetEntity()->wxDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, ~wxDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, ~wxDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, AddMainButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, AddMainButtonId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->AddMainButtonId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, CanDoLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, CanDoLayoutAdaptation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CanDoLayoutAdaptation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, Centre)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "direction", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, Centre)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int direction = arg.GetNumber(0)
	//pThis->GetEntity()->Centre();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, Create)
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

Gura_ImplementMethod(wx_Dialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
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

Gura_DeclareMethod(wx_Dialog, CreateButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, CreateButtonSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CreateButtonSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, CreateSeparatedButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, CreateSeparatedButtonSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CreateSeparatedButtonSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, CreateSeparatedSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sizer", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, CreateSeparatedSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int sizer = arg.GetNumber(0)
	//pThis->GetEntity()->CreateSeparatedSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, CreateStdDialogButtonSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, CreateStdDialogButtonSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->CreateStdDialogButtonSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, CreateTextSizer)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, CreateTextSizer)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int message = arg.GetNumber(0)
	//pThis->GetEntity()->CreateTextSizer();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, DoLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, DoLayoutAdaptation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->DoLayoutAdaptation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, EnableLayoutAdaptation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "enable", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, EnableLayoutAdaptation)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int enable = arg.GetNumber(0)
	//pThis->GetEntity()->EnableLayoutAdaptation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, EndModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, EndModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int retCode = arg.GetNumber(0)
	//pThis->GetEntity()->EndModal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetAffirmativeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetAffirmativeId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetAffirmativeId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetContentWindow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetContentWindow)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetContentWindow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetEscapeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetEscapeId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetEscapeId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationDone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationDone)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutAdaptationDone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutAdaptationLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdaptationMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdaptationMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutAdaptationMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetLayoutAdapter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetLayoutAdapter)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLayoutAdapter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetMainButtonIds)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetMainButtonIds)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMainButtonIds();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetReturnCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetReturnCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetReturnCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, GetToolBar)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, GetToolBar)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetToolBar();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, Iconize)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "iconize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, Iconize)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int iconize = arg.GetNumber(0)
	//pThis->GetEntity()->Iconize();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, IsIconized)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, IsIconized)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsIconized();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, IsLayoutAdaptationEnabled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, IsLayoutAdaptationEnabled)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsLayoutAdaptationEnabled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, IsMainButtonId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, IsMainButtonId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->IsMainButtonId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, IsModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, IsModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsModal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetAffirmativeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetAffirmativeId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetAffirmativeId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetEscapeId)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetEscapeId)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//pThis->GetEntity()->SetEscapeId();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetIcon)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icon", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetIcon)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icon = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcon();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetIcons)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "icons", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetIcons)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int icons = arg.GetNumber(0)
	//pThis->GetEntity()->SetIcons();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationDone)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "done", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationDone)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int done = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutAdaptationDone();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationLevel)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "level", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationLevel)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int level = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutAdaptationLevel();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdaptationMode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdaptationMode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mode = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutAdaptationMode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetLayoutAdapter)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "adapter", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetLayoutAdapter)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int adapter = arg.GetNumber(0)
	//pThis->GetEntity()->SetLayoutAdapter();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, SetReturnCode)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "retCode", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, SetReturnCode)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int retCode = arg.GetNumber(0)
	//pThis->GetEntity()->SetReturnCode();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, Show)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, Show)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->Show();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, ShowWindowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Dialog, ShowWindowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowWindowModal();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Dialog, ShowWindowModalThenDo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "onEndModal", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Dialog, ShowWindowModalThenDo)
{
	Signal &sig = env.GetSignal();
	Object_wx_Dialog *pThis = Object_wx_Dialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int onEndModal = arg.GetNumber(0)
	//pThis->GetEntity()->ShowWindowModalThenDo();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Dialog)
{
	Gura_AssignMethod(wx_Dialog, wxDialog);
	Gura_AssignMethod(wx_Dialog, wxDialog_1);
	Gura_AssignMethod(wx_Dialog, ~wxDialog);
	Gura_AssignMethod(wx_Dialog, AddMainButtonId);
	Gura_AssignMethod(wx_Dialog, CanDoLayoutAdaptation);
	Gura_AssignMethod(wx_Dialog, Centre);
	Gura_AssignMethod(wx_Dialog, Create);
	Gura_AssignMethod(wx_Dialog, CreateButtonSizer);
	Gura_AssignMethod(wx_Dialog, CreateSeparatedButtonSizer);
	Gura_AssignMethod(wx_Dialog, CreateSeparatedSizer);
	Gura_AssignMethod(wx_Dialog, CreateStdDialogButtonSizer);
	Gura_AssignMethod(wx_Dialog, CreateTextSizer);
	Gura_AssignMethod(wx_Dialog, DoLayoutAdaptation);
	Gura_AssignMethod(wx_Dialog, EnableLayoutAdaptation);
	Gura_AssignMethod(wx_Dialog, EndModal);
	Gura_AssignMethod(wx_Dialog, GetAffirmativeId);
	Gura_AssignMethod(wx_Dialog, GetContentWindow);
	Gura_AssignMethod(wx_Dialog, GetEscapeId);
	Gura_AssignMethod(wx_Dialog, GetLayoutAdaptationDone);
	Gura_AssignMethod(wx_Dialog, GetLayoutAdaptationLevel);
	Gura_AssignMethod(wx_Dialog, GetLayoutAdaptationMode);
	Gura_AssignMethod(wx_Dialog, GetLayoutAdapter);
	Gura_AssignMethod(wx_Dialog, GetMainButtonIds);
	Gura_AssignMethod(wx_Dialog, GetReturnCode);
	Gura_AssignMethod(wx_Dialog, GetToolBar);
	Gura_AssignMethod(wx_Dialog, Iconize);
	Gura_AssignMethod(wx_Dialog, IsIconized);
	Gura_AssignMethod(wx_Dialog, IsLayoutAdaptationEnabled);
	Gura_AssignMethod(wx_Dialog, IsMainButtonId);
	Gura_AssignMethod(wx_Dialog, IsModal);
	Gura_AssignMethod(wx_Dialog, SetAffirmativeId);
	Gura_AssignMethod(wx_Dialog, SetEscapeId);
	Gura_AssignMethod(wx_Dialog, SetIcon);
	Gura_AssignMethod(wx_Dialog, SetIcons);
	Gura_AssignMethod(wx_Dialog, SetLayoutAdaptationDone);
	Gura_AssignMethod(wx_Dialog, SetLayoutAdaptationLevel);
	Gura_AssignMethod(wx_Dialog, SetLayoutAdaptationMode);
	Gura_AssignMethod(wx_Dialog, SetLayoutAdapter);
	Gura_AssignMethod(wx_Dialog, SetReturnCode);
	Gura_AssignMethod(wx_Dialog, Show);
	Gura_AssignMethod(wx_Dialog, ShowModal);
	Gura_AssignMethod(wx_Dialog, ShowWindowModal);
	Gura_AssignMethod(wx_Dialog, ShowWindowModalThenDo);
}

Gura_ImplementDescendantCreator(wx_Dialog)
{
	return new Object_wx_Dialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
