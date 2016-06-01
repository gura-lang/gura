//----------------------------------------------------------------------------
// wxSpinDoubleEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxSpinDoubleEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxSpinDoubleEvent
//----------------------------------------------------------------------------
Object_wx_SpinDoubleEvent::~Object_wx_SpinDoubleEvent()
{
}

Object *Object_wx_SpinDoubleEvent::Clone() const
{
	return nullptr;
}

String Object_wx_SpinDoubleEvent::ToString(bool exprFlag)
{
	String rtn("<wx.SpinDoubleEvent:");
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
Gura_DeclareMethod(wx_SpinDoubleEvent, wxSpinDoubleEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinDoubleEvent, wxSpinDoubleEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinDoubleEvent *pThis = Object_wx_SpinDoubleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//int value = arg.GetNumber(2)
	//pThis->GetEntity()->wxSpinDoubleEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinDoubleEvent, wxSpinDoubleEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinDoubleEvent, wxSpinDoubleEvent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinDoubleEvent *pThis = Object_wx_SpinDoubleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int event = arg.GetNumber(0)
	//pThis->GetEntity()->wxSpinDoubleEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinDoubleEvent, GetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinDoubleEvent, GetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinDoubleEvent *pThis = Object_wx_SpinDoubleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethod(wx_SpinDoubleEvent, SetValue)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinDoubleEvent, SetValue)
{
	Signal &sig = env.GetSignal();
	Object_wx_SpinDoubleEvent *pThis = Object_wx_SpinDoubleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinDoubleEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinDoubleEvent)
{
	Gura_AssignMethod(wx_SpinDoubleEvent, wxSpinDoubleEvent);
	Gura_AssignMethod(wx_SpinDoubleEvent, wxSpinDoubleEvent_1);
	Gura_AssignMethod(wx_SpinDoubleEvent, GetValue);
	Gura_AssignMethod(wx_SpinDoubleEvent, SetValue);
}

Gura_ImplementDescendantCreator(wx_SpinDoubleEvent)
{
	return new Object_wx_SpinDoubleEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
