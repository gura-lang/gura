//----------------------------------------------------------------------------
// wxScopedPtr
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxScopedPtr
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxScopedPtr
//----------------------------------------------------------------------------
Object_wx_ScopedPtr::~Object_wx_ScopedPtr()
{
}

Object *Object_wx_ScopedPtr::Clone() const
{
	return nullptr;
}

String Object_wx_ScopedPtr::ToString(bool exprFlag)
{
	String rtn("<wx.ScopedPtr:");
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
Gura_DeclareMethod(wx_ScopedPtr, wxScopedPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "T", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr, wxScopedPtr)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int T = arg.GetNumber(0)
	//pThis->GetEntity()->wxScopedPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr, ~wxScopedPtr)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr, ~wxScopedPtr)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxScopedPtr();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr, get)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr, get)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->get();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr, release)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ScopedPtr, release)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->release();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr, reset)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "p", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr, reset)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int p = arg.GetNumber(0)
	//pThis->GetEntity()->reset();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ScopedPtr, swap)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ScopedPtr, swap)
{
	Signal &sig = env.GetSignal();
	Object_wx_ScopedPtr *pThis = Object_wx_ScopedPtr::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->swap();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxScopedPtr
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ScopedPtr)
{
	Gura_AssignMethod(wx_ScopedPtr, wxScopedPtr);
	Gura_AssignMethod(wx_ScopedPtr, ~wxScopedPtr);
	Gura_AssignMethod(wx_ScopedPtr, get);
	Gura_AssignMethod(wx_ScopedPtr, release);
	Gura_AssignMethod(wx_ScopedPtr, reset);
	Gura_AssignMethod(wx_ScopedPtr, swap);
}

Gura_ImplementDescendantCreator(wx_ScopedPtr)
{
	return new Object_wx_ScopedPtr((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
