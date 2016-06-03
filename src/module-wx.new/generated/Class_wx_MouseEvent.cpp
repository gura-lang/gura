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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__MouseEvent, "MouseEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "mouseEventType", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_MouseEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__MouseEvent)
{
	//int mouseEventType = arg.GetNumber(0)
	//wxMouseEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_MouseEvent, __Aux1DClick, "Aux1DClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Aux1DClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Aux1DClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Aux1Down, "Aux1Down")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Aux1Down)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Aux1Down();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Aux1Up, "Aux1Up")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Aux1Up)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Aux1Up();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Aux2DClick, "Aux2DClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Aux2DClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Aux2DClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Aux2Down, "Aux2Down")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Aux2Down)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Aux2Down();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Aux2Up, "Aux2Up")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Aux2Up)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Aux2Up();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Button, "Button")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "but", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, __Button)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int but = arg.GetNumber(0)
	//pThis->GetEntity()->Button();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __ButtonDClick, "ButtonDClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "but", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, __ButtonDClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int but = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonDClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __ButtonDown, "ButtonDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "but", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, __ButtonDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int but = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __ButtonUp, "ButtonUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "but", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, __ButtonUp)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int but = arg.GetNumber(0)
	//pThis->GetEntity()->ButtonUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Dragging, "Dragging")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Dragging)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Dragging();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Entering, "Entering")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Entering)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Entering();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetButton, "GetButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __GetButton)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetClickCount, "GetClickCount")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __GetClickCount)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetClickCount();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetLinesPerAction, "GetLinesPerAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __GetLinesPerAction)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetLinesPerAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetColumnsPerAction, "GetColumnsPerAction")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __GetColumnsPerAction)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetColumnsPerAction();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetLogicalPosition, "GetLogicalPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "dc", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_MouseEvent, __GetLogicalPosition)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int dc = arg.GetNumber(0)
	//pThis->GetEntity()->GetLogicalPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetMagnification, "GetMagnification")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __GetMagnification)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetMagnification();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetWheelDelta, "GetWheelDelta")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __GetWheelDelta)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWheelDelta();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetWheelRotation, "GetWheelRotation")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __GetWheelRotation)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWheelRotation();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __GetWheelAxis, "GetWheelAxis")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __GetWheelAxis)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetWheelAxis();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __IsButton, "IsButton")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __IsButton)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsButton();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __IsPageScroll, "IsPageScroll")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __IsPageScroll)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->IsPageScroll();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Leaving, "Leaving")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Leaving)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Leaving();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __LeftDClick, "LeftDClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __LeftDClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LeftDClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __LeftDown, "LeftDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __LeftDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LeftDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __LeftUp, "LeftUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __LeftUp)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->LeftUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Magnify, "Magnify")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Magnify)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Magnify();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __MetaDown, "MetaDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __MetaDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __MiddleDClick, "MiddleDClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __MiddleDClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MiddleDClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __MiddleDown, "MiddleDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __MiddleDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MiddleDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __MiddleUp, "MiddleUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __MiddleUp)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MiddleUp();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __Moving, "Moving")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __Moving)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Moving();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __RightDClick, "RightDClick")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __RightDClick)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RightDClick();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __RightDown, "RightDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __RightDown)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RightDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_MouseEvent, __RightUp, "RightUp")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_MouseEvent, __RightUp)
{
	Object_wx_MouseEvent *pThis = Object_wx_MouseEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->RightUp();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxMouseEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_MouseEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__MouseEvent);
	// Method assignment
	Gura_AssignMethod(wx_MouseEvent, __Aux1DClick);
	Gura_AssignMethod(wx_MouseEvent, __Aux1Down);
	Gura_AssignMethod(wx_MouseEvent, __Aux1Up);
	Gura_AssignMethod(wx_MouseEvent, __Aux2DClick);
	Gura_AssignMethod(wx_MouseEvent, __Aux2Down);
	Gura_AssignMethod(wx_MouseEvent, __Aux2Up);
	Gura_AssignMethod(wx_MouseEvent, __Button);
	Gura_AssignMethod(wx_MouseEvent, __ButtonDClick);
	Gura_AssignMethod(wx_MouseEvent, __ButtonDown);
	Gura_AssignMethod(wx_MouseEvent, __ButtonUp);
	Gura_AssignMethod(wx_MouseEvent, __Dragging);
	Gura_AssignMethod(wx_MouseEvent, __Entering);
	Gura_AssignMethod(wx_MouseEvent, __GetButton);
	Gura_AssignMethod(wx_MouseEvent, __GetClickCount);
	Gura_AssignMethod(wx_MouseEvent, __GetLinesPerAction);
	Gura_AssignMethod(wx_MouseEvent, __GetColumnsPerAction);
	Gura_AssignMethod(wx_MouseEvent, __GetLogicalPosition);
	Gura_AssignMethod(wx_MouseEvent, __GetMagnification);
	Gura_AssignMethod(wx_MouseEvent, __GetWheelDelta);
	Gura_AssignMethod(wx_MouseEvent, __GetWheelRotation);
	Gura_AssignMethod(wx_MouseEvent, __GetWheelAxis);
	Gura_AssignMethod(wx_MouseEvent, __IsButton);
	Gura_AssignMethod(wx_MouseEvent, __IsPageScroll);
	Gura_AssignMethod(wx_MouseEvent, __Leaving);
	Gura_AssignMethod(wx_MouseEvent, __LeftDClick);
	Gura_AssignMethod(wx_MouseEvent, __LeftDown);
	Gura_AssignMethod(wx_MouseEvent, __LeftUp);
	Gura_AssignMethod(wx_MouseEvent, __Magnify);
	Gura_AssignMethod(wx_MouseEvent, __MetaDown);
	Gura_AssignMethod(wx_MouseEvent, __MiddleDClick);
	Gura_AssignMethod(wx_MouseEvent, __MiddleDown);
	Gura_AssignMethod(wx_MouseEvent, __MiddleUp);
	Gura_AssignMethod(wx_MouseEvent, __Moving);
	Gura_AssignMethod(wx_MouseEvent, __RightDClick);
	Gura_AssignMethod(wx_MouseEvent, __RightDown);
	Gura_AssignMethod(wx_MouseEvent, __RightUp);
}

Gura_ImplementDescendantCreator(wx_MouseEvent)
{
	return new Object_wx_MouseEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
