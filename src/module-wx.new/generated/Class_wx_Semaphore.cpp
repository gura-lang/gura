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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__Semaphore, "Semaphore")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "initialcount", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "maxcount", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_Semaphore));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__Semaphore)
{
	//int initialcount = arg.GetNumber(0)
	//int maxcount = arg.GetNumber(1)
	//wxSemaphore(initialcount, maxcount);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_Semaphore, __Post, "Post")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Semaphore, __Post)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSemaError _rtn = pThis->GetEntity()->Post();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Semaphore, __TryWait, "TryWait")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Semaphore, __TryWait)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSemaError _rtn = pThis->GetEntity()->TryWait();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Semaphore, __Wait, "Wait")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_Semaphore, __Wait)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxSemaError _rtn = pThis->GetEntity()->Wait();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_Semaphore, __WaitTimeout, "WaitTimeout")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "timeout_millis", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Semaphore, __WaitTimeout)
{
	Object_wx_Semaphore *pThis = Object_wx_Semaphore::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//unsigned long timeout_millis = arg.GetNumber(0)
	//wxSemaError _rtn = pThis->GetEntity()->WaitTimeout(timeout_millis);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSemaphore
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Semaphore)
{
	// Constructor assignment
	Gura_AssignFunction(__Semaphore);
	// Method assignment
	Gura_AssignMethod(wx_Semaphore, __Post);
	Gura_AssignMethod(wx_Semaphore, __TryWait);
	Gura_AssignMethod(wx_Semaphore, __Wait);
	Gura_AssignMethod(wx_Semaphore, __WaitTimeout);
}

Gura_ImplementDescendantCreator(wx_Semaphore)
{
	return new Object_wx_Semaphore((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
