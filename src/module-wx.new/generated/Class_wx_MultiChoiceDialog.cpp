//----------------------------------------------------------------------------
// wxMultiChoiceDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMultiChoiceDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMultiChoiceDialog
//----------------------------------------------------------------------------
Object_wx_MultiChoiceDialog::~Object_wx_MultiChoiceDialog()
{
}

Object *Object_wx_MultiChoiceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_MultiChoiceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.MultiChoiceDialog:");
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
Gura_DeclareMethod(wx_MultiChoiceDialog, wxMultiChoiceDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, wxMultiChoiceDialog)
{
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int n = arg.GetNumber(3)
	//int choices = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//pThis->GetEntity()->wxMultiChoiceDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MultiChoiceDialog, wxMultiChoiceDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, wxMultiChoiceDialog_1)
{
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int choices = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//pThis->GetEntity()->wxMultiChoiceDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MultiChoiceDialog, GetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, GetSelections)
{
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MultiChoiceDialog, SetSelections)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, SetSelections)
{
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selections = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelections();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MultiChoiceDialog, ShowModal)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, ShowModal)
{
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShowModal();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMultiChoiceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MultiChoiceDialog)
{
	Gura_AssignMethod(wx_MultiChoiceDialog, wxMultiChoiceDialog);
	Gura_AssignMethod(wx_MultiChoiceDialog, wxMultiChoiceDialog_1);
	Gura_AssignMethod(wx_MultiChoiceDialog, GetSelections);
	Gura_AssignMethod(wx_MultiChoiceDialog, SetSelections);
	Gura_AssignMethod(wx_MultiChoiceDialog, ShowModal);
}

Gura_ImplementDescendantCreator(wx_MultiChoiceDialog)
{
	return new Object_wx_MultiChoiceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
