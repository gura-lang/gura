//----------------------------------------------------------------------------
// wxGauge
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGauge
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGauge
//----------------------------------------------------------------------------
Object_wx_Gauge::~Object_wx_Gauge()
{
}

Object *Object_wx_Gauge::Clone() const
{
	return nullptr;
}

String Object_wx_Gauge::ToString(bool exprFlag)
{
	String rtn("<wx.Gauge:");
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
Gura_DeclareMethod(wx_Gauge, wxGauge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, wxGauge)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGauge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, wxGauge_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, wxGauge_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->wxGauge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, ~wxGauge)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, ~wxGauge)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->~wxGauge();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, Create)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "parent", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "size", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "style", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "validator", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "name", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, Create)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int parent = arg.GetNumber(0)
	//int id = arg.GetNumber(1)
	//int range = arg.GetNumber(2)
	//int pos = arg.GetNumber(3)
	//int size = arg.GetNumber(4)
	//int style = arg.GetNumber(5)
	//int validator = arg.GetNumber(6)
	//int name = arg.GetNumber(7)
	//pThis->GetEntity()->Create();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, GetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, GetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, IsVertical)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, IsVertical)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsVertical();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, Pulse)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_Gauge, Pulse)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Pulse();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, SetRange)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "range", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, SetRange)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int range = arg.GetNumber(0)
	//pThis->GetEntity()->SetRange();
	return Value::Nil;
}

Gura_DeclareMethod(wx_Gauge, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_Gauge, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_Gauge *pThis = Object_wx_Gauge::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGauge
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_Gauge)
{
	Gura_AssignMethod(wx_Gauge, wxGauge);
	Gura_AssignMethod(wx_Gauge, wxGauge_1);
	Gura_AssignMethod(wx_Gauge, ~wxGauge);
	Gura_AssignMethod(wx_Gauge, Create);
	Gura_AssignMethod(wx_Gauge, GetRange);
	Gura_AssignMethod(wx_Gauge, GetValue);
	Gura_AssignMethod(wx_Gauge, IsVertical);
	Gura_AssignMethod(wx_Gauge, Pulse);
	Gura_AssignMethod(wx_Gauge, SetRange);
	Gura_AssignMethod(wx_Gauge, SetValue);
}

Gura_ImplementDescendantCreator(wx_Gauge)
{
	return new Object_wx_Gauge((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
