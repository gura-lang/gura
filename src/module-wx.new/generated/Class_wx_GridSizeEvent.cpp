//----------------------------------------------------------------------------
// wxGridSizeEvent
//----------------------------------------------------------------------------
#include "stdafx.h"

Gura_BeginModuleScope(wx)

//----------------------------------------------------------------------------
// Gura interfaces for wxGridSizeEvent
//----------------------------------------------------------------------------

//----------------------------------------------------------------------------
// Object implementation for wxGridSizeEvent
//----------------------------------------------------------------------------
Object_wx_GridSizeEvent::~Object_wx_GridSizeEvent()
{
}

Object *Object_wx_GridSizeEvent::Clone() const
{
	return nullptr;
}

String Object_wx_GridSizeEvent::ToString(bool exprFlag)
{
	String rtn("<wx.GridSizeEvent:");
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
Gura_DeclareMethod(wx_GridSizeEvent, wxGridSizeEvent)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, wxGridSizeEvent)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->wxGridSizeEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizeEvent, wxGridSizeEvent_1)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rowOrCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kbd", VTYPE_number, OCCUR_Once);
}

Gura_ImplementMethod(wx_GridSizeEvent, wxGridSizeEvent_1)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int id = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int obj = arg.GetNumber(2)
	//int rowOrCol = arg.GetNumber(3)
	//int x = arg.GetNumber(4)
	//int y = arg.GetNumber(5)
	//int kbd = arg.GetNumber(6)
	//pThis->GetEntity()->wxGridSizeEvent();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizeEvent, AltDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, AltDown)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AltDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizeEvent, ControlDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, ControlDown)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ControlDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizeEvent, GetPosition)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, GetPosition)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizeEvent, GetRowOrCol)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, GetRowOrCol)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRowOrCol();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizeEvent, MetaDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, MetaDown)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethod(wx_GridSizeEvent, ShiftDown)
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, ShiftDown)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ShiftDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridSizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizeEvent)
{
	Gura_AssignMethod(wx_GridSizeEvent, wxGridSizeEvent);
	Gura_AssignMethod(wx_GridSizeEvent, wxGridSizeEvent_1);
	Gura_AssignMethod(wx_GridSizeEvent, AltDown);
	Gura_AssignMethod(wx_GridSizeEvent, ControlDown);
	Gura_AssignMethod(wx_GridSizeEvent, GetPosition);
	Gura_AssignMethod(wx_GridSizeEvent, GetRowOrCol);
	Gura_AssignMethod(wx_GridSizeEvent, MetaDown);
	Gura_AssignMethod(wx_GridSizeEvent, ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridSizeEvent)
{
	return new Object_wx_GridSizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
