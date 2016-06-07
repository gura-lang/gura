//----------------------------------------------------------------------------
// wxSingleChoiceDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSingleChoiceDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSingleChoiceDialog
//----------------------------------------------------------------------------
Object_wx_SingleChoiceDialog::~Object_wx_SingleChoiceDialog()
{
}

Object *Object_wx_SingleChoiceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_SingleChoiceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.SingleChoiceDialog:");
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
Gura_DeclareFunctionAlias(__SingleChoiceDialog, "SingleChoiceDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SingleChoiceDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SingleChoiceDialog)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& caption = arg.GetNumber(2)
	//int n = arg.GetNumber(3)
	//const wxString* choices = arg.GetNumber(4)
	//void** clientData = arg.GetNumber(5)
	//long style = arg.GetNumber(6)
	//const wxPoint& pos = arg.GetNumber(7)
	//wxSingleChoiceDialog(parent, message, caption, n, choices, clientData, style, pos);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SingleChoiceDialog_1, "SingleChoiceDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SingleChoiceDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SingleChoiceDialog_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& caption = arg.GetNumber(2)
	//const wxArrayString& choices = arg.GetNumber(3)
	//void** clientData = arg.GetNumber(4)
	//long style = arg.GetNumber(5)
	//const wxPoint& pos = arg.GetNumber(6)
	//wxSingleChoiceDialog(parent, message, caption, choices, clientData, style, pos);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SingleChoiceDialog, __GetSelection, "GetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, __GetSelection)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SingleChoiceDialog, __GetSelectionData, "GetSelectionData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, __GetSelectionData)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SingleChoiceDialog, __GetStringSelection, "GetStringSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, __GetStringSelection)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SingleChoiceDialog, __SetSelection, "SetSelection")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, __SetSelection)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection(selection);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SingleChoiceDialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, __ShowModal)
{
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSingleChoiceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SingleChoiceDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__SingleChoiceDialog);
	Gura_AssignFunction(__SingleChoiceDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_SingleChoiceDialog, __GetSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, __GetSelectionData);
	Gura_AssignMethod(wx_SingleChoiceDialog, __GetStringSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, __SetSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, __ShowModal);
}

Gura_ImplementDescendantCreator(wx_SingleChoiceDialog)
{
	return new Object_wx_SingleChoiceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
