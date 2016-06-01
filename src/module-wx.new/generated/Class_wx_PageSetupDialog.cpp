//----------------------------------------------------------------------------
// wxPageSetupDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxPageSetupDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxPageSetupDialog
//----------------------------------------------------------------------------
Object_wx_PageSetupDialog::~Object_wx_PageSetupDialog()
{
}

Object *Object_wx_PageSetupDialog::Clone() const
{
	return nullptr;
}

String Object_wx_PageSetupDialog::ToString(bool exprFlag)
{
	String rtn("<wx.PageSetupDialog:");
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
Gura_DeclareMethod(wx_PageSetupDialog, wxPageSetupDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_PageSetupDialog, wxPageSetupDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//pThis->GetEntity()->wxPageSetupDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialog, ~wxPageSetupDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialog, ~wxPageSetupDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxPageSetupDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialog, GetPageSetupData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialog, GetPageSetupData)
{
	Signal &sig = env.GetSignal();
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPageSetupData();
	return Value::Nil;
}

Gura_DeclareMethod(wx_PageSetupDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_PageSetupDialog, ShowModal)
{
	Signal &sig = env.GetSignal();
	Object_wx_PageSetupDialog *pThis = Object_wx_PageSetupDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxPageSetupDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_PageSetupDialog)
{
	Gura_AssignMethod(wx_PageSetupDialog, wxPageSetupDialog);
	Gura_AssignMethod(wx_PageSetupDialog, ~wxPageSetupDialog);
	Gura_AssignMethod(wx_PageSetupDialog, GetPageSetupData);
	Gura_AssignMethod(wx_PageSetupDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_PageSetupDialog)
{
	return new Object_wx_PageSetupDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
