//----------------------------------------------------------------------------
// wxPrintDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPrintDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPrintDialog
//----------------------------------------------------------------------------
Object_wx_PrintDialog::~Object_wx_PrintDialog()
{
}

Object *Object_wx_PrintDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PrintDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PrintDialog:");
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
Gura_DeclareMethod(wx_PrintDialog, wxPrintDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialog, wxPrintDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->wxPrintDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialog, wxPrintDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PrintDialog, wxPrintDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->wxPrintDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialog, ~wxPrintDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, ~wxPrintDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPrintDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialog, GetPrintDC)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, GetPrintDC)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintDC();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialog, GetPrintDialogData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, GetPrintDialogData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialog, GetPrintData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, GetPrintData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PrintDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintDialog)
{
	Gura_AssignMethod(wx_PrintDialog, wxPrintDialog);
	Gura_AssignMethod(wx_PrintDialog, wxPrintDialog_1);
	Gura_AssignMethod(wx_PrintDialog, ~wxPrintDialog);
	Gura_AssignMethod(wx_PrintDialog, GetPrintDC);
	Gura_AssignMethod(wx_PrintDialog, GetPrintDialogData);
	Gura_AssignMethod(wx_PrintDialog, GetPrintData);
	Gura_AssignMethod(wx_PrintDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_PrintDialog)
{
	return new Object_wx_PrintDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
