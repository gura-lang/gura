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
Gura_DeclareMethod(wx_MessageQueue<T>, wxMessageQueue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageQueue<T>, wxMessageQueue)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxMessageQueue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageQueue<T>, Clear)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageQueue<T>, Clear)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Clear();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageQueue<T>, IsOk)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MessageQueue<T>, IsOk)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsOk();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageQueue<T>, Post)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageQueue<T>, Post)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//pThis->GetEntity()->Post();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageQueue<T>, Receive)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageQueue<T>, Receive)
{
	Object_wx_MessageQueue<T> *pThis = Object_wx_MessageQueue<T>::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msg = arg.GetNumber(0)
	//pThis->GetEntity()->Receive();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MessageQueue<T>, ReceiveTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeout", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "msg", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MessageQueue<T>, ReceiveTimeout)
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
	Gura_AssignMethod(wx_MessageQueue<T>, wxMessageQueue);
	Gura_AssignMethod(wx_MessageQueue<T>, Clear);
	Gura_AssignMethod(wx_MessageQueue<T>, IsOk);
	Gura_AssignMethod(wx_MessageQueue<T>, Post);
	Gura_AssignMethod(wx_MessageQueue<T>, Receive);
	Gura_AssignMethod(wx_MessageQueue<T>, ReceiveTimeout);
}

Gura_ImplementDescendantCreator(wx_MessageQueue<T>)
{
	return new Object_wx_MessageQueue<T>((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
