//----------------------------------------------------------------------------
// wxAutomationObject
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAutomationObject
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAutomationObject
//----------------------------------------------------------------------------
Object_wx_AutomationObject::~Object_wx_AutomationObject()
{
}

Object *Object_wx_AutomationObject::Clone() const
{
	return nullptr;
}

String Object_wx_AutomationObject::ToString(bool exprFlag)
{
	String rtn("<wx.AutomationObject:");
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
Gura_DeclareMethod(wx_AutomationObject, wxAutomationObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dispatchPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, wxAutomationObject)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dispatchPtr = arg.GetNumber(0)
	//pThis->GetEntity()->wxAutomationObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, CallMethod)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, CallMethod)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int method = arg.GetNumber(0)
	//int noArgs = arg.GetNumber(1)
	//int args = arg.GetNumber(2)
	//pThis->GetEntity()->CallMethod();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, CallMethod_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, CallMethod_1)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int method = arg.GetNumber(0)
	//pThis->GetEntity()->CallMethod();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, CreateInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "progId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, CreateInstance)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int progId = arg.GetNumber(0)
	//pThis->GetEntity()->CreateInstance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AutomationObject, IsOk)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, GetDispatchPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AutomationObject, GetDispatchPtr)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDispatchPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, GetInstance)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "progId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, GetInstance)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int progId = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->GetInstance();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, GetObject)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, GetObject)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int obj = arg.GetNumber(0)
	//int property = arg.GetNumber(1)
	//int noArgs = arg.GetNumber(2)
	//int args = arg.GetNumber(3)
	//pThis->GetEntity()->GetObject();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, GetProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, GetProperty)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int noArgs = arg.GetNumber(1)
	//int args = arg.GetNumber(2)
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, GetProperty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, GetProperty_1)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//pThis->GetEntity()->GetProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, Invoke)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "member", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "retValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "ptrArgs", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, Invoke)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int member = arg.GetNumber(0)
	//int action = arg.GetNumber(1)
	//int retValue = arg.GetNumber(2)
	//int noArgs = arg.GetNumber(3)
	//int args = arg.GetNumber(4)
	//int ptrArgs = arg.GetNumber(5)
	//pThis->GetEntity()->Invoke();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, PutProperty)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, PutProperty)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//int noArgs = arg.GetNumber(1)
	//int args = arg.GetNumber(2)
	//pThis->GetEntity()->PutProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, PutProperty_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, PutProperty_1)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int property = arg.GetNumber(0)
	//pThis->GetEntity()->PutProperty();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, SetDispatchPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dispatchPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, SetDispatchPtr)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dispatchPtr = arg.GetNumber(0)
	//pThis->GetEntity()->SetDispatchPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, GetLCID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AutomationObject, GetLCID)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLCID();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, SetLCID)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lcid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, SetLCID)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int lcid = arg.GetNumber(0)
	//pThis->GetEntity()->SetLCID();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, GetConvertVariantFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AutomationObject, GetConvertVariantFlags)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetConvertVariantFlags();
	return Value::Nil;
}

Gura_DeclareMethod(wx_AutomationObject, SetConvertVariantFlags)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, SetConvertVariantFlags)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetConvertVariantFlags();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAutomationObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AutomationObject)
{
	Gura_AssignMethod(wx_AutomationObject, wxAutomationObject);
	Gura_AssignMethod(wx_AutomationObject, CallMethod);
	Gura_AssignMethod(wx_AutomationObject, CallMethod_1);
	Gura_AssignMethod(wx_AutomationObject, CreateInstance);
	Gura_AssignMethod(wx_AutomationObject, IsOk);
	Gura_AssignMethod(wx_AutomationObject, GetDispatchPtr);
	Gura_AssignMethod(wx_AutomationObject, GetInstance);
	Gura_AssignMethod(wx_AutomationObject, GetObject);
	Gura_AssignMethod(wx_AutomationObject, GetProperty);
	Gura_AssignMethod(wx_AutomationObject, GetProperty_1);
	Gura_AssignMethod(wx_AutomationObject, Invoke);
	Gura_AssignMethod(wx_AutomationObject, PutProperty);
	Gura_AssignMethod(wx_AutomationObject, PutProperty_1);
	Gura_AssignMethod(wx_AutomationObject, SetDispatchPtr);
	Gura_AssignMethod(wx_AutomationObject, GetLCID);
	Gura_AssignMethod(wx_AutomationObject, SetLCID);
	Gura_AssignMethod(wx_AutomationObject, GetConvertVariantFlags);
	Gura_AssignMethod(wx_AutomationObject, SetConvertVariantFlags);
}

Gura_ImplementDescendantCreator(wx_AutomationObject)
{
	return new Object_wx_AutomationObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
