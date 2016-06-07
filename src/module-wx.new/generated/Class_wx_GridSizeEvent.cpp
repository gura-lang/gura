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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GridSizeEvent, "GridSizeEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridSizeEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridSizeEvent)
{
	//wxGridSizeEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GridSizeEvent_1, "GridSizeEvent_1")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
	//DeclareArg(env, "id", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "type", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "obj", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "rowOrCol", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "x", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "y", VTYPE_number, OCCUR_Once);
	//DeclareArg(env, "kbd", VTYPE_number, OCCUR_Once);
	SetClassToConstruct(Gura_UserClass(wx_GridSizeEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridSizeEvent_1)
{
	//int id = arg.GetNumber(0)
	//wxEventType type = arg.GetNumber(1)
	//wxObject* obj = arg.GetNumber(2)
	//int rowOrCol = arg.GetNumber(3)
	//int x = arg.GetNumber(4)
	//int y = arg.GetNumber(5)
	//const wxKeyboardState& kbd = arg.GetNumber(6)
	//wxGridSizeEvent(id, type, obj, rowOrCol, x, y, kbd);
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridSizeEvent, __AltDown, "AltDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, __AltDown)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->AltDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizeEvent, __ControlDown, "ControlDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, __ControlDown)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->ControlDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizeEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, __GetPosition)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//wxPoint _rtn = pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizeEvent, __GetRowOrCol, "GetRowOrCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, __GetRowOrCol)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//int _rtn = pThis->GetEntity()->GetRowOrCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizeEvent, __MetaDown, "MetaDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, __MetaDown)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridSizeEvent, __ShiftDown, "ShiftDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Normal, FLAG_None);
}

Gura_ImplementMethod(wx_GridSizeEvent, __ShiftDown)
{
	Object_wx_GridSizeEvent *pThis = Object_wx_GridSizeEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//bool _rtn = pThis->GetEntity()->ShiftDown();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Class implementation for wxGridSizeEvent
//----------------------------------------------------------------------------
Gura_ImplementUserInheritableClass(wx_GridSizeEvent)
{
	// Constructor assignment
	Gura_AssignFunction(__GridSizeEvent);
	Gura_AssignFunction(__GridSizeEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_GridSizeEvent, __AltDown);
	Gura_AssignMethod(wx_GridSizeEvent, __ControlDown);
	Gura_AssignMethod(wx_GridSizeEvent, __GetPosition);
	Gura_AssignMethod(wx_GridSizeEvent, __GetRowOrCol);
	Gura_AssignMethod(wx_GridSizeEvent, __MetaDown);
	Gura_AssignMethod(wx_GridSizeEvent, __ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridSizeEvent)
{
	return new Object_wx_GridSizeEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
