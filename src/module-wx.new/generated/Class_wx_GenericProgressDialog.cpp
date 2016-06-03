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
Gura_DeclareMethodAlias(wx_GenericProgressDialog, __wxGenericProgressDialog, "wxGenericProgressDialog")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "title", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "message", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maximum", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __wxGenericProgressDialog)
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

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __GetValue)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __GetRange, "GetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __GetRange)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __GetMessage, "GetMessage")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __GetMessage)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMessage();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __Pulse, "Pulse")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "newmsg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "skip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __Pulse)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int newmsg = arg.GetNumber(0)
	//int skip = arg.GetNumber(1)
	//pThis->GetEntity()->Pulse();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __Resume, "Resume")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __Resume)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Resume();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __SetRange, "SetRange")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "maximum", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __SetRange)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int maximum = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __WasCancelled, "WasCancelled")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __WasCancelled)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WasCancelled();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __WasSkipped, "WasSkipped")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __WasSkipped)
{
	Object_wx_GenericProgressDialog *pThis = Object_wx_GenericProgressDialog::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->WasSkipped();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GenericProgressDialog, __Update, "Update")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "newmsg", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "skip", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GenericProgressDialog, __Update)
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
	Gura_AssignMethod(wx_GenericProgressDialog, __wxGenericProgressDialog);
	Gura_AssignMethod(wx_GenericProgressDialog, __GetValue);
	Gura_AssignMethod(wx_GenericProgressDialog, __GetRange);
	Gura_AssignMethod(wx_GenericProgressDialog, __GetMessage);
	Gura_AssignMethod(wx_GenericProgressDialog, __Pulse);
	Gura_AssignMethod(wx_GenericProgressDialog, __Resume);
	Gura_AssignMethod(wx_GenericProgressDialog, __SetRange);
	Gura_AssignMethod(wx_GenericProgressDialog, __WasCancelled);
	Gura_AssignMethod(wx_GenericProgressDialog, __WasSkipped);
	Gura_AssignMethod(wx_GenericProgressDialog, __Update);
}

Gura_ImplementDescendantCreator(wx_GenericProgressDialog)
{
	return new Object_wx_GenericProgressDialog((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
