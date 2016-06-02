//----------------------------------------------------------------------------
// wxSemaphore
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSemaphore
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSemaphore
//----------------------------------------------------------------------------
Object_wx_Semaphore::~Object_wx_Semaphore()
{
}

Object *Object_wx_Semaphore::Clone() const
{
	return nullptr;
}

String Object_wx_Semaphore::ToString(bool exprFlag)
{
	String rtn("<wx.Semaphore:");
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
Gura_DeclareMethod(wx_Semaphore, wxSemaphore)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "initialcount", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxcount", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Semaphore, wxSemaphore)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int initialcount = arg.GetNumber(0)
	//int maxcount = arg.GetNumber(1)
	//pThis->GetEntity()->wxSemaphore();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Semaphore, Post)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Semaphore, Post)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Post();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Semaphore, TryWait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Semaphore, TryWait)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TryWait();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Semaphore, Wait)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Semaphore, Wait)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Wait();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Semaphore, WaitTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "timeout_millis", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Semaphore, WaitTimeout)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int timeout_millis = arg.GetNumber(0)
	//pThis->GetEntity()->WaitTimeout();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSemaphore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Semaphore)
{
	Gura_AssignMethod(wx_Semaphore, wxSemaphore);
	Gura_AssignMethod(wx_Semaphore, Post);
	Gura_AssignMethod(wx_Semaphore, TryWait);
	Gura_AssignMethod(wx_Semaphore, Wait);
	Gura_AssignMethod(wx_Semaphore, WaitTimeout);
}

Gura_ImplementDescendantCreator(wx_Semaphore)
{
	return new Object_wx_Semaphore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
