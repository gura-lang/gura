//----------------------------------------------------------------------------
// wxMessageQueue<T>
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMessageQueue<T>
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMessageQueue<T>
//----------------------------------------------------------------------------
Object_wx_MessageQueue<T>::~Object_wx_MessageQueue<T>()
{
}

Object *Object_wx_MessageQueue<T>::Clone() const
{
	return nullptr;
}

String Object_wx_MessageQueue<T>::ToString(bool exprFlag)
{
	String rtn("<wx.MessageQueue<T>:");
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
Gura_DeclareMethodAlias(wx_MessageQueue<T>, __wxMessageQueue, "wxMessageQueue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageQueue<T>, __wxMessageQueue)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMessageQueue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageQueue<T>, __Clear, "Clear")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageQueue<T>, __Clear)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageQueue<T>, __IsOk, "IsOk")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageQueue<T>, __IsOk)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageQueue<T>, __Post, "Post")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageQueue<T>, __Post)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//pThis->GetEntity()->Post();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageQueue<T>, __Receive, "Receive")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageQueue<T>, __Receive)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//pThis->GetEntity()->Receive();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MessageQueue<T>, __ReceiveTimeout, "ReceiveTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageQueue<T>, __ReceiveTimeout)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timeout = arg.GetNumber(0)
	//int msg = arg.GetNumber(1)
	//pThis->GetEntity()->ReceiveTimeout();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMessageQueue<T>
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MessageQueue<T>)
{
	// Class assignment
	Gura_AssignValueEx("MessageQueue<T>", Reference());
	// Method assignment
	Gura_AssignMethod(wx_MessageQueue<T>, __wxMessageQueue);
	Gura_AssignMethod(wx_MessageQueue<T>, __Clear);
	Gura_AssignMethod(wx_MessageQueue<T>, __IsOk);
	Gura_AssignMethod(wx_MessageQueue<T>, __Post);
	Gura_AssignMethod(wx_MessageQueue<T>, __Receive);
	Gura_AssignMethod(wx_MessageQueue<T>, __ReceiveTimeout);
}

Gura_ImplementDescendantCreator(wx_MessageQueue<T>)
{
	return new Object_wx_MessageQueue<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
