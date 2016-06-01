//----------------------------------------------------------------------------
// wxKeyboardState
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxKeyboardState
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxKeyboardState
//----------------------------------------------------------------------------
Object_wx_KeyboardState::~Object_wx_KeyboardState()
{
}

Object *Object_wx_KeyboardState::Clone() const
{
	return nullptr;
}

String Object_wx_KeyboardState::ToString(bool exprFlag)
{
	String rtn("<wx.KeyboardState:");
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
Gura_DeclareMethod(wx_KeyboardState, wxKeyboardState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "controlDown", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "shiftDown", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "altDown", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "metaDown", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, wxKeyboardState)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int controlDown = arg.GetNumber(0)
	//int shiftDown = arg.GetNumber(1)
	//int altDown = arg.GetNumber(2)
	//int metaDown = arg.GetNumber(3)
	//pThis->GetEntity()->wxKeyboardState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, GetModifiers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, GetModifiers)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetModifiers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, HasAnyModifiers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, HasAnyModifiers)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasAnyModifiers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, HasModifiers)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, HasModifiers)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->HasModifiers();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, ControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ControlDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, RawControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, RawControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RawControlDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, ShiftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShiftDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, MetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, AltDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AltDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, CmdDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_KeyboardState, CmdDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->CmdDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, SetControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, SetControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetControlDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, SetRawControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, SetRawControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetRawControlDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, SetShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, SetShiftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetShiftDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, SetAltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, SetAltDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetAltDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_KeyboardState, SetMetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_KeyboardState, SetMetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_KeyboardState *pThis = Object_wx_KeyboardState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetMetaDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxKeyboardState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_KeyboardState)
{
	Gura_AssignMethod(wx_KeyboardState, wxKeyboardState);
	Gura_AssignMethod(wx_KeyboardState, GetModifiers);
	Gura_AssignMethod(wx_KeyboardState, HasAnyModifiers);
	Gura_AssignMethod(wx_KeyboardState, HasModifiers);
	Gura_AssignMethod(wx_KeyboardState, ControlDown);
	Gura_AssignMethod(wx_KeyboardState, RawControlDown);
	Gura_AssignMethod(wx_KeyboardState, ShiftDown);
	Gura_AssignMethod(wx_KeyboardState, MetaDown);
	Gura_AssignMethod(wx_KeyboardState, AltDown);
	Gura_AssignMethod(wx_KeyboardState, CmdDown);
	Gura_AssignMethod(wx_KeyboardState, SetControlDown);
	Gura_AssignMethod(wx_KeyboardState, SetRawControlDown);
	Gura_AssignMethod(wx_KeyboardState, SetShiftDown);
	Gura_AssignMethod(wx_KeyboardState, SetAltDown);
	Gura_AssignMethod(wx_KeyboardState, SetMetaDown);
}

Gura_ImplementDescendantCreator(wx_KeyboardState)
{
	return new Object_wx_KeyboardState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
