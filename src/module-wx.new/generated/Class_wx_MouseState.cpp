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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__MouseState, "MouseState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_MouseState));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MouseState)
{
	//wxMouseState();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MouseState, __GetX, "GetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, __GetX)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord _rtn = pThis->GetEntity()->GetX();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __GetY, "GetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, __GetY)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord _rtn = pThis->GetEntity()->GetY();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, __GetPosition)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __GetPosition_1, "GetPosition_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __GetPosition_1)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int* x = arg.GetNumber(0)
	//int* y = arg.GetNumber(1)
	//pThis->GetEntity()->GetPosition(x, y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __LeftIsDown, "LeftIsDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, __LeftIsDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->LeftIsDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __MiddleIsDown, "MiddleIsDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, __MiddleIsDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->MiddleIsDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __RightIsDown, "RightIsDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, __RightIsDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->RightIsDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __Aux1IsDown, "Aux1IsDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, __Aux1IsDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Aux1IsDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __Aux2IsDown, "Aux2IsDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_MouseState, __Aux2IsDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->Aux2IsDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetX, "SetX")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetX)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord x = arg.GetNumber(0)
	//pThis->GetEntity()->SetX(x);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetY, "SetY")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetY)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxCoord y = arg.GetNumber(0)
	//pThis->GetEntity()->SetY(y);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetPosition, "SetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "pos", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetPosition)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint pos = arg.GetNumber(0)
	//pThis->GetEntity()->SetPosition(pos);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetLeftDown, "SetLeftDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetLeftDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool down = arg.GetNumber(0)
	//pThis->GetEntity()->SetLeftDown(down);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetMiddleDown, "SetMiddleDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetMiddleDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool down = arg.GetNumber(0)
	//pThis->GetEntity()->SetMiddleDown(down);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetRightDown, "SetRightDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetRightDown)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool down = arg.GetNumber(0)
	//pThis->GetEntity()->SetRightDown(down);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetAux1Down, "SetAux1Down")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetAux1Down)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool down = arg.GetNumber(0)
	//pThis->GetEntity()->SetAux1Down(down);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetAux2Down, "SetAux2Down")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "down", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetAux2Down)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool down = arg.GetNumber(0)
	//pThis->GetEntity()->SetAux2Down(down);
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseState, __SetState, "SetState")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "state", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseState, __SetState)
{
	Object_wx_MouseState *pThis = Object_wx_MouseState::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//const wxMouseState& state = arg.GetNumber(0)
	//pThis->GetEntity()->SetState(state);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseState
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseState)
{
	// Constructor assignment
	Gura_AssignFunction(__MouseState);
	// Method assignment
	Gura_AssignMethod(wx_MouseState, __GetX);
	Gura_AssignMethod(wx_MouseState, __GetY);
	Gura_AssignMethod(wx_MouseState, __GetPosition);
	Gura_AssignMethod(wx_MouseState, __GetPosition_1);
	Gura_AssignMethod(wx_MouseState, __LeftIsDown);
	Gura_AssignMethod(wx_MouseState, __MiddleIsDown);
	Gura_AssignMethod(wx_MouseState, __RightIsDown);
	Gura_AssignMethod(wx_MouseState, __Aux1IsDown);
	Gura_AssignMethod(wx_MouseState, __Aux2IsDown);
	Gura_AssignMethod(wx_MouseState, __SetX);
	Gura_AssignMethod(wx_MouseState, __SetY);
	Gura_AssignMethod(wx_MouseState, __SetPosition);
	Gura_AssignMethod(wx_MouseState, __SetLeftDown);
	Gura_AssignMethod(wx_MouseState, __SetMiddleDown);
	Gura_AssignMethod(wx_MouseState, __SetRightDown);
	Gura_AssignMethod(wx_MouseState, __SetAux1Down);
	Gura_AssignMethod(wx_MouseState, __SetAux2Down);
	Gura_AssignMethod(wx_MouseState, __SetState);
}

Gura_ImplementDescendantCreator(wx_MouseState)
{
	return new Object_wx_MouseState((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
