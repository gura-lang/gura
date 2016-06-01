//----------------------------------------------------------------------------
// wxGridRangeSelectEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridRangeSelectEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Object_wx_GridRangeSelectEvent::~Object_wx_GridRangeSelectEvent()
{
}

Object *Object_wx_GridRangeSelectEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridRangeSelectEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridRangeSelectEvent:");
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
Gura_DeclareMethod(wx_GridRangeSelectEvent, wxGridRangeSelectEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, wxGridRangeSelectEvent)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->wxGridRangeSelectEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, wxGridRangeSelectEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "topLeft", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "bottomRight", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kbd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, wxGridRangeSelectEvent_1)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int obj = arg.GetNumber(2)
	//int topLeft = arg.GetNumber(3)
	//int bottomRight = arg.GetNumber(4)
	//int sel = arg.GetNumber(5)
	//int kbd = arg.GetNumber(6)
	//pThis->GetEntity()->wxGridRangeSelectEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, AltDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->AltDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, ControlDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ControlDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetBottomRightCoords)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetBottomRightCoords)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottomRightCoords();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetBottomRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetBottomRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetBottomRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetLeftCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetLeftCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetLeftCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetRightCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetRightCol)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetRightCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetTopLeftCoords)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetTopLeftCoords)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTopLeftCoords();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, GetTopRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, GetTopRow)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->GetTopRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, MetaDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, Selecting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, Selecting)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->Selecting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridRangeSelectEvent, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridRangeSelectEvent, ShiftDown)
{
	Signal &sig = env.GetSignal();
	Object_wx_GridRangeSelectEvent *pThis = Object_wx_GridRangeSelectEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(sig)) return Value::Nil;
	//pThis->GetEntity()->ShiftDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridRangeSelectEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridRangeSelectEvent)
{
	Gura_AssignMethod(wx_GridRangeSelectEvent, wxGridRangeSelectEvent);
	Gura_AssignMethod(wx_GridRangeSelectEvent, wxGridRangeSelectEvent_1);
	Gura_AssignMethod(wx_GridRangeSelectEvent, AltDown);
	Gura_AssignMethod(wx_GridRangeSelectEvent, ControlDown);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetBottomRightCoords);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetBottomRow);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetLeftCol);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetRightCol);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetTopLeftCoords);
	Gura_AssignMethod(wx_GridRangeSelectEvent, GetTopRow);
	Gura_AssignMethod(wx_GridRangeSelectEvent, MetaDown);
	Gura_AssignMethod(wx_GridRangeSelectEvent, Selecting);
	Gura_AssignMethod(wx_GridRangeSelectEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridRangeSelectEvent)
{
	return new Object_wx_GridRangeSelectEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
