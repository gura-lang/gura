//----------------------------------------------------------------------------
// wxMouseState
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseState
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseState
//----------------------------------------------------------------------------
Object_wx_MouseState::~Object_wx_MouseState()
{
}

Object *Object_wx_MouseState::Clone() const
{
	return nullptr;
}

String Object_wx_MouseState::ToString(bool exprFlag)
{
	String rtn("<wx.MouseState:");
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
Gura_DeclareMethod(wx_MouseState, wxMouseState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, wxMouseState)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxMouseState();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, GetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, GetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, GetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, GetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, GetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, GetPosition_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, GetPosition_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//int y = arg.GetNumber(1)
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, LeftIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, LeftIsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LeftIsDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, MiddleIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, MiddleIsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MiddleIsDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, RightIsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, RightIsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RightIsDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, Aux1IsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, Aux1IsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Aux1IsDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, Aux2IsDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, Aux2IsDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Aux2IsDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetX)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetX)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int x = arg.GetNumber(0)
	//pThis->GetEntity()->SetX();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetY)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetY)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int y = arg.GetNumber(0)
	//pThis->GetEntity()->SetY();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetLeftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetLeftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeftDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetMiddleDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetMiddleDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetMiddleDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetRightDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetRightDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetAux1Down)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetAux1Down)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetAux1Down();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetAux2Down)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetAux2Down)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int down = arg.GetNumber(0)
	//pThis->GetEntity()->SetAux2Down();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseState, SetState)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, SetState)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int state = arg.GetNumber(0)
	//pThis->GetEntity()->SetState();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseState)
{
	Gura_AssignMethod(wx_MouseState, wxMouseState);
	Gura_AssignMethod(wx_MouseState, GetX);
	Gura_AssignMethod(wx_MouseState, GetY);
	Gura_AssignMethod(wx_MouseState, GetPosition);
	Gura_AssignMethod(wx_MouseState, GetPosition_1);
	Gura_AssignMethod(wx_MouseState, LeftIsDown);
	Gura_AssignMethod(wx_MouseState, MiddleIsDown);
	Gura_AssignMethod(wx_MouseState, RightIsDown);
	Gura_AssignMethod(wx_MouseState, Aux1IsDown);
	Gura_AssignMethod(wx_MouseState, Aux2IsDown);
	Gura_AssignMethod(wx_MouseState, SetX);
	Gura_AssignMethod(wx_MouseState, SetY);
	Gura_AssignMethod(wx_MouseState, SetPosition);
	Gura_AssignMethod(wx_MouseState, SetLeftDown);
	Gura_AssignMethod(wx_MouseState, SetMiddleDown);
	Gura_AssignMethod(wx_MouseState, SetRightDown);
	Gura_AssignMethod(wx_MouseState, SetAux1Down);
	Gura_AssignMethod(wx_MouseState, SetAux2Down);
	Gura_AssignMethod(wx_MouseState, SetState);
}

Gura_ImplementDescendantCreator(wx_MouseState)
{
	return new Object_wx_MouseState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
