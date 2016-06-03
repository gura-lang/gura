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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__wxMultiChoiceDialog, "wxMultiChoiceDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "n", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MultiChoiceDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxMultiChoiceDialog)
{
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int n = arg.GetNumber(3)
	//int choices = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int pos = arg.GetNumber(6)
	//wxMultiChoiceDialog();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__wxMultiChoiceDialog_1, "wxMultiChoiceDialog_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "caption", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "choices", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MultiChoiceDialog));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__wxMultiChoiceDialog_1)
{
	//int parent = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int caption = arg.GetNumber(2)
	//int choices = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//int pos = arg.GetNumber(5)
	//wxMultiChoiceDialog();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MultiChoiceDialog, __GetSelections, "GetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, __GetSelections)
{
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MultiChoiceDialog, __SetSelections, "SetSelections")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "selections", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, __SetSelections)
{
	Object_wx_MultiChoiceDialog *pThis = Object_wx_MultiChoiceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int selections = arg.GetNumber(0)
	//pThis->GetEntity()->SetSelections();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MultiChoiceDialog, __ShowModal, "ShowModal")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MultiChoiceDialog, __ShowModal)
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
	// Constructor assignment
	Gura_AssignFunction(__wxMultiChoiceDialog);
	Gura_AssignFunction(__wxMultiChoiceDialog_1);
	// Method assignment
	Gura_AssignMethod(wx_MultiChoiceDialog, __GetSelections);
	Gura_AssignMethod(wx_MultiChoiceDialog, __SetSelections);
	Gura_AssignMethod(wx_MultiChoiceDialog, __ShowModal);
}

Gura_ImplementDescendantCreator(wx_MultiChoiceDialog)
{
	return new Object_wx_MultiChoiceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
