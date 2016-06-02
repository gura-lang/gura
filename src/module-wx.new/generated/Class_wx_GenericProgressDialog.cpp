//----------------------------------------------------------------------------
// wxGenericProgressDialog
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGenericProgressDialog
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGenericProgressDialog
//----------------------------------------------------------------------------
Object_wx_GenericProgressDialog::~Object_wx_GenericProgressDialog()
{
}

Object *Object_wx_GenericProgressDialog::Clone() const
{
	return nullptr;
}

String Object_wx_GenericProgressDialog::ToString(bool exprFlag)
{
	String rtn("<wx.GenericProgressDialog:");
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
Gura_DeclareMethod(wx_GenericProgressDialog, wxGenericProgressDialog)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maximum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericProgressDialog, wxGenericProgressDialog)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int title = arg.GetNumber(0)
	//int message = arg.GetNumber(1)
	//int maximum = arg.GetNumber(2)
	//int parent = arg.GetNumber(3)
	//int style = arg.GetNumber(4)
	//pThis->GetEntity()->wxGenericProgressDialog();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, GetValue)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, GetRange)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, GetMessage)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, GetMessage)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMessage();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, Pulse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newmsg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "skip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericProgressDialog, Pulse)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newmsg = arg.GetNumber(0)
	//int skip = arg.GetNumber(1)
	//pThis->GetEntity()->Pulse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, Resume)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, Resume)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maximum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericProgressDialog, SetRange)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maximum = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, WasCancelled)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, WasCancelled)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WasCancelled();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, WasSkipped)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, WasSkipped)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WasSkipped();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GenericProgressDialog, Update)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newmsg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "skip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericProgressDialog, Update)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//int newmsg = arg.GetNumber(1)
	//int skip = arg.GetNumber(2)
	//pThis->GetEntity()->Update();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGenericProgressDialog
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GenericProgressDialog)
{
	Gura_AssignMethod(wx_GenericProgressDialog, wxGenericProgressDialog);
	Gura_AssignMethod(wx_GenericProgressDialog, GetValue);
	Gura_AssignMethod(wx_GenericProgressDialog, GetRange);
	Gura_AssignMethod(wx_GenericProgressDialog, GetMessage);
	Gura_AssignMethod(wx_GenericProgressDialog, Pulse);
	Gura_AssignMethod(wx_GenericProgressDialog, Resume);
	Gura_AssignMethod(wx_GenericProgressDialog, SetRange);
	Gura_AssignMethod(wx_GenericProgressDialog, WasCancelled);
	Gura_AssignMethod(wx_GenericProgressDialog, WasSkipped);
	Gura_AssignMethod(wx_GenericProgressDialog, Update);
}

Gura_ImplementDescendantCreator(wx_GenericProgressDialog)
{
	return new Object_wx_GenericProgressDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
