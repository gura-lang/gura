//----------------------------------------------------------------------------
// wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Object_wx_RichTextStyleOrganiserDialog::~Object_wx_RichTextStyleOrganiserDialog()
{
}

Object *Object_wx_RichTextStyleOrganiserDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RichTextStyleOrganiserDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RichTextStyleOrganiserDialog:");
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
Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, wxRichTextStyleOrganiserDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, wxRichTextStyleOrganiserDialog)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextStyleOrganiserDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, wxRichTextStyleOrganiserDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, wxRichTextStyleOrganiserDialog_1)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int sheet = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int parent = arg.GetNumber(3)
	//int id = arg.GetNumber(4)
	//int caption = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int style = arg.GetNumber(8)
	//pThis->GetEntity()->wxRichTextStyleOrganiserDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, ApplyStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, ApplyStyle)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, Create)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//int sheet = arg.GetNumber(1)
	//int ctrl = arg.GetNumber(2)
	//int parent = arg.GetNumber(3)
	//int id = arg.GetNumber(4)
	//int caption = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//int size = arg.GetNumber(7)
	//int style = arg.GetNumber(8)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetRestartNumbering)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetRestartNumbering)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRestartNumbering();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetRichTextCtrl)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyle)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyle)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedStyle();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyleDefinition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyleDefinition)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetStyleSheet)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetFlags)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetRestartNumbering)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "restartNumbering", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetRestartNumbering)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int restartNumbering = arg.GetNumber(0)
	//pThis->GetEntity()->SetRestartNumbering();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetRichTextCtrl)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetRichTextCtrl)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetShowToolTips)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetShowToolTips)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowToolTips();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, SetStyleSheet)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, SetStyleSheet)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichTextStyleOrganiserDialog, GetFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, GetFlags)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleOrganiserDialog)
{
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, wxRichTextStyleOrganiserDialog);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, wxRichTextStyleOrganiserDialog_1);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, ApplyStyle);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, Create);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetRestartNumbering);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyle);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetSelectedStyleDefinition);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetFlags);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetRestartNumbering);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetShowToolTips);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, GetFlags);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleOrganiserDialog)
{
	return new Object_wx_RichTextStyleOrganiserDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
