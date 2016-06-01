//----------------------------------------------------------------------------
// wxThreadHelper
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxThreadHelper
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxThreadHelper
//----------------------------------------------------------------------------
Object_wx_ThreadHelper::~Object_wx_ThreadHelper()
{
}

Object *Object_wx_ThreadHelper::Clone() const
{
	return nullptr;
}

String Object_wx_ThreadHelper::ToString(bool exprFlag)
{
	String rtn("<wx.ThreadHelper:");
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
Gura_DeclareMethod(wx_ThreadHelper, wxThreadHelper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadHelper, wxThreadHelper)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int kind = arg.GetNumber(0)
	//pThis->GetEntity()->wxThreadHelper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, ~wxThreadHelper)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadHelper, ~wxThreadHelper)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxThreadHelper();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, Entry)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadHelper, Entry)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Entry();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, OnDelete)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadHelper, OnDelete)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnDelete();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, OnKill)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadHelper, OnKill)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->OnKill();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "stackSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadHelper, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int stackSize = arg.GetNumber(0)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, CreateThread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "kind", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "stackSize", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_ThreadHelper, CreateThread)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int kind = arg.GetNumber(0)
	//int stackSize = arg.GetNumber(1)
	//pThis->GetEntity()->CreateThread();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, GetThread)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadHelper, GetThread)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetThread();
	return Value::Nil;
}

Gura_DeclareMethod(wx_ThreadHelper, GetThreadKind)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_ThreadHelper, GetThreadKind)
{
	Signal &sig = env.GetSignal();
	Object_wx_ThreadHelper *pThis = Object_wx_ThreadHelper::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetThreadKind();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxThreadHelper
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_ThreadHelper)
{
	Gura_AssignMethod(wx_ThreadHelper, wxThreadHelper);
	Gura_AssignMethod(wx_ThreadHelper, ~wxThreadHelper);
	Gura_AssignMethod(wx_ThreadHelper, Entry);
	Gura_AssignMethod(wx_ThreadHelper, OnDelete);
	Gura_AssignMethod(wx_ThreadHelper, OnKill);
	Gura_AssignMethod(wx_ThreadHelper, Create);
	Gura_AssignMethod(wx_ThreadHelper, CreateThread);
	Gura_AssignMethod(wx_ThreadHelper, GetThread);
	Gura_AssignMethod(wx_ThreadHelper, GetThreadKind);
}

Gura_ImplementDescendantCreator(wx_ThreadHelper)
{
	return new Object_wx_ThreadHelper((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
