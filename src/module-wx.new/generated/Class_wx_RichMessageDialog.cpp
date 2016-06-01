//----------------------------------------------------------------------------
// wxRichMessageDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRichMessageDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRichMessageDialog
//----------------------------------------------------------------------------
Object_wx_RichMessageDialog::~Object_wx_RichMessageDialog()
{
}

Object *Object_wx_RichMessageDialog::Clone() const
{
	return nullptr;
}

String Object_wx_RichMessageDialog::ToString(bool exprFlag)
{
	String rtn("<wx.RichMessageDialog:");
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
Gura_DeclareMethod(wx_RichMessageDialog, wxRichMessageDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichMessageDialog, wxRichMessageDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichMessageDialog *pThis = Object_wx_RichMessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->wxRichMessageDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichMessageDialog, ShowCheckBox)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "checkBoxText", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "checked", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichMessageDialog, ShowCheckBox)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichMessageDialog *pThis = Object_wx_RichMessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int checkBoxText = arg.GetNumber(0)
	//int checked = arg.GetNumber(1)
	//pThis->GetEntity()->ShowCheckBox();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichMessageDialog, GetCheckBoxText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichMessageDialog, GetCheckBoxText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichMessageDialog *pThis = Object_wx_RichMessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetCheckBoxText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichMessageDialog, ShowDetailedText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "detailedText", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RichMessageDialog, ShowDetailedText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichMessageDialog *pThis = Object_wx_RichMessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int detailedText = arg.GetNumber(0)
	//pThis->GetEntity()->ShowDetailedText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichMessageDialog, GetDetailedText)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichMessageDialog, GetDetailedText)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichMessageDialog *pThis = Object_wx_RichMessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetDetailedText();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichMessageDialog, IsCheckBoxChecked)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichMessageDialog, IsCheckBoxChecked)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichMessageDialog *pThis = Object_wx_RichMessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsCheckBoxChecked();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RichMessageDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RichMessageDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_RichMessageDialog *pThis = Object_wx_RichMessageDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRichMessageDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RichMessageDialog)
{
	Gura_AssignMethod(wx_RichMessageDialog, wxRichMessageDialog);
	Gura_AssignMethod(wx_RichMessageDialog, ShowCheckBox);
	Gura_AssignMethod(wx_RichMessageDialog, GetCheckBoxText);
	Gura_AssignMethod(wx_RichMessageDialog, ShowDetailedText);
	Gura_AssignMethod(wx_RichMessageDialog, GetDetailedText);
	Gura_AssignMethod(wx_RichMessageDialog, IsCheckBoxChecked);
	Gura_AssignMethod(wx_RichMessageDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_RichMessageDialog)
{
	return new Object_wx_RichMessageDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
