//----------------------------------------------------------------------------
// wxMutex
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMutex
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMutex
//----------------------------------------------------------------------------
Object_wx_Mutex::~Object_wx_Mutex()
{
}

Object *Object_wx_Mutex::Clone() const
{
	return nullptr;
}

String Object_wx_Mutex::ToString(bool exprFlag)
{
	String rtn("<wx.Mutex:");
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
Gura_DeclareMethod(wx_Mutex, wxMutex)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mutex, wxMutex)
{
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int type = arg.GetNumber(0)
	//pThis->GetEntity()->wxMutex();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mutex, Lock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Mutex, Lock)
{
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Lock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mutex, LockTimeout)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mutex, LockTimeout)
{
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int msec = arg.GetNumber(0)
	//pThis->GetEntity()->LockTimeout();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mutex, TryLock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Mutex, TryLock)
{
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TryLock();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Mutex, Unlock)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Mutex, Unlock)
{
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Unlock();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMutex
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Mutex)
{
	Gura_AssignMethod(wx_Mutex, wxMutex);
	Gura_AssignMethod(wx_Mutex, Lock);
	Gura_AssignMethod(wx_Mutex, LockTimeout);
	Gura_AssignMethod(wx_Mutex, TryLock);
	Gura_AssignMethod(wx_Mutex, Unlock);
}

Gura_ImplementDescendantCreator(wx_Mutex)
{
	return new Object_wx_Mutex((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
