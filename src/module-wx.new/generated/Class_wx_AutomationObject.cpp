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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__AutomationObject, "AutomationObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dispatchPtr", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_AutomationObject));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__AutomationObject)
{
	//WXIDISPATCH* dispatchPtr = arg.GetNumber(0)
	//wxAutomationObject(dispatchPtr);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_AutomationObject, __CallMethod, "CallMethod")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "method", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __CallMethod)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& method = arg.GetNumber(0)
	//int noArgs = arg.GetNumber(1)
	//wxVariant args = arg.GetNumber(2)
	//pThis->GetEntity()->CallMethod(method, noArgs, args);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __CreateInstance, "CreateInstance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "progId", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __CreateInstance)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& progId = arg.GetNumber(0)
	//pThis->GetEntity()->CreateInstance(progId);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AutomationObject, __IsOk)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __GetDispatchPtr, "GetDispatchPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AutomationObject, __GetDispatchPtr)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetDispatchPtr();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __GetInstance, "GetInstance")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "progId", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __GetInstance)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& progId = arg.GetNumber(0)
	//int flags = arg.GetNumber(1)
	//pThis->GetEntity()->GetInstance(progId, flags);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __GetObject, "GetObject")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg3", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __GetObject)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxAutomationObject& obj = arg.GetNumber(0)
	//const wxString& property = arg.GetNumber(1)
	//int noArgs = arg.GetNumber(2)
	//wxVariant args[] _arg3 = arg.GetNumber(3)
	//pThis->GetEntity()->GetObject(obj, property, noArgs, _arg3);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __GetProperty, "GetProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __GetProperty)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& property = arg.GetNumber(0)
	//int noArgs = arg.GetNumber(1)
	//wxVariant args = arg.GetNumber(2)
	//pThis->GetEntity()->GetProperty(property, noArgs, args);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __Invoke, "Invoke")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "member", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "action", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "retValue", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "_arg5", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __Invoke)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& member = arg.GetNumber(0)
	//int action = arg.GetNumber(1)
	//wxVariant& retValue = arg.GetNumber(2)
	//int noArgs = arg.GetNumber(3)
	//wxVariant args = arg.GetNumber(4)
	//const wxVariant* ptrArgs[] _arg5 = arg.GetNumber(5)
	//pThis->GetEntity()->Invoke(member, action, retValue, noArgs, args, _arg5);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __PutProperty, "PutProperty")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "property", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "noArgs", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "args", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __PutProperty)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxString& property = arg.GetNumber(0)
	//int noArgs = arg.GetNumber(1)
	//wxVariant args = arg.GetNumber(2)
	//pThis->GetEntity()->PutProperty(property, noArgs, args);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __SetDispatchPtr, "SetDispatchPtr")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dispatchPtr", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __SetDispatchPtr)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//WXIDISPATCH* dispatchPtr = arg.GetNumber(0)
	//pThis->GetEntity()->SetDispatchPtr(dispatchPtr);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __GetLCID, "GetLCID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AutomationObject, __GetLCID)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLCID();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __SetLCID, "SetLCID")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "lcid", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __SetLCID)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//LCID lcid = arg.GetNumber(0)
	//pThis->GetEntity()->SetLCID(lcid);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __GetConvertVariantFlags, "GetConvertVariantFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_AutomationObject, __GetConvertVariantFlags)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetConvertVariantFlags();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_AutomationObject, __SetConvertVariantFlags, "SetConvertVariantFlags")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flags", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_AutomationObject, __SetConvertVariantFlags)
{
	Object_wx_AutomationObject *pThis = Object_wx_AutomationObject::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//long flags = arg.GetNumber(0)
	//pThis->GetEntity()->SetConvertVariantFlags(flags);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAutomationObject
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_AutomationObject)
{
	// Constructor assignment
	Gura_AssignFunction(__AutomationObject);
	// Method assignment
	Gura_AssignMethod(wx_AutomationObject, __CallMethod);
	Gura_AssignMethod(wx_AutomationObject, __CreateInstance);
	Gura_AssignMethod(wx_AutomationObject, __IsOk);
	Gura_AssignMethod(wx_AutomationObject, __GetDispatchPtr);
	Gura_AssignMethod(wx_AutomationObject, __GetInstance);
	Gura_AssignMethod(wx_AutomationObject, __GetObject);
	Gura_AssignMethod(wx_AutomationObject, __GetProperty);
	Gura_AssignMethod(wx_AutomationObject, __Invoke);
	Gura_AssignMethod(wx_AutomationObject, __PutProperty);
	Gura_AssignMethod(wx_AutomationObject, __SetDispatchPtr);
	Gura_AssignMethod(wx_AutomationObject, __GetLCID);
	Gura_AssignMethod(wx_AutomationObject, __SetLCID);
	Gura_AssignMethod(wx_AutomationObject, __GetConvertVariantFlags);
	Gura_AssignMethod(wx_AutomationObject, __SetConvertVariantFlags);
}

Gura_ImplementDescendantCreator(wx_AutomationObject)
{
	return new Object_wx_AutomationObject((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
