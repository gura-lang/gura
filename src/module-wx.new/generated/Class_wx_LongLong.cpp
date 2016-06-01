//----------------------------------------------------------------------------
// wxLongLong
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxLongLong
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxLongLong
//----------------------------------------------------------------------------
Object_wx_LongLong::~Object_wx_LongLong()
{
}

Object *Object_wx_LongLong::Clone() const
{
	return nullptr;
}

String Object_wx_LongLong::ToString(bool exprFlag)
{
	String rtn("<wx.LongLong:");
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
Gura_DeclareMethod(wx_LongLong, wxLongLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, wxLongLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxLongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, wxLongLong_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "ll", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LongLong, wxLongLong_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int ll = arg.GetNumber(0)
	//pThis->GetEntity()->wxLongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, wxLongLong_2)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "hi", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "lo", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LongLong, wxLongLong_2)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int hi = arg.GetNumber(0)
	//int lo = arg.GetNumber(1)
	//pThis->GetEntity()->wxLongLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, Abs)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, Abs)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Abs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, Abs_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, Abs_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Abs();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, Assign)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "d", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_LongLong, Assign)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int d = arg.GetNumber(0)
	//pThis->GetEntity()->Assign();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, GetHi)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, GetHi)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetHi();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, GetLo)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, GetLo)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLo();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, ToDouble)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, ToDouble)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ToDouble();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, ToLong)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, ToLong)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ToLong();
	return Value::Nil;
}

Gura_DeclareMethod(wx_LongLong, ToString)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_LongLong, ToString)
{
	Signal &sig = env.GetSignal();
	Object_wx_LongLong *pThis = Object_wx_LongLong::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ToString();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxLongLong
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_LongLong)
{
	Gura_AssignMethod(wx_LongLong, wxLongLong);
	Gura_AssignMethod(wx_LongLong, wxLongLong_1);
	Gura_AssignMethod(wx_LongLong, wxLongLong_2);
	Gura_AssignMethod(wx_LongLong, Abs);
	Gura_AssignMethod(wx_LongLong, Abs_1);
	Gura_AssignMethod(wx_LongLong, Assign);
	Gura_AssignMethod(wx_LongLong, GetHi);
	Gura_AssignMethod(wx_LongLong, GetLo);
	Gura_AssignMethod(wx_LongLong, GetValue);
	Gura_AssignMethod(wx_LongLong, ToDouble);
	Gura_AssignMethod(wx_LongLong, ToLong);
	Gura_AssignMethod(wx_LongLong, ToString);
}

Gura_ImplementDescendantCreator(wx_LongLong)
{
	return new Object_wx_LongLong((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
