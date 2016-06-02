//----------------------------------------------------------------------------
// wxGridEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridEvent
//----------------------------------------------------------------------------
Object_wx_GridEvent::~Object_wx_GridEvent()
{
}

Object *Object_wx_GridEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridEvent:");
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
Gura_DeclareMethod(wx_GridEvent, wxGridEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, wxGridEvent)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, wxGridEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "row", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "col", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "sel", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kbd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridEvent, wxGridEvent_1)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int obj = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//int x = arg.GetNumber(5)
	//int y = arg.GetNumber(6)
	//int sel = arg.GetNumber(7)
	//int kbd = arg.GetNumber(8)
	//pThis->GetEntity()->wxGridEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, AltDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AltDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, ControlDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ControlDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, GetCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, GetCol)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, GetPosition)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, GetRow)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, GetRow)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, MetaDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, Selecting)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, Selecting)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Selecting();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridEvent, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, ShiftDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShiftDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridEvent)
{
	Gura_AssignMethod(wx_GridEvent, wxGridEvent);
	Gura_AssignMethod(wx_GridEvent, wxGridEvent_1);
	Gura_AssignMethod(wx_GridEvent, AltDown);
	Gura_AssignMethod(wx_GridEvent, ControlDown);
	Gura_AssignMethod(wx_GridEvent, GetCol);
	Gura_AssignMethod(wx_GridEvent, GetPosition);
	Gura_AssignMethod(wx_GridEvent, GetRow);
	Gura_AssignMethod(wx_GridEvent, MetaDown);
	Gura_AssignMethod(wx_GridEvent, Selecting);
	Gura_AssignMethod(wx_GridEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridEvent)
{
	return new Object_wx_GridEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
