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
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethod(wx_SingleChoiceDialog, wxSingleChoiceDialog)
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
}

Gura_ImplementMethod(wx_SingleChoiceDialog, wxSingleChoiceDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int n = arg.GetNumber(3)
	//int choices = arg.GetNumber(4)
	//int clientData = arg.GetNumber(5)
	//int style = arg.GetNumber(6)
	//int pos = arg.GetNumber(7)
	//pThis->GetEntity()->wxSingleChoiceDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleChoiceDialog, wxSingleChoiceDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "clientData", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, wxSingleChoiceDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int choices = arg.GetNumber(3)
	//int clientData = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//pThis->GetEntity()->wxSingleChoiceDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleChoiceDialog, GetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, GetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleChoiceDialog, GetSelectionData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, GetSelectionData)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetSelectionData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleChoiceDialog, GetStringSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, GetStringSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetStringSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleChoiceDialog, SetSelection)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selection", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, SetSelection)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int selection = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelection();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SingleChoiceDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SingleChoiceDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_SingleChoiceDialog *pThis = Object_wx_SingleChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSingleChoiceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SingleChoiceDialog)
{
	Gura_AssignMethod(wx_SingleChoiceDialog, wxSingleChoiceDialog);
	Gura_AssignMethod(wx_SingleChoiceDialog, wxSingleChoiceDialog_1);
	Gura_AssignMethod(wx_SingleChoiceDialog, GetSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, GetSelectionData);
	Gura_AssignMethod(wx_SingleChoiceDialog, GetStringSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, SetSelection);
	Gura_AssignMethod(wx_SingleChoiceDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_SingleChoiceDialog)
{
	return new Object_wx_SingleChoiceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
