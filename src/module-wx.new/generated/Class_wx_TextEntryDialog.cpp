//----------------------------------------------------------------------------
// wxTextEntryDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxTextEntryDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxTextEntryDialog
//----------------------------------------------------------------------------
Object_wx_TextEntryDialog::~Object_wx_TextEntryDialog()
{
}

Object *Object_wx_TextEntryDialog::Clone() const
{
	return nullptr;
}

String Object_wx_TextEntryDialog::ToString(bool exprFlag)
{
	String rtn("<wx.TextEntryDialog:");
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
Gura_DeclareMethod(wx_TextEntryDialog, wxTextEntryDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntryDialog, wxTextEntryDialog)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxTextEntryDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, wxTextEntryDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, wxTextEntryDialog_1)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int value = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//pThis->GetEntity()->wxTextEntryDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, Create)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int value = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntryDialog, GetValue)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, SetTextValidator)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, SetTextValidator)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int validator = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, SetTextValidator_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, SetTextValidator_1)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int style = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextValidator();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, SetMaxLength)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, SetMaxLength)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int len = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, SetValue)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, ForceUpper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntryDialog, ForceUpper)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ForceUpper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_TextEntryDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntryDialog, ShowModal)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxTextEntryDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_TextEntryDialog)
{
	Gura_AssignMethod(wx_TextEntryDialog, wxTextEntryDialog);
	Gura_AssignMethod(wx_TextEntryDialog, wxTextEntryDialog_1);
	Gura_AssignMethod(wx_TextEntryDialog, Create);
	Gura_AssignMethod(wx_TextEntryDialog, GetValue);
	Gura_AssignMethod(wx_TextEntryDialog, SetTextValidator);
	Gura_AssignMethod(wx_TextEntryDialog, SetTextValidator_1);
	Gura_AssignMethod(wx_TextEntryDialog, SetMaxLength);
	Gura_AssignMethod(wx_TextEntryDialog, SetValue);
	Gura_AssignMethod(wx_TextEntryDialog, ForceUpper);
	Gura_AssignMethod(wx_TextEntryDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_TextEntryDialog)
{
	return new Object_wx_TextEntryDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
