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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__TextEntryDialog, "TextEntryDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_TextEntryDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextEntryDialog)
{
	//wxTextEntryDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__TextEntryDialog_1, "TextEntryDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_TextEntryDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__TextEntryDialog_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& caption = arg.GetNumber(2)
	//const wxString& value = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxPoint& pos = arg.GetNumber(5)
	//wxTextEntryDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_TextEntryDialog, __Create, "Create")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, __Create)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxWindow* parent = arg.GetNumber(0)
	//const wxString& message = arg.GetNumber(1)
	//const wxString& caption = arg.GetNumber(2)
	//const wxString& value = arg.GetNumber(3)
	//long style = arg.GetNumber(4)
	//const wxPoint& pos = arg.GetNumber(5)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntryDialog, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntryDialog, __GetValue)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntryDialog, __SetTextValidator, "SetTextValidator")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, __SetTextValidator)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxTextValidator& validator = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntryDialog, __SetTextValidator_1, "SetTextValidator_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, __SetTextValidator_1)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxTextValidatorStyle style = arg.GetNumber(0)
	//pThis->GetEntity()->SetTextValidator();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntryDialog, __SetMaxLength, "SetMaxLength")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "len", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, __SetMaxLength)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long len = arg.GetNumber(0)
	//pThis->GetEntity()->SetMaxLength();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntryDialog, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_TextEntryDialog, __SetValue)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntryDialog, __ForceUpper, "ForceUpper")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntryDialog, __ForceUpper)
{
	Object_wx_TextEntryDialog *pThis = Object_wx_TextEntryDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ForceUpper();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_TextEntryDialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_TextEntryDialog, __ShowModal)
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
	// Constructor assignment
	Gura_AssignFunction(__TextEntryDialog);
	Gura_AssignFunction(__TextEntryDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_TextEntryDialog, __Create);
	Gura_AssignMethod(wx_TextEntryDialog, __GetValue);
	Gura_AssignMethod(wx_TextEntryDialog, __SetTextValidator);
	Gura_AssignMethod(wx_TextEntryDialog, __SetTextValidator_1);
	Gura_AssignMethod(wx_TextEntryDialog, __SetMaxLength);
	Gura_AssignMethod(wx_TextEntryDialog, __SetValue);
	Gura_AssignMethod(wx_TextEntryDialog, __ForceUpper);
	Gura_AssignMethod(wx_TextEntryDialog, __ShowModal);
}

Gura_ImplementDescendantCreator(wx_TextEntryDialog)
{
	return new Object_wx_TextEntryDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
