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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__RichTextStyleOrganiserDialog, "RichTextStyleOrganiserDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleOrganiserDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextStyleOrganiserDialog)
{
	//wxRichTextStyleOrganiserDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__RichTextStyleOrganiserDialog_1, "RichTextStyleOrganiserDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sheet", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_RichTextStyleOrganiserDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__RichTextStyleOrganiserDialog_1)
{
	//int flags = arg.GetNumber(0)
	//wxRichTextStyleSheet* sheet = arg.GetNumber(1)
	//wxRichTextCtrl* ctrl = arg.GetNumber(2)
	//wxWindow* parent = arg.GetNumber(3)
	//wxWindowID id = arg.GetNumber(4)
	//const wxString& caption = arg.GetNumber(5)
	//const wxPoint& pos = arg.GetNumber(6)
	//const wxSize& size = arg.GetNumber(7)
	//long style = arg.GetNumber(8)
	//wxRichTextStyleOrganiserDialog(flags, sheet, ctrl, parent, id, caption, pos, size, style);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __ApplyStyle, "ApplyStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "ctrl", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __ApplyStyle)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextCtrl* ctrl = arg.GetNumber(0)
	//bool _rtn = pThis->GetEntity()->ApplyStyle(ctrl);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
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
	//wxRichTextStyleSheet* sheet = arg.GetNumber(1)
	//wxRichTextCtrl* ctrl = arg.GetNumber(2)
	//wxWindow* parent = arg.GetNumber(3)
	//wxWindowID id = arg.GetNumber(4)
	//const wxString& caption = arg.GetNumber(5)
	//const wxPoint& pos = arg.GetNumber(6)
	//const wxSize& size = arg.GetNumber(7)
	//long style = arg.GetNumber(8)
	//bool _rtn = pThis->GetEntity()->Create(flags, sheet, ctrl, parent, id, caption, pos, size, style);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetRestartNumbering, "GetRestartNumbering")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetRestartNumbering)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->GetRestartNumbering();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetRichTextCtrl, "GetRichTextCtrl")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetRichTextCtrl)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextCtrl* _rtn = pThis->GetEntity()->GetRichTextCtrl();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetSelectedStyle, "GetSelectedStyle")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetSelectedStyle)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxString _rtn = pThis->GetEntity()->GetSelectedStyle();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetSelectedStyleDefinition, "GetSelectedStyleDefinition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetSelectedStyleDefinition)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextStyleDefinition* _rtn = pThis->GetEntity()->GetSelectedStyleDefinition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetStyleSheet, "GetStyleSheet")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetStyleSheet)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxRichTextStyleSheet* _rtn = pThis->GetEntity()->GetStyleSheet();
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
	//pThis->GetEntity()->SetFlags(flags);
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
	//bool restartNumbering = arg.GetNumber(0)
	//pThis->GetEntity()->SetRestartNumbering(restartNumbering);
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
	//wxRichTextCtrl* ctrl = arg.GetNumber(0)
	//pThis->GetEntity()->SetRichTextCtrl(ctrl);
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
	//bool show = arg.GetNumber(0)
	//pThis->GetEntity()->SetShowToolTips(show);
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
	//wxRichTextStyleSheet* sheet = arg.GetNumber(0)
	//pThis->GetEntity()->SetStyleSheet(sheet);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_RichTextStyleOrganiserDialog, __GetFlags, "GetFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_RichTextStyleOrganiserDialog, __GetFlags)
{
	Object_wx_RichTextStyleOrganiserDialog *pThis = Object_wx_RichTextStyleOrganiserDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichTextStyleOrganiserDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichTextStyleOrganiserDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__RichTextStyleOrganiserDialog);
	Gura_AssignFunction(__RichTextStyleOrganiserDialog_1);
	// Method assignment
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
