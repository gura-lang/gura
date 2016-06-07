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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__SpinDoubleEvent, "SpinDoubleEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "commandType", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "winid", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SpinDoubleEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SpinDoubleEvent)
{
	//wxEventType commandType = arg.GetNumber(0)
	//int winid = arg.GetNumber(1)
	//double value = arg.GetNumber(2)
	//wxSpinDoubleEvent(commandType, winid, value);
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__SpinDoubleEvent_1, "SpinDoubleEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "event", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_SpinDoubleEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__SpinDoubleEvent_1)
{
	//const wxSpinDoubleEvent& event = arg.GetNumber(0)
	//wxSpinDoubleEvent(event);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_SpinDoubleEvent, __GetValue, "GetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_SpinDoubleEvent, __GetValue)
{
	Object_wx_SpinDoubleEvent *pThis = Object_wx_SpinDoubleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetValue();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_SpinDoubleEvent, __SetValue, "SetValue")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "value", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_SpinDoubleEvent, __SetValue)
{
	Object_wx_SpinDoubleEvent *pThis = Object_wx_SpinDoubleEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//double value = arg.GetNumber(0)
	//pThis->GetEntity()->SetValue(value);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxSpinDoubleEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_SpinDoubleEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__SpinDoubleEvent);
	Gura_AssignFunction(__SpinDoubleEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_SpinDoubleEvent, __GetValue);
	Gura_AssignMethod(wx_SpinDoubleEvent, __SetValue);
}

Gura_ImplementDescendantCreator(wx_SpinDoubleEvent)
{
	return new Object_wx_SpinDoubleEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
