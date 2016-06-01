//----------------------------------------------------------------------------
// wxRecursionGuard
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxRecursionGuard
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Object_wx_RecursionGuard::~Object_wx_RecursionGuard()
{
}

Object *Object_wx_RecursionGuard::Clone() const
{
	return nullptr;
}

String Object_wx_RecursionGuard::ToString(bool exprFlag)
{
	String rtn("<wx.RecursionGuard:");
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
Gura_DeclareMethod(wx_RecursionGuard, wxRecursionGuard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "flag", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_RecursionGuard, wxRecursionGuard)
{
	Signal &sig = env.GetSignal();
	Object_wx_RecursionGuard *pThis = Object_wx_RecursionGuard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int flag = arg.GetNumber(0)
	//pThis->GetEntity()->wxRecursionGuard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RecursionGuard, ~wxRecursionGuard)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RecursionGuard, ~wxRecursionGuard)
{
	Signal &sig = env.GetSignal();
	Object_wx_RecursionGuard *pThis = Object_wx_RecursionGuard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxRecursionGuard();
	return Value::Nil;
}

Gura_DeclareMethod(wx_RecursionGuard, IsInside)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_RecursionGuard, IsInside)
{
	Signal &sig = env.GetSignal();
	Object_wx_RecursionGuard *pThis = Object_wx_RecursionGuard::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsInside();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxRecursionGuard
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_RecursionGuard)
{
	Gura_AssignMethod(wx_RecursionGuard, wxRecursionGuard);
	Gura_AssignMethod(wx_RecursionGuard, ~wxRecursionGuard);
	Gura_AssignMethod(wx_RecursionGuard, IsInside);
}

Gura_ImplementDescendantCreator(wx_RecursionGuard)
{
	return new Object_wx_RecursionGuard((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
