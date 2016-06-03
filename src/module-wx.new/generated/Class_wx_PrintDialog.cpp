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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__PrintDialog, "PrintDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PrintDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PrintDialog)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxPrintDialogData* data = arg.GetNumber(1)
	//wxPrintDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__PrintDialog_1, "PrintDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_PrintDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__PrintDialog_1)
{
	//wxWindow* parent = arg.GetNumber(0)
	//wxPrintData* data = arg.GetNumber(1)
	//wxPrintDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_PrintDialog, __GetPrintDC, "GetPrintDC")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, __GetPrintDC)
{
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintDC();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialog, __GetPrintDialogData, "GetPrintDialogData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, __GetPrintDialogData)
{
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintDialogData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialog, __GetPrintData, "GetPrintData")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, __GetPrintData)
{
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPrintData();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_PrintDialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PrintDialog, __ShowModal)
{
	Object_wx_PrintDialog *pThis = Object_wx_PrintDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPrintDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PrintDialog)
{
	// Constructor assignment
	Gura_AssignFunction(__PrintDialog);
	Gura_AssignFunction(__PrintDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_PrintDialog, __GetPrintDC);
	Gura_AssignMethod(wx_PrintDialog, __GetPrintDialogData);
	Gura_AssignMethod(wx_PrintDialog, __GetPrintData);
	Gura_AssignMethod(wx_PrintDialog, __ShowModal);
}

Gura_ImplementDescendantCreator(wx_PrintDialog)
{
	return new Object_wx_PrintDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
