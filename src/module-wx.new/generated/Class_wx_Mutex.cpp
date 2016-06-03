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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Mutex, "Mutex")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Mutex));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Mutex)
{
	//wxMutexType type = arg.GetNumber(0)
	//wxMutex();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Mutex, __Lock, "Lock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Mutex, __Lock)
{
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Lock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Mutex, __LockTimeout, "LockTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "msec", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Mutex, __LockTimeout)
{
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long msec = arg.GetNumber(0)
	//pThis->GetEntity()->LockTimeout();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Mutex, __TryLock, "TryLock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Mutex, __TryLock)
{
	Object_wx_Mutex *pThis = Object_wx_Mutex::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->TryLock();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Mutex, __Unlock, "Unlock")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Mutex, __Unlock)
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
	// Constructor assignment
	Gura_AssignFunction(__Mutex);
	// Method assignment
	Gura_AssignMethod(wx_Mutex, __Lock);
	Gura_AssignMethod(wx_Mutex, __LockTimeout);
	Gura_AssignMethod(wx_Mutex, __TryLock);
	Gura_AssignMethod(wx_Mutex, __Unlock);
}

Gura_ImplementDescendantCreator(wx_Mutex)
{
	return new Object_wx_Mutex((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
