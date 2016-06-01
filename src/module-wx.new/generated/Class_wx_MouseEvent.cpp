//----------------------------------------------------------------------------
// wxMouseEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxMouseEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxMouseEvent
//----------------------------------------------------------------------------
Object_wx_MouseEvent::~Object_wx_MouseEvent()
{
}

Object *Object_wx_MouseEvent::Clone() const
{
	return nullptr;
}

String Object_wx_MouseEvent::ToString(bool exprFlag)
{
	String rtn("<wx.MouseEvent:");
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
Gura_DeclareMethod(wx_MouseEvent, wxMouseEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mouseEventType", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, wxMouseEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int mouseEventType = arg.GetNumber(0)
	//pThis->GetEntity()->wxMouseEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Aux1DClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Aux1DClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Aux1DClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Aux1Down)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Aux1Down)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Aux1Down();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Aux1Up)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Aux1Up)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Aux1Up();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Aux2DClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Aux2DClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Aux2DClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Aux2Down)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Aux2Down)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Aux2Down();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Aux2Up)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Aux2Up)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Aux2Up();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Button)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "but", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, Button)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int but = arg.GetNumber(0)
	//pThis->GetEntity()->Button();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, ButtonDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "but", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonDClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int but = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonDClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, ButtonDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "but", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int but = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, ButtonUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "but", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, ButtonUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int but = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Dragging)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Dragging)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Dragging();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Entering)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Entering)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Entering();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, GetButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetClickCount)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, GetClickCount)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetClickCount();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetLinesPerAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, GetLinesPerAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLinesPerAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetColumnsPerAction)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, GetColumnsPerAction)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetColumnsPerAction();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetLogicalPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, GetLogicalPosition)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->GetLogicalPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetMagnification)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, GetMagnification)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetMagnification();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetWheelDelta)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, GetWheelDelta)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWheelDelta();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetWheelRotation)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, GetWheelRotation)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWheelRotation();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, GetWheelAxis)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, GetWheelAxis)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetWheelAxis();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, IsButton)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, IsButton)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsButton();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, IsPageScroll)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, IsPageScroll)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->IsPageScroll();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Leaving)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Leaving)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Leaving();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, LeftDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, LeftDClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LeftDClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, LeftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, LeftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LeftDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, LeftUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, LeftUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->LeftUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Magnify)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Magnify)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Magnify();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, MetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, MiddleDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleDClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MiddleDClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, MiddleDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MiddleDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, MiddleUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, MiddleUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MiddleUp();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, Moving)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, Moving)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Moving();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, RightDClick)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, RightDClick)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RightDClick();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, RightDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, RightDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RightDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_MouseEvent, RightUp)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, RightUp)
{
	Signal &sig = env.GetSignal();
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->RightUp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseEvent)
{
	Gura_AssignMethod(wx_MouseEvent, wxMouseEvent);
	Gura_AssignMethod(wx_MouseEvent, Aux1DClick);
	Gura_AssignMethod(wx_MouseEvent, Aux1Down);
	Gura_AssignMethod(wx_MouseEvent, Aux1Up);
	Gura_AssignMethod(wx_MouseEvent, Aux2DClick);
	Gura_AssignMethod(wx_MouseEvent, Aux2Down);
	Gura_AssignMethod(wx_MouseEvent, Aux2Up);
	Gura_AssignMethod(wx_MouseEvent, Button);
	Gura_AssignMethod(wx_MouseEvent, ButtonDClick);
	Gura_AssignMethod(wx_MouseEvent, ButtonDown);
	Gura_AssignMethod(wx_MouseEvent, ButtonUp);
	Gura_AssignMethod(wx_MouseEvent, Dragging);
	Gura_AssignMethod(wx_MouseEvent, Entering);
	Gura_AssignMethod(wx_MouseEvent, GetButton);
	Gura_AssignMethod(wx_MouseEvent, GetClickCount);
	Gura_AssignMethod(wx_MouseEvent, GetLinesPerAction);
	Gura_AssignMethod(wx_MouseEvent, GetColumnsPerAction);
	Gura_AssignMethod(wx_MouseEvent, GetLogicalPosition);
	Gura_AssignMethod(wx_MouseEvent, GetMagnification);
	Gura_AssignMethod(wx_MouseEvent, GetWheelDelta);
	Gura_AssignMethod(wx_MouseEvent, GetWheelRotation);
	Gura_AssignMethod(wx_MouseEvent, GetWheelAxis);
	Gura_AssignMethod(wx_MouseEvent, IsButton);
	Gura_AssignMethod(wx_MouseEvent, IsPageScroll);
	Gura_AssignMethod(wx_MouseEvent, Leaving);
	Gura_AssignMethod(wx_MouseEvent, LeftDClick);
	Gura_AssignMethod(wx_MouseEvent, LeftDown);
	Gura_AssignMethod(wx_MouseEvent, LeftUp);
	Gura_AssignMethod(wx_MouseEvent, Magnify);
	Gura_AssignMethod(wx_MouseEvent, MetaDown);
	Gura_AssignMethod(wx_MouseEvent, MiddleDClick);
	Gura_AssignMethod(wx_MouseEvent, MiddleDown);
	Gura_AssignMethod(wx_MouseEvent, MiddleUp);
	Gura_AssignMethod(wx_MouseEvent, Moving);
	Gura_AssignMethod(wx_MouseEvent, RightDClick);
	Gura_AssignMethod(wx_MouseEvent, RightDown);
	Gura_AssignMethod(wx_MouseEvent, RightUp);
}

Gura_ImplementDescendantCreator(wx_MouseEvent)
{
	return new Object_wx_MouseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
