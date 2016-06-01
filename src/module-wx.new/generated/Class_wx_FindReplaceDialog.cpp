//----------------------------------------------------------------------------
// wxFindReplaceDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxFindReplaceDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Object_wx_FindReplaceDialog::~Object_wx_FindReplaceDialog()
{
}

Object *Object_wx_FindReplaceDialog::Clone() const
{
	return nullptr;
}

String Object_wx_FindReplaceDialog::ToString(bool exprFlag)
{
	String rtn("<wx.FindReplaceDialog:");
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
Gura_DeclareMethod(wx_FindReplaceDialog, wxFindReplaceDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceDialog, wxFindReplaceDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxFindReplaceDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceDialog, wxFindReplaceDialog_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceDialog, wxFindReplaceDialog_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->wxFindReplaceDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceDialog, ~wxFindReplaceDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceDialog, ~wxFindReplaceDialog)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxFindReplaceDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceDialog, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "data", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_FindReplaceDialog, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int data = arg.GetNumber(1)
	//int title = arg.GetNumber(2)
	//int style = arg.GetNumber(3)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_FindReplaceDialog, GetData)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_FindReplaceDialog, GetData)
{
	Signal &sig = env.GetSignal();
	Object_wx_FindReplaceDialog *pThis = Object_wx_FindReplaceDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetData();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxFindReplaceDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_FindReplaceDialog)
{
	Gura_AssignMethod(wx_FindReplaceDialog, wxFindReplaceDialog);
	Gura_AssignMethod(wx_FindReplaceDialog, wxFindReplaceDialog_1);
	Gura_AssignMethod(wx_FindReplaceDialog, ~wxFindReplaceDialog);
	Gura_AssignMethod(wx_FindReplaceDialog, Create);
	Gura_AssignMethod(wx_FindReplaceDialog, GetData);
}

Gura_ImplementDescendantCreator(wx_FindReplaceDialog)
{
	return new Object_wx_FindReplaceDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
