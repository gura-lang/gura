//----------------------------------------------------------------------------
// wxAny
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxAny
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxAny
//----------------------------------------------------------------------------
Object_wx_Any::~Object_wx_Any()
{
}

Object *Object_wx_Any::Clone() const
{
	return nullptr;
}

String Object_wx_Any::ToString(bool exprFlag)
{
	String rtn("<wx.Any:");
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
Gura_DeclareMethod(wx_Any, wxAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, wxAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, wxAny_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, wxAny_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, wxAny_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "any", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, wxAny_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int any = arg.GetNumber(0)
	//pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, wxAny_3)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "variant", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, wxAny_3)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int variant = arg.GetNumber(0)
	//pThis->GetEntity()->wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, ~wxAny)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, ~wxAny)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxAny();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, As)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, As)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->As();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, CheckType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, CheckType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CheckType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, GetAs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, GetAs)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->GetAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, GetAs_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, GetAs_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->GetAs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, GetType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, GetType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, HasSameType)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "other", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Any, HasSameType)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int other = arg.GetNumber(0)
	//pThis->GetEntity()->HasSameType();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, IsNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, IsNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsNull();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Any, MakeNull)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Any, MakeNull)
{
	Signal &sig = env.GetSignal();
	Object_wx_Any *pThis = Object_wx_Any::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MakeNull();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxAny
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Any)
{
	Gura_AssignMethod(wx_Any, wxAny);
	Gura_AssignMethod(wx_Any, wxAny_1);
	Gura_AssignMethod(wx_Any, wxAny_2);
	Gura_AssignMethod(wx_Any, wxAny_3);
	Gura_AssignMethod(wx_Any, ~wxAny);
	Gura_AssignMethod(wx_Any, As);
	Gura_AssignMethod(wx_Any, CheckType);
	Gura_AssignMethod(wx_Any, GetAs);
	Gura_AssignMethod(wx_Any, GetAs_1);
	Gura_AssignMethod(wx_Any, GetType);
	Gura_AssignMethod(wx_Any, HasSameType);
	Gura_AssignMethod(wx_Any, IsNull);
	Gura_AssignMethod(wx_Any, MakeNull);
}

Gura_ImplementDescendantCreator(wx_Any)
{
	return new Object_wx_Any((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
