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
// Constructor implementation
//----------------------------------------------------------------------------
Gura_DeclareFunctionAlias(__GridEvent, "GridEvent")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
	SetClassToConstruct(Gura_UserClass(wx_GridEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridEvent)
{
	//wxGridEvent();
	return Value::Nil;
}

Gura_DeclareFunctionAlias(__GridEvent_1, "GridEvent_1")
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
	SetClassToConstruct(Gura_UserClass(wx_GridEvent));
	DeclareBlock(OCCUR_ZeroOrOnce);
}

Gura_ImplementFunction(__GridEvent_1)
{
	//int id = arg.GetNumber(0)
	//int type = arg.GetNumber(1)
	//int obj = arg.GetNumber(2)
	//int row = arg.GetNumber(3)
	//int col = arg.GetNumber(4)
	//int x = arg.GetNumber(5)
	//int y = arg.GetNumber(6)
	//int sel = arg.GetNumber(7)
	//int kbd = arg.GetNumber(8)
	//wxGridEvent();
	return Value::Nil;
}

//----------------------------------------------------------------------------
// Method implementation
//----------------------------------------------------------------------------
Gura_DeclareMethodAlias(wx_GridEvent, __AltDown, "AltDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, __AltDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->AltDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEvent, __ControlDown, "ControlDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, __ControlDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->ControlDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEvent, __GetCol, "GetCol")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, __GetCol)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetCol();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEvent, __GetPosition, "GetPosition")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, __GetPosition)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetPosition();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEvent, __GetRow, "GetRow")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, __GetRow)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->GetRow();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEvent, __MetaDown, "MetaDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, __MetaDown)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->MetaDown();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEvent, __Selecting, "Selecting")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, __Selecting)
{
	Object_wx_GridEvent *pThis = Object_wx_GridEvent::GetObjectThis(arg);
	if (pThis->IsInvalid(env)) return Value::Nil;
	//pThis->GetEntity()->Selecting();
	return Value::Nil;
}

Gura_DeclareMethodAlias(wx_GridEvent, __ShiftDown, "ShiftDown")
{
	SetFuncAttr(VTYPE_any, RSLTMODE_Void, FLAG_None);
}

Gura_ImplementMethod(wx_GridEvent, __ShiftDown)
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
	// Constructor assignment
	Gura_AssignFunction(__GridEvent);
	Gura_AssignFunction(__GridEvent_1);
	// Method assignment
	Gura_AssignMethod(wx_GridEvent, __AltDown);
	Gura_AssignMethod(wx_GridEvent, __ControlDown);
	Gura_AssignMethod(wx_GridEvent, __GetCol);
	Gura_AssignMethod(wx_GridEvent, __GetPosition);
	Gura_AssignMethod(wx_GridEvent, __GetRow);
	Gura_AssignMethod(wx_GridEvent, __MetaDown);
	Gura_AssignMethod(wx_GridEvent, __Selecting);
	Gura_AssignMethod(wx_GridEvent, __ShiftDown);
}

Gura_ImplementDescendantCreator(wx_GridEvent)
{
	return new Object_wx_GridEvent((pClass == nullptr)? this : pClass, nullptr, nullptr, OwnerFalse);
}

Gura_EndModuleScope(wx)
