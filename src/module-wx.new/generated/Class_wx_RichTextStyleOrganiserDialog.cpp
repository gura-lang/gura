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
Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __wxRichTextStyleOrganiserDialog, "wxRichTextStyleOrganiserDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __wxRichTextStyleOrganiserDialog)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxRichTextStyleOrganiserDialog();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __wxRichTextStyleOrganiserDialog_1, "wxRichTextStyleOrganiserDialog_1")
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

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __wxRichTextStyleOrganiserDialog_1)
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

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __ApplyStyle, "ApplyStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __ApplyStyle)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->ApplyStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __Create, "Create")
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

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __Create)
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

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetRestartNumbering, "GetRestartNumbering")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetRestartNumbering)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRestartNumbering();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetRichTextCtrl, "GetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetRichTextCtrl)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetSelectedStyle, "GetSelectedStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetSelectedStyle)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetSelectedStyleDefinition, "GetSelectedStyleDefinition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetSelectedStyleDefinition)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectedStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetStyleSheet, "GetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetStyleSheet)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __SetFlags, "SetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __SetFlags)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __SetRestartNumbering, "SetRestartNumbering")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "restartNumbering", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __SetRestartNumbering)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int restartNumbering = arg.GetNumber(0)
	//pThis->GetEntity()->SetRestartNumbering();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __SetRichTextCtrl, "SetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __SetRichTextCtrl)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __SetShowToolTips, "SetShowToolTips")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "show", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __SetShowToolTips)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int show = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowToolTips();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __SetStyleSheet, "SetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __SetStyleSheet)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetFlags)
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
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __wxRichTextStyleOrganiserDialog);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __wxRichTextStyleOrganiserDialog_1);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __ApplyStyle);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __Create);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __GetRestartNumbering);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __GetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __GetSelectedStyle);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __GetSelectedStyleDefinition);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __GetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __SetFlags);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __SetRestartNumbering);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __SetRichTextCtrl);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __SetShowToolTips);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __SetStyleSheet);
	Gura_AssignMethod(wx_RichTextStyleOrganiserDialog, __GetFlags);
}

Gura_ImplementDescendantCreator(wx_RichTextStyleOrganiserDialog)
{
	return new Object_wx_RichTextStyleOrganiserDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
